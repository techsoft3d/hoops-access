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
 
#ifndef MASSPRP_DEF
#define MASSPRP_DEF
#include "sam/base/base.h"
#include "sam/vis/model.h"
#include "sam/vis/gridfun.h"
struct vis_MassPrp { Vint ierr;vis_Model* model;vis_GridFun*
gf;vsy_HashTable* beamsecth;
#ifdef __cplusplus
public: VKI_EXTERN vis_MassPrp(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_MassPrp(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void SetObject(Vint,Vobject*);VKI_EXTERN
void Compute(vis_Group*,Vfloat*,Vfloat*,Vfloat[3],Vfloat[6]);
VKI_EXTERN void Principal(Vfloat[6],Vfloat[3],Vfloat[3][3]);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_MassPrp* vis_MassPrpBegin(void);VKI_EXTERN
void vis_MassPrp_Construct(vis_MassPrp* p);VKI_EXTERN
void vis_MassPrpEnd(vis_MassPrp* p);VKI_EXTERN void
vis_MassPrp_Destruct(vis_MassPrp* p);VKI_EXTERN Vint
vis_MassPrpError(vis_MassPrp* p);VKI_EXTERN void vis_MassPrpSetObject(vis_MassPrp*
p,Vint type,Vobject* object);VKI_EXTERN void vis_MassPrpCompute(vis_MassPrp*
p,vis_Group* group,Vfloat* vtot,Vfloat* mtot,Vfloat
xcom[3],Vfloat mten[6]);VKI_EXTERN void vis_MassPrpPrincipal(vis_MassPrp*
p,Vfloat mten[6],Vfloat mpri[3],Vfloat tm[3][3]);
#ifdef __cplusplus
}
#endif
#endif

