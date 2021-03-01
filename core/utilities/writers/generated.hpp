void set_node(const Node& data)
{
  conduit_node_set_node(this->c_node, data.c_node);
}

void set(const Node& data)
{
  this->set_node(data);
}

void set_int8(const conduit_int8 data)
{
  conduit_node_set_int8(this->c_node, data);
}

void set(const conduit_int8 data)
{
  this->set_int8(data);
}

void set_int16(const conduit_int16 data)
{
  conduit_node_set_int16(this->c_node, data);
}

void set(const conduit_int16 data)
{
  this->set_int16(data);
}

void set_int32(const conduit_int32 data)
{
  conduit_node_set_int32(this->c_node, data);
}

void set(const conduit_int32 data)
{
  this->set_int32(data);
}

void set_int64(const conduit_int64 data)
{
  conduit_node_set_int64(this->c_node, data);
}

void set(const conduit_int64 data)
{
  this->set_int64(data);
}

void set_uint8(const conduit_uint8 data)
{
  conduit_node_set_uint8(this->c_node, data);
}

void set(const conduit_uint8 data)
{
  this->set_uint8(data);
}

void set_uint16(const conduit_uint16 data)
{
  conduit_node_set_uint16(this->c_node, data);
}

void set(const conduit_uint16 data)
{
  this->set_uint16(data);
}

void set_uint32(const conduit_uint32 data)
{
  conduit_node_set_uint32(this->c_node, data);
}

void set(const conduit_uint32 data)
{
  this->set_uint32(data);
}

void set_uint64(const conduit_uint64 data)
{
  conduit_node_set_uint64(this->c_node, data);
}

void set(const conduit_uint64 data)
{
  this->set_uint64(data);
}

void set_float32(const conduit_float32 data)
{
  conduit_node_set_float32(this->c_node, data);
}

void set(const conduit_float32 data)
{
  this->set_float32(data);
}

void set_float64(const conduit_float64 data)
{
  conduit_node_set_float64(this->c_node, data);
}

void set(const conduit_float64 data)
{
  this->set_float64(data);
}

void set(const char data)
{
  conduit_node_set_char(this->c_node, data);
}
#ifndef CONDUIT_USE_CHAR
void set(const signed char data)
{
  conduit_node_set_signed_char(this->c_node, data);
}
void set(const unsigned char data)
{
  conduit_node_set_unsigned_char(this->c_node, data);
}
#endif
#ifndef CONDUIT_USE_SHORT
void set(const short data)
{
  conduit_node_set_short(this->c_node, data);
}
void set(const unsigned short data)
{
  conduit_node_set_unsigned_short(this->c_node, data);
}
#endif
#ifndef CONDUIT_USE_INT
void set(const int data)
{
  conduit_node_set_int(this->c_node, data);
}
void set(const unsigned int data)
{
  conduit_node_set_unsigned_int(this->c_node, data);
}
#endif
#ifndef CONDUIT_USE_LONG
void set(const long data)
{
  conduit_node_set_long(this->c_node, data);
}
void set(const unsigned long data)
{
  conduit_node_set_unsigned_long(this->c_node, data);
}
#endif
void set_string(const std::string& data)
{
  conduit_node_set_char8_str(this->c_node, data.c_str());
}

void set(const std::string& data)
{
  this->set_string(data);
}

void set_char8_str(const char* data)
{
  conduit_node_set_char8_str(this->c_node, data);
}

void set_int8_vector(const std::vector<conduit_int8>& data)
{
  conduit_node_set_int8_ptr(this->c_node, std::vector<conduit_int8>(data).data(), data.size());
}

void set(const std::vector<conduit_int8>& data)
{
  this->set_int8_vector(data);
}

void set_int16_vector(const std::vector<conduit_int16>& data)
{
  conduit_node_set_int16_ptr(this->c_node, std::vector<conduit_int16>(data).data(), data.size());
}

void set(const std::vector<conduit_int16>& data)
{
  this->set_int16_vector(data);
}

void set_int32_vector(const std::vector<conduit_int32>& data)
{
  conduit_node_set_int32_ptr(this->c_node, std::vector<conduit_int32>(data).data(), data.size());
}

void set(const std::vector<conduit_int32>& data)
{
  this->set_int32_vector(data);
}

void set_int64_vector(const std::vector<conduit_int64>& data)
{
  conduit_node_set_int64_ptr(this->c_node, std::vector<conduit_int64>(data).data(), data.size());
}

void set(const std::vector<conduit_int64>& data)
{
  this->set_int64_vector(data);
}

void set_uint8_vector(const std::vector<conduit_uint8>& data)
{
  conduit_node_set_uint8_ptr(this->c_node, std::vector<conduit_uint8>(data).data(), data.size());
}

void set(const std::vector<conduit_uint8>& data)
{
  this->set_uint8_vector(data);
}

void set_uint16_vector(const std::vector<conduit_uint16>& data)
{
  conduit_node_set_uint16_ptr(this->c_node, std::vector<conduit_uint16>(data).data(), data.size());
}

void set(const std::vector<conduit_uint16>& data)
{
  this->set_uint16_vector(data);
}

void set_uint32_vector(const std::vector<conduit_uint32>& data)
{
  conduit_node_set_uint32_ptr(this->c_node, std::vector<conduit_uint32>(data).data(), data.size());
}

void set(const std::vector<conduit_uint32>& data)
{
  this->set_uint32_vector(data);
}

void set_uint64_vector(const std::vector<conduit_uint64>& data)
{
  conduit_node_set_uint64_ptr(this->c_node, std::vector<conduit_uint64>(data).data(), data.size());
}

void set(const std::vector<conduit_uint64>& data)
{
  this->set_uint64_vector(data);
}

void set_float32_vector(const std::vector<conduit_float32>& data)
{
  conduit_node_set_float32_ptr(
    this->c_node, std::vector<conduit_float32>(data).data(), data.size());
}

void set(const std::vector<conduit_float32>& data)
{
  this->set_float32_vector(data);
}

void set_float64_vector(const std::vector<conduit_float64>& data)
{
  conduit_node_set_float64_ptr(
    this->c_node, std::vector<conduit_float64>(data).data(), data.size());
}

void set(const std::vector<conduit_float64>& data)
{
  this->set_float64_vector(data);
}

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
    (conduit_float32*)memcpy(data_cpy, data, sizeof(conduit_float32) * num_elements), num_elements,
    offset, stride, element_bytes, endianness);
}

void set(const conduit_float32* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
  conduit_index_t stride = sizeof(conduit_float32),
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
    (conduit_float64*)memcpy(data_cpy, data, sizeof(conduit_float64) * num_elements), num_elements,
    offset, stride, element_bytes, endianness);
}

void set(const conduit_float64* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
  conduit_index_t stride = sizeof(conduit_float64),
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
    (signed char*)memcpy(data_cpy, data, sizeof(signed char) * num_elements), num_elements, offset,
    stride, element_bytes, endianness);
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

void set_path(const std::string& path, const Node& data)
{
  this->set_path_node(path, data);
}

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

void set_path(const std::string& path, const conduit_int16* data, conduit_index_t num_elements = 1,
  conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int16),
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

void set_path(const std::string& path, const conduit_int32* data, conduit_index_t num_elements = 1,
  conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int32),
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

void set_path(const std::string& path, const conduit_int64* data, conduit_index_t num_elements = 1,
  conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int64),
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

void set_path(const std::string& path, const conduit_uint8* data, conduit_index_t num_elements = 1,
  conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint8),
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

void set_path(const std::string& path, const conduit_uint16* data, conduit_index_t num_elements = 1,
  conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint16),
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

void set_path(const std::string& path, const conduit_uint32* data, conduit_index_t num_elements = 1,
  conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint32),
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

void set_path(const std::string& path, const conduit_uint64* data, conduit_index_t num_elements = 1,
  conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_uint64),
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
    (conduit_float32*)memcpy(data_cpy, data, sizeof(conduit_float32) * num_elements), num_elements,
    offset, stride, element_bytes, endianness);
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
    (conduit_float64*)memcpy(data_cpy, data, sizeof(conduit_float64) * num_elements), num_elements,
    offset, stride, element_bytes, endianness);
}

void set_path(const std::string& path, const conduit_float64* data,
  conduit_index_t num_elements = 1, conduit_index_t offset = 0,
  conduit_index_t stride = sizeof(conduit_float64),
  conduit_index_t element_bytes = sizeof(conduit_float64), conduit_index_t endianness = 0)
{
  this->set_path_float64_ptr(path, data, num_elements, offset, stride, element_bytes, endianness);
}

void set_path_char_ptr(const std::string& path, const char* data, conduit_index_t num_elements = 1,
  conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_CHAR),
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
    (signed char*)memcpy(data_cpy, data, sizeof(signed char) * num_elements), num_elements, offset,
    stride, element_bytes, endianness);
}
void set_path(const std::string& path, const unsigned char* data, conduit_index_t num_elements = 1,
  conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_CHAR),
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
void set_path(const std::string& path, const unsigned short* data, conduit_index_t num_elements = 1,
  conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_SHORT),
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
void set_path(const std::string& path, const unsigned long* data, conduit_index_t num_elements = 1,
  conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
  conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
  conduit_index_t endianness = 0)
{
  unsigned long data_cpy[num_elements];
  conduit_node_set_path_unsigned_long_ptr_detailed(this->c_node, path.c_str(),
    (unsigned long*)memcpy(data_cpy, data, sizeof(unsigned long) * num_elements), num_elements,
    offset, stride, element_bytes, endianness);
}
#endif
void set_external_node(Node& data)
{
  conduit_node_set_external_node(this->c_node, data.c_node);
}

void set_external(Node& data)
{
  this->set_external_node(data);
}

void set_external_char8_str(char* data)
{
  conduit_node_set_external_char8_str(this->c_node, data);
}

void set_external(char* data)
{
  this->set_external_char8_str(data);
}

void set_external_int8_vector(std::vector<conduit_int8>& data)
{
  conduit_node_set_external_int8_ptr(this->c_node, data.data(), data.size());
}

void set_external(std::vector<conduit_int8>& data)
{
  this->set_external_int8_vector(data);
}

void set_external_int16_vector(std::vector<conduit_int16>& data)
{
  conduit_node_set_external_int16_ptr(this->c_node, data.data(), data.size());
}

void set_external(std::vector<conduit_int16>& data)
{
  this->set_external_int16_vector(data);
}

void set_external_int32_vector(std::vector<conduit_int32>& data)
{
  conduit_node_set_external_int32_ptr(this->c_node, data.data(), data.size());
}

void set_external(std::vector<conduit_int32>& data)
{
  this->set_external_int32_vector(data);
}

void set_external_int64_vector(std::vector<conduit_int64>& data)
{
  conduit_node_set_external_int64_ptr(this->c_node, data.data(), data.size());
}

void set_external(std::vector<conduit_int64>& data)
{
  this->set_external_int64_vector(data);
}

void set_external_uint8_vector(std::vector<conduit_uint8>& data)
{
  conduit_node_set_external_uint8_ptr(this->c_node, data.data(), data.size());
}

void set_external(std::vector<conduit_uint8>& data)
{
  this->set_external_uint8_vector(data);
}

void set_external_uint16_vector(std::vector<conduit_uint16>& data)
{
  conduit_node_set_external_uint16_ptr(this->c_node, data.data(), data.size());
}

void set_external(std::vector<conduit_uint16>& data)
{
  this->set_external_uint16_vector(data);
}

void set_external_uint32_vector(std::vector<conduit_uint32>& data)
{
  conduit_node_set_external_uint32_ptr(this->c_node, data.data(), data.size());
}

void set_external(std::vector<conduit_uint32>& data)
{
  this->set_external_uint32_vector(data);
}

void set_external_uint64_vector(std::vector<conduit_uint64>& data)
{
  conduit_node_set_external_uint64_ptr(this->c_node, data.data(), data.size());
}

void set_external(std::vector<conduit_uint64>& data)
{
  this->set_external_uint64_vector(data);
}

void set_external_float32_vector(std::vector<conduit_float32>& data)
{
  conduit_node_set_external_float32_ptr(this->c_node, data.data(), data.size());
}

void set_external(std::vector<conduit_float32>& data)
{
  this->set_external_float32_vector(data);
}

void set_external_float64_vector(std::vector<conduit_float64>& data)
{
  conduit_node_set_external_float64_ptr(this->c_node, data.data(), data.size());
}

void set_external(std::vector<conduit_float64>& data)
{
  this->set_external_float64_vector(data);
}

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
void set_external_int8_ptr(conduit_int8* data, conduit_index_t num_elements = 1,
  conduit_index_t offset = 0, conduit_index_t stride = sizeof(conduit_int8),
  conduit_index_t element_bytes = sizeof(conduit_int8), conduit_index_t endianness = 0)
{
  conduit_node_set_external_int8_ptr_detailed(
    this->c_node, data, num_elements, offset, stride, element_bytes, endianness);
}

void set_external(conduit_int8* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
  conduit_index_t stride = sizeof(conduit_int8),
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

void set_external(conduit_int16* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
  conduit_index_t stride = sizeof(conduit_int16),
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

void set_external(conduit_int32* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
  conduit_index_t stride = sizeof(conduit_int32),
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

void set_external(conduit_int64* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
  conduit_index_t stride = sizeof(conduit_int64),
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

void set_external(conduit_uint8* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
  conduit_index_t stride = sizeof(conduit_uint8),
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

void set_external_char_ptr(char* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
  conduit_index_t stride = sizeof(CONDUIT_NATIVE_CHAR),
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
void set_external(unsigned char* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
  conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_CHAR),
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
void set_external(unsigned int* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
  conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_INT),
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
void set_external(unsigned long* data, conduit_index_t num_elements = 1, conduit_index_t offset = 0,
  conduit_index_t stride = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
  conduit_index_t element_bytes = sizeof(CONDUIT_NATIVE_UNSIGNED_LONG),
  conduit_index_t endianness = 0)
{
  conduit_node_set_external_unsigned_long_ptr_detailed(
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

void set_path_external(const std::string& path, char* data)
{
  this->set_path_external_char8_str(path, data);
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
  conduit_node_set_path_external_float32_ptr(this->c_node, path.c_str(), data.data(), data.size());
}

void set_path_external(const std::string& path, std::vector<conduit_float32>& data)
{
  this->set_path_external_float32_vector(path, data);
}

void set_path_external_float64_vector(const std::string& path, std::vector<conduit_float64>& data)
{
  conduit_node_set_path_external_float64_ptr(this->c_node, path.c_str(), data.data(), data.size());
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
void set_path_external(const std::string& path, signed char* data, conduit_index_t num_elements = 1,
  conduit_index_t offset = 0, conduit_index_t stride = sizeof(CONDUIT_NATIVE_SIGNED_CHAR),
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
