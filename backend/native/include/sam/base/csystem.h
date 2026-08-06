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
 
#ifndef CSYSTEM_DEF
#define CSYSTEM_DEF
#include "sam/base/basedefs.h"
typedef struct vsy_CSystem { Vint ierr;Vint type;Vdouble
x[3];Vdouble tm[3][3];Vdouble radius;}vsy_CSystem;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_CSystem* vsy_CSystemBegin(void);VKI_EXTERN
void vsy_CSystemEnd(vsy_CSystem* p);VKI_EXTERN Vint
vsy_CSystemError(vsy_CSystem* p);VKI_EXTERN void vsy_CSystemDef(vsy_CSystem*
p,Vint type);VKI_EXTERN void vsy_CSystemDefOnePointdv(vsy_CSystem*
p,Vint type,Vdouble x1[3]);VKI_EXTERN void vsy_CSystemDefTwoPointsdv(vsy_CSystem*
p,Vint type,Vdouble x1[3],Vdouble x2[3]);VKI_EXTERN
void vsy_CSystemDefPoints(vsy_CSystem* p,Vint iop,Vint
type,Vfloat x1[3],Vfloat x2[3],Vfloat x3[3]);VKI_EXTERN
void vsy_CSystemDefPointsdv(vsy_CSystem* p,Vint iop,
Vint type,Vdouble x1[3],Vdouble x2[3],Vdouble x3[3]);
VKI_EXTERN void vsy_CSystemDefOriginTriad(vsy_CSystem*
p,Vint type,Vfloat x[3],Vfloat tm[3][3]);VKI_EXTERN
void vsy_CSystemDefOriginTriaddv(vsy_CSystem* p,Vint
type,Vdouble x[3],Vdouble tm[3][3]);VKI_EXTERN void
vsy_CSystemInqOriginTriad(vsy_CSystem* p,Vint* type,
Vfloat xo[3],Vfloat tm[3][3]);VKI_EXTERN void vsy_CSystemInqOriginTriaddv(vsy_CSystem*
p,Vint* type,Vdouble xo[3],Vdouble tm[3][3]);VKI_EXTERN
void vsy_CSystemSetRadius(vsy_CSystem* p,Vdouble radius);
VKI_EXTERN void vsy_CSystemTranslate(vsy_CSystem* p,
Vdouble tx,Vdouble ty,Vdouble tz);VKI_EXTERN void vsy_CSystemRotate(vsy_CSystem*
p,Vdouble angle,Vint axis);VKI_EXTERN void vsy_CSystemGetPosTriad(vsy_CSystem*
p,Vfloat xg[3],Vfloat tm[3][3]);VKI_EXTERN void vsy_CSystemGetPosTriaddv(vsy_CSystem*
p,Vdouble xg[3],Vdouble tm[3][3]);VKI_EXTERN void vsy_CSystemGetMetric(vsy_CSystem*
p,Vfloat xl[3],Vfloat dxl[3]);VKI_EXTERN void vsy_CSystemConvert2Global(vsy_CSystem*
p,Vint ideg,Vfloat xl[3],Vfloat xg[3]);VKI_EXTERN void
vsy_CSystemConvert2Globaldv(vsy_CSystem* p,Vint ideg,
Vdouble xl[3],Vdouble xg[3]);VKI_EXTERN void vsy_CSystemConvert2Local(vsy_CSystem*
p,Vint ideg,Vfloat xg[3],Vfloat xl[3]);VKI_EXTERN void
vsy_CSystemConvert2Localdv(vsy_CSystem* p,Vint ideg,
Vdouble xg[3],Vdouble xl[3]);VKI_EXTERN void vsy_CSystemPrint(vsy_CSystem*
p);
#ifdef __cplusplus
}
#endif
#endif

