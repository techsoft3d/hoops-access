#include "sam/base/base.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Import all Datasets to a Native library
----------------------------------------------------------------------*/
int
main()
{
    vdm_LMan* lman;
    vdm_NatLib* natlib;
    vdm_DataFun* datafun;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create data function object */
    datafun = vdm_DataFunBegin();

    /* create Native library device */
    natlib = vdm_NatLibBegin();
    vdm_NatLibDataFun(natlib, datafun);

    /* set status to new */
    vdm_DataFunSetStatus(datafun, VDM_STATUS_NEW);

    /* open native library device */
    vdm_DataFunOpen(datafun, 0, (Vchar*)"bumper.vdm", VDM_NATIVE);

    /* Use LMan to import data and print TOC */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);
    vdm_LManImport(lman, (Vchar*)"exam4.exp");
    vdm_LManSetParami(lman, LMAN_VERBOSE, SYS_ON);
    vdm_LManTOC(lman, "*");
    vdm_LManEnd(lman);

    /* close library device */
    vdm_DataFunClose(datafun);

    /* free objects */
    vdm_DataFunEnd(datafun);
    vdm_NatLibEnd(natlib);
    return 0;
}
