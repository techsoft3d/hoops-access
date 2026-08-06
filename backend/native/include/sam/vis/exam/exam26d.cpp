#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_ELEM 1
#define MAX_NODE 8

static Vint conn[MAX_ELEM][8] = {{1, 2, 3, 4, 5, 6, 7, 8}};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.},
                                     {0., 0., 1.}, {1., 0., 1.}, {1., 1., 1.}, {0., 1., 1.}};

/*----------------------------------------------------------------------
                      Computing Gradient of Normal Stress
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_ElemDat* elemdat;
    vis_Group* groupfree;
    vis_GridFun* gf;
    vis_State* state;
    vis_Threshold* threshold;

    Vint i, j, k, m, n;
    Vfloat x[8][3];
    Vfloat stress[8][6];
    Vfloat s[8][6], sn[8];
    Vint nix, ix[8];
    Vfloat v[4][3];
    Vint flags, nfaces, nifx, jfx[4], nd, flagj;
    Vint shape, maxi, maxj, maxk;
    Vfloat sng[8][3], grad;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set node coordinates */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }
    /* set topologies */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, VIS_SHAPEHEX, 2, 0, 0);
    }
    /* set element node connectivity */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
    }
    /* create a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* generate kernel */
    vis_ConnectKernel(connect, 0);

    /* create state of global stress data */
    state = vis_StateBegin();
    vis_StateDef(state, MAX_ELEM, SYS_ELEM, SYS_NODE, SYS_TENSOR);
    vis_StateSetObject(state, VIS_GRIDFUN, gf);
    /* generated stress has gradients of 2,3,4 in x,y,z */
    for (i = 0; i < MAX_NODE; i++) {
        stress[i][0] = 2.F * coords[i][0];
        stress[i][1] = 3.F * coords[i][1];
        stress[i][2] = 4.F * coords[i][2];
        stress[i][3] = 0.;
        stress[i][4] = 0.;
        stress[i][5] = 0.;
    }
    vis_StateSetData(state, 1, (Vfloat*)stress);

    /* free face group */
    groupfree = vis_GroupBegin();
    vis_GroupDef(groupfree, MAX_ELEM, SYS_ELEM, SYS_FACE);
    vis_ConnectFaceGroup(connect, CONNECT_FREE, NULL, groupfree);

    /* create elemdat object for element face normals */
    elemdat = vis_ElemDatBegin();
    vis_ElemDatDef(elemdat, MAX_ELEM, SYS_FACE, SYS_NODE, SYS_VECTOR);
    vis_ElemDatSetObject(elemdat, VIS_GRIDFUN, gf);
    vis_ElemDatSetParamf(elemdat, ELEMDAT_FEATUREANGLE, 20.);
    vis_ElemDatSetParami(elemdat, ELEMDAT_FEATUREBRANCH, SYS_ON);
    vis_ElemDatNormal(elemdat, groupfree);

    /* instance a Threshold object */
    threshold = vis_ThresholdBegin();

    /* compute normal stress gradient on free face nodes */
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_GroupGetIndex(groupfree, i, &flags);
        if (flags == 0)
            continue;
        printf("elem= %d\n", i);

        /* gather element coordinates, etc. */
        vis_GridFunTopology(gf, i, &shape, &maxi, &maxj, &maxk);
        vis_GridFunElemNode(gf, i, &nix, ix);
        vis_GridFunCoords(gf, nix, ix, x);

        /* gather element stress */
        vis_StateData(state, 1, &i, (Vfloat*)s);
        vis_ConnectElemNum(connect, SYS_FACE, i, &nfaces);

        /* set element topology */
        vis_ThresholdSetTopology(threshold, shape, maxi, maxj, maxk);

        /* loop through element faces */
        for (j = 1; j <= nfaces; j++) {
            vis_GroupGetEntFlag(groupfree, i, j, &flagj);
            if (flagj == 0)
                continue;
            printf(" face= %d\n", j);

            /* gather face normals */
            vis_ElemDatData(elemdat, i, j, (Vfloat*)v);

            /* get face node indices into element connectivity */
            vis_GridFunElemCnn(gf, SYS_FACE, i, j, &nifx, jfx);

            /* loop through nodes on face */
            for (k = 0; k < nifx; k++) {
                /* loop through each component */
                for (n = 0; n < 6; n++) {
                    /* gather each component as a scalar per node */
                    for (m = 0; m < nix; m++) {
                        sn[m] = s[m][n];
                    }
                    /* compute gradients of normal stress field */
                    vis_ThresholdComputeGrad(threshold, sn, x, SYS_OFF, sng);
                    /* project gradient along normal direction */
                    nd = jfx[k] - 1;
                    grad = sng[nd][0] * v[k][0] + sng[nd][1] * v[k][1] + sng[nd][2] * v[k][2];
                    printf("  node= %d, comp= %d, grad= %e\n", ix[nd], n, grad);
                }
                printf("\n");
            }
        }
    }

    /* end objects */
    vis_ConnectEnd(connect);
    vis_ElemDatEnd(elemdat);
    vis_StateEnd(state);
    vis_GroupEnd(groupfree);
    vis_GridFunEnd(gf);
    vis_ThresholdEnd(threshold);
    return 0;
}
