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
 
#ifndef REDPRE_DEF
#define REDPRE_DEF
#include "sam/base/basedefs.h"
#define PREC_MANTISSA 1
struct vsy_RedPre { Vint ierr;Vint type;Vdouble min;
Vdouble max;Vdouble dinc;
#ifdef __cplusplus
public: VKI_EXTERN vsy_RedPre(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_RedPre(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Extent(Vfloat,Vfloat);VKI_EXTERN void
Def(Vint);VKI_EXTERN void Inq(Vint*);VKI_EXTERN void
Load(Vint,Vfloat[],void*);VKI_EXTERN void Loaddv(Vint,
Vdouble[],void*);VKI_EXTERN void Store(Vint,void*,Vfloat[]);
VKI_EXTERN void Storedv(Vint,void*,Vdouble[]);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_RedPre* vsy_RedPreBegin(void);VKI_EXTERN
void vsy_RedPre_Construct(vsy_RedPre* p);VKI_EXTERN
void vsy_RedPreEnd(vsy_RedPre* p);VKI_EXTERN void vsy_RedPre_Destruct(vsy_RedPre*
p);VKI_EXTERN Vint vsy_RedPreError(vsy_RedPre* p);VKI_EXTERN
void vsy_RedPreExtent(vsy_RedPre* p,Vfloat min,Vfloat
max);VKI_EXTERN void vsy_RedPreDef(vsy_RedPre* p,Vint
type);VKI_EXTERN void vsy_RedPreInq(vsy_RedPre* p,Vint*
type);VKI_EXTERN void vsy_RedPreLoad(vsy_RedPre* p,
Vint n,Vfloat a[],void* b);VKI_EXTERN void vsy_RedPreLoaddv(vsy_RedPre*
p,Vint n,Vdouble a[],void* b);VKI_EXTERN void vsy_RedPreStore(vsy_RedPre*
p,Vint n,void* a,Vfloat b[]);VKI_EXTERN void vsy_RedPreStoredv(vsy_RedPre*
p,Vint n,void* a,Vdouble b[]);
#ifdef __cplusplus
}
#endif
#endif

