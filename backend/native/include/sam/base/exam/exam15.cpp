#include "stdio.h"
#include "stdlib.h"
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

typedef struct ptdot ptdot;
struct ptdot {
    int n;
    double* a;
    double* b;
    double s;
};

void
pdot(ptdot* p);

#define NUMPROC  2
#define NUMVEC   1000000
#define CACHEPAD 1024

/*----------------------------------------------------------------------
                      Test and Demonstrate PTask
----------------------------------------------------------------------*/
int
main()
{
    int i, j;
    int num, rem;
    int np, nt;
    double *at, *bt;
    double st;
    vsy_PTask* ptask;
    ptdot* pt[NUMPROC];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance PTask object */
    ptask = vsy_PTaskBegin();

    /* allocate vectors */
    at = (double*)malloc(NUMVEC * sizeof(double));
    bt = (double*)malloc(NUMVEC * sizeof(double));

    /* initialize with ones */
    for (j = 0; j < NUMVEC; j++) {
        at[j] = 1.;
        bt[j] = 1.;
    }
    /* partition dot product */
    num = NUMVEC / NUMPROC;
    rem = (NUMVEC % NUMPROC);
    nt = 0;
    for (i = 0; i < NUMPROC; i++) {
        pt[i] = (ptdot*)malloc(sizeof(ptdot) + CACHEPAD);
        if (i < NUMPROC - 1) {
            np = num;
        }
        else {
            np = num + rem;
        }
        pt[i]->n = np;
        pt[i]->a = &at[nt];
        pt[i]->b = &bt[nt];
        nt += np;
    }
    /* execute over NUMPROC threads */
    vsy_PTaskDef(ptask, NUMPROC, PTASK_EXEC);
    vsy_PTaskExec(ptask, NUMPROC, (void (*)(void*))pdot, (Vobject**)pt);

    /* add results of each thread */
    st = 0.;
    for (i = 0; i < NUMPROC; i++) {
        st += pt[i]->s;
        free(pt[i]);
    }
    printf("st= %e\n", st);

    /* free vectors */
    free(at);
    free(bt);
    /* delete PTask */
    vsy_PTaskEnd(ptask);
    return 0;
}

void
pdot(ptdot* p)
{
    int i;
    /* perform dot product */
    p->s = 0.;
    for (i = 0; i < p->n; i++) {
        p->s += p->a[i] * p->b[i];
    }
}
