#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vdouble x[20][3] = {{1., 0., 0.}, {4., 0., 0.}, {0., 3., 0.}, {1., 3., 0.}, {4., 3., 0.}, {5., 3., 0.}, {2., 4., 0.},
                           {4., 4., 0.}, {1., 5., 0.}, {3., 5., 0.}, {2., 6., 0.}, {4., 6., 0.}, {1., 7., 0.}, {3., 7., 0.},
                           {0., 8., 0.}, {5., 8., 0.}, {2., 1., 0.}, {3., 1., 0.}, {2., 2., 0.}, {3., 2., 0.}};

static Vint ix[20][2] = {{1, 2},   {2, 5},   {5, 4},   {4, 1},

                         {3, 6},   {6, 16},  {16, 15}, {15, 3},

                         {9, 10},  {10, 14}, {14, 13}, {13, 9},

                         {7, 8},   {8, 12},  {12, 11}, {11, 7},

                         {17, 19}, {19, 20}, {20, 18}, {18, 17}};

/*----------------------------------------------------------------------
                      Tesselate and Mesh a Bounded Region in a Plane
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect *connect, *tess;
    msh_TriMesh* trimesh;
    msh_SurfMesh* surfmesh;
    Vint n, numnp, numel, nix, jx[3], aid[20], num, k, efls[3], i;
    Vdouble xd[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* define original geometry */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    for (n = 1; n <= 20; n++) {
        vis_ConnectSetCoordsdv(connect, n, x[n - 1]);
    }
    for (n = 1; n <= 20; n++) {
        vis_ConnectSetTopology(connect, n, SYS_SHAPELINE, 2, 0, 0);
        vis_ConnectSetElemNode(connect, n, ix[n - 1]);
        vis_ConnectSetElemAssoc(connect, VIS_PROPID, n, (n - 1) / 4 + 1);
    }
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam51-bound.bdf");

    /* tesselate geometry */
    tess = vis_ConnectBegin();
    vis_ConnectPre(tess, SYS_DOUBLE);
    vis_ConnectTess(tess, connect);
    vis_ConnectEnd(connect);
    vis_ConnectWrite(tess, SYS_NASTRAN_BULKDATA, "exam51-tess.bdf");

    vis_ConnectNumber(tess, SYS_NODE, &numnp);
    vis_ConnectNumber(tess, SYS_ELEM, &numel);

    /* create trimesh object */
    trimesh = msh_TriMeshBegin();
    msh_TriMeshDef(trimesh, numnp, numel, 2);
    msh_TriMeshSetParamd(trimesh, VIS_MESH_EDGELENGTH, 10.);

    /* define trimesh nodes */
    for (n = 1; n <= numnp; n++) {
        vis_ConnectCoordsdv(tess, 1, &n, (Vdouble(*)[3])xd);
        msh_TriMeshSetNode(trimesh, n, xd);
    }
    /* define trimesh lines */
    for (n = 1; n <= numel; n++) {
        vis_ConnectElemNode(tess, n, &nix, jx);
        msh_TriMeshSetLine(trimesh, n, jx);
        vis_ConnectAllElemAssoc(tess, VIS_PROPID, n, &num, aid);
        for (k = 0; k < num; k++) {
            msh_TriMeshSetLineAssoc(trimesh, VIS_PROPID, n, SYS_ELEM, aid[k]);
            msh_TriMeshSetLineAssoc(trimesh, VIS_PROPID, n, SYS_EDGE, aid[k]);
        }
    }
    vis_ConnectEnd(tess);

    connect = vis_ConnectBegin();
    msh_TriMeshWrite(trimesh, SYS_ASCII, "exam51.tri");
    msh_TriMeshGenerate(trimesh, connect);
    msh_TriMeshEnd(trimesh);
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam51-tri.bdf");

    /* use output from TriMesh as input to SurfMesh */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, numnp, numel);

    for (n = 1; n <= numnp; n++) {
        vis_ConnectCoordsdv(connect, 1, &n, (Vdouble(*)[3])xd);
        msh_SurfMeshSetPoint(surfmesh, n, xd, 1);
    }

    for (n = 1; n <= numel; n++) {
        vis_ConnectElemNode(connect, n, &nix, jx);
        efls[0] = efls[1] = efls[2] = 0;
        for (i = 1; i <= 3; i++) {
            vis_ConnectAllElemEntAssoc(connect, VIS_PROPID, SYS_EDGE, n, i, &num, aid);
            if (num) {
                if (aid[0]) {
                    efls[i - 1] = 1;
                }
            }
        }
        msh_SurfMeshSetTri(surfmesh, n, jx, efls);
        for (i = 1; i <= 3; i++) {
            vis_ConnectAllElemEntAssoc(connect, VIS_PROPID, SYS_EDGE, n, i, &num, aid);
            if (num) {
                for (k = 0; k < num; k++) {
                    msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, n, SYS_EDGE, i, aid[k]);
                }
            }
        }

        vis_ConnectAllElemAssoc(connect, VIS_PROPID, n, &num, aid);
        if (num) {
            for (k = 0; k < num; k++) {
                msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, n, SYS_ELEM, 1, aid[k]);
                msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, n, SYS_FACE, 1, aid[k]);
            }
        }
    }
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, 0.5);
    vis_ConnectEnd(connect);

    connect = vis_ConnectBegin();
    msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam51.srf");
    msh_SurfMeshGenerate(surfmesh, connect);
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam51-srf.bdf");

    /* print result */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("Nodes:\n");
    for (n = 1; n <= numnp; n++) {
        vis_ConnectCoordsdv(connect, 1, &n, (Vdouble(*)[3])xd);
        printf("node= %d, x= %e, y= %e\n", n, xd[0], xd[1]);
    }

    printf("Elements:\n");
    for (n = 1; n <= numel; n++) {
        vis_ConnectElemNode(connect, n, &nix, jx);
        printf("elem= %d, nodes= %d %d %d, assoc= ", n, jx[0], jx[1], jx[2]);
        vis_ConnectAllElemAssoc(connect, VIS_PROPID, n, &num, aid);
        for (k = 0; k < num; k++) {
            printf("%d ", aid[k]);
        }
        printf("\n");
    }
    /* end objects */
    vis_ConnectEnd(connect);
    msh_SurfMeshEnd(surfmesh);
    return 0;
}
