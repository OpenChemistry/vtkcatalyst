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
/// file: conduit_node.cpp
///
//-----------------------------------------------------------------------------

#include "c_typedefs.hpp"
#include "catalyst_conduit.hpp"

#include "gtest/gtest.h"
#include <iostream>

using namespace conduit_cpp;

TEST(conduit_node, cc)
{
  Node n;
  n = (int32)5;
  EXPECT_EQ(n.as_int32(), (int32)5);
  Node n2(n);
  EXPECT_EQ(n2.as_int32(), (int32)5);
}

//-----------------------------------------------------------------------------
TEST(conduit_node, simple)
{

  uint32 a_val = 10;
  uint32 b_val = 20;
  float64 c_val = 30.0;

  Node n;
  n["a"] = a_val;
  n["b"] = b_val;
  n["c"] = c_val;

  EXPECT_EQ(n["a"].as_uint32(), a_val);
  EXPECT_EQ(n["b"].as_uint32(), b_val);
  EXPECT_EQ(n["c"].as_float64(), c_val);
}

TEST(conduit_node, nested)
{

  uint32 val = 10;

  Node n;
  n["a"]["b"] = val;
  EXPECT_EQ(n["a"]["b"].as_uint32(), val);
}

//-----------------------------------------------------------------------------
TEST(conduit_node, vector)
{

  std::vector<uint32> vec;
  for (int i = 0; i < 100; i++)
    vec.push_back(i);

  Node n;
  n["a"] = vec;
  EXPECT_EQ(n["a"].as_uint32_ptr()[99], 99);
}

//-----------------------------------------------------------------------------
TEST(conduit_node, list)
{

  std::vector<uint32> vec;
  for (int i = 0; i < 100; i++)
    vec.push_back(i);

  Node n;
  Node list = n["mylist"];
  uint32 a_val = 10;
  uint32 b_val = 20;
  float64 c_val = 30.0;
  list.append().set(a_val);
  list.append().set(b_val);
  list.append().set(c_val);
  list.append().set(vec);
  EXPECT_EQ(list[0].as_uint32(), a_val);
  EXPECT_EQ(list[1].as_uint32(), b_val);
  EXPECT_EQ(list[2].as_float64(), c_val);
  EXPECT_EQ(list[3].as_uint32_ptr()[99], 99);

  EXPECT_EQ(n["mylist"][0].as_uint32(), a_val);
  EXPECT_EQ(n["mylist"][1].as_uint32(), b_val);
  EXPECT_EQ(n["mylist"][2].as_float64(), c_val);
  EXPECT_EQ(n["mylist"][3].as_uint32_ptr()[99], 99);
}

// -----------------------------------------------------------------------------
TEST(conduit_node, in_place)
{
  uint32 a_val = 10;
  uint32 b_val = 20;
  float64 c_val = 30.0;

  Node n;
  n["a"].set_external(&a_val);
  n["b"].set_external(&b_val);
  n["c"].set_external(&c_val);

  n["a"] = (uint32)11;
  n["b"] = (uint32)21;
  n["c"] = (float64)31.0;

  EXPECT_EQ(n["a"].as_uint32(), 11);
  EXPECT_EQ(n["b"].as_uint32(), 21);
  EXPECT_EQ(n["c"].as_float64(), 31.0);

  EXPECT_EQ(a_val, 11);
  EXPECT_EQ(b_val, 21);
  EXPECT_EQ(c_val, 31.0);
}

//-----------------------------------------------------------------------------
TEST(conduit_node, remove_by_name)
{
  Node n;
  n["a"] = 1;
  n["b"] = 2;
  n["c"] = 3;
  n.print();
  EXPECT_TRUE(n.has_path("a"));
  EXPECT_TRUE(n.has_path("b"));
  EXPECT_TRUE(n.has_path("c"));
  n.remove("a");
  n.print();
  EXPECT_FALSE(n.has_path("a"));
  EXPECT_TRUE(n.has_path("b"));
  EXPECT_TRUE(n.has_path("c"));
  n.remove("c");
  n.print();
  EXPECT_FALSE(n.has_path("a"));
  EXPECT_TRUE(n.has_path("b"));
  EXPECT_FALSE(n.has_path("c"));
  n.remove("b");
  n.print();
  EXPECT_FALSE(n.has_path("a"));
  EXPECT_FALSE(n.has_path("b"));
  EXPECT_FALSE(n.has_path("c"));
}

//-----------------------------------------------------------------------------
TEST(conduit_node, remove_by_index)
{
  Node n;
  n["a"] = int32(10);
  n["b"] = int32(20);
  n["c"] = int32(30);
  n.print();
  EXPECT_TRUE(n.has_path("a"));
  EXPECT_TRUE(n.has_path("b"));
  EXPECT_TRUE(n.has_path("c"));
  n.remove(1);
  n.print();
  EXPECT_TRUE(n.has_path("a"));
  EXPECT_FALSE(n.has_path("b"));
  EXPECT_TRUE(n.has_path("c"));
  EXPECT_EQ(n[0].to_int32(), 10);
  EXPECT_EQ(n[1].to_int32(), 30);
  n.remove(0);
  n.print();
  EXPECT_FALSE(n.has_path("a"));
  EXPECT_FALSE(n.has_path("b"));
  EXPECT_TRUE(n.has_path("c"));
  EXPECT_EQ(n[0].to_int32(), 30);
  n.remove(0);
  n.print();
  EXPECT_FALSE(n.has_path("a"));
  EXPECT_FALSE(n.has_path("b"));
  EXPECT_FALSE(n.has_path("c"));
}

//-----------------------------------------------------------------------------
TEST(conduit_node, check_contiguous)
{
  uint8 u8av[6] = { 2, 4, 8, 16, 32, 64 };
  uint16 u16av[6] = { 2, 4, 8, 16, 32, 64 };
  uint32 u32av[6] = { 2, 4, 8, 16, 32, 64 };
  uint64 u64av[6] = { 2, 4, 8, 16, 32, 64 };

  Node n;
  n["a"].set_external(u8av);
  n["b"].set_external(u16av);
  n["c"].set_external(u32av);
  n["d"].set_external(u64av);

  // not contig
  EXPECT_FALSE(n.is_contiguous());

  // contig & compact external
  Node n2;
  n2["a"].set_external(u64av, 2);
  n2["b"].set_external(u64av, 4, sizeof(uint64) * 2);
  EXPECT_TRUE(n2.is_contiguous());

  // make non contig
  n2["c"].set_external(u64av, 3, sizeof(uint64) * 3);
  EXPECT_FALSE(n2.is_contiguous());

  Node n3;
  n3["a"].set_external(u64av, 2);
  n3["b"].set_external(u64av, 2, sizeof(uint64) * 2, sizeof(uint64) * 2);
  EXPECT_TRUE(n3.is_contiguous());

  // nested contig and compact
  Node n4;
  n4["a/b/c/d/e/f"].set_int64(10);

  EXPECT_TRUE(n4.is_contiguous());
}

//-----------------------------------------------------------------------------
TEST(conduit_node, check_contiguous_with)
{
  uint64 u64av[10] = { 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };

  Node n1;
  n1["a"].set_external(u64av, 5);
  n1["b"].set_external(u64av, 5, 5 * sizeof(uint64));

  n1.print();

  // and contig
  EXPECT_TRUE(n1.is_contiguous());

  // we don't expect things to be contig with NULL
  EXPECT_FALSE(n1["a"].contiguous_with(NULL));
  EXPECT_FALSE(n1["b"].contiguous_with(NULL));

  // b should be contig with a
  EXPECT_TRUE(n1["b"].contiguous_with(n1["a"]));

  // but the reverse is not the case (b comes after a ...)
  EXPECT_FALSE(n1["a"].contiguous_with(n1["b"]));

  // b it should be contig with address at the end of a
  // a.ele_ptr(5) should land us right at start of b
  EXPECT_EQ(n1["b"].element_ptr(0), n1["a"].element_ptr(5));

  // b it should be contig with address at the end of a
  EXPECT_TRUE(n1["b"].contiguous_with(n1["a"].element_ptr(5)));

  Node n2;
  n2["a"].set_external(u64av, 5);
  n2["b"].set_external_uint8_ptr(NULL);
  n2["c"].set_external(u64av, 5, 5 * sizeof(uint64));

  // we expect c to be contig with a
  EXPECT_TRUE(n2["c"].contiguous_with(n2["a"]));

  // null leaf type in middle should break contig
  EXPECT_FALSE(n2.is_contiguous());

  // should be contig if we removed the null leaf
  n2.remove("b");
  EXPECT_TRUE(n2.is_contiguous());

  // but an empy leaf type in middle shouldn't break contig
  n2["a"].set_external(u64av, 5);
  n2["b"] = Node();
  n2["c"].set_external(u64av, 5, 5 * sizeof(uint64));

  EXPECT_TRUE(n2.is_contiguous());
}

//-----------------------------------------------------------------------------
TEST(conduit_node, number_of_children_object)
{

  Node n;
  EXPECT_EQ(n.number_of_children(), 0);

  n["a"].set(10);
  n["b"].set(20);
  n["c"].set(30);
  EXPECT_EQ(n.number_of_children(), 3);

  n["c"]["d"].set(40);
  EXPECT_EQ(n.number_of_children(), 3);
  EXPECT_EQ(n["c"].number_of_children(), 1);
}

//-----------------------------------------------------------------------------
TEST(conduit_node, number_of_children_list)
{

  Node n;
  EXPECT_EQ(n.number_of_children(), 0);

  n.append().set(10);
  n.append().set(20);
  n.append().set(30);
  EXPECT_EQ(n.number_of_children(), 3);

  n[2].append().set(40);
  EXPECT_EQ(n.number_of_children(), 3);
  EXPECT_EQ(n[2].number_of_children(), 1);
}

//-----------------------------------------------------------------------------
TEST(conduit_node, name_object)
{

  Node n;
  EXPECT_EQ(n.name(), "");

  n["n_first_child"].set(10);
  n["n_second_child"].set(20);
  n["n_third_child"].set(30);
  EXPECT_EQ(n["n_first_child"].name(), "n_first_child");
  EXPECT_EQ(n["n_second_child"].name(), "n_second_child");
  EXPECT_EQ(n["n_third_child"].name(), "n_third_child");

  n["n_third_child"]["n_grandchild"].set(40);
  EXPECT_EQ(n["n_first_child"]["n_grandchild"].name(), "n_grandchild");
}

//-----------------------------------------------------------------------------
TEST(conduit_node, name_list)
{

  Node n;
  EXPECT_EQ(n.name(), "");

  n.append().set(10);
  n.append().set(20);
  n.append().set(30);
  EXPECT_EQ(n[0].name(), "[0]");
  EXPECT_EQ(n[1].name(), "[1]");
  EXPECT_EQ(n[2].name(), "[2]");

  n[2].append().set(40);
  EXPECT_EQ(n[2][0].name(), "[0]");
}

//-----------------------------------------------------------------------------
TEST(conduit_node, check_path)
{

  Node n;

  n["a/b/c/d/e/f"] = 10;

  EXPECT_EQ(n.path(), "");
  EXPECT_EQ(n["a/b/c/d/e/f"].path(), "a/b/c/d/e/f");

  // check roundtrip -- using path() to fetch from root node
  EXPECT_EQ(n[n["a/b/c/d/e/f"].path()].to_int32(), n["a/b/c/d/e/f"].to_int32());

  // list cases
  EXPECT_EQ(n["a/b/c/list"].append().path(), "a/b/c/list/[0]");
  EXPECT_EQ(n["a/b/c/list"].append().path(), "a/b/c/list/[1]");
  EXPECT_EQ(n["a/b/c/list"].append().path(), "a/b/c/list/[2]");

  n.print();
}

// -----------------------------------------------------------------------------
TEST(conduit_node, check_const_access)
{
  Node n;
  int64 arr[2] = { 1, 2 };
  n["a/b"].set_int32(10);
  n["a/c"].set_int64_ptr(arr, 2);

  // Note: this won't throw b/c n is not const, so the const fetch
  // will not bind
  // const Node &n_bad = n["bad"];

  const Node n_a = n["a"];
  const int64* c_vals_const = n_a["c"].as_int64_ptr();

  EXPECT_EQ(n_a["b"].as_int32(), 10);
  EXPECT_EQ(c_vals_const[0], arr[0]);
  EXPECT_EQ(c_vals_const[1], arr[1]);
}

//-----------------------------------------------------------------------------
TEST(conduit_node, node_more_set_cases)
{
  // construct from data type
  Node n;

  // create complex tree
  int64 val[2];
  n["a/b/c/d"].append().set_external(val, 2);

  int64* cvals = n["a/b/c/d"][0].as_int64_ptr();
  cvals[0] = 1;
  cvals[1] = 2;

  // set from constructor
  Node n2(n);

  // set using node
  Node n3;
  n3.set(n2);

  const int64* n2_vals_ptr = n2["a/b/c/d"][0].as_int64_ptr();
  const int64* n3_vals_ptr = n3["a/b/c/d"][0].as_int64_ptr();

  EXPECT_EQ(n2_vals_ptr[0], 1);
  EXPECT_EQ(n2_vals_ptr[1], 2);

  EXPECT_EQ(n3_vals_ptr[0], 1);
  EXPECT_EQ(n3_vals_ptr[1], 2);
  n2.print();
  n3.print();

  float64 fval[1] = { 3.1415 };

  Node n4;
  n4["a"].set(fval);
  n4.set_path("b", fval);

  EXPECT_EQ(n4["a"].as_float64(), fval[0]);
  EXPECT_EQ(n4["b"].as_float64(), fval[0]);

  n4.print();
}

//-----------------------------------------------------------------------------
TEST(conduit_node, rename_child)
{
  Node n;

  n["a"].set((int64)0);
  n["b"].set((float64)0);
  n["c"].set(std::vector<float32>(10));

  float32* c_vals = n["c"].as_float32_ptr();
  for (index_t i = 0; i < 10; i++)
  {
    c_vals[i] = i;
  }

  n.print();

  EXPECT_TRUE(n.has_child("c"));
  EXPECT_FALSE(n.has_child("d"));

  n.rename_child("c", "d");

  n.print();

  EXPECT_TRUE(n.has_child("d"));
  EXPECT_FALSE(n.has_child("c"));

  // or old c_vals ptr should now be wired to d,
  // give the name change
  EXPECT_EQ(c_vals, n["d"].data_ptr());
}

//-----------------------------------------------------------------------------
TEST(conduit_node, list_to_obj_cleanup)
{
  // before resolved,
  // this case triggered a mem-access after release case in:
  // https://github.com/LLNL/conduit/issues/428

  // create list
  Node n;
  n.append();
  n.print();
  // switch to object
  Node n_cld = n["cld"];
  EXPECT_TRUE(n.has_child("cld"));
  n_cld.print();
}

// -----------------------------------------------------------------------------
TEST(conduit_node, check_as_native_and_native_ptr)
{
  Node n;

  char cv = 1;
  short sv = 2;
  int iv = 3;
  long lv = 4;

  signed char scv = -1;
  signed short ssv = -2;
  signed int siv = -3;
  signed long slv = -4;

  unsigned char ucv = 1;
  unsigned short usv = 2;
  unsigned int uiv = 3;
  unsigned long ulv = 4;

  float fv = 1.2f;
  double dv = 2.4;

  const char* char_strv = "str1";
  std::string std_strv = std::string("str2");

  n["cv"] = cv;
  n["sv"] = sv;
  n["iv"] = iv;
  n["lv"] = lv;

  n["scv"] = scv;
  n["ssv"] = ssv;
  n["siv"] = siv;
  n["slv"] = slv;

  n["ucv"] = ucv;
  n["usv"] = usv;
  n["uiv"] = uiv;
  n["ulv"] = ulv;

  n["fv"] = fv;
  n["dv"] = dv;

  n["char_strv"] = char_strv;
  n["std_strv"] = std_strv;

  n.print();

  char cv_r = n["cv"].as_char();
  short sv_r = n["sv"].as_short();
  int iv_r = n["iv"].as_int();
  long lv_r = n["lv"].as_long();

  EXPECT_EQ(cv, cv_r);
  EXPECT_EQ(sv, sv_r);
  EXPECT_EQ(iv, iv_r);
  EXPECT_EQ(lv, lv_r);

  signed char scv_r = n["scv"].as_signed_char();
  signed short ssv_r = n["ssv"].as_signed_short();
  signed int siv_r = n["siv"].as_signed_int();
  signed long slv_r = n["slv"].as_signed_long();

  EXPECT_EQ(scv, scv_r);
  EXPECT_EQ(ssv, ssv_r);
  EXPECT_EQ(siv, siv_r);
  EXPECT_EQ(slv, slv_r);

  unsigned char ucv_r = n["ucv"].as_unsigned_char();
  unsigned short usv_r = n["usv"].as_unsigned_short();
  unsigned int uiv_r = n["uiv"].as_unsigned_int();
  unsigned long ulv_r = n["ulv"].as_unsigned_long();

  EXPECT_EQ(ucv, ucv_r);
  EXPECT_EQ(usv, usv_r);
  EXPECT_EQ(uiv, uiv_r);
  EXPECT_EQ(ulv, ulv_r);

  float fv_r = n["fv"].as_float();
  double dv_r = n["dv"].as_double();

  EXPECT_NEAR(fv, fv_r, 0.001);
  EXPECT_NEAR(dv, dv_r, 0.001);

  char* char_strv_r = n["char_strv"].as_char8_str();
  std::string std_strv_r = n["std_strv"].as_string();
  EXPECT_EQ(std::string(char_strv), std::string(char_strv_r));
  EXPECT_EQ(std_strv, std_strv_r);

  char* cv_p_r = n["cv"].as_char_ptr();
  short* sv_p_r = n["sv"].as_short_ptr();
  int* iv_p_r = n["iv"].as_int_ptr();
  long* lv_p_r = n["lv"].as_long_ptr();

  EXPECT_EQ(cv, cv_p_r[0]);
  EXPECT_EQ(sv, sv_p_r[0]);
  EXPECT_EQ(iv, iv_p_r[0]);
  EXPECT_EQ(lv, lv_p_r[0]);

  signed char* scv_p_r = n["scv"].as_signed_char_ptr();
  signed short* ssv_p_r = n["ssv"].as_signed_short_ptr();
  signed int* siv_p_r = n["siv"].as_signed_int_ptr();
  signed long* slv_p_r = n["slv"].as_signed_long_ptr();

  EXPECT_EQ(scv, scv_p_r[0]);
  EXPECT_EQ(ssv, ssv_p_r[0]);
  EXPECT_EQ(siv, siv_p_r[0]);
  EXPECT_EQ(slv, slv_p_r[0]);

  unsigned char* ucv_p_r = n["ucv"].as_unsigned_char_ptr();
  unsigned short* usv_p_r = n["usv"].as_unsigned_short_ptr();
  unsigned int* uiv_p_r = n["uiv"].as_unsigned_int_ptr();
  unsigned long* ulv_p_r = n["ulv"].as_unsigned_long_ptr();

  EXPECT_EQ(ucv, ucv_p_r[0]);
  EXPECT_EQ(usv, usv_p_r[0]);
  EXPECT_EQ(uiv, uiv_p_r[0]);
  EXPECT_EQ(ulv, ulv_p_r[0]);

  float* fv_p_r = n["fv"].as_float_ptr();
  double* dv_p_r = n["dv"].as_double_ptr();

  EXPECT_NEAR(fv, fv_p_r[0], 0.001);
  EXPECT_NEAR(dv, dv_p_r[0], 0.001);
}

// -----------------------------------------------------------------------------
TEST(conduit_node, check_as_native_ptr_const)
{
  Node n;

  char cv = 1;
  short sv = 2;
  int iv = 3;
  long lv = 4;

  signed char scv = -1;
  signed short ssv = -2;
  signed int siv = -3;
  signed long slv = -4;

  unsigned char ucv = 1;
  unsigned short usv = 2;
  unsigned int uiv = 3;
  unsigned long ulv = 4;

  float fv = 1.2f;
  double dv = 2.4;

  const char* char_strv = "str1";

  n["cv"] = cv;
  n["sv"] = sv;
  n["iv"] = iv;
  n["lv"] = lv;

  n["scv"] = scv;
  n["ssv"] = ssv;
  n["siv"] = siv;
  n["slv"] = slv;

  n["ucv"] = ucv;
  n["usv"] = usv;
  n["uiv"] = uiv;
  n["ulv"] = ulv;

  n["fv"] = fv;
  n["dv"] = dv;

  n["char_strv"] = char_strv;

  // n_const has same_c_node as n, but is const.
  const Node n_const(n);
  n_const.print();

  const char* cv_p_r = n_const["cv"].as_char_ptr();
  const short* sv_p_r = n_const["sv"].as_short_ptr();
  const int* iv_p_r = n_const["iv"].as_int_ptr();
  const long* lv_p_r = n_const["lv"].as_long_ptr();

  EXPECT_EQ(cv, cv_p_r[0]);
  EXPECT_EQ(sv, sv_p_r[0]);
  EXPECT_EQ(iv, iv_p_r[0]);
  EXPECT_EQ(lv, lv_p_r[0]);

  const signed char* scv_p_r = n_const["scv"].as_signed_char_ptr();
  const signed short* ssv_p_r = n_const["ssv"].as_signed_short_ptr();
  const signed int* siv_p_r = n_const["siv"].as_signed_int_ptr();
  const signed long* slv_p_r = n_const["slv"].as_signed_long_ptr();

  EXPECT_EQ(scv, scv_p_r[0]);
  EXPECT_EQ(ssv, ssv_p_r[0]);
  EXPECT_EQ(siv, siv_p_r[0]);
  EXPECT_EQ(slv, slv_p_r[0]);

  const unsigned char* ucv_p_r = n_const["ucv"].as_unsigned_char_ptr();
  const unsigned short* usv_p_r = n_const["usv"].as_unsigned_short_ptr();
  const unsigned int* uiv_p_r = n_const["uiv"].as_unsigned_int_ptr();
  const unsigned long* ulv_p_r = n_const["ulv"].as_unsigned_long_ptr();

  EXPECT_EQ(ucv, ucv_p_r[0]);
  EXPECT_EQ(usv, usv_p_r[0]);
  EXPECT_EQ(uiv, uiv_p_r[0]);
  EXPECT_EQ(ulv, ulv_p_r[0]);

  const float* fv_p_r = n_const["fv"].as_float_ptr();
  const double* dv_p_r = n_const["dv"].as_double_ptr();

  EXPECT_NEAR(fv, fv_p_r[0], 0.001);
  EXPECT_NEAR(dv, dv_p_r[0], 0.001);

  const char* char_strv_r = n["char_strv"].as_char8_str();
  EXPECT_EQ(std::string(char_strv), std::string(char_strv_r));
}

// -----------------------------------------------------------------------------
TEST(conduit_node, check_as_bitwidth_and_as_bitwidth_ptr)
{
  Node n;

  int8 i8v = -1;
  int16 i16v = -2;
  int32 i32v = -3;
  int64 i64v = -4;

  uint8 ui8v = 1;
  uint16 ui16v = 2;
  uint32 ui32v = 3;
  uint64 ui64v = 4;

  float32 f32v = 1.2f;
  float64 f64v = 2.4;

  n["i8v"] = i8v;
  n["i16v"] = i16v;
  n["i32v"] = i32v;
  n["i64v"] = i64v;

  n["ui8v"] = ui8v;
  n["ui16v"] = ui16v;
  n["ui32v"] = ui32v;
  n["ui64v"] = ui64v;

  n["f32v"] = f32v;
  n["f64v"] = f64v;

  n.print();

  int8 i8v_r = n["i8v"].as_int8();
  int16 i16v_r = n["i16v"].as_int16();
  int32 i32v_r = n["i32v"].as_int32();
  int64 i64v_r = n["i64v"].as_int64();

  EXPECT_EQ(i8v, i8v_r);
  EXPECT_EQ(i16v, i16v_r);
  EXPECT_EQ(i32v, i32v_r);
  EXPECT_EQ(i64v, i64v_r);

  uint8 ui8v_r = n["ui8v"].as_uint8();
  uint16 ui16v_r = n["ui16v"].as_uint16();
  uint32 ui32v_r = n["ui32v"].as_uint32();
  uint64 ui64v_r = n["ui64v"].as_uint64();

  EXPECT_EQ(ui8v, ui8v_r);
  EXPECT_EQ(ui16v, ui16v_r);
  EXPECT_EQ(ui32v, ui32v_r);
  EXPECT_EQ(ui64v, ui64v_r);

  float32 f32v_r = n["f32v"].as_float32();
  float64 f64v_r = n["f64v"].as_float64();

  EXPECT_NEAR(f32v, f32v_r, 0.001);
  EXPECT_NEAR(f64v, f64v_r, 0.001);

  int8* i8v_p_r = n["i8v"].as_int8_ptr();
  int16* i16v_p_r = n["i16v"].as_int16_ptr();
  int32* i32v_p_r = n["i32v"].as_int32_ptr();
  int64* i64v_p_r = n["i64v"].as_int64_ptr();

  EXPECT_EQ(i8v, i8v_p_r[0]);
  EXPECT_EQ(i16v, i16v_p_r[0]);
  EXPECT_EQ(i32v, i32v_p_r[0]);
  EXPECT_EQ(i64v, i64v_p_r[0]);

  uint8* ui8v_p_r = n["ui8v"].as_uint8_ptr();
  uint16* ui16v_p_r = n["ui16v"].as_uint16_ptr();
  uint32* ui32v_p_r = n["ui32v"].as_uint32_ptr();
  uint64* ui64v_p_r = n["ui64v"].as_uint64_ptr();

  EXPECT_EQ(ui8v, ui8v_p_r[0]);
  EXPECT_EQ(ui16v, ui16v_p_r[0]);
  EXPECT_EQ(ui32v, ui32v_p_r[0]);
  EXPECT_EQ(ui64v, ui64v_p_r[0]);

  float32* f32v_p_r = n["f32v"].as_float32_ptr();
  float64* f64v_p_r = n["f64v"].as_float64_ptr();

  EXPECT_NEAR(f32v, f32v_p_r[0], 0.001);
  EXPECT_NEAR(f64v, f64v_p_r[0], 0.001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node, check_as_bitwidth_ptr_const)
{
  Node n;

  int8 i8v = -1;
  int16 i16v = -2;
  int32 i32v = -3;
  int64 i64v = -4;

  uint8 ui8v = 1;
  uint16 ui16v = 2;
  uint32 ui32v = 3;
  uint64 ui64v = 4;

  float32 f32v = 1.2f;
  float64 f64v = 2.4;

  n["i8v"] = i8v;
  n["i16v"] = i16v;
  n["i32v"] = i32v;
  n["i64v"] = i64v;

  n["ui8v"] = ui8v;
  n["ui16v"] = ui16v;
  n["ui32v"] = ui32v;
  n["ui64v"] = ui64v;

  n["f32v"] = f32v;
  n["f64v"] = f64v;

  // n_const has same_c_node as n, but is const.
  const Node n_const(n);
  n_const.print();

  const int8* i8v_p_r = n_const["i8v"].as_int8_ptr();
  const int16* i16v_p_r = n_const["i16v"].as_int16_ptr();
  const int32* i32v_p_r = n_const["i32v"].as_int32_ptr();
  const int64* i64v_p_r = n_const["i64v"].as_int64_ptr();

  EXPECT_EQ(i8v, i8v_p_r[0]);
  EXPECT_EQ(i16v, i16v_p_r[0]);
  EXPECT_EQ(i32v, i32v_p_r[0]);
  EXPECT_EQ(i64v, i64v_p_r[0]);

  const uint8* ui8v_p_r = n_const["ui8v"].as_uint8_ptr();
  const uint16* ui16v_p_r = n_const["ui16v"].as_uint16_ptr();
  const uint32* ui32v_p_r = n_const["ui32v"].as_uint32_ptr();
  const uint64* ui64v_p_r = n_const["ui64v"].as_uint64_ptr();

  EXPECT_EQ(ui8v, ui8v_p_r[0]);
  EXPECT_EQ(ui16v, ui16v_p_r[0]);
  EXPECT_EQ(ui32v, ui32v_p_r[0]);
  EXPECT_EQ(ui64v, ui64v_p_r[0]);

  const float32* f32v_p_r = n_const["f32v"].as_float32_ptr();
  const float64* f64v_p_r = n_const["f64v"].as_float64_ptr();

  EXPECT_NEAR(f32v, f32v_p_r[0], 0.001);
  EXPECT_NEAR(f64v, f64v_p_r[0], 0.001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, check_assignment_from_bitwidth_vec)
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
  Node n;
  n["i8"] = i8_vec;
  n["i16"] = i16_vec;
  n["i32"] = i32_vec;
  n["i64"] = i64_vec;

  n["ui8"] = ui8_vec;
  n["ui16"] = ui16_vec;
  n["ui32"] = ui32_vec;
  n["ui64"] = ui64_vec;

  n["f32"] = f32_vec;
  n["f64"] = f64_vec;

  n.print();

  int8* i8_ptr = n["i8"].as_int8_ptr();
  int16* i16_ptr = n["i16"].as_int16_ptr();
  int32* i32_ptr = n["i32"].as_int32_ptr();
  int64* i64_ptr = n["i64"].as_int64_ptr();

  EXPECT_EQ(i8_ptr[0], i8_vec[0]);
  EXPECT_EQ(i16_ptr[0], i16_vec[0]);
  EXPECT_EQ(i32_ptr[0], i32_vec[0]);
  EXPECT_EQ(i64_ptr[0], i64_vec[0]);

  uint8* ui8_ptr = n["ui8"].as_uint8_ptr();
  uint16* ui16_ptr = n["ui16"].as_uint16_ptr();
  uint32* ui32_ptr = n["ui32"].as_uint32_ptr();
  uint64* ui64_ptr = n["ui64"].as_uint64_ptr();

  EXPECT_EQ(ui8_ptr[0], ui8_vec[0]);
  EXPECT_EQ(ui16_ptr[0], ui16_vec[0]);
  EXPECT_EQ(ui32_ptr[0], ui32_vec[0]);
  EXPECT_EQ(ui64_ptr[0], ui64_vec[0]);

  float32* f32_ptr = n["f32"].as_float32_ptr();
  float64* f64_ptr = n["f64"].as_float64_ptr();

  EXPECT_EQ(f32_ptr[0], f32_vec[0]);
  EXPECT_EQ(f64_ptr[0], f64_vec[0]);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, check_assignment_from_cstyle_vec)
{

  std::vector<char> char_vec(1);
  std::vector<short> short_vec(1);
  std::vector<int> int_vec(1);
  std::vector<long> long_vec(1);

  char_vec[0] = -8;
  short_vec[0] = -16;
  int_vec[0] = -32;
  long_vec[0] = -64;

  std::vector<unsigned char> uchar_vec(1);
  std::vector<unsigned short> ushort_vec(1);
  std::vector<unsigned int> uint_vec(1);
  std::vector<unsigned long> ulong_vec(1);

  uchar_vec[0] = 8;
  ushort_vec[0] = 16;
  uint_vec[0] = 32;
  ulong_vec[0] = 64;

  std::vector<signed char> schar_vec(1);
  std::vector<signed short> sshort_vec(1);
  std::vector<signed int> sint_vec(1);
  std::vector<signed long> slong_vec(1);

  schar_vec[0] = 8;
  sshort_vec[0] = 16;
  sint_vec[0] = 32;
  slong_vec[0] = 64;

  std::vector<float> f_vec(1);
  std::vector<double> d_vec(1);
  f_vec[0] = 2.71828f;
  d_vec[0] = 3.1415;

  // set
  Node n;
  n["char"] = char_vec;
  n["short"] = short_vec;
  n["int"] = int_vec;
  n["long"] = long_vec;

  n["uchar"] = uchar_vec;
  n["ushort"] = ushort_vec;
  n["uint"] = uint_vec;
  n["ulong"] = ulong_vec;

  n["schar"] = schar_vec;
  n["sshort"] = sshort_vec;
  n["sint"] = sint_vec;
  n["slong"] = slong_vec;

  n["f"] = f_vec;
  n["d"] = d_vec;

  n.print();

  char* char_ptr = n["char"].as_char_ptr();
  short* short_ptr = n["short"].as_short_ptr();
  int* int_ptr = n["int"].as_int_ptr();
  long* long_ptr = n["long"].as_long_ptr();

  EXPECT_EQ(char_ptr[0], char_vec[0]);
  EXPECT_EQ(short_ptr[0], short_vec[0]);
  EXPECT_EQ(int_ptr[0], int_vec[0]);
  EXPECT_EQ(long_ptr[0], long_vec[0]);

  unsigned char* uchar_ptr = n["uchar"].as_unsigned_char_ptr();
  unsigned short* ushort_ptr = n["ushort"].as_unsigned_short_ptr();
  unsigned int* uint_ptr = n["uint"].as_unsigned_int_ptr();
  unsigned long* ulong_ptr = n["ulong"].as_unsigned_long_ptr();

  EXPECT_EQ(uchar_ptr[0], uchar_vec[0]);
  EXPECT_EQ(ushort_ptr[0], ushort_vec[0]);
  EXPECT_EQ(uint_ptr[0], uint_vec[0]);
  EXPECT_EQ(ulong_ptr[0], ulong_vec[0]);

  signed char* schar_ptr = n["schar"].as_signed_char_ptr();
  signed short* sshort_ptr = n["sshort"].as_signed_short_ptr();
  signed int* sint_ptr = n["sint"].as_signed_int_ptr();
  signed long* slong_ptr = n["slong"].as_signed_long_ptr();

  EXPECT_EQ(schar_ptr[0], schar_vec[0]);
  EXPECT_EQ(sshort_ptr[0], sshort_vec[0]);
  EXPECT_EQ(sint_ptr[0], sint_vec[0]);
  EXPECT_EQ(slong_ptr[0], slong_vec[0]);

  float* f_ptr = n["f"].as_float_ptr();
  double* d_ptr = n["d"].as_double_ptr();

  EXPECT_EQ(f_ptr[0], f_vec[0]);
  EXPECT_EQ(d_ptr[0], d_vec[0]);
}
