#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Manage Tabular Functions Using TCurve
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vis_TCurve *tcurve1, *tcurve2, *tcurve;
    vis_TCurve* tc[2];
    Vdouble temp[5];
    Vdouble elas[4][2], dens[5];
    Vdouble t, f[3];
    Vint npts;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create tcurve for temperature dependent E, Nu, data */
    tcurve1 = vis_TCurveBegin();
    vis_TCurveDef(tcurve1, TCURVE_PWLINEAR, 2);

    /* set data */
    temp[0] = 20.;
    temp[1] = 100.;
    temp[2] = 150.;
    temp[3] = 180.;
    elas[0][0] = 12000000.;
    elas[0][1] = .30;
    elas[1][0] = 11000000.;
    elas[1][1] = .31;
    elas[2][0] = 10000000.;
    elas[2][1] = .33;
    elas[3][0] = 9000000.;
    elas[3][1] = .35;
    vis_TCurveSetPWLineardv(tcurve1, 4, temp, (Vdouble*)elas);

    for (i = 0; i <= 10; i++) {
        t = 20. * i;
        vis_TCurveEvaldv(tcurve1, 1, &t, f);
        printf("t= %f: E= %f,  Nu= %f\n", t, f[0], f[1]);
    }

    /* create curve for density */
    tcurve2 = vis_TCurveBegin();
    vis_TCurveDef(tcurve2, TCURVE_PWLINEAR, 1);

    /* set data */
    temp[0] = 0.;
    temp[1] = 80.;
    temp[2] = 120.;
    temp[3] = 150.;
    temp[4] = 200.;
    dens[0] = 1.0e-4;
    dens[1] = 1.2e-4;
    dens[2] = 1.3e-4;
    dens[3] = 1.4e-4;
    dens[4] = 1.5e-4;
    vis_TCurveSetPWLineardv(tcurve2, 5, temp, dens);

    /* merge curves */
    tcurve = vis_TCurveBegin();
    vis_TCurveDef(tcurve, TCURVE_PWLINEAR, 3);
    tc[0] = tcurve1;
    tc[1] = tcurve2;
    vis_TCurveMerge(tcurve, 2, tc);

    /* query for merged independent points */
    vis_TCurveNum(tcurve, &npts);
    printf("npts= %d\n", npts);
    for (i = 1; i <= npts; i++) {
        vis_TCurveIndepdv(tcurve, 1, &i, &t);
        printf("pt= %d, t= %f\n", i, t);
    }

    /* evaluate at equally spaced intervals */
    for (i = 0; i <= 10; i++) {
        t = 20. * i;
        vis_TCurveEvaldv(tcurve, 1, &t, f);
        printf("t= %f: E= %f,  Nu= %f,  rho= %f\n", t, f[0], f[1], f[2]);
    }

    /* end objects */
    vis_TCurveEnd(tcurve1);
    vis_TCurveEnd(tcurve2);
    vis_TCurveEnd(tcurve);
    return 0;
}
