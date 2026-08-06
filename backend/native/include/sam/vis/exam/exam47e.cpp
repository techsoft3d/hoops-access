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
/* simple square plate to mesh and imprint */
/* offset .1 in Y from mesh it is imprinted on */
static Vdouble xc1[4][3] = {{0.250e+00, 1.100e+00, 0.250e+00},
                            {0.250e+00, 1.100e+00, 0.750e+00},
                            {0.750e+00, 1.100e+00, 0.750e+00},
                            {0.750e+00, 1.100e+00, 0.250e+00}};
static Vint pc1[4] = {1, 1, 1, 1};
static Vint tix1[2][3] = {{1, 2, 3}, {1, 3, 4}};

/*----------------------------------------------------------------------
                      Generate a Surface Mesh With an Imprinted Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_SurfMesh* surfmesh;
    vis_Connect *connect1, *connect;
    vis_Group *groupnode, *groupedge;
    vis_IdTran* idtrannode;

    Vint i, k, n;
    Vint numnp1, numel1;
    Vint numnp, numel;
    Vint numpts, numcorn, numchild;
    Vdouble x[3];
    Vint nix, ixe[2], ide[3], ice[2];
    Vint flag, flagk;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create first mesh to be imprinted */
    /* create SurfMesh object */
    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, 4, 2);
    /* define points */
    for (i = 0; i < 4; i++) {
        msh_SurfMeshSetPoint(surfmesh, i + 1, xc1[i], pc1[i]);
    }
    /* define triangle connectivity */
    for (i = 0; i < 2; i++) {
        msh_SurfMeshSetTri(surfmesh, i + 1, tix1[i], efl);
    }
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 3);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, .1);
    connect1 = vis_ConnectBegin();
    vis_ConnectPre(connect1, SYS_DOUBLE);
    vis_ConnectDef(connect1, 0, 0);
    msh_SurfMeshGenerate(surfmesh, connect1);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect1, SYS_NODE, &numnp1);
    vis_ConnectNumber(connect1, SYS_ELEM, &numel1);
    printf("numnp= %d, numel= %d\n", numnp1, numel1);

    /* extract corner nodes to imprint */
    groupnode = vis_GroupBegin();
    vis_GroupDef(groupnode, numnp1, SYS_NODE, SYS_NONE);
    vis_ConnectNodeGroup(connect1, CONNECT_CORNER, NULL, groupnode);
    vis_GroupCount(groupnode, &numcorn, &numchild);

    /* extract unique edges to imprint */
    vis_ConnectKernel(connect1, 0);
    groupedge = vis_GroupBegin();
    vis_GroupDef(groupedge, numel1, SYS_ELEM, SYS_EDGE);
    vis_ConnectEdgeGroup(connect1, CONNECT_UNIQUE, NULL, groupedge);

    /* total nodes now includes nodes to be imprinted */
    numpts = 12 + numcorn;
    msh_SurfMeshDef(surfmesh, numpts, 10);
    /* create Connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);
    /* define geometry points */
    for (i = 0; i < 12; i++) {
        msh_SurfMeshSetPoint(surfmesh, i + 1, xc[i], pc[i]);
    }
    /* add imprinted points and preserve them */
    /* need to relate point number, n, to node in mesh */
    idtrannode = vis_IdTranBegin();
    vis_IdTranDef(idtrannode, numnp1);
    n = 12;
    for (i = 1; i <= numnp1; i++) {
        vis_GroupGetIndex(groupnode, i, &flag);
        if (flag == 0)
            continue;
        vis_ConnectCoordsdv(connect1, 1, &i, (Vdouble(*)[3])x);
        n += 1;
        vis_IdTranSetId(idtrannode, i, n);
        msh_SurfMeshSetPoint(surfmesh, n, x, 1);
    }
    /* define recovered edges */
    for (i = 1; i <= numel1; i++) {
        vis_GroupGetIndex(groupedge, i, &flag);
        if (flag == 0)
            continue;
        /* extract corner nodes of edge and find point numbers */
        for (k = 1; k <= 3; k++) {
            vis_GroupGetEntFlag(groupedge, i, k, &flagk);
            if (flagk == 0)
                continue;
            vis_ConnectElemCon(connect1, SYS_EDGE, i, k, &nix, ide);
            ice[0] = ide[0];
            ice[1] = ide[2];
            vis_IdTranGetIds(idtrannode, 2, ice, ixe);
            msh_SurfMeshSetEdge(surfmesh, 0, 2, ixe, 0, NULL);
        }
    }
    /* define triangle connectivity */
    for (i = 0; i < 10; i++) {
        msh_SurfMeshSetTri(surfmesh, i + 1, tix[i], efl);
    }
    /* set mesh parameters */
    /* set option to project imprinted nodes to geometry */
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_UNCONNECTPROJECT, SYS_ON);
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 3);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_SPANANGLE, 30.);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_MINEDGELENGTH, .02);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, .2);

    /* write out file encapsulating meshing specifications
       for debugging purposes */
    msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam47e.srf");
    /* generate */
    msh_SurfMeshGenerate(surfmesh, connect);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);

    /* now append first mesh to second so that when written
       to a .bdf file you see both */
    vis_ConnectAppend(connect, connect1);

    /* write generated mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam47e.bdf");

    /* end objects */
    vis_IdTranEnd(idtrannode);
    vis_GroupEnd(groupnode);
    vis_GroupEnd(groupedge);
    vis_ConnectEnd(connect1);
    vis_ConnectEnd(connect);
    msh_SurfMeshEnd(surfmesh);
    return 0;
}
