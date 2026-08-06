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
/* Timer object */

#ifndef TIMER_DEF
#define TIMER_DEF

#include "sam/base/basedefs.h"
#include "sam/base/dictionary.h"

#define TIMER_ECHO 1

typedef struct vsy_Timer_Ent {
    Vint nintervals;
    Vint running;
    Vfloat usrstatime;
    Vfloat sysstatime;
    Vfloat usrtottime;
    Vfloat systottime;
    Vlong elastatime;
    Vfloat elatottime;
} vsy_Timer_Ent;

struct vsy_Timer {
    Vint ierr;
    vsy_Dictionary* dict;
    Vint echoflag;
    Vlong elastatime;
    Vfloat elatottime;
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vsy_Timer*
vsy_TimerBegin(void);
VKI_EXTERN void
vsy_TimerEnd(vsy_Timer* p);
VKI_EXTERN Vint
vsy_TimerError(vsy_Timer* p);
VKI_EXTERN void
vsy_TimerDef(vsy_Timer* p, Vint numsec);
VKI_EXTERN void
vsy_TimerInq(const vsy_Timer* p, Vint* len);
VKI_EXTERN void
vsy_TimerSetParami(vsy_Timer* p, Vint type, Vint iparam);
VKI_EXTERN void
vsy_TimerStart(vsy_Timer* p, const Vchar* name);
VKI_EXTERN void
vsy_TimerStop(vsy_Timer* p, const Vchar* name);
VKI_EXTERN void
vsy_TimerInit(vsy_Timer* p, const Vchar* name);
VKI_EXTERN void
vsy_TimerEval(vsy_Timer* p, const Vchar* name, Vint* nintervals, Vint* running, Vfloat* usrtime, Vfloat* systime, Vfloat* elatime);
VKI_EXTERN void
vsy_TimerRemove(vsy_Timer* p, const Vchar* name);
VKI_EXTERN void
vsy_TimerClear(vsy_Timer* p);
VKI_EXTERN void
vsy_TimerInitIter(vsy_Timer* p);
VKI_EXTERN void
vsy_TimerNextIter(vsy_Timer* p, Vchar** name);
VKI_EXTERN void
vsy_TimerPrint(vsy_Timer* p);

#ifdef __cplusplus
}
#endif

#endif
