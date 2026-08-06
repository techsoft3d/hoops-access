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
 
#ifndef OPENFOAMDAT_DEF
#define OPENFOAMDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct { Vint processor;Vint format;Vchar cname[80];
Vchar oname[80];Vchar nname[80];Vchar region[80];Vchar
name[SYS_MAXPATHCHAR];Vchar rootfile[SYS_MAXPATHCHAR];
Vchar pmname[SYS_MAXPATHCHAR];Vfloat time;Vlong pos;
Vlong offset;Vint timeflag;Vint pmflag;Vint lagrangian;
}vdm_OpenFOAMLib_File;typedef struct vdm_OPENFoamDat
{ Vint nfiles;Vint ifile;Vint ncmp;Vchar oname[256];
Vfloat time;Vint enttype;Vint id1;Vint istrack;vdm_OpenFOAMLib_File**
file;}vdm_OpenFOAMDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_OpenFOAMDat* vdm_OpenFOAMDatBegin(void);
VKI_EXTERN void vdm_OpenFOAMDatEnd(vdm_OpenFOAMDat*
p);VKI_EXTERN void vdm_OpenFOAMDatDef(vdm_OpenFOAMDat*
p,Vchar oname[],Vint ncmp,Vint enttype,Vint id1,Vfloat
time,Vint istrack);VKI_EXTERN void vdm_OpenFOAMDatInq(vdm_OpenFOAMDat*
p,Vchar oname[],Vint* ncmp,Vint* enttype,Vint* id1,
Vfloat* time,Vint* istrack);VKI_EXTERN void vdm_OpenFOAMDatAddFile(vdm_OpenFOAMDat*
p,vdm_OpenFOAMLib_File* file);VKI_EXTERN void vdm_OpenFOAMDatInitFile(vdm_OpenFOAMDat*
p);VKI_EXTERN void vdm_OpenFOAMDatNextFile(vdm_OpenFOAMDat*
p,vdm_OpenFOAMLib_File** file);
#ifdef __cplusplus
}
#endif
#endif

