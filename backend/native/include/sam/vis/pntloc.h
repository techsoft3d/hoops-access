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
/* PntLoc object */

#ifndef PNTLOC_DEF
#define PNTLOC_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/idtran.h"
#include "sam/vis/group.h"

#define PNTLOC_CLOSEST 1
#define PNTLOC_LOWEST  2
#define PNTLOC_ANY     3

typedef struct vis_PntLoc {
    Vint ierr;
    Vint num_pts;
    Vfloat tol;
    Vint* index_array;
    Vfloat* pd_array;
    Vfloat proj_vec[3];

    Vobject* get_coord_obj;
    void (*get_coord_func)(Vobject*, Vint n, Vint[], Vfloat[][3]);
    void (*get_coord_funcdv)(Vobject*, Vint n, Vint[], Vdouble[][3]);
} vis_PntLoc;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_PntLoc*
vis_PntLocBegin(void);
VKI_EXTERN void
vis_PntLocEnd(vis_PntLoc* p);
VKI_EXTERN Vint
vis_PntLocError(vis_PntLoc* p);
VKI_EXTERN void
vis_PntLocSetTol(vis_PntLoc* p, Vfloat tol);
VKI_EXTERN void
vis_PntLocSetCoordFunc(vis_PntLoc* p, Vint num_pts, Vfunc* function, Vobject* object);
VKI_EXTERN void
vis_PntLocSetCoordFuncdv(vis_PntLoc* p, Vint num_pts, Vfunc* function, Vobject* object);
VKI_EXTERN void
vis_PntLocSearchId(vis_PntLoc* p, Vint type, Vint num_spts, Vfloat spts[][3], vis_Group* group, vis_IdTran* idtran);
VKI_EXTERN void
vis_PntLocFindDupe(vis_PntLoc* p, Vint type, vis_Group* group, vis_IdTran* idtran);

#ifdef __cplusplus
}
#endif

#endif
