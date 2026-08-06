#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
/*
                 5------6
                /.     /.\
  y            / .    / . \
  |           /  .   /  .  \7------8
  --x        /   1../...2. /|      |
 /         12-----13-----14 |      |
z           |  . / |  .   |.|      |
           /| .    | .    | 3------4
            |./    |.     |/
          / 9-----10-----11
           .    /
         /. /
         .
        15
*/
/* These arrays define only the first 3 elements and 14 nodes */
#define MAX_ELEM 3
#define MAX_NODE 14

static Vint conn[MAX_ELEM][8] = {{1, 2, 6, 5, 9, 10, 13, 12}, {2, 3, 7, 6, 10, 11, 14, 13}, {3, 4, 8, 7, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 1.}, {3., 0., 1.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 1.}, {3., 1., 1.}, {0., 0., 2.}, {1., 0., 2.},
                                     {2., 0., 2.}, {0., 1., 2.}, {1., 1., 2.}, {2., 1., 2.}};

static void
connect_print(vis_Connect* connect);

/*----------------------------------------------------------------------
                      Node and Element Insertion and Deletion using Connect
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    Vint i;
    Vint flag;
    Vint numnp, numel;
    Vint nfaces, nedges, nnodes;
    Vint nix, ix[64];
    Vint nindices, indices[2];
    Vfloat x[3];
    Vint nid, eid;

    printf("Example 23d, Using Connect\n");

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);
    /* set mode to dynamic */
    vis_ConnectMode(connect, CONNECT_DYNAMIC);

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
    connect_print(connect);
    /* add a pyramid element */
    /* find a free node index */
    vis_ConnectGenNode(connect, &nid);
    printf("new nid= %d\n", nid);
    x[0] = 0.;
    x[1] = 0.;
    x[2] = 3.;
    vis_ConnectSetCoords(connect, nid, x);
    /* find a free element index */
    vis_ConnectGenElem(connect, &eid);
    printf("new eid= %d\n", eid);
    vis_ConnectSetTopology(connect, eid, VIS_SHAPEPYR, 2, 0, 0);
    ix[0] = 9;
    ix[1] = 10;
    ix[2] = 13;
    ix[3] = 12;
    ix[4] = nid;
    vis_ConnectSetElemNode(connect, eid, ix);
    connect_print(connect);

    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);

    /* delete element 2 */
    printf("delete element 2 and any resulting unattached nodes\n");
    vis_ConnectDelElem(connect, 2);
    /* delete any unattached nodes */
    for (i = 1; i <= numnp; i++) {
        vis_ConnectNumNodeElem(connect, i, &nix);
        if (nix == 0) {
            vis_ConnectDelNode(connect, i);
        }
    }
    connect_print(connect);

    /* print element entity info */
    printf("element - number of faces, edges, nodes\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectIsElem(connect, i, &flag);
        if (flag == 0)
            continue;
        vis_ConnectElemNum(connect, SYS_FACE, i, &nfaces);
        vis_ConnectElemNum(connect, SYS_EDGE, i, &nedges);
        vis_ConnectElemNum(connect, SYS_NODE, i, &nnodes);
        printf("%5d              %5d  %5d  %5d\n", i, nfaces, nedges, nnodes);
    }
    /* element adjacency query for element 1 */
    vis_ConnectElemNum(connect, SYS_FACE, 1, &nfaces);
    printf("element 1 face - adjacent element\n");
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
    /* query elements connected to both nodes 10 and 13 */
    nindices = 2;
    indices[0] = 10;
    indices[1] = 13;
    vis_ConnectNodeAdj(connect, nindices, indices, &nix, ix);
    printf("nodes 10 and 13 adjacent element\n");
    for (i = 0; i < nix; i++) {
        printf("%5d\n", ix[i]);
    }
    /* now ask for 10 available nodes */
    printf("ten available nodes\n");
    for (i = 0; i < 10; i++) {
        vis_ConnectGenNode(connect, &nid);
        printf(" %d", nid);
    }
    printf("\n");
    /* now ask for 10 available elements */
    printf("ten available elements\n");
    for (i = 0; i < 10; i++) {
        vis_ConnectGenElem(connect, &eid);
        printf(" %d", eid);
    }
    printf("\n");
    /* end objects */
    vis_ConnectEnd(connect);
    return 0;
}

/*----------------------------------------------------------------------
                      utility to print node and element info
----------------------------------------------------------------------*/
static void
connect_print(vis_Connect* connect)
{
    Vint i, n;
    Vint numnp, numel;
    Vint flag;
    Vfloat x[3];
    Vint nix, ix[64];

    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    /* node coordinates */
    printf("Nodes\n");
    printf("index       x             y             z\n");
    for (n = 1; n <= numnp; n++) {
        vis_ConnectIsNode(connect, n, &flag);
        if (flag == 0) {
            printf("%4d   deleted\n", n);
            continue;
        }
        vis_ConnectCoords(connect, 1, &n, (Vfloat(*)[3])x);
        printf("%4d     %e  %e  %e\n", n, x[0], x[1], x[2]);
    }
    /* node element connection */
    printf("index   connected elements\n");
    for (n = 1; n <= numnp; n++) {
        printf("%4d", n);
        vis_ConnectIsNode(connect, n, &flag);
        if (flag == 0) {
            printf("   deleted\n");
            continue;
        }
        vis_ConnectNodeElem(connect, n, &nix, ix);
        for (i = 0; i < nix; i++) {
            printf("%5d", ix[i]);
        }
        printf("\n");
    }

    printf("Elements\n");
    printf("index       connectivity\n");
    for (n = 1; n <= numel; n++) {
        printf("%4d", n);
        vis_ConnectIsElem(connect, n, &flag);
        if (flag == 0) {
            printf("   deleted\n");
            continue;
        }
        vis_ConnectElemNode(connect, n, &nix, ix);
        for (i = 0; i < nix; i++) {
            printf("%5d", ix[i]);
        }
        printf("\n");
    }
}
