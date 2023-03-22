// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from @(package_name):@(interface_path)
// generated code does not contain a copyright notice
@
@#######################################################################
@# EmPy template for generating <idl>__struct.h files
@#
@# Context:
@#  - package_name (string)
@#  - interface_path (Path relative to the directory named after the package)
@#  - content (IdlContent, list of elements, e.g. Messages or Services)
@#######################################################################
@{
from rosidl_generator_c import idl_structure_type_to_c_typename
from rosidl_generator_c import type_hash_to_c_definition
from rosidl_generator_type_description import TYPE_HASH_VAR
from rosidl_pycommon import convert_camel_case_to_lower_case_underscore
include_parts = [package_name] + list(interface_path.parents[0].parts) + [
    'detail', convert_camel_case_to_lower_case_underscore(interface_path.stem)]
header_guard_variable = '__'.join([x.upper() for x in include_parts]) + \
    '__STRUCT_H_'

include_directives = set()
}@

#ifndef @(header_guard_variable)
#define @(header_guard_variable)

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "rosidl_runtime_c/type_hash.h"

@#######################################################################
@# Handle message
@#######################################################################
@{
from rosidl_parser.definition import Message
}@
@[for message in content.get_elements_of_type(Message)]@
@{
TEMPLATE(
    'msg__struct.h.em',
    package_name=package_name, interface_path=interface_path,
    message=message, include_directives=include_directives, type_hash=type_hash)
}@

@[end for]@
@
@#######################################################################
@# Handle service
@#######################################################################
@{
from rosidl_parser.definition import Service
}@
@[for service in content.get_elements_of_type(Service)]@

static const rosidl_type_hash_t @(idl_structure_type_to_c_typename(service.namespaced_type))__@(TYPE_HASH_VAR) = @(type_hash_to_c_definition(type_hash['service']));

@{
TEMPLATE(
    'msg__struct.h.em',
    package_name=package_name, interface_path=interface_path,
    message=service.request_message, include_directives=include_directives,
    type_hash=type_hash['request_message'])
}@

@{
TEMPLATE(
    'msg__struct.h.em',
    package_name=package_name, interface_path=interface_path,
    message=service.response_message, include_directives=include_directives,
    type_hash=type_hash['response_message'])
}@

@{
TEMPLATE(
    'msg__struct.h.em',
    package_name=package_name, interface_path=interface_path,
    message=service.event_message, include_directives=include_directives,
    type_hash=type_hash['event_message'])
}@

@[end for]@
@
@#######################################################################
@# Handle action
@#######################################################################
@{
from rosidl_parser.definition import Action
}@
@[for action in content.get_elements_of_type(Action)]@

static const rosidl_type_hash_t @(idl_structure_type_to_c_typename(action.namespaced_type))__@(TYPE_HASH_VAR) = @(type_hash_to_c_definition(type_hash['action']));

@{
TEMPLATE(
    'msg__struct.h.em',
    package_name=package_name, interface_path=interface_path,
    message=action.goal, include_directives=include_directives,
    type_hash=type_hash['goal'])
}@

@{
TEMPLATE(
    'msg__struct.h.em',
    package_name=package_name, interface_path=interface_path,
    message=action.result, include_directives=include_directives,
    type_hash=type_hash['result'])
}@

@{
TEMPLATE(
    'msg__struct.h.em',
    package_name=package_name, interface_path=interface_path,
    message=action.feedback, include_directives=include_directives,
    type_hash=type_hash['feedback'])
}@

static const rosidl_type_hash_t @(idl_structure_type_to_c_typename(action.send_goal_service.namespaced_type))__@(TYPE_HASH_VAR) = @(type_hash_to_c_definition(type_hash['send_goal_service']['service']));

@{
TEMPLATE(
    'msg__struct.h.em',
    package_name=package_name, interface_path=interface_path,
    message=action.send_goal_service.request_message, include_directives=include_directives,
    type_hash=type_hash['send_goal_service']['request_message'])
}@

@{
TEMPLATE(
    'msg__struct.h.em',
    package_name=package_name, interface_path=interface_path,
    message=action.send_goal_service.response_message, include_directives=include_directives,
    type_hash=type_hash['send_goal_service']['response_message'])
}@

@{
TEMPLATE(
    'msg__struct.h.em',
    package_name=package_name, interface_path=interface_path,
    message=action.send_goal_service.event_message, include_directives=include_directives,
    type_hash=type_hash['send_goal_service']['event_message'])
}@

static const rosidl_type_hash_t @(idl_structure_type_to_c_typename(action.get_result_service.namespaced_type))__@(TYPE_HASH_VAR) = @(type_hash_to_c_definition(type_hash['get_result_service']['service']));

@{
TEMPLATE(
    'msg__struct.h.em',
    package_name=package_name, interface_path=interface_path,
    message=action.get_result_service.request_message, include_directives=include_directives,
    type_hash=type_hash['get_result_service']['request_message'])
}@

@{
TEMPLATE(
    'msg__struct.h.em',
    package_name=package_name, interface_path=interface_path,
    message=action.get_result_service.response_message, include_directives=include_directives,
    type_hash=type_hash['get_result_service']['response_message'])
}@

@{
TEMPLATE(
    'msg__struct.h.em',
    package_name=package_name, interface_path=interface_path,
    message=action.get_result_service.event_message, include_directives=include_directives,
    type_hash=type_hash['get_result_service']['event_message'])
}@

@{
TEMPLATE(
    'msg__struct.h.em',
    package_name=package_name, interface_path=interface_path,
    message=action.feedback_message, include_directives=include_directives,
    type_hash=type_hash['feedback_message'])
}@

@[end for]@
#ifdef __cplusplus
}
#endif

#endif  // @(header_guard_variable)
