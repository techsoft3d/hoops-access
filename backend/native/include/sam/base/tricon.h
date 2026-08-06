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
 
#ifndef TRICON_DEF
#define TRICON_DEF
#include "sam/base/basedefs.h"
#define TRICON_MAXLENGTH 1
#define TRICON_SWAP 2
struct vsy_TriCon { Vint ierr;Vint numelem;Vint maxelem;
Vint maxelst;Vint numedge;Vint maxedge;Vint (*elno)[3];
Vint* eldf;Vint (*elel)[3];Vchar (*elbk)[3];Vint (*edno)[2];
Vint* edel;Vint processed;Vint mxvlen;Vint mxtlen;Vint
swapfl;Vint numstrips;Vint maxlength;Vint* estart;Vint*
kstart;Vint* lstrip;Vint* elemmark;Vint* elemindx;Vint
ncanc;Vint iproc;
#ifdef __cplusplus
public: VKI_EXTERN vsy_TriCon(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_TriCon(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void SetParami(Vint,Vint);VKI_EXTERN
void Append(Vint[3]);VKI_EXTERN void Ref(Vint,Vint[3]);
VKI_EXTERN void Num(Vint*);VKI_EXTERN void Clear();
VKI_EXTERN void Process(Vint*,Vint*);VKI_EXTERN void
Strip(Vint,Vint*,Vint[],Vint[]);VKI_EXTERN void Adj(Vint,
Vint[3],Vint[3]);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_TriCon* vsy_TriConBegin(void);VKI_EXTERN
void vsy_TriCon_Construct(vsy_TriCon* p);VKI_EXTERN
void vsy_TriConEnd(vsy_TriCon* p);VKI_EXTERN void vsy_TriCon_Destruct(vsy_TriCon*
p);VKI_EXTERN Vint vsy_TriConError(vsy_TriCon* p);VKI_EXTERN
void vsy_TriConDef(vsy_TriCon* p,Vint numtri);VKI_EXTERN
void vsy_TriConInq(const vsy_TriCon* p,Vint* numtri);
VKI_EXTERN void vsy_TriConSetParami(vsy_TriCon* p,Vint
ptype,Vint iparam);VKI_EXTERN void vsy_TriConAppend(vsy_TriCon*
p,Vint ix[3]);VKI_EXTERN void vsy_TriConRef(vsy_TriCon*
p,Vint index,Vint ix[3]);VKI_EXTERN void vsy_TriConNum(vsy_TriCon*
p,Vint* numtri);VKI_EXTERN void vsy_TriConClear(vsy_TriCon*
p);VKI_EXTERN void vsy_TriConProcess(vsy_TriCon* p,
Vint* numstrip,Vint* maxlength);VKI_EXTERN void vsy_TriConStrip(vsy_TriCon*
p,Vint istrip,Vint* nix,Vint it[],Vint ix[]);VKI_EXTERN
void vsy_TriConAdj(vsy_TriCon* p,Vint index,Vint aix[3],
Vint aed[3]);VKI_EXTERN void vsy_TriConPrint(vsy_TriCon*
p);
#ifdef __cplusplus
}
#endif
#endif

