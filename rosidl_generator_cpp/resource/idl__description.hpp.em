// generated from rosidl_generator_cpp/resource/idl__description.hpp.em
// with input from @(package_name):@(interface_path)
// generated code does not contain a copyright notice
@
@#######################################################################
@# EmPy template for generating <idl>__description.hpp files
@#
@# Context:
@#  - package_name (string)
@#  - interface_path (Path relative to the directory named after the package)
@#  - content (IdlContent, list of elements, e.g. Messages or Services)
@#######################################################################
@{
from rosidl_pycommon import convert_camel_case_to_lower_case_underscore
include_parts = [package_name] + list(interface_path.parents[0].parts) + [
    'detail', convert_camel_case_to_lower_case_underscore(interface_path.stem)]
include_base = '/'.join(include_parts)
header_guard_variable = '__'.join([x.upper() for x in include_parts]) + \
    '__DESCRIPTION_HPP_'
type_hash = type_description_info['hashes']
type_description = type_description_info['type_description']
}@

#ifndef @(header_guard_variable)
#define @(header_guard_variable)

#include "@(include_base)__struct.hpp"
#include "rosidl_runtime_cpp/type_description/type_description__struct.hpp"

@#######################################################################
@# Handle message
@#######################################################################
@{
from rosidl_parser.definition import Message
toplevel_template = True
}@
@[for message in content.get_elements_of_type(Message)]@
@{
TEMPLATE(
    'msg__description.hpp.em',
    package_name=package_name, interface_path=interface_path,
    message=message,
    type_hash=type_hash, type_description=type_description)
}@

@[end for]@
@
@#######################################################################
@# Handle service
@#######################################################################
@{
from rosidl_parser.definition import Service
toplevel_template = False
}@
@[for service in content.get_elements_of_type(Service)]@
@#@{
@#TEMPLATE(
@#    'srv__description.hpp.em',
@#    package_name=package_name, interface_path=interface_path,
@#    service=service,
@#    type_hash=type_hash, type_description=type_description)
@#}@

@[end for]@
@
@#######################################################################
@# Handle action
@#######################################################################
@{
from rosidl_parser.definition import Action
toplevel_template = False
}@
@[for action in content.get_elements_of_type(Action)]@
@#@{
@#TEMPLATE(
@#    'action__description.hpp.em',
@#    package_name=package_name, interface_path=interface_path,
@#    action=action,
@#    type_hash=type_hash, type_description=type_description)
@#}@

@[end for]@


#endif  // @(header_guard_variable)
