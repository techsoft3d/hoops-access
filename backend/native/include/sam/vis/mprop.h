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
 
#ifndef MPROP_DEF
#define MPROP_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#define MPROP_360 1
typedef struct vis_MProp_Entry { Vint flag;Vint id;
Vint nval;union { Vint* ip;Vdouble* fp;}prop;}vis_MProp_Entry;
struct vis_MProp { Vint ierr;Vint mtype;Vuchar mvec[MPROP_MAX];
Vint nvecs;Vint mvecs;vis_MProp_Entry* vect;Vint mid;
Vchar* name;Vint mprop360;
#ifdef __cplusplus
public: VKI_EXTERN vis_MProp(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_MProp(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*);
VKI_EXTERN void ReDef(Vint);VKI_EXTERN void SetParami(Vint,
Vint);VKI_EXTERN void SetValuei(Vint,Vint);VKI_EXTERN
void SetValuef(Vint,Vfloat);VKI_EXTERN void SetValuefv(Vint,
Vfloat[]);VKI_EXTERN void SetValued(Vint,Vdouble);VKI_EXTERN
void SetValuedv(Vint,Vdouble[]);VKI_EXTERN void SetValueId(Vint,
Vint);VKI_EXTERN void UnSetValue(Vint);VKI_EXTERN void
ValueTypeNum(Vint*);VKI_EXTERN void ValueType(Vint*,
Vint[]);VKI_EXTERN void ValueParams(Vint,Vint*,Vint*);
VKI_EXTERN void ValueFlag(Vint,Vint*);VKI_EXTERN void
ValueId(Vint,Vint*);VKI_EXTERN void ValueName(Vint,
Vchar[]);VKI_EXTERN void ValueDouble(Vint,Vdouble[]);
VKI_EXTERN void ValueFloat(Vint,Vfloat[]);VKI_EXTERN
void ValueInteger(Vint,Vint[]);VKI_EXTERN void StreamNum(Vint,
Vint*);VKI_EXTERN void StreamSave(Vint,void*);VKI_EXTERN
void StreamLoad(Vint,Vint,void*);VKI_EXTERN void SetId(Vint);
VKI_EXTERN void GetId(Vint*);VKI_EXTERN void SetName(const
Vchar*);VKI_EXTERN void GetName(Vchar[]);VKI_EXTERN
void Print();VKI_EXTERN void Copy(vis_MProp*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_MProp* vis_MPropBegin(void);VKI_EXTERN
void vis_MProp_Construct(vis_MProp* p);VKI_EXTERN void
vis_MPropEnd(vis_MProp* p);VKI_EXTERN void vis_MProp_Destruct(vis_MProp*
p);VKI_EXTERN Vint vis_MPropError(vis_MProp* p);VKI_EXTERN
void vis_MPropDef(vis_MProp* p,Vint type);VKI_EXTERN
void vis_MPropInq(vis_MProp* p,Vint* mtype);VKI_EXTERN
void vis_MPropReDef(vis_MProp* p,Vint mtype);VKI_EXTERN
void vis_MPropSetParami(vis_MProp* p,Vint type,Vint
iparam);VKI_EXTERN void vis_MPropSetValuei(vis_MProp*
p,Vint type,Vint ivalue);VKI_EXTERN void vis_MPropSetValuef(vis_MProp*
p,Vint type,Vfloat rvalue);VKI_EXTERN void vis_MPropSetValuefv(vis_MProp*
p,Vint type,Vfloat rvalue[]);VKI_EXTERN void vis_MPropSetValued(vis_MProp*
p,Vint type,Vdouble dparam);VKI_EXTERN void vis_MPropSetValuedv(vis_MProp*
p,Vint type,Vdouble dparam[]);VKI_EXTERN void vis_MPropSetValueId(vis_MProp*
p,Vint type,Vint id);VKI_EXTERN void vis_MPropUnSetValue(vis_MProp*
p,Vint type);VKI_EXTERN void vis_MPropValueTypeNum(vis_MProp*
p,Vint* ntypes);VKI_EXTERN void vis_MPropValueType(vis_MProp*
p,Vint* ntypes,Vint type[]);VKI_EXTERN void vis_MPropValueParams(vis_MProp*
p,Vint type,Vint* nval,Vint* dtyp);VKI_EXTERN void vis_MPropValueFlag(vis_MProp*
p,Vint type,Vint* flag);VKI_EXTERN void vis_MPropValueId(vis_MProp*
p,Vint type,Vint* id);VKI_EXTERN void vis_MPropValueName(vis_MProp*
p,Vint type,Vchar name[]);VKI_EXTERN void vis_MPropValueDouble(vis_MProp*
p,Vint type,Vdouble dparam[]);VKI_EXTERN void vis_MPropValueFloat(vis_MProp*
p,Vint type,Vfloat fparam[]);VKI_EXTERN void vis_MPropValueInteger(vis_MProp*
p,Vint type,Vint iparam[]);VKI_EXTERN void vis_MPropStreamNum(vis_MProp*
p,Vint strmtype,Vint* num);VKI_EXTERN void vis_MPropStreamSave(vis_MProp*
p,Vint strmtype,void* data);VKI_EXTERN void vis_MPropStreamLoad(vis_MProp*
p,Vint strmtype,Vint ndat,void* data);VKI_EXTERN void
vis_MPropSetId(vis_MProp* p,Vint id);VKI_EXTERN void
vis_MPropGetId(vis_MProp* p,Vint* id);VKI_EXTERN void
vis_MPropSetName(vis_MProp* p,const Vchar* name);VKI_EXTERN
void vis_MPropGetName(vis_MProp* p,Vchar name[]);VKI_EXTERN
void vis_MPropPrint(vis_MProp* p);VKI_EXTERN void vis_MPropCopy(vis_MProp*
p,vis_MProp* fromp);
#ifdef __cplusplus
}
#endif
#endif

