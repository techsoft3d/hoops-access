#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
interval2(vsy_Progress* p);
static void
interval2_1(vsy_Progress* p);

/*----------------------------------------------------------------------
                      Test and demonstrate Progress
----------------------------------------------------------------------*/
int
main()
{
    vsy_Progress* p;
    Vint i;
    Vfloat percent;

    vsy_LicenseValidate(HOOPS_LICENSE);

    p = vsy_ProgressBegin();

    vsy_ProgressPush(p, "push 1", 3);
    vsy_ProgressInterval(p, 1, "level 1, primary 1, interval 1", 20, 100);
    vsy_ProgressInterval(p, 2, "level 1, primary 1, interval 2", 50, 0);
    vsy_ProgressInterval(p, 3, "level 1, primary 1, interval 3", 100, 0);

    /* interval 1 - 100 uniform steps */
    for (i = 1; i <= 100; i++) {
        vsy_ProgressSecondary(p, (Vfloat)i);
        vsy_ProgressPercentDone(p, &percent);
        printf("level 1, primary 1, interval 1, Percent done= %f\n", percent);
    }
    vsy_ProgressPrimary(p, 1);
    vsy_ProgressPercentDone(p, &percent);
    printf("level 1, primary 1, Percent done= %f\n", percent);

    /* interval 2 - pass control to a function */
    interval2(p);
    vsy_ProgressPrimaryName(p, "level 1, primary 1, interval 2");
    vsy_ProgressPercentDone(p, &percent);
    printf("level 1, primary 2, Percent done= %f\n", percent);

    /* interval 3 - wait until the primary is finished */
    vsy_ProgressPrimary(p, 3);
    vsy_ProgressPercentDone(p, &percent);
    printf("level 1, primary 3, Percent done= %f\n", percent);
    vsy_ProgressPop(p, "push 1");

    vsy_ProgressEnd(p);
    return 0;
}

static void
interval2(vsy_Progress* p)
{
    Vint i;
    Vfloat percent;

    vsy_ProgressPush(p, "push 2", 2);

    vsy_ProgressInterval(p, 1, "level2, primary 1, interval 1", 40, 0);
    vsy_ProgressInterval(p, 2, "level2, primary 2, interval 2", 100, 5);

    /* interval 2-1 - pass control to a function */
    interval2_1(p);
    vsy_ProgressPrimary(p, 1);

    /* interval 2-2 - 5 uniform steps */
    for (i = 1; i <= 5; i++) {
        vsy_ProgressSecondary(p, (Vfloat)i);
        vsy_ProgressPercentDone(p, &percent);
        printf("level 2, primary 2, Percent done= %f\n", percent);
    }
    vsy_ProgressPrimary(p, 2);

    vsy_ProgressPop(p, "push 2");
}

static void
interval2_1(vsy_Progress* p)
{
    Vint i;
    Vfloat percent;

    vsy_ProgressPush(p, "push 3", 1);

    vsy_ProgressInterval(p, 1, "level3, primary 1, interval 1", 100, 50);

    /* interval 2-2 - 50 uniform steps */
    for (i = 1; i <= 50; i++) {
        vsy_ProgressSecondary(p, (Vfloat)i);
        vsy_ProgressPercentDone(p, &percent);
        printf("level 3, primary 1, Percent done= %f\n", percent);
    }
    vsy_ProgressPrimary(p, 1);

    vsy_ProgressPop(p, "push 3");
}
