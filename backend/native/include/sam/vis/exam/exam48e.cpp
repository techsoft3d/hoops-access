#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* a cube with interior surface, and two inclusions */
/* point coordinates */
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
                            /* inclusion 1 */
                            {.1, .1, .1},
                            {.2, .1, .1},
                            {.1, .2, .1},
                            {.2, .2, .1},
                            {.1, .1, .2},
                            {.2, .1, .2},
                            {.1, .2, .2},
                            {.2, .2, .2},
                            /* inclusion 2 */
                            {.1, .1, 1.1},
                            {.2, .1, 1.1},
                            {.1, .2, 1.1},
                            {.2, .2, 1.1},
                            {.1, .1, 1.2},
                            {.2, .1, 1.2},
                            {.1, .2, 1.2},
                            {.2, .2, 1.2}};

/* triangle connectivity */
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
                           /* inclusion 1 */
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
                           /* inclusion 2 */
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

/* triangle right and left element associations */
static Vint ta[46][2] = {
/* outer boundary and non-manifold internal surface */
{1, 0},
{1, 0},
{1, 0},
{1, 0},
{1, 0},
{1, 0},
{1, 0},
{1, 0},
{1, 0},
{1, 0},
{1, 2},
{1, 2},
{2, 0},
{2, 0},
{2, 0},
{2, 0},
{2, 0},
{2, 0},
{2, 0},
{2, 0},
{2, 0},
{2, 0},
/* inclusion 1, faces point into inclusion */
{1, 3},
{1, 3},
{1, 3},
{1, 3},
{1, 3},
{1, 3},
{1, 3},
{1, 3},
{1, 3},
{1, 3},
{1, 3},
{1, 3},
/* inclusion 2, faces point out of inclusion */
{4, 2},
{4, 2},
{4, 2},
{4, 2},
{4, 2},
{4, 2},
{4, 2},
{4, 2},
{4, 2},
{4, 2},
{4, 2},
{4, 2}};

/* triangle edge flags */
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
                           /* inclusion 1 */
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
                           /* inclusion 2 */
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

/* triangle normals */
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
                                  /* inclusion 1 */
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
                                  /* inclusion 2 */
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
                   Generate a Hybrid Boundary and Volumetric Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_SurfMesh* surfmesh;
    msh_VolMesh* volmesh;
    vis_Connect *connectsurf, *connectvol;

    Vint i;
    Vint numsurfpnts, numsurftris;
    Vint numnp, numel;
    Vint aid;
    Vdouble edgelength;

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
        msh_SurfMeshSetTriNorm(surfmesh, i + 1, norms[i]);
        msh_SurfMeshSetTriBack(surfmesh, i + 1, ta[i][0], ta[i][1]);
        /* set property associations */
        if (ta[i][0]) {
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, i + 1, SYS_ELEM, 0, ta[i][0]);
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, i + 1, SYS_ELEM, 0, ta[i][0]);
        }
        if (ta[i][1]) {
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, i + 1, SYS_ELEM, -1, ta[i][1]);
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, i + 1, SYS_ELEM, -1, ta[i][1]);
        }
    }
    /* set mesh parameters */
    edgelength = .5;
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 2);
    msh_SurfMeshSetParami(surfmesh, SURFMESH_NONMANIFOLD, VIS_ON);
    msh_SurfMeshSetParami(surfmesh, SURFMESH_INTSURFBACK, VIS_ON);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, edgelength);

    /* write out file encapsulating meshing specifications */
    msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam48e.srf");
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
    vis_ConnectWrite(connectsurf, SYS_NASTRAN_BULKDATA, "exam48e-srf.bdf");

    /* create VolMesh object */
    volmesh = msh_VolMeshBegin();
    msh_VolMeshDef(volmesh, numsurfpnts, numsurftris);

    /* Fill VolMesh object with generated surface mesh */
    msh_VolMeshConnect(volmesh, connectsurf);

    /* Define fill regions */
    for (i = 1; i <= numsurftris; i++) {
        vis_ConnectElemAssoc(connectsurf, VIS_GEOBODY, 1, &i, &aid);
        /* tet fill for regions 1 and 2 */
        if (aid == 1 || aid == 2) {
            msh_VolMeshSetFaceFill(volmesh, i, VOLMESH_FILL_TET);
            /* boundary output for regions 3 and 4 */
        }
        else {
            msh_VolMeshSetFaceFill(volmesh, i, VOLMESH_FILL_BOUNDARY);
        }
    }
    msh_VolMeshSetParamd(volmesh, VIS_MESH_EDGELENGTH, edgelength);
    vis_ConnectEnd(connectsurf);

    /* create Connect object to hold generated vol mesh */
    connectvol = vis_ConnectBegin();
    vis_ConnectPre(connectvol, SYS_DOUBLE);
    vis_ConnectDef(connectvol, 0, 0);

    /* write out file encapsulating meshing specifications */
    msh_VolMeshWrite(volmesh, SYS_ASCII, "exam48e.vol");
    /* generate mesh */
    msh_VolMeshGenerate(volmesh, connectvol);
    if (msh_VolMeshError(volmesh)) {
        printf("hybrid mesh generation error\n");
        exit(1);
    }
    else {
        printf("hybrid mesh generation complete\n");
    }
    msh_VolMeshEnd(volmesh);
    /* print number of surface nodes and elements */
    vis_ConnectNumber(connectvol, SYS_NODE, &numnp);
    vis_ConnectNumber(connectvol, SYS_ELEM, &numel);
    printf(" Number of nodes= %d\n", numnp);
    printf(" Number of elems= %d\n", numel);

    /* write generated hybrid mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connectvol, SYS_NASTRAN_BULKDATA, "exam48e-vol.bdf");

    vis_ConnectEnd(connectvol);
    return 0;
}
