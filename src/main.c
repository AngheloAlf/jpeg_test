#include "jpegmodule/z64.h"
#include "jpegmodule/functions.h"
#include "jpegmodule/variables.h"
#include "jpegmodule/jpeg.h"
#include "jpegmodule/room.h"

#include <stdio.h>
#include <stdlib.h>

void setup() {
    sLogScheduler = false;
}

void cleanup() {
}

char* readJpegBuff(const char* jpegPath) {
    FILE* jpegFile = fopen(jpegPath, "rb");
    size_t fileSize = 0;


    fseek(jpegFile, 0L, SEEK_END);
    fileSize = ftell(jpegFile);
    fseek(jpegFile, 0L, SEEK_SET);

    char* jpegBuffer;
    //jpegBuffer = malloc(fileSize * sizeof(char));
    jpegBuffer = malloc(SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(u16));

    fread(jpegBuffer, fileSize, 1, jpegFile);

    fclose(jpegFile);

    return jpegBuffer;
}

void writeOutputBuff(const char* outpath, char* buff) {
    FILE* outfile = fopen(outpath, "wb");

    fwrite(buff, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(u16), 1, outfile);

    fclose(outfile);
}


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s path/to/jpegfile [outpath]\n", argv[0]);
        return 1;
    }

    setup();

    char* jpegPath = argv[1];
    char* jpegBuffer = readJpegBuff(jpegPath);

    s32 status = func_80096238(jpegBuffer);

    if (argc >= 3) {
        writeOutputBuff(argv[2], jpegBuffer);
    }

    free(jpegBuffer);

    if (status != 0) {
        fprintf(stderr, "Something went wrong...\n");
        return 1;
    }

    cleanup();

    return 0;
}
