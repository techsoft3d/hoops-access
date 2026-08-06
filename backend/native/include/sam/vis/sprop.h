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
 
#ifndef SPROP_DEF
#define SPROP_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/uprop.h"
typedef struct vis_SProp_Entry { Vint flag;Vint id;
Vint nval;union { Vint* ip;Vdouble* fp;Vchar* cp;}prop;
}vis_SProp_Entry;struct vis_SProp { Vint ierr;Vint stype;
Vint pvec[SPROP_MAX];Vint nvecs;Vint mvecs;vis_SProp_Entry*
vect;vis_UProp* uprop;Vint sid;Vchar* name;Vint sprop360;
#ifdef __cplusplus
public: VKI_EXTERN vis_SProp(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_SProp(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*);
VKI_EXTERN void ReDef(Vint);VKI_EXTERN void SetParami(Vint,
Vint);VKI_EXTERN void SetValuei(Vint,Vint);VKI_EXTERN
void SetValueiv(Vint,Vint[]);VKI_EXTERN void SetValuef(Vint,
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
VKI_EXTERN void SetId(Vint);VKI_EXTERN void GetId(Vint*);
VKI_EXTERN void SetName(const Vchar*);VKI_EXTERN void
GetName(Vchar[]);VKI_EXTERN void Copy(vis_SProp*);VKI_EXTERN
void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_SProp* vis_SPropBegin(void);VKI_EXTERN
void vis_SProp_Construct(vis_SProp* p);VKI_EXTERN void
vis_SPropEnd(vis_SProp* p);VKI_EXTERN void vis_SProp_Destruct(vis_SProp*
p);VKI_EXTERN Vint vis_SPropError(vis_SProp* p);VKI_EXTERN
void vis_SPropDef(vis_SProp* p,Vint ptype);VKI_EXTERN
void vis_SPropInq(vis_SProp* p,Vint* stype);VKI_EXTERN
void vis_SPropReDef(vis_SProp* p,Vint stype);VKI_EXTERN
void vis_SPropSetParami(vis_SProp* p,Vint type,Vint
iparam);VKI_EXTERN void vis_SPropSetValuei(vis_SProp*
p,Vint type,Vint ivalue);VKI_EXTERN void vis_SPropSetValueiv(vis_SProp*
p,Vint type,Vint ivalue[]);VKI_EXTERN void vis_SPropSetValuef(vis_SProp*
p,Vint type,Vfloat rvalue);VKI_EXTERN void vis_SPropSetValuefv(vis_SProp*
p,Vint type,Vfloat rvalue[]);VKI_EXTERN void vis_SPropSetValued(vis_SProp*
p,Vint type,Vdouble dparam);VKI_EXTERN void vis_SPropSetValuedv(vis_SProp*
p,Vint type,Vdouble dparam[]);VKI_EXTERN void vis_SPropSetValuec(vis_SProp*
p,Vint type,const Vchar* cvalue);VKI_EXTERN void vis_SPropSetValueId(vis_SProp*
p,Vint type,Vint id);VKI_EXTERN void vis_SPropUnSetValue(vis_SProp*
p,Vint type);VKI_EXTERN void vis_SPropAddUserValue(vis_SProp*
p,Vint ndim,Vchar* name,Vint dim[],Vint dtype,void*
dat);VKI_EXTERN void vis_SPropValueTypeNum(vis_SProp*
p,Vint* ntypes);VKI_EXTERN void vis_SPropValueType(vis_SProp*
p,Vint* ntypes,Vint type[]);VKI_EXTERN void vis_SPropValueFlag(vis_SProp*
p,Vint type,Vint* flag);VKI_EXTERN void vis_SPropValueId(vis_SProp*
p,Vint type,Vint* id);VKI_EXTERN void vis_SPropValueParams(vis_SProp*
p,Vint type,Vint* nval,Vint* dtyp);VKI_EXTERN void vis_SPropValueName(vis_SProp*
p,Vint type,Vchar name[]);VKI_EXTERN void vis_SPropValueFloat(vis_SProp*
p,Vint type,Vfloat fparam[]);VKI_EXTERN void vis_SPropValueDouble(vis_SProp*
p,Vint type,Vdouble dparam[]);VKI_EXTERN void vis_SPropValueString(vis_SProp*
p,Vint type,Vchar cparam[]);VKI_EXTERN void vis_SPropValueInteger(vis_SProp*
p,Vint type,Vint iparam[]);VKI_EXTERN void vis_SPropStreamNum(vis_SProp*
p,Vint strmtype,Vint* num);VKI_EXTERN void vis_SPropStreamSave(vis_SProp*
p,Vint strmtype,void* data);VKI_EXTERN void vis_SPropStreamLoad(vis_SProp*
p,Vint strmtype,Vint ndat,void* data);VKI_EXTERN void
vis_SPropSetId(vis_SProp* p,Vint id);VKI_EXTERN void
vis_SPropGetId(vis_SProp* p,Vint* id);VKI_EXTERN void
vis_SPropSetName(vis_SProp* p,const Vchar* name);VKI_EXTERN
void vis_SPropGetName(vis_SProp* p,Vchar name[]);VKI_EXTERN
void vis_SPropCopy(vis_SProp* p,vis_SProp* fromp);VKI_EXTERN
void vis_SPropPrint(vis_SProp* p);
#ifdef __cplusplus
}
#endif
#endif

