// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from solution_interfaces:msg/WorldItem.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEM__TRAITS_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "solution_interfaces/msg/detail/world_item__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace solution_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const WorldItem & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: colour
  {
    out << "colour: ";
    rosidl_generator_traits::value_to_yaml(msg.colour, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WorldItem & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: colour
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "colour: ";
    rosidl_generator_traits::value_to_yaml(msg.colour, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WorldItem & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace solution_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use solution_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const solution_interfaces::msg::WorldItem & msg,
  std::ostream & out, size_t indentation = 0)
{
  solution_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use solution_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const solution_interfaces::msg::WorldItem & msg)
{
  return solution_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<solution_interfaces::msg::WorldItem>()
{
  return "solution_interfaces::msg::WorldItem";
}

template<>
inline const char * name<solution_interfaces::msg::WorldItem>()
{
  return "solution_interfaces/msg/WorldItem";
}

template<>
struct has_fixed_size<solution_interfaces::msg::WorldItem>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<solution_interfaces::msg::WorldItem>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<solution_interfaces::msg::WorldItem>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEM__TRAITS_HPP_
