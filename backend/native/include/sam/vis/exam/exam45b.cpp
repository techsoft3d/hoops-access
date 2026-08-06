#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Read TetMeshWrite File and Generate TetMesh
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    msh_TetMesh* tetmesh;
    vis_Connect* connect;
    Vint ierr;
    Vint numnp, numel;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        exit(1);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    tetmesh = msh_TetMeshBegin();
    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* read file */
    if (strstr(argv[1], ".tet") != NULL) {
        msh_TetMeshRead(tetmesh, SYS_ASCII, argv[1]);
    }
    else if (strstr(argv[1], ".btet") != NULL) {
        msh_TetMeshRead(tetmesh, SYS_BINARY, argv[1]);
    }
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
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam45b.bdf");

    /* destroy tetmesh object */
    msh_TetMeshEnd(tetmesh);
    vis_ConnectEnd(connect);
    return (0);
}
