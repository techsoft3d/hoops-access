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
 
#ifndef ASURF_DEF
#define ASURF_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
struct vis_ASurf { Vint ierr;Vint type;Vchar* name;
Vint numpnt;Vint numseg;Vint numnurbs;Vint numtrims;
Vint numfacets;vis_Connect* ce;Vint nhomos;Vint nknots;
vsy_DblVec* homovec;vsy_DblVec* knotvec;Vdouble fillet;
Vdouble orient[3][3];Vdouble length;Vdouble width;Vdouble
height;Vdouble r,ra;Vdouble c[3];vsy_IntVHash* ids;
Vint numelem;Vint maxord;
#ifdef __cplusplus
public: VKI_EXTERN vis_ASurf(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_ASurf(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*);
VKI_EXTERN void SetName(const Vchar*);VKI_EXTERN void
GetName(Vchar[]);VKI_EXTERN void SetPoint(Vint,Vfloat[3]);
VKI_EXTERN void SetPointdv(Vint,Vdouble[3]);VKI_EXTERN
void GetPoint(Vint,Vfloat[3]);VKI_EXTERN void GetPointdv(Vint,
Vdouble[3]);VKI_EXTERN void NumPoints(Vint*);VKI_EXTERN
void SetSegment(Vint,Vint,Vint[]);VKI_EXTERN void GetSegment(Vint,
Vint*,Vint[]);VKI_EXTERN void NumSegments(Vint*);VKI_EXTERN
void SetSegmentRule(Vfloat[3],Vfloat[3],Vfloat[3]);
VKI_EXTERN void SetSegmentRuledv(Vdouble[3],Vdouble[3],
Vdouble[3]);VKI_EXTERN void GetSegmentRule(Vfloat[3],
Vfloat[3],Vfloat[3]);VKI_EXTERN void GetSegmentRuledv(Vdouble[3],
Vdouble[3],Vdouble[3]);VKI_EXTERN void SetSegmentRev(Vfloat[3],
Vfloat[3],Vfloat[3]);VKI_EXTERN void SetSegmentRevdv(Vdouble[3],
Vdouble[3],Vdouble[3]);VKI_EXTERN void GetSegmentRev(Vfloat[3],
Vfloat[3],Vfloat[3]);VKI_EXTERN void GetSegmentRevdv(Vdouble[3],
Vdouble[3],Vdouble[3]);VKI_EXTERN void SetSegmentFillet(Vfloat);
VKI_EXTERN void SetSegmentFilletdv(Vdouble);VKI_EXTERN
void GetSegmentFillet(Vfloat*);VKI_EXTERN void GetSegmentFilletdv(Vdouble*);
VKI_EXTERN void SetPlane(Vfloat[3],Vfloat[3],Vfloat[3],
Vfloat,Vfloat);VKI_EXTERN void SetPlanedv(Vdouble[3],
Vdouble[3],Vdouble[3],Vdouble,Vdouble);VKI_EXTERN void
GetPlane(Vfloat[3],Vfloat[3],Vfloat[3],Vfloat*,Vfloat*);
VKI_EXTERN void GetPlanedv(Vdouble[3],Vdouble[3],Vdouble[3],
Vdouble*,Vdouble*);VKI_EXTERN void SetBox(Vfloat[3],
Vfloat[3],Vfloat[3],Vfloat,Vfloat,Vfloat);VKI_EXTERN
void SetBoxdv(Vdouble[3],Vdouble[3],Vdouble[3],Vdouble,
Vdouble,Vdouble);VKI_EXTERN void GetBox(Vfloat[3],Vfloat[3],
Vfloat[3],Vfloat*,Vfloat*,Vfloat*);VKI_EXTERN void GetBoxdv(Vdouble[3],
Vdouble[3],Vdouble[3],Vdouble*,Vdouble*,Vdouble*);VKI_EXTERN
void SetCylinder(Vfloat[3],Vfloat[3],Vfloat[3],Vfloat,
Vfloat);VKI_EXTERN void SetCylinderdv(Vdouble[3],Vdouble[3],
Vdouble[3],Vdouble,Vdouble);VKI_EXTERN void GetCylinder(Vfloat[3],
Vfloat[3],Vfloat[3],Vfloat*,Vfloat*);VKI_EXTERN void
GetCylinderdv(Vdouble[3],Vdouble[3],Vdouble[3],Vdouble*,
Vdouble*);VKI_EXTERN void SetCone(Vfloat[3],Vfloat[3],
Vfloat[3],Vfloat,Vfloat,Vfloat);VKI_EXTERN void SetConedv(Vdouble[3],
Vdouble[3],Vdouble[3],Vdouble,Vdouble,Vdouble);VKI_EXTERN
void GetCone(Vfloat[3],Vfloat[3],Vfloat[3],Vfloat*,
Vfloat*,Vfloat*);VKI_EXTERN void GetConedv(Vdouble[3],
Vdouble[3],Vdouble[3],Vdouble*,Vdouble*,Vdouble*);VKI_EXTERN
void SetSphere(Vfloat[3],Vfloat);VKI_EXTERN void SetSpheredv(Vdouble[3],
Vdouble);VKI_EXTERN void GetSphere(Vfloat[3],Vfloat*);
VKI_EXTERN void GetSpheredv(Vdouble[3],Vdouble*);VKI_EXTERN
void Print();VKI_EXTERN void SetNURBS(Vint,Vint,Vint,
Vint,Vint,Vint,Vint[],Vfloat[],Vfloat[],Vint,Vint[]);
VKI_EXTERN void SetNURBSdv(Vint,Vint,Vint,Vint,Vint,
Vint,Vint[],Vdouble[],Vdouble[],Vint,Vint[]);VKI_EXTERN
void NumNURBS(Vint*);VKI_EXTERN void MaxNURBSOrder(Vint*);
VKI_EXTERN void GetNURBSNum(Vint,Vint*,Vint*,Vint*,
Vint*,Vint*,Vint*);VKI_EXTERN void GetNURBS(Vint,Vint*,
Vint*,Vint*,Vint*,Vint*,Vint[],Vfloat[],Vfloat[],Vint*,
Vint[]);VKI_EXTERN void GetNURBSdv(Vint,Vint*,Vint*,
Vint*,Vint*,Vint*,Vint[],Vdouble[],Vdouble[],Vint*,
Vint[]);VKI_EXTERN void SetNURBSTrim(Vint,Vint,Vint[]);
VKI_EXTERN void NumNURBSTrim(Vint*);VKI_EXTERN void
GetNURBSTrimNum(Vint,Vint*);VKI_EXTERN void GetNURBSTrim(Vint,
Vint*,Vint[]);VKI_EXTERN void SetFacet(Vint,Vint,Vint[]);
VKI_EXTERN void NumFacets(Vint*);VKI_EXTERN void GetFacet(Vint,
Vint*,Vint[]);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_ASurf* vis_ASurfBegin(void);VKI_EXTERN
void vis_ASurf_Construct(vis_ASurf* p);VKI_EXTERN void
vis_ASurfEnd(vis_ASurf* p);VKI_EXTERN void vis_ASurf_Destruct(vis_ASurf*
p);VKI_EXTERN Vint vis_ASurfError(vis_ASurf* p);VKI_EXTERN
void vis_ASurfDef(vis_ASurf* p,Vint type);VKI_EXTERN
void vis_ASurfInq(vis_ASurf* p,Vint* type);VKI_EXTERN
void vis_ASurfSetName(vis_ASurf* p,const Vchar* name);
VKI_EXTERN void vis_ASurfGetName(vis_ASurf* p,Vchar
name[]);VKI_EXTERN void vis_ASurfSetPoint(vis_ASurf*
p,Vint id,Vfloat x[3]);VKI_EXTERN void vis_ASurfSetPointdv(vis_ASurf*
p,Vint id,Vdouble x[3]);VKI_EXTERN void vis_ASurfGetPoint(vis_ASurf*
p,Vint id,Vfloat x[3]);VKI_EXTERN void vis_ASurfGetPointdv(vis_ASurf*
p,Vint id,Vdouble x[3]);VKI_EXTERN void vis_ASurfNumPoints(vis_ASurf*
p,Vint* numpnt);VKI_EXTERN void vis_ASurfSetSegment(vis_ASurf*
p,Vint id,Vint type,Vint ix[]);VKI_EXTERN void vis_ASurfGetSegment(vis_ASurf*
p,Vint id,Vint* type,Vint ix[]);VKI_EXTERN void vis_ASurfNumSegments(vis_ASurf*
p,Vint* numseg);VKI_EXTERN void vis_ASurfSetSegmentRule(vis_ASurf*
p,Vfloat a[3],Vfloat b[3],Vfloat c[3]);VKI_EXTERN void
vis_ASurfSetSegmentRuledv(vis_ASurf* p,Vdouble a[3],
Vdouble b[3],Vdouble c[3]);VKI_EXTERN void vis_ASurfGetSegmentRule(vis_ASurf*
p,Vfloat a[3],Vfloat b[3],Vfloat c[3]);VKI_EXTERN void
vis_ASurfGetSegmentRuledv(vis_ASurf* p,Vdouble a[3],
Vdouble b[3],Vdouble c[3]);VKI_EXTERN void vis_ASurfSetSegmentRev(vis_ASurf*
p,Vfloat a[3],Vfloat b[3],Vfloat c[3]);VKI_EXTERN void
vis_ASurfSetSegmentRevdv(vis_ASurf* p,Vdouble a[3],
Vdouble b[3],Vdouble c[3]);VKI_EXTERN void vis_ASurfGetSegmentRev(vis_ASurf*
p,Vfloat a[3],Vfloat b[3],Vfloat c[3]);VKI_EXTERN void
vis_ASurfGetSegmentRevdv(vis_ASurf* p,Vdouble a[3],
Vdouble b[3],Vdouble c[3]);VKI_EXTERN void vis_ASurfSetSegmentFillet(vis_ASurf*
p,Vfloat r);VKI_EXTERN void vis_ASurfSetSegmentFilletdv(vis_ASurf*
p,Vdouble r);VKI_EXTERN void vis_ASurfGetSegmentFillet(vis_ASurf*
p,Vfloat* r);VKI_EXTERN void vis_ASurfGetSegmentFilletdv(vis_ASurf*
p,Vdouble* r);VKI_EXTERN void vis_ASurfSetPlane(vis_ASurf*
p,Vfloat a[3],Vfloat b[3],Vfloat c[3],Vfloat length,
Vfloat width);VKI_EXTERN void vis_ASurfSetPlanedv(vis_ASurf*
p,Vdouble a[3],Vdouble b[3],Vdouble c[3],Vdouble length,
Vdouble width);VKI_EXTERN void vis_ASurfGetPlane(vis_ASurf*
p,Vfloat a[3],Vfloat b[3],Vfloat c[3],Vfloat* length,
Vfloat* width);VKI_EXTERN void vis_ASurfGetPlanedv(vis_ASurf*
p,Vdouble a[3],Vdouble b[3],Vdouble c[3],Vdouble* length,
Vdouble* width);VKI_EXTERN void vis_ASurfSetBox(vis_ASurf*
p,Vfloat a[3],Vfloat b[3],Vfloat c[3],Vfloat length,
Vfloat width,Vfloat height);VKI_EXTERN void vis_ASurfSetBoxdv(vis_ASurf*
p,Vdouble a[3],Vdouble b[3],Vdouble c[3],Vdouble length,
Vdouble width,Vdouble height);VKI_EXTERN void vis_ASurfGetBox(vis_ASurf*
p,Vfloat a[3],Vfloat b[3],Vfloat c[3],Vfloat* length,
Vfloat* width,Vfloat* height);VKI_EXTERN void vis_ASurfGetBoxdv(vis_ASurf*
p,Vdouble a[3],Vdouble b[3],Vdouble c[3],Vdouble* length,
Vdouble* width,Vdouble* height);VKI_EXTERN void vis_ASurfSetCylinder(vis_ASurf*
p,Vfloat a[3],Vfloat b[3],Vfloat c[3],Vfloat radius,
Vfloat height);VKI_EXTERN void vis_ASurfSetCylinderdv(vis_ASurf*
p,Vdouble a[3],Vdouble b[3],Vdouble c[3],Vdouble r,
Vdouble height);VKI_EXTERN void vis_ASurfGetCylinder(vis_ASurf*
p,Vfloat a[3],Vfloat b[3],Vfloat c[3],Vfloat* r,Vfloat*
height);VKI_EXTERN void vis_ASurfGetCylinderdv(vis_ASurf*
p,Vdouble a[3],Vdouble b[3],Vdouble c[3],Vdouble* r,
Vdouble* height);VKI_EXTERN void vis_ASurfSetCone(vis_ASurf*
p,Vfloat a[3],Vfloat b[3],Vfloat c[3],Vfloat r1,Vfloat
r2,Vfloat height);VKI_EXTERN void vis_ASurfSetConedv(vis_ASurf*
p,Vdouble a[3],Vdouble b[3],Vdouble c[3],Vdouble r1,
Vdouble r2,Vdouble height);VKI_EXTERN void vis_ASurfGetCone(vis_ASurf*
p,Vfloat a[3],Vfloat b[3],Vfloat c[3],Vfloat* r1,Vfloat*
r2,Vfloat* height);VKI_EXTERN void vis_ASurfGetConedv(vis_ASurf*
p,Vdouble a[3],Vdouble b[3],Vdouble c[3],Vdouble* r1,
Vdouble* r2,Vdouble* height);VKI_EXTERN void vis_ASurfSetSphere(vis_ASurf*
p,Vfloat c[3],Vfloat r);VKI_EXTERN void vis_ASurfSetSpheredv(vis_ASurf*
p,Vdouble c[3],Vdouble r);VKI_EXTERN void vis_ASurfGetSphere(vis_ASurf*
p,Vfloat c[3],Vfloat* r);VKI_EXTERN void vis_ASurfGetSpheredv(vis_ASurf*
p,Vdouble c[3],Vdouble* r);VKI_EXTERN void vis_ASurfPrint(vis_ASurf*
p);VKI_EXTERN void vis_ASurfSetNURBS(vis_ASurf* p,Vint
id,Vint type,Vint nptu,Vint nordu,Vint nptv,Vint nordv,
Vint ix[],Vfloat homo[],Vfloat knots[],Vint ntrim,Vint
trimlist[]);VKI_EXTERN void vis_ASurfSetNURBSdv(vis_ASurf*
p,Vint id,Vint type,Vint nptu,Vint nordu,Vint nptv,
Vint nordv,Vint ix[],Vdouble homos[],Vdouble knots[],
Vint ntrim,Vint trimlist[]);VKI_EXTERN void vis_ASurfNumNURBS(vis_ASurf*
p,Vint* numnurbs);VKI_EXTERN void vis_ASurfMaxNURBSOrder(vis_ASurf*
p,Vint* maxord);VKI_EXTERN void vis_ASurfGetNURBSNum(vis_ASurf*
p,Vint id,Vint* type,Vint* nptu,Vint* nordu,Vint* nptv,
Vint* nordv,Vint* ntrim);VKI_EXTERN void vis_ASurfGetNURBS(vis_ASurf*
p,Vint id,Vint* type,Vint* nptu,Vint* nordu,Vint* nptv,
Vint* nordv,Vint ix[],Vfloat homos[],Vfloat knots[],
Vint* ntrim,Vint trimlist[]);VKI_EXTERN void vis_ASurfGetNURBSdv(vis_ASurf*
p,Vint id,Vint* type,Vint* nptu,Vint* nordu,Vint* nptv,
Vint* nordv,Vint ix[],Vdouble homos[],Vdouble knots[],
Vint* ntrim,Vint trimlist[]);VKI_EXTERN void vis_ASurfSetNURBSTrim(vis_ASurf*
p,Vint id,Vint npts,Vint ix[]);VKI_EXTERN void vis_ASurfNumNURBSTrim(vis_ASurf*
p,Vint* numtrim);VKI_EXTERN void vis_ASurfGetNURBSTrimNum(vis_ASurf*
p,Vint id,Vint* npts);VKI_EXTERN void vis_ASurfGetNURBSTrim(vis_ASurf*
p,Vint id,Vint* npts,Vint ix[]);VKI_EXTERN void vis_ASurfSetFacet(vis_ASurf*
p,Vint id,Vint type,Vint ix[]);VKI_EXTERN void vis_ASurfNumFacets(vis_ASurf*
p,Vint* numfacet);VKI_EXTERN void vis_ASurfGetFacet(vis_ASurf*
p,Vint id,Vint* type,Vint ix[]);
#ifdef __cplusplus
}
#endif
#endif

