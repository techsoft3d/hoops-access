#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      test and demonstrate random object
----------------------------------------------------------------------*/
int
main()
{
    int i;
    Vint ir;
    Vfloat fr;
    vsy_Random* random;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance Random object */
    random = vsy_RandomBegin();

    /* generate and print 10 random numbers */
    printf("Default seed\n");
    for (i = 0; i < 10; i++) {
        vsy_RandomNumber(random, &fr);
        printf("i,fr %d %f\n", i, fr);
    }
    /* set a seed and generate 10 more random numbers */
    printf("User seed\n");
    vsy_RandomInit(random, 70946);
    for (i = 0; i < 10; i++) {
        vsy_RandomNumber(random, &fr);
        printf("i,fr %d %f\n", i, fr);
    }
    for (i = 0; i < 10; i++) {
        vsy_RandomInteger(random, &ir);
        printf("i,ir %d %d\n", i, ir);
    }
    /* destroy Random object */
    vsy_RandomEnd(random);
    return 0;
}
