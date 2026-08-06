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
#include "sam/base/basedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

VKI_EXTERN void
vml_METIS_SetOptions(Vint options[], Vint numflag, Vlong options5[]);
VKI_EXTERN void
vml_METIS_ENodeNDExt(Vint* neqns, Vlong xadj[], Vint adjncy[], Vint* numflag, Vint options[], Vint perm[], Vint invp[],
                     Vint* vkierror);

#ifdef __cplusplus
}
#endif
