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
 
#ifndef INTVHASH_DEF
#define INTVHASH_DEF
#define INTVHASH_EMPTY_SLOT 0
#define INTVHASH_TRASH_SLOT INT_MIN
#define INTVHASH_MIN_TABLE_SIZE 5
// Enum of hash function types available 
#define INTVHASH_HASH_FUNCTION_LEGACY 0
#define INTVHASH_HASH_FUNCTION_FNV1A 1
#include "sam/base/basedefs.h"
struct vsy_IntVHash { Vint ierr;Vint iter;Vint numelt;
Vint highwater;Vint vsize;Vint size;Vint* vec;Vint undefined;
Vint (*hashFunction)(const Vint*,const Vint*,Vint*);
#ifdef __cplusplus
public: VKI_EXTERN vsy_IntVHash(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_IntVHash(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void SetHashFunction(Vint);VKI_EXTERN
void Def(Vint,Vint);VKI_EXTERN void Inq(Vint*,Vint*)
const;VKI_EXTERN void Count(Vint*)const;VKI_EXTERN void
Insert(Vint[],Vint);VKI_EXTERN void InsertUndef(Vint[],
Vint,Vint*);VKI_EXTERN void Lookup(Vint[],Vint*)const;
VKI_EXTERN void Remove(Vint[]);VKI_EXTERN void Clear();
VKI_EXTERN void InitIter();VKI_EXTERN void NextIter(Vint*,
Vint*);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_IntVHash* vsy_IntVHashBegin(void);VKI_EXTERN
void vsy_IntVHash_Construct(vsy_IntVHash* p);VKI_EXTERN
void vsy_IntVHashEnd(vsy_IntVHash* p);VKI_EXTERN void
vsy_IntVHash_Destruct(vsy_IntVHash* p);VKI_EXTERN Vint
vsy_IntVHashError(vsy_IntVHash* p);VKI_EXTERN void vsy_IntVHashDef(vsy_IntVHash*
p,Vint size,Vint numint);VKI_EXTERN void vsy_IntVHashSetHashFunction(vsy_IntVHash*
p,Vint hashFunctionType);VKI_EXTERN void vsy_IntVHashSetDefaultHashFunction(Vint
hashFunctionType);VKI_EXTERN void vsy_IntVHashInq(const
vsy_IntVHash* p,Vint* size,Vint* nument);VKI_EXTERN
void vsy_IntVHashCount(const vsy_IntVHash* p,Vint* num);
VKI_EXTERN void vsy_IntVHashInsert(vsy_IntVHash* p,
Vint key[],Vint value);VKI_EXTERN void vsy_IntVHashInsertUndef(vsy_IntVHash*
p,Vint key[],Vint value,Vint* oldvalue);VKI_EXTERN void
vsy_IntVHashLookup(const vsy_IntVHash* p,Vint key[],
Vint* value);VKI_EXTERN void vsy_IntVHashRemove(vsy_IntVHash*
p,Vint key[]);VKI_EXTERN void vsy_IntVHashClear(vsy_IntVHash*
p);VKI_EXTERN void vsy_IntVHashInitIter(vsy_IntVHash*
p);VKI_EXTERN void vsy_IntVHashNextIter(vsy_IntVHash*
p,Vint* key,Vint* value);VKI_EXTERN void vsy_IntVHashPrint(vsy_IntVHash*
p);
#ifdef __cplusplus
}
#endif
#endif

