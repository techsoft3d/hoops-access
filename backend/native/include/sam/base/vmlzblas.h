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
#ifndef VMLZBLAS_DEF
#define VMLZBLAS_DEF
#include "sam/base/basedefs.h"

#if defined(VKI_LIBAPI_BLASMKL_SEQUENTIAL) || defined(VKI_LIBAPI_BLASMKL_THREAD)
#ifdef VKI_LIBAPI_BLASMKL_ILP64
#ifndef MKL_ILP64
#define MKL_ILP64
#endif
#endif
#include "mkl.h"
#endif

#if defined(VKI_LIBAPI_BLASMKL_SEQUENTIAL) || defined(VKI_LIBAPI_BLASMKL_THREAD)
/*
 * These are the MKL function definitions
 */
#ifdef VKI_LIBAPI_BLASMKL_ILP64
/*
 * BLAS interface uses 64-bit integers but calls to BLAS use 32-bit integers
 */
static inline std::complex<Vdouble>
BLAS_zdot(Vint* arg1, std::complex<Vdouble>* arg2, Vint* arg3, std::complex<Vdouble>* arg4, Vint* arg5)
{
    MKL_Complex16 ret;
    Vlong larg1 = (Vlong) * (arg1);
    Vlong larg3 = (Vlong) * (arg3);
    Vlong larg5 = (Vlong) * (arg5);
    zdotc(&ret, &larg1, reinterpret_cast<MKL_Complex16*>(arg2), &larg3, reinterpret_cast<MKL_Complex16*>(arg4), &larg5);
    return {ret.real, ret.imag};
}
/*
 * BLAS interface uses 64-bit integers and calls to BLAS use 64-bit integers
 */
static inline std::complex<Vdouble>
BLAS_ZDOT(Vlong* arg1, std::complex<Vdouble>* arg2, Vlong* arg3, std::complex<Vdouble>* arg4, Vlong* arg5)
{
    MKL_Complex16 ret;
    zdotc(&ret, arg1, reinterpret_cast<MKL_Complex16*>(arg2), arg3, reinterpret_cast<MKL_Complex16*>(arg4), arg5);
    return {ret.real, ret.imag};
}
#else

/*
 * BLAS interface uses 32-bit integers and calls to BLAS use 32-bit integers
 */
static inline std::complex<Vdouble>
BLAS_zdot(Vint* arg1, std::complex<Vdouble>* arg2, Vint* arg3, std::complex<Vdouble>* arg4, Vint* arg5)
{
    MKL_Complex16 ret;
    zdotc(&ret, arg1, reinterpret_cast<MKL_Complex16*>(arg2), arg3, reinterpret_cast<MKL_Complex16*>(arg4), arg5);
    return {ret.real, ret.imag};
}
/*
 * BLAS interface uses 32-bit integers but calls to BLAS use 64-bit integers
 */
static inline std::complex<Vdouble>
BLAS_ZDOT(Vlong* arg1, std::complex<Vdouble>* arg2, Vlong* arg3, std::complex<Vdouble>* arg4, Vlong* arg5)
{
    MKL_Complex16 ret;
    Vint iarg1 = (Vint) * (arg1);
    Vint iarg3 = (Vint) * (arg3);
    Vint iarg5 = (Vint) * (arg5);
    zdotc(&ret, &iarg1, reinterpret_cast<MKL_Complex16*>(arg2), &iarg3, reinterpret_cast<MKL_Complex16*>(arg4), &iarg5);
    return {ret.real, ret.imag};
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
static inline std::complex<Vdouble>
BLAS_zdot(Vint* arg1, std::complex<Vdouble>* arg2, Vint* arg3, std::complex<Vdouble>* arg4, Vint* arg5)
{
    const Vlong larg1 = (Vlong) * (arg1);
    const Vlong larg3 = (Vlong) * (arg3);
    const Vlong larg5 = (Vlong) * (arg5);
    return cblas_zdotc(larg1, arg2, larg3, arg4, larg5);
}
/*
 * BLAS interface uses 64-bit integers and calls to BLAS use 64-bit integers
 */
static inline std::complex<Vdouble>
BLAS_ZDOT(Vlong* arg1, std::complex<Vdouble>* arg2, Vlong* arg3, std::complex<Vdouble>* arg4, Vlong* arg5)
{
    return cblas_zdotc(*arg1, arg2, *arg3, arg4, *arg5);
}
#else

/*
 * BLAS interface uses 32-bit integers and calls to BLAS use 32-bit integers
 */
static inline std::complex<Vdouble>
BLAS_zdot(Vint* arg1, std::complex<Vdouble>* arg2, Vint* arg3, std::complex<Vdouble>* arg4, Vint* arg5)
{
    openblas_complex_double a;
    std::complex<Vdouble> r;
    a = cblas_zdotc(*arg1, arg2, *arg3, arg4, *arg5);
    r = {a.real, a.imag};
    return r;
}

static inline void
BLAS_zgemm(const Vchar* arg1, const Vchar* arg2, const Vint* arg3, const Vint* arg4, const Vint* arg5,
           const std::complex<Vdouble>* arg6, const std::complex<Vdouble>* arg7, const Vint* arg8,
           const std::complex<Vdouble>* arg9, const Vint* arg10, const std::complex<Vdouble>* arg11, std::complex<Vdouble>* arg12,
           const Vint* arg13)
{
    cblas_zgemm(CblasColMajor, (arg1)[0] == 'n' || (arg1)[0] == 'N' ? CblasNoTrans : CblasTrans,
                (arg2)[0] == 'n' || (arg2)[0] == 'N' ? CblasNoTrans : CblasTrans, *(arg3), *(arg4), *(arg5), arg6, arg7, *(arg8),
                arg9, *(arg10), arg11, arg12, *(arg13));
}

static inline void
BLAS_zgemv(const char* arg1, const Vint* arg2, const Vint* arg3, const std::complex<Vdouble>* arg4,
           const std::complex<Vdouble>* arg5, const Vint* arg6, const std::complex<Vdouble>* arg7, const Vint* arg8,
           const std::complex<Vdouble>* arg9, std::complex<Vdouble>* arg10, const Vint* arg11)
{
    cblas_zgemv(CblasColMajor, (arg1)[0] == 'n' || (arg1)[0] == 'N' ? CblasNoTrans : CblasTrans, *(arg2), *(arg3), arg4, arg5,
                *(arg6), arg7, *(arg8), arg9, arg10, *(arg11));
}

static inline void
BLAS_zscal(const Vint* arg1, const std::complex<Vdouble>* arg2, std::complex<Vdouble>* arg3, const Vint* arg4)
{
    cblas_zscal(*(arg1), arg2, arg3, *(arg4));
}

static inline void
BLAS_ztrsm(const Vchar* arg1, const Vchar* arg2, const Vchar* arg3, const Vchar* arg4, const Vint* arg5, const Vint* arg6,
           const std::complex<Vdouble>* arg7, const std::complex<Vdouble>* arg8, const Vint* arg9, std::complex<Vdouble>* arg10,
           const Vint* arg11)
{
    cblas_ztrsm(CblasColMajor, (arg1)[0] == 'l' || (arg1)[0] == 'L' ? CblasLeft : CblasRight,
                (arg2)[0] == 'u' || (arg2)[0] == 'U' ? CblasUpper : CblasLower,
                (arg3)[0] == 'n' || (arg3)[0] == 'N' ? CblasNoTrans : CblasTrans,
                (arg4)[0] == 'u' || (arg4)[0] == 'U' ? CblasUnit : CblasNonUnit, *(arg5), *(arg6), arg7, arg8, *(arg9), arg10,
                *(arg11));
}

static inline void
BLAS_zgerc(const Vint* arg1, const Vint* arg2, std::complex<Vdouble>* arg3, std::complex<Vdouble>* arg4, const Vint* arg5,
           std::complex<Vdouble>* arg6, const Vint* arg7, std::complex<Vdouble>* arg8, const Vint* arg9)
{
    cblas_zgerc(CblasColMajor, *arg1, *arg2, arg3, arg4, *arg5, arg6, *arg7, arg8, *arg9);
}

static inline void
BLAS_zgeru(const Vint* arg1, const Vint* arg2, std::complex<Vdouble>* arg3, std::complex<Vdouble>* arg4, const Vint* arg5,
           std::complex<Vdouble>* arg6, const Vint* arg7, std::complex<Vdouble>* arg8, const Vint* arg9)
{
    cblas_zgeru(CblasColMajor, *arg1, *arg2, arg3, arg4, *arg5, arg6, *arg7, arg8, *arg9);
}
/*
 * BLAS interface uses 32-bit integers but calls to BLAS use 64-bit integers
 */
static inline std::complex<Vdouble>
BLAS_ZDOT(Vlong* arg1, std::complex<Vdouble>* arg2, Vlong* arg3, std::complex<Vdouble>* arg4, Vlong* arg5)
{
    const Vint iarg1 = (Vint) * (arg1);
    const Vint iarg3 = (Vint) * (arg3);
    const Vint iarg5 = (Vint) * (arg5);
    openblas_complex_double a;
    std::complex<Vdouble> r;
    a = cblas_zdotc(iarg1, arg2, iarg3, arg4, iarg5);
    r = {a.real, a.imag};
    return r;
}
#endif

#else
static inline std::complex<Vdouble>
BLAS_ZDOT(Vlong* arg1, std::complex<Vdouble>* arg2, Vlong* arg3, std::complex<Vdouble>* arg4, Vlong* arg5)
{
    Vlong i, n1, n2;
    std::complex<Vdouble> ret = 0.;

    for (n1 = 0, n2 = 0, i = 0; i < *arg1; ++i, n1 += *arg3, n2 += *arg5) {
        ret += conj(arg2[n1]) * arg4[n2];
    }
    return ret;
}

static inline std::complex<Vdouble>
BLAS_zdot(Vint* arg1, std::complex<Vdouble>* arg2, Vint* arg3, std::complex<Vdouble>* arg4, Vint* arg5)
{
    Vint i, n1, n2;
    std::complex<Vdouble> ret = 0.;

    for (n1 = 0, n2 = 0, i = 0; i < *arg1; ++i, n1 += *arg3, n2 += *arg5) {
        ret += conj(arg2[n1]) * arg4[n2];
    }
    return ret;
}
#endif
#endif
