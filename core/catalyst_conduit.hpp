/*
Copyright (c) 2014-2020, Lawrence Livermore National Security, LLC.

Produced at the Lawrence Livermore National Laboratory

LLNL-CODE-666778

All rights reserved.

This file is part of Conduit.

For details, see: http://software.llnl.gov/conduit/.

Please also read conduit/LICENSE

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice,
  this list of conditions and the disclaimer below.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the disclaimer (as noted below) in the
  documentation and/or other materials provided with the distribution.

* Neither the name of the LLNS/LLNL nor the names of its contributors may
  be used to endorse or promote products derived from this software without
  specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL LAWRENCE LIVERMORE NATIONAL SECURITY,
LLC, THE U.S. DEPARTMENT OF ENERGY OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

Additional BSD Notice

 1. This notice is required to be provided under our contract with the U.S.
    Department of Energy (DOE). This work was produced at Lawrence
    Livermore National Laboratory under Contract No. DE-AC52-07NA27344 with
    the DOE.

 2. Neither the United States Government nor Lawrence Livermore National
    Security, LLC nor any of their employees, makes any warranty, express
    or implied, or assumes any liability or responsibility for the
    accuracy, completeness, or usefulness of any information, apparatus,
    product, or process disclosed, or represents that its use would not
    infringe privately-owned rights.

 3. Also, reference herein to any specific commercial products, process,
    or services by trade name, trademark, manufacturer or otherwise does
    not necessarily constitute or imply its endorsement, recommendation,
    or favoring by the United States Government or Lawrence Livermore
    National Security, LLC. The views and opinions of authors expressed
    herein do not necessarily state or reflect those of the United
    States Government or Lawrence Livermore National Security, LLC, and
    shall not be used for advertising or product endorsement purposes.
*/

#ifndef catalyst_conduit_hpp
#define catalyst_conduit_hpp

#include <cstring>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include <conduit.h>

namespace conduit_cpp
{

class Node
{
public:
  conduit_node* c_node;

  Node()
    : c_node(conduit_node_create())
  {
  }
  Node(const Node& other)
  {
    this->c_node = conduit_node_create();
    this->set(other);
  }
  Node(Node&& other)
    : c_node(other.c_node)
  {
    other.c_node = nullptr;
  }
  ~Node()
  {
    if (this->c_node)
    {
      conduit_node_destroy(this->c_node);
    }
  }
  //-----------------------------------------------------------------------------
  // -- set for generic types --
  //-----------------------------------------------------------------------------
  void set_node(const Node& data) { conduit_node_set_node(this->c_node, data.c_node); }
  void set(const Node& data) { this->set_node(data); }

  //-----------------------------------------------------------------------------
  //
  // -- begin declaration of Node set methods --
  //
  //-----------------------------------------------------------------------------
  ///@name Node::set(...)
  ///@{
  //-----------------------------------------------------------------------------
  /// description:
  ///   set(...) methods follow copy semantics.
  //-----------------------------------------------------------------------------

  void set_int8(const conduit_int8 data) { conduit_node_set_int8(this->c_node, data); }

  void set(const conduit_int8 data) { this->set_int8(data); }

  void set_int16(const conduit_int16 data) { conduit_node_set_int16(this->c_node, data); }

  void set(const conduit_int16 data) { this->set_int16(data); }

  void set_int32(const conduit_int32 data) { conduit_node_set_int32(this->c_node, data); }

  void set(const conduit_int32 data) { this->set_int32(data); }

  void set_int64(const conduit_int64 data) { conduit_node_set_int64(this->c_node, data); }

  void set(const conduit_int64 data) { this->set_int64(data); }

  void set_uint8(const conduit_uint8 data) { conduit_node_set_uint8(this->c_node, data); }

  void set(const conduit_uint8 data) { this->set_uint8(data); }

  void set_uint16(const conduit_uint16 data) { conduit_node_set_uint16(this->c_node, data); }

  void set(const conduit_uint16 data) { this->set_uint16(data); }

  void set_uint32(const conduit_uint32 data) { conduit_node_set_uint32(this->c_node, data); }

  void set(const conduit_uint32 data) { this->set_uint32(data); }

  void set_uint64(const conduit_uint64 data) { conduit_node_set_uint64(this->c_node, data); }

  void set(const conduit_uint64 data) { this->set_uint64(data); }

  void set_float32(const conduit_float32 data) { conduit_node_set_float32(this->c_node, data); }

  void set(const conduit_float32 data) { this->set_float32(data); }

  void set_float64(const conduit_float64 data) { conduit_node_set_float64(this->c_node, data); }

  void set(const conduit_float64 data) { this->set_float64(data); }

  void set(const char data) { conduit_node_set_char(this->c_node, data); }
#ifndef CONDUIT_USE_CHAR
  void set(const signed char data) { conduit_node_set_signed_char(this->c_node, data); }
  void set(const unsigned char data) { conduit_node_set_unsigned_char(this->c_node, data); }
#endif
#ifndef CONDUIT_USE_SHORT
  void set(const short data) { conduit_node_set_short(this->c_node, data); }
  void set(const unsigned short data) { conduit_node_set_unsigned_short(this->c_node, data); }
#endif
#ifndef CONDUIT_USE_INT
  void set(const int data) { conduit_node_set_int(this->c_node, data); }
  void set(const unsigned int data) { conduit_node_set_unsigned_int(this->c_node, data); }
#endif
#ifndef CONDUIT_USE_LONG
  void set(const long data) { conduit_node_set_long(this->c_node, data); }
  void set(const unsigned long data) { conduit_node_set_unsigned_long(this->c_node, data); }
#endif
  void set_string(const std::string& data)
  {

    conduit_node_set_char8_str(this->c_node, data.c_str());
  }

  void set(const std::string& data) { this->set_string(data); }

  void set_char8_str(const char* data) { conduit_node_set_char8_str(this->c_node, data); }

  void set_int8_vector(const std::vector<conduit_int8>& data)
  {

    conduit_node_set_int8_ptr(this->c_node, std::vector<conduit_int8>(data).data(), data.size());
  }

  void set(const std::vector<conduit_int8>& data) { this->set_int8_vector(data); }

  void set_int16_vector(const std::vector<conduit_int16>& data)
  {

    conduit_node_set_int16_ptr(this->c_node, std::vector<conduit_int16>(data).data(), data.size());
  }

  void set(const std::vector<conduit_int16>& data) { this->set_int16_vector(data); }

  void set_int32_vector(const std::vector<conduit_int32>& data)
  {

    conduit_node_set_int32_ptr(this->c_node, std::vector<conduit_int32>(data).data(), data.size());
  }

  void set(const std::vector<conduit_int32>& data) { this->set_int32_vector(data); }

  void set_int64_vector(const std::vector<conduit_int64>& data)
  {

    conduit_node_set_int64_ptr(this->c_node, std::vector<conduit_int64>(data).data(), data.size());
  }

  void set(const std::vector<conduit_int64>& data) { this->set_int64_vector(data); }

  void set_uint8_vector(const std::vector<conduit_uint8>& data)
  {

    conduit_node_set_uint8_ptr(this->c_node, std::vector<conduit_uint8>(data).data(), data.size());
  }

  void set(const std::vector<conduit_uint8>& data) { this->set_uint8_vector(data); }

  void set_uint16_vector(const std::vector<conduit_uint16>& data)
  {

    conduit_node_set_uint16_ptr(
      this->c_node, std::vector<conduit_uint16>(data).data(), data.size());
  }

  void set(const std::vector<conduit_uint16>& data) { this->set_uint16_vector(data); }

  void set_uint32_vector(const std::vector<conduit_uint32>& data)
  {

    conduit_node_set_uint32_ptr(
      this->c_node, std::vector<conduit_uint32>(data).data(), data.size());
  }

  void set(const std::vector<conduit_uint32>& data) { this->set_uint32_vector(data); }

  void set_uint64_vector(const std::vector<conduit_uint64>& data)
  {

    conduit_node_set_uint64_ptr(
      this->c_node, std::vector<conduit_uint64>(data).data(), data.size());
  }

  void set(const std::vector<conduit_uint64>& data) { this->set_uint64_vector(data); }

  void set_float32_vector(const std::vector<conduit_float32>& data)
  {

    conduit_node_set_float32_ptr(
      this->c_node, std::vector<conduit_float32>(data).data(), data.size());
  }

  void set(const std::vector<conduit_float32>& data) { this->set_float32_vector(data); }

  void set_float64_vector(const std::vector<conduit_float64>& data)
  {

    conduit_node_set_float64_ptr(
      this->c_node, std::vector<conduit_float64>(data).data(), data.size());
  }

  void set(const std::vector<conduit_float64>& data) { this->set_float64_vector(data); }

  void set(const std::vector<char>& data)
  {

    conduit_node_set_char_ptr(this->c_node, std::vector<char>(data).data(), data.size());
  }
#ifndef CONDUIT_USE_CHAR
  void set(const std::vector<signed char>& data)
  {

    conduit_node_set_signed_char_ptr(
      this->c_node, std::vector<signed char>(data).data(), data.size());
  }
  void set(const std::vector<unsigned char>& data)
  {

    conduit_node_set_unsigned_char_ptr(
      this->c_node, std::vector<unsigned char>(data).data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_SHORT
  void set(const std::vector<short>& data)
  {

    conduit_node_set_short_ptr(this->c_node, std::vector<short>(data).data(), data.size());
  }
  void set(const std::vector<unsigned short>& data)
  {

    conduit_node_set_unsigned_short_ptr(
      this->c_node, std::vector<unsigned short>(data).data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_INT
  void set(const std::vector<int>& data)
  {

    conduit_node_set_int_ptr(this->c_node, std::vector<int>(data).data(), data.size());
  }
  void set(const std::vector<unsigned int>& data)
  {

    conduit_node_set_unsigned_int_ptr(
      this->c_node, std::vector<unsigned int>(data).data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_LONG
  void set(const std::vector<long>& data)
  {

    conduit_node_set_long_ptr(this->c_node, std::vector<long>(data).data(), data.size());
  }
  void set(const std::vector<unsigned long>& data)
  {

    conduit_node_set_unsigned_long_ptr(
      this->c_node, std::vector<unsigned long>(data).data(), data.size());
  }
#endif
  void set_int8_ptr(const conduit_int8* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int8),
    conduit_index_t element_bytes = sizeof(conduit_int8), conduit_index_t endianness = 0)
  {
    conduit_int8 data_cpy[num_elements];
    conduit_node_set_int8_ptr_detailed(this->c_node,
      (conduit_int8*)memcpy(data_cpy, data, sizeof(conduit_int8) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set(const conduit_int8* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int8),
    conduit_index_t element_bytes = sizeof(conduit_int8), conduit_index_t endianness = 0)
  {

    this->set_int8_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_int16_ptr(const conduit_int16* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int16),
    conduit_index_t element_bytes = sizeof(conduit_int16), conduit_index_t endianness = 0)
  {
    conduit_int16 data_cpy[num_elements];
    conduit_node_set_int16_ptr_detailed(this->c_node,
      (conduit_int16*)memcpy(data_cpy, data, sizeof(conduit_int16) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set(const conduit_int16* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int16),
    conduit_index_t element_bytes = sizeof(conduit_int16), conduit_index_t endianness = 0)
  {
    this->set_int16_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_int32_ptr(const conduit_int32* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int32),
    conduit_index_t element_bytes = sizeof(conduit_int32), conduit_index_t endianness = 0)
  {
    conduit_int32 data_cpy[num_elements];
    conduit_node_set_int32_ptr_detailed(this->c_node,
      (conduit_int32*)memcpy(data_cpy, data, sizeof(conduit_int32) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set(const conduit_int32* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int32),
    conduit_index_t element_bytes = sizeof(conduit_int32), conduit_index_t endianness = 0)
  {
    this->set_int32_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_int64_ptr(const conduit_int64* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int64),
    conduit_index_t element_bytes = sizeof(conduit_int64), conduit_index_t endianness = 0)
  {
    conduit_int64 data_cpy[num_elements];
    conduit_node_set_int64_ptr_detailed(this->c_node,
      (conduit_int64*)memcpy(data_cpy, data, sizeof(conduit_int64) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set(const conduit_int64* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int64),
    conduit_index_t element_bytes = sizeof(conduit_int64), conduit_index_t endianness = 0)
  {
    this->set_int64_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_uint8_ptr(const conduit_uint8* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint8),
    conduit_index_t element_bytes = sizeof(conduit_uint8), conduit_index_t endianness = 0)
  {
    conduit_uint8 data_cpy[num_elements];
    conduit_node_set_uint8_ptr_detailed(this->c_node,
      (conduit_uint8*)memcpy(data_cpy, data, sizeof(conduit_uint8) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set(const conduit_uint8* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint8),
    conduit_index_t element_bytes = sizeof(conduit_uint8), conduit_index_t endianness = 0)
  {
    this->set_uint8_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_uint16_ptr(const conduit_uint16* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint16),
    conduit_index_t element_bytes = sizeof(conduit_uint16), conduit_index_t endianness = 0)
  {
    conduit_uint16 data_cpy[num_elements];
    conduit_node_set_uint16_ptr_detailed(this->c_node,
      (conduit_uint16*)memcpy(data_cpy, data, sizeof(conduit_uint16) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set(const conduit_uint16* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint16),
    conduit_index_t element_bytes = sizeof(conduit_uint16), conduit_index_t endianness = 0)
  {
    this->set_uint16_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_uint32_ptr(const conduit_uint32* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint32),
    conduit_index_t element_bytes = sizeof(conduit_uint32), conduit_index_t endianness = 0)
  {
    conduit_uint32 data_cpy[num_elements];
    conduit_node_set_uint32_ptr_detailed(this->c_node,
      (conduit_uint32*)memcpy(data_cpy, data, sizeof(conduit_uint32) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set(const conduit_uint32* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint32),
    conduit_index_t element_bytes = sizeof(conduit_uint32), conduit_index_t endianness = 0)
  {
    this->set_uint32_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_uint64_ptr(const conduit_uint64* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint64),
    conduit_index_t element_bytes = sizeof(conduit_uint64), conduit_index_t endianness = 0)
  {
    conduit_uint64 data_cpy[num_elements];
    conduit_node_set_uint64_ptr_detailed(this->c_node,
      (conduit_uint64*)memcpy(data_cpy, data, sizeof(conduit_uint64) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set(const conduit_uint64* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint64),
    conduit_index_t element_bytes = sizeof(conduit_uint64), conduit_index_t endianness = 0)
  {
    this->set_uint64_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_float32_ptr(const conduit_float32* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_float32),
    conduit_index_t element_bytes = sizeof(conduit_float32), conduit_index_t endianness = 0)
  {
    conduit_float32 data_cpy[num_elements];
    conduit_node_set_float32_ptr_detailed(this->c_node,
      (conduit_float32*)memcpy(data_cpy, data, sizeof(conduit_float32) * num_elements),
      num_elements, offset, stride, element_bytes, endianness);
  }

  void set(const conduit_float32* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_float32),
    conduit_index_t element_bytes = sizeof(conduit_float32), conduit_index_t endianness = 0)
  {
    this->set_float32_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_float64_ptr(const conduit_float64* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_float64),
    conduit_index_t element_bytes = sizeof(conduit_float64), conduit_index_t endianness = 0)
  {
    conduit_float64 data_cpy[num_elements];
    conduit_node_set_float64_ptr_detailed(this->c_node,
      (conduit_float64*)memcpy(data_cpy, data, sizeof(conduit_float64) * num_elements),
      num_elements, offset, stride, element_bytes, endianness);
  }

  void set(const conduit_float64* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_float64),
    conduit_index_t element_bytes = sizeof(conduit_float64), conduit_index_t endianness = 0)
  {
    this->set_float64_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_char_ptr(const char* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_CHAR), conduit_index_t endianness = 0)
  {
    char data_cpy[num_elements];
    conduit_node_set_char_ptr_detailed(this->c_node,
      (char*)memcpy(data_cpy, data, sizeof(char) * num_elements), num_elements, offset, stride,
      element_bytes, endianness);
  }
#ifndef CONDUIT_USE_CHAR
  void set(const signed char* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_SIGNED_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_SIGNED_CHAR),
    conduit_index_t endianness = 0)
  {
    signed char data_cpy[num_elements];
    conduit_node_set_signed_char_ptr_detailed(this->c_node,
      (signed char*)memcpy(data_cpy, data, sizeof(signed char) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }
  void set(const unsigned char* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_CHAR),
    conduit_index_t endianness = 0)
  {
    unsigned char data_cpy[num_elements];
    conduit_node_set_unsigned_char_ptr_detailed(this->c_node,
      (unsigned char*)memcpy(data_cpy, data, sizeof(unsigned char) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_SHORT
  void set(const short* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_SHORT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_SHORT), conduit_index_t endianness = 0)
  {
    short data_cpy[num_elements];
    conduit_node_set_short_ptr_detailed(this->c_node,
      (short*)memcpy(data_cpy, data, sizeof(short) * num_elements), num_elements, offset, stride,
      element_bytes, endianness);
  }
  void set(const unsigned short* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_SHORT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_SHORT),
    conduit_index_t endianness = 0)
  {
    unsigned short data_cpy[num_elements];
    conduit_node_set_unsigned_short_ptr_detailed(this->c_node,
      (unsigned short*)memcpy(data_cpy, data, sizeof(unsigned short) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_INT
  void set(const int* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_INT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_INT), conduit_index_t endianness = 0)
  {
    int data_cpy[num_elements];
    conduit_node_set_int_ptr_detailed(this->c_node,
      (int*)memcpy(data_cpy, data, sizeof(int) * num_elements), num_elements, offset, stride,
      element_bytes, endianness);
  }
  void set(const unsigned int* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_INT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_INT),
    conduit_index_t endianness = 0)
  {
    unsigned int data_cpy[num_elements];
    conduit_node_set_unsigned_int_ptr_detailed(this->c_node,
      (unsigned int*)memcpy(data_cpy, data, sizeof(unsigned int) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_LONG
  void set(const long* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_LONG),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_LONG), conduit_index_t endianness = 0)
  {
    long data_cpy[num_elements];
    conduit_node_set_long_ptr_detailed(this->c_node,
      (long*)memcpy(data_cpy, data, sizeof(long) * num_elements), num_elements, offset, stride,
      element_bytes, endianness);
  }
  void set(const unsigned long* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
    conduit_index_t endianness = 0)
  {
    unsigned long data_cpy[num_elements];
    conduit_node_set_unsigned_long_ptr_detailed(this->c_node,
      (unsigned long*)memcpy(data_cpy, data, sizeof(unsigned long) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }
#endif

  void set_path_node(const std::string& path, const Node& data)
  {
    conduit_node_set_path_node(this->c_node, path.c_str(), data.c_node);
  }
  void set_path(const std::string& path, const Node& data) { this->set_path_node(path, data); }

  void set_path_int8(const std::string& path, const conduit_int8 data)
  {

    conduit_node_set_path_int8(this->c_node, path.c_str(), data);
  }

  void set_path(const std::string& path, const conduit_int8 data)
  {
    this->set_path_int8(path, data);
  }

  void set_path_int16(const std::string& path, const conduit_int16 data)
  {

    conduit_node_set_path_int16(this->c_node, path.c_str(), data);
  }

  void set_path(const std::string& path, const conduit_int16 data)
  {
    this->set_path_int16(path, data);
  }

  void set_path_int32(const std::string& path, const conduit_int32 data)
  {

    conduit_node_set_path_int32(this->c_node, path.c_str(), data);
  }

  void set_path(const std::string& path, const conduit_int32 data)
  {
    this->set_path_int32(path, data);
  }

  void set_path_int64(const std::string& path, const conduit_int64 data)
  {

    conduit_node_set_path_int64(this->c_node, path.c_str(), data);
  }

  void set_path(const std::string& path, const conduit_int64 data)
  {
    this->set_path_int64(path, data);
  }

  void set_path_uint8(const std::string& path, const conduit_uint8 data)
  {

    conduit_node_set_path_uint8(this->c_node, path.c_str(), data);
  }

  void set_path(const std::string& path, const conduit_uint8 data)
  {
    this->set_path_uint8(path, data);
  }

  void set_path_uint16(const std::string& path, const conduit_uint16 data)
  {

    conduit_node_set_path_uint16(this->c_node, path.c_str(), data);
  }

  void set_path(const std::string& path, const conduit_uint16 data)
  {
    this->set_path_uint16(path, data);
  }

  void set_path_uint32(const std::string& path, const conduit_uint32 data)
  {

    conduit_node_set_path_uint32(this->c_node, path.c_str(), data);
  }

  void set_path(const std::string& path, const conduit_uint32 data)
  {
    this->set_path_uint32(path, data);
  }

  void set_path_uint64(const std::string& path, const conduit_uint64 data)
  {

    conduit_node_set_path_uint64(this->c_node, path.c_str(), data);
  }

  void set_path(const std::string& path, const conduit_uint64 data)
  {
    this->set_path_uint64(path, data);
  }

  void set_path_float32(const std::string& path, const conduit_float32 data)
  {

    conduit_node_set_path_float32(this->c_node, path.c_str(), data);
  }

  void set_path(const std::string& path, const conduit_float32 data)
  {
    this->set_path_float32(path, data);
  }

  void set_path_float64(const std::string& path, const conduit_float64 data)
  {

    conduit_node_set_path_float64(this->c_node, path.c_str(), data);
  }

  void set_path(const std::string& path, const conduit_float64 data)
  {
    this->set_path_float64(path, data);
  }

  void set_path(const std::string& path, const char data)
  {

    conduit_node_set_path_char(this->c_node, path.c_str(), data);
  }
#ifndef CONDUIT_USE_CHAR
  void set_path(const std::string& path, const signed char data)
  {

    conduit_node_set_path_signed_char(this->c_node, path.c_str(), data);
  }
  void set_path(const std::string& path, const unsigned char data)
  {

    conduit_node_set_path_unsigned_char(this->c_node, path.c_str(), data);
  }
#endif
#ifndef CONDUIT_USE_SHORT
  void set_path(const std::string& path, const short data)
  {

    conduit_node_set_path_short(this->c_node, path.c_str(), data);
  }
  void set_path(const std::string& path, const unsigned short data)
  {

    conduit_node_set_path_unsigned_short(this->c_node, path.c_str(), data);
  }
#endif
#ifndef CONDUIT_USE_INT
  void set_path(const std::string& path, const int data)
  {

    conduit_node_set_path_int(this->c_node, path.c_str(), data);
  }
  void set_path(const std::string& path, const unsigned int data)
  {

    conduit_node_set_path_unsigned_int(this->c_node, path.c_str(), data);
  }
#endif
#ifndef CONDUIT_USE_LONG
  void set_path(const std::string& path, const long data)
  {

    conduit_node_set_path_long(this->c_node, path.c_str(), data);
  }
  void set_path(const std::string& path, const unsigned long data)
  {

    conduit_node_set_path_unsigned_long(this->c_node, path.c_str(), data);
  }
#endif
  void set_path_string(const std::string& path, const std::string data)
  {

    conduit_node_set_path_char8_str(this->c_node, path.c_str(), data.c_str());
  }

  void set_path(const std::string& path, const std::string data)
  {
    this->set_path_string(path, data);
  }

  void set_path_char8_str(const std::string& path, const char* data)
  {

    conduit_node_set_path_char8_str(this->c_node, path.c_str(), data);
  }

  void set_path_int8_vector(const std::string& path, const std::vector<conduit_int8>& data)
  {

    conduit_node_set_path_int8_ptr(
      this->c_node, path.c_str(), std::vector<conduit_int8>(data).data(), data.size());
  }

  void set_path(const std::string& path, const std::vector<conduit_int8>& data)
  {
    this->set_path_int8_vector(path, data);
  }

  void set_path_int16_vector(const std::string& path, const std::vector<conduit_int16>& data)
  {

    conduit_node_set_path_int16_ptr(
      this->c_node, path.c_str(), std::vector<conduit_int16>(data).data(), data.size());
  }

  void set_path(const std::string& path, const std::vector<conduit_int16>& data)
  {
    this->set_path_int16_vector(path, data);
  }

  void set_path_int32_vector(const std::string& path, const std::vector<conduit_int32>& data)
  {

    conduit_node_set_path_int32_ptr(
      this->c_node, path.c_str(), std::vector<conduit_int32>(data).data(), data.size());
  }

  void set_path(const std::string& path, const std::vector<conduit_int32>& data)
  {
    this->set_path_int32_vector(path, data);
  }

  void set_path_int64_vector(const std::string& path, const std::vector<conduit_int64>& data)
  {

    conduit_node_set_path_int64_ptr(
      this->c_node, path.c_str(), std::vector<conduit_int64>(data).data(), data.size());
  }

  void set_path(const std::string& path, const std::vector<conduit_int64>& data)
  {
    this->set_path_int64_vector(path, data);
  }

  void set_path_uint8_vector(const std::string& path, const std::vector<conduit_uint8>& data)
  {

    conduit_node_set_path_uint8_ptr(
      this->c_node, path.c_str(), std::vector<conduit_uint8>(data).data(), data.size());
  }

  void set_path(const std::string& path, const std::vector<conduit_uint8>& data)
  {
    this->set_path_uint8_vector(path, data);
  }

  void set_path_uint16_vector(const std::string& path, const std::vector<conduit_uint16>& data)
  {

    conduit_node_set_path_uint16_ptr(
      this->c_node, path.c_str(), std::vector<conduit_uint16>(data).data(), data.size());
  }

  void set_path(const std::string& path, const std::vector<conduit_uint16>& data)
  {
    this->set_path_uint16_vector(path, data);
  }

  void set_path_uint32_vector(const std::string& path, const std::vector<conduit_uint32>& data)
  {

    conduit_node_set_path_uint32_ptr(
      this->c_node, path.c_str(), std::vector<conduit_uint32>(data).data(), data.size());
  }

  void set_path(const std::string& path, const std::vector<conduit_uint32>& data)
  {
    this->set_path_uint32_vector(path, data);
  }

  void set_path_uint64_vector(const std::string& path, const std::vector<conduit_uint64>& data)
  {

    conduit_node_set_path_uint64_ptr(
      this->c_node, path.c_str(), std::vector<conduit_uint64>(data).data(), data.size());
  }

  void set_path(const std::string& path, const std::vector<conduit_uint64>& data)
  {
    this->set_path_uint64_vector(path, data);
  }

  void set_path_float32_vector(const std::string& path, const std::vector<conduit_float32>& data)
  {

    conduit_node_set_path_float32_ptr(
      this->c_node, path.c_str(), std::vector<conduit_float32>(data).data(), data.size());
  }

  void set_path(const std::string& path, const std::vector<conduit_float32>& data)
  {
    this->set_path_float32_vector(path, data);
  }

  void set_path_float64_vector(const std::string& path, const std::vector<conduit_float64>& data)
  {

    conduit_node_set_path_float64_ptr(
      this->c_node, path.c_str(), std::vector<conduit_float64>(data).data(), data.size());
  }

  void set_path(const std::string& path, const std::vector<conduit_float64>& data)
  {
    this->set_path_float64_vector(path, data);
  }

  void set_path(const std::string& path, const std::vector<char>& data)
  {

    conduit_node_set_path_char_ptr(
      this->c_node, path.c_str(), std::vector<char>(data).data(), data.size());
  }
#ifndef CONDUIT_USE_CHAR
  void set_path(const std::string& path, const std::vector<signed char>& data)
  {

    conduit_node_set_path_signed_char_ptr(
      this->c_node, path.c_str(), std::vector<signed char>(data).data(), data.size());
  }
  void set_path(const std::string& path, const std::vector<unsigned char>& data)
  {

    conduit_node_set_path_unsigned_char_ptr(
      this->c_node, path.c_str(), std::vector<unsigned char>(data).data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_SHORT
  void set_path(const std::string& path, const std::vector<short>& data)
  {

    conduit_node_set_path_short_ptr(
      this->c_node, path.c_str(), std::vector<short>(data).data(), data.size());
  }
  void set_path(const std::string& path, const std::vector<unsigned short>& data)
  {

    conduit_node_set_path_unsigned_short_ptr(
      this->c_node, path.c_str(), std::vector<unsigned short>(data).data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_INT
  void set_path(const std::string& path, const std::vector<int>& data)
  {

    conduit_node_set_path_int_ptr(
      this->c_node, path.c_str(), std::vector<int>(data).data(), data.size());
  }
  void set_path(const std::string& path, const std::vector<unsigned int>& data)
  {

    conduit_node_set_path_unsigned_int_ptr(
      this->c_node, path.c_str(), std::vector<unsigned int>(data).data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_LONG
  void set_path(const std::string& path, const std::vector<long>& data)
  {

    conduit_node_set_path_long_ptr(
      this->c_node, path.c_str(), std::vector<long>(data).data(), data.size());
  }
  void set_path(const std::string& path, const std::vector<unsigned long>& data)
  {

    conduit_node_set_path_unsigned_long_ptr(
      this->c_node, path.c_str(), std::vector<unsigned long>(data).data(), data.size());
  }
#endif
  void set_path_int8_ptr(const std::string& path, const conduit_int8* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int8),
    conduit_index_t element_bytes = sizeof(conduit_int8), conduit_index_t endianness = 0)
  {
    conduit_int8 data_cpy[num_elements];
    conduit_node_set_path_int8_ptr_detailed(this->c_node, path.c_str(),
      (conduit_int8*)memcpy(data_cpy, data, sizeof(conduit_int8) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set_path(const std::string& path, const conduit_int8* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int8),
    conduit_index_t element_bytes = sizeof(conduit_int8), conduit_index_t endianness = 0)
  {
    this->set_path_int8_ptr(path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_int16_ptr(const std::string& path, const conduit_int16* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int16),
    conduit_index_t element_bytes = sizeof(conduit_int16), conduit_index_t endianness = 0)
  {
    conduit_int16 data_cpy[num_elements];
    conduit_node_set_path_int16_ptr_detailed(this->c_node, path.c_str(),
      (conduit_int16*)memcpy(data_cpy, data, sizeof(conduit_int16) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set_path(const std::string& path, const conduit_int16* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int16),
    conduit_index_t element_bytes = sizeof(conduit_int16), conduit_index_t endianness = 0)
  {
    this->set_path_int16_ptr(path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_int32_ptr(const std::string& path, const conduit_int32* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int32),
    conduit_index_t element_bytes = sizeof(conduit_int32), conduit_index_t endianness = 0)
  {
    conduit_int32 data_cpy[num_elements];
    conduit_node_set_path_int32_ptr_detailed(this->c_node, path.c_str(),
      (conduit_int32*)memcpy(data_cpy, data, sizeof(conduit_int32) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set_path(const std::string& path, const conduit_int32* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int32),
    conduit_index_t element_bytes = sizeof(conduit_int32), conduit_index_t endianness = 0)
  {
    this->set_path_int32_ptr(path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_int64_ptr(const std::string& path, const conduit_int64* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int64),
    conduit_index_t element_bytes = sizeof(conduit_int64), conduit_index_t endianness = 0)
  {
    conduit_int64 data_cpy[num_elements];
    conduit_node_set_path_int64_ptr_detailed(this->c_node, path.c_str(),
      (conduit_int64*)memcpy(data_cpy, data, sizeof(conduit_int64) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set_path(const std::string& path, const conduit_int64* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int64),
    conduit_index_t element_bytes = sizeof(conduit_int64), conduit_index_t endianness = 0)
  {
    this->set_path_int64_ptr(path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_uint8_ptr(const std::string& path, const conduit_uint8* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint8),
    conduit_index_t element_bytes = sizeof(conduit_uint8), conduit_index_t endianness = 0)
  {
    conduit_uint8 data_cpy[num_elements];
    conduit_node_set_path_uint8_ptr_detailed(this->c_node, path.c_str(),
      (conduit_uint8*)memcpy(data_cpy, data, sizeof(conduit_uint8) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set_path(const std::string& path, const conduit_uint8* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint8),
    conduit_index_t element_bytes = sizeof(conduit_uint8), conduit_index_t endianness = 0)
  {
    this->set_path_uint8_ptr(path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_uint16_ptr(const std::string& path, const conduit_uint16* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint16),
    conduit_index_t element_bytes = sizeof(conduit_uint16), conduit_index_t endianness = 0)
  {
    conduit_uint16 data_cpy[num_elements];
    conduit_node_set_path_uint16_ptr_detailed(this->c_node, path.c_str(),
      (conduit_uint16*)memcpy(data_cpy, data, sizeof(conduit_uint16) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set_path(const std::string& path, const conduit_uint16* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint16),
    conduit_index_t element_bytes = sizeof(conduit_uint16), conduit_index_t endianness = 0)
  {
    this->set_path_uint16_ptr(path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_uint32_ptr(const std::string& path, const conduit_uint32* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint32),
    conduit_index_t element_bytes = sizeof(conduit_uint32), conduit_index_t endianness = 0)
  {
    conduit_uint32 data_cpy[num_elements];
    conduit_node_set_path_uint32_ptr_detailed(this->c_node, path.c_str(),
      (conduit_uint32*)memcpy(data_cpy, data, sizeof(conduit_uint32) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set_path(const std::string& path, const conduit_uint32* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint32),
    conduit_index_t element_bytes = sizeof(conduit_uint32), conduit_index_t endianness = 0)
  {
    this->set_path_uint32_ptr(path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_uint64_ptr(const std::string& path, const conduit_uint64* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint64),
    conduit_index_t element_bytes = sizeof(conduit_uint64), conduit_index_t endianness = 0)
  {
    conduit_uint64 data_cpy[num_elements];
    conduit_node_set_path_uint64_ptr_detailed(this->c_node, path.c_str(),
      (conduit_uint64*)memcpy(data_cpy, data, sizeof(conduit_uint64) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }

  void set_path(const std::string& path, const conduit_uint64* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint64),
    conduit_index_t element_bytes = sizeof(conduit_uint64), conduit_index_t endianness = 0)
  {
    this->set_path_uint64_ptr(path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_float32_ptr(const std::string& path, const conduit_float32* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_float32),
    conduit_index_t element_bytes = sizeof(conduit_float32), conduit_index_t endianness = 0)
  {
    conduit_float32 data_cpy[num_elements];
    conduit_node_set_path_float32_ptr_detailed(this->c_node, path.c_str(),
      (conduit_float32*)memcpy(data_cpy, data, sizeof(conduit_float32) * num_elements),
      num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path(const std::string& path, const conduit_float32* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_float32),
    conduit_index_t element_bytes = sizeof(conduit_float32), conduit_index_t endianness = 0)
  {
    this->set_path_float32_ptr(path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_float64_ptr(const std::string& path, const conduit_float64* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_float64),
    conduit_index_t element_bytes = sizeof(conduit_float64), conduit_index_t endianness = 0)
  {
    conduit_float64 data_cpy[num_elements];
    conduit_node_set_path_float64_ptr_detailed(this->c_node, path.c_str(),
      (conduit_float64*)memcpy(data_cpy, data, sizeof(conduit_float64) * num_elements),
      num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path(const std::string& path, const conduit_float64* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_float64),
    conduit_index_t element_bytes = sizeof(conduit_float64), conduit_index_t endianness = 0)
  {
    this->set_path_float64_ptr(path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_char_ptr(const std::string& path, const char* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_CHAR), conduit_index_t endianness = 0)
  {
    char data_cpy[num_elements];
    conduit_node_set_path_char_ptr_detailed(this->c_node, path.c_str(),
      (char*)memcpy(data_cpy, data, sizeof(char) * num_elements), num_elements, offset, stride,
      element_bytes, endianness);
  }
#ifndef CONDUIT_USE_CHAR
  void set_path(const std::string& path, const signed char* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_SIGNED_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_SIGNED_CHAR),
    conduit_index_t endianness = 0)
  {
    signed char data_cpy[num_elements];
    conduit_node_set_path_signed_char_ptr_detailed(this->c_node, path.c_str(),
      (signed char*)memcpy(data_cpy, data, sizeof(signed char) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }
  void set_path(const std::string& path, const unsigned char* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_CHAR),
    conduit_index_t endianness = 0)
  {
    unsigned char data_cpy[num_elements];
    conduit_node_set_path_unsigned_char_ptr_detailed(this->c_node, path.c_str(),
      (unsigned char*)memcpy(data_cpy, data, sizeof(unsigned char) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_SHORT
  void set_path(const std::string& path, const short* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_SHORT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_SHORT), conduit_index_t endianness = 0)
  {
    short data_cpy[num_elements];
    conduit_node_set_path_short_ptr_detailed(this->c_node, path.c_str(),
      (short*)memcpy(data_cpy, data, sizeof(short) * num_elements), num_elements, offset, stride,
      element_bytes, endianness);
  }
  void set_path(const std::string& path, const unsigned short* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_SHORT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_SHORT),
    conduit_index_t endianness = 0)
  {
    unsigned short data_cpy[num_elements];
    conduit_node_set_path_unsigned_short_ptr_detailed(this->c_node, path.c_str(),
      (unsigned short*)memcpy(data_cpy, data, sizeof(unsigned short) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_INT
  void set_path(const std::string& path, const int* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_INT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_INT), conduit_index_t endianness = 0)
  {
    int data_cpy[num_elements];
    conduit_node_set_path_int_ptr_detailed(this->c_node, path.c_str(),
      (int*)memcpy(data_cpy, data, sizeof(int) * num_elements), num_elements, offset, stride,
      element_bytes, endianness);
  }
  void set_path(const std::string& path, const unsigned int* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_INT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_INT),
    conduit_index_t endianness = 0)
  {
    unsigned int data_cpy[num_elements];
    conduit_node_set_path_unsigned_int_ptr_detailed(this->c_node, path.c_str(),
      (unsigned int*)memcpy(data_cpy, data, sizeof(unsigned int) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_LONG
  void set_path(const std::string& path, const long* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_LONG),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_LONG), conduit_index_t endianness = 0)
  {
    long data_cpy[num_elements];
    conduit_node_set_path_long_ptr_detailed(this->c_node, path.c_str(),
      (long*)memcpy(data_cpy, data, sizeof(long) * num_elements), num_elements, offset, stride,
      element_bytes, endianness);
  }
  void set_path(const std::string& path, const unsigned long* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
    conduit_index_t endianness = 0)
  {
    unsigned long data_cpy[num_elements];
    conduit_node_set_path_unsigned_long_ptr_detailed(this->c_node, path.c_str(),
      (unsigned long*)memcpy(data_cpy, data, sizeof(unsigned long) * num_elements), num_elements,
      offset, stride, element_bytes, endianness);
  }
#endif

  void set_external_char8_str(char* data)
  {

    conduit_node_set_external_char8_str(this->c_node, data);
  }

  void set_external_int8_vector(std::vector<conduit_int8>& data)
  {

    conduit_node_set_external_int8_ptr(this->c_node, data.data(), data.size());
  }

  void set_external(std::vector<conduit_int8>& data) { this->set_external_int8_vector(data); }

  void set_external_int16_vector(std::vector<conduit_int16>& data)
  {

    conduit_node_set_external_int16_ptr(this->c_node, data.data(), data.size());
  }

  void set_external(std::vector<conduit_int16>& data) { this->set_external_int16_vector(data); }

  void set_external_int32_vector(std::vector<conduit_int32>& data)
  {

    conduit_node_set_external_int32_ptr(this->c_node, data.data(), data.size());
  }

  void set_external(std::vector<conduit_int32>& data) { this->set_external_int32_vector(data); }

  void set_external_int64_vector(std::vector<conduit_int64>& data)
  {

    conduit_node_set_external_int64_ptr(this->c_node, data.data(), data.size());
  }

  void set_external(std::vector<conduit_int64>& data) { this->set_external_int64_vector(data); }

  void set_external_uint8_vector(std::vector<conduit_uint8>& data)
  {

    conduit_node_set_external_uint8_ptr(this->c_node, data.data(), data.size());
  }

  void set_external(std::vector<conduit_uint8>& data) { this->set_external_uint8_vector(data); }

  void set_external_uint16_vector(std::vector<conduit_uint16>& data)
  {

    conduit_node_set_external_uint16_ptr(this->c_node, data.data(), data.size());
  }

  void set_external(std::vector<conduit_uint16>& data) { this->set_external_uint16_vector(data); }

  void set_external_uint32_vector(std::vector<conduit_uint32>& data)
  {

    conduit_node_set_external_uint32_ptr(this->c_node, data.data(), data.size());
  }

  void set_external(std::vector<conduit_uint32>& data) { this->set_external_uint32_vector(data); }

  void set_external_uint64_vector(std::vector<conduit_uint64>& data)
  {

    conduit_node_set_external_uint64_ptr(this->c_node, data.data(), data.size());
  }

  void set_external(std::vector<conduit_uint64>& data) { this->set_external_uint64_vector(data); }

  void set_external_float32_vector(std::vector<conduit_float32>& data)
  {

    conduit_node_set_external_float32_ptr(this->c_node, data.data(), data.size());
  }

  void set_external(std::vector<conduit_float32>& data) { this->set_external_float32_vector(data); }

  void set_external_float64_vector(std::vector<conduit_float64>& data)
  {

    conduit_node_set_external_float64_ptr(this->c_node, data.data(), data.size());
  }

  void set_external(std::vector<conduit_float64>& data) { this->set_external_float64_vector(data); }

  void set_external(std::vector<char>& data)
  {

    conduit_node_set_external_char_ptr(this->c_node, data.data(), data.size());
  }
#ifndef CONDUIT_USE_CHAR
  void set_external(std::vector<signed char>& data)
  {

    conduit_node_set_external_signed_char_ptr(this->c_node, data.data(), data.size());
  }
  void set_external(std::vector<unsigned char>& data)
  {

    conduit_node_set_external_unsigned_char_ptr(this->c_node, data.data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_SHORT
  void set_external(std::vector<short>& data)
  {

    conduit_node_set_external_short_ptr(this->c_node, data.data(), data.size());
  }
  void set_external(std::vector<unsigned short>& data)
  {

    conduit_node_set_external_unsigned_short_ptr(this->c_node, data.data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_INT
  void set_external(std::vector<int>& data)
  {

    conduit_node_set_external_int_ptr(this->c_node, data.data(), data.size());
  }
  void set_external(std::vector<unsigned int>& data)
  {

    conduit_node_set_external_unsigned_int_ptr(this->c_node, data.data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_LONG
  void set_external(std::vector<long>& data)
  {

    conduit_node_set_external_long_ptr(this->c_node, data.data(), data.size());
  }
  void set_external(std::vector<unsigned long>& data)
  {

    conduit_node_set_external_unsigned_long_ptr(this->c_node, data.data(), data.size());
  }
#endif

  void set_external_node(const Node& n) { conduit_node_set_external_node(this->c_node, n.c_node); }
  void set_external(const Node& n) { this->set_external_node(n); }

  void set_external_int8_ptr(conduit_int8* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int8),
    conduit_index_t element_bytes = sizeof(conduit_int8), conduit_index_t endianness = 0)
  {

    conduit_node_set_external_int8_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external(conduit_int8* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int8),
    conduit_index_t element_bytes = sizeof(conduit_int8), conduit_index_t endianness = 0)
  {
    this->set_external_int8_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external_int16_ptr(conduit_int16* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int16),
    conduit_index_t element_bytes = sizeof(conduit_int16), conduit_index_t endianness = 0)
  {

    conduit_node_set_external_int16_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external(conduit_int16* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int16),
    conduit_index_t element_bytes = sizeof(conduit_int16), conduit_index_t endianness = 0)
  {
    this->set_external_int16_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external_int32_ptr(conduit_int32* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int32),
    conduit_index_t element_bytes = sizeof(conduit_int32), conduit_index_t endianness = 0)
  {

    conduit_node_set_external_int32_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external(conduit_int32* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int32),
    conduit_index_t element_bytes = sizeof(conduit_int32), conduit_index_t endianness = 0)
  {
    this->set_external_int32_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external_int64_ptr(conduit_int64* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int64),
    conduit_index_t element_bytes = sizeof(conduit_int64), conduit_index_t endianness = 0)
  {

    conduit_node_set_external_int64_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external(conduit_int64* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int64),
    conduit_index_t element_bytes = sizeof(conduit_int64), conduit_index_t endianness = 0)
  {
    this->set_external_int64_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external_uint8_ptr(conduit_uint8* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint8),
    conduit_index_t element_bytes = sizeof(conduit_uint8), conduit_index_t endianness = 0)
  {

    conduit_node_set_external_uint8_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external(conduit_uint8* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint8),
    conduit_index_t element_bytes = sizeof(conduit_uint8), conduit_index_t endianness = 0)
  {
    this->set_external_uint8_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external_uint16_ptr(conduit_uint16* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint16),
    conduit_index_t element_bytes = sizeof(conduit_uint16), conduit_index_t endianness = 0)
  {

    conduit_node_set_external_uint16_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external(conduit_uint16* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint16),
    conduit_index_t element_bytes = sizeof(conduit_uint16), conduit_index_t endianness = 0)
  {
    this->set_external_uint16_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external_uint32_ptr(conduit_uint32* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint32),
    conduit_index_t element_bytes = sizeof(conduit_uint32), conduit_index_t endianness = 0)
  {

    conduit_node_set_external_uint32_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external(conduit_uint32* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint32),
    conduit_index_t element_bytes = sizeof(conduit_uint32), conduit_index_t endianness = 0)
  {
    this->set_external_uint32_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external_uint64_ptr(conduit_uint64* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint64),
    conduit_index_t element_bytes = sizeof(conduit_uint64), conduit_index_t endianness = 0)
  {

    conduit_node_set_external_uint64_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external(conduit_uint64* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint64),
    conduit_index_t element_bytes = sizeof(conduit_uint64), conduit_index_t endianness = 0)
  {
    this->set_external_uint64_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external_float32_ptr(conduit_float32* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_float32),
    conduit_index_t element_bytes = sizeof(conduit_float32), conduit_index_t endianness = 0)
  {

    conduit_node_set_external_float32_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external(conduit_float32* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_float32),
    conduit_index_t element_bytes = sizeof(conduit_float32), conduit_index_t endianness = 0)
  {
    this->set_external_float32_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external_float64_ptr(conduit_float64* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_float64),
    conduit_index_t element_bytes = sizeof(conduit_float64), conduit_index_t endianness = 0)
  {

    conduit_node_set_external_float64_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external(conduit_float64* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_float64),
    conduit_index_t element_bytes = sizeof(conduit_float64), conduit_index_t endianness = 0)
  {
    this->set_external_float64_ptr(data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_external_char_ptr(char* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_CHAR), conduit_index_t endianness = 0)
  {

    conduit_node_set_external_char_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }
#ifndef CONDUIT_USE_CHAR
  void set_external(signed char* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_SIGNED_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_SIGNED_CHAR),
    conduit_index_t endianness = 0)
  {

    conduit_node_set_external_signed_char_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }
  void set_external(unsigned char* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_CHAR),
    conduit_index_t endianness = 0)
  {

    conduit_node_set_external_unsigned_char_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_SHORT
  void set_external(short* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_SHORT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_SHORT), conduit_index_t endianness = 0)
  {

    conduit_node_set_external_short_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }
  void set_external(unsigned short* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_SHORT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_SHORT),
    conduit_index_t endianness = 0)
  {

    conduit_node_set_external_unsigned_short_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_INT
  void set_external(int* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_INT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_INT), conduit_index_t endianness = 0)
  {

    conduit_node_set_external_int_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }
  void set_external(unsigned int* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_INT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_INT),
    conduit_index_t endianness = 0)
  {

    conduit_node_set_external_unsigned_int_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_LONG
  void set_external(long* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_LONG),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_LONG), conduit_index_t endianness = 0)
  {

    conduit_node_set_external_long_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }
  void set_external(unsigned long* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
    conduit_index_t endianness = 0)
  {

    conduit_node_set_external_unsigned_long_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }
#endif

  void set_path_external_int8_vector(const std::string& path, std::vector<conduit_int8>& data)
  {

    conduit_node_set_path_external_int8_ptr(this->c_node, path.c_str(), data.data(), data.size());
  }

  void set_path_external(const std::string& path, std::vector<conduit_int8>& data)
  {
    this->set_path_external_int8_vector(path, data);
  }

  void set_path_external_int16_vector(const std::string& path, std::vector<conduit_int16>& data)
  {

    conduit_node_set_path_external_int16_ptr(this->c_node, path.c_str(), data.data(), data.size());
  }

  void set_path_external(const std::string& path, std::vector<conduit_int16>& data)
  {
    this->set_path_external_int16_vector(path, data);
  }

  void set_path_external_int32_vector(const std::string& path, std::vector<conduit_int32>& data)
  {

    conduit_node_set_path_external_int32_ptr(this->c_node, path.c_str(), data.data(), data.size());
  }

  void set_path_external(const std::string& path, std::vector<conduit_int32>& data)
  {
    this->set_path_external_int32_vector(path, data);
  }

  void set_path_external_int64_vector(const std::string& path, std::vector<conduit_int64>& data)
  {

    conduit_node_set_path_external_int64_ptr(this->c_node, path.c_str(), data.data(), data.size());
  }

  void set_path_external(const std::string& path, std::vector<conduit_int64>& data)
  {
    this->set_path_external_int64_vector(path, data);
  }

  void set_path_external_uint8_vector(const std::string& path, std::vector<conduit_uint8>& data)
  {

    conduit_node_set_path_external_uint8_ptr(this->c_node, path.c_str(), data.data(), data.size());
  }

  void set_path_external(const std::string& path, std::vector<conduit_uint8>& data)
  {
    this->set_path_external_uint8_vector(path, data);
  }

  void set_path_external_uint16_vector(const std::string& path, std::vector<conduit_uint16>& data)
  {

    conduit_node_set_path_external_uint16_ptr(this->c_node, path.c_str(), data.data(), data.size());
  }

  void set_path_external(const std::string& path, std::vector<conduit_uint16>& data)
  {
    this->set_path_external_uint16_vector(path, data);
  }

  void set_path_external_uint32_vector(const std::string& path, std::vector<conduit_uint32>& data)
  {

    conduit_node_set_path_external_uint32_ptr(this->c_node, path.c_str(), data.data(), data.size());
  }

  void set_path_external(const std::string& path, std::vector<conduit_uint32>& data)
  {
    this->set_path_external_uint32_vector(path, data);
  }

  void set_path_external_uint64_vector(const std::string& path, std::vector<conduit_uint64>& data)
  {

    conduit_node_set_path_external_uint64_ptr(this->c_node, path.c_str(), data.data(), data.size());
  }

  void set_path_external(const std::string& path, std::vector<conduit_uint64>& data)
  {
    this->set_path_external_uint64_vector(path, data);
  }

  void set_path_external_float32_vector(const std::string& path, std::vector<conduit_float32>& data)
  {

    conduit_node_set_path_external_float32_ptr(
      this->c_node, path.c_str(), data.data(), data.size());
  }

  void set_path_external(const std::string& path, std::vector<conduit_float32>& data)
  {
    this->set_path_external_float32_vector(path, data);
  }

  void set_path_external_float64_vector(const std::string& path, std::vector<conduit_float64>& data)
  {

    conduit_node_set_path_external_float64_ptr(
      this->c_node, path.c_str(), data.data(), data.size());
  }

  void set_path_external(const std::string& path, std::vector<conduit_float64>& data)
  {
    this->set_path_external_float64_vector(path, data);
  }

  void set_path_external(const std::string& path, std::vector<char>& data)
  {

    conduit_node_set_path_external_char_ptr(this->c_node, path.c_str(), data.data(), data.size());
  }
#ifndef CONDUIT_USE_CHAR
  void set_path_external(const std::string& path, std::vector<signed char>& data)
  {

    conduit_node_set_path_external_signed_char_ptr(
      this->c_node, path.c_str(), data.data(), data.size());
  }
  void set_path_external(const std::string& path, std::vector<unsigned char>& data)
  {

    conduit_node_set_path_external_unsigned_char_ptr(
      this->c_node, path.c_str(), data.data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_SHORT
  void set_path_external(const std::string& path, std::vector<short>& data)
  {

    conduit_node_set_path_external_short_ptr(this->c_node, path.c_str(), data.data(), data.size());
  }
  void set_path_external(const std::string& path, std::vector<unsigned short>& data)
  {

    conduit_node_set_path_external_unsigned_short_ptr(
      this->c_node, path.c_str(), data.data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_INT
  void set_path_external(const std::string& path, std::vector<int>& data)
  {

    conduit_node_set_path_external_int_ptr(this->c_node, path.c_str(), data.data(), data.size());
  }
  void set_path_external(const std::string& path, std::vector<unsigned int>& data)
  {

    conduit_node_set_path_external_unsigned_int_ptr(
      this->c_node, path.c_str(), data.data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_LONG
  void set_path_external(const std::string& path, std::vector<long>& data)
  {

    conduit_node_set_path_external_long_ptr(this->c_node, path.c_str(), data.data(), data.size());
  }
  void set_path_external(const std::string& path, std::vector<unsigned long>& data)
  {

    conduit_node_set_path_external_unsigned_long_ptr(
      this->c_node, path.c_str(), data.data(), data.size());
  }
#endif

  void set_path_external_node(const std::string& path, Node& node)
  {
    conduit_node_set_path_external_node(this->c_node, path.c_str(), node.c_node);
  }

  void set_path_external(const std::string& path, Node& node)
  {
    this->set_path_external_node(path, node);
  }

  void set_path_external_int8_ptr(const std::string& path, conduit_int8* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int8),
    conduit_index_t element_bytes = sizeof(conduit_int8), conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_int8_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external(const std::string& path, conduit_int8* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int8),
    conduit_index_t element_bytes = sizeof(conduit_int8), conduit_index_t endianness = 0)
  {
    this->set_path_external_int8_ptr(
      path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external_int16_ptr(const std::string& path, conduit_int16* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int16),
    conduit_index_t element_bytes = sizeof(conduit_int16), conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_int16_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external(const std::string& path, conduit_int16* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int16),
    conduit_index_t element_bytes = sizeof(conduit_int16), conduit_index_t endianness = 0)
  {
    this->set_path_external_int16_ptr(
      path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external_int32_ptr(const std::string& path, conduit_int32* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int32),
    conduit_index_t element_bytes = sizeof(conduit_int32), conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_int32_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external(const std::string& path, conduit_int32* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int32),
    conduit_index_t element_bytes = sizeof(conduit_int32), conduit_index_t endianness = 0)
  {
    this->set_path_external_int32_ptr(
      path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external_int64_ptr(const std::string& path, conduit_int64* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int64),
    conduit_index_t element_bytes = sizeof(conduit_int64), conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_int64_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external(const std::string& path, conduit_int64* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int64),
    conduit_index_t element_bytes = sizeof(conduit_int64), conduit_index_t endianness = 0)
  {
    this->set_path_external_int64_ptr(
      path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external_uint8_ptr(const std::string& path, conduit_uint8* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint8),
    conduit_index_t element_bytes = sizeof(conduit_uint8), conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_uint8_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external(const std::string& path, conduit_uint8* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint8),
    conduit_index_t element_bytes = sizeof(conduit_uint8), conduit_index_t endianness = 0)
  {
    this->set_path_external_uint8_ptr(
      path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external_uint16_ptr(const std::string& path, conduit_uint16* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint16),
    conduit_index_t element_bytes = sizeof(conduit_uint16), conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_uint16_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external(const std::string& path, conduit_uint16* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint16),
    conduit_index_t element_bytes = sizeof(conduit_uint16), conduit_index_t endianness = 0)
  {
    this->set_path_external_uint16_ptr(
      path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external_uint32_ptr(const std::string& path, conduit_uint32* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint32),
    conduit_index_t element_bytes = sizeof(conduit_uint32), conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_uint32_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external(const std::string& path, conduit_uint32* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint32),
    conduit_index_t element_bytes = sizeof(conduit_uint32), conduit_index_t endianness = 0)
  {
    this->set_path_external_uint32_ptr(
      path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external_uint64_ptr(const std::string& path, conduit_uint64* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint64),
    conduit_index_t element_bytes = sizeof(conduit_uint64), conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_uint64_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external(const std::string& path, conduit_uint64* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_uint64),
    conduit_index_t element_bytes = sizeof(conduit_uint64), conduit_index_t endianness = 0)
  {
    this->set_path_external_uint64_ptr(
      path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external_float32_ptr(const std::string& path, conduit_float32* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_float32),
    conduit_index_t element_bytes = sizeof(conduit_float32), conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_float32_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external(const std::string& path, conduit_float32* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_float32),
    conduit_index_t element_bytes = sizeof(conduit_float32), conduit_index_t endianness = 0)
  {
    this->set_path_external_float32_ptr(
      path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external_float64_ptr(const std::string& path, conduit_float64* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_float64),
    conduit_index_t element_bytes = sizeof(conduit_float64), conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_float64_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external(const std::string& path, conduit_float64* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_float64),
    conduit_index_t element_bytes = sizeof(conduit_float64), conduit_index_t endianness = 0)
  {
    this->set_path_external_float64_ptr(
      path, data, num_elements, offset, stride, element_bytes, endianness);
  }

  void set_path_external_char_ptr(const std::string& path, char* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_CHAR), conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_char_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }
#ifndef CONDUIT_USE_CHAR
  void set_path_external(const std::string& path, signed char* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_SIGNED_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_SIGNED_CHAR),
    conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_signed_char_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }
  void set_path_external(const std::string& path, unsigned char* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_CHAR),
    conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_unsigned_char_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_SHORT
  void set_path_external(const std::string& path, short* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_SHORT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_SHORT), conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_short_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }
  void set_path_external(const std::string& path, unsigned short* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_SHORT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_SHORT),
    conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_unsigned_short_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_INT
  void set_path_external(const std::string& path, int* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_INT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_INT), conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_int_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }
  void set_path_external(const std::string& path, unsigned int* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_INT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_INT),
    conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_unsigned_int_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_LONG
  void set_path_external(const std::string& path, long* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_LONG),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_LONG), conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_long_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }
  void set_path_external(const std::string& path, unsigned long* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
    conduit_index_t endianness = 0)
  {

    conduit_node_set_path_external_unsigned_long_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }
#endif

  //-----------------------------------------------------------------------------
  ///@}
  //-----------------------------------------------------------------------------
  //
  // -- end setters --
  //
  //-----------------------------------------------------------------------------

  //-----------------------------------------------------------------------------
  // -- copy and move assignment operator for Node --
  //-----------------------------------------------------------------------------
  Node& operator=(const Node& other)
  {
    set(other);
    return *this;
  }

  Node& operator=(Node&& other)
  {
    this->c_node = other.c_node;
    other.c_node = nullptr;
    return *this;
  }
  //-----------------------------------------------------------------------------
  // --  assignment operators for scalar types ---
  //-----------------------------------------------------------------------------

  //-----------------------------------------------------------------------------
  // signed integer scalar types
  //-----------------------------------------------------------------------------

  //---------------------------------------------------------------------------//
  Node& operator=(conduit_int8 data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(conduit_int16 data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(conduit_int32 data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(conduit_int64 data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  // unsigned integer scalar types
  //-----------------------------------------------------------------------------

  //---------------------------------------------------------------------------//
  Node& operator=(conduit_uint8 data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(conduit_uint16 data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(conduit_uint32 data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(conduit_uint64 data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  // floating point scalar types
  //-----------------------------------------------------------------------------

  //---------------------------------------------------------------------------//
  Node& operator=(conduit_float32 data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(conduit_float64 data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  // assignment operator gap methods for scalar c-native types
  //-----------------------------------------------------------------------------
  //-----------------------------------------------------------------------------
  Node& operator=(char data)
  {
    set(data);
    return *this;
  }

//-----------------------------------------------------------------------------
#ifndef CONDUIT_USE_CHAR
  //-----------------------------------------------------------------------------
  Node& operator=(signed char data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  Node& operator=(unsigned char data)
  {
    set(data);
    return *this;
  }

//-----------------------------------------------------------------------------
#endif // end use char check
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#ifndef CONDUIT_USE_SHORT
  //-----------------------------------------------------------------------------
  Node& operator=(short data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  Node& operator=(unsigned short data)
  {
    set(data);
    return *this;
  }
//-----------------------------------------------------------------------------
#endif // end use short check
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#ifndef CONDUIT_USE_INT
  //-----------------------------------------------------------------------------
  Node& operator=(int data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  Node& operator=(unsigned int data)
  {
    set(data);
    return *this;
  }
//-----------------------------------------------------------------------------
#endif // end use int check
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#ifndef CONDUIT_USE_LONG
  //-----------------------------------------------------------------------------
  Node& operator=(long data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  Node& operator=(unsigned long data)
  {
    set(data);
    return *this;
  }
//-----------------------------------------------------------------------------
#endif // end use long check
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#ifndef CONDUIT_USE_FLOAT
  //-----------------------------------------------------------------------------
  Node& operator=(float data)
  {
    set(data);
    return *this;
  }
//-----------------------------------------------------------------------------
#endif // end use float check
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#ifndef CONDUIT_USE_DOUBLE
  //-----------------------------------------------------------------------------
  Node& operator=(double data)
  {
    set(data);
    return *this;
  }
//-----------------------------------------------------------------------------
#endif // end use double check
       //-----------------------------------------------------------------------------

  //-----------------------------------------------------------------------------
  // -- assignment operators for string types --
  //-----------------------------------------------------------------------------

  //---------------------------------------------------------------------------//
  Node& operator=(const std::string& data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(const char* data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  // -- assignment operators for std::vector types ---
  //-----------------------------------------------------------------------------
  //-----------------------------------------------------------------------------
  // signed integer array types via std::vector
  //-----------------------------------------------------------------------------

  //---------------------------------------------------------------------------//
  Node& operator=(const std::vector<conduit_int8>& data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(const std::vector<conduit_int16>& data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(const std::vector<conduit_int32>& data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(const std::vector<conduit_int64>& data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  // unsigned integer array types via std::vector
  //-----------------------------------------------------------------------------

  //---------------------------------------------------------------------------//
  Node& operator=(const std::vector<conduit_uint8>& data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(const std::vector<conduit_uint16>& data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(const std::vector<conduit_uint32>& data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(const std::vector<conduit_uint64>& data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  // floating point array types via std::vector
  //-----------------------------------------------------------------------------

  //---------------------------------------------------------------------------//
  Node& operator=(const std::vector<conduit_float32>& data)
  {
    set(data);
    return *this;
  }

  //---------------------------------------------------------------------------//
  Node& operator=(const std::vector<conduit_float64>& data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  // assignment operator gap methods for vector c-native types
  //-----------------------------------------------------------------------------

  //-----------------------------------------------------------------------------
  Node& operator=(const std::vector<char>& data)
  {
    set(data);
    return *this;
  }

//-----------------------------------------------------------------------------
#ifndef CONDUIT_USE_CHAR
  //-----------------------------------------------------------------------------
  Node& operator=(const std::vector<signed char>& data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  Node& operator=(const std::vector<unsigned char>& data)
  {
    set(data);
    return *this;
  }
//-----------------------------------------------------------------------------
#endif // end use char check
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#ifndef CONDUIT_USE_SHORT
  //-----------------------------------------------------------------------------
  Node& operator=(const std::vector<short>& data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  Node& operator=(const std::vector<unsigned short>& data)
  {
    set(data);
    return *this;
  }    //-----------------------------------------------------------------------------
#endif // end use short check
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#ifndef CONDUIT_USE_INT
  //-----------------------------------------------------------------------------
  Node& operator=(const std::vector<int>& data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  Node& operator=(const std::vector<unsigned int>& data)
  {
    set(data);
    return *this;
  }
//-----------------------------------------------------------------------------
#endif // end use int check
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#ifndef CONDUIT_USE_LONG
  //-----------------------------------------------------------------------------
  Node& operator=(const std::vector<long>& data)
  {
    set(data);
    return *this;
  }

  //-----------------------------------------------------------------------------
  Node& operator=(const std::vector<unsigned long>& data)
  {
    set(data);
    return *this;
  }
//-----------------------------------------------------------------------------
#endif // end use long check
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#ifndef CONDUIT_USE_FLOAT
  //-----------------------------------------------------------------------------
  Node& operator=(const std::vector<float>& data)
  {
    set(data);
    return *this;
  }
//-----------------------------------------------------------------------------
#endif // end use float check
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#ifndef CONDUIT_USE_DOUBLE
  //-----------------------------------------------------------------------------
  Node& operator=(const std::vector<double>& data)
  {
    set(data);
    return *this;
  }
//-----------------------------------------------------------------------------
#endif // end use double check
       //-----------------------------------------------------------------------------

  //-----------------------------------------------------------------------------
  //
  // -- end definition of Node assignment operators --
  //
  //-----------------------------------------------------------------------------

  //-----------------------------------------------------------------------------
  // -- leaf coercion methods ---
  //-----------------------------------------------------------------------------
  ///
  /// These methods allow you to coerce a leaf type to another type.
  ///

  /// scalar coercion

  /// convert to a signed integer types
  conduit_int8 to_int8() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (conduit_int8)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (conduit_int8)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (conduit_int8)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (conduit_int8)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (conduit_int8)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (conduit_int8)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (conduit_int8)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (conduit_int8)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (conduit_int8)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      conduit_int16 res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return (conduit_int8)res;
    }
    return 0;
  }

  conduit_int16 to_int16() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (conduit_int16)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (conduit_int16)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (conduit_int16)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (conduit_int16)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (conduit_int16)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (conduit_int16)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (conduit_int16)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (conduit_int16)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (conduit_int16)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      conduit_int16 res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  conduit_int32 to_int32() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (conduit_int32)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (conduit_int32)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (conduit_int32)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (conduit_int32)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (conduit_int32)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (conduit_int32)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (conduit_int32)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (conduit_int32)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (conduit_int32)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      conduit_int32 res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  conduit_int64 to_int64() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (conduit_int64)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (conduit_int64)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (conduit_int64)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (conduit_int64)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (conduit_int64)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (conduit_int64)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (conduit_int64)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (conduit_int64)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (conduit_int64)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      conduit_int64 res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  /// convert to a unsigned integer types
  conduit_uint8 to_uint8() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (conduit_uint8)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (conduit_uint8)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (conduit_uint8)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (conduit_uint8)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (conduit_uint8)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (conduit_uint8)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (conduit_uint8)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (conduit_uint8)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (conduit_uint8)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      conduit_uint16 res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return (conduit_uint8)res;
    }
    return 0;
  }

  conduit_uint16 to_uint16() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (conduit_uint16)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (conduit_uint16)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (conduit_uint16)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (conduit_uint16)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (conduit_uint16)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (conduit_uint16)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (conduit_uint16)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (conduit_uint16)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (conduit_uint16)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      conduit_uint16 res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  conduit_uint32 to_uint32() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (conduit_uint32)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (conduit_uint32)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (conduit_uint32)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (conduit_uint32)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (conduit_uint32)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (conduit_uint32)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (conduit_uint32)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (conduit_uint32)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (conduit_uint32)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      conduit_uint32 res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  conduit_uint64 to_uint64() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (conduit_uint64)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (conduit_uint64)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (conduit_uint64)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (conduit_uint64)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (conduit_uint64)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (conduit_uint64)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (conduit_uint64)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (conduit_uint64)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (conduit_uint64)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      conduit_uint64 res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  /// convert to a floating point type
  conduit_float32 to_float32() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (conduit_float32)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (conduit_float32)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (conduit_float32)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (conduit_float32)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (conduit_float32)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (conduit_float32)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (conduit_float32)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (conduit_float32)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (conduit_float32)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      conduit_float32 res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  conduit_float64 to_float64() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (conduit_float64)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (conduit_float64)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (conduit_float64)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (conduit_float64)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (conduit_float64)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (conduit_float64)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (conduit_float64)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (conduit_float64)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (conduit_float64)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (conduit_float64)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      conduit_float64 res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  conduit_index_t to_index_t() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (conduit_index_t)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (conduit_index_t)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (conduit_index_t)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (conduit_index_t)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (conduit_index_t)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (conduit_index_t)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (conduit_index_t)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (conduit_index_t)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (conduit_index_t)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (conduit_index_t)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      conduit_index_t res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  /// convert to c integer types
  char to_char() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (char)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (char)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (char)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (char)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (char)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (char)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (char)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (char)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (char)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (char)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      conduit_int16 res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return (char)res;
    }
    return 0;
  }

  short to_short() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (short)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (short)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (short)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (short)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (short)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (short)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (short)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (short)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (short)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (short)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      short res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  int to_int() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (int)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (int)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (int)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (int)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (int)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (int)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (int)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (int)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (int)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (int)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      int res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  long to_long() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (long)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (long)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (long)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (long)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (long)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (long)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (long)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (long)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (long)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (long)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      long res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  /// convert to c signed integer types
  signed char to_signed_char() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (signed char)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (signed char)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (signed char)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (signed char)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (signed char)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (signed char)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (signed char)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (signed char)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (signed char)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (signed char)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      conduit_int16 res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return (signed char)res;
    }
    return 0;
  }

  signed short to_signed_short() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (signed short)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (signed short)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (signed short)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (signed short)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (signed short)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (signed short)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (signed short)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (signed short)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (signed short)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (signed short)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      signed short res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  signed int to_signed_int() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (signed int)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (signed int)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (signed int)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (signed int)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (signed int)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (signed int)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (signed int)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (signed int)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (signed int)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (signed int)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      signed int res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  signed long to_signed_long() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (signed long)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (signed long)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (signed long)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (signed long)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (signed long)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (signed long)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (signed long)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (signed long)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (signed long)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (signed long)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      signed long res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  /// convert to c unsigned integer types
  unsigned char to_unsigned_char() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (unsigned char)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (unsigned char)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (unsigned char)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (unsigned char)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (unsigned char)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (unsigned char)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (unsigned char)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (unsigned char)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (unsigned char)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (unsigned char)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      conduit_uint16 res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return (unsigned char)res;
    }
    return 0;
  }
  unsigned short to_unsigned_short() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (unsigned short)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (unsigned short)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (unsigned short)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (unsigned short)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (unsigned short)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (unsigned short)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (unsigned short)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (unsigned short)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (unsigned short)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (unsigned short)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      unsigned short res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }
  unsigned int to_unsigned_int() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (unsigned int)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (unsigned int)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (unsigned int)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (unsigned int)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (unsigned int)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (unsigned int)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (unsigned int)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (unsigned int)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (unsigned int)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (unsigned int)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      unsigned int res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }
  unsigned long to_unsigned_long() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (unsigned long)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (unsigned long)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (unsigned long)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (unsigned long)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (unsigned long)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (unsigned long)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (unsigned long)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (unsigned long)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (unsigned long)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (unsigned long)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      unsigned long res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  /// convert to c floating point types
  float to_float() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (float)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (float)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (float)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (float)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (float)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (float)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (float)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (float)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (float)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (float)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      float res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  double to_double() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (catalyst_conduit_datatype_is_int8(data))
    {
      return (double)as_int8();
    }
    if (catalyst_conduit_datatype_is_int16(data))
    {
      return (double)as_int16();
    }
    if (catalyst_conduit_datatype_is_int32(data))
    {
      return (double)as_int32();
    }
    if (catalyst_conduit_datatype_is_int64(data))
    {
      return (double)as_int64();
    }
    /* conduit_uints */
    if (catalyst_conduit_datatype_is_uint8(data))
    {
      return (double)as_uint8();
    }
    if (catalyst_conduit_datatype_is_uint16(data))
    {
      return (double)as_uint16();
    }
    if (catalyst_conduit_datatype_is_uint32(data))
    {
      return (double)as_uint32();
    }
    if (catalyst_conduit_datatype_is_uint64(data))
    {
      return (double)as_uint64();
    }
    /* floats */
    if (catalyst_conduit_datatype_is_float32(data))
    {
      return (double)as_float32();
    }
    if (catalyst_conduit_datatype_is_float64(data))
    {
      return (double)as_float64();
    }
    // string case
    if (catalyst_conduit_datatype_is_char8_str(data))
    {
      double res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return res;
    }
    return 0;
  }

  //-----------------------------------------------------------------------------
  //
  // -- begin declaration of Node information methods --
  //
  //-----------------------------------------------------------------------------
  //-----------------------------------------------------------------------------
  ///@name Node Information
  ///@{
  //-----------------------------------------------------------------------------
  /// description:
  ///  These methods provide general info about the node.
  //-----------------------------------------------------------------------------

  const conduit_datatype* c_dtype() { return conduit_node_dtype(this->c_node); }

  //-------------------------------------------------------------------------
  /// contiguous checks
  //-------------------------------------------------------------------------

  /// Does this node has a contiguous data layout?
  bool is_contiguous() const { return conduit_node_is_contiguous(this->c_node); }

  /// true if node hierarchy's memory contiguously follows
  /// the given node's memory
  bool contiguous_with(const Node& n) const
  {
    return conduit_node_contiguous_with_node(this->c_node, n.c_node);
  }

  /// true if node hierarchy's memory contiguously follows
  /// the given address. Note: contiguous with NULL is false.
  bool contiguous_with(void* address) const
  {
    return conduit_node_contiguous_with_address(this->c_node, address);
  }

  /// is this node compatible with given node
  bool compatible(const Node& n) const { return conduit_node_compatible(this->c_node, n.c_node); }

  /// check for differences between this node and the given node, storing
  //  the results digest in the provided data node
  bool diff(const Node& n, Node& info, const conduit_float64 epsilon) const
  {
    return conduit_node_diff(this->c_node, n.c_node, info.c_node, epsilon);
  }

  /// diff this node to the given node for compatibility (i.e. validate it
  //  has everything that the instance node has), storing the results
  //  digest in the provided data node
  bool diff_compatible(const Node& n, Node& info, const conduit_float64 epsilon) const
  {
    return conduit_node_diff_compatible(this->c_node, n.c_node, info.c_node, epsilon);
  }

  ///
  /// info() creates a node that contains metadata about the current
  /// node's memory properties
  void info(Node& nres) const { conduit_node_info(this->c_node, nres.c_node); }

  Node info() const
  {
    Node ret;
    this->info(ret);
    return ret;
  }

  //-----------------------------------------------------------------------------
  // -- stdout print methods ---
  //-----------------------------------------------------------------------------
  /// print a simplified json representation of the this node to std out
  void print() const { conduit_node_print(this->c_node); }

  /// print a detailed json representation of the this node to std out.
  /// json output includes conduit schema constructs
  void print_detailed() const { conduit_node_print_detailed(this->c_node); }

  //-----------------------------------------------------------------------------
  ///@}
  //-----------------------------------------------------------------------------
  //
  // -- end declaration of Node information methods --
  //
  //-----------------------------------------------------------------------------

  //-----------------------------------------------------------------------------
  //
  // -- begin declaration of Node entry access methods --
  //
  //-----------------------------------------------------------------------------
  //-----------------------------------------------------------------------------
  ///@name Node Entry Access Methods
  ///@{
  //-----------------------------------------------------------------------------
  /// description:
  ///  child access (for list or object types)
  //-----------------------------------------------------------------------------

  /// fetch the node at the given index
  Node child(conduit_index_t idx) { return Node(conduit_node_child(this->c_node, idx)); }

  const Node child(conduit_index_t idx) const
  {
    return Node(conduit_node_child(this->c_node, idx));
  }

  /// access child node via a path (equivalent to fetch via path)
  Node operator[](const std::string& path)
  {
    return Node(conduit_node_fetch(this->c_node, path.c_str()));
  }

  // Don't modify underlying structure if path doesn't exist
  const Node operator[](const std::string& path) const
  {
    if (this->has_path(path))
    {
      return Node(conduit_node_fetch(this->c_node, path.c_str()));
    }
    return Node(nullptr); // TODO: Throwing an exception more appropriate?
  }

  /// access child node via index (equivalent to fetch via index)
  Node operator[](conduit_index_t idx) { return child(idx); }
  const Node operator[](conduit_index_t idx) const { return child(idx); }

  /// returns the number of children (list and object interfaces)
  conduit_index_t number_of_children() const
  {
    return conduit_node_number_of_children(this->c_node);
  }

  // conduit_node_name uses strdup, which allocates memory
  // on the heap. Must free the result here after copying.
  std::string name() const
  {
    char* name = conduit_node_name(this->c_node);
    std::string ret(name);
    free(name);

    return ret;
  }

  // conduit_node_path uses strdup, which allocates memory
  // on the heap. Must free the result here after copying.
  std::string path() const
  {
    char* path = conduit_node_path(this->c_node);
    std::string ret(path);
    free(path);

    // Return copy and implicitly copy to an std::string
    return ret;
  }

  /// checks if a node has a direct child with given name
  bool has_child(const std::string& name) const
  {
    return conduit_node_has_child(this->c_node, name.c_str());
  }
  /// checks if given path exists in the Node hierarchy
  bool has_path(const std::string& path) const
  {
    return conduit_node_has_path(this->c_node, path.c_str());
  }

  Node append() { return Node(conduit_node_append(this->c_node)); }

  /// remove child at index (list and object interfaces)
  void remove(conduit_index_t idx) { conduit_node_remove_child(this->c_node, idx); }
  /// remove child at given path (object interface)
  void remove(const std::string& path) { conduit_node_remove_path(this->c_node, path.c_str()); }
  /// rename a child (object interface)
  void rename_child(const std::string& current_name, const std::string& new_name)
  {
    conduit_node_rename_child(this->c_node, current_name.c_str(), new_name.c_str());
  }

  //-----------------------------------------------------------------------------
  ///@}
  //-----------------------------------------------------------------------------
  //
  // -- end declaration of Node entry access methods --
  //
  //-----------------------------------------------------------------------------

  //-----------------------------------------------------------------------------
  //
  // -- begin declaration of Node value access methods --
  //
  //-----------------------------------------------------------------------------
  //-----------------------------------------------------------------------------
  ///@name Node Value Access Methods
  ///@{
  //-----------------------------------------------------------------------------
  /// description:
  ///  Direct access to data at leaf types.
  //-----------------------------------------------------------------------------

  // signed integer scalars
  conduit_int8 as_int8() const { return conduit_node_as_int8(this->c_node); }
  conduit_int16 as_int16() const { return conduit_node_as_int16(this->c_node); }
  conduit_int32 as_int32() const { return conduit_node_as_int32(this->c_node); }
  conduit_int64 as_int64() const { return conduit_node_as_int64(this->c_node); }

  // unsigned integer scalars
  conduit_uint8 as_uint8() const { return conduit_node_as_uint8(this->c_node); }
  conduit_uint16 as_uint16() const { return conduit_node_as_uint16(this->c_node); }
  conduit_uint32 as_uint32() const { return conduit_node_as_uint32(this->c_node); }
  conduit_uint64 as_uint64() const { return conduit_node_as_uint64(this->c_node); }

  // floating point scalars
  conduit_float32 as_float32() const { return conduit_node_as_float32(this->c_node); }
  conduit_float64 as_float64() const { return conduit_node_as_float64(this->c_node); }

  // signed integers via pointers
  conduit_int8* as_int8_ptr() { return conduit_node_as_int8_ptr(this->c_node); }
  conduit_int16* as_int16_ptr() { return conduit_node_as_int16_ptr(this->c_node); }
  conduit_int32* as_int32_ptr() { return conduit_node_as_int32_ptr(this->c_node); }
  conduit_int64* as_int64_ptr() { return conduit_node_as_int64_ptr(this->c_node); }

  // unsigned integers via pointers
  conduit_uint8* as_uint8_ptr() { return conduit_node_as_uint8_ptr(this->c_node); }
  conduit_uint16* as_uint16_ptr() { return conduit_node_as_uint16_ptr(this->c_node); }
  conduit_uint32* as_uint32_ptr() { return conduit_node_as_uint32_ptr(this->c_node); }
  conduit_uint64* as_uint64_ptr() { return conduit_node_as_uint64_ptr(this->c_node); }

  // floating point via pointers
  conduit_float32* as_float32_ptr() { return conduit_node_as_float32_ptr(this->c_node); }
  conduit_float64* as_float64_ptr() { return conduit_node_as_float64_ptr(this->c_node); }

  // signed integers via pointers
  const conduit_int8* as_int8_ptr() const { return conduit_node_as_int8_ptr(this->c_node); }
  const conduit_int16* as_int16_ptr() const { return conduit_node_as_int16_ptr(this->c_node); }
  const conduit_int32* as_int32_ptr() const { return conduit_node_as_int32_ptr(this->c_node); }
  const conduit_int64* as_int64_ptr() const { return conduit_node_as_int64_ptr(this->c_node); }

  // unsigned integers via pointers
  const conduit_uint8* as_uint8_ptr() const { return conduit_node_as_uint8_ptr(this->c_node); }
  const conduit_uint16* as_uint16_ptr() const { return conduit_node_as_uint16_ptr(this->c_node); }
  const conduit_uint32* as_uint32_ptr() const { return conduit_node_as_uint32_ptr(this->c_node); }
  const conduit_uint64* as_uint64_ptr() const { return conduit_node_as_uint64_ptr(this->c_node); }

  // floating point via pointers
  const conduit_float32* as_float32_ptr() const
  {
    return conduit_node_as_float32_ptr(this->c_node);
  }
  const conduit_float64* as_float64_ptr() const
  {
    return conduit_node_as_float64_ptr(this->c_node);
  }

  // char8_str cases
  char* as_char8_str() { return conduit_node_as_char8_str(this->c_node); }
  const char* as_char8_str() const { return conduit_node_as_char8_str(this->c_node); }
  std::string as_string() const { return std::string(conduit_node_as_char8_str(this->c_node)); }

  // direct data pointer access
  void* data_ptr() { return conduit_node_data_ptr(this->c_node); }
  const void* data_ptr() const { return conduit_node_data_ptr(this->c_node); }

  void* element_ptr(conduit_index_t idx) { return conduit_node_element_ptr(this->c_node, idx); }
  const void* element_ptr(conduit_index_t idx) const
  {
    return conduit_node_element_ptr(this->c_node, idx);
  }

  //-----------------------------------------------------------------------------
  /// description:
  ///  Direct access to data at leaf types (native c++ types)
  //-----------------------------------------------------------------------------`

  // c style scalar
  char as_char() const { return conduit_node_as_char(this->c_node); }
  short as_short() const { return conduit_node_as_short(this->c_node); }
  int as_int() const { return conduit_node_as_int(this->c_node); }
  long as_long() const { return conduit_node_as_long(this->c_node); }

  // signed integer scalars
  signed char as_signed_char() const { return conduit_node_as_signed_char(this->c_node); }
  signed short as_signed_short() const { return conduit_node_as_signed_short(this->c_node); }
  signed int as_signed_int() const { return conduit_node_as_signed_int(this->c_node); }
  signed long as_signed_long() const { return conduit_node_as_signed_long(this->c_node); }

  // unsigned integer scalars
  unsigned char as_unsigned_char() const { return conduit_node_as_unsigned_char(this->c_node); }
  unsigned short as_unsigned_short() const { return conduit_node_as_unsigned_short(this->c_node); }
  unsigned int as_unsigned_int() const { return conduit_node_as_unsigned_int(this->c_node); }
  unsigned long as_unsigned_long() const { return conduit_node_as_unsigned_long(this->c_node); }

  // floating point scalars
  float as_float() const { return conduit_node_as_float(this->c_node); }
  double as_double() const { return conduit_node_as_double(this->c_node); }

  // c style via pointer
  char* as_char_ptr() { return conduit_node_as_char_ptr(this->c_node); }
  short* as_short_ptr() { return conduit_node_as_short_ptr(this->c_node); }
  int* as_int_ptr() { return conduit_node_as_int_ptr(this->c_node); }
  long* as_long_ptr() { return conduit_node_as_long_ptr(this->c_node); }

  // signed integers via pointers
  signed char* as_signed_char_ptr() { return conduit_node_as_signed_char_ptr(this->c_node); }
  signed short* as_signed_short_ptr() { return conduit_node_as_signed_short_ptr(this->c_node); }
  signed int* as_signed_int_ptr() { return conduit_node_as_signed_int_ptr(this->c_node); }
  signed long* as_signed_long_ptr() { return conduit_node_as_signed_long_ptr(this->c_node); }

  // unsigned integers via pointers
  unsigned char* as_unsigned_char_ptr() { return conduit_node_as_unsigned_char_ptr(this->c_node); }
  unsigned short* as_unsigned_short_ptr()
  {
    return conduit_node_as_unsigned_short_ptr(this->c_node);
  }
  unsigned int* as_unsigned_int_ptr() { return conduit_node_as_unsigned_int_ptr(this->c_node); }
  unsigned long* as_unsigned_long_ptr() { return conduit_node_as_unsigned_long_ptr(this->c_node); }

  // floating point via pointers
  float* as_float_ptr() { return conduit_node_as_float_ptr(this->c_node); }
  double* as_double_ptr() { return conduit_node_as_double_ptr(this->c_node); }

  // char via pointer (const variant)
  const char* as_char_ptr() const { return conduit_node_as_char_ptr(this->c_node); }
  const short* as_short_ptr() const { return conduit_node_as_short_ptr(this->c_node); }
  const int* as_int_ptr() const { return conduit_node_as_int_ptr(this->c_node); }
  const long* as_long_ptr() const { return conduit_node_as_long_ptr(this->c_node); }

  // signed integers via pointers (const variants)
  const signed char* as_signed_char_ptr() const
  {
    return conduit_node_as_signed_char_ptr(this->c_node);
  }
  const signed short* as_signed_short_ptr() const
  {
    return conduit_node_as_signed_short_ptr(this->c_node);
  }
  const signed int* as_signed_int_ptr() const
  {
    return conduit_node_as_signed_int_ptr(this->c_node);
  }
  const signed long* as_signed_long_ptr() const
  {
    return conduit_node_as_signed_long_ptr(this->c_node);
  }

  // unsigned integers via pointers (const variants)
  const unsigned char* as_unsigned_char_ptr() const
  {
    return conduit_node_as_unsigned_char_ptr(this->c_node);
  }
  const unsigned short* as_unsigned_short_ptr() const
  {
    return conduit_node_as_unsigned_short_ptr(this->c_node);
  }
  const unsigned int* as_unsigned_int_ptr() const
  {
    return conduit_node_as_unsigned_int_ptr(this->c_node);
  }
  const unsigned long* as_unsigned_long_ptr() const
  {
    return conduit_node_as_unsigned_long_ptr(this->c_node);
  }

  // floating point via pointers (const variants)
  const float* as_float_ptr() const { return conduit_node_as_float_ptr(this->c_node); }

  const double* as_double_ptr() const { return conduit_node_as_double_ptr(this->c_node); }

private:
  Node(conduit_node* other)
    : c_node(other)
  {
  }
};

conduit_node* c_node(Node* n)
{
  return n ? n->c_node : nullptr;
}
}
#endif
