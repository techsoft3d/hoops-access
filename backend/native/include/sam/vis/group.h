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
 
#ifndef GROUP_DEF
#define GROUP_DEF
#include "sam/base/basedefs.h"
#include "sam/base/propset.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/idtran.h"
#include "sam/vis/connect.h"
struct vis_Group { Vint ierr;Vint nument;Vint maxent;
Vint enttype;Vint subtype;Vint length;Vuchar* ind1;
Vchar* ind8;Vshort* ind16;Vint* indx;Vint numext;Vint
maxext;Vint (*extx)[2];Vint nextind;Vint maxsize;Vchar*
name;Vint sid;Vint userdata;Vint type,spec;
#ifdef __cplusplus
public: VKI_EXTERN vis_Group(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_Group(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint,Vint,Vint);VKI_EXTERN void
Inq(Vint*,Vint*,Vint*)const;VKI_EXTERN Vint Err(Vint,
Vint,Vint,Vint*);VKI_EXTERN void SetIndex(Vint,Vint);
VKI_EXTERN void SetIndices(Vint,Vint[],Vint);VKI_EXTERN
void GetIndex(Vint,Vint*)const;VKI_EXTERN void SetEntFlag(Vint,
Vint,Vint);VKI_EXTERN void GetEntFlag(Vint,Vint,Vint*)
const;VKI_EXTERN void NthEntFlag(Vint,Vint,Vint*)const;
VKI_EXTERN void NumEntFlag(Vint,Vint*,Vint*)const;VKI_EXTERN
Vint Node(Vint)const;VKI_EXTERN Vint Elem(Vint)const;
VKI_EXTERN Vint ElemEnt(Vint,Vint)const;VKI_EXTERN void
SetUID(Vint);VKI_EXTERN void GetUID(Vint*);VKI_EXTERN
void SetName(const Vchar*);VKI_EXTERN void GetName(Vchar[]);
VKI_EXTERN void SetUserData(Vint);VKI_EXTERN void GetUserData(Vint*);
VKI_EXTERN void SetType(Vint);VKI_EXTERN void GetType(Vint*);
VKI_EXTERN void SetSpec(Vint);VKI_EXTERN void GetSpec(Vint*);
VKI_EXTERN void InitIndex();VKI_EXTERN void NextIndex(Vint*,
Vint*);VKI_EXTERN void Clear();VKI_EXTERN void All();
VKI_EXTERN void Boolean(Vint,vis_Group*);VKI_EXTERN
void Complement();VKI_EXTERN void Count(Vint*,Vint*)
const;VKI_EXTERN void IdTran(vis_IdTran*);VKI_EXTERN
void Configure(vis_Connect*);VKI_EXTERN void Copy(vis_Group*);
VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_Group* vis_GroupBegin(void);VKI_EXTERN
void vis_Group_Construct(vis_Group* p);VKI_EXTERN void
vis_GroupEnd(vis_Group* p);VKI_EXTERN void vis_Group_Destruct(vis_Group*
p);VKI_EXTERN Vint vis_GroupError(vis_Group* p);VKI_EXTERN
void vis_GroupDef(vis_Group* p,Vint nument,Vint parenttype,
Vint childtype);VKI_EXTERN void vis_GroupInq(const vis_Group*
p,Vint* nument,Vint* enttype,Vint* subtype);VKI_EXTERN
Vint vis_GroupErr(vis_Group* p,Vint nument,Vint enttype,
Vint subtype,Vint* ierr);VKI_EXTERN void vis_GroupSetIndex(vis_Group*
p,Vint index,Vint flags);VKI_EXTERN void vis_GroupSetIndices(vis_Group*
p,Vint nix,Vint indices[],Vint flags);VKI_EXTERN void
vis_GroupGetIndex(const vis_Group* p,Vint index,Vint*
flag);VKI_EXTERN void vis_GroupSetEntFlag(vis_Group*
p,Vint index,Vint no,Vint flag);VKI_EXTERN void vis_GroupGetEntFlag(const
vis_Group* p,Vint index,Vint no,Vint* flag);VKI_EXTERN
void vis_GroupNthEntFlag(const vis_Group* p,Vint index,
Vint no,Vint* nth);VKI_EXTERN void vis_GroupNumEntFlag(const
vis_Group* p,Vint index,Vint* numno,Vint* maxno);VKI_EXTERN
Vint vis_GroupNode(const vis_Group* p,Vint index);VKI_EXTERN
Vint vis_GroupElem(const vis_Group* p,Vint index);VKI_EXTERN
Vint vis_GroupElemEnt(const vis_Group* p,Vint index,
Vint no);VKI_EXTERN void vis_GroupSetUID(vis_Group*
p,Vint id);VKI_EXTERN void vis_GroupGetUID(vis_Group*
p,Vint* id);VKI_EXTERN void vis_GroupSetName(vis_Group*
p,const Vchar* name);VKI_EXTERN void vis_GroupGetName(vis_Group*
p,Vchar name[]);VKI_EXTERN void vis_GroupSetUserData(vis_Group*
p,Vint userdata);VKI_EXTERN void vis_GroupGetUserData(vis_Group*
p,Vint* userdata);VKI_EXTERN void vis_GroupSetType(vis_Group*
p,Vint type);VKI_EXTERN void vis_GroupGetType(vis_Group*
p,Vint* type);VKI_EXTERN void vis_GroupSetSpec(vis_Group*
p,Vint spec);VKI_EXTERN void vis_GroupGetSpec(vis_Group*
p,Vint* spec);VKI_EXTERN void vis_GroupInitIndex(vis_Group*
p);VKI_EXTERN void vis_GroupNextIndex(vis_Group* p,
Vint* index,Vint* flags);VKI_EXTERN void vis_GroupClear(vis_Group*
p);VKI_EXTERN void vis_GroupAll(vis_Group* p);VKI_EXTERN
void vis_GroupBoolean(vis_Group* p,Vint operation,vis_Group*
groupsrc);VKI_EXTERN void vis_GroupComplement(vis_Group*
p);VKI_EXTERN void vis_GroupCount(const vis_Group* p,
Vint* nparent,Vint* nchild);VKI_EXTERN void vis_GroupIdTran(vis_Group*
p,vis_IdTran* idtran);VKI_EXTERN void vis_GroupConfigure(vis_Group*
p,vis_Connect* connect);VKI_EXTERN void vis_GroupCopy(vis_Group*
p,vis_Group* fromp);VKI_EXTERN void vis_GroupPrint(vis_Group*
p);
#ifdef __cplusplus
}
#endif
#endif

