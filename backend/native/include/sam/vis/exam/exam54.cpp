
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Manage User Defined Properties Using UProp
----------------------------------------------------------------------*/
int
main()
{
    Vint num, nval, dtype;
    vis_UProp* uprop;
    Vdouble area;
    Vint nodes[2];
    Vdouble dval[3];
    Vfloat fval[3];
    Vint ival[3];
    Vchar name[256];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create uprop properties */
    uprop = vis_UPropBegin();
    /* set type */
    vis_UPropSetType(uprop, 1, (Vchar*)"Total Area", 1, SYS_REAL);
    area = 2.;
    vis_UPropSetValued(uprop, 1, area);

    vis_UPropSetType(uprop, 2, (Vchar*)"Inlet Nodes", 2, SYS_INTEGER);
    nodes[0] = 1001;
    nodes[1] = 1023;
    vis_UPropSetValueiv(uprop, 2, nodes);

    vis_UPropPrint(uprop);

    vis_UPropNum(uprop, &num);
    printf("number of user properties= %d\n", num);

    vis_UPropValueDouble(uprop, 1, dval);
    printf("dval[0]= %e\n", dval[0]);
    vis_UPropValueFloat(uprop, 1, fval);
    printf("fval[0]= %e\n", fval[0]);

    vis_UPropGetType(uprop, 2, name, &nval, &dtype);
    printf("property= 2\n");
    printf(" name= %s\n", name);
    printf(" nval= %d\n", nval);
    printf(" dtype= %d\n", dtype);

    vis_UPropValueInteger(uprop, 2, ival);
    printf("ival[0]= %d\n", ival[0]);
    printf("ival[1]= %d\n", ival[1]);
    /* end objects */
    vis_UPropEnd(uprop);
    return 0;
}
