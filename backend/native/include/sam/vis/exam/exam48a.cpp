#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
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

/* isotropic size function */
static void
s_iso(msh_SurfMesh* surfmesh, Vobject* usrobj, Vdouble x[3], Vdouble* s)
{
    /* linear size gradation in x direction */
    *s = .02 + .2 * x[0];
}

/* anisotropic size function */
static void
s_aniso(msh_SurfMesh* surfmesh, Vobject* usrobj, Vdouble x[3], Vdouble s[3][3])
{
    Vdouble s1, s2, s3;
    /* 4 to 1 aspect ratio at 45 degree angle in x,y */
    s1 = .025;
    s[0][0] = s1 * .707;
    s[0][1] = s1 * .707;
    s[0][2] = 0.;

    s2 = .1;
    s[1][0] = s2 * -.707;
    s[1][1] = s2 * .707;
    s[1][2] = 0.;
    /* z */
    s3 = .2;
    s[2][0] = 0.;
    s[2][1] = 0.;
    s[2][2] = s3 * 1.;
}

/*----------------------------------------------------------------------
                      Generate an Anisotropic Surface Mesh and Tet Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_SurfMesh* surfmesh;
    msh_TetMesh* tetmesh;
    vis_Connect *connectsurf, *connecttet;

    Vint i;
    Vint numsurfpnts, numsurftris;
    Vint numnp, numel;
    Vdouble x[3];
    Vint nix, ix[3];
    Vint iso;

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

    /* set iso to 1 for isotropic, 0 for anisotropic */
    iso = 1;
    /* set isotropic sizing function */
    if (iso) {
        msh_SurfMeshSetFunction(surfmesh, SYS_FUNCTION_SIZING, (Vfunc*)s_iso, NULL);
        /* set anisotropic sizing function */
    }
    else {
        msh_SurfMeshSetFunction(surfmesh, SYS_FUNCTION_ASIZING, (Vfunc*)s_aniso, NULL);
    }
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

    /* write generated surf mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connectsurf, SYS_NASTRAN_BULKDATA, "exam48a_srf.bdf");

    /* create TetMesh object */
    tetmesh = msh_TetMeshBegin();
    msh_TetMeshDef(tetmesh, numsurfpnts, numsurftris, 2);

    /* Fill TetMesh object with generated points on surface */
    for (i = 1; i <= numsurfpnts; i++) {
        vis_ConnectCoordsdv(connectsurf, 1, &i, (Vdouble(*)[3])x);
        msh_TetMeshSetNode(tetmesh, i, x);
    }
    /* Fill TetMesh object with generated triangles */
    for (i = 1; i <= numsurftris; i++) {
        vis_ConnectElemNode(connectsurf, i, &nix, ix);
        msh_TetMeshSetTri(tetmesh, i, ix);
    }

    /* create Connect object to hold generated tet mesh */
    connecttet = vis_ConnectBegin();
    vis_ConnectPre(connecttet, SYS_DOUBLE);
    vis_ConnectDef(connecttet, 0, 0);

    /* set isotropic sizing function */
    if (iso) {
        msh_TetMeshSetFunction(tetmesh, SYS_FUNCTION_SIZING, (Vfunc*)s_iso, NULL);
        /* set anisotropic sizing function */
    }
    else {
        msh_TetMeshSetFunction(tetmesh, SYS_FUNCTION_ASIZING, (Vfunc*)s_aniso, NULL);
    }
    /* generate mesh */
    msh_TetMeshGenerate(tetmesh, connecttet);
    if (msh_TetMeshError(tetmesh)) {
        printf("tet mesh generation error\n");
        exit(1);
    }
    else {
        printf("tet mesh generation complete\n");
    }
    /* print number of surface nodes and elements */
    vis_ConnectNumber(connecttet, SYS_NODE, &numnp);
    vis_ConnectNumber(connecttet, SYS_ELEM, &numel);
    printf(" Number of nodes= %d\n", numnp);
    printf(" Number of elems= %d\n", numel);

    /* write generated tet mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connecttet, SYS_NASTRAN_BULKDATA, "exam48a_tet.bdf");

    /* end objects */
    vis_ConnectEnd(connectsurf);
    vis_ConnectEnd(connecttet);
    msh_SurfMeshEnd(surfmesh);
    msh_TetMeshEnd(tetmesh);
    return 0;
}
