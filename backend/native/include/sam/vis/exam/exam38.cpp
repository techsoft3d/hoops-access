#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Manage Result Properties Using RProp
----------------------------------------------------------------------*/
int
main()
{
    Vint i, j;
    Vint type, id1, id2, id3;
    Vint iparams[2];
    Vdouble dparams[2];
    Vchar cparams[81];
    vis_RProp* rprop;
    Vint ntypes, types[RPROP_MAX];
    Vint nval, dtyp;
    Vchar name[64];
    Vint nqua, iqua[SYS_NQUA_MAX];
    Vchar cqua[64];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create rprop for stress results */
    rprop = vis_RPropBegin();
    vis_RPropDef(rprop, SYS_ELEM, SYS_NONE);

    /* set type */
    vis_RPropSetType(rprop, SYS_RES_S);

    /* set optional qualifier(s) */
    iqua[0] = SYS_QUA_EQUIV;
    iqua[1] = SYS_QUA_PLAST;
    vis_RPropSetQual(rprop, 2, iqua, NULL);

    /* set ids */
    vis_RPropSetIds(rprop, 1, 2, 0);

    /* query primary properties */
    vis_RPropGetType(rprop, &type);
    vis_RPropGetQual(rprop, &nqua, iqua, cqua);
    vis_RPropGetIds(rprop, &id1, &id2, &id3);
    printf("type = %d\n", type);
    printf("nqua = %d\n", nqua);
    for (i = 0; i < nqua; i++) {
        printf("iqua[%d] = %d\n", i, iqua[i]);
    }
    printf("cqua = %s\n", cqua);
    printf("id1,id2,id3 = %d %d %d\n", id1, id2, id3);

    /* query equivalent dataset name */
    vis_RPropGetDatasetName(rprop, name);
    printf("dataset name = %s\n", name);

    /* set titles */
    vis_RPropSetValuec(rprop, RPROP_TITLE, (Vchar*)"Drop test case");
    vis_RPropSetValuec(rprop, RPROP_SUBTITLE, (Vchar*)"Oblique strike");

    /* set load factor */
    vis_RPropSetValued(rprop, RPROP_LOADFACTOR, 1.);

    /* traverse defined solution properties */
    vis_RPropValueType(rprop, &ntypes, types);
    printf("\n ntypes = %d\n", ntypes);

    /* loop through types */
    for (i = 0; i < ntypes; i++) {
        vis_RPropValueName(rprop, types[i], name);
        printf("\n name = %s\n", name);
        vis_RPropValueParams(rprop, types[i], &nval, &dtyp);
        printf(" nval= %d\n", nval);

        /* integer valued */
        if (dtyp == SYS_INTEGER) {
            printf(" Integer\n");
            vis_RPropValueInteger(rprop, types[i], iparams);
            for (j = 0; j < nval; j++) {
                printf("  value= %d\n", iparams[j]);
            }
            /* real valued */
        }
        else if (dtyp == SYS_REAL) {
            vis_RPropValueDouble(rprop, types[i], dparams);
            printf(" Real\n");
            for (j = 0; j < nval; j++) {
                printf("  value= %e\n", dparams[j]);
            }
            /* character valued */
        }
        else if (dtyp == SYS_CHAR) {
            vis_RPropValueString(rprop, types[i], cparams);
            printf("  value= %s\n", cparams);
        }
    }
    /* now conversely, set dataset name */
    vis_RPropSetDatasetName(rprop, (Vchar*)"D.N:1");
    /* query for equivalent primary properties */
    vis_RPropGetType(rprop, &type);
    vis_RPropGetQual(rprop, &nqua, iqua, cqua);
    vis_RPropGetIds(rprop, &id1, &id2, &id3);
    printf("type = %d\n", type);
    printf("nqua = %d\n", nqua);
    for (i = 0; i < nqua; i++) {
        printf("iqua[%d] = %d\n", i, iqua[i]);
    }
    printf("cqua = %s\n", cqua);
    printf("id1,id2,id3 = %d %d %d\n", id1, id2, id3);

    /* end objects */
    vis_RPropEnd(rprop);
    return 0;
}
