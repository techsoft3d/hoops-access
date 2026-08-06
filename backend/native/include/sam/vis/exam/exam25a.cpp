#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_NODE 2
#define MAX_STEP 5

/* history data */
static Vfloat v[MAX_STEP][MAX_NODE][3] = {{{3.0f, 2.0f, 0.}, {-1.0f, 0., 0.}},
                                          {{3.1f, 2.2f, 0.}, {-1.1f, 0., 0.}},
                                          {{3.2f, 2.4f, 0.}, {-1.2f, 0., 0.}},
                                          {{3.3f, 2.2f, 0.}, {-1.3f, 0., 0.}},
                                          {{3.4f, 2.0f, 0.}, {-1.4f, 0., 0.}}};

/* node indices */
static Vint ind[MAX_NODE] = {1801, 2102};

/* step numbers */
static Vint stp[MAX_STEP] = {10, 20, 30, 40, 50};
/* independent step values */
static Vfloat t[MAX_STEP] = {1., 3., 5., 7., 9.};

/*----------------------------------------------------------------------
                      Generate node vector history object
----------------------------------------------------------------------*/
int
main()
{
    Vint i, j;
    vis_History* history;
    Vint istep, index;
    Vfloat vs[3], vmag, ts;
    Vfloat extent[2][3];
    Vint nument, numstp;
    Vint stpnum[MAX_STEP], indval[MAX_NODE];
    Vfloat sval[MAX_STEP];
    Vint rank, cutoffrank;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create node history object */
    history = vis_HistoryBegin();
    vis_HistoryDef(history, MAX_STEP, MAX_NODE, SYS_NODE, SYS_NONE, VIS_VECTOR);

    /* set vector and independent data values */
    for (j = 0; j < MAX_STEP; j++) {
        vis_HistorySetIndep(history, stp[j], t[j]);
        for (i = 0; i < MAX_NODE; i++) {
            vis_HistorySetData(history, stp[j], ind[i], v[j][i]);
        }
    }
    /* get vector and independent value data */
    vis_HistorySteps(history, &numstp, stpnum);
    vis_HistoryIndices(history, &nument, indval);
    for (j = 0; j < numstp; j++) {
        vis_HistoryIndep(history, stpnum[j], &ts);
        for (i = 0; i < nument; i++) {
            vis_HistoryData(history, stpnum[j], 1, &indval[i], vs);
            printf("istep= %d, index= %d, vector= %f %f %f, indep= %f\n", stpnum[j], indval[i], vs[0], vs[1], vs[2], ts);
        }
    }
    /* query for data extent */
    vis_HistoryExtent(history, (Vfloat*)extent);
    printf("vector min= %f %f %f\n", extent[0][0], extent[0][1], extent[0][2]);
    printf("vector max= %f %f %f\n", extent[1][0], extent[1][1], extent[1][2]);

    /* compute vector magnitude */
    vis_HistorySetDerive(history, VIS_VECTOR_MAG);
    istep = 20;
    index = 1801;
    vis_HistoryData(history, istep, 1, &index, &vmag);
    printf("istep= %d, index= %d, mag= %f\n", istep, index, vmag);

    /* get vector magnitude for node 1801 for all steps */
    vis_HistoryDataSteps(history, 1, &index, sval);
    for (i = 0; i < numstp; i++) {
        printf("istep= %d, mag= %f\n", stpnum[i], sval[i]);
    }
    /* generate sampling rank */
    vis_HistorySample(history);
    /* query ranking */
    for (i = 0; i < numstp; i++) {
        vis_HistoryGetRank(history, stpnum[i], &rank);
        printf("istep= %d, rank= %d\n", stpnum[i], rank);
    }
    /* determine cutoff rank to retain 3 points
       for last 4 steps */
    vis_HistoryCutoffRank(history, stpnum[1], stpnum[4], 3, &cutoffrank);
    printf("cutoffrank= %d\n", cutoffrank);

    /* traverse steps, retain first and last points
       and any rank greater than cutoff */
    for (i = 1; i <= 4; i++) {
        vis_HistoryGetRank(history, stpnum[i], &rank);
        if (i == 1 || i == 4 || rank > cutoffrank) {
            printf("draw step %d\n", stpnum[i]);
        }
        else {
            printf("ignore step %d\n", stpnum[i]);
        }
    }
    /* end objects */
    vis_HistoryEnd(history);
    return 0;
}
