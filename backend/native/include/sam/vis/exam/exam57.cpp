#include "sam/base/system.h"
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*
                 5------6
                /.     /.\
  y            / .    / . \
  |           /  .   /  .  \7------8
  --x        /   1../...2../|      |
 /         12-----13-----14 |      |
z           |  .   |  .   |.|      |
            | .    | .    | 3------4
            |.     |.     |/
            9-----10-----11
*/

#define MAX_ELEM 3
#define MAX_NODE 14

static Vint conn[MAX_ELEM][8] = {{1, 2, 6, 5, 9, 10, 13, 12}, {2, 3, 7, 6, 10, 11, 14, 13}, {3, 4, 8, 7, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 1.}, {3., 0., 1.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 1.}, {3., 1., 1.}, {0., 0., 2.}, {1., 0., 2.},
                                     {2., 0., 2.}, {0., 1., 2.}, {1., 1., 2.}, {2., 1., 2.}};

/*----------------------------------------------------------------------
          Compress and Uncompress Coordinate Field with ZState
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    vis_ZState* zstate;
    vis_Connect* connect;
    vis_GridFun* gridfun;
    vis_State* state;
    Vuchar *bkernel, *bstate;
    Vint i;
    Vulong nbytes, newbytes;
    Vfloat x[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set topologies */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], 2, 0, 0);
    }
    /* set element node connectivity */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
    }
    /* set node coordinates */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }
    /* create GridFun */
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);

    /* create ZState and Def it for nodal data */
    zstate = vis_ZStateBegin();
    vis_ZStateDef(zstate, MAX_NODE, SYS_NODE, SYS_NONE);
    vis_ZStateSetObject(zstate, VIS_GRIDFUN, (Vobject*)gridfun);

    /* create ZState kernel and save it */
    vis_ZStateKernel(zstate, NULL);
    vis_ZStateLngKernel(zstate, &nbytes);
    bkernel = (Vuchar*)malloc(nbytes * sizeof(Vuchar));
    vis_ZStateSaveKernel(zstate, bkernel, &newbytes);
    printf("Kernel size= %lld bytes, actual= %lld\n", nbytes, newbytes);
    /* create coordinate state */
    state = vis_StateBegin();
    vis_StateSetObject(state, VIS_GRIDFUN, (Vobject*)gridfun);
    vis_StateDef(state, MAX_NODE, SYS_NODE, SYS_NONE, SYS_VECTOR);
    for (i = 1; i <= MAX_NODE; i++) {
        vis_ConnectCoords(connect, 1, &i, &x);
        vis_StateSetData(state, i, x);
    }
    /* compress and save coordinate state */
    vis_ZStateState(zstate, state);
    vis_ZStateLngState(zstate, &nbytes);
    bstate = (Vuchar*)malloc(nbytes * sizeof(Vuchar));
    vis_ZStateSaveState(zstate, state, bstate, &newbytes);
    printf("State size= %lld bytes, actual= %lld\n", nbytes, newbytes);

    /* clean-up ZState and State */
    vis_ZStateEnd(zstate);
    vis_StateEnd(state);

    /* instance new ZState and State to reload */
    zstate = vis_ZStateBegin();
    vis_ZStateSetObject(zstate, VIS_GRIDFUN, (Vobject*)gridfun);
    vis_ZStateLoadKernel(zstate, bkernel);
    state = vis_StateBegin();
    vis_StateSetObject(state, VIS_GRIDFUN, (Vobject*)gridfun);
    vis_ZStateLoadState(zstate, bstate, state);

    /* compare compressed and uncompressed values */
    for (i = 1; i <= MAX_NODE; i++) {
        vis_ConnectCoords(connect, 1, &i, &x);
        printf("%5d, %11.4e %11.4e %11.4e, ", i, x[0], x[1], x[2]);
        vis_StateData(state, 1, &i, x);
        printf("%11.4e %11.4e %11.4e\n", x[0], x[1], x[2]);
    }
    /* clean-up */
    vis_ZStateEnd(zstate);
    vis_ConnectEnd(connect);
    vis_GridFunEnd(gridfun);
    vis_StateEnd(state);
    free(bstate);
    free(bkernel);
    return 0;
}
