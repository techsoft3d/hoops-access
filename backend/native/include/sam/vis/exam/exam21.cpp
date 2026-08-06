#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vint ids[5] = {2, 33, 14, 25, 8};

/*----------------------------------------------------------------------
                      Build and query an IdTran object
----------------------------------------------------------------------*/
int
main()
{
    vis_IdTran* idtran;
    vis_IdTran* idtrana;
    Vint i;
    Vint index, id, no;
    Vint match;
    Vint num;
    Vint numind, numuni;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create IdTran object */
    idtran = vis_IdTranBegin();

    /* specify 5 entities */
    vis_IdTranDef(idtran, 5);

    /* set identifier for each entity index */
    for (i = 0; i < 5; i++) {
        vis_IdTranSetId(idtran, i + 1, ids[i]);
    }
    /* query and print index of each identifier */
    for (i = 0; i < 5; i++) {
        vis_IdTranIndex(idtran, ids[i], &index);
        printf("identifier = %d, index = %d\n", ids[i], index);
    }
    /* query and print index of illegal identifier */
    vis_IdTranIndex(idtran, -44, &index);
    printf("identifier = %d, index = %d\n", -44, index);

    /* check for matching objects */
    idtrana = vis_IdTranBegin();
    vis_IdTranDef(idtrana, 5);
    for (i = 0; i < 5; i++) {
        vis_IdTranSetId(idtrana, i + 1, ids[i]);
    }
    /* this should match */
    vis_IdTranMatch(idtran, idtrana, &match);
    printf("match = %d\n", match);

    /* this should not match */
    vis_IdTranSetId(idtrana, 2, 3);
    vis_IdTranMatch(idtran, idtrana, &match);
    printf("match = %d\n", match);

    /* query for unique identifiers */
    vis_IdTranSetId(idtran, 2, 25);
    vis_IdTranCount(idtran, IDTRAN_NUMINDICES, &numind);
    vis_IdTranCount(idtran, IDTRAN_NUMUNIQUE, &numuni);
    printf("numind= %d, numuni= %d\n", numind, numuni);
    vis_IdTranSetId(idtran, 3, 0);
    vis_IdTranCount(idtran, IDTRAN_NUMINDICES, &numind);
    vis_IdTranCount(idtran, IDTRAN_NUMUNIQUE, &numuni);
    printf("numind= %d, numuni= %d\n", numind, numuni);
    vis_IdTranClear(idtrana);
    vis_IdTranUnique(idtrana, idtran);
    /* query and print unique identifiers */
    for (i = 1; i <= numuni; i++) {
        vis_IdTranGetId(idtrana, i, &id);
        printf("index = %d, identifier = %d\n", i, id);
    }
    vis_IdTranEnd(idtrana);

    /* manage an element face set */
    vis_IdTranClear(idtran);
    /* element 3, face 2 */
    vis_IdTranSetEntType(idtran, SYS_ELEM, SYS_FACE);
    vis_IdTranSetId(idtran, 1, 3);
    vis_IdTranSetEnt(idtran, 1, 2);
    /* element 4, faces 1 and 3 */
    vis_IdTranSetId(idtran, 2, 4);
    vis_IdTranSetEnt(idtran, 2, 1);
    vis_IdTranSetId(idtran, 3, 4);
    vis_IdTranSetEnt(idtran, 3, 3);
    vis_IdTranCount(idtran, IDTRAN_NUMINDICES, &numind);
    vis_IdTranCount(idtran, IDTRAN_NUMUNIQUE, &numuni);
    printf("numind= %d, numuni= %d\n", numind, numuni);
    /* query and print identifiers and face numbers */
    for (i = 1; i <= numind; i++) {
        vis_IdTranGetId(idtran, i, &id);
        vis_IdTranGetEnt(idtran, i, &no);
        printf("index = %d, identifier = %d, face number= %d\n", i, id, no);
    }

    /* manage equivalenced identifiers, 1,2,4,5 */
    vis_IdTranClear(idtran);
    /* enter identifiers pairs in some arbitrary way */
    vis_IdTranEquId(idtran, 1, 2);
    vis_IdTranEquId(idtran, 4, 5);
    vis_IdTranEquId(idtran, 4, 2);
    vis_IdTranEquSweep(idtran);
    for (i = 1; i <= 5; i++) {
        vis_IdTranGetId(idtran, i, &index);
        if (index) {
            printf("equivalence id = %d to id = %d\n", i, index);
        }
    }
    vis_IdTranEquReNumber(idtran, &num);
    printf("Number of unique nodes= %d\n", num);
    for (i = 1; i <= 5; i++) {
        vis_IdTranGetId(idtran, i, &index);
        printf("index= %d, new id = %d\n", i, index);
    }

    /* free objects */
    vis_IdTranEnd(idtran);
    return 0;
}
