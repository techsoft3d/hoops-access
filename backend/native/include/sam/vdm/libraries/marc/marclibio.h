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
 
#ifndef MARCTLIBIODEF
#define MARCTLIBIODEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vdm/vdmdefs.h"
#define MARCLIB_OK 0
#define MARCLIB_ERROR 1
#define MARCLIB_EOF 2
#define MARCLIBIO_BSIZE 1024
typedef struct vdm_MarcLibio { Vint ierr;FILE* fd;Vchar
buffer[132];Vint ibuffer[MARCLIBIO_BSIZE];Vint nibuf;
Vint iibuf;Vint ibuf;Vint nbuf;Vint format;Vint swap;
Vint skip;Vint recsize;Vint irec;}vdm_MarcLibio;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_MarcLibio* vdm_MarcLibioBegin(void);
VKI_EXTERN void vdm_MarcLibioEnd(vdm_MarcLibio* p);
VKI_EXTERN Vint vdm_MarcLibioError(vdm_MarcLibio* p);
VKI_EXTERN void vdm_MarcLibioOpen(vdm_MarcLibio* p,
Vchar* filename,Vint* status);VKI_EXTERN void vdm_MarcLibioClose(vdm_MarcLibio*
p);VKI_EXTERN void vdm_MarcLibioBlock(vdm_MarcLibio*
p,Vint* id,Vchar head[80],Vint* flag);VKI_EXTERN void
vdm_MarcLibioGetPos(vdm_MarcLibio* p,Vlong* nc);VKI_EXTERN
void vdm_MarcLibioSetPos(vdm_MarcLibio* p,Vlong nc);
VKI_EXTERN void vdm_MarcLibioSkipf(vdm_MarcLibio* p,
Vint n,Vint* flag);VKI_EXTERN void vdm_MarcLibioRewind(vdm_MarcLibio*
p);VKI_EXTERN void vdm_MarcLibioDataf(vdm_MarcLibio*
p,Vint n,Vfloat fdata[],Vint* flag);VKI_EXTERN void
vdm_MarcLibioDatai(vdm_MarcLibio* p,Vint n,Vint idata[],
Vint* flag);VKI_EXTERN void vdm_MarcLibioDatac(vdm_MarcLibio*
p,Vint n,Vchar data[],Vint* flag);VKI_EXTERN void vdm_MarcLibioDataic(vdm_MarcLibio*
p,Vint nint,Vint idata[],Vint n,Vchar data[],Vint* flag);
#ifdef __cplusplus
}
#endif
#endif

