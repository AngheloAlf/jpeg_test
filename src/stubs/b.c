#include "jpegmodule/z64.h"
#include "jpegmodule/functions.h"

#include <string.h>

// void _custom_bzero(void* __s, u32 __n);
void* _custom_bcopy(void* __src, void* __dest, u32 __n) {
    return memmove(__dest, __src, __n);
}
