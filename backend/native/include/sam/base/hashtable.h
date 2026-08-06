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
 
#ifndef HASHTABLE_DEF
#define HASHTABLE_DEF
#include "sam/base/basedefs.h"
typedef struct _HashTable_Entry { Vint key;union { Vint
n;Vobject* v;}value;}vsy_HashTable_Entry;struct vsy_HashTable
{ Vint ierr;Vint iter;Vint numsrt;Vint *isort,*jsort;
Vint numelt;Vint highwater;Vint vsize;Vint havezero;
Vobject* zeroval;vsy_HashTable_Entry* vec;Vobject* undefined;
#ifdef __cplusplus
public: VKI_EXTERN vsy_HashTable(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_HashTable(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void Count(Vint*)const;VKI_EXTERN void
MaxKey(Vint*)const;VKI_EXTERN void AllKeys(Vint[])const;
VKI_EXTERN void Insert(Vint,Vobject*);VKI_EXTERN void
Lookup(Vint,Vobject**)const;VKI_EXTERN void Remove(Vint);
VKI_EXTERN void Clear();VKI_EXTERN void InitIter();
VKI_EXTERN void InitIterOrder();VKI_EXTERN void NextIter(Vint*,
Vobject**);VKI_EXTERN void ForEach(Vfunc1*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_HashTable* vsy_HashTableBegin(void);
VKI_EXTERN void vsy_HashTable_Construct(vsy_HashTable*
p);VKI_EXTERN void vsy_HashTableEnd(vsy_HashTable* p);
VKI_EXTERN void vsy_HashTable_Destruct(vsy_HashTable*
p);VKI_EXTERN Vint vsy_HashTableError(vsy_HashTable*
p);VKI_EXTERN void vsy_HashTableDef(vsy_HashTable* p,
Vint numobj);VKI_EXTERN void vsy_HashTableInq(const
vsy_HashTable* p,Vint* nument);VKI_EXTERN void vsy_HashTableCount(const
vsy_HashTable* p,Vint* num);VKI_EXTERN void vsy_HashTableMaxKey(const
vsy_HashTable* p,Vint* maxkey);VKI_EXTERN void vsy_HashTableAllKeys(const
vsy_HashTable* p,Vint allkeys[]);VKI_EXTERN void vsy_HashTableInsert(vsy_HashTable*
p,Vint key,Vobject* value);VKI_EXTERN void vsy_HashTableLookup(const
vsy_HashTable* p,Vint key,Vobject** value);VKI_EXTERN
void vsy_HashTableRemove(vsy_HashTable* p,Vint key);
VKI_EXTERN void vsy_HashTableClear(vsy_HashTable* p);
VKI_EXTERN void vsy_HashTableInitIter(vsy_HashTable*
p);VKI_EXTERN void vsy_HashTableInitIterOrder(vsy_HashTable*
p);VKI_EXTERN void vsy_HashTableNextIter(vsy_HashTable*
p,Vint* key,Vobject** value);VKI_EXTERN void vsy_HashTableForEach(vsy_HashTable*
p,Vfunc1* func);
#ifdef __cplusplus
}
#endif
#endif

