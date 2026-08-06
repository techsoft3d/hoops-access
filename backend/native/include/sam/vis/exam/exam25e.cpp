
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_ELEM 3
#define MAX_NODE 14
/* element model data */
static Vint conn[MAX_ELEM][8] = {{1, 2, 6, 5, 9, 10, 13, 12}, {2, 3, 7, 6, 10, 11, 14, 13}, {3, 4, 8, 7, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD};
/* number of sections */
static Vint nsec[MAX_ELEM] = {1, 1, 2};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {3., 0., 0.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 0.}, {3., 1., 0.}, {0., 0., 1.}, {1., 0., 1.},
                                     {2., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}, {2., 1., 1.}};

/* solid element tensor data */
static Vfloat selemx[2][6] = {{1., -2.f, 3., .1f, .2f, .3f}, {1.2f, -2.1f, 3.5f, .12f, .21f, .31f}};
/* shell element tensor data */
static Vfloat selemy[2][6] = {{11.f, -12.f, 13.f, 1.1f, 1.2f, 1.3f}, {11.2f, -12.1f, 13.5f, 1.12f, 1.21f, 1.31f}};

/*----------------------------------------------------------------------
                      Combine two State objects into one State
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_State* state;
    vis_State *statex, *statey;
    vis_GridFun* gf;

    Vint i = 0;
    Vint statx = 0, staty = 0;
    Vint nsect = 0, laypos = 0;
    Vint lay[2], pos[2];
    Vfloat s[2 * 6];

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
    /* create a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* create separate state objects for solids and shells */
    statex = vis_StateBegin();
    vis_StateDef(statex, MAX_ELEM, SYS_ELEM, SYS_NONE, VIS_TENSOR);
    vis_StateSetObject(statex, VIS_GRIDFUN, gf);
    statey = vis_StateBegin();
    vis_StateDef(statey, MAX_ELEM, SYS_ELEM, SYS_NONE, VIS_TENSOR);
    vis_StateSetObject(statey, VIS_GRIDFUN, gf);

    /* create final combined state object */
    state = vis_StateBegin();
    vis_StateDef(state, MAX_ELEM, SYS_ELEM, SYS_NONE, VIS_TENSOR);
    vis_StateSetObject(state, VIS_GRIDFUN, gf);

    /* load data */
    /* set number of sections */
    for (i = 1; i <= MAX_ELEM; i++) {
        if (shap[i - 1] == VIS_SHAPEHEX) {
            vis_StateSetDataSect(statex, i, nsec[i - 1]);
        }
        else {
            vis_StateSetDataSect(statey, i, nsec[i - 1]);
        }
    }
    /* set tensor data */
    for (i = 1; i <= MAX_ELEM; i++) {
        if (shap[i - 1] == VIS_SHAPEHEX) {
            vis_StateSetData(statex, i, selemx[i - 1]);
        }
        else {
            vis_StateSetData(statey, i, (Vfloat*)selemy);
        }
    }
    vis_StateSetSection(statex, 0);
    vis_StateSetSection(statey, 0);

    /* now perform general combine */
    /* first set sections */
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_StateDataStat(statex, 1, &i, &statx);
        /* data from x state */
        if (statx) {
            vis_StateDataSect(statex, 1, &i, &nsect);
            vis_StateDataLayPos(statex, 1, &i, &laypos);
        }
        /* no data from x state test y state */
        if (statx == 0) {
            vis_StateDataStat(statey, 1, &i, &staty);
            if (staty) {
                vis_StateDataSect(statey, 1, &i, &nsect);
                vis_StateDataLayPos(statey, 1, &i, &laypos);
            }
        }
        if (statx || staty) {
            vis_StateSetDataSect(state, i, nsect);
            vis_StateSetDataLayPos(state, i, laypos);
        }
    }
    /* second set layer position information and data */
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_StateDataStat(statex, 1, &i, &statx);
        if (statx) {
            vis_StateData(statex, 1, &i, s);
            vis_StateDataLayers(statex, i, pos, lay);
        }
        if (statx == 0) {
            vis_StateDataStat(statey, 1, &i, &staty);
            if (staty) {
                vis_StateData(statey, 1, &i, s);
                vis_StateDataLayers(statey, i, pos, lay);
            }
        }
        if (statx || staty) {
            vis_StateSetData(state, i, s);
            vis_StateSetDataLayers(state, i, pos, lay);
        }
    }
    vis_StateSetSection(state, 0);
    vis_StatePrint(state);

    /* end objects */
    vis_ConnectEnd(connect);
    vis_StateEnd(state);
    vis_StateEnd(statex);
    vis_StateEnd(statey);
    vis_GridFunEnd(gf);
    return 0;
}
