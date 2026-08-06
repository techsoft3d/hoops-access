#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* example mesh is two bricks and a quad */
#define MAX_ELEM 3
#define MAX_NODE 14

static Vint conn[MAX_ELEM][8] = {{1, 2, 6, 5, 9, 10, 13, 12}, {2, 3, 7, 6, 10, 11, 14, 13}, {3, 4, 8, 7, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {3., 0., 0.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 0.}, {3., 1., 0.}, {0., 0., 1.}, {1., 0., 1.},
                                     {2., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}, {2., 1., 1.}};

static Vfloat temps[MAX_NODE] = {0., 0., 0., 0., 0., 0., 0., 0., 2., 2., 2., 2., 2., 2.};

/*----------------------------------------------------------------------
                      Perform space searches, intersection and interpolation
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_Space* space;
    vis_GridFun* gf;
    vis_Group *group, *groupface;
    vis_Face* face;
    vis_VisContext* vc;
    Vint i, j, k;
    Vint nfaces;
    Vfloat line_pts[2][3];
    Vint flag, flagj;

    Vint shape, maxi, maxj;
    Vint nix, ix[8];
    Vfloat x[8][3], t[8];
    Vfloat r[2], xr[3], xd[3], tr;
    Vint status;

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

    /* Search the mesh for the elements which intersect line */
    /* define line endpoints */
    line_pts[0][0] = -0.5;
    line_pts[0][1] = 0.5;
    line_pts[0][2] = 0.5;
    line_pts[1][0] = 2.5;
    line_pts[1][1] = 0.5;
    line_pts[1][2] = 0.5;

    /* restrict search to elements with external faces */
    groupface = vis_GroupBegin();
    vis_GroupDef(groupface, MAX_ELEM, SYS_ELEM, SYS_FACE);
    vis_ConnectFaceGroup(connect, CONNECT_FREE, NULL, groupface);

    /* prepare group object for output */
    group = vis_GroupBegin();
    vis_GroupDef(group, MAX_ELEM, SYS_ELEM, SYS_NONE);
    vis_GroupClear(group);

    /* set infinite line type and perform line search */
    vis_SpaceSetParami(space, SPACE_LINE_INFINITE, VIS_ON);
    vis_SpaceLineGroup(space, line_pts, groupface, group);

    face = vis_FaceBegin();
    vc = vis_VisContextBegin();
    vis_FaceSetObject(face, VIS_VISCONTEXT, vc);

    /* find precise face intersect point */
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_GroupGetIndex(group, i, &flag);
        if (flag == 0)
            continue;
        vis_ConnectElemNum(connect, SYS_FACE, i, &nfaces);
        for (j = 1; j <= nfaces; j++) {
            vis_GroupGetEntFlag(groupface, i, j, &flagj);
            if (flagj == 0)
                continue;
            vis_ConnectElemCon(connect, SYS_FACE, i, j, &nix, ix);
            vis_ConnectElemTopo(connect, SYS_FACE, i, j, &shape, &maxi, &maxj);
            vis_ConnectCoords(connect, nix, ix, x);
            vis_FaceSetTopology(face, shape, maxi, maxj);
            vis_FaceIntersectLine(face, x, line_pts, r, xr, xd, &status);

            /* intersection */
            if (status) {
                printf("\n the line intersects element= %d, face= %d\n", i, j);
                printf("   face natural coordinates= %f,%f\n", r[0], r[1]);

                /* gather scalar at face */
                for (k = 0; k < nix; k++) {
                    t[k] = temps[ix[k] - 1];
                }

                /* interpolate scalar at intersection */
                vis_FaceInterpolate(face, r, 1, t, &tr);
                printf("   scalar= %f\n", tr);
            }
        }
    }

    /* end objects */
    vis_ConnectEnd(connect);
    vis_GridFunEnd(gf);
    vis_SpaceEnd(space);
    vis_GroupEnd(group);
    vis_GroupEnd(groupface);
    vis_FaceEnd(face);
    vis_VisContextEnd(vc);
    return 0;
}
