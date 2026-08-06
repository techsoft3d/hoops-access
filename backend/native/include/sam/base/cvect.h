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
 
#ifndef CVECT_DEF
#define CVECT_DEF
#include "sam/base/basedefs.h"
#define CVECT_NUM 4
struct vsy_CVectEntry { struct vsy_CVectEntry* next;
Vint ix[CVECT_NUM];};typedef struct vsy_CVectEntry vsy_CVectEntry;
struct vsy_CVect { Vint ierr;Vint maxindex;Vint nblocks;
Vint nvec;Vint** nix;Vint max;Vlong* ptren;Vlong* ptrne;
Vint* en;Vint* ne;Vint maxnode;Vint minnode;vsy_CVectEntry*
m_free;vsy_CVectEntry** vec;vsy_CVectEntry** mem;
#ifdef __cplusplus
public: VKI_EXTERN vsy_CVect(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_CVect(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*);
VKI_EXTERN void Set(Vint,Vint,Vint[]);VKI_EXTERN void
SetOne(Vint,Vint,Vint);VKI_EXTERN void Replace(Vint,
Vint,Vint);VKI_EXTERN void Get(Vint,Vint,Vint[]);VKI_EXTERN
void GetNum(Vint,Vint*);VKI_EXTERN void GetAll(Vint,
Vint*,Vint[])const;VKI_EXTERN void GetInv(Vint,Vint*,
Vint[])const;VKI_EXTERN void GetOne(Vint,Vint,Vint*);
VKI_EXTERN void Append(Vint,Vint);VKI_EXTERN void Remove(Vint,
Vint,Vint*);VKI_EXTERN void Del(Vint);VKI_EXTERN void
Print();VKI_EXTERN void GetMax(Vint*);VKI_EXTERN void
Count(Vint*);VKI_EXTERN void Kernel(Vint);VKI_EXTERN
void PtrAll(Vint,Vint*,Vint**);VKI_EXTERN void PtrInv(Vint,
Vint*,Vint**);VKI_EXTERN void Match(vsy_CVect*,Vint*);
VKI_EXTERN void Copy(vsy_CVect*);VKI_EXTERN void Clear();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_CVect* vsy_CVectBegin(void);VKI_EXTERN
void vsy_CVect_Construct(vsy_CVect* p);VKI_EXTERN void
vsy_CVectEnd(vsy_CVect* p);VKI_EXTERN void vsy_CVect_Destruct(vsy_CVect*
p);VKI_EXTERN Vint vsy_CVectError(vsy_CVect* p);VKI_EXTERN
void vsy_CVectDef(vsy_CVect* p,Vint maxindex);VKI_EXTERN
void vsy_CVectInq(vsy_CVect* p,Vint* maxindex);VKI_EXTERN
void vsy_CVectSet(vsy_CVect* p,Vint index,Vint nix,
Vint ix[]);VKI_EXTERN void vsy_CVectSetOne(vsy_CVect*
p,Vint index,Vint no,Vint ix);VKI_EXTERN void vsy_CVectReplace(vsy_CVect*
p,Vint index,Vint no,Vint ix);VKI_EXTERN void vsy_CVectGet(vsy_CVect*
p,Vint index,Vint nix,Vint ix[]);VKI_EXTERN void vsy_CVectGetNum(vsy_CVect*
p,Vint index,Vint* nix);VKI_EXTERN void vsy_CVectGetAll(const
vsy_CVect* p,Vint index,Vint* nix,Vint ix[]);VKI_EXTERN
void vsy_CVectGetInv(const vsy_CVect* p,Vint index,
Vint* nix,Vint ix[]);VKI_EXTERN void vsy_CVectGetOne(vsy_CVect*
p,Vint index,Vint no,Vint* ix);VKI_EXTERN void vsy_CVectAppend(vsy_CVect*
p,Vint index,Vint id);VKI_EXTERN void vsy_CVectRemove(vsy_CVect*
p,Vint index,Vint id,Vint* flag);VKI_EXTERN void vsy_CVectDel(vsy_CVect*
p,Vint index);VKI_EXTERN void vsy_CVectPrint(vsy_CVect*
p);VKI_EXTERN void vsy_CVectGetMax(vsy_CVect* p,Vint*
max);VKI_EXTERN void vsy_CVectCount(vsy_CVect* p,Vint*
count);VKI_EXTERN void vsy_CVectKernel(vsy_CVect* p,
Vint flag);VKI_EXTERN void vsy_CVectPtrAll(vsy_CVect*
p,Vint index,Vint* nix,Vint** ix);VKI_EXTERN void vsy_CVectPtrInv(vsy_CVect*
p,Vint index,Vint* nix,Vint** ix);VKI_EXTERN void vsy_CVectMatch(vsy_CVect*
p,vsy_CVect* q,Vint* flag);VKI_EXTERN void vsy_CVectCopy(vsy_CVect*
p,vsy_CVect* q);VKI_EXTERN void vsy_CVectClear(vsy_CVect*
p);
#ifdef __cplusplus
}
#endif
#endif

