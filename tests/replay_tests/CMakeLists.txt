cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_REPLAY_TESTS)

# MPI should be enabled already, but good to leave this check in
if (${CATALYST_USE_MPI})
  add_catalyst_test(replay_ranks_mismatch)
  add_catalyst_test(replay_no_data_dump_dir)
  add_catalyst_test(replay_missing_initialize_data)
  add_catalyst_test(replay_missing_execute_invc)
endif()
