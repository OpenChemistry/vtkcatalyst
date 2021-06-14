set(CATALYST_BUILD_TESTING             ON CACHE BOOL "")
set(CATALYST_BUILD_STUB_IMPLEMENTATION ON CACHE BOOL "")
set(CATALYST_BUILD_SHARED_LIBS         ON CACHE BOOL "")

function (configuration_flag variable configuration)
  if ("$ENV{CMAKE_CONFIGURATION}" MATCHES "${configuration}")
    set("${variable}" ON CACHE BOOL "")
  else ()
    set("${variable}" OFF CACHE BOOL "")
  endif ()
endfunction ()

configuration_flag(CATALYST_USE_MPI "mpi")
configuration_flag(CATALYST_BUILD_REPLAY "replay")
