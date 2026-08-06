#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vdouble coords[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                               {0., 0., 1.}, {1., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}};

static Vint tris[12][3] = {{1, 5, 3}, {3, 5, 7}, {4, 6, 2}, {8, 6, 4}, {1, 2, 5}, {5, 2, 6},
                           {7, 4, 3}, {8, 4, 7}, {1, 4, 2}, {4, 1, 3}, {5, 8, 7}, {5, 6, 8}};

/*----------------------------------------------------------------------
                      Generate a 3D Volume Tet Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_TetMesh* tetmesh;
    vis_Connect* connect;
    vis_State* state;

    Vint i, j;
    Vint numnp, numel;
    Vdouble x[3], v;
    Vint nix, ix[4];
    Vint num, aid, aids[10];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create tetmesh object */
    tetmesh = msh_TetMeshBegin();
    msh_TetMeshDef(tetmesh, 8, 12, 2);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* define nodes */
    for (i = 0; i < 8; i++) {
        msh_TetMeshSetNode(tetmesh, i + 1, coords[i]);
    }
    /* define tris */
    for (i = 0; i < 12; i++) {
        msh_TetMeshSetTri(tetmesh, i + 1, tris[i]);
    }
    /* define a node association on node 2 */
    msh_TetMeshSetNodeAssoc(tetmesh, VIS_GEOVERT, 2, 1000);
    /* define an element edge association on tri 4, edge 2 */
    msh_TetMeshSetTriAssoc(tetmesh, VIS_GEOEDGE, 4, SYS_EDGE, 2, 10);
    /* define an element face association on tri 3 */
    msh_TetMeshSetTriAssoc(tetmesh, VIS_GEOFACE, 3, SYS_FACE, 1, 100);

    msh_TetMeshWrite(tetmesh, SYS_ASCII, "exam44b.tet");
    /* generate */
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
    /* node associations */
    for (i = 1; i <= numnp; i++) {
        vis_ConnectAllNodeAssoc(connect, VIS_GEOVERT, i, &num, aids);
        for (j = 0; j < num; j++) {
            if (aids[j] == 0)
                continue;
            printf("id= %d  aid[%d]= %d\n", i, j, aids[j]);
        }
    }
    /* print element information */
    printf("Element information\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        printf("id= %d  ix= %d %d %d %d\n", i, ix[0], ix[1], ix[2], ix[3]);
    }
    /* element entity associations */
    for (i = 1; i <= numel; i++) {
        /* tet edges */
        for (j = 1; j <= 6; j++) {
            vis_ConnectElemEntAssoc(connect, VIS_GEOEDGE, SYS_EDGE, i, j, &aid);
            if (aid == 0)
                continue;
            printf("id= %d edge= %d, aid= %d\n", i, j, aid);
        }
        /* tet faces */
        for (j = 1; j <= 4; j++) {
            vis_ConnectElemEntAssoc(connect, VIS_GEOFACE, SYS_FACE, i, j, &aid);
            if (aid == 0)
                continue;
            printf("id= %d face= %d, aid= %d\n", i, j, aid);
        }
    }
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam44b.bdf");

    state = vis_StateBegin();
    vis_StateDef(state, numel, SYS_ELEM, SYS_NONE, VIS_SCALAR);
    for (i = 1; i <= numel; ++i) {
        v = .5;
        vis_StateSetDatadv(state, i, &v);
    }
    vis_StateWrite(state, NULL, SYS_ASCII, "exam44b.tet.sta1");
    vis_ConnectDef(connect, 0, 0);
    msh_TetMeshRefine(tetmesh, state, connect);
    vis_StateEnd(state);
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam44b.ref.bdf");

    /* end objects */
    vis_ConnectEnd(connect);
    msh_TetMeshEnd(tetmesh);
    return 0;
}
