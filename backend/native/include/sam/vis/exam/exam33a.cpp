#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Manage Initial Conditions Using ICase
----------------------------------------------------------------------*/
int
main()
{
    vis_ICase* icase;
    vis_Group* nodegroup;
    Vint i, j;
    Vint index;
    Vint flags;
    Vint ntags, tag[SYS_DOF_MAX];
    Vdouble val[SYS_DOF_MAX];
    Vint ntypes, type[2];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance ICase object */
    icase = vis_ICaseBegin();

    /* specify initial conditions for translational freedoms */
    ntags = 3;
    tag[0] = SYS_DOF_TX;
    tag[1] = SYS_DOF_TY;
    tag[2] = SYS_DOF_TZ;

    /* initial displacement at nodes 3 and 10 */
    val[0] = 1.;
    val[1] = 0.;
    val[2] = 0.;
    vis_ICaseSetSPVdv(icase, 3, ICASE_DOF, ntags, tag, val);

    val[0] = -2.;
    val[1] = 0.;
    val[2] = 0.;
    vis_ICaseSetSPVdv(icase, 10, ICASE_DOF, ntags, tag, val);

    /* initial velocity at node 2 */
    val[0] = 0.;
    val[1] = 1000.;
    val[2] = 0.;
    vis_ICaseSetSPVdv(icase, 2, ICASE_DOFDOT, ntags, tag, val);

    /* query initial conditions */
    nodegroup = vis_GroupBegin();
    vis_GroupDef(nodegroup, 10, SYS_NODE, SYS_NONE);
    vis_GroupClear(nodegroup);

    /* group of nodes with initial conditions */
    vis_ICaseNodeGroup(icase, NULL, nodegroup);

    /* iterate through node group */
    printf("\nInitial Conditions\n");
    vis_GroupInitIndex(nodegroup);
    while (vis_GroupNextIndex(nodegroup, &index, &flags), index) {
        printf("node= %d\n", index);
        vis_ICaseSPVType(icase, index, &ntypes, type);
        for (i = 0; i < ntypes; i++) {
            vis_ICaseSPVdv(icase, index, type[i], &ntags, tag, val);
            for (j = 0; j < ntags; j++) {
                printf("tag= %d\n", tag[j]);
                if (type[i] == ICASE_DOF) {
                    printf(" dof= %f\n", val[j]);
                }
                else if (type[i] == ICASE_DOFDOT) {
                    printf(" dofdot= %f\n", val[j]);
                }
            }
        }
    }

    /* end objects */
    vis_ICaseEnd(icase);
    vis_GroupEnd(nodegroup);
    return 0;
}
