
#include <stdio.h>
#include <math.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define SQUARE_NODE 8
#define SQUARE_LINE 4

/* outside square */
static Vdouble coords[SQUARE_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.},
                                         {.5, 0., 0.}, {1., .5, 0.}, {.5, 1., 0.}, {0., .5, 0.}};

/* square boundary lines */
static Vint lines[SQUARE_LINE][3] = {{1, 5, 2}, {2, 6, 3}, {3, 7, 4}, {4, 8, 1}};

/*----------------------------------------------------------------------
                      Generate a 2D Planar Tri Mesh with Parabolic Lines
----------------------------------------------------------------------*/
int
main()
{
    msh_TriMesh* trimesh;
    vis_Connect* connect;

    Vint i;
    Vint numpts, numlns, lix[3], numcirclelines;
    Vint numnp, numel;
    Vdouble ang, rad, xc[3], x[3];
    Vint nix, ix[6];

    vsy_LicenseValidate(HOOPS_LICENSE);

    numcirclelines = 8;
    numpts = SQUARE_NODE + 2 * numcirclelines;
    numlns = SQUARE_LINE + numcirclelines;
    /* create trimesh object */
    trimesh = msh_TriMeshBegin();
    msh_TriMeshDef(trimesh, numpts, numlns, 3);

    /* create connect object to receive mesh */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* define nodes */
    for (i = 0; i < SQUARE_NODE; i++) {
        msh_TriMeshSetNode(trimesh, i + 1, coords[i]);
    }
    /* generate circle nodes */
    rad = .25;
    ang = 0.;
    xc[0] = .5;
    xc[1] = .5;
    xc[2] = 0.;
    for (i = 0; i < 2 * numcirclelines; i++) {
        x[0] = rad * cos(ang) + xc[0];
        x[1] = rad * sin(ang) + xc[1];
        x[2] = 0. + xc[2];
        ang += 3.14159 / numcirclelines;
        msh_TriMeshSetNode(trimesh, SQUARE_NODE + i + 1, x);
    }
    /* define lines */
    for (i = 0; i < SQUARE_LINE; i++) {
        msh_TriMeshSetLine(trimesh, i + 1, lines[i]);
    }
    /* generate circle lines */
    for (i = 0; i < numcirclelines; i++) {
        if (i == numcirclelines - 1) {
            lix[0] = SQUARE_NODE + 1;
        }
        else {
            lix[0] = SQUARE_NODE + 2 * i + 3;
        }
        lix[1] = SQUARE_NODE + 2 * i + 2;
        lix[2] = SQUARE_NODE + 2 * i + 1;
        msh_TriMeshSetLine(trimesh, SQUARE_LINE + i + 1, lix);
    }
    /* generate quadratic elements */
    msh_TriMeshSetParami(trimesh, VIS_MESH_MAXI, 3);
    msh_TriMeshSetParami(trimesh, TRIMESH_SMOOTH, 1);

    /* set mesh size */
    msh_TriMeshSetParamd(trimesh, VIS_MESH_EDGELENGTH, .05);

    /* write debugging file */
    msh_TriMeshWrite(trimesh, SYS_ASCII, "exam43a.tri");
    /* generate */
    msh_TriMeshGenerate(trimesh, connect);

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
        printf("id= %d  ix= %d %d %d %d %d %d\n", i, ix[0], ix[1], ix[2], ix[3], ix[4], ix[5]);
    }
    /* write out NASTRAN bulk data file */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam43a.bdf");

    /* end objects */
    vis_ConnectEnd(connect);
    msh_TriMeshEnd(trimesh);
    return 0;
}
