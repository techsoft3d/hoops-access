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
 
#ifndef PROGRESS_DEF
#define PROGRESS_DEF
#include "sam/base/basedefs.h"
#include "sam/base/list.h"
#include "sam/base/timer.h"
#define PROGRESS_RATE 1
#define PROGRESS_RATE_NORMAL 1
#define PROGRESS_RATE_ACCELERATED 2
#define PROGRESS_RATE_STALLED 3
struct vsy_Progress { Vint ierr;Vint id;Vint running;
Vint rate;vsy_List* list;vsy_Timer* timer;
#ifdef __cplusplus
public: VKI_EXTERN vsy_Progress(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_Progress(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Start();VKI_EXTERN void Stop();
VKI_EXTERN void Push(const Vchar*,Vint);VKI_EXTERN void
Pop(const Vchar*);VKI_EXTERN void Interval(Vint,const
Vchar*,Vfloat,Vfloat);VKI_EXTERN void Primary(Vint);
VKI_EXTERN void PrimaryName(const Vchar*);VKI_EXTERN
void Secondary(Vfloat);VKI_EXTERN void PercentDone(Vfloat*);
VKI_EXTERN void Time(Vfloat*,Vfloat*);VKI_EXTERN void
GetInteger(Vint,Vint*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_Progress* vsy_ProgressBegin(void);VKI_EXTERN
void vsy_Progress_Construct(vsy_Progress* p);VKI_EXTERN
void vsy_ProgressEnd(vsy_Progress* p);VKI_EXTERN void
vsy_Progress_Destruct(vsy_Progress* p);VKI_EXTERN Vint
vsy_ProgressError(vsy_Progress* p);VKI_EXTERN void vsy_ProgressStart(vsy_Progress*
p);VKI_EXTERN void vsy_ProgressStop(vsy_Progress* p);
VKI_EXTERN void vsy_ProgressPush(vsy_Progress* p,const
Vchar* name,Vint npri);VKI_EXTERN void vsy_ProgressPop(vsy_Progress*
p,const Vchar* name);VKI_EXTERN void vsy_ProgressInterval(vsy_Progress*
p,Vint ipri,const Vchar* name,Vfloat weight,Vfloat sec);
VKI_EXTERN void vsy_ProgressPrimary(vsy_Progress* p,
Vint ipri);VKI_EXTERN void vsy_ProgressPrimaryName(vsy_Progress*
p,const Vchar* name);VKI_EXTERN void vsy_ProgressSecondary(vsy_Progress*
p,Vfloat sec);VKI_EXTERN void vsy_ProgressPercentDone(vsy_Progress*
p,Vfloat* percent);VKI_EXTERN void vsy_ProgressTime(vsy_Progress*
p,Vfloat* timespent,Vfloat* timetogo);VKI_EXTERN void
vsy_ProgressGetInteger(vsy_Progress* p,Vint type,Vint*
value);
#ifdef __cplusplus
}
#endif
#endif

