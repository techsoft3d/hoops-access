#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Manage Solution Properties Using SProp
----------------------------------------------------------------------*/
int
main()
{
    Vint i, j;
    Vint iparams[2];
    Vdouble dparams[6];
    Vchar cparams[81];
    vis_SProp* sprop;
    Vint ntypes, *type;
    Vint nval, dtyp;
    Vint flag, usernum;
    Vchar name[256];
    Vint dimen, dimes[2];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create sprop for buckling solution */
    sprop = vis_SPropBegin();
    vis_SPropDef(sprop, SYS_SOL_BUCKLING);

    /* set number of modes */
    vis_SPropSetValuei(sprop, SPROP_EIGEN_NUM, 1);

    /* set restraint case number */
    vis_SPropSetValuei(sprop, SPROP_RCASE, 1);

    /* set load case numbers */
    vis_SPropSetValuei(sprop, SPROP_LCASE_NUM, 2);
    iparams[0] = 2;
    iparams[1] = 4;
    vis_SPropSetValueiv(sprop, SPROP_LCASE, iparams);
    dparams[0] = 10.;
    dparams[1] = 20.;
    vis_SPropSetValuedv(sprop, SPROP_LCASE_FACTOR, dparams);

    /* set results to be saved */
    vis_SPropSetValuei(sprop, SPROP_RESFILE_NUM, 1);
    vis_SPropSetValuei(sprop, SPROP_RESFILE, SYS_RES_D);

    /* set titles */
    vis_SPropSetValuec(sprop, SPROP_TITLE, (Vchar*)"Buckling solution");
    vis_SPropSetValuec(sprop, SPROP_SUBTITLE, (Vchar*)"Example");

    /* set a couple of user properties */
    vis_SPropSetValuei(sprop, SPROP_USER_NUM, 2);

    /* set "user scalar" to scalar integer value 6 */
    vis_SPropSetValuei(sprop, SPROP_USERDIMENUM + 0, 1);
    vis_SPropSetValuei(sprop, SPROP_USERDIME + 0, 1);
    vis_SPropSetValuec(sprop, SPROP_USERNAME + 0, (Vchar*)"user scalar");
    vis_SPropSetValuei(sprop, SPROP_USERDATATYPE + 0, SYS_INTEGER);
    vis_SPropSetValuei(sprop, SPROP_USERDATA + 0, 6);

    /* set "user 1" to 2x3 array of real values */
    vis_SPropSetValuei(sprop, SPROP_USERDIMENUM + 1, 2);
    dimes[0] = 3;
    dimes[1] = 2;
    vis_SPropSetValueiv(sprop, SPROP_USERDIME + 1, dimes);
    vis_SPropSetValuec(sprop, SPROP_USERNAME + 1, (Vchar*)"user 2x3 array ");
    vis_SPropSetValuei(sprop, SPROP_USERDATATYPE + 1, SYS_REAL);
    dparams[0] = 1.;
    dparams[1] = 2.;
    dparams[2] = 3.;
    dparams[3] = 4.;
    dparams[4] = 5.;
    dparams[5] = 6.;
    vis_SPropSetValuedv(sprop, SPROP_USERDATA + 1, dparams);

    /* traverse defined solution properties */
    /* query for number of types and allocate array */
    vis_SPropValueTypeNum(sprop, &ntypes);
    printf("ntypes = %d\n", ntypes);
    type = (Vint*)malloc(ntypes * sizeof(Vint));
    /* query for types */
    vis_SPropValueType(sprop, &ntypes, type);
    /* loop through types generically */
    for (i = 0; i < ntypes; i++) {
        vis_SPropValueName(sprop, type[i], name);
        printf("\n name = %s\n", name);
        vis_SPropValueParams(sprop, type[i], &nval, &dtyp);
        printf(" nval= %d\n", nval);

        /* integer valued */
        if (dtyp == SYS_INTEGER) {
            printf(" Integer\n");
            vis_SPropValueInteger(sprop, type[i], iparams);
            for (j = 0; j < nval; j++) {
                printf("  value= %d\n", iparams[j]);
            }
            /* real valued */
        }
        else if (dtyp == SYS_REAL) {
            vis_SPropValueDouble(sprop, type[i], dparams);
            printf(" Real\n");
            for (j = 0; j < nval; j++) {
                printf("  value= %e\n", dparams[j]);
            }
            /* character valued */
        }
        else if (dtyp == SYS_CHAR) {
            vis_SPropValueString(sprop, type[i], cparams);
            printf("  value= %s\n", cparams);
        }
    }
    free(type);
    /* specifically access user data */
    printf("\nUser data\n");
    usernum = 0;
    vis_SPropValueFlag(sprop, SPROP_USER_NUM, &flag);
    if (flag) {
        vis_SPropValueInteger(sprop, SPROP_USER_NUM, &usernum);
    }
    for (i = 0; i < usernum; i++) {
        vis_SPropValueInteger(sprop, SPROP_USERDIMENUM + i, &dimen);
        vis_SPropValueInteger(sprop, SPROP_USERDIME + i, dimes);
        vis_SPropValueString(sprop, SPROP_USERNAME + i, name);
        vis_SPropValueInteger(sprop, SPROP_USERDATATYPE + i, &dtyp);
        printf("\n");
        printf("name= %s\n", name);
        printf("number of dimensions= %d\n", dimen);
        printf("dimensions=");
        nval = 1;
        for (j = 0; j < dimen; j++) {
            printf(" %d", dimes[j]);
            nval *= dimes[j];
        }
        printf("\n");
        printf("datatype= %d\n", dtyp);
        /* integer valued */
        if (dtyp == SYS_INTEGER) {
            printf(" Integer\n");
            vis_SPropValueInteger(sprop, SPROP_USERDATA + i, iparams);
            for (j = 0; j < nval; j++) {
                printf("  value= %d\n", iparams[j]);
            }
            /* real valued */
        }
        else if (dtyp == SYS_REAL) {
            vis_SPropValueDouble(sprop, SPROP_USERDATA + i, dparams);
            printf(" Real\n");
            for (j = 0; j < nval; j++) {
                printf("  value= %e\n", dparams[j]);
            }
            /* character valued */
        }
        else if (dtyp == SYS_CHAR) {
            vis_SPropValueString(sprop, SPROP_USERDATA + i, cparams);
            printf("  value= %s\n", cparams);
        }
    }
    /* end objects */
    vis_SPropEnd(sprop);
    return 0;
}
