#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Manage Element Properties Using EProp
----------------------------------------------------------------------*/
int
main()
{
    Vint i, j, k;
    Vint iparams[1];
    Vdouble dparams[4];
    vis_EProp* eprop;
    Vint ntypes, *type;
    Vint nval, nloc, dtyp;
    Vchar name[64];
    Vdouble cthick[4], thick[8];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create eprop for shell element properties */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, VIS_ELEM_SHELL);

    /* set material id */
    vis_EPropSetValuei(eprop, EPROP_MID, 1);

    /* install corner thicknesses */
    cthick[0] = .5;
    cthick[1] = .5;
    cthick[2] = 1.5;
    cthick[3] = 1.5;
    vis_EPropSetValuedv(eprop, EPROP_THICKNESS, cthick);

    /* compute thicknesses for 8 node shell */
    vis_EPropEvaldv(eprop, EPROP_THICKNESS, VIS_SHAPEQUAD, 3, 0, thick);
    printf("\nElement node thickness:\n");
    for (i = 0; i < 8; i++) {
        printf("thickness= %e\n", thick[i]);
    }
    /* traverse defined element properties */
    vis_EPropValueTypeNum(eprop, &ntypes);
    printf("ntypes = %d\n", ntypes);
    type = (Vint*)malloc(ntypes * sizeof(Vint));
    vis_EPropValueType(eprop, &ntypes, type);

    /* loop through types */
    for (i = 0; i < ntypes; i++) {
        vis_EPropValueName(eprop, type[i], name);
        printf("\n name = %s\n", name);
        vis_EPropValueParams(eprop, type[i], &nval, &nloc, &dtyp);
        printf(" nval= %d, nloc= %d\n", nval, nloc);

        /* integer valued */
        if (dtyp == SYS_INTEGER) {
            printf(" Integer\n");
            vis_EPropValueInteger(eprop, type[i], iparams);
            for (j = 0; j < nval; j++) {
                printf("  value= %d\n", iparams[j]);
            }
            /* real valued */
        }
        else {
            vis_EPropValueDouble(eprop, type[i], dparams);
            printf(" Real\n");
            for (k = 0; k < nloc; k++) {
                printf(" Location= %d\n", k);
                for (j = 0; j < nval; j++) {
                    printf("  value= %e\n", dparams[k * nval + j]);
                }
            }
        }
    }
    /* end objects */
    free(type);
    vis_EPropEnd(eprop);
    return 0;
}
