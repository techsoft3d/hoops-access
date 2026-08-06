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
/* vdm local functions header file */
#ifndef VDMOPER_DEF
#define VDMOPER_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void
vdm_makeDirectory(Vchar* path, Vint* ierr);
extern void
vdm_posDirectory(Vchar* path, Vint* pos);
extern void
vdm_catDirectory(Vchar* root, Vchar* name, Vchar* path);
extern void
vdm_relDirectory(Vchar* path, Vint* rel);
extern void
vdm_checkDirectory(Vchar* path, Vint* ierr);
extern void
vdm_makelistDirectory(Vchar* path, Vint dirflag, Vint* numlist, Vchar*** clist);
extern void
vdm_freelistDirectory(Vint numlist, Vchar** clist);
extern void
vdm_setFpe(Vfpe fpe);
extern void
vdm_getFpe(Vfpe* fpe);

#ifdef __cplusplus
}
#endif

#endif
