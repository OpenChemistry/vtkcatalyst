/*
 * Distributed under OSI-approved BSD 3-Clause License. See
 * accompanying License.txt
 */

#define _GNU_SOURCE

#include "catalyst_api.h"
#include "catalyst_impl.h"

#include "conduit_node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
typedef HMODULE catalyst_handle_t;
#else
#include <dlfcn.h>
#include <stdio.h>
typedef void* catalyst_handle_t;
#endif

static char* default_search_path();
static catalyst_handle_t handle_default();
static catalyst_handle_t handle_open(const char* directory, const char* libname);
static void* handle_load_symbol(catalyst_handle_t handle, const char* symbol);
static int handle_is_valid(catalyst_handle_t handle);

static struct catalyst_impl const* impl = NULL;
extern struct catalyst_impl const default_impl;

static enum catalyst_error catalyst_load(const conduit_node* params)
{
  // Ensure that an implementation has not already been loaded.
  if (impl)
  {
    return catalyst_error_already_loaded;
  }

  // C APIs all expect non-const pointers.
  conduit_node* p = (conduit_node*)params;

  char* impl_name = NULL;
  if (conduit_node_has_path(p, "catalyst_load/implementation"))
  {
    impl_name = conduit_node_fetch_path_as_char8_str(p, "catalyst_load/implementation");
  }

  if (!impl_name)
  {
    impl_name = getenv("CATALYST_IMPLEMENTATION_NAME");
  }

  if (impl_name)
  {
    catalyst_handle_t handle = handle_default();
    if (conduit_node_has_path(p, "catalyst_load/search_paths"))
    {
      conduit_node* search_paths = conduit_node_fetch(p, "catalyst_load/search_paths");
      if (search_paths)
      {
        conduit_index_t npaths = conduit_node_number_of_children(search_paths);
        for (conduit_index_t i = 0; i < npaths; ++i)
        {
          conduit_node* path_node = conduit_node_child(search_paths, i);
          char* search_path = conduit_node_as_char8_str(path_node);
          if (search_path)
          {
            handle = handle_open(search_path, impl_name);
            if (handle_is_valid(handle))
            {
              break;
            }
          }
        }
      }
    }

    // Search the default path
    if (!handle_is_valid(handle))
    {
      char* beside_catalyst = default_search_path();
      char* default_paths[] = {
        beside_catalyst,
        NULL,
      };
      for (char** search_path = &default_paths[0]; *search_path; ++search_path)
      {
        handle = handle_open(*search_path, impl_name);
        if (handle_is_valid(handle))
        {
          break;
        }
      }
      free(beside_catalyst);
    }

    if (!handle_is_valid(handle))
    {
      return catalyst_error_not_found;
    }

    impl = (struct catalyst_impl const*)handle_load_symbol(handle, "catalyst_api_impl");
  }
  else
  {
    impl = &default_impl;
  }

  if (!impl)
  {
    return catalyst_error_not_catalyst;
  }

  if (impl->version != 1)
  {
    return catalyst_error_unsupported_version;
  }

  // Ensure that all required API functions are provided.
  if (!impl->initialize || !impl->execute || !impl->finalize || !impl->about)
  {
    impl = NULL;
    return catalyst_error_incomplete;
  }

  return catalyst_error_ok;
}

#define impl_check(method)                                                                         \
  do                                                                                               \
  {                                                                                                \
    if (!impl)                                                                                     \
    {                                                                                              \
      return catalyst_error_no_implementation;                                                     \
    }                                                                                              \
    if (!impl->method)                                                                             \
    {                                                                                              \
      return catalyst_error_no_implementation;                                                     \
    }                                                                                              \
  } while (0)

enum catalyst_error catalyst_initialize(const conduit_node* params)
{
  if (!impl)
  {
    enum catalyst_error err = catalyst_load(params);
    if (err != catalyst_error_ok)
    {
      return err;
    }
  }

  impl_check(initialize);
  return (*impl->initialize)(params);
}

enum catalyst_error catalyst_execute(const conduit_node* params)
{
  impl_check(execute);
  return (*impl->execute)(params);
}

enum catalyst_error catalyst_finalize(const conduit_node* params)
{
  impl_check(finalize);
  return (*impl->finalize)(params);
}

enum catalyst_error catalyst_about(conduit_node* params)
{
  impl_check(about);
  return (*impl->about)(params);
}

#ifdef _WIN32
char* default_search_path()
{
  MEMORY_BASIC_INFORMATION mbi;
  VirtualQuery(catalyst_initialize, &mbi, sizeof(mbi));
  wchar_t pathBuf[16384];
  if (!GetModuleFileNameW((HMODULE)mbi.AllocationBase, pathBuf, sizeof(pathBuf)))
  {
    return NULL;
  }

  size_t size = WideCharToMultiByte(CP_UTF8, 0, pathBuf, -1, NULL, 0, NULL, NULL);
  char* path_utf8 = (char*)malloc(size);
  if (!path_utf8)
  {
    return NULL;
  }
  path_utf8[0] = '\0';
  WideCharToMultiByte(CP_UTF8, 0, pathBuf, -1, path_utf8, size, NULL, NULL);

  // The Windows API will always use `\` separators here.
  char* dirsep = strrchr(path_utf8, '\\');
  *dirsep = '\0';

  size_t dirlen = strlen(path_utf8) + 9 + 1;
  char* directory_name = (char*)malloc(dirlen);
  if (!directory_name)
  {
    return NULL;
  }

  snprintf(directory_name, dirlen, "%s/catalyst", path_utf8);
  free(path_utf8);

  return directory_name;
}

catalyst_handle_t handle_default()
{
  return NULL;
}

catalyst_handle_t handle_open(const char* directory, const char* libname)
{
  size_t path_len = strlen(directory) + strlen(libname) + 9 + 5 + 1;
  char* full_library_path = (char*)malloc(path_len);
  if (!full_library_path)
  {
    return NULL;
  }

  snprintf(full_library_path, path_len, "%s/catalyst-%s.dll", directory, libname);

  catalyst_handle_t handle = LoadLibraryExA(full_library_path, NULL, 0);

  free(full_library_path);
  return handle;
}

void* handle_load_symbol(catalyst_handle_t handle, const char* symbol)
{
  return (void*)GetProcAddress(handle, symbol);
}

int handle_is_valid(catalyst_handle_t handle)
{
  return handle != NULL;
}
#else
char* default_search_path()
{
  catalyst_handle_t handle = dlsym(RTLD_DEFAULT, "catalyst_initialize");
  if (!handle)
  {
    return NULL;
  }

  Dl_info info;
  int ret = dladdr(handle, &info);
  if (ret == 0 || !info.dli_saddr || !info.dli_fname)
  {
    return NULL;
  }

  char* dirsep = strrchr(info.dli_fname, '/');
  *dirsep = '\0';

  size_t dirlen = strlen(info.dli_fname) + 9 + 1;
  char* directory_name = (char*)malloc(dirlen);
  if (!directory_name)
  {
    return NULL;
  }

  snprintf(directory_name, dirlen, "%s/catalyst", info.dli_fname);

  return directory_name;
}

catalyst_handle_t handle_default()
{
  return NULL;
}

catalyst_handle_t handle_open(const char* directory, const char* libname)
{
  size_t path_len = strlen(directory) + strlen(libname) + 9 + 7 + 1;
  char* full_library_path = (char*)malloc(path_len);
  if (!full_library_path)
  {
    return NULL;
  }

  snprintf(full_library_path, path_len, "%s/libcatalyst-%s.so", directory, libname);

  catalyst_handle_t handle = dlopen(full_library_path, RTLD_LAZY | RTLD_LOCAL);
  if (!handle)
  {
    printf("failed to open library: %s\n", dlerror());
  }

  free(full_library_path);
  return handle;
}

void* handle_load_symbol(catalyst_handle_t handle, const char* symbol)
{
  return dlsym(handle, symbol);
}

int handle_is_valid(catalyst_handle_t handle)
{
  return handle != NULL;
}
#endif
