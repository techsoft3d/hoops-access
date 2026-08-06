#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_ELEM 4
#define NUM_ELEM 2
#define NUM_STEP 5

/* element shape */
static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEQUAD, VIS_SHAPEWED, VIS_SHAPETRI};

/* elem indices */
static Vint ind[NUM_ELEM] = {1, 4};
/* number of sections */
static Vint sec[NUM_ELEM] = {1, 3};
/* step numbers */
static Vint stp[NUM_STEP] = {10, 20, 30, 40, 50};
/* independent step values */
static Vfloat t[NUM_STEP] = {1., 3., 5., 7., 9.};

/*----------------------------------------------------------------------
                      Element Node Scalar Section Results Using History
----------------------------------------------------------------------*/
int
main()
{
    Vint i, j, k, n;
    vis_Connect* connect;
    vis_GridFun* gridfun;
    vis_History* history;
    Vint istep, index, in;
    Vfloat dat[12];
    Vfloat ss[8], ts;
    Vint nument, numstp;
    Vint nix;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create element model */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, 0, MAX_ELEM);
    /* define element topologies */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], 2, 0, 0);
    }
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);

    /* create element node scalar history object */
    history = vis_HistoryBegin();
    vis_HistoryDef(history, NUM_STEP, NUM_ELEM, SYS_ELEM, SYS_NODE, VIS_SCALAR);
    vis_HistorySetObject(history, VIS_GRIDFUN, gridfun);

    /* set number of sections for each element */
    for (i = 0; i < NUM_ELEM; i++) {
        vis_HistorySetDataSect(history, ind[i], sec[i]);
    }
    /* set scalar and independent data values */
    /*  1  digit is element node index
       10  digit is section index
      100  digit is element index
     1000  digit is time step index  */
    for (j = 0; j < NUM_STEP; j++) {
        vis_HistorySetIndep(history, stp[j], t[j]);
        for (i = 0; i < NUM_ELEM; i++) {
            vis_GridFunNumElemNode(gridfun, ind[i], &nix);
            in = 0;
            for (n = 0; n < sec[i]; n++) {
                for (k = 0; k < nix; k++) {
                    dat[in++] = (Vfloat)((j + 1) * 1000 + ind[i] * 100 + (n + 1) * 10 + k + 1);
                }
            }
            vis_HistorySetData(history, stp[j], ind[i], dat);
        }
    }
    /* get scalar and independent value data */
    /* query for number of steps and indices */
    vis_HistoryNumSteps(history, &numstp);
    printf("numstp= %d\n", numstp);
    vis_HistoryNumIndices(history, &nument);
    printf("nument= %d\n", nument);
    /* set section */
    vis_HistorySetSection(history, 1);
    /* loop through steps */
    for (j = 1; j <= numstp; j++) {
        vis_HistoryGetStep(history, j, &istep);
        vis_HistoryIndep(history, istep, &ts);
        printf("istep= %d, indep= %f\n", istep, ts);
        /* loop through indices */
        for (i = 1; i <= nument; i++) {
            vis_HistoryGetIndex(history, i, &index);
            vis_HistoryData(history, istep, 1, &index, ss);
            vis_GridFunNumElemNode(gridfun, index, &nix);
            printf("index= %d\n", index);
            /* loop through element nodes */
            for (k = 0; k < nix; k++) {
                printf("scalar= %f\n", ss[k]);
            }
        }
    }
    /* end objects */
    vis_HistoryEnd(history);
    vis_GridFunEnd(gridfun);
    vis_ConnectEnd(connect);
    return 0;
}
