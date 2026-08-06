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
 
#ifndef NASFILIO_DEF
#define NASFILIO_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vis/gridfun.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#define NASFIL_MAX_RECORDSIZE 256
#define NASFIL_FIELDS_PER_CARD 10
#define NASFIL_FIELDSIZE 8
#define NASFIL_CONT_FIELD_START_COLUMN 73
#define NASFIL_INT 0
#define NASFIL_FLOAT 1
#define NASFIL_NORMAL 0
#define NASFIL_COPY_PREVIOUS 1
#define NASFIL_INCREMENT_INT_PREVIOUS 2
#define NASFIL_INCREMENT_FLOAT_PREVIOUS 3
#define NASFIL_COPY_REST_PREVIOUS 4
#define NASFIL_REPEAT_PREVIOUS 5
#define NASFIL_COMMON_STRING_SIZE 17
#define NASFIL_ILINENUM 1
#define NASFIL_ISAVEDLINENUM 2
#define NASFIL_CURRENTFIELD 3
typedef struct vdm_NASFilio { FILE* fd;vsy_Stack* fdStack;
Vint ierr;Vint offset;Vchar record[NASFIL_MAX_RECORDSIZE
+ 1];Vint recordLength;Vint maxfpr;Vchar cardFields[NASFIL_FIELDS_PER_CARD][3
* NASFIL_FIELDSIZE + 1];Vchar (*tranCardFields)[3 *
NASFIL_FIELDSIZE + 1];Vint numCardFields;Vint numtranFields;
Vchar savedField[256];Vint savedlinenum;Vchar savedrecord[256];
Vchar controlField[3 * NASFIL_FIELDSIZE + 1];Vchar continuationField[3
* NASFIL_FIELDSIZE + 1];Vchar (*field)[NASFIL_MAX_RECORDSIZE];
Vint currentField;Vint isRepeat;Vint repeatCount;Vint
isFreeField;Vint isInclude;Vint recordFieldLength;Vint
recordFieldNumber;Vint FieldsPerCard;Vint eof;Vint stackid;
vsy_DblDict* labeledDoubleReferences;vsy_IntDict* labeledIntegerReferences;
}vdm_NASFilio;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_NASFilio* vdm_NASFilioBegin(void);VKI_EXTERN
void vdm_NASFilioEnd(vdm_NASFilio* p);VKI_EXTERN Vint
vdm_NASFilioError(vdm_NASFilio* p);VKI_EXTERN void vdm_NASFilioOpen(vdm_NASFilio*
p,Vchar filename[],Vint* status);VKI_EXTERN void vdm_NASFilioClose(vdm_NASFilio*
p);VKI_EXTERN void vdm_NASFilioRewind(vdm_NASFilio*
p);VKI_EXTERN void vdm_NASFilioStackId(vdm_NASFilio*
p,Vint* stackid);VKI_EXTERN void vdm_NASFilioResetFields(vdm_NASFilio*
p);VKI_EXTERN Vchar* vdm_NASFilioGetControl(vdm_NASFilio*
p);VKI_EXTERN Vint vdm_NASFilioItemi(vdm_NASFilio* p,
Vint fieldNo);VKI_EXTERN void vdm_NASFilioItem2i(vdm_NASFilio*
p,Vint ifn,Vint* id1,Vint* id2);VKI_EXTERN void vdm_NASFilioItemni(vdm_NASFilio*
p,Vint fieldNo,Vint n,Vint id[]);VKI_EXTERN Vchar* vdm_NASFilioItemc(vdm_NASFilio*
p,Vint fieldNo);VKI_EXTERN Vint vdm_NASFilioIsBlank(vdm_NASFilio*
p,Vint fieldNo);VKI_EXTERN Vint vdm_NASFilioIsChar(vdm_NASFilio*
p,Vint fieldNo);VKI_EXTERN Vint vdm_NASFilioIsInteger(vdm_NASFilio*
p,Vint fieldNo);VKI_EXTERN void vdm_NASFilioSetDictionaryOfLabels(vdm_NASFilio*
p,vsy_DblDict* labeledDoubleReferences,vsy_IntDict*
labeledIntegerReferences);VKI_EXTERN Vfloat vdm_NASFilioItemf(vdm_NASFilio*
p,Vint fieldNo);VKI_EXTERN Vdouble vdm_NASFilioItemd(vdm_NASFilio*
p,Vint fieldNo);VKI_EXTERN void vdm_NASFilio3Itemd(vdm_NASFilio*
p,Vint fieldNo,Vdouble d[3]);VKI_EXTERN void vdm_NASFilioMultipleItemd(vdm_NASFilio*
p,Vint fieldNo,Vint itemdCount,Vdouble* d);VKI_EXTERN
void vdm_NASFilio3Itemf(vdm_NASFilio* p,Vint fieldNo,
Vfloat d[3]);VKI_EXTERN Vint vdm_NASFilioNumItems(vdm_NASFilio*
p);VKI_EXTERN Vint vdm_NASFilioEOFReached(vdm_NASFilio*
p);VKI_EXTERN void vdm_NASFilioReadRawRecord(vdm_NASFilio*
p);VKI_EXTERN void vdm_NASFilioReadRecord(vdm_NASFilio*
p);VKI_EXTERN Vint vdm_NASFilioIsComment(vdm_NASFilio*
p);VKI_EXTERN void vdm_NASFilioReadRecordGroup(vdm_NASFilio*
p);VKI_EXTERN void vdm_NASFilioCcInteger(vdm_NASFilio*
p,Vint* ival);VKI_EXTERN void vdm_NASFilioCcString(vdm_NASFilio*
p,Vchar* cval);VKI_EXTERN void vdm_NASFilioPpString(vdm_NASFilio*
p,Vchar* cval);VKI_EXTERN void vdm_NASFilioGetKeyword(vdm_NASFilio*
p,Vchar key[]);VKI_EXTERN void vdm_NASFilioGetControlField(vdm_NASFilio*
p,Vchar field[]);VKI_EXTERN void vdm_NASFilioGetSavedRecord(vdm_NASFilio*
p,Vchar record[]);VKI_EXTERN void vdm_NASFilioGetSavedField(vdm_NASFilio*
p,Vchar field[]);VKI_EXTERN void vdm_NASFilioGetInteger(vdm_NASFilio*
p,Vint type,Vint* value);VKI_EXTERN void vdm_NASFilioSkip(vdm_NASFilio*
p);VKI_EXTERN void vdm_NASFilioGetFileName(vdm_NASFilio*
p,Vchar** filename);
#ifdef __cplusplus
}
#endif
#endif

