#include "jpegmodule/z64.h"
#include "jpegmodule/functions.h"
#include "jpegmodule/jpeg.h"
#include "jpegmodule/room.h"

#include <stdio.h>
#include <stdlib.h>

char* readJpegBuff(const char* jpegPath) {
    FILE* jpegFile = fopen(jpegPath, "rb");
    size_t fileSize = 0;


    fseek(jpegFile, 0L, SEEK_END);
    fileSize = ftell(jpegFile);
    fseek(jpegFile, 0L, SEEK_SET);

    char* jpegBuffer = malloc(fileSize * sizeof(char));

    fread(jpegBuffer, fileSize, 1, jpegFile);

    fclose(jpegFile);

    return jpegBuffer;
}


int main(int argc, char** argv) {
    //printf("%i", argc);
    if (argc < 2) {
        printf("Usage: %s <path/to/jpegfile>\n", argv[0]);
        return 1;
    }

    char* jpegPath = argv[1];
    char* jpegBuffer = readJpegBuff(jpegPath);

    s32 status = func_80096238(jpegBuffer);

    free(jpegBuffer);

    if (status != 0) {
        fprintf(stderr, "Something went wrong...\n");
        return 1;
    }

    return 0;
}
