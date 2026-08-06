#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
/*
                8
              . .
             .  .
           7    6
           .  . .
  y        . .  .
  |        5    .
  --x      .    .
           3....4
           .    .
           .    .
           1....2
*/
#define MAX_ELEM 3
#define MAX_NODE 8

static Vint conn[MAX_ELEM][4] = {{1, 2, 4, 3}, {3, 4, 6, 5}, {5, 7, 8, 6}};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {2., 0., 0.}, {0., 2., 0.}, {2., 2., 0.},
                                     {0., 3., 0.}, {2., 4., 0.}, {0., 4., 0.}, {2., 5., 0.}};

/*----------------------------------------------------------------------
                      Element Checking
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vis_Connect* connect;
    vis_ElemChk* elemchk;
    vis_State* state;
    vis_GridFun* gf;
    Vfloat s[ELEMCHK_MAX];
    Vfloat vn[3];
    Vint edgeflags;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set topologies and element connectivity */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, SYS_SHAPEQUAD, 2, 0, 0);
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
    }
    /* set node coordinates */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }
    /* generate connect kernel */
    vis_ConnectKernel(connect, 0);

    /* create a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* create a ElemChk object */
    elemchk = vis_ElemChkBegin();

    /* install GridFun object */
    vis_ElemChkSetObject(elemchk, VIS_GRIDFUN, gf);

    /* instance a state object to hold areas */
    state = vis_StateBegin();
    vis_StateDef(state, MAX_ELEM, SYS_ELEM, SYS_NONE, SYS_SCALAR);

    /* set area, taper, skew and aspect ratio */
    vis_ElemChkSetType(elemchk, ELEMCHK_JACOBIAN_SUM, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_FACE_TAPER, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_SKEW, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_ASPECT_RATIO, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_EDGEALT_RATIO, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_CG_X, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_MIN_ANGLE, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_MAX_ANGLE, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_HANDEDNESS, SYS_ON);

    /* compute shape parameters */
    printf("Shape Parameters\n");
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_ElemChkData(elemchk, i, s);
        printf("element= %d\n", i);
        printf(" area          = %e\n", s[ELEMCHK_JACOBIAN_SUM]);
        printf(" taper         = %e\n", s[ELEMCHK_FACE_TAPER]);
        printf(" skew          = %e\n", s[ELEMCHK_SKEW]);
        printf(" aspect ratio  = %e\n", s[ELEMCHK_ASPECT_RATIO]);
        printf(" edgealt ratio = %e\n", s[ELEMCHK_EDGEALT_RATIO]);
        printf(" cg            = %e %e %e\n", s[ELEMCHK_CG_X], s[ELEMCHK_CG_Y], s[ELEMCHK_CG_Z]);
        printf(" min angle     = %e\n", s[ELEMCHK_MIN_ANGLE]);
        printf(" max angle     = %e\n", s[ELEMCHK_MAX_ANGLE]);
        printf(" handedness    = %e\n", s[ELEMCHK_HANDEDNESS]);
        vis_StateSetData(state, i, &s[ELEMCHK_JACOBIAN_SUM]);
    }
    /* check normals */
    printf("Check Normals\n");
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_ElemChkNorm(elemchk, NULL, i, vn, &edgeflags);
        printf("element= %d\n", i);
        printf(" normal    = %f,%f,%f\n", vn[0], vn[1], vn[2]);
        printf(" edgeflags = %d\n", edgeflags);
    }
    /* growth rate */
    printf("Growth Rate\n");
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_ElemChkRate(elemchk, state, NULL, i, s);
        printf("element= %d\n", i);
        printf(" maximum rate   = %e\n", s[0]);
        printf(" maximum change = %e\n", s[1]);
    }

    /* end objects */
    vis_ConnectEnd(connect);
    vis_GridFunEnd(gf);
    vis_ElemChkEnd(elemchk);
    vis_StateEnd(state);
    return 0;
}
