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
 
#ifndef FLTVEC_DEF
#define FLTVEC_DEF
#include "sam/base/basedefs.h"
struct vsy_FltVec { Vint ierr;Vint staind;Vint maxind;
Vint maxelt;Vint iter;Vfloat* vec;Vfloat undefined;
#ifdef __cplusplus
public: VKI_EXTERN vsy_FltVec(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_FltVec(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void SetParami(Vint,Vint);VKI_EXTERN
void Count(Vint*)const;VKI_EXTERN void Set(Vint,Vfloat);
VKI_EXTERN void Sum(Vint,Vfloat);VKI_EXTERN void Append(Vfloat);
VKI_EXTERN void Get(Vint,Vfloat*)const;VKI_EXTERN void
Clear();VKI_EXTERN void GetPtr(Vfloat**);VKI_EXTERN
void InitIter();VKI_EXTERN void NextIter(Vint*,Vfloat*);
VKI_EXTERN void Match(vsy_FltVec*,Vint*);VKI_EXTERN
void Copy(vsy_FltVec*);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_FltVec* vsy_FltVecBegin(void);VKI_EXTERN
void vsy_FltVec_Construct(vsy_FltVec* p);VKI_EXTERN
void vsy_FltVecEnd(vsy_FltVec* p);VKI_EXTERN void vsy_FltVec_Destruct(vsy_FltVec*
p);VKI_EXTERN Vint vsy_FltVecError(vsy_FltVec* p);VKI_EXTERN
void vsy_FltVecDef(vsy_FltVec* p,Vint len);VKI_EXTERN
void vsy_FltVecInq(const vsy_FltVec* p,Vint* maxind);
VKI_EXTERN void vsy_FltVecSetParami(vsy_FltVec* p,Vint
type,Vint iparam);VKI_EXTERN void vsy_FltVecCount(const
vsy_FltVec* p,Vint* num);VKI_EXTERN void vsy_FltVecSet(vsy_FltVec*
p,Vint idx,Vfloat value);VKI_EXTERN void vsy_FltVecSum(vsy_FltVec*
p,Vint idx,Vfloat value);VKI_EXTERN void vsy_FltVecAppend(vsy_FltVec*
p,Vfloat value);VKI_EXTERN void vsy_FltVecGet(const
vsy_FltVec* p,Vint idx,Vfloat* value);VKI_EXTERN void
vsy_FltVecClear(vsy_FltVec* p);VKI_EXTERN void vsy_FltVecGetPtr(vsy_FltVec*
p,Vfloat** ptr);VKI_EXTERN void vsy_FltVecInitIter(vsy_FltVec*
p);VKI_EXTERN void vsy_FltVecNextIter(vsy_FltVec* p,
Vint* idx,Vfloat* value);VKI_EXTERN void vsy_FltVecMatch(vsy_FltVec*
p,vsy_FltVec* q,Vint* flag);VKI_EXTERN void vsy_FltVecCopy(vsy_FltVec*
p,vsy_FltVec* fromp);VKI_EXTERN void vsy_FltVecPrint(vsy_FltVec*
p);
#ifdef __cplusplus
}
#endif
#endif

