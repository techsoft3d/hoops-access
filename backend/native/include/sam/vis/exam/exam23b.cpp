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
            |  . / |  .   |.|      |
           /| .   /| .   /| 3------4
            |. /   |.     |/
          / 9----/10----/11
           . / .  .      .\
         /.  .  /.     /.  \
         . .    .      .    \
        15-----16-----17-----18
*/
#define MAX_ELEM 7
#define MAX_NODE 18

static Vint numconn[MAX_ELEM] = {8, 8, 4, 5, 4, 6, 3};

static Vint conn[MAX_ELEM][8] = {{1, 2, 6, 5, 9, 10, 13, 12},  {2, 3, 7, 6, 10, 11, 14, 13}, {3, 4, 8, 7, 0, 0, 0, 0},
                                 {9, 10, 13, 12, 15, 0, 0, 0}, {10, 15, 16, 13, 0, 0, 0, 0}, {16, 10, 13, 17, 11, 14, 0, 0},
                                 {11, 17, 18, 0, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD, VIS_SHAPEPYR, VIS_SHAPETET, VIS_SHAPEWED, VIS_SHAPETRI};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 1.}, {3., 0., 1.}, {0., 1., 0.}, {1., 1., 0.},
                                     {2., 1., 1.}, {3., 1., 1.}, {0., 0., 2.}, {1., 0., 2.}, {2., 0., 2.}, {0., 1., 2.},
                                     {1., 1., 2.}, {2., 1., 2.}, {0., 0., 3.}, {1., 0., 3.}, {2., 0., 3.}, {3., 0., 3.}};

/*----------------------------------------------------------------------
                      Grid functions for model description
----------------------------------------------------------------------*/
void
exam_Topology(Vobject* obj, Vint id, Vint* shape, Vint* maxi, Vint* maxj, Vint* maxk)
{
    *shape = shap[id - 1];
    *maxi = 2;
    *maxj = 0;
    *maxk = 0;
}

void
exam_MaxElemNode(Vobject* obj, Vint* maxnum)
{
    *maxnum = 8;
}

void
exam_ElemNode(Vobject* obj, Vint id, Vint* nix, Vint ix[])
{
    int i;

    *nix = numconn[id - 1];
    for (i = 0; i < *nix; i++) {
        ix[i] = conn[id - 1][i];
    }
}

void
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
    Vint i, j, k;
    Vint nfaces, nedges, nnodes;
    Vint nix, ix[64];
    Vfloat x[64][3];
    Vint shape, maxi, maxj;

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
    printf("Example 23b, Using Connect with All Element Types\n");
    printf("element - number of faces, edges, nodes\n");
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_ConnectElemNum(connect, SYS_FACE, i, &nfaces);
        vis_ConnectElemNum(connect, SYS_EDGE, i, &nedges);
        vis_ConnectElemNum(connect, SYS_NODE, i, &nnodes);
        printf("%5d              %5d  %5d  %5d\n", i, nfaces, nedges, nnodes);
    }

    printf("element, face, shape, maxi, maxj, face connectivity\n");
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_ConnectElemNum(connect, SYS_FACE, i, &nfaces);
        for (j = 1; j <= nfaces; j++) {
            printf("%5d  %5d", i, j);
            vis_ConnectElemTopo(connect, SYS_FACE, i, j, &shape, &maxi, &maxj);
            printf("  %5d %5d %5d", shape, maxi, maxj);
            vis_ConnectElemCon(connect, SYS_FACE, i, j, &nix, ix);
            for (k = 0; k < nix; k++) {
                printf("%4d", ix[k]);
            }
            printf("\n");
        }
    }
    printf("element, edge, shape, maxi, edge connectivity\n");
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_ConnectElemNum(connect, SYS_EDGE, i, &nedges);
        for (j = 1; j <= nedges; j++) {
            printf("%5d  %5d", i, j);
            vis_ConnectElemTopo(connect, SYS_EDGE, i, j, &shape, &maxi, &maxj);
            printf("  %5d %5d", shape, maxi);
            vis_ConnectElemCon(connect, SYS_EDGE, i, j, &nix, ix);
            for (k = 0; k < nix; k++) {
                printf("%4d", ix[k]);
            }
            printf("\n");
        }
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

    /* element face adjacency query */
    printf("element, face, adjacent element\n");
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_ConnectElemNum(connect, SYS_FACE, i, &nfaces);
        for (j = 1; j <= nfaces; j++) {
            printf("%5d  %5d", i, j);
            vis_ConnectElemAdj(connect, SYS_FACE, i, j, &nix, ix);
            /* test for adjacent element */
            if (nix) {
                printf(" %3d\n", ix[0]);
            }
            else {
                printf("   none\n");
            }
        }
    }
    /* element edge adjacency query */
    printf("element, edge, adjacent element\n");
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_ConnectElemNum(connect, SYS_EDGE, i, &nedges);
        for (j = 1; j <= nedges; j++) {
            printf("%5d  %5d", i, j);
            vis_ConnectElemAdj(connect, SYS_EDGE, i, j, &nix, ix);
            /* test for adjacent element */
            if (nix) {
                for (k = 0; k < nix; k++) {
                    printf(" %3d", ix[k]);
                }
                printf("\n");
            }
            else {
                printf("   none\n");
            }
        }
    }
    /* end objects */
    vis_ConnectEnd(connect);
    vis_GridFunEnd(gf);
    return 0;
}
