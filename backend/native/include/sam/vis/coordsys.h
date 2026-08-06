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
 
#ifndef COORDSYS_DEF
#define COORDSYS_DEF
#include "sam/base/base.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/idtran.h"
#include "sam/vis/gridfun.h"
#define COORDSYS_XAXIS_XYPLANE 0
#define COORDSYS_XAXIS_XZPLANE 1
#define COORDSYS_ZAXIS_XZPLANE 2
struct vis_CoordSys { Vint ierr;Vint type;Vint sour;
Vint iop;Vint resolve;vsy_HashTable* ht;vis_IdTran*
dtnode;vis_GridFun* gf;Vint gid[3];Vint rcid;Vdouble
xa[3][3];Vdouble x[3];Vdouble tm[3][3];Vdouble radius;
Vint idirs;Vdouble xcs;Vint isens;vsy_CSystem* csystem;
vsy_PropSet* ps;Vint cid;Vchar* name;
#ifdef __cplusplus
public: VKI_EXTERN vis_CoordSys(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_CoordSys(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void SetObject(Vint,Vobject*);VKI_EXTERN
void GetObject(Vint,Vobject**);VKI_EXTERN void Def(Vint);
VKI_EXTERN void Inq(Vint*)const;VKI_EXTERN void SetNode(Vint,
Vint,Vint,Vint);VKI_EXTERN void SetCoord(Vint,Vfloat[3],
Vfloat[3],Vfloat[3],Vint);VKI_EXTERN void SetCoorddv(Vint,
Vdouble[3],Vdouble[3],Vdouble[3],Vint);VKI_EXTERN void
SetOriginZAxis(Vfloat[3],Vfloat[3]);VKI_EXTERN void
SetOriginZAxisdv(Vdouble[3],Vdouble[3]);VKI_EXTERN void
SetOriginVectors(Vfloat[3],Vfloat[3],Vfloat[3]);VKI_EXTERN
void SetOriginVectorsdv(Vdouble[3],Vdouble[3],Vdouble[3]);
VKI_EXTERN void SetOriginRotAng(Vfloat[3],Vfloat[3]);
VKI_EXTERN void SetOriginRotAngdv(Vdouble[3],Vdouble[3]);
VKI_EXTERN void SetOriginTriad(Vfloat[3],Vfloat[3][3]);
VKI_EXTERN void SetOriginTriaddv(Vdouble[3],Vdouble[3][3]);
VKI_EXTERN void SetRadius(Vfloat);VKI_EXTERN void SetRadiusdv(Vdouble);
VKI_EXTERN void GetRadiusdv(Vdouble*);VKI_EXTERN void
SetSurface(Vint,Vfloat);VKI_EXTERN void SetSurfacedv(Vint,
Vdouble);VKI_EXTERN void GetSurfacedv(Vint*,Vdouble*);
VKI_EXTERN void SetSurfaceSense(Vint);VKI_EXTERN void
GetSurfaceSense(Vint*);VKI_EXTERN void ChkSurfacedv(Vdouble,
Vdouble[3],Vdouble[3],Vint*);VKI_EXTERN void Resolve(Vint*);
VKI_EXTERN void DirCos(Vfloat[3],Vfloat[3][3]);VKI_EXTERN
void DirCosdv(Vdouble[3],Vdouble[3][3]);VKI_EXTERN void
RotAng(Vfloat[3],Vfloat[3]);VKI_EXTERN void RotAngdv(Vdouble[3],
Vdouble[3]);VKI_EXTERN void OriginTriad(Vfloat[3],Vfloat[3][3]);
VKI_EXTERN void OriginTriaddv(Vdouble[3],Vdouble[3][3]);
VKI_EXTERN void OriginRotAng(Vfloat[3],Vfloat[3]);VKI_EXTERN
void OriginRotAngdv(Vdouble[3],Vdouble[3]);VKI_EXTERN
void ConvertCoord(Vfloat[3],Vfloat[3]);VKI_EXTERN void
ConvertCoorddv(Vdouble[3],Vdouble[3]);VKI_EXTERN void
ComputeCoord(Vfloat[3],Vfloat[3]);VKI_EXTERN void ComputeCoorddv(Vdouble[3],
Vdouble[3]);VKI_EXTERN void ProjSurfacedv(Vdouble[3],
Vdouble[3]);VKI_EXTERN void NormSurfacedv(Vdouble[3],
Vdouble[3]);VKI_EXTERN void ComputeVector(Vfloat[3],
Vfloat[3],Vfloat[3]);VKI_EXTERN void ComputeVectordv(Vdouble[3],
Vdouble[3],Vdouble[3]);VKI_EXTERN void ComputeTensor(Vfloat[3],
Vfloat[6],Vfloat[6]);VKI_EXTERN void ComputeTensordv(Vdouble[3],
Vdouble[6],Vdouble[6]);VKI_EXTERN void ComputeMatrix(Vfloat[3],
Vfloat[9],Vfloat[9]);VKI_EXTERN void ComputeMatrixdv(Vdouble[3],
Vdouble[9],Vdouble[9]);VKI_EXTERN void ConvertVector(Vfloat[3],
Vfloat[3],Vfloat[3]);VKI_EXTERN void ConvertVectordv(Vdouble[3],
Vdouble[3],Vdouble[3]);VKI_EXTERN void ConvertTensor(Vfloat[3],
Vfloat[6],Vfloat[6]);VKI_EXTERN void ConvertTensordv(Vdouble[3],
Vdouble[6],Vdouble[6]);VKI_EXTERN void ConvertMatrix(Vfloat[3],
Vfloat[9],Vfloat[9]);VKI_EXTERN void ConvertMatrixdv(Vdouble[3],
Vdouble[9],Vdouble[9]);VKI_EXTERN void LineInterpolatedv(Vdouble[2][3],
Vdouble,Vdouble[3]);VKI_EXTERN void QuadSurfaceCoord(Vdouble[4][3],
Vdouble[4][3],Vdouble*,Vdouble*);VKI_EXTERN void GetCSystem(vsy_CSystem**);
VKI_EXTERN void SetId(Vint);VKI_EXTERN void GetId(Vint*);
VKI_EXTERN void SetName(const Vchar*);VKI_EXTERN void
GetName(Vchar[]);VKI_EXTERN void Print();VKI_EXTERN
void Copy(vis_CoordSys*);VKI_EXTERN void Transform(Vdouble[3],
Vdouble[3][3]);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_CoordSys* vis_CoordSysBegin(void);VKI_EXTERN
void vis_CoordSys_Construct(vis_CoordSys* p);VKI_EXTERN
void vis_CoordSysEnd(vis_CoordSys* p);VKI_EXTERN void
vis_CoordSys_Destruct(vis_CoordSys* p);VKI_EXTERN Vint
vis_CoordSysError(vis_CoordSys* p);VKI_EXTERN void vis_CoordSysSetObject(vis_CoordSys*
p,Vint objecttype,Vobject* object);VKI_EXTERN void vis_CoordSysGetObject(vis_CoordSys*
p,Vint objecttype,Vobject** object);VKI_EXTERN void
vis_CoordSysDef(vis_CoordSys* p,Vint type);VKI_EXTERN
void vis_CoordSysInq(const vis_CoordSys* p,Vint* type);
VKI_EXTERN void vis_CoordSysSetNode(vis_CoordSys* p,
Vint iop,Vint gid1,Vint gid2,Vint gid3);VKI_EXTERN void
vis_CoordSysSetCoord(vis_CoordSys* p,Vint iop,Vfloat
x1[3],Vfloat x2[3],Vfloat x3[3],Vint rcid);VKI_EXTERN
void vis_CoordSysSetCoorddv(vis_CoordSys* p,Vint iop,
Vdouble x1[3],Vdouble x2[3],Vdouble x3[3],Vint rcid);
VKI_EXTERN void vis_CoordSysSetOriginZAxis(vis_CoordSys*
p,Vfloat x[3],Vfloat zv[3]);VKI_EXTERN void vis_CoordSysSetOriginZAxisdv(vis_CoordSys*
p,Vdouble x[3],Vdouble zv[3]);VKI_EXTERN void vis_CoordSysSetOriginVectors(vis_CoordSys*
p,Vfloat x[3],Vfloat v1[3],Vfloat v2[3]);VKI_EXTERN
void vis_CoordSysSetOriginVectorsdv(vis_CoordSys* p,
Vdouble x[3],Vdouble xa[3],Vdouble ya[3]);VKI_EXTERN
void vis_CoordSysSetOriginRotAng(vis_CoordSys* p,Vfloat
x[3],Vfloat ra[3]);VKI_EXTERN void vis_CoordSysSetOriginRotAngdv(vis_CoordSys*
p,Vdouble x[3],Vdouble rotang[3]);VKI_EXTERN void vis_CoordSysSetOriginTriad(vis_CoordSys*
p,Vfloat x[3],Vfloat tm[3][3]);VKI_EXTERN void vis_CoordSysSetOriginTriaddv(vis_CoordSys*
p,Vdouble x[3],Vdouble tm[3][3]);VKI_EXTERN void vis_CoordSysSetRadius(vis_CoordSys*
p,Vfloat radius);VKI_EXTERN void vis_CoordSysSetRadiusdv(vis_CoordSys*
p,Vdouble radius);VKI_EXTERN void vis_CoordSysGetRadiusdv(vis_CoordSys*
p,Vdouble* radius);VKI_EXTERN void vis_CoordSysSetSurface(vis_CoordSys*
p,Vint idir,Vfloat xc);VKI_EXTERN void vis_CoordSysSetSurfacedv(vis_CoordSys*
p,Vint idir,Vdouble xc);VKI_EXTERN void vis_CoordSysGetSurfacedv(vis_CoordSys*
p,Vint* idir,Vdouble* xc);VKI_EXTERN void vis_CoordSysSetSurfaceSense(vis_CoordSys*
p,Vint isens);VKI_EXTERN void vis_CoordSysGetSurfaceSense(vis_CoordSys*
p,Vint* isens);VKI_EXTERN void vis_CoordSysChkSurfacedv(vis_CoordSys*
p,Vdouble cl,Vdouble x[3],Vdouble v[3],Vint* flag);
VKI_EXTERN void vis_CoordSysResolve(vis_CoordSys* p,
Vint* resolve);VKI_EXTERN void vis_CoordSysDirCos(vis_CoordSys*
p,Vfloat x[3],Vfloat tm[3][3]);VKI_EXTERN void vis_CoordSysDirCosdv(vis_CoordSys*
p,Vdouble x[3],Vdouble tm[3][3]);VKI_EXTERN void vis_CoordSysRotAng(vis_CoordSys*
p,Vfloat x[3],Vfloat ra[3]);VKI_EXTERN void vis_CoordSysRotAngdv(vis_CoordSys*
p,Vdouble x[3],Vdouble rotang[3]);VKI_EXTERN void vis_CoordSysOriginTriad(vis_CoordSys*
p,Vfloat x[3],Vfloat tm[3][3]);VKI_EXTERN void vis_CoordSysOriginTriaddv(vis_CoordSys*
p,Vdouble x[3],Vdouble tm[3][3]);VKI_EXTERN void vis_CoordSysOriginRotAng(vis_CoordSys*
p,Vfloat x[3],Vfloat rotang[3]);VKI_EXTERN void vis_CoordSysOriginRotAngdv(vis_CoordSys*
p,Vdouble x[3],Vdouble rotang[3]);VKI_EXTERN void vis_CoordSysConvertCoord(vis_CoordSys*
p,Vfloat x[3],Vfloat xl[3]);VKI_EXTERN void vis_CoordSysConvertCoorddv(vis_CoordSys*
p,Vdouble x[3],Vdouble xl[3]);VKI_EXTERN void vis_CoordSysComputeCoord(vis_CoordSys*
p,Vfloat xl[3],Vfloat x[3]);VKI_EXTERN void vis_CoordSysComputeCoorddv(vis_CoordSys*
p,Vdouble x[3],Vdouble xg[3]);VKI_EXTERN void vis_CoordSysProjSurfacedv(vis_CoordSys*
p,Vdouble x[3],Vdouble xp[3]);VKI_EXTERN void vis_CoordSysNormSurfacedv(vis_CoordSys*
p,Vdouble x[3],Vdouble v[3]);VKI_EXTERN void vis_CoordSysComputeVector(vis_CoordSys*
p,Vfloat x[3],Vfloat vl[3],Vfloat v[3]);VKI_EXTERN void
vis_CoordSysComputeVectordv(vis_CoordSys* p,Vdouble
x[3],Vdouble t[3],Vdouble tg[3]);VKI_EXTERN void vis_CoordSysComputeTensor(vis_CoordSys*
p,Vfloat x[3],Vfloat tl[6],Vfloat t[6]);VKI_EXTERN void
vis_CoordSysComputeTensordv(vis_CoordSys* p,Vdouble
x[3],Vdouble t[6],Vdouble tg[6]);VKI_EXTERN void vis_CoordSysComputeMatrix(vis_CoordSys*
p,Vfloat x[3],Vfloat gl[9],Vfloat g[9]);VKI_EXTERN void
vis_CoordSysComputeMatrixdv(vis_CoordSys* p,Vdouble
x[3],Vdouble t[9],Vdouble tg[9]);VKI_EXTERN void vis_CoordSysConvertVector(vis_CoordSys*
p,Vfloat x[3],Vfloat v[3],Vfloat vl[3]);VKI_EXTERN void
vis_CoordSysConvertVectordv(vis_CoordSys* p,Vdouble
x[3],Vdouble t[3],Vdouble tl[3]);VKI_EXTERN void vis_CoordSysConvertTensor(vis_CoordSys*
p,Vfloat x[3],Vfloat t[6],Vfloat tl[6]);VKI_EXTERN void
vis_CoordSysConvertTensordv(vis_CoordSys* p,Vdouble
x[3],Vdouble t[6],Vdouble tl[6]);VKI_EXTERN void vis_CoordSysConvertMatrix(vis_CoordSys*
p,Vfloat x[3],Vfloat g[9],Vfloat gl[9]);VKI_EXTERN void
vis_CoordSysConvertMatrixdv(vis_CoordSys* p,Vdouble
x[3],Vdouble t[9],Vdouble tl[9]);VKI_EXTERN void vis_CoordSysLineInterpolatedv(vis_CoordSys*
p,Vdouble xl[2][3],Vdouble s,Vdouble x[3]);VKI_EXTERN
void vis_CoordSysQuadSurfaceCoord(vis_CoordSys* p,Vdouble
x[4][3],Vdouble xs[4][3],Vdouble* cho,Vdouble* chs);
VKI_EXTERN void vis_CoordSysGetCSystem(vis_CoordSys*
p,vsy_CSystem** csystem);VKI_EXTERN void vis_CoordSysSetId(vis_CoordSys*
p,Vint id);VKI_EXTERN void vis_CoordSysGetId(vis_CoordSys*
p,Vint* id);VKI_EXTERN void vis_CoordSysSetName(vis_CoordSys*
p,const Vchar* name);VKI_EXTERN void vis_CoordSysGetName(vis_CoordSys*
p,Vchar name[]);VKI_EXTERN void vis_CoordSysPrint(vis_CoordSys*
p);VKI_EXTERN void vis_CoordSysCopy(vis_CoordSys* p,
vis_CoordSys* q);VKI_EXTERN void vis_CoordSysTransform(vis_CoordSys*
p,Vdouble u[3],Vdouble tm[3][3]);
#ifdef __cplusplus
}
#endif
#endif

