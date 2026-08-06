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
 
#ifndef NATDAT_DEF
#define NATDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/dataset.h"
#include "sam/vdm/library.h"
typedef struct vdm_NatDat { Vlong length;Vlong offset;
Vlong size;Vchar* hdfpath;vdm_Library* library;}vdm_NatDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_NatDat* vdm_NatDatBegin(void);VKI_EXTERN
void vdm_NatDatEnd(vdm_NatDat* natdat);VKI_EXTERN void
vdm_NatDatDef(vdm_NatDat* natdat,Vlong length,Vlong
offset,Vlong size);VKI_EXTERN void vdm_NatDatInq(vdm_NatDat*
natdat,Vlong* length,Vlong* offset,Vlong* size);VKI_EXTERN
void vdm_NatDatSetHDFPath(vdm_NatDat* natdat,Vchar path[],
Vchar name[]);VKI_EXTERN void vdm_NatDatGetHDFPath(vdm_NatDat*
natdat,Vchar** path);VKI_EXTERN void vdm_NatDatSetLibrary(vdm_NatDat*
natdat,vdm_Library* library);VKI_EXTERN void vdm_NatDatGetLibrary(vdm_NatDat*
natdat,vdm_Library** library);
#ifdef __cplusplus
}
#endif
#endif

