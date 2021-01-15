// Copyright (c) Lawrence Livermore National Security, LLC and other Conduit
// Project developers. See top-level LICENSE AND COPYRIGHT files for dates and
// other details. No copyright assignment is required to contribute to Conduit.

//-----------------------------------------------------------------------------
///
/// file: conduit_to_string.cpp
///
//-----------------------------------------------------------------------------

#include "catalyst_conduit.hpp"

#include "gtest/gtest.h"
#include <iostream>
using namespace conduit_cpp;

//-----------------------------------------------------------------------------
// TODO: Figure out why \n aren't present in this test, but are in original conduit test.
// TODO: Capture stdout and compare to correct value
TEST(conduit_to_string, simple_1)
{
  conduit_uint32 a_val = 10;
  conduit_uint32 b_val = 20;
  conduit_float64 c_val = 30.0;

  Node n;
  n["a"] = a_val;
  n["b"] = b_val;
  n["c"] = c_val;
  n.print_detailed();
  // EXPECT_EQ(std::string("{\"a\": 10,\"b\": 20,\"c\": 30.0}"),n.to_json("json",0,0,"",""));

  Node n2;
  n2["g"]["a"] = a_val;
  n2["g"]["b"] = b_val;
  n2["g"]["c"] = c_val;
  n2.print_detailed();
  // EXPECT_EQ(std::string("{\"g\": {\"a\": 10,\"b\":
  // 20,\"c\": 30.0}}"),n2.to_json("json",0,0,"",""));
}
