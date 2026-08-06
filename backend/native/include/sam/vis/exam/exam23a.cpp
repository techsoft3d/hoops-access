#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
/*
                 5------6
                /.     /.\
               / .    / . \
              /  .   /  .  \7------8
             /   1../...2../|      |
           12-----13-----14 |      |
            |  .   |  .   |.|      |
            | .    | .    | 3------4
            |.     |.     |/
            9-----10-----11
*/
#define MAX_ELEM 3
#define MAX_NODE 14

static Vint numconn[MAX_ELEM] = {8, 8, 4};

static Vint conn[MAX_ELEM][8] = {{1, 2, 6, 5, 9, 10, 13, 12}, {2, 3, 7, 6, 10, 11, 14, 13}, {3, 4, 8, 7, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 1.}, {3., 0., 1.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 1.}, {3., 1., 1.}, {0., 0., 2.}, {1., 0., 2.},
                                     {2., 0., 2.}, {0., 1., 2.}, {1., 1., 2.}, {2., 1., 2.}};

/*----------------------------------------------------------------------
                      Grid functions for model description
----------------------------------------------------------------------*/
static void
exam_Topology(Vobject* obj, Vint id, Vint* shape, Vint* maxi, Vint* maxj, Vint* maxk)
{
    *shape = shap[id - 1];
    *maxi = 2;
    *maxj = 0;
    *maxk = 0;
}

static void
exam_MaxElemNode(Vobject* obj, Vint* maxnum)
{
    *maxnum = 8;
}

static void
exam_ElemNode(Vobject* obj, Vint id, Vint* nix, Vint ix[])
{
    int i;

    *nix = numconn[id - 1];
    for (i = 0; i < *nix; i++) {
        ix[i] = conn[id - 1][i];
    }
}

static void
exam_Coords(Vobject* obj, Vint nids, Vint ids[], Vfloat x[][3])
{
    int i;

    for (i = 0; i < nids; i++) {
        x[i][0] = coords[ids[i] - 1][0];
        x[i][1] = coords[ids[i] - 1][1];
        x[i][2] = coords[ids[i] - 1][2];
    }
}

/*----------------------------------------------------------------------
                      Element Connectivity and Adjacency using Connect
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_GridFun* gf;
    Vint i;
    Vint nfaces, nedges, nnodes;
    Vint nix, ix[64];
    Vfloat x[64][3];
    Vint nindices, indices[2];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* create gridfun object */
    gf = vis_GridFunBegin();

    /* register example grid functions */
    vis_GridFunSet(gf, GRIDFUN_TOPOLOGY, (void (*)(void))exam_Topology);
    vis_GridFunSet(gf, GRIDFUN_MAXELEMNODE, (void (*)(void))exam_MaxElemNode);
    vis_GridFunSet(gf, GRIDFUN_ELEMNODE, (void (*)(void))exam_ElemNode);
    vis_GridFunSet(gf, GRIDFUN_COORDS, (void (*)(void))exam_Coords);

    /* set grid function as attribute to connect */
    vis_ConnectSetObject(connect, VIS_GRIDFUN, gf);

    /* print element connection info */
    printf("Example 23a, Using Connect with a GridFun object\n");
    printf("element - number of faces, edges, nodes\n");
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectElemNum(connect, SYS_FACE, i + 1, &nfaces);
        vis_ConnectElemNum(connect, SYS_EDGE, i + 1, &nedges);
        vis_ConnectElemNum(connect, SYS_NODE, i + 1, &nnodes);
        printf("%5d              %5d  %5d  %5d\n", i + 1, nfaces, nedges, nnodes);
    }
    /* node connectivity query for element 1 */
    vis_ConnectElemNode(connect, 1, &nix, ix);
    vis_ConnectCoords(connect, nix, ix, x);
    printf("element node - connected node, coordinates\n");
    for (i = 0; i < nix; i++) {
        printf("%5d                %3d", i + 1, ix[i]);
        printf("       %f  %f  %f\n", x[i][0], x[i][1], x[i][2]);
    }

    /* generate connect kernel */
    vis_ConnectKernel(connect, 0);

    /* element adjacency query for element 1 */
    vis_ConnectElemNum(connect, SYS_FACE, 1, &nfaces);
    printf("element face - adjacent element\n");
    for (i = 0; i < nfaces; i++) {
        vis_ConnectElemAdj(connect, SYS_FACE, 1, i + 1, &nix, ix);
        /* test for adjacent element */
        if (nix) {
            printf("%5d                %3d\n", i + 1, ix[0]);
        }
        else {
            printf("%5d               none\n", i + 1);
        }
    }

    /* query elements connected to both nodes 3 and 11 */
    nindices = 2;
    indices[0] = 3;
    indices[1] = 11;
    vis_ConnectNodeAdj(connect, nindices, indices, &nix, ix);
    printf("adjacent element\n");
    for (i = 0; i < nix; i++) {
        printf("%5d\n", ix[i]);
    }

    /* end objects */
    vis_ConnectEnd(connect);
    vis_GridFunEnd(gf);
    return 0;
}
