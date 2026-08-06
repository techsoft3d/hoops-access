
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Read SurfMeshWrite File and Generate TetMesh
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    msh_SurfMesh* surfmesh;
    msh_TetMesh* tetmesh;
    vis_Connect *connectsurf, *connect;
    Vint ierr;
    Vint maxi;
    Vint numnpsurf, numelsurf;
    Vint numnp, numel;
    Vdouble edgelength;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        exit(1);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    connectsurf = vis_ConnectBegin();
    vis_ConnectPre(connectsurf, SYS_DOUBLE);
    vis_ConnectDef(connectsurf, 0, 0);
    surfmesh = msh_SurfMeshBegin();
    /* read file */
    if (strstr(argv[1], ".srf") != NULL) {
        msh_SurfMeshRead(surfmesh, SYS_ASCII, argv[1]);
    }
    else if (strstr(argv[1], ".bsrf") != NULL) {
        msh_SurfMeshRead(surfmesh, SYS_BINARY, argv[1]);
    }
    msh_SurfMeshGenerate(surfmesh, connectsurf);
    /* test for error */
    ierr = msh_SurfMeshError(surfmesh);
    if (ierr) {
        printf("Surf mesh generation error\n");
        exit(1);
    }
    else {
        printf("Surf mesh generation complete\n");
    }
    msh_SurfMeshGetParami(surfmesh, VIS_MESH_MAXI, &maxi);
    msh_SurfMeshGetParamd(surfmesh, VIS_MESH_EDGELENGTH, &edgelength);

    vis_ConnectNumber(connectsurf, SYS_NODE, &numnpsurf);
    vis_ConnectNumber(connectsurf, SYS_ELEM, &numelsurf);
    printf("numnpsurf= %d, numelsurf= %d\n", numnpsurf, numelsurf);

    tetmesh = msh_TetMeshBegin();
    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* load surface mesh as boundary to tetmesh */
    msh_TetMeshDef(tetmesh, numnpsurf, numelsurf, maxi);
    msh_TetMeshConnect(tetmesh, connectsurf);

    msh_TetMeshSetParamd(tetmesh, VIS_MESH_EDGELENGTH, edgelength);
    msh_TetMeshGenerate(tetmesh, connect);
    /* test for error */
    ierr = msh_TetMeshError(tetmesh);
    if (ierr) {
        printf("Tet mesh generation error\n");
        exit(1);
    }
    else {
        printf("Tet mesh generation complete\n");
    }
    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam45d.bdf");

    /* destroy objects */
    msh_SurfMeshEnd(surfmesh);
    msh_TetMeshEnd(tetmesh);
    vis_ConnectEnd(connectsurf);
    vis_ConnectEnd(connect);
    return (0);
}
