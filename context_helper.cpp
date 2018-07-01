#include "context_helper.h"

ContextHelper::ContextHelper() {
    cuCtxGetCurrent(&this->context);
}

void ContextHelper::pop_ctx() {
    CUcontext context;
    cuCtxPopCurrent(&context);
}

void ContextHelper::push_ctx() {
    cuCtxPushCurrent(this->context);
}
