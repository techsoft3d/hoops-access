
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
                      Node and Element Associations
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    Vint i;
    Vint id, aid, num, aids[3];

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
    /* set node association */
    vis_ConnectSetNodeAssoc(connect, VIS_CSYSID, 5, 100);
    /* query node association */
    id = 5;
    vis_ConnectNodeAssoc(connect, VIS_CSYSID, 1, &id, &aid);
    printf("node 5, aid= %d\n", aid);

    /* add another node association of same type to same node */
    vis_ConnectAddNodeAssoc(connect, VIS_CSYSID, id, 101);
    vis_ConnectNumNodeAssoc(connect, VIS_CSYSID, id, &num);
    printf("node 5, num= %d\n", num);
    vis_ConnectAllNodeAssoc(connect, VIS_CSYSID, id, &num, aids);
    for (i = 0; i < num; i++) {
        printf("node 5, aid[%d]= %d\n", i, aids[i]);
    }
    /* now delete added associations */
    vis_ConnectDelNodeAssoc(connect, VIS_CSYSID, id);
    vis_ConnectNumNodeAssoc(connect, VIS_CSYSID, id, &num);
    printf("node 5, num= %d\n", num);
    vis_ConnectAllNodeAssoc(connect, VIS_CSYSID, id, &num, aids);
    for (i = 0; i < num; i++) {
        printf("node 5, aid[%d]= %d\n", i, aids[i]);
    }
    /* now set element face entity associations */
    vis_ConnectSetElemEntAssoc(connect, VIS_GEOFACE, SYS_FACE, 2, 1, 100);
    vis_ConnectSetElemEntAssoc(connect, VIS_GEOFACE, SYS_FACE, 3, 1, 100);

    /* set element edge entity association */
    /* element 3, edge 2 */
    vis_ConnectSetElemEntAssoc(connect, VIS_GEOEDGE, SYS_EDGE, 3, 2, 1);

    /* query element edge association */
    /* undefined associations return 0 */
    vis_ConnectElemEntAssoc(connect, VIS_GEOEDGE, SYS_EDGE, 3, 1, &aid);
    printf("element 3, edge 1, aid= %d\n", aid);
    /* element 3, edge 2 */
    vis_ConnectElemEntAssoc(connect, VIS_GEOEDGE, SYS_EDGE, 3, 2, &aid);
    printf("element 3, edge 2, aid= %d\n", aid);

    /* additional associations */
    printf("\nTest adding non-unique associations\n");
    vis_ConnectAddElemEntAssoc(connect, VIS_GEOFACE, SYS_FACE, 2, 1, 100);
    vis_ConnectAllElemEntAssoc(connect, VIS_GEOFACE, SYS_FACE, 2, 1, &num, aids);
    printf("element 2, face 1, num= %d\n", num);
    for (i = 0; i < num; i++) {
        printf("element 2, face 1, aid[%d]= %d\n", i, aids[i]);
    }
    /* delete all associations */
    printf("\nTest delete additional associations\n");
    vis_ConnectDelElemEntAssoc(connect, VIS_GEOFACE, SYS_FACE, 2, 1);
    vis_ConnectAllElemEntAssoc(connect, VIS_GEOFACE, SYS_FACE, 2, 1, &num, aids);
    printf("element 2, face 1, num= %d\n", num);
    for (i = 0; i < num; i++) {
        printf("element 2, face 1, aid[%d]= %d\n", i, aids[i]);
    }
    /* add associations to elements with no set association */
    printf("\nTest adding associations without set association\n");
    vis_ConnectAddElemEntAssoc(connect, VIS_GEOFACE, SYS_FACE, 6, 5, 50);
    vis_ConnectAllElemEntAssoc(connect, VIS_GEOFACE, SYS_FACE, 6, 5, &num, aids);
    printf("element 6, face 5, num= %d\n", num);
    for (i = 0; i < num; i++) {
        printf("element 6, face 5, aid[%d]= %d\n", i, aids[i]);
    }
    /* end objects */
    vis_ConnectEnd(connect);
    return 0;
}
