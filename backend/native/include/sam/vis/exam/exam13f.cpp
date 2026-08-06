#include <stdio.h>
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vdouble vy[3] = {0., 1., 0.};
static Vdouble vz[3] = {0., 0., 1.};
static Vdouble origin[3] = {0., 0., 0.};

static Vint loop[3][4] = {{1, 2, 5, 8}, {2, 3, 4, 5}, {5, 6, 7, 8}};
static Vdouble elast[3][2] = {{1.e+7, 0.1}, {2.e+6, 0.2}, {3.e+7, 0.3}};
static Vdouble x[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {5., 0., 0.}, {5., 2., 0.},
                          {1., 2., 0.}, {1., 4., 0.}, {0., 4., 0.}, {0., 2., 0.}};

/*----------------------------------------------------------------------
                      Compute Composite Beam Section Properties
----------------------------------------------------------------------*/
int
main()
{
    vis_BeamSect* beamsect;
    vis_Connect* connect;
    vis_State *states, *statee;
    vis_RProp *rprops, *rprope;
    vis_GridFun* gridfun;
    Vdouble eks[6], strs[36], strn[36];
    Vint i, j, n;
    Vdouble props[BEAMSECT_MAXPROPS], dmat[21], xp[3];
    Vint ix[6], mid;
    Vint npoints, nloops, nlines, ntris, nqualpnts, nqualtris;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance BeamSect for comparison */
    beamsect = vis_BeamSectBegin();

    /* generate data in arbitrary coordinates */
    vis_BeamSectDef(beamsect, BEAMSECT_GEOMETRY);
    for (n = 1; n <= 8; n++) {
        vis_BeamSectSetPointdv(beamsect, n, x[n - 1]);
    }
    for (n = 1; n <= 3; n++) {
        mid = n;
        vis_BeamSectSetLoop(beamsect, n, mid, 4, loop[n - 1]);
        vis_BeamSectSetElasPropdv(beamsect, mid, SYS_MAT_ISOTROPIC, elast[n - 1]);
    }
    vis_BeamSectSetParami(beamsect, BEAMSECT_VABS, SYS_ON);
    vis_BeamSectProps(beamsect);
    vis_BeamSectGetPropsdv(beamsect, props, dmat);

    /* print Timoshenko stiffness matrix */
    for (n = 0, i = 0; i < 6; i++) {
        for (j = 0; j <= i; j++, n++) {
            printf("%11.4e ", dmat[n]);
        }
        printf("\n");
    }
    /* determine number of quality points and triangles */
    vis_BeamSectGetNum(beamsect, &npoints, &nloops, &nlines, &ntris, &nqualpnts, &nqualtris);

    /* save model to IDEAS Universal file */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, nqualpnts, nqualtris);
    for (n = 1; n <= nqualpnts; n++) {
        vis_BeamSectCoordsdv(beamsect, n, origin, vy, vz, xp);
        vis_ConnectSetCoordsdv(connect, n, xp);
    }
    for (n = 1; n <= nqualtris; n++) {
        vis_BeamSectGetQualTri(beamsect, n, ix, &mid);
        vis_ConnectSetTopology(connect, n, SYS_SHAPETRI, 3, 0, 0);
        vis_ConnectSetElemNode(connect, n, ix);
        vis_ConnectSetElemAssoc(connect, VIS_MATLID, n, mid);
    }
    vis_ConnectWrite(connect, SYS_SDRC_UNIVERSAL, "exam13f.unv");

    /* set stress and strain states */
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);

    statee = vis_StateBegin();
    vis_StateSetObject(statee, VIS_GRIDFUN, (Vobject*)gridfun);
    vis_StateDef(statee, nqualtris, SYS_ELEM, SYS_NODE, SYS_TENSOR);
    rprope = vis_RPropBegin();
    vis_RPropSetType(rprope, SYS_RES_E);
    vis_RPropSetIds(rprope, 1, 0, 0);

    states = vis_StateBegin();
    vis_StateSetObject(states, VIS_GRIDFUN, (Vobject*)gridfun);
    vis_StateDef(states, nqualtris, SYS_ELEM, SYS_NODE, SYS_TENSOR);
    rprops = vis_RPropBegin();
    vis_RPropSetType(rprops, SYS_RES_S);
    vis_RPropSetIds(rprops, 1, 0, 0);

    /* set centroidal strain, curvature, twist */
    eks[0] = .001;
    eks[1] = .002;
    eks[2] = .003;
    eks[3] = .004;
    eks[4] = .005;
    eks[5] = .006;
    /* evaluate stress and strain at each quality element */
    for (n = 1; n <= nqualtris; n++) {
        vis_BeamSectGetQualTri(beamsect, n, ix, &mid);
        vis_BeamSectElemStrsStrndv(beamsect, n, eks, strs, strn);
        printf("element= %d, mid= %d\n", n, mid);
        for (i = 0; i < 6; ++i) {
            printf("   node= %d\n", i + 1);
            printf("      strain= %11.4e %11.4e %11.4e %11.4e %11.4e %11.4e\n", strn[6 * i], strn[6 * i + 1], strn[6 * i + 2],
                   strn[6 * i + 3], strn[6 * i + 4], strn[6 * i + 5]);
            printf("      stress= %11.4e %11.4e %11.4e %11.4e %11.4e %11.4e\n", strs[6 * i], strs[6 * i + 1], strs[6 * i + 2],
                   strs[6 * i + 3], strs[6 * i + 4], strs[6 * i + 5]);
            vis_StateSetDatadv(statee, n, strn);
            vis_StateSetDatadv(states, n, strs);
        }
    }
    vis_StateWrite(statee, rprope, SYS_SDRC_UNIVERSAL, "exam13f.unv");
    vis_StateWrite(states, rprops, SYS_SDRC_UNIVERSAL, "exam13f.unv");

    /* clean up*/
    vis_StateEnd(statee);
    vis_StateEnd(states);
    vis_RPropEnd(rprope);
    vis_RPropEnd(rprops);
    vis_GridFunEnd(gridfun);
    vis_ConnectEnd(connect);
    vis_BeamSectEnd(beamsect);
    return 0;
}
