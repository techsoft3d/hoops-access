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
#ifndef RESULTINFORMATION_DEF
#define RESULTINFORMATION_DEF

#include <stdio.h>
#include "sam/vis/visdefs.h"
#include "sam/base/basedefs.h"
/*----------------------------------------------------------------------
Structure containing all the requirements for defining a result
It is used for generating datasets in vdm
----------------------------------------------------------------------*/
struct vis_ResultInformation {
    Vint resultType;                      /* Result type description : SYS_RES_X, SYS_RES_ENTROPY, etc*/
    Vint dataType;                        /* SYS_SCALAR, SYS_VECTOR, etc */
    Vint entityType;                      /* SYS_ELEM, SYS_NODE, etc */
    Vint subentityType;                   /* SYS_NODE, SYS_FACE, SYS_NONE */
    Vint doublePrecisionFlag;             /* SYS_ON, SYS_OFF */
    Vint complexDataflag;                 /* SYS_OFF or SYS_ON*/
    Vint categoryType;                    /* SYS_CATEGORY_BUCK, SYS_CATEGORY_STAT, etc  */
    Vint sectionType;                     /* SYS_ELEMSEC_NONE,BOT,TOP,MID,ALL  */
    Vint sectionIndex;                    /* (optional) tells which section index this result relates to*/
    Vint componentCount;                  /* 1 scalar, 3 vector, 6 symTensor, etc*/
    Vint entityCount;                     /* SYS_ELEME, SYS_NODE etc*/
    Vlong totalBuffersize;                /* the size of the result buffer also know as lrec */
    Vint id1;                             /* first result identifier*/
    Vint id2;                             /* second result identifier*/
    Vint id3;                             /* third result identifier*/
    Vchar origin[SYS_MAXNAMECHAR];        /* identify the original block where this info was found (optional)*/
    Vdouble time;                         /* Time attribute WRITTEN ONLY if different from SYS_DOUBLE_UNDEFINED */
    Vdouble frequency;                    /* Frequency attribute WRITTEN ONLY if different from SYS_DOUBLE_UNDEFINED */
    Vdouble loadFactor;                   /* LoadFactor attribute WRITTEN ONLY if different from SYS_DOUBLE_UNDEFINED */
    Vint integerQualifiersCount;          /* Number of integer qualifiers */
    Vint integerQualifiers[SYS_NQUA_MAX]; /* Array of integer qualifiers */
    Vint system;     /* System of the result, STATE_GLOBAL, STATE_LOCAL, STATE_ROTANG, STATE_MATERIAL or -1 (undefined) */
    Vint strainType; /* Qualifier for strain type: VDMUTIL_STRAINTYPE_TENSOR, VDMUTIL_STRAINTYPE_ENGINEERING */
};

#ifdef __cplusplus
extern "C" {
#endif
/*Default contructor to use as initialization*/
VKI_EXTERN vis_ResultInformation
vis_ResultInformationDefault(void);

#ifdef __cplusplus
}
#endif

#endif
