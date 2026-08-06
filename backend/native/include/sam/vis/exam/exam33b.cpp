#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                    Manage Complex Constraints Using RCase
----------------------------------------------------------------------*/
int
main()
{
    vis_RCase* rcase;
    vis_Group* nodegroup;
    Vint i;
    Vint index;
    Vint numtags, tag[SYS_DOF_MAX], tid[2], dottype;
    Vint flags, type, master;
    Vdouble value[2];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance RCase object */
    rcase = vis_RCaseBegin();

    /* Define SPC's */
    /* specify x translation fixity at node 2 */
    vis_RCaseSetSPCdv(rcase, 2, SYS_DOF_TX, RCASE_FIXED, NULL, 0);

    /* specify applied x translation at node 3 */
    vis_RCaseSetComplexMode(rcase, SYS_COMPLEX_REALIMAGINARY);
    value[0] = 1.;
    value[1] = 2.;
    vis_RCaseSetSPCdv(rcase, 3, SYS_DOF_TX, RCASE_APPLIED, value, 0);
    /* specify applied y acceleration at node 4 */
    value[0] = 10.;
    value[1] = 20.;
    vis_RCaseSetSPCdv(rcase, 4, SYS_DOF_TY, RCASE_APPLIED, value, 0);
    vis_RCaseSetSPCDot(rcase, 4, SYS_DOF_TY, RCASE_DOFDOTDOT);
    tid[0] = 30;
    tid[1] = 40;
    vis_RCaseSetSPCTId(rcase, 4, SYS_DOF_TY, tid);

    /* specify master for y rotation at node 5 */
    vis_RCaseSetSPCdv(rcase, 7, SYS_DOF_RY, RCASE_MASTER, NULL, 5);

    /* query SPC's */
    nodegroup = vis_GroupBegin();
    vis_GroupDef(nodegroup, 4, SYS_NODE, SYS_NONE);
    vis_GroupClear(nodegroup);

    /* group of nodes with single point constraints */
    vis_RCaseNodeGroup(rcase, NULL, nodegroup);

    /* iterate through node group */
    printf("\nSingle Point Constraints\n");
    vis_GroupInitIndex(nodegroup);
    while (vis_GroupNextIndex(nodegroup, &index, &flags), index) {
        printf("node= %d\n", index);
        vis_RCaseSPCTag(rcase, index, &numtags, tag);
        for (i = 0; i < numtags; i++) {
            vis_RCaseSPCdv(rcase, index, tag[i], &type, value, &master);
            printf("tag= %d, type= %d\n", tag[i], type);
            if (type == RCASE_APPLIED) {
                vis_RCaseSPCTId(rcase, index, tag[i], tid);
                vis_RCaseSPCDot(rcase, index, tag[i], &dottype);
                printf(" value= %f %f(i)\n", value[0], value[1]);
                printf(" tid= %d %d(i)\n", tid[0], tid[1]);
                printf(" dottype= %d\n", dottype);
            }
            else if (type == RCASE_MASTER) {
                printf(" master= %d\n", master);
            }
        }
    }
    /* end objects */
    vis_RCaseEnd(rcase);
    vis_GroupEnd(nodegroup);
    return 0;
}
