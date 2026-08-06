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
 
#ifndef GPROP_DEF
#define GPROP_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/uprop.h"
typedef struct vis_GProp_Entry { Vint flag;Vint id;
Vint nval;union { Vint* ip;Vdouble* fp;Vchar* cp;}prop;
}vis_GProp_Entry;struct vis_GProp { Vint ierr;Vint stype;
Vuchar pvec[GPROP_MAX];Vint nvecs;Vint mvecs;vis_GProp_Entry*
vect;vis_UProp* uprop;
#ifdef __cplusplus
public: VKI_EXTERN vis_GProp(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_GProp(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void SetValuei(Vint,Vint);VKI_EXTERN void
SetValueiv(Vint,Vint[]);VKI_EXTERN void SetValuef(Vint,
Vfloat);VKI_EXTERN void SetValuefv(Vint,Vfloat[]);VKI_EXTERN
void SetValued(Vint,Vdouble);VKI_EXTERN void SetValuedv(Vint,
Vdouble[]);VKI_EXTERN void SetValuec(Vint,const Vchar*);
VKI_EXTERN void SetValueId(Vint,Vint);VKI_EXTERN void
UnSetValue(Vint);VKI_EXTERN void AddUserValue(Vint,
Vchar*,Vint[],Vint,void*);VKI_EXTERN void ValueTypeNum(Vint*);
VKI_EXTERN void ValueType(Vint*,Vint[]);VKI_EXTERN void
ValueFlag(Vint,Vint*);VKI_EXTERN void ValueId(Vint,
Vint*);VKI_EXTERN void ValueParams(Vint,Vint*,Vint*);
VKI_EXTERN void ValueName(Vint,Vchar[]);VKI_EXTERN void
ValueFloat(Vint,Vfloat[]);VKI_EXTERN void ValueDouble(Vint,
Vdouble[]);VKI_EXTERN void ValueString(Vint,Vchar[]);
VKI_EXTERN void ValueInteger(Vint,Vint[]);VKI_EXTERN
void StreamNum(Vint,Vint*);VKI_EXTERN void StreamSave(Vint,
void*);VKI_EXTERN void StreamLoad(Vint,Vint,void*);
VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_GProp* vis_GPropBegin(void);VKI_EXTERN
void vis_GProp_Construct(vis_GProp* p);VKI_EXTERN void
vis_GPropEnd(vis_GProp* p);VKI_EXTERN void vis_GProp_Destruct(vis_GProp*
p);VKI_EXTERN Vint vis_GPropError(vis_GProp* p);VKI_EXTERN
void vis_GPropSetValuei(vis_GProp* p,Vint type,Vint
ivalue);VKI_EXTERN void vis_GPropSetValueiv(vis_GProp*
p,Vint type,Vint iparam[]);VKI_EXTERN void vis_GPropSetValuef(vis_GProp*
p,Vint type,Vfloat fparam);VKI_EXTERN void vis_GPropSetValuefv(vis_GProp*
p,Vint type,Vfloat rvalue[]);VKI_EXTERN void vis_GPropSetValued(vis_GProp*
p,Vint type,Vdouble dparam);VKI_EXTERN void vis_GPropSetValuedv(vis_GProp*
p,Vint type,Vdouble dparam[]);VKI_EXTERN void vis_GPropSetValuec(vis_GProp*
p,Vint type,const Vchar* cvalue);VKI_EXTERN void vis_GPropSetValueId(vis_GProp*
p,Vint type,Vint id);VKI_EXTERN void vis_GPropUnSetValue(vis_GProp*
p,Vint type);VKI_EXTERN void vis_GPropAddUserValue(vis_GProp*
p,Vint ndim,Vchar* name,Vint dim[],Vint dtype,void*
dat);VKI_EXTERN void vis_GPropValueTypeNum(vis_GProp*
p,Vint* ntypes);VKI_EXTERN void vis_GPropValueType(vis_GProp*
p,Vint* ntypes,Vint type[]);VKI_EXTERN void vis_GPropValueFlag(vis_GProp*
p,Vint type,Vint* flag);VKI_EXTERN void vis_GPropValueId(vis_GProp*
p,Vint type,Vint* id);VKI_EXTERN void vis_GPropValueParams(vis_GProp*
p,Vint type,Vint* nval,Vint* dtyp);VKI_EXTERN void vis_GPropValueName(vis_GProp*
p,Vint type,Vchar name[]);VKI_EXTERN void vis_GPropValueFloat(vis_GProp*
p,Vint id,Vfloat fparam[]);VKI_EXTERN void vis_GPropValueDouble(vis_GProp*
p,Vint id,Vdouble dparam[]);VKI_EXTERN void vis_GPropValueString(vis_GProp*
p,Vint type,Vchar cparam[]);VKI_EXTERN void vis_GPropValueInteger(vis_GProp*
p,Vint type,Vint iparam[]);VKI_EXTERN void vis_GPropStreamNum(vis_GProp*
p,Vint strmtype,Vint* num);VKI_EXTERN void vis_GPropStreamSave(vis_GProp*
p,Vint strmtype,void* data);VKI_EXTERN void vis_GPropStreamLoad(vis_GProp*
p,Vint strmtype,Vint ndat,void* data);VKI_EXTERN void
vis_GPropPrint(vis_GProp* p);
#ifdef __cplusplus
}
#endif
#endif

