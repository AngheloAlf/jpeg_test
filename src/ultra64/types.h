#ifndef ULTRA64_TYPES_H
#define ULTRA64_TYPES_H

#define CUSTOM_CODE 1

#ifdef CUSTOM_CODE
#include <stdint.h>
#include <stdlib.h>

typedef int8_t                 s8;
typedef uint8_t                u8;
typedef int16_t                s16;
typedef uint16_t               u16;
typedef int32_t                s32;
typedef uint32_t               u32;
typedef int64_t                s64;
typedef uint64_t               u64;
#else
typedef signed char            s8;
typedef unsigned char          u8;
typedef signed short int       s16;
typedef unsigned short int     u16;
typedef signed int             s32;
typedef unsigned int           u32;
typedef signed long long int   s64;
typedef unsigned long long int u64;
#endif

typedef volatile u8  vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8  vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef float  f32;
typedef double f64;


typedef long int Mtx_t[4][4];
typedef union {
    Mtx_t m;
    long long int forc_structure_alignment;
} Mtx;

typedef float MtxF_t[4][4];
typedef union {
    MtxF_t mf;
    struct {
        float xx, yx, zx, wx,
              xy, yy, zy, wy,
              xz, yz, zz, wz,
              xw, yw, zw, ww;
    };
} MtxF;

#endif
