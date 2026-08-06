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
/* Quadruple precision utility */
#ifndef QUAD_DEF
#define QUAD_DEF

#include <stdio.h>
#include "sam/base/basedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

VKI_EXTERN void
vut_VQuadPrintBin(Vquad a);
VKI_EXTERN void
vut_VQuadPrintComp(Vquad a);
VKI_EXTERN void
vut_VQuadPrintf(Vquad f, Vint width, Vint sign, Vint* ierr);
VKI_EXTERN void
vut_VQuadSPrintf(Vquad f, Vint width, Vint sign, Vchar buf[], Vint* ierr);
VKI_EXTERN Vquad
vut_VQuadLoad(Vdouble a);
VKI_EXTERN Vdouble
vut_VQuadStore(Vquad a, Vint* ierr);
VKI_EXTERN Vint
vut_VQuadEQ(Vquad a, Vquad b);
VKI_EXTERN Vint
vut_VQuadGT(Vquad a, Vquad b);
VKI_EXTERN Vint
vut_VQuadGE(Vquad a, Vquad b);
VKI_EXTERN Vint
vut_VQuadLT(Vquad a, Vquad b);
VKI_EXTERN Vint
vut_VQuadLE(Vquad a, Vquad b);
VKI_EXTERN Vquad
vut_VQuadAdd(Vquad a, Vquad b, Vint* ierr);
VKI_EXTERN Vquad
vut_VQuadSub(Vquad a, Vquad b, Vint* ierr);
VKI_EXTERN Vquad
vut_VQuadMult(Vquad a, Vquad b, Vint* ierr);
VKI_EXTERN Vquad
vut_VQuadDiv(Vquad a, Vquad b, Vint* ierr);
VKI_EXTERN Vquad
vut_VQuadSqrt(Vquad a, Vint* ierr);
VKI_EXTERN Vquad
vut_VQuadDot3(Vquad a[3], Vquad b[3], Vint* ierr);
VKI_EXTERN void
vut_VQuadCross3(Vquad a[3], Vquad b[3], Vquad c[3], Vint* ierr);
VKI_EXTERN void
vut_VQuadScale3(Vquad a[3], Vquad s, Vquad b[3], Vint* ierr);
VKI_EXTERN Vquad
vut_VQuadMag3(Vquad a[3], Vint* ierr);
VKI_EXTERN void
vut_VQuadUnit3(Vquad a[3], Vint* ierr);
VKI_EXTERN Vquad
vut_VQuadAbs(Vquad a);
VKI_EXTERN Vquad
vut_VQuadHalf(Vquad a);
VKI_EXTERN Vquad
vut_VQuadNeg(Vquad a);

#ifdef __cplusplus
}
#endif

#endif
