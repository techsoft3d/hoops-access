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
 
#ifndef COMSOLDAT_DEF
#define COMSOLDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct { Vlong nc;Vchar var[80];Vfloat time;
}vdm_COMSOLDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_COMSOLDat* vdm_COMSOLDatBegin(void);
VKI_EXTERN void vdm_COMSOLDatEnd(vdm_COMSOLDat* p);
VKI_EXTERN void vdm_COMSOLDatDef(vdm_COMSOLDat* p,Vlong
nc);VKI_EXTERN void vdm_COMSOLDatInq(vdm_COMSOLDat*
p,Vlong* nc);VKI_EXTERN void vdm_COMSOLDatSetVar(vdm_COMSOLDat*
p,Vchar var[]);VKI_EXTERN void vdm_COMSOLDatGetVar(vdm_COMSOLDat*
p,Vchar var[]);VKI_EXTERN void vdm_COMSOLDatSetTime(vdm_COMSOLDat*
p,Vfloat time);VKI_EXTERN void vdm_COMSOLDatGetTime(vdm_COMSOLDat*
p,Vfloat* time);
#ifdef __cplusplus
}
#endif
#endif

