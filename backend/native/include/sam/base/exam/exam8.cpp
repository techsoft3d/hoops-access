#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Test and demonstrate data table
----------------------------------------------------------------------*/
int
main()
{
    Vint num;
    vsy_DataTable* datatable;
    Vdouble v, *d, deval[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance object */
    datatable = vsy_DataTableBegin();

    /* configure to hold 3-component data objects */
    vsy_DataTableDef(datatable, 0, 3);

    d = (Vdouble*)malloc(3 * sizeof(Vdouble));
    d[0] = 20000000.;
    d[1] = .3;
    d[2] = .0020;
    vsy_DataTableInsert(datatable, 200., d);

    d = (Vdouble*)malloc(3 * sizeof(Vdouble));
    d[0] = 10000000.;
    d[1] = .3;
    d[2] = .0015;
    vsy_DataTableInsert(datatable, 100., d);

    d = (Vdouble*)malloc(3 * sizeof(Vdouble));
    d[0] = 8000000.;
    d[1] = .3;
    d[2] = .0010;
    vsy_DataTableInsert(datatable, 50., d);

    d = (Vdouble*)malloc(3 * sizeof(Vdouble));
    d[0] = 6000000.;
    d[1] = .3;
    d[2] = .0008;
    vsy_DataTableInsert(datatable, -50., d);

    /* count objects */
    vsy_DataTableCount(datatable, &num);
    printf("\n");
    printf("num= %d\n\n", num);

    /* lookup */
    vsy_DataTableLookup(datatable, 200., &d);
    if (d != NULL) {
        printf("Lookup v= 200. d = %f %f %f\n\n", d[0], d[1], d[2]);
    }
    /* evaluate */
    vsy_DataTableSetParami(datatable, DATATABLE_EXTRAPOLATE, DATATABLE_LINEAR);
    vsy_DataTableEval(datatable, 150., deval);
    printf("Eval   v= 150. d = %f %f %f\n\n", deval[0], deval[1], deval[2]);
    vsy_DataTableEval(datatable, 400., deval);
    printf("Eval   v= 400. d = %f %f %f\n\n", deval[0], deval[1], deval[2]);

    /* iterate through objects */
    vsy_DataTableInitIter(datatable);
    while (vsy_DataTableNextIter(datatable, &v, (Vdouble**)&d), d != NULL) {
        printf("v = %f, d = %f %f %f\n", v, d[0], d[1], d[2]);
    }
    /* free data objects */
    vsy_DataTableForEach(datatable, (void (*)(void*))free);

    /* delete object */
    vsy_DataTableEnd(datatable);
    return 0;
}
