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
 
#ifndef EPROP_DEF
#define EPROP_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/uprop.h"
typedef struct vis_EProp_Entry { Vint flag;Vint id;
Vint nloc;Vint nval;union { Vint* ip;Vdouble* fp;Vchar*
cp;}prop;}vis_EProp_Entry;struct vis_EProp { Vint ierr;
Vint etype;Vuchar pvec[EPROP_MAX];Vint nvecs;Vint mvecs;
vis_EProp_Entry* vect;vis_UProp* uprop;Vint pid;Vchar*
name;Vint eprop360;Vint mdof;Vint* idof;
#ifdef __cplusplus
public: VKI_EXTERN vis_EProp(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_EProp(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*);
VKI_EXTERN void SetParami(Vint,Vint);VKI_EXTERN void
MatNum(Vint*);VKI_EXTERN void MatCon(Vint[],Vint[]);
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
Vint*);VKI_EXTERN void ValueParams(Vint,Vint*,Vint*,
Vint*);VKI_EXTERN void ValueName(Vint,Vchar[]);VKI_EXTERN
void ValueFloat(Vint,Vfloat[]);VKI_EXTERN void ValueDouble(Vint,
Vdouble[]);VKI_EXTERN void ValueString(Vint,Vchar[]);
VKI_EXTERN void ValueInteger(Vint,Vint[]);VKI_EXTERN
void Fill(vis_EProp*);VKI_EXTERN void StreamNum(Vint,
Vint*);VKI_EXTERN void StreamSave(Vint,void*);VKI_EXTERN
void StreamLoad(Vint,Vint,void*);VKI_EXTERN void SetId(Vint);
VKI_EXTERN void GetId(Vint*);VKI_EXTERN void SetName(const
Vchar*);VKI_EXTERN void GetName(Vchar[]);VKI_EXTERN
void Eval(Vint,Vint,Vint,Vint,Vfloat[]);VKI_EXTERN void
Evaldv(Vint,Vint,Vint,Vint,Vdouble[]);VKI_EXTERN void
Copy(vis_EProp*);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_EProp* vis_EPropBegin(void);VKI_EXTERN
void vis_EProp_Construct(vis_EProp* p);VKI_EXTERN void
vis_EPropEnd(vis_EProp* p);VKI_EXTERN void vis_EProp_Destruct(vis_EProp*
p);VKI_EXTERN Vint vis_EPropError(vis_EProp* p);VKI_EXTERN
void vis_EPropDef(vis_EProp* p,Vint ptype);VKI_EXTERN
void vis_EPropInq(vis_EProp* p,Vint* etype);VKI_EXTERN
void vis_EPropSetParami(vis_EProp* p,Vint type,Vint
iparam);VKI_EXTERN void vis_EPropMatNum(vis_EProp* p,
Vint* ndof);VKI_EXTERN void vis_EPropMatCon(vis_EProp*
p,Vint icon[],Vint idof[]);VKI_EXTERN void vis_EPropSetValuei(vis_EProp*
p,Vint type,Vint ivalue);VKI_EXTERN void vis_EPropSetValueiv(vis_EProp*
p,Vint type,Vint ivalue[]);VKI_EXTERN void vis_EPropSetValuef(vis_EProp*
p,Vint type,Vfloat rvalue);VKI_EXTERN void vis_EPropSetValuefv(vis_EProp*
p,Vint type,Vfloat rvalue[]);VKI_EXTERN void vis_EPropSetValued(vis_EProp*
p,Vint type,Vdouble dparam);VKI_EXTERN void vis_EPropSetValuedv(vis_EProp*
p,Vint type,Vdouble dparam[]);VKI_EXTERN void vis_EPropSetValuec(vis_EProp*
p,Vint type,const Vchar* cvalue);VKI_EXTERN void vis_EPropSetValueId(vis_EProp*
p,Vint type,Vint id);VKI_EXTERN void vis_EPropUnSetValue(vis_EProp*
p,Vint type);VKI_EXTERN void vis_EPropAddUserValue(vis_EProp*
p,Vint ndim,Vchar* name,Vint dim[],Vint dtype,void*
dat);VKI_EXTERN void vis_EPropValueTypeNum(vis_EProp*
p,Vint* ntypes);VKI_EXTERN void vis_EPropValueType(vis_EProp*
p,Vint* ntypes,Vint type[]);VKI_EXTERN void vis_EPropValueFlag(vis_EProp*
p,Vint type,Vint* flag);VKI_EXTERN void vis_EPropValueId(vis_EProp*
p,Vint type,Vint* id);VKI_EXTERN void vis_EPropValueParams(vis_EProp*
p,Vint type,Vint* nval,Vint* nloc,Vint* dtyp);VKI_EXTERN
void vis_EPropValueName(vis_EProp* p,Vint type,Vchar
name[]);VKI_EXTERN void vis_EPropValueFloat(vis_EProp*
p,Vint type,Vfloat fparam[]);VKI_EXTERN void vis_EPropValueDouble(vis_EProp*
p,Vint type,Vdouble dparam[]);VKI_EXTERN void vis_EPropValueString(vis_EProp*
p,Vint type,Vchar cparam[]);VKI_EXTERN void vis_EPropValueInteger(vis_EProp*
p,Vint type,Vint iparam[]);VKI_EXTERN void vis_EPropFill(vis_EProp*
p,vis_EProp* eprop);VKI_EXTERN void vis_EPropStreamNum(vis_EProp*
p,Vint strmtype,Vint* num);VKI_EXTERN void vis_EPropStreamSave(vis_EProp*
p,Vint strmtype,void* data);VKI_EXTERN void vis_EPropStreamLoad(vis_EProp*
p,Vint strmtype,Vint ndat,void* data);VKI_EXTERN void
vis_EPropSetId(vis_EProp* p,Vint id);VKI_EXTERN void
vis_EPropGetId(vis_EProp* p,Vint* id);VKI_EXTERN void
vis_EPropSetName(vis_EProp* p,const Vchar* name);VKI_EXTERN
void vis_EPropGetName(vis_EProp* p,Vchar name[]);VKI_EXTERN
void vis_EPropEval(vis_EProp* p,Vint type,Vint shape,
Vint maxi,Vint maxj,Vfloat value[]);VKI_EXTERN void
vis_EPropEvaldv(vis_EProp* p,Vint type,Vint shape,Vint
maxi,Vint maxj,Vdouble dvalue[]);VKI_EXTERN void vis_EPropCopy(vis_EProp*
p,vis_EProp* fromp);VKI_EXTERN void vis_EPropPrint(vis_EProp*
p);
#ifdef __cplusplus
}
#endif
#endif

