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
 
#ifndef MCASE_DEF
#define MCASE_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
typedef struct vis_MCase_MPC { Vint type;Vint numterms;
Vint* ix;Vint* ig;Vdouble* c;Vdouble r;}vis_MCase_MPC;
struct vis_MCase { Vint ierr;Vint maxmpcindex;Vint maxmpcterms;
Vint maxrhs;vsy_HashTable* mpcTable;Vint mpid;Vchar*
name;
#ifdef __cplusplus
public: VKI_EXTERN vis_MCase(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_MCase(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void SetMPC(Vint,Vint,Vint[],Vint[],Vfloat[],
Vfloat);VKI_EXTERN void SetMPCdv(Vint,Vint,Vint[],Vint[],
Vdouble[],Vdouble);VKI_EXTERN void SetRHS(Vint,Vfloat);
VKI_EXTERN void SetRHSdv(Vint,Vdouble);VKI_EXTERN void
SetCon(Vint,Vint,Vint[]);VKI_EXTERN void Num(Vint,Vint*);
VKI_EXTERN void MPC(Vint,Vint*,Vint[],Vint[],Vfloat[],
Vfloat*);VKI_EXTERN void MPCdv(Vint,Vint*,Vint[],Vint[],
Vdouble[],Vdouble*);VKI_EXTERN void Con(Vint,Vint*,
Vint*,Vint[]);VKI_EXTERN void Del(Vint);VKI_EXTERN void
Type(Vint,Vint*);VKI_EXTERN void Max(Vint*,Vint*,Vint*);
VKI_EXTERN void InitIter();VKI_EXTERN void NextIter(Vint*);
VKI_EXTERN void Clear();VKI_EXTERN void SpecFlag(Vint*);
VKI_EXTERN void Add(vis_MCase*);VKI_EXTERN void SetId(Vint);
VKI_EXTERN void GetId(Vint*);VKI_EXTERN void SetName(const
Vchar*);VKI_EXTERN void GetName(Vchar[]);VKI_EXTERN
void Print();VKI_EXTERN void GetNumberOfterms(Vint,
Vint*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_MCase* vis_MCaseBegin(void);VKI_EXTERN
void vis_MCase_Construct(vis_MCase* p);VKI_EXTERN void
vis_MCaseEnd(vis_MCase* p);VKI_EXTERN void vis_MCase_Destruct(vis_MCase*
p);VKI_EXTERN Vint vis_MCaseError(vis_MCase* p);VKI_EXTERN
void vis_MCaseSetMPC(vis_MCase* p,Vint index,Vint nterms,
Vint ix[],Vint tag[],Vfloat c[],Vfloat r);VKI_EXTERN
void vis_MCaseSetMPCdv(vis_MCase* p,Vint index,Vint
numterms,Vint ix[],Vint ig[],Vdouble c[],Vdouble rhs);
VKI_EXTERN void vis_MCaseSetRHS(vis_MCase* p,Vint index,
Vfloat r);VKI_EXTERN void vis_MCaseSetRHSdv(vis_MCase*
p,Vint index,Vdouble rhs);VKI_EXTERN void vis_MCaseSetCon(vis_MCase*
p,Vint index,Vint type,Vint ix[]);VKI_EXTERN void vis_MCaseNum(vis_MCase*
p,Vint index,Vint* nterms);VKI_EXTERN void vis_MCaseMPC(vis_MCase*
p,Vint index,Vint* nterms,Vint ix[],Vint tag[],Vfloat
c[],Vfloat* r);VKI_EXTERN void vis_MCaseMPCdv(vis_MCase*
p,Vint index,Vint* numterms,Vint ix[],Vint ig[],Vdouble
c[],Vdouble* rhs);VKI_EXTERN void vis_MCaseCon(vis_MCase*
p,Vint index,Vint* type,Vint* nterms,Vint ix[]);VKI_EXTERN
void vis_MCaseDel(vis_MCase* p,Vint index);VKI_EXTERN
void vis_MCaseType(vis_MCase* p,Vint index,Vint* type);
VKI_EXTERN void vis_MCaseMax(vis_MCase* p,Vint* maxindex,
Vint* maxterms,Vint* maxrhs);VKI_EXTERN void vis_MCaseInitIter(vis_MCase*
p);VKI_EXTERN void vis_MCaseNextIter(vis_MCase* p,Vint*
index);VKI_EXTERN void vis_MCaseClear(vis_MCase* p);
VKI_EXTERN void vis_MCaseSpecFlag(vis_MCase* p,Vint*
flag);VKI_EXTERN void vis_MCaseAdd(vis_MCase* p,vis_MCase*
addmcase);VKI_EXTERN void vis_MCaseSetId(vis_MCase*
p,Vint id);VKI_EXTERN void vis_MCaseGetId(vis_MCase*
p,Vint* id);VKI_EXTERN void vis_MCaseSetName(vis_MCase*
p,const Vchar* name);VKI_EXTERN void vis_MCaseGetName(vis_MCase*
p,Vchar name[]);VKI_EXTERN void vis_MCasePrint(vis_MCase*
p);VKI_EXTERN void vis_MCaseGetNumberOfterms(vis_MCase*
p,Vint type,Vint* numterms);
#ifdef __cplusplus
}
#endif
#endif

