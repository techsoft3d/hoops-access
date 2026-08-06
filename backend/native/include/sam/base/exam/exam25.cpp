#include <stdio.h>
#include <math.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Test and demonstrate Pred
----------------------------------------------------------------------*/
int
main()
{
    Vdouble x[4][3], e[3], xt[3][3], xl[2][3], xl0[2][2], xl1[2][2];
    vsy_Pred* pred;
    Vdouble retval;
    Vint pass;
    Vint code, ient, ierr;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance object */
    pred = vsy_PredBegin();
    /* push FPU control words */
    vsy_PredPushFPU(pred);
    /* check to see if Pred is exact */
    vsy_PredExact(pred, &pass);
    if (pass == 0) {
        printf("Pred is unable to do exact arithmetic, check compiler options\n");
    }
    else {
        printf("Pred is able to do exact arithmetic\n");
    }
    /* set tetrahedron vertices for right tetrahedron */
    /* first node at origin */
    x[0][0] = 0.;
    x[0][1] = 0.;
    x[0][2] = 0.;
    /* second node on x-axis */
    x[1][0] = 1.;
    x[1][1] = 0.;
    x[1][2] = 0.;
    /* third node on y-axis */
    x[2][0] = 0.;
    x[2][1] = 1.;
    x[2][2] = 0.;
    /* fourth node on z-axis */
    x[3][0] = 0.;
    x[3][1] = 0.;
    x[3][2] = 1.;
    /* test point for insphere */
    e[0] = 20.;
    e[1] = .25;
    e[2] = .25;
    retval = vsy_PredInsphere(pred, x[0], x[1], x[2], x[3], e);
    printf("Point outside sphere: retval= %e\n", retval);

    e[0] = .2;
    e[1] = .25;
    e[2] = .25;
    retval = vsy_PredInsphere(pred, x[0], x[1], x[2], x[3], e);
    printf("Point inside sphere: retval= %e\n", retval);

    e[0] = 0.;
    e[1] = 0.;
    e[2] = 0.;
    retval = vsy_PredInsphere(pred, x[0], x[1], x[2], x[3], e);
    printf("Point on sphere: retval= %e\n", retval);

    /* compute orientation */
    /* return value should be positive */
    retval = vsy_PredOrient3d(pred, x[0], x[1], x[2], x[3]);
    printf("Proper tetrahedron: retval= %e\n", retval);

    /* move second point close to plane of 1,3 and 4th points */
    /* return value should be positive */
    x[1][0] = 1.e-100;
    x[1][1] = 0.5;
    x[1][2] = 0.5;
    retval = vsy_PredOrient3d(pred, x[0], x[1], x[2], x[3]);
    printf("Proper tetrahedron: retval= %e\n", retval);
    /* move second point to plane of 1,3 and 4th points */
    /* return value should be zero */
    x[1][0] = 0.;
    x[1][1] = 0.5;
    x[1][2] = 0.5;
    retval = vsy_PredOrient3d(pred, x[0], x[1], x[2], x[3]);
    printf("Degenerate tetrahedron: retval= %e\n", retval);
    /* move second point beyond plane of 1,3 and 4th points */
    /* return value should be negative */
    x[1][0] = -1.e-100;
    x[1][1] = 0.5;
    x[1][2] = 0.5;
    retval = vsy_PredOrient3d(pred, x[0], x[1], x[2], x[3]);
    printf("Inverted tetrahedron: retval= %e\n", retval);

    /* compute line tri intersection status */
    xt[0][0] = 0.;
    xt[0][1] = 0.;
    xt[0][2] = 0.;
    /* second node on x-axis */
    xt[1][0] = 1.;
    xt[1][1] = 0.;
    xt[1][2] = 0.;
    /* third node on y-axis */
    xt[2][0] = 0.;
    xt[2][1] = 1.;
    xt[2][2] = 0.;
    /* line endpoints */
    xl[0][0] = -1.;
    xl[0][1] = 0.;
    xl[0][2] = 0.;
    xl[1][0] = 0.;
    xl[1][1] = 2.;
    xl[1][2] = 0.;
    vsy_PredIntersectLineTri(pred, xt, xl, &code, &ient, &ierr);
    printf("Line Tri no intersection, code= %d\n", code);
    /* line end point in triangle interior */
    xl[1][0] = .25;
    xl[1][1] = .25;
    xl[1][2] = 0.;
    vsy_PredIntersectLineTri(pred, xt, xl, &code, &ient, &ierr);
    printf("Line Tri coplanar intersection, code= %d\n", code);
    /* line spans triangle */
    xl[1][0] = .75;
    xl[1][1] = .75;
    xl[1][2] = 0.;
    vsy_PredIntersectLineTri(pred, xt, xl, &code, &ient, &ierr);
    printf("Line Tri coplanar intersection, code= %d\n", code);

    /* two-dimension tests */
    /* set circle points */
    x[0][0] = -1.;
    x[0][1] = 0.;
    x[1][0] = 1.;
    x[1][1] = 0.;
    x[2][0] = 0.;
    x[2][1] = 1.;

    /* check point inside circle */
    e[0] = 0.;
    e[1] = 0.;
    retval = vsy_PredIncircle(pred, x[0], x[1], x[2], e);
    printf("Point inside circle: retval= %e\n", retval);

    /* check point outside circle */
    e[0] = 2.;
    e[1] = 0.;
    retval = vsy_PredIncircle(pred, x[0], x[1], x[2], e);
    printf("Point outside circle: retval= %e\n", retval);

    /* check point on circle */
    e[0] = 0.;
    e[1] = -1.;
    retval = vsy_PredIncircle(pred, x[0], x[1], x[2], e);
    printf("Point on circle: retval= %e\n", retval);

    /* check properly defined triangle */
    x[0][0] = 0.;
    x[0][1] = 0.;
    x[1][0] = 1.;
    x[1][1] = 0.;
    x[2][0] = 0.;
    x[2][1] = 1.;
    retval = vsy_PredOrient2d(pred, x[0], x[1], x[2]);
    printf("Proper triangle: retval= %e\n", retval);

    /* check degenerate triangle */
    x[0][0] = 0.;
    x[0][1] = 0.;
    x[1][0] = 1.;
    x[1][1] = 0.;
    x[2][0] = 0.5;
    x[2][1] = 0.;
    retval = vsy_PredOrient2d(pred, x[0], x[1], x[2]);
    printf("Degenerate triangle: retval= %e\n", retval);

    /* check inverted triangle */
    x[0][0] = 0.;
    x[0][1] = 0.;
    x[1][0] = 1.;
    x[1][1] = 0.;
    x[2][0] = 0.;
    x[2][1] = -1.;
    retval = vsy_PredOrient2d(pred, x[0], x[1], x[2]);
    printf("Inverted triangle: retval= %e\n", retval);

    /* compute line line intersection status */
    xl0[0][0] = 0.;
    xl0[0][1] = 0.;
    xl0[1][0] = 1.;
    xl0[1][1] = 0.;
    xl1[0][0] = -1.;
    xl1[0][1] = 0.;
    xl1[1][0] = 2.;
    xl1[1][1] = 0.;
    vsy_PredIntersectLineLine(pred, xl0, xl1, &code, &ient, &ierr);
    printf("Line Line intersection, code= %d, ient= %d\n", code, ient);

    /* pop (restore) FPU control words */
    vsy_PredPopFPU(pred);

    vsy_PredEnd(pred);
    return 0;
}
