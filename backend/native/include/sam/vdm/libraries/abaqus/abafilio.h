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
 
#ifndef ABAFILIODEF
#define ABAFILIODEF
#include <stdio.h>
#include "sam/base/base.h"
#define ABAFIL_KEYWORD 1
#define ABAFIL_DATALINE 2
#define ABAFIL_UNKNOWN 3
#define ABAFIL_EOF 4
#define ABAFIL_CONTINUE 5
#define ABAFIL_BLANKLINE 6
#define ABAFIL_MODE_NONE 0
#define ABAFIL_MODE_DEFAULT 1
#define ABAFIL_MODE_COMMA 2
#define ABAFIL_MODE_LITERAL 3
#define ABAFIL_MODE_PYTHON 4
#define ABAFIL_LINENUMBER 1
typedef struct { Vint type;Vdouble dvalue;Vint ivalue;
Vchar cvalue[256];}ABAFilSymbol;typedef struct vdm_ABAFilio
{ Vint ierr;Vint includeerror;FILE* inp;FILE* inc;FILE*
fd;Vchar* buffer;Vchar obuffer[256];Vint nitems;Vint*
qdata;Vint* idata;Vint* tdata;Vdouble* ddata;Vchar**
cdata;Vchar** pdata;Vchar key[256];fpos_t pos;fpos_t
poskey;Vint waskey;Vint* stack_line;FILE** stack_fd;
Vchar** stack_name;Vint stackmax;Vint stackcur;Vint
line;Vchar name[SYS_MAXPATHCHAR];Vchar fullname[SYS_MAXPATHCHAR];
Vint dline;Vchar dname[SYS_MAXPATHCHAR];Vint mode;Vint
comma;Vint nsymbols;Vint maxsymbols;ABAFilSymbol* symbol;
vsy_Dictionary* sdic;}vdm_ABAFilio;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_ABAFilio* vdm_ABAFilioBegin(void);VKI_EXTERN
void vdm_ABAFilioEnd(vdm_ABAFilio* p);VKI_EXTERN Vint
vdm_ABAFilioError(vdm_ABAFilio* p);VKI_EXTERN void vdm_ABAFilioSetMode(vdm_ABAFilio*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_ABAFilioOpen(vdm_ABAFilio*
p,Vchar* filename,Vint* status);VKI_EXTERN void vdm_ABAFilioClose(vdm_ABAFilio*
p);VKI_EXTERN void vdm_ABAFilioRewind(vdm_ABAFilio*
p);VKI_EXTERN void vdm_ABAFilioReadKeyword(vdm_ABAFilio*
p,Vint* linetype);VKI_EXTERN void vdm_ABAFilioGetKeyword(vdm_ABAFilio*
p,Vchar* key);VKI_EXTERN void vdm_ABAFilioNumParam(vdm_ABAFilio*
p,Vint* num);VKI_EXTERN void vdm_ABAFilioGetParam(vdm_ABAFilio*
p,Vint n,Vchar* param,Vint* valuetype);VKI_EXTERN void
vdm_ABAFilioParami(vdm_ABAFilio* p,Vint n,Vint* value);
VKI_EXTERN void vdm_ABAFilioParamd(vdm_ABAFilio* p,
Vint n,Vdouble* value);VKI_EXTERN void vdm_ABAFilioParamc(vdm_ABAFilio*
p,Vint n,Vchar* value);VKI_EXTERN void vdm_ABAFilioReadDataLine(vdm_ABAFilio*
p,Vint mode,Vint* linetype);VKI_EXTERN void vdm_ABAFilioDataLine(vdm_ABAFilio*
p,Vint* nitems);VKI_EXTERN void vdm_ABAFilioDataType(vdm_ABAFilio*
p,Vint n,Vint* valuetype);VKI_EXTERN void vdm_ABAFilioDatai(vdm_ABAFilio*
p,Vint n,Vint* value);VKI_EXTERN void vdm_ABAFilioDatad(vdm_ABAFilio*
p,Vint n,Vdouble* value);VKI_EXTERN void vdm_ABAFilioNDatad(vdm_ABAFilio*
p,Vint n,Vint lengthOfDataToRead,Vdouble* value);VKI_EXTERN
void vdm_ABAFilio3Datad(vdm_ABAFilio* p,Vint n,Vdouble
value[3]);VKI_EXTERN void vdm_ABAFilioDatac(vdm_ABAFilio*
p,Vint n,Vchar* value);VKI_EXTERN void vdm_ABAFilioInput(vdm_ABAFilio*
p,Vchar* filename,Vint* status);VKI_EXTERN void vdm_ABAFilioInclude(vdm_ABAFilio*
p,Vchar* filename,Vint* status);VKI_EXTERN void vdm_ABAFilioGetBuffer(vdm_ABAFilio*
p,Vchar* buffer);VKI_EXTERN void vdm_ABAFilioBackup(vdm_ABAFilio*
p);VKI_EXTERN void vdm_ABAFilioGetInteger(vdm_ABAFilio*
p,Vint type,Vint* value);VKI_EXTERN void vdm_ABAFilioGetFilename(vdm_ABAFilio*
p,Vchar* filename);VKI_EXTERN void vdm_ABAFilioSetSymbol(vdm_ABAFilio*
p,Vchar* name,Vint type,Vint ivalue,Vdouble dvalue,
Vchar cvalue[]);VKI_EXTERN void vdm_ABAFilioFixIncludeFilePath(vdm_ABAFilio*
p,Vchar* filePath);
#ifdef __cplusplus
}
#endif
#endif

