/*
 * Distributed under OSI-approved BSD 3-Clause License. See
 * accompanying License.txt
 */

#include <catalyst.h>
#include <catalyst_stub.h>

#include "catalyst_impl_double.h"

static double data = 0.;

//-----------------------------------------------------------------------------
enum catalyst_error catalyst_initialize_double(const conduit_node* params)
{
  conduit_node* p = (conduit_node*)params;
  conduit_node* d = conduit_node_fetch(p, "data");
  if (d)
  {
    const conduit_datatype* dtype = conduit_node_dtype(d);
    if (conduit_datatype_is_double(dtype))
    {
      data = conduit_node_as_double(d);
    }
  }

  return catalyst_error_ok;
}

//-----------------------------------------------------------------------------
enum catalyst_error catalyst_execute_double(const conduit_node* params)
{
  conduit_node* p = (conduit_node*)params;
  conduit_node* d = conduit_node_fetch(p, "data");
  if (d)
  {
    const conduit_datatype* dtype = conduit_node_dtype(d);
    if (conduit_datatype_is_double(dtype))
    {
      data = conduit_node_as_double(d);
    }
  }

  return catalyst_error_ok;
}

//-----------------------------------------------------------------------------
enum catalyst_error catalyst_finalize_double(const conduit_node* params)
{
  conduit_node* p = (conduit_node*)params;
  conduit_node_set_path_double(p, "data", data);

  data = 0.;

  return catalyst_error_ok;
}

//-----------------------------------------------------------------------------
enum catalyst_error catalyst_about_double(conduit_node* params)
{
  enum catalyst_error err = catalyst_stub_about(params);

  conduit_node_set_path_char8_str(params, "catalyst/implementation", "test");
  conduit_node_set_path_double(params, "data", data);

  return err;
}
