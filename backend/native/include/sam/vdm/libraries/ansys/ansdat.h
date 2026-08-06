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
 
#ifndef ANSDAT_DEF
#define ANSDAT_DEF
#include "sam/base/basedefs.h"
typedef struct vdm_ANSDat { Vuint nc[2];Vuint nb[2];
Vint sect;Vint size;Vint iset;Vint indx;Vint icmp;Vint
ncmp;Vint type;Vint qual;Vint prin;Vint cplx;}vdm_ANSDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_ANSDat* vdm_ANSDatBegin(void);VKI_EXTERN
void vdm_ANSDatEnd(vdm_ANSDat* ansdat);VKI_EXTERN void
vdm_ANSDatDef(vdm_ANSDat* ansdat,Vuint nc[2],Vint iset,
Vint indx,Vint icmp,Vint ncmp,Vint type);VKI_EXTERN
void vdm_ANSDatInq(vdm_ANSDat* ansdat,Vuint nc[2],Vint*
iset,Vint* indx,Vint* icmp,Vint* ncmp,Vint* type);VKI_EXTERN
void vdm_ANSDatSetSize(vdm_ANSDat* ansdat,Vint size);
VKI_EXTERN void vdm_ANSDatGetSize(vdm_ANSDat* ansdat,
Vint* size);VKI_EXTERN void vdm_ANSDatSetQual(vdm_ANSDat*
ansdat,Vint qual);VKI_EXTERN void vdm_ANSDatGetQual(vdm_ANSDat*
ansdat,Vint* qual);VKI_EXTERN void vdm_ANSDatSetSection(vdm_ANSDat*
ansdat,Vint sect);VKI_EXTERN void vdm_ANSDatGetSection(vdm_ANSDat*
ansdat,Vint* sect);VKI_EXTERN void vdm_ANSDatSetBase(vdm_ANSDat*
ansdat,Vuint nb[2]);VKI_EXTERN void vdm_ANSDatGetBase(vdm_ANSDat*
ansdat,Vuint nb[2]);VKI_EXTERN void vdm_ANSDatSetPrinKey(vdm_ANSDat*
ansdat,Vint prin);VKI_EXTERN void vdm_ANSDatGetPrinKey(vdm_ANSDat*
ansdat,Vint* prin);VKI_EXTERN void vdm_ANSDatSetCplx(vdm_ANSDat*
ansdat,Vint cplx);VKI_EXTERN void vdm_ANSDatGetCplx(vdm_ANSDat*
ansdat,Vint* cplx);
#ifdef __cplusplus
}
#endif
#endif

