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

static Vint nsec[MAX_ELEM] = {1, 1, 2};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {3., 0., 0.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 0.}, {3., 1., 0.}, {0., 0., 1.}, {1., 0., 1.},
                                     {2., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}, {2., 1., 1.}};

/* element tensor data */
static Vfloat selem[4][6] = {{1.f, -2.f, 3.f, .1f, .2f, .3f},       /* element 1 */
                             {1.2f, -2.1f, 3.5f, .12f, .21f, .31f}, /* element 2 */
                             {1.3f, -2.2f, 3.4f, .13f, .24f, .33f}, /* element 3, with 2 section points */
                             {1.4f, -2.3f, 3.5f, .14f, .25f, .34f}};

void
print_nodestate(vis_State* state, const Vchar* stg);
void
print_elemstate(vis_State* state, const Vchar* stg);
void
print_elemsect(Vint nsec, Vfloat s[]);
void
print_elemnodesect(Vint nsec, Vint nix, Vint ix[], Vfloat s[]);

/*----------------------------------------------------------------------
                      Element and Node Tensor Section Data
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_State *stateelem, *statenode, *stateelemnode;
    vis_GridFun* gf;

    Vint i;
    Vfloat s[8 * 2 * 6];
    Vint nsecs;
    Vfloat extent[2][6];
    Vint ids[2][6], nos[2][6], sec[2][6];
    Vint nix, ix[8];
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

    /* specify element sections */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_StateSetDataSect(stateelem, i + 1, nsec[i]);
    }
    /* load element tensor */
    /* the 3rd element will load two tensors */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_StateSetData(stateelem, i + 1, selem[i]);
    }
    /* access data at all sections */
    printf("Access Data\n");
    vis_StateSetSection(stateelem, 0); /* query for all sections */
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_StateData(stateelem, 1, &i, s);
        vis_StateDataSect(stateelem, 1, &i, &nsecs);
        printf("elem= %2d, nsecs= %2d\n", i, nsecs);
        print_elemsect(nsecs, s);
        /* access data as element node */
        vis_ConnectElemNode(connect, i, &nix, ix);
        vis_StateDataElemNode(stateelem, i, nix, ix, s);
        print_elemnodesect(nsecs, nix, ix, s);
    }
    /* set section to 2 */
    /* all subsequent queries are restricted to this section */
    vis_StateSetSection(stateelem, 2);
    /* access data */
    print_elemstate(stateelem, "\nSection 2");

    /* extent */
    printf("\n");
    vis_StateExtent(stateelem, NULL, (Vfloat*)extent);
    for (i = 0; i < 6; i++) {
        printf("min= %f, max= %f\n", extent[0][i], extent[1][i]);
    }
    /* operate unary, double values */
    printf("OperateUnary\n");
    vis_StateOperateUnary(stateelem, STATE_MULTIPLYEQUAL, 2., STATE_UNITY, NULL, NULL);
    /* access data */
    print_elemstate(stateelem, "\nSection 2, doubled");

    /* operate unary, halve values */
    vis_StateSetSection(stateelem, 0);
    vis_StateOperateUnary(stateelem, STATE_MINUSEQUAL, .5, STATE_IDENTITY, stateelem, NULL);
    print_elemstate(stateelem, "\nSection 0, halved");
    vis_StateSetSection(stateelem, 2);
    print_elemstate(stateelem, "\nSection 2, halved");

    /* map element data to nodes */
    printf("Map element data to nodes by averaging\n");
    vis_StateSetSection(stateelem, 1);
    vis_StateMap(statenode, stateelem, NULL);
    for (i = 1; i <= MAX_NODE; i++) {
        vis_StateData(statenode, 1, &i, s);
        print_nodestate(statenode, "\nSection 1, Mapped to nodes");
    }
    /* set derived quantity to Von Mises stress */
    vis_StateSetDerive(statenode, VIS_TENSOR_VONMISES);

    /* query for Von Mises stress at nodes */
    for (i = 1; i <= MAX_NODE; i++) {
        vis_StateData(statenode, 1, &i, s);
        printf("node= %d, Von Mises stress= %f\n", i, s[0]);
    }
    vis_StateSetDerive(statenode, VIS_TENSOR);

    /* create state object for element node data */
    stateelemnode = vis_StateBegin();
    vis_StateDef(stateelemnode, MAX_ELEM, SYS_ELEM, SYS_NODE, VIS_TENSOR);
    vis_StateSetObject(stateelemnode, VIS_GRIDFUN, gf);

    vis_StateSetSection(stateelem, 0);
    /* sum data */
    vis_StateSum(stateelem, NULL, s);
    printf(" Sum\n");
    printf(" sxx= %10f,  syy= %10f,  szz= %10f\n", s[0], s[1], s[2]);
    printf(" sxy= %10f,  syz= %10f,  szx= %10f\n", s[3], s[4], s[5]);

    /* map elem data at all sections to elem nodes */
    printf("Map all data to element nodes\n");
    vis_StateMap(stateelemnode, stateelem, NULL);
    vis_StateSetSection(stateelemnode, 0);

    vis_StateDef(stateelem, MAX_ELEM, SYS_ELEM, SYS_NONE, VIS_TENSOR);
    vis_StateMap(stateelem, stateelemnode, NULL);
    /* access data at all sections */
    printf("\n");
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_StateData(stateelemnode, 1, &i, s);
        vis_StateDataSect(stateelemnode, 1, &i, &nsecs);
        vis_ConnectElemNode(connect, i, &nix, ix);
        printf("elem= %2d, nsecs= %2d\n", i, nsecs);
        print_elemnodesect(nsecs, nix, ix, s);
        /* averaged element data */
        vis_StateDataElem(stateelemnode, i, s);
        print_elemsect(nsecs, s);
    }

    /* find extremes and locations */
    vis_StateExtentLoc(stateelemnode, NULL, (Vfloat*)extent, (Vint*)ids, (Vint*)nos);
    for (i = 0; i < 6; i++) {
        printf("min= %f ids= %d nos= %d, max= %f ids= %d nos= %d\n", extent[0][i], ids[0][i], nos[0][i], extent[1][i], ids[1][i],
               nos[1][i]);
    }
    /* find extremes,locations and sections */
    vis_StateExtentLocSect(stateelemnode, NULL, (Vfloat*)extent, (Vint*)ids, (Vint*)nos, (Vint*)sec);
    for (i = 0; i < 6; i++) {
        printf("min= %f ids= %d nos= %d sec= %d\n", extent[0][i], ids[0][i], nos[0][i], sec[0][i]);
        printf("max= %f ids= %d nos= %d sec= %d\n", extent[1][i], ids[1][i], nos[1][i], sec[1][i]);
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

void
print_elemstate(vis_State* state, const Vchar* stg)
{
    Vint i;
    Vfloat s[8 * 2 * 6];
    Vint nsecs, nvals, nlocs;

    printf("%s\n", stg);
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_StateDataNum(state, i, &nvals, &nlocs, &nsecs);
        if (nvals == 0)
            continue;
        vis_StateData(state, 1, &i, s);
        printf("elem= %2d \n", i);
        printf(" sxx= %10f,  syy= %10f,  szz= %10f\n", s[0], s[1], s[2]);
        printf(" sxy= %10f,  syz= %10f,  szx= %10f\n", s[3], s[4], s[5]);
    }
}

void
print_elemsect(Vint nsecArg, Vfloat s[])
{
    Vint j, n;
    /* loop over sections */
    for (j = 1; j <= nsecArg; j++) {
        printf("section= %2d\n", j);
        n = 6 * (j - 1);
        printf(" sxx= %10f,  syy= %10f,  szz= %10f\n", s[n + 0], s[n + 1], s[n + 2]);
        printf(" sxy= %10f,  syz= %10f,  szx= %10f\n", s[n + 3], s[n + 4], s[n + 5]);
    }
}

void
print_elemnodesect(Vint nsecArg, Vint nix, Vint ix[], Vfloat s[])
{
    Vint j, k, n;
    /* loop over sections */
    for (j = 1; j <= nsecArg; j++) {
        printf("section= %2d\n", j);
        /* loop over nodes */
        for (k = 0; k < nix; k++) {
            printf("node= %2d\n", ix[k]);
            n = 6 * nix * (j - 1) + 6 * k;
            printf(" sxx= %10f,  syy= %10f,  szz= %10f\n", s[n + 0], s[n + 1], s[n + 2]);
            printf(" sxy= %10f,  syz= %10f,  szx= %10f\n", s[n + 3], s[n + 4], s[n + 5]);
        }
    }
}
