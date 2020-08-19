# Macros and other CMake code part of the Catalyst SDK i.e.
# API used to build Catalyst API implementations.

#[==[
Mark a target as the Catalyst API implementation.

~~~{.cmake}
catalyst_library(
  TARGET    <target>)
~~~

The `TARGET` identifies the target added using an `add_library` call.
This function ensures that properties on the target are set up
appropriately so that the generated library is ABI compatible
with the Catalyst stub implementation.
#]==]
function(catalyst_library)
  cmake_parse_arguments(PARSE_ARGV 0 arg "" "TARGET" "")
  if (arg_UNPARSED_ARGUMENT)
    message(FATAL_ERROR
      "Unknown argument(s) passed to 'catalyst_library': '${arg_UNPARSED_ARGUMENT}'")
  endif()
  target_link_libraries(${arg_TARGET}
    PUBLIC
      catalyst::core
      catalyst::conduit_headers
    PRIVATE
      catalyst::conduit
      catalyst::blueprint)
  set_target_properties(${arg_TARGET}
    PROPERTIES
      VERSION   "${CATALYST_ABI_VERSION}"
      SOVERSION "${CATALYST_ABI_VERSION}"
      OUTPUT_NAME "catalyst")
endfunction()
