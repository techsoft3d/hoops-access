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
 
#ifndef TCURVE_DEF
#define TCURVE_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
struct vis_TCurve { Vint ierr;Vint type;Vint nval;Vdouble
scale;Vdouble shift;Vdouble divisor;Vdouble offset;
Vdouble tol;Vint hint;Vint extraflag;Vint npts;Vdouble*
t;Vdouble* f;Vdouble* fd;Vint tid;Vchar* name;
#ifdef __cplusplus
public: VKI_EXTERN vis_TCurve(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_TCurve(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void SetId(Vint);VKI_EXTERN void GetId(Vint*);
VKI_EXTERN void SetName(const Vchar*);VKI_EXTERN void
GetName(Vchar[]);VKI_EXTERN void Def(Vint,Vint);VKI_EXTERN
void Inq(Vint*,Vint*);VKI_EXTERN void SetFactor(Vint,
Vfloat);VKI_EXTERN void SetFactord(Vint,Vdouble);VKI_EXTERN
void GetFactor(Vint,Vfloat*);VKI_EXTERN void GetFactord(Vint,
Vdouble*);VKI_EXTERN void SetParamd(Vint,Vdouble);VKI_EXTERN
void SetParami(Vint,Vint);VKI_EXTERN void GetParami(Vint,
Vint*);VKI_EXTERN void SetPWLinear(Vint,Vfloat[],Vfloat[]);
VKI_EXTERN void SetPWLineardv(Vint,Vdouble[],Vdouble[]);
VKI_EXTERN void SetCompPWLinear(Vint,Vint,Vfloat[]);
VKI_EXTERN void Num(Vint*);VKI_EXTERN void Indep(Vint,
Vint[],Vfloat[]);VKI_EXTERN void Indepdv(Vint,Vint[],
Vdouble[]);VKI_EXTERN void Dep(Vint,Vint[],Vfloat[]);
VKI_EXTERN void Depdv(Vint,Vint[],Vdouble[]);VKI_EXTERN
void SetDep(Vint,Vint[],Vfloat[]);VKI_EXTERN void SetDepdv(Vint,
Vint[],Vdouble[]);VKI_EXTERN void Eval(Vint,Vfloat[],
Vfloat[]);VKI_EXTERN void Evaldv(Vint,Vdouble[],Vdouble[]);
VKI_EXTERN void Merge(Vint,vis_TCurve*[]);VKI_EXTERN
void IndepMatch(Vint,Vfloat[],Vint*);VKI_EXTERN void
Print();VKI_EXTERN Vint IsEqualTo(vis_TCurve*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_TCurve* vis_TCurveBegin(void);VKI_EXTERN
void vis_TCurve_Construct(vis_TCurve* p);VKI_EXTERN
void vis_TCurveEnd(vis_TCurve* p);VKI_EXTERN void vis_TCurve_Destruct(vis_TCurve*
p);VKI_EXTERN Vint vis_TCurveError(vis_TCurve* p);VKI_EXTERN
void vis_TCurveSetId(vis_TCurve* p,Vint id);VKI_EXTERN
void vis_TCurveGetId(vis_TCurve* p,Vint* id);VKI_EXTERN
void vis_TCurveSetName(vis_TCurve* p,const Vchar* name);
VKI_EXTERN void vis_TCurveGetName(vis_TCurve* p,Vchar
name[]);VKI_EXTERN void vis_TCurveDef(vis_TCurve* p,
Vint type,Vint nval);VKI_EXTERN void vis_TCurveInq(vis_TCurve*
p,Vint* type,Vint* nval);VKI_EXTERN void vis_TCurveSetFactor(vis_TCurve*
p,Vint ptype,Vfloat param);VKI_EXTERN void vis_TCurveSetFactord(vis_TCurve*
p,Vint type,Vdouble fparam);VKI_EXTERN void vis_TCurveGetFactor(vis_TCurve*
p,Vint type,Vfloat* fparam);VKI_EXTERN void vis_TCurveGetFactord(vis_TCurve*
p,Vint type,Vdouble* fparam);VKI_EXTERN void vis_TCurveSetParamd(vis_TCurve*
p,Vint type,Vdouble dparam);VKI_EXTERN void vis_TCurveSetParami(vis_TCurve*
p,Vint ptype,Vint iparam);VKI_EXTERN void vis_TCurveGetParami(vis_TCurve*
p,Vint type,Vint* iparam);VKI_EXTERN void vis_TCurveSetPWLinear(vis_TCurve*
p,Vint npts,Vfloat t[],Vfloat f[]);VKI_EXTERN void vis_TCurveSetPWLineardv(vis_TCurve*
p,Vint npts,Vdouble t[],Vdouble f[]);VKI_EXTERN void
vis_TCurveSetCompPWLinear(vis_TCurve* p,Vint npts,Vint
ival,Vfloat f[]);VKI_EXTERN void vis_TCurveNum(vis_TCurve*
p,Vint* npts);VKI_EXTERN void vis_TCurveIndep(vis_TCurve*
p,Vint npts,Vint pts[],Vfloat t[]);VKI_EXTERN void vis_TCurveIndepdv(vis_TCurve*
p,Vint npts,Vint pts[],Vdouble t[]);VKI_EXTERN void
vis_TCurveDep(vis_TCurve* p,Vint npts,Vint pts[],Vfloat
f[]);VKI_EXTERN void vis_TCurveDepdv(vis_TCurve* p,
Vint npts,Vint pts[],Vdouble f[]);VKI_EXTERN void vis_TCurveSetDep(vis_TCurve*
p,Vint npts,Vint pts[],Vfloat f[]);VKI_EXTERN void vis_TCurveSetDepdv(vis_TCurve*
p,Vint npts,Vint pts[],Vdouble f[]);VKI_EXTERN void
vis_TCurveEval(vis_TCurve* p,Vint npts,Vfloat t[],Vfloat
f[]);VKI_EXTERN void vis_TCurveEvaldv(vis_TCurve* p,
Vint npts,Vdouble t[],Vdouble f[]);VKI_EXTERN void vis_TCurveMerge(vis_TCurve*
p,Vint num,vis_TCurve* tcurvex[]);VKI_EXTERN void vis_TCurveIndepMatch(vis_TCurve*
p,Vint npts,Vfloat t[],Vint* flag);VKI_EXTERN void vis_TCurvePrint(vis_TCurve*
p);VKI_EXTERN Vint vis_TCurveIsEqualTo(vis_TCurve* p,
vis_TCurve* q);
#ifdef __cplusplus
}
#endif
#endif

