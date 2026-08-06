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
 
#ifndef CPAIR_DEF
#define CPAIR_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/gridfun.h"
typedef struct vis_CPair_node { Vint id;Vdouble area;
}vis_CPair_node;typedef struct vis_CPair_elem { Vint
id;Vint flags;}vis_CPair_elem;typedef struct vis_CPair_Entry
{ Vint flag;union { Vobject* p;Vint* ip;Vdouble* fp;
}prop;}vis_CPair_Entry;struct vis_CPair { Vint ierr;
Vint mastent;Vint slavent;Vint ctype;Vchar* name;Vint
maxmastindex;Vint maxslavindex;Vint ntyps;Vint stab[CPAIR_MAX];
Vint snum[CPAIR_MAX];vis_CPair_Entry* vect;vsy_HashTable*
htmast;vsy_HashTable* htslav;vsy_Concat* concat;vsy_ADTree*
adtree;vsy_IntHash* snih;Vint asid;Vint adtreekernel;
vis_IdTran* idtranent;vis_GridFun* gf;Vchar* masterElementSetName;
Vchar* slaveElementSetName;
#ifdef __cplusplus
public: VKI_EXTERN vis_CPair(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_CPair(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint,Vint);VKI_EXTERN void Inq(Vint*,
Vint*);VKI_EXTERN void SetObject(Vint,Vobject*);VKI_EXTERN
void SetType(Vint);VKI_EXTERN void GetType(Vint*);VKI_EXTERN
void SetName(const Vchar*);VKI_EXTERN void GetName(Vchar[]);
VKI_EXTERN void SetSlaveNode(Vint,Vfloat);VKI_EXTERN
void SetSlaveNodedv(Vint,Vdouble);VKI_EXTERN void MasterInitIter();
VKI_EXTERN void MasterNextIter(Vint*);VKI_EXTERN void
SetSlaveElem(Vint,Vint);VKI_EXTERN void SetMaster(Vint,
Vint);VKI_EXTERN void SlaveInitIter();VKI_EXTERN void
SlaveNextIter(Vint*);VKI_EXTERN void SlaveNodeInitIter();
VKI_EXTERN void SlaveNodeNextIter(Vint*);VKI_EXTERN
void SlaveMax(Vint*);VKI_EXTERN void SlaveNum(Vint*,
Vint*);VKI_EXTERN void SlaveFlag(Vint,Vint*);VKI_EXTERN
void SlaveEnt(Vint,Vint*,Vint[]);VKI_EXTERN void SlaveNode(Vint,
Vfloat*);VKI_EXTERN void SlaveNodedv(Vint,Vdouble*);
VKI_EXTERN void MasterMax(Vint*);VKI_EXTERN void MasterNum(Vint*,
Vint*);VKI_EXTERN void MasterFlag(Vint,Vint*);VKI_EXTERN
void MasterEnt(Vint,Vint*,Vint[]);VKI_EXTERN void SpecFlag(Vint*);
VKI_EXTERN void SetValuei(Vint,Vint);VKI_EXTERN void
SetValuef(Vint,Vfloat);VKI_EXTERN void SetValued(Vint,
Vdouble);VKI_EXTERN void ValueType(Vint*,Vint[]);VKI_EXTERN
void ValueFlag(Vint,Vint*);VKI_EXTERN void ValueParams(Vint,
Vint*,Vint*);VKI_EXTERN void ValueName(Vint,Vchar[]);
VKI_EXTERN void ValueFloat(Vint,Vfloat[]);VKI_EXTERN
void ValueDouble(Vint,Vdouble[]);VKI_EXTERN void ValueInteger(Vint,
Vint[]);VKI_EXTERN void NodeIdTran(vis_IdTran*);VKI_EXTERN
void FaceIdTran(Vint,vis_IdTran*);VKI_EXTERN void EdgeIdTran(Vint,
vis_IdTran*);VKI_EXTERN void SlaveNodeMaster(Vint,Vint*,
Vint*);VKI_EXTERN void Print();VKI_EXTERN void SetMasterASurf(Vint);
VKI_EXTERN void MasterASurf(Vint*);VKI_EXTERN void MasterSetElementSetName(const
Vchar*);VKI_EXTERN void MasterGetElementSetName(Vchar[]);
VKI_EXTERN void SlaveSetElementSetName(const Vchar*);
VKI_EXTERN void SlaveGetElementSetName(Vchar[]);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_CPair* vis_CPairBegin(void);VKI_EXTERN
void vis_CPair_Construct(vis_CPair* p);VKI_EXTERN void
vis_CPairEnd(vis_CPair* p);VKI_EXTERN void vis_CPair_Destruct(vis_CPair*
p);VKI_EXTERN Vint vis_CPairError(vis_CPair* p);VKI_EXTERN
void vis_CPairDef(vis_CPair* p,Vint mastent,Vint slavent);
VKI_EXTERN void vis_CPairInq(vis_CPair* p,Vint* mastent,
Vint* slavent);VKI_EXTERN void vis_CPairSetObject(vis_CPair*
p,Vint objecttype,Vobject* object);VKI_EXTERN void vis_CPairSetType(vis_CPair*
p,Vint ctype);VKI_EXTERN void vis_CPairGetType(vis_CPair*
p,Vint* ctype);VKI_EXTERN void vis_CPairSetName(vis_CPair*
p,const Vchar* name);VKI_EXTERN void vis_CPairGetName(vis_CPair*
p,Vchar name[]);VKI_EXTERN void vis_CPairSetSlaveNode(vis_CPair*
p,Vint index,Vfloat area);VKI_EXTERN void vis_CPairSetSlaveNodedv(vis_CPair*
p,Vint index,Vdouble area);VKI_EXTERN void vis_CPairSetSlaveElem(vis_CPair*
p,Vint index,Vint no);VKI_EXTERN void vis_CPairSetMaster(vis_CPair*
p,Vint index,Vint no);VKI_EXTERN void vis_CPairSlaveInitIter(vis_CPair*
p);VKI_EXTERN void vis_CPairSlaveNextIter(vis_CPair*
p,Vint* index);VKI_EXTERN void vis_CPairSlaveNodeInitIter(vis_CPair*
p);VKI_EXTERN void vis_CPairSlaveNodeNextIter(vis_CPair*
p,Vint* index);VKI_EXTERN void vis_CPairSlaveMax(vis_CPair*
p,Vint* maxindex);VKI_EXTERN void vis_CPairSlaveNum(vis_CPair*
p,Vint* numindex,Vint* numentity);VKI_EXTERN void vis_CPairSlaveFlag(vis_CPair*
p,Vint index,Vint* flags);VKI_EXTERN void vis_CPairSlaveEnt(vis_CPair*
p,Vint index,Vint* numno,Vint no[]);VKI_EXTERN void
vis_CPairSlaveNode(vis_CPair* p,Vint index,Vfloat* area);
VKI_EXTERN void vis_CPairSlaveNodedv(vis_CPair* p,Vint
index,Vdouble* area);VKI_EXTERN void vis_CPairMasterInitIter(vis_CPair*
p);VKI_EXTERN void vis_CPairMasterNextIter(vis_CPair*
p,Vint* index);VKI_EXTERN void vis_CPairMasterMax(vis_CPair*
p,Vint* maxindex);VKI_EXTERN void vis_CPairMasterNum(vis_CPair*
p,Vint* numindex,Vint* numentity);VKI_EXTERN void vis_CPairMasterFlag(vis_CPair*
p,Vint index,Vint* flags);VKI_EXTERN void vis_CPairMasterEnt(vis_CPair*
p,Vint index,Vint* numno,Vint no[]);VKI_EXTERN void
vis_CPairSpecFlag(vis_CPair* p,Vint* flag);VKI_EXTERN
void vis_CPairSetValuei(vis_CPair* p,Vint type,Vint
ivalue);VKI_EXTERN void vis_CPairSetValuef(vis_CPair*
p,Vint type,Vfloat rvalue);VKI_EXTERN void vis_CPairSetValued(vis_CPair*
p,Vint type,Vdouble dparam);VKI_EXTERN void vis_CPairValueType(vis_CPair*
p,Vint* ntypes,Vint type[]);VKI_EXTERN void vis_CPairValueFlag(vis_CPair*
p,Vint type,Vint* flag);VKI_EXTERN void vis_CPairValueParams(vis_CPair*
p,Vint type,Vint* nval,Vint* dtyp);VKI_EXTERN void vis_CPairValueName(vis_CPair*
p,Vint type,Vchar name[]);VKI_EXTERN void vis_CPairValueFloat(vis_CPair*
p,Vint type,Vfloat fparam[]);VKI_EXTERN void vis_CPairValueDouble(vis_CPair*
p,Vint type,Vdouble dparam[]);VKI_EXTERN void vis_CPairValueInteger(vis_CPair*
p,Vint type,Vint iparam[]);VKI_EXTERN void vis_CPairNodeIdTran(vis_CPair*
p,vis_IdTran* idtran);VKI_EXTERN void vis_CPairFaceIdTran(vis_CPair*
p,Vint oper,vis_IdTran* idtran);VKI_EXTERN void vis_CPairEdgeIdTran(vis_CPair*
p,Vint oper,vis_IdTran* idtran);VKI_EXTERN void vis_CPairSlaveNodeMaster(vis_CPair*
p,Vint index,Vint* ix,Vint* no);VKI_EXTERN void vis_CPairPrint(vis_CPair*
p);VKI_EXTERN void vis_CPairSetMasterASurf(vis_CPair*
p,Vint asid);VKI_EXTERN void vis_CPairMasterASurf(vis_CPair*
p,Vint* asid);VKI_EXTERN void vis_CPairMasterSetElementSetName(vis_CPair*
p,const Vchar* name);VKI_EXTERN void vis_CPairMasterGetElementSetName(vis_CPair*
p,Vchar name[]);VKI_EXTERN void vis_CPairSlaveSetElementSetName(vis_CPair*
p,const Vchar* name);VKI_EXTERN void vis_CPairSlaveGetElementSetName(vis_CPair*
p,Vchar name[]);
#ifdef __cplusplus
}
#endif
#endif

