#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
/*
                                   18
                 5------6        / |
                /.     /.\     16  17
  y            / .    / . \   /    |
  |           /  .   /  .  \7------8
  --x        /   1../...2../|      |
 /         12-----13-----14 |      15
z           |  .   |  .   |.|      |
            | .    | .    | 3------4
          23|.24 25|.   26|/
            9-----10-----11
           .   .  .      .

         19  20 21     22
        . .    .      .

      27--28-29--30-31
*/
#define MAX_ELEM 7
#define MAX_NODE 31

static Vint conn[MAX_ELEM][16] = {
{1, 2, 6, 5, 9, 10, 13, 12, 0, 0, 0, 0, 0, 0, 0, 0},        {2, 3, 7, 6, 10, 11, 14, 13, 0, 0, 0, 0, 0, 0, 0, 0},
{3, 4, 8, 7, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},          {7, 8, 18, 17, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{9, 10, 13, 12, 27, 19, 20, 24, 23, 0, 0, 0, 0, 0, 0, 0},   {10, 27, 29, 13, 20, 28, 21, 24, 25, 0, 0, 0, 0, 0, 0, 0},
{29, 10, 13, 31, 11, 14, 21, 25, 22, 26, 30, 0, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD, VIS_SHAPETRI, VIS_SHAPEPYR, VIS_SHAPETET, VIS_SHAPEWED};

static Vint maxi[MAX_ELEM] = {0, 0, 3, 3, 3, 3, 3};
static Vint maxj[MAX_ELEM] = {0, 0, 0xd0000, 0x10000, 0xf0000, 0x80000, 0x1920000};

static Vfloat coords[MAX_NODE][3] = {
{0., 0., 0.}, {1., 0., 0.},   {2., 0., 1.},  {3., 0., 1.}, {0., 1., 0.},  {1., 1., 0.}, {2., 1., 1.},
{3., 1., 1.}, {0., 0., 2.},   {1., 0., 2.},  {2., 0., 2.}, {0., 1., 2.},  {1., 1., 2.}, {2., 1., 2.},
{3., .5, 1.}, {2.5, 1.5, 1.}, {3., 1.5, 1.}, {3., 2., 1.}, /* 16-18 */
{0., 0., 3.}, {.5, 0., 3.},   {1., 0., 3.},  {2., 0., 3.}, {0., .5, 3.},  {.5, .5, 3.}, {1., .5, 3.},
{2., .5, 3.}, {0., 0., 4.},   {.5, 0., 4.},  {1., 0., 4.}, {1.5, 0., 4.}, {2., 0., 4.}};

/*----------------------------------------------------------------------
                      Variable Element Connectivity and Adjacency using Connect
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    Vint i;
    Vint nfaces, nedges, nnodes;
    Vint nix, ix[64], no[64];
    Vfloat x[64][3];
    Vint nindices, indices[2];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set topologies */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], maxi[i], maxj[i], 0);
    }

    /* set element node connectivity */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
    }

    /* set node coordinates */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }
    /* print element connection info */
    printf("Example 23e, Using Connect\n");
    printf("element - number of faces, edges, nodes\n");
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectElemNum(connect, SYS_FACE, i + 1, &nfaces);
        vis_ConnectElemNum(connect, SYS_EDGE, i + 1, &nedges);
        vis_ConnectElemNum(connect, SYS_NODE, i + 1, &nnodes);
        printf("%5d              %5d  %5d  %5d\n", i + 1, nfaces, nedges, nnodes);
    }
    /* node connectivity query for element 3 */
    vis_ConnectElemNode(connect, 3, &nix, ix);
    vis_ConnectCoords(connect, nix, ix, x);
    printf("element node - connected node, coordinates\n");
    for (i = 0; i < nix; i++) {
        printf("%5d                %3d", i + 1, ix[i]);
        printf("       %f  %f  %f\n", x[i][0], x[i][1], x[i][2]);
    }
    /* write to NASTRAN bulk data file */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam23e.bdf");

    /* generate connect kernel */
    vis_ConnectKernel(connect, 0);

    /* element adjacency query for element 1 */
    vis_ConnectElemNum(connect, SYS_FACE, 1, &nfaces);
    printf("element face - adjacent element entity\n");
    for (i = 0; i < nfaces; i++) {
        vis_ConnectElemAdjEnt(connect, SYS_FACE, 1, i + 1, &nix, ix, no);
        /* test for adjacent element */
        if (nix) {
            printf("%5d                %3d %3d\n", i + 1, ix[0], no[0]);
        }
        else {
            printf("%5d               none\n", i + 1);
        }
    }

    /* query elements connected to both nodes 3 and 7 */
    nindices = 2;
    indices[0] = 3;
    indices[1] = 7;
    vis_ConnectNodeAdj(connect, nindices, indices, &nix, ix);
    printf("adjacent element\n");
    for (i = 0; i < nix; i++) {
        printf("%5d\n", ix[i]);
    }

    /* end objects */
    vis_ConnectEnd(connect);
    return 0;
}
