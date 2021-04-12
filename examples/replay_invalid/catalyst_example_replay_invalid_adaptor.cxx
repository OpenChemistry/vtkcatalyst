/*
 * Distributed under OSI-approved BSD 3-Clause License. See
 * accompanying License.txt
 */
#include <catalyst.hpp>
#include <catalyst_stub.h>
#include <stdexcept>

// Call the stub implementation and check the node passed in.

//-----------------------------------------------------------------------------
void catalyst_initialize(const conduit_node* params)
{
  catalyst_stub_initialize(params);

  // TODO: Improve below tests
  if (!conduit_node_has_path(params, "stage") || !conduit_node_has_path(params, "data"))
  {
    throw std::runtime_error("Missing paths");
  }
}

//-----------------------------------------------------------------------------
void catalyst_execute(const conduit_node* params)
{
  catalyst_stub_execute(params);

  if (!conduit_node_has_path(params, "stage") || !conduit_node_has_path(params, "data"))
  {
    throw std::runtime_error("Missing paths");
  }
}

//-----------------------------------------------------------------------------
void catalyst_finalize(const conduit_node* params)
{
  catalyst_stub_finalize(params);

  if (!conduit_node_has_path(params, "stage") || !conduit_node_has_path(params, "data"))
  {
    throw std::runtime_error("Missing paths");
  }
}

//-----------------------------------------------------------------------------
void catalyst_about(conduit_node* params)
{
  catalyst_stub_about(params);
}
