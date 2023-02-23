# rosidl_runtime_c Features

## Primitive sequence definitions initializations and finalizations

`rosidl_runtime_c` provides default definitions, as well as initialization and finalization functions for the supported rosidl primitive sequence types.
These functions are defined in the following headers:

* `primitives_sequence.h`: C struct definitions for all supported primitive sequence types.
* `primitive_sequence_functions.h`: initialization and finalization functionality for the above defined sequences.
* `sequence_bound.h`: Struct designed to track the upper bounds size of a sequence. Currently unused.

## String and u16string definitions, initializations and finalizations

Like the sequences described above, `rosidl_runtime_c` provides definitions, as well as initialization and finalization functions for 8-bit and 16-bit character strings.

* `string.h`: C struct definition for an 8-bit string.
* `string_functions.h`: initialization and finalization functionality for the rosidl 8-bit string.
* `string_bound.h`: Designed to track the upper bounds size of a string. Currently unused.

* `u16string.h`: C struct definition for a 16-bit string.
* `u16string_functions.h`: initialization and finalization functionality for the rosidl 16-bit string.

## Typesupport structs

This package defines several structs which are utilized for providing access to properties and functionality of different rosidl types.
They are defined for the three main ROS 2 rosidl types:
* Messages (`message_type_support_struct.h`)
* Services (`service_type_support_struct.h`)
* Actions (`action_type_support_struct.h`)

## Type Description Interface Structs

A direct copy of the output of `rosidl_generator_c` for `type_description_interfaces`.

Goal: to have every generated interface type contain an instance of a TypeDescription that can be used for introspection and distribution at runtime.

Problem: `type_description_interfaces` is a message package like any other, and therefore depends on `rosidl_generator_c` and `rosidl_runtime_c`. So, if the generator depends on that package it causes a circular dependency.

Solution: Copy the struct definitions here for use in code generation, forcing them to stay in sync by build/test time means.

Constraints:
* The data structure instance created by codegen should be directly castable to an instance of the actual message, so that it can be published without computation.

Copying process:
1. Run `colcon build --packages-up-to type_description_interfaces`
1. Copy `build/type_description_interfaces/rosidl_generator_c/type_description_interfaces` to `rosidl_runtime_c/include/type_description_interfaces`
1. mv srcs to src
1. Find-and-replace all instances, in those copied files,  `type_description_interfaces__msg` to `rosidl_type_description`
1. Add "copied" notice to all copied files as the very first line

```
// copied from type_description_interfaces/rosidl_generator_c/
```
