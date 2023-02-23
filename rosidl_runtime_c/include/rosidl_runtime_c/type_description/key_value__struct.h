// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from type_description_interfaces:msg/KeyValue.idl
// generated code does not contain a copyright notice

#ifndef ROSIDL_RUNTIME_C__TYPE_DESCRIPTION__KEY_VALUE__STRUCT_H_
#define ROSIDL_RUNTIME_C__TYPE_DESCRIPTION__KEY_VALUE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "rosidl_runtime_c/type_hash.h"


// Type Version Hash for interface
// Note: this define is for MSVC, where the static const var can't be used in downstream aggregate initializers
#define rosidl_runtime_c__type_description__KeyValue__TYPE_VERSION_HASH__INIT {1, { \
      0x96, 0xeb, 0xe1, 0xdc, 0xdd, 0xe6, 0x55, 0x04, \
      0x93, 0xad, 0xeb, 0x5f, 0xa6, 0x97, 0x73, 0x36, \
      0x00, 0xb9, 0x68, 0x79, 0x2c, 0x20, 0xac, 0x18, \
      0xdb, 0x60, 0x05, 0x6e, 0xb6, 0x46, 0xee, 0xad, \
    }}
static const rosidl_type_hash_t rosidl_runtime_c__type_description__KeyValue__TYPE_VERSION_HASH = rosidl_runtime_c__type_description__KeyValue__TYPE_VERSION_HASH__INIT;

/// Type Description for interface, defined in compilation unit
// extern const rosidl_runtime_c__type_description__TypeDescription rosidl_runtime_c__type_description__KeyValue__TYPE_DESCRIPTION;

// Constants defined in the message

// Include directives for member types
// Member 'key'
// Member 'value'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/KeyValue in the package type_description_interfaces.
typedef struct rosidl_runtime_c__type_description__KeyValue
{
  rosidl_runtime_c__String key;
  rosidl_runtime_c__String value;
} rosidl_runtime_c__type_description__KeyValue;

// Struct for a sequence of rosidl_runtime_c__type_description__KeyValue.
typedef struct rosidl_runtime_c__type_description__KeyValue__Sequence
{
  rosidl_runtime_c__type_description__KeyValue * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_runtime_c__type_description__KeyValue__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSIDL_RUNTIME_C__TYPE_DESCRIPTION__KEY_VALUE__STRUCT_H_
