set(headers
  catalyst.h
  catalyst_api.h
  catalyst_impl.h
  catalyst_stub.h
  catalyst.hpp
  catalyst_conduit.hpp
  catalyst_conduit_error.hpp
  catalyst_dump_node.h
  ${CMAKE_CURRENT_BINARY_DIR}/catalyst_export.h
  ${CMAKE_CURRENT_BINARY_DIR}/catalyst_version.h)
configure_file(catalyst_version.h.in catalyst_version.h)

#------------------------------------------------------------
# Add an interface library just to setup include dirs.
add_library(catalyst_headers INTERFACE)
target_include_directories(catalyst_headers
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${CATALYST_INSTALL_INCLUDE_DIR}>)
add_library(catalyst::catalyst_headers ALIAS catalyst_headers)

add_library(catalyst
  catalyst_api.c
  catalyst_api_default.cpp
  ${headers})
target_link_libraries(catalyst
  PUBLIC
    catalyst::blueprint_headers
    catalyst::conduit_headers
    catalyst::catalyst_headers
  PRIVATE
    conduit
    blueprint
    libyaml
    b64
    ${CMAKE_DL_LIBS})

if (BUILD_SHARED_LIBS)
  target_compile_definitions(catalyst
    PRIVATE
      conduit_EXPORTS
      conduit_blueprint_EXPORTS)
endif ()

add_library(catalyst::catalyst ALIAS catalyst)

if (CATALYST_USE_MPI)
  target_link_libraries(catalyst INTERFACE MPI::MPI_C)
  target_compile_definitions(catalyst INTERFACE CATALYST_USE_MPI)
endif ()

c_install_targets(catalyst catalyst_headers)
c_install_headers(
  HEADERS ${headers})

#-------------------------------------------------------------
# Generate export header.
set_target_properties(catalyst
  PROPERTIES
    DEFINE_SYMBOL catalyst_EXPORTS)
include(GenerateExportHeader)
generate_export_header(catalyst)