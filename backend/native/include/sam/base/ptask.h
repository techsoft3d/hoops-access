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
/* PTask object */

#ifndef PTASK_DEF
#define PTASK_DEF

#include "sam/base/basedefs.h"
#include "sam/base/vsy_threadpool.h"
#ifdef VKI_OS_WIN32
#include <windows.h>
#endif
/* mode definitions */
#define PTASK_SERIALMODE 1
/* def definitions */
#define PTASK_EXEC  1
#define PTASK_START 2

typedef struct {
    Vfunc1* func;
    Vobject* obj;
    void* athread;
} vsy_PTaskStartObj;

struct vsy_PTask {
    Vint ierr;
    Vint nproc;
    Vint serialmode;
    Vint isparallel;
    Vint type;
    Vint nfree;
    Vint maxids;
    Vint* freeid;
    Vchar* statusid;
    void* umutex;
    vsy_TaskID* ids;
    vsy_Thread_Pool tp;
    Vint queuestarted;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vsy_PTask(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vsy_PTask(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void Def(Vint, Vint);
    VKI_EXTERN void
    Inq(Vint*, Vint*) const;
    VKI_EXTERN void
    Exec(Vint, Vfunc1*, Vobject**);
    VKI_EXTERN void
    Start(Vfunc1*, Vobject*, Vint*);
    VKI_EXTERN void
    Lock();
    VKI_EXTERN void
    Unlock();
    VKI_EXTERN void Join(Vint);
    VKI_EXTERN void
    GetThreadId(Vint*);
    VKI_EXTERN void SetMode(Vint, Vint);
    VKI_EXTERN void
    GetMode(Vint, Vint*);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vsy_PTask*
vsy_PTaskBegin(void);
VKI_EXTERN void
vsy_PTask_Construct(vsy_PTask* p);
VKI_EXTERN void
vsy_PTaskEnd(vsy_PTask* p);
VKI_EXTERN void
vsy_PTask_Destruct(vsy_PTask* p);
VKI_EXTERN Vint
vsy_PTaskError(vsy_PTask* p);
VKI_EXTERN void
vsy_PTaskDef(vsy_PTask* p, Vint numthreads, Vint type);
VKI_EXTERN void
vsy_PTaskInq(const vsy_PTask* p, Vint* num, Vint* type);
VKI_EXTERN void
vsy_PTaskExec(vsy_PTask* p, Vint ntasks, Vfunc1* func, Vobject** data);
VKI_EXTERN void
vsy_PTaskStart(vsy_PTask* p, Vfunc1* func, Vobject* data, Vint* taskid);
VKI_EXTERN void
vsy_PTaskLock(vsy_PTask* p);
VKI_EXTERN void
vsy_PTaskUnlock(vsy_PTask* p);
VKI_EXTERN void
vsy_PTaskJoin(vsy_PTask* p, Vint taskid);
VKI_EXTERN void
vsy_PTaskGetThreadId(vsy_PTask* p, Vint* num);
VKI_EXTERN void
vsy_PTaskSetMode(vsy_PTask* p, Vint mode, Vint flag);
VKI_EXTERN void
vsy_PTaskGetMode(vsy_PTask* p, Vint mode, Vint* value);

#ifdef __cplusplus
}
#endif

#endif
