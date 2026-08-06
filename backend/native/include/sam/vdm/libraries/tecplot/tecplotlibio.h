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
 
#ifndef TECPLOTLIBIODEF
#define TECPLOTLIBIODEF
#include <stdio.h>
#define TECPLOTLIB_OK 0
#define TECPLOTLIB_EOF 1
#define TECPLOTLIB_ZONE 2
#define TECPLOTLIB_DATA 3
#define TECPLOTLIB_SKIP_ZONE 1
#define TECPLOTLIB_SKIP_DATA 2
#define TECPLOTLIB_SKIP_ZONEDATA 3
#define TECPLOTLIBIO_FORMAT 1
#define TECPLOTLIBIO_BYTESWAP 2
#define TECPLOTLIBIO_VERSION 3
#define TECPLOTLIBIO_KEYWORD 0
#define TECPLOTLIBIO_EOF 1
typedef struct vdm_TecplotLibio { Vint ierr;FILE* fd;
Vint format;Vint byteswap;Vchar version[5];Vint iversion;
Vint numvar;Vchar** varnam;Vint maxbuf;Vchar keybuf[32000];
Vchar buffer[32000];Vchar keyword[17];Vint numkeyval;
Vint ikeyval[1000];Vdouble dkeyval[1000];Vchar ckeyval[1000][65];
Vchar rbuf[4096];Vint bufloc;Vint bufsize;}vdm_TecplotLibio;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_TecplotLibio* vdm_TecplotLibioBegin(void);
VKI_EXTERN void vdm_TecplotLibioEnd(vdm_TecplotLibio*
p);VKI_EXTERN Vint vdm_TecplotLibioError(vdm_TecplotLibio*
p);VKI_EXTERN void vdm_TecplotLibioOpen(vdm_TecplotLibio*
p,Vchar* filename,Vint* status);VKI_EXTERN void vdm_TecplotLibioWriteOpen(vdm_TecplotLibio*
p,Vchar* filename,Vint* status);VKI_EXTERN void vdm_TecplotLibioClose(vdm_TecplotLibio*
p);VKI_EXTERN void vdm_TecplotLibioRewind(vdm_TecplotLibio*
p);VKI_EXTERN void vdm_TecplotLibioInit(vdm_TecplotLibio*
p,Vchar vers[5],Vint* ierr);VKI_EXTERN void vdm_TecplotLibioGetInteger(vdm_TecplotLibio*
p,Vint type,Vint* value);VKI_EXTERN void vdm_TecplotLibioFileHeader(vdm_TecplotLibio*
p,Vchar title[],Vint* filetype,Vint* numvar,Vint* ierr);
VKI_EXTERN void vdm_TecplotLibioVariableName(vdm_TecplotLibio*
p,Vint ivar,Vchar* varnam);VKI_EXTERN void vdm_TecplotLibioFindZone(vdm_TecplotLibio*
p,Vint* ierr);VKI_EXTERN void vdm_TecplotLibioWriteInit(vdm_TecplotLibio*
p);VKI_EXTERN void vdm_TecplotLibioSkip(vdm_TecplotLibio*
p,Vint type,Vint* flag);VKI_EXTERN void vdm_TecplotLibioSkipByte(vdm_TecplotLibio*
p,Vint size,Vint nwds,Vint* ierr);VKI_EXTERN void vdm_TecplotLibioDatai(vdm_TecplotLibio*
p,Vint n,Vint val[],Vint* flag);VKI_EXTERN void vdm_TecplotLibioDataf(vdm_TecplotLibio*
p,Vint n,Vfloat val[],Vint* flag);VKI_EXTERN void vdm_TecplotLibioDatad(vdm_TecplotLibio*
p,Vint n,Vdouble val[],Vint* flag);VKI_EXTERN void vdm_TecplotLibioConvi(vdm_TecplotLibio*
p,Vint dtyp,Vint n,Vint val[],Vint* flag);VKI_EXTERN
void vdm_TecplotLibioDatac(vdm_TecplotLibio* p,Vchar
val[],Vint* flag);VKI_EXTERN void vdm_TecplotLibioGetPos(vdm_TecplotLibio*
p,Vlong* nc);VKI_EXTERN void vdm_TecplotLibioSetPos(vdm_TecplotLibio*
p,Vlong nc,Vint* ierr);VKI_EXTERN void vdm_TecplotLibioWritei(vdm_TecplotLibio*
p,Vint n,Vint val[],Vint* flag);VKI_EXTERN void vdm_TecplotLibioWritef(vdm_TecplotLibio*
p,Vint n,Vfloat val[],Vint* flag);VKI_EXTERN void vdm_TecplotLibioWrited(vdm_TecplotLibio*
p,Vint n,Vdouble val[],Vint* flag);VKI_EXTERN void vdm_TecplotLibioWritec(vdm_TecplotLibio*
p,Vchar val[],Vint* flag);
#ifdef __cplusplus
}
#endif
#endif

