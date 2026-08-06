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
 
#ifndef DISK_DEF
#define DISK_DEF
#include <stdio.h>
#include <sys/types.h>
#include "sam/base/basedefs.h"
#define DISK_UNKNOWN 0
#define DISK_OLD 1
#define DISK_NEW 2
#define DISK_ADD 3
#define DISK_MAGIC 101491
#define DISK_MAGIC1 31601
#define DISK_MAGIC2 82610
#define DISK_MAGIC3 32411
#define DISK_MAGIC4 200924
#define DISK_OFFMULT 1
#define DISK_OFFMULT1 256
typedef struct vdm_Disk { FILE* fd;Vint ierr;Vint iver;
Vint swapflag;Vint magic;Vint freeoff;Vint freesiz;
Vint maxoffset;Vlong freeoffl;Vlong freesizl;Vlong maxoffsetl;
Vint tailsize;Vint offmult;Vlong liboff;Vlong maxoff;
Vlong curoff;Vlong rwstat;}vdm_Disk;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_Disk* vdm_DiskBegin(void);VKI_EXTERN
void vdm_DiskEnd(vdm_Disk* p);VKI_EXTERN Vint vdm_DiskError(vdm_Disk*
p);VKI_EXTERN void vdm_DiskOpen(vdm_Disk* p,Vchar* path,
Vint status,Vint* iexist);VKI_EXTERN void vdm_DiskClose(vdm_Disk*
p);VKI_EXTERN void vdm_DiskLoadLibrary(vdm_Disk* p,
vdm_Library* library);VKI_EXTERN void vdm_DiskSaveLibrary(vdm_Disk*
p,vdm_Library* library);VKI_EXTERN void vdm_DiskAlloc(vdm_Disk*
p,Vint length,Vint contig,Vint* offset,Vint* size);
VKI_EXTERN void vdm_DiskAllocl(vdm_Disk* p,Vlong length,
Vint contig,Vlong* offset,Vlong* size);VKI_EXTERN void
vdm_DiskWrite(vdm_Disk* p,Vint length,Vint offset,Vint
size,void* buff);VKI_EXTERN void vdm_DiskWritel(vdm_Disk*
p,Vlong length,Vlong offset,Vlong size,void* buff);
VKI_EXTERN void vdm_DiskRead(vdm_Disk* p,Vint length,
Vint offset,Vint size,void* buff);VKI_EXTERN void vdm_DiskReadl(vdm_Disk*
p,Vlong length,Vlong offset,Vlong size,void* buff);
VKI_EXTERN void vdm_DiskFree(vdm_Disk* p,Vint offset,
Vint size);VKI_EXTERN void vdm_DiskFreel(vdm_Disk* p,
Vlong offset,Vlong size);VKI_EXTERN void vdm_DiskRealloc(vdm_Disk*
p,Vint length,Vint contig,Vint offset,Vint size);VKI_EXTERN
void vdm_DiskReallocl(vdm_Disk* p,Vlong length,Vlong
contig,Vlong offset,Vlong size);VKI_EXTERN void vdm_DiskUpdate(vdm_Disk*
p);VKI_EXTERN void vdm_DiskDump(vdm_Disk* p);VKI_EXTERN
void vdm_DiskInq(vdm_Disk* p,Vint* minoffset);VKI_EXTERN
void vdm_DiskAddSize(vdm_Disk* p,Vint* addsize);VKI_EXTERN
void vdm_DiskInqVersion(vdm_Disk* p,Vint* iver);VKI_EXTERN
void vdm_DiskInqMaxoff(vdm_Disk* p,Vlong* maxoff);
#ifdef __cplusplus
}
#endif
#endif

