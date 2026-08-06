#include <stdio.h>
#include "sam/base/base.h"

/*----------------------------------------------------------------------
                      test and demonstrate random object
----------------------------------------------------------------------*/
int
main()
{
    int i;
    Vfloat f;
    vsy_Random* random;

    /* instance Random object */
    random = new vsy_Random();

    /* generate and print 10 random numbers */
    printf("Default seed\n");
    for (i = 0; i < 10; i++) {
        random->Number(&f);
        printf("i,f %d %f\n", i, f);
    }
    /* set a seed and generate 10 more random numbers */
    printf("User seed\n");
    random->Init(70946);
    for (i = 0; i < 10; i++) {
        random->Number(&f);
        printf("i,f %d %f\n", i, f);
    }
    /* destroy Random object */
    delete random;
    return 0;
}
