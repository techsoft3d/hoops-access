#include <stdio.h>
#include <math.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Generate a Multiple Patch Mapped Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_MapMesh* mapmesh;
    vis_Connect* connect;

    Vdouble radius, angle, length, span, radian;
    Vdouble coords[10][3];
    Vint i;
    Vint pix[8];
    Vint numnp, numel;
    Vdouble x[3];
    Vint aid, aid1, pid;
    Vint nix, ix[4];

    radius = 3.;
    angle = 60.;
    length = 10.;
    span = 50.;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create MapMesh object */
    mapmesh = msh_MapMeshBegin();
    msh_MapMeshDef(mapmesh, 10, 2);

    /* create Connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, 0, 0);

    /* compute points */
    /* cross section radius, compute 4 points */
    for (i = 0; i < 4; i++) {
        radian = i * angle / 3. * (3.14159 / 180.);
        coords[i][0] = radius - radius * cos(radian);
        coords[i][1] = radius * sin(radian);
        coords[i][2] = 0.;
    }
    /* cross section straight length, 1 additional point */
    coords[4][0] = coords[3][0] + length * sin(radian);
    coords[4][1] = coords[3][1] + length * cos(radian);
    coords[4][2] = 0.;
    /* span, 5 more points offset in z from first 5 points */
    for (i = 0; i < 5; i++) {
        coords[i + 5][0] = coords[i][0];
        coords[i + 5][1] = coords[i][1];
        coords[i + 5][2] = coords[i][2] + span;
    }
    /* define points */
    for (i = 0; i < 10; i++) {
        msh_MapMeshSetPoint(mapmesh, i + 1, coords[i]);
    }
    /* define patch point connectivity */
    /* patch 1 */
    pix[0] = 1;
    pix[1] = 2;
    pix[2] = 3;
    pix[3] = 4;
    pix[4] = 6;
    pix[5] = 7;
    pix[6] = 8;
    pix[7] = 9;
    msh_MapMeshSetPatch(mapmesh, 1, VIS_SHAPEQUAD, 4, 2, 0, pix);
    /* patch 2 */
    pix[0] = 4;
    pix[1] = 5;
    pix[2] = 9;
    pix[3] = 10;
    msh_MapMeshSetPatch(mapmesh, 2, VIS_SHAPEQUAD, 2, 2, 0, pix);

    /* set assoc of 1 at z=0. edge */
    msh_MapMeshSetPatchAssoc(mapmesh, VIS_MISCID, 1, SYS_EDGE, 1, 1);
    msh_MapMeshSetPatchAssoc(mapmesh, VIS_MISCID, 2, SYS_EDGE, 1, 1);

    /* set assoc of 2 at z=span edge */
    msh_MapMeshSetPatchAssoc(mapmesh, VIS_MISCID, 1, SYS_EDGE, 3, 2);
    msh_MapMeshSetPatchAssoc(mapmesh, VIS_MISCID, 2, SYS_EDGE, 3, 2);

    /* set property ids as element associations */
    msh_MapMeshSetPatchAssoc(mapmesh, VIS_PROPID, 1, SYS_ELEM, 0, 10);
    msh_MapMeshSetPatchAssoc(mapmesh, VIS_PROPID, 2, SYS_ELEM, 0, 20);

    /* set mesh parameters */
    msh_MapMeshSetParami(mapmesh, VIS_MESH_MAXI, 2);
    /* patch 1 */
    msh_MapMeshSetPatchParami(mapmesh, 1, VIS_MESH_SHAPE, VIS_SHAPEQUAD);
    msh_MapMeshSetPatchParami(mapmesh, 1, MAPMESH_NUMELEMI, 4);
    msh_MapMeshSetPatchParami(mapmesh, 1, MAPMESH_NUMELEMJ, 20);
    /* patch 2 */
    msh_MapMeshSetPatchParami(mapmesh, 2, VIS_MESH_SHAPE, VIS_SHAPEQUAD);
    msh_MapMeshSetPatchParami(mapmesh, 2, MAPMESH_NUMELEMI, 10);
    msh_MapMeshSetPatchParami(mapmesh, 2, MAPMESH_NUMELEMJ, 20);

    /* generate */
    msh_MapMeshGenerate(mapmesh, connect);

    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam41a.bdf");

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
        vis_ConnectElemAssoc(connect, VIS_PROPID, 1, &i, &pid);
        printf("id= %d  ix= %d %d %d %d,  pid= %d\n", i, ix[0], ix[1], ix[2], ix[3], pid);
    }

    /* end objects */
    vis_ConnectEnd(connect);
    msh_MapMeshEnd(mapmesh);
    return 0;
}
