#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vdouble coords[9][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.}, {0., 0., 1.},
                               {1., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}, {0., .5, 1.}};

static Vint faces[11][4] = {{1, 5, 3}, {3, 5, 7, 9}, {4, 6, 2},    {8, 6, 4},    {1, 2, 5}, {5, 2, 6},
                            {7, 4, 3}, {8, 4, 7},    {1, 3, 4, 2}, {5, 8, 7, 9}, {5, 6, 8}};

static Vint shapefaces[11] = {SYS_SHAPETRI, SYS_SHAPETRI, SYS_SHAPETRI,  SYS_SHAPETRI, SYS_SHAPETRI, SYS_SHAPETRI,
                              SYS_SHAPETRI, SYS_SHAPETRI, SYS_SHAPEQUAD, SYS_SHAPETRI, SYS_SHAPETRI};

#define MAXJ_SETMISSINGMIDSIDE(a, b) (a) += (1 << (16 + (b)))

/*----------------------------------------------------------------------
                      Generate a Mixed Order 3D Volume Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_VolMesh* volmesh;
    vis_Connect* connect;

    Vint i;
    Vint maxi, maxj;
    Vint numnp, numel;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create volmesh object */
    volmesh = msh_VolMeshBegin();
    msh_VolMeshDef(volmesh, 9, 11);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* define nodes */
    for (i = 0; i < 9; i++) {
        msh_VolMeshSetNode(volmesh, i + 1, coords[i]);
    }
    /* define faces */
    for (i = 0; i < 11; i++) {
        maxi = 2;
        maxj = 0;
        /* mixed order triangles */
        /* maxi is 3 and add bits to maxj for missing midside */
        if (i + 1 == 2) {
            maxi = 3;
            MAXJ_SETMISSINGMIDSIDE(maxj, 0);
            MAXJ_SETMISSINGMIDSIDE(maxj, 2);
        }
        if (i + 1 == 10) {
            maxi = 3;
            MAXJ_SETMISSINGMIDSIDE(maxj, 0);
            MAXJ_SETMISSINGMIDSIDE(maxj, 1);
        }
        msh_VolMeshSetFace(volmesh, i + 1, shapefaces[i], maxi, maxj, faces[i]);
    }
    /* set target edge length */
    msh_VolMeshSetParamd(volmesh, VIS_MESH_EDGELENGTH, .1);
    /* generate parabolic tets/pyramids in the interior */
    msh_VolMeshSetParami(volmesh, VIS_MESH_MAXI, 3);

    msh_VolMeshWrite(volmesh, SYS_ASCII, "exam61b.vol");
    /* generate */
    msh_VolMeshGenerate(volmesh, connect);
    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);

    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam61b.bdf");

    /* end objects */
    vis_ConnectEnd(connect);
    msh_VolMeshEnd(volmesh);
    return 0;
}
