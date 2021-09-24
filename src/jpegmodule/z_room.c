#include "jpeg.h"
#include "functions.h"
#include "variables.h"

s32 func_80096238(void* data) {
    OSTime time;

    if (*(u32*)data == JPEG_MARKER) {
        osSyncPrintf("JPEGデータを展開します\n");        // "Expanding jpeg data"
        osSyncPrintf("JPEGデータアドレス %08x\n", data); // "Jpeg data address %08x"
        // "Work buffer address (Z buffer) %08x"
        osSyncPrintf("ワークバッファアドレス（Ｚバッファ）%08x\n", gZBuffer);

        time = osGetTime();
        if (!Jpeg_Decode(data, gZBuffer, gGfxSPTaskOutputBuffer, sizeof(gGfxSPTaskOutputBuffer))) {
            time = osGetTime() - time;

            // "Success... I think. time = %6.3f ms"
            osSyncPrintf("成功…だと思う。 time = %6.3f ms \n", OS_CYCLES_TO_USEC(time) / 1000.0f);
            // "Writing back to original address from work buffer."
            osSyncPrintf("ワークバッファから元のアドレスに書き戻します。\n");
            // "If the original buffer size isn't at least 150kb, it will be out of control."
            osSyncPrintf("元のバッファのサイズが150キロバイト無いと暴走するでしょう。\n");

            _custom_bcopy(gZBuffer, data, sizeof(gZBuffer));
        } else {
            osSyncPrintf("失敗！なんで〜\n"); // "Failure! Why is it 〜"
        }
    }

    return 0;
}
