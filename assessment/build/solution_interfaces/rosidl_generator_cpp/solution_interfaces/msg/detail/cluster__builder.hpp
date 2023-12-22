// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:msg/Cluster.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__CLUSTER__BUILDER_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__CLUSTER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/msg/detail/cluster__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace msg
{

namespace builder
{

class Init_Cluster_colour
{
public:
  explicit Init_Cluster_colour(::solution_interfaces::msg::Cluster & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::msg::Cluster colour(::solution_interfaces::msg::Cluster::_colour_type arg)
  {
    msg_.colour = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::msg::Cluster msg_;
};

class Init_Cluster_y
{
public:
  explicit Init_Cluster_y(::solution_interfaces::msg::Cluster & msg)
  : msg_(msg)
  {}
  Init_Cluster_colour y(::solution_interfaces::msg::Cluster::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Cluster_colour(msg_);
  }

private:
  ::solution_interfaces::msg::Cluster msg_;
};

class Init_Cluster_x
{
public:
  Init_Cluster_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Cluster_y x(::solution_interfaces::msg::Cluster::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Cluster_y(msg_);
  }

private:
  ::solution_interfaces::msg::Cluster msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::msg::Cluster>()
{
  return solution_interfaces::msg::builder::Init_Cluster_x();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__CLUSTER__BUILDER_HPP_
