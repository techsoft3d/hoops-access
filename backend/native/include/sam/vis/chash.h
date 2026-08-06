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
 
#ifndef CHASH_DEF
#define CHASH_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
struct vis_CHashEntry { struct vis_CHashEntry* next;
Vint no;Vint aid;};typedef struct vis_CHashEntry vis_CHashEntry;
struct vis_CHash { Vint ierr;Vint maxindex;Vint nblocks;
Vint nvec;Vint** nix;vis_CHashEntry* m_free;vis_CHashEntry**
mem;vsy_HashTable* ht;
#ifdef __cplusplus
public: VKI_EXTERN vis_CHash(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_CHash(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Set(Vint,Vint,Vint);VKI_EXTERN void
Get(Vint,Vint,Vint*);VKI_EXTERN void Add(Vint,Vint,
Vint);VKI_EXTERN void Uni(Vint,Vint,Vint);VKI_EXTERN
void Num(Vint,Vint,Vint*);VKI_EXTERN void All(Vint,
Vint,Vint*,Vint[]);VKI_EXTERN void Del(Vint,Vint);VKI_EXTERN
void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_CHash* vis_CHashBegin(void);VKI_EXTERN
void vis_CHash_Construct(vis_CHash* p);VKI_EXTERN void
vis_CHashEnd(vis_CHash* p);VKI_EXTERN void vis_CHash_Destruct(vis_CHash*
p);VKI_EXTERN Vint vis_CHashError(vis_CHash* p);VKI_EXTERN
void vis_CHashSet(vis_CHash* p,Vint index,Vint no,Vint
aid);VKI_EXTERN void vis_CHashGet(vis_CHash* p,Vint
index,Vint no,Vint* aid);VKI_EXTERN void vis_CHashAdd(vis_CHash*
p,Vint index,Vint no,Vint aid);VKI_EXTERN void vis_CHashUni(vis_CHash*
p,Vint index,Vint no,Vint aid);VKI_EXTERN void vis_CHashNum(vis_CHash*
p,Vint index,Vint no,Vint* num);VKI_EXTERN void vis_CHashAll(vis_CHash*
p,Vint index,Vint no,Vint* num,Vint aids[]);VKI_EXTERN
void vis_CHashDel(vis_CHash* p,Vint index,Vint no);
VKI_EXTERN void vis_CHashPrint(vis_CHash* p);
#ifdef __cplusplus
}
#endif
#endif

