// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from solution_interfaces:msg/WorldItems.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEMS__STRUCT_H_
#define SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEMS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'red'
// Member 'green'
// Member 'blue'
#include "solution_interfaces/msg/detail/world_item__struct.h"

/// Struct defined in msg/WorldItems in the package solution_interfaces.
typedef struct solution_interfaces__msg__WorldItems
{
  solution_interfaces__msg__WorldItem__Sequence red;
  solution_interfaces__msg__WorldItem__Sequence green;
  solution_interfaces__msg__WorldItem__Sequence blue;
} solution_interfaces__msg__WorldItems;

// Struct for a sequence of solution_interfaces__msg__WorldItems.
typedef struct solution_interfaces__msg__WorldItems__Sequence
{
  solution_interfaces__msg__WorldItems * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__msg__WorldItems__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEMS__STRUCT_H_
