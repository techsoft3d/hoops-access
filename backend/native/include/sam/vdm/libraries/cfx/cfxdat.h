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
 
#ifndef CFXDAT_DEF
#define CFXDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct vdm_CFXDat { Vint num;Vint length;Vint
iter;vsy_IntVec* zoneids;vsy_IntVec* varids;vsy_IntVec*
icmps;vsy_IntVec* stepids;Vchar filename[SYS_MAXPATHCHAR];
}vdm_CFXDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_CFXDat* vdm_CFXDatBegin(void);VKI_EXTERN
void vdm_CFXDatEnd(vdm_CFXDat* p);VKI_EXTERN void vdm_CFXDatAddRes(vdm_CFXDat*
p,Vint stepid,Vint zoneid,Vint varid,Vint icmp,Vint
length);VKI_EXTERN void vdm_CFXDatInitIter(vdm_CFXDat*
p);VKI_EXTERN void vdm_CFXDatNextIter(vdm_CFXDat* p,
Vint* stepid,Vint* zoneid,Vint* varid,Vint* icmp);VKI_EXTERN
void vdm_CFXDatGetMaxLength(vdm_CFXDat* p,Vint* length);
VKI_EXTERN void vdm_CFXDatSetFilename(vdm_CFXDat* p,
Vchar filename[]);VKI_EXTERN void vdm_CFXDatGetFilename(vdm_CFXDat*
p,Vchar filename[]);
#ifdef __cplusplus
}
#endif
#endif

