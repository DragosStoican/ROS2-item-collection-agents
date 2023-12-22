// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from solution_interfaces:msg/Clusters.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__CLUSTERS__STRUCT_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__CLUSTERS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'red'
// Member 'green'
// Member 'blue'
#include "solution_interfaces/msg/detail/cluster__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__solution_interfaces__msg__Clusters __attribute__((deprecated))
#else
# define DEPRECATED__solution_interfaces__msg__Clusters __declspec(deprecated)
#endif

namespace solution_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Clusters_
{
  using Type = Clusters_<ContainerAllocator>;

  explicit Clusters_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Clusters_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _red_type =
    std::vector<solution_interfaces::msg::Cluster_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<solution_interfaces::msg::Cluster_<ContainerAllocator>>>;
  _red_type red;
  using _green_type =
    std::vector<solution_interfaces::msg::Cluster_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<solution_interfaces::msg::Cluster_<ContainerAllocator>>>;
  _green_type green;
  using _blue_type =
    std::vector<solution_interfaces::msg::Cluster_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<solution_interfaces::msg::Cluster_<ContainerAllocator>>>;
  _blue_type blue;

  // setters for named parameter idiom
  Type & set__red(
    const std::vector<solution_interfaces::msg::Cluster_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<solution_interfaces::msg::Cluster_<ContainerAllocator>>> & _arg)
  {
    this->red = _arg;
    return *this;
  }
  Type & set__green(
    const std::vector<solution_interfaces::msg::Cluster_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<solution_interfaces::msg::Cluster_<ContainerAllocator>>> & _arg)
  {
    this->green = _arg;
    return *this;
  }
  Type & set__blue(
    const std::vector<solution_interfaces::msg::Cluster_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<solution_interfaces::msg::Cluster_<ContainerAllocator>>> & _arg)
  {
    this->blue = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    solution_interfaces::msg::Clusters_<ContainerAllocator> *;
  using ConstRawPtr =
    const solution_interfaces::msg::Clusters_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<solution_interfaces::msg::Clusters_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<solution_interfaces::msg::Clusters_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::msg::Clusters_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::msg::Clusters_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::msg::Clusters_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::msg::Clusters_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<solution_interfaces::msg::Clusters_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<solution_interfaces::msg::Clusters_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__solution_interfaces__msg__Clusters
    std::shared_ptr<solution_interfaces::msg::Clusters_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__solution_interfaces__msg__Clusters
    std::shared_ptr<solution_interfaces::msg::Clusters_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Clusters_ & other) const
  {
    if (this->red != other.red) {
      return false;
    }
    if (this->green != other.green) {
      return false;
    }
    if (this->blue != other.blue) {
      return false;
    }
    return true;
  }
  bool operator!=(const Clusters_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Clusters_

// alias to use template instance with default allocator
using Clusters =
  solution_interfaces::msg::Clusters_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__CLUSTERS__STRUCT_HPP_
