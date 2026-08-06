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
/* MeshSize object */
#ifndef MESHSIZE_DEF
#define MESHSIZE_DEF

#include "sam/base/base.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/connect.h"

typedef struct {
    Vint ierr;
    Vint numgeom;
    Vint maxnumgeom;
    Vint* type;
    Vdouble (*xo)[3];
    Vdouble (*xa)[3];
    Vdouble (*xb)[3];
    Vdouble (*d)[3];
    Vdouble* s;
    Vdouble (*tm)[3][3];
    Vdouble extent[2][3];
    vsy_ADTree* adt;
    Vint iter;
} vis_MeshSize;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_MeshSize*
vis_MeshSizeBegin(void);
VKI_EXTERN void
vis_MeshSize_Construct(vis_MeshSize* p);
VKI_EXTERN void
vis_MeshSizeEnd(vis_MeshSize* p);
VKI_EXTERN void
vis_MeshSize_Destruct(vis_MeshSize* p);
VKI_EXTERN Vint
vis_MeshSizeError(vis_MeshSize* p);
VKI_EXTERN void
vis_MeshSizeDef(vis_MeshSize* p, Vint numgeom);
VKI_EXTERN void
vis_MeshSizeSetExtent(vis_MeshSize* p, Vdouble extent[2][3]);
VKI_EXTERN void
vis_MeshSizeNumGeom(vis_MeshSize* p, Vint* numgeom);
VKI_EXTERN void
vis_MeshSizeSetGeom(vis_MeshSize* p, Vint type, Vdouble xo[3], Vdouble xa[3], Vdouble xb[3], Vdouble d[3], Vdouble s);
VKI_EXTERN void
vis_MeshSizeIthGeom(vis_MeshSize* p, Vint ith, Vint* type, Vdouble xo[3], Vdouble xa[3], Vdouble xb[3], Vdouble d[3], Vdouble* s);
VKI_EXTERN void
vis_MeshSizeWrite(vis_MeshSize* p, Vint type, Vint ith, FILE* fd);
VKI_EXTERN void
vis_MeshSizeRead(Vint type, Vint swap, Vint* gtype, Vdouble xo[3], Vdouble xa[3], Vdouble xb[3], Vdouble d[3], Vdouble* h,
                 FILE* fd);
VKI_EXTERN void
vis_MeshSizeProcess(vis_MeshSize* p);
VKI_EXTERN void
vis_MeshSizeSize(vis_MeshSize* p, Vdouble x[3], Vdouble* s);
VKI_EXTERN Vint
vis_MeshSizeUnsuitable(vis_MeshSize* p, Vint shape, Vdouble x[][3]);

#ifdef __cplusplus
}
#endif

#endif
