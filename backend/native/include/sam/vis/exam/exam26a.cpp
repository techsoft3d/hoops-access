#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_ELEM 3
#define MAX_NODE 14

static Vint conn[MAX_ELEM][8] = {{1, 2, 6, 5, 9, 10, 13, 12}, {2, 3, 7, 6, 10, 11, 14, 13}, {3, 4, 8, 7, 0, 0, 0, 0}};
static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD};
static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {3., 0., 0.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 0.}, {3., 1., 0.}, {0., 0., 1.}, {1., 0., 1.},
                                     {2., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}, {2., 1., 1.}};

/*----------------------------------------------------------------------
                      Element Face Node Data
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_ElemDat* elemdat;
    vis_IdTran* idtran;
    vis_GridFun* gf;

    Vint i, j, k, m;
    Vfloat p[8];
    Vint num, nix, ix[4], flag;

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
    /* create a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* create elemdat object for element face node scalars */
    elemdat = vis_ElemDatBegin();
    vis_ElemDatDef(elemdat, MAX_ELEM, SYS_FACE, SYS_NODE, SYS_SCALAR);
    vis_ElemDatSetObject(elemdat, VIS_GRIDFUN, gf);

    /* set pressure for front face of element 1 */
    p[0] = 1.;
    p[1] = 2.;
    p[2] = 2.;
    p[3] = 1.;
    vis_ElemDatSetData(elemdat, 1, 2, p);
    /* set pressure for front face of element 2 */
    p[0] = 2.;
    p[1] = 1.;
    p[2] = 1.;
    p[3] = 2.;
    vis_ElemDatSetData(elemdat, 2, 2, p);

    /* fill idtran with defined element faces */
    idtran = vis_IdTranBegin();
    vis_ElemDatIdTran(elemdat, ELEMDAT_SETDATA, idtran);

    /* loop through defined element faces and print */
    vis_IdTranInq(idtran, &num);
    for (i = 1; i <= num; i++) {
        vis_IdTranGetId(idtran, i, &m);
        vis_IdTranGetEnt(idtran, i, &j);
        vis_ElemDatData(elemdat, m, j, p);
        vis_GridFunElemCon(gf, SYS_FACE, m, j, &nix, ix);
        printf("element= %d, face= %d, number of nodes= %d\n", m, j, nix);
        for (k = 0; k < nix; k++) {
            printf("  p(node= %d)= %f\n", ix[k], p[k]);
        }
    }
    /* now add imaginary data at front face of element 2 */
    vis_ElemDatSetComplexMode(elemdat, SYS_COMPLEX_IMAGINARY);
    p[0] = 4.;
    p[1] = 3.;
    p[2] = 3.;
    p[3] = 4.;
    vis_ElemDatSetData(elemdat, 2, 2, p);
    /* query overall complex data flag, should be 1 now */
    vis_ElemDatGetComplex(elemdat, &flag);
    printf("Complex flag= %d\n", flag);
    /* get complete complex data, entities have not changed */
    vis_ElemDatSetComplexMode(elemdat, SYS_COMPLEX_REALIMAGINARY);
    for (i = 1; i <= num; i++) {
        vis_IdTranGetId(idtran, i, &m);
        vis_IdTranGetEnt(idtran, i, &j);
        vis_ElemDatData(elemdat, m, j, p);
        vis_GridFunElemCon(gf, SYS_FACE, m, j, &nix, ix);
        printf("element= %d, face= %d, number of nodes= %d\n", m, j, nix);
        for (k = 0; k < nix; k++) {
            printf("  p(node= %d)= %f %f(i)\n", ix[k], p[2 * k], p[2 * k + 1]);
        }
    }
    /* end objects */
    vis_ConnectEnd(connect);
    vis_ElemDatEnd(elemdat);
    vis_IdTranEnd(idtran);
    vis_GridFunEnd(gf);
    return 0;
}
