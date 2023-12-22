// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from solution_interfaces:msg/WorldItems.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "solution_interfaces/msg/detail/world_items__rosidl_typesupport_introspection_c.h"
#include "solution_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "solution_interfaces/msg/detail/world_items__functions.h"
#include "solution_interfaces/msg/detail/world_items__struct.h"


// Include directives for member types
// Member `red`
// Member `green`
// Member `blue`
#include "solution_interfaces/msg/world_item.h"
// Member `red`
// Member `green`
// Member `blue`
#include "solution_interfaces/msg/detail/world_item__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  solution_interfaces__msg__WorldItems__init(message_memory);
}

void solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_fini_function(void * message_memory)
{
  solution_interfaces__msg__WorldItems__fini(message_memory);
}

size_t solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__size_function__WorldItems__red(
  const void * untyped_member)
{
  const solution_interfaces__msg__WorldItem__Sequence * member =
    (const solution_interfaces__msg__WorldItem__Sequence *)(untyped_member);
  return member->size;
}

const void * solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_const_function__WorldItems__red(
  const void * untyped_member, size_t index)
{
  const solution_interfaces__msg__WorldItem__Sequence * member =
    (const solution_interfaces__msg__WorldItem__Sequence *)(untyped_member);
  return &member->data[index];
}

void * solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_function__WorldItems__red(
  void * untyped_member, size_t index)
{
  solution_interfaces__msg__WorldItem__Sequence * member =
    (solution_interfaces__msg__WorldItem__Sequence *)(untyped_member);
  return &member->data[index];
}

void solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__fetch_function__WorldItems__red(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const solution_interfaces__msg__WorldItem * item =
    ((const solution_interfaces__msg__WorldItem *)
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_const_function__WorldItems__red(untyped_member, index));
  solution_interfaces__msg__WorldItem * value =
    (solution_interfaces__msg__WorldItem *)(untyped_value);
  *value = *item;
}

void solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__assign_function__WorldItems__red(
  void * untyped_member, size_t index, const void * untyped_value)
{
  solution_interfaces__msg__WorldItem * item =
    ((solution_interfaces__msg__WorldItem *)
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_function__WorldItems__red(untyped_member, index));
  const solution_interfaces__msg__WorldItem * value =
    (const solution_interfaces__msg__WorldItem *)(untyped_value);
  *item = *value;
}

bool solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__resize_function__WorldItems__red(
  void * untyped_member, size_t size)
{
  solution_interfaces__msg__WorldItem__Sequence * member =
    (solution_interfaces__msg__WorldItem__Sequence *)(untyped_member);
  solution_interfaces__msg__WorldItem__Sequence__fini(member);
  return solution_interfaces__msg__WorldItem__Sequence__init(member, size);
}

size_t solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__size_function__WorldItems__green(
  const void * untyped_member)
{
  const solution_interfaces__msg__WorldItem__Sequence * member =
    (const solution_interfaces__msg__WorldItem__Sequence *)(untyped_member);
  return member->size;
}

const void * solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_const_function__WorldItems__green(
  const void * untyped_member, size_t index)
{
  const solution_interfaces__msg__WorldItem__Sequence * member =
    (const solution_interfaces__msg__WorldItem__Sequence *)(untyped_member);
  return &member->data[index];
}

void * solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_function__WorldItems__green(
  void * untyped_member, size_t index)
{
  solution_interfaces__msg__WorldItem__Sequence * member =
    (solution_interfaces__msg__WorldItem__Sequence *)(untyped_member);
  return &member->data[index];
}

void solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__fetch_function__WorldItems__green(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const solution_interfaces__msg__WorldItem * item =
    ((const solution_interfaces__msg__WorldItem *)
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_const_function__WorldItems__green(untyped_member, index));
  solution_interfaces__msg__WorldItem * value =
    (solution_interfaces__msg__WorldItem *)(untyped_value);
  *value = *item;
}

void solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__assign_function__WorldItems__green(
  void * untyped_member, size_t index, const void * untyped_value)
{
  solution_interfaces__msg__WorldItem * item =
    ((solution_interfaces__msg__WorldItem *)
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_function__WorldItems__green(untyped_member, index));
  const solution_interfaces__msg__WorldItem * value =
    (const solution_interfaces__msg__WorldItem *)(untyped_value);
  *item = *value;
}

bool solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__resize_function__WorldItems__green(
  void * untyped_member, size_t size)
{
  solution_interfaces__msg__WorldItem__Sequence * member =
    (solution_interfaces__msg__WorldItem__Sequence *)(untyped_member);
  solution_interfaces__msg__WorldItem__Sequence__fini(member);
  return solution_interfaces__msg__WorldItem__Sequence__init(member, size);
}

size_t solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__size_function__WorldItems__blue(
  const void * untyped_member)
{
  const solution_interfaces__msg__WorldItem__Sequence * member =
    (const solution_interfaces__msg__WorldItem__Sequence *)(untyped_member);
  return member->size;
}

const void * solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_const_function__WorldItems__blue(
  const void * untyped_member, size_t index)
{
  const solution_interfaces__msg__WorldItem__Sequence * member =
    (const solution_interfaces__msg__WorldItem__Sequence *)(untyped_member);
  return &member->data[index];
}

void * solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_function__WorldItems__blue(
  void * untyped_member, size_t index)
{
  solution_interfaces__msg__WorldItem__Sequence * member =
    (solution_interfaces__msg__WorldItem__Sequence *)(untyped_member);
  return &member->data[index];
}

void solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__fetch_function__WorldItems__blue(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const solution_interfaces__msg__WorldItem * item =
    ((const solution_interfaces__msg__WorldItem *)
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_const_function__WorldItems__blue(untyped_member, index));
  solution_interfaces__msg__WorldItem * value =
    (solution_interfaces__msg__WorldItem *)(untyped_value);
  *value = *item;
}

void solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__assign_function__WorldItems__blue(
  void * untyped_member, size_t index, const void * untyped_value)
{
  solution_interfaces__msg__WorldItem * item =
    ((solution_interfaces__msg__WorldItem *)
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_function__WorldItems__blue(untyped_member, index));
  const solution_interfaces__msg__WorldItem * value =
    (const solution_interfaces__msg__WorldItem *)(untyped_value);
  *item = *value;
}

bool solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__resize_function__WorldItems__blue(
  void * untyped_member, size_t size)
{
  solution_interfaces__msg__WorldItem__Sequence * member =
    (solution_interfaces__msg__WorldItem__Sequence *)(untyped_member);
  solution_interfaces__msg__WorldItem__Sequence__fini(member);
  return solution_interfaces__msg__WorldItem__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_message_member_array[3] = {
  {
    "red",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(solution_interfaces__msg__WorldItems, red),  // bytes offset in struct
    NULL,  // default value
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__size_function__WorldItems__red,  // size() function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_const_function__WorldItems__red,  // get_const(index) function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_function__WorldItems__red,  // get(index) function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__fetch_function__WorldItems__red,  // fetch(index, &value) function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__assign_function__WorldItems__red,  // assign(index, value) function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__resize_function__WorldItems__red  // resize(index) function pointer
  },
  {
    "green",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(solution_interfaces__msg__WorldItems, green),  // bytes offset in struct
    NULL,  // default value
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__size_function__WorldItems__green,  // size() function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_const_function__WorldItems__green,  // get_const(index) function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_function__WorldItems__green,  // get(index) function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__fetch_function__WorldItems__green,  // fetch(index, &value) function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__assign_function__WorldItems__green,  // assign(index, value) function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__resize_function__WorldItems__green  // resize(index) function pointer
  },
  {
    "blue",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(solution_interfaces__msg__WorldItems, blue),  // bytes offset in struct
    NULL,  // default value
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__size_function__WorldItems__blue,  // size() function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_const_function__WorldItems__blue,  // get_const(index) function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__get_function__WorldItems__blue,  // get(index) function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__fetch_function__WorldItems__blue,  // fetch(index, &value) function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__assign_function__WorldItems__blue,  // assign(index, value) function pointer
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__resize_function__WorldItems__blue  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_message_members = {
  "solution_interfaces__msg",  // message namespace
  "WorldItems",  // message name
  3,  // number of fields
  sizeof(solution_interfaces__msg__WorldItems),
  solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_message_member_array,  // message members
  solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_init_function,  // function to initialize message memory (memory has to be allocated)
  solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_message_type_support_handle = {
  0,
  &solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_solution_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, solution_interfaces, msg, WorldItems)() {
  solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, solution_interfaces, msg, WorldItem)();
  solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, solution_interfaces, msg, WorldItem)();
  solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, solution_interfaces, msg, WorldItem)();
  if (!solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_message_type_support_handle.typesupport_identifier) {
    solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &solution_interfaces__msg__WorldItems__rosidl_typesupport_introspection_c__WorldItems_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
