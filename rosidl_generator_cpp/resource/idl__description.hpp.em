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
from rosidl_generator_type_description import extract_subinterface
from rosidl_parser.definition import Action
from rosidl_parser.definition import Message
from rosidl_parser.definition import Service
from rosidl_pycommon import convert_camel_case_to_lower_case_underscore

include_parts = [package_name] + list(interface_path.parents[0].parts) + [
    'detail', convert_camel_case_to_lower_case_underscore(interface_path.stem)]
include_base = '/'.join(include_parts)
header_guard_variable = '__'.join([x.upper() for x in include_parts]) + \
    '__DESCRIPTION_HPP_'
type_description_msg = type_description_info['type_description_msg']
subinterfaces = type_description_info['subinterfaces']
}@

@[def define_get_type_description_function(namespaced_type, type_description_msg, template=True)]@
@{
from rosidl_generator_cpp import escape_string
suffix = '_<ContainerAllocator>' if template else ''
toplevel_type_description = type_description_msg['type_description']
all_type_descriptions = [toplevel_type_description] + type_description_msg['referenced_type_descriptions']

def typename_to_individual_varname(typename):
  return typename.replace('/', '__') + '__individual'
}@
@[  if template]@
template <class ContainerAllocator>
@[  else]@
inline
@[  end if]@
const rosidl_runtime_cpp::type_description::TypeDescription &
@(namespaced_type.name)@(suffix)::get_type_description() {
  static bool constructed = false;
  static rosidl_runtime_cpp::type_description::TypeDescription instance;
  if (constructed) {
    return instance;
  }
@[  for itd in all_type_descriptions]@
@{ itd_var = typename_to_individual_varname(itd['type_name']) }@
  static rosidl_runtime_cpp::type_description::IndividualTypeDescription @(itd_var);
  @(itd_var).type_name = "@(itd['type_name'])";
  @(itd_var).fields.resize(@(len(itd['fields'])));
@[    for idx, field in enumerate(itd['fields'])]@
  @(itd_var).fields[@(idx)].name = "@(field['name'])";
  @(itd_var).fields[@(idx)].type.type_id = @(field['type']['type_id']);
  @(itd_var).fields[@(idx)].type.capacity = @(field['type']['capacity']);
  @(itd_var).fields[@(idx)].type.string_capacity = @(field['type']['string_capacity']);
  @(itd_var).fields[@(idx)].type.nested_type_name = "@(field['type']['nested_type_name'])";
  @(itd_var).fields[@(idx)].default_value = "@(escape_string(field['default_value']))";
@[    end for]@

@[  end for]@

  instance.type_description = @(typename_to_individual_varname(toplevel_type_description['type_name']));
  instance.referenced_type_descriptions = {
@[  for ref_itd in type_description_msg['referenced_type_descriptions']]@
      @(typename_to_individual_varname(ref_itd['type_name'])),
@[  end for]@
  };

  constructed = true;
  return instance;
}
@[end def]@

@[def define_srv_description_functions(service, type_description_msg, subinterfaces, define_get_type_description_function)]@
@{
from rosidl_generator_type_description import extract_subinterface
request_msg = extract_subinterface(type_description_msg, 'request_message', subinterfaces)
response_msg = extract_subinterface(type_description_msg, 'response_message', subinterfaces)
event_msg = extract_subinterface(type_description_msg, 'event_message', subinterfaces)
}@
@(define_get_type_description_function(service.namespaced_type, type_description_msg, template=False))
@(define_get_type_description_function(service.request_message.structure.namespaced_type, request_msg))
@(define_get_type_description_function(service.response_message.structure.namespaced_type, response_msg))
@(define_get_type_description_function(service.event_message.structure.namespaced_type, event_msg))
@[end def]@

#ifndef @(header_guard_variable)
#define @(header_guard_variable)

#include "@(include_base)__struct.hpp"
#include "rosidl_runtime_cpp/type_description/type_description__struct.hpp"

@#######################################################################
@# Handle message
@#######################################################################
@[for message in content.get_elements_of_type(Message)]@
@[  for ns in message.structure.namespaced_type.namespaces]@
namespace @(ns)
{

@[  end for]@
@(define_get_type_description_function(message.structure.namespaced_type, type_description_msg))
@[  for ns in reversed(message.structure.namespaced_type.namespaces)]@

}  // namespace @(ns)
@[  end for]@
@[end for]@
@
@#######################################################################
@# Handle service
@#######################################################################
@[for service in content.get_elements_of_type(Service)]@
@[  for ns in service.namespaced_type.namespaces]@
namespace @(ns)
{

@[  end for]@
@(define_srv_description_functions(service, type_description_msg, subinterfaces, define_get_type_description_function))
@[  for ns in reversed(service.namespaced_type.namespaces)]@

}  // namespace @(ns)
@[  end for]@
@[end for]@
@
@#######################################################################
@# Handle action
@#######################################################################
@[for action in content.get_elements_of_type(Action)]@
@{
goal_msg = extract_subinterface(type_description_msg, 'goal', subinterfaces)
result_msg = extract_subinterface(type_description_msg, 'result', subinterfaces)
feedback_msg = extract_subinterface(type_description_msg, 'feedback', subinterfaces)
send_goal_srv = extract_subinterface(type_description_msg, 'send_goal_service', subinterfaces)
get_result_srv = extract_subinterface(type_description_msg, 'get_result_service', subinterfaces)
feedback_message_msg = extract_subinterface(type_description_msg, 'feedback_message', subinterfaces)
}@
@[  for ns in action.namespaced_type.namespaces]@
namespace @(ns)
{

@[  end for]@
@(define_get_type_description_function(action.namespaced_type, type_description_msg, template=False))
@(define_get_type_description_function(action.goal.structure.namespaced_type, goal_msg))
@(define_get_type_description_function(action.result.structure.namespaced_type, result_msg))
@(define_get_type_description_function(action.feedback.structure.namespaced_type, feedback_msg))
@(define_srv_description_functions(action.send_goal_service, send_goal_srv, subinterfaces, define_get_type_description_function))
@(define_srv_description_functions(action.get_result_service, get_result_srv, subinterfaces, define_get_type_description_function))
@(define_get_type_description_function(action.feedback_message.structure.namespaced_type, feedback_message_msg))
@[  for ns in reversed(action.namespaced_type.namespaces)]@

}  // namespace @(ns)
@[  end for]@
@[end for]@

#endif  // @(header_guard_variable)
