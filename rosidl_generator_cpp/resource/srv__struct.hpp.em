@# Included from rosidl_generator_cpp/resource/idl__struct.hpp.em
@{
from rosidl_generator_c import type_hash_to_c_definition
}@
@{
TEMPLATE(
    'msg__struct.hpp.em',
    package_name=package_name, interface_path=interface_path,
    message=service.request_message, include_directives=include_directives,
    type_hash=type_hash['request_message'], type_description=type_description)
}@
@# TODO(ek) find the description within

@{
TEMPLATE(
    'msg__struct.hpp.em',
    package_name=package_name, interface_path=interface_path,
    message=service.response_message, include_directives=include_directives,
    type_hash=type_hash['response_message'], type_description=type_description)
}@
@# TODO(ek) find the description within

@{
TEMPLATE(
    'msg__struct.hpp.em',
    package_name=package_name, interface_path=interface_path,
    message=service.event_message, include_directives=include_directives,
    type_hash=type_hash['event_message'], type_description=type_description)
}@
@# TODO(ek) find the description within

@[for ns in service.namespaced_type.namespaces]@
namespace @(ns)
{

@[end for]@
@
struct @(service.namespaced_type.name)
{
@{
service_typename = '::'.join(service.namespaced_type.namespaced_name())
}@
  static constexpr const rosidl_type_hash_t TYPE_VERSION_HASH = @(type_hash_to_c_definition(type_hash['service']));

  using Request = @(service_typename)_Request;
  using Response = @(service_typename)_Response;
  using Event = @(service_typename)_Event;

  static constexpr const @(type_hash_to_c_definition("TYPE_VERSION_HASH", type_hash['service'], indent=2))@

  static const rosidl_runtime_cpp::type_description::TypeDescription & get_type_description();
  // TODO(ek) implement
};
@
@[for ns in reversed(service.namespaced_type.namespaces)]@

}  // namespace @(ns)
@[end for]@
