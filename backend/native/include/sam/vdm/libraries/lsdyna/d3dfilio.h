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
 
#ifndef D3DFILIODEF
#define D3DFILIODEF
#include <stdio.h>
#include "sam/base/base.h"
#define D3DFIL_KEYWORD 1
#define D3DFIL_DATALINE 2
#define D3DFIL_UNKNOWN 3
#define D3DFIL_EOF 4
#define D3DFIL_LINENUMBER 1
#define D3DFIL_MODE_DATA 1
#define D3DFIL_MODE_LITERAL 2
#define D3DFIL_PARAMETER_DOUBLE 'R'
#define D3DFIL_PARAMETER_INT 'I'
#define D3DFIL_PARAMETER_CHAR 'C'
typedef struct vdm_D3DFilioParameter { Vint type;Vint
ivalue;Vdouble dvalue;Vchar cvalue[11];}vdm_D3DFilioParameter;
typedef struct vdm_D3DFilio { Vint ierr;Vchar buffer[256];
Vint nitems;Vint* idata;Vint* tdata;Vdouble* ddata;
Vchar** cdata;Vchar key[81];Vint mode;Vint nformats;
Vint formatsize[50];Vint formattype[50];Vint id;Vchar
fullname[SYS_MAXPATHCHAR];vsy_Stack* stack;vsy_Dictionary*
parameterdictionary;Vint longFormatMode;Vint I10FormatInputFlag;
}vdm_D3DFilio;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_D3DFilio* vdm_D3DFilioBegin(void);VKI_EXTERN
void vdm_D3DFilioEnd(vdm_D3DFilio* p);VKI_EXTERN Vint
vdm_D3DFilioError(vdm_D3DFilio* p);VKI_EXTERN void vdm_D3DFilioOpen(vdm_D3DFilio*
p,Vchar* filename,Vint* status);VKI_EXTERN void vdm_D3DFilioClose(vdm_D3DFilio*
p);VKI_EXTERN void vdm_D3DFilioRewind(vdm_D3DFilio*
p);VKI_EXTERN void vdm_D3DFilioReadKeyword(vdm_D3DFilio*
p,Vint* linetype);VKI_EXTERN Vint vdm_D3DFilioReadNextWord(vdm_D3DFilio*
p,Vint start,Vchar* word);VKI_EXTERN void vdm_D3DFilioGetKeyword(vdm_D3DFilio*
p,Vchar* key);VKI_EXTERN void vdm_D3DFilioReadDataLine(vdm_D3DFilio*
p,Vint mode,Vint* linetype);VKI_EXTERN void vdm_D3DFilioSetFormat(vdm_D3DFilio*
p,Vint nformats,Vint formatsize[],Vint formattype[]);
VKI_EXTERN void vdm_D3DFilioDataLine(vdm_D3DFilio* p,
Vint* nitems);VKI_EXTERN void vdm_D3DFilioDataType(vdm_D3DFilio*
p,Vint n,Vint* valuetype);VKI_EXTERN void vdm_D3DFilioDatai(vdm_D3DFilio*
p,Vint n,Vint* value);VKI_EXTERN void vdm_D3DFilioDatad(vdm_D3DFilio*
p,Vint n,Vdouble* value);VKI_EXTERN void vdm_D3DFilio3Datad(vdm_D3DFilio*
p,Vint n,Vdouble value[3]);VKI_EXTERN void vdm_D3DFilioDatac(vdm_D3DFilio*
p,Vint n,Vchar* value);VKI_EXTERN void vdm_D3DFilioGetBuffer(vdm_D3DFilio*
p,Vint slen,Vchar* buffer);VKI_EXTERN void vdm_D3DFilioGetInteger(vdm_D3DFilio*
p,Vint type,Vint* value);VKI_EXTERN void vdm_D3DFilioGetFilename(vdm_D3DFilio*
p,Vchar* filename);VKI_EXTERN void vdm_D3DFilioInclude(vdm_D3DFilio*
p,Vchar* filename,Vint* status);VKI_EXTERN void vdm_D3DFilioAddParameter(vdm_D3DFilio*
p,Vchar* parametername,Vint type,Vchar* value);VKI_EXTERN
void vdm_D3DFilioSetLongFormatMode(vdm_D3DFilio* p,
Vint mode);VKI_EXTERN void vdm_D3DFilioSetI10FormatInputFlag(vdm_D3DFilio*
p,Vint flag);
#ifdef __cplusplus
}
#endif
#endif

