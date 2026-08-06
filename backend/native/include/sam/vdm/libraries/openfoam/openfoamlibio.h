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
 
#ifndef OPENFOAMLIBIO_DEF
#define OPENFOAMLIBIO_DEF
#include "sam/base/base.h"
#include "sam/vdm/zfile.h"
#define OPENFOAM_BUFFSIZE 4096
#define OPENFOAM_FORMAT_ASCII 1
#define OPENFOAM_FORMAT_BIN 2
#define OPENFOAM_TYPE_NONE 0
#define OPENFOAM_TYPE_DATA 1
#define OPENFOAM_TYPE_BEGINARRAY 2
#define OPENFOAM_TYPE_ENDARRAY 3
#define OPENFOAM_TYPE_BEGINDICT 4
#define OPENFOAM_TYPE_ENDDICT 5
#define OPENFOAM_TYPE_ENDKEY 6
#define OPENFOAM_TYPE_BEGINDIM 7
#define OPENFOAM_TYPE_ENDDIM 8
#define OPENFOAM_TYPE_BEGINLIST 9
#define OPENFOAM_TYPE_ENDLIST 10
#define OPENFOAM_TYPE_EOF 11
#define OPENFOAM_TYPE_ERROR 12
#define OPENFOAMLIBIO_INC 1
#define OPENFOAMLIBIO_GO 2
#define OPENFOAMLIBIO_INCEXT 3
#define OPENFOAMLIBIO_INC_ETC 4
#define OPENFOAM_MAXWORD 256
typedef struct { vdm_ZFile* fd;Vchar name[SYS_MAXPATHCHAR];
}vdm_OpenFOAMLibio_file;typedef struct { vdm_ZFile*
fd;Vint line;Vint format;Vint nexttype;Vint bin;Vchar
word[OPENFOAM_MAXWORD];Vchar buffer[OPENFOAM_BUFFSIZE];
Vlong bufloc;Vlong bufsize;Vint keyword;vsy_Dictionary*
incdict;vsy_IntDict* filedict;vdm_OpenFOAMLibio_file*
flist;Vint fid;Vint numf;Vint maxf;Vint inlist;Vchar
basename[SYS_MAXPATHCHAR];Vchar root[SYS_MAXPATHCHAR];
Vchar includeEtcPath[SYS_MAXPATHCHAR];vsy_Stack* stack;
Vint level;Vint maxlevel;}vdm_OpenFOAMLibio;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_OpenFOAMLibio* vdm_OpenFOAMLibioBegin(void);
VKI_EXTERN void vdm_OpenFOAMLibioEnd(vdm_OpenFOAMLibio*
p);VKI_EXTERN void vdm_OpenFOAMLibioOpenPos(vdm_OpenFOAMLibio*
p,Vchar filename[],Vlong pos,Vlong offset,Vchar root[],
Vchar includeEtcPath[]);VKI_EXTERN Vint vdm_OpenFOAMLibioPush(vdm_OpenFOAMLibio*
p,Vchar name[],Vint pushtype);VKI_EXTERN void vdm_OpenFOAMLibioPop(vdm_OpenFOAMLibio*
p);VKI_EXTERN void vdm_OpenFOAMLibioRealPrec(vdm_OpenFOAMLibio*
p,Vint num,Vint* ipre);VKI_EXTERN void vdm_OpenFOAMLibioOpen(vdm_OpenFOAMLibio*
p,Vchar* filename,Vint* format,Vfloat* fversion,Vchar
cname[],Vchar oname[],Vchar nname[],Vlong* pos,Vlong*
offset,Vint* ierr,Vchar root[],Vchar includeEtcPath[]);
VKI_EXTERN void vdm_OpenFOAMLibioData(vdm_OpenFOAMLibio*
p,Vchar str[]);VKI_EXTERN void vdm_OpenFOAMLibioDatai(vdm_OpenFOAMLibio*
p,Vint* ivalue);VKI_EXTERN void vdm_OpenFOAMLibioDataf(vdm_OpenFOAMLibio*
p,Vfloat* fvalue);VKI_EXTERN void vdm_OpenFOAMLibioDatad(vdm_OpenFOAMLibio*
p,Vdouble* dvalue);VKI_EXTERN void vdm_OpenFOAMLibioDataSkip(vdm_OpenFOAMLibio*
p);VKI_EXTERN void vdm_OpenFOAMLibioNext(vdm_OpenFOAMLibio*
p,Vint* type,Vchar message[]);VKI_EXTERN void vdm_OpenFOAMLibioClose(vdm_OpenFOAMLibio*
p);VKI_EXTERN void vdm_OpenFOAMLibioRBin(vdm_OpenFOAMLibio*
p,Vint num,Vfloat fbuf[],Vint* swap,Vint* ierr);VKI_EXTERN
void vdm_OpenFOAMLibioDBin(vdm_OpenFOAMLibio* p,Vint
num,Vdouble dbuf[],Vint* swap,Vint* ierr);VKI_EXTERN
void vdm_OpenFOAMLibioIBin(vdm_OpenFOAMLibio* p,Vint
num,Vint ibuf[],Vint* is64,Vint* swap,Vint* ierr);VKI_EXTERN
void vdm_OpenFOAMLibioGetPos(vdm_OpenFOAMLibio* p,Vlong*
pos,Vlong* offset);VKI_EXTERN void vdm_OpenFOAMLibioSetPos(vdm_OpenFOAMLibio*
p,Vlong pos,Vlong offset);VKI_EXTERN Vint vdm_OpenFOAMLibioSkipList(vdm_OpenFOAMLibio*
p,Vint ncmp);
#ifdef __cplusplus
}
#endif
#endif

