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
  --x        /   1../...2../|      |
 /         12-----13-----14 |      |
z           |  .   |  .   |.|      |
            | .    | .    | 3------4
            |.     |.     |/
            9-----10-----11
*/

#define MAX_ELEM 3
#define MAX_NODE 14

static Vint conn[MAX_ELEM][8] = {{1, 2, 6, 5, 9, 10, 13, 12}, {2, 3, 7, 6, 10, 11, 14, 13}, {3, 4, 8, 7, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 1.}, {3., 0., 1.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 1.}, {3., 1., 1.}, {0., 0., 2.}, {1., 0., 2.},
                                     {2., 0., 2.}, {0., 1., 2.}, {1., 1., 2.}, {2., 1., 2.}};

/*----------------------------------------------------------------------
                      Convert Linear Elements to Parabolic Elements
----------------------------------------------------------------------*/
int
main()
{
    Vint i, j;
    vis_Connect *connect, *connectp;
    vis_Group* groupedge;
    vsy_IntVHash* ivh;
    Vint numnp, numel, numnpp;
    Vint nelem, nedge;
    Vint index, nix, ix[20], ixs, nid, nex, iex[2], ned;
    Vint shape, maxi, maxj, maxk;
    Vfloat xe[2][3], xm[3];
    Vint flags, flag, numno, maxno;

    vsy_LicenseValidate(HOOPS_LICENSE);

    numnp = MAX_NODE;
    numel = MAX_ELEM;
    printf("number of corner nodes=    %d\n", numnp);
    printf("number of linear elements= %d\n", numel);
    /* create connect object to hold linear elements */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, numnp, numel);
    /* set node coordinates */
    for (i = 0; i < numnp; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }
    /* set topologies */
    for (i = 0; i < numel; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], 2, 0, 0);
    }
    /* set element node connectivity */
    for (i = 0; i < numel; i++) {
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
    }
    /* generate connect kernel for adjacency type queries */
    vis_ConnectKernel(connect, 0);

    /* generate group of element unique edges */
    groupedge = vis_GroupBegin();
    vis_GroupDef(groupedge, numel, SYS_ELEM, SYS_EDGE);
    vis_ConnectEdgeGroup(connect, CONNECT_UNIQUE, NULL, groupedge);
    /* count unique edges */
    vis_GroupCount(groupedge, &nelem, &nedge);
    printf("number of unique edges= %d\n", nedge);

    /* create connect object to hold parabolic elements */
    numnpp = numnp + nedge;
    connectp = vis_ConnectBegin();
    vis_ConnectDef(connectp, numnpp, numel);
    /* copy original corner nodes */
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoords(connect, 1, &i, xe);
        vis_ConnectSetCoords(connectp, i, xe[0]);
    }
    /* put unique edges in a hashtable */
    /* one midside node will be generated per unique edge */
    ivh = vsy_IntVHashBegin();
    vsy_IntVHashDef(ivh, 2, nedge);
    nid = numnp;
    vis_GroupInitIndex(groupedge);
    while (vis_GroupNextIndex(groupedge, &index, &flags), index) {
        vis_GroupNumEntFlag(groupedge, index, &numno, &maxno);
        for (j = 1; j <= maxno; j++) {
            vis_GroupGetEntFlag(groupedge, index, j, &flag);
            if (flag) {
                vis_ConnectElemCon(connect, SYS_EDGE, index, j, &nex, iex);
                vis_ConnectCoords(connect, 2, iex, xe);
                xm[0] = .5F * (xe[0][0] + xe[1][0]);
                xm[1] = .5F * (xe[0][1] + xe[1][1]);
                xm[2] = .5F * (xe[0][2] + xe[1][2]);
                /* make sure that the edge nodes are lowest first */
                if (iex[0] > iex[1]) {
                    ixs = iex[0];
                    iex[0] = iex[1];
                    iex[1] = ixs;
                }
                nid += 1;
                vis_ConnectSetCoords(connectp, nid, xm);
                vsy_IntVHashInsert(ivh, iex, nid);
            }
        }
    }
    /* now loop through elements and insert edge midsides */
    /* promote topology to parabolic Serendipity */
    for (i = 1; i <= numel; i++) {
        vis_ConnectTopology(connect, i, &shape, &maxi, &maxj, &maxk);
        vis_ConnectSetTopology(connectp, i, shape, 3, 0, 0);
        vis_ConnectElemNode(connect, i, &nix, ix);
        vis_ConnectElemNum(connect, SYS_EDGE, i, &ned);
        /* look up edge in hashtable to retrieve midside node */
        for (j = 1; j <= ned; j++) {
            vis_ConnectElemCon(connect, SYS_EDGE, i, j, &nex, iex);
            if (iex[0] > iex[1]) {
                ixs = iex[0];
                iex[0] = iex[1];
                iex[1] = ixs;
            }
            vsy_IntVHashLookup(ivh, iex, &nid);
            ix[nix + j - 1] = nid;
        }
        vis_ConnectSetElemNode(connectp, i, ix);
    }
    vis_ConnectWrite(connectp, SYS_NASTRAN_BULKDATA, "exam24a.bdf");

    /* destroy objects */
    vis_ConnectEnd(connect);
    vis_ConnectEnd(connectp);
    vis_GroupEnd(groupedge);
    vsy_IntVHashEnd(ivh);
    return 0;
}
