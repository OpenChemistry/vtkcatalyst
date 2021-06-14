cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_REPLAY_HIGH_NUM_EXECUTE_INVC)

find_package(catalyst
  REQUIRED
  COMPONENTS SDK)

# No need to repeat the same adaptor and driver multiple times
# across tests. Here we'll just use the common adaptor.
get_filename_component(PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)
set(common_src_dir "${PARENT_DIR}/common_src_dir")


add_library(high_num_execute_invc_adaptor
 "${common_src_dir}/common_replay_adaptor.cxx")

# use this function call to mark any library as the
# Catalyst API implementation.
catalyst_library(TARGET high_num_execute_invc_adaptor)

include(CTest)
if (BUILD_TESTING)
  # Add a test that links against the standard Catalyst library
  # However at runtime ensures the implementation built here
  # is being used.
  set(CMAKE_SKIP_BUILD_RPATH ON)
  add_executable(high_num_execute_invc_driver "high_num_execute_invc_driver.cxx")

  target_link_libraries(high_num_execute_invc_driver
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
    NAME high_num_execute_invc_write_out
    COMMAND ${mpi_prefix_or_blank} "$<TARGET_FILE:high_num_execute_invc_driver>"
  )

  # Set up the data dump directory for the test
  set(data_dump_directory "${CMAKE_CURRENT_BINARY_DIR}/data_dump/")
  file(MAKE_DIRECTORY ${data_dump_directory})

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
    "${pathvar_name}=$<TARGET_FILE_DIR:high_num_execute_invc_adaptor>${sep}$ENV{${pathvar_name}}"
  )

  set(write_out_environ_str
     "CATALYST_DATA_DUMP_DIRECTORY=${data_dump_directory}"
     "${environ_with_impl}"
  )

  set_tests_properties(high_num_execute_invc_write_out
    PROPERTIES
      ENVIRONMENT "${write_out_environ_str}"
      FIXTURES_SETUP write_out)

  add_test(
    NAME high_num_execute_invc_read_in
    COMMAND ${mpi_prefix_or_blank} ${catalyst_replay_command} ${data_dump_directory}
  )

  set_tests_properties(high_num_execute_invc_read_in
    PROPERTIES
    ENVIRONMENT "${environ_with_impl}"
      FIXTURES_REQUIRED write_out)

endif()
