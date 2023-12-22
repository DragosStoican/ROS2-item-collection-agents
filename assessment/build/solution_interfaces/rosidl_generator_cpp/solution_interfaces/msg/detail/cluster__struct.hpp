// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from solution_interfaces:msg/Cluster.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__CLUSTER__STRUCT_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__CLUSTER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__solution_interfaces__msg__Cluster __attribute__((deprecated))
#else
# define DEPRECATED__solution_interfaces__msg__Cluster __declspec(deprecated)
#endif

namespace solution_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Cluster_
{
  using Type = Cluster_<ContainerAllocator>;

  explicit Cluster_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0;
      this->y = 0;
      this->colour = "";
    }
  }

  explicit Cluster_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : colour(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0;
      this->y = 0;
      this->colour = "";
    }
  }

  // field types and members
  using _x_type =
    int16_t;
  _x_type x;
  using _y_type =
    int16_t;
  _y_type y;
  using _colour_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _colour_type colour;

  // setters for named parameter idiom
  Type & set__x(
    const int16_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const int16_t & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__colour(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->colour = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    solution_interfaces::msg::Cluster_<ContainerAllocator> *;
  using ConstRawPtr =
    const solution_interfaces::msg::Cluster_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<solution_interfaces::msg::Cluster_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<solution_interfaces::msg::Cluster_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::msg::Cluster_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::msg::Cluster_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::msg::Cluster_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::msg::Cluster_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<solution_interfaces::msg::Cluster_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<solution_interfaces::msg::Cluster_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__solution_interfaces__msg__Cluster
    std::shared_ptr<solution_interfaces::msg::Cluster_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__solution_interfaces__msg__Cluster
    std::shared_ptr<solution_interfaces::msg::Cluster_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Cluster_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->colour != other.colour) {
      return false;
    }
    return true;
  }
  bool operator!=(const Cluster_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Cluster_

// alias to use template instance with default allocator
using Cluster =
  solution_interfaces::msg::Cluster_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__CLUSTER__STRUCT_HPP_
