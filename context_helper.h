#ifndef CONTEXT_HELPER_H
#define CONTEXT_HELPER_H
#include <cuda.h>

class ContextHelper {
    CUcontext context;
    public:
        ContextHelper();
        void push_ctx();
        void pop_ctx();
};
#endif