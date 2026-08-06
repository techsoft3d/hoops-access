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
 
#ifndef VTKLIBIO_DEF
#define VTKLIBIO_DEF
#include "sam/base/base.h"
typedef struct vdm_VTKLibio { FILE* fd;Vint format;
Vint bufsize;Vint maxwords;Vint len;Vint nwords;Vint
iword;Vint nkey;Vint binary;Vchar* buffer;Vchar (*word)[40];
Vchar key[10][40];}vdm_VTKLibio;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_VTKLibio* vdm_VTKLibioBegin(void);VKI_EXTERN
void vdm_VTKLibioEnd(vdm_VTKLibio* p);VKI_EXTERN void
vdm_VTKLibioOpen(vdm_VTKLibio* p,Vchar filename[],Vchar
version[],Vchar title[],Vint* ier);VKI_EXTERN void vdm_VTKLibioClose(vdm_VTKLibio*
p);VKI_EXTERN Vchar* vdm_VTKLibioRawLine(vdm_VTKLibio*
p);VKI_EXTERN void vdm_VTKLibioKeyword(vdm_VTKLibio*
p,Vchar key[]);VKI_EXTERN Vint vdm_VTKLibioKeyDatai(vdm_VTKLibio*
p,Vint n,Vint* ival);VKI_EXTERN Vint vdm_VTKLibioKeyDatas(vdm_VTKLibio*
p,Vint n,Vchar sval[]);VKI_EXTERN Vint vdm_VTKLibioKeyDataf(vdm_VTKLibio*
p,Vint n,Vfloat* fval);VKI_EXTERN Vint vdm_VTKLibioDatac(vdm_VTKLibio*
p,Vint n,Vchar ix[]);VKI_EXTERN Vint vdm_VTKLibioDatai(vdm_VTKLibio*
p,Vint* swap,Vint n,void* ix,Vint int64Flag);VKI_EXTERN
Vint vdm_VTKLibioDataf(vdm_VTKLibio* p,Vint* swap,Vint
n,Vfloat fx[]);VKI_EXTERN Vint vdm_VTKLibioDatad(vdm_VTKLibio*
p,Vint* swap,Vint n,Vdouble dx[]);VKI_EXTERN Vlong vdm_VTKLibioTell(vdm_VTKLibio*
p);VKI_EXTERN void vdm_VTKLibioSeek(vdm_VTKLibio* p,
Vlong offset,Vint whence);VKI_EXTERN void vdm_VTKLibioSkipc(vdm_VTKLibio*
p,Vint n);VKI_EXTERN void vdm_VTKLibioSkipi(vdm_VTKLibio*
p,Vint n,Vint int64Flag);VKI_EXTERN void vdm_VTKLibioSkipf(vdm_VTKLibio*
p,Vint n);VKI_EXTERN void vdm_VTKLibioSkipd(vdm_VTKLibio*
p,Vint n);VKI_EXTERN void vdm_VTKLibioResetStoredData(vdm_VTKLibio*
p);
#ifdef __cplusplus
}
#endif
#endif

