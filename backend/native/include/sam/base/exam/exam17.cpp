#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Test and demonstrate LinkList
----------------------------------------------------------------------*/
int
main()
{
    Vint index, i1, i2, i3, i4;
    Vint num, nbytes, count;
    vsy_LinkList* linklist;
    Vdouble* d;

    printf("\nLinkList test\n");

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance LinkList object */
    linklist = vsy_LinkListBegin();

    /* set initial allocation to four objects */
    vsy_LinkListDef(linklist, 4, sizeof(Vdouble));

    /* inquire and count */
    vsy_LinkListInq(linklist, &num, &nbytes);
    vsy_LinkListCount(linklist, &count);
    printf("num = %d, nbytes= %d, count = %d\n", num, nbytes, count);

    /* insert some double objects */
    vsy_LinkListAdd(linklist, &i1, (Vobject**)&d);
    *d = 1000.;
    vsy_LinkListAdd(linklist, &i2, (Vobject**)&d);
    *d = 2000.;
    vsy_LinkListAdd(linklist, &i3, (Vobject**)&d);
    *d = 3000.;
    vsy_LinkListAdd(linklist, &i4, (Vobject**)&d);
    *d = 4000.;
    /* inquire and count */
    vsy_LinkListInq(linklist, &num, &nbytes);
    vsy_LinkListCount(linklist, &count);
    printf("num = %d, nbytes= %d, count = %d\n", num, nbytes, count);
    /* InitIter,NextIter traversal */
    vsy_LinkListInitIter(linklist);
    while (vsy_LinkListNextIter(linklist, &index, (Vobject**)&d), d != NULL) {
        printf("index = %d, double = %e\n", index, *d);
    }
    /* remove a couple */
    vsy_LinkListRemove(linklist, i1);
    vsy_LinkListRemove(linklist, i2);

    /* lookup */
    vsy_LinkListRef(linklist, i3, (Vobject**)&d);
    printf("index = %d, double = %e\n", i3, *d);
    vsy_LinkListRef(linklist, i4, (Vobject**)&d);
    printf("index = %d, double = %e\n", i4, *d);

    /* now inquire and count */
    vsy_LinkListInq(linklist, &num, &nbytes);
    vsy_LinkListCount(linklist, &count);
    printf("num = %d, nbytes= %d, count = %d\n", num, nbytes, count);

    /* InitIter,NextIter traversal */
    vsy_LinkListInitIter(linklist);
    while (vsy_LinkListNextIter(linklist, &index, (Vobject**)&d), d != NULL) {
        printf("index = %d, double = %e\n", index, *d);
    }
    /* clear */
    vsy_LinkListClear(linklist);
    /* inquire and count */
    vsy_LinkListInq(linklist, &num, &nbytes);
    vsy_LinkListCount(linklist, &count);
    printf("num = %d, nbytes= %d, count = %d\n", num, nbytes, count);

    /* delete object */
    vsy_LinkListEnd(linklist);
    return 0;
}
