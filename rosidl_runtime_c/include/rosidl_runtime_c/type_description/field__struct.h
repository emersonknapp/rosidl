// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from type_description_interfaces:msg/Field.idl
// generated code does not contain a copyright notice

#ifndef ROSIDL_RUNTIME_C__TYPE_DESCRIPTION__FIELD__STRUCT_H_
#define ROSIDL_RUNTIME_C__TYPE_DESCRIPTION__FIELD__STRUCT_H_

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
#define rosidl_runtime_c__type_description__Field__TYPE_VERSION_HASH__INIT {1, { \
      0x16, 0xac, 0x44, 0xbf, 0xed, 0x90, 0xab, 0xa3, \
      0x4c, 0xee, 0x4b, 0xad, 0x73, 0x6d, 0xae, 0xdc, \
      0x4a, 0x08, 0xf8, 0xd1, 0x44, 0x22, 0xdb, 0xe6, \
      0xf9, 0x24, 0x6f, 0xa6, 0x9f, 0xca, 0xe0, 0x03, \
    }}
static const rosidl_type_hash_t rosidl_runtime_c__type_description__Field__TYPE_VERSION_HASH = rosidl_runtime_c__type_description__Field__TYPE_VERSION_HASH__INIT;

/// Type Description for interface, defined in compilation unit
// extern const rosidl_runtime_c__type_description__TypeDescription rosidl_runtime_c__type_description__Field__TYPE_DESCRIPTION;

// Constants defined in the message

// Include directives for member types
// Member 'name'
// Member 'default_value'
#include "rosidl_runtime_c/string.h"
// Member 'type'
#include "rosidl_runtime_c/type_description/field_type__struct.h"

/// Struct defined in msg/Field in the package type_description_interfaces.
/**
  * Represents a single field in a type.
 */
typedef struct rosidl_runtime_c__type_description__Field
{
  /// Name of the field.
  rosidl_runtime_c__String name;
  /// Type of the field, including details about the type like length, nested name, etc.
  rosidl_runtime_c__type_description__FieldType type;
  /// Literal default value of the field as a string, as it appeared in the original
  /// message description file, whether that be .msg/.srv/.action or .idl.
  rosidl_runtime_c__String default_value;
} rosidl_runtime_c__type_description__Field;

// Struct for a sequence of rosidl_runtime_c__type_description__Field.
typedef struct rosidl_runtime_c__type_description__Field__Sequence
{
  rosidl_runtime_c__type_description__Field * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_runtime_c__type_description__Field__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSIDL_RUNTIME_C__TYPE_DESCRIPTION__FIELD__STRUCT_H_
