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
static Vint ncon[MAX_ELEM] = {8, 8, 4};
/* number of sections */
static Vint nsec[MAX_ELEM] = {1, 1, 2};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {3., 0., 0.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 0.}, {3., 1., 0.}, {0., 0., 1.}, {1., 0., 1.},
                                     {2., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}, {2., 1., 1.}};

/* element tensor data */
static Vfloat selem[3][6] = {
{1., -2., 3., .1f, .2f, .3f}, {1.2f, -2.1f, 3.5f, .12f, .21f, .31f}, {1.3f, -2.2f, 3.4f, .13f, .24f, .33f}};

/*----------------------------------------------------------------------
                      Element and Node Complex Tensor Data
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_State *stateelem, *statenode, *stateelemnode;
    vis_GridFun* gf;
    vis_RProp* rprop;

    Vint i, j, k;
    Vint ind, lay[2], pos[2];
    Vfloat d[6], s[8 * 2 * 2 * 6];

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
    vis_ConnectWrite(connect, SYS_SDRC_UNIVERSAL, "exam25d.unv");

    /* create state object for node data */
    statenode = vis_StateBegin();
    vis_StateDef(statenode, MAX_NODE, SYS_NODE, SYS_NONE, VIS_VECTOR);
    /* load node complex translation vector */
    vis_StateSetComplexMode(statenode, SYS_COMPLEX_REALIMAGINARY);
    for (i = 1; i <= MAX_NODE; i++) {
        d[0] = (Vfloat)i;
        d[1] = 10 * d[0];
        d[2] = (Vfloat)(i + 1);
        d[3] = 10 * d[2];
        d[4] = (Vfloat)(i + 2);
        d[5] = 10 * d[4];
        vis_StateSetData(statenode, i, d);
    }
    rprop = vis_RPropBegin();
    vis_RPropDef(rprop, SYS_NODE, SYS_NONE);
    vis_RPropSetType(rprop, SYS_RES_D);
    vis_RPropSetIds(rprop, 1, 1, 0);
    vis_StateWrite(statenode, rprop, SYS_SDRC_UNIVERSAL, "exam25d.unv");

    stateelem = vis_StateBegin();
    vis_StateDef(stateelem, MAX_ELEM, SYS_ELEM, SYS_NONE, VIS_TENSOR);
    vis_StateSetObject(stateelem, VIS_GRIDFUN, gf);
    vis_StateSetComplexMode(stateelem, SYS_COMPLEX_REALIMAGINARY);
    /* set number of sections */
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_StateSetDataSect(stateelem, i, nsec[i - 1]);
    }
    /* set complex tensor data */
    for (i = 1; i <= MAX_ELEM; i++) {
        ind = 0;
        for (j = 0; j < nsec[i - 1]; j++) {
            s[0 + ind] = selem[i - 1][0] + j;
            s[1 + ind] = 10.F * s[0 + ind];
            s[2 + ind] = selem[i - 1][1] + j;
            s[3 + ind] = 10.F * s[2 + ind];
            s[4 + ind] = selem[i - 1][2] + j;
            s[5 + ind] = 10.F * s[4 + ind];
            s[6 + ind] = selem[i - 1][3] + j;
            s[7 + ind] = 10.F * s[6 + ind];
            s[8 + ind] = selem[i - 1][4] + j;
            s[9 + ind] = 10.F * s[8 + ind];
            s[10 + ind] = selem[i - 1][5] + j;
            s[11 + ind] = 10.F * s[10 + ind];
            ind += 12;
        }
        vis_StateSetData(stateelem, i, s);
    }
    vis_StateSetSection(stateelem, 0);
    vis_RPropDef(rprop, SYS_ELEM, SYS_NONE);
    vis_RPropSetType(rprop, SYS_RES_S);
    vis_RPropSetIds(rprop, 1, 1, 0);
    vis_StateWrite(stateelem, rprop, SYS_SDRC_UNIVERSAL, "exam25d.unv");
    /* now set layer positions for shell element id 3 */
    /* call the result strain */
    i = 3;
    pos[0] = SYS_LAYERPOSITION_MID;
    pos[1] = SYS_LAYERPOSITION_MID;
    lay[0] = 1;
    lay[1] = 5;
    vis_StateSetDataLayers(stateelem, i, pos, lay);
    vis_RPropSetType(rprop, SYS_RES_E);
    vis_StateWrite(stateelem, rprop, SYS_SDRC_UNIVERSAL, "exam25d.unv");

    /* create state object for element node data */
    stateelemnode = vis_StateBegin();
    vis_StateDef(stateelemnode, MAX_ELEM, SYS_ELEM, SYS_NODE, VIS_TENSOR);
    vis_StateSetObject(stateelemnode, VIS_GRIDFUN, gf);
    vis_StateSetComplexMode(stateelemnode, SYS_COMPLEX_REALIMAGINARY);
    /* set number of sections */
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_StateSetDataSect(stateelemnode, i, nsec[i - 1]);
    }
    /* set complex tensor data */
    for (i = 1; i <= MAX_ELEM; i++) {
        ind = 0;
        for (j = 0; j < nsec[i - 1]; j++) {
            for (k = 0; k < ncon[i - 1]; k++) {
                s[0 + ind] = selem[i - 1][0] + 100 * j + k;
                s[1 + ind] = 10.F * s[0 + ind];
                s[2 + ind] = selem[i - 1][1] + 100 * j + k;
                s[3 + ind] = 10.F * s[2 + ind];
                s[4 + ind] = selem[i - 1][2] + 100 * j + k;
                s[5 + ind] = 10.F * s[4 + ind];
                s[6 + ind] = selem[i - 1][3] + 100 * j + k;
                s[7 + ind] = 10.F * s[6 + ind];
                s[8 + ind] = selem[i - 1][4] + 100 * j + k;
                s[9 + ind] = 10.F * s[8 + ind];
                s[10 + ind] = selem[i - 1][5] + 100 * j + k;
                s[11 + ind] = 10.F * s[10 + ind];
                ind += 12;
            }
        }
        vis_StateSetData(stateelemnode, i, s);
    }
    vis_StateSetSection(stateelemnode, 0);
    vis_RPropDef(rprop, SYS_ELEM, SYS_NODE);
    vis_RPropSetType(rprop, SYS_RES_S);
    vis_RPropSetIds(rprop, 1, 1, 0);
    vis_StateWrite(stateelemnode, rprop, SYS_SDRC_UNIVERSAL, "exam25d.unv");

    /* end objects */
    vis_ConnectEnd(connect);
    vis_StateEnd(stateelem);
    vis_StateEnd(statenode);
    vis_StateEnd(stateelemnode);
    vis_RPropEnd(rprop);
    vis_GridFunEnd(gf);
    return 0;
}
