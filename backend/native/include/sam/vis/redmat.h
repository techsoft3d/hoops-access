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
/* RedMat object */

#ifndef REDMAT_DEF
#define REDMAT_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"

struct vis_RedMat {
    Vint ierr;
    Vint prec;
    Vint complexmode;
    Vint complexflag;
    Vint type;
    Vint ndofs;
    Vint nval;
    Vlong lrec;
    Vlong* pointers;
    Vint* indices;
    Vint* nid;
    Vint* doftag;
    Vdouble* ddata;
    Vdouble* ddatai;
    Vfloat* fdata;
    Vfloat* fdatai;
    Vint cacherow;
    Vint cachecol;
    Vint kernel;
    Vint* count;
#ifdef __cplusplus
  public:
    VKI_EXTERN
    vis_RedMat(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vis_RedMat(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void Pre(Vint);
    VKI_EXTERN void
    GetPre(Vint*);
    VKI_EXTERN void Def(Vint, Vint);
    VKI_EXTERN void
    Inq(Vint*, Vint*);
    VKI_EXTERN void SetComplexMode(Vint);
    VKI_EXTERN void
    GetComplexMode(Vint*);
    VKI_EXTERN void
    GetComplex(Vint*);
    VKI_EXTERN void SetDatadv(Vint, Vint, Vdouble[]);
    VKI_EXTERN void SetData(Vint, Vint, Vfloat[]);
    VKI_EXTERN void Datadv(Vint, Vint, Vdouble[]);
    VKI_EXTERN void Data(Vint, Vint, Vfloat[]);
    VKI_EXTERN void
    Print();
    VKI_EXTERN void SetDof(Vint, Vint, Vint);
    VKI_EXTERN void
    GetDof(Vint, Vint*, Vint*);
    VKI_EXTERN void
    Num(Vlong*, Vint*);
    VKI_EXTERN void
    Sparse(Vint*);
    VKI_EXTERN void Ithdv(Vlong, Vdouble[]);
    VKI_EXTERN void Ith(Vlong, Vfloat[]);
    VKI_EXTERN void SetDataSize(Vint, Vint);
    VKI_EXTERN void
    GetDataSize(Vint, Vint*);
    VKI_EXTERN void
    DataCols(Vint, Vint*, Vint[]);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_RedMat*
vis_RedMatBegin(void);
VKI_EXTERN void
vis_RedMat_Construct(vis_RedMat* p);
VKI_EXTERN void
vis_RedMatEnd(vis_RedMat* p);
VKI_EXTERN void
vis_RedMat_Destruct(vis_RedMat* p);
VKI_EXTERN Vint
vis_RedMatError(vis_RedMat* p);
VKI_EXTERN void
vis_RedMatPre(vis_RedMat* p, Vint prec);
VKI_EXTERN void
vis_RedMatGetPre(vis_RedMat* p, Vint* prec);
VKI_EXTERN void
vis_RedMatDef(vis_RedMat* p, Vint ndofs, Vint type);
VKI_EXTERN void
vis_RedMatInq(vis_RedMat* p, Vint* ndofs, Vint* type);
VKI_EXTERN void
vis_RedMatSetComplexMode(vis_RedMat* p, Vint complexmode);
VKI_EXTERN void
vis_RedMatGetComplexMode(vis_RedMat* p, Vint* complexmode);
VKI_EXTERN void
vis_RedMatGetComplex(vis_RedMat* p, Vint* complexflag);
VKI_EXTERN void
vis_RedMatSetDatadv(vis_RedMat* p, Vint i, Vint j, Vdouble v[]);
VKI_EXTERN void
vis_RedMatSetData(vis_RedMat* p, Vint idof, Vint jdof, Vfloat v[]);
VKI_EXTERN void
vis_RedMatDatadv(vis_RedMat* p, Vint i, Vint j, Vdouble v[]);
VKI_EXTERN void
vis_RedMatData(vis_RedMat* p, Vint idof, Vint jdof, Vfloat v[]);
VKI_EXTERN void
vis_RedMatPrint(vis_RedMat* p);
VKI_EXTERN void
vis_RedMatSetDof(vis_RedMat* p, Vint dof, Vint index, Vint doftag);
VKI_EXTERN void
vis_RedMatGetDof(vis_RedMat* p, Vint dof, Vint* nid, Vint* doftag);
VKI_EXTERN void
vis_RedMatNum(vis_RedMat* p, Vlong* nent, Vint* nval);
VKI_EXTERN void
vis_RedMatSparse(vis_RedMat* p, Vint* sparse);
VKI_EXTERN void
vis_RedMatIthdv(vis_RedMat* p, Vlong i, Vdouble v[]);
VKI_EXTERN void
vis_RedMatIth(vis_RedMat* p, Vlong i, Vfloat v[]);
VKI_EXTERN void
vis_RedMatSetDataSize(vis_RedMat* p, Vint idof, Vint ncols);
VKI_EXTERN void
vis_RedMatGetDataSize(vis_RedMat* p, Vint i, Vint* size);
VKI_EXTERN void
vis_RedMatDataCols(vis_RedMat* p, Vint idof, Vint* ncols, Vint icols[]);

#ifdef __cplusplus
}
#endif

#endif
