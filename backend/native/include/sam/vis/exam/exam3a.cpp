#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* sample tensor */
static Vdouble td[6] = {5.2586293220520020,  0.32901409268379211,   -0.18742503225803375,
                        0.23982234299182892, -0.042775686830282211, 0.76196306943893433};

/*----------------------------------------------------------------------
                      Tensor Computations Using Mark
----------------------------------------------------------------------*/
int
main()
{
    vis_Mark* mark;

    int i, j;
    Vfloat ts[6];
    Vfloat vs[6], tms[3][3];
    Vdouble vd[6], tmd[3][3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create mark object */
    mark = vis_MarkBegin();
    /* load double precison tensor into single */
    for (i = 0; i < 6; i++) {
        ts[i] = (Vfloat)td[i];
    }
    /* compute principal values in single, double precision */
    vis_MarkTensorPrincipal(mark, ts, vs, tms);
    printf("Single precision\n");
    printf("Principal values\n");
    for (i = 0; i < 3; i++) {
        printf(" %e\n", vs[i]);
    }
    printf("Principal directions\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %16.9e", tms[i][j]);
        }
        printf("\n");
    }

    vis_MarkTensorPrincipaldv(mark, td, vd, tmd);
    printf("Double precision\n");
    printf("Principal values\n");
    for (i = 0; i < 3; i++) {
        printf(" %e\n", vd[i]);
    }
    printf("Principal directions\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %16.9e", tmd[i][j]);
        }
        printf("\n");
    }

    /* compute max shear values in single, double precision */
    vis_MarkTensorMaxShear(mark, ts, vs, tms);
    printf("Single precision\n");
    printf("Max Shear values\n");
    for (i = 0; i < 6; i++) {
        printf(" %e\n", vs[i]);
    }
    printf("Max Shear directions\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %16.9e", tms[i][j]);
        }
        printf("\n");
    }

    vis_MarkTensorMaxSheardv(mark, td, vd, tmd);
    printf("Double precision\n");
    printf("Max Shear values\n");
    for (i = 0; i < 6; i++) {
        printf(" %e\n", vd[i]);
    }
    printf("Max Shear directions\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %16.9e", tmd[i][j]);
        }
        printf("\n");
    }

    vis_MarkEnd(mark);
    return 0;
}
