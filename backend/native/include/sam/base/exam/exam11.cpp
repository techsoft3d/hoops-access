#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

Vfloat vert[4][3] = {{0.f, 0.f, 0.f}, {1.f, 0.f, 0.f}, {0.f, 1.f, 0.f}, {1.f, 0.f, 0.f}};
Vfloat ct[4][3] = {{0.f, 0.f, 0.f}, {0.f, 1.f, 0.f}, {0.f, 0.f, 1.f}, {0.f, 1.f, 0.f}};
Vfloat vn[4][3] = {{1.f, 0.f, 0.f}, {.7071f, .7071f, 0.f}, {0.f, 0.f, -1.f}, {.7071f, .7071f, 0.f}};

/*----------------------------------------------------------------------
                      test and demonstrate VertLoc object
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vsy_VertLoc* vertloc;
    Vint numunique, maxlocate, iunique, lowestid;
    Vint nverts;
    Vfloat x[3];
    Vfloat c[3], v[3];
    Vint nu, iu[10];
    Vint numvert;

    vsy_LicenseValidate(HOOPS_LICENSE);

    nverts = 4;

    /* instance VertLoc object */
    vertloc = vsy_VertLocBegin();
    vsy_VertLocDef(vertloc, nverts);

    /* insert vertices */
    for (i = 1; i <= nverts; i++) {
        vsy_VertLocSetColor(vertloc, ct[i - 1]);
        vsy_VertLocSetNormal(vertloc, vn[i - 1]);
        vsy_VertLocInsert(vertloc, i, vert[i - 1]);
    }

    /* merge */
    vsy_VertLocMerge(vertloc, &numunique, &maxlocate);
    printf(" numunique= %d, maxlocate= %d\n", numunique, maxlocate);

    /* query for unique clusters of vertices */
    for (iunique = 1; iunique <= numunique; iunique++) {
        vsy_VertLocUnique(vertloc, iunique, &nu, iu);
        printf("unique vertex cluster= %d, nu= %d\n", iunique, nu);
        for (i = 0; i < nu; i++) {
            printf(" %d", iu[i]);
        }
        printf("\n");
    }
    /* access lowest id */
    for (i = 1; i <= nverts; i++) {
        vsy_VertLocLowest(vertloc, i, &iunique, &lowestid);
        printf("vert[%d], iunique= %d, lowestid= %d\n", i, iunique, lowestid);
    }
    /* find out how many points there are */
    vsy_VertLocNum(vertloc, &numvert);
    printf("Current number of points= %d\n", numvert);

    /* access input vertex locations */
    for (i = 1; i <= numvert; i++) {
        vsy_VertLocRef(vertloc, i, x);
        printf("vert[%d]= %e %e %e\n", i, x[0], x[1], x[2]);
        vsy_VertLocColor(vertloc, i, c);
        printf("color[%d]= %e %e %e\n", i, c[0], c[1], c[2]);
        vsy_VertLocNormal(vertloc, i, v);
        printf("normal[%d]= %e %e %e\n", i, v[0], v[1], v[2]);
    }

    /* destroy VertLoc object */
    vsy_VertLocEnd(vertloc);
    return 0;
}
