#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_NODE 8
#define MAX_LINE 8

/* a square with a rectangular hole */
static Vdouble coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                                      {.2, .2, 0.}, {.8, .2, 0.}, {.2, .8, 0.}, {.8, .8, 0.}};

static Vint lines[MAX_LINE][2] = {{1, 2}, {2, 4}, {4, 3}, {3, 1}, {5, 7}, {7, 8}, {8, 6}, {6, 5}};

/*----------------------------------------------------------------------
                      Refine a 2D Planar Tri Mesh as on Orphan Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_TriMesh* trimesh;
    vis_Connect* connect;
    vis_State* state;

    Vint i;
    Vint numnp, numel;
    Vdouble x[3], v;
    Vint nix, ix[6];

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
    /* generate quadratic elements */
    msh_TriMeshSetParami(trimesh, VIS_MESH_MAXI, 3);
    msh_TriMeshSetParami(trimesh, TRIMESH_SMOOTH, VIS_ON);
    msh_TriMeshSetParamd(trimesh, VIS_MESH_EDGELENGTH, .2);

    /* generate initial mesh */
    msh_TriMeshGenerate(trimesh, connect);
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("Generated original mesh\n");
    printf("numnp= %d\n", numnp);
    printf("numel= %d\n", numel);
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam43e.bdf");

    /* redefine trimesh to setup as taking orphan mesh */
    msh_TriMeshDef(trimesh, numnp, MAX_LINE, 2);
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, &x);
        msh_TriMeshSetNode(trimesh, i, x);
    }
    /* define lines */
    for (i = 0; i < MAX_LINE; i++) {
        msh_TriMeshSetLine(trimesh, i + 1, lines[i]);
    }
    /* set trimesh as background mesh */
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        msh_TriMeshSetElem(trimesh, i, SYS_SHAPETRI, 3, ix);
    }
    /* create State object with new element edge lengths */
    state = vis_StateBegin();
    vis_StateDef(state, numel, SYS_ELEM, SYS_NONE, VIS_SCALAR);
    /* refine elements in upper right corner */
    for (i = 1; i <= numel; ++i) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        vis_ConnectCoordsdv(connect, 1, &ix[0], (Vdouble(*)[3])x);
        if (x[0] >= .8 && x[1] >= .8) {
            v = .1;
            vis_StateSetDatadv(state, i, &v);
        }
    }
    /* clear Connect object */
    vis_ConnectDef(connect, 0, 0);
    /* generate refined mesh */
    msh_TriMeshRefine(trimesh, state, connect);
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam43e_ref.bdf");

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("Generated refined mesh\n");
    printf("numnp= %d\n", numnp);
    printf("numel= %d\n", numel);

    /* print node information */
    /* check for nodes generated on tagged line segment */
    printf("Node information\n");
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, (Vdouble(*)[3])x);
    }
    /* print element information */
    printf("Element information\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        printf("id= %d  ix= %d %d %d %d %d %d\n", i, ix[0], ix[1], ix[2], ix[3], ix[4], ix[5]);
    }

    /* end objects */
    vis_ConnectEnd(connect);
    msh_TriMeshEnd(trimesh);
    vis_StateEnd(state);
    return 0;
}
