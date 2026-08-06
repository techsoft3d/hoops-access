#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Manage Constraints Using RCase and MCase
----------------------------------------------------------------------*/
int
main()
{
    vis_RCase* rcase;
    vis_MCase* mcase;
    vis_Group* nodegroup;
    Vint i;
    Vint index;
    Vint numtags, tag[SYS_DOF_MAX];
    Vint flags, type, master;
    Vfloat value;
    Vint ix[3], ig[3];
    Vfloat c[3], r;
    Vint maxindex, maxterms, maxrhs, nterms;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance RCase object */
    rcase = vis_RCaseBegin();

    /* Define SPC's */
    /* specify x translation fixity at node 2 */
    vis_RCaseSetSPC(rcase, 2, SYS_DOF_TX, RCASE_FIXED, NULL, 0);

    /* specify applied x rotation at node 4 */
    value = 1.;
    vis_RCaseSetSPC(rcase, 4, SYS_DOF_RX, RCASE_APPLIED, &value, 0);

    /* specify master for y rotation at node 4 */
    vis_RCaseSetSPC(rcase, 4, SYS_DOF_RY, RCASE_MASTER, NULL, 2);

    /* instance MCase object */
    mcase = vis_MCaseBegin();

    /* Define MPC's */
    ix[0] = 5;
    ix[1] = 100;
    ix[2] = 101;
    ig[0] = SYS_DOF_TX;
    ig[1] = SYS_DOF_TX;
    ig[2] = SYS_DOF_TX;
    c[0] = -1.;
    c[1] = .5;
    c[2] = .5;
    vis_MCaseSetMPC(mcase, 1, 3, ix, ig, c, 0.);
    ig[0] = SYS_DOF_TY;
    ig[1] = SYS_DOF_TY;
    ig[2] = SYS_DOF_TY;
    vis_MCaseSetMPC(mcase, 2, 3, ix, ig, c, 0.);
    /* define a Tie */
    ix[0] = 2;
    ix[1] = 3;
    vis_MCaseSetCon(mcase, 3, MCASE_TIE, ix);

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
            vis_RCaseSPC(rcase, index, tag[i], &type, &value, &master);
            printf("tag= %d, type= %d\n", tag[i], type);
            if (type == RCASE_APPLIED) {
                printf(" value= %f\n", value);
            }
            else if (type == RCASE_MASTER) {
                printf(" master= %d\n", master);
            }
        }
    }
    /* query MPC's */
    vis_MCaseMax(mcase, &maxindex, &maxterms, &maxrhs);

    printf("\nMultiPoint Constraints\n");
    for (index = 1; index <= maxindex; index++) {
        vis_MCaseNum(mcase, index, &nterms);
        vis_MCaseType(mcase, index, &type);
        if (nterms) {
            if (type == MCASE_MPC) {
                vis_MCaseMPC(mcase, index, &nterms, ix, ig, c, &r);
                printf("index= %d, nterms= %d, r= %f\n", index, nterms, r);
                for (i = 0; i < nterms; i++) {
                    printf(" ix= %d, tag= %d, c= %f\n", ix[i], ig[i], c[i]);
                }
            }
            else {
                vis_MCaseCon(mcase, index, &type, &nterms, ix);
                printf("index= %d, type= %d, nterms= %d\n", index, type, nterms);
                for (i = 0; i < nterms; i++) {
                    printf(" ix= %d\n", ix[i]);
                }
            }
        }
    }
    /* end objects */
    vis_RCaseEnd(rcase);
    vis_MCaseEnd(mcase);
    vis_GroupEnd(nodegroup);
    return 0;
}
