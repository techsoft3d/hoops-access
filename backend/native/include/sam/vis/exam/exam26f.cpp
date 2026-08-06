#include <stdio.h>
#include <math.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*
    7-----8-----9
    |           | \
    |           |  12
    |           |   \
    4     5     6    11
    |           |   /
    |           |  10
    |           | /
    1-----2-----3
*/
#define MAX_ELEM 2
#define MAX_NODE 12

static Vint shap[MAX_ELEM] = {VIS_SHAPEQUAD, VIS_SHAPETRI};
static Vint topo[MAX_ELEM][2] = {{3, 3}, {3, 0}};
static Vint conn[MAX_ELEM][9] = {{1, 2, 3, 4, 5, 6, 7, 8, 9}, {3, 11, 9, 10, 12, 6, 0, 0, 0}};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {0., 1., 0.},  {1., 1., 0.}, {2., 1., 0.},
                                     {0., 2., 0.}, {1., 2., 0.}, {2., 2., 0.}, {2.5, .5, 0.}, {3., 1., 0.}, {2.5, 1.5, 0.}};

/*----------------------------------------------------------------------
                      Element and Node Tensor Data
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_State *state, *statee;
    vis_GridFun* gf;
    Vint i, j;
    Vfloat d, s[9];
    Vint ndat, nloc, nsec;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set topology and element node connectivity */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], topo[i][0], topo[i][1], 0);
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
    }
    /* set node coordinates */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }
    /* create a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* create node state object for original raw data */
    state = vis_StateBegin();
    vis_StateDef(state, MAX_NODE, SYS_NODE, SYS_NONE, VIS_SCALAR);
    vis_StateSetObject(state, VIS_GRIDFUN, gf);

    /* fill state with distance from origin */
    for (i = 1; i <= MAX_NODE; i++) {
        d = (Vfloat)sqrt(coords[i - 1][0] * coords[i - 1][0] + coords[i - 1][1] * coords[i - 1][1] +
                         coords[i - 1][2] * coords[i - 1][2]);
        vis_StateSetData(state, i, &d);
    }
    /* data */
    printf("Original distance, node state\n");
    for (i = 1; i <= MAX_NODE; i++) {
        vis_StateData(state, 1, &i, s);
        printf("node= %d, s= %f\n", i, s[0]);
    }
    /* create elem state */
    statee = vis_StateBegin();
    vis_StateDef(statee, MAX_ELEM, SYS_ELEM, SYS_NODE, VIS_SCALAR);
    vis_StateSetObject(statee, VIS_GRIDFUN, gf);

    /* map to element state */
    vis_StateMap(statee, state, NULL);

    /* linearize midside data */
    vis_StateMidside(state, NULL);
    printf("Linearized midsides, node state\n");
    for (i = 1; i <= MAX_NODE; i++) {
        vis_StateData(state, 1, &i, s);
        printf("node= %d, s= %f\n", i, s[0]);
    }

    vis_StateMidside(statee, NULL);
    printf("Linearized midsides, elem state\n");
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_StateDataNum(statee, i, &ndat, &nloc, &nsec);
        vis_StateData(statee, 1, &i, s);
        for (j = 1; j <= nloc; j++) {
            printf("elem= %d, node= %d, s= %f\n", i, j, s[j - 1]);
        }
    }
    /* end objects */
    vis_ConnectEnd(connect);
    vis_StateEnd(state);
    vis_StateEnd(statee);
    vis_GridFunEnd(gf);
    return 0;
}
