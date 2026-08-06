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
 
#ifndef HEAP_DEF
#define HEAP_DEF
#include "sam/base/basedefs.h"
#define HEAP_MIN 0
#define HEAP_MAX 1
struct vsy_Heap { Vint ierr;Vint maxsize;Vint minmax;
Vint currentSize;Vdouble* storage;Vint* indices;Vint*
indpos;Vulong epsilonCountForComparison;
#ifdef __cplusplus
public: VKI_EXTERN vsy_Heap(void);VKI_EXTERN void* operator
new(size_t);VKI_EXTERN ~vsy_Heap(void);VKI_EXTERN void
operator delete(void*);VKI_EXTERN Vint Error();VKI_EXTERN
void Def(Vint,Vint);VKI_EXTERN void Inq(Vint*,Vint*);
VKI_EXTERN void Clear();VKI_EXTERN void Ref(Vint*,Vdouble*);
VKI_EXTERN void RefRemove(Vint*,Vdouble*);VKI_EXTERN
void Remove(Vint);VKI_EXTERN void Insert(Vint,Vdouble);
VKI_EXTERN void Lookup(Vint,Vdouble*);VKI_EXTERN void
Print();VKI_EXTERN void SetEpsilonCountForComparison(Vulong);
VKI_EXTERN void SetRelativeTolerance(Vdouble);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_Heap* vsy_HeapBegin(void);VKI_EXTERN
void vsy_Heap_Construct(vsy_Heap* p);VKI_EXTERN void
vsy_HeapEnd(vsy_Heap* p);VKI_EXTERN void vsy_Heap_Destruct(vsy_Heap*
p);VKI_EXTERN Vint vsy_HeapError(vsy_Heap* p);VKI_EXTERN
void vsy_HeapDef(vsy_Heap* p,Vint maxindex,Vint minmax);
VKI_EXTERN void vsy_HeapInq(vsy_Heap* p,Vint* nument,
Vint* minmax);VKI_EXTERN void vsy_HeapClear(vsy_Heap*
p);VKI_EXTERN void vsy_HeapRef(vsy_Heap* p,Vint* index,
Vdouble* val);VKI_EXTERN void vsy_HeapRefRemove(vsy_Heap*
p,Vint* index,Vdouble* val);VKI_EXTERN void vsy_HeapRemove(vsy_Heap*
p,Vint index);VKI_EXTERN void vsy_HeapInsert(vsy_Heap*
p,Vint index,Vdouble val);VKI_EXTERN void vsy_HeapLookup(vsy_Heap*
p,Vint index,Vdouble* val);VKI_EXTERN void vsy_HeapPrint(vsy_Heap*
p);VKI_EXTERN void vsy_HeapSetEpsilonCountForComparison(vsy_Heap*
p,Vulong epsilonCount);VKI_EXTERN void vsy_HeapSetRelativeTolerance(vsy_Heap*
p,Vdouble tolerance);
#ifdef __cplusplus
}
#endif
#endif

