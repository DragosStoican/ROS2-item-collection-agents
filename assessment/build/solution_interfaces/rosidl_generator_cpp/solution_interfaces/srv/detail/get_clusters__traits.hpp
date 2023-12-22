// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from solution_interfaces:srv/GetClusters.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__SRV__DETAIL__GET_CLUSTERS__TRAITS_HPP_
#define SOLUTION_INTERFACES__SRV__DETAIL__GET_CLUSTERS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "solution_interfaces/srv/detail/get_clusters__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace solution_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetClusters_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetClusters_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetClusters_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace solution_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use solution_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const solution_interfaces::srv::GetClusters_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  solution_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use solution_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const solution_interfaces::srv::GetClusters_Request & msg)
{
  return solution_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<solution_interfaces::srv::GetClusters_Request>()
{
  return "solution_interfaces::srv::GetClusters_Request";
}

template<>
inline const char * name<solution_interfaces::srv::GetClusters_Request>()
{
  return "solution_interfaces/srv/GetClusters_Request";
}

template<>
struct has_fixed_size<solution_interfaces::srv::GetClusters_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<solution_interfaces::srv::GetClusters_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<solution_interfaces::srv::GetClusters_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'clusters'
#include "solution_interfaces/msg/detail/world_item__traits.hpp"

namespace solution_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetClusters_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: clusters
  {
    if (msg.clusters.size() == 0) {
      out << "clusters: []";
    } else {
      out << "clusters: [";
      size_t pending_items = msg.clusters.size();
      for (auto item : msg.clusters) {
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
  const GetClusters_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: clusters
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.clusters.size() == 0) {
      out << "clusters: []\n";
    } else {
      out << "clusters:\n";
      for (auto item : msg.clusters) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetClusters_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace solution_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use solution_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const solution_interfaces::srv::GetClusters_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  solution_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use solution_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const solution_interfaces::srv::GetClusters_Response & msg)
{
  return solution_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<solution_interfaces::srv::GetClusters_Response>()
{
  return "solution_interfaces::srv::GetClusters_Response";
}

template<>
inline const char * name<solution_interfaces::srv::GetClusters_Response>()
{
  return "solution_interfaces/srv/GetClusters_Response";
}

template<>
struct has_fixed_size<solution_interfaces::srv::GetClusters_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<solution_interfaces::srv::GetClusters_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<solution_interfaces::srv::GetClusters_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<solution_interfaces::srv::GetClusters>()
{
  return "solution_interfaces::srv::GetClusters";
}

template<>
inline const char * name<solution_interfaces::srv::GetClusters>()
{
  return "solution_interfaces/srv/GetClusters";
}

template<>
struct has_fixed_size<solution_interfaces::srv::GetClusters>
  : std::integral_constant<
    bool,
    has_fixed_size<solution_interfaces::srv::GetClusters_Request>::value &&
    has_fixed_size<solution_interfaces::srv::GetClusters_Response>::value
  >
{
};

template<>
struct has_bounded_size<solution_interfaces::srv::GetClusters>
  : std::integral_constant<
    bool,
    has_bounded_size<solution_interfaces::srv::GetClusters_Request>::value &&
    has_bounded_size<solution_interfaces::srv::GetClusters_Response>::value
  >
{
};

template<>
struct is_service<solution_interfaces::srv::GetClusters>
  : std::true_type
{
};

template<>
struct is_service_request<solution_interfaces::srv::GetClusters_Request>
  : std::true_type
{
};

template<>
struct is_service_response<solution_interfaces::srv::GetClusters_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SOLUTION_INTERFACES__SRV__DETAIL__GET_CLUSTERS__TRAITS_HPP_
