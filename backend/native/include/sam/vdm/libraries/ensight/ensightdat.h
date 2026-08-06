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
 
#ifndef ENSIGHTDAT_DEF
#define ENSIGHTDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct vdm_EnSightDat { Vchar description[80];
Vchar cqua[80];Vchar fname[SYS_MAXPATHCHAR];Vint datatype;
Vint enttype;Vint iscomplex;Vint ts;Vint fsflag;Vint
freqflag;Vint type;Vint id1;Vint I1;Vint nqua;Vint iqua[SYS_NQUA_MAX];
Vint np;Vfloat freq;}vdm_EnSightDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_EnSightDat* vdm_EnSightDatBegin(void);
VKI_EXTERN void vdm_EnSightDatEnd(vdm_EnSightDat* p);
VKI_EXTERN void vdm_EnSightDatDef(vdm_EnSightDat* p,
Vint type,Vchar description[],Vchar cqua[],Vint datatype,
Vint enttype,Vint iscomplex,Vchar fname[],Vint ts,Vint
fsflag,Vint freqflag,Vfloat freq,Vint nqua,Vint iqua[],
Vint id1,Vint I1,Vint np);VKI_EXTERN void vdm_EnSightDatInq(vdm_EnSightDat*
p,Vint* type,Vchar description[],Vchar cqua[],Vint*
datatype,Vint* enttype,Vint* iscomplex,Vchar fname[80],
Vint* ts,Vint* fsflag,Vint* freqflag,Vfloat* freq,Vint*
nqua,Vint iqua[],Vint* id1,Vint* I1,Vint* np);
#ifdef __cplusplus
}
#endif
#endif

