#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_ELEM 16

/*----------------------------------------------------------------------
                      Generate element group object
----------------------------------------------------------------------*/
int
main()
{
    vis_Group *group, *groups;

    Vint i;
    Vint index, flag;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create element group object */
    group = vis_GroupBegin();
    vis_GroupDef(group, MAX_ELEM, SYS_ELEM, SYS_NONE);

    /* activate the 2nd and 13th elements */
    vis_GroupClear(group);
    vis_GroupSetIndex(group, 2, 1);
    vis_GroupSetIndex(group, 13, 1);

    /* return active elements using Init-Next facility */
    vis_GroupInitIndex(group);
    while (vis_GroupNextIndex(group, &index, &flag), index != 0) {
        printf("element index = %d, flag = %d\n", index, flag);
    }

    /* take complement of group */
    vis_GroupComplement(group);

    /* return active elements using GetIndex facility */
    for (i = 1; i <= MAX_ELEM; i++) {
        vis_GroupGetIndex(group, i, &flag);
        if (flag) {
            printf("element index = %d, flag = %d\n", i, flag);
        }
    }
    /* perform boolean operation */
    groups = vis_GroupBegin();
    vis_GroupDef(groups, MAX_ELEM, SYS_ELEM, SYS_NONE);

    /* activate even elements */
    for (i = 2; i <= MAX_ELEM; i += 2) {
        vis_GroupSetIndex(groups, i, flag);
    }
    /* delete all even elements from group */
    vis_GroupBoolean(group, GROUP_DELETE, groups);

    /* return active elements using Init-Next facility */
    vis_GroupInitIndex(group);
    while (vis_GroupNextIndex(group, &index, &flag), index != 0) {
        printf("element index = %d, flag = %d\n", index, flag);
    }

    /* end objects */
    vis_GroupEnd(group);
    vis_GroupEnd(groups);
    return 0;
}
