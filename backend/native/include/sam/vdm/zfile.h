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
 
#ifndef ZFILE_DEF
#define ZFILE_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#define ZFILE_READ 1
#define ZFILE_WRITE 2
typedef struct vdm_ZFile { Vchar name[SYS_MAXPATHCHAR];
FILE* fd;void* gzfd;Vint mode;Vint compressed;}vdm_ZFile;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_ZFile* vdm_ZFileBegin(void);VKI_EXTERN
void vdm_ZFileEnd(vdm_ZFile* p);VKI_EXTERN void vdm_ZFileOpen(vdm_ZFile*
p,Vchar name[],Vint mode,Vint* flag);VKI_EXTERN void
vdm_ZFileClose(vdm_ZFile* p);VKI_EXTERN void vdm_ZFileRewind(vdm_ZFile*
p);VKI_EXTERN Vint vdm_ZFileRead(vdm_ZFile* p,Vint size,
Vchar buffer[]);VKI_EXTERN Vchar* vdm_ZFileGets(vdm_ZFile*
p,Vint size,Vchar buffer[]);VKI_EXTERN void vdm_ZFileSeek(vdm_ZFile*
p,Vlong offset,Vint whence);VKI_EXTERN Vlong vdm_ZFileTell(vdm_ZFile*
p);VKI_EXTERN void vdm_ZFileCheckASCII(vdm_ZFile* p,
Vint nbytes,Vint* status);
#ifdef __cplusplus
}
#endif
#endif

