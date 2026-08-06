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
 
#ifndef FLUENTDAT_DEF
#define FLUENTDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct vdm_FLUENTDat { Vlong nc[6];Vint npos;
Vint ncmp;Vint type;Vint nsect;}vdm_FLUENTDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_FLUENTDat* vdm_FLUENTDatBegin(void);
VKI_EXTERN void vdm_FLUENTDatEnd(vdm_FLUENTDat* p);
VKI_EXTERN void vdm_FLUENTDatDef(vdm_FLUENTDat* p,Vint
ncmp,Vint type,Vint nsect);VKI_EXTERN void vdm_FLUENTDatInq(vdm_FLUENTDat*
p,Vlong nc[6],Vint* npos,Vint* ncmp,Vint* type,Vint*
nsect);VKI_EXTERN void vdm_FLUENTDatSetPos(vdm_FLUENTDat*
p,Vlong nc,Vint ipos);VKI_EXTERN void vdm_FLUENTDatIncSection(vdm_FLUENTDat*
p);
#ifdef __cplusplus
}
#endif
#endif

