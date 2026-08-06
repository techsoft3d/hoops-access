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
 
#ifndef PERMUTE_DEF
#define PERMUTE_DEF
#include "sam/base/basedefs.h"
typedef struct vdm_Permute { Vint ierr;Vint type;Vint*
ixt[8][7];}vdm_Permute;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_Permute* vdm_PermuteBegin(void);VKI_EXTERN
void vdm_PermuteEnd(vdm_Permute* p);VKI_EXTERN Vint
vdm_PermuteError(vdm_Permute* p);VKI_EXTERN void vdm_PermuteType(vdm_Permute*
p,Vint type);VKI_EXTERN void vdm_PermuteVect(vdm_Permute*
p,Vint numnod,Vint ishape,Vint iredir,Vint ixt[]);VKI_EXTERN
void vdm_PermuteElem(vdm_Permute* p,Vint numnod,Vint
ishape,Vint iredir,Vint ixin[],Vint ix[]);VKI_EXTERN
void vdm_PermuteElemr(vdm_Permute* p,Vint npe,Vint shape,
Vint iredir,Vint ix[]);VKI_EXTERN void vdm_PermuteElemData(vdm_Permute*
p,Vint numnod,Vint ishape,Vint iredir,Vint nrows,Vfloat
din[],Vfloat d[]);VKI_EXTERN void vdm_PermuteElemDatadv(vdm_Permute*
p,Vint numnod,Vint ishape,Vint iredir,Vint nrows,Vdouble
din[],Vdouble d[]);VKI_EXTERN void vdm_PermuteElemDataMisMid(vdm_Permute*
p,Vint ishape,Vint maxj,Vint iredir,Vint nrows,Vfloat
din[],Vfloat d[]);VKI_EXTERN void vdm_PermuteElemReverse(vdm_Permute*
p,Vint numnod,Vint ishape,Vint iredir,Vint ix[],Vint
ixout[]);VKI_EXTERN void vdm_PermuteElemDataReversedv(vdm_Permute*
p,Vint numnod,Vint ishape,Vint iredir,Vint nrows,Vdouble
d[],Vdouble dout[]);
#ifdef __cplusplus
}
#endif
#endif

