#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_EProp(vis_EProp* eprop);

/*----------------------------------------------------------------------
                      Composite Shell and General Beam Property Using EProp
----------------------------------------------------------------------*/
int
main()
{
    vis_EProp *eprop, *epropb;
    Vint nlay, mid[4];
    Vdouble thk[4], phi[4];
    Vint midb;
    Vdouble a, iyy, izz, j, cw;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create eprop for shell element composite property */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, VIS_ELEM_SHELL);
    vis_EPropSetValuei(eprop, EPROP_SHELLWALL, SYS_SHELLWALL_LAMINATE);
    /* 4 layers */
    nlay = 4;
    /* material ids */
    mid[0] = 1;
    mid[1] = 2;
    mid[2] = 2;
    mid[3] = 1;
    /* thicknesses */
    thk[0] = .2;
    thk[1] = .1;
    thk[2] = .1;
    thk[3] = .2;
    /* layup angles in degrees */
    phi[0] = 0.;
    phi[1] = 45.;
    phi[2] = -45.;
    phi[3] = 0.;
    vis_EPropSetValuei(eprop, EPROP_LAYER_NUM, nlay);
    vis_EPropSetValueiv(eprop, EPROP_LAYER_MID, mid);
    vis_EPropSetValuedv(eprop, EPROP_LAYER_THK, thk);
    vis_EPropSetValuedv(eprop, EPROP_LAYER_PHI, phi);
    /* set optional eccentricity */
    vis_EPropSetValued(eprop, EPROP_ECC, .3);
    /* print contents of shell EProp */
    print_EProp(eprop);

    /* create eprop for general beam element property */
    epropb = vis_EPropBegin();
    vis_EPropDef(epropb, VIS_ELEM_BEAM);
    vis_EPropSetValuei(epropb, EPROP_BEAMSECT, SYS_BEAMSECT_PROPS);
    /* set material id */
    midb = 10;
    vis_EPropSetValuei(epropb, EPROP_MID, midb);
    /* 3 by 2 rectangular beam */
    a = 6.;
    iyy = 2.;
    izz = 4.5;
    j = 4.7017;
    cw = 0.24272;
    /* set section properties */
    vis_EPropSetValued(epropb, EPROP_AREA, a);
    vis_EPropSetValued(epropb, EPROP_IYY, iyy);
    vis_EPropSetValued(eprop, EPROP_IZZ, izz);
    vis_EPropSetValued(epropb, EPROP_IYZ, 0.);
    vis_EPropSetValued(epropb, EPROP_J, j);
    vis_EPropSetValued(epropb, EPROP_CW, cw);
    /* print contents of beam EProp */
    print_EProp(epropb);

    /* delete objects */
    vis_EPropEnd(eprop);
    vis_EPropEnd(epropb);
}

/*----------------------------------------------------------------------
                      print EProp
----------------------------------------------------------------------*/
static void
print_EProp(vis_EProp* eprop)
{
    Vint i, j, k;
    Vint* iparams = NULL;
    Vdouble* dparams = NULL;
    Vint ntypes, *type;
    Vint nval, nloc, dtyp;
    Vchar name[64];
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

        if (dtyp == SYS_INTEGER) {
            /* integer valued */
            printf(" Integer\n");
            iparams = (Vint*)vut_MemoryMalloc(nval * nloc * sizeof(Vint));
            vis_EPropValueInteger(eprop, type[i], iparams);
            for (j = 0; j < nval; j++) {
                printf("  value= %d\n", iparams[j]);
            }
            vut_MemoryFree(iparams);
        }
        else {
            /* real valued */
            printf(" Real\n");
            dparams = (Vdouble*)vut_MemoryMalloc(nval * nloc * sizeof(Vdouble));
            vis_EPropValueDouble(eprop, type[i], dparams);
            for (k = 0; k < nloc; k++) {
                printf(" Location= %d\n", k);
                for (j = 0; j < nval; j++) {
                    printf("  value= %e\n", dparams[k * nval + j]);
                }
            }
            vut_MemoryFree(dparams);
        }
    }
    free(type);
    return;
}
