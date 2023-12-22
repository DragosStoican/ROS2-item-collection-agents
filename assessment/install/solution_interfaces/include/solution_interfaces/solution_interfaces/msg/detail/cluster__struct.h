// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from solution_interfaces:msg/Cluster.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__CLUSTER__STRUCT_H_
#define SOLUTION_INTERFACES__MSG__DETAIL__CLUSTER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'colour'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Cluster in the package solution_interfaces.
typedef struct solution_interfaces__msg__Cluster
{
  int16_t x;
  int16_t y;
  rosidl_runtime_c__String colour;
} solution_interfaces__msg__Cluster;

// Struct for a sequence of solution_interfaces__msg__Cluster.
typedef struct solution_interfaces__msg__Cluster__Sequence
{
  solution_interfaces__msg__Cluster * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__msg__Cluster__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__CLUSTER__STRUCT_H_
