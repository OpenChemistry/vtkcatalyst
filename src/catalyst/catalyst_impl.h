/*
 * Distributed under OSI-approved BSD 3-Clause License. See
 * accompanying License.txt
 */

#ifndef catalyst_impl_h
#define catalyst_impl_h

#include <catalyst_api.h>

// include mangled conduit C API.
#include <conduit.h>

#ifdef __cplusplus
extern "C"
{
#endif

  struct catalyst_impl
  {
    int version;
    enum catalyst_error (*initialize)(const conduit_node*);
    enum catalyst_error (*execute)(const conduit_node*);
    enum catalyst_error (*finalize)(const conduit_node*);
    enum catalyst_error (*about)(conduit_node*);
  };

#ifdef __cplusplus
} // extern "C"
#endif

#endif // #ifndef catalyst_impl_h
