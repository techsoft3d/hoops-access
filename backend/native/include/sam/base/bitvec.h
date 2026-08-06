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
 
#ifndef BITVEC_DEF
#define BITVEC_DEF
#include "sam/base/basedefs.h"
#define BITVEC_SET 1
#define BITVEC_AND 2
#define BITVEC_OR 3
#define BITVEC_XOR 4
struct vsy_BitVec { Vint ierr;Vint staind;Vint maxind;
Vint maxelt;Vint vsize;Vint iter;Vuchar* vec;Vint undefined;
#ifdef __cplusplus
public: VKI_EXTERN vsy_BitVec(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_BitVec(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void SetParami(Vint,Vint);VKI_EXTERN
void Count(Vint*)const;VKI_EXTERN void Vector(Vint[])
const;VKI_EXTERN void Set(Vint,Vint);VKI_EXTERN void
Get(Vint,Vint*)const;VKI_EXTERN void Clear();VKI_EXTERN
void Complement();VKI_EXTERN void Boolean(Vint,vsy_BitVec*);
VKI_EXTERN void InitIter();VKI_EXTERN void NextIter(Vint*);
VKI_EXTERN void Match(vsy_BitVec*,Vint*);VKI_EXTERN
void Copy(vsy_BitVec*);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_BitVec* vsy_BitVecBegin(void);VKI_EXTERN
void vsy_BitVec_Construct(vsy_BitVec* p);VKI_EXTERN
void vsy_BitVecEnd(vsy_BitVec* p);VKI_EXTERN void vsy_BitVec_Destruct(vsy_BitVec*
p);VKI_EXTERN Vint vsy_BitVecError(vsy_BitVec* p);VKI_EXTERN
void vsy_BitVecDef(vsy_BitVec* p,Vint maxindex);VKI_EXTERN
void vsy_BitVecInq(const vsy_BitVec* p,Vint* len);VKI_EXTERN
void vsy_BitVecSetParami(vsy_BitVec* p,Vint ptype,Vint
iparam);VKI_EXTERN void vsy_BitVecCount(const vsy_BitVec*
p,Vint* num);VKI_EXTERN void vsy_BitVecVector(const
vsy_BitVec* p,Vint vec[]);VKI_EXTERN void vsy_BitVecSet(vsy_BitVec*
p,Vint index,Vint value);VKI_EXTERN void vsy_BitVecGet(const
vsy_BitVec* p,Vint idx,Vint* value);VKI_EXTERN void
vsy_BitVecClear(vsy_BitVec* p);VKI_EXTERN void vsy_BitVecComplement(vsy_BitVec*
p);VKI_EXTERN void vsy_BitVecBoolean(vsy_BitVec* p,
Vint oper,vsy_BitVec* bitvecsrc);VKI_EXTERN void vsy_BitVecInitIter(vsy_BitVec*
p);VKI_EXTERN void vsy_BitVecNextIter(vsy_BitVec* p,
Vint* index);VKI_EXTERN void vsy_BitVecMatch(vsy_BitVec*
p,vsy_BitVec* bitvecm,Vint* flag);VKI_EXTERN void vsy_BitVecCopy(vsy_BitVec*
p,vsy_BitVec* fromp);VKI_EXTERN void vsy_BitVecPrint(vsy_BitVec*
p);
#ifdef __cplusplus
}
#endif
#endif

