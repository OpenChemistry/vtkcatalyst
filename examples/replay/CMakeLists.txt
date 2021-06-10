cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_REPLAY_EXAMPLE)

find_package(catalyst
  REQUIRED
  COMPONENTS SDK)

# use this function call to mark any library as the
# Catalyst API implementation.
catalyst_implementation(
  TARGET  catalyst_example_replay_adaptor
  NAME    example_replay_adaptor
  SOURCES catalyst_example_replay_adaptor.cxx)

include(CTest)
if (BUILD_TESTING)
  add_executable(replay_test replay_test.cxx)

  target_link_libraries(replay_test
    PRIVATE
      catalyst::catalyst)

  set(num_ranks_if_mpi 2)
  set(mpi_prefix_or_blank)
  if (CATALYST_USE_MPI)
    set(mpi_prefix_or_blank
        ${MPIEXEC_EXECUTABLE} ${MPIEXEC_NUMPROC_FLAG} ${num_ranks_if_mpi})
  endif()

  # Add a test for writing out the conduit nodes to disk
  add_test(
    NAME replay_test_write_out
    COMMAND ${mpi_prefix_or_blank} "$<TARGET_FILE:replay_test>" "$<TARGET_FILE_DIR:catalyst_example_replay_adaptor>"
  )

  # Set up the data dump directory for the test
  set(example_data_dump_directory "${CMAKE_CURRENT_BINARY_DIR}/data_dump")
  file(MAKE_DIRECTORY ${example_data_dump_directory})

  set(write_out_environ_str
     "CATALYST_DATA_DUMP_DIRECTORY=${example_data_dump_directory}"
  )

  set_tests_properties(replay_test_write_out
    PROPERTIES
      ENVIRONMENT "${write_out_environ_str}"
      FIXTURES_SETUP write_out)

  add_test(
    NAME replay_test_read_in
    COMMAND ${mpi_prefix_or_blank} ${catalyst_replay_command} ${example_data_dump_directory}
  )

  set_tests_properties(replay_test_read_in
    PROPERTIES
      FIXTURES_REQUIRED write_out)

endif()
