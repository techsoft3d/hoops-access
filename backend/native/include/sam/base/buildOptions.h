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
#pragma once
#include "sam/base/base.h"

#define SYS_BUILD_OPTION_BLASMKL_SEQUENTIAL 1
#define SYS_BUILD_OPTION_BLASMKL_THREAD     2
#define SYS_BUILD_OPTION_BLASMKL            3
#define SYS_BUILD_OPTION_ADDRESS_SANITIZER  4
#define SYS_BUILD_OPTION_THREAD_SANITIZER   5
#define SYS_BUILD_OPTION_FREETYPE           6
#define SYS_BUILD_OPTION_METIS              7
#define SYS_BUILD_OPTION_BLOSC              8
#define SYS_BUILD_OPTION_FFMPEG             9
#define SYS_BUILD_OPTION_64BITS             10
#define SYS_BUILD_OPTION_MUMPS              11
#define SYS_BUILD_OPTION_HOOPS_EXCHANGE     12
#define SYS_BUILD_OPTION_MAX                13

#ifdef __cplusplus
extern "C" {
#endif

VKI_EXTERN void
vsy_GetEnabledBuildOptions(vsy_BitVec* enabledBuildOptions);

#ifdef __cplusplus
}
#endif
