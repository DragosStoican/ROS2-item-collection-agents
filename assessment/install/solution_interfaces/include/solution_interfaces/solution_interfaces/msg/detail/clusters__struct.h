// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from solution_interfaces:msg/Clusters.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__CLUSTERS__STRUCT_H_
#define SOLUTION_INTERFACES__MSG__DETAIL__CLUSTERS__STRUCT_H_

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
#include "solution_interfaces/msg/detail/cluster__struct.h"

/// Struct defined in msg/Clusters in the package solution_interfaces.
typedef struct solution_interfaces__msg__Clusters
{
  solution_interfaces__msg__Cluster__Sequence red;
  solution_interfaces__msg__Cluster__Sequence green;
  solution_interfaces__msg__Cluster__Sequence blue;
} solution_interfaces__msg__Clusters;

// Struct for a sequence of solution_interfaces__msg__Clusters.
typedef struct solution_interfaces__msg__Clusters__Sequence
{
  solution_interfaces__msg__Clusters * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__msg__Clusters__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__CLUSTERS__STRUCT_H_
