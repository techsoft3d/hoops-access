#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* fixed node points */
static Vdouble coords[25][3] = {{0., 0., 0.},
                                {5., 0., 0.},
                                {0., 3., 0.},
                                {5., 3., 0.},
                                {0., 0., 3.},
                                {5., 0., 3.},
                                {0., 3., 3.},
                                {5., 3., 3.},
                                /* unit cube void */
                                {1., 1., 1.},
                                {2., 1., 1.},
                                {1., 2., 1.},
                                {2., 2., 1.},
                                {1., 1., 2.},
                                {2., 1., 2.},
                                {1., 2., 2.},
                                {2., 2., 2.},
                                /* interior baffle face */
                                {3., 1., 1.},
                                {3., 1., 2.},
                                /* interior edge */
                                {4., 2., 1.},
                                {4., 2., 2.},
                                /* interior point */
                                {3., 2., 1.},
                                /* interior floating face */
                                {3.5, 1., 1.},
                                {3.5, 1., 2.},
                                {4.5, 1., 1.},
                                {4.5, 1., 2.}};

/* surface triangles */
static Vint tris[32][3] = {{1, 5, 3},
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
                           /* unit cube void */
                           {9, 11, 13},
                           {11, 15, 13},
                           {12, 10, 14},
                           {16, 12, 14},
                           {9, 13, 10},
                           {13, 14, 10},
                           {15, 11, 12},
                           {16, 15, 12},
                           {9, 10, 12},
                           {12, 11, 9},
                           {13, 15, 16},
                           {13, 16, 14},
                           /* interior double backed triangles */
                           {14, 18, 10},
                           {14, 10, 18},
                           {10, 18, 17},
                           {10, 17, 18},
                           /* interior double backed floating triangles */
                           {22, 25, 24},
                           {22, 24, 25},
                           {23, 22, 25},
                           {23, 25, 22}};

/* interior edge */
static Vint inedge[2] = {19, 20};

/*----------------------------------------------------------------------
                      monitor function
----------------------------------------------------------------------*/
static void
monitor(msh_TetMesh* tetmesh, Vobject* usrobj)
{
    int iparam[4];

    printf("monitor called\n");
    /* query and print progress */
    msh_TetMeshGetInteger(tetmesh, VIS_MESH_PROGRESS, iparam);
    printf("phase=   %d\n", iparam[0]);
    printf("numnp=   %d\n", iparam[1]);
    printf("numel=   %d\n", iparam[2]);
    printf("percent= %d\n", iparam[3]);
}

/*----------------------------------------------------------------------
                      Generate a 3D Volume Tet Mesh with Interior Features
----------------------------------------------------------------------*/
int
main()
{
    msh_TetMesh* tetmesh;
    vis_Connect* connect;

    Vint i;
    Vint numnode, numtris;
    Vint numnp, numel;
    Vdouble x[3];
    Vint nix, ix[4];

    /* number of nodes */
    numnode = 25;
    /* number of triangles */
    numtris = 32;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create tetmesh object */
    tetmesh = msh_TetMeshBegin();
    msh_TetMeshDef(tetmesh, numnode, numtris, 2);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* define nodes */
    for (i = 0; i < numnode; i++) {
        msh_TetMeshSetNode(tetmesh, i + 1, coords[i]);
    }
    /* define tris */
    for (i = 0; i < numtris; i++) {
        msh_TetMeshSetTri(tetmesh, i + 1, tris[i]);
    }
    /* define interior edge */
    msh_TetMeshSetEdge(tetmesh, 1, inedge);

    /* allow unconnected nodes */
    msh_TetMeshSetParami(tetmesh, TETMESH_UNCONNECT, VIS_ON);

    /* set monitor function */
    msh_TetMeshSetFunction(tetmesh, TETMESH_FUN_MONITOR, (Vfunc*)monitor, NULL);

    /* generate */
    msh_TetMeshWrite(tetmesh, SYS_ASCII, "exam44a.tet");
    msh_TetMeshGenerate(tetmesh, connect);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);

    /* print node information */
    printf("Node information\n");
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, (Vdouble(*)[3])x);
        printf("id= %d  x= %f, y= %f, z= %f\n", i, x[0], x[1], x[2]);
    }
    /* print element information */
    printf("Element information\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        printf("id= %d  ix= %d %d %d %d\n", i, ix[0], ix[1], ix[2], ix[3]);
    }
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam44a.bdf");
    /* end objects */
    vis_ConnectEnd(connect);
    msh_TetMeshEnd(tetmesh);
    return 0;
}
