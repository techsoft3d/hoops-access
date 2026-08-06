#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_NODE 4

static Vfloat v[MAX_NODE][3] = {{3., 2., 0.}, {-1., 0., 0.}, {1., 1., 0.}, {2., -2., -4.}};

/*----------------------------------------------------------------------
                      Generate node vector state object
----------------------------------------------------------------------*/
int
main()
{
    vis_State* state;
    Vint i;
    Vfloat vs[9], extent[2][3];
    Vint ix[3];
    Vint ids[2][3], nos[2][3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create node state object */
    state = vis_StateBegin();
    vis_StateDef(state, MAX_NODE, SYS_NODE, SYS_NONE, VIS_VECTOR);

    /* load vector data */
    for (i = 0; i < MAX_NODE; i++) {
        vis_StateSetData(state, i + 1, v[i]);
    }
    /* query derived vector magnitude */
    vis_StateSetDerive(state, VIS_VECTOR_MAG);
    for (i = 1; i <= MAX_NODE; i++) {
        vis_StateData(state, 1, &i, vs);
        printf("index= %d, magnitude= %f\n", i, vs[0]);
    }
    /* query for primitive vector at nodes 2, 3 and 4 */
    vis_StateSetDerive(state, VIS_VECTOR);
    ix[0] = 2;
    ix[1] = 3;
    ix[2] = 4;
    vis_StateData(state, 3, ix, vs);
    for (i = 0; i < 3; i++) {
        printf("index= %d, vector= %f %f %f\n", ix[i], vs[3 * i], vs[3 * i + 1], vs[3 * i + 2]);
    }
    /* query for data extent */
    vis_StateExtent(state, NULL, (Vfloat*)extent);
    printf("vector min= %f %f %f\n", extent[0][0], extent[0][1], extent[0][2]);
    printf("vector max= %f %f %f\n", extent[1][0], extent[1][1], extent[1][2]);

    /* query for data extent and locations */
    vis_StateExtentLoc(state, NULL, (Vfloat*)extent, (Vint*)ids, (Vint*)nos);
    printf("vector min= %f %f %f\n", extent[0][0], extent[0][1], extent[0][2]);
    printf("       ids= %d %d %d\n", ids[0][0], ids[0][1], ids[0][2]);
    printf("vector max= %f %f %f\n", extent[1][0], extent[1][1], extent[1][2]);
    printf("       ids= %d %d %d\n", ids[1][0], ids[1][1], ids[1][2]);

    /* double the values */
    vis_StateOperateUnary(state, STATE_MULTIPLYEQUAL, 2., STATE_UNITY, NULL, NULL);

    /* query for data extent */
    vis_StateExtent(state, NULL, (Vfloat*)extent);
    printf("vector min= %f %f %f\n", extent[0][0], extent[0][1], extent[0][2]);
    printf("vector max= %f %f %f\n", extent[1][0], extent[1][1], extent[1][2]);

    /* take the absolute values */
    vis_StateOperateUnary(state, STATE_EQUAL, 1., STATE_ABS, state, NULL);

    /* query and print all vector data */
    for (i = 1; i <= MAX_NODE; i++) {
        vis_StateData(state, 1, &i, vs);
        printf("index= %d, vector= %f %f %f\n", ix[0], vs[0], vs[1], vs[2]);
    }
    /* end objects */
    vis_StateEnd(state);
    return 0;
}
