cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_EXAMPLES)
if (CATALYST_BINARY_DIR)
  #------------------------------------------------------------------
  # add a test to do installation of catalyst
  set(install_prefix "${CMAKE_CURRENT_BINARY_DIR}/root")
  add_test(
    NAME  "install-prepare"
    COMMAND "${CMAKE_COMMAND}" -E rm -rf "${install_prefix}")
  add_test(
    NAME  "install"
    COMMAND "${CMAKE_COMMAND}"
            --build ${CATALYST_BINARY_DIR}
            --target "install"
            --config $<CONFIGURATION>
    WORKING_DIRECTORY ${CATALYST_BINARY_DIR})
  set_tests_properties("install"
    PROPERTIES
      ENVIRONMENT "DESTDIR=${install_prefix}")
  set_tests_properties("install-prepare"
    PROPERTIES
      FIXTURES_SETUP "install-prepare")
  set_tests_properties("install"
    PROPERTIES
      FIXTURES_REQUIRED "install-prepare"
      FIXTURES_SETUP    "install")
endif()

include("${CMAKE_SOURCE_DIR}/cmake/catalyst-test-macros.cmake")

add_catalyst_example(about)
add_catalyst_example(adaptor0)
if (${CATALYST_USE_MPI})
  add_catalyst_example(replay)
endif()
