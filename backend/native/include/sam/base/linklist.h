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
 
#ifndef LINKLIST_DEF
#define LINKLIST_DEF
#include "sam/base/basedefs.h"
typedef struct vsy_LinkList_Node vsy_LinkList_Node;
struct vsy_LinkList_Node { Vint prev;Vint next;Vint
inuse;void* obj;};struct vsy_LinkList { Vint ierr;Vint
maxnode;Vint nbytes;Vint lenent;Vint iter;Vdouble**
node;vsy_Concat* concat;Vint freenode;Vint headnode;
#ifdef __cplusplus
public: VKI_EXTERN vsy_LinkList(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_LinkList(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(Vint,Vint);VKI_EXTERN void
Inq(Vint*,Vint*)const;VKI_EXTERN void Count(Vint*)const;
VKI_EXTERN void Add(Vint*,Vobject**);VKI_EXTERN void
Ref(Vint,Vobject**)const;VKI_EXTERN void Remove(Vint);
VKI_EXTERN void Init();VKI_EXTERN void Clear();VKI_EXTERN
void Head(Vint*,Vobject**);VKI_EXTERN void InitIter();
VKI_EXTERN void NextIter(Vint*,Vobject**);VKI_EXTERN
void ForEach(Vfunc1*);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_LinkList* vsy_LinkListBegin(void);VKI_EXTERN
void vsy_LinkList_Construct(vsy_LinkList* p);VKI_EXTERN
void vsy_LinkListEnd(vsy_LinkList* p);VKI_EXTERN void
vsy_LinkList_Destruct(vsy_LinkList* p);VKI_EXTERN Vint
vsy_LinkListError(vsy_LinkList* p);VKI_EXTERN void vsy_LinkListDef(vsy_LinkList*
p,Vint len,Vint nbytes);VKI_EXTERN void vsy_LinkListInq(const
vsy_LinkList* p,Vint* len,Vint* nbytes);VKI_EXTERN void
vsy_LinkListCount(const vsy_LinkList* p,Vint* num);
VKI_EXTERN void vsy_LinkListAdd(vsy_LinkList* p,Vint*
index,Vobject** value);VKI_EXTERN void vsy_LinkListRef(const
vsy_LinkList* p,Vint index,Vobject** value);VKI_EXTERN
void vsy_LinkListRemove(vsy_LinkList* p,Vint index);
VKI_EXTERN void vsy_LinkListInit(vsy_LinkList* p);VKI_EXTERN
void vsy_LinkListClear(vsy_LinkList* p);VKI_EXTERN void
vsy_LinkListHead(vsy_LinkList* p,Vint* index,Vobject**
value);VKI_EXTERN void vsy_LinkListInitIter(vsy_LinkList*
p);VKI_EXTERN void vsy_LinkListNextIter(vsy_LinkList*
p,Vint* index,Vobject** value);VKI_EXTERN void vsy_LinkListForEach(vsy_LinkList*
p,Vfunc1* function);VKI_EXTERN void vsy_LinkListPrint(vsy_LinkList*
p);
#ifdef __cplusplus
}
#endif
#define VSY_LinkListRef(x,a,b)*(b)= &(((vsy_LinkList_Node*)(x)->node[(a)])->obj)
#endif

