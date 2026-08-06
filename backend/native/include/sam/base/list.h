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
 
#ifndef LIST_DEF
#define LIST_DEF
#include "sam/base/basedefs.h"
#include "sam/base/concat.h"
struct vsy_List { Vint ierr;Vint maxelt;Vint vsize;
Vint iter;Vobject** vec;Vobject* undefined;vsy_Concat*
concat;
#ifdef __cplusplus
public: VKI_EXTERN vsy_List(void);VKI_EXTERN void* operator
new(size_t);VKI_EXTERN ~vsy_List(void);VKI_EXTERN void
operator delete(void*);VKI_EXTERN Vint Error();VKI_EXTERN
void Def(Vint);VKI_EXTERN void Inq(Vint*)const;VKI_EXTERN
void Count(Vint*)const;VKI_EXTERN void MaxIndex(Vint*)
const;VKI_EXTERN void AllIndices(Vint[])const;VKI_EXTERN
void Insert(Vint,Vobject*);VKI_EXTERN void InsertCopy(Vint,
Vint,Vobject*);VKI_EXTERN void Add(Vobject*,Vint*);
VKI_EXTERN void Append(Vobject*);VKI_EXTERN void Ref(Vint,
Vobject**)const;VKI_EXTERN void Remove(Vint);VKI_EXTERN
void Clear();VKI_EXTERN void Compact();VKI_EXTERN void
InitIter();VKI_EXTERN void NextIter(Vint*,Vobject**);
VKI_EXTERN void ForEach(Vfunc1*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_List* vsy_ListBegin(void);VKI_EXTERN
void vsy_List_Construct(vsy_List* p);VKI_EXTERN void
vsy_ListEnd(vsy_List* p);VKI_EXTERN void vsy_List_Destruct(vsy_List*
p);VKI_EXTERN Vint vsy_ListError(vsy_List* p);VKI_EXTERN
void vsy_ListDef(vsy_List* p,Vint numobj);VKI_EXTERN
void vsy_ListInq(const vsy_List* p,Vint* len);VKI_EXTERN
void vsy_ListCount(const vsy_List* p,Vint* num);VKI_EXTERN
void vsy_ListMaxIndex(const vsy_List* p,Vint* maxindex);
VKI_EXTERN void vsy_ListAllIndices(const vsy_List* p,
Vint allindices[]);VKI_EXTERN void vsy_ListInsert(vsy_List*
p,Vint index,Vobject* value);VKI_EXTERN void vsy_ListInsertCopy(vsy_List*
p,Vint key,Vint nb,Vobject* value);VKI_EXTERN void vsy_ListAdd(vsy_List*
p,Vobject* value,Vint* idx);VKI_EXTERN void vsy_ListAppend(vsy_List*
p,Vobject* value);VKI_EXTERN void vsy_ListRef(const
vsy_List* p,Vint index,Vobject** value);VKI_EXTERN void
vsy_ListRemove(vsy_List* p,Vint index);VKI_EXTERN void
vsy_ListClear(vsy_List* p);VKI_EXTERN void vsy_ListCompact(vsy_List*
p);VKI_EXTERN void vsy_ListInitIter(vsy_List* p);VKI_EXTERN
void vsy_ListNextIter(vsy_List* p,Vint* idx,Vobject**
value);VKI_EXTERN void vsy_ListForEach(vsy_List* p,
Vfunc1* func);
#ifdef __cplusplus
}
#endif
#endif

