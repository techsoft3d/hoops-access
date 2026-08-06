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
 
#ifndef TECPLOTDAT_DEF
#define TECPLOTDAT_DEF
#include "sam/base/basedefs.h"
typedef struct vdm_TecplotDat { Vint ivar[9];Vint ncmp;
Vint dtyp;Vint type;Vint step;}vdm_TecplotDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_TecplotDat* vdm_TecplotDatBegin(void);
VKI_EXTERN void vdm_TecplotDatEnd(vdm_TecplotDat* p);
VKI_EXTERN void vdm_TecplotDatDef(vdm_TecplotDat* p,
Vint dtyp,Vint type);VKI_EXTERN void vdm_TecplotDatInq(vdm_TecplotDat*
p,Vint ivar[9],Vint* ncmp,Vint* dtyp,Vint* type);VKI_EXTERN
void vdm_TecplotDatSetComp(vdm_TecplotDat* p,Vint icmp,
Vint ivar);VKI_EXTERN void vdm_TecplotDatSetStep(vdm_TecplotDat*
p,Vint step);VKI_EXTERN void vdm_TecplotDatGetStep(vdm_TecplotDat*
p,Vint* step);
#ifdef __cplusplus
}
#endif
#endif

