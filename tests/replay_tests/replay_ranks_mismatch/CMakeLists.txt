cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_REPLAY_RANKS_MISMATCH)

find_package(catalyst
  REQUIRED
  COMPONENTS SDK)

# No need to repeat the same adaptor and driver multiple times
# across tests
get_filename_component(PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)
set(src_dir "${PARENT_DIR}/common_src_dir")

catalyst_implementation(
  TARGET  replay_ranks_mismatch_adaptor
  NAME    replay
  SOURCES "${src_dir}/common_replay_adaptor.cxx")

include(CTest)
if (BUILD_TESTING)
  add_executable(replay_ranks_mismatch_driver "${src_dir}/common_replay_driver.cxx")

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
            "$<TARGET_FILE_DIR:replay_ranks_mismatch_adaptor>"
  )

  # Set up the data dump directory for the test
  set(data_dump_directory "${CMAKE_CURRENT_BINARY_DIR}/data_dump/")
  file(MAKE_DIRECTORY ${data_dump_directory})

  set(write_out_environ_str
     "CATALYST_DATA_DUMP_DIRECTORY=${data_dump_directory}"
  )

  set_tests_properties(replay_ranks_mismatch_write_out
    PROPERTIES
      ENVIRONMENT "${write_out_environ_str}"
      FIXTURES_SETUP replay_ranks_mismatch_write_out_fixture)

  add_test(
    NAME replay_ranks_mismatch_read_in
    COMMAND ${MPIEXEC_EXECUTABLE} ${MPIEXEC_NUMPROC_FLAG} ${num_ranks_read_in}
            ${catalyst_replay_command} ${data_dump_directory}
  )

  set_tests_properties(replay_ranks_mismatch_read_in
    PROPERTIES
      PASS_REGULAR_EXPRESSION "ERROR: Mismatch in the number of ranks"
      FIXTURES_REQUIRED replay_ranks_mismatch_write_out_fixture)

endif()
