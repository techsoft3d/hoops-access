#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vdouble xc[12][3] = {
{0.000e+00, 0.000e+00, 0.000e+00}, {0.000e+00, 9.000e-01, 0.000e+00}, {1.333e-02, 9.500e-01, 0.000e+00},
{5.000e-02, 9.866e-01, 0.000e+00}, {1.000e-01, 1.000e+00, 0.000e+00}, {1.000e+00, 1.000e+00, 0.000e+00},
{0.000e+00, 0.000e+00, 1.000e+00}, {0.000e+00, 9.000e-01, 1.000e+00}, {1.333e-02, 9.500e-01, 1.000e+00},
{5.000e-02, 9.866e-01, 1.000e+00}, {1.000e-01, 1.000e+00, 1.000e+00}, {1.000e+00, 1.000e+00, 1.000e+00}};

static Vint pc[12] = {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1};

static Vint tix[10][3] = {{1, 2, 7},  {2, 8, 7},  {2, 3, 8},   {3, 9, 8},  {3, 4, 9},
                          {4, 10, 9}, {4, 5, 10}, {5, 11, 10}, {5, 6, 11}, {6, 12, 11}};

static Vint efl[3] = {0, 0, 0};

/*----------------------------------------------------------------------
                      Generate a Surface Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_SurfMesh* surfmesh = NULL;
    vis_Connect* connect = NULL;

    Vint i = 0;
    Vint numnp = 0;
    Vint numel = 0;
    Vdouble x[3] = {0};
    Vint nix = 0;
    Vint ix[3] = {0};

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create SurfMesh object */
    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, 12, 10);

    /* create Connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* define points */
    for (i = 0; i < 12; i++) {
        msh_SurfMeshSetPoint(surfmesh, i + 1, xc[i], pc[i]);
    }
    /* define triangle connectivity */
    for (i = 0; i < 10; i++) {
        msh_SurfMeshSetTri(surfmesh, i + 1, tix[i], efl);
    }

    /* set mesh parameters */
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 2);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_SPANANGLE, 30.);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_MINEDGELENGTH, .02);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, .2);

    /* write out file encapsulating meshing specifications */
    msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam47.srf");
    /* generate */
    msh_SurfMeshGenerate(surfmesh, connect);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);

    /* print node information */
    printf("Node information\n");
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, (Vdouble(*)[3])x);
        printf("id= %d  x= %f, y= %f, z= %f\n", i, x[0], x[1], x[2]);
    }
    /* print element information */
    printf("Element information\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        printf("id= %d  ix= %d %d %d\n", i, ix[0], ix[1], ix[2]);
    }
    /* write generated mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "example47_SurfMeshGenerate.bdf");

    /* end objects */
    vis_ConnectEnd(connect);
    msh_SurfMeshEnd(surfmesh);
    return 0;
}
