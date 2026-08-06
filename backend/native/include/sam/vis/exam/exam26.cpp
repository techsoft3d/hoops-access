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

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {3., 0., 0.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 0.}, {3., 1., 0.}, {0., 0., 1.}, {1., 0., 1.},
                                     {2., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}, {2., 1., 1.}};

/* element tensor data */
static Vfloat selem[3][6] = {
{1.f, -2.f, 3.f, .1f, .2f, .3f}, {1.2f, -2.1f, 3.5f, .12f, .21f, .31f}, {1.3f, -2.2f, 3.4f, .13f, .24f, .33f}};

void
print_nodestate(vis_State* state, const Vchar* stg);

/*----------------------------------------------------------------------
                      Element and Node Tensor Data
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_State *stateelem, *statenode, *stateelemnode;
    vis_GridFun* gf;

    Vint i;
    Vfloat s[6], tm[3][3];
    Vfloat extent[2][6];
    Vint ids[2][6], nos[2][6];
    Vfloat se[8];

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

    /* create state object for element data */
    stateelem = vis_StateBegin();
    vis_StateDef(stateelem, MAX_ELEM, SYS_ELEM, SYS_NONE, VIS_TENSOR);
    vis_StateSetObject(stateelem, VIS_GRIDFUN, gf);

    /* create state object for node data */
    statenode = vis_StateBegin();
    vis_StateDef(statenode, MAX_NODE, SYS_NODE, SYS_NONE, VIS_TENSOR);

    /* load element tensor */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_StateSetData(stateelem, i + 1, selem[i]);
    }
    /* compute principal values and directions */
    vis_StateSetDerive(stateelem, VIS_TENSOR_PRINC);
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_StateData(stateelem, 1, &i, s);
        printf("elem= %d, principal stresses= %f %f %f\n", i, s[0], s[1], s[2]);
    }
    vis_StateSetDerive(stateelem, VIS_TENSOR_PRINCDIRCOS);
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_StateData(stateelem, 1, &i, (Vfloat*)tm);
        printf("elem= %d, principal vector 1= %f %f %f\n", i, tm[0][0], tm[0][1], tm[0][2]);
        printf("elem= %d, principal vector 2= %f %f %f\n", i, tm[1][0], tm[1][1], tm[1][2]);
        printf("elem= %d, principal vector 3= %f %f %f\n", i, tm[2][0], tm[2][1], tm[2][2]);
    }
    /* set derived quantity back to full tensor */
    vis_StateSetDerive(stateelem, VIS_TENSOR);

    /* map element data to nodes */
    vis_StateMap(statenode, stateelem, NULL);

    /* set derived quantity to Von Mises stress */
    vis_StateSetDerive(statenode, VIS_TENSOR_VONMISES);

    /* query for Von Mises stress at nodes */
    for (i = 1; i <= MAX_NODE; i++) {
        vis_StateData(statenode, 1, &i, s);
        printf("node= %d, Von Mises stress= %f\n", i, s[0]);
    }
    /* create state object for element node data */
    stateelemnode = vis_StateBegin();
    vis_StateDef(stateelemnode, MAX_ELEM, SYS_ELEM, SYS_NODE, VIS_TENSOR);
    vis_StateSetObject(stateelemnode, VIS_GRIDFUN, gf);

    /* map node data to element nodes */
    vis_StateSetDerive(statenode, VIS_TENSOR);
    vis_StateMap(stateelemnode, statenode, NULL);

    /* find extremes and locations */
    vis_StateExtentLoc(stateelemnode, NULL, (Vfloat*)extent, (Vint*)ids, (Vint*)nos);
    for (i = 0; i < 6; i++) {
        printf("min= %f ids= %d nos= %d, max= %f ids= %d nos= %d\n", extent[0][i], ids[0][i], nos[0][i], extent[1][i], ids[1][i],
               nos[1][i]);
    }
    /* gather element face from node state */
    vis_StateSetObject(statenode, VIS_GRIDFUN, gf);
    vis_StateSetDerive(statenode, VIS_TENSOR_VONMISES);
    vis_StateDataElemEnt(statenode, SYS_FACE, 1, 2, se);
    printf("Element 1, face 2 from node state\n");
    for (i = 0; i < 4; i++) {
        printf("Von Mises stress= %f\n", se[i]);
    }
    /* gather element face from element node state */
    vis_StateSetDerive(stateelemnode, VIS_TENSOR_VONMISES);
    vis_StateDataElemEnt(stateelemnode, SYS_FACE, 1, 2, se);
    printf("Element 1, face 2 from element node state\n");
    for (i = 0; i < 4; i++) {
        printf("Von Mises stress= %f\n", se[i]);
    }
    /* now test some different node mapping options */
    vis_StateSetDerive(statenode, VIS_TENSOR);

    /* strict minimum */
    vis_StateSetParami(statenode, STATE_MAPNODE, STATE_MAPMIN);
    vis_StateMap(statenode, stateelem, NULL);
    print_nodestate(statenode, "Map Minimum");

    /* minimum based on absolute value */
    vis_StateSetParami(statenode, STATE_MAPNODE, STATE_MAPABSMIN);
    vis_StateMap(statenode, stateelem, NULL);
    print_nodestate(statenode, "Map Absolute Value Minimum");

    /* strict maximum */
    vis_StateSetParami(statenode, STATE_MAPNODE, STATE_MAPMAX);
    vis_StateMap(statenode, stateelem, NULL);
    print_nodestate(statenode, "Map Maximum");

    /* maximum based on absolute value */
    vis_StateSetParami(statenode, STATE_MAPNODE, STATE_MAPABSMAX);
    vis_StateMap(statenode, stateelem, NULL);
    print_nodestate(statenode, "Map Absolute Value Maximum");

    /* min-max difference */
    vis_StateSetParami(statenode, STATE_MAPNODE, STATE_MAPDIFF);
    vis_StateMap(statenode, stateelem, NULL);
    print_nodestate(statenode, "Map Difference");

    /* end objects */
    vis_ConnectEnd(connect);
    vis_StateEnd(stateelem);
    vis_StateEnd(statenode);
    vis_StateEnd(stateelemnode);
    vis_GridFunEnd(gf);
    return 0;
}

void
print_nodestate(vis_State* state, const Vchar* stg)
{
    Vint i;
    Vfloat s[6];

    printf("%s\n", stg);
    for (i = 1; i <= MAX_NODE; i++) {
        vis_StateData(state, 1, &i, s);
        printf("node= %2d, sxx= %10f,  syy= %10f,  szz= %10f\n", i, s[0], s[1], s[2]);
        printf("          sxy= %10f,  syz= %10f,  szx= %10f\n", s[3], s[4], s[5]);
    }
}
