#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_ELEM 4
#define NUM_ELEM 2

/* element shape */
static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEQUAD, VIS_SHAPEWED, VIS_SHAPETRI};

/* elem indices */
static Vint ind[NUM_ELEM] = {1, 4};
static Vint numno[NUM_ELEM] = {2, 1};
static Vint no[NUM_ELEM][2] = {{3, 4}, {1, 0}};

/*----------------------------------------------------------------------
                      Element Face and Face Node Results Using State
----------------------------------------------------------------------*/
int
main()
{
    Vint i, j, k, n;
    vis_Connect* connect;
    vis_GridFun* gridfun;
    vis_State *state, *statefn;
    Vfloat s[24];
    Vint ndat, nloc, nsec;
    Vint shape, maxi, maxj, nfx;

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

    /* create element face vector state object */
    state = vis_StateBegin();
    vis_StateDef(state, MAX_ELEM, SYS_FACE, SYS_NONE, VIS_VECTOR);
    vis_StateSetObject(state, VIS_GRIDFUN, gridfun);

    /* set number of faces and face numbers for each element */
    for (i = 0; i < NUM_ELEM; i++) {
        vis_StateSetDataEnt(state, ind[i], numno[i], no[i]);
    }
    /* manufacture and set data */
    for (i = 0; i < NUM_ELEM; i++) {
        s[0] = (Vfloat)no[i][0];
        s[1] = s[0] + .01f;
        s[2] = s[0] + .02f;

        s[3] = (Vfloat)no[i][1];
        s[4] = s[3] + .01f;
        s[5] = s[3] + .02f;
        vis_StateSetData(state, ind[i], s);
    }
    /* get data */
    for (i = 0; i < NUM_ELEM; i++) {
        vis_StateData(state, 1, &ind[i], s);
        vis_StateDataNum(state, ind[i], &ndat, &nloc, &nsec);
        printf("element= %d, data= ", ind[i]);
        for (j = 0; j < ndat; j++) {
            printf(" %e", s[j]);
        }
        printf("\n");
    }
    /* get data at first element face 4 */
    vis_StateDataElemEnt(state, SYS_FACE, ind[0], 4, s);
    printf("element= %d, data= %e %e %e\n", ind[0], s[0], s[1], s[2]);

    vis_StateSetDerive(state, VIS_VECTOR_MAG);
    for (i = 0; i < NUM_ELEM; i++) {
        vis_StateData(state, 1, &ind[i], s);
        printf("element= %d, data= %e\n", ind[i], s[0]);
    }
    /* test element face node state */
    statefn = vis_StateBegin();
    vis_StateDef(statefn, MAX_ELEM, SYS_FACE, SYS_NODE, VIS_VECTOR);
    vis_StateSetObject(statefn, VIS_GRIDFUN, gridfun);
    /* set number of faces and face numbers for each element */
    for (i = 0; i < NUM_ELEM; i++) {
        vis_StateSetDataEnt(statefn, ind[i], numno[i], no[i]);
    }
    /* manufacture and set data */
    /* loop over elements */
    for (i = 0; i < NUM_ELEM; i++) {
        n = 0;
        /* loop over faces */
        for (j = 0; j < numno[i]; j++) {
            vis_ConnectElemTopo(connect, SYS_FACE, ind[i], no[i][j], &shape, &maxi, &maxj);
            /* compute number of face nodes */
            if (shape == SYS_SHAPEQUAD) {
                nfx = 4;
            }
            else {
                nfx = 3;
            }
            /* set data at each face node */
            for (k = 0; k < 3 * nfx; k++) {
                s[n++] = (Vfloat)(ind[i] + no[i][j] + k);
            }
        }
        vis_StateSetData(statefn, ind[i], s);
    }
    /* get data at first element face 4 */
    vis_StateDataElemEnt(statefn, SYS_FACE, ind[0], 4, s);
    printf("element= %d\n", ind[0]);
    for (k = 0; k < 4; k++) {
        printf("k= %d, data= %e %e %e\n", k, s[3 * k], s[3 * k + 1], s[3 * k + 2]);
    }

    vis_StateEnd(state);
    vis_StateEnd(statefn);
    vis_GridFunEnd(gridfun);
    vis_ConnectEnd(connect);
    return 0;
}
