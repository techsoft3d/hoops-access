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
 
#ifndef LCASE_DEF
#define LCASE_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/gridfun.h"
#include "sam/vis/group.h"
typedef struct vis_LCase_Conc { Vdouble* dat;Vdouble*
dati;Vint* tid;Vint* tidi;}vis_LCase_Conc;typedef struct
vis_LCase_Dist { Vshort num;Vshort dim;union { Vdouble*
dat;Vdouble val;}prop;union { Vdouble* dat;Vdouble val;
}propi;Vint tid;Vint tidi;}vis_LCase_Dist;typedef struct
vis_LCase_ElemEnt { Vint nent;union { vis_LCase_Dist**
vect;vis_LCase_Dist* dist;}dst;}vis_LCase_ElemEnt;struct
vis_LCase { Vint ierr;Vint nval;Vint complexmode;Vint
complexflag;Vint nvalc;vsy_HashTable* conch[LCASE_CONC_MAX];
vsy_IntHash* ihfm;Vint concmax[LCASE_CONC_MAX];Vint
numconctid[LCASE_CONC_MAX];vsy_HashTable* faceh[LCASE_DIST_MAX];
Vint facemax[LCASE_DIST_MAX];vsy_HashTable* edgeh[LCASE_DIST_MAX];
Vint edgemax[LCASE_DIST_MAX];Vint numdisttid[LCASE_DIST_MAX];
vsy_HashTable* elemh[LCASE_ELEM_MAX];Vint elemmax[LCASE_ELEM_MAX];
Vint numelemtid[LCASE_ELEM_MAX];Vint accelflag;Vdouble
grav[3];Vdouble cent[3];Vdouble w[3];Vdouble wdot[3];
vis_GridFun* gf;Vint lid;Vchar* name;Vdouble addfac;
#ifdef __cplusplus
public: VKI_EXTERN vis_LCase(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_LCase(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void SetObject(Vint,Vobject*);VKI_EXTERN
void GetObject(Vint,Vobject**);VKI_EXTERN void SetParamd(Vint,
Vdouble);VKI_EXTERN void SetComplexMode(Vint);VKI_EXTERN
void GetComplexMode(Vint*);VKI_EXTERN void GetComplex(Vint*);
VKI_EXTERN void SetConc(Vint,Vint,Vfloat[]);VKI_EXTERN
void SetConcdv(Vint,Vint,Vdouble[]);VKI_EXTERN void
SetConcTId(Vint,Vint,Vint[]);VKI_EXTERN void ConcNumTId(Vint,
Vint*);VKI_EXTERN void AddConc(Vint,Vint,Vfloat[3]);
VKI_EXTERN void AddConcdv(Vint,Vint,Vdouble[3]);VKI_EXTERN
void ConcMax(Vint,Vint*);VKI_EXTERN void ConcNum(Vint,
Vint*);VKI_EXTERN void ConcInitIter(Vint);VKI_EXTERN
void ConcNextIter(Vint,Vint*);VKI_EXTERN void ConcFlag(Vint,
Vint,Vint*);VKI_EXTERN void ConcType(Vint,Vint*,Vint[]);
VKI_EXTERN void Conc(Vint,Vint,Vfloat[]);VKI_EXTERN
void Concdv(Vint,Vint,Vdouble[]);VKI_EXTERN void ConcTId(Vint,
Vint,Vint[]);VKI_EXTERN void SetDist(Vint,Vint,Vint,
Vint,Vfloat[]);VKI_EXTERN void SetDistdv(Vint,Vint,
Vint,Vint,Vdouble[]);VKI_EXTERN void SetDistTId(Vint,
Vint,Vint,Vint,Vint[]);VKI_EXTERN void DistNumTId(Vint,
Vint*);VKI_EXTERN void AddDist(Vint,Vint,Vint,Vint,
Vfloat[]);VKI_EXTERN void AddDistdv(Vint,Vint,Vint,
Vint,Vdouble[]);VKI_EXTERN void AddDistCentdv(Vint,
Vint,Vint,Vint,Vdouble[]);VKI_EXTERN void AddDistCorndv(Vint,
Vint,Vint,Vint,Vdouble[]);VKI_EXTERN void DistMax(Vint,
Vint,Vint*);VKI_EXTERN void DistNum(Vint,Vint,Vint*,
Vint*);VKI_EXTERN void DistInitIter(Vint,Vint);VKI_EXTERN
void DistNextIter(Vint,Vint,Vint*);VKI_EXTERN void DistFlag(Vint,
Vint,Vint,Vint*);VKI_EXTERN void DistType(Vint,Vint,
Vint,Vint*,Vint[]);VKI_EXTERN void Dist(Vint,Vint,Vint,
Vint,Vint,Vfloat[]);VKI_EXTERN void Distdv(Vint,Vint,
Vint,Vint,Vint,Vdouble[]);VKI_EXTERN void DistTId(Vint,
Vint,Vint,Vint,Vint[]);VKI_EXTERN Vint DistFlagEnt(Vint,
Vint,Vint,Vint);VKI_EXTERN void SetElem(Vint,Vint,Vfloat[]);
VKI_EXTERN void SetElemdv(Vint,Vint,Vdouble[]);VKI_EXTERN
void SetElemTId(Vint,Vint,Vint[]);VKI_EXTERN void ElemNumTId(Vint,
Vint*);VKI_EXTERN void AddElem(Vint,Vint,Vfloat[]);
VKI_EXTERN void AddElemdv(Vint,Vint,Vdouble[]);VKI_EXTERN
void ElemMax(Vint,Vint*);VKI_EXTERN void ElemNum(Vint,
Vint*,Vint*);VKI_EXTERN void ElemInitIter(Vint);VKI_EXTERN
void ElemNextIter(Vint,Vint*);VKI_EXTERN void ElemFlag(Vint,
Vint,Vint*);VKI_EXTERN void ElemType(Vint,Vint*,Vint[]);
VKI_EXTERN void Elem(Vint,Vint,Vfloat[]);VKI_EXTERN
void Elemdv(Vint,Vint,Vdouble[]);VKI_EXTERN void ElemTId(Vint,
Vint,Vint[]);VKI_EXTERN void SetAccel(Vfloat[3],Vfloat[3],
Vfloat[3],Vfloat[3]);VKI_EXTERN void SetAcceldv(Vdouble[3],
Vdouble[3],Vdouble[3],Vdouble[3]);VKI_EXTERN void AccelFlag(Vint*);
VKI_EXTERN void Accel(Vfloat[3],Vfloat[3],Vfloat[3],
Vfloat[3]);VKI_EXTERN void Acceldv(Vdouble[3],Vdouble[3],
Vdouble[3],Vdouble[3]);VKI_EXTERN void NodeGroup(vis_Group*,
vis_Group*);VKI_EXTERN void ElemGroup(vis_Group*,vis_Group*);
VKI_EXTERN void FaceGroup(vis_Group*,vis_Group*);VKI_EXTERN
void EdgeGroup(vis_Group*,vis_Group*);VKI_EXTERN void
ClearConc(Vint);VKI_EXTERN void ClearDist(Vint);VKI_EXTERN
void ClearElem(Vint);VKI_EXTERN void ClearAccel();VKI_EXTERN
void Clear();VKI_EXTERN void SpecFlag(Vint*);VKI_EXTERN
void Add(vis_LCase*);VKI_EXTERN void SetId(Vint);VKI_EXTERN
void GetId(Vint*);VKI_EXTERN void SetName(const Vchar*);
VKI_EXTERN void GetName(Vchar[]);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_LCase* vis_LCaseBegin(void);VKI_EXTERN
void vis_LCase_Construct(vis_LCase* p);VKI_EXTERN void
vis_LCaseEnd(vis_LCase* p);VKI_EXTERN void vis_LCase_Destruct(vis_LCase*
p);VKI_EXTERN Vint vis_LCaseError(vis_LCase* p);VKI_EXTERN
void vis_LCaseSetObject(vis_LCase* p,Vint objecttype,
Vobject* object);VKI_EXTERN void vis_LCaseGetObject(vis_LCase*
p,Vint objecttype,Vobject** object);VKI_EXTERN void
vis_LCaseSetParamd(vis_LCase* p,Vint type,Vdouble dparam);
VKI_EXTERN void vis_LCaseSetComplexMode(vis_LCase* p,
Vint complexmode);VKI_EXTERN void vis_LCaseGetComplexMode(vis_LCase*
p,Vint* complexmode);VKI_EXTERN void vis_LCaseGetComplex(vis_LCase*
p,Vint* complexflag);VKI_EXTERN void vis_LCaseSetConc(vis_LCase*
p,Vint index,Vint type,Vfloat value[]);VKI_EXTERN void
vis_LCaseSetConcdv(vis_LCase* p,Vint index,Vint type,
Vdouble val[]);VKI_EXTERN void vis_LCaseSetConcTId(vis_LCase*
p,Vint index,Vint type,Vint tid[]);VKI_EXTERN void vis_LCaseConcNumTId(vis_LCase*
p,Vint type,Vint* numtid);VKI_EXTERN void vis_LCaseAddConc(vis_LCase*
p,Vint index,Vint type,Vfloat value[3]);VKI_EXTERN void
vis_LCaseAddConcdv(vis_LCase* p,Vint index,Vint type,
Vdouble val[3]);VKI_EXTERN void vis_LCaseConcMax(vis_LCase*
p,Vint type,Vint* maxindex);VKI_EXTERN void vis_LCaseConcNum(vis_LCase*
p,Vint type,Vint* numindex);VKI_EXTERN void vis_LCaseConcInitIter(vis_LCase*
p,Vint type);VKI_EXTERN void vis_LCaseConcNextIter(vis_LCase*
p,Vint type,Vint* index);VKI_EXTERN void vis_LCaseConcFlag(vis_LCase*
p,Vint index,Vint type,Vint* flag);VKI_EXTERN void vis_LCaseConcType(vis_LCase*
p,Vint index,Vint* ntypes,Vint type[]);VKI_EXTERN void
vis_LCaseConc(vis_LCase* p,Vint index,Vint type,Vfloat
value[]);VKI_EXTERN void vis_LCaseConcdv(vis_LCase*
p,Vint index,Vint type,Vdouble val[]);VKI_EXTERN void
vis_LCaseConcTId(vis_LCase* p,Vint index,Vint type,
Vint tid[]);VKI_EXTERN void vis_LCaseSetDist(vis_LCase*
p,Vint enttype,Vint index,Vint no,Vint type,Vfloat value[]);
VKI_EXTERN void vis_LCaseSetDistdv(vis_LCase* p,Vint
enttype,Vint index,Vint no,Vint type,Vdouble val[]);
VKI_EXTERN void vis_LCaseSetDistTId(vis_LCase* p,Vint
enttype,Vint index,Vint no,Vint type,Vint tid[]);VKI_EXTERN
void vis_LCaseDistNumTId(vis_LCase* p,Vint type,Vint*
numtid);VKI_EXTERN void vis_LCaseAddDist(vis_LCase*
p,Vint enttype,Vint index,Vint no,Vint type,Vfloat value[]);
VKI_EXTERN void vis_LCaseAddDistdv(vis_LCase* p,Vint
enttype,Vint index,Vint no,Vint type,Vdouble val[]);
VKI_EXTERN void vis_LCaseAddDistCentdv(vis_LCase* p,
Vint enttype,Vint index,Vint no,Vint type,Vdouble val[]);
VKI_EXTERN void vis_LCaseAddDistCorndv(vis_LCase* p,
Vint enttype,Vint index,Vint no,Vint type,Vdouble val[]);
VKI_EXTERN void vis_LCaseDistMax(vis_LCase* p,Vint enttype,
Vint type,Vint* maxindex);VKI_EXTERN void vis_LCaseDistNum(vis_LCase*
p,Vint enttype,Vint type,Vint* numindex,Vint* lngindex);
VKI_EXTERN void vis_LCaseDistInitIter(vis_LCase* p,
Vint enttype,Vint type);VKI_EXTERN void vis_LCaseDistNextIter(vis_LCase*
p,Vint enttype,Vint type,Vint* index);VKI_EXTERN void
vis_LCaseDistFlag(vis_LCase* p,Vint enttype,Vint index,
Vint type,Vint* flags);VKI_EXTERN Vint vis_LCaseDistFlagEnt(vis_LCase*
p,Vint enttype,Vint index,Vint type,Vint no);VKI_EXTERN
void vis_LCaseDistType(vis_LCase* p,Vint enttype,Vint
index,Vint no,Vint* ntypes,Vint type[]);VKI_EXTERN void
vis_LCaseDist(vis_LCase* p,Vint enttype,Vint index,
Vint no,Vint type,Vint enflag,Vfloat value[]);VKI_EXTERN
void vis_LCaseDistdv(vis_LCase* p,Vint enttype,Vint
index,Vint no,Vint type,Vint enflag,Vdouble val[]);
VKI_EXTERN void vis_LCaseDistTId(vis_LCase* p,Vint enttype,
Vint index,Vint no,Vint type,Vint tid[]);VKI_EXTERN
void vis_LCaseSetElem(vis_LCase* p,Vint index,Vint type,
Vfloat value[]);VKI_EXTERN void vis_LCaseSetElemdv(vis_LCase*
p,Vint index,Vint type,Vdouble val[]);VKI_EXTERN void
vis_LCaseSetElemTId(vis_LCase* p,Vint index,Vint type,
Vint tid[]);VKI_EXTERN void vis_LCaseElemNumTId(vis_LCase*
p,Vint type,Vint* numtid);VKI_EXTERN void vis_LCaseAddElem(vis_LCase*
p,Vint index,Vint type,Vfloat value[]);VKI_EXTERN void
vis_LCaseAddElemdv(vis_LCase* p,Vint index,Vint type,
Vdouble val[]);VKI_EXTERN void vis_LCaseElemMax(vis_LCase*
p,Vint type,Vint* maxindex);VKI_EXTERN void vis_LCaseElemNum(vis_LCase*
p,Vint type,Vint* numindex,Vint* lngindex);VKI_EXTERN
void vis_LCaseElemInitIter(vis_LCase* p,Vint type);
VKI_EXTERN void vis_LCaseElemNextIter(vis_LCase* p,
Vint type,Vint* index);VKI_EXTERN void vis_LCaseElemFlag(vis_LCase*
p,Vint index,Vint type,Vint* flag);VKI_EXTERN void vis_LCaseElemType(vis_LCase*
p,Vint index,Vint* ntypes,Vint type[]);VKI_EXTERN void
vis_LCaseElem(vis_LCase* p,Vint index,Vint type,Vfloat
value[]);VKI_EXTERN void vis_LCaseElemdv(vis_LCase*
p,Vint index,Vint type,Vdouble val[]);VKI_EXTERN void
vis_LCaseElemTId(vis_LCase* p,Vint index,Vint type,
Vint tid[]);VKI_EXTERN void vis_LCaseSetAccel(vis_LCase*
p,Vfloat grav[3],Vfloat cent[3],Vfloat w[3],Vfloat wdot[3]);
VKI_EXTERN void vis_LCaseSetAcceldv(vis_LCase* p,Vdouble
grav[3],Vdouble cent[3],Vdouble w[3],Vdouble wdot[3]);
VKI_EXTERN void vis_LCaseAccelFlag(vis_LCase* p,Vint*
accelflag);VKI_EXTERN void vis_LCaseAccel(vis_LCase*
p,Vfloat grav[3],Vfloat cent[3],Vfloat w[3],Vfloat wdot[3]);
VKI_EXTERN void vis_LCaseAcceldv(vis_LCase* p,Vdouble
grav[3],Vdouble cent[3],Vdouble w[3],Vdouble wdot[3]);
VKI_EXTERN void vis_LCaseNodeGroup(vis_LCase* p,vis_Group*
group,vis_Group* groupdst);VKI_EXTERN void vis_LCaseElemGroup(vis_LCase*
p,vis_Group* group,vis_Group* groupdst);VKI_EXTERN void
vis_LCaseFaceGroup(vis_LCase* p,vis_Group* group,vis_Group*
groupdst);VKI_EXTERN void vis_LCaseEdgeGroup(vis_LCase*
p,vis_Group* group,vis_Group* groupdst);VKI_EXTERN void
vis_LCaseClearConc(vis_LCase* p,Vint type);VKI_EXTERN
void vis_LCaseClearDist(vis_LCase* p,Vint type);VKI_EXTERN
void vis_LCaseClearElem(vis_LCase* p,Vint type);VKI_EXTERN
void vis_LCaseClearAccel(vis_LCase* p);VKI_EXTERN void
vis_LCaseClear(vis_LCase* p);VKI_EXTERN void vis_LCaseSpecFlag(vis_LCase*
p,Vint* flag);VKI_EXTERN void vis_LCaseAdd(vis_LCase*
p,vis_LCase* addlcase);VKI_EXTERN void vis_LCaseSetId(vis_LCase*
p,Vint id);VKI_EXTERN void vis_LCaseGetId(vis_LCase*
p,Vint* id);VKI_EXTERN void vis_LCaseSetName(vis_LCase*
p,const Vchar* name);VKI_EXTERN void vis_LCaseGetName(vis_LCase*
p,Vchar name[]);VKI_EXTERN void vis_LCasePrint(vis_LCase*
p);
#ifdef __cplusplus
}
#endif
#endif

