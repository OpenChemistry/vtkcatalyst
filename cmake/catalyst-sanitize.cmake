if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # Add option for enabling sanitizers
  option(CATALYST_ENABLE_SANITIZER "Build with sanitizer support." OFF)
  mark_as_advanced(CATALYST_ENABLE_SANITIZER)

  if (CATALYST_ENABLE_SANITIZER)
      set(CATALYST_SANITIZER "address"
      CACHE STRING "The sanitizer to use")
    mark_as_advanced(CATALYST_SANITIZER)

    #We're setting the CXX flags and C flags beacuse they're propagated down
    #independent of build type.
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=${CATALYST_SANITIZER}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=${CATALYST_SANITIZER}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=${CATALYST_SANITIZER}")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fsanitize=${CATALYST_SANITIZER}")
  endif ()
endif ()
