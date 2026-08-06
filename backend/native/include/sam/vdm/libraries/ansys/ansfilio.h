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
 
#ifndef ANSFILIODEF
#define ANSFILIODEF
#include <stdio.h>
#include "sam/base/base.h"
#define ANSFIL_COMMAND 1
#define ANSFIL_DATA 2
#define ANSFIL_FORMAT 3
#define ANSFIL_EOF 4
#define ANSFIL_UNKNOWN 5
#define ANSFIL_MAXCHAR 641
#define ANSFIL_MAXITEMS 128
#define ANSFIL_FORMAT_SIZE 50
#define ANSFIL_LINENUMBER 1
typedef struct { Vint id;Vchar type[256];Vint imax,
jmax,kmax;Vint csysid;Vchar var1[256];Vchar var2[256];
Vchar var3[256];Vint ival;Vdouble dval;Vchar cval[256];
Vdouble* arrayStorage;}vdm_ANSFil_SDIM;typedef struct
vdm_ANSFilio { Vint ierr;FILE* fd;Vint buflen;Vchar
rline[ANSFIL_MAXCHAR];Vchar* buffer[ANSFIL_MAXCHAR];
Vint nitems;Vint* idata;Vint* tdata;Vdouble* ddata;
Vchar** pdata;Vint nfitems;Vint* fitemtype;Vint* fitemsize;
Vchar key[81];Vint waskey;Vint line;Vint type;Vchar
name[SYS_MAXPATHCHAR];Vint fnum;Vint ftype[ANSFIL_FORMAT_SIZE];
Vint fsize[ANSFIL_FORMAT_SIZE];Vint nb;Vint ib;Vchar*
inquote;vsy_Dictionary* sdim;}vdm_ANSFilio;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_ANSFilio* vdm_ANSFilioBegin(void);VKI_EXTERN
void vdm_ANSFilioEnd(vdm_ANSFilio* p);VKI_EXTERN Vint
vdm_ANSFilioError(vdm_ANSFilio* p);VKI_EXTERN void vdm_ANSFilioOpen(vdm_ANSFilio*
p,Vchar* filename,Vint* status);VKI_EXTERN void vdm_ANSFilioClose(vdm_ANSFilio*
p);VKI_EXTERN void vdm_ANSFilioRewind(vdm_ANSFilio*
p);VKI_EXTERN void vdm_ANSFilioGetPos(vdm_ANSFilio*
p,Vlong* nc);VKI_EXTERN void vdm_ANSFilioSetDictionary(vdm_ANSFilio*
p,vsy_Dictionary* sdim);VKI_EXTERN void vdm_ANSFilioSetPos(vdm_ANSFilio*
p,Vlong nc);VKI_EXTERN void vdm_ANSFilioSetLineType(vdm_ANSFilio*
p,Vint type);VKI_EXTERN void vdm_ANSFilioReadLine(vdm_ANSFilio*
p,Vint* linetype);VKI_EXTERN void vdm_ANSFilioReadContinuationLine(vdm_ANSFilio*
p,Vint* linetype);VKI_EXTERN void vdm_ANSFilioSetFormat(vdm_ANSFilio*
p,Vint num,Vint type[],Vint size[]);VKI_EXTERN void
vdm_ANSFilioGetFormat(vdm_ANSFilio* p,Vint* num,Vint
type[],Vint size[]);VKI_EXTERN void vdm_ANSFilioNumItems(vdm_ANSFilio*
p,Vint* num);VKI_EXTERN void vdm_ANSFilioItemType(vdm_ANSFilio*
p,Vint n,Vint* valuetype);VKI_EXTERN void vdm_ANSFilioItemi(vdm_ANSFilio*
p,Vint n,Vint* value);VKI_EXTERN void vdm_ANSFilioItemd(vdm_ANSFilio*
p,Vint n,Vdouble* value);VKI_EXTERN void vdm_ANSFilio3Itemd(vdm_ANSFilio*
p,Vint n,Vdouble value[3]);VKI_EXTERN void vdm_ANSFilioItemc(vdm_ANSFilio*
p,Vint n,Vchar* value);VKI_EXTERN void vdm_ANSFilioItemr(vdm_ANSFilio*
p,Vint n,Vchar* value);VKI_EXTERN void vdm_ANSFilioItemv(vdm_ANSFilio*
p,Vint n,Vint* flag,Vchar* var);VKI_EXTERN void vdm_ANSFilioGetBuffer(vdm_ANSFilio*
p,Vchar* buffer);VKI_EXTERN void vdm_ANSFilioGetInteger(vdm_ANSFilio*
p,Vint type,Vint* value);VKI_EXTERN void vdm_ANSFilioGetFilename(vdm_ANSFilio*
p,Vchar* filename);VKI_EXTERN void vdm_ANSFilioSetLineNumber(vdm_ANSFilio*
p,Vint linenumber);
#ifdef __cplusplus
}
#endif
#endif

