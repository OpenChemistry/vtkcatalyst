add_library(catalyst
  catalyst.cxx)
add_library(catalyst::catalyst ALIAS catalyst)
catalyst_library(TARGET catalyst
                 INSTALL_EXPORT_DEFAULT)
