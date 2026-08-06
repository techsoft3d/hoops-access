#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"

static void
printflags(vis_Group* group, Vchar* stg, Vint numelem);

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

    Vint i;

    /* create connect object */
    connect = new vis_Connect;
    connect->Def(MAX_NODE, MAX_ELEM);

    /* set topologies */
    for (i = 0; i < MAX_ELEM; i++) {
        connect->SetTopology(i + 1, shap[i], 2, 0, 0);
    }

    /* set element node connectivity */
    for (i = 0; i < MAX_ELEM; i++) {
        connect->SetElemNode(i + 1, conn[i]);
    }

    /* set node coordinates */
    for (i = 0; i < MAX_NODE; i++) {
        connect->SetCoords(i + 1, coords[i]);
    }

    /* generate connect kernel */
    connect->Kernel(0);

    /* create element face group */
    groupface = new vis_Group;
    groupface->Def(MAX_ELEM, SYS_ELEM, SYS_FACE);

    /* generate group of element free faces */
    connect->FaceGroup(CONNECT_FREE, NULL, groupface);
    printflags(groupface, "element - free face flags", MAX_ELEM);

    /* create element edge group */
    groupedge = new vis_Group;
    groupedge->Def(MAX_ELEM, SYS_ELEM, SYS_EDGE);

    /* generate group of element unique edges */
    connect->EdgeGroup(CONNECT_UNIQUE, NULL, groupedge);
    printflags(groupedge, "element - unique edge flags", MAX_ELEM);

    /* generate group of element free edges */
    groupedge->Clear();
    connect->EdgeGroup(CONNECT_FREE, NULL, groupedge);
    printflags(groupedge, "element - free edge flags", MAX_ELEM);

    /* generate group of element face feature edges */
    groupedge->Clear();
    connect->EdgeGroup(CONNECT_FEATURE, groupface, groupedge);
    printflags(groupedge, "element - element face feature edge flags", MAX_ELEM);

    /* end objects */
    delete connect;
    delete groupface;
    delete groupedge;
    return 0;
}

/*----------------------------------------------------------------------
                      print elem edge or elem face flags in a group
----------------------------------------------------------------------*/
static void
printflags(vis_Group* group, Vchar* stg, Vint numelem)
{
    Vint i;
    Vint flags;

    printf("%s\n", stg);
    for (i = 0; i < numelem; i++) {
        group->GetIndex(i + 1, &flags);
        printf("%5d      %3x\n", i + 1, flags);
    }
}
