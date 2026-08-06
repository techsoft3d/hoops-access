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
 
#ifndef MARCDAT_DEF
#define MARCDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct vdm_MarcDat { Vlong* nbps;Vint type;
Vint nrow;Vint sect;Vint* irot;Vlong* nbpr;Vobject*
obj;Vint nprocd;}vdm_MarcDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_MarcDat* vdm_MarcDatBegin(void);VKI_EXTERN
void vdm_MarcDatEnd(vdm_MarcDat* p);VKI_EXTERN void
vdm_MarcDatDef(vdm_MarcDat* p,Vint nprocd,Vint type,
Vint nrow,Vint sect);VKI_EXTERN void vdm_MarcDatInq(vdm_MarcDat*
p,Vint* nprocd,Vint* type,Vint* nrow,Vint* sect);VKI_EXTERN
void vdm_MarcDatAddRot(vdm_MarcDat* p,Vint idom,Vint
irot,Vlong nbpr);VKI_EXTERN void vdm_MarcDatGetRot(vdm_MarcDat*
p,Vint idom,Vint* irot,Vlong* nbpr);VKI_EXTERN void
vdm_MarcDatAddDom(vdm_MarcDat* p,Vint idom,Vlong nbps);
VKI_EXTERN void vdm_MarcDatGetDom(vdm_MarcDat* p,Vint
idom,Vlong* nbps);VKI_EXTERN void vdm_MarcDatSetObject(vdm_MarcDat*
p,Vobject* obj);VKI_EXTERN void vdm_MarcDatGetObject(vdm_MarcDat*
p,Vobject** obj);VKI_EXTERN void vdm_MarcDatCopy(vdm_MarcDat*
p,vdm_MarcDat* q);
#ifdef __cplusplus
}
#endif
#endif

