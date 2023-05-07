/**
 * Author: eredotpkfr
 * Purpose: Implementing fast IP validators with C language.
 * Language:  C
 *
 * Main C API source file for fipv module.
 */

#define PY_SSIZE_T_CLEAN
#include <Python.h> /* For python integration */

#include "validators/ipv4.h"
#include "validators/ipv6.h"

static PyObject *ipv4(PyObject *self, PyObject *args);
static PyObject *ipv4_cidr(PyObject *self, PyObject *args);
static PyObject *ipv6(PyObject *self, PyObject *args);
static PyObject *ipv6_cidr(PyObject *self, PyObject *args);
PyMODINIT_FUNC PyInit_fipv(void);

/**
 * Module function for validating IPv4 values.
 *
 * Args:
 *     self(PyObject *): the module itself
 *     args(PyObject *): function arguments as a python object
 *
 * Returns:
 *     Python boolean object, ``True`` if value is a valid IPv4
 *         otherwise returns ``False``
 *
 */
static PyObject *ipv4(PyObject *self, PyObject *args) {
  char *ipv4_addr;

  if (!PyArg_ParseTuple(args, "s", &ipv4_addr))
    return NULL;

  if (is_ipv4(ipv4_addr))
    Py_RETURN_TRUE;

  Py_RETURN_FALSE;
}

/**
 * Module function for validating IPv4 CIDR values.
 *
 * Args:
 *     self(PyObject *): the module itself
 *     args(PyObject *): function arguments as a python object
 *
 * Returns:
 *     Python boolean object, ``True`` if value is a valid IPv4 CIDR
 *         otherwise returns ``False``
 *
 */
static PyObject *ipv4_cidr(PyObject *self, PyObject *args) {
  char *ipv4_addr_cidr;

  if (!PyArg_ParseTuple(args, "s", &ipv4_addr_cidr))
    return NULL;

  if (is_ipv4_cidr(ipv4_addr_cidr))
    Py_RETURN_TRUE;

  Py_RETURN_FALSE;
}

/**
 * Module function for validating IPv6 values.
 *
 * Args:
 *     self(PyObject *): the module itself
 *     args(PyObject *): function arguments as a python object
 *
 * Returns:
 *     Python boolean object, ``True`` if value is a valid IPv6
 *         otherwise returns ``False``
 *
 */
static PyObject *ipv6(PyObject *self, PyObject *args) {
  char *ipv6_addr;

  if (!PyArg_ParseTuple(args, "s", &ipv6_addr))
    return NULL;

  if (is_ipv6(ipv6_addr))
    Py_RETURN_TRUE;

  Py_RETURN_FALSE;
}

/**
 * Module function for validating IPv6 CIDR values.
 *
 * Args:
 *     self(PyObject *): the module itself
 *     args(PyObject *): function arguments as a python object
 *
 * Returns:
 *     Python boolean object, ``True`` if value is a valid IPv6 CIDR
 *         otherwise returns ``False``
 *
 */
static PyObject *ipv6_cidr(PyObject *self, PyObject *args) {
  char *ipv6_addr_cidr;

  if (!PyArg_ParseTuple(args, "s", &ipv6_addr_cidr))
    return NULL;

  if (is_ipv6_cidr(ipv6_addr_cidr))
    Py_RETURN_TRUE;

  Py_RETURN_FALSE;
}

static PyMethodDef ModuleFuncs[] = {
    {"ipv4", ipv4, METH_VARARGS, "Validate IPv4"},
    {"ipv6", ipv6, METH_VARARGS, "Validate IPv6"},
    {"ipv4_cidr", ipv4_cidr, METH_VARARGS, "Validate IPv4CIDR"},
    {"ipv6_cidr", ipv6_cidr, METH_VARARGS, "Validate IPv6CIDR"},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef fipv = {
    PyModuleDef_HEAD_INIT,
    "fipv",
    "Fast IP validator with C language as a python module",
    -1,
    ModuleFuncs,
};

PyMODINIT_FUNC PyInit_fipv(void) { return PyModule_Create(&fipv); }
