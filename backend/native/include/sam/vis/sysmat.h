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
 
#ifndef SYSMAT_DEF
#define SYSMAT_DEF
#include "sam/vis/visdefs.h"
#define SYSMAT_VECTOR 0
#define SYSMAT_MATRIX 1
#define SYSMAT_MATRIX_DIAG 2
#define SYSMAT_MATRIX_SPARSE 3
#define SYSMAT_TECH 0
#define SYSMAT_MAXITER 1
#define SYSMAT_TOL 0
#define SYSMAT_TECH_DIRECT 0
#define SYSMAT_TECH_CONJGRAD 1
#define SYSMAT_NUMITER 0
#define SYSMAT_CONV 0
#define SYSMAT_FUN_PROD 0
typedef struct vis_SysMat vis_SysMat;struct vis_SysMat
{ Vint ierr;Vint type;Vint nod;Vint sized;Vdouble fdet;
Vint nexp;Vint nneg;Vint sing;Vint* iptr;Vdouble* dptr;
Vdouble conv;Vdouble tol;Vint iter;vis_IdTran* idtran;
Vint tech;Vint maxiter;void (*funprod)(vis_SysMat*,
vis_SysMat*,vis_SysMat*,Vobject*);Vobject* funobjprod;
Vint maxelem;Vint numel;Vint** elemdof;Vlong* pointers;
Vint* indices;struct Sp_Chol* L;Vdouble* rwork;Vint
method;Vdouble* lnz;Vdouble* diag;};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_SysMat* vis_SysMatBegin(void);VKI_EXTERN
void vis_SysMatEnd(vis_SysMat* p);VKI_EXTERN Vint vis_SysMatError(vis_SysMat*
p);VKI_EXTERN void vis_SysMatSetObject(vis_SysMat* p,
Vint objecttype,Vobject* object);VKI_EXTERN void vis_SysMatDef(vis_SysMat*
p,Vint type,Vint nod);VKI_EXTERN void vis_SysMatInq(vis_SysMat*
p,Vint* type,Vint* nod);VKI_EXTERN void vis_SysMatCopy(vis_SysMat*
p,vis_SysMat* fromsysmat);VKI_EXTERN void vis_SysMatPrint(vis_SysMat*
p);VKI_EXTERN void vis_SysMatComputeBand(vis_SysMat*
p,Vint nft,Vint lm[]);VKI_EXTERN void vis_SysMatProcessBand(vis_SysMat*
p);VKI_EXTERN void vis_SysMatBandIdTran(vis_SysMat*
p,vis_IdTran* idtran);VKI_EXTERN void vis_SysMatAlloc(vis_SysMat*
p);VKI_EXTERN void vis_SysMatAssem(vis_SysMat* p,Vint
nft,Vint lm[],Vdouble s[]);VKI_EXTERN void vis_SysMatGather(vis_SysMat*
p,Vint nft,Vint lm[],Vdouble s[]);VKI_EXTERN void vis_SysMatSetValues(vis_SysMat*
p,Vint nft,Vint lm[],Vdouble s[]);VKI_EXTERN void vis_SysMatValues(vis_SysMat*
p,Vint nft,Vint lm[],Vdouble s[]);VKI_EXTERN void vis_SysMatFactor(vis_SysMat*
p,Vint* ising);VKI_EXTERN void vis_SysMatGetPivots(vis_SysMat*
p,Vint* sing,Vint* nneg,Vdouble* fdet,Vint* nexp);VKI_EXTERN
void vis_SysMatSolve(vis_SysMat* p,vis_SysMat* sysx);
VKI_EXTERN void vis_SysMatDot(vis_SysMat* p,vis_SysMat*
sysx,Vdouble* s);VKI_EXTERN void vis_SysMatZero(vis_SysMat*
p);VKI_EXTERN void vis_SysMatSetParami(vis_SysMat* p,
Vint type,Vint value);VKI_EXTERN void vis_SysMatSetParamd(vis_SysMat*
p,Vint type,Vdouble value);VKI_EXTERN void vis_SysMatGetInteger(vis_SysMat*
p,Vint type,Vint* value);VKI_EXTERN void vis_SysMatGetDouble(vis_SysMat*
p,Vint type,Vdouble* value);VKI_EXTERN void vis_SysMatSetFunction(vis_SysMat*
p,Vint functype,Vfunc* function,Vobject* object);
#ifdef __cplusplus
}
#endif
#endif

