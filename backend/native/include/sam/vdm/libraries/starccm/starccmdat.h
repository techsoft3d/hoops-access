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
 
#ifndef STARCCMDAT_DEF
#define STARCCMDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct vdm_STARCCMDat { Vint type;Vint id1;
Vint id2;Vint location;Vint ncmp;Vint dtype;Vfloat time;
Vchar cqua[80];Vint nqua;Vint iqua[2];Vchar* source;
Vchar* sname;vsy_List* list;vsy_IntVec* intvec;}vdm_STARCCMDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_STARCCMDat* vdm_STARCCMDatBegin(void);
VKI_EXTERN void vdm_STARCCMDatEnd(vdm_STARCCMDat* p);
VKI_EXTERN void vdm_STARCCMDatDef(vdm_STARCCMDat* p,
Vint type,Vint id1,Vint id2,Vint location,Vint ncmp,
Vint nqua,Vint iqua[2],Vchar cqua[],Vchar* source,Vchar*
sname);VKI_EXTERN void vdm_STARCCMDatInq(vdm_STARCCMDat*
p,Vint* type,Vint* id1,Vint* id2,Vint* location,Vint*
ncmp,Vint* nqua,Vint** iqua,Vchar** cqua,Vchar source[],
Vchar sname[]);VKI_EXTERN void vdm_STARCCMDatSetObject(vdm_STARCCMDat*
p,Vint type,Vobject* obj);VKI_EXTERN void vdm_STARCCMDatGetObject(vdm_STARCCMDat*
p,Vint type,Vobject** obj);VKI_EXTERN void vdm_STARCCMDatSetTime(vdm_STARCCMDat*
p,Vfloat time);VKI_EXTERN void vdm_STARCCMDatGetTime(vdm_STARCCMDat*
p,Vfloat* time);VKI_EXTERN void vdm_STARCCMDatSetDType(vdm_STARCCMDat*
p,Vint dtype);VKI_EXTERN void vdm_STARCCMDatGetDType(vdm_STARCCMDat*
p,Vint* dtype);
#ifdef __cplusplus
}
#endif
#endif

