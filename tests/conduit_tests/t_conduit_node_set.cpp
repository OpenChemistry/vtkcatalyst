//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Copyright (c) 2014-2019, Lawrence Livermore National Security, LLC.
//
// Produced at the Lawrence Livermore National Laboratory
//
// LLNL-CODE-666778
//
// All rights reserved.
//
// This file is part of Conduit.
//
// For details, see: http://software.llnl.gov/conduit/.
//
// Please also read conduit/LICENSE
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the disclaimer below.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the disclaimer (as noted below) in the
//   documentation and/or other materials provided with the distribution.
//
// * Neither the name of the LLNS/LLNL nor the names of its contributors may
//   be used to endorse or promote products derived from this software without
//   specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL LAWRENCE LIVERMORE NATIONAL SECURITY,
// LLC, THE U.S. DEPARTMENT OF ENERGY OR CONTRIBUTORS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
// IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//-----------------------------------------------------------------------------
///
/// file: conduit_node_set.cpp
///
//-----------------------------------------------------------------------------

#include "c_typedefs.hpp"
#include "catalyst_conduit.hpp"

#include "gtest/gtest.h"
#include <iostream>
using namespace conduit_cpp;

//-----------------------------------------------------------------------------
// set bitwidth unsigned int scalar
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_bitwidth_uint_scalar)
{
  uint8 u8v = 8;
  uint16 u16v = 16;
  uint32 u32v = 32;
  uint64 u64v = 64;

  Node n;
  // uint8
  n.set(u8v);
  EXPECT_EQ(n.as_uint8(), u8v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_uint64(), 8);

  // uint16
  n.set(u16v);
  EXPECT_EQ(n.as_uint16(), u16v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_uint64(), 16);

  // uint32
  n.set(u32v);
  EXPECT_EQ(n.as_uint32(), u32v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_uint64(), 32);

  // uint64
  n.set(u64v);
  EXPECT_EQ(n.as_uint64(), u64v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_uint64(), 64);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_bitwidth_uint_scalar)
{
  uint8 u8v = 8;
  uint16 u16v = 16;
  uint32 u32v = 32;
  uint64 u64v = 64;

  Node n;
  // uint8
  n.set_path("one/two/three", u8v);
  EXPECT_TRUE(n.has_path("one"));
  EXPECT_TRUE(n["one"].has_path("two/three"));
  Node nc = n["one/two/three"];
  EXPECT_EQ(nc.as_uint8(), u8v);
  EXPECT_EQ(conduit_datatype_is_number(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(nc.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_floating_point(nc.c_dtype()), false);
  EXPECT_EQ(nc.to_uint64(), 8);

  // uint16
  n.set_path("one/two/three", u16v);
  EXPECT_TRUE(n.has_path("one"));
  EXPECT_TRUE(n["one"].has_path("two/three"));
  nc = n["one/two/three"];
  EXPECT_EQ(nc.as_uint16(), u16v);
  EXPECT_EQ(conduit_datatype_is_number(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(nc.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_floating_point(nc.c_dtype()), false);
  EXPECT_EQ(nc.to_uint64(), 16);

  // uint32
  n.set_path("one/two/three", u32v);
  EXPECT_TRUE(n.has_path("one"));
  EXPECT_TRUE(n["one"].has_path("two/three"));
  nc = n["one/two/three"];
  EXPECT_EQ(nc.as_uint32(), u32v);
  EXPECT_EQ(conduit_datatype_is_number(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(nc.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_floating_point(nc.c_dtype()), false);
  EXPECT_EQ(nc.to_uint64(), 32);

  // uint64
  n.set_path("one/two/three", u64v);
  EXPECT_TRUE(n.has_path("one"));
  EXPECT_TRUE(n["one"].has_path("two/three"));
  nc = n["one/two/three"];
  EXPECT_EQ(nc.as_uint64(), u64v);
  EXPECT_EQ(conduit_datatype_is_number(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(nc.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_floating_point(nc.c_dtype()), false);
  EXPECT_EQ(nc.to_uint64(), 64);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_external_bitwidth_uint_scalar)
{
  uint8 u8v = 8;
  uint16 u16v = 16;
  uint32 u32v = 32;
  uint64 u64v = 64;

  Node n;
  // uint8
  n.set_external(&u8v);
  EXPECT_EQ(n.as_uint8(), u8v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_int64(), 8);
  n.set((uint8)1);
  EXPECT_EQ(u8v, 1);

  // uint16
  n.set_external(&u16v);
  EXPECT_EQ(n.as_uint16(), u16v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_int64(), 16);
  n.set((uint16)1);
  EXPECT_EQ(u16v, 1);

  // uint32
  n.set_external(&u32v);
  EXPECT_EQ(n.as_uint32(), u32v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_int64(), 32);
  n.set((uint32)1);
  EXPECT_EQ(u32v, 1);

  // uint64
  n.set_external(&u64v);
  EXPECT_EQ(n.as_uint64(), u64v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_int64(), 64);
  n.set((uint64)1);
  EXPECT_EQ(u64v, 1);
}

// //-----------------------------------------------------------------------------
// // set bitwidth signed int scalar
// //-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_bitwidth_int_scalar)
{
  int8 i8v = -8;
  int16 i16v = -16;
  int32 i32v = -32;
  int64 i64v = -64;

  Node n;
  // int8
  n.set(i8v);
  EXPECT_EQ(n.as_int8(), i8v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_int64(), -8);

  // int16
  n.set(i16v);
  EXPECT_EQ(n.as_int16(), i16v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_int64(), -16);

  // int32
  n.set(i32v);
  EXPECT_EQ(n.as_int32(), i32v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_int64(), -32);

  // int64
  n.set(i64v);
  EXPECT_EQ(n.as_int64(), i64v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_int64(), -64);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_bitwidth_int_scalar)
{
  int8 i8v = -8;
  int16 i16v = -16;
  int32 i32v = -32;
  int64 i64v = -64;

  Node n;
  // int8
  n.set_path("one/two/three", i8v);
  EXPECT_TRUE(n.has_path("one"));
  EXPECT_TRUE(n["one"].has_path("two/three"));
  Node nc = n["one/two/three"];
  EXPECT_EQ(nc.as_int8(), i8v);
  EXPECT_EQ(conduit_datatype_is_number(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(nc.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(nc.c_dtype()), false);
  EXPECT_EQ(nc.to_int64(), -8);

  // int16
  n.set_path("one/two/three", i16v);
  EXPECT_TRUE(n.has_path("one"));
  EXPECT_TRUE(n["one"].has_path("two/three"));
  nc = n["one/two/three"];
  EXPECT_EQ(nc.as_int16(), i16v);
  EXPECT_EQ(conduit_datatype_is_number(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(nc.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(nc.c_dtype()), false);
  EXPECT_EQ(nc.to_int64(), -16);

  // int32
  n.set_path("one/two/three", i32v);
  EXPECT_TRUE(n.has_path("one"));
  EXPECT_TRUE(n["one"].has_path("two/three"));
  nc = n["one/two/three"];
  EXPECT_EQ(nc.as_int32(), i32v);
  EXPECT_EQ(conduit_datatype_is_number(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(nc.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(nc.c_dtype()), false);
  EXPECT_EQ(nc.to_int64(), -32);

  // int64
  n.set_path("one/two/three", i64v);
  EXPECT_TRUE(n.has_path("one"));
  EXPECT_TRUE(n["one"].has_path("two/three"));
  nc = n["one/two/three"];
  EXPECT_EQ(nc.as_int64(), i64v);
  EXPECT_EQ(conduit_datatype_is_number(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(nc.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(nc.c_dtype()), false);
  EXPECT_EQ(nc.to_int64(), -64);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_external_bitwidth_int_scalar)
{
  int8 i8v = -8;
  int16 i16v = -16;
  int32 i32v = -32;
  int64 i64v = -64;

  Node n;
  // int8
  n.set_external(&i8v);
  EXPECT_EQ(n.as_int8(), i8v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  n.set((int8)-1);
  EXPECT_EQ(i8v, -1);

  // int16
  n.set_external(&i16v);
  EXPECT_EQ(n.as_int16(), i16v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_int64(), -16);
  n.set((int16)-1);
  EXPECT_EQ(i16v, -1);

  // int32
  n.set_external(&i32v);
  EXPECT_EQ(n.as_int32(), i32v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_int64(), -32);
  n.set((int32)-1);
  EXPECT_EQ(i32v, -1);

  // int64
  n.set_external(&i64v);
  EXPECT_EQ(n.as_int64(), i64v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), false);
  EXPECT_EQ(n.to_int64(), -64);
  n.set((int64)-1);
  EXPECT_EQ(i64v, -1);
}

// //-----------------------------------------------------------------------------
// // set bitwidth float scalar
// //-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_bitwidth_float_scalar)
{
  float32 f32v = -3.2f;
  float64 f64v = -6.4;

  Node n;

  // float32
  n.set(f32v);
  EXPECT_EQ(n.as_float32(), f32v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), true);
  EXPECT_NEAR(n.to_float64(), -3.2, 0.001);

  // float64
  n.set(f64v);
  EXPECT_EQ(n.as_float64(), f64v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), true);
  EXPECT_NEAR(n.to_float64(), -6.4, 0.001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_bitwidth_float_scalar)
{
  float32 f32v = -3.2f;
  float64 f64v = -6.4;

  // float32
  Node n;
  n.set_path("one/two/three", f32v);
  EXPECT_TRUE(n.has_path("one"));
  EXPECT_TRUE(n["one"].has_path("two/three"));
  Node nc = n["one/two/three"];
  EXPECT_EQ(nc.as_float32(), f32v);
  EXPECT_EQ(conduit_datatype_is_number(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(nc.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_signed_integer(nc.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(nc.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(nc.c_dtype()), true);
  EXPECT_NEAR(nc.to_float64(), -3.2, 0.001);

  // float64
  n.set_path("one/two/three", f64v);
  EXPECT_TRUE(n.has_path("one"));
  EXPECT_TRUE(n["one"].has_path("two/three"));
  nc = n["one/two/three"];
  EXPECT_EQ(nc.as_float64(), f64v);
  EXPECT_EQ(conduit_datatype_is_number(nc.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(nc.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_signed_integer(nc.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(nc.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(nc.c_dtype()), true);
  EXPECT_NEAR(nc.to_float64(), -6.4, 0.001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_external_bitwidth_float_scalar)
{
  float32 f32v = -3.2f;
  float64 f64v = -6.4;

  Node n;

  // float32
  n.set_external(&f32v);
  EXPECT_EQ(n.as_float32(), f32v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), true);
  EXPECT_NEAR(n.to_float64(), -3.2, 0.001);
  n.set((float32)-1.1);
  EXPECT_NEAR(f32v, -1.1, 0.001);

  // float64
  n.set_external(&f64v);
  EXPECT_EQ(n.as_float64(), f64v);
  EXPECT_EQ(conduit_datatype_is_number(n.c_dtype()), true);
  EXPECT_EQ(conduit_datatype_is_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_signed_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_unsigned_integer(n.c_dtype()), false);
  EXPECT_EQ(conduit_datatype_is_floating_point(n.c_dtype()), true);
  EXPECT_NEAR(n.to_float64(), -6.4, 0.001);
  n.set((float64)-1.1);
  EXPECT_NEAR(f64v, -1.1, 0.001);
}

// //-----------------------------------------------------------------------------
// // set bitwidth unsigned int ptr
// //-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_bitwidth_uint_ptr)
{
  uint8 u8av[6] = { 2, 4, 8, 16, 32, 64 };
  uint16 u16av[6] = { 2, 4, 8, 16, 32, 64 };
  uint32 u32av[6] = { 2, 4, 8, 16, 32, 64 };
  uint64 u64av[6] = { 2, 4, 8, 16, 32, 64 };

  Node n;
  // using uint8* interface
  n.set(u8av, 6);
  uint8* u8av_ptr = n.as_uint8_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u8av_ptr[i], u8av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&u8av_ptr[i], &u8av[i]);
  }
  EXPECT_EQ(u8av_ptr[5], 64);

  // using uint16* interface
  n.set(u16av, 6);
  uint16* u16av_ptr = n.as_uint16_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u16av_ptr[i], u16av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&u16av_ptr[i], &u16av[i]);
  }
  EXPECT_EQ(u16av_ptr[5], 64);

  // using uint32 * interface
  n.set(u32av, 6);
  uint32* u32av_ptr = n.as_uint32_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u32av_ptr[i], u32av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&u32av_ptr[i], &u32av[i]);
  }
  EXPECT_EQ(u32av_ptr[5], 64);

  // using uint64 * interface
  n.set(u64av, 6);
  uint64* u64av_ptr = n.as_uint64_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u64av_ptr[i], u64av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&u64av_ptr[i], &u64av[i]);
  }
  EXPECT_EQ(u64av_ptr[5], 64);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_bitwidth_uint_ptr)
{
  uint8 u8av[6] = { 2, 4, 8, 16, 32, 64 };
  uint16 u16av[6] = { 2, 4, 8, 16, 32, 64 };
  uint32 u32av[6] = { 2, 4, 8, 16, 32, 64 };
  uint64 u64av[6] = { 2, 4, 8, 16, 32, 64 };

  Node n;
  // using uint8* interface
  n.set_path("two/lvl", u8av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  uint8* u8av_ptr = n["two/lvl"].as_uint8_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u8av_ptr[i], u8av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&u8av_ptr[i], &u8av[i]);
  }
  EXPECT_EQ(u8av_ptr[5], 64);

  // using uint16* interface
  n.set_path("two/lvl", u16av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  uint16* u16av_ptr = n["two/lvl"].as_uint16_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u16av_ptr[i], u16av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&u16av_ptr[i], &u16av[i]);
  }
  EXPECT_EQ(u16av_ptr[5], 64);

  // using uint32 * interface
  n.set_path("two/lvl", u32av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  uint32* u32av_ptr = n["two"]["lvl"].as_uint32_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u32av_ptr[i], u32av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&u32av_ptr[i], &u32av[i]);
  }
  EXPECT_EQ(u32av_ptr[5], 64);

  // using uint64 * interface
  n.set_path("two/lvl", u64av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  uint64* u64av_ptr = n["two/lvl"].as_uint64_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u64av_ptr[i], u64av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&u64av_ptr[i], &u64av[i]);
  }
  EXPECT_EQ(u64av_ptr[5], 64);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_external_bitwidth_uint_ptr)
{
  uint8 u8av[6] = { 2, 4, 8, 16, 32, 64 };
  uint16 u16av[6] = { 2, 4, 8, 16, 32, 64 };
  uint32 u32av[6] = { 2, 4, 8, 16, 32, 64 };
  uint64 u64av[6] = { 2, 4, 8, 16, 32, 64 };

  Node n;
  // uint8
  n.set_external(u8av, 6);
  uint8* u8av_ptr = n.as_uint8_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u8av_ptr[i], u8av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&u8av_ptr[i], &u8av[i]);
  }
  u8av_ptr[1] = 100;
  EXPECT_EQ(u8av[1], 100);
  n.print();

  // uint16
  n.set_external(u16av, 6);
  uint16* u16av_ptr = n.as_uint16_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u16av_ptr[i], u16av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&u16av_ptr[i], &u16av[i]);
  }
  u16av_ptr[1] = 100;
  EXPECT_EQ(u16av[1], 100);
  n.print();

  // uint32
  n.set_external(u32av, 6);
  uint32* u32av_ptr = n.as_uint32_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u32av_ptr[i], u32av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&u32av_ptr[i], &u32av[i]);
  }
  u32av_ptr[1] = 100;
  EXPECT_EQ(u32av[1], 100);
  n.print();

  // uint64
  n.set_external(u64av, 6);
  uint64* u64av_ptr = n.as_uint64_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u64av_ptr[i], u64av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&u64av_ptr[i], &u64av[i]);
  }
  EXPECT_EQ(u64av_ptr[5], 64);
  u64av_ptr[1] = 100;
  EXPECT_EQ(u64av[1], 100);
  n.print();
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_external_bitwidth_uint_ptr)
{
  uint8 u8av[6] = { 2, 4, 8, 16, 32, 64 };
  uint16 u16av[6] = { 2, 4, 8, 16, 32, 64 };
  uint32 u32av[6] = { 2, 4, 8, 16, 32, 64 };
  uint64 u64av[6] = { 2, 4, 8, 16, 32, 64 };

  Node n;
  // uint8
  n.set_path_external("two/lvl", u8av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  uint8* u8av_ptr = n["two/lvl"].as_uint8_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u8av_ptr[i], u8av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&u8av_ptr[i], &u8av[i]);
  }
  u8av_ptr[1] = 100;
  EXPECT_EQ(u8av[1], 100);
  n.print();

  // uint16
  n.set_path_external("two/lvl", u16av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  uint16* u16av_ptr = n["two/lvl"].as_uint16_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u16av_ptr[i], u16av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&u16av_ptr[i], &u16av[i]);
  }
  u16av_ptr[1] = 100;
  EXPECT_EQ(u16av[1], 100);
  n.print();

  // uint32
  n.set_path_external("two/lvl", u32av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  uint32* u32av_ptr = n["two/lvl"].as_uint32_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u32av_ptr[i], u32av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&u32av_ptr[i], &u32av[i]);
  }
  u32av_ptr[1] = 100;
  EXPECT_EQ(u32av[1], 100);
  n.print();

  // uint64
  n.set_path_external("two/lvl", u64av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  uint64* u64av_ptr = n["two/lvl"].as_uint64_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(u64av_ptr[i], u64av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&u64av_ptr[i], &u64av[i]);
  }
  EXPECT_EQ(u64av_ptr[5], 64);
  u64av_ptr[1] = 100;
  EXPECT_EQ(u64av[1], 100);
  n.print();
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_bitwidth_int_ptr)
{
  int8 i8av[6] = { -2, -4, -8, -16, -32, -64 };
  int16 i16av[6] = { -2, -4, -8, -16, -32, -64 };
  int32 i32av[6] = { -2, -4, -8, -16, -32, -64 };
  int64 i64av[6] = { -2, -4, -8, -16, -32, -64 };

  Node n;
  // int8
  n.set(i8av, 6);
  int8* i8av_ptr = n.as_int8_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i8av_ptr[i], i8av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&i8av_ptr[i], &i8av[i]);
  }
  EXPECT_EQ(i8av_ptr[5], -64);
  // int16
  n.set(i16av, 6);
  int16* i16av_ptr = n.as_int16_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i16av_ptr[i], i16av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&i16av_ptr[i], &i16av[i]);
  }
  EXPECT_EQ(i16av_ptr[5], -64);
  // int32
  n.set(i32av, 6);
  int32* i32av_ptr = n.as_int32_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i32av_ptr[i], i32av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&i32av_ptr[i], &i32av[i]);
  }
  EXPECT_EQ(i32av_ptr[5], -64);
  // int64
  n.set(i64av, 6);
  int64* i64av_ptr = n.as_int64_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i64av_ptr[i], i64av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&i64av_ptr[i], &i64av[i]);
  }
  EXPECT_EQ(i64av_ptr[5], -64);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set_, set_path_bitwidth_int_ptr)
{
  int8 i8av[6] = { -2, -4, -8, -16, -32, -64 };
  int16 i16av[6] = { -2, -4, -8, -16, -32, -64 };
  int32 i32av[6] = { -2, -4, -8, -16, -32, -64 };
  int64 i64av[6] = { -2, -4, -8, -16, -32, -64 };

  Node n;
  // int8
  n.set_path("two/lvl", i8av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  int8* i8av_ptr = n["two/lvl"].as_int8_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i8av_ptr[i], i8av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&i8av_ptr[i], &i8av[i]);
  }
  EXPECT_EQ(i8av_ptr[5], -64);
  // int16
  n.set_path("two/lvl", i16av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  int16* i16av_ptr = n["two/lvl"].as_int16_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i16av_ptr[i], i16av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&i16av_ptr[i], &i16av[i]);
  }
  EXPECT_EQ(i16av_ptr[5], -64);
  // int32
  n.set_path("two/lvl", i32av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  int32* i32av_ptr = n["two/lvl"].as_int32_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i32av_ptr[i], i32av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&i32av_ptr[i], &i32av[i]);
  }
  EXPECT_EQ(i32av_ptr[5], -64);
  // int64
  n.set_path("two/lvl", i64av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  int64* i64av_ptr = n["two/lvl"].as_int64_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i64av_ptr[i], i64av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&i64av_ptr[i], &i64av[i]);
  }
  EXPECT_EQ(i64av_ptr[5], -64);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set_, set_external_bitwidth_int_ptr)
{
  int8 i8av[6] = { -2, -4, -8, -16, -32, -64 };
  int16 i16av[6] = { -2, -4, -8, -16, -32, -64 };
  int32 i32av[6] = { -2, -4, -8, -16, -32, -64 };
  int64 i64av[6] = { -2, -4, -8, -16, -32, -64 };

  Node n;
  // int8
  n.set_external(i8av, 6);
  int8* i8av_ptr = n.as_int8_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i8av_ptr[i], i8av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&i8av_ptr[i], &i8av[i]);
  }
  EXPECT_EQ(i8av_ptr[5], -64);
  i8av_ptr[1] = -100;
  EXPECT_EQ(i8av[1], -100);
  n.print();

  // int16
  n.set_external(i16av, 6);
  int16* i16av_ptr = n.as_int16_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i16av_ptr[i], i16av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&i16av_ptr[i], &i16av[i]);
  }
  EXPECT_EQ(i16av_ptr[5], -64);
  i16av_ptr[1] = -100;
  EXPECT_EQ(i16av[1], -100);
  n.print();

  // int32
  n.set_external(i32av, 6);
  int32* i32av_ptr = n.as_int32_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i32av_ptr[i], i32av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&i32av_ptr[i], &i32av[i]);
  }
  EXPECT_EQ(i32av_ptr[5], -64);
  i32av_ptr[1] = -100;
  EXPECT_EQ(i32av[1], -100);
  n.print();

  // int64
  n.set_external(i64av, 6);
  int64* i64av_ptr = n.as_int64_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i64av_ptr[i], i64av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&i64av_ptr[i], &i64av[i]);
  }
  EXPECT_EQ(i64av_ptr[5], -64);
  i64av_ptr[1] = -100;
  EXPECT_EQ(i64av[1], -100);
  n.print();
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_external_bitwidth_int_ptr)
{
  int8 i8av[6] = { -2, -4, -8, -16, -32, -64 };
  int16 i16av[6] = { -2, -4, -8, -16, -32, -64 };
  int32 i32av[6] = { -2, -4, -8, -16, -32, -64 };
  int64 i64av[6] = { -2, -4, -8, -16, -32, -64 };

  Node n;
  // int8
  n.set_path_external("two/lvl", i8av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  int8* i8av_ptr = n["two/lvl"].as_int8_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i8av_ptr[i], i8av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&i8av_ptr[i], &i8av[i]);
  }
  EXPECT_EQ(i8av_ptr[5], -64);
  i8av_ptr[1] = -100;
  EXPECT_EQ(i8av[1], -100);
  n.print();

  // int16
  n.set_path_external("two/lvl", i16av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  int16* i16av_ptr = n["two/lvl"].as_int16_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i16av_ptr[i], i16av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&i16av_ptr[i], &i16av[i]);
  }
  EXPECT_EQ(i16av_ptr[5], -64);
  i16av_ptr[1] = -100;
  EXPECT_EQ(i16av[1], -100);
  n.print();

  // int32
  n.set_path_external("two/lvl", i32av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  int32* i32av_ptr = n["two/lvl"].as_int32_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i32av_ptr[i], i32av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&i32av_ptr[i], &i32av[i]);
  }
  EXPECT_EQ(i32av_ptr[5], -64);
  i32av_ptr[1] = -100;
  EXPECT_EQ(i32av[1], -100);
  n.print();

  // int64
  n.set_path_external("two/lvl", i64av, 6);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  int64* i64av_ptr = n["two/lvl"].as_int64_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(i64av_ptr[i], i64av[i]);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&i64av_ptr[i], &i64av[i]);
  }
  EXPECT_EQ(i64av_ptr[5], -64);
  i64av_ptr[1] = -100;
  EXPECT_EQ(i64av[1], -100);
  n.print();
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_bitwidth_float_ptr)
{
  float32 f32av[4] = { -0.8f, -1.6f, -3.2f, -6.4f };
  float64 f64av[4] = { -0.8, -1.6, -3.2, -6.4 };

  Node n;
  // float32
  n.set(f32av, 4);
  float32* f32av_ptr = n.as_float32_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f32av_ptr[i], f32av[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&f32av_ptr[i], &f32av[i]);
  }
  EXPECT_NEAR(f32av_ptr[3], -6.4, 0.001);

  // float64
  n.set(f64av, 4);
  float64* f64av_ptr = n.as_float64_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f64av_ptr[i], f64av[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&f64av_ptr[i], &f64av[i]);
  }
  EXPECT_NEAR(f64av_ptr[3], -6.4, 0.001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_bitwidth_float_ptr)
{
  float32 f32av[4] = { -0.8f, -1.6f, -3.2f, -6.4f };
  float64 f64av[4] = { -0.8, -1.6, -3.2, -6.4 };

  Node n;
  // float32
  n.set_path("two/lvl", f32av, 4);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  float32* f32av_ptr = n["two/lvl"].as_float32_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f32av_ptr[i], f32av[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&f32av_ptr[i], &f32av[i]);
  }
  EXPECT_NEAR(f32av_ptr[3], -6.4, 0.001);

  // float64
  n.set_path("two/lvl", f64av, 4);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  float64* f64av_ptr = n["two/lvl"].as_float64_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f64av_ptr[i], f64av[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&f64av_ptr[i], &f64av[i]);
  }
  EXPECT_NEAR(f64av_ptr[3], -6.4, 0.001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_external_bitwidth_float_ptr)
{
  float32 f32av[4] = { -0.8f, -1.6f, -3.2f, -6.4f };
  float64 f64av[4] = { -0.8, -1.6, -3.2, -6.4 };

  Node n;
  // float32
  n.set_external(f32av, 4);
  float32* f32av_ptr = n.as_float32_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f32av_ptr[i], f32av[i], 0.001);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&f32av_ptr[i], &f32av[i]);
  }
  EXPECT_NEAR(f32av_ptr[3], -6.4, 0.001);
  f32av_ptr[1] = -110.1f;
  EXPECT_NEAR(f32av[1], -110.1, 0.001);
  n.print();

  // float64
  n.set_external(f64av, 4);
  float64* f64av_ptr = n.as_float64_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f64av_ptr[i], f64av[i], 0.001);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&f64av_ptr[i], &f64av[i]);
  }
  EXPECT_NEAR(f64av_ptr[3], -6.4, 0.001);
  f64av_ptr[1] = -110.1;
  EXPECT_NEAR(f64av[1], -110.1, 0.001);
  n.print();
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_external_bitwidth_float_ptr)
{
  float32 f32av[4] = { -0.8f, -1.6f, -3.2f, -6.4f };
  float64 f64av[4] = { -0.8, -1.6, -3.2, -6.4 };

  Node n;
  // float32
  n.set_path_external("two/lvl", f32av, 4);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  float32* f32av_ptr = n["two/lvl"].as_float32_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f32av_ptr[i], f32av[i], 0.001);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&f32av_ptr[i], &f32av[i]);
  }
  EXPECT_NEAR(f32av_ptr[3], -6.4, 0.001);
  f32av_ptr[1] = -110.1f;
  EXPECT_NEAR(f32av[1], -110.1, 0.001);
  n.print();

  // float64
  n.set_path_external("two/lvl", f64av, 4);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  float64* f64av_ptr = n["two/lvl"].as_float64_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f64av_ptr[i], f64av[i], 0.001);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&f64av_ptr[i], &f64av[i]);
  }
  EXPECT_NEAR(f64av_ptr[3], -6.4, 0.001);
  f64av_ptr[1] = -110.1;
  EXPECT_NEAR(f64av[1], -110.1, 0.001);
  n.print();
}

// //-----------------------------------------------------------------------------
// // C Style Checks
// //-----------------------------------------------------------------------------
// //  -- set & set_external --
// //-----------------------------------------------------------------------------
// //
// //  set_cstyle_native_int_ptr
// //  set_cstyle_native_int_vec
// //
// //  set_cstyle_unsigned_int_ptr
// //  set_cstyle_unsigned_int_vec
// //
// //  set_cstyle_signed_int_ptr
// //  set_cstyle_signed_int_vec
// //
// //  set_cstyle_float_ptr
// //  set_cstyle_float_vec
// //
// //-----------------------------------------------------------------------------

// //-----------------------------------------------------------------------------
// // set -- c style native ptr and vec
// //-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_cstyle_native_int_ptr)
{
  char char_av[6] = { 2, 4, 8, 16, 32, 64 };
  short short_av[6] = { 2, 4, 8, 16, 32, 64 };
  int int_av[6] = { 2, 4, 8, 16, 32, 64 };
  long long_av[6] = { 2, 4, 8, 16, 32, 64 };

  Node n;

  ////////////////////////////
  // set
  ////////////////////////////

  // char
  n.set_char_ptr(char_av, 6);
  char* char_ptr = n.as_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(char_ptr[i], char_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&char_ptr[i], &char_av[i]);
  }

  EXPECT_EQ(char_ptr[5], 64);

  // short
  n.set(short_av, 6);
  short* short_ptr = n.as_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(short_ptr[i], short_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&short_ptr[i], &short_av[i]);
  }

  EXPECT_EQ(short_ptr[5], 64);

  // int
  n.set(int_av, 6);
  int* int_ptr = n.as_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(int_ptr[i], int_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&int_ptr[i], &int_av[i]);
  }

  EXPECT_EQ(int_ptr[5], 64);

  // long
  n.set(long_av, 6);
  long* long_ptr = n.as_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(long_ptr[i], long_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&long_ptr[i], &long_av[i]);
  }

  EXPECT_EQ(long_ptr[5], 64);

  ////////////////////////////
  // set external
  ////////////////////////////

  // char
  n.set_external_char_ptr(char_av, 6);
  char_ptr = n.as_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(char_ptr[i], char_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&char_ptr[i], &char_av[i]);
  }

  EXPECT_EQ(char_ptr[5], 64);

  // short
  n.set_external(short_av, 6);
  short_ptr = n.as_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(short_ptr[i], short_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&short_ptr[i], &short_av[i]);
  }

  EXPECT_EQ(short_ptr[5], 64);

  // int
  n.set_external(int_av, 6);
  int_ptr = n.as_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(int_ptr[i], int_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&int_ptr[i], &int_av[i]);
  }

  EXPECT_EQ(int_ptr[5], 64);

  // long
  n.set_external(long_av, 6);
  long_ptr = n.as_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(long_ptr[i], long_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&long_ptr[i], &long_av[i]);
  }

  EXPECT_EQ(long_ptr[5], 64);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_cstyle_native_int_vec)
{
  // note: char may not be signed, we check
  // signed values in other tests
  char char_av[6] = { 2, 4, 8, 16, 32, 64 };
  short short_av[6] = { 2, 4, 8, 16, 32, 64 };
  int int_av[6] = { 2, 4, 8, 16, 32, 64 };
  long long_av[6] = { 2, 4, 8, 16, 32, 64 };

  std::vector<char> char_v(char_av, char_av + 6);
  std::vector<short> short_v(short_av, short_av + 6);
  std::vector<int> int_v(int_av, int_av + 6);
  std::vector<long> long_v(long_av, long_av + 6);

  Node n;

  ////////////////////////////
  // set
  ////////////////////////////

  // char
  n.set(char_v);
  char* char_ptr = n.as_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(char_ptr[i], char_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&char_ptr[i], &char_v[i]);
  }

  EXPECT_EQ(char_ptr[5], 64);

  // short
  n.set(short_v);
  short* short_ptr = n.as_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(short_ptr[i], short_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&short_ptr[i], &short_v[i]);
  }

  EXPECT_EQ(short_ptr[5], 64);

  // int
  n.set(int_v);
  int* int_ptr = n.as_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(int_ptr[i], int_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&int_ptr[i], &int_v[i]);
  }

  EXPECT_EQ(int_ptr[5], 64);

  // long
  n.set(long_v);
  long* long_ptr = n.as_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(long_ptr[i], long_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&long_ptr[i], &long_v[i]);
  }

  EXPECT_EQ(long_ptr[5], 64);

  ////////////////////////////
  // set external
  ////////////////////////////

  // char
  n.set_external(char_v);
  char_ptr = n.as_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(char_ptr[i], char_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&char_ptr[i], &char_v[i]);
  }

  EXPECT_EQ(char_ptr[5], 64);

  // short
  n.set_external(short_v);
  short_ptr = n.as_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(short_ptr[i], short_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&short_ptr[i], &short_v[i]);
  }

  EXPECT_EQ(short_ptr[5], 64);

  // int
  n.set_external(int_v);
  int_ptr = n.as_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(int_ptr[i], int_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&int_ptr[i], &int_v[i]);
  }

  EXPECT_EQ(int_ptr[5], 64);

  // long
  n.set_external(long_v);
  long_ptr = n.as_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(long_ptr[i], long_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&long_ptr[i], &long_v[i]);
  }

  EXPECT_EQ(long_ptr[5], 64);
}

// //-----------------------------------------------------------------------------
// // set -- c style unsigned ptr, array, and vec
// //-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_cstyle_unsigned_int_ptr)
{
  unsigned char uchar_av[6] = { 2, 4, 8, 16, 32, 64 };
  unsigned short ushort_av[6] = { 2, 4, 8, 16, 32, 64 };
  unsigned int uint_av[6] = { 2, 4, 8, 16, 32, 64 };
  unsigned long ulong_av[6] = { 2, 4, 8, 16, 32, 64 };

  Node n;

  ////////////////////////////
  // set
  ////////////////////////////

  // unsigned char
  n.set(uchar_av, 6);
  unsigned char* uchar_ptr = n.as_unsigned_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uchar_ptr[i], uchar_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&uchar_ptr[i], &uchar_av[i]);
  }

  EXPECT_EQ(uchar_ptr[5], 64);

  // unsigned short
  n.set(ushort_av, 6);
  unsigned short* ushort_ptr = n.as_unsigned_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ushort_ptr[i], ushort_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&ushort_ptr[i], &ushort_av[i]);
  }

  EXPECT_EQ(ushort_ptr[5], 64);

  // unsigned int
  n.set(uint_av, 6);
  unsigned int* uint_ptr = n.as_unsigned_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uint_ptr[i], uint_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&uint_ptr[i], &uint_av[i]);
  }

  EXPECT_EQ(uint_ptr[5], 64);

  // unsigned long
  n.set(ulong_av, 6);
  unsigned long* ulong_ptr = n.as_unsigned_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ulong_ptr[i], ulong_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&ulong_ptr[i], &ulong_av[i]);
  }

  EXPECT_EQ(ulong_ptr[5], 64);

  ////////////////////////////
  // set external
  ////////////////////////////

  // unsigned char
  n.set_external(uchar_av, 6);
  uchar_ptr = n.as_unsigned_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uchar_ptr[i], uchar_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&uchar_ptr[i], &uchar_av[i]);
  }

  EXPECT_EQ(uchar_ptr[5], 64);

  // unsigned short
  n.set_external(ushort_av, 6);
  ushort_ptr = n.as_unsigned_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ushort_ptr[i], ushort_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&ushort_ptr[i], &ushort_av[i]);
  }

  EXPECT_EQ(ushort_ptr[5], 64);

  // unsigned int
  n.set_external(uint_av, 6);
  uint_ptr = n.as_unsigned_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uint_ptr[i], uint_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&uint_ptr[i], &uint_av[i]);
  }

  EXPECT_EQ(uint_ptr[5], 64);

  // unsigned long
  n.set_external(ulong_av, 6);
  ulong_ptr = n.as_unsigned_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ulong_ptr[i], ulong_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&ulong_ptr[i], &ulong_av[i]);
  }

  EXPECT_EQ(ulong_ptr[5], 64);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_cstyle_unsigned_int_vec)
{
  unsigned char uchar_av[6] = { 2, 4, 8, 16, 32, 64 };
  unsigned short ushort_av[6] = { 2, 4, 8, 16, 32, 64 };
  unsigned int uint_av[6] = { 2, 4, 8, 16, 32, 64 };
  unsigned long ulong_av[6] = { 2, 4, 8, 16, 32, 64 };

  std::vector<unsigned char> uchar_v(uchar_av, uchar_av + 6);
  std::vector<unsigned short> ushort_v(ushort_av, ushort_av + 6);
  std::vector<unsigned int> uint_v(uint_av, uint_av + 6);
  std::vector<unsigned long> ulong_v(ulong_av, ulong_av + 6);

  Node n;

  ////////////////////////////
  // set
  ////////////////////////////

  // unsigned char
  n.set(uchar_v);
  unsigned char* uchar_ptr = n.as_unsigned_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uchar_ptr[i], uchar_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&uchar_ptr[i], &uchar_v[i]);
  }

  EXPECT_EQ(uchar_ptr[5], 64);

  // unsigned short
  n.set(ushort_v);
  unsigned short* ushort_ptr = n.as_unsigned_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ushort_ptr[i], ushort_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&ushort_ptr[i], &ushort_v[i]);
  }

  EXPECT_EQ(ushort_ptr[5], 64);

  // unsigned int
  n.set(uint_v);
  unsigned int* uint_ptr = n.as_unsigned_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uint_ptr[i], uint_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&uint_ptr[i], &uint_v[i]);
  }

  EXPECT_EQ(uint_ptr[5], 64);

  // unsigned long
  n.set(ulong_v);
  unsigned long* ulong_ptr = n.as_unsigned_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ulong_ptr[i], ulong_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&ulong_ptr[i], &ulong_v[i]);
  }

  EXPECT_EQ(ulong_ptr[5], 64);

  ////////////////////////////
  // set external
  ////////////////////////////

  // unsigned char
  n.set_external(uchar_v);
  uchar_ptr = n.as_unsigned_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uchar_ptr[i], uchar_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&uchar_ptr[i], &uchar_v[i]);
  }

  EXPECT_EQ(uchar_ptr[5], 64);

  // unsigned short
  n.set_external(ushort_v);
  ushort_ptr = n.as_unsigned_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ushort_ptr[i], ushort_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&ushort_ptr[i], &ushort_v[i]);
  }

  EXPECT_EQ(ushort_ptr[5], 64);

  // unsigned int
  n.set_external(uint_v);
  uint_ptr = n.as_unsigned_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uint_ptr[i], uint_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&uint_ptr[i], &uint_v[i]);
  }

  EXPECT_EQ(uint_ptr[5], 64);

  // unsigned long
  n.set_external(ulong_v);
  ulong_ptr = n.as_unsigned_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ulong_ptr[i], ulong_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&ulong_ptr[i], &ulong_v[i]);
  }

  EXPECT_EQ(ulong_ptr[5], 64);
}

// //-----------------------------------------------------------------------------
// // set -- c style signed ptr and vec
// //-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_cstyle_signed_int_ptr)
{
  signed char schar_av[6] = { -2, -4, -8, -16, -32, -64 };
  signed short sshort_av[6] = { -2, -4, -8, -16, -32, -64 };
  signed int sint_av[6] = { -2, -4, -8, -16, -32, -64 };
  signed long slong_av[6] = { -2, -4, -8, -16, -32, -64 };

  Node n;

  ////////////////////////////
  // set
  ////////////////////////////

  // unsigned char
  n.set(schar_av, 6);
  signed char* schar_ptr = n.as_signed_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(schar_ptr[i], schar_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&schar_ptr[i], &schar_av[i]);
  }

  EXPECT_EQ(schar_ptr[5], -64);

  // unsigned short
  n.set(sshort_av, 6);
  signed short* sshort_ptr = n.as_signed_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sshort_ptr[i], sshort_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&sshort_ptr[i], &sshort_av[i]);
  }

  EXPECT_EQ(sshort_ptr[5], -64);

  // unsigned int
  n.set(sint_av, 6);
  signed int* sint_ptr = n.as_signed_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sint_ptr[i], sint_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&sint_ptr[i], &sint_av[i]);
  }

  EXPECT_EQ(sint_ptr[5], -64);

  // unsigned long
  n.set(slong_av, 6);
  signed long* slong_ptr = n.as_signed_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(slong_ptr[i], slong_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&slong_ptr[i], &slong_av[i]);
  }

  EXPECT_EQ(slong_ptr[5], -64);

  ////////////////////////////
  // set external
  ////////////////////////////

  // unsigned char
  n.set_external(schar_av, 6);
  schar_ptr = n.as_signed_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(schar_ptr[i], schar_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&schar_ptr[i], &schar_av[i]);
  }

  EXPECT_EQ(schar_ptr[5], -64);

  // unsigned short
  n.set_external(sshort_av, 6);
  sshort_ptr = n.as_signed_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sshort_ptr[i], sshort_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&sshort_ptr[i], &sshort_av[i]);
  }

  EXPECT_EQ(sshort_ptr[5], -64);

  // unsigned int
  n.set_external(sint_av, 6);
  sint_ptr = n.as_signed_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sint_ptr[i], sint_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&sint_ptr[i], &sint_av[i]);
  }

  EXPECT_EQ(sint_ptr[5], -64);

  // unsigned long
  n.set_external(slong_av, 6);
  slong_ptr = n.as_signed_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(slong_ptr[i], slong_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&slong_ptr[i], &slong_av[i]);
  }

  EXPECT_EQ(slong_ptr[5], -64);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_cstyle_signed_int_vec)
{
  signed char schar_av[6] = { -2, -4, -8, -16, -32, -64 };
  signed short sshort_av[6] = { -2, -4, -8, -16, -32, -64 };
  signed int sint_av[6] = { -2, -4, -8, -16, -32, -64 };
  signed long slong_av[6] = { -2, -4, -8, -16, -32, -64 };

  std::vector<signed char> schar_v(schar_av, schar_av + 6);
  std::vector<signed short> sshort_v(sshort_av, sshort_av + 6);
  std::vector<signed int> sint_v(sint_av, sint_av + 6);
  std::vector<signed long> slong_v(slong_av, slong_av + 6);

  Node n;

  ////////////////////////////
  // set
  ////////////////////////////

  // char
  n.set(schar_v);
  signed char* schar_ptr = n.as_signed_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(schar_ptr[i], schar_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&schar_ptr[i], &schar_v[i]);
  }

  EXPECT_EQ(schar_ptr[5], -64);

  // short
  n.set(sshort_v);
  short* sshort_ptr = n.as_signed_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sshort_ptr[i], sshort_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&sshort_ptr[i], &sshort_v[i]);
  }

  EXPECT_EQ(sshort_ptr[5], -64);

  // int
  n.set(sint_v);
  int* sint_ptr = n.as_signed_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sint_ptr[i], sint_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&sint_ptr[i], &sint_v[i]);
  }

  EXPECT_EQ(sint_ptr[5], -64);

  // long
  n.set(slong_v);
  long* slong_ptr = n.as_signed_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(slong_ptr[i], slong_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&slong_ptr[i], &slong_v[i]);
  }

  EXPECT_EQ(slong_ptr[5], -64);

  ////////////////////////////
  // set external
  ////////////////////////////

  // char
  n.set_external(schar_v);
  schar_ptr = n.as_signed_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(schar_ptr[i], schar_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&schar_ptr[i], &schar_v[i]);
  }

  EXPECT_EQ(schar_ptr[5], -64);

  // short
  n.set_external(sshort_v);
  sshort_ptr = n.as_signed_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sshort_ptr[i], sshort_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&sshort_ptr[i], &sshort_v[i]);
  }

  EXPECT_EQ(sshort_ptr[5], -64);

  // int
  n.set_external(sint_v);
  sint_ptr = n.as_signed_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sint_ptr[i], sint_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&sint_ptr[i], &sint_v[i]);
  }

  EXPECT_EQ(sint_ptr[5], -64);

  // long
  n.set_external(slong_v);
  slong_ptr = n.as_signed_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(slong_ptr[i], slong_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&slong_ptr[i], &slong_v[i]);
  }

  EXPECT_EQ(slong_ptr[5], -64);
}

// //-----------------------------------------------------------------------------
// // set -- c style float ptr, array, and vec
// //-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_cstyle_float_ptr)
{
  float fav[4] = { -0.8f, -1.6f, -3.2f, -6.4f };
  double dav[4] = { -0.8, -1.6, -3.2, -6.4 };

#ifdef CONDUIT_USE_LONG_DOUBLE
  long double ldav[4] = { -0.8, -1.6, -3.2, -6.4 };
#endif

  Node n;
  if (sizeof(float) == 4)
  {
    // float32
    n.set(fav, 4);
    float32* f32av_ptr = n.as_float32_ptr();
    for (index_t i = 0; i < 4; i++)
    {
      EXPECT_NEAR(f32av_ptr[i], fav[i], 0.001);
      // set(...) semantics imply a copy -- mem addys should differ
      EXPECT_NE(&f32av_ptr[i], &fav[i]);
    }
    EXPECT_NEAR(f32av_ptr[3], -6.4, 0.001);
  }

  if (sizeof(double) == 8)
  {
    // float64
    n.set(dav, 4);
    float64* f64av_ptr = n.as_float64_ptr();
    for (index_t i = 0; i < 4; i++)
    {
      EXPECT_NEAR(f64av_ptr[i], dav[i], 0.001);
      // set(...) semantics imply a copy -- mem addys should differ
      EXPECT_NE(&f64av_ptr[i], &dav[i]);
    }
    EXPECT_NEAR(f64av_ptr[3], -6.4, 0.001);
  }

  ////////////////////////////
  // set
  ////////////////////////////

  // float
  n.set(fav, 4);
  float* f_ptr = n.as_float_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f_ptr[i], fav[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&f_ptr[i], &fav[i]);
  }

  EXPECT_NEAR(f_ptr[3], -6.4, 0.001);

  // double
  n.set(dav, 4);
  double* d_ptr = n.as_double_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(d_ptr[i], dav[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&d_ptr[i], &dav[i]);
  }

  EXPECT_NEAR(d_ptr[3], -6.4, 0.001);

#ifdef CONDIT_USE_LONG_DOUBLE

  // long_double
  n.set(ldav, 4);
  long double* ld_ptr = n.as_long_double_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(ld_ptr[i], ldav[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&ld_ptr[i], &ldav[i]);
  }
  EXPECT_NEAR(ld_ptr[3], -6.4, 0.001);

#endif

  ////////////////////////////
  // set external
  ////////////////////////////

  // float
  n.set_external(fav, 4);
  f_ptr = n.as_float_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f_ptr[i], fav[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_EQ(&f_ptr[i], &fav[i]);
  }

  EXPECT_NEAR(f_ptr[3], -6.4, 0.001);

  // double
  n.set_external(dav, 4);
  d_ptr = n.as_double_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(d_ptr[i], dav[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_EQ(&d_ptr[i], &dav[i]);
  }

  EXPECT_NEAR(d_ptr[3], -6.4, 0.001);

#ifdef CONDIT_USE_LONG_DOUBLE

  // long_double
  n.set_external(ldav, 4);
  ld_ptr = n.as_long_double_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(ld_ptr[i], ldav[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_EQ(&ld_ptr[i], &ldav[i]);
  }
  EXPECT_NEAR(ld_ptr[3], -6.4, 0.001);

#endif
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_cstyle_float_vec)
{
  float fav[4] = { -0.8f, -1.6f, -3.2f, -6.4f };
  double dav[4] = { -0.8, -1.6, -3.2, -6.4 };

  std::vector<float> fav_v(fav, fav + 4);
  std::vector<double> dav_v(dav, dav + 4);

  Node n;

  ////////////////////////////
  // set
  ////////////////////////////

  // float
  n.set(fav_v);
  float* f_ptr = n.as_float_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f_ptr[i], fav_v[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&f_ptr[i], &fav_v[i]);
  }
  EXPECT_NEAR(f_ptr[3], -6.4, 0.001);

  // double
  n.set(dav_v);
  double* d_ptr = n.as_double_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(d_ptr[i], dav_v[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&d_ptr[i], &dav_v[i]);
  }
  EXPECT_NEAR(d_ptr[3], -6.4, 0.001);

  ////////////////////////////
  // set external
  ////////////////////////////

  // float
  n.set_external(fav_v);
  f_ptr = n.as_float_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f_ptr[i], fav_v[i], 0.001);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&f_ptr[i], &fav_v[i]);
  }
  EXPECT_NEAR(f_ptr[3], -6.4, 0.001);

  // double
  n.set_external(dav_v);
  d_ptr = n.as_double_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(d_ptr[i], dav_v[i], 0.001);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&d_ptr[i], &dav_v[i]);
  }
  EXPECT_NEAR(d_ptr[3], -6.4, 0.001);
}

// //-----------------------------------------------------------------------------
// // C Style Checks
// //-----------------------------------------------------------------------------
// //  -- set_path & set_path_external --
// //-----------------------------------------------------------------------------
// //
// //  set_path_cstyle_native_int_ptr
// //  set_path_cstyle_native_int_vec
// //
// //  set_path_cstyle_unsigned_int_ptr
// //  set_path_cstyle_unsigned_int_vec
// //
// //  set_path_cstyle_signed_int_ptr
// //  set_path_cstyle_signed_int_vec
// //
// //  set_path_cstyle_float_ptr
// //  set_path_cstyle_float_vec
// //
// //-----------------------------------------------------------------------------

// //-----------------------------------------------------------------------------
// // set_path -- c style native ptr and vec
// //-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_cstyle_native_int_ptr)
{
  char char_av[6] = { 2, 4, 8, 16, 32, 64 };
  short short_av[6] = { 2, 4, 8, 16, 32, 64 };
  int int_av[6] = { 2, 4, 8, 16, 32, 64 };
  long long_av[6] = { 2, 4, 8, 16, 32, 64 };

  Node n;

  ////////////////////////////
  // set path
  ////////////////////////////

  // char
  n.set_path_char_ptr("c", char_av, 6);
  char* char_ptr = n["c"].as_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(char_ptr[i], char_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&char_ptr[i], &char_av[i]);
  }

  EXPECT_EQ(char_ptr[5], 64);

  // short
  n.set_path("s", short_av, 6);
  short* short_ptr = n["s"].as_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(short_ptr[i], short_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&short_ptr[i], &short_av[i]);
  }

  EXPECT_EQ(short_ptr[5], 64);

  // int
  n.set_path("i", int_av, 6);
  int* int_ptr = n["i"].as_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(int_ptr[i], int_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&int_ptr[i], &int_av[i]);
  }

  EXPECT_EQ(int_ptr[5], 64);

  // long
  n.set_path("l", long_av, 6);
  long* long_ptr = n["l"].as_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(long_ptr[i], long_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&long_ptr[i], &long_av[i]);
  }

  EXPECT_EQ(long_ptr[5], 64);

  ////////////////////////////
  // set path external
  ////////////////////////////

  // char
  n.set_path_external_char_ptr("c", char_av, 6);
  char_ptr = n["c"].as_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(char_ptr[i], char_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&char_ptr[i], &char_av[i]);
  }

  EXPECT_EQ(char_ptr[5], 64);

  // short
  n.set_path_external("s", short_av, 6);
  short_ptr = n["s"].as_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(short_ptr[i], short_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&short_ptr[i], &short_av[i]);
  }

  EXPECT_EQ(short_ptr[5], 64);

  // int
  n.set_path_external("i", int_av, 6);
  int_ptr = n["i"].as_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(int_ptr[i], int_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&int_ptr[i], &int_av[i]);
  }

  EXPECT_EQ(int_ptr[5], 64);

  // long
  n.set_path_external("l", long_av, 6);
  long_ptr = n["l"].as_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(long_ptr[i], long_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&long_ptr[i], &long_av[i]);
  }

  EXPECT_EQ(long_ptr[5], 64);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_cstyle_native_int_vec)
{
  char char_av[6] = { 2, 4, 8, 16, 32, 64 };
  short short_av[6] = { 2, 4, 8, 16, 32, 64 };
  int int_av[6] = { 2, 4, 8, 16, 32, 64 };
  long long_av[6] = { 2, 4, 8, 16, 32, 64 };

  std::vector<char> char_v(char_av, char_av + 6);
  std::vector<short> short_v(short_av, short_av + 6);
  std::vector<int> int_v(int_av, int_av + 6);
  std::vector<long> long_v(long_av, long_av + 6);

  Node n;

  ////////////////////////////
  // set path
  ////////////////////////////

  // char
  n.set_path("c", char_v);
  char* char_ptr = n["c"].as_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(char_ptr[i], char_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&char_ptr[i], &char_v[i]);
  }

  EXPECT_EQ(char_ptr[5], 64);

  // short
  n.set_path("s", short_v);
  short* short_ptr = n["s"].as_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(short_ptr[i], short_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&short_ptr[i], &short_v[i]);
  }

  EXPECT_EQ(short_ptr[5], 64);

  // int
  n.set_path("i", int_v);
  int* int_ptr = n["i"].as_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(int_ptr[i], int_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&int_ptr[i], &int_v[i]);
  }

  EXPECT_EQ(int_ptr[5], 64);

  // long
  n.set_path("l", long_v);
  long* long_ptr = n["l"].as_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(long_ptr[i], long_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&long_ptr[i], &long_v[i]);
  }

  EXPECT_EQ(long_ptr[5], 64);

  ////////////////////////////
  // set path external
  ////////////////////////////

  // char
  n.set_path_external("c", char_v);
  char_ptr = n["c"].as_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(char_ptr[i], char_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&char_ptr[i], &char_v[i]);
  }

  EXPECT_EQ(char_ptr[5], 64);

  // short
  n.set_path_external("s", short_v);
  short_ptr = n["s"].as_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(short_ptr[i], short_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&short_ptr[i], &short_v[i]);
  }

  EXPECT_EQ(short_ptr[5], 64);

  // int
  n.set_path_external("i", int_v);
  int_ptr = n["i"].as_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(int_ptr[i], int_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&int_ptr[i], &int_v[i]);
  }

  EXPECT_EQ(int_ptr[5], 64);

  // long
  n.set_path_external("l", long_v);
  long_ptr = n["l"].as_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(long_ptr[i], long_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&long_ptr[i], &long_v[i]);
  }

  EXPECT_EQ(long_ptr[5], 64);
}

// //-----------------------------------------------------------------------------
// // set_path -- c style unsigned ptr, array, and vec
// //-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_cstyle_unsigned_int_ptr)
{
  unsigned char uchar_av[6] = { 2, 4, 8, 16, 32, 64 };
  unsigned short ushort_av[6] = { 2, 4, 8, 16, 32, 64 };
  unsigned int uint_av[6] = { 2, 4, 8, 16, 32, 64 };
  unsigned long ulong_av[6] = { 2, 4, 8, 16, 32, 64 };

  Node n;

  ////////////////////////////
  // set path
  ////////////////////////////

  // unsigned char
  n.set_path("uc", uchar_av, 6);
  unsigned char* uchar_ptr = n["uc"].as_unsigned_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uchar_ptr[i], uchar_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&uchar_ptr[i], &uchar_av[i]);
  }

  EXPECT_EQ(uchar_ptr[5], 64);

  // unsigned short
  n.set_path("us", ushort_av, 6);
  unsigned short* ushort_ptr = n["us"].as_unsigned_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ushort_ptr[i], ushort_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&ushort_ptr[i], &ushort_av[i]);
  }

  EXPECT_EQ(ushort_ptr[5], 64);

  // unsigned int
  n.set_path("ui", uint_av, 6);
  unsigned int* uint_ptr = n["ui"].as_unsigned_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uint_ptr[i], uint_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&uint_ptr[i], &uint_av[i]);
  }

  EXPECT_EQ(uint_ptr[5], 64);

  // unsigned long
  n.set_path("ul", ulong_av, 6);
  unsigned long* ulong_ptr = n["ul"].as_unsigned_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ulong_ptr[i], ulong_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&ulong_ptr[i], &ulong_av[i]);
  }

  EXPECT_EQ(ulong_ptr[5], 64);

  ////////////////////////////
  // set path external
  ////////////////////////////

  // unsigned char
  n.set_path_external("uc", uchar_av, 6);
  uchar_ptr = n["uc"].as_unsigned_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uchar_ptr[i], uchar_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&uchar_ptr[i], &uchar_av[i]);
  }

  EXPECT_EQ(uchar_ptr[5], 64);

  // unsigned short
  n.set_path_external("us", ushort_av, 6);
  ushort_ptr = n["us"].as_unsigned_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ushort_ptr[i], ushort_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&ushort_ptr[i], &ushort_av[i]);
  }

  EXPECT_EQ(ushort_ptr[5], 64);

  // unsigned int
  n.set_path_external("ui", uint_av, 6);
  uint_ptr = n["ui"].as_unsigned_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uint_ptr[i], uint_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&uint_ptr[i], &uint_av[i]);
  }

  EXPECT_EQ(uint_ptr[5], 64);

  // unsigned long
  n.set_path_external("ul", ulong_av, 6);
  ulong_ptr = n["ul"].as_unsigned_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ulong_ptr[i], ulong_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&ulong_ptr[i], &ulong_av[i]);
  }

  EXPECT_EQ(ulong_ptr[5], 64);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_cstyle_unsigned_int_vec)
{
  unsigned char uchar_av[6] = { 2, 4, 8, 16, 32, 64 };
  unsigned short ushort_av[6] = { 2, 4, 8, 16, 32, 64 };
  unsigned int uint_av[6] = { 2, 4, 8, 16, 32, 64 };
  unsigned long ulong_av[6] = { 2, 4, 8, 16, 32, 64 };

  std::vector<unsigned char> uchar_v(uchar_av, uchar_av + 6);
  std::vector<unsigned short> ushort_v(ushort_av, ushort_av + 6);
  std::vector<unsigned int> uint_v(uint_av, uint_av + 6);
  std::vector<unsigned long> ulong_v(ulong_av, ulong_av + 6);

  Node n;

  ////////////////////////////
  // set path
  ////////////////////////////

  // unsigned char
  n.set_path("uc", uchar_v);
  unsigned char* uchar_ptr = n["uc"].as_unsigned_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uchar_ptr[i], uchar_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&uchar_ptr[i], &uchar_v[i]);
  }

  EXPECT_EQ(uchar_ptr[5], 64);

  // unsigned short
  n.set_path("us", ushort_v);
  unsigned short* ushort_ptr = n["us"].as_unsigned_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ushort_ptr[i], ushort_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&ushort_ptr[i], &ushort_v[i]);
  }

  EXPECT_EQ(ushort_ptr[5], 64);

  // unsigned int
  n.set_path("ui", uint_v);
  unsigned int* uint_ptr = n["ui"].as_unsigned_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uint_ptr[i], uint_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&uint_ptr[i], &uint_v[i]);
  }

  EXPECT_EQ(uint_ptr[5], 64);

  // unsigned long
  n.set_path("ul", ulong_v);
  unsigned long* ulong_ptr = n["ul"].as_unsigned_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ulong_ptr[i], ulong_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&ulong_ptr[i], &ulong_v[i]);
  }

  EXPECT_EQ(ulong_ptr[5], 64);

  ////////////////////////////
  // set path external
  ////////////////////////////

  // unsigned char
  n.set_path_external("uc", uchar_v);
  uchar_ptr = n["uc"].as_unsigned_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uchar_ptr[i], uchar_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&uchar_ptr[i], &uchar_v[i]);
  }

  EXPECT_EQ(uchar_ptr[5], 64);

  // unsigned short
  n.set_path_external("us", ushort_v);
  ushort_ptr = n["us"].as_unsigned_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ushort_ptr[i], ushort_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&ushort_ptr[i], &ushort_v[i]);
  }

  EXPECT_EQ(ushort_ptr[5], 64);

  // unsigned int
  n.set_path_external("ui", uint_v);
  uint_ptr = n["ui"].as_unsigned_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(uint_ptr[i], uint_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&uint_ptr[i], &uint_v[i]);
  }

  EXPECT_EQ(uint_ptr[5], 64);

  // unsigned long
  n.set_path_external("ul", ulong_v);
  ulong_ptr = n["ul"].as_unsigned_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(ulong_ptr[i], ulong_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&ulong_ptr[i], &ulong_v[i]);
  }

  EXPECT_EQ(ulong_ptr[5], 64);
}

// //-----------------------------------------------------------------------------
// // set_path -- c style signed ptr and vec
// //-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_cstyle_signed_int_ptr)
{
  signed char schar_av[6] = { -2, -4, -8, -16, -32, -64 };
  signed short sshort_av[6] = { -2, -4, -8, -16, -32, -64 };
  signed int sint_av[6] = { -2, -4, -8, -16, -32, -64 };
  signed long slong_av[6] = { -2, -4, -8, -16, -32, -64 };

  Node n;

  ////////////////////////////
  // set path
  ////////////////////////////

  // char
  n.set_path("c", schar_av, 6);
  signed char* schar_ptr = n["c"].as_signed_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(schar_ptr[i], schar_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&schar_ptr[i], &schar_av[i]);
  }

  EXPECT_EQ(schar_ptr[5], -64);

  // short
  n.set_path("s", sshort_av, 6);
  signed short* sshort_ptr = n["s"].as_signed_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sshort_ptr[i], sshort_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&sshort_ptr[i], &sshort_av[i]);
  }

  EXPECT_EQ(sshort_ptr[5], -64);

  // int
  n.set_path("i", sint_av, 6);
  signed int* sint_ptr = n["i"].as_signed_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sint_ptr[i], sint_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&sint_ptr[i], &sint_av[i]);
  }

  EXPECT_EQ(sint_ptr[5], -64);

  // long
  n.set_path("l", slong_av, 6);
  signed long* slong_ptr = n["l"].as_signed_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(slong_ptr[i], slong_av[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&slong_ptr[i], &slong_av[i]);
  }

  EXPECT_EQ(slong_ptr[5], -64);

  ////////////////////////////
  // set path external
  ////////////////////////////

  // char
  n.set_path_external("c", schar_av, 6);
  schar_ptr = n["c"].as_signed_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(schar_ptr[i], schar_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&schar_ptr[i], &schar_av[i]);
  }

  EXPECT_EQ(schar_ptr[5], -64);

  // short
  n.set_path_external("s", sshort_av, 6);
  sshort_ptr = n["s"].as_signed_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sshort_ptr[i], sshort_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&sshort_ptr[i], &sshort_av[i]);
  }

  EXPECT_EQ(sshort_ptr[5], -64);

  // int
  n.set_path_external("i", sint_av, 6);
  sint_ptr = n["i"].as_signed_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sint_ptr[i], sint_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&sint_ptr[i], &sint_av[i]);
  }

  EXPECT_EQ(sint_ptr[5], -64);

  // long
  n.set_path_external("l", slong_av, 6);
  slong_ptr = n["l"].as_signed_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(slong_ptr[i], slong_av[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&slong_ptr[i], &slong_av[i]);
  }

  EXPECT_EQ(slong_ptr[5], -64);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_cstyle_signed_int_vec)
{
  signed char schar_av[6] = { -2, -4, -8, -16, -32, -64 };
  signed short sshort_av[6] = { -2, -4, -8, -16, -32, -64 };
  signed int sint_av[6] = { -2, -4, -8, -16, -32, -64 };
  signed long slong_av[6] = { -2, -4, -8, -16, -32, -64 };

  std::vector<signed char> schar_v(schar_av, schar_av + 6);
  std::vector<signed short> sshort_v(sshort_av, sshort_av + 6);
  std::vector<signed int> sint_v(sint_av, sint_av + 6);
  std::vector<signed long> slong_v(slong_av, slong_av + 6);

  Node n;

  ////////////////////////////
  // set path
  ////////////////////////////

  // char
  n.set_path("c", schar_v);
  signed char* schar_ptr = n["c"].as_signed_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(schar_ptr[i], schar_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&schar_ptr[i], &schar_v[i]);
  }

  EXPECT_EQ(schar_ptr[5], -64);

  // short
  n.set_path("s", sshort_v);
  signed short* sshort_ptr = n["s"].as_signed_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sshort_ptr[i], sshort_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&sshort_ptr[i], &sshort_v[i]);
  }

  EXPECT_EQ(sshort_ptr[5], -64);

  // int
  n.set_path("i", sint_v);
  signed int* sint_ptr = n["i"].as_signed_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sint_ptr[i], sint_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&sint_ptr[i], &sint_v[i]);
  }

  EXPECT_EQ(sint_ptr[5], -64);

  // long
  n.set_path("l", slong_v);
  signed long* slong_ptr = n["l"].as_signed_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(slong_ptr[i], slong_v[i]);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&slong_ptr[i], &slong_v[i]);
  }

  EXPECT_EQ(slong_ptr[5], -64);

  ////////////////////////////
  // set path external
  ////////////////////////////

  // char
  n.set_path_external("c", schar_v);
  schar_ptr = n["c"].as_signed_char_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(schar_ptr[i], schar_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&schar_ptr[i], &schar_v[i]);
  }

  EXPECT_EQ(schar_ptr[5], -64);

  // short
  n.set_path_external("s", sshort_v);
  sshort_ptr = n["s"].as_short_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sshort_ptr[i], sshort_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&sshort_ptr[i], &sshort_v[i]);
  }

  EXPECT_EQ(sshort_ptr[5], -64);

  // int
  n.set_path_external("i", sint_v);
  sint_ptr = n["i"].as_int_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(sint_ptr[i], sint_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&sint_ptr[i], &sint_v[i]);
  }

  EXPECT_EQ(sint_ptr[5], -64);

  // long
  n.set_path_external("l", slong_v);
  slong_ptr = n["l"].as_long_ptr();
  for (index_t i = 0; i < 6; i++)
  {
    EXPECT_EQ(slong_ptr[i], slong_v[i]);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&slong_ptr[i], &slong_v[i]);
  }

  EXPECT_EQ(slong_ptr[5], -64);
}

// //-----------------------------------------------------------------------------
// // set_path -- c style float ptr and vec
// //-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_cstyle_float_ptr)
{
  float fav[4] = { -0.8f, -1.6f, -3.2f, -6.4f };
  double dav[4] = { -0.8, -1.6, -3.2, -6.4 };

#ifdef CONDUIT_USE_LONG_DOUBLE
  long double ldav[4] = { -0.8, -1.6, -3.2, -6.4 };
#endif

  Node n;

  ////////////////////////////
  // set path
  ////////////////////////////

  // float
  n.set_path("f", fav, 4);
  float* f_ptr = n["f"].as_float_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f_ptr[i], fav[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&f_ptr[i], &fav[i]);
  }

  EXPECT_NEAR(f_ptr[3], -6.4, 0.001);

  // double
  n.set_path("d", dav, 4);
  double* d_ptr = n["d"].as_double_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(d_ptr[i], dav[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&d_ptr[i], &dav[i]);
  }

  EXPECT_NEAR(d_ptr[3], -6.4, 0.001);

#ifdef CONDIT_USE_LONG_DOUBLE

  // long_double
  n.set_path("ld", ldav, 4);
  long double* ld_ptr = n["ld"].as_long_double_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(ld_ptr[i], ldav[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&ld_ptr[i], &ldav[i]);
  }
  EXPECT_NEAR(ld_ptr[3], -6.4, 0.001);

#endif

  ////////////////////////////
  // set path external
  ////////////////////////////

  // float
  n.set_path_external("f", fav, 4);
  f_ptr = n["f"].as_float_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f_ptr[i], fav[i], 0.001);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&f_ptr[i], &fav[i]);
  }

  EXPECT_NEAR(f_ptr[3], -6.4, 0.001);

  // double
  n.set_path_external("d", dav, 4);
  d_ptr = n["d"].as_double_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(d_ptr[i], dav[i], 0.001);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&d_ptr[i], &dav[i]);
  }

  EXPECT_NEAR(d_ptr[3], -6.4, 0.001);

#ifdef CONDIT_USE_LONG_DOUBLE

  // long_double
  n.set_path_extenral("ld", ldav, 4);
  ld_ptr = n["ld"].as_long_double_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(ld_ptr[i], ldav[i], 0.001);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&ld_ptr[i], &ldav[i]);
  }
  EXPECT_NEAR(ld_ptr[3], -6.4, 0.001);

#endif
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_cstyle_float_vec)
{
  std::vector<float> fav;
  fav.push_back(-0.8f);
  fav.push_back(-1.6f);
  fav.push_back(-3.2f);
  fav.push_back(-6.4f);

  std::vector<double> dav;
  dav.push_back(-0.8);
  dav.push_back(-1.6);
  dav.push_back(-3.2);
  dav.push_back(-6.4);

  ////////////////////////////
  // set path
  ////////////////////////////

  Node n;
  // float
  n.set_path("f", fav);
  float* f_ptr = n["f"].as_float_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f_ptr[i], fav[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&f_ptr[i], &fav[i]);
  }
  EXPECT_NEAR(f_ptr[3], -6.4, 0.001);

  // double
  n.set_path("d", dav);
  double* d_ptr = n["d"].as_double_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(d_ptr[i], dav[i], 0.001);
    // set(...) semantics imply a copy -- mem addys should differ
    EXPECT_NE(&d_ptr[i], &dav[i]);
  }
  EXPECT_NEAR(d_ptr[3], -6.4, 0.001);

  ////////////////////////////
  // set path external
  ////////////////////////////

  // float
  n.set_path_external("f", fav);
  f_ptr = n["f"].as_float_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f_ptr[i], fav[i], 0.001);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&f_ptr[i], &fav[i]);
  }
  EXPECT_NEAR(f_ptr[3], -6.4, 0.001);

  // double
  n.set_path_external("d", dav);
  d_ptr = n["d"].as_double_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(d_ptr[i], dav[i], 0.001);
    // set_external(...) semantics implies zero-copy -- mem addys should equal
    EXPECT_EQ(&d_ptr[i], &dav[i]);
  }
  EXPECT_NEAR(d_ptr[3], -6.4, 0.001);
}

// //-----------------------------------------------------------------------------
// // end c style set and set path checks
// //-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_path_external_node)
{
  float32 f32av[4] = { -0.8f, -1.6f, -3.2f, -6.4f };
  float64 f64av[4] = { -0.8, -1.6, -3.2, -6.4 };

  Node nsrc;
  // float32
  nsrc.set_path_external("two/lvl", f32av, 4);
  nsrc.print();

  Node n;
  n.set_external(nsrc);

  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  float32* f32av_ptr = n["two/lvl"].as_float32_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f32av_ptr[i], f32av[i], 0.001);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&f32av_ptr[i], &f32av[i]);
  }
  EXPECT_NEAR(f32av_ptr[3], -6.4, 0.001);
  f32av_ptr[1] = -110.1f;
  EXPECT_NEAR(f32av[1], -110.1, 0.001);
  n.print();

  // float64
  nsrc.set_path_external("two/lvl", f64av, 4);
  nsrc.print();

  n.set_external(nsrc);
  EXPECT_TRUE(n.has_path("two"));
  EXPECT_TRUE(n["two"].has_path("lvl"));
  float64* f64av_ptr = n["two/lvl"].as_float64_ptr();
  for (index_t i = 0; i < 4; i++)
  {
    EXPECT_NEAR(f64av_ptr[i], f64av[i], 0.001);
    // set_external(...) semantics imply a ref -- mem addys should match
    EXPECT_EQ(&f64av_ptr[i], &f64av[i]);
  }
  EXPECT_NEAR(f64av_ptr[3], -6.4, 0.001);
  f64av_ptr[1] = -110.1;
  EXPECT_NEAR(f64av[1], -110.1, 0.001);
  n.print();
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_string_multiple)
{
  Node n;
  n.set_string("I am a long string");
  EXPECT_EQ(n.as_string(), "I am a long string");
  n.set_string("I am a longer string than before"); // OK
  EXPECT_EQ(n.as_string(), "I am a longer string than before");
  n.set_string("shorter"); // was crashing ..
  EXPECT_EQ(n.as_string(), "shorter");
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_vector)
{

  std::vector<int8> i8_vec(1);
  std::vector<int16> i16_vec(1);
  std::vector<int32> i32_vec(1);
  std::vector<int64> i64_vec(1);

  i8_vec[0] = -8;
  i16_vec[0] = -16;
  i32_vec[0] = -32;
  i64_vec[0] = -64;

  std::vector<uint8> ui8_vec(1);
  std::vector<uint16> ui16_vec(1);
  std::vector<uint32> ui32_vec(1);
  std::vector<uint64> ui64_vec(1);

  ui8_vec[0] = 8;
  ui16_vec[0] = 16;
  ui32_vec[0] = 32;
  ui64_vec[0] = 64;

  std::vector<float32> f32_vec(1);
  std::vector<float64> f64_vec(1);
  f32_vec[0] = 2.71828f;
  f64_vec[0] = 3.1415;

  // set
  Node n1;
  n1["i8"].set(i8_vec);
  n1["i16"].set(i16_vec);
  n1["i32"].set(i32_vec);
  n1["i64"].set(i64_vec);

  n1["ui8"].set(ui8_vec);
  n1["ui16"].set(ui16_vec);
  n1["ui32"].set(ui32_vec);
  n1["ui64"].set(ui64_vec);

  n1["f32"].set(f32_vec);
  n1["f64"].set(f64_vec);

  n1.print();

  // set_path

  Node n2;
  n2.set_path("i8", i8_vec);
  n2.set_path("i16", i16_vec);
  n2.set_path("i32", i32_vec);
  n2.set_path("i64", i64_vec);

  n2.set_path("ui8", ui8_vec);
  n2.set_path("ui16", ui16_vec);
  n2.set_path("ui32", ui32_vec);
  n2.set_path("ui64", ui64_vec);

  n2.set_path("f32", f32_vec);
  n2.set_path("f64", f64_vec);

  n2.print();
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, set_vector_external)
{

  std::vector<int8> i8_vec(1);
  std::vector<int16> i16_vec(1);
  std::vector<int32> i32_vec(1);
  std::vector<int64> i64_vec(1);

  std::vector<uint8> ui8_vec(1);
  std::vector<uint16> ui16_vec(1);
  std::vector<uint32> ui32_vec(1);
  std::vector<uint64> ui64_vec(1);

  std::vector<float32> f32_vec(1);
  std::vector<float64> f64_vec(1);

  // set
  Node n1;
  n1["i8"].set_external(i8_vec);
  n1["i16"].set_external(i16_vec);
  n1["i32"].set_external(i32_vec);
  n1["i64"].set_external(i64_vec);

  n1["ui8"].set_external(ui8_vec);
  n1["ui16"].set_external(ui16_vec);
  n1["ui32"].set_external(ui32_vec);
  n1["ui64"].set_external(ui64_vec);

  n1["f32"].set_external(f32_vec);
  n1["f64"].set_external(f64_vec);

  n1.print();

  // set_path

  Node n2;
  n2.set_path_external("i8", i8_vec);
  n2.set_path_external("i16", i16_vec);
  n2.set_path_external("i32", i32_vec);
  n2.set_path_external("i64", i64_vec);

  n2.set_path_external("ui8", ui8_vec);
  n2.set_path_external("ui16", ui16_vec);
  n2.set_path_external("ui32", ui32_vec);
  n2.set_path_external("ui64", ui64_vec);

  n2.set_path_external("f32", f32_vec);
  n2.set_path_external("f64", f64_vec);

  i8_vec[0] = -8;
  i16_vec[0] = -16;
  i32_vec[0] = -32;
  i64_vec[0] = -64;

  ui8_vec[0] = 8;
  ui16_vec[0] = 16;
  ui32_vec[0] = 32;
  ui64_vec[0] = 64;

  f32_vec[0] = 2.71828f;
  f64_vec[0] = 3.1415;

  n1.print();
  n2.print();

  int8* i8_ptr = n1["i8"].as_int8_ptr();
  int16* i16_ptr = n1["i16"].as_int16_ptr();
  int32* i32_ptr = n1["i32"].as_int32_ptr();
  int64* i64_ptr = n1["i64"].as_int64_ptr();

  EXPECT_EQ(i8_ptr, &i8_vec[0]);
  EXPECT_EQ(i16_ptr, &i16_vec[0]);
  EXPECT_EQ(i32_ptr, &i32_vec[0]);
  EXPECT_EQ(i64_ptr, &i64_vec[0]);

  uint8* ui8_ptr = n1["ui8"].as_uint8_ptr();
  uint16* ui16_ptr = n1["ui16"].as_uint16_ptr();
  uint32* ui32_ptr = n1["ui32"].as_uint32_ptr();
  uint64* ui64_ptr = n1["ui64"].as_uint64_ptr();

  EXPECT_EQ(ui8_ptr, &ui8_vec[0]);
  EXPECT_EQ(ui16_ptr, &ui16_vec[0]);
  EXPECT_EQ(ui32_ptr, &ui32_vec[0]);
  EXPECT_EQ(ui64_ptr, &ui64_vec[0]);

  float32* f32_ptr = n1["f32"].as_float32_ptr();
  float64* f64_ptr = n1["f64"].as_float64_ptr();

  EXPECT_EQ(f32_ptr, &f32_vec[0]);
  EXPECT_EQ(f64_ptr, &f64_vec[0]);
}

// //-----------------------------------------------------------------------------
// TEST(conduit_node, node_set_existing_char8)
// {
//     Schema s;

//     std::string value = "my value";

//     s["a"].set(DataType::int64());
//     s["b"].set(DataType::char8_str(value.length()+1));

//     Schema s_compact;
//     s.compact_to(s_compact);

//     Node n2;
//     n2.set_external_char8_str(const_cast<char*>(value.c_str()));

//     Node n(s_compact);

//     n["a"].set_int64(10);
//     n["b"].update(n2);

//     EXPECT_EQ(n["a"].as_int64(),10);
//     EXPECT_EQ(n["b"].as_string(),value);

//     n.print();

//     n["b"].set(value);

//     n.print();

//     EXPECT_EQ(n["b"].as_string(),value);
// }

// //-----------------------------------------------------------------------------
// TEST(conduit_node, node_set_existing_obj)
// {
//     Node n_init;

//     n_init["a"] = DataType::list();

//     CONDUIT_INFO("INITIAL");
//     CONDUIT_INFO(n_init.to_json());

//     Node n_des;
//     n_des["a"].append().set("value");

//     CONDUIT_INFO("DES");
//     CONDUIT_INFO(n_des.to_json());

//     n_init = n_des;

//     EXPECT_EQ(n_init.number_of_children(),1);

//     CONDUIT_INFO("POST SET");
//     CONDUIT_INFO(n_init.to_json());

// }

// //-----------------------------------------------------------------------------
// TEST(conduit_node, node_set_non_compact_dtype)
// {
//     // These checks node set for a non-compact datatype
//     // matches the results of node set for a schema with
//     // the same data type.

//     Node n1;

//     DataType dt = DataType::c_int(2,0,sizeof(int)*2);
//     Schema s(dt);
//     n1.set(s);

//     n1.info().print();

//     int_array n1_vals = n1.value();

//     n1_vals[0] = 10;
//     n1_vals[1] = 20;

//     Node n2;
//     n2.set(dt);

//     n2.info().print();

//     int_array n2_vals = n1.value();

//     n2_vals[0] = 10;
//     n2_vals[1] = 20;

//     EXPECT_EQ(n1.dtype().strided_bytes(),n2.dtype().strided_bytes());
//     EXPECT_EQ(n1.total_bytes_allocated(),n2.total_bytes_allocated());

// }
