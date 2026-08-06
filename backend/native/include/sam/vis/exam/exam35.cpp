#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Manage Material Properties Using MProp
----------------------------------------------------------------------*/
int
main()
{
    Vint i, j;
    Vint iparams[1];
    Vdouble dparams[3];
    vis_MProp* mprop;
    Vdouble eort[3], nuort[3], gort[3], kort[3];
    Vint ntypes, *type;
    Vint nval, dtyp;
    Vchar name[64];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create mprop for linear orthotropic properties */
    mprop = vis_MPropBegin();
    vis_MPropDef(mprop, SYS_MAT_ORTHOTROPIC);

    /* set material density */
    vis_MPropSetValued(mprop, MPROP_DENSITY, 7800.);

    /* install elastic moduli */
    eort[0] = 2.1e+11;
    eort[1] = 1.1e+11;
    eort[2] = 1.2e+11;
    vis_MPropSetValuedv(mprop, MPROP_EORT, eort);
    nuort[0] = .3;
    nuort[1] = .3;
    nuort[2] = .3;
    vis_MPropSetValuedv(mprop, MPROP_NUORT, nuort);
    gort[0] = .4e+11;
    gort[1] = .3e+11;
    gort[2] = .3e+11;
    vis_MPropSetValuedv(mprop, MPROP_GORT, gort);

    /* thermal conductivity and specific heat */
    kort[0] = 55.;
    kort[1] = 30.;
    kort[2] = 25.;
    vis_MPropSetValuedv(mprop, MPROP_KORT, kort);
    vis_MPropSetValued(mprop, MPROP_CP, 465.);

    /* traverse defined material properties */
    vis_MPropValueTypeNum(mprop, &ntypes);
    printf("ntypes = %d\n", ntypes);
    type = (Vint*)malloc(ntypes * sizeof(Vint));
    vis_MPropValueType(mprop, &ntypes, type);

    /* loop through types */
    for (i = 0; i < ntypes; i++) {
        vis_MPropValueName(mprop, type[i], name);
        printf("\n name = %s\n", name);
        vis_MPropValueParams(mprop, type[i], &nval, &dtyp);
        printf(" nval= %d\n", nval);

        /* integer valued */
        if (dtyp == SYS_INTEGER) {
            printf(" Integer\n");
            vis_MPropValueInteger(mprop, type[i], iparams);
            for (j = 0; j < nval; j++) {
                printf("  value= %d\n", iparams[j]);
            }
            /* real valued */
        }
        else {
            vis_MPropValueDouble(mprop, type[i], dparams);
            printf(" Real\n");
            for (j = 0; j < nval; j++) {
                printf("  value= %e\n", dparams[j]);
            }
        }
    }
    /* end objects */
    free(type);
    vis_MPropEnd(mprop);
    return 0;
}
