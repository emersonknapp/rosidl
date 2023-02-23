// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from type_description_interfaces:msg/Field.idl
// generated code does not contain a copyright notice

#ifndef ROSIDL_RUNTIME_CPP__TYPE_DESCRIPTION__FIELD__STRUCT_HPP_
#define ROSIDL_RUNTIME_CPP__TYPE_DESCRIPTION__FIELD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"
#include "rosidl_runtime_cpp/type_description/type_description__struct.hpp"


// Include directives for member types
// Member 'type'
#include "rosidl_runtime_cpp/type_description/field_type__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosidl_runtime_cpp__type_description__Field __attribute__((deprecated))
#else
# define DEPRECATED__rosidl_runtime_cpp__type_description__Field __declspec(deprecated)
#endif

namespace rosidl_runtime_cpp
{

namespace type_description
{

// message struct
template<class ContainerAllocator>
struct Field_
{
  using Type = Field_<ContainerAllocator>;

  // Description of interface
  constexpr static const rosidl_type_hash_t TYPE_VERSION_HASH = {1, {
      0x16, 0xac, 0x44, 0xbf, 0xed, 0x90, 0xab, 0xa3,
      0x4c, 0xee, 0x4b, 0xad, 0x73, 0x6d, 0xae, 0xdc,
      0x4a, 0x08, 0xf8, 0xd1, 0x44, 0x22, 0xdb, 0xe6,
      0xf9, 0x24, 0x6f, 0xa6, 0x9f, 0xca, 0xe0, 0x03,
    }};

  // static const rosidl_runtime_cpp::type_description::TypeDescription_<ContainerAllocator> & get_type_description();

  explicit Field_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : type(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->default_value = "";
    }
  }

  explicit Field_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    type(_alloc, _init),
    default_value(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->default_value = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _type_type =
    rosidl_runtime_cpp::type_description::FieldType_<ContainerAllocator>;
  _type_type type;
  using _default_value_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _default_value_type default_value;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__type(
    const rosidl_runtime_cpp::type_description::FieldType_<ContainerAllocator> & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__default_value(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->default_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosidl_runtime_cpp::type_description::Field_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosidl_runtime_cpp::type_description::Field_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosidl_runtime_cpp::type_description::Field_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosidl_runtime_cpp::type_description::Field_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosidl_runtime_cpp::type_description::Field_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosidl_runtime_cpp::type_description::Field_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosidl_runtime_cpp::type_description::Field_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosidl_runtime_cpp::type_description::Field_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosidl_runtime_cpp::type_description::Field_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosidl_runtime_cpp::type_description::Field_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosidl_runtime_cpp__type_description__Field
    std::shared_ptr<rosidl_runtime_cpp::type_description::Field_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosidl_runtime_cpp__type_description__Field
    std::shared_ptr<rosidl_runtime_cpp::type_description::Field_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Field_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->default_value != other.default_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const Field_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Field_

// alias to use template instance with default allocator
using Field =
  rosidl_runtime_cpp::type_description::Field_<std::allocator<void>>;

template<class ContainerAllocator>
constexpr const rosidl_type_hash_t Field_<ContainerAllocator>::TYPE_VERSION_HASH;

// constant definitions

}  // namespace type_description

}  // namespace rosidl_runtime_cpp

#endif  // ROSIDL_RUNTIME_CPP__TYPE_DESCRIPTION__FIELD__STRUCT_HPP_
