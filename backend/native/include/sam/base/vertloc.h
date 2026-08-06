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
 
#ifndef VERTLOC_DEF
#define VERTLOC_DEF
#include "sam/base/basedefs.h"
#define VERTLOC_TOL 1
#define VERTLOC_NTOL 2
#define VERTLOC_NORMALATT 3
#define VERTLOC_COLORTRANSATT 4
struct vsy_VertLoc { Vint ierr;Vint numvert;Vint maxvert;
Vint maxvlst;Vfloat (*x)[3];Vchar* vtdf;Vfloat tol;
Vfloat atol;Vfloat ntol;Vint nattflag;Vint ctattflag;
Vint merged;Vint numunique;Vint maxlocate;Vint ncanc;
Vint iproc;Vfloat ct[4];Vfloat vn[3];Vint* vertlow;
Vint* vertuni;Vint* vertunp;Vint* vertunn;Vint* vertinv;
Vint* vertct;Vint* vertvn;
#ifdef __cplusplus
public: VKI_EXTERN vsy_VertLoc(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_VertLoc(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void SetParamf(Vint,Vfloat);VKI_EXTERN
void SetParami(Vint,Vint);VKI_EXTERN void SetColor(Vfloat[3]);
VKI_EXTERN void SetTrans(Vfloat);VKI_EXTERN void SetNormal(Vfloat[3]);
VKI_EXTERN void Insert(Vint,Vfloat[3]);VKI_EXTERN void
Ref(Vint,Vfloat[3]);VKI_EXTERN void Num(Vint*);VKI_EXTERN
void Color(Vint,Vfloat[3]);VKI_EXTERN void Trans(Vint,
Vfloat*);VKI_EXTERN void Normal(Vint,Vfloat[3]);VKI_EXTERN
void Clear();VKI_EXTERN void Merge(Vint*,Vint*);VKI_EXTERN
void Unique(Vint,Vint*,Vint[]);VKI_EXTERN void Lowest(Vint,
Vint*,Vint*);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_VertLoc* vsy_VertLocBegin(void);VKI_EXTERN
void vsy_VertLoc_Construct(vsy_VertLoc* p);VKI_EXTERN
void vsy_VertLocEnd(vsy_VertLoc* p);VKI_EXTERN void
vsy_VertLoc_Destruct(vsy_VertLoc* p);VKI_EXTERN Vint
vsy_VertLocError(vsy_VertLoc* p);VKI_EXTERN void vsy_VertLocDef(vsy_VertLoc*
p,Vint numvert);VKI_EXTERN void vsy_VertLocInq(const
vsy_VertLoc* p,Vint* numvert);VKI_EXTERN void vsy_VertLocSetParamf(vsy_VertLoc*
p,Vint ptype,Vfloat fparam);VKI_EXTERN void vsy_VertLocSetParami(vsy_VertLoc*
p,Vint ptype,Vint iparam);VKI_EXTERN void vsy_VertLocSetColor(vsy_VertLoc*
p,Vfloat c[3]);VKI_EXTERN void vsy_VertLocSetTrans(vsy_VertLoc*
p,Vfloat t);VKI_EXTERN void vsy_VertLocSetNormal(vsy_VertLoc*
p,Vfloat v[3]);VKI_EXTERN void vsy_VertLocInsert(vsy_VertLoc*
p,Vint index,Vfloat x[3]);VKI_EXTERN void vsy_VertLocRef(vsy_VertLoc*
p,Vint index,Vfloat x[3]);VKI_EXTERN void vsy_VertLocNum(vsy_VertLoc*
p,Vint* numvert);VKI_EXTERN void vsy_VertLocColor(vsy_VertLoc*
p,Vint index,Vfloat c[3]);VKI_EXTERN void vsy_VertLocTrans(vsy_VertLoc*
p,Vint index,Vfloat* t);VKI_EXTERN void vsy_VertLocNormal(vsy_VertLoc*
p,Vint index,Vfloat v[3]);VKI_EXTERN void vsy_VertLocClear(vsy_VertLoc*
p);VKI_EXTERN void vsy_VertLocMerge(vsy_VertLoc* p,
Vint* numunique,Vint* maxlocate);VKI_EXTERN void vsy_VertLocUnique(vsy_VertLoc*
p,Vint iunique,Vint* nix,Vint ix[]);VKI_EXTERN void
vsy_VertLocLowest(vsy_VertLoc* p,Vint index,Vint* iunique,
Vint* lowestindex);VKI_EXTERN void vsy_VertLocPrint(vsy_VertLoc*
p);
#ifdef __cplusplus
}
#endif
#endif

