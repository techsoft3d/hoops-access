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
 
#ifndef HEAPIND_DEF
#define HEAPIND_DEF
#include "sam/base/basedefs.h"
struct vsy_HeapInd { Vint ierr;Vint maxsize;Vint minmax;
Vint currentSize;Vint maxind;Vint* storage;Vint* indices;
Vint* indpos;
#ifdef __cplusplus
public: VKI_EXTERN vsy_HeapInd(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_HeapInd(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(Vint,Vint);VKI_EXTERN void
Inq(Vint*,Vint*);VKI_EXTERN void Clear();VKI_EXTERN
void Ref(Vint*);VKI_EXTERN void RefRemove(Vint*);VKI_EXTERN
void Remove(Vint);VKI_EXTERN void Insert(Vint);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_HeapInd* vsy_HeapIndBegin(void);VKI_EXTERN
void vsy_HeapInd_Construct(vsy_HeapInd* p);VKI_EXTERN
void vsy_HeapIndEnd(vsy_HeapInd* p);VKI_EXTERN void
vsy_HeapInd_Destruct(vsy_HeapInd* p);VKI_EXTERN Vint
vsy_HeapIndError(vsy_HeapInd* p);VKI_EXTERN void vsy_HeapIndDef(vsy_HeapInd*
p,Vint nument,Vint minmax);VKI_EXTERN void vsy_HeapIndInq(vsy_HeapInd*
p,Vint* nument,Vint* minmax);VKI_EXTERN void vsy_HeapIndClear(vsy_HeapInd*
p);VKI_EXTERN void vsy_HeapIndRef(vsy_HeapInd* p,Vint*
value);VKI_EXTERN void vsy_HeapIndRefRemove(vsy_HeapInd*
p,Vint* value);VKI_EXTERN void vsy_HeapIndRemove(vsy_HeapInd*
p,Vint value);VKI_EXTERN void vsy_HeapIndInsert(vsy_HeapInd*
p,Vint value);
#ifdef __cplusplus
}
#endif
#endif

