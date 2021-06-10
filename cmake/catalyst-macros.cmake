# Macros and other CMake code part of the Catalyst SDK i.e.
# API used to build Catalyst API implementations.

#[==[
Make a catalyst implementation library.

~~~{.cmake}
catalyst_implementation(
  TARGET  <target>
  NAME    <name>
  [EXPORT <export>]
  [SOURCES <source>...]
  [LIBRARY_DESTINATION <destination>]
  )
~~~

The `TARGET` identifies the target to create in this function. This function
creates source files to adapt to the Catalyst ABI and creates a header for use
in the actual implementation.

`LIBRARY_DESTINATION` defaults to `${CMAKE_INSTALL_LIBDIR}/catalyst` and
indicates where the library will be placed in the build and install tree.

The library will be installed with the export set provided to `EXPORT` if
given.
#]==]
function (catalyst_implementation)
  cmake_parse_arguments(PARSE_ARGV 0 catalyst_impl
    ""
    "NAME;TARGET;LIBRARY_DESTINATION;EXPORT"
    "SOURCES")
  if (catalyst_impl_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR
      "Unknown argument(s) passed to 'catalyst_implementation': '${catalyst_impl_UNPARSED_ARGUMENTS}'")
  endif ()

  if (NOT catalyst_impl_NAME)
    message(FATAL_ERROR
      "The `NAME` argument is required for `catalyst_implementation`.")
  endif ()

  if (NOT catalyst_impl_TARGET)
    message(FATAL_ERROR
      "The `TARGET` argument is required for `catalyst_implementation`.")
  endif ()

  if (NOT catalyst_impl_LIBRARY_DESTINATION)
    set(catalyst_impl_LIBRARY_DESTINATION
      "${CMAKE_INSTALL_LIBDIR}/catalyst")
  endif ()

  configure_file(
    "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/catalyst_impl.c.in"
    "${CMAKE_CURRENT_BINARY_DIR}/catalyst_impl_${catalyst_impl_NAME}.c"
    @ONLY)
  configure_file(
    "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/catalyst_impl.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/catalyst_impl_${catalyst_impl_NAME}.h"
    @ONLY)

  if (BUILD_SHARED_LIBS)
    set(catalyst_impl_library_type MODULE)
  else ()
    set(catalyst_impl_library_type STATIC)
  endif ()

  if (catalyst_impl_LIBRARY_DESTINATION)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${catalyst_impl_LIBRARY_DESTINATION}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${catalyst_impl_LIBRARY_DESTINATION}")
  endif ()

  add_library("${catalyst_impl_TARGET}" "${catalyst_impl_library_type}"
    "${CMAKE_CURRENT_BINARY_DIR}/catalyst_impl_${catalyst_impl_NAME}.c"
    "${CMAKE_CURRENT_BINARY_DIR}/catalyst_impl_${catalyst_impl_NAME}.h"
    ${catalyst_impl_SOURCES})
  target_include_directories("${catalyst_impl_TARGET}"
    PRIVATE
      "${CMAKE_CURRENT_BINARY_DIR}")
  target_link_libraries("${catalyst_impl_TARGET}"
    PUBLIC
      catalyst::catalyst)
  set_target_properties("${catalyst_impl_TARGET}"
    PROPERTIES
      OUTPUT_NAME "catalyst-${catalyst_impl_NAME}")

  set(catalyst_impl_export_args)
  if (catalyst_impl_EXPORT)
    set(catalyst_impl_export_args
      EXPORT "${catalyst_impl_EXPORT}")
  endif ()

  if (catalyst_impl_LIBRARY_DESTINATION)
    install(
      TARGETS "${catalyst_impl_TARGET}"
      ${catalyst_impl_export_args}
      RUNTIME DESTINATION "${catalyst_impl_LIBRARY_DESTINATION}"
      LIBRARY DESTINATION "${catalyst_impl_LIBRARY_DESTINATION}")
  endif ()
endfunction ()
