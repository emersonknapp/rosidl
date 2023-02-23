// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from type_description_interfaces:msg/KeyValue.idl
// generated code does not contain a copyright notice

#ifndef ROSIDL_RUNTIME_CPP__TYPE_DESCRIPTION__KEY_VALUE__STRUCT_HPP_
#define ROSIDL_RUNTIME_CPP__TYPE_DESCRIPTION__KEY_VALUE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"
#include "rosidl_runtime_cpp/type_description/type_description__struct.hpp"


#ifndef _WIN32
# define DEPRECATED__rosidl_runtime_cpp__type_description__KeyValue __attribute__((deprecated))
#else
# define DEPRECATED__rosidl_runtime_cpp__type_description__KeyValue __declspec(deprecated)
#endif

namespace rosidl_runtime_cpp
{

namespace type_description
{

// message struct
template<class ContainerAllocator>
struct KeyValue_
{
  using Type = KeyValue_<ContainerAllocator>;

  // Description of interface
  constexpr static const rosidl_type_hash_t TYPE_VERSION_HASH = {1, {
      0x96, 0xeb, 0xe1, 0xdc, 0xdd, 0xe6, 0x55, 0x04,
      0x93, 0xad, 0xeb, 0x5f, 0xa6, 0x97, 0x73, 0x36,
      0x00, 0xb9, 0x68, 0x79, 0x2c, 0x20, 0xac, 0x18,
      0xdb, 0x60, 0x05, 0x6e, 0xb6, 0x46, 0xee, 0xad,
    }};

  // static const rosidl_runtime_cpp::type_description::TypeDescription_<ContainerAllocator> & get_type_description();

  explicit KeyValue_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = "";
      this->value = "";
    }
  }

  explicit KeyValue_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : key(_alloc),
    value(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = "";
      this->value = "";
    }
  }

  // field types and members
  using _key_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _key_type key;
  using _value_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _value_type value;

  // setters for named parameter idiom
  Type & set__key(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->key = _arg;
    return *this;
  }
  Type & set__value(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosidl_runtime_cpp::type_description::KeyValue_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosidl_runtime_cpp::type_description::KeyValue_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosidl_runtime_cpp::type_description::KeyValue_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosidl_runtime_cpp::type_description::KeyValue_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosidl_runtime_cpp::type_description::KeyValue_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosidl_runtime_cpp::type_description::KeyValue_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosidl_runtime_cpp::type_description::KeyValue_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosidl_runtime_cpp::type_description::KeyValue_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosidl_runtime_cpp::type_description::KeyValue_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosidl_runtime_cpp::type_description::KeyValue_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosidl_runtime_cpp__type_description__KeyValue
    std::shared_ptr<rosidl_runtime_cpp::type_description::KeyValue_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosidl_runtime_cpp__type_description__KeyValue
    std::shared_ptr<rosidl_runtime_cpp::type_description::KeyValue_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const KeyValue_ & other) const
  {
    if (this->key != other.key) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const KeyValue_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct KeyValue_

// alias to use template instance with default allocator
using KeyValue =
  rosidl_runtime_cpp::type_description::KeyValue_<std::allocator<void>>;

template<class ContainerAllocator>
constexpr const rosidl_type_hash_t KeyValue_<ContainerAllocator>::TYPE_VERSION_HASH;

// constant definitions

}  // namespace type_description

}  // namespace rosidl_runtime_cpp

#endif  // ROSIDL_RUNTIME_CPP__TYPE_DESCRIPTION__KEY_VALUE__STRUCT_HPP_
