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
 
#ifndef AUTODYNDAT_DEF
#define AUTODYNDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct vdm_AUTODYNDat { Vint istep;vsy_IntVec*
comp;Vint ncomp;Vint type;Vint nsect;}vdm_AUTODYNDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_AUTODYNDat* vdm_AUTODYNDatBegin(void);
VKI_EXTERN void vdm_AUTODYNDatEnd(vdm_AUTODYNDat* p);
VKI_EXTERN void vdm_AUTODYNDatDef(vdm_AUTODYNDat* p,
Vint istep,Vint type);VKI_EXTERN void vdm_AUTODYNDatInq(vdm_AUTODYNDat*
p,Vint* istep,Vint* type);VKI_EXTERN void vdm_AUTODYNDatAddComp(vdm_AUTODYNDat*
p,Vint node,Vint isect,Vint icomp,Vint ietype,Vint ivar);
VKI_EXTERN void vdm_AUTODYNDatNumSect(vdm_AUTODYNDat*
p,Vint* nsect);VKI_EXTERN void vdm_AUTODYNDatNumComp(vdm_AUTODYNDat*
p,Vint* num);VKI_EXTERN void vdm_AUTODYNDatGetComp(vdm_AUTODYNDat*
p,Vint n,Vint* node,Vint* isect,Vint* icomp,Vint* ietype,
Vint* ivar);
#ifdef __cplusplus
}
#endif
#endif

