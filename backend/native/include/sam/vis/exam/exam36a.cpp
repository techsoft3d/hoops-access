#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Manage Global Properties Using GProp
----------------------------------------------------------------------*/
int
main()
{
    Vint iparams[2];
    Vchar cparams[81];
    vis_GProp* gprop;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GProp */
    gprop = vis_GPropBegin();

    /* set title */
    vis_GPropSetValuec(gprop, GPROP_TITLE, (Vchar*)"Example 36a");
    vis_GPropSetValuec(gprop, GPROP_SUBTITLE, (Vchar*)"GProp");

    /* set 2d analysis plane */
    vis_GPropSetValuei(gprop, GPROP_2DPLANE, SYS_XYPLANE);
    /* set 2d analysis axis */
    vis_GPropSetValuei(gprop, GPROP_2DAXIS, SYS_YAXIS);
    /* set 2d analysis type */
    vis_GPropSetValuei(gprop, GPROP_2DTYPE, SYS_AXISYMMETRIC);

    /* now query these values */
    vis_GPropValueString(gprop, GPROP_TITLE, cparams);
    printf("TITLE: %s\n", cparams);
    vis_GPropValueString(gprop, GPROP_SUBTITLE, cparams);
    printf("SUBTITLE: %s\n", cparams);
    vis_GPropValueInteger(gprop, GPROP_2DPLANE, iparams);
    printf("2DPLANE: %d\n", iparams[0]);
    vis_GPropValueInteger(gprop, GPROP_2DTYPE, iparams);
    printf("2DTYPE: %d\n", iparams[0]);

    /* end objects */
    vis_GPropEnd(gprop);
    return 0;
}
