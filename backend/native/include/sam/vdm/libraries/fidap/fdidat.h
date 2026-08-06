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
 
#ifndef FDIDAT_DEF
#define FDIDAT_DEF
#include "sam/base/basedefs.h"
typedef struct vdm_FDIDat { Vlong nc;Vint type;Vint
dtype;}vdm_FDIDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_FDIDat* vdm_FDIDatBegin(void);VKI_EXTERN
void vdm_FDIDatEnd(vdm_FDIDat* fdidat);VKI_EXTERN void
vdm_FDIDatDef(vdm_FDIDat* fdidat,Vlong nc,Vint type,
Vint dtype);VKI_EXTERN void vdm_FDIDatInq(vdm_FDIDat*
fdidat,Vlong* nc,Vint* type,Vint* dtype);
#ifdef __cplusplus
}
#endif
#endif

