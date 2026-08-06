#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/system.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* a simple unit cube */
static Vdouble xc[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                           {0., 0., 1.}, {1., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}};

static Vint tris[12][3] = {{1, 5, 3}, {3, 5, 7}, {4, 6, 2}, {8, 6, 4}, {1, 2, 5}, {5, 2, 6},
                           {7, 4, 3}, {8, 4, 7}, {1, 4, 2}, {4, 1, 3}, {5, 8, 7}, {5, 6, 8}};
static Vint tefl[12][3] = {{1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {1, 0, 1}, {1, 0, 1}, {0, 1, 1},
                           {0, 1, 1}, {1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {0, 1, 1}, {1, 1, 0}};

static Vdouble norms[12][3][3] = {{{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}}, {{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}},
                                  {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},    {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                  {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}}, {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                  {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},    {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},
                                  {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}}, {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}},
                                  {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}},    {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}}};

/*----------------------------------------------------------------------
                      Generate a Surface Mesh and Pyr/Tet Mesh Interior Sizing
----------------------------------------------------------------------*/
int
main()
{
    msh_SurfMesh* surfmesh;
    msh_VolMesh* volmesh;
    vis_Connect *connectsurf, *connectvol;

    Vint i;
    Vint numsurfpnts, numsurftris;
    Vint numnp, numel;
    Vdouble x[3];
    Vint nix, ix[4];
    Vdouble isize, bsize;
    Vdouble xo[3], xa[3], xb[3], d[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create SurfMesh object */
    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, 8, 12);

    /* create Connect object */
    connectsurf = vis_ConnectBegin();
    vis_ConnectPre(connectsurf, SYS_DOUBLE);
    vis_ConnectDef(connectsurf, 0, 0);

    /* define points */
    for (i = 0; i < 8; i++) {
        msh_SurfMeshSetPoint(surfmesh, i + 1, xc[i], 1);
    }
    /* define triangle connectivity */
    for (i = 0; i < 12; i++) {
        msh_SurfMeshSetTri(surfmesh, i + 1, tris[i], tefl[i]);
        msh_SurfMeshSetTriNorm(surfmesh, i + 1, norms[i]);
    }
    /* set mesh parameters */
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 2);
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_SHAPE, VIS_SHAPEQUAD);
    /* boundary size */
    bsize = .05;
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, bsize);
    /* generate */
    msh_SurfMeshGenerate(surfmesh, connectsurf);
    if (msh_SurfMeshError(surfmesh)) {
        printf("surf mesh generation error\n");
        exit(1);
    }
    else {
        printf("surf mesh generation complete\n");
    }
    /* print number of surface nodes and elements */
    vis_ConnectNumber(connectsurf, SYS_NODE, &numsurfpnts);
    vis_ConnectNumber(connectsurf, SYS_ELEM, &numsurftris);
    printf(" Number of nodes= %d\n", numsurfpnts);
    printf(" Number of tris = %d\n", numsurftris);

    /* create VolMesh object */
    volmesh = msh_VolMeshBegin();
    msh_VolMeshDef(volmesh, numsurfpnts, numsurftris);
    /* interior ellipsoidal shape for sizing */
    /* positioned in center of cube */
    xo[0] = .5;
    xo[1] = .5;
    xo[2] = .5;
    /* oriented along x axis and at 45 degrees in y-z plane */
    xa[0] = 1.0;
    xa[1] = .5;
    xa[2] = .5;
    xb[0] = .5;
    xb[1] = 1.0;
    xb[2] = 1.0;
    /* lengths of ellipsoid along each axis */
    d[0] = .10;
    d[1] = .20;
    d[2] = .30;
    msh_VolMeshSetGeomSizing(volmesh, VIS_MESH_GEOMSPHERE, xo, xa, xb, d, 0.02);

    /* interior sizing */
    isize = .2;
    msh_VolMeshSetParamd(volmesh, VIS_MESH_EDGELENGTH, isize);

    /* Fill VolMesh object with generated points on surface */
    for (i = 1; i <= numsurfpnts; i++) {
        vis_ConnectCoordsdv(connectsurf, 1, &i, (Vdouble(*)[3])x);
        msh_VolMeshSetNode(volmesh, i, x);
    }
    /* Fill VolMesh object with generated triangles */
    for (i = 1; i <= numsurftris; i++) {
        vis_ConnectElemNode(connectsurf, i, &nix, ix);
        msh_VolMeshSetFace(volmesh, i, VIS_SHAPEQUAD, 0, 0, ix);
    }
    /* set boundary depth and size */
    for (i = 1; i <= numsurftris; i++) {
        msh_VolMeshSetFaceDepthSizing(volmesh, i, 0.1, bsize);
    }
    /* create Connect object to hold generated pyr/tet mesh */
    connectvol = vis_ConnectBegin();
    vis_ConnectPre(connectvol, SYS_DOUBLE);
    vis_ConnectDef(connectvol, 0, 0);

    msh_VolMeshWrite(volmesh, SYS_ASCII, "exam48f.vol");
    /* generate mesh */
    msh_VolMeshGenerate(volmesh, connectvol);
    if (msh_VolMeshError(volmesh)) {
        printf("Vol mesh generation error\n");
        exit(1);
    }
    else {
        printf("Vol mesh generation complete\n");
    }
    /* print number of surface nodes and elements */
    vis_ConnectNumber(connectvol, SYS_NODE, &numnp);
    vis_ConnectNumber(connectvol, SYS_ELEM, &numel);
    printf(" Number of nodes= %d\n", numnp);
    printf(" Number of elems= %d\n", numel);

    /* write generated mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connectvol, SYS_NASTRAN_BULKDATA, "exam48f.bdf");

    /* end objects */
    vis_ConnectEnd(connectsurf);
    vis_ConnectEnd(connectvol);
    msh_SurfMeshEnd(surfmesh);
    msh_VolMeshEnd(volmesh);
    return 0;
}
