#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Manage Sparse Degree of Freedom Data Using RedMat
----------------------------------------------------------------------*/
int
main()
{
    vis_RedMat* redmat;
    Vint i, j, n;
    Vint i1;
    Vdouble dv[2];
    Vint nrows, type, sparse;
    Vint ncols, cols[10];

    vsy_LicenseValidate(HOOPS_LICENSE);

    redmat = vis_RedMatBegin();

    /* define a tridiagonal symmetric matrix */
    vis_RedMatDef(redmat, 10, SYS_MATRIX_SYMM);
    /* define row sizes first */
    for (i = 1; i <= 10; i++) {
        if (i == 1) {
            vis_RedMatSetDataSize(redmat, i, 1);
        }
        else {
            vis_RedMatSetDataSize(redmat, i, 2);
        }
    }
    /* set data */
    for (n = 1, i = 1; i <= 10; i++) {
        if (i == 1) {
            i1 = 1;
        }
        else {
            i1 = i - 1;
        }
        for (j = i1; j <= i; j++, n++) {
            dv[0] = n;
            vis_RedMatSetDatadv(redmat, i, j, dv);
        }
    }
    /* access data and print */
    vis_RedMatInq(redmat, &nrows, &type);
    /* inquire sparsity */
    vis_RedMatSparse(redmat, &sparse);
    printf("nrows= %d, sparse= %d\n", nrows, sparse);
    for (i = 1; i <= nrows; i++) {
        vis_RedMatDataCols(redmat, i, &ncols, cols);
        for (j = 0; j < ncols; j++) {
            vis_RedMatDatadv(redmat, i, cols[j], dv);
            printf(" i= %d, j= %d, v= %le\n", i, cols[j], dv[0]);
        }
    }
    /* destroy object */
    vis_RedMatEnd(redmat);
    return 0;
}
