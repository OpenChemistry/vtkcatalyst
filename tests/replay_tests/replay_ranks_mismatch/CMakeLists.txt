cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_REPLAY_RANKS_MISMATCH)

find_package(catalyst
  REQUIRED
  COMPONENTS SDK)

add_library(replay_ranks_mismatch_adaptor
 replay_ranks_mismatch_adaptor.cxx)

# use this function call to mark any library as the
# Catalyst API implementation.
catalyst_library(TARGET replay_ranks_mismatch_adaptor)

include(CTest)
if (BUILD_TESTING)
  find_package(MPI COMPONENTS CXX C REQUIRED)
  # Add a test that links against the standard Catalyst library
  # However at runtime ensures the implementation built here
  # is being used.
  set(CMAKE_SKIP_BUILD_RPATH ON)
  add_executable(replay_ranks_mismatch_driver replay_ranks_mismatch_driver.cxx)

  target_link_libraries(replay_ranks_mismatch_driver
    PRIVATE
      catalyst::catalyst)

  # Make sure that we error out if the number of ranks is different
  set(num_ranks_write_out 1)
  set(num_ranks_read_in 2)

  # Add a test for writing out the conduit nodes to disk
  add_test(
    NAME replay_ranks_mismatch_write_out
    COMMAND ${MPIEXEC_EXECUTABLE} ${MPIEXEC_NUMPROC_FLAG} ${num_ranks_write_out}
            "$<TARGET_FILE:replay_ranks_mismatch_driver>"
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
     "${pathvar_name}=$<TARGET_FILE_DIR:replay_ranks_mismatch_adaptor>${sep}$ENV{${pathvar_name}}"
    )

  set_tests_properties(replay_ranks_mismatch_write_out
    PROPERTIES
      ENVIRONMENT "${environ_str}"
      FIXTURES_SETUP replay_ranks_mismatch_write_out_fixture)

  add_test(
    NAME replay_ranks_mismatch_read_in
    COMMAND ${MPIEXEC_EXECUTABLE} ${MPIEXEC_NUMPROC_FLAG} ${num_ranks_read_in}
            ${catalyst_replay_command} ${example_data_dump_directory}
  )

  set_tests_properties(replay_ranks_mismatch_read_in
    PROPERTIES
      WILL_FAIL TRUE
      FIXTURES_REQUIRED replay_ranks_mismatch_write_out_fixture)

endif()
