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
 
#ifndef INTHASH_DEF
#define INTHASH_DEF
#include "sam/base/basedefs.h"
typedef struct _IntHash_Entry { Vint key;Vint val;}
vsy_IntHash_Entry;struct vsy_IntHash { Vint ierr;Vint
iter;Vint numsrt;Vint *isort,*jsort;Vint numelt;Vint
highwater;Vint vsize;vsy_IntHash_Entry* vec;Vint undefined;
Vint lowempty;Vint maxkey;Vchar* name;
#ifdef __cplusplus
public: VKI_EXTERN vsy_IntHash(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_IntHash(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void Count(Vint*)const;VKI_EXTERN void
MaxKey(Vint*);VKI_EXTERN void AllKeys(Vint[])const;
VKI_EXTERN void EmptyKey(Vint*);VKI_EXTERN void Insert(Vint,
Vint);VKI_EXTERN void InsertUndef(Vint,Vint,Vint*);
VKI_EXTERN void Lookup(Vint,Vint*)const;VKI_EXTERN void
Clear();VKI_EXTERN void SetName(const Vchar*);VKI_EXTERN
void GetName(Vchar[]);VKI_EXTERN void InitIter();VKI_EXTERN
void InitIterOrder();VKI_EXTERN void NextIter(Vint*,
Vint*);VKI_EXTERN void Print();VKI_EXTERN void SetParami(Vint,
Vint);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_IntHash* vsy_IntHashBegin(void);VKI_EXTERN
void vsy_IntHash_Construct(vsy_IntHash* p);VKI_EXTERN
void vsy_IntHashEnd(vsy_IntHash* p);VKI_EXTERN void
vsy_IntHash_Destruct(vsy_IntHash* p);VKI_EXTERN Vint
vsy_IntHashError(vsy_IntHash* p);VKI_EXTERN void vsy_IntHashDef(vsy_IntHash*
p,Vint numint);VKI_EXTERN void vsy_IntHashInq(const
vsy_IntHash* p,Vint* nument);VKI_EXTERN void vsy_IntHashCount(const
vsy_IntHash* p,Vint* num);VKI_EXTERN void vsy_IntHashMaxKey(vsy_IntHash*
p,Vint* maxkey);VKI_EXTERN void vsy_IntHashAllKeys(const
vsy_IntHash* p,Vint allkeys[]);VKI_EXTERN void vsy_IntHashEmptyKey(vsy_IntHash*
p,Vint* key);VKI_EXTERN void vsy_IntHashInsert(vsy_IntHash*
p,Vint key,Vint value);VKI_EXTERN void vsy_IntHashInsertUndef(vsy_IntHash*
p,Vint key,Vint value,Vint* oldvalue);VKI_EXTERN void
vsy_IntHashLookup(const vsy_IntHash* p,Vint key,Vint*
value);VKI_EXTERN void vsy_IntHashClear(vsy_IntHash*
p);VKI_EXTERN void vsy_IntHashSetName(vsy_IntHash* p,
const Vchar* name);VKI_EXTERN void vsy_IntHashGetName(vsy_IntHash*
p,Vchar name[]);VKI_EXTERN void vsy_IntHashInitIter(vsy_IntHash*
p);VKI_EXTERN void vsy_IntHashInitIterOrder(vsy_IntHash*
p);VKI_EXTERN void vsy_IntHashNextIter(vsy_IntHash*
p,Vint* key,Vint* value);VKI_EXTERN void vsy_IntHashPrint(vsy_IntHash*
p);VKI_EXTERN void vsy_IntHashSetParami(vsy_IntHash*
p,Vint type,Vint iparam);
#ifdef __cplusplus
}
#endif
#endif

