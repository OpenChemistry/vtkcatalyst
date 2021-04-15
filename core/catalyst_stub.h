/*
 * Distributed under OSI-approved BSD 3-Clause License. See
 * accompanying License.txt
 */

#ifndef catalyst_stub_h
#define catalyst_stub_h

#ifdef CATALYST_USE_MPI
#include "catalyst_dump_node.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#endif

// This file provides functions to use when implementing custom Catalyst
// implementation if you want to forward calls to the stub
// implementation.

void catalyst_stub_initialize(const conduit_node* params)
{
#ifdef CATALYST_USE_MPI
  dump_node(params, "initialize", 0, false);
#endif
}

void catalyst_stub_finalize(const conduit_node* params)
{
#ifdef CATALYST_USE_MPI
  dump_node(params, "finalize", 0, false);
#endif
}

void catalyst_stub_execute(const conduit_node* params)
{
#ifdef CATALYST_USE_MPI
  static unsigned long invocations = 0;
  dump_node(params, "execute", invocations, true);
  invocations++;
#endif
}

void catalyst_stub_about(conduit_node* params)
{
  conduit_node_set_path_char8_str(params, "catalyst/version", CATALYST_VERSION);
  conduit_node_set_path_char8_str(params, "catalyst/abi_version", CATALYST_ABI_VERSION);
  conduit_node_set_path_char8_str(params, "catalyst/implementation", "stub");

  // add information about all third-party dependencies.
  conduit_node* conduit_info = conduit_node_create();
  conduit_about(conduit_info);
  conduit_node_set_path_node(params, "catalyst/tpl/conduit", conduit_info);
  conduit_node_destroy(conduit_info);
}

#endif
