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

static Vint efl[16][3] = {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1},
                          {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

/*----------------------------------------------------------------------
                      Refine a 3D Surface Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_SurfMesh* surfmesh;
    vis_Connect* connect;
    vis_State* state;

    Vint i, k;
    Vint numtris, numpnts;
    Vint numnp, numel;
    Vdouble x[3];
    Vdouble sn[2][3];
    Vdouble v;
    Vint nix, *ix = NULL;
    Vint i1, i2;
    Vint maxElementNodes = 0;

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
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_SPANANGLE, 45.);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_MINEDGELENGTH, .04);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, .3);

    msh_SurfMeshSetParami(surfmesh, VIS_MESH_SHAPE, SYS_SHAPEQUAD);

    /* generate */
    msh_SurfMeshGenerate(surfmesh, connect);
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("Original mesh complete\n");
    printf("numnp= %d, numel= %d\n", numnp, numel);
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam60a-orig.bdf");

    state = vis_StateBegin();
    vis_StateDef(state, numel, SYS_ELEM, SYS_NONE, VIS_SCALAR);
    /* refine elements in upper right corner */
    maxElementNodes = 0;
    vis_ConnectMaxElemNode(connect, &maxElementNodes);
    ix = (Vint*)vut_MemoryMalloc(maxElementNodes * sizeof(Vint));
    for (i = 1; i <= numel; ++i) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        vis_ConnectCoordsdv(connect, 1, &ix[0], (Vdouble(*)[3])x);
        if (x[0] >= .6 && x[1] >= .6) {
            v = .1;
            vis_StateSetDatadv(state, i, &v);
        }
    }
    vut_MemoryFree(ix);
    /* clear Connect object */
    vis_ConnectDef(connect, 0, 0);
    msh_SurfMeshRefine(surfmesh, state, connect);
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("Refined mesh complete\n");
    printf("numnp= %d, numel= %d\n", numnp, numel);
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam60a-ref.bdf");

    /* end objects */
    vis_ConnectEnd(connect);
    vis_StateEnd(state);
    msh_SurfMeshEnd(surfmesh);
    return 0;
}
