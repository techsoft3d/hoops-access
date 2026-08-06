#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* a cube with interior surface */
/* point coordinates */
static Vdouble xc[12][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.}, {0., 0., 1.}, {1., 0., 1.},
                            {0., 1., 1.}, {1., 1., 1.}, {0., 0., 2.}, {1., 0., 2.}, {0., 1., 2.}, {1., 1., 2.}};

/* triangle connectivity */
static Vint tris[22][3] = {{1, 5, 3}, {3, 5, 7},  {4, 6, 2},  {8, 6, 4},   {1, 2, 5},   {5, 2, 6},  {7, 4, 3},  {8, 4, 7},
                           {1, 4, 2}, {4, 1, 3},  {5, 8, 7},  {5, 6, 8},   {5, 9, 7},   {7, 9, 11}, {8, 10, 6}, {12, 10, 8},
                           {5, 6, 9}, {9, 6, 10}, {11, 8, 7}, {12, 8, 11}, {9, 12, 11}, {9, 10, 12}};
/* triangle right and left element associations */
static Vint ta[22][2] = {
/* outer boundary and non-manifold internal surface */
{1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 2},
{1, 2}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}};

/* triangle edge flags */
static Vint tefl[22][3] = {{1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {1, 0, 1}, {1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {1, 0, 1},
                           {0, 1, 1}, {0, 1, 1}, {0, 1, 1}, {1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {1, 0, 1},
                           {1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {1, 0, 1}, {0, 1, 1}, {1, 1, 0}};

/* triangle normals */
static Vdouble norms[22][3][3] = {{{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}}, {{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}},
                                  {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},    {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                  {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}}, {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                  {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},    {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},
                                  {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}}, {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}},
                                  {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}},    {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}},

                                  {{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}}, {{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}},
                                  {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},    {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                  {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}}, {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                  {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},    {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},
                                  {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}},    {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}}};

/*----------------------------------------------------------------------
                      Generate Surface and 3D Volume Tet Mesh with Sizing
----------------------------------------------------------------------*/
int
main()
{
    msh_SurfMesh* surfmesh;
    msh_TetMesh* tetmesh;
    vis_Connect *connectsurf, *connecttet;

    Vint i;
    Vint numsurfpnts, numsurftris;
    Vint numnp, numel;
    Vdouble x[3];
    Vint nix, ix[3], aid;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create SurfMesh object */
    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, 12, 22);

    /* create Connect object */
    connectsurf = vis_ConnectBegin();
    vis_ConnectPre(connectsurf, SYS_DOUBLE);
    vis_ConnectDef(connectsurf, 0, 0);

    /* define points */
    for (i = 0; i < 12; i++) {
        msh_SurfMeshSetPoint(surfmesh, i + 1, xc[i], 1);
    }
    /* define triangle connectivity */
    for (i = 0; i < 22; i++) {
        msh_SurfMeshSetTri(surfmesh, i + 1, tris[i], tefl[i]);
        msh_SurfMeshSetTriNorm(surfmesh, i + 1, norms[i]);
        msh_SurfMeshSetTriBack(surfmesh, i + 1, ta[i][0], ta[i][1]);
        /* set property associations */
        if (ta[i][0]) {
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, i + 1, SYS_ELEM, 0, ta[i][0]);
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, i + 1, SYS_ELEM, 0, ta[i][0]);
        }
        if (ta[i][1]) {
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, i + 1, SYS_ELEM, -1, ta[i][1]);
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, i + 1, SYS_ELEM, -1, ta[i][1]);
        }
    }
    /* set mesh parameters */
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 2);
    msh_SurfMeshSetParami(surfmesh, SURFMESH_NONMANIFOLD, VIS_ON);
    msh_SurfMeshSetParami(surfmesh, SURFMESH_INTSURFBACK, VIS_ON);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, .2);

    /* write out file encapsulating meshing specifications */
    msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam45a.srf");
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
    vis_ConnectWrite(connectsurf, SYS_NASTRAN_BULKDATA, "exam45a-srf.bdf");

    /* create TetMesh object */
    tetmesh = msh_TetMeshBegin();
    msh_TetMeshDef(tetmesh, numsurfpnts + 1, numsurftris, 2);

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
        vis_ConnectElemAssoc(connectsurf, VIS_GEOBODY, 1, &i, &aid);
        if (aid) {
            msh_TetMeshSetTriAssoc(tetmesh, VIS_GEOBODY, i, SYS_ELEM, 0, aid);
        }
    }
    /* set sizing */
    msh_TetMeshSetParamd(tetmesh, VIS_MESH_EDGELENGTH, .2);
    /* add sizing at unconnected node in center of region 1 */
    x[0] = .5;
    x[1] = .5;
    x[2] = .5;
    msh_TetMeshSetNode(tetmesh, numsurfpnts + 1, x);
    msh_TetMeshSetNodeSizing(tetmesh, numsurfpnts + 1, .02);
    msh_TetMeshSetParami(tetmesh, TETMESH_UNCONNECT, SYS_ON);
    /* set region sizing */
    for (i = 1; i <= numsurftris; i++) {
        vis_ConnectElemAssoc(connectsurf, VIS_GEOBODY, 1, &i, &aid);
        if (aid == 2) {
            msh_TetMeshSetTriSizing(tetmesh, i, .05);
        }
    }

    vis_ConnectEnd(connectsurf);

    /* create Connect object to hold generated tet mesh */
    connecttet = vis_ConnectBegin();
    vis_ConnectPre(connecttet, SYS_DOUBLE);
    vis_ConnectDef(connecttet, 0, 0);

    /* write out file encapsulating meshing specifications */
    msh_TetMeshWrite(tetmesh, SYS_ASCII, "exam45a.tet");
    /* generate mesh */
    msh_TetMeshGenerate(tetmesh, connecttet);
    if (msh_TetMeshError(tetmesh)) {
        printf("tet mesh generation error\n");
        exit(1);
    }
    else {
        printf("tet mesh generation complete\n");
    }
    msh_TetMeshEnd(tetmesh);
    /* print number of surface nodes and elements */
    vis_ConnectNumber(connecttet, SYS_NODE, &numnp);
    vis_ConnectNumber(connecttet, SYS_ELEM, &numel);
    printf(" Number of nodes= %d\n", numnp);
    printf(" Number of elems= %d\n", numel);

    /* write generated tet mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connecttet, SYS_NASTRAN_BULKDATA, "exam45a-tet.bdf");

    vis_ConnectEnd(connecttet);
    return 0;
}
