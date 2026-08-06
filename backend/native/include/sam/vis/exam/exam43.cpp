#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_NODE 12
#define MAX_LINE 16

/* a square with a rectangular hole and fixed edge */
static Vdouble coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},  {.3, .3, 0.},   {.7, .3, 0.},
                                      {.3, .7, 0.}, {.7, .7, 0.}, {.8, .8, 0.}, {.91, .9, 0.}, {.15, .15, 0.}, {.85, .15, 0.}};

/* boundary lines */
static Vint lines[MAX_LINE][2] = {{1, 2},
                                  {2, 4},
                                  {4, 3},
                                  {3, 1},
                                  {5, 7},
                                  {7, 8},
                                  {8, 6},
                                  {6, 5},
                                  {11, 5},
                                  {5, 11},
                                  {12, 6},
                                  {6, 12},
                                  {11, 12},
                                  {12, 11},
                                  /* interior edge */
                                  {9, 10},
                                  {10, 9}};

/*----------------------------------------------------------------------
                      Generate a 2D Planar Tri Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_TriMesh* trimesh;
    vis_Connect* connect;

    Vint i, k;
    Vint numnp, numel;
    Vdouble x[3];
    Vint nix, ix[6];
    Vint aid, num, aids[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create trimesh object */
    trimesh = msh_TriMeshBegin();
    msh_TriMeshDef(trimesh, MAX_NODE, MAX_LINE, 2);

    /* create connect object to receive mesh */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* define nodes */
    for (i = 0; i < MAX_NODE; i++) {
        msh_TriMeshSetNode(trimesh, i + 1, coords[i]);
    }
    /* define lines */
    for (i = 0; i < MAX_LINE; i++) {
        msh_TriMeshSetLine(trimesh, i + 1, lines[i]);
    }
    /* set line 16 as an undivided edge */
    msh_TriMeshSetLineStat(trimesh, 16, 0);

    /* tag the first line segment */
    msh_TriMeshSetLineAssoc(trimesh, VIS_MISCID, 1, SYS_EDGE, 1001);
    /* elements inside region with boundary edge 10 or 13 */
    msh_TriMeshSetLineAssoc(trimesh, VIS_MISCID1, 10, SYS_ELEM, 2000);
    msh_TriMeshSetLineAssoc(trimesh, VIS_MISCID1, 10, SYS_ELEM, 2002);
    msh_TriMeshSetLineAssoc(trimesh, VIS_MISCID1, 13, SYS_ELEM, 2001);
    /* tag the first node */
    msh_TriMeshSetNodeAssoc(trimesh, VIS_MISCID2, 1, 1002);

    /* generate quadratic elements */
    msh_TriMeshSetParami(trimesh, VIS_MESH_MAXI, 3);
    msh_TriMeshSetParami(trimesh, TRIMESH_SMOOTH, 1);

    /* set mesh size */
    msh_TriMeshSetParamd(trimesh, VIS_MESH_EDGELENGTH, .1);

    /* refine about node 1 */
    msh_TriMeshSetNodeSizing(trimesh, 1, .02);

    msh_TriMeshWrite(trimesh, SYS_ASCII, "exam43.tri");
    /* generate */
    msh_TriMeshGenerate(trimesh, connect);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);

    /* print node information */
    /* check for nodes generated on tagged line segment */
    printf("Node information\n");
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, (Vdouble(*)[3])x);
        printf("id= %d  x= %13.10f, y= %13.10f, z= %13.10f\n", i, x[0], x[1], x[2]);
        vis_ConnectNodeAssoc(connect, VIS_MISCID2, 1, &i, &aid);
        if (aid) {
            printf("   VIS_MISCID2= %d\n", aid);
        }
    }
    /* print element information */
    printf("Element information\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        printf("id= %d  ix= %d %d %d %d %d %d\n", i, ix[0], ix[1], ix[2], ix[3], ix[4], ix[5]);
        for (k = 1; k <= 3; k++) {
            vis_ConnectElemEntAssoc(connect, VIS_MISCID, SYS_EDGE, i, k, &aid);
            if (aid) {
                printf(" edge %d,   VIS_MISCID= %d\n", k, aid);
            }
        }
        vis_ConnectAllElemAssoc(connect, VIS_MISCID1, i, &num, aids);
        for (k = 0; k < num; k++) {
            if (aids[k]) {
                printf(" elem,   VIS_MISCID1= %d\n", aids[k]);
            }
        }
    }
    /* write out NASTRAN bulk data file */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam43.bdf");

    /* end objects */
    vis_ConnectEnd(connect);
    msh_TriMeshEnd(trimesh);
    return 0;
}
