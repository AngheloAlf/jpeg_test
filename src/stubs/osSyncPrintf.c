#include "jpegmodule/z64.h"
#include "jpegmodule/functions.h"

#include <stdio.h>

void osSyncPrintf(const char* fmt, ...) {
    va_list va;

    va_start(va, fmt);
    vprintf(fmt, va);
    va_end(va);
}
