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
 
#ifndef NAME_DEF
#define NAME_DEF
#include "sam/base/basedefs.h"
#define NAME_COLOR 0
#define NAME_POSITION 1
#define NAME_ONOFF 2
#define NAME_AXIS 3
#define NAME_LINESTYLE 4
#define NAME_OBJECT 5
#define NAME_MARKER 6
#define NAME_FORMAT 7
#define NAME_SCALE 8
#define NAME_DIRECTION 9
#define NAME_CURSOR 10
#define NAME_ELEM 11
#define NAME_TRANSPARENCY 12
#define NAME_ELEMSHAPE 13
#define NAME_LINEWIDTH 14
#define NAME_POINTSIZE 15
#define NAME_ON 16
#define NAME_OFF 17
#define NAME_ELEMTYPE 18
#define NAME_DOF 19
#define NAME_VERSION 20
#define NAME_YESNO 21
#define NAME_ELEM_SOLID 22
#define NAME_ELEM_INTER 23
#define NAME_ASSOC 24
#define NAME_OBJECT4 25
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN Vchar* vut_Name(Vint,Vint);VKI_EXTERN void
vut_NameColorValue(Vint idx,Vfloat dst[],Vint* ierr);
VKI_EXTERN void vut_NameNum(Vint type,Vint* n);VKI_EXTERN
void vut_NameCode(Vint type,Vchar* name,Vint* code);
VKI_EXTERN const Vchar* vut_FEASpecName(Vint feaType,
Vint feaSpec);
#ifdef __cplusplus
}
#endif
#endif

