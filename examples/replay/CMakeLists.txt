cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_REPLAY_EXAMPLE)

find_package(catalyst
  REQUIRED
  COMPONENTS SDK)

add_library(catalyst_example_replay_adaptor
 catalyst_example_replay_adaptor.cxx)

# use this function call to mark any library as the
# Catalyst API implementation.
catalyst_library(TARGET catalyst_example_replay_adaptor)

include(CTest)
if (BUILD_TESTING)
  find_package(MPI COMPONENTS CXX C REQUIRED)
  # Add a test that links against the standard Catalyst library
  # However at runtime ensures the implementation built here
  # is being used.
  set(CMAKE_SKIP_BUILD_RPATH ON)
  add_executable(replay_test replay_test.cxx)

  target_link_libraries(replay_test
    PRIVATE
      catalyst::catalyst)

  set(num_ranks_test 1)
  # Add a test for writing out the conduit nodes to disk
  add_test(
    NAME replay_test_write_out
    COMMAND ${MPIEXEC_EXECUTABLE} ${MPIEXEC_NUMPROC_FLAG} ${num_ranks_test}
            "$<TARGET_FILE:replay_test>"
  )

  # Set up the data dump directory for the test
  set(example_data_dump_directory "${CMAKE_CURRENT_BINARY_DIR}/data_dump/")
  file(MAKE_DIRECTORY ${example_data_dump_directory})

  # set test PATH to ensure our implementation of the Catalyst
  # library is loaded.
  set (pathvar_name)
  if (APPLE)
    set(pathvar_name "DYLD_LIBRARY_PATH")
    set(sep ":")
  elseif(WIN32)
    set(pathvar_name "PATH")
    set(sep "\;")
  elseif (UNIX)
    set(pathvar_name "LD_LIBRARY_PATH")
    set(sep ":")
  endif()

  set(environ_str
     "CATALYST_DATA_DUMP_DIRECTORY=${example_data_dump_directory}"
     "${pathvar_name}=$<TARGET_FILE_DIR:catalyst_example_replay_adaptor>${sep}$ENV{${pathvar_name}}"
    )

  set_tests_properties(replay_test_write_out
    PROPERTIES
      ENVIRONMENT "${environ_str}")

  add_test(
    NAME replay_test_read_in
    COMMAND ${MPIEXEC_EXECUTABLE} ${MPIEXEC_NUMPROC_FLAG} ${num_ranks_test}
            ${catalyst_replay_command} ${example_data_dump_directory}
  )
endif()
