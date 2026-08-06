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
 
#ifndef RCASE_DEF
#define RCASE_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/group.h"
typedef struct vis_RCase_SPC { Vint maxtag;Vchar* type;
Vdouble* value;Vdouble* valuei;Vint* master;Vint* tid;
Vint* tidi;Vint* dot;}vis_RCase_SPC;struct vis_RCase
{ Vint ierr;Vint complexmode;Vint complexflag;Vint maxspcindex;
Vint numvalue;Vint nummaster;Vint numtid;Vint numdot;
Vint usetag[SYS_DOF_MAX];vsy_HashTable* spcTable;Vint
maxelcindex;Vint numelvalue;Vint useeltag[SYS_DOF_MAX];
vsy_HashTable* elcTable;Vint rid;Vchar* name;
#ifdef __cplusplus
public: VKI_EXTERN vis_RCase(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_RCase(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void SetComplexMode(Vint);VKI_EXTERN void
GetComplexMode(Vint*);VKI_EXTERN void GetComplex(Vint*);
VKI_EXTERN void SetSPC(Vint,Vint,Vint,Vfloat[],Vint);
VKI_EXTERN void SetSPCdv(Vint,Vint,Vint,Vdouble[],Vint);
VKI_EXTERN void SetSPCTId(Vint,Vint,Vint[]);VKI_EXTERN
void SetSPCDot(Vint,Vint,Vint);VKI_EXTERN void SPCMax(Vint*);
VKI_EXTERN void SPCNum(Vint*,Vint*,Vint*);VKI_EXTERN
void SPCInitIter();VKI_EXTERN void SPCNextIter(Vint*);
VKI_EXTERN void SPCNumTId(Vint*);VKI_EXTERN void SPCNumDot(Vint*);
VKI_EXTERN void SPCUseTag(Vint*,Vint[]);VKI_EXTERN void
SPCTag(Vint,Vint*,Vint[]);VKI_EXTERN void SPC(Vint,
Vint,Vint*,Vfloat[],Vint*);VKI_EXTERN void SPCdv(Vint,
Vint,Vint*,Vdouble[],Vint*);VKI_EXTERN void SPCTId(Vint,
Vint,Vint[]);VKI_EXTERN void SPCDot(Vint,Vint,Vint*);
VKI_EXTERN void NodeGroup(vis_Group*,vis_Group*);VKI_EXTERN
void SetElemC(Vint,Vint,Vint,Vfloat[]);VKI_EXTERN void
SetElemCdv(Vint,Vint,Vint,Vdouble[]);VKI_EXTERN void
ElemCMax(Vint*);VKI_EXTERN void ElemCNum(Vint*,Vint*);
VKI_EXTERN void ElemCInitIter();VKI_EXTERN void ElemCNextIter(Vint*);
VKI_EXTERN void ElemCUseTag(Vint*,Vint[]);VKI_EXTERN
void ElemCTag(Vint,Vint*,Vint[]);VKI_EXTERN void ElemC(Vint,
Vint,Vint*,Vfloat*);VKI_EXTERN void ElemCdv(Vint,Vint,
Vint*,Vdouble*);VKI_EXTERN void ElemGroup(vis_Group*,
vis_Group*);VKI_EXTERN void Clear();VKI_EXTERN void
SpecFlag(Vint*);VKI_EXTERN void Add(vis_RCase*);VKI_EXTERN
void SetId(Vint);VKI_EXTERN void GetId(Vint*);VKI_EXTERN
void SetName(const Vchar*);VKI_EXTERN void GetName(Vchar[]);
VKI_EXTERN void Print();VKI_EXTERN void Copy(vis_RCase*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_RCase* vis_RCaseBegin(void);VKI_EXTERN
void vis_RCase_Construct(vis_RCase* p);VKI_EXTERN void
vis_RCaseEnd(vis_RCase* p);VKI_EXTERN void vis_RCase_Destruct(vis_RCase*
p);VKI_EXTERN Vint vis_RCaseError(vis_RCase* p);VKI_EXTERN
void vis_RCaseSetComplexMode(vis_RCase* p,Vint complexmode);
VKI_EXTERN void vis_RCaseGetComplexMode(vis_RCase* p,
Vint* complexmode);VKI_EXTERN void vis_RCaseGetComplex(vis_RCase*
p,Vint* complexflag);VKI_EXTERN void vis_RCaseSetSPC(vis_RCase*
p,Vint index,Vint tag,Vint type,Vfloat value[],Vint
master);VKI_EXTERN void vis_RCaseSetSPCdv(vis_RCase*
p,Vint index,Vint tag,Vint type,Vdouble value[],Vint
master);VKI_EXTERN void vis_RCaseSetSPCTId(vis_RCase*
p,Vint index,Vint tag,Vint tid[]);VKI_EXTERN void vis_RCaseSetSPCDot(vis_RCase*
p,Vint index,Vint tag,Vint dottype);VKI_EXTERN void
vis_RCaseSPCMax(vis_RCase* p,Vint* maxindex);VKI_EXTERN
void vis_RCaseSPCNum(vis_RCase* p,Vint* numindex,Vint*
numvalue,Vint* nummaster);VKI_EXTERN void vis_RCaseSPCInitIter(vis_RCase*
p);VKI_EXTERN void vis_RCaseSPCNextIter(vis_RCase* p,
Vint* index);VKI_EXTERN void vis_RCaseSPCNumTId(vis_RCase*
p,Vint* numtid);VKI_EXTERN void vis_RCaseSPCNumDot(vis_RCase*
p,Vint* numdot);VKI_EXTERN void vis_RCaseSPCUseTag(vis_RCase*
p,Vint* ntags,Vint tag[]);VKI_EXTERN void vis_RCaseSPCTag(vis_RCase*
p,Vint index,Vint* ntags,Vint tag[]);VKI_EXTERN void
vis_RCaseSPC(vis_RCase* p,Vint index,Vint tag,Vint*
type,Vfloat value[],Vint* master);VKI_EXTERN void vis_RCaseSPCdv(vis_RCase*
p,Vint index,Vint tag,Vint* type,Vdouble value[],Vint*
master);VKI_EXTERN void vis_RCaseSPCTId(vis_RCase* p,
Vint index,Vint tag,Vint tid[]);VKI_EXTERN void vis_RCaseSPCDot(vis_RCase*
p,Vint index,Vint tag,Vint* dottype);VKI_EXTERN void
vis_RCaseNodeGroup(vis_RCase* p,vis_Group* group,vis_Group*
groupdst);VKI_EXTERN void vis_RCaseSetElemC(vis_RCase*
p,Vint index,Vint tag,Vint type,Vfloat value[]);VKI_EXTERN
void vis_RCaseSetElemCdv(vis_RCase* p,Vint index,Vint
tag,Vint type,Vdouble value[]);VKI_EXTERN void vis_RCaseElemCMax(vis_RCase*
p,Vint* maxindex);VKI_EXTERN void vis_RCaseElemCNum(vis_RCase*
p,Vint* numindex,Vint* numvalue);VKI_EXTERN void vis_RCaseElemCInitIter(vis_RCase*
p);VKI_EXTERN void vis_RCaseElemCNextIter(vis_RCase*
p,Vint* index);VKI_EXTERN void vis_RCaseElemCUseTag(vis_RCase*
p,Vint* ntags,Vint tag[]);VKI_EXTERN void vis_RCaseElemCTag(vis_RCase*
p,Vint index,Vint* ntags,Vint tag[]);VKI_EXTERN void
vis_RCaseElemC(vis_RCase* p,Vint index,Vint tag,Vint*
type,Vfloat* value);VKI_EXTERN void vis_RCaseElemCdv(vis_RCase*
p,Vint index,Vint tag,Vint* type,Vdouble* value);VKI_EXTERN
void vis_RCaseElemGroup(vis_RCase* p,vis_Group* group,
vis_Group* groupdst);VKI_EXTERN void vis_RCaseClear(vis_RCase*
p);VKI_EXTERN void vis_RCaseSpecFlag(vis_RCase* p,Vint*
flag);VKI_EXTERN void vis_RCaseAdd(vis_RCase* p,vis_RCase*
addrcase);VKI_EXTERN void vis_RCaseSetId(vis_RCase*
p,Vint id);VKI_EXTERN void vis_RCaseGetId(vis_RCase*
p,Vint* id);VKI_EXTERN void vis_RCaseSetName(vis_RCase*
p,const Vchar* name);VKI_EXTERN void vis_RCaseGetName(vis_RCase*
p,Vchar name[]);VKI_EXTERN void vis_RCasePrint(vis_RCase*
p);VKI_EXTERN void vis_RCaseCopy(vis_RCase* p,vis_RCase*
fromp);
#ifdef __cplusplus
}
#endif
#endif

