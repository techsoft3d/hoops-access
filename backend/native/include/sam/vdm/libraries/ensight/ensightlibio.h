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
 
#ifndef ENSIGHTLIBIO_DEF
#define ENSIGHTLIBIO_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#define ENSIGHT_FORMAT_UNKNOWN 0
#define ENSIGHT_FORMAT_CBIN 1
#define ENSIGHT_FORMAT_FBIN 2
#define ENSIGHT_FORMAT_ASCII 3
typedef struct vdm_EnSightLibio { FILE* fp;Vchar buffer[2048];
Vint swap;Vint type;Vint format;Vint lineno;Vint goldflag;
Vint fsize;Vlong fread;Vint maxbuf;Vchar (*b)[13];}
vdm_EnSightLibio;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_EnSightLibio* vdm_EnSightLibioBegin(void);
VKI_EXTERN void vdm_EnSightLibioEnd(vdm_EnSightLibio*
p);VKI_EXTERN Vint vdm_EnSightLibioRF(vdm_EnSightLibio*
p,Vlong n,Vfloat* x);VKI_EXTERN Vint vdm_EnSightLibioRI(vdm_EnSightLibio*
p,Vlong n,Vint* ix);VKI_EXTERN Vint vdm_EnSightLibioRC(vdm_EnSightLibio*
p,Vint n,Vchar cx[]);VKI_EXTERN Vint vdm_EnSightLibioRM(vdm_EnSightLibio*
p,Vlong n,Vint type[],Vfloat* x);VKI_EXTERN void vdm_EnSightLibioSetMark(vdm_EnSightLibio*
p,fpos_t* position);VKI_EXTERN void vdm_EnSightLibioGetMark(vdm_EnSightLibio*
p,fpos_t* position);VKI_EXTERN void vdm_EnSightLibioSetFile(vdm_EnSightLibio*
p,FILE* f);VKI_EXTERN void vdm_EnSightLibioSetSwap(vdm_EnSightLibio*
p,Vint swap);VKI_EXTERN void vdm_EnSightLibioGetSwap(vdm_EnSightLibio*
p,Vint* swap);VKI_EXTERN void vdm_EnSightLibioSetFormat(vdm_EnSightLibio*
p,Vint format);VKI_EXTERN void vdm_EnSightLibioSetGold(vdm_EnSightLibio*
p,Vint goldflag);
#ifdef __cplusplus
}
#endif
#endif

