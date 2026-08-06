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
/* Space object */
#ifndef SPACE_DEF
#define SPACE_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/gridfun.h"
#include "sam/vis/idtran.h"
#include "sam/vis/group.h"
#include "sam/vis/pntloc.h"

/*------------------------------------------------------------*
 *                                                            *
 *              ****  block decompostion  ****                *
 *                                                            *
 * stores information used in performing Space decomposition  *
 * and searching using a simple blocking of space.            *
 *------------------------------------------------------------*/

/*----------------------------------------*
 *                                        *
 *     ****  Space param defs  ****       *
 *                                        *
 *----------------------------------------*/

#define SPACE_LINE_INFINITE  2
#define SPACE_PLANE_INFINITE 6

#define SPACE_DEPTH            11
#define SPACE_RESOLUTION       12
#define SPACE_RESOLUTION_ADAPT 13

#define SPACE_DECOMP_BLOCK       31
#define SPACE_DECOMP_ADAPT_BLOCK 32

#define SPACE_TOLERANCE 50
#define SPACE_REFINE    51

#define SPACE_NODE_SEARCH  60
#define SPACE_NODE_LOWEST  61
#define SPACE_NODE_CLOSEST 62
#define SPACE_NODE_ANY     63

#define SPACE_TREE        70
#define SPACE_TREE_OCTREE 71
#define SPACE_TREE_ADTREE 72

/*----------------------------------------*
 *                                        *
 *     ****  SpaceParams  ****            *
 *                                        *
 *----------------------------------------*/

typedef struct SpaceParams {
    Vint line;
    Vint plane;
    Vint decomp;
    Vint ires, jres, kres;
    Vint adapt_ires, adapt_jres, adapt_kres;
    Vint max_level;
    Vint max_count;
    Vfloat node_tol;
    Vfloat dist_tol;
    Vint node_search;
    Vint refine;
    Vint tree;
} SpaceParams;

/*----------------------------------------*
 *                                        *
 *       ****  SpaceBlock  ****           *
 *                                        *
 * stores a list of elements for a given  *
 * block.                                 *
 *                                        *
 * num_elem: number of elements per block.*
 *                                        *
 * list: list of elements in the block.   *
 *----------------------------------------*/

typedef struct SpaceElemBlock {
    Vint num_elem;
    Vint num_node;
    Vint* elem_list;
    Vint* node_list;
    struct SpaceElemBlock** block_list;
} SpaceElemBlock;

/*----------------------------------------*
 *                                        *
 *    ****  SpaceBlock  ****              *
 *                                        *
 * stores a set of blocks for a Space     *
 * decomposition.                         *
 *----------------------------------------*/

typedef struct SpaceBlock {
    Vfloat xmin, xmax, ymin, ymax, zmin, zmax;
    SpaceElemBlock** block_list;
} SpaceBlock;

/*----------------------------------------*
 *                                        *
 *         ****  vis_Space  ****          *
 *                                        *
 * stores data for Space decomposition    *
 * for a mesh.                            *
 *                                        *
 * ierr: error flag.                      *
 *                                        *
 * decomp: decomposition type.            *
 *                                        *
 * block_decomp: block decomposition      *
 *----------------------------------------*/

struct vis_Space {
    Vint ierr;
    Vint level;
    Vint nodedecomp;
    vis_GridFun* gf;
    Vfloat extent[2][3];
    SpaceBlock* block_decomp;
    SpaceParams params;
    Vint num_adapt_blocks;
    SpaceElemBlock** adapt_block_table;
    vis_PntLoc* pnt_loc;
    vsy_ADTree* adtree;
    Vfloat (*elext)[6];

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vis_Space(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vis_Space(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void
    SetObject(Vint, Vobject*);
    VKI_EXTERN void SetParami(Vint, Vint);
    VKI_EXTERN void
    GetParami(Vint, Vint*);
    VKI_EXTERN void SetParamf(Vint, Vfloat);
    VKI_EXTERN void
    GetParamf(Vint, Vfloat*);
    VKI_EXTERN void
    Kernel();
    VKI_EXTERN void ElemRST(Vfloat[3], vis_Group*, Vint*, Vfloat[3]);
    VKI_EXTERN void ElemRSTdv(Vdouble[3], vis_Group*, Vint*, Vdouble[3]);
    VKI_EXTERN void
    NodeKernel();
    VKI_EXTERN void PointIdTran(Vint, Vfloat[][3], vis_Group*, vis_IdTran*, Vfloat[][3]);
    VKI_EXTERN void LineGroup(Vfloat[2][3], vis_Group*, vis_Group*);
    VKI_EXTERN void PlaneGroup(Vfloat[4][3], vis_Group*, vis_Group*);
    VKI_EXTERN void PlaneGroupdv(Vdouble[4][3], vis_Group*, vis_Group*);
    VKI_EXTERN void BoxNodeGroup(Vfloat[8][3], vis_Group*, vis_Group*);
    VKI_EXTERN void BoxGroup(Vfloat[8][3], vis_Group*, vis_Group*);
    VKI_EXTERN void
    GetNumBlocks(Vint*);
    VKI_EXTERN void
    GetElemList(Vint, Vint*, Vint**);
    VKI_EXTERN void SetMaxCount(Vint);
    VKI_EXTERN void
    GetMaxCount(Vint*);
    VKI_EXTERN void
    GetStats(Vint*, Vint*, Vint*);
    VKI_EXTERN void
    GetExtents(Vint*, Vfloat (**)[3]);
    VKI_EXTERN void
    DupNodeIdTran(vis_Group*, vis_IdTran*);
    VKI_EXTERN void PointNodeIdTran(Vint, Vfloat[][3], vis_Group*, vis_IdTran*);
    VKI_EXTERN void
    Print();
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_Space*
vis_SpaceBegin(void);
VKI_EXTERN void
vis_Space_Construct(vis_Space* p);
VKI_EXTERN void
vis_SpaceEnd(vis_Space* p);
VKI_EXTERN void
vis_Space_Destruct(vis_Space* p);
VKI_EXTERN Vint
vis_SpaceError(vis_Space* p);
VKI_EXTERN void
vis_SpaceSetObject(vis_Space* p, Vint objecttype, Vobject* object);
VKI_EXTERN void
vis_SpaceSetParami(vis_Space* p, Vint type, Vint value);
VKI_EXTERN void
vis_SpaceGetParami(vis_Space* p, Vint type, Vint* value);
VKI_EXTERN void
vis_SpaceSetParamf(vis_Space* p, Vint ptype, Vfloat fparam);
VKI_EXTERN void
vis_SpaceGetParamf(vis_Space* p, Vint type, Vfloat* value);
VKI_EXTERN void
vis_SpaceKernel(vis_Space* p);
VKI_EXTERN void
vis_SpaceElemRST(vis_Space* p, Vfloat x[3], vis_Group* group, Vint* id, Vfloat r[3]);
VKI_EXTERN void
vis_SpaceElemRSTdv(vis_Space* p, Vdouble x[3], vis_Group* group, Vint* id, Vdouble r[3]);
VKI_EXTERN void
vis_SpaceNodeKernel(vis_Space* p);
VKI_EXTERN void
vis_SpacePointIdTran(vis_Space* p, Vint num_pts, Vfloat pts[][3], vis_Group* group, vis_IdTran* idtran, Vfloat r[][3]);
VKI_EXTERN void
vis_SpaceLineGroup(vis_Space* p, Vfloat line_pts[2][3], vis_Group* group, vis_Group* groupdst);
VKI_EXTERN void
vis_SpacePlaneGroup(vis_Space* p, Vfloat plane_pts[4][3], vis_Group* group, vis_Group* groupdst);
VKI_EXTERN void
vis_SpacePlaneGroupdv(vis_Space* p, Vdouble pts[4][3], vis_Group* subset, vis_Group* group);
VKI_EXTERN void
vis_SpaceBoxNodeGroup(vis_Space* p, Vfloat box_pts[8][3], vis_Group* group, vis_Group* groupdst);
VKI_EXTERN void
vis_SpaceBoxGroup(vis_Space* p, Vfloat box_pts[8][3], vis_Group* group, vis_Group* groupdst);
VKI_EXTERN void
vis_SpaceGetNumBlocks(vis_Space* p, Vint* num_blocks);
VKI_EXTERN void
vis_SpaceGetElemList(vis_Space* p, Vint block, Vint* num_elem, Vint** list);
VKI_EXTERN void
vis_SpaceSetMaxCount(vis_Space* p, Vint value);
VKI_EXTERN void
vis_SpaceGetMaxCount(vis_Space* p, Vint* value);
VKI_EXTERN void
vis_SpaceGetStats(vis_Space* p, Vint* max_elem, Vint* min_elem, Vint* avg_elem);
VKI_EXTERN void
vis_SpaceGetExtents(vis_Space* p, Vint* num_pts, Vfloat (**pts)[3]);
VKI_EXTERN void
vis_SpaceDupNodeIdTran(vis_Space* p, vis_Group* group, vis_IdTran* idtran);
VKI_EXTERN void
vis_SpacePointNodeIdTran(vis_Space* p, Vint num_pts, Vfloat pts[][3], vis_Group* group, vis_IdTran* idtran);
VKI_EXTERN void
vis_SpacePrint(vis_Space* p);

#ifdef __cplusplus
}
#endif

#endif
