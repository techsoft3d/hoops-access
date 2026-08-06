#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* point coordinates */
static Vdouble xc[12][3] = {
{0.000e+00, 0.000e+00, 0.000e+00}, {0.000e+00, 9.000e-01, 0.000e+00}, {1.333e-02, 9.500e-01, 0.000e+00},
{5.000e-02, 9.866e-01, 0.000e+00}, {1.000e-01, 1.000e+00, 0.000e+00}, {1.000e+00, 1.000e+00, 0.000e+00},
{0.000e+00, 0.000e+00, 1.000e+00}, {0.000e+00, 9.000e-01, 1.000e+00}, {1.333e-02, 9.500e-01, 1.000e+00},
{5.000e-02, 9.866e-01, 1.000e+00}, {1.000e-01, 1.000e+00, 1.000e+00}, {1.000e+00, 1.000e+00, 1.000e+00}};
/* preserved point flags */
static Vint pc[12] = {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1};
/* triangle connectivity */
static Vint tix[10][3] = {{1, 2, 7},  {2, 8, 7},  {2, 3, 8},   {3, 9, 8},  {3, 4, 9},
                          {4, 10, 9}, {4, 5, 10}, {5, 11, 10}, {5, 6, 11}, {6, 12, 11}};
/* triangle preserved edge flags */
static Vint efl[10][3] = {{0, 0, 0}, {1, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
                          {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
/* triangle node normals */
static Vdouble tvn[10][3][3] = {{{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},

                                {{1., 0., 0.}, {.867, -.500, 0.}, {1., 0., 0.}},
                                {{.867, -.500, 0.}, {.867, -.500, 0.}, {1., 0., 0.}},

                                {{.867, -.500, 0.}, {.500, -.867, 0.}, {.867, -.500, 0.}},
                                {{.500, -.867, 0.}, {.500, -.867, 0.}, {.867, -.500, 0.}},

                                {{.500, -.867, 0.}, {0., -1., 0.}, {.500, -.867, 0.}},
                                {{0., -1., 0.}, {0., -1., 0.}, {.500, -.867, 0.}},

                                {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}}};

/* triangle associations */
static Vint tpid[10] = {1, 1, 2, 2, 2, 2, 2, 2, 2, 2};

/*----------------------------------------------------------------------
                      Generate a 3D Surface Mesh with Associations
----------------------------------------------------------------------*/
int
main()
{
    msh_SurfMesh* surfmesh;
    vis_Connect* connect;

    Vint i;
    Vint numnp, numel;
    Vdouble x[3];
    Vint aid, aid1, pid;
    Vint nix, ix[6];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create SurfMesh object */
    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, 12, 10);

    /* create Connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* define points */
    for (i = 0; i < 12; i++) {
        msh_SurfMeshSetPoint(surfmesh, i + 1, xc[i], pc[i]);
    }
    /* set node associations at points 1 and 7 */
    msh_SurfMeshSetPointAssoc(surfmesh, VIS_MISCID1, 1, 1011);
    msh_SurfMeshSetPointAssoc(surfmesh, VIS_MISCID, 7, 1001);

    /* define triangle connectivity, normals and property id */
    for (i = 0; i < 10; i++) {
        msh_SurfMeshSetTri(surfmesh, i + 1, tix[i], efl[i]);
        msh_SurfMeshSetTriNorm(surfmesh, i + 1, tvn[i]);
        msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, i + 1, SYS_ELEM, 0, tpid[i]);
    }
    /* set node associations at triangle edge */
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_MISCID, 2, SYS_EDGE, 1, 1002);

    /* set node associations on triangles */
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_MISCID, 1, SYS_FACE, 0, 1003);
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_MISCID, 2, SYS_FACE, 0, 1003);

    /* set mesh parameters */
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 3);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_SPANANGLE, 60.);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_MINEDGELENGTH, .04);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, .4);

    /* generate */
    msh_SurfMeshGenerate(surfmesh, connect);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);

    /* print node information */
    printf("Node information\n");
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, (Vdouble(*)[3])x);
        vis_ConnectNodeAssoc(connect, VIS_MISCID, 1, &i, &aid);
        vis_ConnectNodeAssoc(connect, VIS_MISCID1, 1, &i, &aid1);
        printf("id= %d  x= %f, y= %f, z= %f,  aid= %d, aid1= %d\n", i, x[0], x[1], x[2], aid, aid1);
    }
    /* print element information */
    printf("Element information\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        vis_ConnectElemAssoc(connect, VIS_PROPID, 1, &i, &pid);
        printf("id= %d  ix= %d %d %d %d %d %d, pid= %d\n", i, ix[0], ix[1], ix[2], ix[3], ix[4], ix[5], pid);
    }
    /* write generated mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam47a.bdf");

    /* end objects */
    vis_ConnectEnd(connect);
    msh_SurfMeshEnd(surfmesh);
    return 0;
}
