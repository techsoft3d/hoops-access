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
 
#ifndef INTDICT_DEF
#define INTDICT_DEF
#include "sam/base/basedefs.h"
#define INTEGER_DICTIONARY_MIN_STORAGE 128
typedef struct _IntDict_Entry { Vchar* name;Vint val;
}vsy_IntDict_Entry;struct vsy_IntDict { Vint ierr;Vint
iter;Vchar** csort;Vint* isort;Vint numelt;Vint highwater;
Vint vsize;vsy_IntDict_Entry* vec;Vint undefined;
#ifdef __cplusplus
public: VKI_EXTERN vsy_IntDict(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_IntDict(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void Count(Vint*)const;VKI_EXTERN void
Insert(const Vchar*,Vint);VKI_EXTERN void Lookup(const
Vchar*,Vint*)const;VKI_EXTERN void Clear();VKI_EXTERN
void InitIter();VKI_EXTERN void NextIter(Vchar**,Vint*);
VKI_EXTERN void InitIterOrder();VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_IntDict* vsy_IntDictBegin(void);VKI_EXTERN
void vsy_IntDict_Construct(vsy_IntDict* p);VKI_EXTERN
void vsy_IntDictEnd(vsy_IntDict* p);VKI_EXTERN void
vsy_IntDict_Destruct(vsy_IntDict* p);VKI_EXTERN Vint
vsy_IntDictError(vsy_IntDict* p);VKI_EXTERN void vsy_IntDictDef(vsy_IntDict*
p,Vint numint);VKI_EXTERN void vsy_IntDictInq(const
vsy_IntDict* p,Vint* nument);VKI_EXTERN void vsy_IntDictCount(const
vsy_IntDict* p,Vint* num);VKI_EXTERN void vsy_IntDictInsert(vsy_IntDict*
p,const Vchar* name,Vint value);VKI_EXTERN void vsy_IntDictLookup(const
vsy_IntDict* p,const Vchar* name,Vint* value);VKI_EXTERN
void vsy_IntDictClear(vsy_IntDict* p);VKI_EXTERN void
vsy_IntDictInitIter(vsy_IntDict* p);VKI_EXTERN void
vsy_IntDictNextIter(vsy_IntDict* p,Vchar** name,Vint*
value);VKI_EXTERN void vsy_IntDictInitIterOrder(vsy_IntDict*
p);VKI_EXTERN void vsy_IntDictPrint(vsy_IntDict* p);
#ifdef __cplusplus
}
#endif
#endif

