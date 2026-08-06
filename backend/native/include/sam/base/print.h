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
 
#ifndef PRINT_DEF
#define PRINT_DEF
#include "sam/base/basedefs.h"
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN void vut_PrintSetFile(FILE* fd);VKI_EXTERN
void vut_PrintSetPath(Vchar* path);VKI_EXTERN FILE*
vut_PrintFile(void);
#ifdef __cplusplus
}
#endif
#endif

