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
#ifndef VMLBLAS_DEF
#define VMLBLAS_DEF
#include "sam/base/basedefs.h"

#ifdef __cplusplus
extern "C" {
#endif
/* Our own BLAS headers are always present */
VKI_EXTERN int
vki_drotg(double* da, double* db, double* c, double* s);
VKI_EXTERN int
vki_daxpy(const int* n, const double* da, const double* dx, const int* incx, double* dy, const int* incy);
VKI_EXTERN int
vki_dcopy(const int* n, const double* dx, const int* incx, double* dy, const int* incy);
VKI_EXTERN double
vki_ddot(const int* n, const double* dx, const int* incx, const double* dy, const int* incy);
VKI_EXTERN int
vki_dscal(const int* n, const double* da, double* dx, const int* incx);
VKI_EXTERN int
vki_dswap(const int* n, double* dx, const int* incx, double* dy, const int* incy);
VKI_EXTERN int
vki_idamax(const int* n, const double* dx, const int* incx);
VKI_EXTERN int
vki_dgemv(const char* trans, const Vint* m, const Vint* n, const double* alpha, const double* a, const Vint* lda, const double* x,
          const Vint* incx, const double* beta, double* y, const Vint* incy);
VKI_EXTERN int
vki_dger(const int* m, const int* n, const double* alpha, const double* x, const int* incx, const double* y, const int* incy,
         double* a, const int* lda);
VKI_EXTERN int
vki_dtrsm(const char* side, const char* uplo, const char* transa, const char* diag, const int* m, const int* n,
          const double* alpha, const double* a, const int* lda, double* b, const int* ldb);
VKI_EXTERN int
vki_dgemm(const char* transa, const char* transb, const int* m, const int* n, const int* k, const double* alpha, const double* a,
          const int* lda, const double* b, const int* ldb, const double* beta, double* c_, const int* ldc);
VKI_EXTERN int
vki_dsymm(const char* side, const char* uplo, const int* m, const int* n, const double* alpha, const double* a, const int* lda,
          const double* b, const int* ldb, const double* beta, double* c_, const int* ldc);
VKI_EXTERN int
vki_dtrmm(const char* side, const char* uplo, const char* transa, const char* diag, const int* m, const int* n,
          const double* alpha, const double* a, const int* lda, double* b, const int* ldb);
VKI_EXTERN double
vki_dnrm2(const int* n, const double* x, const int* incx);
VKI_EXTERN void
vki_dspmv(const char* uplo, const int* n, const double* alpha, const double* ap, const double* x, const int* incx,
          const double* beta, double* y, const int* incy);

#if defined(VKI_LIBAPI_BLASMKL_SEQUENTIAL) || defined(VKI_LIBAPI_BLASMKL_THREAD)
#ifdef VKI_LIBAPI_BLASMKL_ILP64
#ifndef MKL_ILP64
#define MKL_ILP64
#endif
#endif
#include "mkl.h"
#endif
#if defined(VKI_LIBAPI_BLASMKL_THREAD)
static inline void
BLAS_setnumthreads(Vint arg1, Vint* arg2)
{
    int knum = (arg1);
    *arg2 = mkl_set_num_threads_local(knum);
}
static inline void
BLAS_freebuffers()
{
    mkl_free_buffers();
}
#elif defined(VKI_LIBAPI_BLASMKL_SEQUENTIAL)
#if defined(__clang__) && (__clang_major__ >= 14)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-but-set-parameter"
#endif
static inline void
BLAS_setnumthreads(Vint arg1, Vint* arg2)
{
    arg1 = 1; /*remove warning of unused variable*/
    *arg2 = 1;
}
#if defined(__clang__) && (__clang_major__ >= 14)
#pragma clang diagnostic pop
#endif
static inline void
BLAS_freebuffers()
{
    mkl_free_buffers();
}
#elif defined(VKI_LIBAPI_OPENBLAS)
VKI_EXTERN void
openblas_set_num_threads(int);
int
openblas_get_num_threads();
static inline void
BLAS_setnumthreads(Vint arg1, Vint* arg2)
{
    int knum = (arg1);
    *arg2 = openblas_get_num_threads();
    openblas_set_num_threads(knum);
}
static inline void
BLAS_freebuffers()
{
}
#else
static inline void
BLAS_setnumthreads(Vint arg1, Vint* arg2)
{
    (void)arg1;
    *arg2 = 0;
}
static inline void
BLAS_freebuffers(void)
{
}
#endif

#if defined(VKI_LIBAPI_BLASMKL_SEQUENTIAL) || defined(VKI_LIBAPI_BLASMKL_THREAD)
/*
 * These are the MKL function definitions
 */
#ifdef VKI_LIBAPI_BLASMKL_ILP64
/*
 * BLAS interface uses 64-bit integers but calls to BLAS use 32-bit integers
 */
static inline void
BLAS_drotg(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4)
{
    drotg(arg1, arg2, arg3, arg4);
}
static inline void
BLAS_dscal(const Vint* arg1, const Vdouble* arg2, Vdouble* arg3, const Vint* arg4)
{
    Vlong larg1 = *(arg1);
    Vlong larg4 = *(arg4);
    dscal((&larg1), arg2, arg3, (&larg4));
}
static inline void
BLAS_dcopy(Vint* arg1, Vdouble* arg2, const Vint* arg3, Vdouble* arg4, Vint* arg5)
{
    Vlong larg1 = *(arg1);
    Vlong larg3 = *(arg3);
    Vlong larg5 = *(arg5);
    dcopy(&(larg1), arg2, &(larg3), arg4, &(larg5));
}

static inline void
BLAS_dgemm(const Vchar* arg1, const Vchar* arg2, const Vint* arg3, const Vint* arg4, const Vint* arg5, const Vdouble* arg6,
           const Vdouble* arg7, const Vint* arg8, const Vdouble* arg9, const Vint* arg10, const Vdouble* arg11, Vdouble* arg12,
           const Vint* arg13)
{
    Vlong larg3 = *(arg3);
    Vlong larg4 = *(arg4);
    Vlong larg5 = *(arg5);
    Vlong larg8 = *(arg8);
    Vlong larg10 = *(arg10);
    Vlong larg13 = *(arg13);
    dgemm(arg1, arg2, &(larg3), &(larg4), &(larg5), arg6, arg7, &(larg8), arg9, &(larg10), arg11, arg12, &(larg13));
}
static inline void
BLAS_dtrsm(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, const Vint* arg5, const Vint* arg6,
           const Vdouble* arg7, const Vdouble* arg8, const Vint* arg9, Vdouble* arg10, const Vint* arg11)
{
    Vlong larg5 = *(arg5);
    Vlong larg6 = *(arg6);
    Vlong larg9 = *(arg9);
    Vlong larg11 = *(arg11);
    dtrsm(arg1, arg2, arg3, arg4, &(larg5), &(larg6), arg7, arg8, &(larg9), arg10, &(larg11));
}
static inline void
BLAS_dgemv(const char* arg1, const Vint* arg2, const Vint* arg3, const double* arg4, const double* arg5, const Vint* arg6,
           const double* arg7, const Vint* arg8, const double* arg9, double* arg10, const Vint* arg11)
{
    Vlong larg2 = *(arg2);
    Vlong larg3 = *(arg3);
    Vlong larg6 = *(arg6);
    Vlong larg8 = *(arg8);
    Vlong larg11 = *(arg11);
    dgemv(arg1, &(larg2), &(larg3), arg4, arg5, &(larg6), arg7, &(larg8), arg9, arg10, &(larg11));
}
static inline void
BLAS_daxpy(const Vint* arg1, const Vdouble* arg2, const Vdouble* arg3, const Vint* arg4, Vdouble* arg5, const Vint* arg6)
{
    Vlong larg1 = *(arg1);
    Vlong larg4 = *(arg4);
    Vlong larg6 = *(arg6);
    daxpy(&(larg1), arg2, arg3, &(larg4), arg5, &(larg6));
}
static inline Vint
BLAS_idamax(const Vint* arg1, const Vdouble* arg2, const Vint* arg3)
{
    Vlong larg1 = *(arg1);
    Vlong larg3 = *(arg3);
    return (Vint)idamax(&(larg1), arg2, &(larg3));
}
static inline void
BLAS_dger(const Vint* arg1, const Vint* arg2, Vdouble* arg3, const Vdouble* arg4, const Vint* arg5, const Vdouble* arg6,
          const Vint* arg7, Vdouble* arg8, const Vint* arg9)
{
    Vlong larg1 = *(arg1);
    Vlong larg2 = *(arg2);
    Vlong larg5 = *(arg5);
    Vlong larg7 = *(arg7);
    Vlong larg9 = *(arg9);
    dger(&(larg1), &(larg2), arg3, arg4, &(larg5), arg6, &(larg7), arg8, &(larg9));
}
static inline void
BLAS_dswap(const Vint* arg1, Vdouble* arg2, const Vint* arg3, Vdouble* arg4, const Vint* arg5)
{
    Vlong larg1 = *(arg1);
    Vlong larg3 = *(arg3);
    Vlong larg5 = *(arg5);
    dswap(&(larg1), arg2, &(larg3), arg4, &(larg5));
}
static inline void
BLAS_dtrmm(Vchar* arg1, Vchar* arg2, Vchar* arg3, Vchar* arg4, Vint* arg5, Vint* arg6, Vdouble* arg7, Vdouble* arg8, Vint* arg9,
           Vdouble* arg10, Vint* arg11)
{
    Vlong larg5 = *(arg5);
    Vlong larg6 = *(arg6);
    Vlong larg9 = *(arg9);
    Vlong larg11 = *(arg11);
    dtrmm(arg1, arg2, arg3, arg4, &(larg5), &(larg6), arg7, arg8, &(larg9), arg10, &(larg11));
}
static inline Vdouble
BLAS_dnrm2(Vint* arg1, Vdouble* arg2, Vint* arg3)
{
    Vlong larg1 = (Vlong) * (arg1);
    Vlong larg3 = (Vlong) * (arg3);
    return dnrm2(&larg1, arg2, &larg3);
}
static inline Vdouble
BLAS_ddot(Vint* arg1, Vdouble* arg2, Vint* arg3, Vdouble* arg4, Vint* arg5)
{
    Vlong larg1 = (Vlong) * (arg1);
    Vlong larg3 = (Vlong) * (arg3);
    Vlong larg5 = (Vlong) * (arg5);
    return ddot(&larg1, arg2, &larg3, arg4, &larg5);
}
static inline void
BLAS_dspmv(Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7, Vdouble* arg8,
           Vint* arg9)
{
    Vlong larg2 = *(arg2);
    Vlong larg6 = *(arg6);
    Vlong larg9 = *(arg9);
    dspmv(arg1, &(larg2), arg3, arg4, arg5, &(larg6), arg7, arg8, &(larg9));
}
static inline void
BLAS_dsyr2k(Vchar* arg1, Vchar* arg2, Vint* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7, Vdouble* arg8, Vint* arg9,
            Vdouble* arg10, Vdouble* arg11, Vint* arg12)
{
    Vlong larg3 = *(arg3);
    Vlong larg4 = *(arg4);
    Vlong larg7 = *(arg7);
    Vlong larg9 = *(arg9);
    Vlong larg12 = *(arg12);
    dsyr2k(arg1, arg2, &(larg3), &(larg4), arg5, arg6, &(larg7), arg8, &(larg9), arg10, arg11, &(larg12));
}
/*
 * BLAS interface uses 64-bit integers and calls to BLAS use 64-bit integers
 */
static inline void
BLAS_DROTG(double* arg1, double* arg2, double* arg3, double* arg4)
{
    drotg(arg1, arg2, arg3, arg4);
}
static inline void
BLAS_DSCAL(const Vlong* arg1, const Vdouble* arg2, Vdouble* arg3, const Vlong* arg4)
{
    dscal(arg1, arg2, arg3, arg4);
}
static inline void
BLAS_DCOPY(Vlong* arg1, Vdouble* arg2, const Vlong* arg3, Vdouble* arg4, Vlong* arg5)
{
    dcopy(arg1, arg2, arg3, arg4, arg5);
}
static inline void
BLAS_DGEMM(const Vchar* arg1, const Vchar* arg2, const Vlong* arg3, const Vlong* arg4, const Vlong* arg5, const Vdouble* arg6,
           const Vdouble* arg7, const Vlong* arg8, const Vdouble* arg9, const Vlong* arg10, const Vdouble* arg11, Vdouble* arg12,
           const Vlong* arg13)
{
    dgemm(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
}
static inline void
BLAS_DTRSM(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, const Vlong* arg5, const Vlong* arg6,
           const Vdouble* arg7, const Vdouble* arg8, const Vlong* arg9, Vdouble* arg10, const Vlong* arg11)
{
    dtrsm(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
BLAS_DGEMV(const char* arg1, const Vlong* arg2, const Vlong* arg3, const double* arg4, const double* arg5, const Vlong* arg6,
           const double* arg7, const Vlong* arg8, const double* arg9, double* arg10, const Vlong* arg11)
{
    dgemv(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline Vdouble
BLAS_DDOT(Vlong* arg1, Vdouble* arg2, Vlong* arg3, Vdouble* arg4, Vlong* arg5)
{
    return ddot(arg1, arg2, arg3, arg4, arg5);
}
static inline void
BLAS_DAXPY(const Vlong* arg1, const Vdouble* arg2, const Vdouble* arg3, const Vlong* arg4, Vdouble* arg5, const Vlong* arg6)
{
    daxpy(arg1, arg2, arg3, arg4, arg5, arg6);
}
static inline Vlong
BLAS_IDAMAX(const Vlong* arg1, const Vdouble* arg2, const Vlong* arg3)
{
    return idamax(arg1, arg2, arg3);
}
static inline void
BLAS_DGER(const Vlong* arg1, const Vlong* arg2, Vdouble* arg3, const Vdouble* arg4, const Vlong* arg5, const Vdouble* arg6,
          const Vlong* arg7, Vdouble* arg8, const Vlong* arg9)
{
    dger(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
static inline void
BLAS_DSWAP(const Vlong* arg1, Vdouble* arg2, const Vlong* arg3, Vdouble* arg4, const Vlong* arg5)
{
    dswap(arg1, arg2, arg3, arg4, arg5);
}
static inline void
BLAS_DTRMM(Vchar* arg1, Vchar* arg2, Vchar* arg3, Vchar* arg4, Vlong* arg5, Vlong* arg6, Vdouble* arg7, Vdouble* arg8,
           Vlong* arg9, Vdouble* arg10, Vlong* arg11)
{
    dtrmm(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline Vdouble
BLAS_DNRM2(Vlong* arg1, Vdouble* arg2, Vlong* arg3)
{
    return dnrm2(arg1, arg2, arg3);
}
static inline void
BLAS_DSPMV(Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7, Vdouble* arg8,
           Vlong* arg9)
{
    dspmv(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
static inline void
BLAS_DSYR2K(Vchar* arg1, Vchar* arg2, Vlong* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7, Vdouble* arg8,
            Vlong* arg9, Vdouble* arg10, Vdouble* arg11, Vlong* arg12)
{
    dsyr2k(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
#else

/*
 * BLAS interface uses 32-bit integers and calls to BLAS use 32-bit integers
 */
static inline void
BLAS_drotg(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4)
{
    drotg(arg1, arg2, arg3, arg4);
}
static inline void
BLAS_dscal(const Vint* arg1, const Vdouble* arg2, Vdouble* arg3, const Vint* arg4)
{
    dscal(arg1, arg2, arg3, arg4);
}
static inline void
BLAS_dcopy(Vint* arg1, Vdouble* arg2, const Vint* arg3, Vdouble* arg4, Vint* arg5)
{
    dcopy(arg1, arg2, arg3, arg4, arg5);
}
static inline void
BLAS_dgemm(const Vchar* arg1, const Vchar* arg2, const Vint* arg3, const Vint* arg4, const Vint* arg5, const Vdouble* arg6,
           const Vdouble* arg7, const Vint* arg8, const Vdouble* arg9, const Vint* arg10, const Vdouble* arg11, Vdouble* arg12,
           const Vint* arg13)
{
    dgemm(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
}
static inline void
BLAS_dtrsm(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, const Vint* arg5, const Vint* arg6,
           const Vdouble* arg7, const Vdouble* arg8, const Vint* arg9, Vdouble* arg10, const Vint* arg11)
{
    dtrsm(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
BLAS_dgemv(const char* arg1, const Vint* arg2, const Vint* arg3, const double* arg4, const double* arg5, const Vint* arg6,
           const double* arg7, const Vint* arg8, const double* arg9, double* arg10, const Vint* arg11)
{
    dgemv(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline Vdouble
BLAS_ddot(Vint* arg1, Vdouble* arg2, Vint* arg3, Vdouble* arg4, Vint* arg5)
{
    return ddot(arg1, arg2, arg3, arg4, arg5);
}
static inline void
BLAS_daxpy(const Vint* arg1, const Vdouble* arg2, const Vdouble* arg3, const Vint* arg4, Vdouble* arg5, const Vint* arg6)
{
    daxpy(arg1, arg2, arg3, arg4, arg5, arg6);
}
static inline Vint
BLAS_idamax(const Vint* arg1, const Vdouble* arg2, const Vint* arg3)
{
    return idamax(arg1, arg2, arg3);
}
static inline void
BLAS_dger(const Vint* arg1, const Vint* arg2, Vdouble* arg3, const Vdouble* arg4, const Vint* arg5, const Vdouble* arg6,
          const Vint* arg7, Vdouble* arg8, const Vint* arg9)
{
    dger(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
static inline void
BLAS_dswap(const Vint* arg1, Vdouble* arg2, const Vint* arg3, Vdouble* arg4, const Vint* arg5)
{
    dswap(arg1, arg2, arg3, arg4, arg5);
}
static inline void
BLAS_dtrmm(Vchar* arg1, Vchar* arg2, Vchar* arg3, Vchar* arg4, Vint* arg5, Vint* arg6, Vdouble* arg7, Vdouble* arg8, Vint* arg9,
           Vdouble* arg10, Vint* arg11)
{
    dtrmm(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline Vdouble
BLAS_dnrm2(Vint* arg1, Vdouble* arg2, Vint* arg3)
{
    return dnrm2(arg1, arg2, arg3);
}
static inline void
BLAS_dspmv(Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7, Vdouble* arg8,
           Vint* arg9)
{
    dspmv(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
static inline void
BLAS_dsyr2k(Vchar* arg1, Vchar* arg2, Vint* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7, Vdouble* arg8, Vint* arg9,
            Vdouble* arg10, Vdouble* arg11, Vint* arg12)
{
    dsyr2k(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}

/*
 * BLAS interface uses 32-bit integers but calls to BLAS use 64-bit integers
 */
static inline void
BLAS_DROTG(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4)
{
    drotg(arg1, arg2, arg3, arg4);
}
static inline void
BLAS_DSCAL(const Vlong* arg1, const Vdouble* arg2, Vdouble* arg3, const Vlong* arg4)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg4 = (Vint) * (arg4);
    dscal((&larg1), arg2, arg3, (&larg4));
}
static inline void
BLAS_DSYR(const Vchar* uplo, const Vlong* n, const Vdouble* alpha, const Vdouble* x, const Vlong* incx, Vdouble* A,
          const Vlong* lda)
{
    Vint i_n = (Vint)*n;
    Vint i_incx = (Vint)*incx;
    Vint i_lda = (Vint)*lda;
    dsyr(uplo, &i_n, alpha, x, &i_incx, A, &i_lda);
}
static inline void
BLAS_DCOPY(Vlong* arg1, Vdouble* arg2, const Vlong* arg3, Vdouble* arg4, Vlong* arg5)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg3 = (Vint) * (arg3);
    Vint larg5 = (Vint) * (arg5);
    dcopy(&(larg1), arg2, &(larg3), arg4, &(larg5));
}
static inline void
BLAS_DGEMM(const Vchar* arg1, const Vchar* arg2, const Vlong* arg3, const Vlong* arg4, Vlong* arg5, const Vdouble* arg6,
           const Vdouble* arg7, const Vlong* arg8, const Vdouble* arg9, const Vlong* arg10, const Vdouble* arg11, Vdouble* arg12,
           const Vlong* arg13)
{
    Vint larg3 = (Vint) * (arg3);
    Vint larg4 = (Vint) * (arg4);
    Vint larg5 = (Vint) * (arg5);
    Vint larg8 = (Vint) * (arg8);
    Vint larg10 = (Vint) * (arg10);
    Vint larg13 = (Vint) * (arg13);
    dgemm(arg1, arg2, &(larg3), &(larg4), &(larg5), arg6, arg7, &(larg8), arg9, &(larg10), arg11, arg12, &(larg13));
}
static inline void
BLAS_DTRSM(const Vchar* side, const Vchar* uplo, const Vchar* transA, const Vchar* diag, const Vlong* m, const Vlong* n,
           const Vdouble* alpha, const Vdouble* A, const Vlong* lda, Vdouble* B, const Vlong* ldb)
{
    Vint larg5 = (Vint) * (m);
    Vint larg6 = (Vint) * (n);
    Vint larg9 = (Vint) * (lda);
    Vint larg11 = (Vint) * (ldb);
    dtrsm(side, uplo, transA, diag, &(larg5), &(larg6), alpha, A, &(larg9), B, &(larg11));
}
static inline void
BLAS_DGEMV(const char* arg1, const Vlong* arg2, const Vlong* arg3, const double* arg4, const double* arg5, const Vlong* arg6,
           const double* arg7, const Vlong* arg8, const double* arg9, double* arg10, const Vlong* arg11)
{
    Vint larg2 = (Vint) * (arg2);
    Vint larg3 = (Vint) * (arg3);
    Vint larg6 = (Vint) * (arg6);
    Vint larg8 = (Vint) * (arg8);
    Vint larg11 = (Vint) * (arg11);
    dgemv(arg1, &(larg2), &(larg3), arg4, arg5, &(larg6), arg7, &(larg8), arg9, arg10, &(larg11));
}
static inline void
BLAS_DAXPY(const Vlong* arg1, const Vdouble* arg2, const Vdouble* arg3, const Vlong* arg4, Vdouble* arg5, const Vlong* arg6)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg4 = (Vint) * (arg4);
    Vint larg6 = (Vint) * (arg6);
    daxpy(&(larg1), arg2, arg3, &(larg4), arg5, &(larg6));
}
static inline Vlong
BLAS_IDAMAX(const Vlong* arg1, const Vdouble* arg2, const Vlong* arg3)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg3 = (Vint) * (arg3);
    return (Vlong)idamax(&(larg1), arg2, &(larg3));
}
static inline void
BLAS_DGER(const Vlong* arg1, const Vlong* arg2, Vdouble* arg3, const Vdouble* arg4, const Vlong* arg5, const Vdouble* arg6,
          const Vlong* arg7, Vdouble* arg8, const Vlong* arg9)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg2 = (Vint) * (arg2);
    Vint larg5 = (Vint) * (arg5);
    Vint larg7 = (Vint) * (arg7);
    Vint larg9 = (Vint) * (arg9);
    dger(&(larg1), &(larg2), arg3, arg4, &(larg5), arg6, &(larg7), arg8, &(larg9));
}
static inline void
BLAS_DSWAP(const Vlong* arg1, Vdouble* arg2, const Vlong* arg3, Vdouble* arg4, const Vlong* arg5)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg3 = (Vint) * (arg3);
    Vint larg5 = (Vint) * (arg5);
    dswap(&(larg1), arg2, &(larg3), arg4, &(larg5));
}
static inline void
BLAS_DTRMM(Vchar* arg1, Vchar* arg2, Vchar* arg3, Vchar* arg4, Vlong* arg5, Vlong* arg6, Vdouble* arg7, Vdouble* arg8,
           Vlong* arg9, Vdouble* arg10, Vlong* arg11)
{
    Vint larg5 = (Vint) * (arg5);
    Vint larg6 = (Vint) * (arg6);
    Vint larg9 = (Vint) * (arg9);
    Vint larg11 = (Vint) * (arg11);
    dtrmm(arg1, arg2, arg3, arg4, &(larg5), &(larg6), arg7, arg8, &(larg9), arg10, &(larg11));
}
static inline Vdouble
BLAS_DNRM2(Vlong* arg1, Vdouble* arg2, Vlong* arg3)
{
    Vint iarg1 = (Vint) * (arg1);
    Vint iarg3 = (Vint) * (arg3);
    return dnrm2(&iarg1, arg2, &iarg3);
}
static inline Vdouble
BLAS_DDOT(Vlong* arg1, Vdouble* arg2, Vlong* arg3, Vdouble* arg4, Vlong* arg5)
{
    Vint iarg1 = (Vint) * (arg1);
    Vint iarg3 = (Vint) * (arg3);
    Vint iarg5 = (Vint) * (arg5);
    return ddot(&iarg1, arg2, &iarg3, arg4, &iarg5);
}
static inline void
BLAS_DSPMV(Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7, Vdouble* arg8,
           Vlong* arg9)
{
    Vint larg2 = (Vint) * (arg2);
    Vint larg6 = (Vint) * (arg6);
    Vint larg9 = (Vint) * (arg9);
    dspmv(arg1, &(larg2), arg3, arg4, arg5, &(larg6), arg7, arg8, &(larg9));
}
static inline void
BLAS_DSYR2K(Vchar* arg1, Vchar* arg2, Vlong* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7, Vdouble* arg8,
            Vlong* arg9, Vdouble* arg10, Vdouble* arg11, Vlong* arg12)
{
    Vint larg3 = (Vint) * (arg3);
    Vint larg4 = (Vint) * (arg4);
    Vint larg7 = (Vint) * (arg7);
    Vint larg9 = (Vint) * (arg9);
    Vint larg12 = (Vint) * (arg12);
    dsyr2k(arg1, arg2, &(larg3), &(larg4), arg5, arg6, &(larg7), arg8, &(larg9), arg10, arg11, &(larg12));
}
#endif
#elif defined(VKI_LIBAPI_OPENBLAS)
#include "cblas.h"
/*
 * These are the MKL function definitions
 */
#ifdef OPENBLAS_USE64BITINT
/*
 * BLAS interface uses 64-bit integers but calls to BLAS use 32-bit integers
 */
static inline void
BLAS_drotg(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4)
{
    cblas_drotg(arg1, arg2, arg3, arg4);
}
static inline void
BLAS_dscal(const Vint* arg1, const Vdouble* arg2, Vdouble* arg3, const Vint* arg4)
{
    Vlong larg1 = *(arg1);
    Vlong larg4 = *(arg4);
    cblas_dscal(larg1, *(arg2), arg3, larg4);
}
static inline void
BLAS_dcopy(Vint* arg1, Vdouble* arg2, const Vint* arg3, Vdouble* arg4, Vint* arg5)
{
    Vlong larg1 = (Vlong) * (arg1);
    Vlong larg3 = (Vlong) * (arg3);
    Vlong larg5 = (Vlong) * (arg5);
    cblas_dcopy(larg1, arg2, larg3, arg4, larg5);
}
static inline void
BLAS_dgemm(const Vchar* arg1, const Vchar* arg2, const Vint* arg3, const Vint* arg4, const Vint* arg5, const Vdouble* arg6,
           const Vdouble* arg7, const Vint* arg8, const Vdouble* arg9, const Vint* arg10, const Vdouble* arg11, Vdouble* arg12,
           const Vint* arg13)
{
    Vlong larg3 = (Vlong) * (arg3);
    Vlong larg4 = (Vlong) * (arg4);
    Vlong larg5 = (Vlong) * (arg5);
    Vlong larg8 = (Vlong) * (arg8);
    Vlong larg10 = (Vlong) * (arg10);
    Vlong larg13 = (Vlong) * (arg13);
    cblas_dgemm(CblasColMajor, (arg1)[0] == 'n' || (arg1)[0] == 'N' ? CblasNoTrans : CblasTrans,
                (arg2)[0] == 'n' || (arg2)[0] == 'N' ? CblasNoTrans : CblasTrans, larg3, larg4, larg5, *(arg6), arg7, larg8, arg9,
                larg10, *(arg11), arg12, larg13);
}
static inline void
BLAS_dtrsm(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, const Vint* arg5, const Vint* arg6,
           const Vdouble* arg7, const Vdouble* arg8, const Vint* arg9, Vdouble* arg10, const Vint* arg11)
{
    blasint larg5 = (blasint) * (arg5);
    blasint larg6 = (blasint) * (arg6);
    blasint larg9 = (blasint) * (arg9);
    blasint larg11 = (blasint) * (arg11);
    cblas_dtrsm(CblasColMajor, (arg1)[0] == 'l' || (arg1)[0] == 'L' ? CblasLeft : CblasRight,
                (arg2)[0] == 'u' || (arg2)[0] == 'U' ? CblasUpper : CblasLower,
                (arg3)[0] == 'n' || (arg3)[0] == 'N' ? CblasNoTrans : CblasTrans,
                (arg4)[0] == 'u' || (arg4)[0] == 'U' ? CblasUnit : CblasNonUnit, larg5, larg6, *arg7, arg8, larg9, arg10, larg11);
}
static inline void
BLAS_dgemv(const char* arg1, const Vint* arg2, const Vint* arg3, const double* arg4, const double* arg5, const Vint* arg6,
           const double* arg7, const Vint* arg8, const double* arg9, double* arg10, const Vint* arg11)
{
    Vlong larg2 = *(arg2);
    Vlong larg3 = *(arg3);
    Vlong larg6 = *(arg6);
    Vlong larg8 = *(arg8);
    Vlong larg11 = *(arg11);
    cblas_dgemv(CblasColMajor, (arg1)[0] == 'n' || (arg1)[0] == 'N' ? CblasNoTrans : CblasTrans, larg2, larg3, *(arg4), arg5,
                larg6, arg7, larg8, *(arg9), arg10, larg11);
}
static inline void
BLAS_daxpy(const Vint* arg1, const Vdouble* arg2, const Vdouble* arg3, const Vint* arg4, Vdouble* arg5, const Vint* arg6)
{
    Vlong larg1 = *(arg1);
    Vlong larg4 = *(arg4);
    Vlong larg6 = *(arg6);
    cblas_daxpy(larg1, *(arg2), arg3, larg4, arg5, larg6);
}
static inline Vint
BLAS_idamax(Vint* arg1, Vdouble* arg2, Vint* arg3)
{
    const Vlong larg1 = *(arg1);
    const Vlong larg3 = *(arg3);
    return (Vint)cblas_idamax(larg1, arg2, larg3);
}
static inline void
BLAS_dger(const Vint* arg1, const Vint* arg2, Vdouble* arg3, const Vdouble* arg4, const Vint* arg5, const Vdouble* arg6,
          const Vint* arg7, Vdouble* arg8, const Vint* arg9)
{
    Vlong larg1 = *(arg1);
    Vlong larg2 = *(arg2);
    Vlong larg5 = *(arg5);
    Vlong larg7 = *(arg7);
    Vlong larg9 = *(arg9);
    cblas_dger(CblasColMajor, larg1, larg2, *(arg3), arg4, larg5, arg6, larg7, arg8, larg9);
}
static inline void
BLAS_dswap(const Vint* arg1, Vdouble* arg2, const Vint* arg3, Vdouble* arg4, const Vint* arg5)
{
    Vlong larg1 = *(arg1);
    Vlong larg3 = *(arg3);
    Vlong larg5 = *(arg5);
    cblas_dswap(larg1, arg2, larg3, arg4, larg5);
}
static inline void
BLAS_dtrmm(Vchar* arg1, Vchar* arg2, Vchar* arg3, Vchar* arg4, Vint* arg5, Vint* arg6, Vdouble* arg7, Vdouble* arg8, Vint* arg9,
           Vdouble* arg10, Vint* arg11)
{
    const Vlong larg5 = *(arg5);
    const Vlong larg6 = *(arg6);
    const Vlong larg9 = *(arg9);
    const Vlong larg11 = *(arg11);
    cblas_dtrmm(CblasColMajor, (arg1)[0] == 'l' || (arg1)[0] == 'L' ? CblasLeft : CblasRight,
                (arg2)[0] == 'u' || (arg2)[0] == 'U' ? CblasUpper : CblasLower,
                (arg3)[0] == 'n' || (arg3)[0] == 'N' ? CblasNoTrans : CblasTrans,
                (arg4)[0] == 'u' || (arg4)[0] == 'U' ? CblasUnit : CblasNonUnit, larg5, larg6, *arg7, arg8, larg9, arg10, larg11);
}
static inline Vdouble
BLAS_dnrm2(Vint* arg1, Vdouble* arg2, Vint* arg3)
{
    blasint larg1 = (blasint) * (arg1);
    blasint larg3 = (blasint) * (arg3);
    return cblas_dnrm2(larg1, arg2, larg3);
}
static inline Vdouble
BLAS_ddot(Vint* arg1, Vdouble* arg2, Vint* arg3, Vdouble* arg4, Vint* arg5)
{
    const Vlong larg1 = (Vlong) * (arg1);
    const Vlong larg3 = (Vlong) * (arg3);
    const Vlong larg5 = (Vlong) * (arg5);
    return cblas_ddot(larg1, arg2, larg3, arg4, larg5);
}
static inline void
BLAS_dspmv(Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7, Vdouble* arg8,
           Vint* arg9)
{
    const Vlong larg2 = *(arg2);
    const Vlong larg6 = *(arg6);
    const Vlong larg9 = *(arg9);
    cblas_dspmv(CblasColMajor, (arg1)[0] == 'u' || (arg1)[0] == 'U' ? CblasUpper : CblasLower, larg2, *arg3, arg4, arg5, larg6,
                *arg7, arg8, larg9);
}
static inline void
BLAS_dsyr2k(Vchar* arg1, Vchar* arg2, Vint* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7, Vdouble* arg8, Vint* arg9,
            Vdouble* arg10, Vdouble* arg11, Vint* arg12)
{
    const Vlong larg3 = *(arg3);
    const Vlong larg4 = *(arg4);
    const Vlong larg7 = *(arg7);
    const Vlong larg9 = *(arg9);
    const Vlong larg12 = *(arg12);
    cblas_dsyr2k(CblasColMajor, (arg1)[0] == 'u' || (arg1)[0] == 'U' ? CblasUpper : CblasLower,
                 (arg2)[0] == 'n' || (arg2)[0] == 'N' ? CblasNoTrans : CblasTrans, larg3, larg4, *arg5, arg6, larg7, arg8, larg9,
                 *arg10, arg11, larg12);
}
/*
 * BLAS interface uses 64-bit integers and calls to BLAS use 64-bit integers
 */
static inline void
BLAS_DROTG(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4)
{
    cblas_drotg(arg1, arg2, arg3, arg4);
}
static inline void
BLAS_DSCAL(const Vlong* arg1, const Vdouble* arg2, Vdouble* arg3, const Vlong* arg4)
{
    cblas_dscal(*(arg1), *(arg2), arg3, *(arg4));
}
static inline void
BLAS_DCOPY(Vlong* arg1, Vdouble* arg2, const Vlong* arg3, Vdouble* arg4, Vlong* arg5)
{
    cblas_dcopy(*(arg1), arg2, *(arg3), arg4, *(arg5));
}
static inline void
BLAS_DGEMM(const Vchar* arg1, const Vchar* arg2, const Vlong* arg3, const Vlong* arg4, const Vlong* arg5, const Vdouble* arg6,
           const Vdouble* arg7, const Vlong* arg8, const Vdouble* arg9, const Vlong* arg10, const Vdouble* arg11, Vdouble* arg12,
           const Vlong* arg13)
{
    cblas_dgemm(CblasColMajor, (arg1)[0] == 'n' || (arg1)[0] == 'N' ? CblasNoTrans : CblasTrans,
                (arg2)[0] == 'n' || (arg2)[0] == 'N' ? CblasNoTrans : CblasTrans, *(arg3), *(arg4), *(arg5), *(arg6), arg7,
                *(arg8), arg9, *(arg10), *(arg11), arg12, *(arg13));
}
static inline void
BLAS_DTRSM(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, const Vlong* arg5, const Vlong* arg6,
           const Vdouble* arg7, const Vdouble* arg8, const Vlong* arg9, Vdouble* arg10, const Vlong* arg11)
{
    cblas_dtrsm(CblasColMajor, (arg1)[0] == 'l' || (arg1)[0] == 'L' ? CblasLeft : CblasRight,
                (arg2)[0] == 'u' || (arg2)[0] == 'U' ? CblasUpper : CblasLower,
                (arg3)[0] == 'n' || (arg3)[0] == 'N' ? CblasNoTrans : CblasTrans,
                (arg4)[0] == 'u' || (arg4)[0] == 'U' ? CblasUnit : CblasNonUnit, *(arg5), *(arg6), *(arg7), arg8, *(arg9), arg10,
                *(arg11));
}
static inline void
BLAS_DGEMV(const char* arg1, const Vlong* arg2, const Vlong* arg3, const double* arg4, const double* arg5, const Vlong* arg6,
           const double* arg7, const Vlong* arg8, const double* arg9, double* arg10, const Vlong* arg11)
{
    cblas_dgemv(CblasColMajor, (arg1)[0] == 'n' || (arg1)[0] == 'N' ? CblasNoTrans : CblasTrans, *(arg2), *(arg3), *(arg4), arg5,
                *(arg6), arg7, *(arg8), *(arg9), arg10, *(arg11));
}
static inline Vdouble
BLAS_DDOT(Vlong* arg1, Vdouble* arg2, Vlong* arg3, Vdouble* arg4, Vlong* arg5)
{
    return cblas_ddot(*arg1, arg2, *arg3, arg4, *arg5);
}
static inline void
BLAS_DAXPY(const Vlong* arg1, const Vdouble* arg2, const Vdouble* arg3, const Vlong* arg4, Vdouble* arg5, const Vlong* arg6)
{
    cblas_daxpy(*(arg1), *(arg2), arg3, *(arg4), arg5, *(arg6));
}
static inline Vlong
BLAS_IDAMAX(Vlong* arg1, Vdouble* arg2, Vlong* arg3)
{
    return cblas_idamax(*arg1, arg2, *arg3);
}
static inline void
BLAS_DGER(const Vlong* arg1, const Vlong* arg2, Vdouble* arg3, const Vdouble* arg4, const Vlong* arg5, const Vdouble* arg6,
          const Vlong* arg7, Vdouble* arg8, const Vlong* arg9)
{
    cblas_dger(CblasColMajor, *(arg1), *(arg2), *(arg3), arg4, *(arg5), arg6, *(arg7), arg8, *(arg9));
}
static inline void
BLAS_DSWAP(const Vlong* arg1, Vdouble* arg2, const Vlong* arg3, Vdouble* arg4, const Vlong* arg5)
{
    cblas_dswap(*(arg1), arg2, *(arg3), arg4, *(arg5));
}
static inline void
BLAS_DTRMM(Vchar* arg1, Vchar* arg2, Vchar* arg3, Vchar* arg4, Vlong* arg5, Vlong* arg6, Vdouble* arg7, Vdouble* arg8,
           Vlong* arg9, Vdouble* arg10, Vlong* arg11)
{
    cblas_dtrmm(CblasColMajor, (arg1)[0] == 'l' || (arg1)[0] == 'L' ? CblasLeft : CblasRight,
                (arg2)[0] == 'u' || (arg2)[0] == 'U' ? CblasUpper : CblasLower,
                (arg3)[0] == 'n' || (arg3)[0] == 'N' ? CblasNoTrans : CblasTrans,
                (arg4)[0] == 'u' || (arg4)[0] == 'U' ? CblasUnit : CblasNonUnit, *arg5, *arg6, *arg7, arg8, *arg9, arg10, *arg11);
}
static inline Vdouble
BLAS_DNRM2(Vlong* arg1, Vdouble* arg2, Vlong* arg3)
{
    blasint larg1 = (blasint) * (arg1);
    blasint larg3 = (blasint) * (arg3);
    return cblas_dnrm2(larg1, arg2, larg3);
}
static inline void
BLAS_DSPMV(Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7, Vdouble* arg8,
           Vlong* arg9)
{
    cblas_dspmv(CblasColMajor, (arg1)[0] == 'u' || (arg1)[0] == 'U' ? CblasUpper : CblasLower, *arg2, *arg3, arg4, arg5, *arg6,
                *arg7, arg8, *arg9);
}
static inline void
BLAS_DSYR2K(Vchar* arg1, Vchar* arg2, Vlong* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7, Vdouble* arg8,
            Vlong* arg9, Vdouble* arg10, Vdouble* arg11, Vlong* arg12)
{
    cblas_dsyr2k(CblasColMajor, (arg1)[0] == 'u' || (arg1)[0] == 'U' ? CblasUpper : CblasLower,
                 (arg2)[0] == 'n' || (arg2)[0] == 'N' ? CblasNoTrans : CblasTrans, *arg3, *arg4, *arg5, arg6, *arg7, arg8, *arg9,
                 *arg10, arg11, *arg12);
}

#else

/*
 * BLAS interface uses 32-bit integers and calls to BLAS use 32-bit integers
 */
static inline void
BLAS_drotg(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4)
{
    cblas_drotg(arg1, arg2, arg3, arg4);
}
static inline void
BLAS_dscal(const Vint* arg1, const Vdouble* arg2, Vdouble* arg3, const Vint* arg4)
{
    cblas_dscal(*(arg1), *(arg2), arg3, *(arg4));
}
static inline void
BLAS_dcopy(Vint* arg1, Vdouble* arg2, const Vint* arg3, Vdouble* arg4, Vint* arg5)
{
    cblas_dcopy(*(arg1), arg2, *(arg3), arg4, *(arg5));
}
static inline void
BLAS_dgemm(const Vchar* arg1, const Vchar* arg2, const Vint* arg3, const Vint* arg4, const Vint* arg5, const Vdouble* arg6,
           const Vdouble* arg7, const Vint* arg8, const Vdouble* arg9, const Vint* arg10, const Vdouble* arg11, Vdouble* arg12,
           const Vint* arg13)
{
    cblas_dgemm(CblasColMajor, (arg1)[0] == 'n' || (arg1)[0] == 'N' ? CblasNoTrans : CblasTrans,
                (arg2)[0] == 'n' || (arg2)[0] == 'N' ? CblasNoTrans : CblasTrans, *(arg3), *(arg4), *(arg5), *(arg6), arg7,
                *(arg8), arg9, *(arg10), *(arg11), arg12, *(arg13));
}
static inline void
BLAS_dtrsm(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, const Vint* arg5, const Vint* arg6,
           const Vdouble* arg7, const Vdouble* arg8, const Vint* arg9, Vdouble* arg10, const Vint* arg11)
{
    cblas_dtrsm(CblasColMajor, (arg1)[0] == 'l' || (arg1)[0] == 'L' ? CblasLeft : CblasRight,
                (arg2)[0] == 'u' || (arg2)[0] == 'U' ? CblasUpper : CblasLower,
                (arg3)[0] == 'n' || (arg3)[0] == 'N' ? CblasNoTrans : CblasTrans,
                (arg4)[0] == 'u' || (arg4)[0] == 'U' ? CblasUnit : CblasNonUnit, *(arg5), *(arg6), *(arg7), arg8, *(arg9), arg10,
                *(arg11));
}
static inline void
BLAS_dsyr(const Vchar* arg1, const Vint* arg2, const Vdouble* arg3, Vdouble* arg4, const Vint* arg5, Vdouble* A, const Vint* lda)
{
    cblas_dsyr(CblasColMajor, (arg1)[0] == 'u' || (arg1)[0] == 'U' ? CblasUpper : CblasLower, *arg2, *arg3, arg4, *arg5, A, *lda);
}
static inline void
BLAS_dgemv(const char* arg1, const Vint* arg2, const Vint* arg3, const double* arg4, const double* arg5, const Vint* arg6,
           const double* arg7, const Vint* arg8, const double* arg9, double* arg10, const Vint* arg11)
{
    cblas_dgemv(CblasColMajor, (arg1)[0] == 'n' || (arg1)[0] == 'N' ? CblasNoTrans : CblasTrans, *(arg2), *(arg3), *(arg4), arg5,
                *(arg6), arg7, *(arg8), *(arg9), arg10, *(arg11));
}
static inline Vdouble
BLAS_ddot(Vint* arg1, Vdouble* arg2, Vint* arg3, Vdouble* arg4, Vint* arg5)
{
    return cblas_ddot(*arg1, arg2, *arg3, arg4, *arg5);
}
static inline void
BLAS_daxpy(const Vint* arg1, const Vdouble* arg2, const Vdouble* arg3, const Vint* arg4, Vdouble* arg5, const Vint* arg6)
{
    cblas_daxpy(*(arg1), *(arg2), arg3, *(arg4), arg5, *(arg6));
}
static inline Vint
BLAS_idamax(Vint* arg1, Vdouble* arg2, Vint* arg3)
{
    return (Vint)cblas_idamax(*arg1, arg2, *arg3);
}
static inline void
BLAS_dger(const Vint* arg1, const Vint* arg2, Vdouble* arg3, const Vdouble* arg4, const Vint* arg5, const Vdouble* arg6,
          const Vint* arg7, Vdouble* arg8, const Vint* arg9)
{
    cblas_dger(CblasColMajor, *(arg1), *(arg2), *(arg3), arg4, *(arg5), arg6, *(arg7), arg8, *(arg9));
}
static inline void
BLAS_dswap(const Vint* arg1, Vdouble* arg2, const Vint* arg3, Vdouble* arg4, const Vint* arg5)
{
    cblas_dswap(*(arg1), arg2, *(arg3), arg4, *(arg5));
}
static inline void
BLAS_dtrmm(Vchar* arg1, Vchar* arg2, Vchar* arg3, Vchar* arg4, Vint* arg5, Vint* arg6, Vdouble* arg7, Vdouble* arg8, Vint* arg9,
           Vdouble* arg10, Vint* arg11)
{
    cblas_dtrmm(CblasColMajor, (arg1)[0] == 'l' || (arg1)[0] == 'L' ? CblasLeft : CblasRight,
                (arg2)[0] == 'u' || (arg2)[0] == 'U' ? CblasUpper : CblasLower,
                (arg3)[0] == 'n' || (arg3)[0] == 'N' ? CblasNoTrans : CblasTrans,
                (arg4)[0] == 'u' || (arg4)[0] == 'U' ? CblasUnit : CblasNonUnit, *arg5, *arg6, *arg7, arg8, *arg9, arg10, *arg11);
}
static inline Vdouble
BLAS_dnrm2(Vint* arg1, Vdouble* arg2, Vint* arg3)
{
    return cblas_dnrm2(*arg1, arg2, *arg3);
}
static inline void
BLAS_dspmv(Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7, Vdouble* arg8,
           Vint* arg9)
{
    cblas_dspmv(CblasColMajor, (arg1)[0] == 'u' || (arg1)[0] == 'U' ? CblasUpper : CblasLower, *arg2, *arg3, arg4, arg5, *arg6,
                *arg7, arg8, *arg9);
}
static inline void
BLAS_dsyr2k(Vchar* arg1, Vchar* arg2, Vint* arg3, Vint* arg4, Vdouble* arg5, Vdouble* arg6, Vint* arg7, Vdouble* arg8, Vint* arg9,
            Vdouble* arg10, Vdouble* arg11, Vint* arg12)
{
    cblas_dsyr2k(CblasColMajor, (arg1)[0] == 'u' || (arg1)[0] == 'U' ? CblasUpper : CblasLower,
                 (arg2)[0] == 'n' || (arg2)[0] == 'N' ? CblasNoTrans : CblasTrans, *arg3, *arg4, *arg5, arg6, *arg7, arg8, *arg9,
                 *arg10, arg11, *arg12);
}
/*
 * BLAS interface uses 32-bit integers but calls to BLAS use 64-bit integers
 */
static inline void
BLAS_DROTG(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4)
{
    cblas_drotg(arg1, arg2, arg3, arg4);
}
static inline void
BLAS_DSCAL(const Vlong* arg1, const Vdouble* arg2, Vdouble* arg3, const Vlong* arg4)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg4 = (Vint) * (arg4);
    cblas_dscal(larg1, *(arg2), arg3, larg4);
}
static inline void
BLAS_DCOPY(Vlong* arg1, Vdouble* arg2, const Vlong* arg3, Vdouble* arg4, Vlong* arg5)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg3 = (Vint) * (arg3);
    Vint larg5 = (Vint) * (arg5);
    cblas_dcopy(larg1, arg2, larg3, arg4, larg5);
}
static inline void
BLAS_DGEMM(const Vchar* arg1, const Vchar* arg2, const Vlong* arg3, const Vlong* arg4, const Vlong* arg5, const Vdouble* arg6,
           const Vdouble* arg7, const Vlong* arg8, const Vdouble* arg9, const Vlong* arg10, const Vdouble* arg11, Vdouble* arg12,
           const Vlong* arg13)
{
    Vint larg3 = (Vint) * (arg3);
    Vint larg4 = (Vint) * (arg4);
    Vint larg5 = (Vint) * (arg5);
    Vint larg8 = (Vint) * (arg8);
    Vint larg10 = (Vint) * (arg10);
    Vint larg13 = (Vint) * (arg13);
    cblas_dgemm(CblasColMajor, (arg1)[0] == 'n' || (arg1)[0] == 'N' ? CblasNoTrans : CblasTrans,
                (arg2)[0] == 'n' || (arg2)[0] == 'N' ? CblasNoTrans : CblasTrans, larg3, larg4, larg5, *(arg6), arg7, larg8, arg9,
                larg10, *(arg11), arg12, larg13);
}
static inline void
BLAS_DTRSM(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, const Vlong* arg5, const Vlong* arg6,
           const Vdouble* arg7, const Vdouble* arg8, const Vlong* arg9, Vdouble* arg10, const Vlong* arg11)
{
    Vint larg5 = (Vint) * (arg5);
    Vint larg6 = (Vint) * (arg6);
    Vint larg9 = (Vint) * (arg9);
    Vint larg11 = (Vint) * (arg11);
    cblas_dtrsm(CblasColMajor, (arg1)[0] == 'l' || (arg1)[0] == 'L' ? CblasLeft : CblasRight,
                (arg2)[0] == 'u' || (arg2)[0] == 'U' ? CblasUpper : CblasLower,
                (arg3)[0] == 'n' || (arg3)[0] == 'N' ? CblasNoTrans : CblasTrans,
                (arg4)[0] == 'u' || (arg4)[0] == 'U' ? CblasUnit : CblasNonUnit, larg5, larg6, *(arg7), arg8, larg9, arg10,
                larg11);
}
static inline void
BLAS_DGEMV(const char* arg1, const Vlong* arg2, const Vlong* arg3, const double* arg4, const double* arg5, const Vlong* arg6,
           const double* arg7, const Vlong* arg8, const double* arg9, double* arg10, const Vlong* arg11)
{
    Vint larg2 = (Vint) * (arg2);
    Vint larg3 = (Vint) * (arg3);
    Vint larg6 = (Vint) * (arg6);
    Vint larg8 = (Vint) * (arg8);
    Vint larg11 = (Vint) * (arg11);
    cblas_dgemv(CblasColMajor, (arg1)[0] == 'n' || (arg1)[0] == 'N' ? CblasNoTrans : CblasTrans, larg2, larg3, *(arg4), arg5,
                larg6, arg7, larg8, *(arg9), arg10, larg11);
}
static inline void
BLAS_DAXPY(const Vlong* arg1, const Vdouble* arg2, const Vdouble* arg3, const Vlong* arg4, Vdouble* arg5, const Vlong* arg6)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg4 = (Vint) * (arg4);
    Vint larg6 = (Vint) * (arg6);
    cblas_daxpy(larg1, *(arg2), arg3, larg4, arg5, larg6);
}
static inline Vlong
BLAS_IDAMAX(Vlong* arg1, Vdouble* arg2, Vlong* arg3)
{
    const Vint larg1 = (Vint) * (arg1);
    const Vint larg3 = (Vint) * (arg3);
    return (Vlong)cblas_idamax(larg1, arg2, larg3);
}
static inline void
BLAS_DGER(const Vlong* arg1, const Vlong* arg2, Vdouble* arg3, const Vdouble* arg4, const Vlong* arg5, const Vdouble* arg6,
          const Vlong* arg7, Vdouble* arg8, const Vlong* arg9)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg2 = (Vint) * (arg2);
    Vint larg5 = (Vint) * (arg5);
    Vint larg7 = (Vint) * (arg7);
    Vint larg9 = (Vint) * (arg9);
    cblas_dger(CblasColMajor, larg1, larg2, *(arg3), arg4, larg5, arg6, larg7, arg8, larg9);
}
static inline void
BLAS_DSWAP(const Vlong* arg1, Vdouble* arg2, const Vlong* arg3, Vdouble* arg4, const Vlong* arg5)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg3 = (Vint) * (arg3);
    Vint larg5 = (Vint) * (arg5);
    cblas_dswap(larg1, arg2, larg3, arg4, larg5);
}
static inline void
BLAS_DTRMM(Vchar* arg1, Vchar* arg2, Vchar* arg3, Vchar* arg4, Vlong* arg5, Vlong* arg6, Vdouble* arg7, Vdouble* arg8,
           Vlong* arg9, Vdouble* arg10, Vlong* arg11)
{
    const Vint larg5 = (Vint) * (arg5);
    const Vint larg6 = (Vint) * (arg6);
    const Vint larg9 = (Vint) * (arg9);
    const Vint larg11 = (Vint) * (arg11);
    cblas_dtrmm(CblasColMajor, (arg1)[0] == 'l' || (arg1)[0] == 'L' ? CblasLeft : CblasRight,
                (arg2)[0] == 'u' || (arg2)[0] == 'U' ? CblasUpper : CblasLower,
                (arg3)[0] == 'n' || (arg3)[0] == 'N' ? CblasNoTrans : CblasTrans,
                (arg4)[0] == 'u' || (arg4)[0] == 'U' ? CblasUnit : CblasNonUnit, larg5, larg6, *arg7, arg8, larg9, arg10, larg11);
}
static inline Vdouble
BLAS_DNRM2(Vlong* arg1, Vdouble* arg2, Vlong* arg3)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg3 = (Vint) * (arg3);
    return cblas_dnrm2(larg1, arg2, larg3);
}
static inline Vdouble
BLAS_DDOT(Vlong* arg1, Vdouble* arg2, Vlong* arg3, Vdouble* arg4, Vlong* arg5)
{
    const Vint iarg1 = (Vint) * (arg1);
    const Vint iarg3 = (Vint) * (arg3);
    const Vint iarg5 = (Vint) * (arg5);
    return cblas_ddot(iarg1, arg2, iarg3, arg4, iarg5);
}
static inline void
BLAS_DSPMV(Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7, Vdouble* arg8,
           Vlong* arg9)
{
    const Vint larg2 = (Vint) * (arg2);
    const Vint larg6 = (Vint) * (arg6);
    const Vint larg9 = (Vint) * (arg9);
    cblas_dspmv(CblasColMajor, (arg1)[0] == 'u' || (arg1)[0] == 'U' ? CblasUpper : CblasLower, larg2, *arg3, arg4, arg5, larg6,
                *arg7, arg8, larg9);
}
static inline void
BLAS_DSYR2K(Vchar* arg1, Vchar* arg2, Vlong* arg3, Vlong* arg4, Vdouble* arg5, Vdouble* arg6, Vlong* arg7, Vdouble* arg8,
            Vlong* arg9, Vdouble* arg10, Vdouble* arg11, Vlong* arg12)
{
    const Vint larg3 = (Vint) * (arg3);
    const Vint larg4 = (Vint) * (arg4);
    const Vint larg7 = (Vint) * (arg7);
    const Vint larg9 = (Vint) * (arg9);
    const Vint larg12 = (Vint) * (arg12);
    cblas_dsyr2k(CblasColMajor, (arg1)[0] == 'u' || (arg1)[0] == 'U' ? CblasUpper : CblasLower,
                 (arg2)[0] == 'n' || (arg2)[0] == 'N' ? CblasNoTrans : CblasTrans, larg3, larg4, *arg5, arg6, larg7, arg8, larg9,
                 *arg10, arg11, larg12);
}
#endif
#else

/*
 * Other BLAS libraries would go here. Since we don't support others
 * at this point, the "#else" defaults to ours
 */

static inline void
BLAS_drotg(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4)
{
    vki_drotg(arg1, arg2, arg3, arg4);
}
static inline void
BLAS_daxpy(const Vint* arg1, const Vdouble* arg2, const Vdouble* arg3, const Vint* arg4, Vdouble* arg5, const Vint* arg6)
{
    vki_daxpy(arg1, arg2, arg3, arg4, arg5, arg6);
}
static inline void
BLAS_dcopy(const Vint* arg1, const Vdouble* arg2, const Vint* arg3, Vdouble* arg4, const Vint* arg5)
{
    vki_dcopy(arg1, arg2, arg3, arg4, arg5);
}
static inline Vdouble
BLAS_ddot(Vint* arg1, Vdouble* arg2, Vint* arg3, Vdouble* arg4, Vint* arg5)
{
    return vki_ddot(arg1, arg2, arg3, arg4, arg5);
}
static inline void
BLAS_dscal(const Vint* arg1, const Vdouble* arg2, Vdouble* arg3, const Vint* arg4)
{
    vki_dscal(arg1, arg2, arg3, arg4);
}
static inline void
BLAS_dswap(const Vint* arg1, Vdouble* arg2, const Vint* arg3, Vdouble* arg4, const Vint* arg5)
{
    vki_dswap(arg1, arg2, arg3, arg4, arg5);
}
static inline Vint
BLAS_idamax(const Vint* arg1, const Vdouble* arg2, const Vint* arg3)
{
    return vki_idamax(arg1, arg2, arg3);
}
static inline void
BLAS_dgemv(const char* arg1, const Vint* arg2, const Vint* arg3, const double* arg4, const double* arg5, const Vint* arg6,
           const double* arg7, const Vint* arg8, const double* arg9, double* arg10, const Vint* arg11)
{
    vki_dgemv(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
BLAS_dger(const Vint* arg1, const Vint* arg2, Vdouble* arg3, const Vdouble* arg4, const Vint* arg5, const Vdouble* arg6,
          const Vint* arg7, Vdouble* arg8, const Vint* arg9)
{
    vki_dger(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
static inline void
BLAS_dtrsm(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, Vint* arg5, Vint* arg6, Vdouble* arg7,
           Vdouble* arg8, Vint* arg9, Vdouble* arg10, Vint* arg11)
{
    vki_dtrsm(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline void
BLAS_dgemm(const Vchar* arg1, const Vchar* arg2, const Vint* arg3, const Vint* arg4, const Vint* arg5, const Vdouble* arg6,
           const Vdouble* arg7, const Vint* arg8, const Vdouble* arg9, const Vint* arg10, const Vdouble* arg11, Vdouble* arg12,
           const Vint* arg13)
{
    vki_dgemm(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
}
static inline void
BLAS_dtrmm(Vchar* arg1, Vchar* arg2, Vchar* arg3, Vchar* arg4, Vint* arg5, Vint* arg6, Vdouble* arg7, Vdouble* arg8, Vint* arg9,
           Vdouble* arg10, Vint* arg11)
{
    vki_dtrmm(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
static inline Vdouble
BLAS_dnrm2(Vint* arg1, Vdouble* arg2, Vint* arg3)
{
    return vki_dnrm2(arg1, arg2, arg3);
}
static inline void
BLAS_dspmv(Vchar* arg1, Vint* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vint* arg6, Vdouble* arg7, Vdouble* arg8,
           Vint* arg9)
{
    vki_dspmv(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
static inline void
BLAS_DROTG(Vdouble* arg1, Vdouble* arg2, Vdouble* arg3, Vdouble* arg4)
{
    vki_drotg(arg1, arg2, arg3, arg4);
}
static inline void
BLAS_DSCAL(const Vlong* arg1, const Vdouble* arg2, Vdouble* arg3, const Vlong* arg4)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg4 = (Vint) * (arg4);
    vki_dscal((&larg1), arg2, arg3, (&larg4));
}
static inline void
BLAS_DCOPY(Vlong* arg1, Vdouble* arg2, Vlong* arg3, Vdouble* arg4, Vlong* arg5)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg3 = (Vint) * (arg3);
    Vint larg5 = (Vint) * (arg5);
    vki_dcopy(&(larg1), arg2, &(larg3), arg4, &(larg5));
}
static inline void
BLAS_DGEMM(const Vchar* arg1, const Vchar* arg2, const Vlong* arg3, const Vlong* arg4, const Vlong* arg5, const Vdouble* arg6,
           const Vdouble* arg7, const Vlong* arg8, const Vdouble* arg9, const Vlong* arg10, const Vdouble* arg11, Vdouble* arg12,
           const Vlong* arg13)
{
    Vint larg3 = (Vint) * (arg3);
    Vint larg4 = (Vint) * (arg4);
    Vint larg5 = (Vint) * (arg5);
    Vint larg8 = (Vint) * (arg8);
    Vint larg10 = (Vint) * (arg10);
    Vint larg13 = (Vint) * (arg13);
    vki_dgemm(arg1, arg2, &(larg3), &(larg4), &(larg5), arg6, arg7, &(larg8), arg9, &(larg10), arg11, arg12, &(larg13));
}
static inline void
BLAS_DTRSM(const Vchar* side, const Vchar* uplow, const Vchar* transa, const Vchar* diag, const Vlong* m, const Vlong* n,
           const Vdouble* alpha, const Vdouble* A, const Vlong* ldA, Vdouble* B, const Vlong* ldB)
{
    Vint larg5 = (Vint) * (m);
    Vint larg6 = (Vint) * (n);
    Vint larg9 = (Vint) * (ldA);
    Vint larg11 = (Vint) * (ldB);
    vki_dtrsm(side, uplow, transa, diag, &(larg5), &(larg6), alpha, A, &(larg9), B, &(larg11));
}
static inline void
BLAS_DGEMV(const char* arg1, const Vlong* arg2, const Vlong* arg3, const double* arg4, const double* arg5, const Vlong* arg6,
           const double* arg7, const Vlong* arg8, const double* arg9, double* arg10, const Vlong* arg11)
{
    Vint larg2 = (Vint) * (arg2);
    Vint larg3 = (Vint) * (arg3);
    Vint larg6 = (Vint) * (arg6);
    Vint larg8 = (Vint) * (arg8);
    Vint larg11 = (Vint) * (arg11);
    vki_dgemv(arg1, &(larg2), &(larg3), arg4, arg5, &(larg6), arg7, &(larg8), arg9, arg10, &(larg11));
}
static inline void
BLAS_DAXPY(const Vlong* arg1, const Vdouble* arg2, const Vdouble* arg3, const Vlong* arg4, Vdouble* arg5, const Vlong* arg6)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg4 = (Vint) * (arg4);
    Vint larg6 = (Vint) * (arg6);
    vki_daxpy(&(larg1), arg2, arg3, &(larg4), arg5, &(larg6));
}
static inline Vlong
BLAS_IDAMAX(const Vlong* arg1, const Vdouble* arg2, const Vlong* arg3)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg3 = (Vint) * (arg3);
    return (Vlong)vki_idamax(&(larg1), arg2, &(larg3));
}
static inline void
BLAS_DGER(const Vlong* arg1, const Vlong* arg2, Vdouble* arg3, const Vdouble* arg4, const Vlong* arg5, const Vdouble* arg6,
          const Vlong* arg7, Vdouble* arg8, const Vlong* arg9)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg2 = (Vint) * (arg2);
    Vint larg5 = (Vint) * (arg5);
    Vint larg7 = (Vint) * (arg7);
    Vint larg9 = (Vint) * (arg9);
    vki_dger(&(larg1), &(larg2), arg3, arg4, &(larg5), arg6, &(larg7), arg8, &(larg9));
}
static inline void
BLAS_DSWAP(const Vlong* arg1, Vdouble* arg2, const Vlong* arg3, Vdouble* arg4, const Vlong* arg5)
{
    Vint larg1 = (Vint) * (arg1);
    Vint larg3 = (Vint) * (arg3);
    Vint larg5 = (Vint) * (arg5);
    vki_dswap(&(larg1), arg2, &(larg3), arg4, &(larg5));
}
static inline void
BLAS_DTRMM(Vchar* arg1, Vchar* arg2, Vchar* arg3, Vchar* arg4, Vlong* arg5, Vlong* arg6, Vdouble* arg7, Vdouble* arg8,
           Vlong* arg9, Vdouble* arg10, Vlong* arg11)
{
    Vint larg5 = (Vint) * (arg5);
    Vint larg6 = (Vint) * (arg6);
    Vint larg9 = (Vint) * (arg9);
    Vint larg11 = (Vint) * (arg11);
    vki_dtrmm(arg1, arg2, arg3, arg4, &(larg5), &(larg6), arg7, arg8, &(larg9), arg10, &(larg11));
}
static inline Vdouble
BLAS_DNRM2(Vlong* arg1, Vdouble* arg2, Vlong* arg3)
{
    Vint iarg1 = (Vint) * (arg1);
    Vint iarg3 = (Vint) * (arg3);
    return vki_dnrm2(&iarg1, arg2, &iarg3);
}
static inline Vdouble
BLAS_DDOT(Vlong* arg1, Vdouble* arg2, Vlong* arg3, Vdouble* arg4, Vlong* arg5)
{
    Vint iarg1 = (Vint) * (arg1);
    Vint iarg3 = (Vint) * (arg3);
    Vint iarg5 = (Vint) * (arg5);
    return vki_ddot(&iarg1, arg2, &iarg3, arg4, &iarg5);
}
static inline void
BLAS_DSPMV(Vchar* arg1, Vlong* arg2, Vdouble* arg3, Vdouble* arg4, Vdouble* arg5, Vlong* arg6, Vdouble* arg7, Vdouble* arg8,
           Vlong* arg9)
{
    Vint larg2 = (Vint) * (arg2);
    Vint larg6 = (Vint) * (arg6);
    Vint larg9 = (Vint) * (arg9);
    vki_dspmv(arg1, &(larg2), arg3, arg4, arg5, &(larg6), arg7, arg8, &(larg9));
}
#endif

#ifdef __cplusplus
}
#endif

#endif
