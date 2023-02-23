@# Included from rosidl_generator_cpp/resource/idl__description.hpp.em
@{
def typename_to_individual_varname(typename):
  return typename.replace('/', '__') + '__individual'
}@
@[for ns in message.structure.namespaced_type.namespaces]@
namespace @(ns)
{

@[end for]@
template <class ContainerAllocator>
const rosidl_runtime_cpp::type_description::TypeDescription_<ContainerAllocator> &
@(message.structure.namespaced_type.name)_<ContainerAllocator>::get_type_description() {
  static bool constructed = false;
  static rosidl_runtime_cpp::type_description::TypeDescription_<ContainerAllocator> instance;
  if (constructed) {
    return instance;
  }
@[for itd in [type_description['type_description']] + type_description['referenced_type_descriptions']]@
@{
itd_var = typename_to_individual_varname(itd['type_name'])
}@
  static rosidl_runtime_cpp::type_description::IndividualTypeDescription @(itd_var);
  @(itd_var).type_name = "@(itd['type_name'])";
  @(itd_var).fields.resize(@(len(itd['fields'])));
@[  for idx, field in enumerate(itd['fields'])]@
  @(itd_var).fields[@(idx)].name = "@(field['name'])";
  @(itd_var).fields[@(idx)].type.type_id = @(field['type']['type_id']);
  @(itd_var).fields[@(idx)].type.capacity = @(field['type']['capacity']);
  @(itd_var).fields[@(idx)].type.string_capacity = @(field['type']['string_capacity']);
  @(itd_var).fields[@(idx)].type.nested_type_name = "@(field['type']['nested_type_name'])";
  @(itd_var).fields[@(idx)].default_value = "@(field['default_value'])";
@[  end for]@
@[end for]@
@{
this_individual_var = typename_to_individual_varname(type_description['type_description']['type_name'])
}@

  instance.type_description = @(this_individual_var);
  instance.referenced_type_descriptions = {
@[for ref_itd in type_description['referenced_type_descriptions']]@
      @(typename_to_individual_varname(ref_itd['type_name'])),
@[end for]@
  };

  constructed = true;
  return instance;
}
@
@[for ns in reversed(message.structure.namespaced_type.namespaces)]@

}  // namespace @(ns)
@[end for]@
