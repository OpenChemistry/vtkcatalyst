cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_EXAMPLES)

set(examples
    about
    adaptor0)

set(mpi_examples
    replay)

if (NOT DEFINED CATALYST_BINARY_DIR)
  find_package(catalyst VERSION 2.0 REQUIRED)
endif()

foreach(example ${examples})
  if (CATALYST_BINARY_DIR)
    add_catalyst_example(${example})
  else()
    add_subdirectory(${example})
  endif()
endforeach()

if (${CATALYST_USE_MPI})
  foreach(mpi_example ${mpi_examples})
    if (CATALYST_BINARY_DIR)
      add_catalyst_example(${mpi_example})
    else()
      add_subdirectory(${mpi_example})
    endif()
  endforeach()
endif()
