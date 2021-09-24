#ifndef VARIABLES_H
#define VARIABLES_H

#include "z64.h"

extern SchedContext gSchedContext;
extern u64 gJpegUCode[];
extern u64 gJpegUCodeData[];
extern u16 gZBuffer[SCREEN_HEIGHT][SCREEN_WIDTH]; // 0x25800 bytes
extern u64 gGfxSPTaskOutputBuffer[0x3000]; // 0x18000 bytes

extern vs32 sLogScheduler;

#endif
