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
static void
printflags(vis_Group* group, const Vchar* stg, Vint numelem);

#define MAX_ELEM 3
#define MAX_NODE 14

static Vint conn[MAX_ELEM][8] = {{1, 2, 6, 5, 9, 10, 13, 12}, {2, 3, 7, 6, 10, 11, 14, 13}, {3, 4, 8, 7, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 1.}, {3., 0., 1.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 1.}, {3., 1., 1.}, {0., 0., 2.}, {1., 0., 2.},
                                     {2., 0., 2.}, {0., 1., 2.}, {1., 1., 2.}, {2., 1., 2.}};

/*----------------------------------------------------------------------
                      Generate Element Face and Edge Groups using Connect
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_Group *groupface, *groupedge;
    vis_Group* groupfaceseed;
    Vfloat c, s, ctm[4][4];

    Vint i;

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

    /* generate connect kernel */
    vis_ConnectKernel(connect, 0);

    /* create element face group */
    groupface = vis_GroupBegin();
    vis_GroupDef(groupface, MAX_ELEM, SYS_ELEM, SYS_FACE);

    /* generate group of element free faces */
    vis_ConnectFaceGroup(connect, CONNECT_FREE, NULL, groupface);
    printflags(groupface, "element - free faces", MAX_ELEM);

    /* create element edge group */
    groupedge = vis_GroupBegin();
    vis_GroupDef(groupedge, MAX_ELEM, SYS_ELEM, SYS_EDGE);

    /* generate group of element unique edges */
    vis_ConnectEdgeGroup(connect, CONNECT_UNIQUE, NULL, groupedge);
    printflags(groupedge, "element - unique edges", MAX_ELEM);

    /* generate group of element free edges */
    vis_GroupClear(groupedge);
    vis_ConnectEdgeGroup(connect, CONNECT_FREE, NULL, groupedge);
    printflags(groupedge, "element - free edges", MAX_ELEM);

    /* generate group of element face feature edges */
    vis_GroupClear(groupedge);
    vis_ConnectEdgeGroup(connect, CONNECT_FEATURE, groupface, groupedge);
    printflags(groupedge, "element - element face feature edges", MAX_ELEM);

    /* generate group of element faces from seeded face */
    /* seed element 1 face 4 (top face) */
    /* containing only free faces and bounded by feature edges */
    groupfaceseed = vis_GroupBegin();
    vis_GroupDef(groupfaceseed, MAX_ELEM, SYS_ELEM, SYS_FACE);
    vis_GroupClear(groupfaceseed);
    vis_ConnectSetGroupParami(connect, CONNECT_SEEDELEM, 1);
    vis_ConnectSetGroupParami(connect, CONNECT_SEEDFACE, 4);
    vis_ConnectSetGroupObject(connect, CONNECT_SEEDGROUP, groupedge);
    vis_ConnectFaceGroup(connect, CONNECT_SEED, groupface, groupfaceseed);
    printflags(groupfaceseed, "element - element face seeded", MAX_ELEM);

    /* generate group of element face silhouette edges */
    /* load model view matrix */
    c = 0.866026f;
    s = 0.500000;
    ctm[0][0] = 1.0;
    ctm[1][0] = 0.0;
    ctm[2][0] = 0.0;
    ctm[3][0] = 0.0;
    ctm[0][1] = 0.0;
    ctm[1][1] = c;
    ctm[2][1] = -s;
    ctm[3][1] = 0.0;
    ctm[0][2] = 0.0;
    ctm[1][2] = s;
    ctm[2][2] = c;
    ctm[3][2] = 0.0;
    ctm[0][3] = 0.0;
    ctm[1][3] = 0.0;
    ctm[2][3] = 0.0;
    ctm[3][3] = 1.0;
    vis_ConnectSetGroupParamfv(connect, CONNECT_MODELVIEWMATRIX, (Vfloat*)ctm);

    vis_GroupClear(groupedge);
    vis_ConnectEdgeGroup(connect, CONNECT_SILHOUETTE, groupface, groupedge);
    printflags(groupedge, "element - element face silhouette edges", MAX_ELEM);

    /* end objects */
    vis_ConnectEnd(connect);
    vis_GroupEnd(groupface);
    vis_GroupEnd(groupfaceseed);
    vis_GroupEnd(groupedge);
    return 0;
}

/*----------------------------------------------------------------------
                      print elem edge or elem face flags in a group
----------------------------------------------------------------------*/
static void
printflags(vis_Group* group, const Vchar* stg, Vint numelem)
{
    Vint i;
    Vint flags;

    printf("%s\n", stg);
    for (i = 0; i < numelem; i++) {
        vis_GroupGetIndex(group, i + 1, &flags);
        printf("%5d      %3x\n", i + 1, flags);
    }
}
