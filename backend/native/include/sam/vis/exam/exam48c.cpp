#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* a cube with interior surface, a hole and an inclusion */
static Vdouble xc[28][3] = {{0., 0., 0.},
                            {1., 0., 0.},
                            {0., 1., 0.},
                            {1., 1., 0.},
                            {0., 0., 1.},
                            {1., 0., 1.},
                            {0., 1., 1.},
                            {1., 1., 1.},
                            {0., 0., 2.},
                            {1., 0., 2.},
                            {0., 1., 2.},
                            {1., 1., 2.},
                            /* hole */
                            {.1, .1, .1},
                            {.2, .1, .1},
                            {.1, .2, .1},
                            {.2, .2, .1},
                            {.1, .1, .2},
                            {.2, .1, .2},
                            {.1, .2, .2},
                            {.2, .2, .2},
                            /* inclusion */
                            {.1, .1, 1.1},
                            {.2, .1, 1.1},
                            {.1, .2, 1.1},
                            {.2, .2, 1.1},
                            {.1, .1, 1.2},
                            {.2, .1, 1.2},
                            {.1, .2, 1.2},
                            {.2, .2, 1.2}};

static Vint tris[46][3] = {{1, 5, 3},
                           {3, 5, 7},
                           {4, 6, 2},
                           {8, 6, 4},
                           {1, 2, 5},
                           {5, 2, 6},
                           {7, 4, 3},
                           {8, 4, 7},
                           {1, 4, 2},
                           {4, 1, 3},
                           {5, 8, 7},
                           {5, 6, 8},
                           {5, 9, 7},
                           {7, 9, 11},
                           {8, 10, 6},
                           {12, 10, 8},
                           {5, 6, 9},
                           {9, 6, 10},
                           {11, 8, 7},
                           {12, 8, 11},
                           {9, 12, 11},
                           {9, 10, 12},
                           /* hole */
                           {13, 15, 17},
                           {15, 19, 17},
                           {16, 14, 18},
                           {20, 16, 18},
                           {13, 17, 14},
                           {17, 18, 14},
                           {19, 15, 16},
                           {20, 19, 16},
                           {13, 14, 16},
                           {16, 15, 13},
                           {17, 19, 20},
                           {17, 20, 18},
                           /* inclusion */
                           {21, 25, 23},
                           {23, 25, 27},
                           {24, 26, 22},
                           {28, 26, 24},
                           {21, 22, 25},
                           {25, 22, 26},
                           {27, 24, 23},
                           {28, 24, 27},
                           {21, 24, 22},
                           {24, 21, 23},
                           {25, 28, 27},
                           {25, 26, 28}};

static Vint tefl[46][3] = {{1, 0, 1},
                           {0, 1, 1},
                           {0, 1, 1},
                           {1, 0, 1},
                           {1, 0, 1},
                           {0, 1, 1},
                           {0, 1, 1},
                           {1, 0, 1},
                           {0, 1, 1},
                           {0, 1, 1},
                           {0, 1, 1},
                           {1, 1, 0},
                           {1, 0, 1},
                           {0, 1, 1},
                           {0, 1, 1},
                           {1, 0, 1},
                           {1, 0, 1},
                           {0, 1, 1},
                           {0, 1, 1},
                           {1, 0, 1},
                           {0, 1, 1},
                           {1, 1, 0},
                           /* hole */
                           {1, 0, 1},
                           {1, 1, 0},
                           {1, 1, 0},
                           {1, 0, 1},
                           {1, 0, 1},
                           {1, 1, 0},
                           {1, 1, 0},
                           {1, 0, 1},
                           {1, 1, 0},
                           {1, 1, 0},
                           {1, 1, 0},
                           {0, 1, 1},
                           /* inclusion */
                           {1, 0, 1},
                           {0, 1, 1},
                           {0, 1, 1},
                           {1, 0, 1},
                           {1, 0, 1},
                           {0, 1, 1},
                           {0, 1, 1},
                           {1, 0, 1},
                           {0, 1, 1},
                           {0, 1, 1},
                           {0, 1, 1},
                           {1, 1, 0}};

static Vdouble norms[46][3][3] = {{{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}},
                                  {{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}},
                                  {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                  {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                  {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                  {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                  {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},
                                  {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},
                                  {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}},
                                  {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}},
                                  {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}},
                                  {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}},

                                  {{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}},
                                  {{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}},
                                  {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                  {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                  {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                  {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                  {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},
                                  {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},
                                  {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}},
                                  {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}},
                                  /* hole */
                                  {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                  {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                  {{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}},
                                  {{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}},
                                  {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},
                                  {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},
                                  {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                  {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                  {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}},
                                  {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}},
                                  {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}},
                                  {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}},
                                  /* inclusion */
                                  {{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}},
                                  {{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}},
                                  {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                  {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                  {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                  {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                  {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},
                                  {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},
                                  {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}},
                                  {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}},
                                  {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}},
                                  {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}}};

/*----------------------------------------------------------------------
                      Generate a Surface Mesh and Tet Mesh, Non-manifold Solid
----------------------------------------------------------------------*/
int
main()
{
    msh_SurfMesh* surfmesh;
    msh_TetMesh* tetmesh;
    vis_Connect *connectsurf, *connecttet, *connectref;
    vis_State* state;
    vis_GridFun* gf;

    Vint i, j;
    Vint numsurfpnts, numsurftris;
    Vint numnp, numel;
    Vdouble x[3], size;
    Vint nix, ix[3], aid;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create SurfMesh object */
    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, 28, 46);

    /* create Connect object */
    connectsurf = vis_ConnectBegin();
    vis_ConnectPre(connectsurf, SYS_DOUBLE);
    vis_ConnectDef(connectsurf, 0, 0);

    /* define points */
    for (i = 0; i < 28; i++) {
        msh_SurfMeshSetPoint(surfmesh, i + 1, xc[i], 1);
    }
    /* define triangle connectivity */
    for (i = 0; i < 46; i++) {
        msh_SurfMeshSetTri(surfmesh, i + 1, tris[i], tefl[i]);
        for (j = 0; j < 3; j++) {
            if (tefl[i][j]) {
                msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOEDGE, i + 1, SYS_EDGE, j + 1, 1);
            }
        }
        msh_SurfMeshSetTriNorm(surfmesh, i + 1, norms[i]);
    }
    /* set property association for each body */
    /* set all elements on a face bordering body */
    /* body 1 */
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, 1, SYS_ELEM, 0, 1);
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, 2, SYS_ELEM, 0, 1);
    /* body 2 */
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, 21, SYS_ELEM, 0, 2);
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, 22, SYS_ELEM, 0, 2);
    /* body 3, inclusion */
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, 45, SYS_ELEM, 0, 3);
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, 46, SYS_ELEM, 0, 3);

    /* set mesh parameters */
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 2);
    msh_SurfMeshSetParami(surfmesh, SURFMESH_NONMANIFOLD, VIS_ON);
    msh_SurfMeshSetParami(surfmesh, SURFMESH_INTSURFBACK, VIS_ON);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, 1.);

    /* write out file encapsulating meshing specifications */
    msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam48c.srf");
    /* generate */
    msh_SurfMeshGenerate(surfmesh, connectsurf);
    if (msh_SurfMeshError(surfmesh)) {
        printf("surf mesh generation error\n");
        exit(1);
    }
    else {
        printf("surf mesh generation complete\n");
    }
    msh_SurfMeshEnd(surfmesh);

    /* print number of surface nodes and elements */
    vis_ConnectNumber(connectsurf, SYS_NODE, &numsurfpnts);
    vis_ConnectNumber(connectsurf, SYS_ELEM, &numsurftris);
    printf(" Number of nodes= %d\n", numsurfpnts);
    printf(" Number of tris = %d\n", numsurftris);

    /* write generated surf mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connectsurf, SYS_NASTRAN_BULKDATA, "exam48c-srf.bdf");

    /* create TetMesh object */
    tetmesh = msh_TetMeshBegin();
    msh_TetMeshDef(tetmesh, numsurfpnts, numsurftris, 2);

    /* Fill TetMesh object with generated points on surface */
    for (i = 1; i <= numsurfpnts; i++) {
        vis_ConnectCoordsdv(connectsurf, 1, &i, (Vdouble(*)[3])x);
        msh_TetMeshSetNode(tetmesh, i, x);
    }
    /* Fill TetMesh object with generated triangles */
    for (i = 1; i <= numsurftris; i++) {
        vis_ConnectElemNode(connectsurf, i, &nix, ix);
        msh_TetMeshSetTri(tetmesh, i, ix);
        vis_ConnectElemAssoc(connectsurf, VIS_PROPID, 1, &i, &aid);
        if (aid) {
            msh_TetMeshSetTriAssoc(tetmesh, VIS_PROPID, i, SYS_ELEM, 0, aid);
        }
        /* flag preserved edge with a VIS_GEOEDGE association */
        for (j = 1; j <= 3; j++) {
            vis_ConnectElemEntAssoc(connectsurf, VIS_GEOEDGE, SYS_EDGE, i, j, &aid);
            if (aid) {
                msh_TetMeshSetTriAssoc(tetmesh, VIS_PROPID, i, SYS_EDGE, j, aid);
            }
        }
    }
    vis_ConnectEnd(connectsurf);

    /* create Connect object to hold generated tet mesh */
    connecttet = vis_ConnectBegin();
    vis_ConnectPre(connecttet, SYS_DOUBLE);
    vis_ConnectDef(connecttet, 0, 0);

    /* write out file encapsulating meshing specifications */
    msh_TetMeshWrite(tetmesh, SYS_ASCII, "exam48c.tet");
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

    /* write generated tet mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connecttet, SYS_NASTRAN_BULKDATA, "exam48c-tet.bdf");

    /* refine mesh */
    state = vis_StateBegin();
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connecttet, gf);
    vis_StateSetObject(state, VIS_GRIDFUN, (Vobject*)gf);
    vis_StateDef(state, numel, SYS_ELEM, SYS_NONE, VIS_SCALAR);
    for (i = 1; i <= numel; i++) {
        size = .125;
        vis_StateSetDatadv(state, i, &size);
    }
    /* refine tetmesh */
    connectref = vis_ConnectBegin();
    vis_ConnectPre(connectref, SYS_DOUBLE);
    msh_TetMeshRefine(tetmesh, state, connectref);
    if (msh_TetMeshError(tetmesh)) {
        printf("tet mesh refinement error\n");
        exit(1);
    }
    else {
        printf("tet mesh refinement complete\n");
    }
    /* print number of surface nodes and elements */
    vis_ConnectNumber(connectref, SYS_NODE, &numnp);
    vis_ConnectNumber(connectref, SYS_ELEM, &numel);
    printf(" Number of nodes= %d\n", numnp);
    printf(" Number of elems= %d\n", numel);
    /* write refined tet mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connectref, SYS_NASTRAN_BULKDATA, "exam48c-ref.bdf");

    msh_TetMeshEnd(tetmesh);
    vis_ConnectEnd(connecttet);
    vis_ConnectEnd(connectref);
    vis_StateEnd(state);
    vis_GridFunEnd(gf);
    return 0;
}
