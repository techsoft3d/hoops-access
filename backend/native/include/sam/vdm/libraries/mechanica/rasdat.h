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
 
#ifndef RASDAT_DEF
#define RASDAT_DEF
#include "sam/base/basedefs.h"
typedef struct vdm_RASDat { Vchar path[SYS_MAXPATHCHAR];
Vchar pathr[SYS_MAXPATHCHAR];Vint form;Vint flagr;Vint
type;Vint sect;}vdm_RASDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_RASDat* vdm_RASDatBegin(void);VKI_EXTERN
void vdm_RASDatEnd(vdm_RASDat* rasdat);VKI_EXTERN void
vdm_RASDatDef(vdm_RASDat* rasdat,const Vchar* path,
const Vchar* pathr,Vint form,Vint flagr,Vint type,Vint
sect);VKI_EXTERN void vdm_RASDatInq(vdm_RASDat* rasdat,
Vchar path[],Vchar pathr[],Vint* form,Vint* flagr,Vint*
type,Vint* sect);
#ifdef __cplusplus
}
#endif
#endif

