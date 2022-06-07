add_executable(test_catalyst_abi test_catalyst_abi.cpp)
target_link_libraries(test_catalyst_abi catalyst::catalyst)
target_compile_features(test_catalyst_abi PRIVATE cxx_std_17)
add_test(NAME catalyst-abi COMMAND test_catalyst_abi)

add_executable(test_conduit_abi test_conduit_abi.cpp)
target_link_libraries(test_conduit_abi catalyst::catalyst)
add_test(NAME conduit-abi COMMAND test_conduit_abi)
