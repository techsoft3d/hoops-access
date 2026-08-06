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
 
#ifndef DATATABLE_DEF
#define DATATABLE_DEF
#include "sam/base/basedefs.h"
#define DATATABLE_INTERPOLATE 1
#define DATATABLE_EXTRAPOLATE 2
#define DATATABLE_CLAMP 1
#define DATATABLE_LINEAR 2
#define DATATABLE_PARABOLIC_SLOPE 3
struct vsy_DataTable { Vint ierr;Vint maxelt;Vint numdep;
Vint vsize;Vint iter;Vint sortflag;Vint inter;Vint extra;
Vint maxidx;Vdouble* var;Vdouble** vec;Vint* ins;Vdouble*
vas;Vdouble* undefined;Vdouble* value;
#ifdef __cplusplus
public: VKI_EXTERN vsy_DataTable(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_DataTable(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(Vint,Vint);VKI_EXTERN void
Inq(Vint*,Vint*)const;VKI_EXTERN void SetParami(Vint,
Vint);VKI_EXTERN void Count(Vint*)const;VKI_EXTERN void
Insert(Vdouble,Vdouble[]);VKI_EXTERN void Lookup(Vdouble,
Vdouble*[])const;VKI_EXTERN void Eval(Vdouble,Vdouble[]);
VKI_EXTERN void EvalGrad(Vdouble,Vdouble[],Vdouble[]);
VKI_EXTERN void Clear();VKI_EXTERN void InitIter();
VKI_EXTERN void NextIter(Vdouble*,Vdouble**);VKI_EXTERN
void ForEach(Vfunc1*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_DataTable* vsy_DataTableBegin(void);
VKI_EXTERN void vsy_DataTable_Construct(vsy_DataTable*
p);VKI_EXTERN void vsy_DataTableEnd(vsy_DataTable* p);
VKI_EXTERN void vsy_DataTable_Destruct(vsy_DataTable*
p);VKI_EXTERN Vint vsy_DataTableError(vsy_DataTable*
p);VKI_EXTERN void vsy_DataTableDef(vsy_DataTable* p,
Vint numobj,Vint length);VKI_EXTERN void vsy_DataTableInq(const
vsy_DataTable* p,Vint* len,Vint* siz);VKI_EXTERN void
vsy_DataTableSetParami(vsy_DataTable* p,Vint ptype,
Vint iparam);VKI_EXTERN void vsy_DataTableCount(const
vsy_DataTable* p,Vint* num);VKI_EXTERN void vsy_DataTableInsert(vsy_DataTable*
p,Vdouble value,Vdouble vec[]);VKI_EXTERN void vsy_DataTableLookup(const
vsy_DataTable* p,Vdouble value,Vdouble* vec[]);VKI_EXTERN
void vsy_DataTableEval(vsy_DataTable* p,Vdouble value,
Vdouble vec[]);VKI_EXTERN void vsy_DataTableEvalGrad(vsy_DataTable*
p,Vdouble value,Vdouble vec[],Vdouble grad[]);VKI_EXTERN
void vsy_DataTableClear(vsy_DataTable* p);VKI_EXTERN
void vsy_DataTableInitIter(vsy_DataTable* p);VKI_EXTERN
void vsy_DataTableNextIter(vsy_DataTable* p,Vdouble*
var,Vdouble** value);VKI_EXTERN void vsy_DataTableForEach(vsy_DataTable*
p,Vfunc1* func);
#ifdef __cplusplus
}
#endif
#endif

