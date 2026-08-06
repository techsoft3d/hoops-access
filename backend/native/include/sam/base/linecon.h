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
 
#ifndef LINECON_DEF
#define LINECON_DEF
#include "sam/base/basedefs.h"
#define LINECON_MAXLENGTH 1
struct vsy_LineCon { Vint ierr;Vint numedge;Vint maxedge;
Vint maxedst;Vint numnode;Vint maxnode;Vint numunno;
Vint maxunno;Vint (*edno)[2];Vint* eddf;Vint* noed;
Vint* noedpntr;Vint* noedordr;Vint* noid;Vint processed;
Vint mxelen;Vint numstrips;Vint maxlength;Vint* edsttemp;
Vint* edst;Vint* edstpntr;Vint* kstrip;Vint* lstrip;
Vint* nodehash;Vint* nodeindx;Vint* edgemark;Vint* edgeindx;
Vint ncanc;Vint iproc;
#ifdef __cplusplus
public: VKI_EXTERN vsy_LineCon(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_LineCon(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void SetParami(Vint,Vint);VKI_EXTERN
void Append(Vint[2]);VKI_EXTERN void Ref(Vint,Vint[2]);
VKI_EXTERN void Num(Vint*);VKI_EXTERN void Clear();
VKI_EXTERN void Process(Vint*,Vint*);VKI_EXTERN void
Strip(Vint,Vint*,Vint[],Vint[]);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_LineCon* vsy_LineConBegin(void);VKI_EXTERN
void vsy_LineCon_Construct(vsy_LineCon* p);VKI_EXTERN
void vsy_LineConEnd(vsy_LineCon* p);VKI_EXTERN void
vsy_LineCon_Destruct(vsy_LineCon* p);VKI_EXTERN Vint
vsy_LineConError(vsy_LineCon* p);VKI_EXTERN void vsy_LineConDef(vsy_LineCon*
p,Vint numline);VKI_EXTERN void vsy_LineConInq(const
vsy_LineCon* p,Vint* numline);VKI_EXTERN void vsy_LineConSetParami(vsy_LineCon*
p,Vint ptype,Vint iparam);VKI_EXTERN void vsy_LineConAppend(vsy_LineCon*
p,Vint ix[2]);VKI_EXTERN void vsy_LineConRef(vsy_LineCon*
p,Vint index,Vint ix[2]);VKI_EXTERN void vsy_LineConNum(vsy_LineCon*
p,Vint* numlin);VKI_EXTERN void vsy_LineConClear(vsy_LineCon*
p);VKI_EXTERN void vsy_LineConProcess(vsy_LineCon* p,
Vint* numstrip,Vint* maxlength);VKI_EXTERN void vsy_LineConStrip(vsy_LineCon*
p,Vint istrip,Vint* nix,Vint it[],Vint ix[]);VKI_EXTERN
void vsy_LineConPrint(vsy_LineCon* p);
#ifdef __cplusplus
}
#endif
#endif

