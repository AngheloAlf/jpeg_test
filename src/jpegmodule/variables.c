#include "variables.h"

SchedContext gSchedContext;
u64 gJpegUCode[0x60];
u64 gJpegUCodeData[0xAF0];

u16 gZBuffer[SCREEN_HEIGHT][SCREEN_WIDTH]; // 0x25800 bytes
u64 gGfxSPTaskOutputBuffer[0x3000]; // 0x18000 bytes
