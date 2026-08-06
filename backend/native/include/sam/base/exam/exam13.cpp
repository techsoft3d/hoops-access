#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_time(vsy_Timer* timer);

#if defined(__clang__) && (__clang_major__ >= 14)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-but-set-variable"
#endif

/*----------------------------------------------------------------------
                      Test and demonstrate Timer
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    Vdouble a;
    vsy_Timer* timer;

    vsy_LicenseValidate(HOOPS_LICENSE);

    printf("\nTimer test\n");

    /* instance object */
    timer = vsy_TimerBegin();

    /* start timing addition */
    vsy_TimerStart(timer, "PlusOne");
    a = 0;
    for (i = 0; i < 10000000; i++) {
        a += 1.;
    }
    /* stop and print */
    vsy_TimerStop(timer, "PlusOne");
    print_time(timer);

    /* start timing multiplication */
    vsy_TimerStart(timer, "Multiply");
    a = 1;
    for (i = 0; i < 10000000; i++) {
        a *= 1.0000001;
    }
    /* stop and print */
    vsy_TimerStop(timer, "Multiply");
    print_time(timer);

    /* restart timing addition */
    vsy_TimerStart(timer, "PlusOne");
    a = 0;
    for (i = 0; i < 20000000; i++) {
        a += 1.;
    }
    /* print before stopping */
    print_time(timer);

    /* stop and print */
    vsy_TimerStop(timer, "PlusOne");
    print_time(timer);

    /* initialize and print */
    vsy_TimerInit(timer, "PlusOne");
    print_time(timer);

    /* remove and print */
    vsy_TimerRemove(timer, "Multiply");
    print_time(timer);

    /* clear all */
    vsy_TimerClear(timer);
    print_time(timer);

    /* delete object */
    vsy_TimerEnd(timer);
    return 0;
}

#if defined(__clang__) && (__clang_major__ >= 14)
#pragma clang diagnostic pop
#endif

/*----------------------------------------------------------------------
                      print utility
----------------------------------------------------------------------*/
static void
print_time(vsy_Timer* timer)
{
    Vchar* name;
    Vint num, run;
    Vfloat usr, sys, ela;

    printf("Current timer state\n");
    /* iterate through all times */
    vsy_TimerInitIter(timer);
    while (vsy_TimerNextIter(timer, &name), name) {
        vsy_TimerEval(timer, name, &num, &run, &usr, &sys, &ela);
        printf(" name: %s, num= %d, run= %d, cpu= %f, sys= %f, ela= %f\n", name, num, run, usr, sys, ela);
    }
}
