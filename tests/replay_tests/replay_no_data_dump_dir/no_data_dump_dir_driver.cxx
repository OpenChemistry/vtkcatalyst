/*
 * Distributed under OSI-approved BSD 3-Clause License. See
 * accompanying License.txt
 */

#include "catalyst.hpp"
#include "mpi.h"
#include <iostream>

int main(int argc, char* argv[])
{
  MPI_Init(&argc, &argv);
  conduit_cpp::Node node;

  int a = 10;
  node["data"].set_int32(a);
  node["stage"].set_char8_str("initialize");
  catalyst_initialize(conduit_cpp::c_node(&node));

  node["stage"].set_char8_str("execute");
  for (unsigned i = 0; i < 3; i++)
  {
    node["data"] = a++;
    catalyst_execute(conduit_cpp::c_node(&node));
  }

  node["stage"].set_char8_str("finalize");
  node["data"] = a++;
  catalyst_finalize(conduit_cpp::c_node(&node));

  node["stage"].set_char8_str("about");
  catalyst_about(conduit_cpp::c_node(&node));

  MPI_Finalize();

  return EXIT_SUCCESS;
}
