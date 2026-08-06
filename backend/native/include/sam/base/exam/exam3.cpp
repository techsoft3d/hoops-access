#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_propset(vsy_PropSet* propset, Vchar* stg);

/*----------------------------------------------------------------------
                      Test and demonstrate property sets
----------------------------------------------------------------------*/
int
main()
{
    vsy_PropSet* propset;
    Vint ivalue[16];
    Vdouble dvalue[16];
    Vobject* pvalue[16];
    Vint count;

    vsy_LicenseValidate(HOOPS_LICENSE);

    printf("\nPropSet test\n");

    /* instance object */
    propset = vsy_PropSetBegin();

    /* insert some properties */
    vsy_PropSetInserti(propset, "integer", 1);
    vsy_PropSetInsertf(propset, "float", 2.);
    ivalue[0] = 10;
    ivalue[1] = 11;
    ivalue[2] = 12;
    vsy_PropSetInsertiv(propset, "integer vector", 3, ivalue);
    vsy_PropSetInsertc(propset, "string", (Vchar*)"Test and demonstrate property set");
    dvalue[0] = 100.;
    dvalue[1] = 101.;
    vsy_PropSetInsertdv(propset, "double vector", 2, dvalue);
    pvalue[0] = (void*)1;
    pvalue[1] = (void*)2;
    vsy_PropSetInsertpv(propset, "object vector", 2, pvalue);

    vsy_PropSetCount(propset, &count);
    printf("number of properties = %d\n", count);

    print_propset(propset, (Vchar*)"Property Set");

    /* delete object */
    vsy_PropSetEnd(propset);
    return 0;
}

/*----------------------------------------------------------------------
                      print utility
----------------------------------------------------------------------*/
static void
print_propset(vsy_PropSet* propset, Vchar* stg)
{
    Vchar* name;
    Vint type, num, size;
    Vint i;
    Vint ivalue[16];
    Vfloat fvalue[16];
    Vdouble dvalue[16];
    Vobject* pvalue[16];
    Vchar cvalue[256];

    /* print a title */
    printf("\n%s\n", stg);

    /* print values of all entries */
    vsy_PropSetInitIter(propset);
    while (vsy_PropSetNextIter(propset, &name), name != NULL) {
        vsy_PropSetLookup(propset, name, &type, &num, &size);
        printf("\nProperty name = %s\n", name);
        printf(" type         = %d\n", type);
        printf(" num          = %d\n", num);
        printf(" size         = %d\n", size);
        if (type == SYS_INTEGER) {
            vsy_PropSetLookupInteger(propset, name, ivalue);
            for (i = 0; i < num; i++) {
                printf("  prop[%2d]    = %d\n", i, ivalue[i]);
            }
        }
        else if (type == SYS_FLOAT) {
            vsy_PropSetLookupFloat(propset, name, fvalue);
            for (i = 0; i < num; i++) {
                printf("  prop[%2d]    = %f\n", i, fvalue[i]);
            }
        }
        else if (type == SYS_DOUBLE) {
            vsy_PropSetLookupDouble(propset, name, dvalue);
            for (i = 0; i < num; i++) {
                printf("  prop[%2d]    = %f\n", i, dvalue[i]);
            }
        }
        else if (type == SYS_OBJECT) {
            vsy_PropSetLookupObject(propset, name, pvalue);
            for (i = 0; i < num; i++) {
                printf("  prop[%2d]    = %p\n", i, pvalue[i]);
            }
        }
        else if (type == SYS_STRING) {
            vsy_PropSetLookupString(propset, name, cvalue);
            printf("  prop        = %s\n", cvalue);
        }
    }
}
