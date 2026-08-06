#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
/*
                 5------6
                /.     /.\
  y            / .    / . \
  |           /  .   /  .  \7      8-----16
  --x        /   1../...2../|      |      |
 /         12-----13-----14 |      |      |
z           |  .   |  .   |.|      |      |
            | .    | .    | 3      4-----15
            |.     |.     |/
            9-----10-----11
*/

#define MAX_ELEM 3
#define MAX_NODE 16

static Vint conn[MAX_ELEM][8] = {{1, 2, 6, 5, 9, 10, 13, 12}, {2, 3, 7, 6, 10, 11, 14, 13}, {4, 15, 16, 8, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 1.}, {3., 0., 1.}, {0., 1., 0.}, {1., 1., 0.},
                                     {2., 1., 1.}, {3., 1., 1.}, {0., 0., 2.}, {1., 0., 2.}, {2., 0., 2.}, {0., 1., 2.},
                                     {1., 1., 2.}, {2., 1., 2.}, {4., 0., 1.}, {4., 1., 1.}};

/*----------------------------------------------------------------------
                      Manage Contact Pairs Using CPair
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vis_Connect* connect;
    vis_GridFun* gf;
    vis_CPair* cpair;
    vis_IdTran *nodeidtran, *faceidtran;
    Vdouble area;
    Vint index, num, no;

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
    /* create gridfun object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* instance CPair object */
    cpair = vis_CPairBegin();

    /* master surface is defined by element faces */
    /* slave surface is defined by nodes */
    vis_CPairDef(cpair, SYS_FACE, SYS_NODE);
    vis_CPairSetObject(cpair, VIS_GRIDFUN, gf);

    /* specify master surface as element faces */
    vis_CPairSetMaster(cpair, 2, 1);

    /* specify slave surface as nodes */
    vis_CPairSetSlaveNodedv(cpair, 4, 1.);
    vis_CPairSetSlaveNodedv(cpair, 8, 1.);

    /* define properties */
    vis_CPairSetValuei(cpair, CPAIR_PID, 20);
    /* Adjust parameter */
    vis_CPairSetValued(cpair, CPAIR_ADJUST, .1);

    /* query slave nodes */
    nodeidtran = vis_IdTranBegin();
    /* slave nodes */
    vis_CPairNodeIdTran(cpair, nodeidtran);

    /* iterate through nodes */
    printf("\nSlave Nodes\n");
    vis_IdTranCount(nodeidtran, IDTRAN_NUMINDICES, &num);
    for (i = 1; i <= num; i++) {
        vis_IdTranGetId(nodeidtran, i, &index);
        vis_CPairSlaveNodedv(cpair, index, &area);
        printf("node= %d, area= %e\n", index, area);
    }

    /* query master element faces */
    faceidtran = vis_IdTranBegin();
    /* element faces */
    vis_CPairFaceIdTran(cpair, CPAIR_MASTER, faceidtran);

    /* iterate through element faces */
    printf("\nMaster Element Faces\n");
    vis_IdTranCount(faceidtran, IDTRAN_NUMINDICES, &num);
    for (i = 1; i <= num; i++) {
        vis_IdTranGetId(faceidtran, i, &index);
        vis_IdTranGetEnt(faceidtran, i, &no);
        printf("elem= %d, face= %d\n", index, no);
    }

    /* end objects */
    vis_ConnectEnd(connect);
    vis_GridFunEnd(gf);
    vis_CPairEnd(cpair);
    vis_IdTranEnd(nodeidtran);
    vis_IdTranEnd(faceidtran);
    return 0;
}
