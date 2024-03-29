add_executable(test_catalyst_abi test_catalyst_abi.cpp)
target_link_libraries(test_catalyst_abi catalyst::catalyst)
target_compile_features(test_catalyst_abi PRIVATE cxx_std_17)
add_test(NAME catalyst-abi COMMAND test_catalyst_abi)

add_executable(test_conduit_abi test_conduit_abi.cpp)
target_link_libraries(test_conduit_abi catalyst::catalyst)
add_test(NAME conduit-abi COMMAND test_conduit_abi)

find_program(NM_EXECUTABLE NAMES nm DOC "`nm` executable")
if (NM_EXECUTABLE)
  add_test(NAME catalyst-abi-nm
    COMMAND
      "${CMAKE_COMMAND}"
      "-Dnm=${NM_EXECUTABLE}"
      "-Dlibrary=$<TARGET_FILE:catalyst::catalyst>"
      "-Dsymbols=${CMAKE_CURRENT_SOURCE_DIR}/catalyst.symbols.txt"
      "-Dapple_mangle=$<BOOL:${APPLE}>"
      -P "${CMAKE_CURRENT_SOURCE_DIR}/nm.cmake")
endif ()

find_program(DUMPBIN_EXECUTABLE NAMES dumpbin DOC "`dumpbin` executable")
if (DUMPBIN_EXECUTABLE)
  add_test(NAME catalyst-abi-dumpbin
    COMMAND
      "${CMAKE_COMMAND}"
      "-Ddumpbin=${DUMPBIN_EXECUTABLE}"
      "-Dlibrary=$<TARGET_FILE:catalyst::catalyst>"
      "-Dsymbols=${CMAKE_CURRENT_SOURCE_DIR}/catalyst.symbols.txt"
      -P "${CMAKE_CURRENT_SOURCE_DIR}/dumpbin.cmake")
endif ()
