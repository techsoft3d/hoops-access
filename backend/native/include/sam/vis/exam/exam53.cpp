#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Manage System Degree of Freedom Data Using RedMat
----------------------------------------------------------------------*/
int
main()
{
    vis_RedMat* redmat;
    Vint i, j, n, doftag;
    Vfloat fv[2];
    Vdouble dv[2];

    vsy_LicenseValidate(HOOPS_LICENSE);

    redmat = vis_RedMatBegin();
    /* define a diagonal matrix */
    vis_RedMatDef(redmat, 10, SYS_MATRIX_DIAG);
    for (i = 1; i <= 10; ++i) {
        dv[0] = i;
        vis_RedMatSetDatadv(redmat, i, i, dv);
    }
    printf("SYS_MATRIX_DIAG:\n");
    for (i = 1; i <= 10; ++i) {
        vis_RedMatData(redmat, i, i, fv);
        printf("   i= %2d, j= %2d, fv= %11.4e\n", i, i, fv[0]);
    }
    for (i = 1; i <= 10; ++i) {
        vis_RedMatDatadv(redmat, i, i, dv);
        printf("   i= %2d, j= %2d, dv= %11.4e\n", i, i, dv[0]);
    }
    /* define a complex symmetric matrix, lower triangle */
    vis_RedMatDef(redmat, 10, SYS_MATRIX_SYMM);
    vis_RedMatSetComplexMode(redmat, SYS_COMPLEX_REALIMAGINARY);
    for (n = 1, j = 1; j <= 10; ++j) {
        for (i = 1; i <= j; ++i, ++n) {
            dv[0] = 2 * n;
            dv[1] = 2 * n + 1;
            vis_RedMatSetDatadv(redmat, i, j, dv);
        }
    }
    /* add associated entity index and dof tag */
    /* nodes 1 throught 5, doftags translation x and y */
    for (i = 1; i <= 10; ++i) {
        n = (i - 1) / 2 + 1;
        if ((i - 1) % 2 == 0) {
            doftag = SYS_DOF_TX;
        }
        else {
            doftag = SYS_DOF_TY;
        }
        vis_RedMatSetDof(redmat, i, n, doftag);
    }

    printf("SYS_MATRIX_SYMM:\n");
    for (j = 1; j <= 10; ++j) {
        vis_RedMatGetDof(redmat, j, &n, &doftag);
        printf("   j= %2d, n= %d, doftag= %d\n", j, n, doftag);
        for (i = 1; i <= j; ++i) {
            vis_RedMatData(redmat, i, j, fv);
            printf("   i= %2d, j= %2d, fv= %11.4e %11.4e\n", i, j, fv[0], fv[1]);
        }
    }
    for (j = 1; j <= 10; ++j) {
        for (i = 1; i <= j; ++i) {
            vis_RedMatDatadv(redmat, i, j, dv);
            printf("   i= %2d, j= %2d, dv= %11.4e\n", i, j, dv[0]);
        }
    }
    /* define an unsymmetric matrix */
    vis_RedMatDef(redmat, 10, SYS_MATRIX_USYMM);
    vis_RedMatSetComplexMode(redmat, SYS_COMPLEX_REAL);
    for (n = 1, j = 1; j <= 10; ++j) {
        for (i = 1; i <= 10; ++i, ++n) {
            dv[0] = n;
            vis_RedMatSetDatadv(redmat, i, j, dv);
        }
    }
    printf("SYS_MATRIX_USYMM:\n");
    for (j = 1; j <= 10; ++j) {
        for (i = 1; i <= 10; ++i) {
            vis_RedMatData(redmat, i, j, fv);
            printf("   i= %2d, j= %2d, fv= %11.4e\n", i, j, fv[0]);
        }
    }
    for (j = 1; j <= 10; ++j) {
        for (i = 1; i <= 10; ++i) {
            vis_RedMatDatadv(redmat, i, j, dv);
            printf("   i= %2d, j= %2d, dv= %11.4e\n", i, j, dv[0]);
        }
    }
    /* define a vector, single row */
    vis_RedMatDef(redmat, 10, SYS_VECTOR);
    i = 1;
    for (j = 1; j <= 10; ++j) {
        dv[0] = j;
        vis_RedMatSetDatadv(redmat, i, j, dv);
    }
    printf("SYS_VECTOR:\n");
    for (j = 1; j <= 10; ++j) {
        vis_RedMatData(redmat, i, j, fv);
        printf("   i= %2d, j= %2d, fv= %11.4e\n", i, j, fv[0]);
    }
    for (j = 1; j <= 10; ++j) {
        vis_RedMatDatadv(redmat, i, j, dv);
        printf("   i= %2d, j= %2d, dv= %11.4e\n", i, j, dv[0]);
    }
    /* destroy object */
    vis_RedMatEnd(redmat);
    return 0;
}
