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
 
#ifndef FEMAPDAT_DEF
#define FEMAPDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct { Vlong nc;Vint line;Vchar title[81];
Vint setid;Vint id;Vint comp[20];Vint out_type;Vint
ent_type;Vint comp_dir;Vint cent_total;Vint visited;
Vint cplx;Vint cpll;Vint sect;Vint len;}vdm_FEMAPLib_Res;
typedef struct vdm_FEMAPDat { vsy_List* list;vsy_IntVec*
intvec;Vint beam;Vint shell;}vdm_FEMAPDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_FEMAPDat* vdm_FEMAPDatBegin(void);VKI_EXTERN
void vdm_FEMAPDatEnd(vdm_FEMAPDat* p);VKI_EXTERN void
vdm_FEMAPDatSetRes(vdm_FEMAPDat* p,Vint n,vdm_FEMAPLib_Res*
dep);VKI_EXTERN void vdm_FEMAPDatInitIter(vdm_FEMAPDat*
p);VKI_EXTERN void vdm_FEMAPDatNextIter(vdm_FEMAPDat*
p,Vint* n,vdm_FEMAPLib_Res** dep);VKI_EXTERN void vdm_FEMAPDatSetBeamSect(vdm_FEMAPDat*
p,Vint sect);VKI_EXTERN void vdm_FEMAPDatSetShell(vdm_FEMAPDat*
p,Vint sect);VKI_EXTERN void vdm_FEMAPDatGetBeamSect(vdm_FEMAPDat*
p,Vint* beam);VKI_EXTERN void vdm_FEMAPDatGetShell(vdm_FEMAPDat*
p,Vint* shell);
#ifdef __cplusplus
}
#endif
#endif

