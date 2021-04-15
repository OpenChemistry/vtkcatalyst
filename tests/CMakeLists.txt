add_subdirectory(conduit_tests)
if (${CATALYST_USE_MPI})
  add_subdirectory(replay_tests)
endif()
