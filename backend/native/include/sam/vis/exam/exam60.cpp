#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vdouble xc[21][3] = {{5.000e-01, 0.000e+00, 0.000e+00},
                            {4.330e-01, 2.500e-01, 0.000e+00},
                            {2.500e-01, 4.330e-01, 0.000e+00},
                            {0.000e+00, 5.000e-01, 0.000e+00},
                            {-2.500e-01, 4.330e-01, 0.000e+00},
                            {-4.330e-01, 2.500e-01, 0.000e+00},
                            {-5.000e-01, 0.000e+00, 0.000e+00},
                            {-4.330e-01, -2.500e-01, 0.000e+00},
                            {-2.500e-01, -4.330e-01, 0.000e+00},
                            {0.000e+00, -5.000e-01, 0.000e+00},
                            {2.500e-01, -4.330e-01, 0.000e+00},
                            {4.330e-01, -2.500e-01, 0.000e+00},
                            {1., 1., 0.},
                            {-1., 1., 0.},
                            {-1., -1., 0.},
                            {1., -1., 0.},
                            {3.536e-01, 3.536e-01, 0.000e+00},
                            {-3.536e-01, 3.536e-01, 0.000e+00},
                            {-3.536e-01, -3.536e-01, 0.000e+00},
                            {3.536e-01, -3.536e-01, 0.000e+00},
                            {7.500e-01, 0.000e+00, 0.000e+00}};

static Vint pc[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

static Vdouble tng[12][3] = {{0.000, -1.000, 0.000}, {0.500, -0.866, 0.000}, {0.866, -0.500, 0.000},  {1.000, 0.000, 0.000},
                             {0.866, 0.500, 0.000},  {0.500, 0.866, 0.000},  {0.000, 1.000, 0.000},   {-0.500, 0.866, 0.000},
                             {-0.866, 0.500, 0.000}, {-1.000, 0.000, 0.000}, {-0.866, -0.500, 0.000}, {-0.500, -0.866, 0.000}};

static Vdouble tvn[3][3] = {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}};

static Vint tix[16][3] = {{1, 13, 2},  {2, 13, 3},  {3, 13, 4},  {4, 14, 5},   {5, 14, 6},   {6, 14, 7},
                          {7, 15, 8},  {8, 15, 9},  {9, 15, 10}, {10, 16, 11}, {11, 16, 12}, {12, 16, 1},
                          {1, 16, 13}, {4, 13, 14}, {7, 14, 15}, {10, 15, 16}};

static Vint efl[16][3] = {{0, 0, 2}, {0, 0, 2}, {0, 0, 2}, {0, 0, 2}, {0, 0, 2}, {0, 0, 2}, {0, 0, 2}, {0, 0, 2},
                          {0, 0, 2}, {0, 0, 2}, {0, 0, 2}, {0, 0, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

/*----------------------------------------------------------------------
                      Generate a 3D Surface Mesh with User Nodes
----------------------------------------------------------------------*/
int
main()
{
    msh_SurfMesh* surfmesh;
    vis_Connect* connect;

    Vint i, k;
    Vint numtris, numpnts;
    Vint numnp, numel;
    Vdouble x[3];
    Vdouble sn[2][3];
    Vint aid, pid;
    Vint nix, ix[6];
    Vint i1, i2;
    Vint numnegjac, qualflag;

    numpnts = 21;
    numtris = 16;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create SurfMesh object */
    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, numpnts, numtris);

    /* create Connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* define points */
    for (i = 0; i < numpnts; i++) {
        msh_SurfMeshSetPoint(surfmesh, i + 1, xc[i], pc[i]);
    }

    /* define triangle connectivity */
    for (i = 0; i < numtris; i++) {
        msh_SurfMeshSetTri(surfmesh, i + 1, tix[i], efl[i]);
        msh_SurfMeshSetTriNorm(surfmesh, i + 1, tvn);
    }
    /* define triangle side tangents for
       triangle edges in circle */
    for (i = 0; i < 12; i++) {
        i1 = tix[i][2];
        i2 = tix[i][0];
        for (k = 0; k < 3; k++) {
            sn[0][k] = tng[i1 - 1][k];
            sn[1][k] = tng[i2 - 1][k];
        }
        msh_SurfMeshSetTriTang(surfmesh, i + 1, 3, sn);
    }
    /* set unconnected point hints for points 17-20 */
    msh_SurfMeshSetTriHint(surfmesh, 2, SYS_EDGE, 3, 17);
    msh_SurfMeshSetTriHint(surfmesh, 5, SYS_EDGE, 3, 18);
    msh_SurfMeshSetTriHint(surfmesh, 8, SYS_EDGE, 3, 19);
    msh_SurfMeshSetTriHint(surfmesh, 11, SYS_EDGE, 3, 20);

    /* set unconnected point hint for point 21 */
    msh_SurfMeshSetTriHint(surfmesh, 12, SYS_FACE, 0, 21);

    /* set point associations */
    msh_SurfMeshSetPointAssoc(surfmesh, VIS_MISCID, 17, 1017);
    msh_SurfMeshSetPointAssoc(surfmesh, VIS_MISCID, 18, 1018);
    msh_SurfMeshSetPointAssoc(surfmesh, VIS_MISCID, 19, 1019);
    msh_SurfMeshSetPointAssoc(surfmesh, VIS_MISCID, 20, 1020);
    msh_SurfMeshSetPointAssoc(surfmesh, VIS_MISCID, 21, 1021);

    /* set mesh parameters */
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 3);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_SPANANGLE, 60.);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_MINEDGELENGTH, .04);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, .4);

    /* generate */
    msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam60.srf");
    msh_SurfMeshGenerate(surfmesh, connect);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);

    /* query for negative jacobians */
    msh_SurfMeshGetInteger(surfmesh, SURFMESH_NUMNEGJAC, &numnegjac);
    if (numnegjac) {
        printf(" Number of negative jacobians= %d\n", numnegjac);
        for (i = 1; i <= numel; i++) {
            vis_ConnectElemAssoc(connect, VIS_QUALFLAG, 1, &i, &qualflag);
            if (qualflag != 0) {
                printf(" element= %d\n", i);
            }
        }
    }
    /* print node information */
    printf("Node information\n");
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, (Vdouble(*)[3])x);
        vis_ConnectNodeAssoc(connect, VIS_MISCID, 1, &i, &aid);
        printf("id= %d  x= %f, y= %f, z= %f,  aid= %d\n", i, x[0], x[1], x[2], aid);
    }
    /* print element information */
    printf("Element information\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        vis_ConnectElemAssoc(connect, VIS_PROPID, 1, &i, &pid);
        printf("id= %d  ix= %d %d %d %d %d %d, pid= %d\n", i, ix[0], ix[1], ix[2], ix[3], ix[4], ix[5], pid);
    }
    /* write generated mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam60.bdf");

    /* end objects */
    vis_ConnectEnd(connect);
    msh_SurfMeshEnd(surfmesh);
    return 0;
}
