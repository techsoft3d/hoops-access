#include <stdio.h>
#include <math.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vdouble coords[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                               {0., 0., 1.}, {1., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}};

static Vint tris[12][3] = {{1, 5, 3}, {3, 5, 7}, {4, 6, 2}, {8, 6, 4}, {1, 2, 5}, {5, 2, 6},
                           {7, 4, 3}, {8, 4, 7}, {1, 4, 2}, {4, 1, 3}, {5, 8, 7}, {5, 6, 8}};

static Vint eassoc[12][3] = {{1, 0, 2},  {0, 3, 4},  {0, 5, 6}, {7, 0, 8}, {9, 0, 0}, {0, 0, 10},
                             {0, 11, 0}, {0, 0, 12}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

static Vint maxi = 2;

/*----------------------------------------------------------------------
      Generate a 3D Volume Tet Mesh and Refine it as an Orphan Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_TetMesh* tetmesh;
    vis_Connect *connect1, *connect2;
    vis_State* state;

    Vint i, j;
    Vint numnp, numel;
    Vdouble x[3], size;
    Vint nix, ix[4];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create tetmesh object */
    tetmesh = msh_TetMeshBegin();
    msh_TetMeshDef(tetmesh, 8, 12, maxi);

    /* create connect object */
    connect1 = vis_ConnectBegin();
    vis_ConnectPre(connect1, SYS_DOUBLE);
    vis_ConnectDef(connect1, 0, 0);

    /* define nodes */
    for (i = 0; i < 8; i++) {
        msh_TetMeshSetNode(tetmesh, i + 1, coords[i]);
        msh_TetMeshSetNodeAssoc(tetmesh, VIS_GEOVERT, i + 1, i + 1);
    }
    /* define tris */
    for (i = 0; i < 12; i++) {
        msh_TetMeshSetTri(tetmesh, i + 1, tris[i]);
        for (j = 0; j < 3; ++j) {
            if (eassoc[i][j]) {
                msh_TetMeshSetTriAssoc(tetmesh, VIS_GEOEDGE, i + 1, SYS_EDGE, j + 1, eassoc[i][j]);
            }
        }
    }
    /* generate */
    msh_TetMeshGenerate(tetmesh, connect1);
    vis_ConnectNumber(connect1, SYS_NODE, &numnp);
    vis_ConnectNumber(connect1, SYS_ELEM, &numel);
    printf("Generated original mesh\n");
    printf("numnp= %d\n", numnp);
    printf("numel= %d\n", numel);
    vis_ConnectWrite(connect1, SYS_NASTRAN_BULKDATA, "exam44c_orig.bdf");

    /* redefine tetmesh to setup as taking orphan mesh */
    msh_TetMeshDef(tetmesh, numnp, 12, maxi);

    /* define nodes */
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect1, 1, &i, &x);
        msh_TetMeshSetNode(tetmesh, i, x);
        msh_TetMeshSetNodeAssoc(tetmesh, VIS_GEOVERT, i, i);
    }
    /* define tris */
    for (i = 0; i < 12; i++) {
        msh_TetMeshSetTri(tetmesh, i + 1, tris[i]);
        for (j = 0; j < 3; ++j) {
            if (eassoc[i][j]) {
                msh_TetMeshSetTriAssoc(tetmesh, VIS_GEOEDGE, i + 1, SYS_EDGE, j + 1, eassoc[i][j]);
            }
        }
    }
    /* set tetmesh as background mesh */
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect1, i, &nix, ix);
        msh_TetMeshSetElem(tetmesh, i, SYS_SHAPETET, maxi, ix);
    }
    /* create state object with new sizes */
    state = vis_StateBegin();
    vis_StatePre(state, SYS_DOUBLE);
    vis_StateDef(state, numel, SYS_ELEM, SYS_NONE, VIS_SCALAR);
    size = 0.25;
    for (i = 1; i <= numel; i++) {
        vis_StateSetDatadv(state, i, &size);
    }
    /* refine mesh */
    connect2 = vis_ConnectBegin();
    vis_ConnectPre(connect2, SYS_DOUBLE);
    vis_ConnectDef(connect2, 0, 0);
    msh_TetMeshRefine(tetmesh, state, connect2);
    vis_ConnectNumber(connect2, SYS_NODE, &numnp);
    vis_ConnectNumber(connect2, SYS_ELEM, &numel);
    printf("Generated refined mesh\n");
    printf("numnp= %d\n", numnp);
    printf("numel= %d\n", numel);
    vis_ConnectWrite(connect2, SYS_NASTRAN_BULKDATA, "exam44c_ref.bdf");

    /* end objects */
    vis_ConnectEnd(connect1);
    vis_ConnectEnd(connect2);
    msh_TetMeshEnd(tetmesh);
    vis_StateEnd(state);
    return 0;
}
