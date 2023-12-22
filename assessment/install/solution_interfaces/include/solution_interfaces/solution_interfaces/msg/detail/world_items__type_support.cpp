// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from solution_interfaces:msg/WorldItems.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "solution_interfaces/msg/detail/world_items__struct.hpp"
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

void WorldItems_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) solution_interfaces::msg::WorldItems(_init);
}

void WorldItems_fini_function(void * message_memory)
{
  auto typed_message = static_cast<solution_interfaces::msg::WorldItems *>(message_memory);
  typed_message->~WorldItems();
}

size_t size_function__WorldItems__red(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<solution_interfaces::msg::WorldItem> *>(untyped_member);
  return member->size();
}

const void * get_const_function__WorldItems__red(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<solution_interfaces::msg::WorldItem> *>(untyped_member);
  return &member[index];
}

void * get_function__WorldItems__red(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<solution_interfaces::msg::WorldItem> *>(untyped_member);
  return &member[index];
}

void fetch_function__WorldItems__red(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const solution_interfaces::msg::WorldItem *>(
    get_const_function__WorldItems__red(untyped_member, index));
  auto & value = *reinterpret_cast<solution_interfaces::msg::WorldItem *>(untyped_value);
  value = item;
}

void assign_function__WorldItems__red(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<solution_interfaces::msg::WorldItem *>(
    get_function__WorldItems__red(untyped_member, index));
  const auto & value = *reinterpret_cast<const solution_interfaces::msg::WorldItem *>(untyped_value);
  item = value;
}

void resize_function__WorldItems__red(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<solution_interfaces::msg::WorldItem> *>(untyped_member);
  member->resize(size);
}

size_t size_function__WorldItems__green(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<solution_interfaces::msg::WorldItem> *>(untyped_member);
  return member->size();
}

const void * get_const_function__WorldItems__green(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<solution_interfaces::msg::WorldItem> *>(untyped_member);
  return &member[index];
}

void * get_function__WorldItems__green(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<solution_interfaces::msg::WorldItem> *>(untyped_member);
  return &member[index];
}

void fetch_function__WorldItems__green(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const solution_interfaces::msg::WorldItem *>(
    get_const_function__WorldItems__green(untyped_member, index));
  auto & value = *reinterpret_cast<solution_interfaces::msg::WorldItem *>(untyped_value);
  value = item;
}

void assign_function__WorldItems__green(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<solution_interfaces::msg::WorldItem *>(
    get_function__WorldItems__green(untyped_member, index));
  const auto & value = *reinterpret_cast<const solution_interfaces::msg::WorldItem *>(untyped_value);
  item = value;
}

void resize_function__WorldItems__green(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<solution_interfaces::msg::WorldItem> *>(untyped_member);
  member->resize(size);
}

size_t size_function__WorldItems__blue(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<solution_interfaces::msg::WorldItem> *>(untyped_member);
  return member->size();
}

const void * get_const_function__WorldItems__blue(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<solution_interfaces::msg::WorldItem> *>(untyped_member);
  return &member[index];
}

void * get_function__WorldItems__blue(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<solution_interfaces::msg::WorldItem> *>(untyped_member);
  return &member[index];
}

void fetch_function__WorldItems__blue(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const solution_interfaces::msg::WorldItem *>(
    get_const_function__WorldItems__blue(untyped_member, index));
  auto & value = *reinterpret_cast<solution_interfaces::msg::WorldItem *>(untyped_value);
  value = item;
}

void assign_function__WorldItems__blue(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<solution_interfaces::msg::WorldItem *>(
    get_function__WorldItems__blue(untyped_member, index));
  const auto & value = *reinterpret_cast<const solution_interfaces::msg::WorldItem *>(untyped_value);
  item = value;
}

void resize_function__WorldItems__blue(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<solution_interfaces::msg::WorldItem> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember WorldItems_message_member_array[3] = {
  {
    "red",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<solution_interfaces::msg::WorldItem>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(solution_interfaces::msg::WorldItems, red),  // bytes offset in struct
    nullptr,  // default value
    size_function__WorldItems__red,  // size() function pointer
    get_const_function__WorldItems__red,  // get_const(index) function pointer
    get_function__WorldItems__red,  // get(index) function pointer
    fetch_function__WorldItems__red,  // fetch(index, &value) function pointer
    assign_function__WorldItems__red,  // assign(index, value) function pointer
    resize_function__WorldItems__red  // resize(index) function pointer
  },
  {
    "green",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<solution_interfaces::msg::WorldItem>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(solution_interfaces::msg::WorldItems, green),  // bytes offset in struct
    nullptr,  // default value
    size_function__WorldItems__green,  // size() function pointer
    get_const_function__WorldItems__green,  // get_const(index) function pointer
    get_function__WorldItems__green,  // get(index) function pointer
    fetch_function__WorldItems__green,  // fetch(index, &value) function pointer
    assign_function__WorldItems__green,  // assign(index, value) function pointer
    resize_function__WorldItems__green  // resize(index) function pointer
  },
  {
    "blue",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<solution_interfaces::msg::WorldItem>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(solution_interfaces::msg::WorldItems, blue),  // bytes offset in struct
    nullptr,  // default value
    size_function__WorldItems__blue,  // size() function pointer
    get_const_function__WorldItems__blue,  // get_const(index) function pointer
    get_function__WorldItems__blue,  // get(index) function pointer
    fetch_function__WorldItems__blue,  // fetch(index, &value) function pointer
    assign_function__WorldItems__blue,  // assign(index, value) function pointer
    resize_function__WorldItems__blue  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers WorldItems_message_members = {
  "solution_interfaces::msg",  // message namespace
  "WorldItems",  // message name
  3,  // number of fields
  sizeof(solution_interfaces::msg::WorldItems),
  WorldItems_message_member_array,  // message members
  WorldItems_init_function,  // function to initialize message memory (memory has to be allocated)
  WorldItems_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t WorldItems_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &WorldItems_message_members,
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
get_message_type_support_handle<solution_interfaces::msg::WorldItems>()
{
  return &::solution_interfaces::msg::rosidl_typesupport_introspection_cpp::WorldItems_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, solution_interfaces, msg, WorldItems)() {
  return &::solution_interfaces::msg::rosidl_typesupport_introspection_cpp::WorldItems_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
