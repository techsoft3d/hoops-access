#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
queryTetMesherrors(msh_TetMesh* tetmesh);

/*----------------------------------------------------------------------
                      Generate TetMesh and Perform Element Checking
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    Vint i;
    msh_TetMesh* tetmesh;
    vis_Connect* connect;
    Vint ierr;
    Vint numnp, numel;
    vis_GridFun* gridfun;
    vis_ElemChk* elemchk;
    Vfloat s[ELEMCHK_MAX];
    /* first argument is TetMeshWrite .tet or .btet file */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        exit(1);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance TetMesh object */
    tetmesh = msh_TetMeshBegin();
    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* read a TetMeshWrite file */
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
        queryTetMesherrors(tetmesh);
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

    /* perform element checking */
    /* create a grid function object */
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);
    /* create a ElemChk object and install GridFun */
    elemchk = vis_ElemChkBegin();
    vis_ElemChkSetObject(elemchk, VIS_GRIDFUN, gridfun);

    /* set desired shape parameters */
    vis_ElemChkSetType(elemchk, ELEMCHK_JACOBIAN_SUM, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_JACOBIAN_RATIO, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_CIRCUM_RATIO, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_EDGEALT_RATIO, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_JACOBIAN_NODAL, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_JACOBIAN_SMALL, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_MIN_ANGLE, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_MIN_DIHEDANGLE, SYS_ON);
    vis_ElemChkSetType(elemchk, ELEMCHK_MAX_DIHEDANGLE, SYS_ON);

    /* loop over elements and compute shape parameters */
    printf("Shape Parameters\n");
    for (i = 1; i <= numel; i++) {
        vis_ElemChkData(elemchk, i, s);
        printf("element= %d\n", i);
        printf(" area           = %e\n", s[ELEMCHK_JACOBIAN_SUM]);
        printf(" Jacobian ratio = %e\n", s[ELEMCHK_JACOBIAN_RATIO]);
        printf(" Jacobian small = %e\n", s[ELEMCHK_JACOBIAN_SMALL]);
        printf(" Jacobian nodal = %e\n", s[ELEMCHK_JACOBIAN_NODAL]);
        printf(" circum ratio   = %e\n", s[ELEMCHK_CIRCUM_RATIO]);
        printf(" edgealt ratio  = %e\n", s[ELEMCHK_EDGEALT_RATIO]);
        printf(" min angle      = %e\n", s[ELEMCHK_MIN_ANGLE]);
        printf(" min dihedral angle = %e\n", s[ELEMCHK_MIN_DIHEDANGLE]);
        printf(" max dihedral angle = %e\n", s[ELEMCHK_MAX_DIHEDANGLE]);
    }
    /* destroy objects */
    msh_TetMeshEnd(tetmesh);
    vis_ConnectEnd(connect);
    vis_ElemChkEnd(elemchk);
    vis_GridFunEnd(gridfun);
    return (0);
}

/*----------------------------------------------------------------------
                      query TetMesh error data
----------------------------------------------------------------------*/
static void
queryTetMesherrors(msh_TetMesh* tetmesh)
{
    Vint i;
    Vint ndat, *idat;
    /* Query for unacceptable input data */
    /* Inconsistently oriented input triangles */
    msh_TetMeshGetInteger(tetmesh, TETMESH_NUMINCONS, &ndat);
    if (ndat) {
        idat = (Vint*)malloc(ndat * sizeof(Vint));
        printf(" Number inconsistent triangles= %d\n", ndat);
        msh_TetMeshGetInteger(tetmesh, TETMESH_INCONS, idat);
        for (i = 0; i < ndat; i++) {
            printf(" triangle= %d\n", idat[i]);
        }
        free(idat);
    }
    /* Zero area input triangles */
    msh_TetMeshGetInteger(tetmesh, TETMESH_NUMTRIZEROANG, &ndat);
    if (ndat) {
        idat = (Vint*)malloc(ndat * sizeof(Vint));
        printf(" Number zero angle triangles= %d\n", ndat);
        msh_TetMeshGetInteger(tetmesh, TETMESH_TRIZEROANG, idat);
        for (i = 0; i < ndat; i++) {
            printf(" triangle= %d\n", idat[i]);
        }
        free(idat);
    }
    /* Free edges */
    msh_TetMeshGetInteger(tetmesh, TETMESH_NUMFREEEDGE, &ndat);
    if (ndat) {
        idat = (Vint*)malloc(ndat * sizeof(Vint));
        printf(" Number free edge triangles= %d\n", ndat);
        msh_TetMeshGetInteger(tetmesh, TETMESH_FREEEDGE, idat);
        for (i = 0; i < ndat; i++) {
            printf(" triangle= %d\n", idat[i]);
        }
        free(idat);
    }
    /* Intersecting boundary triangles */
    msh_TetMeshGetInteger(tetmesh, TETMESH_NUMINTERSECT, &ndat);
    if (ndat) {
        idat = (Vint*)malloc(ndat * sizeof(Vint));
        printf(" Number intersecting triangles= %d\n", ndat);
        msh_TetMeshGetInteger(tetmesh, TETMESH_INTERSECT, idat);
        for (i = 0; i < ndat; i++) {
            printf(" triangle= %d\n", idat[i]);
        }
        free(idat);
    }
    /* Query for input data causing meshing failure */
    /* Nodes unable to be inserted */
    msh_TetMeshGetInteger(tetmesh, TETMESH_NUMNODEINSERT, &ndat);
    if (ndat) {
        idat = (Vint*)malloc(ndat * sizeof(Vint));
        printf(" Number uninserted nodes= %d\n", ndat);
        msh_TetMeshGetInteger(tetmesh, TETMESH_NODEINSERT, idat);
        for (i = 0; i < ndat; i++) {
            printf(" node= %d\n", idat[i]);
        }
        free(idat);
    }
    /* Unrecovered boundary triangles */
    msh_TetMeshGetInteger(tetmesh, TETMESH_NUMUNREC, &ndat);
    if (ndat) {
        idat = (Vint*)malloc(ndat * sizeof(Vint));
        printf(" Number unrecovered triangles= %d\n", ndat);
        msh_TetMeshGetInteger(tetmesh, TETMESH_UNREC, idat);
        for (i = 0; i < ndat; i++) {
            printf(" triangle= %d\n", idat[i]);
        }
        free(idat);
    }
}
