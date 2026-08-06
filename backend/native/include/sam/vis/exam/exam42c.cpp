#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vdouble x[16][3] = {{0., 1., 1.}, {1., 1., 1.}, {2., 0., 1.}, {3., 0., 1.}, {4., 1., 1.}, {5., 1., 1.},
                           {0., 1., 0.}, {1., 1., 0.}, {2., 0., 0.}, {3., 0., 0.}, {4., 1., 0.}, {5., 1., 0.},
                           {0., 2., 0.}, {5., 2., 0.}, {0., 2., 1.}, {5., 2., 1.}};

static Vdouble xn[16][3] = {{0., 1., 0.},  {1., 1., 0.},  {1., 1., 0.},  {-1., 1., 0.}, {-1., 1., 0.}, {0., 1., 0.},
                            {0., 1., 0.},  {1., 1., 0.},  {1., 1., 0.},  {-1., 1., 0.}, {-1., 1., 0.}, {0., 1., 0.},
                            {0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}};

static Vint pix[6][4] = {{1, 2, 8, 7}, {2, 3, 9, 8}, {3, 4, 10, 9}, {4, 5, 11, 10}, {5, 6, 12, 11}, {13, 14, 16, 15}};

/*----------------------------------------------------------------------
                      Generate an Extruded Mesh with Interface Layers
----------------------------------------------------------------------*/
int
main()
{
    msh_ExtMesh* extmesh;
    vis_Connect* connect;
    Vint numnp, numel, i, j, nix, ix[8];
    Vdouble y[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create ExtMesh object */
    extmesh = msh_ExtMeshBegin();
    msh_ExtMeshDef(extmesh, 16, 6);

    /* create Connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, 0, 0);

    /* define nodes */
    for (i = 0; i < 16; i++) {
        msh_ExtMeshSetNode(extmesh, i + 1, x[i]);
        msh_ExtMeshSetNodeNormal(extmesh, i + 1, xn[i]);
    }
    /* define linear quadrilateral connectivity */
    for (i = 0; i < 6; i++) {
        msh_ExtMeshSetElem(extmesh, i + 1, VIS_SHAPEQUAD, 2, 0, pix[i]);
    }
    /* set mesh parameters */
    msh_ExtMeshSetParami(extmesh, EXTMESH_NORMAL, SYS_ON);
    msh_ExtMeshSetParami(extmesh, EXTMESH_GLOBALRECEDE, SYS_ON);
    msh_ExtMeshSetParami(extmesh, EXTMESH_FACEMARK, VIS_GEOFACE);
    /* 3 sets of layers with an interface */
    msh_ExtMeshSetNormalPath(extmesh, 4, 0.25, SYS_ON);
    msh_ExtMeshSetNormalPath(extmesh, 5, 0.5, SYS_ON);
    msh_ExtMeshSetNormalPath(extmesh, 4, 0.25, SYS_ON);

    /* generate */
    msh_ExtMeshGenerate(extmesh, connect);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);

    /* print node information */
    printf("Node information\n");
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, &y);
        printf("id= %d  x= %e, y= %e, z= %e\n", i, y[0], y[1], y[2]);
    }
    /* print element information */
    printf("Element information\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        printf("id= %d  ix=", i);
        for (j = 0; j < nix; j++) {
            printf(" %d", ix[j]);
        }
        printf("\n");
    }
    /* write out NASTRAN bulk data file */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam42c.bdf");

    /* end objects */
    vis_ConnectEnd(connect);
    msh_ExtMeshEnd(extmesh);
    return 0;
}
