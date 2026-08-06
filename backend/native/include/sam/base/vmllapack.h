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
/* Fortran to C header file */
#ifndef VMLLAPACK_DEF
#define VMLLAPACK_DEF
#include "sam/base/basedefs.h"
#include "sam/base/vututil.h"
#include "sam/base/vmlblas.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Headers for internal VKI alternatives */
VKI_EXTERN int
vki_dlarnv(const int* idist, int* iseed, const int* n, double* x);
VKI_EXTERN int
vki_dlascl(const char* type_, const int* kl, const int* ku, const double* cfrom, const double* cto, const int* m, const int* n,
           double* a, const int* lda, int* info);
VKI_EXTERN int
vki_dlacpy(const char* uplo, const int* m, const int* n, const double* a, const int* lda, double* b, const int* ldb);
VKI_EXTERN int
vki_dlartg(const double* f, const double* g, double* cs, double* sn, double* r_);
VKI_EXTERN int
vki_dlaset(const char* uplo, const int* m, const int* n, const double* alpha, const double* beta, double* a, const int* lda);
VKI_EXTERN int
vki_dorm2r(const char* side, const char* trans, const int* m, const int* n, const int* k, double* a, const int* lda,
           const double* tau, double* c_, const int* ldc, double* work, int* info);
VKI_EXTERN int
vki_dgeqr2(const int* m, const int* n, double* a, const int* lda, double* tau, double* work, int* info);
VKI_EXTERN int
vki_dsteqr(const char* compz, const int* n, double* d_, double* e, double* z_, const int* ldz, double* work, int* info);
VKI_EXTERN double
vki_dlamch(const char* cmach);
VKI_EXTERN int
vki_dlae2(const double* a, const double* b, const double* c_, double* rt1, double* rt2);
VKI_EXTERN int
vki_dlaev2(const double* a, const double* b, const double* c_, double* rt1, double* rt2, double* cs1, double* sn1);
VKI_EXTERN double
vki_dlapy2(const double* x, const double* y);
VKI_EXTERN double
vki_dlanst(const char* norm, const int* n, const double* d_, const double* e);
VKI_EXTERN int
vki_dlasrt(const char* id, const int* n, double* d_, int* info);
VKI_EXTERN int
vki_dlasr(const char* side, const char* pivot, const char* direct, const int* m, const int* n, const double* c_, const double* s,
          double* a, const int* lda);
VKI_EXTERN int
vki_lsame(const char* ca, const char* cb);

#if defined(VKI_LIBAPI_BLASMKL_SEQUENTIAL) || defined(VKI_LIBAPI_BLASMKL_THREAD)
#ifdef VKI_LIBAPI_BLASMKL_ILP64
#ifndef MKL_ILP64
#define MKL_ILP64
#endif
#endif
#include "mkl.h"
typedef MKL_INT lapackint;
#ifdef VKI_LIBAPI_BLASMKL_ILP64
/*
 * BLAS interface uses 32-bit integers but calls to BLAS use 64-bit integers
 */
static inline void
LAPACK_dpotrf(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vint* arg5)
{
    lapackint larg2 = (lapackint) * (arg2);
    lapackint larg4 = (lapackint) * (arg4);
    lapackint larg5;
    dpotrf(arg1, &larg2, arg3, &larg4, &larg5);
    *arg5 = (Vint)larg5;
}
static inline void
LAPACK_dgesvd(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
              Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11, Vdouble* arg12, Vint* arg13, Vint* arg14)
{
    lapackint larg3 = (lapackint) * (arg3);
    lapackint larg4 = (lapackint) * (arg4);
    lapackint larg6 = (lapackint) * (arg6);
    lapackint larg9 = (lapackint) * (arg9);
    lapackint larg11 = (lapackint) * (arg11);
    lapackint larg13 = (lapackint) * (arg13);
    lapackint larg14 = (lapackint) * (arg14);
    dgesvd(arg1, arg2, &(larg3), &(larg4), arg5, &(larg6), arg7, arg8, &(larg9), arg10, &(larg11), arg12, &(larg13), &(larg14));
    *arg14 = (Vint)larg14;
}
static inline void
LAPACK_dgeqrf(Vint* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7, Vint* arg8)
{
    lapackint larg1 = (lapackint)(*arg1);
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg4 = (lapackint)(*arg4);
    lapackint larg7 = (lapackint)(*arg7);
    lapackint larg8 = (lapackint)(*arg8);
    dgeqrf(&larg1, &larg2, arg3, &larg4, arg5, arg6, &larg7, &larg8);
    *arg8 = (Vint)larg8;
}
static inline void
LAPACK_dormqr(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7, Vdouble* arg8,
              Vdouble* arg9, Vint* arg10, Vdouble* arg11, Vint* arg12, Vint* arg13)
{
    lapackint larg3 = (lapackint)(*arg3);
    lapackint larg4 = (lapackint)(*arg4);
    lapackint larg5 = (lapackint)(*arg5);
    lapackint larg7 = (lapackint)(*arg7);
    lapackint larg10 = (lapackint)(*arg10);
    lapackint larg12 = (lapackint)(*arg12);
    lapackint larg13 = (lapackint)(*arg13);
    dormqr(arg1, arg2, &larg3, &larg4, &larg5, arg6, &larg7, arg8, arg9, &larg10, arg11, &larg12, &larg13);
    *arg13 = (Vint)larg13;
}
static inline void
LAPACK_dsyev(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vdouble* arg4, Vint* arg5, Vdouble* arg6, Vdouble* arg7,
             Vint* arg8, Vint* arg9)
{
    lapackint larg3 = (lapackint)(*arg3);
    lapackint larg5 = (lapackint)(*arg5);
    lapackint larg8 = (lapackint)(*arg8);
    lapackint larg9 = (lapackint)(*arg9);
    dsyev(arg1, arg2, &larg3, arg4, &larg5, arg6, arg7, &larg8, &larg9);
    *(arg9) = (Vint)larg9;
}
static inline void
LAPACK_dsbev(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11)
{
    lapackint larg3 = (lapackint)(*arg3);
    lapackint larg4 = (lapackint)(*arg4);
    lapackint larg6 = (lapackint)(*arg6);
    lapackint larg9 = (lapackint)(*arg9);
    lapackint larg11 = (lapackint)(*arg11);
    dsbev(arg1, arg2, &larg3, &larg4, arg5, &larg6, arg7, arg8, &larg9, arg10, &larg11);
    *arg11 = (Vint)larg11;
}
static inline void
LAPACK_dsyevx(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
              Vdouble* arg8, Vint* arg9, Vint* arg10, Vdouble* arg11, Vint* arg12, Vdouble* arg13, Vdouble* arg14, Vint* arg15,
              Vdouble* arg16, Vint* arg17, Vint* arg18, Vint* arg19, Vint* arg20)
{
    lapackint n;
    lapackint larg4 = (lapackint) * (arg4);
    lapackint larg6 = (lapackint) * (arg6);
    lapackint larg9 = (lapackint) * (arg9);
    lapackint larg10 = (lapackint) * (arg10);
    lapackint larg12 = (lapackint) * (arg12);
    lapackint larg15 = (lapackint) * (arg15);
    lapackint larg17 = (lapackint) * (arg17);
    lapackint* larg18;
    lapackint* larg19;
    lapackint larg20 = (lapackint) * (arg20);
    larg18 = (lapackint*)vut_mallocMem(5 * larg4 * sizeof(lapackint));
    larg19 = (lapackint*)vut_mallocMem(larg4 * sizeof(lapackint));
    dsyevx(arg1, arg2, arg3, &larg4, arg5, &larg6, arg7, arg8, &larg9, &larg10, arg11, &larg12, arg13, arg14, &larg15, arg16,
           &larg17, larg18, larg19, &larg20);
    *(arg12) = (Vint)larg12;
    *(arg20) = (Vint)larg20;
    for (n = 0; n < 5 * larg4; ++n) {
        arg18[n] = (Vint)larg18[n];
    }
    for (n = 0; n < larg4; ++n) {
        arg19[n] = (Vint)larg19[n];
    }
    vut_freeMem(larg18);
    vut_freeMem(larg19);
}
static inline void
LAPACK_dlarnv(Vint* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4)
{
    lapackint larg1 = (lapackint)(*arg1);
    lapackint larg2[4];
    lapackint larg3 = (lapackint)(*arg3);
    larg2[0] = (lapackint)(arg2)[0];
    larg2[1] = (lapackint)(arg2)[1];
    larg2[2] = (lapackint)(arg2)[2];
    larg2[3] = (lapackint)(arg2)[3];
    dlarnv(&larg1, larg2, &larg3, arg4);
    (arg2)[0] = (Vint)(larg2[0]);
    (arg2)[1] = (Vint)(larg2[1]);
    (arg2)[2] = (Vint)(larg2[2]);
    (arg2)[3] = (Vint)(larg2[3]);
}
static inline void
LAPACK_dlascl(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vint* arg7, Vdouble* arg8,
              Vint* arg9, Vint* arg10)
{
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg3 = (lapackint)(*arg3);
    lapackint larg6 = (lapackint)(*arg6);
    lapackint larg7 = (lapackint)(*arg7);
    lapackint larg9 = (lapackint)(*arg9);
    lapackint larg10 = (lapackint)(*arg10);
    dlascl(arg1, &larg2, &larg3, arg4, arg5, &larg6, &larg7, arg8, &larg9, &larg10);
    *(arg10) = (Vint)(larg10);
}
static inline void
LAPACK_dlacpy(const Vchar* arg1, const Vint* arg2, const Vint* arg3, const Vdouble* arg4, const Vint* arg5, Vdouble* arg6,
              const Vint* arg7)
{
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg3 = (lapackint)(*arg3);
    lapackint larg5 = (lapackint)(*arg5);
    lapackint larg7 = (lapackint)(*arg7);
    dlacpy(arg1, &larg2, &larg3, arg4, &larg5, arg6, &larg7);
}
static inline void
LAPACK_dspgv(Vint* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11)
{
    lapackint larg1 = (lapackint) * (arg1);
    lapackint larg4 = (lapackint) * (arg4);
    lapackint larg9 = (lapackint) * (arg9);
    lapackint larg11 = (lapackint) * (arg11);
    dspgv(&(larg1), arg2, arg3, &(larg4), arg5, arg6, arg7, arg8, &(larg9), arg10, &(larg11));
    *arg11 = (Vint)larg11;
}
static inline void
LAPACK_dsygv(const Vint* arg1, const Vchar* arg2, const Vchar* arg3, const Vint* arg4, Vdouble* arg5, const Vint* arg6,
             Vdouble* arg7, const Vint* arg8, Vdouble* arg9, Vdouble* arg10, const Vint* arg11, Vint* arg12)
{
    lapackint larg1 = (lapackint) * (arg1);
    lapackint larg4 = (lapackint) * (arg4);
    lapackint larg6 = (lapackint) * (arg6);
    lapackint larg8 = (lapackint) * (arg8);
    lapackint larg11 = (lapackint) * (arg11);
    lapackint larg12 = (lapackint) * (arg12);
    dsygv(&(larg1), arg2, arg3, &(larg4), arg5, &(larg6), arg7, &(larg8), arg9, arg10, &(larg11), &(larg12));
    *arg12 = (Vint)larg12;
}
static inline void
LAPACK_dsygvx(const Vint* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7,
              Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vdouble* arg11, Vint* arg12, Vint* arg13, Vdouble* arg14, Vint* arg15,
              Vdouble* arg16, Vdouble* arg17, Vint* arg18, Vdouble* arg19, Vint* arg20, Vint* arg21, Vint* arg22, Vint* arg23)
{
    lapackint n;
    lapackint larg1 = (lapackint) * (arg1);
    lapackint larg5 = (lapackint) * (arg5);
    lapackint larg7 = (lapackint) * (arg7);
    lapackint larg9 = (lapackint) * (arg9);
    lapackint larg12 = (lapackint) * (arg12);
    lapackint larg13 = (lapackint) * (arg13);
    lapackint larg15 = (lapackint) * (arg15);
    lapackint larg18 = (lapackint) * (arg18);
    lapackint larg20 = (lapackint) * (arg20);
    lapackint* larg21;
    lapackint* larg22;
    lapackint larg23 = (lapackint) * (arg23);
    larg21 = (lapackint*)vut_mallocMem(5 * larg5 * sizeof(lapackint));
    larg22 = (lapackint*)vut_mallocMem(larg5 * sizeof(lapackint));
    dsygvx(&larg1, arg2, arg3, arg4, &larg5, arg6, &larg7, arg8, &larg9, arg10, arg11, &larg12, &larg13, arg14, &larg15, arg16,
           arg17, &larg18, arg19, &larg20, larg21, larg22, &larg23);
    *arg15 = (Vint)larg15;
    *arg23 = (Vint)larg23;
    for (n = 0; n < 5 * larg5; ++n) {
        arg21[n] = (Vint)larg21[n];
    }
    for (n = 0; n < larg5; ++n) {
        arg22[n] = (Vint)larg22[n];
    }
    vut_freeMem(larg21);
    vut_freeMem(larg22);
}
static inline void
LAPACK_dsytrf(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7, Vint* arg8)
{
    lapackint n;
    lapackint larg2 = (lapackint) * (arg2);
    lapackint* larg5;
    lapackint larg4 = (lapackint) * (arg4);
    lapackint larg7 = (lapackint) * (arg7);
    lapackint larg8 = (lapackint) * (arg8);
    larg5 = (lapackint*)vut_mallocMem(larg2 * sizeof(lapackint));
    dsytrf(arg1, &(larg2), arg3, &(larg4), larg5, arg6, &(larg7), &(larg8));
    for (n = 0; n < larg2; ++n) {
        arg5[n] = (Vint)larg5[n];
    }
    vut_freeMem(larg5);
    *arg8 = (Vint)larg8;
}

static inline void
LAPACK_dgttrs(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7, Vint* arg8,
              Vdouble* arg9, Vint* arg10, Vint* arg11)
{
    lapackint i;
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg3 = (lapackint)(*arg3);
    lapackint* larg8;
    lapackint larg10 = (lapackint)(*arg10);
    lapackint larg11 = (lapackint)(*arg11);
    larg8 = (lapackint*)vut_mallocMem((*arg2) * sizeof(lapackint));
    for (i = 0; i < *(arg2); ++i) {
        larg8[i] = (lapackint)((arg8)[i]);
    }
    dgttrs(arg1, &larg2, &larg3, arg4, arg5, arg6, arg7, larg8, arg9, &larg10, &larg11);
    for (i = 0; i < *(arg2); ++i) {
        (arg8)[i] = (Vint)(larg8[i]);
    }
    vut_freeMem(larg8);
}
static inline void
LAPACK_dgttrf(Vint* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vint* arg7)
{
    lapackint i;
    lapackint larg1 = (lapackint)(*arg1);
    lapackint* larg6;
    lapackint larg7 = (lapackint)(*arg7);
    larg6 = (lapackint*)vut_mallocMem((*arg1) * sizeof(lapackint));
    for (i = 0; i < *(arg1); ++i) {
        larg6[i] = (lapackint)((arg6)[i]);
    }
    dgttrf(&larg1, arg2, arg3, arg4, arg5, larg6, &larg7);
    for (i = 0; i < *(arg1); ++i) {
        (arg6)[i] = (Vint)(larg6[i]);
    }
    vut_freeMem(larg6);
}
static inline void
LAPACK_dlaset(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7)
{
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg3 = (lapackint)(*arg3);
    lapackint larg7 = (lapackint)(*arg7);
    dlaset(arg1, &larg2, &larg3, arg4, arg5, arg6, &larg7);
}
static inline void
LAPACK_dorm2r(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7, Vdouble* arg8,
              Vdouble* arg9, Vint* arg10, Vdouble* arg11, Vint* arg12)
{
    lapackint larg3 = (lapackint)(*arg3);
    lapackint larg4 = (lapackint)(*arg4);
    lapackint larg5 = (lapackint)(*arg5);
    lapackint larg7 = (lapackint)(*arg7);
    lapackint larg10 = (lapackint)(*arg10);
    lapackint larg12 = (lapackint)(*arg12);
    dorm2r(arg1, arg2, &larg3, &larg4, &larg5, arg6, &larg7, arg8, arg9, &larg10, arg11, &larg12);
}
static inline void
LAPACK_dgeqr2(Vint* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7)
{
    lapackint larg1 = (lapackint)(*arg1);
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg4 = (lapackint)(*arg4);
    lapackint larg7 = (lapackint)(*arg7);
    dgeqr2(&larg1, &larg2, arg3, &larg4, arg5, arg6, &larg7);
}
static inline void
LAPACK_dsteqr(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7, Vint* arg8)
{
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg6 = (lapackint)(*arg6);
    lapackint larg8 = (lapackint)(*arg8);
    dsteqr(arg1, &larg2, arg3, arg4, arg5, &larg6, arg7, &larg8);
}
static inline Vdouble
LAPACK_dlamch(const Vchar* arg1)
{
    return dlamch(arg1);
}
static inline void
LAPACK_dlasrt(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4)
{
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg4 = (lapackint)(*arg4);
    dlasrt(arg1, &larg2, arg3, &larg4);
    *arg4 = (Vint)larg4;
}
static inline Vdouble
LAPACK_dlanst(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4)
{
    lapackint larg2 = (lapackint)(*arg2);
    return dlanst(arg1, &larg2, arg3, arg4);
}
static inline void
LAPACK_dlasr(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9)
{
    lapackint larg4 = (lapackint)(*arg4);
    lapackint larg5 = (lapackint)(*arg5);
    lapackint larg9 = (lapackint)(*arg9);
    dlasr(arg1, arg2, arg3, &larg4, &larg5, arg6, arg7, arg8, &larg9);
}
static inline void
LAPACK_dlaev2(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7)
{
    dlaev2(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_dlae2(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5)
{
    dlae2(arg1, arg2, arg3, arg4, arg5);
}
static inline void
LAPACK_dlartg(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5)
{
    dlartg(arg1, arg2, arg3, arg4, arg5);
}
static inline Vdouble
LAPACK_dlapy2(Vdouble* arg1, Vdouble* arg2)
{
    return dlapy2(arg1, arg2);
}
/*
 * BLAS interface uses 64-bit integers but calls to BLAS use 64-bit integers
 */
static inline void
LAPACK_DPOTRF(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vlong* arg5)
{
    dpotrf(arg1, arg2, arg3, arg4, arg5);
}
static inline void
LAPACK_DGESVD(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
              Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vlong* arg11, Vdouble* arg12, Vlong* arg13, Vlong* arg14)
{
    dgesvd(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
}
static inline void
LAPACK_DGEQRF(Vlong* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7, Vlong* arg8)
{
    dgeqrf(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
static inline void
LAPACK_DORMQR(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7,
              Vdouble* arg8, Vdouble* arg9, Vlong* arg10, Vdouble* arg11, Vlong* arg12, Vlong* arg13)
{
    dormqr(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
}
static inline void
LAPACK_DSYEV(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vdouble* arg4, Vlong* arg5, Vdouble* arg6, Vdouble* arg7,
             Vlong* arg8, Vlong* arg9)
{
    dsyev(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
static inline void
LAPACK_DSYEVX(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vlong* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
              Vdouble* arg8, Vlong* arg9, Vlong* arg10, Vdouble* arg11, Vlong* arg12, Vdouble* arg13, Vdouble* arg14,
              Vlong* arg15, Vdouble* arg16, Vlong* arg17, Vlong* arg18, Vlong* arg19, Vlong* arg20)
{
    dsyevx(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18,
           arg19, arg20);
}
static inline void
LAPACK_DSBEV(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
             Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vlong* arg11)
{
    dsbev(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
LAPACK_DLARNV(Vlong* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4)
{
    dlarnv(arg1, arg2, arg3, arg4);
}
static inline void
LAPACK_DLASCL(const Vchar* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vlong* arg7, Vdouble* arg8,
              Vlong* arg9, Vlong* arg10)
{
    dlascl(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
static inline void
LAPACK_DLACPY(const Vchar* arg1, const Vlong* arg2, const Vlong* arg3, const Vdouble* arg4, const Vlong* arg5, Vdouble* arg6,
              const Vlong* arg7)
{
    dlacpy(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_DSPGV(Vlong* arg1, const Vchar* arg2, const Vchar* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vlong* arg11)
{
    dspgv(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
LAPACK_DSYGV(const Vlong* arg1, const Vchar* arg2, const Vchar* arg3, const Vlong* arg4, Vdouble* arg5, const Vlong* arg6,
             Vdouble* arg7, const Vlong* arg8, Vdouble* arg9, Vdouble* arg10, const Vlong* arg11, Vlong* arg12)
{
    dsygv(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
static inline void
LAPACK_DSYGVX(const Vlong* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7,
              Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vdouble* arg11, Vlong* arg12, Vlong* arg13, Vdouble* arg14,
              Vlong* arg15, Vdouble* arg16, Vdouble* arg17, Vlong* arg18, Vdouble* arg19, Vlong* arg20, Vlong* arg21,
              Vlong* arg22, Vlong* arg23)
{
    dsygvx(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18,
           arg19, arg20, arg21, arg22, arg23);
}
static inline void
LAPACK_DSYTRF(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7, Vlong* arg8)
{
    dsytrf(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
static inline void
LAPACK_DGTTRS(const Vchar* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7,
              Vlong* arg8, Vdouble* arg9, Vlong* arg10, Vlong* arg11)
{
    dgttrs(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
LAPACK_DGTTRF(Vlong* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vlong* arg7)
{
    dgttrf(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_DLASET(const Vchar* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7)
{
    dlaset(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_DORM2R(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7,
              Vdouble* arg8, Vdouble* arg9, Vlong* arg10, Vdouble* arg11, Vlong* arg12)
{
    dorm2r(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
static inline void
LAPACK_DGEQR2(Vlong* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7)
{
    dgeqr2(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_DSTEQR(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
              Vlong* arg8)
{
    dsteqr(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
static inline void
LAPACK_DLASRT(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4)
{
    dlasrt(arg1, arg2, arg3, arg4);
}
static inline void
LAPACK_DLASR(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vlong* arg9)
{
    dlasr(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
static inline Vdouble
LAPACK_DLANST(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4)
{
    return dlanst(arg1, arg2, arg3, arg4);
}
#else
/*
 * BLAS interface uses 32-bit integers but calls to BLAS use 32-bit integers
 */
static inline void
LAPACK_dpotrf(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vint* arg5)
{
    dpotrf(arg1, arg2, arg3, arg4, arg5);
}
static inline void
LAPACK_dgesvd(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
              Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11, Vdouble* arg12, Vint* arg13, Vint* arg14)
{
    dgesvd(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
}
static inline void
LAPACK_dgeqrf(Vint* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7, Vint* arg8)
{
    dgeqrf(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
static inline void
LAPACK_dormqr(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7, Vdouble* arg8,
              Vdouble* arg9, Vint* arg10, Vdouble* arg11, Vint* arg12, Vint* arg13)
{
    dormqr(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
}
static inline void
LAPACK_dsyev(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vdouble* arg4, Vint* arg5, Vdouble* arg6, Vdouble* arg7,
             Vint* arg8, Vint* arg9)
{
    dsyev(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
static inline void
LAPACK_dsyevx(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
              Vdouble* arg8, Vint* arg9, Vint* arg10, Vdouble* arg11, Vint* arg12, Vdouble* arg13, Vdouble* arg14, Vint* arg15,
              Vdouble* arg16, Vint* arg17, Vint* arg18, Vint* arg19, Vint* arg20)
{
    dsyevx(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18,
           arg19, arg20);
}
static inline void
LAPACK_dsbev(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11)
{
    dsbev(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
LAPACK_dlarnv(Vint* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4)
{
    dlarnv(arg1, arg2, arg3, arg4);
}
static inline void
LAPACK_dlascl(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vint* arg7, Vdouble* arg8,
              Vint* arg9, Vint* arg10)
{
    dlascl(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
static inline void
LAPACK_dgttrs(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7, Vint* arg8,
              Vdouble* arg9, Vint* arg10, Vint* arg11)
{
    dgttrs(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
LAPACK_dgttrf(Vint* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vint* arg7)
{
    dgttrf(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_dlacpy(const Vchar* arg1, const Vint* arg2, const Vint* arg3, const Vdouble* arg4, const Vint* arg5, Vdouble* arg6,
              const Vint* arg7)
{
    dlacpy(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_dspgv(Vint* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11)
{
    dspgv(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
LAPACK_dsygv(const Vint* arg1, const Vchar* arg2, const Vchar* arg3, const Vint* arg4, Vdouble* arg5, const Vint* arg6,
             Vdouble* arg7, const Vint* arg8, Vdouble* arg9, Vdouble* arg10, const Vint* arg11, Vint* arg12)
{
    dsygv(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
static inline void
LAPACK_dsygvx(const Vint* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7,
              Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vdouble* arg11, Vint* arg12, Vint* arg13, Vdouble* arg14, Vint* arg15,
              Vdouble* arg16, Vdouble* arg17, Vint* arg18, Vdouble* arg19, Vint* arg20, Vint* arg21, Vint* arg22, Vint* arg23)
{
    dsygvx(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18,
           arg19, arg20, arg21, arg22, arg23);
}
static inline void
LAPACK_dsytrf(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7, Vint* arg8)
{
    dsytrf(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
static inline void
LAPACK_dlartg(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5)
{
    dlartg(arg1, arg2, arg3, arg4, arg5);
}
static inline void
LAPACK_dlaset(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7)
{
    dlaset(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_dorm2r(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7, Vdouble* arg8,
              Vdouble* arg9, Vint* arg10, Vdouble* arg11, Vint* arg12)
{
    dorm2r(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
static inline void
LAPACK_dgeqr2(Vint* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7)
{
    dgeqr2(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_dsteqr(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7, Vint* arg8)
{
    dsteqr(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
static inline Vdouble
LAPACK_dlamch(const Vchar* arg1)
{
    return dlamch(arg1);
}
static inline void
LAPACK_dlae2(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5)
{
    dlae2(arg1, arg2, arg3, arg4, arg5);
}
static inline void
LAPACK_dlaev2(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7)
{
    dlaev2(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline Vdouble
LAPACK_dlapy2(Vdouble* arg1, Vdouble* arg2)
{
    return dlapy2(arg1, arg2);
}
static inline Vdouble
LAPACK_dlanst(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4)
{
    return dlanst(arg1, arg2, arg3, arg4);
}
static inline void
LAPACK_dlasrt(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4)
{
    dlasrt(arg1, arg2, arg3, arg4);
}
static inline void
LAPACK_dlasr(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9)
{
    dlasr(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

/*
 * BLAS interface uses 32-bit integers but calls to BLAS use 64-bit integers
 */
static inline void
LAPACK_DPOTRF(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vlong* arg5)
{
    Vint larg2 = (Vint) * (arg2);
    Vint larg4 = (Vint) * (arg4);
    Vint larg5;
    dpotrf(arg1, &larg2, arg3, &larg4, &larg5);
    *arg5 = (Vlong)larg5;
}
static inline void
LAPACK_DGESVD(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
              Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vlong* arg11, Vdouble* arg12, Vlong* arg13, Vlong* arg14)
{
    Vint larg3 = (Vint) * (arg3);
    Vint larg4 = (Vint) * (arg4);
    Vint larg6 = (Vint) * (arg6);
    Vint larg9 = (Vint) * (arg9);
    Vint larg11 = (Vint) * (arg11);
    Vint larg13 = (Vint) * (arg13);
    Vint larg14 = (Vint) * (arg14);
    dgesvd(arg1, arg2, &(larg3), &(larg4), arg5, &(larg6), arg7, arg8, &(larg9), arg10, &(larg11), arg12, &(larg13), &(larg14));
    *arg14 = (Vlong)larg14;
}
static inline void
LAPACK_DGEQRF(Vlong* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7, Vlong* arg8)
{
    Vint iarg1 = (Vint)(*arg1);
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg4 = (Vint)(*arg4);
    Vint iarg7 = (Vint)(*arg7);
    Vint iarg8 = (Vint)(*arg8);
    dgeqrf(&iarg1, &iarg2, arg3, &iarg4, arg5, arg6, &iarg7, &iarg8);
    *arg8 = (Vlong)iarg8;
}
static inline void
LAPACK_DORMQR(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7,
              Vdouble* arg8, Vdouble* arg9, Vlong* arg10, Vdouble* arg11, Vlong* arg12, Vlong* arg13)
{
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg4 = (Vint)(*arg4);
    Vint iarg5 = (Vint)(*arg5);
    Vint iarg7 = (Vint)(*arg7);
    Vint iarg10 = (Vint)(*arg10);
    Vint iarg12 = (Vint)(*arg12);
    Vint iarg13 = (Vint)(*arg13);
    dormqr(arg1, arg2, &iarg3, &iarg4, &iarg5, arg6, &iarg7, arg8, arg9, &iarg10, arg11, &iarg12, &iarg13);
    *arg13 = (Vlong)iarg13;
}
static inline void
LAPACK_DSYEV(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vdouble* arg4, Vlong* arg5, Vdouble* arg6, Vdouble* arg7,
             Vlong* arg8, Vlong* arg9)
{
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg5 = (Vint)(*arg5);
    Vint iarg8 = (Vint)(*arg8);
    Vint iarg9 = (Vint)(*arg9);
    dsyev(arg1, arg2, &iarg3, arg4, &iarg5, arg6, arg7, &iarg8, &iarg9);
    *(arg9) = (Vlong)iarg9;
}
static inline void
LAPACK_DSYEVX(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vlong* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
              Vdouble* arg8, Vlong* arg9, Vlong* arg10, Vdouble* arg11, Vlong* arg12, Vdouble* arg13, Vdouble* arg14,
              Vlong* arg15, Vdouble* arg16, Vlong* arg17, Vlong* arg18, Vlong* arg19, Vlong* arg20)
{
    Vint n;
    Vint larg4 = (Vint) * (arg4);
    Vint larg6 = (Vint) * (arg6);
    Vint larg9 = (Vint) * (arg9);
    Vint larg10 = (Vint) * (arg10);
    Vint larg12 = (Vint) * (arg12);
    Vint larg15 = (Vint) * (arg15);
    Vint larg17 = (Vint) * (arg17);
    Vint* larg18;
    Vint* larg19;
    Vint larg20 = (lapackint) * (arg20);
    larg18 = (lapackint*)vut_mallocMem(5 * (larg4 * sizeof(lapackint)));
    larg19 = (lapackint*)vut_mallocMem(larg4 * sizeof(lapackint));
    dsyevx(arg1, arg2, arg3, &larg4, arg5, &larg6, arg7, arg8, &larg9, &larg10, arg11, &larg12, arg13, arg14, &larg15, arg16,
           &larg17, larg18, larg19, &larg20);
    *(arg12) = (Vlong)larg12;
    *(arg20) = (Vlong)larg20;
    for (n = 0; n < 5 * larg4; ++n) {
        arg18[n] = (Vlong)larg18[n];
    }
    for (n = 0; n < larg4; ++n) {
        arg19[n] = (Vlong)larg19[n];
    }
    vut_freeMem(larg18);
    vut_freeMem(larg19);
}
/*
* DSBEV computes all the eigenvalues and, optionally, eigenvectors of
 a real symmetric band matrix A.
*/
/*
* Parameters
[in]	JOBZ
          JOBZ is CHARACTER*1
          = 'N':  Compute eigenvalues only;
          = 'V':  Compute eigenvalues and eigenvectors.
[in]	UPLO
          UPLO is CHARACTER*1
          = 'U':  Upper triangle of A is stored;
          = 'L':  Lower triangle of A is stored.
[in]	N
          N is INTEGER
          The order of the matrix A.  N >= 0.
[in]	KD
          KD is INTEGER
          The number of superdiagonals of the matrix A if UPLO = 'U',
          or the number of subdiagonals if UPLO = 'L'.  KD >= 0.
[in,out]	AB
          AB is DOUBLE PRECISION array, dimension (LDAB, N)
          On entry, the upper or lower triangle of the symmetric band
          matrix A, stored in the first KD+1 rows of the array.  The
          j-th column of A is stored in the j-th column of the array AB
          as follows:
          if UPLO = 'U', AB(kd+1+i-j,j) = A(i,j) for max(1,j-kd)<=i<=j;
          if UPLO = 'L', AB(1+i-j,j)    = A(i,j) for j<=i<=min(n,j+kd).

          On exit, AB is overwritten by values generated during the
          reduction to tridiagonal form.  If UPLO = 'U', the first
          superdiagonal and the diagonal of the tridiagonal matrix T
          are returned in rows KD and KD+1 of AB, and if UPLO = 'L',
          the diagonal and first subdiagonal of T are returned in the
          first two rows of AB.
[in]	LDAB
          LDAB is INTEGER
          The leading dimension of the array AB.  LDAB >= KD + 1.
[out]	W
          W is DOUBLE PRECISION array, dimension (N)
          If INFO = 0, the eigenvalues in ascending order.
[out]	Z
          Z is DOUBLE PRECISION array, dimension (LDZ, N)
          If JOBZ = 'V', then if INFO = 0, Z contains the orthonormal
          eigenvectors of the matrix A, with the i-th column of Z
          holding the eigenvector associated with W(i).
          If JOBZ = 'N', then Z is not referenced.
[in]	LDZ
          LDZ is INTEGER
          The leading dimension of the array Z.  LDZ >= 1, and if
          JOBZ = 'V', LDZ >= max(1,N).
[out]	WORK
          WORK is DOUBLE PRECISION array, dimension (max(1,3*N-2))
[out]	INFO
          INFO is INTEGER
          = 0:  successful exit
          < 0:  if INFO = -i, the i-th argument had an illegal value
          > 0:  if INFO = i, the algorithm failed to converge; i
                off-diagonal elements of an intermediate tridiagonal
                form did not converge to zero.
*/
static inline void
LAPACK_DSBEV(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
             Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vlong* arg11)
{
    Vint larg3 = (Vint)(*arg3);
    Vint larg4 = (Vint)(*arg4);
    Vint larg6 = (Vint)(*arg6);
    Vint larg9 = (Vint)(*arg9);
    Vint larg11 = (Vint)(*arg11);
    dsbev(arg1, arg2, &larg3, &larg4, arg5, &larg6, arg7, arg8, &larg9, arg10, &larg11);
    *arg11 = (Vlong)larg11;
}
static inline void
LAPACK_DLARNV(Vlong* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4)
{
    Vint iarg1 = (Vint)(*arg1);
    Vint iarg2[4];
    Vint iarg3 = (Vint)(*arg3);
    iarg2[0] = (Vint)(arg2)[0];
    iarg2[1] = (Vint)(arg2)[1];
    iarg2[2] = (Vint)(arg2)[2];
    iarg2[3] = (Vint)(arg2)[3];
    dlarnv(&iarg1, iarg2, &iarg3, arg4);
    (arg2)[0] = (Vlong)(iarg2[0]);
    (arg2)[1] = (Vlong)(iarg2[1]);
    (arg2)[2] = (Vlong)(iarg2[2]);
    (arg2)[3] = (Vlong)(iarg2[3]);
}
static inline void
LAPACK_DLASCL(const Vchar* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vlong* arg7, Vdouble* arg8,
              Vlong* arg9, Vlong* arg10)
{
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg6 = (Vint)(*arg6);
    Vint iarg7 = (Vint)(*arg7);
    Vint iarg9 = (Vint)(*arg9);
    Vint iarg10 = (Vint)(*arg10);
    dlascl(arg1, &iarg2, &iarg3, arg4, arg5, &iarg6, &iarg7, arg8, &iarg9, &iarg10);
    *(arg10) = (Vlong)(iarg10);
}
static inline void
LAPACK_DGTTRS(const Vchar* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7,
              Vlong* arg8, Vdouble* arg9, Vlong* arg10, Vlong* arg11)
{
    Vint i;
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg3 = (Vint)(*arg3);
    Vint* iarg8;
    Vint iarg10 = (Vint)(*arg10);
    Vint iarg11 = (Vint)(*arg11);
    iarg8 = (Vint*)vut_mallocMem((size_t)(*arg2) * sizeof(Vint));
    for (i = 0; i < *(arg2); ++i) {
        iarg8[i] = (Vint)((arg8)[i]);
    }
    dgttrs(arg1, &iarg2, &iarg3, arg4, arg5, arg6, arg7, iarg8, arg9, &iarg10, &iarg11);
    for (i = 0; i < *(arg2); ++i) {
        (arg8)[i] = (Vlong)(iarg8[i]);
    }
    vut_freeMem(iarg8);
}
static inline void
LAPACK_DGTTRF(Vlong* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vlong* arg7)
{
    Vint i;
    Vint iarg1 = (Vint)(*arg1);
    Vint* iarg6;
    Vint iarg7 = (Vint)(*arg7);
    iarg6 = (Vint*)vut_mallocMem((size_t)(*arg1) * sizeof(Vint));
    for (i = 0; i < *(arg1); ++i) {
        iarg6[i] = (Vint)((arg6)[i]);
    }
    dgttrf(&iarg1, arg2, arg3, arg4, arg5, iarg6, &iarg7);
    for (i = 0; i < *(arg1); ++i) {
        (arg6)[i] = (Vlong)(iarg6[i]);
    }
    vut_freeMem(iarg6);
}

/* DLACPY copies all or part of a two - dimensional matrix A to another matrix B.*/
/*
* [in]	UPLO
          UPLO is CHARACTER*1
          Specifies the part of the matrix A to be copied to B.
          = 'U':      Upper triangular part
          = 'L':      Lower triangular part
          Otherwise:  All of the matrix A
[in]	M
          M is INTEGER
          The number of rows of the matrix A.  M >= 0.
[in]	N
          N is INTEGER
          The number of columns of the matrix A.  N >= 0.
[in]	A
          A is DOUBLE PRECISION array, dimension (LDA,N)
          The m by n matrix A.  If UPLO = 'U', only the upper triangle
          or trapezoid is accessed; if UPLO = 'L', only the lower
          triangle or trapezoid is accessed.
[in]	LDA
          LDA is INTEGER
          The leading dimension of the array A.  LDA >= max(1,M).
[out]	B
          B is DOUBLE PRECISION array, dimension (LDB,N)
          On exit, B = A in the locations specified by UPLO.
[in]	LDB
          LDB is INTEGER
          The leading dimension of the array B.  LDB >= max(1,M).
*/

static inline void
LAPACK_DLACPY(const Vchar* uplo, const Vlong* m, const Vlong* n, const Vdouble* A, const Vlong* ldA, Vdouble* B, const Vlong* ldB)
{
    Vint iarg2 = (Vint)(*m);
    Vint iarg3 = (Vint)(*n);
    Vint iarg5 = (Vint)(*ldA);
    Vint iarg7 = (Vint)(*ldB);
    dlacpy(uplo, &iarg2, &iarg3, A, &iarg5, B, &iarg7);
}
static inline void
LAPACK_DSPGV(Vlong* arg1, const Vchar* arg2, const Vchar* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vlong* arg11)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg4 = (Vint) * (arg4);
    Vint larg9 = (Vint) * (arg9);
    Vint larg11 = (Vint) * (arg11);
    dspgv(&(larg1), arg2, arg3, &(larg4), arg5, arg6, arg7, arg8, &(larg9), arg10, &(larg11));
    *arg11 = (Vlong)larg11;
}
static inline void
LAPACK_DSYGV(const Vlong* arg1, const Vchar* arg2, const Vchar* arg3, const Vlong* arg4, Vdouble* arg5, const Vlong* arg6,
             Vdouble* arg7, const Vlong* arg8, Vdouble* arg9, Vdouble* arg10, const Vlong* arg11, Vlong* arg12)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg4 = (Vint) * (arg4);
    Vint larg6 = (Vint) * (arg6);
    Vint larg8 = (Vint) * (arg8);
    Vint larg11 = (Vint) * (arg11);
    Vint larg12 = (Vint) * (arg12);
    dsygv(&(larg1), arg2, arg3, &(larg4), arg5, &(larg6), arg7, &(larg8), arg9, arg10, &(larg11), &(larg12));
    *arg12 = (Vlong)larg12;
}
static inline void
LAPACK_DSYGVX(const Vlong* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7,
              Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vdouble* arg11, Vlong* arg12, Vlong* arg13, Vdouble* arg14,
              Vlong* arg15, Vdouble* arg16, Vdouble* arg17, Vlong* arg18, Vdouble* arg19, Vlong* arg20, Vlong* arg21,
              Vlong* arg22, Vlong* arg23)
{
    Vint n;
    Vint larg1 = (Vint) * (arg1);
    Vint larg5 = (Vint) * (arg5);
    Vint larg7 = (Vint) * (arg7);
    Vint larg9 = (Vint) * (arg9);
    Vint larg12 = (Vint) * (arg12);
    Vint larg13 = (Vint) * (arg13);
    Vint larg15 = (Vint) * (arg15);
    Vint larg18 = (Vint) * (arg18);
    Vint larg20 = (Vint) * (arg20);
    Vint* larg21;
    Vint* larg22;
    Vint larg23 = (Vint) * (arg23);
    larg21 = (Vint*)vut_mallocMem(5 * (larg5 * sizeof(Vint)));
    larg22 = (Vint*)vut_mallocMem(larg5 * sizeof(Vint));
    dsygvx(&larg1, arg2, arg3, arg4, &larg5, arg6, &larg7, arg8, &larg9, arg10, arg11, &larg12, &larg13, arg14, &larg15, arg16,
           arg17, &larg18, arg19, &larg20, larg21, larg22, &larg23);
    *arg15 = (Vlong)larg15;
    *arg23 = (Vlong)larg23;
    for (n = 0; n < 5 * larg5; ++n) {
        arg21[n] = (Vlong)larg21[n];
    }
    for (n = 0; n < larg5; ++n) {
        arg22[n] = (Vlong)larg22[n];
    }
    vut_freeMem(larg21);
    vut_freeMem(larg22);
}
static inline void
LAPACK_DSYTRF(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7, Vlong* arg8)
{
    Vint n;
    Vint larg2 = (Vint) * (arg2);
    Vint* larg5;
    Vint larg4 = (Vint) * (arg4);
    Vint larg7 = (Vint) * (arg7);
    Vint larg8 = (Vint) * (arg8);
    larg5 = (Vint*)vut_mallocMem(larg2 * sizeof(Vint));
    dsytrf(arg1, &(larg2), arg3, &(larg4), larg5, arg6, &(larg7), &(larg8));
    for (n = 0; n < larg2; ++n) {
        arg5[n] = (Vlong)larg5[n];
    }
    vut_freeMem(larg5);
    *arg8 = (Vlong)larg8;
}
static inline void
LAPACK_DLASET(const Vchar* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7)
{
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg7 = (Vint)(*arg7);
    dlaset(arg1, &iarg2, &iarg3, arg4, arg5, arg6, &iarg7);
}
static inline void
LAPACK_DORM2R(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7,
              Vdouble* arg8, Vdouble* arg9, Vlong* arg10, Vdouble* arg11, Vlong* arg12)
{
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg4 = (Vint)(*arg4);
    Vint iarg5 = (Vint)(*arg5);
    Vint iarg7 = (Vint)(*arg7);
    Vint iarg10 = (Vint)(*arg10);
    Vint iarg12 = (Vint)(*arg12);
    dorm2r(arg1, arg2, &iarg3, &iarg4, &iarg5, arg6, &iarg7, arg8, arg9, &iarg10, arg11, &iarg12);
}
static inline void
LAPACK_DGEQR2(Vlong* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7)
{
    Vint iarg1 = (Vint)(*arg1);
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg4 = (Vint)(*arg4);
    Vint iarg7 = (Vint)(*arg7);
    dgeqr2(&iarg1, &iarg2, arg3, &iarg4, arg5, arg6, &iarg7);
}

/*
* DSTEQR computes all eigenvalues and, optionally, eigenvectors of a
 symmetric tridiagonal matrix using the implicit QL or QR method.
 The eigenvectors of a full or band symmetric matrix can also be found
 if DSYTRD or DSPTRD or DSBTRD has been used to reduce this matrix to
 tridiagonal form.
*/
/*
* Parameters
[in]	COMPZ
          COMPZ is CHARACTER*1
          = 'N':  Compute eigenvalues only.
          = 'V':  Compute eigenvalues and eigenvectors of the original
                  symmetric matrix.  On entry, Z must contain the
                  orthogonal matrix used to reduce the original matrix
                  to tridiagonal form.
          = 'I':  Compute eigenvalues and eigenvectors of the
                  tridiagonal matrix.  Z is initialized to the identity
                  matrix.
[in]	N
          N is INTEGER
          The order of the matrix.  N >= 0.
[in,out]	D
          D is DOUBLE PRECISION array, dimension (N)
          On entry, the diagonal elements of the tridiagonal matrix.
          On exit, if INFO = 0, the eigenvalues in ascending order.
[in,out]	E
          E is DOUBLE PRECISION array, dimension (N-1)
          On entry, the (n-1) subdiagonal elements of the tridiagonal
          matrix.
          On exit, E has been destroyed.
[in,out]	Z
          Z is DOUBLE PRECISION array, dimension (LDZ, N)
          On entry, if  COMPZ = 'V', then Z contains the orthogonal
          matrix used in the reduction to tridiagonal form.
          On exit, if INFO = 0, then if  COMPZ = 'V', Z contains the
          orthonormal eigenvectors of the original symmetric matrix,
          and if COMPZ = 'I', Z contains the orthonormal eigenvectors
          of the symmetric tridiagonal matrix.
          If COMPZ = 'N', then Z is not referenced.
[in]	LDZ
          LDZ is INTEGER
          The leading dimension of the array Z.  LDZ >= 1, and if
          eigenvectors are desired, then  LDZ >= max(1,N).
[out]	WORK
          WORK is DOUBLE PRECISION array, dimension (max(1,2*N-2))
          If COMPZ = 'N', then WORK is not referenced.
[out]	INFO
          INFO is INTEGER
          = 0:  successful exit
          < 0:  if INFO = -i, the i-th argument had an illegal value
          > 0:  the algorithm has failed to find all the eigenvalues in
                a total of 30*N iterations; if INFO = i, then i
                elements of E have not converged to zero; on exit, D
                and E contain the elements of a symmetric tridiagonal
                matrix which is orthogonally similar to the original
                matrix.
*/
static inline void
LAPACK_DSTEQR(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
              Vlong* arg8)
{
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg6 = (Vint)(*arg6);
    Vint iarg8 = (Vint)(*arg8);
    dsteqr(arg1, &iarg2, arg3, arg4, arg5, &iarg6, arg7, &iarg8);
}
static inline void
LAPACK_DLASRT(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4)
{
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg4 = (Vint)(*arg4);
    dlasrt(arg1, &iarg2, arg3, &iarg4);
    *arg4 = (Vlong)iarg4;
}
static inline Vdouble
LAPACK_DLANST(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4)
{
    Vint iarg2 = (Vint)(*arg2);
    return dlanst(arg1, &iarg2, arg3, arg4);
}
static inline void
LAPACK_DLASR(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vlong* arg9)
{
    Vint iarg4 = (Vint)(*arg4);
    Vint iarg5 = (Vint)(*arg5);
    Vint iarg9 = (Vint)(*arg9);
    dlasr(arg1, arg2, arg3, &iarg4, &iarg5, arg6, arg7, arg8, &iarg9);
}
#endif
#elif defined(VKI_LIBAPI_OPENBLAS)
#ifdef OPENBLAS_USE64BITINT
typedef Vlong lapackint;
#else
typedef Vint lapackint;
#endif
VKI_EXTERN int
dlaev2_(const double* a, const double* b, const double* c_, double* rt1, double* rt2, double* cs1, double* sn1);
VKI_EXTERN void
dgeqrf_(const lapackint* m, const lapackint* n, double* a, const lapackint* lda, double* tau, double* work,
        const lapackint* lwork, lapackint* info);
VKI_EXTERN void
dormqr_(const char* side, const char* trans, const lapackint* m, const lapackint* n, const lapackint* k, const double* a,
        const lapackint* lda, const double* tau, double* c, const lapackint* ldc, double* work, const lapackint* lwork,
        lapackint* info);
VKI_EXTERN void
dsyev_(const char* jobz, const char* uplo, const lapackint* n, double* a, const lapackint* lda, double* w, double* work,
       const lapackint* lwork, lapackint* info);
VKI_EXTERN void
dsyevx_(const char* jobz, const char* range, const char* uplo, const lapackint* n, double* a, const lapackint* lda,
        const double* vl, const double* vu, const lapackint* il, const lapackint* iu, const double* abstol, lapackint* m,
        double* w, double* z, const lapackint* ldz, double* work, const lapackint* lwork, lapackint* iwork, lapackint* ifail,
        lapackint* info);
VKI_EXTERN void
dsbev_(const char* jobz, const char* uplo, const lapackint* n, const lapackint* kd, double* ab, const lapackint* ldab, double* w,
       double* z, const lapackint* ldz, double* work, lapackint* info);
VKI_EXTERN void
dlarnv_(const lapackint* idist, lapackint* iseed, const lapackint* n, double* x);
VKI_EXTERN void
dlascl_(const char* type, const lapackint* kl, const lapackint* ku, const double* cfrom, const double* cto, const lapackint* m,
        const lapackint* n, double* a, const lapackint* lda, lapackint* info);
VKI_EXTERN void
dgttrs_(const char* trans, const lapackint* n, const lapackint* nrhs, const double* dl, const double* d, const double* du,
        const double* du2, const lapackint* ipiv, double* b, const lapackint* ldb, lapackint* info);
VKI_EXTERN void
dgttrf_(const lapackint* n, double* dl, double* d, double* du, double* du2, lapackint* ipiv, lapackint* info);
VKI_EXTERN void
dlacpy_(const char* uplo, const lapackint* m, const lapackint* n, const double* a, const lapackint* lda, double* b,
        const lapackint* ldb);
VKI_EXTERN void
dspgv_(const lapackint* itype, const char* jobz, const char* uplo, const lapackint* n, double* ap, double* bp, double* w,
       double* z, const lapackint* ldz, double* work, lapackint* info);
VKI_EXTERN void
dsygv_(const lapackint* itype, const char* jobz, const char* uplo, const lapackint* n, double* a, const lapackint* lda, double* b,
       const lapackint* ldb, double* w, double* work, const lapackint* lwork, lapackint* info);
VKI_EXTERN void
dsygvx_(const lapackint* itype, const char* jobz, const char* range, const char* uplo, const lapackint* n, double* a,
        const lapackint* lda, double* b, const lapackint* ldb, const double* vl, const double* vu, const lapackint* il,
        const lapackint* iu, const double* abstol, lapackint* m, double* w, double* z, const lapackint* ldz, double* work,
        const lapackint* lwork, lapackint* iwork, lapackint* ifail, lapackint* info);
VKI_EXTERN void
dsytrf_(const char* uplo, const lapackint* n, double* a, const lapackint* lda, lapackint* ipiv, double* work,
        const lapackint* lwork, lapackint* info);
VKI_EXTERN void
dlaset_(const char* uplo, const lapackint* m, const lapackint* n, const double* alpha, const double* beta, double* a,
        const lapackint* lda);
VKI_EXTERN void
dorm2r_(const char* side, const char* trans, const lapackint* m, const lapackint* n, const lapackint* k, const double* a,
        const lapackint* lda, const double* tau, double* c, const lapackint* ldc, double* work, lapackint* info);
VKI_EXTERN void
dgeqr2_(const lapackint* m, const lapackint* n, double* a, const lapackint* lda, double* tau, double* work, lapackint* info);
VKI_EXTERN void
dsteqr_(const char* compz, const lapackint* n, double* d, double* e, double* z, const lapackint* ldz, double* work,
        lapackint* info);
VKI_EXTERN void
dlasrt_(const char* id, const lapackint* n, double* d, lapackint* info);
VKI_EXTERN double
dlanst_(const char* norm, const lapackint* n, const double* d, const double* e);
VKI_EXTERN void
dlasr_(const char* side, const char* pivot, const char* direct, const lapackint* m, const lapackint* n, const double* c,
       const double* s, double* a, const lapackint* lda);
VKI_EXTERN void
dgesvd_(const char* jobu, const char* jobvt, const lapackint* m, const lapackint* n, double* a, const lapackint* lda, double* s,
        double* u, const lapackint* ldu, double* vt, const lapackint* ldvt, double* work, const lapackint* lwork,
        lapackint* info);
VKI_EXTERN double
dlamch_(const char* cmach);
VKI_EXTERN lapackint
dlae2_(const double* a, const double* b, const double* c_, double* rt1, double* rt2);
VKI_EXTERN double
dlapy2_(const double* x, const double* y);
VKI_EXTERN lapackint
dlartg_(const double* f, const double* g, double* cs, double* sn, double* r_);
VKI_EXTERN lapackint
lsame_(char* a, char* b);
VKI_EXTERN void
dpotrf_(const Vchar* arg1, lapackint* arg2, Vdouble* arg3, lapackint* arg4, lapackint* arg5);
#ifdef OPENBLAS_USE64BITINT
/*
 * BLAS interface uses 32-bit integers but calls to BLAS use 64-bit integers
 */
static inline void
LAPACK_dpotrf(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vint* arg5)
{
    lapackint larg2 = (lapackint) * (arg2);
    lapackint larg4 = (lapackint) * (arg4);
    lapackint larg5;
    dpotrf_(arg1, &larg2, arg3, &larg4, &larg5);
    *arg5 = (Vint)larg5;
}
static inline void
LAPACK_dgesvd(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
              Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11, Vdouble* arg12, Vint* arg13, Vint* arg14)
{
    lapackint larg3 = (lapackint) * (arg3);
    lapackint larg4 = (lapackint) * (arg4);
    lapackint larg6 = (lapackint) * (arg6);
    lapackint larg9 = (lapackint) * (arg9);
    lapackint larg11 = (lapackint) * (arg11);
    lapackint larg13 = (lapackint) * (arg13);
    lapackint larg14 = (lapackint) * (arg14);
    dgesvd_(arg1, arg2, &(larg3), &(larg4), arg5, &(larg6), arg7, arg8, &(larg9), arg10, &(larg11), arg12, &(larg13), &(larg14));
    *arg14 = (Vint)larg14;
}
static inline void
LAPACK_dgeqrf(Vint* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7, Vint* arg8)
{
    lapackint larg1 = (lapackint)(*arg1);
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg4 = (lapackint)(*arg4);
    lapackint larg7 = (lapackint)(*arg7);
    lapackint larg8 = (lapackint)(*arg8);
    dgeqrf_(&larg1, &larg2, arg3, &larg4, arg5, arg6, &larg7, &larg8);
    *arg8 = (Vint)larg8;
}
static inline void
LAPACK_dormqr(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7, Vdouble* arg8,
              Vdouble* arg9, Vint* arg10, Vdouble* arg11, Vint* arg12, Vint* arg13)
{
    lapackint larg3 = (lapackint)(*arg3);
    lapackint larg4 = (lapackint)(*arg4);
    lapackint larg5 = (lapackint)(*arg5);
    lapackint larg7 = (lapackint)(*arg7);
    lapackint larg10 = (lapackint)(*arg10);
    lapackint larg12 = (lapackint)(*arg12);
    lapackint larg13 = (lapackint)(*arg13);
    dormqr_(arg1, arg2, &larg3, &larg4, &larg5, arg6, &larg7, arg8, arg9, &larg10, arg11, &larg12, &larg13);
    *arg13 = (Vint)larg13;
}
static inline void
LAPACK_dsyev(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vdouble* arg4, Vint* arg5, Vdouble* arg6, Vdouble* arg7,
             Vint* arg8, Vint* arg9)
{
    lapackint larg3 = (lapackint)(*arg3);
    lapackint larg5 = (lapackint)(*arg5);
    lapackint larg8 = (lapackint)(*arg8);
    lapackint larg9 = (lapackint)(*arg9);
    dsyev_(arg1, arg2, &larg3, arg4, &larg5, arg6, arg7, &larg8, &larg9);
    *arg9 = (Vint)larg9;
}
static inline void
LAPACK_dsbev(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11)
{
    lapackint larg3 = (lapackint)(*arg3);
    lapackint larg4 = (lapackint)(*arg4);
    lapackint larg6 = (lapackint)(*arg6);
    lapackint larg9 = (lapackint)(*arg9);
    lapackint larg11 = (lapackint)(*arg11);
    dsbev_(arg1, arg2, &larg3, &larg4, arg5, &larg6, arg7, arg8, &larg9, arg10, &larg11);
    *arg11 = (Vint)larg11;
}
static inline void
LAPACK_dsyevx(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
              Vdouble* arg8, Vint* arg9, Vint* arg10, Vdouble* arg11, Vint* arg12, Vdouble* arg13, Vdouble* arg14, Vint* arg15,
              Vdouble* arg16, Vint* arg17, Vint* arg18, Vint* arg19, Vint* arg20)
{
    lapackint n;
    lapackint larg4 = (lapackint) * (arg4);
    lapackint larg6 = (lapackint) * (arg6);
    lapackint larg9 = (lapackint) * (arg9);
    lapackint larg10 = (lapackint) * (arg10);
    lapackint larg12 = (lapackint) * (arg12);
    lapackint larg15 = (lapackint) * (arg15);
    lapackint larg17 = (lapackint) * (arg17);
    lapackint* larg18;
    lapackint* larg19;
    lapackint larg20 = (lapackint) * (arg20);
    larg18 = (lapackint*)vut_mallocMem(5 * larg4 * sizeof(lapackint));
    larg19 = (lapackint*)vut_mallocMem(larg4 * sizeof(lapackint));
    dsyevx_(arg1, arg2, arg3, &larg4, arg5, &larg6, arg7, arg8, &larg9, &larg10, arg11, &larg12, arg13, arg14, &larg15, arg16,
            &larg17, larg18, larg19, &larg20);
    *(arg12) = (Vint)larg12;
    *(arg20) = (Vint)larg20;
    for (n = 0; n < 5 * larg4; ++n) {
        arg18[n] = (Vint)larg18[n];
    }
    for (n = 0; n < larg4; ++n) {
        arg19[n] = (Vint)larg19[n];
    }
    vut_freeMem(larg18);
    vut_freeMem(larg19);
}
static inline void
LAPACK_dlarnv(Vint* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4)
{
    lapackint larg1 = (lapackint)(*arg1);
    lapackint larg2[4];
    lapackint larg3 = (lapackint)(*arg3);
    larg2[0] = (lapackint)(arg2)[0];
    larg2[1] = (lapackint)(arg2)[1];
    larg2[2] = (lapackint)(arg2)[2];
    larg2[3] = (lapackint)(arg2)[3];
    dlarnv_(&larg1, larg2, &larg3, arg4);
    (arg2)[0] = (Vint)(larg2[0]);
    (arg2)[1] = (Vint)(larg2[1]);
    (arg2)[2] = (Vint)(larg2[2]);
    (arg2)[3] = (Vint)(larg2[3]);
}
static inline void
LAPACK_dlascl(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vint* arg7, Vdouble* arg8,
              Vint* arg9, Vint* arg10)
{
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg3 = (lapackint)(*arg3);
    lapackint larg6 = (lapackint)(*arg6);
    lapackint larg7 = (lapackint)(*arg7);
    lapackint larg9 = (lapackint)(*arg9);
    lapackint larg10 = (lapackint)(*arg10);
    dlascl_(arg1, &larg2, &larg3, arg4, arg5, &larg6, &larg7, arg8, &larg9, &larg10);
    *(arg10) = (Vint)(larg10);
}
static inline void
LAPACK_dlacpy(const Vchar* arg1, const Vint* arg2, const Vint* arg3, const Vdouble* arg4, const Vint* arg5, Vdouble* arg6,
              const Vint* arg7)
{
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg3 = (lapackint)(*arg3);
    lapackint larg5 = (lapackint)(*arg5);
    lapackint larg7 = (lapackint)(*arg7);
    dlacpy_(arg1, &larg2, &larg3, arg4, &larg5, arg6, &larg7);
}
static inline void
LAPACK_dspgv(Vint* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11)
{
    lapackint larg1 = (lapackint) * (arg1);
    lapackint larg4 = (lapackint) * (arg4);
    lapackint larg9 = (lapackint) * (arg9);
    lapackint larg11 = (Vlong) * (arg11);
    dspgv_(&(larg1), arg2, arg3, &(larg4), arg5, arg6, arg7, arg8, &(larg9), arg10, &(larg11));
    *arg11 = (Vint)larg11;
}
static inline void
LAPACK_dsygv(const Vint* arg1, const Vchar* arg2, const Vchar* arg3, const Vint* arg4, Vdouble* arg5, const Vint* arg6,
             Vdouble* arg7, const Vint* arg8, Vdouble* arg9, Vdouble* arg10, const Vint* arg11, Vint* arg12)
{
    lapackint larg1 = (lapackint) * (arg1);
    lapackint larg4 = (lapackint) * (arg4);
    lapackint larg6 = (lapackint) * (arg6);
    lapackint larg8 = (lapackint) * (arg8);
    lapackint larg11 = (lapackint) * (arg11);
    lapackint larg12 = (lapackint) * (arg12);
    dsygv_(&(larg1), arg2, arg3, &(larg4), arg5, &(larg6), arg7, &(larg8), arg9, arg10, &(larg11), &(larg12));
    *arg12 = (Vint)larg12;
}
static inline void
LAPACK_dsygvx(const Vint* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7,
              Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vdouble* arg11, Vint* arg12, Vint* arg13, Vdouble* arg14, Vint* arg15,
              Vdouble* arg16, Vdouble* arg17, Vint* arg18, Vdouble* arg19, Vint* arg20, Vint* arg21, Vint* arg22, Vint* arg23)
{
    lapackint n;
    lapackint larg1 = (lapackint) * (arg1);
    lapackint larg5 = (lapackint) * (arg5);
    lapackint larg7 = (lapackint) * (arg7);
    lapackint larg9 = (lapackint) * (arg9);
    lapackint larg12 = (lapackint) * (arg12);
    lapackint larg13 = (lapackint) * (arg13);
    lapackint larg15 = (lapackint) * (arg15);
    lapackint larg18 = (lapackint) * (arg18);
    lapackint larg20 = (lapackint) * (arg20);
    lapackint* larg21;
    lapackint* larg22;
    lapackint larg23 = (lapackint) * (arg23);
    larg21 = (lapackint*)vut_mallocMem(5 * larg5 * sizeof(lapackint));
    larg22 = (lapackint*)vut_mallocMem(larg5 * sizeof(lapackint));
    dsygvx_(&larg1, arg2, arg3, arg4, &larg5, arg6, &larg7, arg8, &larg9, arg10, arg11, &larg12, &larg13, arg14, &larg15, arg16,
            arg17, &larg18, arg19, &larg20, larg21, larg22, &larg23);
    *arg15 = (Vint)larg15;
    *arg23 = (Vint)larg23;
    for (n = 0; n < 5 * larg5; ++n) {
        arg21[n] = (Vint)larg21[n];
    }
    for (n = 0; n < larg5; ++n) {
        arg22[n] = (Vint)larg22[n];
    }
    vut_freeMem(larg21);
    vut_freeMem(larg22);
}
static inline void
LAPACK_dsytrf(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7, Vint* arg8)
{
    lapackint n;
    lapackint larg2 = (lapackint) * (arg2);
    lapackint* larg5;
    lapackint larg4 = (lapackint) * (arg4);
    lapackint larg7 = (lapackint) * (arg7);
    lapackint larg8 = (lapackint) * (arg8);
    larg5 = (lapackint*)vut_mallocMem(larg2 * sizeof(lapackint));
    dsytrf_(arg1, &(larg2), arg3, &(larg4), larg5, arg6, &(larg7), &(larg8));
    for (n = 0; n < larg2; ++n) {
        arg5[n] = (Vint)larg5[n];
    }
    vut_freeMem(larg5);
    *arg8 = (Vint)larg8;
}
static inline void
LAPACK_dgttrs(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7, Vint* arg8,
              Vdouble* arg9, Vint* arg10, Vint* arg11)
{
    lapackint i;
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg3 = (lapackint)(*arg3);
    lapackint* larg8;
    lapackint larg10 = (lapackint)(*arg10);
    lapackint larg11 = (lapackint)(*arg11);
    larg8 = (lapackint*)vut_mallocMem((*arg2) * sizeof(lapackint));
    for (i = 0; i < *(arg2); ++i) {
        larg8[i] = (lapackint)((arg8)[i]);
    }
    dgttrs_(arg1, &larg2, &larg3, arg4, arg5, arg6, arg7, larg8, arg9, &larg10, &larg11);
    for (i = 0; i < *(arg2); ++i) {
        (arg8)[i] = (Vint)(larg8[i]);
    }
    vut_freeMem(larg8);
}
static inline void
LAPACK_dgttrf(Vint* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vint* arg7)
{
    lapackint i;
    lapackint larg1 = (lapackint)(*arg1);
    lapackint* larg6;
    lapackint larg7 = (lapackint)(*arg7);
    larg6 = (lapackint*)vut_mallocMem((*arg1) * sizeof(lapackint));
    for (i = 0; i < *(arg1); ++i) {
        larg6[i] = (lapackint)((arg6)[i]);
    }
    dgttrf_(&larg1, arg2, arg3, arg4, arg5, larg6, &larg7);
    for (i = 0; i < *(arg1); ++i) {
        (arg6)[i] = (Vint)(larg6[i]);
    }
    vut_freeMem(larg6);
}
static inline void
LAPACK_dlaset(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7)
{
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg3 = (lapackint)(*arg3);
    lapackint larg7 = (lapackint)(*arg7);
    dlaset_(arg1, &larg2, &larg3, arg4, arg5, arg6, &larg7);
}
static inline void
LAPACK_dorm2r(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7, Vdouble* arg8,
              Vdouble* arg9, Vint* arg10, Vdouble* arg11, Vint* arg12)
{
    lapackint larg3 = (lapackint)(*arg3);
    lapackint larg4 = (lapackint)(*arg4);
    lapackint larg5 = (lapackint)(*arg5);
    lapackint larg7 = (lapackint)(*arg7);
    lapackint larg10 = (lapackint)(*arg10);
    lapackint larg12 = (lapackint)(*arg12);
    dorm2r_(arg1, arg2, &larg3, &larg4, &larg5, arg6, &larg7, arg8, arg9, &larg10, arg11, &larg12);
}
static inline void
LAPACK_dgeqr2(Vint* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7)
{
    lapackint larg1 = (lapackint)(*arg1);
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg4 = (lapackint)(*arg4);
    lapackint larg7 = (lapackint)(*arg7);
    dgeqr2_(&larg1, &larg2, arg3, &larg4, arg5, arg6, &larg7);
}
static inline void
LAPACK_dsteqr(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7, Vint* arg8)
{
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg6 = (lapackint)(*arg6);
    lapackint larg8 = (lapackint)(*arg8);
    dsteqr_(arg1, &larg2, arg3, arg4, arg5, &larg6, arg7, &larg8);
}
static inline Vdouble
LAPACK_dlamch(const Vchar* arg1)
{
    return dlamch_(arg1);
}
static inline void
LAPACK_dlasrt(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4)
{
    lapackint larg2 = (lapackint)(*arg2);
    lapackint larg4 = (lapackint)(*arg4);
    dlasrt_(arg1, &larg2, arg3, &larg4);
    *arg4 = (Vint)larg4;
}
static inline Vdouble
LAPACK_dlanst(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4)
{
    lapackint larg2 = (lapackint)(*arg2);
    return dlanst_(arg1, &larg2, arg3, arg4);
}
static inline void
LAPACK_dlasr(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9)
{
    lapackint larg4 = (lapackint)(*arg4);
    lapackint larg5 = (lapackint)(*arg5);
    lapackint larg9 = (lapackint)(*arg9);
    dlasr_(arg1, arg2, arg3, &larg4, &larg5, arg6, arg7, arg8, &larg9);
}
static inline void
LAPACK_dlaev2(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7)
{
    dlaev2_(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_dlae2(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5)
{
    dlae2_(arg1, arg2, arg3, arg4, arg5);
}
static inline void
LAPACK_dlartg(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5)
{
    dlartg_(arg1, arg2, arg3, arg4, arg5);
}
static inline Vdouble
LAPACK_dlapy2(Vdouble* arg1, Vdouble* arg2)
{
    return dlapy2_(arg1, arg2);
}
/*
 * BLAS interface uses 64-bit integers and calls to BLAS use 64-bit integers
 */
static inline void
LAPACK_DPOTRF(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vlong* arg5)
{
    dpotrf_(arg1, arg2, arg3, arg4, arg5);
}
static inline void
LAPACK_DGESVD(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
              Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vlong* arg11, Vdouble* arg12, Vlong* arg13, Vlong* arg14)
{
    dgesvd_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
}
static inline void
LAPACK_DGEQRF(Vlong* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7, Vlong* arg8)
{
    dgeqrf_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
static inline void
LAPACK_DORMQR(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7,
              Vdouble* arg8, Vdouble* arg9, Vlong* arg10, Vdouble* arg11, Vlong* arg12, Vlong* arg13)
{
    dormqr_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
}
static inline void
LAPACK_DSYEV(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vdouble* arg4, Vlong* arg5, Vdouble* arg6, Vdouble* arg7,
             Vlong* arg8, Vlong* arg9)
{
    dsyev_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
static inline void
LAPACK_DSYEVX(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vlong* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
              Vdouble* arg8, Vlong* arg9, Vlong* arg10, Vdouble* arg11, Vlong* arg12, Vdouble* arg13, Vdouble* arg14,
              Vlong* arg15, Vdouble* arg16, Vlong* arg17, Vlong* arg18, Vlong* arg19, Vlong* arg20)
{
    dsyevx_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18,
            arg19, arg20);
}
static inline void
LAPACK_DSBEV(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
             Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vlong* arg11)
{
    dsbev_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
LAPACK_DLARNV(Vlong* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4)
{
    dlarnv_(arg1, arg2, arg3, arg4);
}
static inline void
LAPACK_DLASCL(const Vchar* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vlong* arg7, Vdouble* arg8,
              Vlong* arg9, Vlong* arg10)
{
    dlascl_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
static inline void
LAPACK_DLACPY(const Vchar* arg1, const Vlong* arg2, const Vlong* arg3, const Vdouble* arg4, const Vlong* arg5, Vdouble* arg6,
              const Vlong* arg7)
{
    dlacpy_(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_DSPGV(Vlong* arg1, const Vchar* arg2, const Vchar* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vlong* arg11)
{
    dspgv_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
LAPACK_DSYGV(const Vlong* arg1, const Vchar* arg2, const Vchar* arg3, const Vlong* arg4, Vdouble* arg5, const Vlong* arg6,
             Vdouble* arg7, Vlong* arg8, Vdouble* arg9, Vdouble* arg10, const Vlong* arg11, Vlong* arg12)
{
    dsygv_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
static inline void
LAPACK_DSYGVX(const Vlong* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7,
              Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vdouble* arg11, Vlong* arg12, Vlong* arg13, Vdouble* arg14,
              Vlong* arg15, Vdouble* arg16, Vdouble* arg17, Vlong* arg18, Vdouble* arg19, Vlong* arg20, Vlong* arg21,
              Vlong* arg22, Vlong* arg23)
{
    dsygvx_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18,
            arg19, arg20, arg21, arg22, arg23);
}
static inline void
LAPACK_DSYTRF(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7, Vlong* arg8)
{
    dsytrf_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
static inline void
LAPACK_DGTTRS(const Vchar* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7,
              Vlong* arg8, Vdouble* arg9, Vlong* arg10, Vlong* arg11)
{
    dgttrs_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
LAPACK_DGTTRF(Vlong* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vlong* arg7)
{
    dgttrf_(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_DLASET(const Vchar* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7)
{
    dlaset_(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_DORM2R(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7,
              Vdouble* arg8, Vdouble* arg9, Vlong* arg10, Vdouble* arg11, Vlong* arg12)
{
    dorm2r_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
static inline void
LAPACK_DGEQR2(Vlong* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7)
{
    dgeqr2_(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_DSTEQR(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
              Vlong* arg8)
{
    dsteqr_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
static inline void
LAPACK_DLASRT(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4)
{
    dlasrt_(arg1, arg2, arg3, arg4);
}
static inline void
LAPACK_DLASR(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vlong* arg9)
{
    dlasr_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
static inline Vdouble
LAPACK_DLANST(char* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4)
{
    return dlanst_(arg1, arg2, arg3, arg4);
}
#else
/*
 * BLAS interface uses 32-bit integers but calls to BLAS use 32-bit integers
 */
static inline void
LAPACK_dpotrf(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vint* arg5)
{
    dpotrf_(arg1, arg2, arg3, arg4, arg5);
}
static inline void
LAPACK_dgesvd(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
              Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11, Vdouble* arg12, Vint* arg13, Vint* arg14)
{
    dgesvd_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
}
static inline void
LAPACK_dgeqrf(Vint* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7, Vint* arg8)
{
    dgeqrf_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
static inline void
LAPACK_dormqr(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7, Vdouble* arg8,
              Vdouble* arg9, Vint* arg10, Vdouble* arg11, Vint* arg12, Vint* arg13)
{
    dormqr_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
}
static inline void
LAPACK_dsyev(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vdouble* arg4, Vint* arg5, Vdouble* arg6, Vdouble* arg7,
             Vint* arg8, Vint* arg9)
{
    dsyev_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
static inline void
LAPACK_dsyevx(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
              Vdouble* arg8, Vint* arg9, Vint* arg10, Vdouble* arg11, Vint* arg12, Vdouble* arg13, Vdouble* arg14, Vint* arg15,
              Vdouble* arg16, Vint* arg17, Vint* arg18, Vint* arg19, Vint* arg20)
{
    dsyevx_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18,
            arg19, arg20);
}
static inline void
LAPACK_dsbev(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11)
{
    dsbev_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
LAPACK_dlarnv(Vint* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4)
{
    dlarnv_(arg1, arg2, arg3, arg4);
}
static inline void
LAPACK_dlascl(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vint* arg7, Vdouble* arg8,
              Vint* arg9, Vint* arg10)
{
    dlascl_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
static inline void
LAPACK_dgttrs(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7, Vint* arg8,
              Vdouble* arg9, Vint* arg10, Vint* arg11)
{
    dgttrs_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
LAPACK_dgttrf(Vint* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vint* arg7)
{
    dgttrf_(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_dlacpy(const Vchar* arg1, const Vint* arg2, const Vint* arg3, const Vdouble* arg4, const Vint* arg5, Vdouble* arg6,
              const Vint* arg7)
{
    dlacpy_(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_dspgv(Vint* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11)
{
    dspgv_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
LAPACK_dsygv(const Vint* arg1, const Vchar* arg2, const Vchar* arg3, const Vint* arg4, Vdouble* arg5, const Vint* arg6,
             Vdouble* arg7, const Vint* arg8, Vdouble* arg9, Vdouble* arg10, const Vint* arg11, Vint* arg12)
{
    dsygv_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
static inline void
LAPACK_dsygvx(const Vint* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7,
              Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vdouble* arg11, Vint* arg12, Vint* arg13, Vdouble* arg14, Vint* arg15,
              Vdouble* arg16, Vdouble* arg17, Vint* arg18, Vdouble* arg19, Vint* arg20, Vint* arg21, Vint* arg22, Vint* arg23)
{
    dsygvx_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18,
            arg19, arg20, arg21, arg22, arg23);
}
static inline void
LAPACK_dsytrf(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7, Vint* arg8)
{
    dsytrf_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
static inline void
LAPACK_dlartg(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5)
{
    dlartg_(arg1, arg2, arg3, arg4, arg5);
}
static inline void
LAPACK_dlaset(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7)
{
    dlaset_(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_dorm2r(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7, Vdouble* arg8,
              Vdouble* arg9, Vint* arg10, Vdouble* arg11, Vint* arg12)
{
    dorm2r_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
static inline void
LAPACK_dgeqr2(Vint* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7)
{
    dgeqr2_(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_dsteqr(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7, Vint* arg8)
{
    dsteqr_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
static inline Vdouble
LAPACK_dlamch(const Vchar* arg1)
{
    return dlamch_(arg1);
}
static inline void
LAPACK_dlae2(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5)
{
    dlae2_(arg1, arg2, arg3, arg4, arg5);
}
static inline void
LAPACK_dlaev2(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7)
{
    dlaev2_(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline Vdouble
LAPACK_dlapy2(Vdouble* arg1, Vdouble* arg2)
{
    return dlapy2_(arg1, arg2);
}
static inline Vdouble
LAPACK_dlanst(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4)
{
    return dlanst_(arg1, arg2, arg3, arg4);
}
static inline void
LAPACK_dlasrt(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4)
{
    dlasrt_(arg1, arg2, arg3, arg4);
}
static inline void
LAPACK_dlasr(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9)
{
    dlasr_(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
/*
 * BLAS interface uses 32-bit integers but calls to BLAS use 64-bit integers
 */
static inline void
LAPACK_DPOTRF(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vlong* arg5)
{
    Vint larg2 = (Vint) * (arg2);
    Vint larg4 = (Vint) * (arg4);
    Vint larg5;
    dpotrf_(arg1, &larg2, arg3, &larg4, &larg5);
    *arg5 = (Vlong)larg5;
}
static inline void
LAPACK_DGESVD(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
              Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vlong* arg11, Vdouble* arg12, Vlong* arg13, Vlong* arg14)
{
    Vint larg3 = (Vint) * (arg3);
    Vint larg4 = (Vint) * (arg4);
    Vint larg6 = (Vint) * (arg6);
    Vint larg9 = (Vint) * (arg9);
    Vint larg11 = (Vint) * (arg11);
    Vint larg13 = (Vint) * (arg13);
    Vint larg14 = (Vint) * (arg14);
    dgesvd_(arg1, arg2, &(larg3), &(larg4), arg5, &(larg6), arg7, arg8, &(larg9), arg10, &(larg11), arg12, &(larg13), &(larg14));
    *arg14 = (Vlong)larg14;
}
static inline void
LAPACK_DGEQRF(Vlong* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7, Vlong* arg8)
{
    Vint iarg1 = (Vint)(*arg1);
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg4 = (Vint)(*arg4);
    Vint iarg7 = (Vint)(*arg7);
    Vint iarg8 = (Vint)(*arg8);
    dgeqrf_(&iarg1, &iarg2, arg3, &iarg4, arg5, arg6, &iarg7, &iarg8);
    *arg8 = (Vlong)iarg8;
}
static inline void
LAPACK_DORMQR(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7,
              Vdouble* arg8, Vdouble* arg9, Vlong* arg10, Vdouble* arg11, Vlong* arg12, Vlong* arg13)
{
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg4 = (Vint)(*arg4);
    Vint iarg5 = (Vint)(*arg5);
    Vint iarg7 = (Vint)(*arg7);
    Vint iarg10 = (Vint)(*arg10);
    Vint iarg12 = (Vint)(*arg12);
    Vint iarg13 = (Vint)(*arg13);
    dormqr_(arg1, arg2, &iarg3, &iarg4, &iarg5, arg6, &iarg7, arg8, arg9, &iarg10, arg11, &iarg12, &iarg13);
    *arg13 = (Vlong)iarg13;
}
static inline void
LAPACK_DSYEV(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vdouble* arg4, Vlong* arg5, Vdouble* arg6, Vdouble* arg7,
             Vlong* arg8, Vlong* arg9)
{
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg5 = (Vint)(*arg5);
    Vint iarg8 = (Vint)(*arg8);
    Vint iarg9 = (Vint)(*arg9);
    dsyev_(arg1, arg2, &iarg3, arg4, &iarg5, arg6, arg7, &iarg8, &iarg9);
    *(arg9) = (Vlong)iarg9;
}
static inline void
LAPACK_DSYEVX(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vlong* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
              Vdouble* arg8, Vlong* arg9, Vlong* arg10, Vdouble* arg11, Vlong* arg12, Vdouble* arg13, Vdouble* arg14,
              Vlong* arg15, Vdouble* arg16, Vlong* arg17, Vlong* arg18, Vlong* arg19, Vlong* arg20)
{
    Vint n;
    Vint larg4 = (Vint) * (arg4);
    Vint larg6 = (Vint) * (arg6);
    Vint larg9 = (Vint) * (arg9);
    Vint larg10 = (Vint) * (arg10);
    Vint larg12 = (Vint) * (arg12);
    Vint larg15 = (Vint) * (arg15);
    Vint larg17 = (Vint) * (arg17);
    Vint* larg18;
    Vint* larg19;
    Vint larg20 = (lapackint) * (arg20);
    larg18 = (lapackint*)vut_mallocMem(5 * larg4 * sizeof(lapackint));
    larg19 = (lapackint*)vut_mallocMem(larg4 * sizeof(lapackint));
    dsyevx_(arg1, arg2, arg3, &larg4, arg5, &larg6, arg7, arg8, &larg9, &larg10, arg11, &larg12, arg13, arg14, &larg15, arg16,
            &larg17, larg18, larg19, &larg20);
    *(arg12) = (Vlong)larg12;
    *(arg20) = (Vlong)larg20;
    for (n = 0; n < 5 * larg4; ++n) {
        arg18[n] = (Vlong)larg18[n];
    }
    for (n = 0; n < larg4; ++n) {
        arg19[n] = (Vlong)larg19[n];
    }
    vut_freeMem(larg18);
    vut_freeMem(larg19);
}
static inline void
LAPACK_DSBEV(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
             Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vlong* arg11)
{
    Vint larg3 = (Vint)(*arg3);
    Vint larg4 = (Vint)(*arg4);
    Vint larg6 = (Vint)(*arg6);
    Vint larg9 = (Vint)(*arg9);
    Vint larg11 = (Vint)(*arg11);
    dsbev_(arg1, arg2, &larg3, &larg4, arg5, &larg6, arg7, arg8, &larg9, arg10, &larg11);
    *arg11 = (Vlong)larg11;
}
static inline void
LAPACK_DLARNV(Vlong* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4)
{
    Vint iarg1 = (Vint)(*arg1);
    Vint iarg2[4];
    Vint iarg3 = (Vint)(*arg3);
    iarg2[0] = (Vint)(arg2)[0];
    iarg2[1] = (Vint)(arg2)[1];
    iarg2[2] = (Vint)(arg2)[2];
    iarg2[3] = (Vint)(arg2)[3];
    dlarnv_(&iarg1, iarg2, &iarg3, arg4);
    (arg2)[0] = (Vlong)(iarg2[0]);
    (arg2)[1] = (Vlong)(iarg2[1]);
    (arg2)[2] = (Vlong)(iarg2[2]);
    (arg2)[3] = (Vlong)(iarg2[3]);
}
static inline void
LAPACK_DLASCL(const Vchar* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vlong* arg7, Vdouble* arg8,
              Vlong* arg9, Vlong* arg10)
{
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg6 = (Vint)(*arg6);
    Vint iarg7 = (Vint)(*arg7);
    Vint iarg9 = (Vint)(*arg9);
    Vint iarg10 = (Vint)(*arg10);
    dlascl_(arg1, &iarg2, &iarg3, arg4, arg5, &iarg6, &iarg7, arg8, &iarg9, &iarg10);
    *(arg10) = (Vlong)(iarg10);
}
static inline void
LAPACK_DGTTRS(const Vchar* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7,
              Vlong* arg8, Vdouble* arg9, Vlong* arg10, Vlong* arg11)
{
    Vint i;
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg3 = (Vint)(*arg3);
    Vint* iarg8;
    Vint iarg10 = (Vint)(*arg10);
    Vint iarg11 = (Vint)(*arg11);
    iarg8 = (Vint*)vut_mallocMem((*arg2) * sizeof(Vint));
    for (i = 0; i < *(arg2); ++i) {
        iarg8[i] = (Vint)((arg8)[i]);
    }
    dgttrs_(arg1, &iarg2, &iarg3, arg4, arg5, arg6, arg7, iarg8, arg9, &iarg10, &iarg11);
    for (i = 0; i < *(arg2); ++i) {
        (arg8)[i] = (Vlong)(iarg8[i]);
    }
    vut_freeMem(iarg8);
}
static inline void
LAPACK_DGTTRF(Vlong* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vlong* arg7)
{
    Vint i;
    Vint iarg1 = (Vint)(*arg1);
    Vint* iarg6;
    Vint iarg7 = (Vint)(*arg7);
    iarg6 = (Vint*)vut_mallocMem((*arg1) * sizeof(Vint));
    for (i = 0; i < *(arg1); ++i) {
        iarg6[i] = (Vint)((arg6)[i]);
    }
    dgttrf_(&iarg1, arg2, arg3, arg4, arg5, iarg6, &iarg7);
    for (i = 0; i < *(arg1); ++i) {
        (arg6)[i] = (Vlong)(iarg6[i]);
    }
    vut_freeMem(iarg6);
}
static inline void
LAPACK_DLACPY(const Vchar* arg1, const Vlong* arg2, const Vlong* arg3, const Vdouble* arg4, const Vlong* arg5, Vdouble* arg6,
              const Vlong* arg7)
{
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg5 = (Vint)(*arg5);
    Vint iarg7 = (Vint)(*arg7);
    dlacpy_(arg1, &iarg2, &iarg3, arg4, &iarg5, arg6, &iarg7);
}
static inline void
LAPACK_DSPGV(Vlong* arg1, const Vchar* arg2, const Vchar* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vlong* arg11)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg4 = (Vint) * (arg4);
    Vint larg9 = (Vint) * (arg9);
    Vint larg11 = (Vint) * (arg11);
    dspgv_(&(larg1), arg2, arg3, &(larg4), arg5, arg6, arg7, arg8, &(larg9), arg10, &(larg11));
    *arg11 = (Vlong)larg11;
}
static inline void
LAPACK_DSYGV(const Vlong* arg1, const Vchar* arg2, const Vchar* arg3, const Vlong* arg4, Vdouble* arg5, const Vlong* arg6,
             Vdouble* arg7, const Vlong* arg8, Vdouble* arg9, Vdouble* arg10, const Vlong* arg11, Vlong* arg12)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg4 = (Vint) * (arg4);
    Vint larg6 = (Vint) * (arg6);
    Vint larg8 = (Vint) * (arg8);
    Vint larg11 = (Vint) * (arg11);
    Vint larg12 = (Vint) * (arg12);
    dsygv_(&(larg1), arg2, arg3, &(larg4), arg5, &(larg6), arg7, &(larg8), arg9, arg10, &(larg11), &(larg12));
    *arg12 = (Vlong)larg12;
}
static inline void
LAPACK_DSYGVX(const Vlong* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7,
              Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vdouble* arg11, Vlong* arg12, Vlong* arg13, Vdouble* arg14,
              Vlong* arg15, Vdouble* arg16, Vdouble* arg17, Vlong* arg18, Vdouble* arg19, Vlong* arg20, Vlong* arg21,
              Vlong* arg22, Vlong* arg23)
{
    Vint n;
    Vint larg1 = (Vint) * (arg1);
    Vint larg5 = (Vint) * (arg5);
    Vint larg7 = (Vint) * (arg7);
    Vint larg9 = (Vint) * (arg9);
    Vint larg12 = (Vint) * (arg12);
    Vint larg13 = (Vint) * (arg13);
    Vint larg15 = (Vint) * (arg15);
    Vint larg18 = (Vint) * (arg18);
    Vint larg20 = (Vint) * (arg20);
    Vint* larg21;
    Vint* larg22;
    Vint larg23 = (Vint) * (arg23);
    larg21 = (Vint*)vut_mallocMem(5 * larg5 * sizeof(Vint));
    larg22 = (Vint*)vut_mallocMem(larg5 * sizeof(Vint));
    dsygvx_(&larg1, arg2, arg3, arg4, &larg5, arg6, &larg7, arg8, &larg9, arg10, arg11, &larg12, &larg13, arg14, &larg15, arg16,
            arg17, &larg18, arg19, &larg20, larg21, larg22, &larg23);
    *arg15 = (Vlong)larg15;
    *arg23 = (Vlong)larg23;
    for (n = 0; n < 5 * larg5; ++n) {
        arg21[n] = (Vlong)larg21[n];
    }
    for (n = 0; n < larg5; ++n) {
        arg22[n] = (Vlong)larg22[n];
    }
    vut_freeMem(larg21);
    vut_freeMem(larg22);
}
static inline void
LAPACK_DSYTRF(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7, Vlong* arg8)
{
    Vint n;
    Vint larg2 = (Vint) * (arg2);
    Vint* larg5;
    Vint larg4 = (Vint) * (arg4);
    Vint larg7 = (Vint) * (arg7);
    Vint larg8 = (Vint) * (arg8);
    larg5 = (Vint*)vut_mallocMem(larg2 * sizeof(Vint));
    dsytrf_(arg1, &(larg2), arg3, &(larg4), larg5, arg6, &(larg7), &(larg8));
    for (n = 0; n < larg2; ++n) {
        arg5[n] = (Vlong)larg5[n];
    }
    vut_freeMem(larg5);
    *arg8 = (Vlong)larg8;
}
static inline void
LAPACK_DLASET(const Vchar* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7)
{
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg7 = (Vint)(*arg7);
    dlaset_(arg1, &iarg2, &iarg3, arg4, arg5, arg6, &iarg7);
}
static inline void
LAPACK_DORM2R(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7,
              Vdouble* arg8, Vdouble* arg9, Vlong* arg10, Vdouble* arg11, Vlong* arg12)
{
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg4 = (Vint)(*arg4);
    Vint iarg5 = (Vint)(*arg5);
    Vint iarg7 = (Vint)(*arg7);
    Vint iarg10 = (Vint)(*arg10);
    Vint iarg12 = (Vint)(*arg12);
    dorm2r_(arg1, arg2, &iarg3, &iarg4, &iarg5, arg6, &iarg7, arg8, arg9, &iarg10, arg11, &iarg12);
}
static inline void
LAPACK_DGEQR2(Vlong* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7)
{
    Vint iarg1 = (Vint)(*arg1);
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg4 = (Vint)(*arg4);
    Vint iarg7 = (Vint)(*arg7);
    dgeqr2_(&iarg1, &iarg2, arg3, &iarg4, arg5, arg6, &iarg7);
}
static inline void
LAPACK_DSTEQR(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
              Vlong* arg8)
{
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg6 = (Vint)(*arg6);
    Vint iarg8 = (Vint)(*arg8);
    dsteqr_(arg1, &iarg2, arg3, arg4, arg5, &iarg6, arg7, &iarg8);
}
static inline void
LAPACK_DLASRT(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4)
{
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg4 = (Vint)(*arg4);
    dlasrt_(arg1, &iarg2, arg3, &iarg4);
    *arg4 = (Vint)iarg4;
}
static inline Vdouble
LAPACK_DLANST(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4)
{
    Vint iarg2 = (Vint)(*arg2);
    return dlanst_(arg1, &iarg2, arg3, arg4);
}
static inline void
LAPACK_DLASR(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vlong* arg9)
{
    Vint iarg4 = (Vint)(*arg4);
    Vint iarg5 = (Vint)(*arg5);
    Vint iarg9 = (Vint)(*arg9);
    dlasr_(arg1, arg2, arg3, &iarg4, &iarg5, arg6, arg7, arg8, &iarg9);
}
#endif
#else

static inline void
LAPACK_dlarnv(Vint* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4)
{
    vki_dlarnv(arg1, arg2, arg3, arg4);
}
static inline void
LAPACK_dlascl(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vint* arg7, Vdouble* arg8,
              Vint* arg9, Vint* arg10)
{
    vki_dlascl(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
static inline void
LAPACK_dlacpy(const Vchar* arg1, const Vint* arg2, const Vint* arg3, const Vdouble* arg4, const Vint* arg5, Vdouble* arg6,
              const Vint* arg7)
{
    vki_dlacpy(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_dlartg(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5)
{
    vki_dlartg(arg1, arg2, arg3, arg4, arg5);
}
static inline void
LAPACK_dlaset(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7)
{
    vki_dlaset(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_dorm2r(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7, Vdouble* arg8,
              Vdouble* arg9, Vint* arg10, Vdouble* arg11, Vint* arg12)
{
    vki_dorm2r(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
static inline void
LAPACK_dgeqr2(Vint* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7)
{
    vki_dgeqr2(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline void
LAPACK_dsteqr(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7, Vint* arg8)
{
    vki_dsteqr(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
static inline Vdouble
LAPACK_dlamch(const Vchar* arg1)
{
    return vki_dlamch(arg1);
}
static inline void
LAPACK_dlae2(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5)
{
    vki_dlae2(arg1, arg2, arg3, arg4, arg5);
}
static inline void
LAPACK_dlaev2(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7)
{
    vki_dlaev2(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
static inline Vdouble
LAPACK_dlapy2(Vdouble* arg1, Vdouble* arg2)
{
    return vki_dlapy2(arg1, arg2);
}
static inline Vdouble
LAPACK_dlanst(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4)
{
    return vki_dlanst(arg1, arg2, arg3, arg4);
}
static inline void
LAPACK_dlasrt(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4)
{
    vki_dlasrt(arg1, arg2, arg3, arg4);
}
static inline void
LAPACK_dlasr(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9)
{
    vki_dlasr(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
static inline void
LAPACK_DLARNV(Vlong* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4)
{
    Vint iarg1 = (Vint)(*arg1);
    Vint iarg2[4];
    Vint iarg3 = (Vint)(*arg3);
    iarg2[0] = (Vint)(arg2[0]);
    iarg2[1] = (Vint)(arg2[1]);
    iarg2[2] = (Vint)(arg2[2]);
    iarg2[3] = (Vint)(arg2[3]);
    vki_dlarnv(&iarg1, iarg2, &iarg3, arg4);
    (arg2)[0] = (Vlong)(iarg2[0]);
    (arg2)[1] = (Vlong)(iarg2[1]);
    (arg2)[2] = (Vlong)(iarg2[2]);
    (arg2)[3] = (Vlong)(iarg2[3]);
}
static inline void
LAPACK_DLASCL(const Vchar* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vlong* arg7, Vdouble* arg8,
              Vlong* arg9, Vlong* arg10)
{
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg6 = (Vint)(*arg6);
    Vint iarg7 = (Vint)(*arg7);
    Vint iarg9 = (Vint)(*arg9);
    Vint iarg10 = (Vint)(*arg10);
    vki_dlascl(arg1, &iarg2, &iarg3, arg4, arg5, &iarg6, &iarg7, arg8, &iarg9, &iarg10);
    *(arg10) = (Vlong)(iarg10);
}
static inline void
LAPACK_DLACPY(const Vchar* arg1, const Vlong* arg2, const Vlong* arg3, const Vdouble* arg4, const Vlong* arg5, Vdouble* arg6,
              const Vlong* arg7)
{
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg5 = (Vint)(*arg5);
    Vint iarg7 = (Vint)(*arg7);
    vki_dlacpy(arg1, &iarg2, &iarg3, arg4, &iarg5, arg6, &iarg7);
}
static inline void
LAPACK_DLASET(const Vchar* arg1, Vlong* arg2, Vlong* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7)
{
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg7 = (Vint)(*arg7);
    vki_dlaset(arg1, &iarg2, &iarg3, arg4, arg5, arg6, &iarg7);
}
static inline void
LAPACK_DORM2R(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7,
              Vdouble* arg8, Vdouble* arg9, Vlong* arg10, Vdouble* arg11, Vlong* arg12)
{
    Vint iarg3 = (Vint)(*arg3);
    Vint iarg4 = (Vint)(*arg4);
    Vint iarg5 = (Vint)(*arg5);
    Vint iarg7 = (Vint)(*arg7);
    Vint iarg10 = (Vint)(*arg10);
    Vint iarg12 = (Vint)(*arg12);
    vki_dorm2r(arg1, arg2, &iarg3, &iarg4, &iarg5, arg6, &iarg7, arg8, arg9, &iarg10, arg11, &iarg12);
}
static inline void
LAPACK_DGEQR2(Vlong* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7)
{
    Vint iarg1 = (Vint)(*arg1);
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg4 = (Vint)(*arg4);
    Vint iarg7 = (Vint)(*arg7);
    vki_dgeqr2(&iarg1, &iarg2, arg3, &iarg4, arg5, arg6, &iarg7);
}
static inline void
LAPACK_DSTEQR(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
              Vlong* arg8)
{
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg6 = (Vint)(*arg6);
    Vint iarg8 = (Vint)(*arg8);
    vki_dsteqr(arg1, &iarg2, arg3, arg4, arg5, &iarg6, arg7, &iarg8);
}
static inline void
LAPACK_DLASRT(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4)
{
    Vint iarg2 = (Vint)(*arg2);
    Vint iarg4 = (Vint)(*arg4);
    vki_dlasrt(arg1, &iarg2, arg3, &iarg4);
    *arg4 = (Vlong)iarg4;
}
static inline Vdouble
LAPACK_DLANST(const Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4)
{
    Vint iarg2 = (Vint)(*arg2);
    return vki_dlanst(arg1, &iarg2, arg3, arg4);
}
static inline void
LAPACK_DLASR(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vlong* arg9)
{
    Vint iarg4 = (Vint)(*arg4);
    Vint iarg5 = (Vint)(*arg5);
    Vint iarg9 = (Vint)(*arg9);
    vki_dlasr(arg1, arg2, arg3, &iarg4, &iarg5, arg6, arg7, arg8, &iarg9);
}
static inline void
LAPACK_dgeqrf(Vint* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7, Vint* arg8)
{
}
static inline void
LAPACK_dgesvd(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
              Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11, Vdouble* arg12, Vint* arg13, Vint* arg14)
{
}
static inline void
LAPACK_dgttrf(Vint* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vint* arg7)
{
}
static inline void
LAPACK_dgttrs(const Vchar* arg1, Vint* arg2, Vint* arg3, Vdouble* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7, Vint* arg8,
              Vdouble* arg9, Vint* arg10, Vint* arg11)
{
}
static inline void
LAPACK_dpotrf(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vint* arg5)
{
}
static inline void
LAPACK_dsbev(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11)
{
}
static inline void
LAPACK_dspgv(Vint* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vdouble* arg7,
             Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11)
{
}
static inline void
LAPACK_dsyev(const Vchar* arg1, const Vchar* arg2, Vint* arg3, Vdouble* arg4, Vint* arg5, Vdouble* arg6, Vdouble* arg7,
             Vint* arg8, Vint* arg9)
{
}
static inline void
LAPACK_dsyevx(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, Vint* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7,
              Vdouble* arg8, Vint* arg9, Vint* arg10, Vdouble* arg11, Vint* arg12, Vdouble* arg13, Vdouble* arg14, Vint* arg15,
              Vdouble* arg16, Vint* arg17, Vint* arg18, Vint* arg19, Vint* arg20)
{
}
static inline void
LAPACK_dsygv(const Vint* arg1, const Vchar* arg2, const Vchar* arg3, const Vint* arg4, Vdouble* arg5, const Vint* arg6,
             Vdouble* arg7, const Vint* arg8, Vdouble* arg9, Vdouble* arg10, const Vint* arg11, Vint* arg12)
{
}
static inline void
LAPACK_dsygvx(const Vint* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7,
              Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vdouble* arg11, Vint* arg12, Vint* arg13, Vdouble* arg14, Vint* arg15,
              Vdouble* arg16, Vdouble* arg17, Vint* arg18, Vdouble* arg19, Vint* arg20, Vint* arg21, Vint* arg22, Vint* arg23)
{
}
static inline void
LAPACK_dsytrf(const Vchar* arg1, Vint* arg2, Vdouble* arg3, Vint* arg4, Vint* arg5, Vdouble* arg6, Vint* arg7, Vint* arg8)
{
}
static inline void
LAPACK_DGEQRF(Vlong* arg1, Vlong* arg2, Vdouble* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7, Vlong* arg8)
{
}
static inline void
LAPACK_DORMQR(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vlong* arg5, Vdouble* arg6, Vlong* arg7,
              Vdouble* arg8, Vdouble* arg9, Vlong* arg10, Vdouble* arg11, Vlong* arg12, Vlong* arg13)
{
}
static inline void
LAPACK_DSBEV(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
             Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vlong* arg11)
{
}
static inline void
LAPACK_DGESVD(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vlong* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7,
              Vdouble* arg8, Vlong* arg9, Vdouble* arg10, Vlong* arg11, Vdouble* arg12, Vlong* arg13, Vlong* arg14)
{
}
static inline void
LAPACK_DSYEV(const Vchar* arg1, const Vchar* arg2, Vlong* arg3, Vdouble* arg4, Vlong* arg5, Vdouble* arg6, Vdouble* arg7,
             Vlong* arg8, Vlong* arg9)
{
}

#endif

#ifdef __cplusplus
}
#endif

#endif
