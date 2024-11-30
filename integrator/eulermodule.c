#include <Python.h>

#include "integrator.h"

static PyObject *integrate_method(PyObject *self, PyObject *args) {
    float v0, a;
    int steps;

    if (!PyArg_ParseTuple(args, "ffi", &v0, &a, &steps)) {
        return NULL;
    }

    float *result = integrate(v0, a, steps);

    PyObject *py_result = PyList_New(steps);
    for (int i = 0; i < steps; i++) {
        PyList_SetItem(py_result, i, PyFloat_FromDouble(result[i]));
    }
    return py_result;
}

static PyMethodDef IntegratorMethods[] = {{"integrate", integrate_method,
                                           METH_VARARGS,
                                           "Integrate using Euler's method"},
                                          {NULL, NULL, 0, NULL}};

static struct PyModuleDef euler_module = {PyModuleDef_HEAD_INIT, "euler",
                                          "Python interface for Euler's method",
                                          -1, IntegratorMethods};

PyMODINIT_FUNC PyInit_euler(void) { return PyModule_Create(&euler_module); }
