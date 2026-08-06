#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* point coordinates */
static Vdouble xc[20][3] = {{0.000e+00, 0.000e+00, 0.000e+00},
                            {0.000e+00, 9.000e-01, 0.000e+00},
                            {1.333e-02, 9.500e-01, 0.000e+00},
                            {5.000e-02, 9.867e-01, 0.000e+00},
                            {1.000e-01, 1.000e+00, 0.000e+00},
                            {1.000e+00, 1.000e+00, 0.000e+00},
                            {0.000e+00, 0.000e+00, 1.000e+00},
                            {0.000e+00, 9.000e-01, 1.000e+00},
                            {1.333e-02, 9.500e-01, 1.000e+00},
                            {5.000e-02, 9.867e-01, 1.000e+00},
                            {1.000e-01, 1.000e+00, 1.000e+00},
                            {1.000e+00, 1.000e+00, 1.000e+00},
                            {1.500e+00, 9.000e-01, 0.000e+00},
                            {1.500e+00, 9.000e-01, 1.000e+00},
                            {1.000e+00, 0.000e+00, 0.000e+00},
                            {1.000e+00, 0.000e+00, 1.000e+00},
                            {1.0, .33, .66},
                            {1.0, .33, .33},
                            {1.0, .66, .33},
                            {1.0, .66, .66}};

/* point preservation flags */
static Vint pc[20] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};

/* triangle connectivity */
static Vint tix[14][3] = {{1, 2, 7},   {2, 8, 7},  {2, 3, 8},   {3, 9, 8},   {3, 4, 9},    {4, 10, 9},  {4, 5, 10},
                          {5, 11, 10}, {5, 6, 11}, {6, 12, 11}, {6, 13, 12}, {13, 14, 12}, {12, 15, 6}, {16, 15, 12}};

/* triangle node normals */
static Vdouble tvn[14][3][3] = {{{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},

                                {{1., 0., 0.}, {.867, -.500, 0.}, {1., 0., 0.}},
                                {{.867, -.500, 0.}, {.867, -.500, 0.}, {1., 0., 0.}},

                                {{.867, -.500, 0.}, {.500, -.867, 0.}, {.867, -.500, 0.}},
                                {{.500, -.867, 0.}, {.500, -.867, 0.}, {.867, -.500, 0.}},

                                {{.500, -.867, 0.}, {0., -1., 0.}, {.500, -.867, 0.}},
                                {{0., -1., 0.}, {0., -1., 0.}, {.500, -.867, 0.}},

                                {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},

                                {{-.196, -.981, 0.}, {-.196, -.981, 0.}, {-.196, -.981, 0.}},
                                {{-.196, -.981, 0.}, {-.196, -.981, 0.}, {-.196, -.981, 0.}},

                                {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}}};

/* triangle property ids */
static Vint tpid[14] = {1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 4, 4};

/*----------------------------------------------------------------------
                      Generate a 3D Surface Mesh with Trimming Loop
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connectgeo;
    vis_Group *groupface, *groupedge;
    msh_SurfMesh* surfmesh;
    vis_Connect* connect;

    Vint i, k;
    Vint numpnts, numtris;
    Vint flags;
    Vint efl[3];
    Vint numnp, numel;
    Vdouble x[3], ve[6][3];
    Vint aid, aid1, pid;
    Vint nix, ix[6];
    Vint eix[5];

    vsy_LicenseValidate(HOOPS_LICENSE);

    numpnts = 20;
    numtris = 14;
    /* enter geometry */
    connectgeo = vis_ConnectBegin();
    vis_ConnectPre(connectgeo, SYS_DOUBLE);
    vis_ConnectDef(connectgeo, numpnts, numtris);

    /* enter points */
    for (i = 0; i < numpnts; i++) {
        vis_ConnectSetCoordsdv(connectgeo, i + 1, xc[i]);
    }
    /* enter triangles */
    for (i = 0; i < numtris; i++) {
        vis_ConnectSetTopology(connectgeo, i + 1, VIS_SHAPETRI, 2, 0, 0);
        vis_ConnectSetElemNode(connectgeo, i + 1, tix[i]);
        vis_ConnectSetElemNormdv(connectgeo, i + 1, 1, tvn[i]);
    }
    vis_ConnectKernel(connectgeo, 0);

    /* determine feature edges */
    /* group of faces */
    groupface = vis_GroupBegin();
    vis_GroupDef(groupface, numtris, SYS_ELEM, SYS_FACE);
    vis_ConnectFaceGroup(connectgeo, CONNECT_FREE, NULL, groupface);

    /* extract feature edges and nodes at 10. degrees */
    vis_ConnectSetGroupParamf(connectgeo, CONNECT_FEATUREANGLE, 10.);
    vis_ConnectSetGroupParami(connectgeo, CONNECT_FEATURESENSE, VIS_ON);

    /* curvature changes greater than unity */
    vis_ConnectSetGroupParamf(connectgeo, CONNECT_CURVATURECHANGE, 1.);

    /* group of feature edges */
    groupedge = vis_GroupBegin();
    vis_GroupDef(groupedge, numtris, SYS_ELEM, SYS_EDGE);
    /* surface discontinuity */
    vis_ConnectEdgeGroup(connectgeo, CONNECT_FEATURE, groupface, groupedge);
    /* curvature discontinuity */
    vis_ConnectEdgeGroup(connectgeo, CONNECT_CURVATURE, groupface, groupedge);

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
    /* set node associations at points */
    msh_SurfMeshSetPointAssoc(surfmesh, VIS_MISCID1, 1, 1011);
    msh_SurfMeshSetPointAssoc(surfmesh, VIS_MISCID, 7, 1001);

    /* define triangle connectivity and property id */
    for (i = 0; i < numtris; i++) {
        for (k = 1; k <= 3; k++) {
            vis_GroupGetEntFlag(groupedge, i + 1, k, &flags);
            if (flags) {
                efl[k - 1] = 1;
            }
            else {
                efl[k - 1] = 0;
            }
        }
        msh_SurfMeshSetTri(surfmesh, i + 1, tix[i], efl);
        msh_SurfMeshSetTriNorm(surfmesh, i + 1, tvn[i]);
        msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, i + 1, SYS_ELEM, 0, tpid[i]);
        /* specific sizing for region 3 */
        if (tpid[i] == 3) {
            msh_SurfMeshSetTriSizing(surfmesh, i + 1, SYS_FACE, 0, .05);
        }
        if ((i + 1) == 12) {
            msh_SurfMeshSetTriSizing(surfmesh, i + 1, SYS_EDGE, 1, .0125);
        }
    }
    /* set trimming loop */
    eix[0] = 20;
    eix[1] = 19;
    eix[2] = 18;
    eix[3] = 17;
    eix[4] = 20;
    msh_SurfMeshSetEdge(surfmesh, VIS_ON, 5, eix, VIS_OFF, NULL);

    /* set node associations at triangle edge */
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_MISCID, 2, SYS_EDGE, 1, 1002);

    /* set node associations on triangles */
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_MISCID, 1, SYS_FACE, 0, 1003);
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_MISCID, 2, SYS_FACE, 0, 1003);

    /* set mesh parameters */
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 3);
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_COMPUTENORMAL, 1);
    msh_SurfMeshSetParami(surfmesh, SURFMESH_NONMANIFOLD, VIS_ON);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_SPANANGLE, 60.);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_MINEDGELENGTH, .04);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, .4);

    msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam47d.srf");
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
        vis_ConnectNodeAssoc(connect, VIS_MISCID, 1, &i, &aid);
        vis_ConnectNodeAssoc(connect, VIS_MISCID1, 1, &i, &aid1);
        printf("id= %d  x= %f, y= %f, z= %f,  aid= %d, aid1= %d\n", i, x[0], x[1], x[2], aid, aid1);
    }
    /* print element information */
    printf("Element information\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        /* element connectivity */
        vis_ConnectElemAssoc(connect, VIS_PROPID, 1, &i, &pid);
        printf("id= %d  ix= %d %d %d %d %d %d, pid= %d\n", i, ix[0], ix[1], ix[2], ix[3], ix[4], ix[5], pid);
        /* element normals */
        vis_ConnectElemNormdv(connect, i, 1, ve);
        for (k = 0; k < nix; k++) {
            printf("        n= %e %e %e\n", ve[k][0], ve[k][1], ve[k][2]);
        }
    }
    /* write generated mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam47d.bdf");

    /* end objects */
    vis_ConnectEnd(connectgeo);
    vis_GroupEnd(groupface);
    vis_GroupEnd(groupedge);
    vis_ConnectEnd(connect);
    msh_SurfMeshEnd(surfmesh);
    return 0;
}
