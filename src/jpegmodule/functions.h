#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "z64.h"

void osSyncPrintf(const char* fmt, ...);

void __assert(const char* exp, const char* file, s32 line);

s32 osSendMesg(OSMesgQueue* mq, OSMesg msg, s32 flags);
s32 osRecvMesg(OSMesgQueue* mq, OSMesg* msg, s32 flags);

void osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msq, s32 count);

void osInvalDCache(void* vaddr, s32 nbytes);

uintptr_t SysUcode_GetUCodeBoot(void);
size_t SysUcode_GetUCodeBootSize(void);

OSTime osGetTime(void);

void MsgEvent_SendNullTask(void);

void Sched_SwapFramebuffer(CfbInfo* cfbInfo);
void Sched_RetraceUpdateFramebuffer(SchedContext* sched, CfbInfo* cfbInfo);
void Sched_HandleReset(SchedContext* sched);
void Sched_HandleStop(SchedContext* sched);
void Sched_HandleAudioCancel(SchedContext* sched);
void Sched_HandleGfxCancel(SchedContext* sched);
void Sched_QueueTask(SchedContext* sched, OSScTask* task);
void Sched_Yield(SchedContext* sched);
s32 Sched_Schedule(SchedContext* sched, OSScTask** spTask, OSScTask** dpTask, s32 state);
void Sched_TaskUpdateFramebuffer(SchedContext* sched, OSScTask* task);
void Sched_NotifyDone(SchedContext* sched, OSScTask* task);
void Sched_RunTask(SchedContext* sched, OSScTask* spTask, OSScTask* dpTask);
void Sched_HandleEntry(SchedContext* sched);
void Sched_HandleRetrace(SchedContext* sched);
void Sched_HandleRSPDone(SchedContext* sched);
void Sched_HandleRDPDone(SchedContext* sched);
void Sched_SendEntryMsg(SchedContext* sched);
void Sched_SendAudioCancelMsg(SchedContext* sched);
void Sched_SendGfxCancelMsg(SchedContext* sched);
void Sched_FaultClient(void* param1, void* param2);
void Sched_ThreadEntry(void* arg);
//void Sched_Init(SchedContext* sched, void* stack, OSPri pri, s32 arg3, s32 arg4, IrqMgr* irqMgr);

#endif
