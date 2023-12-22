// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from solution_interfaces:msg/Clusters.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__CLUSTERS__TRAITS_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__CLUSTERS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "solution_interfaces/msg/detail/clusters__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'red'
// Member 'green'
// Member 'blue'
#include "solution_interfaces/msg/detail/cluster__traits.hpp"

namespace solution_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Clusters & msg,
  std::ostream & out)
{
  out << "{";
  // member: red
  {
    if (msg.red.size() == 0) {
      out << "red: []";
    } else {
      out << "red: [";
      size_t pending_items = msg.red.size();
      for (auto item : msg.red) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: green
  {
    if (msg.green.size() == 0) {
      out << "green: []";
    } else {
      out << "green: [";
      size_t pending_items = msg.green.size();
      for (auto item : msg.green) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: blue
  {
    if (msg.blue.size() == 0) {
      out << "blue: []";
    } else {
      out << "blue: [";
      size_t pending_items = msg.blue.size();
      for (auto item : msg.blue) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Clusters & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: red
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.red.size() == 0) {
      out << "red: []\n";
    } else {
      out << "red:\n";
      for (auto item : msg.red) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: green
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.green.size() == 0) {
      out << "green: []\n";
    } else {
      out << "green:\n";
      for (auto item : msg.green) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: blue
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.blue.size() == 0) {
      out << "blue: []\n";
    } else {
      out << "blue:\n";
      for (auto item : msg.blue) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Clusters & msg, bool use_flow_style = false)
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
  const solution_interfaces::msg::Clusters & msg,
  std::ostream & out, size_t indentation = 0)
{
  solution_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use solution_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const solution_interfaces::msg::Clusters & msg)
{
  return solution_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<solution_interfaces::msg::Clusters>()
{
  return "solution_interfaces::msg::Clusters";
}

template<>
inline const char * name<solution_interfaces::msg::Clusters>()
{
  return "solution_interfaces/msg/Clusters";
}

template<>
struct has_fixed_size<solution_interfaces::msg::Clusters>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<solution_interfaces::msg::Clusters>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<solution_interfaces::msg::Clusters>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__CLUSTERS__TRAITS_HPP_
