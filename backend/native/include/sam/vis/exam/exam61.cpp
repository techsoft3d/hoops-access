#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vdouble coords[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                               {0., 0., 1.}, {1., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}};

static Vint tris[16][3] = {{1, 5, 3}, {3, 5, 7}, {4, 6, 2}, {8, 6, 4}, {1, 2, 5}, {5, 2, 6}, {7, 4, 3}, {8, 4, 7},
                           {1, 4, 2}, {4, 1, 3}, {5, 8, 7}, {5, 6, 8}, {5, 2, 4}, {5, 4, 7}, {5, 4, 2}, {5, 7, 4}};
/* fill regions */
static Vint rtris[16] = {1, 1, 2, 2, 1, 2, 1, 2, 1, 1, 2, 2, 1, 1, 2, 2};

/*----------------------------------------------------------------------
                      Generate a 3D Volume Mesh
----------------------------------------------------------------------*/
int
main()
{
    msh_VolMesh* volmesh;
    vis_Connect* connect;

    Vint i;
    Vint numnp, numel;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create volmesh object */
    volmesh = msh_VolMeshBegin();
    msh_VolMeshDef(volmesh, 8, 16);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* define nodes */
    for (i = 0; i < 8; i++) {
        msh_VolMeshSetNode(volmesh, i + 1, coords[i]);
    }
    /* define tris */
    for (i = 0; i < 16; i++) {
        msh_VolMeshSetFace(volmesh, i + 1, VIS_SHAPETRI, 2, 0, tris[i]);
        /* define region fill types */
        if (rtris[i] == 1) {
            msh_VolMeshSetFaceFill(volmesh, i + 1, VOLMESH_FILL_TET);
        }
        else if (rtris[i] == 2) {
            msh_VolMeshSetFaceFill(volmesh, i + 1, VOLMESH_FILL_BOUNDARY);
        }
    }
    /* define a node association on node 2 */
    msh_VolMeshSetNodeAssoc(volmesh, VIS_GEOVERT, 2, 1000);
    /* define an element edge association on tri 4, edge 2 */
    msh_VolMeshSetFaceAssoc(volmesh, VIS_GEOEDGE, 4, SYS_EDGE, 2, 10);
    /* define an element face association on tri 3 */
    msh_VolMeshSetFaceAssoc(volmesh, VIS_GEOFACE, 3, SYS_FACE, 1, 100);
    /* define an element association on tri 3 */
    msh_VolMeshSetFaceAssoc(volmesh, VIS_GEOBODY, 3, SYS_ELEM, 0, 200);

    /* generate */
    msh_VolMeshGenerate(volmesh, connect);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);

    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam61.bdf");

    /* end objects */
    vis_ConnectEnd(connect);
    msh_VolMeshEnd(volmesh);
    return 0;
}
