#include <stdio.h>
#include <math.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vdouble coords[26][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.}, {0., 0., 1.}, {1., 0., 1.}, {0., 1., 1.},
                                {1., 1., 1.}, {.5, 0., 0.}, {1., .5, 0.}, {.5, 1., 0.}, {0., .5, 0.}, {.5, 0., 1.}, {1., .5, 1.},
                                {.5, 1., 1.}, {0., .5, 1.}, {0., 0., .5}, {1., 0., .5}, {0., 1., .5}, {1., 1., .5}, {.5, .5, 0.},
                                {.5, .5, 1.}, {0., .5, .5}, {1., .5, .5}, {.5, 0., .5}, {.5, 1., .5}};

static Vint tris[12][6] = {{1, 5, 3, 17, 23, 12}, {3, 5, 7, 23, 16, 19}, {4, 6, 2, 24, 18, 10}, {8, 6, 4, 14, 24, 20},
                           {1, 2, 5, 9, 25, 17},  {5, 2, 6, 25, 18, 13}, {7, 4, 3, 26, 11, 19}, {8, 4, 7, 20, 26, 15},
                           {1, 4, 2, 21, 10, 9},  {4, 1, 3, 21, 12, 11}, {5, 8, 7, 22, 15, 16}, {5, 6, 8, 13, 14, 22}};

static Vint maxi = 3;

static Vint eassoc[12][3] = {{1, 0, 2},  {0, 3, 4},  {0, 5, 6}, {7, 0, 8}, {9, 0, 0}, {0, 0, 10},
                             {0, 11, 0}, {0, 0, 12}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

/*----------------------------------------------------------------------
    Generate a Quadratic 3D Volume Tet Mesh and Perform Successive Refinements
----------------------------------------------------------------------*/
int
main()
{
    msh_TetMesh* tetmesh;
    vis_Connect *connect1, *connect2, *connecttmp;
    vis_State* state;
    vis_GridFun* gf;

    Vint i, j, iref;
    Vint numel;
    Vdouble size;
    Vchar buffer[80];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create tetmesh object */
    tetmesh = msh_TetMeshBegin();
    msh_TetMeshDef(tetmesh, 26, 12, maxi);

    /* create connect object */
    connect1 = vis_ConnectBegin();
    vis_ConnectPre(connect1, SYS_DOUBLE);
    vis_ConnectDef(connect1, 0, 0);

    /* define nodes */
    for (i = 0; i < 26; i++) {
        msh_TetMeshSetNode(tetmesh, i + 1, coords[i]);
        /* define a node association on every corner vertex */
        if (i < 8) {
            msh_TetMeshSetNodeAssoc(tetmesh, VIS_GEOVERT, i + 1, i + 1);
        }
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
    msh_TetMeshWrite(tetmesh, SYS_ASCII, "exam44e.tet");
    /* generate */
    msh_TetMeshGenerate(tetmesh, connect1);
    vis_ConnectNumber(connect1, SYS_ELEM, &numel);
    printf("Generated original mesh\n");
    vis_ConnectWrite(connect1, SYS_NASTRAN_BULKDATA, "exam44e_orig.bdf");

    /* create state object with new sizes and refine */
    gf = vis_GridFunBegin();
    state = vis_StateBegin();
    vis_StateSetObject(state, VIS_GRIDFUN, (Vobject*)gf);

    connect2 = vis_ConnectBegin();
    vis_ConnectPre(connect2, SYS_DOUBLE);
    size = 1.;
    for (iref = 0; iref < 3; ++iref) {
        size *= 0.5;
        vis_ConnectGridFun(connect1, gf);
        vis_StatePre(state, SYS_DOUBLE);
        vis_StateDef(state, numel, SYS_ELEM, SYS_NONE, VIS_SCALAR);
        for (i = 1; i <= numel; i++) {
            vis_StateSetDatadv(state, i, &size);
        }
        /* refine mesh */
        vis_ConnectDef(connect2, 0, 0);
        msh_TetMeshRefine(tetmesh, state, connect2);
        printf("Generated refined mesh %d\n", iref + 1);
        sprintf(buffer, "exam44e_ref%d.bdf", iref + 1);
        vis_ConnectWrite(connect2, SYS_NASTRAN_BULKDATA, buffer);
        vis_ConnectNumber(connect2, SYS_ELEM, &numel);

        /* swap connect objects */
        connecttmp = connect1;
        connect1 = connect2;
        connect2 = connecttmp;
    }

    /* end objects */
    vis_ConnectEnd(connect1);
    vis_ConnectEnd(connect2);
    msh_TetMeshEnd(tetmesh);
    vis_StateEnd(state);
    vis_GridFunEnd(gf);
    return 0;
}
