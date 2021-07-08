add_executable(catalyst_replay catalyst_replay.cpp)

target_link_libraries(catalyst_replay PRIVATE catalyst)

if(CATALYST_USE_MPI)
  target_link_libraries(catalyst_replay PRIVATE MPI::MPI_CXX)
endif()
