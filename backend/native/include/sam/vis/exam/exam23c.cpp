#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/vis/visshar.h"
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

#define MAX_ELEM 4
#define MAX_NODE 15

static Vint conn[MAX_ELEM][30] = {
{3, 4, 8, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

{1, 5, 6, 2, 1, 9, 10, 13, 12, 9, 1, 9, 12, 5, 1, 2, 6, 13, 10, 2, 1, 2, 10, 9, 1, 5, 12, 13, 6, 5},

{2, 6, 7, 3, 2, 10, 11, 14, 13, 10, 2, 10, 13, 6, 2, 3, 7, 14, 11, 3, 2, 3, 11, 10, 2, 6, 13, 14, 7, 6},

{9, 12, 13, 10, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

static Vint mxi[MAX_ELEM] = {5, 30, 30, 2};

static Vint shap[MAX_ELEM] = {VIS_SHAPEPOLYGON, VIS_SHAPEPOLYHED, VIS_SHAPEPOLYHED, VIS_SHAPEPYR};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 1.}, {3., 0., 1.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 1.}, {3., 1., 1.}, {0., 0., 2.}, {1., 0., 2.},
                                     {2., 0., 2.}, {0., 1., 2.}, {1., 1., 2.}, {2., 1., 2.}, {0., 0., 3.}};

/*----------------------------------------------------------------------
                      Poly Connectivity and Adjacency using Connect
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_Group* groupface;
    Vint i, j;
    Vint nfaces, nedges, nnodes;
    Vint nix, ix[64];
    Vfloat x[64][3];
    Vint numel;
    Vint flags, flag;

    vsy_LicenseValidate(HOOPS_LICENSE);

    numel = MAX_ELEM;
    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, numel);

    /* set topologies */
    for (i = 0; i < numel; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], mxi[i], 0, 0);
    }
    /* set element node connectivity */
    for (i = 0; i < numel; i++) {
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
    }
    /* set node coordinates */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }
    vis_ConnectKernel(connect, 0);

    /* print element connection info */
    printf("element - number of faces, edges, nodes\n");
    for (i = 0; i < numel; i++) {
        vis_ConnectElemNum(connect, SYS_FACE, i + 1, &nfaces);
        vis_ConnectElemNum(connect, SYS_EDGE, i + 1, &nedges);
        vis_ConnectElemNum(connect, SYS_NODE, i + 1, &nnodes);
        printf("%5d              %5d  %5d  %5d\n", i + 1, nfaces, nedges, nnodes);
    }
    /* print element adjacency info */
    printf("element face - adjacent element\n");
    for (i = 0; i < numel; i++) {
        vis_ConnectElemNum(connect, SYS_FACE, i + 1, &nfaces);
        for (j = 1; j <= nfaces; j++) {
            vis_ConnectElemAdj(connect, SYS_FACE, i + 1, j, &nix, ix);
            if (nix) {
                printf("%5d%5d             %3d\n", i + 1, j, ix[0]);
            }
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

    groupface = vis_GroupBegin();
    vis_GroupDef(groupface, numel, SYS_ELEM, SYS_FACE);
    vis_ConnectFaceGroup(connect, CONNECT_UNIQUE, NULL, groupface);
    printf("element face unique\n");
    vis_GroupInitIndex(groupface);
    while (vis_GroupNextIndex(groupface, &i, &flags), i) {
        vis_ConnectElemNum(connect, SYS_FACE, i, &nfaces);
        for (j = 1; j <= nfaces; j++) {
            vis_GroupGetEntFlag(groupface, i, j, &flag);
            if (flag) {
                printf("%5d%5d\n", i, j);
            }
        }
    }
    /* end objects */
    vis_GroupEnd(groupface);
    vis_ConnectEnd(connect);
    return 0;
}
