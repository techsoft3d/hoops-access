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
 
#ifndef STRUTIL_DEF
#define STRUTIL_DEF
#include "sam/base/basedefs.h"
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN void vut_StrUtilFromUTF8(const char* utf8buf,
Vint maxWideChars,wchar_t* wideBuf);VKI_EXTERN void
vut_StrUtilToUTF8(const wchar_t* wideStr,Vint maxUtf8Chars,
char* utf8Buf);VKI_EXTERN Vint vut_StrUtilLenUTF8(const
char* utf8Str);VKI_EXTERN void vut_StrUtilMBCSfromUTF8(const
char* utf8,Vint maxMBCSChars,Vuchar mbcs[]);
#ifdef __cplusplus
}
#endif
#endif

