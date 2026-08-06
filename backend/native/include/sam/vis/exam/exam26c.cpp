#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*
    7-----8-----9
    |     |     |
    |  3  |  4  |
    |     |     |
    4-----5-----6
    |     |     |
    |  1  |  2  |
    |     |     |
    1-----2-----3
*/
#define MAX_ELEM 4
#define MAX_NODE 9

static Vint conn[MAX_ELEM][4] = {{1, 2, 5, 4}, {2, 3, 6, 5}, {4, 5, 8, 7}, {5, 6, 9, 8}};
static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                                     {2., 1., 0.}, {0., 2., 0.}, {1., 2., 0.}, {2., 2., 0.}};

/* group 1, elements 1,2;  group 2, elements 3,4 */
static Vint elemgroup[2][2] = {{1, 2}, {3, 4}};

/*----------------------------------------------------------------------
                      Element and Node Tensor Data
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_State *stateraw, *statenode, *stateave;
    vis_GridFun* gf;
    vis_Group* group;

    Vint i, j, k;
    Vint nix, ix[4];
    Vfloat s[4][3];
    Vfloat x[4][3], xc[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set topology and element node connectivity */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, SYS_SHAPEQUAD, 2, 0, 0);
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
    }
    /* set node coordinates */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }
    /* create a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* create state object for original raw data */
    stateraw = vis_StateBegin();
    vis_StateDef(stateraw, MAX_ELEM, SYS_ELEM, SYS_NODE, VIS_VECTOR);
    vis_StateSetObject(stateraw, VIS_GRIDFUN, gf);

    /* fill raw state with element shrink coordinates */
    /* to create a discontinuity across all elements */
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        vis_ConnectCoords(connect, nix, ix, x);
        /* compute element centroid */
        for (k = 0; k < 3; k++) {
            xc[k] = 0.;
            for (j = 0; j < nix; j++) {
                xc[k] += x[j][k];
            }
            xc[k] /= nix;
        }
        /* shrink coordinates toward centroid by 10 percent */
        for (k = 0; k < 3; k++) {
            for (j = 0; j < nix; j++) {
                x[j][k] = x[j][k] - .1F * (x[j][k] - xc[k]);
            }
        }
        vis_StateSetData(stateraw, i, (Vfloat*)x);
    }
    /* print raw element node data */
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_StateData(stateraw, 1, &i, (Vfloat*)s);
        vis_ConnectElemNode(connect, i, &nix, ix);
        printf("raw data\n");
        for (j = 0; j < nix; j++) {
            printf("elem= %d, node=%d, data= %e %e %e\n", i, ix[j], s[j][0], s[j][1], s[j][2]);
        }
    }
    /* create working state object for node data */
    statenode = vis_StateBegin();
    vis_StateDef(statenode, MAX_NODE, SYS_NODE, SYS_NONE, VIS_VECTOR);

    /* create working element group */
    group = vis_GroupBegin();
    vis_GroupDef(group, MAX_ELEM, SYS_ELEM, SYS_NONE);

    /* create state object for final averaged data */
    stateave = vis_StateBegin();
    vis_StateDef(stateave, MAX_ELEM, SYS_ELEM, SYS_NODE, VIS_VECTOR);
    vis_StateSetObject(stateave, VIS_GRIDFUN, gf);

    /* loop through mutually exclusive groups of elements */
    for (j = 0; j < 2; j++) {
        /* fill group with elements */
        vis_GroupClear(group);
        for (i = 0; i < 2; i++) {
            vis_GroupSetIndex(group, elemgroup[j][i], 1);
        }
        /* average data within element group */
        vis_StateMap(statenode, stateraw, group);
        /* distribute averaged node data to element nodes */
        vis_StateMap(stateave, statenode, group);
    }
    /* print averaged element node data */
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_StateData(stateave, 1, &i, (Vfloat*)s);
        vis_ConnectElemNode(connect, i, &nix, ix);
        printf("averaged data\n");
        for (j = 0; j < nix; j++) {
            printf("elem= %d, node=%d, data= %e %e %e\n", i, ix[j], s[j][0], s[j][1], s[j][2]);
        }
    }
    /* end objects */
    vis_ConnectEnd(connect);
    vis_GroupEnd(group);
    vis_StateEnd(stateraw);
    vis_StateEnd(statenode);
    vis_StateEnd(stateave);
    vis_GridFunEnd(gf);
    return 0;
}
