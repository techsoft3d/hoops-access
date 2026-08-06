#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Generate a 3D Volume Tet Mesh from an STL or OBJ File
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    Vint i, k;
    msh_SurfMesh* surfmesh;
    msh_TetMesh* tetmesh;
    vis_Connect *connect, *connectsurf, *connecttet;
    vis_Group *groupface, *groupedge, *groupnode;

    Vint numpnts, numtris;
    Vdouble x[3];
    Vint nix, tri[3], edgeflags[3];
    Vint numsurfpnts, numsurftris;
    Vint numtetpnts, numtets;
    Vint flags, flagk;
    Vdouble edgelen;
    Vfloat bbox[2][3];
    Vdouble d[3], fl;
    Vchar inpath[256], outpath[256];
    Vint filetype;

    /* check for proper number of arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile outputfile\n", argv[0]);
        fprintf(stderr, " inputfile is blank, 'angle.stl' is assumed\n");
        strcpy(inpath, "angle.stl");
    }
    else {
        strcpy(inpath, argv[1]);
    }
    if (argc < 3) {
        fprintf(stderr, "Usage: %s inputfile outputfile\n", argv[0]);
        fprintf(stderr, " outputfile is blank, 'exam48.unv' is assumed\n");
        strcpy(outpath, "exam48.unv");
    }
    else {
        strcpy(outpath, argv[2]);
    }
    /* detect file type */
    if (strstr(inpath, ".stl") != NULL || strstr(inpath, ".STL") != NULL) {
        filetype = SYS_FILE_STL;
    }
    else if (strstr(inpath, ".obj") != NULL) {
        filetype = SYS_FILE_OBJ;
    }
    else {
        fprintf(stderr, "Unrecognized file type, file: %s\n", inpath);
        exit(0);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance Connect object to hold STL or OBJ data */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    vis_ConnectSetParamf(connect, CONNECT_TOLERANCE, 0.);
    vis_ConnectRead(connect, filetype, inpath);
    if (filetype == SYS_FILE_STL) {
        printf("Read STL file complete\n");
    }
    else {
        printf("Read OBJ file complete\n");
    }
    /* determine model extent for element sizing */
    vis_ConnectExtent(connect, NULL, bbox);
    d[0] = bbox[1][0] - bbox[0][0];
    d[1] = bbox[1][1] - bbox[0][1];
    d[2] = bbox[1][2] - bbox[0][2];
    fl = sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);

    vis_ConnectNumber(connect, SYS_NODE, &numpnts);
    vis_ConnectNumber(connect, SYS_ELEM, &numtris);

    /* determine feature edges, etc. */
    vis_ConnectKernel(connect, 0);

    /* group of faces */
    groupface = vis_GroupBegin();
    vis_GroupDef(groupface, numtris, SYS_ELEM, SYS_FACE);
    vis_ConnectFaceGroup(connect, CONNECT_FREE, NULL, groupface);

    /* extract feature edges and nodes at 45. degrees */
    vis_ConnectSetGroupParamf(connect, CONNECT_FEATUREANGLE, 45.);
    vis_ConnectSetGroupParamf(connect, CONNECT_FEATUREANGLE, 60.);
    vis_ConnectSetGroupParami(connect, CONNECT_FEATURESENSE, VIS_ON);

    /* group of feature edges */
    groupedge = vis_GroupBegin();
    vis_GroupDef(groupedge, numtris, SYS_ELEM, SYS_EDGE);
    vis_ConnectEdgeGroup(connect, CONNECT_FEATURE, groupface, groupedge);

    /* group of feature nodes */
    groupnode = vis_GroupBegin();
    vis_GroupDef(groupnode, numpnts, SYS_NODE, SYS_NONE);
    vis_ConnectNodeGroup(connect, CONNECT_FEATURE, groupedge, groupnode);

    /* instance surf mesher */
    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, numpnts, numtris);

    /* define input points with feature points preserved */
    for (i = 1; i <= numpnts; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, (Vdouble(*)[3])x);
        vis_GroupGetIndex(groupnode, i, &flags);
        msh_SurfMeshSetPoint(surfmesh, i, x, flags);
    }
    /* define input triangles with feature edges preserved */
    for (i = 1; i <= numtris; i++) {
        vis_ConnectElemNode(connect, i, &nix, tri);
        vis_GroupGetIndex(groupedge, i, &flags);
        for (k = 1; k <= 3; k++) {
            vis_GroupGetEntFlag(groupedge, i, k, &flagk);
            if (flagk) {
                edgeflags[k - 1] = 1;
            }
            else {
                edgeflags[k - 1] = 0;
            }
        }
        msh_SurfMeshSetTri(surfmesh, i, tri, edgeflags);
    }
    /* instance Connect object to hold generated surface tris */
    connectsurf = vis_ConnectBegin();
    vis_ConnectPre(connectsurf, SYS_DOUBLE);
    vis_ConnectDef(connectsurf, 0, 0);

    /* set target edge length at 5 percent of model extent */
    edgelen = .05 * fl;
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, edgelen);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_MINEDGELENGTH, .1 * edgelen);
    msh_SurfMeshSetParami(surfmesh, SURFMESH_NONMANIFOLD, VIS_ON);
    msh_SurfMeshSetParami(surfmesh, SURFMESH_INTSURFBACK, VIS_ON);

    /* set span angles, etc. */
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_SPANANGLE, 30.);
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 2);

    msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam48.srf");
    /* generate quality surface mesh */
    msh_SurfMeshGenerate(surfmesh, connectsurf);
    if (msh_SurfMeshError(surfmesh)) {
        printf("surface mesh generation error\n");
    }
    else {
        printf("surface mesh generation complete\n");
    }
    /* find out the number of generated nodes and elements */
    vis_ConnectNumber(connectsurf, SYS_NODE, &numsurfpnts);
    vis_ConnectNumber(connectsurf, SYS_ELEM, &numsurftris);
    printf(" Number of nodes= %d\n", numsurfpnts);
    printf(" Number of tris = %d\n", numsurftris);
    vis_ConnectWrite(connectsurf, SYS_SDRC_UNIVERSAL, "exam48srf.unv");

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
        vis_ConnectElemNode(connectsurf, i, &nix, tri);
        msh_TetMeshSetTri(tetmesh, i, tri);
    }

    /* create Connect object to hold generated tet mesh */
    connecttet = vis_ConnectBegin();
    vis_ConnectPre(connecttet, SYS_DOUBLE);
    vis_ConnectDef(connecttet, 0, 0);

    msh_TetMeshSetParamd(tetmesh, VIS_MESH_EDGELENGTH, edgelen);
    /* generate mesh */
    msh_TetMeshGenerate(tetmesh, connecttet);
    if (msh_TetMeshError(tetmesh)) {
        printf("tet mesh generation error\n");
    }
    else {
        printf("tet mesh generation complete\n");
    }

    /* write out to Universal file */
    vis_ConnectWrite(connecttet, SYS_SDRC_UNIVERSAL, outpath);
    printf("Write Universal file complete\n");

    /* find out the number of generated nodes and elements */
    vis_ConnectNumber(connecttet, SYS_NODE, &numtetpnts);
    vis_ConnectNumber(connecttet, SYS_ELEM, &numtets);
    printf(" Number of nodes= %d\n", numtetpnts);
    printf(" Number of tets = %d\n", numtets);

    /* delete objects */
    vis_ConnectEnd(connect);
    msh_SurfMeshEnd(surfmesh);
    vis_ConnectEnd(connectsurf);
    vis_ConnectEnd(connecttet);
    msh_TetMeshEnd(tetmesh);
    vis_GroupEnd(groupface);
    vis_GroupEnd(groupedge);
    vis_GroupEnd(groupnode);
    return 0;
}
