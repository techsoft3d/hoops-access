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
 
#ifndef RPROP_DEF
#define RPROP_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#define RPROP_UNDEFINED 0
#define RPROP_VALUE 1
#define RPROP_LOADFACTOR 0
#define RPROP_FREQUENCY 1
#define RPROP_EIGENVALUE 2
#define RPROP_TIME 3
#define RPROP_TIMESTEP 4
#define RPROP_AMPLITUDE 5
#define RPROP_PHASE 6
#define RPROP_GENERALIZEDMASS 7
#define RPROP_LOADCASE 8
#define RPROP_CONTENTS 9
#define RPROP_DATATYPE 10
#define RPROP_COMPLEX 11
#define RPROP_TITLE 12
#define RPROP_SUBTITLE 13
#define RPROP_SUBTITLE1 14
#define RPROP_SUBTITLE2 15
#define RPROP_SUBTITLE3 16
#define RPROP_SUBTITLE4 17
#define RPROP_LABEL 18
#define RPROP_SUBLABEL 19
#define RPROP_LINK_ROTANG 20
#define RPROP_LINK_CID 21
#define RPROP_LINK_COMPLEX 22
#define RPROP_LINK_SECTION 23
#define RPROP_LINK_LAYERS 24
#define RPROP_STRAINTYPE 25
#define RPROP_DATASOURCE 26
#define RPROP_CATEGORY 27
#define RPROP_LINK_ENTDOF 28
#define RPROP_LINK_INDEX 29
#define RPROP_LABEL1 30
#define RPROP_ESSTEYR_NT11_EXCEPTION 31
#define RPROP_SCALAR1 32
#define RPROP_SCALAR2 33
#define RPROP_SCALAR3 34
#define RPROP_CYCLICCSYSID 35
#define RPROP_NONLINEAR 36
#define RPROP_MAX 37
typedef struct vis_RProp_Entry { Vint flag;union { Vobject*
p;Vint* ip;Vdouble* fp;Vchar* cp;}prop;}vis_RProp_Entry;
struct vis_RProp { Vint ierr;Vint enttype;Vint subtype;
Vint compflag;Vint type;Vint mode;Vint analysis;Vint
solution;Vint hist;Vint cplx;Vint nqua,iqua[SYS_NQUA_MAX];
Vchar cqua[SYS_MAXNAME];Vint id1,id2,id3;Vchar dsname[SYS_MAXNAME];
Vint dsindex;Vchar caux[SYS_MAXNAME];Vint ntyps;Vint
stab[RPROP_MAX];Vint snum[RPROP_MAX];vis_RProp_Entry*
vect;Vchar* name;
#ifdef __cplusplus
public: VKI_EXTERN vis_RProp(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_RProp(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint,Vint);VKI_EXTERN void Inq(Vint*,
Vint*);VKI_EXTERN void SetType(Vint);VKI_EXTERN void
GetType(Vint*);VKI_EXTERN void SetIds(Vint,Vint,Vint);
VKI_EXTERN void GetIds(Vint*,Vint*,Vint*);VKI_EXTERN
void SetMode(Vint);VKI_EXTERN void GetMode(Vint*);VKI_EXTERN
void SetAnalysis(Vint);VKI_EXTERN void GetAnalysis(Vint*);
VKI_EXTERN void SetSolution(Vint);VKI_EXTERN void GetSolution(Vint*);
VKI_EXTERN void SetHist(Vint);VKI_EXTERN void GetHist(Vint*);
VKI_EXTERN void SetCplx(Vint);VKI_EXTERN void GetCplx(Vint*);
VKI_EXTERN void SetQual(Vint,Vint[],Vchar*);VKI_EXTERN
void GetQual(Vint*,Vint[],Vchar[]);VKI_EXTERN void SetDatasetName(Vchar*);
VKI_EXTERN void GetDatasetName(Vchar[]);VKI_EXTERN void
SetDatasetIndex(Vint);VKI_EXTERN void GetDatasetIndex(Vint*);
VKI_EXTERN void SetValuei(Vint,Vint);VKI_EXTERN void
SetValueiv(Vint,Vint[]);VKI_EXTERN void SetValuef(Vint,
Vfloat);VKI_EXTERN void SetValuefv(Vint,Vfloat[]);VKI_EXTERN
void SetValued(Vint,Vdouble);VKI_EXTERN void SetValuedv(Vint,
Vdouble[]);VKI_EXTERN void SetValuec(Vint,Vchar*);VKI_EXTERN
void UnSetValue(Vint);VKI_EXTERN void ValueType(Vint*,
Vint[]);VKI_EXTERN void ValueFlag(Vint,Vint*);VKI_EXTERN
void ValueParams(Vint,Vint*,Vint*);VKI_EXTERN void ValueName(Vint,
Vchar[]);VKI_EXTERN void ValueFloat(Vint,Vfloat[]);
VKI_EXTERN void ValueDouble(Vint,Vdouble[]);VKI_EXTERN
void ValueString(Vint,Vchar[]);VKI_EXTERN void ValueInteger(Vint,
Vint[]);VKI_EXTERN void SetName(Vchar*);VKI_EXTERN void
GetName(Vchar[]);VKI_EXTERN void Print();VKI_EXTERN
void Copy(vis_RProp*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_RProp* vis_RPropBegin(void);VKI_EXTERN
void vis_RProp_Construct(vis_RProp* p);VKI_EXTERN void
vis_RPropEnd(vis_RProp* p);VKI_EXTERN void vis_RProp_Destruct(vis_RProp*
p);VKI_EXTERN Vint vis_RPropError(vis_RProp* p);VKI_EXTERN
void vis_RPropDef(vis_RProp* p,Vint parenttype,Vint
childtype);VKI_EXTERN void vis_RPropInq(vis_RProp* p,
Vint* enttype,Vint* subtype);VKI_EXTERN void vis_RPropSetType(vis_RProp*
p,Vint type);VKI_EXTERN void vis_RPropGetType(vis_RProp*
p,Vint* type);VKI_EXTERN void vis_RPropSetIds(vis_RProp*
p,Vint id1,Vint id2,Vint id3);VKI_EXTERN void vis_RPropGetIds(vis_RProp*
p,Vint* id1,Vint* id2,Vint* id3);VKI_EXTERN void vis_RPropSetMode(vis_RProp*
p,Vint mode);VKI_EXTERN void vis_RPropGetMode(vis_RProp*
p,Vint* mode);VKI_EXTERN void vis_RPropSetAnalysis(vis_RProp*
p,Vint analysis);VKI_EXTERN void vis_RPropGetAnalysis(vis_RProp*
p,Vint* analysis);VKI_EXTERN void vis_RPropSetSolution(vis_RProp*
p,Vint solution);VKI_EXTERN void vis_RPropGetSolution(vis_RProp*
p,Vint* solution);VKI_EXTERN void vis_RPropSetHist(vis_RProp*
p,Vint hist);VKI_EXTERN void vis_RPropGetHist(vis_RProp*
p,Vint* hist);VKI_EXTERN void vis_RPropSetCplx(vis_RProp*
p,Vint cplx);VKI_EXTERN void vis_RPropGetCplx(vis_RProp*
p,Vint* cplx);VKI_EXTERN void vis_RPropSetQual(vis_RProp*
p,Vint nqua,Vint iqua[],Vchar* cqua);VKI_EXTERN void
vis_RPropGetQual(vis_RProp* p,Vint* nqua,Vint iqua[],
Vchar cqua[]);VKI_EXTERN void vis_RPropSetDatasetName(vis_RProp*
p,Vchar* dsname);VKI_EXTERN void vis_RPropGetDatasetName(vis_RProp*
p,Vchar dsname[]);VKI_EXTERN void vis_RPropSetDatasetIndex(vis_RProp*
p,Vint dsindex);VKI_EXTERN void vis_RPropGetDatasetIndex(vis_RProp*
p,Vint* dsindex);VKI_EXTERN void vis_RPropSetValuei(vis_RProp*
p,Vint type,Vint ivalue);VKI_EXTERN void vis_RPropSetValueiv(vis_RProp*
p,Vint type,Vint ivalue[]);VKI_EXTERN void vis_RPropSetValuef(vis_RProp*
p,Vint type,Vfloat rvalue);VKI_EXTERN void vis_RPropSetValuefv(vis_RProp*
p,Vint type,Vfloat rvalue[]);VKI_EXTERN void vis_RPropSetValued(vis_RProp*
p,Vint type,Vdouble dparam);VKI_EXTERN void vis_RPropSetValuedv(vis_RProp*
p,Vint type,Vdouble dparam[]);VKI_EXTERN void vis_RPropSetValuec(vis_RProp*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vis_RPropUnSetValue(vis_RProp*
p,Vint type);VKI_EXTERN void vis_RPropValueType(vis_RProp*
p,Vint* ntypes,Vint type[]);VKI_EXTERN void vis_RPropValueFlag(vis_RProp*
p,Vint type,Vint* flag);VKI_EXTERN void vis_RPropValueParams(vis_RProp*
p,Vint type,Vint* nval,Vint* dtyp);VKI_EXTERN void vis_RPropValueName(vis_RProp*
p,Vint type,Vchar name[]);VKI_EXTERN void vis_RPropValueFloat(vis_RProp*
p,Vint type,Vfloat fparam[]);VKI_EXTERN void vis_RPropValueDouble(vis_RProp*
p,Vint type,Vdouble dparam[]);VKI_EXTERN void vis_RPropValueString(vis_RProp*
p,Vint type,Vchar cparam[]);VKI_EXTERN void vis_RPropValueInteger(vis_RProp*
p,Vint type,Vint iparam[]);VKI_EXTERN void vis_RPropSetName(vis_RProp*
p,Vchar* name);VKI_EXTERN void vis_RPropGetName(vis_RProp*
p,Vchar name[]);VKI_EXTERN void vis_RPropPrint(vis_RProp*
p);VKI_EXTERN void vis_RPropCopy(vis_RProp* p,vis_RProp*
q);
#ifdef __cplusplus
}
#endif
#endif

