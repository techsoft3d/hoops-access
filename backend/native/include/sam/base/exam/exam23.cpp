#include <stdio.h>
#include <math.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Test and Demonstrate Quadruple Precision
----------------------------------------------------------------------*/
int
main()
{
    Vdouble da, db;
    Vquad qa, qb, qc, va[3], vb[3], vc[3];
    Vint ierr;
    Vchar bufa[256], bufb[256], bufc[256];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* load and store operations */
    da = 1.23;
    db = -0.9;
    printf("Double precision numbers:\n");
    printf("da= %21.14e, db= %21.14e\n\n", da, db);
    printf("sizeof(Vquad)= %d\n", (int)sizeof(Vquad));
    qa = vut_VQuadLoad(da);
    qb = vut_VQuadLoad(db);
    vut_VQuadSPrintf(qa, 41, 1, bufa, &ierr);
    vut_VQuadSPrintf(qb, 41, 1, bufb, &ierr);
    printf("Quadruple precision numbers:\n");
    printf("qa= %s, qb= %s\n\n", bufa, bufb);

    printf("Double precision numbers:\n");
    da = vut_VQuadStore(qa, &ierr);
    db = vut_VQuadStore(qb, &ierr);
    printf("da= %21.14e, db= %21.14e\n\n", da, db);

    /* comparisons */
    printf("Comparisons:\n");
    if (vut_VQuadEQ(qa, qb)) {
        printf("%s == %s\n", bufa, bufb);
    }
    else {
        printf("%s != %s\n", bufa, bufb);
    }

    if (vut_VQuadGE(qa, qb)) {
        printf("%s >= %s\n", bufa, bufb);
    }
    else {
        printf("%s <  %s\n", bufa, bufb);
    }

    if (vut_VQuadGT(qa, qb)) {
        printf("%s >  %s\n", bufa, bufb);
    }
    else {
        printf("%s <= %s\n", bufa, bufb);
    }

    if (vut_VQuadLE(qa, qb)) {
        printf("%s <= %s\n", bufa, bufb);
    }
    else {
        printf("%s >  %s\n", bufa, bufb);
    }

    if (vut_VQuadLT(qa, qb)) {
        printf("%s <  %s\n", bufa, bufb);
    }
    else {
        printf("%s >= %s\n\n", bufa, bufb);
    }

    /* arithmetic operation */
    printf("Arithmetic operations:\n");
    qc = vut_VQuadSub(qa, qb, &ierr);
    vut_VQuadSPrintf(qc, 41, 1, bufc, &ierr);
    printf("%s - %s = %s\n", bufa, bufb, bufc);

    qc = vut_VQuadMult(qa, qb, &ierr);
    vut_VQuadSPrintf(qc, 41, 1, bufc, &ierr);
    printf("%s * %s = %s\n", bufa, bufb, bufc);

    qc = vut_VQuadDiv(qa, qb, &ierr);
    vut_VQuadSPrintf(qc, 41, 1, bufc, &ierr);
    printf("%s / %s = %s\n", bufa, bufb, bufc);

    qa = vut_VQuadLoad(2.0);
    vut_VQuadSPrintf(qa, 41, 1, bufa, &ierr);
    qb = vut_VQuadSqrt(qa, &ierr);
    vut_VQuadSPrintf(qb, 41, 1, bufb, &ierr);
    printf("sqrt(%s) = %s\n", bufa, bufb);
    qc = vut_VQuadMult(qb, qb, &ierr);
    vut_VQuadSPrintf(qc, 41, 1, bufc, &ierr);
    printf("%s * %s = %s\n\n", bufb, bufb, bufc);

    qc = vut_VQuadNeg(qa);
    vut_VQuadSPrintf(qc, 41, 1, bufc, &ierr);
    printf("-(%s) = %s\n", bufa, bufc);

    qa = vut_VQuadLoad(-2.0);
    vut_VQuadSPrintf(qa, 41, 1, bufa, &ierr);
    qb = vut_VQuadAbs(qc);
    vut_VQuadSPrintf(qb, 41, 1, bufb, &ierr);
    printf("abs(%s) = %s\n", bufc, bufb);

    /* vector operation */
    printf("Vector operations:\n");
    va[0] = vut_VQuadLoad(0.);
    va[1] = vut_VQuadLoad(3.);
    va[2] = vut_VQuadLoad(4.);
    vut_VQuadSPrintf(va[0], 41, 1, bufa, &ierr);
    vut_VQuadSPrintf(va[1], 41, 1, bufb, &ierr);
    vut_VQuadSPrintf(va[2], 41, 1, bufc, &ierr);
    printf("va= %s\n    %s\n    %s\n", bufa, bufb, bufc);

    vb[0] = vut_VQuadLoad(2.);
    vb[1] = vut_VQuadLoad(3.);
    vb[2] = vut_VQuadLoad(4.);
    vut_VQuadSPrintf(vb[0], 41, 1, bufa, &ierr);
    vut_VQuadSPrintf(vb[1], 41, 1, bufb, &ierr);
    vut_VQuadSPrintf(vb[2], 41, 1, bufc, &ierr);
    printf("va= %s\n    %s\n    %s\n", bufa, bufb, bufc);

    qa = vut_VQuadDot3(va, va, &ierr);
    vut_VQuadSPrintf(qa, 41, 1, bufa, &ierr);
    printf("Dot3(va,va) = %s\n", bufa);

    qa = vut_VQuadMag3(va, &ierr);
    vut_VQuadSPrintf(qa, 41, 1, bufa, &ierr);
    printf("Mag3(va) = %s\n", bufa);

    vut_VQuadCross3(va, vb, vc, &ierr);
    vut_VQuadSPrintf(vc[0], 41, 1, bufa, &ierr);
    vut_VQuadSPrintf(vc[1], 41, 1, bufb, &ierr);
    vut_VQuadSPrintf(vc[2], 41, 1, bufc, &ierr);
    printf("va X vb = %s\n          %s\n          %s\n", bufa, bufb, bufc);

    vut_VQuadUnit3(va, &ierr);
    vut_VQuadSPrintf(va[0], 41, 1, bufa, &ierr);
    vut_VQuadSPrintf(va[1], 41, 1, bufb, &ierr);
    vut_VQuadSPrintf(va[2], 41, 1, bufc, &ierr);
    printf("Unit3(va)= %s\n           %s\n           %s\n", bufa, bufb, bufc);
    return 0;
}
