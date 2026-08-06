#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vdouble coords[8][3] = {{0., 0., 0.}, {10., 0., 0.}, {0., 1., 0.}, {10., 1., 0.},
                               {0., 0., 2.}, {10., 0., 2.}, {0., 1., 2.}, {10., 1., 2.}};

/*----------------------------------------------------------------------
                      Generate a 3D Mapped Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_MapMesh* mapmesh;
    vis_Connect* connect;

    Vint i, j;
    Vint pix[8];
    Vint numnp, numel;
    Vdouble x[3];
    Vint aid, aid1;
    Vint nix, ix[20];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create MapMesh object */
    mapmesh = msh_MapMeshBegin();
    msh_MapMeshDef(mapmesh, 8, 1);

    /* create Connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* define points */
    for (i = 0; i < 8; i++) {
        msh_MapMeshSetPoint(mapmesh, i + 1, coords[i]);
    }
    /* define patch connectivity */
    pix[0] = 1;
    pix[1] = 2;
    pix[2] = 3;
    pix[3] = 4;
    pix[4] = 5;
    pix[5] = 6;
    pix[6] = 7;
    pix[7] = 8;
    msh_MapMeshSetPatch(mapmesh, 1, VIS_SHAPEHEX, 2, 2, 2, pix);

    /* set assoc of 100 at edge 4 */
    msh_MapMeshSetPatchAssoc(mapmesh, VIS_MISCID, 1, SYS_EDGE, 4, 100);

    /* set assoc of 200 at point 2 */
    msh_MapMeshSetPointAssoc(mapmesh, VIS_MISCID1, 2, 200);

    /* set mesh parameters */
    msh_MapMeshSetParami(mapmesh, VIS_MESH_MAXI, 3);
    msh_MapMeshSetPatchParami(mapmesh, 1, VIS_MESH_SHAPE, VIS_SHAPEHEX);
    msh_MapMeshSetPatchParami(mapmesh, 1, MAPMESH_NUMELEMI, 8);
    msh_MapMeshSetPatchParami(mapmesh, 1, MAPMESH_NUMELEMJ, 2);
    msh_MapMeshSetPatchParami(mapmesh, 1, MAPMESH_NUMELEMK, 2);

    /* generate */
    msh_MapMeshGenerate(mapmesh, connect);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);

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
        printf("id= %d  ix= ", i);
        for (j = 0; j < nix; j++) {
            printf(" %d", ix[j]);
        }
        printf("\n");
    }

    /* end objects */
    vis_ConnectEnd(connect);
    msh_MapMeshEnd(mapmesh);
    return 0;
}
