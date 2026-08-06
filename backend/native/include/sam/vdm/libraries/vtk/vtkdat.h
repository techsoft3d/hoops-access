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
 
#ifndef VTKDAT_DEF
#define VTKDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct { Vint nentries;Vint icur;Vint* index;
Vlong* pos;Vchar c;Vchar d;}vdm_VTKDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_VTKDat* vdm_VTKDatBegin(void);VKI_EXTERN
void vdm_VTKDatEnd(vdm_VTKDat* p);VKI_EXTERN void vdm_VTKDatDef(vdm_VTKDat*
p,Vchar c,Vchar d);VKI_EXTERN void vdm_VTKDatInq(vdm_VTKDat*
p,Vchar* c,Vchar* d);VKI_EXTERN void vdm_VTKDatAdd(vdm_VTKDat*
p,Vint index,Vlong pos);VKI_EXTERN void vdm_VTKDatInitIter(vdm_VTKDat*
p);VKI_EXTERN void vdm_VTKDatNextIter(vdm_VTKDat* p,
Vint* index,Vlong* pos);
#ifdef __cplusplus
}
#endif
#endif

