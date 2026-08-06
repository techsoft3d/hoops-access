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
 
#ifndef INTSTACK_DEF
#define INTSTACK_DEF
#include "sam/base/basedefs.h"
struct vsy_IntStack { Vint ierr;Vint nument;Vint topent;
Vint* stack;Vint maxid;Vchar* cancel;
#ifdef __cplusplus
public: VKI_EXTERN vsy_IntStack(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_IntStack(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void Count(Vint*)const;VKI_EXTERN void
Push(Vint);VKI_EXTERN void Pop(Vint*);VKI_EXTERN void
Ref(Vint*)const;VKI_EXTERN void Clear();VKI_EXTERN void
Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_IntStack* vsy_IntStackBegin(void);VKI_EXTERN
void vsy_IntStack_Construct(vsy_IntStack* p);VKI_EXTERN
void vsy_IntStackEnd(vsy_IntStack* p);VKI_EXTERN void
vsy_IntStack_Destruct(vsy_IntStack* p);VKI_EXTERN Vint
vsy_IntStackError(vsy_IntStack* p);VKI_EXTERN void vsy_IntStackDef(vsy_IntStack*
p,Vint len);VKI_EXTERN void vsy_IntStackInq(const vsy_IntStack*
p,Vint* len);VKI_EXTERN void vsy_IntStackCount(const
vsy_IntStack* p,Vint* num);VKI_EXTERN void vsy_IntStackPush(vsy_IntStack*
p,Vint id);VKI_EXTERN void vsy_IntStackPop(vsy_IntStack*
p,Vint* id);VKI_EXTERN void vsy_IntStackRef(const vsy_IntStack*
p,Vint* id);VKI_EXTERN void vsy_IntStackClear(vsy_IntStack*
p);VKI_EXTERN void vsy_IntStackPrint(vsy_IntStack* p);
#ifdef __cplusplus
}
#endif
#endif

