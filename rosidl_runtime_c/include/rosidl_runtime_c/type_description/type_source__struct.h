// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from type_description_interfaces:msg/TypeSource.idl
// generated code does not contain a copyright notice

#ifndef ROSIDL_RUNTIME_C__TYPE_DESCRIPTION__TYPE_SOURCE__STRUCT_H_
#define ROSIDL_RUNTIME_C__TYPE_DESCRIPTION__TYPE_SOURCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "rosidl_runtime_c/type_hash.h"


// Type Hash for interface
static const rosidl_type_hash_t rosidl_runtime_c__type_description__TypeSource__TYPE_HASH = {1, {
    0xe1, 0xe5, 0x26, 0x05, 0xeb, 0xaa, 0xf4, 0xee,
    0xaa, 0x72, 0xb2, 0xc0, 0x50, 0xe0, 0xb5, 0xff,
    0x22, 0xa9, 0x02, 0x9e, 0x81, 0x78, 0x4a, 0xa6,
    0x99, 0xde, 0x56, 0xbb, 0x7f, 0x90, 0x13, 0x9f,
  }};

/// Type Description for interface, defined in compilation unit
// extern const rosidl_runtime_c__type_description__TypeDescription rosidl_runtime_c__type_description__TypeSource__TYPE_DESCRIPTION;

// Constants defined in the message

/// Constant 'ENCODING_NOT_SET'.
enum
{
  rosidl_runtime_c__type_description__TypeSource__ENCODING_NOT_SET = 0
};

/// Constant 'ENCODING_MSG'.
enum
{
  rosidl_runtime_c__type_description__TypeSource__ENCODING_MSG = 1
};

/// Constant 'ENCODING_SRV'.
enum
{
  rosidl_runtime_c__type_description__TypeSource__ENCODING_SRV = 2
};

/// Constant 'ENCODING_ACTION'.
enum
{
  rosidl_runtime_c__type_description__TypeSource__ENCODING_ACTION = 3
};

/// Constant 'ENCODING_IDL'.
enum
{
  rosidl_runtime_c__type_description__TypeSource__ENCODING_IDL = 4
};

// Include directives for member types
// Member 'type_name'
// Member 'raw_file_contents'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TypeSource in the package type_description_interfaces.
/**
  * Represents the original source of a ROS 2 interface definition.
 */
typedef struct rosidl_runtime_c__type_description__TypeSource
{
  /// ROS interface type name, in PACKAGE/NAMESPACE/TYPENAME format
  rosidl_runtime_c__String type_name;
  /// The type of the original source file, from the above constants
  uint8_t encoding;
  /// Dumped contents of the interface definition source file
  rosidl_runtime_c__String raw_file_contents;
} rosidl_runtime_c__type_description__TypeSource;

// Struct for a sequence of rosidl_runtime_c__type_description__TypeSource.
typedef struct rosidl_runtime_c__type_description__TypeSource__Sequence
{
  rosidl_runtime_c__type_description__TypeSource * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_runtime_c__type_description__TypeSource__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSIDL_RUNTIME_C__TYPE_DESCRIPTION__TYPE_SOURCE__STRUCT_H_
