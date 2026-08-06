#include <stdio.h>
#include "sam/base/base.h"

class der_Random: public vsy_Random {
  public:
    void
    Boolean(Vint*);
};

void
der_Random::Boolean(Vint* boolean)
{
    Vfloat r;

    vsy_Random::Number(&r);
    if (r < .5) {
        *boolean = 0;
    }
    else {
        *boolean = 1;
    }
}

/*----------------------------------------------------------------------
                      demonstrate derived der_Random object
----------------------------------------------------------------------*/
int
main()
{
    int i;
    Vfloat f;
    Vint b;
    der_Random* random;

    /* instance derived Random object */
    random = new der_Random();

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
    /* generate 10 random Booleans */
    printf("Added function Boolean\n");
    for (i = 0; i < 10; i++) {
        random->Boolean(&b);
        printf("i,b %d %d\n", i, b);
    }
    /* destroy derived Random object */
    delete random;
    return 0;
}
