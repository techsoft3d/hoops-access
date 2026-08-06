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
 
#ifndef ELEMCHK_DEF
#define ELEMCHK_DEF
#include "sam/base/base.h"
#include "sam/vis/gridfun.h"
#include "sam/vis/state.h"
#define ELEMCHK_ALL -1
#define ELEMCHK_JACOBIAN_SUM 0
#define ELEMCHK_JACOBIAN_RATIO 1
#define ELEMCHK_JACOBIAN_SMALL 2
#define ELEMCHK_ASPECT_RATIO 3
#define ELEMCHK_FACE_TAPER 4
#define ELEMCHK_SKEW 5
#define ELEMCHK_TWIST 6
#define ELEMCHK_SUBTENDED_ANGLE 7
#define ELEMCHK_CIRCUM_RATIO 8
#define ELEMCHK_MIN_ANGLE 9
#define ELEMCHK_FACE_WARP 10
#define ELEMCHK_CG_X 11
#define ELEMCHK_CG_Y 12
#define ELEMCHK_CG_Z 13
#define ELEMCHK_EDGEALT_RATIO 14
#define ELEMCHK_JACOBIAN_NODAL 15
#define ELEMCHK_DIMENSION 16
#define ELEMCHK_PORDER 17
#define ELEMCHK_H 18
#define ELEMCHK_MAX_ANGLE 19
#define ELEMCHK_MIN_DIHEDANGLE 20
#define ELEMCHK_MAX_DIHEDANGLE 21
#define ELEMCHK_HANDEDNESS 22
#define ELEMCHK_MIN_EDGELENGTH 23
#define ELEMCHK_MAX_EDGELENGTH 24
#define ELEMCHK_CORN_WARP 25
#define ELEMCHK_CORN_SKEW 26
#define ELEMCHK_MIDSIDE_OFF 27
#define ELEMCHK_JACOBIAN_CORN 28
#define ELEMCHK_EDGELENGTH 29
#define ELEMCHK_MAX 30
#define ELEMCHK_CHEAP 1
#define ELEMCHK_ADAPTTOL 1
#define ELEMCHK_MINREFINE 2
struct vis_ElemChk { Vint ierr;Vint fastchk;Vint typeflag[ELEMCHK_MAX];
Vint operationflag[ELEMCHK_MAX];vis_GridFun* gf;Vdouble
adapttol;Vdouble minrefine;
#ifdef __cplusplus
public: VKI_EXTERN vis_ElemChk(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_ElemChk(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void SetObject(Vint,Vobject*);VKI_EXTERN
void SetType(Vint,Vint);VKI_EXTERN void GetType(Vint,
Vint*);VKI_EXTERN void SetParami(Vint,Vint);VKI_EXTERN
void SetParamd(Vint,Vdouble);VKI_EXTERN void Datadv(Vint,
Vdouble[]);VKI_EXTERN void Data(Vint,Vfloat[]);VKI_EXTERN
void Ratedv(vis_State*,vis_Group*,Vint,Vdouble[]);VKI_EXTERN
void Rate(vis_State*,vis_Group*,Vint,Vfloat[]);VKI_EXTERN
void Normdv(vis_Group*,Vint,Vdouble[3],Vint*);VKI_EXTERN
void Norm(vis_Group*,Vint,Vfloat[3],Vint*);VKI_EXTERN
void Delaunay(vis_Group*,Vint,Vint*,Vint[]);VKI_EXTERN
void Adapt(vis_State*,vis_State*,vis_Group*,vis_State*);
VKI_EXTERN void Energy(vis_State*,vis_State*,vis_Group*,
vis_State*,vis_State*);VKI_EXTERN void FaceWeight(vis_Group*,
vis_State*);VKI_EXTERN void CompliesWithShapeParameters(Vint,
Vdouble[ELEMCHK_MAX],Vdouble,Vint*,Vint*);VKI_EXTERN
void FindNonCompliedShapeParameters(Vint,Vdouble[ELEMCHK_MAX],
Vdouble,vsy_BitVec*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_ElemChk* vis_ElemChkBegin(void);VKI_EXTERN
void vis_ElemChk_Construct(vis_ElemChk* p);VKI_EXTERN
void vis_ElemChkEnd(vis_ElemChk* p);VKI_EXTERN void
vis_ElemChk_Destruct(vis_ElemChk* p);VKI_EXTERN Vint
vis_ElemChkError(vis_ElemChk* p);VKI_EXTERN void vis_ElemChkSetObject(vis_ElemChk*
p,Vint objecttype,Vobject* object);VKI_EXTERN void vis_ElemChkSetType(vis_ElemChk*
p,Vint type,Vint flag);VKI_EXTERN void vis_ElemChkGetType(vis_ElemChk*
p,Vint type,Vint* flag);VKI_EXTERN void vis_ElemChkSetParami(vis_ElemChk*
p,Vint ptype,Vint iparam);VKI_EXTERN void vis_ElemChkSetParamd(vis_ElemChk*
p,Vint ptype,Vdouble dparam);VKI_EXTERN void vis_ElemChkDatadv(vis_ElemChk*
p,Vint index,Vdouble s[]);VKI_EXTERN void vis_ElemChkData(vis_ElemChk*
p,Vint index,Vfloat s[]);VKI_EXTERN void vis_ElemChkRatedv(vis_ElemChk*
p,vis_State* state,vis_Group* group,Vint index,Vdouble
s[]);VKI_EXTERN void vis_ElemChkRate(vis_ElemChk* p,
vis_State* state,vis_Group* group,Vint index,Vfloat
s[]);VKI_EXTERN void vis_ElemChkNormdv(vis_ElemChk*
p,vis_Group* group,Vint index,Vdouble vn[3],Vint* edgeflags);
VKI_EXTERN void vis_ElemChkNorm(vis_ElemChk* p,vis_Group*
group,Vint index,Vfloat vn[3],Vint* edgeflags);VKI_EXTERN
void vis_ElemChkDelaunay(vis_ElemChk* p,vis_Group* group,
Vint index,Vint* nixn,Vint ixn[]);VKI_EXTERN void vis_ElemChkAdapt(vis_ElemChk*
p,vis_State* setot,vis_State* seerr,vis_Group* group,
vis_State* esize);VKI_EXTERN void vis_ElemChkEnergy(vis_ElemChk*
p,vis_State* stress,vis_State* strain,vis_Group* group,
vis_State* setot,vis_State* seerr);VKI_EXTERN void vis_ElemChkFaceWeight(vis_ElemChk*
p,vis_Group* group,vis_State* nweight);VKI_EXTERN void
vis_ElemChkCompliesWithShapeParameters(vis_ElemChk*
p,Vint index,Vdouble targetShapeParameters[ELEMCHK_MAX],
Vdouble relativeTolerance,Vint* areShapeParametersCompliant,
Vint* nonCompliantShapeParameter);VKI_EXTERN void vis_ElemChkFindNonCompliedShapeParameters(vis_ElemChk*
p,Vint index,Vdouble targetShapeParameters[ELEMCHK_MAX],
Vdouble relativeTolerance,vsy_BitVec* shapeParameterCompliantFlags);
#ifdef __cplusplus
}
#endif
#endif

