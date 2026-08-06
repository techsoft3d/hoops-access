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
 
#ifndef POLYFLOWDAT_DEF
#define POLYFLOWDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct vdm_POLYFLOWDat { Vchar fname[SYS_MAXPATHCHAR];
Vchar contents[80];Vchar caux[80];fpos_t pos;Vint domain;
Vint interp;Vint ncomp;Vint ncmp;Vint nc;Vint ifree;
}vdm_POLYFLOWDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_POLYFLOWDat* vdm_POLYFLOWDatBegin(void);
VKI_EXTERN void vdm_POLYFLOWDatEnd(vdm_POLYFLOWDat*
p);VKI_EXTERN void vdm_POLYFLOWDatDef(vdm_POLYFLOWDat*
p,Vchar fname[],Vchar contents[],Vchar caux[],fpos_t
pos,Vint domain,Vint interp,Vint ncmp,Vint ncomp,Vint
nc,Vint ifree);VKI_EXTERN void vdm_POLYFLOWDatInq(vdm_POLYFLOWDat*
p,Vchar fname[],Vchar contents[],Vchar caux[],fpos_t*
pos,Vint* domain,Vint* interp,Vint* ncmp,Vint* ncomp,
Vint* nc,Vint* ifree);
#ifdef __cplusplus
}
#endif
#endif

