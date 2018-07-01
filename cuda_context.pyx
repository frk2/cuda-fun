# distutils: language = c++

from context_helper cimport ContextHelper

cdef class PyCudaContext:
    cdef ContextHelper c_cudactx

    def __cinit__(self):
        self.c_cudactx = ContextHelper()

    def pop_ctx(self):
        self.c_cudactx.pop_ctx()

    def push_ctx(self):
        self.c_cudactx.push_ctx()