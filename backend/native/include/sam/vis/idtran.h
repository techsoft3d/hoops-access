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
 
#ifndef IDTRAN_DEF
#define IDTRAN_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/group.h"
#include "sam/vis/uprop.h"
struct vis_IdTran { Vint ierr;Vint nument;Vint maxent;
Vint setent;Vint isort;Vint sorttype;Vint offset;Vint*
ids;Vint* entids;Vint* sortids;Vint* sortins;Vchar*
name;Vint sid;Vint userdata;Vobject* userobj;Vint enttype,
subtype;Vint type,spec;Vint numttab;Vint np2ttab;Vint**
ttab;Vint invert;vis_UProp* uprop;
#ifdef __cplusplus
public: VKI_EXTERN vis_IdTran(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_IdTran(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void SetId(Vint,Vint);VKI_EXTERN void
GetId(Vint,Vint*)const;VKI_EXTERN void GetIds(Vint,
Vint[],Vint[])const;VKI_EXTERN void PtrIds(Vint*,Vint**);
VKI_EXTERN void SetEnt(Vint,Vint);VKI_EXTERN void GetEnt(Vint,
Vint*)const;VKI_EXTERN void GetEnts(Vint,Vint[],Vint[])
const;VKI_EXTERN void AddId(Vint);VKI_EXTERN void AddThruByIds(Vint,
Vint[]);VKI_EXTERN void EquId(Vint,Vint);VKI_EXTERN
void EquSweep();VKI_EXTERN void EquReNumber(Vint*);
VKI_EXTERN void SetUID(Vint);VKI_EXTERN void GetUID(Vint*);
VKI_EXTERN void SetName(const Vchar*);VKI_EXTERN void
GetName(Vchar[]);VKI_EXTERN void SetUserData(Vint);
VKI_EXTERN void GetUserData(Vint*);VKI_EXTERN void SetUserObj(Vobject*);
VKI_EXTERN void GetUserObj(Vobject**);VKI_EXTERN void
SetUProp(vis_UProp*);VKI_EXTERN void GetUProp(vis_UProp**);
VKI_EXTERN void Delete();VKI_EXTERN void SetType(Vint);
VKI_EXTERN void GetType(Vint*);VKI_EXTERN void SetSpec(Vint);
VKI_EXTERN void GetSpec(Vint*);VKI_EXTERN void SetEntType(Vint,
Vint);VKI_EXTERN void GetEntType(Vint*,Vint*);VKI_EXTERN
void Clear();VKI_EXTERN void Init(Vint);VKI_EXTERN void
Append(vis_IdTran*);VKI_EXTERN void Count(Vint,Vint*);
VKI_EXTERN void Group(vis_Group*);VKI_EXTERN void Unique(vis_IdTran*);
VKI_EXTERN void Order();VKI_EXTERN void Type(Vint*);
VKI_EXTERN void Index(Vint,Vint*);VKI_EXTERN void Indices(Vint,
Vint[],Vint[]);VKI_EXTERN void NumIndex(Vint,Vint*);
VKI_EXTERN void AllIndex(Vint,Vint*,Vint[]);VKI_EXTERN
void Sort(vis_IdTran*);VKI_EXTERN void Match(vis_IdTran*,
Vint*);VKI_EXTERN void CheckSum(Vint*);VKI_EXTERN void
Copy(vis_IdTran*);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_IdTran* vis_IdTranBegin(void);VKI_EXTERN
void vis_IdTran_Construct(vis_IdTran* p);VKI_EXTERN
void vis_IdTranEnd(vis_IdTran* p);VKI_EXTERN void vis_IdTran_Destruct(vis_IdTran*
p);VKI_EXTERN Vint vis_IdTranError(vis_IdTran* p);VKI_EXTERN
void vis_IdTranDef(vis_IdTran* p,Vint nument);VKI_EXTERN
void vis_IdTranInq(const vis_IdTran* p,Vint* nument);
VKI_EXTERN void vis_IdTranSetId(vis_IdTran* p,Vint index,
Vint id);VKI_EXTERN void vis_IdTranGetId(const vis_IdTran*
p,Vint index,Vint* id);VKI_EXTERN void vis_IdTranGetIds(const
vis_IdTran* p,Vint nindices,Vint indices[],Vint ids[]);
VKI_EXTERN void vis_IdTranPtrIds(vis_IdTran* p,Vint*
nids,Vint** ids);VKI_EXTERN void vis_IdTranSetEnt(vis_IdTran*
p,Vint index,Vint no);VKI_EXTERN void vis_IdTranGetEnt(const
vis_IdTran* p,Vint index,Vint* ent);VKI_EXTERN void
vis_IdTranGetEnts(const vis_IdTran* p,Vint nindices,
Vint indices[],Vint ents[]);VKI_EXTERN void vis_IdTranAddId(vis_IdTran*
p,Vint id);VKI_EXTERN void vis_IdTranAddThruByIds(vis_IdTran*
p,Vint num,Vint listids[]);VKI_EXTERN void vis_IdTranEquId(vis_IdTran*
p,Vint index,Vint id);VKI_EXTERN void vis_IdTranEquSweep(vis_IdTran*
p);VKI_EXTERN void vis_IdTranEquReNumber(vis_IdTran*
p,Vint* num);VKI_EXTERN void vis_IdTranSetUID(vis_IdTran*
p,Vint id);VKI_EXTERN void vis_IdTranGetUID(vis_IdTran*
p,Vint* id);VKI_EXTERN void vis_IdTranSetName(vis_IdTran*
p,const Vchar* name);VKI_EXTERN void vis_IdTranGetName(vis_IdTran*
p,Vchar name[]);VKI_EXTERN void vis_IdTranSetUserData(vis_IdTran*
p,Vint userdata);VKI_EXTERN void vis_IdTranGetUserData(vis_IdTran*
p,Vint* userdata);VKI_EXTERN void vis_IdTranSetUserObj(vis_IdTran*
p,Vobject* object);VKI_EXTERN void vis_IdTranGetUserObj(vis_IdTran*
p,Vobject** object);VKI_EXTERN void vis_IdTranSetUProp(vis_IdTran*
p,vis_UProp* uprop);VKI_EXTERN void vis_IdTranGetUProp(vis_IdTran*
p,vis_UProp** uprop);VKI_EXTERN void vis_IdTranDelete(vis_IdTran*
p);VKI_EXTERN void vis_IdTranSetType(vis_IdTran* p,
Vint type);VKI_EXTERN void vis_IdTranGetType(vis_IdTran*
p,Vint* type);VKI_EXTERN void vis_IdTranSetSpec(vis_IdTran*
p,Vint spec);VKI_EXTERN void vis_IdTranGetSpec(vis_IdTran*
p,Vint* spec);VKI_EXTERN void vis_IdTranSetEntType(vis_IdTran*
p,Vint parenttype,Vint childtype);VKI_EXTERN void vis_IdTranGetEntType(vis_IdTran*
p,Vint* enttype,Vint* subtype);VKI_EXTERN void vis_IdTranClear(vis_IdTran*
p);VKI_EXTERN void vis_IdTranInit(vis_IdTran* p,Vint
id);VKI_EXTERN void vis_IdTranAppend(vis_IdTran* p,
vis_IdTran* appendp);VKI_EXTERN void vis_IdTranCount(vis_IdTran*
p,Vint type,Vint* num);VKI_EXTERN void vis_IdTranGroup(vis_IdTran*
p,vis_Group* group);VKI_EXTERN void vis_IdTranUnique(vis_IdTran*
p,vis_IdTran* fromidtran);VKI_EXTERN void vis_IdTranOrder(vis_IdTran*
p);VKI_EXTERN void vis_IdTranType(vis_IdTran* p,Vint*
sorttype);VKI_EXTERN void vis_IdTranIndex(vis_IdTran*
p,Vint id,Vint* index);VKI_EXTERN void vis_IdTranIndices(vis_IdTran*
p,Vint nids,Vint ids[],Vint indices[]);VKI_EXTERN void
vis_IdTranNumIndex(vis_IdTran* p,Vint id,Vint* num);
VKI_EXTERN void vis_IdTranAllIndex(vis_IdTran* p,Vint
id,Vint* num,Vint index[]);VKI_EXTERN void vis_IdTranSort(vis_IdTran*
p,vis_IdTran* sortp);VKI_EXTERN void vis_IdTranMatch(vis_IdTran*
p,vis_IdTran* idtranm,Vint* flag);VKI_EXTERN void vis_IdTranCheckSum(vis_IdTran*
p,Vint* checksum);VKI_EXTERN void vis_IdTranCopy(vis_IdTran*
p,vis_IdTran* fromp);VKI_EXTERN void vis_IdTranPrint(vis_IdTran*
p);
#ifdef __cplusplus
}
#endif
#endif

