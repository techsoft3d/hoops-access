#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vdouble xnode[9][3] = {{2., 0., 0.}, {3., 0., 0.}, {4., 0., 0.}, {2., 0., 1.}, {3., 0., 1.},
                              {4., 0., 1.}, {2., 0., 2.}, {3., 0., 2.}, {4., 0., 2.}};

static Vint ixtri[2][6] = {{1, 3, 7, 2, 5, 4}, {3, 9, 7, 6, 8, 5}};

static Vdouble origin[3] = {0., 0., 0.};
static Vdouble triad[3][3] = {{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}};

/*----------------------------------------------------------------------
                      Generate an Extruded Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_ExtMesh* extmesh;
    vis_Connect* connect;

    Vint i;
    Vdouble xp[3];
    Vint pix[2];
    Vint numnp, numel;
    Vdouble x[3];
    Vint nix, ix[15];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create ExtMesh object */
    extmesh = msh_ExtMeshBegin();
    msh_ExtMeshDef(extmesh, 9, 2);

    /* create Connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, 0, 0);

    /* set coordinate system transformation */
    msh_ExtMeshSetOriginTriad(extmesh, SYS_CYLINDRICAL, origin, triad);

    /* define nodes */
    for (i = 0; i < 9; i++) {
        msh_ExtMeshSetNode(extmesh, i + 1, xnode[i]);
    }
    /* define parabolic triangle connectivity */
    for (i = 0; i < 2; i++) {
        msh_ExtMeshSetElem(extmesh, i + 1, VIS_SHAPETRI, 3, 0, ixtri[i]);
    }
    /* define path end points */
    xp[0] = 0.;
    xp[1] = 0.;
    xp[2] = 0.;
    msh_ExtMeshSetPoint(extmesh, 1, xp);
    xp[1] = 45.;
    msh_ExtMeshSetPoint(extmesh, 2, xp);
    pix[0] = 1;
    pix[1] = 2;
    msh_ExtMeshSetPath(extmesh, 2, pix);

    /* set mesh parameters */
    msh_ExtMeshSetPathParami(extmesh, 1, VIS_MESH_NUMELEMENTS, 4);

    /* generate */
    msh_ExtMeshGenerate(extmesh, connect);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);

    /* print node information */
    printf("Node information\n");
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, (Vdouble(*)[3])x);
        printf("id= %d  x= %e, y= %e, z= %e\n", i, x[0], x[1], x[2]);
    }
    /* print element information */
    printf("Element information\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        printf("id= %d  ix= %d %d %d %d %d %d\n", i, ix[0], ix[1], ix[2], ix[3], ix[4], ix[5]);
        printf("           %d %d %d %d %d %d\n", ix[6], ix[7], ix[8], ix[9], ix[10], ix[11]);
        printf("           %d %d %d\n", ix[12], ix[13], ix[14]);
    }
    /* write out NASTRAN bulk data file */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam42.bdf");

    /* end objects */
    vis_ConnectEnd(connect);
    msh_ExtMeshEnd(extmesh);
    return 0;
}
