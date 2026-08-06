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
 
#ifndef D3DDAT_DEF
#define D3DDAT_DEF
#include "sam/base/basedefs.h"
typedef struct vdm_D3DDat { Vint ifamily;Vlong offset;
Vint length;Vint type;Vint sect;Vint ieiph;Vint rtyp;
Vint iqua1,iqua2;Vint ncmp;Vint icmp;Vint istr;Vint
inid;Vlong pos;Vint cplx;}vdm_D3DDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_D3DDat* vdm_D3DDatBegin(void);VKI_EXTERN
void vdm_D3DDatEnd(vdm_D3DDat* d3ddat);VKI_EXTERN void
vdm_D3DDatDef(vdm_D3DDat* d3ddat,Vint ifamily,Vlong
offset,Vint length,Vint type,Vint sect);VKI_EXTERN void
vdm_D3DDatInq(vdm_D3DDat* d3ddat,Vint* ifamily,Vlong*
offset,Vint* length,Vint* type,Vint* sect);VKI_EXTERN
void vdm_D3DDatSetIeiph(vdm_D3DDat* d3ddat,Vint ieiph);
VKI_EXTERN void vdm_D3DDatGetIeiph(vdm_D3DDat* d3ddat,
Vint* ieiph);VKI_EXTERN void vdm_D3DDatSetRtyp(vdm_D3DDat*
d3ddat,Vint rtyp);VKI_EXTERN void vdm_D3DDatGetRtyp(vdm_D3DDat*
d3ddat,Vint* rtyp);VKI_EXTERN void vdm_D3DDatSetQtyp(vdm_D3DDat*
d3ddat,Vint iqua1,Vint iqua2);VKI_EXTERN void vdm_D3DDatGetQtyp(vdm_D3DDat*
d3ddat,Vint* iqua1,Vint* iqua2);VKI_EXTERN void vdm_D3DDatSetNcmp(vdm_D3DDat*
d3ddat,Vint ncmp);VKI_EXTERN void vdm_D3DDatGetNcmp(vdm_D3DDat*
d3ddat,Vint* ncmp);VKI_EXTERN void vdm_D3DDatSetIcmp(vdm_D3DDat*
d3ddat,Vint icmp);VKI_EXTERN void vdm_D3DDatGetIcmp(vdm_D3DDat*
d3ddat,Vint* icmp);VKI_EXTERN void vdm_D3DDatSetIstr(vdm_D3DDat*
d3ddat,Vint istr);VKI_EXTERN void vdm_D3DDatGetIstr(vdm_D3DDat*
d3ddat,Vint* istr);VKI_EXTERN void vdm_D3DDatSetInid(vdm_D3DDat*
d3ddat,Vint inid);VKI_EXTERN void vdm_D3DDatGetInid(vdm_D3DDat*
d3ddat,Vint* inid);VKI_EXTERN void vdm_D3DDatSetPos(vdm_D3DDat*
d3ddat,Vlong pos);VKI_EXTERN void vdm_D3DDatGetPos(vdm_D3DDat*
d3ddat,Vlong* pos);VKI_EXTERN void vdm_D3DDatSetCplx(vdm_D3DDat*
d3ddat,Vint cplx);VKI_EXTERN void vdm_D3DDatGetCplx(vdm_D3DDat*
d3ddat,Vint* cplx);
#ifdef __cplusplus
}
#endif
#endif

