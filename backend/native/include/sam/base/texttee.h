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
 
#ifndef TEXTTEE_DEF
#define TEXTTEE_DEF
#include "sam/base/basedefs.h"
#include "sam/base/textfun.h"
#define VSY_TEXTTEE_MAX 8
struct vsy_TextTee { Vint ierr;Vint max;Vint handleerr;
vsy_TextFun* tf[VSY_TEXTTEE_MAX];
#ifdef __cplusplus
public: VKI_EXTERN vsy_TextTee(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_TextTee(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void SetObject(Vint,Vobject*);VKI_EXTERN
void TextFun(vsy_TextFun*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_TextTee* vsy_TextTeeBegin(void);VKI_EXTERN
void vsy_TextTee_Construct(vsy_TextTee* p);VKI_EXTERN
void vsy_TextTeeEnd(vsy_TextTee* p);VKI_EXTERN void
vsy_TextTee_Destruct(vsy_TextTee* p);VKI_EXTERN Vint
vsy_TextTeeError(vsy_TextTee* p);VKI_EXTERN void vsy_TextTeeSetObject(vsy_TextTee*
p,Vint objecttype,Vobject* object);VKI_EXTERN void vsy_TextTeeTextFun(vsy_TextTee*
p,vsy_TextFun* textfun);
#ifdef __cplusplus
}
#endif
#endif

