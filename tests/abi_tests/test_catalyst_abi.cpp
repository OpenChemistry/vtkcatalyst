/*
 * Distributed under OSI-approved BSD 3-Clause License. See
 * accompanying License.txt
 */

// XXX(c++14): use `_t` and `_v`-suffixed type queries.

#include <catalyst.h>
#include <catalyst_impl.h>
#include <catalyst_stub.h>

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <type_traits>

#define abi_require(cond, desc)                                                                    \
  do                                                                                               \
  {                                                                                                \
    if (!(cond))                                                                                   \
    {                                                                                              \
      fprintf(stderr, "invalid '" #cond "': " desc "\n");                                          \
      ret = EXIT_FAILURE;                                                                          \
    }                                                                                              \
  } while (false)

static int test_catalyst_status()
{
  int ret = EXIT_SUCCESS;

  // Only add assertions to this list; removal or modification of any
  // checks constitutes an ABI break.
  abi_require(sizeof(enum catalyst_status) == sizeof(int),
    "the catalyst_status type must be the same size as an int");
  abi_require(catalyst_status_ok == 0, "the ok status must be 0");
  abi_require(
    catalyst_status_error_no_implementation == 1, "the no implementation status must be 1");
  abi_require(catalyst_status_error_already_loaded == 2, "the already loaded status must be 2");
  abi_require(catalyst_status_error_not_found == 3, "the not found status must be 3");
  abi_require(catalyst_status_error_not_catalyst == 4, "the not catalyst status must be 4");
  abi_require(catalyst_status_error_incomplete == 5, "the incomplete status must be 5");
  abi_require(
    catalyst_status_error_unsupported_version == 6, "the unsupported version status must be 6");

  return ret;
}

template <typename F>
struct funcinfo;

template <typename Return, typename... Args>
struct funcinfo<Return(Args...)>
{
  using return_t = Return;
  using argument_t = std::tuple<Args...>;
};

static int test_catalyst_abi()
{
  int ret = EXIT_SUCCESS;

  // Only add assertions to this list; removal or modification of any
  // checks constitutes an ABI break.

  // catalyst_initialize
  {
    using func_types = funcinfo<decltype(catalyst_initialize)>;
    abi_require(&catalyst_initialize, "catalyst_initialize must be defined");
    static_assert(std::is_same<func_types::return_t, enum catalyst_status>::value,
      "Catalyst API functions must return catalyst_status");
    abi_require(std::tuple_size<func_types::argument_t>::value == 1,
      "catalyst_initialize must take one argument");
    static_assert(
      std::is_same<std::tuple_element<0, func_types::argument_t>::type, const conduit_node*>::value,
      "catalyst_initialize should take a const conduit_node*");
  }

  // catalyst_execute
  {
    using func_types = funcinfo<decltype(catalyst_execute)>;
    abi_require(&catalyst_execute, "catalyst_execute must be defined");
    static_assert(std::is_same<func_types::return_t, enum catalyst_status>::value,
      "Catalyst API functions must return catalyst_status");
    abi_require(std::tuple_size<func_types::argument_t>::value == 1,
      "catalyst_execute must take one argument");
    static_assert(
      std::is_same<std::tuple_element<0, func_types::argument_t>::type, const conduit_node*>::value,
      "catalyst_execute should take a const conduit_node*");
  }

  // catalyst_finalize
  {
    using func_types = funcinfo<decltype(catalyst_finalize)>;
    abi_require(&catalyst_finalize, "catalyst_finalize must be defined");
    static_assert(std::is_same<func_types::return_t, enum catalyst_status>::value,
      "Catalyst API functions must return catalyst_status");
    abi_require(std::tuple_size<func_types::argument_t>::value == 1,
      "catalyst_finalize must take one argument");
    static_assert(
      std::is_same<std::tuple_element<0, func_types::argument_t>::type, const conduit_node*>::value,
      "catalyst_finalize should take a const conduit_node*");
  }

  // catalyst_about
  {
    using func_types = funcinfo<decltype(catalyst_about)>;
    abi_require(&catalyst_about, "catalyst_about must be defined");
    static_assert(std::is_same<func_types::return_t, enum catalyst_status>::value,
      "Catalyst API functions must return catalyst_status");
    abi_require(
      std::tuple_size<func_types::argument_t>::value == 1, "catalyst_about must take one argument");
    static_assert(
      std::is_same<std::tuple_element<0, func_types::argument_t>::type, conduit_node*>::value,
      "catalyst_about should take a conduit_node*");
  }

  // catalyst_results
  {
    using func_types = funcinfo<decltype(catalyst_results)>;
    abi_require(&catalyst_results, "catalyst_results must be defined");
    static_assert(std::is_same<func_types::return_t, enum catalyst_status>::value,
      "Catalyst API functions must return catalyst_status");
    abi_require(std::tuple_size<func_types::argument_t>::value == 1,
      "catalyst_results must take one argument");
    static_assert(
      std::is_same<std::tuple_element<0, func_types::argument_t>::type, conduit_node*>::value,
      "catalyst_results should take a conduit_node*");
  }

  return ret;
}

static int test_catalyst_impl()
{
  int ret = EXIT_SUCCESS;

  // Only add assertions to this list; removal or modification of any
  // checks constitutes an ABI break.

  constexpr size_t offsets_32bit[] = { 0, 4, 8, 12, 16, 20 };
  constexpr size_t offsets_64bit[] = { 0, 8, 16, 24, 32, 40 };
  constexpr size_t offsets_64bit_packed[] = { 0, 4, 12, 20, 28, 36 };
  constexpr size_t offsets_128bit[] = { 0, 16, 32, 40, 48, 64 };
  constexpr size_t offsets_128bit_half_packed[] = { 0, 8, 24, 32, 40, 56 };
  constexpr size_t offsets_128bit_packed[] = { 0, 4, 20, 28, 36, 52 };

  const size_t* offsets = nullptr;

  if (sizeof(void*) == 4)
  {
    offsets = offsets_32bit;
  }
  else if (sizeof(void*) == 8)
  {
    if (alignof(void*) == 8)
    {
      offsets = offsets_64bit;
    }
    else
    {
      offsets = offsets_64bit_packed;
    }
  }
  else if (sizeof(void*) == 16)
  {
    if (alignof(void*) == 16)
    {
      offsets = offsets_128bit;
    }
    else if (alignof(void*) == 8)
    {
      offsets = offsets_128bit_half_packed;
    }
    else
    {
      offsets = offsets_128bit_packed;
    }
  }

  if (!offsets)
  {
    fprintf(stderr, "unknown ABI layout; actual offsets:\n");
    fprintf(stderr, "version: %zu\n", offsetof(catalyst_impl, version));
    fprintf(stderr, "initialize: %zu\n", offsetof(catalyst_impl, initialize));
    fprintf(stderr, "execute: %zu\n", offsetof(catalyst_impl, execute));
    fprintf(stderr, "finalize: %zu\n", offsetof(catalyst_impl, finalize));
    fprintf(stderr, "about: %zu\n", offsetof(catalyst_impl, about));
    fprintf(stderr, "results: %zu\n", offsetof(catalyst_impl, results));
    return EXIT_FAILURE;
  }

  // version
  {
    static_assert(
      std::is_same<decltype(catalyst_impl::version), int>::value, "the version must be an int");
    abi_require(offsetof(catalyst_impl, version) == 0,
      "the offset of the catalyst_impl::version is not expected");
  }

  // initialize
  {
    static_assert(
      std::is_same<decltype(catalyst_impl::initialize), decltype(&catalyst_initialize)>::value,
      "the initialize member must be a compatible function pointer");
    abi_require(offsetof(catalyst_impl, initialize) == 8,
      "the offset of the catalyst_impl::initialize must be 8");
  }

  // execute
  {
    static_assert(
      std::is_same<decltype(catalyst_impl::execute), decltype(&catalyst_execute)>::value,
      "the execute member must be a compatible function pointer");
    abi_require(offsetof(catalyst_impl, execute) == 16,
      "the offset of the catalyst_impl::execute must be 16");
  }

  // finalize
  {
    static_assert(
      std::is_same<decltype(catalyst_impl::finalize), decltype(&catalyst_finalize)>::value,
      "the finalize member must be a compatible function pointer");
    abi_require(offsetof(catalyst_impl, finalize) == 24,
      "the offset of the catalyst_impl::finalize must be 24");
  }

  // about
  {
    static_assert(std::is_same<decltype(catalyst_impl::about), decltype(&catalyst_about)>::value,
      "the about member must be a compatible function pointer");
    abi_require(
      offsetof(catalyst_impl, about) == 32, "the offset of the catalyst_impl::about must be 32");
  }

  // results
  {
    static_assert(
      std::is_same<decltype(catalyst_impl::results), decltype(&catalyst_results)>::value,
      "the results member must be a compatible function pointer");
    abi_require(offsetof(catalyst_impl, results) == 40,
      "the offset of the catalyst_impl::results must be 40");
  }

  return ret;
}

static int test_catalyst_stub()
{
  int ret = EXIT_SUCCESS;

  // Only add assertions to this list; removal or modification of any
  // checks constitutes an ABI break.

  // initialize
  {
    static_assert(
      std::is_same<decltype(catalyst_stub_initialize), decltype(catalyst_initialize)>::value,
      "the stub initialize function must be a compatible function");
  }

  // execute
  {
    static_assert(
      std::is_same<decltype(catalyst_stub_finalize), decltype(catalyst_finalize)>::value,
      "the stub finalize function must be a compatible function");
  }

  // finalize
  {
    static_assert(std::is_same<decltype(catalyst_stub_execute), decltype(catalyst_execute)>::value,
      "the stub execute function must be a compatible function");
  }

  // about
  {
    static_assert(std::is_same<decltype(catalyst_stub_about), decltype(catalyst_about)>::value,
      "the stub about function must be a compatible function");
  }

  // results
  {
    static_assert(std::is_same<decltype(catalyst_stub_results), decltype(catalyst_results)>::value,
      "the stub results function must be a compatible function");
  }

  return ret;
}

int main(int argc, char* argv[])
{
  int ret = EXIT_SUCCESS;

  int test_ret = test_catalyst_status();
  if (test_ret != EXIT_SUCCESS)
  {
    ret = test_ret;
  }

  test_ret = test_catalyst_abi();
  if (test_ret != EXIT_SUCCESS)
  {
    ret = test_ret;
  }

  test_ret = test_catalyst_impl();
  if (test_ret != EXIT_SUCCESS)
  {
    ret = test_ret;
  }

  test_ret = test_catalyst_stub();
  if (test_ret != EXIT_SUCCESS)
  {
    ret = test_ret;
  }

  return ret;
}
