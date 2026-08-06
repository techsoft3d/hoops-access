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
 
#ifndef ERROR_DEF
#define ERROR_DEF
#include "sam/base/basedefs.h"
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN void vut_ErrorSetHandler(void (*handler)(const
Vchar*,Vint,const Vchar*));VKI_EXTERN void vut_ErrorGetHandler(void
(**handler)(const Vchar*,Vint,const Vchar*));VKI_EXTERN
void vut_ErrorSetObject(Vobject* object);VKI_EXTERN
void vut_ErrorGetObject(Vobject** object);VKI_EXTERN
void vut_ErrorHandler(const Vchar* funcname,Vint ierr,
const Vchar* message);VKI_EXTERN void vut_ErrorCall(const
Vchar* funcname,Vint ierr,const Vchar* message);VKI_EXTERN
Vchar* vut_ErrorString(Vint ierr);VKI_EXTERN void vut_Error(const
Vchar* name,const Vchar* message);VKI_EXTERN void vut_ErrorAssert(const
Vchar* name,Vchar* message,const Vchar* file,Vint line);
#ifdef __cplusplus
}
#endif
#endif

