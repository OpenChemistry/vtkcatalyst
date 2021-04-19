cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_EXAMPLES)

add_catalyst_example(about)
add_catalyst_example(adaptor0)
if (${CATALYST_USE_MPI})
  add_catalyst_example(replay)
endif()
