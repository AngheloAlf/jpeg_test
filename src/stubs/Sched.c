#include "jpegmodule/z64.h"
#include "jpegmodule/functions.h"

// data
vs32 sLogScheduler = false;

// bss
OSTime sRSPGFXStartTime;
OSTime sRSPAudioStartTime;
OSTime sRSPOtherStartTime;
OSTime sRDPStartTime;


void Sched_SendEntryMsg(SchedContext* sc) {
    if (sLogScheduler) {
        osSyncPrintf("osScKickEntryMsg\n");
    }

    osSendMesg(&sc->interruptQ, ENTRY_MSG, OS_MESG_BLOCK);
}
