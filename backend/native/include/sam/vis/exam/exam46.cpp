#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vdouble xc[5][3] = {{0., 0., 0.}, {0., .75, 0.}, {.0732233, .9267767, 0.}, {.25, 1., 0.}, {2., 1., 0.}};

static Vint pc[5] = {0, 1, 0, 1, 0};

static Vint lix[4][2] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
static Vdouble vex[4][2][3] = {
{{0., 1., 0.}, {0., 1., 0.}}, {{0., 1., 0.}, {.707, .707, 0.}}, {{.707, .707, 0.}, {1., 0., 0.}}, {{1., 0., 0.}, {1., 0., 0.}}};

/*----------------------------------------------------------------------
                      Generate a Boundary Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_CurvMesh* curvmesh;
    vis_Connect* connect;

    Vint i;
    Vint numnp, numel;
    Vdouble x[3];
    Vint aid, aid1;
    Vint nix, ix[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create CurvMesh object */
    curvmesh = msh_CurvMeshBegin();
    msh_CurvMeshDef(curvmesh, 5, 4);

    /* create Connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, 0, 0);

    /* define points */
    for (i = 0; i < 5; i++) {
        msh_CurvMeshSetPoint(curvmesh, i + 1, xc[i], pc[i]);
    }
    /* define parabolic line segment connectivity */
    for (i = 0; i < 4; i++) {
        msh_CurvMeshSetLine(curvmesh, i + 1, lix[i]);
        msh_CurvMeshSetLineTang(curvmesh, i + 1, vex[i]);
    }
    /* set assoc of 100 at line 1 */
    msh_CurvMeshSetLineAssoc(curvmesh, VIS_MISCID, 1, 100);

    /* set assoc of 200 at point 5 */
    msh_CurvMeshSetPointAssoc(curvmesh, VIS_MISCID1, 5, 200);

    /* set mesh parameters */
    msh_CurvMeshSetParami(curvmesh, VIS_MESH_MAXI, 3);
    msh_CurvMeshSetParamd(curvmesh, VIS_MESH_SPANANGLE, 30.);
    msh_CurvMeshSetParamd(curvmesh, VIS_MESH_EDGELENGTH, .4);

    /* generate */
    msh_CurvMeshGenerate(curvmesh, connect);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);

    vis_ConnectWrite(connect, SYS_SDRC_UNIVERSAL, "exam46.unv");

    /* print node information */
    printf("Node information\n");
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, (Vdouble(*)[3])x);
        vis_ConnectNodeAssoc(connect, VIS_MISCID, 1, &i, &aid);
        vis_ConnectNodeAssoc(connect, VIS_MISCID1, 1, &i, &aid1);
        printf("id= %d  x= %f, y= %f, z= %f,  aid= %d, aid1= %d\n", i, x[0], x[1], x[2], aid, aid1);
    }
    /* print element information */
    printf("Element information\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        printf("id= %d  ix= %d %d %d\n", i, ix[0], ix[1], ix[2]);
    }
    /* end objects */
    vis_ConnectEnd(connect);
    msh_CurvMeshEnd(curvmesh);
    return 0;
}
