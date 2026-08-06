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
 
#ifndef NASOP2IO_DEF
#define NASOP2IO_DEF
#include <stdio.h>
#include "sam/base/base.h"
typedef struct vdm_NASop2io { Vint ierr;Vint count;
Vint nwds;Vint nwdsw;Vint bsizef;Vint bsize;Vint bsize4;
Vint bswap;Vint zero;Vint one;Vint two;Vint three;Vint
four;Vint seven;Vint mone;Vint mtwo;Vint mthree;FILE*
fp;fpos_t posbyte;fpos_t poslength;Vint* buffer;Vint
iw;Vint init;}vdm_NASop2io;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_NASop2io* vdm_NASop2ioBegin(void);VKI_EXTERN
void vdm_NASop2ioEnd(vdm_NASop2io* p);VKI_EXTERN Vint
vdm_NASop2ioError(vdm_NASop2io* p);VKI_EXTERN void vdm_NASop2ioOpen(vdm_NASop2io*
p,Vchar* filename,Vint mode);VKI_EXTERN void vdm_NASop2ioWriteLabel(vdm_NASop2io*
p,Vint day,Vint month,Vint year);VKI_EXTERN void vdm_NASop2ioClose(vdm_NASop2io*
p);VKI_EXTERN void vdm_NASop2ioWriteDBHead(vdm_NASop2io*
p,const Vchar* dbname,Vint trailer[],const Vchar* dbname2,
Vint ndat,Vint data[]);VKI_EXTERN void vdm_NASop2ioWriteDBTail(vdm_NASop2io*
p);VKI_EXTERN void vdm_NASop2ioWriteEOD(vdm_NASop2io*
p);VKI_EXTERN void vdm_NASop2ioRewindEOD(vdm_NASop2io*
p);VKI_EXTERN void vdm_NASop2ioDataAdd(vdm_NASop2io*
p,Vint nwds,void* data);VKI_EXTERN void vdm_NASop2ioDataAddC(vdm_NASop2io*
p,Vint nwds,void* data);VKI_EXTERN void vdm_NASop2ioDataAddD(vdm_NASop2io*
p,Vint nwds,void* data);VKI_EXTERN void vdm_NASop2ioDataInit(vdm_NASop2io*
p);VKI_EXTERN void vdm_NASop2ioDataTerm(vdm_NASop2io*
p);
#ifdef __cplusplus
}
#endif
#endif

