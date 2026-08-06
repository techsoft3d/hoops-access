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
/* datafile header file */
#ifndef DATAFILE_DEF
#define DATAFILE_DEF

#include "sam/base/basedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void
datafiletype(const Vchar inputfile[], Vint* filetype);
extern void
datafileinit(Vint filetype, vdm_DataFun* datafun);
extern void
datafileterm(Vint filetype, vdm_DataFun* datafun);

#ifdef __cplusplus
}
#endif

#endif
