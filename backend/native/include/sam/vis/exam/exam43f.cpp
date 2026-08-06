#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_NODE 7
#define MAX_LINE 8

/* 2 x 1 rectangle divided in the middle into two regions */
static Vdouble coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                                      {2., 0., 0.}, {2., 1., 0.}, {.5, .5, 0.}};

/* boundary lines of two regions */
static Vint lines[MAX_LINE][2] = {{1, 2}, {2, 4}, {4, 3}, {3, 1}, {2, 5}, {5, 6}, {6, 4}, {4, 2}};

/*----------------------------------------------------------------------
                      Generate a 2D Planar Tri Mesh with Sizing
----------------------------------------------------------------------*/
int
main()
{
    msh_TriMesh* trimesh;
    vis_Connect* connect;
    Vint i;
    Vint numnp, numel;

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
    /* tag the two regions */
    msh_TriMeshSetLineAssoc(trimesh, VIS_GEOBODY, 1, SYS_ELEM, 1);
    msh_TriMeshSetLineAssoc(trimesh, VIS_GEOBODY, 5, SYS_ELEM, 2);

    /* generate quadratic elements */
    msh_TriMeshSetParami(trimesh, VIS_MESH_MAXI, 3);
    msh_TriMeshSetParami(trimesh, TRIMESH_SMOOTH, 1);
    /* allow unconnected node */
    msh_TriMeshSetParami(trimesh, TRIMESH_UNCONNECT, SYS_ON);

    /* set mesh size */
    msh_TriMeshSetParamd(trimesh, VIS_MESH_EDGELENGTH, .2);

    /* refine about node 7 in region 1 */
    msh_TriMeshSetNodeSizing(trimesh, 7, .01);

    /* refine edge 4 in region 1 */
    msh_TriMeshSetLineSizing(trimesh, 4, SYS_EDGE, .05);
    /* refine region 2 */
    msh_TriMeshSetLineSizing(trimesh, 5, SYS_ELEM, .05);

    msh_TriMeshWrite(trimesh, SYS_ASCII, "exam43f.tri");
    /* generate */
    msh_TriMeshGenerate(trimesh, connect);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);

    /* write out NASTRAN bulk data file */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam43f.bdf");

    /* end objects */
    vis_ConnectEnd(connect);
    msh_TriMeshEnd(trimesh);
    return 0;
}
