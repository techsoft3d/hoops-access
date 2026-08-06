#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Test and Demonstrate PQueue object
----------------------------------------------------------------------*/
int
main()
{
    vsy_PQueue* pqueue;
    Vint id;
    Vdouble val;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance object */
    pqueue = vsy_PQueueBegin();

    /* configure to degrees from 0. to 60. */
    vsy_PQueueDef(pqueue, 0, 1024);
    vsy_PQueueRange(pqueue, 0., 60.);

    vsy_PQueueInsert(pqueue, 1, 20.);
    vsy_PQueueInsert(pqueue, 3, 30.);
    vsy_PQueueInsert(pqueue, 6, 10.);
    vsy_PQueueInsert(pqueue, 7, 10.001);

    /* redefine index 6 */
    vsy_PQueueInsert(pqueue, 6, 40.001);

    /* query for minimum and remove */
    vsy_PQueueMinMax(pqueue, 0, &id, &val);
    vsy_PQueueRemove(pqueue, id);
    printf("\n");
    printf("minimum id= %d, val= %e\n", id, val);

    /* query for minimum */
    vsy_PQueueMinMax(pqueue, 0, &id, &val);
    printf("\n");
    printf("minimum id= %d, val= %e\n", id, val);

    /* insert new minimum */
    vsy_PQueueInsert(pqueue, 2, 5.);
    vsy_PQueueMinMax(pqueue, 0, &id, &val);
    printf("\n");
    printf("minimum id= %d, val= %e\n", id, val);

    /* query for maximum */
    vsy_PQueueMinMax(pqueue, 1, &id, &val);
    printf("\n");
    printf("maximum id= %d, val= %e\n", id, val);

    /* clear */
    vsy_PQueueClear(pqueue);

    /* check */
    vsy_PQueueMinMax(pqueue, 1, &id, &val);
    printf("maximum id= %d\n", id);

    /* delete object */
    vsy_PQueueEnd(pqueue);
    return 0;
}
