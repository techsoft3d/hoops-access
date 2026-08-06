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
 
#ifndef DICTIONARY_DEF
#define DICTIONARY_DEF
#include "sam/base/basedefs.h"
#define DICTIONARY_IGNORECASE 2
#define DICTIONARY_MIN_STORAGE 128
typedef struct _Dictionary_Entry { Vchar* name;union
{ Vint n;Vobject* v;}value;}vsy_Dictionary_Entry;struct
vsy_Dictionary { Vint ierr;Vint iter;Vint ignorecase;
Vchar** csort;Vint* isort;Vint numelt;Vint highwater;
Vint vsize;vsy_Dictionary_Entry* vec;Vobject* undefined;
#ifdef __cplusplus
public: VKI_EXTERN vsy_Dictionary(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_Dictionary(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void SetParami(Vint,Vint);VKI_EXTERN
void Count(Vint*)const;VKI_EXTERN void Insert(const
Vchar*,Vobject*);VKI_EXTERN void Lookup(const Vchar*,
Vobject**)const;VKI_EXTERN void Remove(const Vchar*);
VKI_EXTERN void Clear();VKI_EXTERN void MaxNameChar(Vint*);
VKI_EXTERN void InitIter();VKI_EXTERN void NextIter(Vchar**,
Vobject**);VKI_EXTERN void InitIterOrder();VKI_EXTERN
void ForEach(Vfunc1*);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_Dictionary* vsy_DictionaryBegin(void);
VKI_EXTERN void vsy_Dictionary_Construct(vsy_Dictionary*
p);VKI_EXTERN void vsy_DictionaryEnd(vsy_Dictionary*
p);VKI_EXTERN void vsy_Dictionary_Destruct(vsy_Dictionary*
p);VKI_EXTERN Vint vsy_DictionaryError(vsy_Dictionary*
p);VKI_EXTERN void vsy_DictionaryDef(vsy_Dictionary*
p,Vint numobj);VKI_EXTERN void vsy_DictionaryInq(const
vsy_Dictionary* p,Vint* nument);VKI_EXTERN void vsy_DictionarySetParami(vsy_Dictionary*
p,Vint type,Vint iparam);VKI_EXTERN void vsy_DictionaryCount(const
vsy_Dictionary* p,Vint* num);VKI_EXTERN void vsy_DictionaryInsert(vsy_Dictionary*
p,const Vchar* name,Vobject* value);VKI_EXTERN void
vsy_DictionaryLookup(const vsy_Dictionary* p,const Vchar*
name,Vobject** value);VKI_EXTERN void vsy_DictionaryRemove(vsy_Dictionary*
p,const Vchar* name);VKI_EXTERN void vsy_DictionaryClear(vsy_Dictionary*
p);VKI_EXTERN void vsy_DictionaryMaxNameChar(vsy_Dictionary*
p,Vint* maxnamechar);VKI_EXTERN void vsy_DictionaryInitIter(vsy_Dictionary*
p);VKI_EXTERN void vsy_DictionaryNextIter(vsy_Dictionary*
p,Vchar** name,Vobject** value);VKI_EXTERN void vsy_DictionaryInitIterOrder(vsy_Dictionary*
p);VKI_EXTERN void vsy_DictionaryForEach(vsy_Dictionary*
p,Vfunc1* func);VKI_EXTERN void vsy_DictionaryPrint(vsy_Dictionary*
p);
#ifdef __cplusplus
}
#endif
#endif

