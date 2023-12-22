// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from solution_interfaces:msg/WorldItems.idl
// generated code does not contain a copyright notice
#include "solution_interfaces/msg/detail/world_items__rosidl_typesupport_fastrtps_cpp.hpp"
#include "solution_interfaces/msg/detail/world_items__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace solution_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const solution_interfaces::msg::WorldItem &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  solution_interfaces::msg::WorldItem &);
size_t get_serialized_size(
  const solution_interfaces::msg::WorldItem &,
  size_t current_alignment);
size_t
max_serialized_size_WorldItem(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace solution_interfaces

// functions for solution_interfaces::msg::WorldItem already declared above

// functions for solution_interfaces::msg::WorldItem already declared above


namespace solution_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_solution_interfaces
cdr_serialize(
  const solution_interfaces::msg::WorldItems & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: red
  {
    size_t size = ros_message.red.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      solution_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.red[i],
        cdr);
    }
  }
  // Member: green
  {
    size_t size = ros_message.green.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      solution_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.green[i],
        cdr);
    }
  }
  // Member: blue
  {
    size_t size = ros_message.blue.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      solution_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.blue[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_solution_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  solution_interfaces::msg::WorldItems & ros_message)
{
  // Member: red
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.red.resize(size);
    for (size_t i = 0; i < size; i++) {
      solution_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.red[i]);
    }
  }

  // Member: green
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.green.resize(size);
    for (size_t i = 0; i < size; i++) {
      solution_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.green[i]);
    }
  }

  // Member: blue
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.blue.resize(size);
    for (size_t i = 0; i < size; i++) {
      solution_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.blue[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_solution_interfaces
get_serialized_size(
  const solution_interfaces::msg::WorldItems & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: red
  {
    size_t array_size = ros_message.red.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        solution_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.red[index], current_alignment);
    }
  }
  // Member: green
  {
    size_t array_size = ros_message.green.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        solution_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.green[index], current_alignment);
    }
  }
  // Member: blue
  {
    size_t array_size = ros_message.blue.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        solution_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.blue[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_solution_interfaces
max_serialized_size_WorldItems(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: red
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        solution_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_WorldItem(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: green
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        solution_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_WorldItem(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: blue
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        solution_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_WorldItem(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = solution_interfaces::msg::WorldItems;
    is_plain =
      (
      offsetof(DataType, blue) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _WorldItems__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const solution_interfaces::msg::WorldItems *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _WorldItems__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<solution_interfaces::msg::WorldItems *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _WorldItems__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const solution_interfaces::msg::WorldItems *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _WorldItems__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_WorldItems(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _WorldItems__callbacks = {
  "solution_interfaces::msg",
  "WorldItems",
  _WorldItems__cdr_serialize,
  _WorldItems__cdr_deserialize,
  _WorldItems__get_serialized_size,
  _WorldItems__max_serialized_size
};

static rosidl_message_type_support_t _WorldItems__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_WorldItems__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace solution_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_solution_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<solution_interfaces::msg::WorldItems>()
{
  return &solution_interfaces::msg::typesupport_fastrtps_cpp::_WorldItems__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, solution_interfaces, msg, WorldItems)() {
  return &solution_interfaces::msg::typesupport_fastrtps_cpp::_WorldItems__handle;
}

#ifdef __cplusplus
}
#endif
