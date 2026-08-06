#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "glwin.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Using Units
----------------------------------------------------------------------*/
int
main()
{
    vis_Units* units;
    Vdouble lfac, mfac, tfac, tempfac, tempoff;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create Units */
    units = vis_UnitsBegin();

    /* set base units to SI */
    vis_UnitsSetBase(units, UNITS_LENGTH, UNITS_LENGTH_METER);
    vis_UnitsSetBase(units, UNITS_MASS, UNITS_MASS_KILOGRAM);
    vis_UnitsSetBase(units, UNITS_TIME, UNITS_TIME_SECOND);
    vis_UnitsSetBase(units, UNITS_TEMP, UNITS_TEMP_KELVIN);

    /* set conversion units to British */
    vis_UnitsSetConv(units, UNITS_LENGTH, UNITS_LENGTH_FOOT);
    vis_UnitsSetConv(units, UNITS_MASS, UNITS_MASS_POUND);
    vis_UnitsSetConv(units, UNITS_TIME, UNITS_TIME_SECOND);
    vis_UnitsSetConv(units, UNITS_TEMP, UNITS_TEMP_FAHRENHEIT);

    /* compute conversion factors */
    vis_UnitsComputeFactors(units);

    /* get and print factors */
    vis_UnitsGetFactor(units, UNITS_LENGTH, &lfac);
    vis_UnitsGetFactor(units, UNITS_MASS, &mfac);
    vis_UnitsGetFactor(units, UNITS_TIME, &tfac);
    vis_UnitsGetFactor(units, UNITS_TEMP, &tempfac);
    vis_UnitsGetFactor(units, UNITS_TEMP_OFFSET, &tempoff);
    printf("length, one meter is %e feet\n", lfac);
    printf("mass,   one kilogram is %e pounds\n", mfac);
    printf("time,   one second is %e seconds\n", tfac);
    printf("temp,   fahrenheit= %e * (kelvin + %e)\n", tempfac, tempoff);

    /* free object */
    vis_UnitsEnd(units);
    return 0;
}
