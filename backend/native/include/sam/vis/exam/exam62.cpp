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
           /|  9      /|  10
          / 8 .      / 6 /
         /  |.      /  |/
        /   5....5./...6
      11---------12   /
       |  .      |   /
       | .       |  /
       |.        | /
       9---------10

           node numbers 1 through 12 shown on corners
           edge numbers 1 through 12 shown on edge midsides
           edges 13 through 18 not shown
           faces are 1(-z), 2(+z) 3(-y) 4(+y) 5(-x) 6(+x)
           faces 7 through 12 not shown

           y
           |
           +-- x
          /
         z
*/

/* a 1 by 1 by 2 cube */
static Vdouble xc[12][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.}, {0., 0., 1.}, {1., 0., 1.},
                            {0., 1., 1.}, {1., 1., 1.}, {0., 0., 2.}, {1., 0., 2.}, {0., 1., 2.}, {1., 1., 2.}};

/* triangle connectivity */
static Vint tris[22][3] = {{1, 5, 3},  {3, 5, 7},   {4, 6, 2},   {8, 6, 4},   {1, 2, 5}, {5, 2, 6},
                           {7, 4, 3},  {8, 4, 7},   {1, 4, 2},   {4, 1, 3},   {5, 8, 7}, {5, 6, 8},

                           {5, 9, 7},  {7, 9, 11},  {8, 10, 6},  {12, 10, 8}, {5, 6, 9}, {9, 6, 10},
                           {11, 8, 7}, {12, 8, 11}, {9, 12, 11}, {9, 10, 12}};

/* triangle preserved edge flags */
static Vint tefl[22][3] = {{1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {1, 0, 1}, {1, 0, 1}, {0, 1, 1},
                           {0, 1, 1}, {1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {0, 1, 1}, {1, 1, 0},

                           {1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {1, 0, 1}, {1, 0, 1}, {0, 1, 1},
                           {0, 1, 1}, {1, 0, 1}, {0, 1, 1}, {1, 1, 0}};
/* edge associations */
static Vint ted[22][3] = {{9, 0, 4},  {0, 8, 12}, {0, 10, 2}, {1, 0, 11}, {1, 0, 9}, {0, 10, 5},
                          {0, 3, 12}, {11, 0, 7}, {0, 2, 1},  {0, 4, 3},  {0, 7, 8}, {5, 6, 0},

                          {9, 0, 4},  {0, 8, 12}, {0, 10, 2}, {1, 0, 11}, {1, 0, 9}, {0, 10, 5},
                          {0, 3, 12}, {11, 0, 7}, {0, 7, 8},  {5, 6, 0}};
/* face associations */
static Vint tfa[22] = {5, 5, 6, 6, 3, 3, 4, 4, 1, 1, 2, 2, 11, 11, 9, 9, 10, 10, 7, 7, 8, 8};

/* triangle normals */
/* triangles 13-24, same */
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
                      Generate a Quad Surface Mesh and Tet Volume Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_SurfMesh* surfmesh;
    msh_VolMesh* volmesh;
    vis_Connect *connectsurf, *connectvol;

    Vint i, j;
    Vint shape, maxi;
    Vint numsurfnode, numsurfface;
    Vint numnp, numel;
    Vint aid;
    Vdouble edgelen;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create SurfMesh object */
    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, 12, 22);

    /* create Connect object */
    connectsurf = vis_ConnectBegin();
    vis_ConnectPre(connectsurf, SYS_DOUBLE);
    vis_ConnectDef(connectsurf, 0, 0);

    /* generate linear quad elements on surface */
    maxi = 2;
    shape = VIS_SHAPEQUAD;
    edgelen = .3;
    /* define points */
    for (i = 0; i < 12; i++) {
        msh_SurfMeshSetPoint(surfmesh, i + 1, xc[i], 1);
        /* set VIS_GEOVERT association to the point id */
        msh_SurfMeshSetPointAssoc(surfmesh, VIS_GEOVERT, i + 1, i + 1);
    }
    /* define triangle connectivity */
    for (i = 0; i < 22; i++) {
        msh_SurfMeshSetTri(surfmesh, i + 1, tris[i], tefl[i]);
        msh_SurfMeshSetTriNorm(surfmesh, i + 1, norms[i]);
        for (j = 0; j < 3; j++) {
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOEDGE, i + 1, SYS_EDGE, j + 1, ted[i][j]);
        }
        msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOFACE, i + 1, SYS_FACE, 0, tfa[i]);
    }
    /* set mesh parameters */
    msh_SurfMeshSetParami(surfmesh, SURFMESH_NONMANIFOLD, VIS_ON);
    msh_SurfMeshSetParami(surfmesh, SURFMESH_INTSURFBACK, VIS_ON);
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, maxi);
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_SHAPE, shape);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, edgelen);

    msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam62.srf");
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
    vis_ConnectNumber(connectsurf, SYS_NODE, &numsurfnode);
    vis_ConnectNumber(connectsurf, SYS_ELEM, &numsurfface);
    printf(" Number of nodes= %d\n", numsurfnode);
    printf(" Number of faces= %d\n", numsurfface);

    /* write generated surf mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connectsurf, SYS_NASTRAN_BULKDATA, "exam62_srf.bdf");

    /* create VolMesh object */
    volmesh = msh_VolMeshBegin();
    msh_VolMeshDef(volmesh, numsurfnode, numsurfface);

    /* Fill VolMesh object with generated surface mesh */
    msh_VolMeshConnect(volmesh, connectsurf);

    /* Define fill regions */
    for (i = 1; i <= numsurfface; i++) {
        vis_ConnectElemAssoc(connectsurf, VIS_GEOBODY, 1, &i, &aid);
        if (aid == 1) {
            msh_VolMeshSetFaceFill(volmesh, i, VOLMESH_FILL_TET);
        }
        else if (aid == 2) {
            msh_VolMeshSetFaceFill(volmesh, i, VOLMESH_FILL_BOUNDARY);
        }
    }
    /* set mesh parameters */
    /* generate parabolic tets */
    msh_VolMeshSetParami(volmesh, VIS_MESH_MAXI, 3);
    msh_VolMeshSetParamd(volmesh, VIS_MESH_EDGELENGTH, edgelen);

    /* create Connect object to hold generated vol mesh */
    connectvol = vis_ConnectBegin();
    vis_ConnectPre(connectvol, SYS_DOUBLE);
    vis_ConnectDef(connectvol, 0, 0);

    msh_VolMeshWrite(volmesh, SYS_ASCII, "exam62.vol");
    /* generate mesh */
    msh_VolMeshGenerate(volmesh, connectvol);
    if (msh_VolMeshError(volmesh)) {
        printf("vol mesh generation error\n");
        exit(1);
    }
    else {
        printf("vol mesh generation complete\n");
    }
    /* print number of surface nodes and elements */
    vis_ConnectNumber(connectvol, SYS_NODE, &numnp);
    vis_ConnectNumber(connectvol, SYS_ELEM, &numel);
    printf(" Number of nodes= %d\n", numnp);
    printf(" Number of elems= %d\n", numel);

    /* write generated mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connectvol, SYS_NASTRAN_BULKDATA, "exam62_vol.bdf");

    /* end objects */
    vis_ConnectEnd(connectsurf);
    vis_ConnectEnd(connectvol);
    msh_SurfMeshEnd(surfmesh);
    msh_VolMeshEnd(volmesh);
    return 0;
}
