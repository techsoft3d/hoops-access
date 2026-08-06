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
 
#ifndef DATAINT_DEF
#define DATAINT_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
typedef void(VDataIntFunc)(vis_DataInt*,Vobject*);struct
vis_DataInt { Vint ierr;Vint nrws;Vfloat* data;VDataIntFunc*
fun;Vobject* funobject;vis_State* state;
#ifdef __cplusplus
public: VKI_EXTERN vis_DataInt(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_DataInt(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void SetDataPtr(Vint,Vint,Vfloat[]);
VKI_EXTERN void GetDataPtr(Vint,Vint*,Vfloat**);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetDataIntFunction(Vint,VDataIntFunc*,Vobject*);VKI_EXTERN
void CallFunction(Vint);VKI_EXTERN void SetState(Vint,
vis_State*);VKI_EXTERN void GetState(Vint,vis_State**);
VKI_EXTERN void Copy(vis_DataInt*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_DataInt* vis_DataIntBegin(void);VKI_EXTERN
void vis_DataInt_Construct(vis_DataInt* p);VKI_EXTERN
void vis_DataIntEnd(vis_DataInt* p);VKI_EXTERN void
vis_DataInt_Destruct(vis_DataInt* p);VKI_EXTERN Vint
vis_DataIntError(vis_DataInt* p);VKI_EXTERN void vis_DataIntSetDataPtr(vis_DataInt*
p,Vint index,Vint nrws,Vfloat dataptr[]);VKI_EXTERN
void vis_DataIntGetDataPtr(vis_DataInt* p,Vint index,
Vint* nrws,Vfloat** data);VKI_EXTERN void vis_DataIntSetFunction(vis_DataInt*
p,Vint index,Vfunc* function,Vobject* object);VKI_EXTERN
void vis_DataIntSetDataIntFunction(vis_DataInt* p,Vint
index,VDataIntFunc* function,Vobject* object);VKI_EXTERN
void vis_DataIntCallFunction(vis_DataInt* p,Vint index);
VKI_EXTERN void vis_DataIntSetState(vis_DataInt* p,
Vint index,vis_State* state);VKI_EXTERN void vis_DataIntGetState(vis_DataInt*
p,Vint index,vis_State** state);VKI_EXTERN void vis_DataIntCopy(vis_DataInt*
p,vis_DataInt* fromp);
#ifdef __cplusplus
}
#endif
#endif

