#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
/*
                 3----3-----4
                /.         /|
               / 4        / 2
             12  .      11  |
             /   1....1./...2
            7----7-----8   /
            |  9       |  10
            8 .        6 /
            |.         |/
            5----5-----6

           faces are ordered 1(-z), 2(+z) 3(-y) 4(+y) 5(-x) 6(+x)

           y
           |
           +-- x
          /
         z
*/

/* a simple unit cube */
static Vdouble xc[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                           {0., 0., 1.}, {1., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}};

static Vint tris[12][3] = {{1, 5, 3}, {3, 5, 7}, {4, 6, 2}, {8, 6, 4}, {1, 2, 5}, {5, 2, 6},
                           {7, 4, 3}, {8, 4, 7}, {1, 4, 2}, {4, 1, 3}, {5, 8, 7}, {5, 6, 8}};
static Vint tefl[12][3] = {{1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {1, 0, 1}, {1, 0, 1}, {0, 1, 1},
                           {0, 1, 1}, {1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {0, 1, 1}, {1, 1, 0}};
/* edge associations */
static Vint ted[12][3] = {{9, 0, 4},  {0, 8, 12}, {0, 10, 2}, {1, 0, 11}, {1, 0, 9}, {0, 10, 5},
                          {0, 3, 12}, {11, 0, 7}, {0, 2, 1},  {0, 4, 3},  {0, 7, 8}, {5, 6, 0}};
/* face associations */
static Vint tfa[12] = {5, 5, 6, 6, 3, 3, 4, 4, 1, 1, 2, 2};

/* triangle normals */
static Vdouble norms[12][3][3] = {{{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}}, {{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}},
                                  {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},    {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                  {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}}, {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                  {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},    {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},
                                  {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}}, {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}},
                                  {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}},    {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}}};

/*----------------------------------------------------------------------
                      Generate a Surface Mesh and Tet Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_SurfMesh* surfmesh;
    msh_TetMesh* tetmesh;
    vis_Connect *connectsurf, *connecttet;

    Vint i, j, k;
    Vint maxi;
    Vint numsurfpnts, numsurftris;
    Vint numnp, numel;
    Vdouble x[3];
    Vint nix, ix[10];
    Vint num, aid, aids[10];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create SurfMesh object */
    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, 8, 12);

    /* create Connect object */
    connectsurf = vis_ConnectBegin();
    vis_ConnectPre(connectsurf, SYS_DOUBLE);
    vis_ConnectDef(connectsurf, 0, 0);

    /* generate parabolic elements */
    maxi = 3;
    /* define points */
    for (i = 0; i < 8; i++) {
        msh_SurfMeshSetPoint(surfmesh, i + 1, xc[i], 1);
        /* set VIS_GEOVERT association to the point id */
        msh_SurfMeshSetPointAssoc(surfmesh, VIS_GEOVERT, i + 1, i + 1);
    }
    /* define triangle connectivity */
    for (i = 0; i < 12; i++) {
        msh_SurfMeshSetTri(surfmesh, i + 1, tris[i], tefl[i]);
        msh_SurfMeshSetTriNorm(surfmesh, i + 1, norms[i]);
        /* set VIS_GEOEDGE and VIS_GEOFACE */
        for (j = 0; j < 3; j++) {
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOEDGE, i + 1, SYS_EDGE, j + 1, ted[i][j]);
        }
        msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOFACE, i + 1, SYS_FACE, 0, tfa[i]);
        /* set VIS_GEOBODY to 1, only a single body */
        msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, i + 1, SYS_ELEM, 0, 1);
    }

    /* set mesh parameters */
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, maxi);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, .5);

    msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam45.srf");
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

    /* write generated tet mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connectsurf, SYS_NASTRAN_BULKDATA, "exam45_srf.bdf");

    /* create TetMesh object */
    tetmesh = msh_TetMeshBegin();
    msh_TetMeshDef(tetmesh, numsurfpnts, numsurftris, maxi);

    /* Fill TetMesh object with generated points on surface */
    msh_TetMeshConnect(tetmesh, connectsurf);

    /* set mesh parameters */
    msh_TetMeshSetParami(tetmesh, VIS_MESH_MAXI, maxi);
    msh_TetMeshSetParamd(tetmesh, VIS_MESH_EDGELENGTH, .5);

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
    printf(" Number of tets = %d\n", numel);

    /* write generated tet mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connecttet, SYS_NASTRAN_BULKDATA, "exam45_tet.bdf");

    /* print node information */
    printf("Node information\n");
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connecttet, 1, &i, (Vdouble(*)[3])x);
        printf("id= %d  x= %e, y= %e, z= %e\n", i, x[0], x[1], x[2]);
    }
    /* node associations */
    for (i = 1; i <= numnp; i++) {
        vis_ConnectAllNodeAssoc(connecttet, VIS_GEOVERT, i, &num, aids);
        for (j = 0; j < num; j++) {
            if (aids[j] == 0)
                continue;
            printf("id= %d, VIS_GEOVERT[%d]= %d\n", i, j, aids[j]);
        }
    }
    /* print element information */
    printf("Element information\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connecttet, i, &nix, ix);
        printf("id= %d  ix=", i);
        for (j = 0; j < nix; j++) {
            printf(" %d", ix[j]);
        }
        printf("\n");
    }
    /* element associations */
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemAssoc(connecttet, VIS_GEOBODY, 1, &i, &aid);
        if (aid == 0)
            continue;
        printf("id= %d, VIS_GEOBODY= %d\n", i, aid);
    }
    /* element entity associations */
    for (i = 1; i <= numel; i++) {
        /* tet edges */
        for (j = 1; j <= 6; j++) {
            vis_ConnectAllElemEntAssoc(connecttet, VIS_GEOEDGE, SYS_EDGE, i, j, &num, aids);
            for (k = 0; k < num; k++) {
                if (aids[k] == 0)
                    continue;
                printf("id= %d edge= %d, VIS_GEOEDGE[%d]= %d\n", i, j, k, aids[k]);
            }
        }
        /* tet faces */
        for (j = 1; j <= 4; j++) {
            vis_ConnectElemEntAssoc(connecttet, VIS_GEOFACE, SYS_FACE, i, j, &aid);
            if (aid == 0)
                continue;
            printf("id= %d face= %d, VIS_GEOFACE= %d\n", i, j, aid);
        }
    }
    /* end objects */
    vis_ConnectEnd(connectsurf);
    vis_ConnectEnd(connecttet);
    msh_SurfMeshEnd(surfmesh);
    msh_TetMeshEnd(tetmesh);
    return 0;
}
