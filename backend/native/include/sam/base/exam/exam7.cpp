#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Test and demonstrate concatenation storage
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vsy_Concat* concat;
    Vint lm[4];
    Vint num;
    Vlong siz;
    Vint nbytes;
    Vint* lmptr;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance object */
    concat = vsy_ConcatBegin();
    /* insert some arrays */
    for (i = 0; i < 10000; i++) {
        lm[0] = i;
        lm[1] = i + 1;
        lm[2] = i + 2;
        lm[3] = i + 3;
        vsy_ConcatAdd(concat, 4 * sizeof(Vint), lm);
        /* get the pointer to the last data entered for i == 100 */
        if (i == 100) {
            vsy_ConcatRef(concat, (void**)&lmptr);
            printf("ith = %d, lm[] = %d %d %d %d\n", i, lmptr[0], lmptr[1], lmptr[2], lmptr[3]);
        }
    }
    /* count objects */
    vsy_ConcatInq(concat, &siz);
    vsy_ConcatCount(concat, &num);
    printf("\n");
    printf("siz= %lld\n", siz);
    printf("num= %d\n", num);
    printf("\n");
    /* iterate through records printing every 100th */
    i = 0;
    vsy_ConcatInitIter(concat);
    while (vsy_ConcatNextIter(concat, &nbytes, (void**)&lmptr), lmptr != NULL) {
        if (i % 100 == 0) {
            printf("ith = %d, nbytes = %d, lm[] = %d %d %d %d\n", i, nbytes, lmptr[0], lmptr[1], lmptr[2], lmptr[3]);
        }
        i++;
    }
    /* delete object */
    vsy_ConcatEnd(concat);
    return 0;
}
