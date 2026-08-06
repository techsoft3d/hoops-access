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
 
#ifndef ABALIBIO_DEF
#define ABALIBIO_DEF
#include "sam/base/base.h"
#define ABALIBIO_LENGTH 1
#define ABALIBIO_BYTESWAP 2
#define ABALIBIO_WORDSINREC 3
#define ABALIBIO_ORIGIN 1
typedef struct vdm_ABALibio { FILE* fd;Vint ipnt;Vlong
iblk;Vint nwds;Vint* ibuff;Vdouble* dbuff;Vchar* cbuff;
Vint iolen;Vint giolen;Vint byteswap;Vint ierr;Vint
status;Vlong orig;Vint l;Vint irec;Vint format;Vint
setposflag;Vint maxswapped;Vchar* swapped;}vdm_ABALibio;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_ABALibio* vdm_ABALibioBegin(void);VKI_EXTERN
void vdm_ABALibioEnd(vdm_ABALibio* p);VKI_EXTERN Vint
vdm_ABALibioError(vdm_ABALibio* p);VKI_EXTERN void vdm_ABALibioOpen(vdm_ABALibio*
p,Vchar* filename,Vint* status);VKI_EXTERN void vdm_ABALibioClose(vdm_ABALibio*
p);VKI_EXTERN void vdm_ABALibioGetPos(vdm_ABALibio*
p,Vint* nc,Vlong* nb);VKI_EXTERN void vdm_ABALibioSetPos(vdm_ABALibio*
p,Vint nc,Vlong nb);VKI_EXTERN void vdm_ABALibioRead(vdm_ABALibio*
p,Vint* nw,Vint* key,Vdouble array[],Vint* jrcd);VKI_EXTERN
void vdm_ABALibioGetInteger(vdm_ABALibio* p,Vint type,
Vint* value);VKI_EXTERN void vdm_ABALibioPuti(vdm_ABALibio*
p,Vint n,Vint ia[]);VKI_EXTERN void vdm_ABALibioPutd(vdm_ABALibio*
p,Vint n,Vdouble a[]);VKI_EXTERN void vdm_ABALibioPutc(vdm_ABALibio*
p,Vint n,const Vchar a[]);VKI_EXTERN void vdm_ABALibioSetStatus(vdm_ABALibio*
p,Vint status);
#ifdef __cplusplus
}
#endif
#endif

