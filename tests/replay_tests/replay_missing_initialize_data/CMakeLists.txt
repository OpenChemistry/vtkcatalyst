cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_REPLAY_MISSING_INITIALIZE_DATA)

find_package(catalyst
  REQUIRED
  COMPONENTS SDK)

# No need to repeat the same adaptor and driver multiple times
# across tests
get_filename_component(PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)
set(src_dir "${PARENT_DIR}/common_src_dir")


add_library(missing_initialize_adaptor
 "${src_dir}/common_replay_adaptor.cxx")

# use this function call to mark any library as the
# Catalyst API implementation.
catalyst_library(TARGET missing_initialize_adaptor)

include(CTest)
if (BUILD_TESTING)
  # Add a test that links against the standard Catalyst library
  # However at runtime ensures the implementation built here
  # is being used.
  set(CMAKE_SKIP_BUILD_RPATH ON)
  add_executable(missing_initialize_driver "${src_dir}/common_replay_driver.cxx")

  target_link_libraries(missing_initialize_driver
    PRIVATE
      catalyst::catalyst)

  set(num_ranks_if_mpi 2)
  set(mpi_prefix_or_blank)
  if (${CATALYST_USE_MPI})
    find_package(MPI COMPONENTS CXX C REQUIRED)
    set(mpi_prefix_or_blank
        ${MPIEXEC_EXECUTABLE} ${MPIEXEC_NUMPROC_FLAG} ${num_ranks_if_mpi})
  endif()

  add_test(
    NAME missing_initialize_write_out
    COMMAND ${mpi_prefix_or_blank} "$<TARGET_FILE:missing_initialize_driver>"
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
    "${pathvar_name}=$<TARGET_FILE_DIR:missing_initialize_adaptor>${sep}$ENV{${pathvar_name}}"
  )

  set(write_out_environ_str
     "CATALYST_DATA_DUMP_DIRECTORY=${data_dump_directory}"
     "${environ_with_impl}"
  )

  set_tests_properties(missing_initialize_write_out
    PROPERTIES
      ENVIRONMENT "${write_out_environ_str}"
      FIXTURES_SETUP missing_initialize_write_out_fixture)


  # Remove one of the ranks' initialize data
  if (${CATALYST_USE_MPI})
    add_test(NAME remove_initialize
             COMMAND "${CMAKE_COMMAND}" -E rm
                     "${data_dump_directory}/initialize_params.conduit_bin.${num_ranks_if_mpi}.0")
  else()
    add_test(NAME remove_initialize
             COMMAND "${CMAKE_COMMAND}" -E rm
                     "${data_dump_directory}/initialize_params.conduit_bin.1.0")
  endif()

  set_tests_properties(remove_initialize
    PROPERTIES
      FIXTURES_REQUIRED missing_initialize_write_out_fixture
      FIXTURES_SETUP remove_initialize_fixture)


  # Add a test to check behavior when we're missing node data
  # for one rank's initialize stage.
  add_test(
    NAME missing_initialize_read_in
    COMMAND ${mpi_prefix_or_blank} ${catalyst_replay_command} ${data_dump_directory}
  )

  # The expected error message will be different based on how many files we write out,
  # which depends on the number of ranks.
  set(pass_str "ERROR: Missing node data for at least one stage")
  if (${CATALYST_USE_MPI} AND ${num_ranks_if_mpi} GREATER 1)
    set(pass_str "ERROR: Mismatch in the number of calls to initialize or finalize")
  endif()

  set_tests_properties(missing_initialize_read_in
    PROPERTIES
      ENVIRONMENT "${environ_with_impl}"
      PASS_REGULAR_EXPRESSION ${pass_str}
      FIXTURES_REQUIRED remove_initialize_fixture)

endif()
