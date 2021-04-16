/*
 * Distributed under OSI-approved BSD 3-Clause License. See
 * accompanying License.txt
 */

#include <catalyst.h>
#include <catalyst.hpp>
#include <catalyst_stub.h>

//-----------------------------------------------------------------------------
void catalyst_initialize(const conduit_node* params)
{
  conduit_cpp::Node temp;
  temp.to_double();

  catalyst_stub_initialize(params);
}

//-----------------------------------------------------------------------------
void catalyst_execute(const conduit_node* params)
{
  catalyst_stub_execute(params);
}

//-----------------------------------------------------------------------------
void catalyst_finalize(const conduit_node* params)
{
  catalyst_stub_finalize(params);
}

//-----------------------------------------------------------------------------
void catalyst_about(conduit_node* params)
{
  catalyst_stub_about(params);
}
