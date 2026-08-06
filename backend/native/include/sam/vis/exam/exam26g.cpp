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

static Vint numeip[MAX_ELEM] = {8, 1, 4};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {3., 0., 0.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 0.}, {3., 1., 0.}, {0., 0., 1.}, {1., 0., 1.},
                                     {2., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}, {2., 1., 1.}};

/*----------------------------------------------------------------------
                      Element Integration Point Tensor Data
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_State* stateeip;
    vis_GridFun* gf;

    Vint i, j;
    Vint in, ind;
    Vfloat s[8 * 3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set topologies */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], 2, 0, 0);
        vis_ConnectSetNumEIP(connect, i + 1, numeip[i]);
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

    /* create state object for element integration point data */
    stateeip = vis_StateBegin();
    vis_StateDef(stateeip, MAX_ELEM, SYS_ELEM, SYS_INTPNT, VIS_VECTOR);
    vis_StateSetObject(stateeip, VIS_GRIDFUN, gf);

    /* load element int. pnt. vector, use node coordinates */
    /* the number of eips in this case just happens to
       be <= number of element nodes */
    for (i = 0; i < MAX_ELEM; i++) {
        ind = 0;
        for (j = 0; j < numeip[i]; j++) {
            in = conn[i][j] - 1;
            s[ind++] = coords[in][0];
            s[ind++] = coords[in][1];
            s[ind++] = coords[in][2];
        }
        vis_StateSetData(stateeip, i + 1, s);
    }
    /* compute magnitudes */
    vis_StateSetDerive(stateeip, VIS_VECTOR_MAG);
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_StateData(stateeip, 1, &i, s);
        for (j = 0; j < numeip[i - 1]; j++) {
            printf("elem= %d, magnitude= %f\n", i, s[j]);
        }
    }
    /* end objects */
    vis_ConnectEnd(connect);
    vis_StateEnd(stateeip);
    vis_GridFunEnd(gf);
    return 0;
}
