#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* example mesh is two bricks, a quad and a line */
#define MAX_ELEM 4
#define MAX_NODE 15

static Vint conn[MAX_ELEM][8] = {
{1, 2, 6, 5, 9, 10, 13, 12}, {2, 3, 7, 6, 10, 11, 14, 13}, {3, 4, 8, 7, 0, 0, 0, 0}, {14, 15, 0, 0, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD, VIS_SHAPELINE};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {3., 0., 0.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 0.}, {3., 1., 0.}, {0., 0., 1.}, {1., 0., 1.},
                                     {2., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}, {2., 1., 1.}, {3., 1., 1.}};

/*----------------------------------------------------------------------
                      Perform space searches using a Space object
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_Space* space;
    vis_GridFun* gf;
    vis_IdTran* idtran;
    vis_Group* group;

    Vint i;
    Vint num_pts;
    Vfloat pts[10][3], rst[3];
    Vfloat local[10][3];
    Vfloat line_pts[2][3];
    Vint node, elem;
    Vint flag;
    Vfloat plane_pts[4][3];
    Vfloat box_pts[8][3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set element topologies, connectivity */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], 2, 0, 0);
    }
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
    }
    /* set node coordinates and generate kernel */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }
    vis_ConnectKernel(connect, 0);

    /* create and load a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* create space object for elements */
    space = vis_SpaceBegin();
    vis_SpaceSetObject(space, VIS_GRIDFUN, gf);

    /* create kernel for entire mesh */
    vis_SpaceKernel(space);

    /*----------------------------------------------------------------------
                          Search the mesh for elements which contain a set
                          of two points.  The elements which the points are
                          in are returned in an vis_Idtran object.
    ----------------------------------------------------------------------*/
    printf("\n ----------  point search  ---------- \n");

    /* define two points */
    num_pts = 2;
    pts[0][0] = 1.4f;
    pts[0][1] = 0.6f;
    pts[0][2] = 0.5f;
    pts[1][0] = 2.3f;
    pts[1][1] = 0.5f;
    pts[1][2] = 0.5f;

    /* prepare idtran object for output */
    idtran = vis_IdTranBegin();
    vis_IdTranDef(idtran, num_pts);

    /* perform point search */
    vis_SpacePointIdTran(space, num_pts, pts, NULL, idtran, local);

    /* print results */
    for (i = 1; i <= num_pts; i++) {
        vis_IdTranGetId(idtran, i, &elem);
        if (elem > 0) {
            printf("\n point %d is in element [%d].\n", i, elem);
        }
        else {
            printf("\n point %d is out. \n", i);
        }
    }
    /* use alternative function to return natural coordinates */
    /* requires ADTREE kernel to be built */
    vis_SpaceSetParami(space, SPACE_TREE, SPACE_TREE_ADTREE);
    vis_SpaceKernel(space);
    for (i = 1; i <= num_pts; i++) {
        vis_SpaceElemRST(space, pts[i - 1], NULL, &elem, rst);
        if (elem) {
            printf("\n point %d is in element [%d], rst= %f %f %f\n", i, elem, rst[0], rst[1], rst[2]);
        }
        else {
            printf("\n point %d is out. \n", i);
        }
    }

    /*----------------------------------------------------------------------
                          Search the mesh for the elements which intersect a
                          line.  The elements which intersect the line are
                          returned in a vis_Group object.
    ----------------------------------------------------------------------*/
    /* pick 3D elements */
    printf("\n ----------  line search 1 ---------- \n");
    /* define line endpoints */
    line_pts[0][0] = -0.5;
    line_pts[0][1] = 0.5;
    line_pts[0][2] = 0.5;
    line_pts[1][0] = 0.5;
    line_pts[1][1] = 0.5;
    line_pts[1][2] = 0.5;

    /* prepare group object for output */
    group = vis_GroupBegin();
    vis_GroupDef(group, MAX_ELEM, SYS_ELEM, SYS_NONE);
    vis_GroupClear(group);

    /* set infinite line type and perform line search */
    vis_SpaceSetParami(space, SPACE_LINE_INFINITE, VIS_ON);
    vis_SpaceLineGroup(space, line_pts, NULL, group);

    /* print results */
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_GroupGetIndex(group, i, &flag);
        if (flag) {
            printf("\n the line intersects element [%d]. \n", i);
        }
    }

    /* pick 2D and 1D elements */
    printf("\n ----------  line search 2 ---------- \n");
    /* define line endpoints */
    line_pts[0][0] = 2.5f;
    line_pts[0][1] = 1.01f;
    line_pts[0][2] = -0.5f;
    line_pts[1][0] = 2.5f;
    line_pts[1][1] = 1.01f;
    line_pts[1][2] = 0.5f;

    vis_GroupClear(group);

    vis_SpaceSetParamf(space, SPACE_TOLERANCE, .02f);
    vis_SpaceLineGroup(space, line_pts, NULL, group);
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_GroupGetIndex(group, i, &flag);
        if (flag) {
            printf("\n the line intersects element [%d]. \n", i);
        }
    }

    /*----------------------------------------------------------------------
                          Search the mesh for the elements which intersect a plane.
                          The elements which intersect the plane are returned in
                          a vis_Group object.
    ----------------------------------------------------------------------*/
    printf("\n  ----------  plane search  ---------- \n");

    /* define points in plane */
    plane_pts[0][0] = 0.0;
    plane_pts[0][1] = 0.0;
    plane_pts[0][2] = 0.5;
    plane_pts[1][0] = 1.5;
    plane_pts[1][1] = 0.0;
    plane_pts[1][2] = 0.5;
    plane_pts[2][0] = 1.5;
    plane_pts[2][1] = 2.0;
    plane_pts[2][2] = 0.5;
    plane_pts[3][0] = 0.0;
    plane_pts[3][1] = 2.0;
    plane_pts[3][2] = 0.5;

    vis_GroupClear(group);

    /* perform plane search */
    vis_SpacePlaneGroup(space, plane_pts, NULL, group);

    for (i = 1; i <= MAX_ELEM; i++) {
        vis_GroupGetIndex(group, i, &flag);
        if (flag) {
            printf("\n  the plane intersects element [%d]. \n", i);
        }
    }

    /*----------------------------------------------------------------------
                          search the mesh for the elements which intersect or are
                          in a box.  The elements which intersect or are in the
                          box are returned in a vis_Group object.
    ----------------------------------------------------------------------*/
    printf("\n  ----------  box search  ---------- \n");

    /* set the six corners of the box. first the */
    /* back four points, then the front. */
    box_pts[0][0] = 0.0f;
    box_pts[0][1] = 0.1f;
    box_pts[0][2] = 0.2f;
    box_pts[1][0] = 0.4f;
    box_pts[1][1] = 0.1f;
    box_pts[1][2] = 0.2f;
    box_pts[2][0] = 0.4f;
    box_pts[2][1] = 0.15f;
    box_pts[2][2] = 0.2f;
    box_pts[3][0] = 0.0f;
    box_pts[3][1] = 0.15f;
    box_pts[3][2] = 0.2f;

    box_pts[4][0] = 0.0f;
    box_pts[4][1] = 0.1f;
    box_pts[4][2] = 0.4f;
    box_pts[5][0] = 0.4f;
    box_pts[5][1] = 0.1f;
    box_pts[5][2] = 0.4f;
    box_pts[6][0] = 0.4f;
    box_pts[6][1] = 0.15f;
    box_pts[6][2] = 0.4f;
    box_pts[7][0] = 0.0f;
    box_pts[7][1] = 0.15f;
    box_pts[7][2] = 0.4f;

    vis_GroupClear(group);

    /* perform box search */
    vis_SpaceBoxGroup(space, box_pts, NULL, group);

    for (i = 1; i <= MAX_ELEM; i++) {
        vis_GroupGetIndex(group, i, &flag);
        if (flag) {
            printf("\n  the element [%d] is in the box. \n", i);
        }
    }
    /*----------------------------------------------------------------------
                          Search the mesh for the nodes which match a set
                          of input points
    ----------------------------------------------------------------------*/
    printf("\n ----------  point node search  ---------- \n");

    num_pts = 2;
    pts[0][0] = 2.0;
    pts[0][1] = 1.0;
    pts[0][2] = 0.;
    pts[1][0] = 2.5;
    pts[1][1] = 0.5;
    pts[1][2] = 0.;

    /* create node kernel */
    vis_SpaceNodeKernel(space);
    vis_SpacePointNodeIdTran(space, num_pts, pts, NULL, idtran);
    /* print results */
    for (i = 1; i <= num_pts; i++) {
        vis_IdTranGetId(idtran, i, &node);
        if (node > 0) {
            printf("\n point %d is coincident with node [%d].\n", i, node);
        }
        else {
            printf("\n point %d is not coincident. \n", i);
        }
    }

    /* end objects */
    vis_ConnectEnd(connect);
    vis_GridFunEnd(gf);
    vis_SpaceEnd(space);
    vis_IdTranEnd(idtran);
    vis_GroupEnd(group);
    return 0;
}
