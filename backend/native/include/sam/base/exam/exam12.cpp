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
Vint line9[9][2] = {{1, 4}, {4, 2}, {1, 6}, {4, 6}, {4, 5}, {2, 5}, {6, 5}, {6, 3}, {5, 3}};
/*
          10
         / \
        8   9
       /     \
      5---6---7
     /         \
    1---2---3---4
*/
Vint line11[11][2] = {{1, 2}, {2, 3}, {3, 4}, {1, 5}, {4, 7}, {5, 6}, {6, 7}, {5, 8}, {7, 9}, {8, 10}, {9, 10}};

/*----------------------------------------------------------------------
                      test and demonstrate LineCon object
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vsy_LineCon* linecon;
    Vint numstrips, maxlength, istrip;
    Vint nlines;
    Vint ns, ie[11], is[12];
    Vint ix[2];
    Vint numline;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* do 4 element triangular mesh, with 9 lines */
    nlines = 9;
    /* instance LineCon object */
    linecon = vsy_LineConBegin();
    vsy_LineConDef(linecon, nlines);

    /* insert lines */
    for (i = 0; i < nlines; i++) {
        vsy_LineConAppend(linecon, line9[i]);
    }
    /* process */
    vsy_LineConProcess(linecon, &numstrips, &maxlength);
    printf(" numstrips= %d, maxlength= %d\n", numstrips, maxlength);

    /* access line strips */
    for (istrip = 1; istrip <= numstrips; istrip++) {
        vsy_LineConStrip(linecon, istrip, &ns, ie, is);
        printf("strip= %d, ns= %d\n", istrip, ns);
        printf("lines=");
        for (i = 0; i < ns - 1; i++) {
            printf(" %d", ie[i]);
        }
        printf("\n");
        printf("nodes=");
        for (i = 0; i < ns; i++) {
            printf(" %d", is[i]);
        }
        printf("\n");
    }
    /* find out how many lines there are */
    vsy_LineConNum(linecon, &numline);
    printf("Current number of lines= %d\n", numline);

    /* access input lines connections */
    for (i = 1; i <= numline; i++) {
        vsy_LineConRef(linecon, i, ix);
        printf("line[%d]= %d %d\n", i, ix[0], ix[1]);
    }

    /* now do a 10 point mesh incompletely connected */
    vsy_LineConClear(linecon);
    nlines = 11;

    for (i = 0; i < nlines; i++) {
        vsy_LineConAppend(linecon, line11[i]);
    }
    vsy_LineConProcess(linecon, &numstrips, &maxlength);
    printf(" numstrips= %d, maxlength= %d\n", numstrips, maxlength);

    for (istrip = 1; istrip <= numstrips; istrip++) {
        vsy_LineConStrip(linecon, istrip, &ns, ie, is);
        printf("strip= %d, ns= %d\n", istrip, ns);
        printf("lines=");
        for (i = 0; i < ns - 1; i++) {
            printf(" %d", ie[i]);
        }
        printf("\n");
        printf("nodes=");
        for (i = 0; i < ns; i++) {
            printf(" %d", is[i]);
        }
        printf("\n");
    }
    /* destroy LineCon object */
    vsy_LineConEnd(linecon);
    return 0;
}
