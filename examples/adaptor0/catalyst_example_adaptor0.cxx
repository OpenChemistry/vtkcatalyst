/*
 * Distributed under OSI-approved BSD 3-Clause License. See
 * accompanying License.txt
 */
#include <catalyst.h>
#include <catalyst_stub.h>
#include <conduit.hpp>
#include <conduit_cpp_to_c.hpp>

#include "catalyst_impl_example_adaptor0.h"

//-----------------------------------------------------------------------------
enum catalyst_error catalyst_initialize_example_adaptor0(const conduit_node*)
{
  return catalyst_error_ok;
}

//-----------------------------------------------------------------------------
enum catalyst_error catalyst_execute_example_adaptor0(const conduit_node*)
{
  return catalyst_error_ok;
}

//-----------------------------------------------------------------------------
enum catalyst_error catalyst_finalize_example_adaptor0(const conduit_node*)
{
  return catalyst_error_ok;
}

//-----------------------------------------------------------------------------
enum catalyst_error catalyst_about_example_adaptor0(conduit_node* params)
{
  catalyst_stub_about(params);
  auto& cpp_params = (*conduit::cpp_node(params));
  cpp_params["catalyst"]["capabilities"].append().set("adaptor0");
  cpp_params["catalyst"]["implementation"] = "examples/adaptor0";

  return catalyst_error_ok;
}
