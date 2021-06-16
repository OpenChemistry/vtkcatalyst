/*
 * Distributed under OSI-approved BSD 3-Clause License. See
 * accompanying License.txt
 */

#ifndef catalyst_api_h
#define catalyst_api_h

#include <catalyst_export.h>

// include mangled conduit C API.
#include <conduit.h>

#ifdef __cplusplus
extern "C"
{
#endif

  enum catalyst_error
  {
    // No error; everything is OK.
    catalyst_error_ok = 0,
    // An implementation has not been loaded.
    catalyst_error_no_implementation,
    // An implementation has already been loaded.
    catalyst_error_already_loaded,
    // The implementation library was not found.
    catalyst_error_not_found,
    // The library did not contain a Catalyst API structure.
    catalyst_error_not_catalyst,
    // The library did not provide all of the required API functions.
    catalyst_error_incomplete,
    // The library did not provide a supported version of the API.
    catalyst_error_unsupported_version,
  };

  /**
   * Initialize Catalyst.
   * TODO: add more docs
   */
  CATALYST_EXPORT enum catalyst_error catalyst_initialize(const conduit_node* params);

  /**
   * Execute per timestep.
   * TODO: add more docs.
   */
  CATALYST_EXPORT enum catalyst_error catalyst_execute(const conduit_node* params);

  /**
   * finalize catalyst.
   * TODO: more docs
   */
  CATALYST_EXPORT enum catalyst_error catalyst_finalize(const conduit_node* params);

  /**
   * Returns information about the catalyst library
   */
  CATALYST_EXPORT enum catalyst_error catalyst_about(conduit_node* params);

  /**
   * Get results from the catalyst library.
   * TODO: add more docs.
   */
  CATALYST_EXPORT enum catalyst_error catalyst_results(conduit_node* params);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // #ifndef catalyst_api_h
