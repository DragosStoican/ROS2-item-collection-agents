// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from solution_interfaces:msg/Clusters.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "solution_interfaces/msg/detail/clusters__struct.h"
#include "solution_interfaces/msg/detail/clusters__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "solution_interfaces/msg/detail/cluster__functions.h"
// end nested array functions include
bool solution_interfaces__msg__cluster__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * solution_interfaces__msg__cluster__convert_to_py(void * raw_ros_message);
bool solution_interfaces__msg__cluster__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * solution_interfaces__msg__cluster__convert_to_py(void * raw_ros_message);
bool solution_interfaces__msg__cluster__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * solution_interfaces__msg__cluster__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool solution_interfaces__msg__clusters__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("solution_interfaces.msg._clusters.Clusters", full_classname_dest, 42) == 0);
  }
  solution_interfaces__msg__Clusters * ros_message = _ros_message;
  {  // red
    PyObject * field = PyObject_GetAttrString(_pymsg, "red");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'red'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!solution_interfaces__msg__Cluster__Sequence__init(&(ros_message->red), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create solution_interfaces__msg__Cluster__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    solution_interfaces__msg__Cluster * dest = ros_message->red.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!solution_interfaces__msg__cluster__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // green
    PyObject * field = PyObject_GetAttrString(_pymsg, "green");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'green'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!solution_interfaces__msg__Cluster__Sequence__init(&(ros_message->green), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create solution_interfaces__msg__Cluster__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    solution_interfaces__msg__Cluster * dest = ros_message->green.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!solution_interfaces__msg__cluster__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // blue
    PyObject * field = PyObject_GetAttrString(_pymsg, "blue");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'blue'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!solution_interfaces__msg__Cluster__Sequence__init(&(ros_message->blue), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create solution_interfaces__msg__Cluster__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    solution_interfaces__msg__Cluster * dest = ros_message->blue.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!solution_interfaces__msg__cluster__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * solution_interfaces__msg__clusters__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Clusters */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("solution_interfaces.msg._clusters");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Clusters");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  solution_interfaces__msg__Clusters * ros_message = (solution_interfaces__msg__Clusters *)raw_ros_message;
  {  // red
    PyObject * field = NULL;
    size_t size = ros_message->red.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    solution_interfaces__msg__Cluster * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->red.data[i]);
      PyObject * pyitem = solution_interfaces__msg__cluster__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "red", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // green
    PyObject * field = NULL;
    size_t size = ros_message->green.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    solution_interfaces__msg__Cluster * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->green.data[i]);
      PyObject * pyitem = solution_interfaces__msg__cluster__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "green", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // blue
    PyObject * field = NULL;
    size_t size = ros_message->blue.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    solution_interfaces__msg__Cluster * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->blue.data[i]);
      PyObject * pyitem = solution_interfaces__msg__cluster__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "blue", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
