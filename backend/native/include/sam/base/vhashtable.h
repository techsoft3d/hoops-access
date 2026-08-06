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
 
#ifndef VHASHTABLE_DEF
#define VHASHTABLE_DEF
// Enum of hash function types available 
#define VHASHTABLE_HASH_FUNCTION_LEGACY 0
#define VHASHTABLE_HASH_FUNCTION_FNV1A 1
#include "sam/base/basedefs.h"
typedef struct _VHashTable_Entry { Vint key[3];union
{ Vint n;Vobject* v;}value;}vsy_VHashTable_Entry;struct
vsy_VHashTable { Vint ierr;Vint iter;Vint numelt;Vint
size;Vint highwater;Vint vsize;vsy_VHashTable_Entry*
vec;Vobject* undefined;Vint (*hashFunction)(const Vint*,
const Vint*,const Vint*);
#ifdef __cplusplus
public: VKI_EXTERN vsy_VHashTable(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_VHashTable(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(Vint,Vint);VKI_EXTERN void
SetHashFunction(Vint);VKI_EXTERN void Inq(Vint*,Vint*)
const;VKI_EXTERN void Count(Vint*)const;VKI_EXTERN void
Insert(const Vint*,Vobject*);VKI_EXTERN void Lookup(const
Vint*,Vobject**)const;VKI_EXTERN void Remove(const Vint*);
VKI_EXTERN void Clear();VKI_EXTERN void InitIter();
VKI_EXTERN void NextIter(Vint[],Vobject**);VKI_EXTERN
void ForEach(Vfunc1*);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_VHashTable* vsy_VHashTableBegin(void);
VKI_EXTERN void vsy_VHashTable_Construct(vsy_VHashTable*
p);VKI_EXTERN void vsy_VHashTableEnd(vsy_VHashTable*
p);VKI_EXTERN void vsy_VHashTable_Destruct(vsy_VHashTable*
p);VKI_EXTERN Vint vsy_VHashTableError(vsy_VHashTable*
p);VKI_EXTERN void vsy_VHashTableDef(vsy_VHashTable*
p,Vint size,Vint numobj);VKI_EXTERN void vsy_VHashTableSetHashFunction(vsy_VHashTable*
p,Vint hashFunctionType);VKI_EXTERN void vsy_VHashTableSetDefaultHashFunction(Vint
hashFunctionType);VKI_EXTERN void vsy_VHashTableInq(const
vsy_VHashTable* p,Vint* size,Vint* nument);VKI_EXTERN
void vsy_VHashTableCount(const vsy_VHashTable* p,Vint*
num);VKI_EXTERN void vsy_VHashTableInsert(vsy_VHashTable*
p,const Vint* key,Vobject* value);VKI_EXTERN void vsy_VHashTableLookup(const
vsy_VHashTable* p,const Vint* key,Vobject** value);
VKI_EXTERN void vsy_VHashTableRemove(vsy_VHashTable*
p,const Vint* key);VKI_EXTERN void vsy_VHashTableClear(vsy_VHashTable*
p);VKI_EXTERN void vsy_VHashTableInitIter(vsy_VHashTable*
p);VKI_EXTERN void vsy_VHashTableNextIter(vsy_VHashTable*
p,Vint key[],Vobject** value);VKI_EXTERN void vsy_VHashTableForEach(vsy_VHashTable*
p,Vfunc1* function);VKI_EXTERN void vsy_VHashTablePrint(vsy_VHashTable*
p);
#ifdef __cplusplus
}
#endif
#endif

