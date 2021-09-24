#ifndef OS_H
#define OS_H

#include <stdint.h>
#include <stdlib.h>

#include "ultra64/types.h"
#include "ultra64/thread.h"
#include "ultra64/convert.h"
#include "ultra64/time.h"
#include "ultra64/message.h"
#include "ultra64/sptask.h"
#include "ultra64/vi.h"
#include "macros.h"

#define NULL ((void*)0)
#define true 1
#define false 0

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240

#define REGION_NULL 0
#define REGION_US 1
#define REGION_JP 2
#define REGION_EU 3

#define Z_PRIORITY_MAIN        10
#define Z_PRIORITY_GRAPH       11
#define Z_PRIORITY_AUDIOMGR    12
#define Z_PRIORITY_PADMGR      14
#define Z_PRIORITY_SCHED       15
#define Z_PRIORITY_DMAMGR      16
#define Z_PRIORITY_IRQMGR      17

// NOTE: Once we start supporting other builds, this can be changed with an ifdef
#define REGION_NATIVE REGION_EU

typedef struct {
    /* 0x00 */ u16* fb1;
    /* 0x04 */ u16* swapBuffer;
    /* 0x08 */ OSViMode* viMode;
    /* 0x0C */ u32 features;
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ s8 updateRate;
    /* 0x12 */ s8 updateRate2;
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ f32 xScale;
    /* 0x18 */ f32 yScale;
} CfbInfo; // size = 0x1C

typedef struct OSScTask {
    /* 0x00 */ struct OSScTask* next;
    /* 0x04 */ u32 state;
    /* 0x08 */ u32 flags;
    /* 0x0C */ CfbInfo* framebuffer;
    /* 0x10 */ OSTask list;
    /* 0x50 */ OSMesgQueue* msgQ;
    /* 0x54 */ OSMesg msg;
} OSScTask;

typedef struct IrqMgrClient {
    /* 0x00 */ struct IrqMgrClient* prev;
    /* 0x04 */ OSMesgQueue* queue;
} IrqMgrClient;

#define OS_SC_NEEDS_RDP         0x0001
#define OS_SC_NEEDS_RSP         0x0002
#define OS_SC_DRAM_DLIST        0x0004
#define OS_SC_PARALLEL_TASK     0x0010
#define OS_SC_LAST_TASK         0x0020
#define OS_SC_SWAPBUFFER        0x0040

#define OS_SC_RCP_MASK          0x0003
#define OS_SC_TYPE_MASK         0x0007

typedef struct {
    /* 0x0000 */ u16*   curBuffer;
    /* 0x0004 */ u16*   nextBuffer;
} FrameBufferSwap;

typedef struct {
    /* 0x0000 */ OSMesgQueue  interruptQ;
    /* 0x0018 */ OSMesg       intBuf[8];
    /* 0x0038 */ OSMesgQueue  cmdQ;
    /* 0x0050 */ OSMesg       cmdMsgBuf[8];
    /* 0x0070 */ OSThread     thread;
    /* 0x0220 */ OSScTask*    audioListHead;
    /* 0x0224 */ OSScTask*    gfxListHead;
    /* 0x0228 */ OSScTask*    audioListTail;
    /* 0x022C */ OSScTask*    gfxListTail;
    /* 0x0230 */ OSScTask*    curRSPTask;
    /* 0x0234 */ OSScTask*    curRDPTask;
    /* 0x0238 */ s32          retraceCnt;
    /* 0x023C */ s32          doAudio;
    /* 0x0240 */ CfbInfo* curBuf;
    /* 0x0244 */ CfbInfo*        pendingSwapBuf1;
    /* 0x0220 */ CfbInfo* pendingSwapBuf2;
    /* 0x0220 */ s32     unk_24C;
    /* 0x0250 */ IrqMgrClient   irqClient;
} SchedContext; // size = 0x258

#endif
