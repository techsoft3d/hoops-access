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
 
#ifndef STACK_DEF
#define STACK_DEF
#include "sam/base/basedefs.h"
struct vsy_Stack { Vint ierr;Vint top;Vint vsize;Vobject**
vec;
#ifdef __cplusplus
public: VKI_EXTERN vsy_Stack(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_Stack(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void Count(Vint*)const;VKI_EXTERN void
Push(Vobject*);VKI_EXTERN void Pop();VKI_EXTERN void
Ref(Vobject**)const;VKI_EXTERN void Clear();VKI_EXTERN
void Compact();VKI_EXTERN void ForEach(Vfunc1*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_Stack* vsy_StackBegin(void);VKI_EXTERN
void vsy_Stack_Construct(vsy_Stack* p);VKI_EXTERN void
vsy_StackEnd(vsy_Stack* p);VKI_EXTERN void vsy_Stack_Destruct(vsy_Stack*
p);VKI_EXTERN Vint vsy_StackError(vsy_Stack* p);VKI_EXTERN
void vsy_StackDef(vsy_Stack* p,Vint numobj);VKI_EXTERN
void vsy_StackInq(const vsy_Stack* p,Vint* len);VKI_EXTERN
void vsy_StackCount(const vsy_Stack* p,Vint* num);VKI_EXTERN
void vsy_StackPush(vsy_Stack* p,Vobject* value);VKI_EXTERN
void vsy_StackPop(vsy_Stack* p);VKI_EXTERN void vsy_StackRef(const
vsy_Stack* p,Vobject** value);VKI_EXTERN void vsy_StackClear(vsy_Stack*
p);VKI_EXTERN void vsy_StackCompact(vsy_Stack* p);VKI_EXTERN
void vsy_StackForEach(vsy_Stack* p,Vfunc1* func);
#ifdef __cplusplus
}
#endif
#endif

