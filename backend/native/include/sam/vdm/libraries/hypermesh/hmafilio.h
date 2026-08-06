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
 
#ifndef HMAFILIODEF
#define HMAFILIODEF
#include <stdio.h>
#include "sam/base/base.h"
#define HMAFIL_KEYWORD 1
#define HMAFIL_UNKNOWN 2
#define HMAFIL_EOF 3
#define HMAFIL_LINENUMBER 1
typedef struct vdm_HMAFilio { Vint ierr;FILE* fd;Vchar
buffer[2048];Vint nitems;Vint* idata;Vint* tdata;Vdouble*
ddata;Vchar** cdata;Vint line;Vchar name[SYS_MAXPATHCHAR];
Vchar key[256];}vdm_HMAFilio;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_HMAFilio* vdm_HMAFilioBegin(void);VKI_EXTERN
void vdm_HMAFilioEnd(vdm_HMAFilio* p);VKI_EXTERN Vint
vdm_HMAFilioError(vdm_HMAFilio* p);VKI_EXTERN void vdm_HMAFilioOpen(vdm_HMAFilio*
p,Vchar* filename,Vint* status);VKI_EXTERN void vdm_HMAFilioClose(vdm_HMAFilio*
p);VKI_EXTERN void vdm_HMAFilioReadKeyword(vdm_HMAFilio*
p,Vint* linetype);VKI_EXTERN void vdm_HMAFilioGetKeyword(vdm_HMAFilio*
p,Vchar* key);VKI_EXTERN void vdm_HMAFilioNumItems(vdm_HMAFilio*
p,Vint* num);VKI_EXTERN void vdm_HMAFilioItemi(vdm_HMAFilio*
p,Vint n,Vint* value);VKI_EXTERN void vdm_HMAFilioItemd(vdm_HMAFilio*
p,Vint n,Vdouble* value);VKI_EXTERN void vdm_HMAFilio3Itemd(vdm_HMAFilio*
p,Vint n,Vdouble value[]);VKI_EXTERN void vdm_HMAFilioItemc(vdm_HMAFilio*
p,Vint n,Vchar* value);VKI_EXTERN void vdm_HMAFilioItemType(vdm_HMAFilio*
p,Vint n,Vint* valuetype);VKI_EXTERN void vdm_HMAFilioGetBuffer(vdm_HMAFilio*
p,Vchar* buffer);VKI_EXTERN void vdm_HMAFilioGetInteger(vdm_HMAFilio*
p,Vint type,Vint* value);VKI_EXTERN void vdm_HMAFilioGetFilename(vdm_HMAFilio*
p,Vchar* filename);
#ifdef __cplusplus
}
#endif
#endif

