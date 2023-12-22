// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from solution_interfaces:msg/WorldItems.idl
// generated code does not contain a copyright notice
#include "solution_interfaces/msg/detail/world_items__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "solution_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "solution_interfaces/msg/detail/world_items__struct.h"
#include "solution_interfaces/msg/detail/world_items__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "solution_interfaces/msg/detail/world_item__functions.h"  // blue, green, red

// forward declare type support functions
size_t get_serialized_size_solution_interfaces__msg__WorldItem(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_solution_interfaces__msg__WorldItem(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, solution_interfaces, msg, WorldItem)();


using _WorldItems__ros_msg_type = solution_interfaces__msg__WorldItems;

static bool _WorldItems__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _WorldItems__ros_msg_type * ros_message = static_cast<const _WorldItems__ros_msg_type *>(untyped_ros_message);
  // Field name: red
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, solution_interfaces, msg, WorldItem
      )()->data);
    size_t size = ros_message->red.size;
    auto array_ptr = ros_message->red.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: green
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, solution_interfaces, msg, WorldItem
      )()->data);
    size_t size = ros_message->green.size;
    auto array_ptr = ros_message->green.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: blue
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, solution_interfaces, msg, WorldItem
      )()->data);
    size_t size = ros_message->blue.size;
    auto array_ptr = ros_message->blue.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _WorldItems__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _WorldItems__ros_msg_type * ros_message = static_cast<_WorldItems__ros_msg_type *>(untyped_ros_message);
  // Field name: red
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, solution_interfaces, msg, WorldItem
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->red.data) {
      solution_interfaces__msg__WorldItem__Sequence__fini(&ros_message->red);
    }
    if (!solution_interfaces__msg__WorldItem__Sequence__init(&ros_message->red, size)) {
      fprintf(stderr, "failed to create array for field 'red'");
      return false;
    }
    auto array_ptr = ros_message->red.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: green
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, solution_interfaces, msg, WorldItem
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->green.data) {
      solution_interfaces__msg__WorldItem__Sequence__fini(&ros_message->green);
    }
    if (!solution_interfaces__msg__WorldItem__Sequence__init(&ros_message->green, size)) {
      fprintf(stderr, "failed to create array for field 'green'");
      return false;
    }
    auto array_ptr = ros_message->green.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: blue
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, solution_interfaces, msg, WorldItem
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->blue.data) {
      solution_interfaces__msg__WorldItem__Sequence__fini(&ros_message->blue);
    }
    if (!solution_interfaces__msg__WorldItem__Sequence__init(&ros_message->blue, size)) {
      fprintf(stderr, "failed to create array for field 'blue'");
      return false;
    }
    auto array_ptr = ros_message->blue.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_solution_interfaces
size_t get_serialized_size_solution_interfaces__msg__WorldItems(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _WorldItems__ros_msg_type * ros_message = static_cast<const _WorldItems__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name red
  {
    size_t array_size = ros_message->red.size;
    auto array_ptr = ros_message->red.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_solution_interfaces__msg__WorldItem(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name green
  {
    size_t array_size = ros_message->green.size;
    auto array_ptr = ros_message->green.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_solution_interfaces__msg__WorldItem(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name blue
  {
    size_t array_size = ros_message->blue.size;
    auto array_ptr = ros_message->blue.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_solution_interfaces__msg__WorldItem(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _WorldItems__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_solution_interfaces__msg__WorldItems(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_solution_interfaces
size_t max_serialized_size_solution_interfaces__msg__WorldItems(
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

  // member: red
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
      size_t inner_size;
      inner_size =
        max_serialized_size_solution_interfaces__msg__WorldItem(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: green
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
      size_t inner_size;
      inner_size =
        max_serialized_size_solution_interfaces__msg__WorldItem(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: blue
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
      size_t inner_size;
      inner_size =
        max_serialized_size_solution_interfaces__msg__WorldItem(
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
    using DataType = solution_interfaces__msg__WorldItems;
    is_plain =
      (
      offsetof(DataType, blue) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _WorldItems__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_solution_interfaces__msg__WorldItems(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_WorldItems = {
  "solution_interfaces::msg",
  "WorldItems",
  _WorldItems__cdr_serialize,
  _WorldItems__cdr_deserialize,
  _WorldItems__get_serialized_size,
  _WorldItems__max_serialized_size
};

static rosidl_message_type_support_t _WorldItems__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_WorldItems,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, solution_interfaces, msg, WorldItems)() {
  return &_WorldItems__type_support;
}

#if defined(__cplusplus)
}
#endif
