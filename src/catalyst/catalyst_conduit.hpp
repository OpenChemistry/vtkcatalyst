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

#include <catalyst_conduit_error.hpp>
#include <conduit.h>

namespace conduit_cpp
{

#define CATALYST_CONDUIT_ERROR(msg) throw Error(msg, std::string(__FILE__), __LINE__);

#define CATALYST_CONDUIT_WRAP_EXCEP(throwing_code)                                                 \
  try                                                                                              \
  {                                                                                                \
    throwing_code;                                                                                 \
  }                                                                                                \
  catch (...)                                                                                      \
  {                                                                                                \
    CATALYST_CONDUIT_ERROR("An error occurred at:")                                                \
  }

class Node;

class DataType
{
public:
  ~DataType() = default;

  enum class Id
  {
    int8,
    int16,
    int32,
    int64,

    uint8,
    uint16,
    uint32,
    uint64,

    float32,
    float64,

    unknown,
  };

  friend class Node;

  bool is_valid() const { return this->c_dtype != nullptr; }

  Id id() const
  {
    if (this->is_valid())
    {
      return Id::unknown;
    }

    if (this->is_int8())
    {
      return Id::int8;
    }
    if (this->is_int16())
    {
      return Id::int16;
    }
    if (this->is_int32())
    {
      return Id::int32;
    }
    if (this->is_int64())
    {
      return Id::int64;
    }

    if (this->is_uint8())
    {
      return Id::uint8;
    }
    if (this->is_uint16())
    {
      return Id::uint16;
    }
    if (this->is_uint32())
    {
      return Id::uint32;
    }
    if (this->is_uint64())
    {
      return Id::uint64;
    }

    if (this->is_float32())
    {
      return Id::float32;
    }
    if (this->is_float64())
    {
      return Id::float64;
    }

    return Id::unknown;
  }

  bool is_empty() const { return conduit_datatype_is_empty(this->c_dtype); }
  bool is_object() const { return conduit_datatype_is_object(this->c_dtype); }
  bool is_list() const { return conduit_datatype_is_list(this->c_dtype); }

  bool is_number() const { return conduit_datatype_is_number(this->c_dtype); }
  bool is_floating_point() const { return conduit_datatype_is_floating_point(this->c_dtype); }
  bool is_integer() const { return conduit_datatype_is_integer(this->c_dtype); }
  bool is_signed_integer() const { return conduit_datatype_is_signed_integer(this->c_dtype); }
  bool is_unsigned_integer() const { return conduit_datatype_is_unsigned_integer(this->c_dtype); }

  bool is_int8() const { return conduit_datatype_is_int8(this->c_dtype); }
  bool is_int16() const { return conduit_datatype_is_int16(this->c_dtype); }
  bool is_int32() const { return conduit_datatype_is_int32(this->c_dtype); }
  bool is_int64() const { return conduit_datatype_is_int64(this->c_dtype); }

  bool is_uint8() const { return conduit_datatype_is_uint8(this->c_dtype); }
  bool is_uint16() const { return conduit_datatype_is_uint16(this->c_dtype); }
  bool is_uint32() const { return conduit_datatype_is_uint32(this->c_dtype); }
  bool is_uint64() const { return conduit_datatype_is_uint64(this->c_dtype); }

  bool is_float32() const { return conduit_datatype_is_float32(this->c_dtype); }
  bool is_float64() const { return conduit_datatype_is_float64(this->c_dtype); }

  bool is_char() const { return conduit_datatype_is_char(this->c_dtype); }
  bool is_short() const { return conduit_datatype_is_short(this->c_dtype); }
  bool is_int() const { return conduit_datatype_is_int(this->c_dtype); }
  bool is_long() const { return conduit_datatype_is_long(this->c_dtype); }

  bool is_unsigned_char() const { return conduit_datatype_is_unsigned_char(this->c_dtype); }
  bool is_unsigned_short() const { return conduit_datatype_is_unsigned_short(this->c_dtype); }
  bool is_unsigned_int() const { return conduit_datatype_is_unsigned_int(this->c_dtype); }
  bool is_unsigned_long() const { return conduit_datatype_is_unsigned_long(this->c_dtype); }

  bool is_float() const { return conduit_datatype_is_float(this->c_dtype); }
  bool is_double() const { return conduit_datatype_is_double(this->c_dtype); }

  bool is_string() const { return conduit_datatype_is_string(this->c_dtype); }
  bool is_char8_str() const { return conduit_datatype_is_char8_str(this->c_dtype); }

  bool is_little_endian() const { return conduit_datatype_is_little_endian(this->c_dtype); }
  bool is_big_endian() const { return conduit_datatype_is_big_endian(this->c_dtype); }
  bool endianness_matches_machine() const
  {
    return conduit_datatype_endianness_matches_machine(this->c_dtype);
  }

private:
  DataType(const conduit_datatype* dtype)
    : c_dtype(dtype)
  {
  }

  const conduit_datatype* c_dtype;
};

class Node
{
public:
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

  friend conduit_node* c_node(const Node* n);
  friend Node cpp_node(conduit_node* n);

  /////////////////////////////////////////////////////////////////////////////
  // The above code will need to be copy and pasted between revisions.
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  // The following code was generated by src/catalyst/utilities/generate_setters.py.
  // The output of the above script is not formatted. It is recommended
  // to format the output using an automatic formatting tool,
  // like clang-format.
  /////////////////////////////////////////////////////////////////////////////

  void set_node(const Node& data) { conduit_node_set_node(this->c_node, data.c_node); }

  void set(const Node& data) { this->set_node(data); }

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
#ifndef CONDUIT_USE_FLOAT
  void set(const float data) { conduit_node_set_float(this->c_node, data); }
#endif
#ifndef CONDUIT_USE_DOUBLE
  void set(const double data) { conduit_node_set_double(this->c_node, data); }
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
#ifndef CONDUIT_USE_FLOAT
  void set(const std::vector<float>& data)
  {
    conduit_node_set_float_ptr(this->c_node, std::vector<float>(data).data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_DOUBLE
  void set(const std::vector<double>& data)
  {
    conduit_node_set_double_ptr(this->c_node, std::vector<double>(data).data(), data.size());
  }
#endif
  void set_int8_ptr(const conduit_int8* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int8),
    conduit_index_t element_bytes = sizeof(conduit_int8), conduit_index_t endianness = 0)
  {
    conduit_node_set_int8_ptr_detailed(this->c_node, const_cast<conduit_int8*>(data), num_elements,
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
    conduit_node_set_int16_ptr_detailed(this->c_node, const_cast<conduit_int16*>(data),
      num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_int32_ptr_detailed(this->c_node, const_cast<conduit_int32*>(data),
      num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_int64_ptr_detailed(this->c_node, const_cast<conduit_int64*>(data),
      num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_uint8_ptr_detailed(this->c_node, const_cast<conduit_uint8*>(data),
      num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_uint16_ptr_detailed(this->c_node, const_cast<conduit_uint16*>(data),
      num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_uint32_ptr_detailed(this->c_node, const_cast<conduit_uint32*>(data),
      num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_uint64_ptr_detailed(this->c_node, const_cast<conduit_uint64*>(data),
      num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_float32_ptr_detailed(this->c_node, const_cast<conduit_float32*>(data),
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
    conduit_node_set_float64_ptr_detailed(this->c_node, const_cast<conduit_float64*>(data),
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
    conduit_node_set_char_ptr_detailed(this->c_node, const_cast<char*>(data), num_elements, offset,
      stride, element_bytes, endianness);
  }
#ifndef CONDUIT_USE_CHAR
  void set(const signed char* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_SIGNED_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_SIGNED_CHAR),
    conduit_index_t endianness = 0)
  {
    conduit_node_set_signed_char_ptr_detailed(this->c_node, const_cast<signed char*>(data),
      num_elements, offset, stride, element_bytes, endianness);
  }
  void set(const unsigned char* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_CHAR),
    conduit_index_t endianness = 0)
  {
    conduit_node_set_unsigned_char_ptr_detailed(this->c_node, const_cast<unsigned char*>(data),
      num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_SHORT
  void set(const short* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_SHORT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_SHORT), conduit_index_t endianness = 0)
  {
    conduit_node_set_short_ptr_detailed(this->c_node, const_cast<short*>(data), num_elements,
      offset, stride, element_bytes, endianness);
  }
  void set(const unsigned short* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_SHORT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_SHORT),
    conduit_index_t endianness = 0)
  {
    conduit_node_set_unsigned_short_ptr_detailed(this->c_node, const_cast<unsigned short*>(data),
      num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_INT
  void set(const int* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_INT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_INT), conduit_index_t endianness = 0)
  {
    conduit_node_set_int_ptr_detailed(this->c_node, const_cast<int*>(data), num_elements, offset,
      stride, element_bytes, endianness);
  }
  void set(const unsigned int* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_INT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_INT),
    conduit_index_t endianness = 0)
  {
    conduit_node_set_unsigned_int_ptr_detailed(this->c_node, const_cast<unsigned int*>(data),
      num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_LONG
  void set(const long* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_LONG),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_LONG), conduit_index_t endianness = 0)
  {
    conduit_node_set_long_ptr_detailed(this->c_node, const_cast<long*>(data), num_elements, offset,
      stride, element_bytes, endianness);
  }
  void set(const unsigned long* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
    conduit_index_t endianness = 0)
  {
    conduit_node_set_unsigned_long_ptr_detailed(this->c_node, const_cast<unsigned long*>(data),
      num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_FLOAT
  void set(const float* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_FLOAT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_FLOAT), conduit_index_t endianness = 0)
  {
    conduit_node_set_float_ptr_detailed(this->c_node, const_cast<float*>(data), num_elements,
      offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_DOUBLE
  void set(const double* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_DOUBLE),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_DOUBLE), conduit_index_t endianness = 0)
  {
    conduit_node_set_double_ptr_detailed(this->c_node, const_cast<double*>(data), num_elements,
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
#ifndef CONDUIT_USE_FLOAT
  void set_path(const std::string& path, const float data)
  {
    conduit_node_set_path_float(this->c_node, path.c_str(), data);
  }
#endif
#ifndef CONDUIT_USE_DOUBLE
  void set_path(const std::string& path, const double data)
  {
    conduit_node_set_path_double(this->c_node, path.c_str(), data);
  }
#endif
  void set_path_string(const std::string& path, const std::string& data)
  {
    conduit_node_set_path_char8_str(this->c_node, path.c_str(), data.c_str());
  }

  void set_path(const std::string& path, const std::string& data)
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
#ifndef CONDUIT_USE_FLOAT
  void set_path(const std::string& path, const std::vector<float>& data)
  {
    conduit_node_set_path_float_ptr(
      this->c_node, path.c_str(), std::vector<float>(data).data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_DOUBLE
  void set_path(const std::string& path, const std::vector<double>& data)
  {
    conduit_node_set_path_double_ptr(
      this->c_node, path.c_str(), std::vector<double>(data).data(), data.size());
  }
#endif
  void set_path_int8_ptr(const std::string& path, const conduit_int8* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(conduit_int8),
    conduit_index_t element_bytes = sizeof(conduit_int8), conduit_index_t endianness = 0)
  {
    conduit_node_set_path_int8_ptr_detailed(this->c_node, path.c_str(),
      const_cast<conduit_int8*>(data), num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_path_int16_ptr_detailed(this->c_node, path.c_str(),
      const_cast<conduit_int16*>(data), num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_path_int32_ptr_detailed(this->c_node, path.c_str(),
      const_cast<conduit_int32*>(data), num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_path_int64_ptr_detailed(this->c_node, path.c_str(),
      const_cast<conduit_int64*>(data), num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_path_uint8_ptr_detailed(this->c_node, path.c_str(),
      const_cast<conduit_uint8*>(data), num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_path_uint16_ptr_detailed(this->c_node, path.c_str(),
      const_cast<conduit_uint16*>(data), num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_path_uint32_ptr_detailed(this->c_node, path.c_str(),
      const_cast<conduit_uint32*>(data), num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_path_uint64_ptr_detailed(this->c_node, path.c_str(),
      const_cast<conduit_uint64*>(data), num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_path_float32_ptr_detailed(this->c_node, path.c_str(),
      const_cast<conduit_float32*>(data), num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_path_float64_ptr_detailed(this->c_node, path.c_str(),
      const_cast<conduit_float64*>(data), num_elements, offset, stride, element_bytes, endianness);
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
    conduit_node_set_path_char_ptr_detailed(this->c_node, path.c_str(), const_cast<char*>(data),
      num_elements, offset, stride, element_bytes, endianness);
  }
#ifndef CONDUIT_USE_CHAR
  void set_path(const std::string& path, const signed char* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_SIGNED_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_SIGNED_CHAR),
    conduit_index_t endianness = 0)
  {
    conduit_node_set_path_signed_char_ptr_detailed(this->c_node, path.c_str(),
      const_cast<signed char*>(data), num_elements, offset, stride, element_bytes, endianness);
  }
  void set_path(const std::string& path, const unsigned char* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_CHAR),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_CHAR),
    conduit_index_t endianness = 0)
  {
    conduit_node_set_path_unsigned_char_ptr_detailed(this->c_node, path.c_str(),
      const_cast<unsigned char*>(data), num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_SHORT
  void set_path(const std::string& path, const short* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_SHORT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_SHORT), conduit_index_t endianness = 0)
  {
    conduit_node_set_path_short_ptr_detailed(this->c_node, path.c_str(), const_cast<short*>(data),
      num_elements, offset, stride, element_bytes, endianness);
  }
  void set_path(const std::string& path, const unsigned short* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_SHORT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_SHORT),
    conduit_index_t endianness = 0)
  {
    conduit_node_set_path_unsigned_short_ptr_detailed(this->c_node, path.c_str(),
      const_cast<unsigned short*>(data), num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_INT
  void set_path(const std::string& path, const int* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_INT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_INT), conduit_index_t endianness = 0)
  {
    conduit_node_set_path_int_ptr_detailed(this->c_node, path.c_str(), const_cast<int*>(data),
      num_elements, offset, stride, element_bytes, endianness);
  }
  void set_path(const std::string& path, const unsigned int* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_INT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_INT),
    conduit_index_t endianness = 0)
  {
    conduit_node_set_path_unsigned_int_ptr_detailed(this->c_node, path.c_str(),
      const_cast<unsigned int*>(data), num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_LONG
  void set_path(const std::string& path, const long* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_LONG),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_LONG), conduit_index_t endianness = 0)
  {
    conduit_node_set_path_long_ptr_detailed(this->c_node, path.c_str(), const_cast<long*>(data),
      num_elements, offset, stride, element_bytes, endianness);
  }
  void set_path(const std::string& path, const unsigned long* data,
    conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
    conduit_index_t endianness = 0)
  {
    conduit_node_set_path_unsigned_long_ptr_detailed(this->c_node, path.c_str(),
      const_cast<unsigned long*>(data), num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_FLOAT
  void set_path(const std::string& path, const float* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_FLOAT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_FLOAT), conduit_index_t endianness = 0)
  {
    conduit_node_set_path_float_ptr_detailed(this->c_node, path.c_str(), const_cast<float*>(data),
      num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_DOUBLE
  void set_path(const std::string& path, const double* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_DOUBLE),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_DOUBLE), conduit_index_t endianness = 0)
  {
    conduit_node_set_path_double_ptr_detailed(this->c_node, path.c_str(), const_cast<double*>(data),
      num_elements, offset, stride, element_bytes, endianness);
  }
#endif
  void set_external_node(Node& data) { conduit_node_set_external_node(this->c_node, data.c_node); }

  void set_external(Node& data) { this->set_external_node(data); }

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
#ifndef CONDUIT_USE_FLOAT
  void set_external(std::vector<float>& data)
  {
    conduit_node_set_external_float_ptr(this->c_node, data.data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_DOUBLE
  void set_external(std::vector<double>& data)
  {
    conduit_node_set_external_double_ptr(this->c_node, data.data(), data.size());
  }
#endif
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
#ifndef CONDUIT_USE_FLOAT
  void set_external(float* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_FLOAT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_FLOAT), conduit_index_t endianness = 0)
  {
    conduit_node_set_external_float_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_DOUBLE
  void set_external(double* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
    conduit_index_t stride = sizeof(CONDUIT_NATIVE_DOUBLE),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_DOUBLE), conduit_index_t endianness = 0)
  {
    conduit_node_set_external_double_ptr_detailed(
      this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
  }
#endif
  void set_path_external_node(const std::string& path, Node& data)
  {
    conduit_node_set_path_external_node(this->c_node, path.c_str(), data.c_node);
  }

  void set_path_external(const std::string& path, Node& data)
  {
    this->set_path_external_node(path, data);
  }

  void set_path_external_char8_str(const std::string& path, char* data)
  {
    conduit_node_set_path_external_char8_str(this->c_node, path.c_str(), data);
  }

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
#ifndef CONDUIT_USE_FLOAT
  void set_path_external(const std::string& path, std::vector<float>& data)
  {
    conduit_node_set_path_external_float_ptr(this->c_node, path.c_str(), data.data(), data.size());
  }
#endif
#ifndef CONDUIT_USE_DOUBLE
  void set_path_external(const std::string& path, std::vector<double>& data)
  {
    conduit_node_set_path_external_double_ptr(this->c_node, path.c_str(), data.data(), data.size());
  }
#endif
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
#ifndef CONDUIT_USE_FLOAT
  void set_path_external(const std::string& path, float* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_FLOAT),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_FLOAT), conduit_index_t endianness = 0)
  {
    conduit_node_set_path_external_float_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }
#endif
#ifndef CONDUIT_USE_DOUBLE
  void set_path_external(const std::string& path, double* data, conduit_index_t num_elements = 1,
    conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_DOUBLE),
    conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_DOUBLE), conduit_index_t endianness = 0)
  {
    conduit_node_set_path_external_double_ptr_detailed(
      this->c_node, path.c_str(), data, num_elements, offset, stride, element_bytes, endianness);
  }
#endif
  /////////////////////////////////////////////////////////////////////////////
  // End generated section.
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  // The following code will need to be copy and pasted between revisions.
  /////////////////////////////////////////////////////////////////////////////

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
  conduit_int8 to_int8() const { return this->to_type<conduit_int8, conduit_int16>(); }

  conduit_int16 to_int16() const { return this->to_type<conduit_int16>(); }

  conduit_int32 to_int32() const { return this->to_type<conduit_int32>(); }

  conduit_int64 to_int64() const { return this->to_type<conduit_int64>(); }

  /// convert to a unsigned integer types
  conduit_uint8 to_uint8() const { return this->to_type<conduit_uint8, conduit_uint16>(); }

  conduit_uint16 to_uint16() const { return this->to_type<conduit_uint16>(); }

  conduit_uint32 to_uint32() const { return this->to_type<conduit_uint32>(); }

  conduit_uint64 to_uint64() const { return this->to_type<conduit_uint64>(); }

  /// convert to a floating point type
  conduit_float32 to_float32() const { return this->to_type<conduit_float32>(); }

  conduit_float64 to_float64() const { return this->to_type<conduit_float64>(); }

  conduit_index_t to_index_t() const { return this->to_type<conduit_index_t>(); }

  /// convert to c integer types
  char to_char() const { return this->to_type<char, conduit_int16>(); }

  short to_short() const { return this->to_type<short>(); }

  int to_int() const { return this->to_type<int>(); }

  long to_long() const { return this->to_type<long>(); }

  /// convert to c signed integer types
  signed char to_signed_char() const { return this->to_type<signed char, conduit_int16>(); }

  signed short to_signed_short() const { return this->to_type<signed short>(); }

  signed int to_signed_int() const { return this->to_type<signed int>(); }

  signed long to_signed_long() const { return this->to_type<signed long>(); }

  /// convert to c unsigned integer types
  unsigned char to_unsigned_char() const { return this->to_type<unsigned char, conduit_uint16>(); }
  unsigned short to_unsigned_short() const { return this->to_type<unsigned short>(); }
  unsigned int to_unsigned_int() const { return this->to_type<unsigned int>(); }
  unsigned long to_unsigned_long() const { return this->to_type<unsigned long>(); }

  /// convert to c floating point types
  float to_float() const { return this->to_type<float>(); }

  double to_double() const { return this->to_type<double>(); }

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

  DataType dtype() const { return DataType(this->c_dtype()); }
  const conduit_datatype* c_dtype() const { return conduit_node_dtype(this->c_node); }

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
    CATALYST_CONDUIT_WRAP_EXCEP(
      return conduit_node_diff(this->c_node, n.c_node, info.c_node, epsilon));
  }

  /// diff this node to the given node for compatibility (i.e. validate it
  //  has everything that the instance node has), storing the results
  //  digest in the provided data node
  bool diff_compatible(const Node& n, Node& info, const conduit_float64 epsilon) const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(
      return conduit_node_diff_compatible(this->c_node, n.c_node, info.c_node, epsilon));
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
  Node child(conduit_index_t idx)
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return Node(conduit_node_child(this->c_node, idx)));
  }

  const Node child(conduit_index_t idx) const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return Node(conduit_node_child(this->c_node, idx)));
  }

  /// access child node via a path (equivalent to fetch via path)
  Node operator[](const std::string& path)
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return Node(conduit_node_fetch(this->c_node, path.c_str())));
  }

  // Don't modify underlying structure if path doesn't exist
  const Node operator[](const std::string& path) const
  {
    if (this->has_path(path))
    {
      CATALYST_CONDUIT_WRAP_EXCEP(return Node(conduit_node_fetch(this->c_node, path.c_str())));
    }
    CATALYST_CONDUIT_ERROR("Error fetching path " + path);
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
    if (!name)
    {
      CATALYST_CONDUIT_ERROR("Error retrieving name from C API.")
    }
    std::string ret(name);
    free(name);

    return ret;
  }

  // conduit_node_path uses strdup, which allocates memory
  // on the heap. Must free the result here after copying.
  std::string path() const
  {
    char* path = conduit_node_path(this->c_node);
    if (!path)
    {
      CATALYST_CONDUIT_ERROR("Error retrieving path from C API.")
    }
    std::string ret(path);
    free(path);

    // Return copy
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
  void remove(conduit_index_t idx)
  {
    CATALYST_CONDUIT_WRAP_EXCEP(conduit_node_remove_child(this->c_node, idx));
  }

  /// remove child at given path (object interface)
  void remove(const std::string& path)
  {
    CATALYST_CONDUIT_WRAP_EXCEP(conduit_node_remove_path(this->c_node, path.c_str()));
  }

  /// rename a child (object interface)
  void rename_child(const std::string& current_name, const std::string& new_name)
  {
    CATALYST_CONDUIT_WRAP_EXCEP(
      conduit_node_rename_child(this->c_node, current_name.c_str(), new_name.c_str()));
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
  conduit_int8 as_int8() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int8(this->c_node));
  }
  conduit_int16 as_int16() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int16(this->c_node));
  }
  conduit_int32 as_int32() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int32(this->c_node));
  }
  conduit_int64 as_int64() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int64(this->c_node));
  }

  // unsigned integer scalars
  conduit_uint8 as_uint8() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_uint8(this->c_node));
  }
  conduit_uint16 as_uint16() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_uint16(this->c_node));
  }
  conduit_uint32 as_uint32() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_uint32(this->c_node));
  }
  conduit_uint64 as_uint64() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_uint64(this->c_node));
  }

  // floating point scalars
  conduit_float32 as_float32() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_float32(this->c_node));
  }
  conduit_float64 as_float64() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_float64(this->c_node));
  }

  // signed integers via pointers
  conduit_int8* as_int8_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int8_ptr(this->c_node));
  }
  conduit_int16* as_int16_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int16_ptr(this->c_node));
  }
  conduit_int32* as_int32_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int32_ptr(this->c_node));
  }
  conduit_int64* as_int64_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int64_ptr(this->c_node));
  }

  // unsigned integers via pointers
  conduit_uint8* as_uint8_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_uint8_ptr(this->c_node));
  }
  conduit_uint16* as_uint16_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_uint16_ptr(this->c_node));
  }
  conduit_uint32* as_uint32_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_uint32_ptr(this->c_node));
  }
  conduit_uint64* as_uint64_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_uint64_ptr(this->c_node));
  }

  // floating point via pointers
  conduit_float32* as_float32_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_float32_ptr(this->c_node));
  }
  conduit_float64* as_float64_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_float64_ptr(this->c_node));
  }

  // signed integers via pointers
  const conduit_int8* as_int8_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int8_ptr(this->c_node));
  }
  const conduit_int16* as_int16_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int16_ptr(this->c_node));
  }
  const conduit_int32* as_int32_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int32_ptr(this->c_node));
  }
  const conduit_int64* as_int64_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int64_ptr(this->c_node));
  }

  // unsigned integers via pointers
  const conduit_uint8* as_uint8_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_uint8_ptr(this->c_node));
  }
  const conduit_uint16* as_uint16_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_uint16_ptr(this->c_node));
  }
  const conduit_uint32* as_uint32_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_uint32_ptr(this->c_node));
  }
  const conduit_uint64* as_uint64_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_uint64_ptr(this->c_node));
  }

  // floating point via pointers
  const conduit_float32* as_float32_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_float32_ptr(this->c_node));
  }
  const conduit_float64* as_float64_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_float64_ptr(this->c_node));
  }

  // char8_str cases
  char* as_char8_str()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_char8_str(this->c_node));
  }
  const char* as_char8_str() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_char8_str(this->c_node));
  }
  std::string as_string() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return std::string(conduit_node_as_char8_str(this->c_node)));
  }

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
  char as_char() const { CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_char(this->c_node)); }
  short as_short() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_short(this->c_node));
  }
  int as_int() const { CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int(this->c_node)); }
  long as_long() const { CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_long(this->c_node)); }

  // signed integer scalars
  signed char as_signed_char() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_signed_char(this->c_node));
  }
  signed short as_signed_short() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_signed_short(this->c_node));
  }
  signed int as_signed_int() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_signed_int(this->c_node));
  }
  signed long as_signed_long() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_signed_long(this->c_node));
  }

  // unsigned integer scalars
  unsigned char as_unsigned_char() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_unsigned_char(this->c_node));
  }
  unsigned short as_unsigned_short() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_unsigned_short(this->c_node));
  }
  unsigned int as_unsigned_int() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_unsigned_int(this->c_node));
  }
  unsigned long as_unsigned_long() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_unsigned_long(this->c_node));
  }

  // floating point scalars
  float as_float() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_float(this->c_node));
  }
  double as_double() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_double(this->c_node));
  }

  // c style via pointer
  char* as_char_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_char_ptr(this->c_node));
  }
  short* as_short_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_short_ptr(this->c_node));
  }
  int* as_int_ptr() { CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int_ptr(this->c_node)); }
  long* as_long_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_long_ptr(this->c_node));
  }

  // signed integers via pointers
  signed char* as_signed_char_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_signed_char_ptr(this->c_node));
  }
  signed short* as_signed_short_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_signed_short_ptr(this->c_node));
  }
  signed int* as_signed_int_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_signed_int_ptr(this->c_node));
  }
  signed long* as_signed_long_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_signed_long_ptr(this->c_node));
  }

  // unsigned integers via pointers
  unsigned char* as_unsigned_char_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_unsigned_char_ptr(this->c_node));
  }
  unsigned short* as_unsigned_short_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_unsigned_short_ptr(this->c_node));
  }
  unsigned int* as_unsigned_int_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_unsigned_int_ptr(this->c_node));
  }
  unsigned long* as_unsigned_long_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_unsigned_long_ptr(this->c_node));
  }

  // floating point via pointers
  float* as_float_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_float_ptr(this->c_node));
  }
  double* as_double_ptr()
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_double_ptr(this->c_node));
  }

  // char via pointer (const variant)
  const char* as_char_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_char_ptr(this->c_node));
  }
  const short* as_short_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_short_ptr(this->c_node));
  }
  const int* as_int_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_int_ptr(this->c_node));
  }
  const long* as_long_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_long_ptr(this->c_node));
  }

  // signed integers via pointers (const variants)
  const signed char* as_signed_char_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_signed_char_ptr(this->c_node));
  }
  const signed short* as_signed_short_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_signed_short_ptr(this->c_node));
  }
  const signed int* as_signed_int_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_signed_int_ptr(this->c_node));
  }
  const signed long* as_signed_long_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_signed_long_ptr(this->c_node));
  }

  // unsigned integers via pointers (const variants)
  const unsigned char* as_unsigned_char_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_unsigned_char_ptr(this->c_node));
  }
  const unsigned short* as_unsigned_short_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_unsigned_short_ptr(this->c_node));
  }
  const unsigned int* as_unsigned_int_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_unsigned_int_ptr(this->c_node));
  }
  const unsigned long* as_unsigned_long_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_unsigned_long_ptr(this->c_node));
  }

  // floating point via pointers (const variants)
  const float* as_float_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_float_ptr(this->c_node));
  }

  const double* as_double_ptr() const
  {
    CATALYST_CONDUIT_WRAP_EXCEP(return conduit_node_as_double_ptr(this->c_node));
  }

private:
  conduit_node* c_node;

  explicit Node(conduit_node* other)
    : c_node(other)
  {
  }

  template <typename T, typename Deser = T>
  T to_type() const
  {
    const conduit_datatype* data = conduit_node_dtype(this->c_node);
    /* ints */
    if (conduit_datatype_is_int8(data))
    {
      return static_cast<T>(as_int8());
    }
    if (conduit_datatype_is_int16(data))
    {
      return static_cast<T>(as_int16());
    }
    if (conduit_datatype_is_int32(data))
    {
      return static_cast<T>(as_int32());
    }
    if (conduit_datatype_is_int64(data))
    {
      return static_cast<T>(as_int64());
    }
    /* conduit_uints */
    if (conduit_datatype_is_uint8(data))
    {
      return static_cast<T>(as_uint8());
    }
    if (conduit_datatype_is_uint16(data))
    {
      return static_cast<T>(as_uint16());
    }
    if (conduit_datatype_is_uint32(data))
    {
      return static_cast<T>(as_uint32());
    }
    if (conduit_datatype_is_uint64(data))
    {
      return static_cast<T>(as_uint64());
    }
    /* floats */
    if (conduit_datatype_is_float32(data))
    {
      return static_cast<T>(as_float32());
    }
    if (conduit_datatype_is_float64(data))
    {
      return static_cast<T>(as_float64());
    }
    // string case
    if (conduit_datatype_is_char8_str(data))
    {
      Deser res;
      std::stringstream ss(as_char8_str());
      if (ss >> res)
        return static_cast<T>(res);
    }
    return 0;
  }
};

inline conduit_node* c_node(const Node* n)
{
  return n ? n->c_node : nullptr;
}

inline Node cpp_node(conduit_node* n)
{
  conduit_node* n2 = conduit_node_create();
  // Setting it as external tells the underlying conduit_node
  // that we do not own this data. So, we won't ever free it.
  conduit_node_set_external_node(n2, n);
  return Node(n2);
}

}
#endif
