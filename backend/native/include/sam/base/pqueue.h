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
 
#ifndef PQUEUE_DEF
#define PQUEUE_DEF
#include "sam/base/basedefs.h"
typedef struct vsy_PQueue_Ent vsy_PQueue_Ent;struct
vsy_PQueue_Ent { Vdouble val;Vint bin;Vint prev;Vint
next;};struct vsy_PQueue { Vint ierr;Vint nument;Vint
maxent;Vdouble binmin,binmax;Vdouble binfac;Vint totent;
vsy_PQueue_Ent* ent;Vint* headbin;Vint* numbin;Vint
numacc;Vint minbin,maxbin;
#ifdef __cplusplus
public: VKI_EXTERN vsy_PQueue(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_PQueue(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint,Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void Range(Vdouble,Vdouble);VKI_EXTERN
void Insert(Vint,Vdouble);VKI_EXTERN void MinMax(Vint,
Vint*,Vdouble*);VKI_EXTERN void Remove(Vint);VKI_EXTERN
void Lookup(Vint,Vdouble*);VKI_EXTERN void Num(Vint*);
VKI_EXTERN void Clear();VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_PQueue* vsy_PQueueBegin(void);VKI_EXTERN
void vsy_PQueue_Construct(vsy_PQueue* p);VKI_EXTERN
void vsy_PQueueEnd(vsy_PQueue* p);VKI_EXTERN void vsy_PQueue_Destruct(vsy_PQueue*
p);VKI_EXTERN Vint vsy_PQueueError(vsy_PQueue* p);VKI_EXTERN
void vsy_PQueueDef(vsy_PQueue* p,Vint maxindex,Vint
numacc);VKI_EXTERN void vsy_PQueueInq(const vsy_PQueue*
p,Vint* maxindex);VKI_EXTERN void vsy_PQueueRange(vsy_PQueue*
p,Vdouble minval,Vdouble maxval);VKI_EXTERN void vsy_PQueueInsert(vsy_PQueue*
p,Vint index,Vdouble val);VKI_EXTERN void vsy_PQueueMinMax(vsy_PQueue*
p,Vint minmax,Vint* index,Vdouble* val);VKI_EXTERN void
vsy_PQueueRemove(vsy_PQueue* p,Vint index);VKI_EXTERN
void vsy_PQueueLookup(vsy_PQueue* p,Vint index,Vdouble*
val);VKI_EXTERN void vsy_PQueueNum(vsy_PQueue* p,Vint*
num);VKI_EXTERN void vsy_PQueueClear(vsy_PQueue* p);
VKI_EXTERN void vsy_PQueuePrint(vsy_PQueue* p);
#ifdef __cplusplus
}
#endif
#endif

