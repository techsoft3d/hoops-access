#include <stdio.h>
#include <math.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_ELEM 5
#define MAX_NODE 12

static Vint conn[MAX_ELEM][4] = {{1, 2, 8, 7}, {3, 4, 6, 5}, {5, 6, 8, 7}, {7, 8, 10, 9}, {9, 10, 12, 11}};
static Vfloat coords[MAX_NODE][3];

/*----------------------------------------------------------------------
                      Element Face Node Normals
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_ElemDat* elemdat;
    vis_Group* groupfree;
    vis_IdTran* idtran;
    vis_GridFun* gf;

    Vint i, j, k, m;
    Vfloat p[4][3];
    Vint num, nix, ix[4];
    Vfloat ang;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* generate node coordinates */
    coords[0][0] = 0.;
    coords[0][1] = 0.;
    coords[0][2] = 1.;

    coords[1][0] = coords[0][0];
    coords[1][1] = 1.;
    coords[1][2] = coords[0][2];
    ang = -40.;
    for (i = 2; i < MAX_NODE; i += 2) {
        coords[i][0] = (Vfloat)sin(.017453 * ang);
        coords[i][1] = 0.;
        coords[i][2] = 1.F - (Vfloat)cos(.017453 * ang);

        coords[i + 1][0] = coords[i][0];
        coords[i + 1][1] = 1.;
        coords[i + 1][2] = coords[i][2];
        ang += 20.;
    }

    /* set topologies */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, VIS_SHAPEQUAD, 2, 0, 0);
    }
    /* set element node connectivity */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
    }
    /* set node coordinates */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }
    /* create a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* generate kernel */
    vis_ConnectKernel(connect, 0);

    /* free face group */
    groupfree = vis_GroupBegin();
    vis_GroupDef(groupfree, MAX_ELEM, SYS_ELEM, SYS_FACE);
    vis_ConnectFaceGroup(connect, CONNECT_FREE, NULL, groupfree);

    /* create elemdat object for element face node normals */
    elemdat = vis_ElemDatBegin();
    vis_ElemDatDef(elemdat, MAX_ELEM, SYS_FACE, SYS_NODE, SYS_VECTOR);
    vis_ElemDatSetObject(elemdat, VIS_GRIDFUN, gf);
    vis_ElemDatSetParamf(elemdat, ELEMDAT_FEATUREANGLE, 20.);
    vis_ElemDatSetParami(elemdat, ELEMDAT_FEATUREBRANCH, SYS_ON);
    vis_ElemDatNormal(elemdat, groupfree);

    /* fill idtran with defined element faces */
    idtran = vis_IdTranBegin();
    vis_ElemDatIdTran(elemdat, ELEMDAT_SETDATA, idtran);

    /* loop through defined faces and print */
    vis_IdTranInq(idtran, &num);
    for (i = 1; i <= num; i++) {
        vis_IdTranGetId(idtran, i, &m);
        vis_IdTranGetEnt(idtran, i, &j);
        vis_ElemDatData(elemdat, m, j, (Vfloat*)p);
        vis_GridFunElemCon(gf, SYS_FACE, m, j, &nix, ix);
        printf("element= %d, face= %d, number of nodes= %d\n", m, j, nix);
        for (k = 0; k < nix; k++) {
            printf("  p(node= %d)= %f %f %f\n", ix[k], p[k][0], p[k][1], p[k][2]);
        }
    }
    /* end objects */
    vis_ConnectEnd(connect);
    vis_ElemDatEnd(elemdat);
    vis_GroupEnd(groupfree);
    vis_IdTranEnd(idtran);
    vis_GridFunEnd(gf);
    return 0;
}
