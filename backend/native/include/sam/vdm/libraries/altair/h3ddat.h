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
 
#ifndef H3DDAT_DEF
#define H3DDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct vdm_H3DDat { Vint num;Vint* isim;Vint*
idt;Vint* icmp;Vint* offset;Vint* nodeid;Vint* isneg;
Vint* isec;Vint** mapr;Vint iter;Vint ncmp;Vint dsloc;
Vint hassect;Vint cplx;Vint parent;}vdm_H3DDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_H3DDat* vdm_H3DDatBegin(void);VKI_EXTERN
void vdm_H3DDatEnd(vdm_H3DDat* p);VKI_EXTERN void vdm_H3DDatAdd(vdm_H3DDat*
p,Vint isim,Vint idt,Vint icmp,Vint offset,Vint nodeid,
Vint isneg,Vint isec,Vint* mapr);VKI_EXTERN void vdm_H3DDatDef(vdm_H3DDat*
p,Vint ncmp,Vint dsloc,Vint cplx);VKI_EXTERN void vdm_H3DDatInq(vdm_H3DDat*
p,Vint* ncmp,Vint* dsloc,Vint* cplx);VKI_EXTERN void
vdm_H3DDatInitIter(vdm_H3DDat* p);VKI_EXTERN void vdm_H3DDatNextIter(vdm_H3DDat*
p,Vint* isim,Vint* idt,Vint* icmp,Vint* offset,Vint*
nodeid,Vint* isneg,Vint* isec,Vint** mapr);VKI_EXTERN
void vdm_H3DDatSetSect(vdm_H3DDat* p,Vint hassect);
VKI_EXTERN void vdm_H3DDatGetSect(vdm_H3DDat* p,Vint*
hassect);VKI_EXTERN void vdm_H3DDatSetLinkParent(vdm_H3DDat*
p,Vint parent);VKI_EXTERN void vdm_H3DDatGetLinkParent(vdm_H3DDat*
p,Vint* parent);
#ifdef __cplusplus
}
#endif
#endif

