cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_REPLAY_TESTS)

# MPI should be enabled already, but good to leave this check in
if (${CATALYST_USE_MPI})
  add_catalyst_test(replay_ranks_mismatch)
endif()
