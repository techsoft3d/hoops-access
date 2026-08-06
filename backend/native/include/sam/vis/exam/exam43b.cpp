#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_NODE 8
#define MAX_LINE 8

/* a square with a rectangular hole */
static Vdouble coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                                      {.2, .2, 0.}, {.8, .2, 0.}, {.2, .8, 0.}, {.8, .8, 0.}};

static Vint lines[MAX_LINE][2] = {{1, 2}, {2, 4}, {4, 3}, {3, 1}, {5, 7}, {7, 8}, {8, 6}, {6, 5}};

/* isotropic size function */
static void
s_iso(msh_TriMesh* trimesh, Vobject* usrobj, Vdouble x[3], Vdouble* s)
{
    printf("s_iso called\n");
    /* linear variation in y direction */
    *s = .05 + .05 * x[1];
    printf("x= %e %e %e, s= %e\n", x[0], x[1], x[2], *s);
}
/* anisotropic size function */
static void
s_aniso(msh_TriMesh* trimesh, Vobject* usrobj, Vdouble x[3], Vdouble s[3][3])
{
    Vdouble s1, s2, s3;
    printf("s_aniso called\n");
    /* 4 to 1 aspect ratio at 45 degree angle */
    s1 = .025;
    s[0][0] = s1 * .707;
    s[0][1] = s1 * .707;
    s[0][2] = 0.;

    s2 = .1;
    s[1][0] = s2 * -.707;
    s[1][1] = s2 * .707;
    s[1][2] = 0.;
    /* set the out of plane direction size to unity */
    s3 = 1.;
    s[2][0] = 0.;
    s[2][1] = 0.;
    s[2][2] = s3 * 1.;
    printf("x= %e %e %e, s1= %e, s2= %e\n", x[0], x[1], x[2], s1, s2);
}

/*----------------------------------------------------------------------
                      Generate a 2D Planar Tri Mesh with Sizing Function
----------------------------------------------------------------------*/
int
main()
{
    msh_TriMesh* trimesh;
    vis_Connect* connect;

    Vint i, k;
    Vint numnp, numel;
    Vdouble x[3];
    Vint nix, ix[6];
    Vint aid;
    Vint anisoflag;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create trimesh object */
    trimesh = msh_TriMeshBegin();
    msh_TriMeshDef(trimesh, MAX_NODE, MAX_LINE, 2);

    /* create connect object to receive mesh */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* define nodes */
    for (i = 0; i < MAX_NODE; i++) {
        msh_TriMeshSetNode(trimesh, i + 1, coords[i]);
    }
    /* define lines */
    for (i = 0; i < MAX_LINE; i++) {
        msh_TriMeshSetLine(trimesh, i + 1, lines[i]);
    }
    /* tag the first line segment */
    msh_TriMeshSetLineAssoc(trimesh, VIS_MISCID, 1, SYS_EDGE, 1001);

    /* generate quadratic elements */
    msh_TriMeshSetParami(trimesh, VIS_MESH_MAXI, 3);
    msh_TriMeshSetParami(trimesh, TRIMESH_SMOOTH, VIS_ON);

    /* use zero for isotropic sizing, one for anisotropic */
    anisoflag = 1;
    /* set sizing function */
    if (anisoflag == 0) {
        msh_TriMeshSetFunction(trimesh, TRIMESH_FUN_SIZING, (Vfunc*)s_iso, NULL);
    }
    else {
        msh_TriMeshSetFunction(trimesh, TRIMESH_FUN_ASIZING, (Vfunc*)s_aniso, NULL);
    }

    msh_TriMeshWrite(trimesh, SYS_ASCII, "exam43b.tri");
    /* generate */
    msh_TriMeshGenerate(trimesh, connect);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);

    /* print node information */
    printf("Node information\n");
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, (Vdouble(*)[3])x);
    }
    /* print element information */
    /* check for edges generated on tagged line segment */
    printf("Element information\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        printf("id= %d  ix= %d %d %d %d %d %d\n", i, ix[0], ix[1], ix[2], ix[3], ix[4], ix[5]);
        for (k = 1; k <= 3; k++) {
            vis_ConnectElemEntAssoc(connect, VIS_MISCID, SYS_EDGE, i, k, &aid);
            if (aid) {
                printf(" edge %d,   VIS_MISCID= %d\n", k, aid);
            }
        }
    }
    /* write out NASTRAN bulk data file */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam43b.bdf");

    /* end objects */
    vis_ConnectEnd(connect);
    msh_TriMeshEnd(trimesh);
    return 0;
}
