#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Test and demonstrate ADTree
----------------------------------------------------------------------*/
int
main()
{
    Vint key;
    Vint nhits;
    vsy_ADTree* adtree;
    Vdouble xmin[3], xmax[3];
    Vdouble x[3], tol;
    Vdouble xn[3], xx[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    printf("\nADTree test\n");

    /* instance ADTree object */
    adtree = vsy_ADTreeBegin();

    /* set up POINT ADTree within unit square */
    /* set initial allocation to five objects */
    printf("\nPOINT ADTree\n");
    xmin[0] = 0.;
    xmin[1] = 0.;
    xmin[2] = 0.;
    xmax[0] = 1.;
    xmax[1] = 1.;
    xmax[2] = 1.;
    vsy_ADTreeDef(adtree, ADTREE_POINT, xmin, xmax);

    /* insert 5 points */
    x[0] = .25;
    x[1] = .75;
    x[2] = 0.;
    vsy_ADTreeInsertPoint(adtree, 1, x);
    x[0] = .75;
    x[1] = .75;
    x[2] = 0.;
    vsy_ADTreeInsertPoint(adtree, 2, x);
    x[0] = .65;
    x[1] = .65;
    x[2] = 0.;
    vsy_ADTreeInsertPoint(adtree, 3, x);
    x[0] = .05;
    x[1] = .65;
    x[2] = 0.;
    vsy_ADTreeInsertPoint(adtree, 4, x);
    x[0] = .65;
    x[1] = .15;
    x[2] = 0.;
    vsy_ADTreeInsertPoint(adtree, 5, x);

    /* search with .26 tolerace box about point .5,.5 */
    tol = .26;
    vsy_ADTreeSetParamd(adtree, ADTREE_TOLERANCE, tol);
    x[0] = .5;
    x[1] = .5;
    x[2] = 0.;
    printf("search point= %f, %f, %f,  tolerance= %f\n", x[0], x[1], x[2], tol);
    vsy_ADTreeRefPointInit(adtree, x);
    while (vsy_ADTreeRefPointNext(adtree, &key), key) {
        printf(" find key= %d\n", key);
    }
    /* remove point 3 and search again */
    printf("remove point 3\n");
    vsy_ADTreeRemove(adtree, 3);
    printf("search point= %f, %f, %f,  tolerance= %f\n", x[0], x[1], x[2], tol);
    vsy_ADTreeRefPointInit(adtree, x);
    while (vsy_ADTreeRefPointNext(adtree, &key), key) {
        printf(" find key= %d\n", key);
    }

    /* search */
    tol = .36;
    vsy_ADTreeSetParamd(adtree, ADTREE_TOLERANCE, tol);
    printf("search point= %f, %f, %f,  tolerance= %f\n", x[0], x[1], x[2], tol);
    vsy_ADTreeRefPointInit(adtree, x);
    while (vsy_ADTreeRefPointNext(adtree, &key), key) {
        printf(" find key= %d\n", key);
    }
    /* remove and search */
    printf("remove point 2\n");
    vsy_ADTreeRemove(adtree, 2);
    printf("search point= %f, %f, %f,  tolerance= %f\n", x[0], x[1], x[2], tol);
    vsy_ADTreeRefPointInit(adtree, x);
    while (vsy_ADTreeRefPointNext(adtree, &key), key) {
        printf(" find key= %d\n", key);
    }

    /* now do objects with EXTENT */
    printf("\nEXTENT ADTree\n");
    vsy_ADTreeDef(adtree, ADTREE_EXTENT, xmin, xmax);

    /* insert 3 extent boxes */
    xn[0] = .25;
    xn[1] = .25;
    xn[2] = 0.;
    xx[0] = .5;
    xx[1] = .5;
    xx[2] = 0.;
    vsy_ADTreeInsertExtent(adtree, 1, xn, xx);
    xn[0] = .6;
    xn[1] = .5;
    xn[2] = 0.;
    xx[0] = .7;
    xx[1] = .8;
    xx[2] = 0.;
    vsy_ADTreeInsertExtent(adtree, 2, xn, xx);
    xn[0] = .8;
    xn[1] = .1;
    xn[2] = 0.;
    xx[0] = .9;
    xx[1] = .9;
    xx[2] = 0.;
    vsy_ADTreeInsertExtent(adtree, 3, xn, xx);

    /* point search */
    x[0] = .5;
    x[1] = .5;
    x[2] = 0.;
    tol = .1000;
    vsy_ADTreeSetParamd(adtree, ADTREE_TOLERANCE, tol);
    printf("search point= %f, %f, %f,  tolerance= %f\n", x[0], x[1], x[2], tol);
    vsy_ADTreeRefPointInit(adtree, x);
    vsy_ADTreeGetInteger(adtree, ADTREE_NUMHITS, &nhits);
    printf(" number of hits= %d\n", nhits);
    while (vsy_ADTreeRefPointNext(adtree, &key), key) {
        printf(" find key= %d\n", key);
    }
    /* extent search */
    xn[0] = .6;
    xn[1] = .55;
    xn[2] = 0.;
    xx[0] = .9;
    xx[1] = .55;
    xx[2] = 0.;
    tol = .05;
    printf("search extent, min= %f, %f, %f\n", xn[0], xn[1], xn[2]);
    printf("               max= %f, %f, %f\n", xx[0], xx[1], xx[2]);
    printf("               tolerance= %f\n", tol);
    vsy_ADTreeSetParamd(adtree, ADTREE_TOLERANCE, tol);
    vsy_ADTreeRefExtentInit(adtree, xn, xx);
    vsy_ADTreeGetInteger(adtree, ADTREE_NUMHITS, &nhits);
    printf(" number of hits= %d\n", nhits);
    while (vsy_ADTreeRefExtentNext(adtree, &key), key) {
        printf(" find key= %d\n", key);
    }

    /* delete object */
    vsy_ADTreeEnd(adtree);
    return 0;
}
