#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* example mesh is two bricks and a quad */
#define MAX_ELEM 3
#define MAX_NODE 14

static Vint conn[MAX_ELEM][8] = {{1, 2, 6, 5, 9, 10, 13, 12}, {2, 3, 7, 6, 10, 11, 14, 13}, {3, 4, 8, 7, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {3., 0., 0.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 0.}, {3., 1., 0.}, {0., 0., 1.}, {1., 0., 1.},
                                     {2., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}, {2., 1., 1.}};

static Vfloat scalar_1[MAX_NODE] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0};

/*----------------------------------------------------------------------
                      Perform range searches using a Range object
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_Space* space;
    vis_GridFun* gf;
    vis_Group* group;
    vis_State* state;
    vis_Range* range;

    Vint i;
    Vint flag;
    Vint n;
    Vfloat value;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set topologies */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], 2, 0, 0);
    }
    /* set element node connectivity */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
    }
    /* set node coordinates */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }
    vis_ConnectKernel(connect, 0);

    /* create and load a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* create space object for elements */
    space = vis_SpaceBegin();
    vis_SpaceSetObject(space, VIS_GRIDFUN, gf);

    /* create kernel for entire mesh */
    vis_SpaceKernel(space);

    /* create range object for elements */
    range = vis_RangeBegin();

    /* set grid function and space objects as attributes */
    vis_RangeSetObject(range, VIS_GRIDFUN, gf);
    vis_RangeSetObject(range, VIS_SPACE, space);

    /* create state object to hold data (range information) */
    state = vis_StateBegin();
    vis_StateDef(state, MAX_NODE, SYS_NODE, SYS_NONE, VIS_SCALAR);

    /* load data */
    for (i = 0; i < MAX_NODE; i++) {
        vis_StateSetData(state, i + 1, &scalar_1[i]);
    }

    /* create group object to hold output of queries */
    group = vis_GroupBegin();
    vis_GroupDef(group, MAX_ELEM, SYS_ELEM, SYS_NONE);
    vis_GroupClear(group);

    /* set state object as range 1 */
    vis_RangeSetState(range, 1, state);

    /* get elements which contain a given value */
    value = 10.0;
    vis_RangeSurfGroup(range, 1, value, NULL, group);

    /* print results */
    printf("\n  ------ search elements for value [%f]  ------ \n", value);
    n = 0;
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_GroupGetIndex(group, i, &flag);
        if (flag) {
            n++;
            printf("  element [%d] contains the value. \n", i);
        }
    }
    printf("\n  [%d] elements in group. \n\n", n);

    /* end objects */
    vis_ConnectEnd(connect);
    vis_GridFunEnd(gf);
    vis_SpaceEnd(space);
    vis_RangeEnd(range);
    vis_StateEnd(state);
    vis_GroupEnd(group);
    return 0;
}
