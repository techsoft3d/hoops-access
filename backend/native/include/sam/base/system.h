/*********************************************************************
 *                                                                   *
 *                          DevTools 3.1.0                           *
 *                                                                   *
 *  These coded instructions, statements and computer programs       *
 *  contain unpublished proprietary information of Tech Soft 3D,     *
 *  and are protected by Federal copyright law.  They may not be     *
 *  disclosed to third parties or copied or duplicated in any form,  *
 *  in whole or in part, without the prior written consent of        *
 *  Tech Soft 3D.                                                    *
 *                                                                   *
 *                 Copyright (C) 2026, Tech Soft 3D                  *
 *                                                                   *
 *********************************************************************/
/* system wide header file */
#ifndef SYSTEM_DEF
#define SYSTEM_DEF

/* POSIX definitions */
#ifdef VKI_ARCH_LINUX
#if !defined(_XOPEN_SOURCE) && !defined(_POSIX_C_SOURCE)
#if defined(__cplusplus)
#define _XOPEN_SOURCE 700 /* SUS v4, POSIX 1003.1 2008/13 (POSIX 2008/13) */
#elif __STDC_VERSION__ >= 199901L
#define _XOPEN_SOURCE 700 /* SUS v4, POSIX 1003.1 2008/13 (POSIX 2008/13) */
#else
#define _XOPEN_SOURCE 500 /* SUS v2, POSIX 1003.1 1997 */
#endif                    /* __STDC_VERSION__ */
#endif                    /* !_XOPEN_SOURCE && !_POSIX_C_SOURCE */
#endif

/* C includes */
#include <string.h>
#include <stddef.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/* convenient constants */
#define PI              3.141592653589793238462643383279502884197169399
#define SQUAREROOTTWO   1.414213562373095048801688724209698078569671875
#define SQUAREROOTTHREE 1.7320508075688772
#define ONETHIRD        0.333333333333333333333333333333333333333333333
#define SMALL           1.0E-12
#define LARGE           1.0E+12
/* these are conservative single and double precisions */
#define SPRE 2.0E-07
#define DPRE 4.0E-16
/* these are conservative min and max floats */
#define SEPS 1.0E-37
#define SBIG 1.0E+37
/* these are floating point comparisions near unity */
#define SEQ(a, b) (ABS((a) - (b)) < SPRE)
#define DEQ(a, b) (ABS((a) - (b)) < DPRE)
/* these are floating point comparisions relative */
#define SEQR(a, b) (fabs((a) - (b)) < fabs((b) * SPRE))
#define DEQR(a, b) (fabs((a) - (b)) < fabs((b) * DPRE))

/* utility macros */
#define IND2(n, i, j)                 (n) * (j) + (i)
#define IND3(n, m, i, j, k)           (n) * (m) * (k) + (n) * (j) + (i)
#define CIND2(n1, j, i)               (n1) * (j) + (i)
#define CIND3(n2, n1, k, j, i)        (n2) * (n1) * (k) + (n1) * (j) + (i)
#define CIND4(n3, n2, n1, l, k, j, i) (n3) * (n2) * (n1) * (l) + (n2) * (n1) * (k) + (n1) * (j) + (i)
#define MAX2(x, y)                    (((x) > (y)) ? (x) : (y))
#define MIN2(x, y)                    (((x) < (y)) ? (x) : (y))
#define MAX3(x, y, z)                 MAX2((MAX2(x, y)), (z))
#define MIN3(x, y, z)                 MIN2((MIN2(x, y)), (z))
#define ABS(x)                        (((x) >= 0) ? (x) : -(x))
#define CLAMP(v, l, h)                ((v) < (l) ? (l) : (v) > (h) ? (h) : v)
#define ZSIGN(x)                      (((x) < 0) ? -1 : (a) > 0 ? 1 : 0)
#define SIGN(x)                       (((x) < 0) ? -1 : 1)
#define DOT2(x, y)                    ((double)(x)[0] * (y)[0] + (double)(x)[1] * (y)[1])
#define DOT2F(x, y)                   ((Vfloat)DOT2(x, y))
#define DOT3TYPE(x, y, t)             ((t)((x)[0] * (y)[0]) + (t)((x)[1] * (y)[1]) + (t)((x)[2] * (y)[2]))
#define DOT3(x, y)                    DOT3TYPE(x, y, Vdouble)
#define DOT3F(x, y)                   DOT3TYPE(x, y, Vfloat)
#define DOT4(x, y)                    ((double)(x)[0] * (y)[0] + (double)(x)[1] * (y)[1] + (double)(x)[2] * (y)[2] + (double)(x)[3] * (y)[3])
#define DOT4F(x, y)                   ((Vfloat)DOT4(x, y))
#define DOT6(x, y)                                                                                           \
    ((double)(x)[0] * (y)[0] + (double)(x)[1] * (y)[1] + (double)(x)[2] * (y)[2] + (double)(x)[3] * (y)[3] + \
     (double)(x)[4] * (y)[4] + (double)(x)[5] * (y)[5])
#define IPOWER(x, y, z)           \
    {                             \
        int i;                    \
        (z) = 1;                  \
        for (i = 0; i < (y); i++) \
            (z) *= (x);           \
    }
#define LERP(x, s, y, dst) (dst) = (x) + (s) * ((y) - (x))
#define LERP2(x, s, y, dst)            \
    LERP((x)[0], s, (y)[0], (dst)[0]); \
    LERP((x)[1], s, (y)[1], (dst)[1])

#define SET2(d, x, y)     (d)[0] = (x), (d)[1] = (y)
#define SET3(d, x, y, z)  (d)[0] = (x), (d)[1] = (y), (d)[2] = (z)
#define SET3F(d, x, y, z) SET3(d, (Vfloat)(x), (Vfloat)(y), (Vfloat)(z))
#define SADD2(x, s, y)     \
    (y)[0] = (x)[0] + (s); \
    (y)[1] = (x)[1] + (s)
#define SADD2TOTYPE(x, s, y, t) \
    (y)[0] = (t)((x)[0] + (s)); \
    (y)[1] = (t)((x)[1] + (s))
#define SADD2TOVFLOAT(x, s, y) SADD2TOTYPE(x, s, y, Vfloat)
#define SADD3(x, s, y)     \
    (y)[0] = (x)[0] + (s); \
    (y)[1] = (x)[1] + (s); \
    (y)[2] = (x)[2] + (s)
#define SADD3TOTYPE(x, s, y, t) \
    (y)[0] = (t)((x)[0] + (s)); \
    (y)[1] = (t)((x)[1] + (s)); \
    (y)[2] = (t)((x)[2] + (s))
#define SADD3TOVFLOAT(x, s, y) SADD3TOTYPE(x, s, y, Vfloat)
#define MOVE2(x, y)  \
    (y)[0] = (x)[0]; \
    (y)[1] = (x)[1]
#define MOVE2TOTYPE(x, y, t) \
    (y)[0] = (t)(x)[0];      \
    (y)[1] = (t)(x)[1]
#define MOVE2TOVFLOAT(x, y) MOVE2TOTYPE(x, y, Vfloat)
#define MOVE3(x, y)  \
    (y)[0] = (x)[0]; \
    (y)[1] = (x)[1]; \
    (y)[2] = (x)[2]
#define MOVE3TOTYPE(x, y, t) \
    (y)[0] = (t)(x)[0];      \
    (y)[1] = (t)(x)[1];      \
    (y)[2] = (t)(x)[2]
#define MOVE3TOVFLOAT(x, y) MOVE3TOTYPE(x, y, Vfloat)
#define MOVE3TOVINT(x, y)   MOVE3TOTYPE(x, y, Vint)
#define GATH3R(x, y) \
    (y)[0] = (x)[0]; \
    (y)[1] = (x)[2]; \
    (y)[2] = (x)[4]
#define SCAT3R(x, y) \
    (y)[0] = (x)[0]; \
    (y)[2] = (x)[1]; \
    (y)[4] = (x)[2]
#define GATH3I(x, y) \
    (y)[0] = (x)[1]; \
    (y)[1] = (x)[3]; \
    (y)[2] = (x)[5]
#define SCAT3I(x, y) \
    (y)[1] = (x)[0]; \
    (y)[3] = (x)[1]; \
    (y)[5] = (x)[2]
#define SMOVE3(x, s, y)    \
    (y)[0] = (s) * (x)[0]; \
    (y)[1] = (s) * (x)[1]; \
    (y)[2] = (s) * (x)[2]
#define MOVE3SEPS(x, y)                                                       \
    (y)[0] = (Vfloat)((x)[0] > SEPS ? (x[0]) : (x)[0] < -SEPS ? (x[0]) : 0.); \
    (y)[1] = (Vfloat)((x)[1] > SEPS ? (x[1]) : (x)[1] < -SEPS ? (x[1]) : 0.); \
    (y)[2] = (Vfloat)((x)[2] > SEPS ? (x[2]) : (x)[2] < -SEPS ? (x[2]) : 0.)
#define MOVE4(x, y)  \
    (y)[0] = (x)[0]; \
    (y)[1] = (x)[1]; \
    (y)[2] = (x)[2]; \
    (y)[3] = (x)[3]
#define MOVE3f(x, y)         \
    (y)[0] = (Vfloat)(x)[0]; \
    (y)[1] = (Vfloat)(x)[1]; \
    (y)[2] = (Vfloat)(x)[2]
#define MMOVE3(x, y)  \
    (y)[0] = -(x)[0]; \
    (y)[1] = -(x)[1]; \
    (y)[2] = -(x)[2]
#define PLUS2(x, y)   \
    (y)[0] += (x)[0]; \
    (y)[1] += (x)[1]
#define PLUS3(x, y)   \
    (y)[0] += (x)[0]; \
    (y)[1] += (x)[1]; \
    (y)[2] += (x)[2]
#define SPLUS3(x, s, y)     \
    (y)[0] += (s) * (x)[0]; \
    (y)[1] += (s) * (x)[1]; \
    (y)[2] += (s) * (x)[2]
#define PLUS4(x, y)   \
    (y)[0] += (x)[0]; \
    (y)[1] += (x)[1]; \
    (y)[2] += (x)[2]; \
    (y)[3] += (x)[3]
#define MINUS3(x, y)  \
    (y)[0] -= (x)[0]; \
    (y)[1] -= (x)[1]; \
    (y)[2] -= (x)[2]
#define TIMES3(x, y)  \
    (y)[0] *= (x)[0]; \
    (y)[1] *= (x)[1]; \
    (y)[2] *= (x)[2]
#define CROSS3(x, y, z)                         \
    (z)[0] = (x)[1] * (y)[2] - (x)[2] * (y)[1]; \
    (z)[1] = (x)[2] * (y)[0] - (x)[0] * (y)[2]; \
    (z)[2] = (x)[0] * (y)[1] - (x)[1] * (y)[0]
#define CROSS2(x, y)  \
    (y)[0] = -(x)[1]; \
    (y)[1] = (x)[0]
#define SCALE3(x, s) \
    (x)[0] *= (s);   \
    (x)[1] *= (s);   \
    (x)[2] *= (s)
#define SCALE2(x, s) \
    (x)[0] *= (s);   \
    (x)[1] *= (s)
#define ZERO2(x) \
    (x)[0] = 0;  \
    (x)[1] = 0
#define ZERO3(x) \
    (x)[0] = 0;  \
    (x)[1] = 0;  \
    (x)[2] = 0
#define ISEQUAL3(x, y) ((x)[0] == (y)[0] && (x)[1] == (y)[1] && (x)[2] == (y)[2])
#define ISZERO3(x)     ((x)[0] == 0 && (x)[1] == 0 && (x)[2] == 0)
#define ISNONZERO3(x)  ((x)[0] != 0 || (x)[1] != 0 || (x)[2] != 0)
#define ISEQUAL4(x, y) ((x)[0] == (y)[0] && (x)[1] == (y)[1] && (x)[2] == (y)[2] && (x)[3] == (y)[3])
#define ZERO4(x) \
    (x)[0] = 0;  \
    (x)[1] = 0;  \
    (x)[2] = 0;  \
    (x)[3] = 0
#define ZERO6(x) \
    (x)[0] = 0;  \
    (x)[1] = 0;  \
    (x)[2] = 0;  \
    (x)[3] = 0;  \
    (x)[4] = 0;  \
    (x)[5] = 0
#define INIT3(x, s) \
    (x)[0] = (s);   \
    (x)[1] = (s);   \
    (x)[2] = (s)
#define SMUL3(x, s, y)     \
    (y)[0] = (x)[0] * (s); \
    (y)[1] = (x)[1] * (s); \
    (y)[2] = (x)[2] * (s)
#define DIFF2(x, y, z)        \
    (z)[0] = (x)[0] - (y)[0]; \
    (z)[1] = (x)[1] - (y)[1]
#define DIFF2TOTYPE(x, y, z, t)    \
    (z)[0] = (t)((x)[0] - (y)[0]); \
    (z)[1] = (t)((x)[1] - (y)[1])
#define DIFF2TOVFLOAT(x, y, z) DIFF2TOTYPE(x, y, z, Vfloat)
#define DIFF3(x, y, z)        \
    (z)[0] = (x)[0] - (y)[0]; \
    (z)[1] = (x)[1] - (y)[1]; \
    (z)[2] = (x)[2] - (y)[2]
#define DIFF3TOTYPE(x, y, z, t)    \
    (z)[0] = (t)((x)[0] - (y)[0]); \
    (z)[1] = (t)((x)[1] - (y)[1]); \
    (z)[2] = (t)((x)[2] - (y)[2])
#define DIFF3TOVFLOAT(x, y, z) DIFF3TOTYPE(x, y, z, Vfloat)
#define MID2(x, y, z)                \
    (z)[0] = .5 * ((x)[0] + (y)[0]); \
    (z)[1] = .5 * ((x)[1] + (y)[1]);
#define MID2TOTYPE(x, y, z, t)            \
    (z)[0] = (t)(.5 * ((x)[0] + (y)[0])); \
    (z)[1] = (t)(.5 * ((x)[1] + (y)[1]));
#define MID2TOVFLOAT(x, y, z) MID2TOTYPE(x, y, z, Vfloat)
#define MID3(x, y, z)                \
    (z)[0] = .5 * ((x)[0] + (y)[0]); \
    (z)[1] = .5 * ((x)[1] + (y)[1]); \
    (z)[2] = .5 * ((x)[2] + (y)[2])
#define MID3TOTYPE(x, y, z, t)            \
    (z)[0] = (t)(.5 * ((x)[0] + (y)[0])); \
    (z)[1] = (t)(.5 * ((x)[1] + (y)[1])); \
    (z)[2] = (t)(.5 * ((x)[2] + (y)[2]))
#define MID3TOVFLOAT(x, y, z) MID3TOTYPE(x, y, z, Vfloat)
#define CENT3(x, y)                                          \
    (y)[0] = ONETHIRD * ((x)[0][0] + (x)[1][0] + (x)[2][0]); \
    (y)[1] = ONETHIRD * ((x)[0][1] + (x)[1][1] + (x)[2][1]); \
    (y)[2] = ONETHIRD * ((x)[0][2] + (x)[1][2] + (x)[2][2])
#define MUL3(x, y, z)         \
    (z)[0] = (x)[0] * (y)[0]; \
    (z)[1] = (x)[1] * (y)[1]; \
    (z)[2] = (x)[2] * (y)[2]
#define SUM2(x, y, z)         \
    (z)[0] = (x)[0] + (y)[0]; \
    (z)[1] = (x)[1] + (y)[1]
#define SUM3(x, y, z)         \
    (z)[0] = (x)[0] + (y)[0]; \
    (z)[1] = (x)[1] + (y)[1]; \
    (z)[2] = (x)[2] + (y)[2]
#define SUM3TOTYPE(x, y, z, t)     \
    (z)[0] = (t)((x)[0] + (y)[0]); \
    (z)[1] = (t)((x)[1] + (y)[1]); \
    (z)[2] = (t)((x)[2] + (y)[2])
#define SUM3TOVFLOAT(x, y, z) SUM3TOTYPE(x, y, z, Vfloat)
#define ADD2(x, s, y, z)            \
    (z)[0] = (x)[0] + (s) * (y)[0]; \
    (z)[1] = (x)[1] + (s) * (y)[1]
#define ADD2F(x, s, y, z)                     \
    (z)[0] = (Vfloat)((x)[0] + (s) * (y)[0]); \
    (z)[1] = (Vfloat)((x)[1] + (s) * (y)[1])
#define ADD3(x, s, y, z)            \
    (z)[0] = (x)[0] + (s) * (y)[0]; \
    (z)[1] = (x)[1] + (s) * (y)[1]; \
    (z)[2] = (x)[2] + (s) * (y)[2]
#define ADD3F(x, s, y, z)                     \
    (z)[0] = (Vfloat)((x)[0] + (s) * (y)[0]); \
    (z)[1] = (Vfloat)((x)[1] + (s) * (y)[1]); \
    (z)[2] = (Vfloat)((x)[2] + (s) * (y)[2])
#define SUB2(x, s, y, z)            \
    (z)[0] = (x)[0] - (s) * (y)[0]; \
    (z)[1] = (x)[1] - (s) * (y)[1]
#define SUB3(x, s, y, z)            \
    (z)[0] = (x)[0] - (s) * (y)[0]; \
    (z)[1] = (x)[1] - (s) * (y)[1]; \
    (z)[2] = (x)[2] - (s) * (y)[2]
#define SUB3F(x, s, y, z)                     \
    (z)[0] = (Vfloat)((x)[0] - (s) * (y)[0]); \
    (z)[1] = (Vfloat)((x)[1] - (s) * (y)[1]); \
    (z)[2] = (Vfloat)((x)[2] - (s) * (y)[2])
#define INTER3(s, x, y, z)                       \
    (z)[0] = (1. - (s)) * (x)[0] + (s) * (y)[0]; \
    (z)[1] = (1. - (s)) * (x)[1] + (s) * (y)[1]; \
    (z)[2] = (1. - (s)) * (x)[2] + (s) * (y)[2]
#define ABS3(x, y)                            \
    (y)[0] = ((x)[0] > 0) ? (x)[0] : -(x)[0]; \
    (y)[1] = ((x)[1] > 0) ? (x)[1] : -(x)[1]; \
    (y)[2] = ((x)[2] > 0) ? (x)[2] : -(x)[2]
#define SIGN3(x, y)                  \
    (y)[0] = ((x)[0] >= 0) ? 1 : -1; \
    (y)[1] = ((x)[1] >= 0) ? 1 : -1; \
    (y)[2] = ((x)[2] >= 0) ? 1 : -1
#define SIGN3TOTYPE(x, y, t)                 \
    (y)[0] = ((x)[0] >= 0) ? (t)1 : (t) - 1; \
    (y)[1] = ((x)[1] >= 0) ? (t)1 : (t) - 1; \
    (y)[2] = ((x)[2] >= 0) ? (t)1 : (t) - 1
#define SIGN3TOVFLOAT(x, y) SIGN3TOTYPE(x, y, Vfloat)

#define ROWPRT3(x, y) printf("%s %16f %16f %16f\n", (y), (x)[0], (x)[1], (x)[2])
#define COLPRT3(x, y) printf("%s\n %16f\n %16f\n %16f\n", (y), (x)[0], (x)[1], (x)[2])
#define MATVEC2(x, y, z)                              \
    (z)[0] = (x)[0][0] * (y)[0] + (x)[1][0] * (y)[1]; \
    (z)[1] = (x)[0][1] * (y)[0] + (x)[1][1] * (y)[1]
#define MATVEC3(x, y, z)                                                   \
    (z)[0] = (x)[0][0] * (y)[0] + (x)[1][0] * (y)[1] + (x)[2][0] * (y)[2]; \
    (z)[1] = (x)[0][1] * (y)[0] + (x)[1][1] * (y)[1] + (x)[2][1] * (y)[2]; \
    (z)[2] = (x)[0][2] * (y)[0] + (x)[1][2] * (y)[1] + (x)[2][2] * (y)[2]
#define MATVEC3TOTYPE(x, y, z, t)                                               \
    (z)[0] = (t)((x)[0][0] * (y)[0] + (x)[1][0] * (y)[1] + (x)[2][0] * (y)[2]); \
    (z)[1] = (t)((x)[0][1] * (y)[0] + (x)[1][1] * (y)[1] + (x)[2][1] * (y)[2]); \
    (z)[2] = (t)((x)[0][2] * (y)[0] + (x)[1][2] * (y)[1] + (x)[2][2] * (y)[2])
#define MATVEC3TOVFLOAT(x, y, z) MATVEC3TOTYPE(x, y, z, Vfloat)
#define MATTVEC3(x, y, z)                                                  \
    (z)[0] = (x)[0][0] * (y)[0] + (x)[0][1] * (y)[1] + (x)[0][2] * (y)[2]; \
    (z)[1] = (x)[1][0] * (y)[0] + (x)[1][1] * (y)[1] + (x)[1][2] * (y)[2]; \
    (z)[2] = (x)[2][0] * (y)[0] + (x)[2][1] * (y)[1] + (x)[2][2] * (y)[2]
/* symmetrize a 3x3 matrix */
#define MATSYM3(x)         \
    (x)[1][0] = (x)[0][1]; \
    (x)[2][0] = (x)[0][2]; \
    (x)[2][1] = (x)[1][2];
/* move a 2x2 matrix */
#define MATMOV2(x, y)      \
    MOVE2((x)[0], (y)[0]); \
    MOVE2((x)[1], (y)[1])
/* move a 3x3 matrix */
#define MATMOV3(x, y)      \
    MOVE3((x)[0], (y)[0]); \
    MOVE3((x)[1], (y)[1]); \
    MOVE3((x)[2], (y)[2])
#define MATMOV3TOTYPE(x, y, t)      \
    MOVE3TOTYPE((x)[0], (y)[0], t); \
    MOVE3TOTYPE((x)[1], (y)[1], t); \
    MOVE3TOTYPE((x)[2], (y)[2], t)
#define MATMOV3TOVFLOAT(x, y) MATMOV3TOTYPE(x, y, Vfloat)
#define MATMOV3SEPS(x, y)      \
    MOVE3SEPS((x)[0], (y)[0]); \
    MOVE3SEPS((x)[1], (y)[1]); \
    MOVE3SEPS((x)[2], (y)[2])
/* move a 4x4 matrix */
#define MATMOV4(x, y)      \
    MOVE4((x)[0], (y)[0]); \
    MOVE4((x)[1], (y)[1]); \
    MOVE4((x)[2], (y)[2]); \
    MOVE4((x)[3], (y)[3])
#define UNIT3TYPE(x, t)                     \
    {                                       \
        Vdouble lengthUnit3 = MAG3((x));    \
        if (lengthUnit3 != 0.) {            \
            lengthUnit3 = 1. / lengthUnit3; \
            (x)[0] *= (t)lengthUnit3;       \
            (x)[1] *= (t)lengthUnit3;       \
            (x)[2] *= (t)lengthUnit3;       \
        }                                   \
    }
#define UNIT3(x)  UNIT3TYPE(x, Vdouble)
#define UNIT3F(x) UNIT3TYPE(x, Vfloat)
#define UNIT2TYPE(x, t)                     \
    {                                       \
        double lengthUnit2 = MAG2((x));     \
        if (lengthUnit2 != 0.) {            \
            lengthUnit2 = 1. / lengthUnit2; \
            (x)[0] *= (t)lengthUnit2;       \
            (x)[1] *= (t)lengthUnit2;       \
        }                                   \
    }
#define UNIT2(x)  UNIT2TYPE(x, Vdouble)
#define UNIT2F(x) UNIT2TYPE(x, Vfloat)
#define TENSOR3(x, y)      \
    (y)[0][0] = (x)[0];    \
    (y)[1][1] = (x)[1];    \
    (y)[2][2] = (x)[2];    \
    (y)[1][0] = (x)[3];    \
    (y)[2][1] = (x)[4];    \
    (y)[0][2] = (x)[5];    \
    (y)[0][1] = (y)[1][0]; \
    (y)[1][2] = (y)[2][1]; \
    (y)[2][0] = (y)[0][2]
#define VECTOR6(x, y)   \
    (y)[0] = (x)[0][0]; \
    (y)[1] = (x)[1][1]; \
    (y)[2] = (x)[2][2]; \
    (y)[3] = (x)[1][0]; \
    (y)[4] = (x)[2][1]; \
    (y)[5] = (x)[0][2]
#define MATRIX3(x, y)   \
    (y)[0][0] = (x)[0]; \
    (y)[0][1] = (x)[1]; \
    (y)[0][2] = (x)[2]; \
    (y)[1][0] = (x)[3]; \
    (y)[1][1] = (x)[4]; \
    (y)[1][2] = (x)[5]; \
    (y)[2][0] = (x)[6]; \
    (y)[2][1] = (x)[7]; \
    (y)[2][2] = (x)[8]
#define IDENT2(x)   \
    (x)[0][0] = 1.; \
    x[0][1] = 0.;   \
    (x)[1][0] = 0.; \
    x[1][1] = 1.
#define IDENT3(x)   \
    (x)[0][0] = 1.; \
    x[0][1] = 0.;   \
    x[0][2] = 0.;   \
    (x)[1][0] = 0.; \
    x[1][1] = 1.;   \
    x[1][2] = 0.;   \
    (x)[2][0] = 0.; \
    x[2][1] = 0.;   \
    x[2][2] = 1.
#define IDENT4(x)   \
    (x)[0][0] = 1.; \
    x[0][1] = 0.;   \
    x[0][2] = 0.;   \
    x[0][3] = 0.;   \
    (x)[1][0] = 0.; \
    x[1][1] = 1.;   \
    x[1][2] = 0.;   \
    x[1][3] = 0.;   \
    (x)[2][0] = 0.; \
    x[2][1] = 0.;   \
    x[2][2] = 1.;   \
    x[2][3] = 0.;   \
    (x)[3][0] = 0.; \
    x[3][1] = 0.;   \
    x[3][2] = 0.;   \
    x[3][3] = 1.;
#define MATPRT2(x, y)                             \
    printf("%s\n", (y));                          \
    printf(" %16f %16f\n", (x)[0][0], (x)[1][0]); \
    printf(" %16f %16f\n", (x)[0][1], (x)[1][1])
#define MATPRT3(x, y)                                             \
    printf("%s\n", (y));                                          \
    printf(" %16f %16f %16f\n", (x)[0][0], (x)[1][0], (x)[2][0]); \
    printf(" %16f %16f %16f\n", (x)[0][1], (x)[1][1], (x)[2][1]); \
    printf(" %16f %16f %16f\n", (x)[0][2], (x)[1][2], (x)[2][2])
#define ZERON(x, n)                     \
    {                                   \
        int i_i;                        \
        for (i_i = 0; i_i < (n); i_i++) \
            (x)[i_i] = 0;               \
    }
#define INITN(x, s, n)                  \
    {                                   \
        int i_i;                        \
        for (i_i = 0; i_i < (n); i_i++) \
            (x)[i_i] = (s);             \
    }
#define SCALEN(x, s, n)                 \
    {                                   \
        int i_i;                        \
        for (i_i = 0; i_i < (n); i_i++) \
            (x)[i_i] = (x)[i_i] * (s);  \
    }
#define MOVEN(x, y, n)                  \
    {                                   \
        int i_i;                        \
        for (i_i = 0; i_i < (n); i_i++) \
            (y)[i_i] = (x)[i_i];        \
    }
#define MOVENTOTYPE(x, y, n, t)         \
    {                                   \
        int i_i;                        \
        for (i_i = 0; i_i < (n); i_i++) \
            (y)[i_i] = (t)(x)[i_i];     \
    }
#define MOVENTOVFLOAT(x, y, n) MOVENTOTYPE(x, y, n, Vfloat)
#define MOVENTOVINT(x, y, n)   MOVENTOTYPE(x, y, n, Vint)

#define MOVE3N(x, y, n)                   \
    {                                     \
        int i_i;                          \
        for (i_i = 0; i_i < (n); i_i++) { \
            (y)[i_i][0] = (x)[i_i][0];    \
            (y)[i_i][1] = (x)[i_i][1];    \
            (y)[i_i][2] = (x)[i_i][2];    \
        }                                 \
    }
#define MOVE3NTOTYPE(x, y, n, t)          \
    {                                     \
        int i_i;                          \
        for (i_i = 0; i_i < (n); i_i++) { \
            (y)[i_i][0] = (t)(x)[i_i][0]; \
            (y)[i_i][1] = (t)(x)[i_i][1]; \
            (y)[i_i][2] = (t)(x)[i_i][2]; \
        }                                 \
    }
#define MOVE3NTOVFLOAT(x, y, n) MOVE3NTOTYPE(x, y, n, Vfloat)
#define DETM3(x, y, z)                                                                             \
    ((x)[0] * ((y)[1] * (z)[2] - (z)[1] * (y)[2]) - (y)[0] * ((x)[1] * (z)[2] - (z)[1] * (x)[2]) + \
     (z)[0] * ((x)[1] * (y)[2] - (y)[1] * (x)[2]))

#define MAG2(x)    sqrt((((double)(x)[0] * (x)[0]) + ((double)(x)[1] * (x)[1])))
#define MAG2F(x)   (Vfloat)(MAG2(x))
#define MAG3(x)    sqrt((((double)(x)[0] * (x)[0]) + ((double)(x)[1] * (x)[1]) + ((double)(x)[2] * (x)[2])))
#define MAG3F(x)   (Vfloat)(MAG3(x))
#define MAG3SQR(x) ((((double)(x)[0] * (x)[0]) + ((double)(x)[1] * (x)[1]) + ((double)(x)[2] * (x)[2])))
#define LEN3(x, y)                                                                                            \
    sqrt((((double)((x)[0] - (y)[0]) * ((x)[0] - (y)[0])) + ((double)((x)[1] - (y)[1]) * ((x)[1] - (y)[1])) + \
          ((double)((x)[2] - (y)[2]) * ((x)[2] - (y)[2]))))
#define LEN3SQR(x, y)                                                                                    \
    (((double)((x)[0] - (y)[0]) * ((x)[0] - (y)[0])) + ((double)((x)[1] - (y)[1]) * ((x)[1] - (y)[1])) + \
     ((double)((x)[2] - (y)[2]) * ((x)[2] - (y)[2])))

#define DEG2RAD(d)  ((d) * PI / 180.)
#define DEG2RADF(d) ((Vfloat)(DEG2RAD(d)))
#define DEG2RAD3(d)         \
    (d)[0] = DEG2RAD(d[0]); \
    (d)[1] = DEG2RAD(d[1]); \
    (d)[2] = DEG2RAD(d[2])
#define RAD2DEG(r)  ((r) * 180. / PI)
#define RAD2DEGF(r) ((Vfloat)(RAD2DEG(r)))

#define RGBA(R, G, B, A) ((((R) & 0xff) << 0) | (((G) & 0xff) << 8) | (((B) & 0xff) << 16) | (((A) & 0xff) << 24))
#define RGB1PACK(rgba, c) \
    (rgba) = (0xff << 24) + ((int)(255.5 * (c)[2]) << 16) + ((int)(255.5 * (c)[1]) << 8) + (int)(255.5 * (c)[0])
#define RGBAPACK(rgba, c) \
    (rgba) = ((int)(255.5 * (c)[3]) << 24) + ((int)(255.5 * (c)[2]) << 16) + ((int)(255.5 * (c)[1]) << 8) + (int)(255.5 * (c)[0])
#define RGBCHAR(rgb, c)                \
    (c)[0] = (Vuchar)(255 * (rgb)[0]); \
    (c)[1] = (Vuchar)(255 * (rgb)[1]); \
    (c)[2] = (Vuchar)(255 * (rgb)[2])
#define RGBACHAR(rgb, c)               \
    (c)[0] = (Vuchar)(255 * (rgb)[0]); \
    (c)[1] = (Vuchar)(255 * (rgb)[1]); \
    (c)[2] = (Vuchar)(255 * (rgb)[2]); \
    (c)[3] = (Vuchar)(255 * (rgb)[3])
#define CHARRGB(c, rgb)                       \
    (rgb)[0] = (Vfloat)(.003921569 * (c)[0]); \
    (rgb)[1] = (Vfloat)(.003921569 * (c)[1]); \
    (rgb)[2] = (Vfloat)(.003921569 * (c)[2])
#define CHARRGBA(c, rgb)                      \
    (rgb)[0] = (Vfloat)(.003921569 * (c)[0]); \
    (rgb)[1] = (Vfloat)(.003921569 * (c)[1]); \
    (rgb)[2] = (Vfloat)(.003921569 * (c)[2]); \
    (rgb)[3] = (Vfloat)(.003921569 * (c)[3])
#define RGBAVECT(c, rgba)                                            \
    (c)[0] = (Vfloat)(.00392156862 * ((rgba) & 0x000000ff));         \
    (c)[1] = (Vfloat)(.00392156862 * (((rgba) & 0x0000ff00) >> 8));  \
    (c)[2] = (Vfloat)(.00392156862 * (((rgba) & 0x00ff0000) >> 16)); \
    (c)[3] = (Vfloat)(.00392156862 * (((rgba) & 0xff000000) >> 24))
#define UNITPACK(rgb, c) (rgb) = ((int)(255.5 * (c)[2]) << 16) + ((int)(255.5 * (c)[1]) << 8) + (int)(255.5 * (c)[0])
#define UNITHTML(rgb, c) (rgb) = ((int)(255.5 * (c)[0]) << 16) + ((int)(255.5 * (c)[1]) << 8) + (int)(255.5 * (c)[2])
#define UNITVECT(c, rgb)                                         \
    (c)[0] = (Vfloat)(.00392156862 * ((rgb) & 0x0000ff));        \
    (c)[1] = (Vfloat)(.00392156862 * (((rgb) & 0x00ff00) >> 8)); \
    (c)[2] = (Vfloat)(.00392156862 * (((rgb) & 0xff0000) >> 16))
#define UNITTRUN(rgb, c) \
    (rgb) = (((int)(255 * (c)[2]) >> 6) << 4) + (((int)(255 * (c)[1]) >> 6) << 2) + ((int)(255 * (c)[0]) >> 6)
/* 8 bits per component */
#define NORMPACK(n, c) (n) = ((int)(127 * (c)[2] + 127) << 16) + ((int)(127 * (c)[1] + 127) << 8) + (int)(127 * (c)[0] + 127)
#define NORMVECT(c, n)                                   \
    (c)[0] = .0078431 * (((n) & 0x0000ff) - 127);        \
    (c)[1] = .0078431 * ((((n) & 0x00ff00) >> 8) - 127); \
    (c)[2] = .0078431 * ((((n) & 0xff0000) >> 16) - 127)
#define NORMVECTF(c, n)                                   \
    (c)[0] = .0078431F * (((n) & 0x0000ff) - 127);        \
    (c)[1] = .0078431F * ((((n) & 0x00ff00) >> 8) - 127); \
    (c)[2] = .0078431F * ((((n) & 0xff0000) >> 16) - 127)
/* 10 bits per component */
#define NORMPACKEXT(n, c) (n) = ((int)(511 * (c)[2] + 511) << 20) + ((int)(511 * (c)[1] + 511) << 10) + (int)(511 * (c)[0] + 511)
#define NORMVECTEXT(c, n)                                                   \
    (c)[0] = (Vfloat)(.00195694716 * (((n) & 0x000003ff) - 511LL));         \
    (c)[1] = (Vfloat)(.00195694716 * ((((n) & 0x000ffc00) >> 10) - 511LL)); \
    (c)[2] = (Vfloat)(.00195694716 * ((((n) & 0x3ff00000) >> 20) - 511LL))
#define NORMCHAR(v, vb)               \
    (vb)[0] = (Vschar)(127 * (v)[0]); \
    (vb)[1] = (Vschar)(127 * (v)[1]); \
    (vb)[2] = (Vschar)(127 * (v)[2]); \
    (vb)[3] = 0
#define CHARNORM(vb, v)                      \
    (v)[0] = (Vfloat)(.007874016 * (vb)[0]); \
    (v)[1] = (Vfloat)(.007874016 * (vb)[1]); \
    (v)[2] = (Vfloat)(.007874016 * (vb)[2])
#define UNITCLAMPTYPE(cc, c, t)                                         \
    (cc)[0] = (c)[0] > (t)1. ? (t)1. : (c)[0] < (t)0. ? (t)0. : (c)[0]; \
    (cc)[1] = (c)[1] > (t)1. ? (t)1. : (c)[1] < (t)0. ? (t)0. : (c)[1]; \
    (cc)[2] = (c)[2] > (t)1. ? (t)1. : (c)[2] < (t)0. ? (t)0. : (c)[2]
#define UNITCLAMPF(cc, c) UNITCLAMPTYPE(cc, c, Vfloat)
#define UNITCLAMPD(cc, c) UNITCLAMPTYPE(cc, c, Vdouble)
#define SMALL3(c)                                                     \
    (c)[0] = (c)[0] > SMALL ? (c)[0] : (c)[0] < -SMALL ? (c)[0] : 0.; \
    (c)[1] = (c)[1] > SMALL ? (c)[1] : (c)[1] < -SMALL ? (c)[1] : 0.; \
    (c)[2] = (c)[2] > SMALL ? (c)[2] : (c)[2] < -SMALL ? (c)[2] : 0.
#define SMALL3F(c)                                                     \
    (c)[0] = (c)[0] > SMALL ? (c)[0] : (c)[0] < -SMALL ? (c)[0] : 0.F; \
    (c)[1] = (c)[1] > SMALL ? (c)[1] : (c)[1] < -SMALL ? (c)[1] : 0.F; \
    (c)[2] = (c)[2] > SMALL ? (c)[2] : (c)[2] < -SMALL ? (c)[2] : 0.F
#define SEPS3(c)                                                    \
    (c)[0] = (c)[0] > SEPS ? (c)[0] : (c)[0] < -SEPS ? (c)[0] : 0.; \
    (c)[1] = (c)[1] > SEPS ? (c)[1] : (c)[1] < -SEPS ? (c)[1] : 0.; \
    (c)[2] = (c)[2] > SEPS ? (c)[2] : (c)[2] < -SEPS ? (c)[2] : 0.
#define FUZZ3(x)                                                      \
    {                                                                 \
        double fuzz = SMALL * (fabs(x[0]) + fabs(x[1]) + fabs(x[2])); \
        if (fabs(x[0]) < fuzz)                                        \
            x[0] = 0.;                                                \
        if (fabs(x[1]) < fuzz)                                        \
            x[1] = 0.;                                                \
        if (fabs(x[2]) < fuzz)                                        \
            x[2] = 0.;                                                \
    }

#define SEPSTRUN(s)  (s) > SEPS ? (s) : (s) < -SEPS ? (s) : 0.
#define SEPSTRUNF(s) ((Vfloat)(SEPSTRUN(s)))
#define SMALLTRUN(s) (s) > SMALL ? (s) : (s) < -SMALL ? (s) : 0.

#define TOPOENCODE(a, b, c, d) (((a) << 28) + ((b) << 16) + ((c) << 8) + (d))
#define TOPODECODESHAPE(a)     (((a) >> 28) & 0x000f)
#define TOPODECODEMAXI(a)      (((a) >> 16) & 0x0fff)
#define TOPODECODEMAXJ(a)      (((a) >> 8) & 0x00ff)
#define TOPODECODEMAXK(a)      (((a)) & 0x00ff)

/* true if Lagrange */
#define MAXJLO(a) ((a) & 0xffff)
/* true if missing midsides */
#define MAXJHI(a) ((a) & 0xffff0000)
/* flag missing midside, 1 if set, 0 if not */
#define MAXJHIFLAG(a, b) (((a) >> (16 + (b))) & 1)
/* set missing midside */
#define MAXJHISET(a, b) (a) += (1 << (16 + (b)))

#define GROUP_FLAG(flags, ind) (((flags) >> ((ind) - 1)) & 1)

#define CREATION_FAILURE    (char*)"Creation Failure"
#define WINDOW_NOTCONNECTED (char*)"Window System Not Connected"

/* error handling */
#define VKI_HANDLEERRS(x, y) vut_ErrorCall((x), (y), "")
#define HANDLEERRS(x, y)     vut_ErrorCall((x), (y), "")
#define HANDLEERR0(f, e, s)           \
    {                                 \
        vut_ErrorCall((f), (e), (s)); \
    }
#define HANDLEERR1(f, e, s, d1)   \
    {                             \
        char s_s[1024];           \
        sprintf(s_s, s, d1);      \
        vut_ErrorCall(f, e, s_s); \
    }
#define HANDLEERR2(f, e, s, d1, d2) \
    {                               \
        char s_s[1024];             \
        sprintf(s_s, s, d1, d2);    \
        vut_ErrorCall(f, e, s_s);   \
    }
#define HANDLEERR3(f, e, s, d1, d2, d3) \
    {                                   \
        char s_s[1024];                 \
        sprintf(s_s, s, d1, d2, d3);    \
        vut_ErrorCall(f, e, s_s);       \
    }
#define HANDLEERR4(f, e, s, d1, d2, d3, d4) \
    {                                       \
        char s_s[1024];                     \
        sprintf(s_s, s, d1, d2, d3, d4);    \
        vut_ErrorCall(f, e, s_s);           \
    }
/* print file descriptor */
#define PSTD (vut_PrintFile() ? vut_PrintFile() : stdout)

/* Vtchar strings */
/* UNICODE and _UNICODE must be defined for Windows */
#ifdef VKI_WIDECHAR
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#define TSTRLEN(x)    (int)wcslen(x)
#define TSTRCPY(x, y) wcscpy((x), (y))
#else
#define TSTRLEN(x)    (int)strlen(x)
#define TSTRCPY(x, y) strcpy((x), (y))
#endif
#define TTRUNC(x) (((x) <= 126) ? (Vchar)(x) : ('_'))

/* Fun define */
#define VKI_FUN_DEFINE 1

/* complex arithmetic macros */

#define CSET(a, b)   \
    {                \
        a[0] = b[0]; \
        a[1] = b[1]; \
    }

#define CVSET(a, b, c) \
    {                  \
        a[0] = b;      \
        a[1] = c;      \
    }

#define CRSET(a, b) \
    {               \
        a[0] = b;   \
        a[1] = 0.0; \
    }

#define CADD(a, b, c)       \
    {                       \
        c[0] = a[0] + b[0]; \
        c[1] = a[1] + b[1]; \
    }

#define CSUB(a, b, c)       \
    {                       \
        c[0] = a[0] - b[0]; \
        c[1] = a[1] - b[1]; \
    }

#define CMULT(a, b, c)                    \
    {                                     \
        c[0] = a[0] * b[0] - a[1] * b[1]; \
        c[1] = a[1] * b[0] + a[0] * b[1]; \
    }

#define CINV(a, b)                                  \
    {                                               \
        b[0] = a[0] / (a[0] * a[0] + a[1] * a[1]);  \
        b[1] = -a[1] / (a[0] * a[0] + a[1] * a[1]); \
    }

#define CDIV(a, b, c)                                                     \
    {                                                                     \
        c[0] = (a[0] * b[0] + a[1] * b[1]) / (a[0] * a[0] + a[1] * a[1]); \
        c[1] = (a[1] * b[0] - a[0] * b[1]) / (a[0] * a[0] + a[1] * a[1]); \
    }

#define CEQ(a, b) ((((a[0]) == (b[0])) && (a[1] == b[1])))

#define CNEQ(a, b) ((((a[0]) != (b[0])) || (a[1] != b[1])))

#endif
