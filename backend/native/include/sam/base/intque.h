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
 
#ifndef INTQUE_DEF
#define INTQUE_DEF
#include "sam/base/basedefs.h"
struct vsy_IntQue { Vint ierr;Vint head;Vint tail;Vint
empty;Vint vsize;Vint* vec;
#ifdef __cplusplus
public: VKI_EXTERN vsy_IntQue(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_IntQue(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void Count(Vint*)const;VKI_EXTERN void
Put(Vint);VKI_EXTERN void Ref(Vint*)const;VKI_EXTERN
void Get(Vint*);VKI_EXTERN void Clear();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_IntQue* vsy_IntQueBegin(void);VKI_EXTERN
void vsy_IntQue_Construct(vsy_IntQue* p);VKI_EXTERN
void vsy_IntQueEnd(vsy_IntQue* p);VKI_EXTERN void vsy_IntQue_Destruct(vsy_IntQue*
p);VKI_EXTERN Vint vsy_IntQueError(vsy_IntQue* p);VKI_EXTERN
void vsy_IntQueDef(vsy_IntQue* p,Vint numint);VKI_EXTERN
void vsy_IntQueInq(const vsy_IntQue* p,Vint* nument);
VKI_EXTERN void vsy_IntQueCount(const vsy_IntQue* p,
Vint* num);VKI_EXTERN void vsy_IntQuePut(vsy_IntQue*
p,Vint value);VKI_EXTERN void vsy_IntQueRef(const vsy_IntQue*
p,Vint* value);VKI_EXTERN void vsy_IntQueGet(vsy_IntQue*
p,Vint* value);VKI_EXTERN void vsy_IntQueClear(vsy_IntQue*
p);
#ifdef __cplusplus
}
#endif
#endif

