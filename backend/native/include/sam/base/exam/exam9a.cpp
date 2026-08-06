#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Test and Demonstrate Heap object
----------------------------------------------------------------------*/
int
main()
{
    vsy_Heap* heap;
    Vint id;
    Vdouble val;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance object */
    heap = vsy_HeapBegin();

    /* set up heap to return minimum */
    vsy_HeapDef(heap, 10, 0);

    vsy_HeapInsert(heap, 1, 20.);
    vsy_HeapInsert(heap, 3, 30.);
    vsy_HeapInsert(heap, 6, 10.);
    vsy_HeapInsert(heap, 7, 10.001);

    /* redefine index 6 */
    vsy_HeapInsert(heap, 6, 40.001);

    /* query for minimum and remove */
    vsy_HeapRefRemove(heap, &id, &val);
    printf("\n");
    printf("minimum id= %d, val= %e\n", id, val);

    /* query for minimum */
    vsy_HeapRef(heap, &id, &val);
    printf("\n");
    printf("minimum id= %d, val= %e\n", id, val);

    /* insert new minimum */
    vsy_HeapInsert(heap, 2, 5.);
    vsy_HeapRef(heap, &id, &val);
    printf("\n");
    printf("minimum id= %d, val= %e\n", id, val);

    /* remove index 1 */
    vsy_HeapRemove(heap, 1);
    /* remove two, if 1 has been removed the 3 is new min */
    vsy_HeapRefRemove(heap, &id, &val);
    vsy_HeapRefRemove(heap, &id, &val);
    printf("\n");
    printf("minimum id= %d, val= %e\n", id, val);

    /* clear */
    vsy_HeapClear(heap);

    /* check */
    vsy_HeapRef(heap, &id, &val);
    printf("minimum id= %d\n", id);

    /* delete object */
    vsy_HeapEnd(heap);
    return 0;
}
