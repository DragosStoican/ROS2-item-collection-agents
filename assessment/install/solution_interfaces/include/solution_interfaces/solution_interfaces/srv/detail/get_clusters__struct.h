// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from solution_interfaces:srv/GetClusters.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__SRV__DETAIL__GET_CLUSTERS__STRUCT_H_
#define SOLUTION_INTERFACES__SRV__DETAIL__GET_CLUSTERS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetClusters in the package solution_interfaces.
typedef struct solution_interfaces__srv__GetClusters_Request
{
  uint8_t structure_needs_at_least_one_member;
} solution_interfaces__srv__GetClusters_Request;

// Struct for a sequence of solution_interfaces__srv__GetClusters_Request.
typedef struct solution_interfaces__srv__GetClusters_Request__Sequence
{
  solution_interfaces__srv__GetClusters_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__srv__GetClusters_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'clusters'
#include "solution_interfaces/msg/detail/world_item__struct.h"

/// Struct defined in srv/GetClusters in the package solution_interfaces.
typedef struct solution_interfaces__srv__GetClusters_Response
{
  solution_interfaces__msg__WorldItem__Sequence clusters;
} solution_interfaces__srv__GetClusters_Response;

// Struct for a sequence of solution_interfaces__srv__GetClusters_Response.
typedef struct solution_interfaces__srv__GetClusters_Response__Sequence
{
  solution_interfaces__srv__GetClusters_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__srv__GetClusters_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__SRV__DETAIL__GET_CLUSTERS__STRUCT_H_
