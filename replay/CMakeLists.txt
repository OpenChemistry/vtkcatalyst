add_executable(catalyst_replay catalyst_replay.cpp)

target_link_libraries(catalyst_replay PRIVATE catalyst)

set(catalyst_replay_command "$<TARGET_FILE:catalyst_replay>" PARENT_SCOPE)
