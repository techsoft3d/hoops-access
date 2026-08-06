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
 
#ifndef CONCAT_DEF
#define CONCAT_DEF
#include "sam/base/basedefs.h"
#define CONCAT_ITER 1
typedef struct vsy_Concat_Block vsy_Concat_Block;struct
vsy_Concat_Block { vsy_Concat_Block* prev;vsy_Concat_Block*
next;Vint datasize;Vint datacurr;Vchar* data;};struct
vsy_Concat { Vint ierr;vsy_Concat_Block* initaddr;vsy_Concat_Block*
blocaddr;Vint numblocks;Vint numitems;Vlong numsize;
Vchar* currptr;Vint initsize;Vint currsize;Vint mallocerr;
Vint iterflag;vsy_Concat_Block* iteraddr;Vint iterdata;
#ifdef __cplusplus
public: VKI_EXTERN vsy_Concat(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_Concat(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vlong);VKI_EXTERN void Inq(Vlong*)
const;VKI_EXTERN void Count(Vint*)const;VKI_EXTERN void
Mem(Vint,void**);VKI_EXTERN void Add(Vint,void*);VKI_EXTERN
void Ref(void**)const;VKI_EXTERN void SetParami(Vint,
Vint);VKI_EXTERN void Clear();VKI_EXTERN void InitIter();
VKI_EXTERN void NextIter(Vint*,void**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_Concat* vsy_ConcatBegin(void);VKI_EXTERN
void vsy_Concat_Construct(vsy_Concat* p);VKI_EXTERN
void vsy_ConcatEnd(vsy_Concat* p);VKI_EXTERN void vsy_Concat_Destruct(vsy_Concat*
p);VKI_EXTERN Vint vsy_ConcatError(vsy_Concat* p);VKI_EXTERN
void vsy_ConcatDef(vsy_Concat* p,Vlong maxbytes);VKI_EXTERN
void vsy_ConcatInq(const vsy_Concat* p,Vlong* len);
VKI_EXTERN void vsy_ConcatCount(const vsy_Concat* p,
Vint* num);VKI_EXTERN void vsy_ConcatMem(vsy_Concat*
p,Vint nbytes,void** data);VKI_EXTERN void vsy_ConcatAdd(vsy_Concat*
p,Vint nbytes,void* data);VKI_EXTERN void vsy_ConcatRef(const
vsy_Concat* p,void** data);VKI_EXTERN void vsy_ConcatSetParami(vsy_Concat*
p,Vint type,Vint ivalue);VKI_EXTERN void vsy_ConcatClear(vsy_Concat*
p);VKI_EXTERN void vsy_ConcatInitIter(vsy_Concat* p);
VKI_EXTERN void vsy_ConcatNextIter(vsy_Concat* p,Vint*
nbytes,void** data);
#ifdef __cplusplus
}
#endif
#endif

