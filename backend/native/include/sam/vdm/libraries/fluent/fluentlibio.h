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
 
#ifndef FLUENTLIBIODEF
#define FLUENTLIBIODEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/zfile.h"
#define FLUENTLIB_SWAP 1
#define FLUENTLIB_FLOAT 2
#define FLUENTLIB_OK 1
#define FLUENTLIB_EOF 2
#define FLUENTLIB_UNREC 3
#define FLUENTLIB_BOS 4
#define FLUENTLIB_EOS 5
#define FLUENTLIB_TRUNC 6
#define FLUENTLIB_FM_DEF 1
#define FLUENTLIB_FM_HEX 2
#define FLUENTLIB_FM_BIN4 3
#define FLUENTLIB_FM_BIN8 4
typedef struct vdm_FLUENTLibio { Vint ierr;Vchar filename[SYS_MAXPATHCHAR];
vdm_ZFile* fd;Vchar* buffer;Vchar* s;Vint bsize;Vint
format;Vint eol;Vint len;Vint m;Vint level;Vint swap;
Vint floatflag;Vint nb,curb,numb,maxb;Vint* ib;Vfloat*
fb;Vdouble* db;}vdm_FLUENTLibio;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_FLUENTLibio* vdm_FLUENTLibioBegin(void);
VKI_EXTERN void vdm_FLUENTLibioEnd(vdm_FLUENTLibio*
p);VKI_EXTERN Vint vdm_FLUENTLibioError(vdm_FLUENTLibio*
p);VKI_EXTERN void vdm_FLUENTLibioOpen(vdm_FLUENTLibio*
p,Vchar* filename,Vint* status);VKI_EXTERN void vdm_FLUENTLibioClose(vdm_FLUENTLibio*
p);VKI_EXTERN void vdm_FLUENTLibioRewind(vdm_FLUENTLibio*
p);VKI_EXTERN void vdm_FLUENTLibioOpenFile(vdm_FLUENTLibio*
p);VKI_EXTERN void vdm_FLUENTLibioCloseFile(vdm_FLUENTLibio*
p);VKI_EXTERN void vdm_FLUENTLibioSetFormat(vdm_FLUENTLibio*
p,Vint type);VKI_EXTERN void vdm_FLUENTLibioStart(vdm_FLUENTLibio*
p,Vint* flag);VKI_EXTERN void vdm_FLUENTLibioGetBuffer(vdm_FLUENTLibio*
p,Vchar** buffer);VKI_EXTERN void vdm_FLUENTLibioSkip(vdm_FLUENTLibio*
p,Vint* flag);VKI_EXTERN void vdm_FLUENTLibioSkipn(vdm_FLUENTLibio*
p,Vint intflag,Vint nv);VKI_EXTERN void vdm_FLUENTLibioDatai(vdm_FLUENTLibio*
p,Vint* ival,Vint* flag);VKI_EXTERN void vdm_FLUENTLibioDatain(vdm_FLUENTLibio*
p,Vint ni,Vint ival[],Vint* flag);VKI_EXTERN void vdm_FLUENTLibioDatad(vdm_FLUENTLibio*
p,Vdouble* dval,Vint* flag);VKI_EXTERN void vdm_FLUENTLibioDatac(vdm_FLUENTLibio*
p,Vchar cval[],Vint* flag);VKI_EXTERN void vdm_FLUENTLibioSetParami(vdm_FLUENTLibio*
p,Vint type,Vint value);VKI_EXTERN void vdm_FLUENTLibioGetParami(vdm_FLUENTLibio*
p,Vint type,Vint* value);VKI_EXTERN void vdm_FLUENTLibioGetPos(vdm_FLUENTLibio*
p,Vlong* nc);VKI_EXTERN void vdm_FLUENTLibioSetPos(vdm_FLUENTLibio*
p,Vlong nc);
#ifdef __cplusplus
}
#endif
#endif

