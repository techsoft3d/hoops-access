#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*
        3
       / \
      6---5
     / \ / \
    1---4---2
*/
Vint tri4[4][3] = {{1, 4, 6}, {4, 5, 6}, {4, 2, 5}, {6, 5, 3}};

/*
          10
         / \
        8---9
       / \ / \
      5---6---7
     / \ / \ / \
    1---2---3---4
*/
Vint tri9[9][3] = {{1, 2, 5}, {2, 6, 5}, {2, 3, 6}, {3, 7, 6}, {3, 4, 7}, {5, 6, 8}, {6, 9, 8}, {6, 7, 9}, {8, 9, 10}};

/*----------------------------------------------------------------------
                      test and demonstrate TriCon object
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vsy_TriCon* tricon;
    Vint numstrips, maxlength, istrip;
    Vint ntris;
    Vint ns, ie[9], is[11];
    Vint ix[3];
    Vint numtri;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* do 4 element triangular mesh */
    ntris = 4;
    /* instance TriCon object */
    tricon = vsy_TriConBegin();
    vsy_TriConDef(tricon, ntris);

    /* insert triangles */
    for (i = 0; i < ntris; i++) {
        vsy_TriConAppend(tricon, tri4[i]);
    }
    /* process */
    vsy_TriConProcess(tricon, &numstrips, &maxlength);
    printf(" numstrips= %d, maxlength= %d\n", numstrips, maxlength);

    /* access triangle strips */
    for (istrip = 1; istrip <= numstrips; istrip++) {
        vsy_TriConStrip(tricon, istrip, &ns, ie, is);
        printf("strip= %d, ns= %d\n", istrip, ns);
        for (i = 0; i < ns; i++) {
            printf(" %d", is[i]);
        }
        printf("\n");
    }
    /* find out how many triangles there are */
    vsy_TriConNum(tricon, &numtri);
    printf("Current number of triangles= %d\n", numtri);

    /* access input triangle connections */
    for (i = 1; i <= numtri; i++) {
        vsy_TriConRef(tricon, i, ix);
        printf("tri[%d]= %d %d %d\n", i, ix[0], ix[1], ix[2]);
    }

    /* now do 9 element triangular mesh */
    vsy_TriConClear(tricon);
    ntris = 9;

    for (i = 0; i < ntris; i++) {
        vsy_TriConAppend(tricon, tri9[i]);
    }

    vsy_TriConProcess(tricon, &numstrips, &maxlength);
    printf(" numstrips= %d, maxlength= %d\n", numstrips, maxlength);
    for (istrip = 1; istrip <= numstrips; istrip++) {
        vsy_TriConStrip(tricon, istrip, &ns, ie, is);
        printf("strip= %d, ns= %d\n", istrip, ns);
        for (i = 0; i < ns; i++) {
            printf(" %d", is[i]);
        }
        printf("\n");
    }
    /* destroy TriCon object */
    vsy_TriConEnd(tricon);
    return 0;
}
