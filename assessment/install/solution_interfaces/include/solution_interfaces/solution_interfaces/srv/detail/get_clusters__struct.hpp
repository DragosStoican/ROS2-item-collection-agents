// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from solution_interfaces:srv/GetClusters.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__SRV__DETAIL__GET_CLUSTERS__STRUCT_HPP_
#define SOLUTION_INTERFACES__SRV__DETAIL__GET_CLUSTERS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__solution_interfaces__srv__GetClusters_Request __attribute__((deprecated))
#else
# define DEPRECATED__solution_interfaces__srv__GetClusters_Request __declspec(deprecated)
#endif

namespace solution_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetClusters_Request_
{
  using Type = GetClusters_Request_<ContainerAllocator>;

  explicit GetClusters_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetClusters_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    solution_interfaces::srv::GetClusters_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const solution_interfaces::srv::GetClusters_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<solution_interfaces::srv::GetClusters_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<solution_interfaces::srv::GetClusters_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::srv::GetClusters_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::srv::GetClusters_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::srv::GetClusters_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::srv::GetClusters_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<solution_interfaces::srv::GetClusters_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<solution_interfaces::srv::GetClusters_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__solution_interfaces__srv__GetClusters_Request
    std::shared_ptr<solution_interfaces::srv::GetClusters_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__solution_interfaces__srv__GetClusters_Request
    std::shared_ptr<solution_interfaces::srv::GetClusters_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetClusters_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetClusters_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetClusters_Request_

// alias to use template instance with default allocator
using GetClusters_Request =
  solution_interfaces::srv::GetClusters_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace solution_interfaces


// Include directives for member types
// Member 'clusters'
#include "solution_interfaces/msg/detail/world_item__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__solution_interfaces__srv__GetClusters_Response __attribute__((deprecated))
#else
# define DEPRECATED__solution_interfaces__srv__GetClusters_Response __declspec(deprecated)
#endif

namespace solution_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetClusters_Response_
{
  using Type = GetClusters_Response_<ContainerAllocator>;

  explicit GetClusters_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit GetClusters_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _clusters_type =
    std::vector<solution_interfaces::msg::WorldItem_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<solution_interfaces::msg::WorldItem_<ContainerAllocator>>>;
  _clusters_type clusters;

  // setters for named parameter idiom
  Type & set__clusters(
    const std::vector<solution_interfaces::msg::WorldItem_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<solution_interfaces::msg::WorldItem_<ContainerAllocator>>> & _arg)
  {
    this->clusters = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    solution_interfaces::srv::GetClusters_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const solution_interfaces::srv::GetClusters_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<solution_interfaces::srv::GetClusters_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<solution_interfaces::srv::GetClusters_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::srv::GetClusters_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::srv::GetClusters_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::srv::GetClusters_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::srv::GetClusters_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<solution_interfaces::srv::GetClusters_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<solution_interfaces::srv::GetClusters_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__solution_interfaces__srv__GetClusters_Response
    std::shared_ptr<solution_interfaces::srv::GetClusters_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__solution_interfaces__srv__GetClusters_Response
    std::shared_ptr<solution_interfaces::srv::GetClusters_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetClusters_Response_ & other) const
  {
    if (this->clusters != other.clusters) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetClusters_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetClusters_Response_

// alias to use template instance with default allocator
using GetClusters_Response =
  solution_interfaces::srv::GetClusters_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace solution_interfaces

namespace solution_interfaces
{

namespace srv
{

struct GetClusters
{
  using Request = solution_interfaces::srv::GetClusters_Request;
  using Response = solution_interfaces::srv::GetClusters_Response;
};

}  // namespace srv

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__SRV__DETAIL__GET_CLUSTERS__STRUCT_HPP_
