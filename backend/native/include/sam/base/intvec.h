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
 
#ifndef INTVEC_DEF
#define INTVEC_DEF
#include "sam/base/basedefs.h"
struct vsy_IntVec { Vint ierr;Vint staind;Vint maxind;
Vint maxelt;Vint iter;Vint* vec;Vint undefined;
#ifdef __cplusplus
public: VKI_EXTERN vsy_IntVec(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_IntVec(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void SetParami(Vint,Vint);VKI_EXTERN
void Count(Vint*)const;VKI_EXTERN void Set(Vint,Vint);
VKI_EXTERN void Expand(Vint);VKI_EXTERN void Append(Vint);
VKI_EXTERN void Get(Vint,Vint*)const;VKI_EXTERN void
Inc(Vint,Vint);VKI_EXTERN void Clear();VKI_EXTERN void
GetPtr(Vint**);VKI_EXTERN void InitIter();VKI_EXTERN
void NextIter(Vint*,Vint*);VKI_EXTERN void Match(vsy_IntVec*,
Vint*);VKI_EXTERN void Copy(vsy_IntVec*);VKI_EXTERN
void Print();VKI_EXTERN void Unique(Vint);VKI_EXTERN
void GetStartingIndex(Vint*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_IntVec* vsy_IntVecBegin(void);VKI_EXTERN
void vsy_IntVec_Construct(vsy_IntVec* p);VKI_EXTERN
void vsy_IntVecEnd(vsy_IntVec* p);VKI_EXTERN void vsy_IntVec_Destruct(vsy_IntVec*
p);VKI_EXTERN Vint vsy_IntVecError(vsy_IntVec* p);VKI_EXTERN
void vsy_IntVecDef(vsy_IntVec* p,Vint maxindex);VKI_EXTERN
void vsy_IntVecInq(const vsy_IntVec* p,Vint* maxind);
VKI_EXTERN void vsy_IntVecSetParami(vsy_IntVec* p,Vint
ptype,Vint iparam);VKI_EXTERN void vsy_IntVecCount(const
vsy_IntVec* p,Vint* num);VKI_EXTERN void vsy_IntVecSet(vsy_IntVec*
p,Vint index,Vint value);VKI_EXTERN void vsy_IntVecExpand(vsy_IntVec*
p,Vint idx);VKI_EXTERN void vsy_IntVecAppend(vsy_IntVec*
p,Vint value);VKI_EXTERN void vsy_IntVecGet(const vsy_IntVec*
p,Vint idx,Vint* value);VKI_EXTERN void vsy_IntVecInc(vsy_IntVec*
p,Vint idx,Vint value);VKI_EXTERN void vsy_IntVecClear(vsy_IntVec*
p);VKI_EXTERN void vsy_IntVecGetPtr(vsy_IntVec* p,Vint**
ptr);VKI_EXTERN Vint* vsy_IntVecPtr(vsy_IntVec* p);
VKI_EXTERN void vsy_IntVecInitIter(vsy_IntVec* p);VKI_EXTERN
void vsy_IntVecNextIter(vsy_IntVec* p,Vint* index,Vint*
value);VKI_EXTERN void vsy_IntVecMatch(vsy_IntVec* p,
vsy_IntVec* intvecm,Vint* flag);VKI_EXTERN void vsy_IntVecCopy(vsy_IntVec*
p,vsy_IntVec* fromp);VKI_EXTERN void vsy_IntVecPrint(vsy_IntVec*
p);VKI_EXTERN void vsy_IntVecUnique(vsy_IntVec* p,Vint
value);VKI_EXTERN void vsy_IntVecGetStartingIndex(vsy_IntVec*
p,Vint* index);
#ifdef __cplusplus
}
#endif
#define VSY_IntVecSet(x,a,b) {  (x)->vec[(a)] = (b);\
 (x)->maxind = MAX2((x)->maxind,(a)); }
#define VSY_IntVecGet(x,a)(x)->vec[(a)]
#endif

