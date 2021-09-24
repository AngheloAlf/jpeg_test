#include "jpegmodule/z64.h"
#include "jpegmodule/functions.h"
#include "jpegmodule/variables.h"

s32 osSendMesg(OSMesgQueue* mq, OSMesg msg, s32 flags) {
    // stub
    return 0;
}

s32 osRecvMesg(OSMesgQueue* mq, OSMesg* msg, s32 flags) {
    // stub
    return 0;
}

void osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msg, s32 count) {
    //mq->mtqueue = (OSThread*)__osThreadTail;
    //mq->fullqueue = (OSThread*)__osThreadTail;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = count;
    mq->msg = msg;
}

void MsgEvent_SendNullTask(void) {
    s32 pad[4];
    OSScTask task;
    OSMesgQueue queue;
    OSMesg msg;
    u32 pad2[1];

    task.next = NULL;
    task.flags = OS_SC_RCP_MASK;
    task.msgQ = &queue;
    task.msg = NULL;
    task.framebuffer = NULL;
    task.list.t.type = M_NULTASK;
    osCreateMesgQueue(task.msgQ, &msg, 1);
    osSendMesg(&gSchedContext.cmdQ, &task, OS_MESG_BLOCK);
    Sched_SendEntryMsg(&gSchedContext);
    osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
}
