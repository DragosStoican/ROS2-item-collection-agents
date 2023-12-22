// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from solution_interfaces:srv/GetClusters.idl
// generated code does not contain a copyright notice
#include "solution_interfaces/srv/detail/get_clusters__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
solution_interfaces__srv__GetClusters_Request__init(solution_interfaces__srv__GetClusters_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
solution_interfaces__srv__GetClusters_Request__fini(solution_interfaces__srv__GetClusters_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
solution_interfaces__srv__GetClusters_Request__are_equal(const solution_interfaces__srv__GetClusters_Request * lhs, const solution_interfaces__srv__GetClusters_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
solution_interfaces__srv__GetClusters_Request__copy(
  const solution_interfaces__srv__GetClusters_Request * input,
  solution_interfaces__srv__GetClusters_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

solution_interfaces__srv__GetClusters_Request *
solution_interfaces__srv__GetClusters_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__srv__GetClusters_Request * msg = (solution_interfaces__srv__GetClusters_Request *)allocator.allocate(sizeof(solution_interfaces__srv__GetClusters_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(solution_interfaces__srv__GetClusters_Request));
  bool success = solution_interfaces__srv__GetClusters_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
solution_interfaces__srv__GetClusters_Request__destroy(solution_interfaces__srv__GetClusters_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    solution_interfaces__srv__GetClusters_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
solution_interfaces__srv__GetClusters_Request__Sequence__init(solution_interfaces__srv__GetClusters_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__srv__GetClusters_Request * data = NULL;

  if (size) {
    data = (solution_interfaces__srv__GetClusters_Request *)allocator.zero_allocate(size, sizeof(solution_interfaces__srv__GetClusters_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = solution_interfaces__srv__GetClusters_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        solution_interfaces__srv__GetClusters_Request__fini(&data[i - 1]);
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
solution_interfaces__srv__GetClusters_Request__Sequence__fini(solution_interfaces__srv__GetClusters_Request__Sequence * array)
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
      solution_interfaces__srv__GetClusters_Request__fini(&array->data[i]);
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

solution_interfaces__srv__GetClusters_Request__Sequence *
solution_interfaces__srv__GetClusters_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__srv__GetClusters_Request__Sequence * array = (solution_interfaces__srv__GetClusters_Request__Sequence *)allocator.allocate(sizeof(solution_interfaces__srv__GetClusters_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = solution_interfaces__srv__GetClusters_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
solution_interfaces__srv__GetClusters_Request__Sequence__destroy(solution_interfaces__srv__GetClusters_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    solution_interfaces__srv__GetClusters_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
solution_interfaces__srv__GetClusters_Request__Sequence__are_equal(const solution_interfaces__srv__GetClusters_Request__Sequence * lhs, const solution_interfaces__srv__GetClusters_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!solution_interfaces__srv__GetClusters_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
solution_interfaces__srv__GetClusters_Request__Sequence__copy(
  const solution_interfaces__srv__GetClusters_Request__Sequence * input,
  solution_interfaces__srv__GetClusters_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(solution_interfaces__srv__GetClusters_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    solution_interfaces__srv__GetClusters_Request * data =
      (solution_interfaces__srv__GetClusters_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!solution_interfaces__srv__GetClusters_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          solution_interfaces__srv__GetClusters_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!solution_interfaces__srv__GetClusters_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `clusters`
#include "solution_interfaces/msg/detail/world_item__functions.h"

bool
solution_interfaces__srv__GetClusters_Response__init(solution_interfaces__srv__GetClusters_Response * msg)
{
  if (!msg) {
    return false;
  }
  // clusters
  if (!solution_interfaces__msg__WorldItem__Sequence__init(&msg->clusters, 0)) {
    solution_interfaces__srv__GetClusters_Response__fini(msg);
    return false;
  }
  return true;
}

void
solution_interfaces__srv__GetClusters_Response__fini(solution_interfaces__srv__GetClusters_Response * msg)
{
  if (!msg) {
    return;
  }
  // clusters
  solution_interfaces__msg__WorldItem__Sequence__fini(&msg->clusters);
}

bool
solution_interfaces__srv__GetClusters_Response__are_equal(const solution_interfaces__srv__GetClusters_Response * lhs, const solution_interfaces__srv__GetClusters_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // clusters
  if (!solution_interfaces__msg__WorldItem__Sequence__are_equal(
      &(lhs->clusters), &(rhs->clusters)))
  {
    return false;
  }
  return true;
}

bool
solution_interfaces__srv__GetClusters_Response__copy(
  const solution_interfaces__srv__GetClusters_Response * input,
  solution_interfaces__srv__GetClusters_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // clusters
  if (!solution_interfaces__msg__WorldItem__Sequence__copy(
      &(input->clusters), &(output->clusters)))
  {
    return false;
  }
  return true;
}

solution_interfaces__srv__GetClusters_Response *
solution_interfaces__srv__GetClusters_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__srv__GetClusters_Response * msg = (solution_interfaces__srv__GetClusters_Response *)allocator.allocate(sizeof(solution_interfaces__srv__GetClusters_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(solution_interfaces__srv__GetClusters_Response));
  bool success = solution_interfaces__srv__GetClusters_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
solution_interfaces__srv__GetClusters_Response__destroy(solution_interfaces__srv__GetClusters_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    solution_interfaces__srv__GetClusters_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
solution_interfaces__srv__GetClusters_Response__Sequence__init(solution_interfaces__srv__GetClusters_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__srv__GetClusters_Response * data = NULL;

  if (size) {
    data = (solution_interfaces__srv__GetClusters_Response *)allocator.zero_allocate(size, sizeof(solution_interfaces__srv__GetClusters_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = solution_interfaces__srv__GetClusters_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        solution_interfaces__srv__GetClusters_Response__fini(&data[i - 1]);
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
solution_interfaces__srv__GetClusters_Response__Sequence__fini(solution_interfaces__srv__GetClusters_Response__Sequence * array)
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
      solution_interfaces__srv__GetClusters_Response__fini(&array->data[i]);
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

solution_interfaces__srv__GetClusters_Response__Sequence *
solution_interfaces__srv__GetClusters_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__srv__GetClusters_Response__Sequence * array = (solution_interfaces__srv__GetClusters_Response__Sequence *)allocator.allocate(sizeof(solution_interfaces__srv__GetClusters_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = solution_interfaces__srv__GetClusters_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
solution_interfaces__srv__GetClusters_Response__Sequence__destroy(solution_interfaces__srv__GetClusters_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    solution_interfaces__srv__GetClusters_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
solution_interfaces__srv__GetClusters_Response__Sequence__are_equal(const solution_interfaces__srv__GetClusters_Response__Sequence * lhs, const solution_interfaces__srv__GetClusters_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!solution_interfaces__srv__GetClusters_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
solution_interfaces__srv__GetClusters_Response__Sequence__copy(
  const solution_interfaces__srv__GetClusters_Response__Sequence * input,
  solution_interfaces__srv__GetClusters_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(solution_interfaces__srv__GetClusters_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    solution_interfaces__srv__GetClusters_Response * data =
      (solution_interfaces__srv__GetClusters_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!solution_interfaces__srv__GetClusters_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          solution_interfaces__srv__GetClusters_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!solution_interfaces__srv__GetClusters_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
