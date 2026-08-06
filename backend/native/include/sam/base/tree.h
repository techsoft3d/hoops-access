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
 
#ifndef TREE_DEF
#define TREE_DEF
#include "sam/base/basedefs.h"
#define TREE_FUNCTION_PRINT 1
typedef struct { Vint prev;Vint next;Vint parent;Vint
child;Vint brother;Vobject* value;}vsy_TreeNode;struct
vsy_Tree { Vint ierr;Vint numnode;Vint maxnode;Vint
headnode;vsy_TreeNode* node;
#ifdef __cplusplus
public: VKI_EXTERN vsy_Tree(void);VKI_EXTERN void* operator
new(size_t);VKI_EXTERN ~vsy_Tree(void);VKI_EXTERN void
operator delete(void*);VKI_EXTERN Vint Error();VKI_EXTERN
void AddNode(Vint,Vint*);VKI_EXTERN void DelNode(Vint);
VKI_EXTERN void FirstChild(Vint,Vint*);VKI_EXTERN void
NextChild(Vint,Vint*);VKI_EXTERN void SetValue(Vint,
Vobject*);VKI_EXTERN void GetValue(Vint,Vobject**);
VKI_EXTERN void Print();VKI_EXTERN void ForEach(Vfunc1*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_Tree* vsy_TreeBegin(void);VKI_EXTERN
void vsy_Tree_Construct(vsy_Tree* p);VKI_EXTERN void
vsy_TreeEnd(vsy_Tree* p);VKI_EXTERN void vsy_Tree_Destruct(vsy_Tree*
p);VKI_EXTERN Vint vsy_TreeError(vsy_Tree* p);VKI_EXTERN
void vsy_TreeAddNode(vsy_Tree* p,Vint pkey,Vint* ckey);
VKI_EXTERN void vsy_TreeDelNode(vsy_Tree* p,Vint key);
VKI_EXTERN void vsy_TreeFirstChild(vsy_Tree* p,Vint
pkey,Vint* child);VKI_EXTERN void vsy_TreeNextChild(vsy_Tree*
p,Vint ckey,Vint* child);VKI_EXTERN void vsy_TreeSetValue(vsy_Tree*
p,Vint key,Vobject* value);VKI_EXTERN void vsy_TreeGetValue(vsy_Tree*
p,Vint key,Vobject** value);VKI_EXTERN void vsy_TreePrint(vsy_Tree*
p);VKI_EXTERN void vsy_TreeForEach(vsy_Tree* p,Vfunc1*
func);
#ifdef __cplusplus
}
#endif
#endif

