// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:srv/GetClusters.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__SRV__DETAIL__GET_CLUSTERS__BUILDER_HPP_
#define SOLUTION_INTERFACES__SRV__DETAIL__GET_CLUSTERS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/srv/detail/get_clusters__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::srv::GetClusters_Request>()
{
  return ::solution_interfaces::srv::GetClusters_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace solution_interfaces


namespace solution_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetClusters_Response_clusters
{
public:
  Init_GetClusters_Response_clusters()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::solution_interfaces::srv::GetClusters_Response clusters(::solution_interfaces::srv::GetClusters_Response::_clusters_type arg)
  {
    msg_.clusters = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::srv::GetClusters_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::srv::GetClusters_Response>()
{
  return solution_interfaces::srv::builder::Init_GetClusters_Response_clusters();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__SRV__DETAIL__GET_CLUSTERS__BUILDER_HPP_
