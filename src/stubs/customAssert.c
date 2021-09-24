#include "jpegmodule/z64.h"
#include "jpegmodule/functions.h"

#include <stdio.h>

void __custom_assert(const char* exp, const char* file, s32 line) {
    fprintf(stderr, "__custom_assert: \n");
    fprintf(stderr, "%s:%i: Assertion `%s' failed.\n", file, line, exp);
    exit(EXIT_FAILURE);
}
