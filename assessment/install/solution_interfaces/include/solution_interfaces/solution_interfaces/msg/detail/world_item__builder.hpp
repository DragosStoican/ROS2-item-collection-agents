// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:msg/WorldItem.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEM__BUILDER_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/msg/detail/world_item__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace msg
{

namespace builder
{

class Init_WorldItem_colour
{
public:
  explicit Init_WorldItem_colour(::solution_interfaces::msg::WorldItem & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::msg::WorldItem colour(::solution_interfaces::msg::WorldItem::_colour_type arg)
  {
    msg_.colour = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::msg::WorldItem msg_;
};

class Init_WorldItem_y
{
public:
  explicit Init_WorldItem_y(::solution_interfaces::msg::WorldItem & msg)
  : msg_(msg)
  {}
  Init_WorldItem_colour y(::solution_interfaces::msg::WorldItem::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_WorldItem_colour(msg_);
  }

private:
  ::solution_interfaces::msg::WorldItem msg_;
};

class Init_WorldItem_x
{
public:
  Init_WorldItem_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WorldItem_y x(::solution_interfaces::msg::WorldItem::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_WorldItem_y(msg_);
  }

private:
  ::solution_interfaces::msg::WorldItem msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::msg::WorldItem>()
{
  return solution_interfaces::msg::builder::Init_WorldItem_x();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEM__BUILDER_HPP_
