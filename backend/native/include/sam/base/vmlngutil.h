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
/* vml ng utility functions header file */
#ifndef VMLNGUTIL_DEF
#define VMLNGUTIL_DEF

#include "sam/base/basedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void
vml_lowerToFull(const int n, const Vlong* pointers, const Vlong* qointersb, const int* ladj, Vlong* xadj, int* adj, Vlong* maxrow,
                Vlong* iw, int fflag, Vint sw);
extern void
vml_lowerToFullMap(int n, Vlong* xladj, Vlong* qointers, int* ladj, Vlong* xadj, int* adj, Vlong* maxrow, Vlong* iw, int fflag,
                   int sw, int* map, Vint neqred);

#ifdef __cplusplus
}
#endif

#endif
