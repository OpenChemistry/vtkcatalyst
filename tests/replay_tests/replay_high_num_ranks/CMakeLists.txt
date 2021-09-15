cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_REPLAY_HIGH_NUM_RANKS)

find_package(catalyst
  REQUIRED
  COMPONENTS SDK)

# No need to repeat the same adaptor and driver multiple times
# across tests
get_filename_component(PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)
set(src_dir "${PARENT_DIR}/common_src_dir")

catalyst_implementation(
  TARGET  high_num_ranks_adaptor
  NAME    replay
  SOURCES "${src_dir}/common_replay_adaptor.cxx")

include(CTest)
if (BUILD_TESTING)
  add_executable(high_num_ranks_driver "${src_dir}/common_replay_driver.cxx")
  target_link_libraries(high_num_ranks_driver
    PRIVATE
      catalyst::catalyst
      MPI::MPI_C)
  target_compile_definitions(high_num_ranks_driver
    PRIVATE CATALYST_USE_MPI
            # force `mpi.h` to not include cxx components to avoid
            # unnecessary dependency on MPI_CPP
            MPICH_SKIP_MPICXX
            OMPI_SKIP_MPICXX
            MPI_NO_CPPBIND
            _MPICC_H)

  set(num_ranks 10)
  set(mpi_prefix
      ${MPIEXEC_EXECUTABLE} ${MPIEXEC_NUMPROC_FLAG} ${num_ranks})

  # Add a test for writing out the conduit nodes to disk
  add_test(
    NAME high_num_ranks_write_out
    COMMAND ${mpi_prefix} "$<TARGET_FILE:high_num_ranks_driver>"
            "$<TARGET_FILE_DIR:high_num_ranks_adaptor>"
  )

  # Set up the data dump directory for the test
  set(data_dump_directory "${CMAKE_CURRENT_BINARY_DIR}/data_dump/")
  file(MAKE_DIRECTORY ${data_dump_directory})

  set(write_out_environ_str
     "CATALYST_DATA_DUMP_DIRECTORY=${data_dump_directory}"
  )

  set_tests_properties(high_num_ranks_write_out
    PROPERTIES
      ENVIRONMENT "${write_out_environ_str}"
      FIXTURES_SETUP write_out)

  add_test(
    NAME high_num_ranks_read_in
    COMMAND ${mpi_prefix} ${catalyst_replay_command} ${data_dump_directory}
  )

  set_tests_properties(high_num_ranks_read_in
    PROPERTIES
      FIXTURES_REQUIRED write_out)

endif()
