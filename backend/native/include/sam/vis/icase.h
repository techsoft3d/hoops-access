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
 
#ifndef ICASE_DEF
#define ICASE_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/group.h"
typedef struct vis_ICase_SPV { Vint mtags[ICASE_SPV_MAX];
Vint ntags[ICASE_SPV_MAX];Vint tags[ICASE_SPV_MAX];
Vdouble* vals[ICASE_SPV_MAX];}vis_ICase_SPV;struct vis_ICase
{ Vint ierr;Vint maxspvindex[ICASE_SPV_MAX];vsy_HashTable*
spvTable;Vint icid;Vchar* name;
#ifdef __cplusplus
public: VKI_EXTERN vis_ICase(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_ICase(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void SetSPV(Vint,Vint,Vint,Vint[],Vfloat[]);
VKI_EXTERN void SetSPVdv(Vint,Vint,Vint,Vint[],Vdouble[]);
VKI_EXTERN void SPVMax(Vint,Vint*);VKI_EXTERN void SPVNum(Vint,
Vint*);VKI_EXTERN void SPVType(Vint,Vint*,Vint[]);VKI_EXTERN
void SPV(Vint,Vint,Vint*,Vint[],Vfloat[]);VKI_EXTERN
void SPVdv(Vint,Vint,Vint*,Vint[],Vdouble[]);VKI_EXTERN
void SPVUseTag(Vint,Vint*,Vint[]);VKI_EXTERN void NodeGroup(vis_Group*,
vis_Group*);VKI_EXTERN void Clear();VKI_EXTERN void
SpecFlag(Vint*);VKI_EXTERN void SetId(Vint);VKI_EXTERN
void GetId(Vint*);VKI_EXTERN void SetName(const Vchar*);
VKI_EXTERN void GetName(Vchar[]);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_ICase* vis_ICaseBegin(void);VKI_EXTERN
void vis_ICase_Construct(vis_ICase* p);VKI_EXTERN void
vis_ICaseEnd(vis_ICase* p);VKI_EXTERN void vis_ICase_Destruct(vis_ICase*
p);VKI_EXTERN Vint vis_ICaseError(vis_ICase* p);VKI_EXTERN
void vis_ICaseSetSPV(vis_ICase* p,Vint index,Vint type,
Vint ntags,Vint tag[],Vfloat value[]);VKI_EXTERN void
vis_ICaseSetSPVdv(vis_ICase* p,Vint index,Vint type,
Vint ntags,Vint tag[],Vdouble val[]);VKI_EXTERN void
vis_ICaseSPVMax(vis_ICase* p,Vint type,Vint* maxindex);
VKI_EXTERN void vis_ICaseSPVNum(vis_ICase* p,Vint type,
Vint* numindex);VKI_EXTERN void vis_ICaseSPVType(vis_ICase*
p,Vint index,Vint* ntypes,Vint type[]);VKI_EXTERN void
vis_ICaseSPV(vis_ICase* p,Vint index,Vint type,Vint*
ntags,Vint tag[],Vfloat value[]);VKI_EXTERN void vis_ICaseSPVdv(vis_ICase*
p,Vint index,Vint type,Vint* ntags,Vint tag[],Vdouble
val[]);VKI_EXTERN void vis_ICaseSPVUseTag(vis_ICase*
p,Vint type,Vint* ntags,Vint tag[]);VKI_EXTERN void
vis_ICaseNodeGroup(vis_ICase* p,vis_Group* group,vis_Group*
groupdst);VKI_EXTERN void vis_ICaseClear(vis_ICase*
p);VKI_EXTERN void vis_ICaseSpecFlag(vis_ICase* p,Vint*
flag);VKI_EXTERN void vis_ICaseSetId(vis_ICase* p,Vint
id);VKI_EXTERN void vis_ICaseGetId(vis_ICase* p,Vint*
id);VKI_EXTERN void vis_ICaseSetName(vis_ICase* p,const
Vchar* name);VKI_EXTERN void vis_ICaseGetName(vis_ICase*
p,Vchar name[]);VKI_EXTERN void vis_ICasePrint(vis_ICase*
p);
#ifdef __cplusplus
}
#endif
#endif

