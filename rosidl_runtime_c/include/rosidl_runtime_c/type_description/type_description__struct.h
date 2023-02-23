// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from type_description_interfaces:msg/TypeDescription.idl
// generated code does not contain a copyright notice

#ifndef ROSIDL_RUNTIME_C__TYPE_DESCRIPTION__TYPE_DESCRIPTION__STRUCT_H_
#define ROSIDL_RUNTIME_C__TYPE_DESCRIPTION__TYPE_DESCRIPTION__STRUCT_H_

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
#define rosidl_runtime_c__type_description__TypeDescription__TYPE_VERSION_HASH__INIT {1, { \
      0xac, 0x5a, 0x6b, 0xf3, 0x23, 0x7f, 0xc6, 0xc4, \
      0xbb, 0xdc, 0x24, 0xca, 0x2b, 0xc9, 0xdc, 0xd1, \
      0x57, 0xe5, 0xd1, 0x13, 0xe4, 0x70, 0x83, 0x61, \
      0x44, 0x3c, 0x33, 0x1d, 0xc2, 0x0d, 0xc6, 0xeb, \
    }}
static const rosidl_type_hash_t rosidl_runtime_c__type_description__TypeDescription__TYPE_VERSION_HASH = rosidl_runtime_c__type_description__TypeDescription__TYPE_VERSION_HASH__INIT;

/// Type Description for interface, defined in compilation unit
// extern const rosidl_runtime_c__type_description__TypeDescription rosidl_runtime_c__type_description__TypeDescription__TYPE_DESCRIPTION;

// Constants defined in the message

// Include directives for member types
// Member 'type_description'
// Member 'referenced_type_descriptions'
#include "rosidl_runtime_c/type_description/individual_type_description__struct.h"

/// Struct defined in msg/TypeDescription in the package type_description_interfaces.
/**
  * Represents a complete type description, including the type itself as well as the types it references.
 */
typedef struct rosidl_runtime_c__type_description__TypeDescription
{
  /// Description of the type.
  rosidl_runtime_c__type_description__IndividualTypeDescription type_description;
  /// Descriptions of all referenced types, recursively.
  rosidl_runtime_c__type_description__IndividualTypeDescription__Sequence referenced_type_descriptions;
} rosidl_runtime_c__type_description__TypeDescription;

// Struct for a sequence of rosidl_runtime_c__type_description__TypeDescription.
typedef struct rosidl_runtime_c__type_description__TypeDescription__Sequence
{
  rosidl_runtime_c__type_description__TypeDescription * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_runtime_c__type_description__TypeDescription__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSIDL_RUNTIME_C__TYPE_DESCRIPTION__TYPE_DESCRIPTION__STRUCT_H_
