// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from solution_interfaces:msg/Cluster.idl
// generated code does not contain a copyright notice
#include "solution_interfaces/msg/detail/cluster__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `colour`
#include "rosidl_runtime_c/string_functions.h"

bool
solution_interfaces__msg__Cluster__init(solution_interfaces__msg__Cluster * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // colour
  if (!rosidl_runtime_c__String__init(&msg->colour)) {
    solution_interfaces__msg__Cluster__fini(msg);
    return false;
  }
  return true;
}

void
solution_interfaces__msg__Cluster__fini(solution_interfaces__msg__Cluster * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // colour
  rosidl_runtime_c__String__fini(&msg->colour);
}

bool
solution_interfaces__msg__Cluster__are_equal(const solution_interfaces__msg__Cluster * lhs, const solution_interfaces__msg__Cluster * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // colour
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->colour), &(rhs->colour)))
  {
    return false;
  }
  return true;
}

bool
solution_interfaces__msg__Cluster__copy(
  const solution_interfaces__msg__Cluster * input,
  solution_interfaces__msg__Cluster * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // colour
  if (!rosidl_runtime_c__String__copy(
      &(input->colour), &(output->colour)))
  {
    return false;
  }
  return true;
}

solution_interfaces__msg__Cluster *
solution_interfaces__msg__Cluster__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__msg__Cluster * msg = (solution_interfaces__msg__Cluster *)allocator.allocate(sizeof(solution_interfaces__msg__Cluster), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(solution_interfaces__msg__Cluster));
  bool success = solution_interfaces__msg__Cluster__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
solution_interfaces__msg__Cluster__destroy(solution_interfaces__msg__Cluster * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    solution_interfaces__msg__Cluster__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
solution_interfaces__msg__Cluster__Sequence__init(solution_interfaces__msg__Cluster__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__msg__Cluster * data = NULL;

  if (size) {
    data = (solution_interfaces__msg__Cluster *)allocator.zero_allocate(size, sizeof(solution_interfaces__msg__Cluster), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = solution_interfaces__msg__Cluster__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        solution_interfaces__msg__Cluster__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
solution_interfaces__msg__Cluster__Sequence__fini(solution_interfaces__msg__Cluster__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      solution_interfaces__msg__Cluster__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

solution_interfaces__msg__Cluster__Sequence *
solution_interfaces__msg__Cluster__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__msg__Cluster__Sequence * array = (solution_interfaces__msg__Cluster__Sequence *)allocator.allocate(sizeof(solution_interfaces__msg__Cluster__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = solution_interfaces__msg__Cluster__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
solution_interfaces__msg__Cluster__Sequence__destroy(solution_interfaces__msg__Cluster__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    solution_interfaces__msg__Cluster__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
solution_interfaces__msg__Cluster__Sequence__are_equal(const solution_interfaces__msg__Cluster__Sequence * lhs, const solution_interfaces__msg__Cluster__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!solution_interfaces__msg__Cluster__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
solution_interfaces__msg__Cluster__Sequence__copy(
  const solution_interfaces__msg__Cluster__Sequence * input,
  solution_interfaces__msg__Cluster__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(solution_interfaces__msg__Cluster);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    solution_interfaces__msg__Cluster * data =
      (solution_interfaces__msg__Cluster *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!solution_interfaces__msg__Cluster__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          solution_interfaces__msg__Cluster__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!solution_interfaces__msg__Cluster__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
