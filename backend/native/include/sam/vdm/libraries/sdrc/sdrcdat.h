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
 
#ifndef SDRCDAT_DEF
#define SDRCDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct vdm_SDRCDat { Vlong nc;Vint ncmp;Vint
type;Vint sect;Vint dtype;Vint cplx;Vint indx;Vint layr;
}vdm_SDRCDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_SDRCDat* vdm_SDRCDatBegin(void);VKI_EXTERN
void vdm_SDRCDatEnd(vdm_SDRCDat* sdrcdat);VKI_EXTERN
void vdm_SDRCDatDef(vdm_SDRCDat* sdrcdat,Vlong nc,Vint
ncmp,Vint type,Vint sect,Vint dtype,Vint cplx);VKI_EXTERN
void vdm_SDRCDatInq(vdm_SDRCDat* sdrcdat,Vlong* nc,
Vint* ncmp,Vint* type,Vint* sect,Vint* dtype,Vint* cplx);
VKI_EXTERN void vdm_SDRCDatSetIndx(vdm_SDRCDat* sdrcdat,
Vint indx);VKI_EXTERN void vdm_SDRCDatGetIndx(vdm_SDRCDat*
sdrcdat,Vint* indx);VKI_EXTERN void vdm_SDRCDatSetLayr(vdm_SDRCDat*
sdrcdat,Vint layr);VKI_EXTERN void vdm_SDRCDatGetLayr(vdm_SDRCDat*
sdrcdat,Vint* layr);
#ifdef __cplusplus
}
#endif
#endif

