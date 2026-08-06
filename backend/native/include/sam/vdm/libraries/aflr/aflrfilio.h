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
 
#ifndef AFLRFILIO_DEF
#define AFLRFILIO_DEF
#include "sam/base/base.h"
typedef struct vdm_AFLRFilio { FILE* fd;Vint ftype;
Vint dftype;Vint nentries;Vint nproc;Vint swap;Vint
charsize;Vint pcharsize;Vchar path[SYS_MAXPATHCHAR];
Vchar buf[40][80];Vchar buffer[4096];Vint bufloc;Vint
bufsize;Vint fsize;Vint nf;Vint ffsize;Vint fnf;}vdm_AFLRFilio;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_AFLRFilio* vdm_AFLRFilioBegin(void);
VKI_EXTERN void vdm_AFLRFilioEnd(vdm_AFLRFilio* p);
VKI_EXTERN void vdm_AFLRFilioOpen(vdm_AFLRFilio* p,
Vchar* filename,Vint* ierr);VKI_EXTERN void vdm_AFLRFilioDatai(vdm_AFLRFilio*
p,Vint n,Vint* ivalue,Vint* ierr);VKI_EXTERN void vdm_AFLRFilioDataf(vdm_AFLRFilio*
p,Vint n,Vfloat* fvalue,Vint* ierr);VKI_EXTERN void
vdm_AFLRFilioDatad(vdm_AFLRFilio* p,Vint n,Vdouble*
dvalue,Vint* ierr);VKI_EXTERN void vdm_AFLRFilioClose(vdm_AFLRFilio*
p);
#ifdef __cplusplus
}
#endif
#endif

