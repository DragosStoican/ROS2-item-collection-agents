// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:msg/Clusters.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__CLUSTERS__BUILDER_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__CLUSTERS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/msg/detail/clusters__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace msg
{

namespace builder
{

class Init_Clusters_blue
{
public:
  explicit Init_Clusters_blue(::solution_interfaces::msg::Clusters & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::msg::Clusters blue(::solution_interfaces::msg::Clusters::_blue_type arg)
  {
    msg_.blue = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::msg::Clusters msg_;
};

class Init_Clusters_green
{
public:
  explicit Init_Clusters_green(::solution_interfaces::msg::Clusters & msg)
  : msg_(msg)
  {}
  Init_Clusters_blue green(::solution_interfaces::msg::Clusters::_green_type arg)
  {
    msg_.green = std::move(arg);
    return Init_Clusters_blue(msg_);
  }

private:
  ::solution_interfaces::msg::Clusters msg_;
};

class Init_Clusters_red
{
public:
  Init_Clusters_red()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Clusters_green red(::solution_interfaces::msg::Clusters::_red_type arg)
  {
    msg_.red = std::move(arg);
    return Init_Clusters_green(msg_);
  }

private:
  ::solution_interfaces::msg::Clusters msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::msg::Clusters>()
{
  return solution_interfaces::msg::builder::Init_Clusters_red();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__CLUSTERS__BUILDER_HPP_
