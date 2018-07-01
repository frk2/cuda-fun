cdef extern from "context_helper.cpp":
    pass

cdef extern from "context_helper.h":
    cdef cppclass ContextHelper:
        ContextHelper() except +
        void push_ctx()
        void pop_ctx()