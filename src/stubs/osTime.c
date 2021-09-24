#include "jpegmodule/z64.h"
#include "jpegmodule/functions.h"

#include <sys/time.h>

OSTime osGetTime(void) {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return OS_USEC_TO_CYCLES(tv.tv_sec*(uint64_t)1000000 + tv.tv_usec);
}
