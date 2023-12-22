// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from solution_interfaces:msg/WorldItem.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEM__FUNCTIONS_H_
#define SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEM__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "solution_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "solution_interfaces/msg/detail/world_item__struct.h"

/// Initialize msg/WorldItem message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * solution_interfaces__msg__WorldItem
 * )) before or use
 * solution_interfaces__msg__WorldItem__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
bool
solution_interfaces__msg__WorldItem__init(solution_interfaces__msg__WorldItem * msg);

/// Finalize msg/WorldItem message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
void
solution_interfaces__msg__WorldItem__fini(solution_interfaces__msg__WorldItem * msg);

/// Create msg/WorldItem message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * solution_interfaces__msg__WorldItem__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
solution_interfaces__msg__WorldItem *
solution_interfaces__msg__WorldItem__create();

/// Destroy msg/WorldItem message.
/**
 * It calls
 * solution_interfaces__msg__WorldItem__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
void
solution_interfaces__msg__WorldItem__destroy(solution_interfaces__msg__WorldItem * msg);

/// Check for msg/WorldItem message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
bool
solution_interfaces__msg__WorldItem__are_equal(const solution_interfaces__msg__WorldItem * lhs, const solution_interfaces__msg__WorldItem * rhs);

/// Copy a msg/WorldItem message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
bool
solution_interfaces__msg__WorldItem__copy(
  const solution_interfaces__msg__WorldItem * input,
  solution_interfaces__msg__WorldItem * output);

/// Initialize array of msg/WorldItem messages.
/**
 * It allocates the memory for the number of elements and calls
 * solution_interfaces__msg__WorldItem__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
bool
solution_interfaces__msg__WorldItem__Sequence__init(solution_interfaces__msg__WorldItem__Sequence * array, size_t size);

/// Finalize array of msg/WorldItem messages.
/**
 * It calls
 * solution_interfaces__msg__WorldItem__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
void
solution_interfaces__msg__WorldItem__Sequence__fini(solution_interfaces__msg__WorldItem__Sequence * array);

/// Create array of msg/WorldItem messages.
/**
 * It allocates the memory for the array and calls
 * solution_interfaces__msg__WorldItem__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
solution_interfaces__msg__WorldItem__Sequence *
solution_interfaces__msg__WorldItem__Sequence__create(size_t size);

/// Destroy array of msg/WorldItem messages.
/**
 * It calls
 * solution_interfaces__msg__WorldItem__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
void
solution_interfaces__msg__WorldItem__Sequence__destroy(solution_interfaces__msg__WorldItem__Sequence * array);

/// Check for msg/WorldItem message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
bool
solution_interfaces__msg__WorldItem__Sequence__are_equal(const solution_interfaces__msg__WorldItem__Sequence * lhs, const solution_interfaces__msg__WorldItem__Sequence * rhs);

/// Copy an array of msg/WorldItem messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
bool
solution_interfaces__msg__WorldItem__Sequence__copy(
  const solution_interfaces__msg__WorldItem__Sequence * input,
  solution_interfaces__msg__WorldItem__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__WORLD_ITEM__FUNCTIONS_H_
