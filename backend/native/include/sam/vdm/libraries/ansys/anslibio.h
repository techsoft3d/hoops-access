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
#ifndef ANSLIBIO_DEF
#define ANSLIBIO_DEF
#include "sam/base/base.h"
#define ANSLIBIO_RECSIZ   1
#define ANSLIBIO_CHARSWAP 2
#define ANSLIBIO_BASEFLAG 3
#define ANSLIBIO_HOSTSWAP 4
typedef struct vdm_ANSLibio {
Vint ierr;
Vint ifd; 
FILE* fd;
Vint byteswap;
Vint charswap;
Vint baseflag;
Vint hostswap; 
Vint trecflag; 
Vint recsiz;
Vfloat release;
Vchar version[5];
Vchar sfil[SYS_MAXPATHCHAR]; 
Vlong slen;                  
FILE* fds[99];
Vuint bas1[2], bas2[2]; 
Vint status;
Vint nfbuf; 
Vfloat* fbuf;
Vint nzbuf; 
Vint* zbuf;
Vint bufsiz; 
Vlong posc;  
Vlong bufc;  
Vlong bufb;  
Vlong bufl;  
Vint* buf;
Vlong iseek, nread; 
vsy_ZMem* zmem;
} vdm_ANSLibio;
#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_ANSLibio*
vdm_ANSLibioBegin(void);
VKI_EXTERN void
vdm_ANSLibioEnd(vdm_ANSLibio* p);
VKI_EXTERN Vint
vdm_ANSLibioError(vdm_ANSLibio* p);
VKI_EXTERN void
vdm_ANSLibioGetInteger(vdm_ANSLibio* p, Vint type, Vint* value);
VKI_EXTERN void
vdm_ANSLibioSetStatus(vdm_ANSLibio* p, Vint status);
VKI_EXTERN void
vdm_ANSLibioOpen(vdm_ANSLibio* p, Vchar filename[], Vint* status);
VKI_EXTERN void
vdm_ANSLibioClose(vdm_ANSLibio* p);
VKI_EXTERN void
vdm_ANSLibioDiff(vdm_ANSLibio* p, Vuint rec1[2], Vuint rec2[2], Vlong* drec);
VKI_EXTERN void
vdm_ANSLibioBase(vdm_ANSLibio* p, Vuint bas1[2], Vuint bas2[2]);
VKI_EXTERN void
vdm_ANSLibioBaseExt(vdm_ANSLibio* p, Vuint bas1[2]);
VKI_EXTERN void
vdm_ANSLibioPosition(vdm_ANSLibio* p, Vuint rec, Vuint bas[2], Vint* ierr);
VKI_EXTERN void
vdm_ANSLibioPosition2(vdm_ANSLibio* p, Vuint rec[2], Vuint bas[2], Vint* ierr);
VKI_EXTERN void
vdm_ANSLibioReadIX(vdm_ANSLibio* p, Vint* nw, Vint id[], Vint* ierr);
VKI_EXTERN void
vdm_ANSLibioReadDX(vdm_ANSLibio* p, Vint* nw, Vdouble dd[], Vint* ierr);
#ifdef __cplusplus
}
#endif
#endif
