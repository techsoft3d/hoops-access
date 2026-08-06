#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_NODE 6
#define MAX_LINE 6

/* a square with a fixed interior edge */
static Vdouble coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.}, {.2, .3, 0.}, {.7, .8, 0.}};

/* boundary lines */
static Vint lines[MAX_LINE][2] = {{1, 2},
                                  {2, 4},
                                  {4, 3},
                                  {3, 1},
                                  /* interior edge */
                                  {5, 6},
                                  {6, 5}};

/*----------------------------------------------------------------------
                      Generate a 2D Planar Quad Surface Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_TriMesh* trimesh;
    vis_Connect *connect, *connectsurf;
    msh_SurfMesh* surfmesh;

    Vint i, j;
    Vint numnp, numel;
    Vdouble x[3];
    Vint nix, ix[6], efl[3];

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
    /* generate boundary triangulation only */
    msh_TriMeshSetParami(trimesh, VIS_MESH_BOUNDREFINE, VIS_OFF);
    msh_TriMeshSetParami(trimesh, VIS_MESH_INTERREFINE, VIS_OFF);
    /* element associations with line flags */
    msh_TriMeshSetParami(trimesh, TRIMESH_LINEFLAG, VIS_MISCID1);

    /* generate */
    msh_TriMeshWrite(trimesh, SYS_ASCII, "exam43c.tri");
    msh_TriMeshGenerate(trimesh, connect);
    /* delete */
    msh_TriMeshEnd(trimesh);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("TriMesh, numnp= %d, numel= %d\n", numnp, numel);

    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, numnp, numel);

    /* create connect object to receive surf mesh */
    connectsurf = vis_ConnectBegin();
    vis_ConnectPre(connectsurf, SYS_DOUBLE);
    vis_ConnectDef(connectsurf, 0, 0);

    /* load nodes and preserve them */
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, (Vdouble(*)[3])x);
        msh_SurfMeshSetPoint(surfmesh, i, x, 1);
    }
    /* load elements */
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        for (j = 0; j < 3; j++) {
            vis_ConnectElemEntAssoc(connect, VIS_MISCID1, SYS_EDGE, i, j + 1, &efl[j]);
        }
        msh_SurfMeshSetTri(surfmesh, i, ix, efl);
    }
    /* delete */
    vis_ConnectEnd(connect);

    /* set mesh parameters */
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 2);
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_SHAPE, VIS_SHAPEQUAD);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, .1);

    /* generate */
    msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam43c.srf");
    msh_SurfMeshGenerate(surfmesh, connectsurf);
    /* print generated nodes and elements */
    vis_ConnectNumber(connectsurf, SYS_NODE, &numnp);
    vis_ConnectNumber(connectsurf, SYS_ELEM, &numel);
    printf("SurfMesh, numnp= %d, numel= %d\n", numnp, numel);

    /* write out NASTRAN bulk data file */
    vis_ConnectWrite(connectsurf, SYS_NASTRAN_BULKDATA, "exam43c.bdf");

    /* end objects */
    vis_ConnectEnd(connectsurf);
    msh_SurfMeshEnd(surfmesh);
    return 0;
}
