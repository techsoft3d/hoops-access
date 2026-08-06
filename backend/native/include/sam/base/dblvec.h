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
 
#ifndef DBLVEC_DEF
#define DBLVEC_DEF
#include "sam/base/basedefs.h"
struct vsy_DblVec { Vint ierr;Vint staind;Vint maxind;
Vint maxelt;Vint iter;Vdouble* vec;Vdouble undefined;
#ifdef __cplusplus
public: VKI_EXTERN vsy_DblVec(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_DblVec(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void SetParami(Vint,Vint);VKI_EXTERN
void Count(Vint*)const;VKI_EXTERN void Set(Vint,Vdouble);
VKI_EXTERN void SetMult(Vint,Vint,Vdouble[]);VKI_EXTERN
void Sum(Vint,Vdouble);VKI_EXTERN void Append(Vdouble);
VKI_EXTERN void Get(Vint,Vdouble*)const;VKI_EXTERN void
GetMult(Vint,Vint,Vdouble[]);VKI_EXTERN void Clear();
VKI_EXTERN void GetPtr(Vdouble**);VKI_EXTERN void InitIter();
VKI_EXTERN void NextIter(Vint*,Vdouble*);VKI_EXTERN
void Match(vsy_DblVec*,Vint*);VKI_EXTERN void Copy(vsy_DblVec*);
VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_DblVec* vsy_DblVecBegin(void);VKI_EXTERN
void vsy_DblVec_Construct(vsy_DblVec* p);VKI_EXTERN
void vsy_DblVecEnd(vsy_DblVec* p);VKI_EXTERN void vsy_DblVec_Destruct(vsy_DblVec*
p);VKI_EXTERN Vint vsy_DblVecError(vsy_DblVec* p);VKI_EXTERN
void vsy_DblVecDef(vsy_DblVec* p,Vint maxindex);VKI_EXTERN
void vsy_DblVecInq(const vsy_DblVec* p,Vint* maxind);
VKI_EXTERN void vsy_DblVecSetParami(vsy_DblVec* p,Vint
ptype,Vint iparam);VKI_EXTERN void vsy_DblVecCount(const
vsy_DblVec* p,Vint* num);VKI_EXTERN void vsy_DblVecSet(vsy_DblVec*
p,Vint index,Vdouble value);VKI_EXTERN void vsy_DblVecSetMult(vsy_DblVec*
p,Vint num,Vint idx,Vdouble value[]);VKI_EXTERN void
vsy_DblVecSum(vsy_DblVec* p,Vint index,Vdouble value);
VKI_EXTERN void vsy_DblVecAppend(vsy_DblVec* p,Vdouble
value);VKI_EXTERN void vsy_DblVecGet(const vsy_DblVec*
p,Vint idx,Vdouble* value);VKI_EXTERN void vsy_DblVecGetMult(vsy_DblVec*
p,Vint num,Vint idx,Vdouble value[]);VKI_EXTERN void
vsy_DblVecClear(vsy_DblVec* p);VKI_EXTERN void vsy_DblVecGetPtr(vsy_DblVec*
p,Vdouble** ptr);VKI_EXTERN Vdouble* vsy_DblVecPtr(vsy_DblVec*
p);VKI_EXTERN void vsy_DblVecInitIter(vsy_DblVec* p);
VKI_EXTERN void vsy_DblVecNextIter(vsy_DblVec* p,Vint*
index,Vdouble* value);VKI_EXTERN void vsy_DblVecMatch(vsy_DblVec*
p,vsy_DblVec* dblvecm,Vint* flag);VKI_EXTERN void vsy_DblVecCopy(vsy_DblVec*
p,vsy_DblVec* fromp);VKI_EXTERN void vsy_DblVecPrint(vsy_DblVec*
p);
#ifdef __cplusplus
}
#endif
#endif

