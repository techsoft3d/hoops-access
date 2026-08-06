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
/* f2cutil utility functions header file */
#ifndef F2CUTIL_DEF
#define F2CUTIL_DEF

typedef double doublereal;
typedef float real;
typedef int ftnlen;

#define TRUE_  1
#define FALSE_ 0

#include "sam/base/basedefs.h"
#include "sam/base/system.h"
#ifdef VKI_F2C_INTEGER64
typedef Vlong integer;
typedef Vlong logical;
#else
typedef int integer;
typedef int logical;
#endif

#ifdef abs
#undef abs
#endif
#ifdef dabs
#undef dabs
#endif
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif
#define abs(x)         ((x) >= 0 ? (x) : -(x))
#define dabs(x)        (doublereal) abs(x)
#define min(a, b)      ((a) <= (b) ? (a) : (b))
#define max(a, b)      ((a) >= (b) ? (a) : (b))
#define dmin(a, b)     (doublereal) min(a, b)
#define dmax(a, b)     (doublereal) max(a, b)
#define bit_test(a, b) ((a) >> (b) & 1)

#ifdef __cplusplus
extern "C" {
#endif

VKI_EXTERN void
vki_s_copy(char* a, const char* b, long la, long lb);
VKI_EXTERN int
vki_s_cmp(const char* a0, const char* b0, long la, long lb);
VKI_EXTERN void
vki_s_cat(char* lp, const char* rpp[], int rnp[], int* np, long ll);
VKI_EXTERN int
vki_i_len(char* s, long n);
VKI_EXTERN int
vki_i_indx(char* a, char* b, long la, long lb);
VKI_EXTERN double
vki_pow_dd(double* ap, double* bp);
VKI_EXTERN double
vki_r_mod(float* x, float* y);
VKI_EXTERN double
vki_r_sign(float* a, float* b);
VKI_EXTERN double
vki_r_lg10(float* x);
VKI_EXTERN int
vki_pow_ii(int* i, int* j);
VKI_EXTERN double
vki_pow_di(double* a, int* j);
VKI_EXTERN double
vki_d_sign(double* a, double* b);
VKI_EXTERN double
vki_d_lg10(double* x);

#ifdef __cplusplus
}
#endif

#endif
