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
 
#ifndef MACHINFO_DEF
#define MACHINFO_DEF
#include "sam/base/basedefs.h"
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN void vut_MachInfoNumProc(Vint* flag,Vint*
numproc);VKI_EXTERN void vut_MachInfoUsedMem(Vint* flag,
Vint* usedmem);VKI_EXTERN void vut_MachInfoTotalMem(Vint*
flag,Vint* totalmem);VKI_EXTERN void vut_MachInfoPrec(Vint*
flag,Vdouble* prec);VKI_EXTERN void vut_MachInfoSystemName(Vint*
flag,Vchar sname[]);VKI_EXTERN void vut_MachInfoHostName(Vint*
flag,Vchar hname[]);VKI_EXTERN void vut_MachInfoUserName(Vint*
flag,Vchar uname[]);VKI_EXTERN void vut_MachInfoObjectSize(Vint*
flag,Vint* objectsize);VKI_EXTERN void vut_MachInfoFilePosSize(Vint*
flag,Vint* filepossize);VKI_EXTERN void vut_MachInfoEndian(Vint*
flag,Vint* endian);VKI_EXTERN void vut_MachInfoLIBAPI_SOCKETS(Vint*
flag);VKI_EXTERN void vut_MachInfoDateString(Vint* flag,
Vchar date[]);VKI_EXTERN void vut_MachInfoDateInteger(Vint*
flag,Vint* day,Vint* mon,Vint* year);VKI_EXTERN void
vut_MachInfoTimeString(Vint* flag,Vchar time[]);VKI_EXTERN
void vut_MachInfoTimeInteger(Vint* flag,Vint* sec,Vint*
min,Vint* hour);VKI_EXTERN void vut_MachInfoVlongString(Vlong
l,Vchar stg[33]);VKI_EXTERN void vut_MachInfoCpuTimes(Vint*
flag,Vfloat* usrtime,Vfloat* systime);
#ifdef __cplusplus
}
#endif
#endif

