add_subdirectory(impls)

add_executable(test_double_impl test_double_impl.c)
target_link_libraries(test_double_impl catalyst::catalyst)
add_test(NAME catalyst-impl-double COMMAND test_double_impl)
