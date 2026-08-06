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
 
#ifndef ABADAT_DEF
#define ABADAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vis/group.h"
typedef struct vdm_ABADat { Vint ncps;Vlong nbps;Vint
nrec;Vint type;Vint sect;Vint rkey;Vint icmp;Vint ncmp;
Vint isca;Vint cplx;Vint intp;Vint nstg;Vint maxstg;
Vchar** rstg;Vint* jcmp;Vint* kcmp;Vint* combine;Vint
locs[2];Vlong lrec;vis_Group* group;}vdm_ABADat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_ABADat* vdm_ABADatBegin(void);VKI_EXTERN
void vdm_ABADatEnd(vdm_ABADat* abadat);VKI_EXTERN void
vdm_ABADatDef(vdm_ABADat* abadat,Vint ncps,Vlong nbps,
Vint nrec,Vint type,Vint sect,Vint rkey,Vint icmp,Vint
ncmp,Vint isca);VKI_EXTERN void vdm_ABADatInq(vdm_ABADat*
abadat,Vint* ncps,Vlong* nbps,Vint* nrec,Vint* type,
Vint* sect,Vint* rkey,Vint* icmp,Vint* ncmp,Vint* isca);
VKI_EXTERN void vdm_ABADatSetCplx(vdm_ABADat* abadat,
Vint cplx);VKI_EXTERN void vdm_ABADatGetCplx(vdm_ABADat*
abadat,Vint* cplx);VKI_EXTERN void vdm_ABADatSetIntp(vdm_ABADat*
abadat,Vint intp);VKI_EXTERN void vdm_ABADatGetIntp(vdm_ABADat*
abadat,Vint* intp);VKI_EXTERN void vdm_ABADatNumRstg(vdm_ABADat*
abadat,Vint* num);VKI_EXTERN void vdm_ABADatSetRstg(vdm_ABADat*
abadat,Vchar* rstg,Vint jcmp,Vint kcmp,Vint combine);
VKI_EXTERN void vdm_ABADatGetRstg(vdm_ABADat* abadat,
Vint istg,Vchar* rstg,Vint* jcmp,Vint* kcmp,Vint* combine);
VKI_EXTERN void vdm_ABADatSetLocs(vdm_ABADat* abadat,
Vint locs[2]);VKI_EXTERN void vdm_ABADatGetLocs(vdm_ABADat*
abadat,Vint locs[2]);VKI_EXTERN void vdm_ABADatCopy(vdm_ABADat*
p,Vint fnum,vdm_ABADat* q);VKI_EXTERN void vdm_ABADatSetGroup(vdm_ABADat*
p,vis_Group* group);VKI_EXTERN void vdm_ABADatGetGroup(vdm_ABADat*
p,vis_Group** group);VKI_EXTERN void vdm_ABADatSetLRec(vdm_ABADat*
p,Vlong lrec);VKI_EXTERN void vdm_ABADatGetLRec(vdm_ABADat*
p,Vlong* lrec);VKI_EXTERN void vdm_ABADatSetType(vdm_ABADat*
p,Vint type);VKI_EXTERN void vdm_ABADatSetNCmp(vdm_ABADat*
p,Vint ncmp);
#ifdef __cplusplus
}
#endif
#endif

