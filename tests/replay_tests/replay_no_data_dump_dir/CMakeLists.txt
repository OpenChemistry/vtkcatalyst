cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_REPLAY_NO_DATA_DUMP_DIR)

find_package(catalyst
  REQUIRED
  COMPONENTS SDK)

# No need to repeat the same adaptor and driver multiple times
# across tests
get_filename_component(PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)
set(src_dir "${PARENT_DIR}/common_src_dir")


add_library(no_data_dump_dir_adapter
 "${src_dir}/common_replay_adaptor.cxx")

# use this function call to mark any library as the
# Catalyst API implementation.
catalyst_library(TARGET no_data_dump_dir_adapter)

include(CTest)
if (BUILD_TESTING)
  # Add a test that links against the standard Catalyst library
  # However at runtime ensures the implementation built here
  # is being used.
  set(CMAKE_SKIP_BUILD_RPATH ON)
  add_executable(no_data_dump_dir_driver "${src_dir}/common_replay_driver.cxx")

  target_link_libraries(no_data_dump_dir_driver
    PRIVATE
      catalyst::catalyst)

  set(num_ranks_if_mpi 2)
  if (CATALYST_USE_MPI)
    set(mpi_prefix_or_blank
        ${MPIEXEC_EXECUTABLE} ${MPIEXEC_NUMPROC_FLAG} ${num_ranks_if_mpi})
  endif()

  # Not specifying a data_dump_dir should be fine when calling the stub implementation.
  # Nothing should be written out
  add_test(
    NAME no_write_out
    COMMAND ${mpi_prefix_or_blank} "$<TARGET_FILE:no_data_dump_dir_driver>"
  )

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


  set(environ_with_impl
    "${pathvar_name}=$<TARGET_FILE_DIR:no_data_dump_dir_adapter>${sep}$ENV{${pathvar_name}}"
  )

  set_tests_properties(no_write_out
    PROPERTIES
      ENVIRONMENT "${environ_with_impl}"
      FIXTURES_SETUP no_write_out_fixture)

  # Add a test to check behavior when no data_dump_dir is specified to replay
  # command. Should error out.
  add_test(
    NAME no_data_dump_dir_read_in
    COMMAND ${mpi_prefix_or_blank} ${catalyst_replay_command}
  )

  set_tests_properties(no_data_dump_dir_read_in
    PROPERTIES
      ENVIRONMENT "${environ_with_impl}"
      PASS_REGULAR_EXPRESSION "ERROR: Expected 1 argument, the data dump directory"
      FIXTURES_REQUIRED no_write_out_fixture)

endif()
