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
 
#ifndef DATASET_DEF
#define DATASET_DEF
#define DATASET_MAXNAME SYS_MAXNAME
#include "sam/base/basedefs.h"
#include "sam/base/list.h"
#include "sam/base/regexp.h"
#include "sam/vdm/attribute.h"
#include "sam/vis/resultmetadata.h"
struct vdm_Dataset { Vint ierr;Vchar* name;Vlong lrec;
Vint nrow;Vint ncol;Vint type;Vint dstype;Vint numatt;
vsy_List* list;Vchar* root;Vint hist;Vint rtype;Vint
nqua;Vint iqua[SYS_NQUA_MAX];Vchar* cqua;Vint cplx;
Vint sect;Vchar* caux;Vint enttype,subtype;Vint id1,
id2,id3;vsy_RegExp* regexp;Vint numint;Vint* ints;Vobject*
obj;Vobject* lib;
#ifdef __cplusplus
public: VKI_EXTERN vdm_Dataset(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_Dataset(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(const Vchar*,Vlong,Vint,
Vint,Vint);VKI_EXTERN void Inq(Vchar[],Vlong*,Vint*,
Vint*,Vint*);VKI_EXTERN void Inqi(Vchar[],Vint*,Vint*,
Vint*,Vint*);VKI_EXTERN void GetNRow(Vint*);VKI_EXTERN
void SetNCol(Vint);VKI_EXTERN void GetNCol(Vint*);VKI_EXTERN
void SetLRec(Vlong);VKI_EXTERN void GetLRec(Vlong*);
VKI_EXTERN void GetLReci(Vint*);VKI_EXTERN void SetDTyp(Vint);
VKI_EXTERN void GetDTyp(Vint*);VKI_EXTERN void SetType(Vint);
VKI_EXTERN void GetType(Vint*);VKI_EXTERN void AddAttribute(vdm_Attribute*);
VKI_EXTERN void GetNumAttributes(Vint*);VKI_EXTERN void
GetAttribute(Vint,vdm_Attribute**);VKI_EXTERN void Redef(Vlong,
Vint,Vint);VKI_EXTERN void Rename(const Vchar*);VKI_EXTERN
void GetName(Vchar[]);VKI_EXTERN void SearchAttribute(Vchar*,
Vint,Vint*,Vint*);VKI_EXTERN void Decode(Vchar[],Vint*,
Vint*,Vint*);VKI_EXTERN void Ids(Vint*,Vint*,Vint*);
VKI_EXTERN void EntType(Vint*,Vint*);VKI_EXTERN void
ResType(Vint*);VKI_EXTERN void Sect(Vint*);VKI_EXTERN
void Hist(Vint*);VKI_EXTERN void Cplx(Vint*);VKI_EXTERN
void Qual(Vint*,Vint[],Vchar[]);VKI_EXTERN void QualVal(Vint*,
Vint[],Vint[],Vint[],Vfloat[]);VKI_EXTERN void QualStrings(Vint,
Vchar[],Vchar[]);VKI_EXTERN void CAux(Vchar[]);VKI_EXTERN
void Result(Vchar[],Vint*,Vint*,Vint*,Vint[],Vchar[],
Vint*,Vchar[],Vint*,Vint*,Vint*,Vint*,Vint*,Vint*);
VKI_EXTERN void DataType(Vchar[],Vint*);VKI_EXTERN void
Contents(Vchar[]);VKI_EXTERN void Model(Vchar[]);VKI_EXTERN
void Description(Vchar[]);VKI_EXTERN void Complx(Vint*);
VKI_EXTERN void Dimensions(Vchar[]);VKI_EXTERN void
SetInt(Vint,Vint);VKI_EXTERN void GetInt(Vint,Vint*);
VKI_EXTERN void SetObj(Vobject*);VKI_EXTERN void GetObj(Vobject**);
VKI_EXTERN void EndObj(Vfunc1*);VKI_EXTERN void SetLib(Vobject*);
VKI_EXTERN void GetLib(Vobject**);VKI_EXTERN void EndLib(Vfunc1*);
VKI_EXTERN void StreamNum(Vint*);VKI_EXTERN void StreamSave(void*);
VKI_EXTERN void StreamLoad(void*);VKI_EXTERN void Copy(vdm_Dataset*);
VKI_EXTERN void Print();VKI_EXTERN void GetMetadata(vis_ResultMetadata*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_Dataset* vdm_DatasetBegin(void);VKI_EXTERN
void vdm_Dataset_Construct(vdm_Dataset* p);VKI_EXTERN
void vdm_DatasetEnd(vdm_Dataset* p);VKI_EXTERN void
vdm_Dataset_Destruct(vdm_Dataset* p);VKI_EXTERN Vint
vdm_DatasetError(vdm_Dataset* p);VKI_EXTERN void vdm_DatasetDef(vdm_Dataset*
p,const Vchar* name,Vlong lrec,Vint nrow,Vint ncol,
Vint type);VKI_EXTERN void vdm_DatasetInq(vdm_Dataset*
p,Vchar name[],Vlong* lrec,Vint* nrow,Vint* ncol,Vint*
type);VKI_EXTERN void vdm_DatasetInqi(vdm_Dataset* p,
Vchar name[],Vint* lrec,Vint* nrow,Vint* ncol,Vint*
type);VKI_EXTERN void vdm_DatasetGetNRow(vdm_Dataset*
p,Vint* nrow);VKI_EXTERN void vdm_DatasetGetNCol(vdm_Dataset*
p,Vint* ncol);VKI_EXTERN void vdm_DatasetSetNCol(vdm_Dataset*
p,Vint ncol);VKI_EXTERN void vdm_DatasetSetLRec(vdm_Dataset*
p,Vlong lrec);VKI_EXTERN void vdm_DatasetGetLRec(vdm_Dataset*
p,Vlong* lrec);VKI_EXTERN void vdm_DatasetGetLReci(vdm_Dataset*
p,Vint* lrec);VKI_EXTERN void vdm_DatasetSetDTyp(vdm_Dataset*
p,Vint type);VKI_EXTERN void vdm_DatasetGetDTyp(vdm_Dataset*
p,Vint* type);VKI_EXTERN void vdm_DatasetSetType(vdm_Dataset*
p,Vint dstype);VKI_EXTERN void vdm_DatasetGetType(vdm_Dataset*
p,Vint* dstype);VKI_EXTERN void vdm_DatasetAddAttribute(vdm_Dataset*
p,vdm_Attribute* attribute);VKI_EXTERN void vdm_DatasetGetNumAttributes(vdm_Dataset*
p,Vint* numattributes);VKI_EXTERN void vdm_DatasetGetAttribute(vdm_Dataset*
p,Vint iatt,vdm_Attribute** attribute);VKI_EXTERN void
vdm_DatasetRedef(vdm_Dataset* p,Vlong lrec,Vint nrow,
Vint ncol);VKI_EXTERN void vdm_DatasetRename(vdm_Dataset*
p,const Vchar* name);VKI_EXTERN void vdm_DatasetGetName(vdm_Dataset*
p,Vchar name[]);VKI_EXTERN void vdm_DatasetSearchAttribute(vdm_Dataset*
p,Vchar* name,Vint max,Vint* iatts,Vint* num);VKI_EXTERN
void vdm_DatasetDecode(vdm_Dataset* p,Vchar name[],
Vint* id1,Vint* id2,Vint* id3);VKI_EXTERN void vdm_DatasetIds(vdm_Dataset*
p,Vint* id1,Vint* id2,Vint* id3);VKI_EXTERN void vdm_DatasetEntType(vdm_Dataset*
p,Vint* enttype,Vint* subtype);VKI_EXTERN void vdm_DatasetResType(vdm_Dataset*
p,Vint* type);VKI_EXTERN void vdm_DatasetSect(vdm_Dataset*
p,Vint* sect);VKI_EXTERN void vdm_DatasetHist(vdm_Dataset*
p,Vint* hist);VKI_EXTERN void vdm_DatasetCplx(vdm_Dataset*
p,Vint* cplx);VKI_EXTERN void vdm_DatasetQual(vdm_Dataset*
p,Vint* nqua,Vint iqua[],Vchar cqua[]);VKI_EXTERN void
vdm_DatasetQualVal(vdm_Dataset* p,Vint* nqua,Vint iqua[],
Vint dtyp[],Vint ival[],Vfloat fval[]);VKI_EXTERN void
vdm_DatasetQualStrings(vdm_Dataset* p,Vint iqlr,Vchar
name[],Vchar contents[]);VKI_EXTERN void vdm_DatasetCAux(vdm_Dataset*
p,Vchar caux[]);VKI_EXTERN void vdm_DatasetResult(vdm_Dataset*
p,Vchar root[],Vint* type,Vint* hist,Vint* nqua,Vint
iqua[],Vchar cqua[],Vint* cplx,Vchar caux[],Vint* sect,
Vint* enttype,Vint* subtype,Vint* id1,Vint* id2,Vint*
id3);VKI_EXTERN void vdm_DatasetDataType(vdm_Dataset*
p,Vchar andata[],Vint* datatypeFIX);VKI_EXTERN void
vdm_DatasetContents(vdm_Dataset* p,Vchar ancont[]);
VKI_EXTERN void vdm_DatasetModel(vdm_Dataset* p,Vchar
model[]);VKI_EXTERN void vdm_DatasetDescription(vdm_Dataset*
p,Vchar description[]);VKI_EXTERN void vdm_DatasetComplx(vdm_Dataset*
p,Vint* cplx);VKI_EXTERN void vdm_DatasetDimensions(vdm_Dataset*
p,Vchar dimensions[]);VKI_EXTERN void vdm_DatasetSetInt(vdm_Dataset*
p,Vint nint,Vint ival);VKI_EXTERN void vdm_DatasetGetInt(vdm_Dataset*
p,Vint nint,Vint* ival);VKI_EXTERN void vdm_DatasetSetObj(vdm_Dataset*
p,Vobject* obj);VKI_EXTERN void vdm_DatasetGetObj(vdm_Dataset*
p,Vobject** obj);VKI_EXTERN void vdm_DatasetEndObj(vdm_Dataset*
p,Vfunc1* function);VKI_EXTERN void vdm_DatasetSetLib(vdm_Dataset*
p,Vobject* lib);VKI_EXTERN void vdm_DatasetGetLib(vdm_Dataset*
p,Vobject** lib);VKI_EXTERN void vdm_DatasetEndLib(vdm_Dataset*
p,Vfunc1* function);VKI_EXTERN void vdm_DatasetStreamNum(vdm_Dataset*
p,Vint* nbytes);VKI_EXTERN void vdm_DatasetStreamSave(vdm_Dataset*
p,void* data);VKI_EXTERN void vdm_DatasetStreamLoad(vdm_Dataset*
p,void* data);VKI_EXTERN void vdm_DatasetCopy(vdm_Dataset*
p,vdm_Dataset* fromp);VKI_EXTERN void vdm_DatasetPrint(vdm_Dataset*
p);VKI_EXTERN void vdm_DatasetGetMetadata(vdm_Dataset*
p,vis_ResultMetadata* metadata);
#ifdef __cplusplus
}
#endif
#endif

