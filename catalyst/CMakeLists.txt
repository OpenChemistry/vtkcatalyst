add_library(catalyst
  catalyst.cxx)
add_library(catalyst::catalyst ALIAS catalyst)
c_install_targets(catalyst)

include(catalyst-sdk-macros)
catalyst_library(TARGET catalyst)
