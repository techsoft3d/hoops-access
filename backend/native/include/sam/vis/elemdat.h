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
 
#ifndef ELEMDAT_DEF
#define ELEMDAT_DEF
#include "sam/base/base.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/gridfun.h"
#include "sam/vis/group.h"
struct vis_ElemDat { Vint ierr;Vint ipre;Vint nument;
Vint enttype;Vint subtype;Vint datatype;Vint complexmode;
Vint complexflag;Vint linnormal;vis_GridFun* gf;Vint
lng,nent;Vfloat featureangle;Vint featurebranch;vsy_List*
listdat;vsy_VHashTable* hashdat;Vint nrows;
#ifdef __cplusplus
public: VKI_EXTERN vis_ElemDat(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_ElemDat(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Pre(Vint);VKI_EXTERN void GetPre(Vint*);
VKI_EXTERN void SetObject(Vint,Vobject*);VKI_EXTERN
void GetObject(Vint,Vobject**);VKI_EXTERN void Def(Vint,
Vint,Vint,Vint);VKI_EXTERN void Inq(Vint*,Vint*,Vint*,
Vint*)const;VKI_EXTERN void SetParami(Vint,Vint);VKI_EXTERN
void SetParamf(Vint,Vfloat);VKI_EXTERN void SetComplexMode(Vint);
VKI_EXTERN void GetComplexMode(Vint*);VKI_EXTERN void
GetComplex(Vint*);VKI_EXTERN void SetData(Vint,Vint,
Vfloat[]);VKI_EXTERN void SetDatadv(Vint,Vint,Vdouble[]);
VKI_EXTERN void Lng(Vint*,Vint*)const;VKI_EXTERN void
Data(Vint,Vint,Vfloat[])const;VKI_EXTERN void Datadv(Vint,
Vint,Vdouble[])const;VKI_EXTERN void Clear();VKI_EXTERN
void DataStat(Vint,Vint,Vint*)const;VKI_EXTERN void
Normal(vis_Group*);VKI_EXTERN void IdTran(Vint,vis_IdTran*);
VKI_EXTERN void Write(vis_RProp*,Vint,Vchar*);VKI_EXTERN
void Copy(vis_ElemDat*);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_ElemDat* vis_ElemDatBegin(void);VKI_EXTERN
void vis_ElemDat_Construct(vis_ElemDat* p);VKI_EXTERN
void vis_ElemDatEnd(vis_ElemDat* p);VKI_EXTERN void
vis_ElemDat_Destruct(vis_ElemDat* p);VKI_EXTERN Vint
vis_ElemDatError(vis_ElemDat* p);VKI_EXTERN void vis_ElemDatPre(vis_ElemDat*
p,Vint ipre);VKI_EXTERN void vis_ElemDatGetPre(vis_ElemDat*
p,Vint* ipre);VKI_EXTERN void vis_ElemDatSetObject(vis_ElemDat*
p,Vint objecttype,Vobject* object);VKI_EXTERN void vis_ElemDatGetObject(vis_ElemDat*
p,Vint objecttype,Vobject** object);VKI_EXTERN void
vis_ElemDatDef(vis_ElemDat* p,Vint nument,Vint enttype,
Vint subtype,Vint datatype);VKI_EXTERN void vis_ElemDatInq(const
vis_ElemDat* p,Vint* nument,Vint* enttype,Vint* subtype,
Vint* datatype);VKI_EXTERN void vis_ElemDatSetParami(vis_ElemDat*
p,Vint type,Vint iparam);VKI_EXTERN void vis_ElemDatSetParamf(vis_ElemDat*
p,Vint type,Vfloat param);VKI_EXTERN void vis_ElemDatSetComplexMode(vis_ElemDat*
p,Vint complexmode);VKI_EXTERN void vis_ElemDatGetComplexMode(vis_ElemDat*
p,Vint* complexmode);VKI_EXTERN void vis_ElemDatGetComplex(vis_ElemDat*
p,Vint* flag);VKI_EXTERN void vis_ElemDatSetData(vis_ElemDat*
p,Vint id,Vint no,Vfloat s[]);VKI_EXTERN void vis_ElemDatSetDatadv(vis_ElemDat*
p,Vint id,Vint no,Vdouble s[]);VKI_EXTERN void vis_ElemDatLng(const
vis_ElemDat* p,Vint* lng,Vint* nent);VKI_EXTERN void
vis_ElemDatData(const vis_ElemDat* p,Vint id,Vint no,
Vfloat s[]);VKI_EXTERN void vis_ElemDatDatadv(const
vis_ElemDat* p,Vint id,Vint no,Vdouble s[]);VKI_EXTERN
void vis_ElemDatClear(vis_ElemDat* p);VKI_EXTERN void
vis_ElemDatDataStat(const vis_ElemDat* p,Vint id,Vint
no,Vint* stat);VKI_EXTERN void vis_ElemDatNormal(vis_ElemDat*
p,vis_Group* group);VKI_EXTERN void vis_ElemDatIdTran(vis_ElemDat*
p,Vint oper,vis_IdTran* idtran);VKI_EXTERN void vis_ElemDatWrite(vis_ElemDat*
p,vis_RProp* rprop,Vint type,Vchar* path);VKI_EXTERN
void vis_ElemDatCopy(vis_ElemDat* p,vis_ElemDat* fromp);
VKI_EXTERN void vis_ElemDatPrint(vis_ElemDat* p);
#ifdef __cplusplus
}
#endif
#endif

