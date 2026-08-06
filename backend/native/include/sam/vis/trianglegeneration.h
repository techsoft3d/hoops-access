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
/* TriangleGeneration object */

#ifndef VIS_TRIANGLEGENERATION_DEF
#define VIS_TRIANGLEGENERATION_DEF

#include "sam/base/basedefs.h"
#include "sam/base/adtree.h"
#include "sam/base/random.h"
#include "sam/base/pred.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/meshcon.h"
#include "sam/vis/connect.h"
#include "sam/vis/group.h"

/* get integer */
#define TRIMESH_NUMNONMAN        1
#define TRIMESH_NONMAN           2
#define TRIMESH_NUMINCONS        3
#define TRIMESH_INCONS           4
#define TRIMESH_NUMNEGJAC        5
#define TRIMESH_NUMFREEEND       6
#define TRIMESH_FREEEND          7
#define TRIMESH_NUMNONQUAL       8
#define TRIMESH_NUMUNCONN        9
#define TRIMESH_UNCONN           10
#define TRIMESH_NUMEXNODE        11
#define TRIMESH_EXNODE           12
#define TRIMESH_NUMINTERSECT     13
#define TRIMESH_INTERSECT        14
#define TRIMESH_NUMREPEATEDNODE  15
#define TRIMESH_REPEATEDNODE     16
#define TRIMESH_NUMDUPLICATELINE 17
#define TRIMESH_DUPLICATELINE    18

/* set parameters */
#define TRIMESH_UNCONNECT         -2
#define TRIMESH_LINEFLAG          -3
#define TRIMESH_UNCONNECT_ERROR   0
#define TRIMESH_UNCONNECT_INCLUDE 1
#define TRIMESH_UNCONNECT_IGNORE  2
#define TRIMESH_ADVFRONT          -5
#define TRIMESH_SMOOTH            -6
#define TRIMESH_BOUNDCUT          -7
#define TRIMESH_CUTFLAG           -8
#define TRIMESH_CUTANGLE          -9
#define TRIMESH_CUTMINEDGELENGTH  -10
#define TRIMESH_NONOBTUSEMETHOD   -11

/* function types */
#define TRIMESH_FUN_DEBUG   1
#define TRIMESH_FUN_MONITOR 2
#define TRIMESH_FUN_SIZING  3
#define TRIMESH_FUN_ASIZING 4

struct vis_TriangleGeneration {
    Vint ierr;

    Vint numnode;
    Vint numline;
    Vint maxi;
    Vdouble edgelen; /* target edge length */
    Vdouble growthrate;
    Vdouble maxedgelen;
    Vdouble jacobianratio;
    Vdouble refinefactor;
    Vint trimaxi; /* requested order of output tris */
    Vint inward;  /* input lines point inward */
    Vint repair;  /* repair inconsistencies */
    Vint boundcut;
    Vint boundref;
    Vint interref;
    Vint refinesmooth;
    Vint pointset;
    Vint nassocflag;
    Vint nassoc[VIS_MAXASSOC];
    Vint edassocflag;
    Vint edassoc[VIS_MAXASSOC];
    Vint elassocflag;
    Vint elassoc[VIS_MAXASSOC];
    Vint maxnumassoc;
    Vdouble* snode;
    Vdouble* sline;
    Vdouble* selem;
    Vdouble (*dselem)[2];
    Vint numgeom;
    vis_MeshSize* meshsize;
    vis_MeshSize* dmeshsize;

    Vint unconnect;
    Vint lineflag;
    Vint cutflag;
    Vdouble cutangle;
    Vdouble cutminedgelen;
    Vint advfront;
    Vint smthflag;
    Vint delaunay;
    Vint nonobtuse;
    Vint nonobtusemethod;
    Vint funsizingminflag;
    Vint funsizingLegacyFlag; /* Activate the sizing callback legacy behavior */
    Vdouble layerinitlen;
    Vdouble layergrowthrate;
    Vdouble (*linnrm)[2][3];
    Vint* linflg;
    Vint linnrmflag;
    Vint planflag;
    Vint repairfailflag;
    Vdouble xo[3], tm[3][3];
    Vint invertchk;
    Vdouble bbox[2][3];
    vsy_Pred* pred;
    /* Number of elements with a negative jacobian */
    Vint numnegjac;
    /* Number of elements with bad quality */
    Vint numnonqual;

    vsy_BitVec* nonman;
    vsy_BitVec* incons;
    vsy_BitVec* freeend;
    vsy_BitVec* unconn;
    vsy_BitVec* exnode;
    vsy_BitVec* inters;
    vsy_BitVec* repeatedNodes;
    vsy_BitVec* duplicateLine;

    vis_MeshCon* meshcon;
    Vint generateflag;
    Vint numcnode;
    vis_IdTran* idtrancnode;
    Vint addcnodeid;
    Vint numenode;
    vis_IdTran* idtranenode;
    vis_Group* groupbnode; /* parabolic nodes on boundary */

    Vint funflag;
    VTriMeshDebugFunc* fun;
    Vobject* funobject;
    VTriMeshMonitorFunc* funmon;
    Vobject* funobjmon;
    VTriMeshSizingFunc* funsiz;
    Vobject* funobjsiz;
    VTriMeshASizingFunc* funani;
    Vobject* funobjani;

    Vint refine;
    Vint phase;
    Vint numnp;
    Vint numel;
    Vint percent;
    Vint estnumel;
    Vdouble totalarea;
    Vint abortflag;
    Vint maxelrefine;

    vis_Connect* ce;
    vis_Group* gls;
    Vint* ia_n;
    Vint* ixnoel;
    Vint nelem;
    vis_Connect* connect;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vis_TriangleGeneration(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vis_TriangleGeneration(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void Def(Vint, Vint, Vint);
    VKI_EXTERN void
    Inq(Vint*, Vint*, Vint*);
    VKI_EXTERN void
    SetFunction(Vint, Vfunc*, Vobject*);
    VKI_EXTERN void
    SetDebugFunction(VTriMeshDebugFunc*, Vobject*);
    VKI_EXTERN void
    SetMonitorFunction(VTriMeshMonitorFunc*, Vobject*);
    VKI_EXTERN void
    SetSizingFunction(VTriMeshSizingFunc*, Vobject*);
    VKI_EXTERN void
    SetASizingFunction(VTriMeshASizingFunc*, Vobject*);
    VKI_EXTERN void SetNode(Vint, Vdouble[3]);
    VKI_EXTERN void SetNodeAssoc(Vint, Vint, Vint);
    VKI_EXTERN void SetNodeSizing(Vint, Vdouble);
    VKI_EXTERN void SetLine(Vint, Vint[]);
    VKI_EXTERN void SetLineStat(Vint, Vint);
    VKI_EXTERN void SetLineSizing(Vint, Vint, Vdouble);
    VKI_EXTERN void SetLineDepthSizing(Vint, Vdouble, Vdouble);
    VKI_EXTERN void SetLineNorm(Vint, Vdouble[2][3]);
    VKI_EXTERN void SetLineAssoc(Vint, Vint, Vint, Vint);
    VKI_EXTERN void SetElem(Vint, Vint, Vint, Vint[]);
    VKI_EXTERN void SetParami(Vint, Vint);
    VKI_EXTERN void
    GetParami(Vint, Vint*);
    VKI_EXTERN void SetParamd(Vint, Vdouble);
    VKI_EXTERN void
    GetParamd(Vint, Vdouble*);
    VKI_EXTERN void
    Abort();
    VKI_EXTERN void SetGeomSizing(Vint, Vdouble[3], Vdouble[3], Vdouble[3], Vdouble[3], Vdouble);
    VKI_EXTERN void
    GetConnect(vis_Connect**);
    VKI_EXTERN void
    Write(Vint, const Vchar*);
    VKI_EXTERN void
    Read(Vint, const Vchar*);
    VKI_EXTERN void GetInteger(Vint, Vint[]);
    VKI_EXTERN void
    ComputeArea(Vdouble*);
    VKI_EXTERN void
    Generate(vis_Connect*);
    VKI_EXTERN void
    Refine(vis_State*, vis_Connect*);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_TriangleGeneration*
vis_TriangleGenerationBegin(void);
VKI_EXTERN void
vis_TriangleGeneration_Construct(vis_TriangleGeneration* p);
VKI_EXTERN void
vis_TriangleGenerationEnd(vis_TriangleGeneration* p);
VKI_EXTERN void
vis_TriangleGeneration_Destruct(vis_TriangleGeneration* p);
VKI_EXTERN Vint
vis_TriangleGenerationError(vis_TriangleGeneration* p);
VKI_EXTERN void
vis_TriangleGenerationDef(vis_TriangleGeneration* p, Vint numnode, Vint numline, Vint maxi);
VKI_EXTERN void
vis_TriangleGenerationInq(vis_TriangleGeneration* p, Vint* numnode, Vint* numline, Vint* maxi);
VKI_EXTERN void
vis_TriangleGenerationSetFunction(vis_TriangleGeneration* p, Vint funtype, Vfunc* function, Vobject* object);
VKI_EXTERN void
vis_TriangleGenerationSetDebugFunction(vis_TriangleGeneration* p, VTriMeshDebugFunc* function, Vobject* object);
VKI_EXTERN void
vis_TriangleGenerationSetMonitorFunction(vis_TriangleGeneration* p, VTriMeshMonitorFunc* function, Vobject* object);
VKI_EXTERN void
vis_TriangleGenerationSetSizingFunction(vis_TriangleGeneration* p, VTriMeshSizingFunc* function, Vobject* object);
VKI_EXTERN void
vis_TriangleGenerationSetASizingFunction(vis_TriangleGeneration* p, VTriMeshASizingFunc* function, Vobject* object);
VKI_EXTERN void
vis_TriangleGenerationSetNode(vis_TriangleGeneration* p, Vint id, Vdouble x[3]);
VKI_EXTERN void
vis_TriangleGenerationSetNodeAssoc(vis_TriangleGeneration* p, Vint type, Vint id, Vint aid);
VKI_EXTERN void
vis_TriangleGenerationSetNodeSizing(vis_TriangleGeneration* p, Vint id, Vdouble h);
VKI_EXTERN void
vis_TriangleGenerationSetLine(vis_TriangleGeneration* p, Vint id, Vint ix[]);
VKI_EXTERN void
vis_TriangleGenerationSetLineStat(vis_TriangleGeneration* p, Vint id, Vint stat);
VKI_EXTERN void
vis_TriangleGenerationSetLineSizing(vis_TriangleGeneration* p, Vint id, Vint enttype, Vdouble h);
VKI_EXTERN void
vis_TriangleGenerationSetLineDepthSizing(vis_TriangleGeneration* p, Vint id, Vdouble d, Vdouble h);
VKI_EXTERN void
vis_TriangleGenerationSetLineNorm(vis_TriangleGeneration* p, Vint id, Vdouble v[2][3]);
VKI_EXTERN void
vis_TriangleGenerationSetLineAssoc(vis_TriangleGeneration* p, Vint type, Vint id, Vint enttype, Vint aid);
VKI_EXTERN void
vis_TriangleGenerationSetElem(vis_TriangleGeneration* p, Vint id, Vint shape, Vint maxi, Vint ix[]);
VKI_EXTERN void
vis_TriangleGenerationSetParami(vis_TriangleGeneration* p, Vint ptype, Vint iparam);
VKI_EXTERN void
vis_TriangleGenerationGetParami(vis_TriangleGeneration* p, Vint type, Vint* iparam);
VKI_EXTERN void
vis_TriangleGenerationSetParamd(vis_TriangleGeneration* p, Vint ptype, Vdouble dparam);
VKI_EXTERN void
vis_TriangleGenerationGetParamd(vis_TriangleGeneration* p, Vint type, Vdouble* param);
VKI_EXTERN void
vis_TriangleGenerationAbort(vis_TriangleGeneration* p);
VKI_EXTERN void
vis_TriangleGenerationSetGeomSizing(vis_TriangleGeneration* p, Vint type, Vdouble xo[3], Vdouble xa[3], Vdouble xb[3],
                                    Vdouble d[3], Vdouble h);
VKI_EXTERN void
vis_TriangleGenerationGetConnect(vis_TriangleGeneration* p, vis_Connect** connect);
VKI_EXTERN void
vis_TriangleGenerationWrite(vis_TriangleGeneration* p, Vint type, const Vchar* path);
VKI_EXTERN void
vis_TriangleGenerationRead(vis_TriangleGeneration* p, Vint type, const Vchar* path);
VKI_EXTERN void
vis_TriangleGenerationGetInteger(vis_TriangleGeneration* p, Vint type, Vint iparam[]);
VKI_EXTERN void
vis_TriangleGenerationComputeArea(vis_TriangleGeneration* p, Vdouble* area);
VKI_EXTERN void
vis_TriangleGenerationGenerate(vis_TriangleGeneration* p, vis_Connect* connect);
VKI_EXTERN void
vis_TriangleGenerationRefine(vis_TriangleGeneration* p, vis_State* state, vis_Connect* connect);

#ifdef __cplusplus
}
#endif

#endif
