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
 
#ifndef RBODY_DEF
#define RBODY_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/gridfun.h"
typedef struct vis_RBody_node { Vint id;Vint type;}
vis_RBody_node;typedef struct vis_RBody_elem { Vint
id;Vint flags;}vis_RBody_elem;typedef struct vis_RBody_Entry
{ Vint flag;union { Vobject* p;Vint* ip;Vdouble* fp;
}prop;}vis_RBody_Entry;struct vis_RBody { Vint ierr;
Vint enttype;Vint refnode;Vchar* name;Vint maxelemindex;
Vint maxnodeindex;Vint ntyps;Vint stab[RBODY_MAX];Vint
snum[RBODY_MAX];vis_RBody_Entry* vect;vsy_HashTable*
htelem;vsy_HashTable* htnode;vsy_Concat* concat;Vint
asid;vis_IdTran* idtranent;vis_GridFun* gf;
#ifdef __cplusplus
public: VKI_EXTERN vis_RBody(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_RBody(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*);
VKI_EXTERN void SetObject(Vint,Vobject*);VKI_EXTERN
void SetName(const Vchar*);VKI_EXTERN void GetName(Vchar[]);
VKI_EXTERN void SetElem(Vint,Vint);VKI_EXTERN void ElemMax(Vint*);
VKI_EXTERN void ElemNum(Vint*,Vint*);VKI_EXTERN void
ElemFlag(Vint,Vint*,Vint*);VKI_EXTERN void ElemEnt(Vint,
Vint*,Vint*,Vint[]);VKI_EXTERN void SetNode(Vint,Vint);
VKI_EXTERN void NodeMax(Vint*);VKI_EXTERN void NodeNum(Vint*);
VKI_EXTERN void NodeType(Vint,Vint*);VKI_EXTERN void
SpecFlag(Vint*);VKI_EXTERN void SetRefNode(Vint);VKI_EXTERN
void GetRefNode(Vint*);VKI_EXTERN void SetValuei(Vint,
Vint);VKI_EXTERN void SetValued(Vint,Vdouble*);VKI_EXTERN
void ValueType(Vint*,Vint[]);VKI_EXTERN void ValueFlag(Vint,
Vint*);VKI_EXTERN void ValueParams(Vint,Vint*,Vint*);
VKI_EXTERN void ValueName(Vint,Vchar[]);VKI_EXTERN void
ValueDouble(Vint,Vdouble[]);VKI_EXTERN void ValueInteger(Vint,
Vint[]);VKI_EXTERN void FaceIdTran(vis_IdTran*);VKI_EXTERN
void EdgeIdTran(vis_IdTran*);VKI_EXTERN void NodeIdTran(Vint,
vis_IdTran*);VKI_EXTERN void Print();VKI_EXTERN void
SetASurf(Vint);VKI_EXTERN void ASurf(Vint*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_RBody* vis_RBodyBegin(void);VKI_EXTERN
void vis_RBody_Construct(vis_RBody* p);VKI_EXTERN void
vis_RBodyEnd(vis_RBody* p);VKI_EXTERN void vis_RBody_Destruct(vis_RBody*
p);VKI_EXTERN Vint vis_RBodyError(vis_RBody* p);VKI_EXTERN
void vis_RBodyDef(vis_RBody* p,Vint enttype);VKI_EXTERN
void vis_RBodyInq(vis_RBody* p,Vint* enttype);VKI_EXTERN
void vis_RBodySetObject(vis_RBody* p,Vint objecttype,
Vobject* object);VKI_EXTERN void vis_RBodySetName(vis_RBody*
p,const Vchar* name);VKI_EXTERN void vis_RBodyGetName(vis_RBody*
p,Vchar name[]);VKI_EXTERN void vis_RBodySetElem(vis_RBody*
p,Vint index,Vint no);VKI_EXTERN void vis_RBodyElemMax(vis_RBody*
p,Vint* maxindex);VKI_EXTERN void vis_RBodyElemNum(vis_RBody*
p,Vint* numindex,Vint* numentity);VKI_EXTERN void vis_RBodyElemFlag(vis_RBody*
p,Vint index,Vint* elem,Vint* flags);VKI_EXTERN void
vis_RBodyElemEnt(vis_RBody* p,Vint index,Vint* elem,
Vint* numno,Vint no[]);VKI_EXTERN void vis_RBodySetNode(vis_RBody*
p,Vint index,Vint type);VKI_EXTERN void vis_RBodyNodeMax(vis_RBody*
p,Vint* maxindex);VKI_EXTERN void vis_RBodyNodeNum(vis_RBody*
p,Vint* numindex);VKI_EXTERN void vis_RBodyNodeType(vis_RBody*
p,Vint index,Vint* type);VKI_EXTERN void vis_RBodySpecFlag(vis_RBody*
p,Vint* flag);VKI_EXTERN void vis_RBodySetRefNode(vis_RBody*
p,Vint index);VKI_EXTERN void vis_RBodyGetRefNode(vis_RBody*
p,Vint* refnode);VKI_EXTERN void vis_RBodySetValuei(vis_RBody*
p,Vint type,Vint ivalue);VKI_EXTERN void vis_RBodySetValued(vis_RBody*
p,Vint type,Vdouble* dparam);VKI_EXTERN void vis_RBodyValueType(vis_RBody*
p,Vint* ntypes,Vint type[]);VKI_EXTERN void vis_RBodyValueFlag(vis_RBody*
p,Vint type,Vint* flag);VKI_EXTERN void vis_RBodyValueParams(vis_RBody*
p,Vint type,Vint* nval,Vint* dtyp);VKI_EXTERN void vis_RBodyValueName(vis_RBody*
p,Vint type,Vchar name[]);VKI_EXTERN void vis_RBodyValueDouble(vis_RBody*
p,Vint type,Vdouble dparam[]);VKI_EXTERN void vis_RBodyValueInteger(vis_RBody*
p,Vint type,Vint iparam[]);VKI_EXTERN void vis_RBodyFaceIdTran(vis_RBody*
p,vis_IdTran* idtran);VKI_EXTERN void vis_RBodyEdgeIdTran(vis_RBody*
p,vis_IdTran* idtran);VKI_EXTERN void vis_RBodyNodeIdTran(vis_RBody*
p,Vint type,vis_IdTran* idtran);VKI_EXTERN void vis_RBodyPrint(vis_RBody*
p);VKI_EXTERN void vis_RBodySetASurf(vis_RBody* p,Vint
asid);VKI_EXTERN void vis_RBodyASurf(vis_RBody* p,Vint*
asid);
#ifdef __cplusplus
}
#endif
#endif

