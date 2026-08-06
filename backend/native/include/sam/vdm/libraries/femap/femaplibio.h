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
 
#ifndef FEMAPLIBIO_DEF
#define FEMAPLIBIO_DEF
#include "sam/base/base.h"
#define FEMAPLIBIO_MAXITEMS 20
#define FEMAPLIBIO_BUFSIZE 256
typedef struct vdm_FEMAPLibio { FILE* fd;Vint line;
Vint nitems;Vint irec;Vint bid;Vint parsed;Vchar buf[FEMAPLIBIO_MAXITEMS][FEMAPLIBIO_BUFSIZE];
Vchar buffer[FEMAPLIBIO_BUFSIZE];Vint size;}vdm_FEMAPLibio;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_FEMAPLibio* vdm_FEMAPLibioBegin(void);
VKI_EXTERN void vdm_FEMAPLibioEnd(vdm_FEMAPLibio* p);
VKI_EXTERN void vdm_FEMAPLibioOpen(vdm_FEMAPLibio* p,
Vchar* filename,Vint* ierr);VKI_EXTERN void vdm_FEMAPLibioClose(vdm_FEMAPLibio*
p);VKI_EXTERN void vdm_FEMAPLibioGetBlock(vdm_FEMAPLibio*
p,Vint* bid);VKI_EXTERN Vint vdm_FEMAPLibioi(vdm_FEMAPLibio*
p,Vint irec,Vint item,Vint* ival);VKI_EXTERN Vint vdm_FEMAPLibioiN(vdm_FEMAPLibio*
p,Vint irec,Vint item,Vint n,Vint ival[]);VKI_EXTERN
Vint vdm_FEMAPLibiod(vdm_FEMAPLibio* p,Vint irec,Vint
item,Vdouble* dval);VKI_EXTERN Vint vdm_FEMAPLibiodN(vdm_FEMAPLibio*
p,Vint irec,Vint item,Vint n,Vdouble dval[]);VKI_EXTERN
Vint vdm_FEMAPLibioc(vdm_FEMAPLibio* p,Vint irec,Vchar
cval[]);VKI_EXTERN void vdm_FEMAPLibioRewind(vdm_FEMAPLibio*
p);VKI_EXTERN void vdm_FEMAPLibioGetPos(vdm_FEMAPLibio*
p,Vlong* nc);VKI_EXTERN void vdm_FEMAPLibioSetPos(vdm_FEMAPLibio*
p,Vlong nc);VKI_EXTERN void vdm_FEMAPLibioGetLine(vdm_FEMAPLibio*
p,Vint* line);VKI_EXTERN void vdm_FEMAPLibioSetLine(vdm_FEMAPLibio*
p,Vint line);VKI_EXTERN void vdm_FEMAPLibioSetRecord(vdm_FEMAPLibio*
p,Vint irec);
#ifdef __cplusplus
}
#endif
#endif

