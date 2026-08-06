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
 
#ifndef ENSIGHTTIME_DEF
#define ENSIGHTTIME_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct vdm_EnSightTime { Vint nsteps;Vint tsetid;
Vint fstart;Vint increment;vsy_FltVec* timeval;vsy_IntVec*
timenum;Vint timenumflag;Vint timenumid;Vint timevalid;
Vint cur;}vdm_EnSightTime;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_EnSightTime* vdm_EnSightTimeBegin(void);
VKI_EXTERN void vdm_EnSightTimeEnd(vdm_EnSightTime*
p);VKI_EXTERN Vint vdm_EnSightTimeFirst(vdm_EnSightTime*
p);VKI_EXTERN Vint vdm_EnSightTimeNext(vdm_EnSightTime*
p);VKI_EXTERN Vfloat vdm_EnSightTimeGetTimeVal(vdm_EnSightTime*
p);VKI_EXTERN void vdm_EnSightTimeGetTimeById(vdm_EnSightTime*
p,Vint id,Vfloat* timeval);VKI_EXTERN void vdm_EnSightTimeVal(vdm_EnSightTime*
p,Vfloat time);VKI_EXTERN void vdm_EnSightTimeNum(vdm_EnSightTime*
p,Vint timenum);VKI_EXTERN void vdm_EnSightTimeInc(vdm_EnSightTime*
p,Vint increment);VKI_EXTERN void vdm_EnSightTimeStart(vdm_EnSightTime*
p,Vint fstart);VKI_EXTERN void vdm_EnSightTimeNumSteps(vdm_EnSightTime*
p,Vint nsteps);VKI_EXTERN void vdm_EnSightTimeGetNumSteps(vdm_EnSightTime*
p,Vint* nsteps);VKI_EXTERN void vdm_EnSightTimeSet(vdm_EnSightTime*
p,Vint tsetid);VKI_EXTERN void vdm_EnSightTimeGet(vdm_EnSightTime*
p,Vint* tsetid);VKI_EXTERN Vint vdm_EnSightTimeEqual(vdm_EnSightTime*
p,vdm_EnSightTime* q);VKI_EXTERN Vint vdm_EnSightTimeNonZero(vdm_EnSightTime*
p);
#ifdef __cplusplus
}
#endif
#endif

