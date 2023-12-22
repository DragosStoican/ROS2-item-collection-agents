// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:msg/WorldItems.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEMS__BUILDER_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEMS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/msg/detail/world_items__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace msg
{

namespace builder
{

class Init_WorldItems_blue
{
public:
  explicit Init_WorldItems_blue(::solution_interfaces::msg::WorldItems & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::msg::WorldItems blue(::solution_interfaces::msg::WorldItems::_blue_type arg)
  {
    msg_.blue = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::msg::WorldItems msg_;
};

class Init_WorldItems_green
{
public:
  explicit Init_WorldItems_green(::solution_interfaces::msg::WorldItems & msg)
  : msg_(msg)
  {}
  Init_WorldItems_blue green(::solution_interfaces::msg::WorldItems::_green_type arg)
  {
    msg_.green = std::move(arg);
    return Init_WorldItems_blue(msg_);
  }

private:
  ::solution_interfaces::msg::WorldItems msg_;
};

class Init_WorldItems_red
{
public:
  Init_WorldItems_red()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WorldItems_green red(::solution_interfaces::msg::WorldItems::_red_type arg)
  {
    msg_.red = std::move(arg);
    return Init_WorldItems_green(msg_);
  }

private:
  ::solution_interfaces::msg::WorldItems msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::msg::WorldItems>()
{
  return solution_interfaces::msg::builder::Init_WorldItems_red();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEMS__BUILDER_HPP_
