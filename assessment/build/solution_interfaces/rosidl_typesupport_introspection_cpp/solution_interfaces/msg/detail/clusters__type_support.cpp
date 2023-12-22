// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from solution_interfaces:msg/Clusters.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "solution_interfaces/msg/detail/clusters__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace solution_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Clusters_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) solution_interfaces::msg::Clusters(_init);
}

void Clusters_fini_function(void * message_memory)
{
  auto typed_message = static_cast<solution_interfaces::msg::Clusters *>(message_memory);
  typed_message->~Clusters();
}

size_t size_function__Clusters__red(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<solution_interfaces::msg::Cluster> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Clusters__red(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<solution_interfaces::msg::Cluster> *>(untyped_member);
  return &member[index];
}

void * get_function__Clusters__red(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<solution_interfaces::msg::Cluster> *>(untyped_member);
  return &member[index];
}

void fetch_function__Clusters__red(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const solution_interfaces::msg::Cluster *>(
    get_const_function__Clusters__red(untyped_member, index));
  auto & value = *reinterpret_cast<solution_interfaces::msg::Cluster *>(untyped_value);
  value = item;
}

void assign_function__Clusters__red(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<solution_interfaces::msg::Cluster *>(
    get_function__Clusters__red(untyped_member, index));
  const auto & value = *reinterpret_cast<const solution_interfaces::msg::Cluster *>(untyped_value);
  item = value;
}

void resize_function__Clusters__red(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<solution_interfaces::msg::Cluster> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Clusters__green(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<solution_interfaces::msg::Cluster> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Clusters__green(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<solution_interfaces::msg::Cluster> *>(untyped_member);
  return &member[index];
}

void * get_function__Clusters__green(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<solution_interfaces::msg::Cluster> *>(untyped_member);
  return &member[index];
}

void fetch_function__Clusters__green(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const solution_interfaces::msg::Cluster *>(
    get_const_function__Clusters__green(untyped_member, index));
  auto & value = *reinterpret_cast<solution_interfaces::msg::Cluster *>(untyped_value);
  value = item;
}

void assign_function__Clusters__green(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<solution_interfaces::msg::Cluster *>(
    get_function__Clusters__green(untyped_member, index));
  const auto & value = *reinterpret_cast<const solution_interfaces::msg::Cluster *>(untyped_value);
  item = value;
}

void resize_function__Clusters__green(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<solution_interfaces::msg::Cluster> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Clusters__blue(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<solution_interfaces::msg::Cluster> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Clusters__blue(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<solution_interfaces::msg::Cluster> *>(untyped_member);
  return &member[index];
}

void * get_function__Clusters__blue(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<solution_interfaces::msg::Cluster> *>(untyped_member);
  return &member[index];
}

void fetch_function__Clusters__blue(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const solution_interfaces::msg::Cluster *>(
    get_const_function__Clusters__blue(untyped_member, index));
  auto & value = *reinterpret_cast<solution_interfaces::msg::Cluster *>(untyped_value);
  value = item;
}

void assign_function__Clusters__blue(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<solution_interfaces::msg::Cluster *>(
    get_function__Clusters__blue(untyped_member, index));
  const auto & value = *reinterpret_cast<const solution_interfaces::msg::Cluster *>(untyped_value);
  item = value;
}

void resize_function__Clusters__blue(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<solution_interfaces::msg::Cluster> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Clusters_message_member_array[3] = {
  {
    "red",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<solution_interfaces::msg::Cluster>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(solution_interfaces::msg::Clusters, red),  // bytes offset in struct
    nullptr,  // default value
    size_function__Clusters__red,  // size() function pointer
    get_const_function__Clusters__red,  // get_const(index) function pointer
    get_function__Clusters__red,  // get(index) function pointer
    fetch_function__Clusters__red,  // fetch(index, &value) function pointer
    assign_function__Clusters__red,  // assign(index, value) function pointer
    resize_function__Clusters__red  // resize(index) function pointer
  },
  {
    "green",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<solution_interfaces::msg::Cluster>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(solution_interfaces::msg::Clusters, green),  // bytes offset in struct
    nullptr,  // default value
    size_function__Clusters__green,  // size() function pointer
    get_const_function__Clusters__green,  // get_const(index) function pointer
    get_function__Clusters__green,  // get(index) function pointer
    fetch_function__Clusters__green,  // fetch(index, &value) function pointer
    assign_function__Clusters__green,  // assign(index, value) function pointer
    resize_function__Clusters__green  // resize(index) function pointer
  },
  {
    "blue",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<solution_interfaces::msg::Cluster>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(solution_interfaces::msg::Clusters, blue),  // bytes offset in struct
    nullptr,  // default value
    size_function__Clusters__blue,  // size() function pointer
    get_const_function__Clusters__blue,  // get_const(index) function pointer
    get_function__Clusters__blue,  // get(index) function pointer
    fetch_function__Clusters__blue,  // fetch(index, &value) function pointer
    assign_function__Clusters__blue,  // assign(index, value) function pointer
    resize_function__Clusters__blue  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Clusters_message_members = {
  "solution_interfaces::msg",  // message namespace
  "Clusters",  // message name
  3,  // number of fields
  sizeof(solution_interfaces::msg::Clusters),
  Clusters_message_member_array,  // message members
  Clusters_init_function,  // function to initialize message memory (memory has to be allocated)
  Clusters_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Clusters_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Clusters_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace solution_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<solution_interfaces::msg::Clusters>()
{
  return &::solution_interfaces::msg::rosidl_typesupport_introspection_cpp::Clusters_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, solution_interfaces, msg, Clusters)() {
  return &::solution_interfaces::msg::rosidl_typesupport_introspection_cpp::Clusters_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
