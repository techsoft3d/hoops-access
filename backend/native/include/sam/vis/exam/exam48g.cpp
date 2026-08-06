#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* a unit cube and interior edge endpoints */
static Vdouble xc[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                           {0., 0., 1.}, {1., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}};

static Vint tris[12][3] = {{1, 5, 3}, {3, 5, 7}, {4, 6, 2}, {8, 6, 4}, {1, 2, 5}, {5, 2, 6},
                           {7, 4, 3}, {8, 4, 7}, {1, 4, 2}, {4, 1, 3}, {5, 8, 7}, {5, 6, 8}};
static Vint tefl[12][3] = {{1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {1, 0, 1}, {1, 0, 1}, {0, 1, 1},
                           {0, 1, 1}, {1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {0, 1, 1}, {1, 1, 0}};

static Vdouble norms[12][3][3] = {{{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}}, {{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}},
                                  {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},    {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                  {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}}, {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                  {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},    {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},
                                  {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}}, {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}},
                                  {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}},    {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}}};

static Vdouble xe[2][3] = {{0.25, 0.25, 0.25}, {0.75, 0.75, 0.25}};

static Vint lin[2] = {1, 2};

static Vdouble tangs[2][3] = {{1., 0., 0.}, {0., 1., 0.}};

/*----------------------------------------------------------------------
                      Generate a Surface Mesh, Curve Mesh and Tet Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_SurfMesh* surfmesh;
    msh_CurvMesh* curvmesh;
    msh_TetMesh* tetmesh;
    vis_Connect *connectsurf, *connectcurv, *connecttet;

    Vint i;
    Vint numsurfpnts, numsurftris;
    Vint numcurvpnts, numcurvlins;
    Vint numnp, numel;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create SurfMesh object */
    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, 8, 12);

    /* create Connect object */
    connectsurf = vis_ConnectBegin();
    vis_ConnectPre(connectsurf, SYS_DOUBLE);
    vis_ConnectDef(connectsurf, 0, 0);

    /* define points */
    for (i = 0; i < 8; i++) {
        msh_SurfMeshSetPoint(surfmesh, i + 1, xc[i], 1);
    }
    /* define triangle connectivity */
    for (i = 0; i < 12; i++) {
        msh_SurfMeshSetTri(surfmesh, i + 1, tris[i], tefl[i]);
        msh_SurfMeshSetTriNorm(surfmesh, i + 1, norms[i]);
    }
    /* set mesh parameters */
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 3);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, .1);

    /* generate */
    msh_SurfMeshGenerate(surfmesh, connectsurf);
    if (msh_SurfMeshError(surfmesh)) {
        printf("surf mesh generation error\n");
        exit(1);
    }
    else {
        printf("surf mesh generation complete\n");
    }
    /* print number of surface nodes and elements */
    vis_ConnectNumber(connectsurf, SYS_NODE, &numsurfpnts);
    vis_ConnectNumber(connectsurf, SYS_ELEM, &numsurftris);
    printf(" Number of nodes= %d\n", numsurfpnts);
    printf(" Number of tris = %d\n", numsurftris);

    /* generate interior curve mesh */
    /* create CurvMesh object */
    curvmesh = msh_CurvMeshBegin();
    msh_CurvMeshDef(curvmesh, 2, 1);

    /* create Connect object */
    connectcurv = vis_ConnectBegin();
    vis_ConnectPre(connectcurv, SYS_DOUBLE);
    vis_ConnectDef(connectcurv, 0, 0);

    /* define points */
    for (i = 0; i < 2; i++) {
        msh_CurvMeshSetPoint(curvmesh, i + 1, xe[i], 1);
    }
    /* define line connectivity */
    msh_CurvMeshSetLine(curvmesh, 1, lin);
    msh_CurvMeshSetLineTang(curvmesh, 1, tangs);
    /* set mesh parameters */
    msh_CurvMeshSetParami(curvmesh, VIS_MESH_MAXI, 3);
    msh_CurvMeshSetParamd(curvmesh, VIS_MESH_EDGELENGTH, .005);

    /* generate */
    msh_CurvMeshGenerate(curvmesh, connectcurv);
    if (msh_CurvMeshError(curvmesh)) {
        printf("curv mesh generation error\n");
        exit(1);
    }
    else {
        printf("curv mesh generation complete\n");
    }
    /* print number of curve nodes and elements */
    vis_ConnectNumber(connectcurv, SYS_NODE, &numcurvpnts);
    vis_ConnectNumber(connectcurv, SYS_ELEM, &numcurvlins);
    printf(" Number of nodes= %d\n", numcurvpnts);
    printf(" Number of lines= %d\n", numcurvlins);

    /* add curve mesh to surface mesh */
    vis_ConnectAppend(connectsurf, connectcurv);
    vis_ConnectMerge(connectsurf, NULL);

    /* create TetMesh object */
    tetmesh = msh_TetMeshBegin();
    msh_TetMeshDef(tetmesh, numsurfpnts, numsurftris, 2);
    /* fill with boundary elements */
    msh_TetMeshConnect(tetmesh, connectsurf);
    msh_TetMeshSetParamd(tetmesh, VIS_MESH_EDGELENGTH, .1);

    /* create Connect object to hold generated tet mesh */
    connecttet = vis_ConnectBegin();
    vis_ConnectPre(connecttet, SYS_DOUBLE);
    vis_ConnectDef(connecttet, 0, 0);

    /* generate mesh */
    msh_TetMeshGenerate(tetmesh, connecttet);
    if (msh_TetMeshError(tetmesh)) {
        printf("tet mesh generation error\n");
        exit(1);
    }
    else {
        printf("tet mesh generation complete\n");
    }
    /* print number of surface nodes and elements */
    vis_ConnectNumber(connecttet, SYS_NODE, &numnp);
    vis_ConnectNumber(connecttet, SYS_ELEM, &numel);
    printf(" Number of nodes= %d\n", numnp);
    printf(" Number of elems= %d\n", numel);
    vis_ConnectWrite(connecttet, SYS_NASTRAN_BULKDATA, "exam48g.bdf");

    /* end objects */
    vis_ConnectEnd(connectsurf);
    vis_ConnectEnd(connectcurv);
    vis_ConnectEnd(connecttet);
    msh_SurfMeshEnd(surfmesh);
    msh_CurvMeshEnd(curvmesh);
    msh_TetMeshEnd(tetmesh);
    return 0;
}
