#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vdouble coords[6][3] = {{0., 0., 0.}, {2., 0., 0.}, {1., 1., 0.}, {0., 0., 1.}, {2., 0., 1.}, {1., 1., 1.}};

static Vint tris[8][3] = {{1, 3, 2}, {4, 5, 6}, {1, 2, 4}, {2, 5, 4}, {2, 3, 5}, {5, 3, 6}, {6, 3, 1}, {6, 1, 4}};

void
loadsurface(vis_Connect* connectsrf);
void
readsurface(vis_Connect* connectsrf, Vchar* path);
int
generatetetmesh(vis_Connect* connectsrf, vis_Connect* connecttet);
void
refinesurface(vis_Connect* connectsrf, vis_Connect* connecttet);

/*----------------------------------------------------------------------
                      Generate a 3D Volume Tet Mesh with No Interior Points
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    vis_Connect* connectsrf;
    vis_Connect* connecttet;
    Vint numnod, numtri;
    Vint numnp, numel;
    Vint istat, imesh, ifail;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object of surface */
    connectsrf = vis_ConnectBegin();
    vis_ConnectPre(connectsrf, SYS_DOUBLE);
    vis_ConnectDef(connectsrf, 0, 0);
    /* load surface from static arrays */
    if (argc < 2) {
        loadsurface(connectsrf);
        /* read surface from TetMeshWrite file */
    }
    else {
        readsurface(connectsrf, argv[1]);
    }
    /* convert to dynamic mode */
    vis_ConnectMode(connectsrf, CONNECT_DYNAMIC);
    /* create tet mesh given surface triangles */
    /* enter refinement loop, try 3 times */
    for (imesh = 0; imesh < 100; imesh++) {
        printf("iteration= %d\n", imesh);
        vis_ConnectNumber(connectsrf, SYS_NODE, &numnod);
        vis_ConnectNumber(connectsrf, SYS_ELEM, &numtri);
        printf("numnod= %d, numtri= %d\n", numnod, numtri);

        connecttet = vis_ConnectBegin();
        vis_ConnectPre(connecttet, SYS_DOUBLE);
        vis_ConnectDef(connecttet, 0, 0);
        /* generate tet mesh */
        istat = generatetetmesh(connectsrf, connecttet);
        if (istat) {
            ifail = 0;
            printf("TetMesh generation failure\n");
            break;
        }
        vis_ConnectNumber(connecttet, SYS_NODE, &numnp);
        vis_ConnectNumber(connecttet, SYS_ELEM, &numel);
        printf("numnp= %d, numel= %d\n", numnp, numel);
        /* check for no interior points */
        if (numnp == numnod) {
            ifail = 0;
            printf("no interior points generated\n");
            vis_ConnectWrite(connecttet, SYS_NASTRAN_BULKDATA, "exam50.bdf");
            break;
        }
        printf("number of interior points= %d \n", numnp - numnod);
        ifail = 1;
        /* refine surface mesh */
        refinesurface(connectsrf, connecttet);
        vis_ConnectEnd(connecttet);
    }
    /* end objects */
    vis_ConnectEnd(connectsrf);
    if (ifail == 0) {
        vis_ConnectEnd(connecttet);
    }
    return 0;
}

void
loadsurface(vis_Connect* connectsrf)
{
    Vint i;

    printf("load surface from static arrays\n");
    /* set nodes */
    for (i = 0; i < 6; i++) {
        vis_ConnectSetCoordsdv(connectsrf, i + 1, coords[i]);
    }
    /* set triangles */
    for (i = 0; i < 8; i++) {
        vis_ConnectSetTopology(connectsrf, i + 1, VIS_SHAPETRI, 2, 0, 0);
        vis_ConnectSetElemNode(connectsrf, i + 1, tris[i]);
    }
}

void
readsurface(vis_Connect* connectsrf, Vchar* path)
{
    msh_TetMesh* tetmesh;
    vis_Connect* connect;

    printf("read surface from file: %s\n", path);
    /* create tetmesh object to import TetMeshWrite file */
    tetmesh = msh_TetMeshBegin();
    /* read file */
    if (strstr(path, ".tet") != NULL) {
        msh_TetMeshRead(tetmesh, SYS_ASCII, path);
    }
    else if (strstr(path, ".btet") != NULL) {
        msh_TetMeshRead(tetmesh, SYS_BINARY, path);
    }
    /* get internal connect object */
    msh_TetMeshGetConnect(tetmesh, &connect);
    /* copy it */
    vis_ConnectCopy(connectsrf, connect);
    /* destroy tetmesh object */
    msh_TetMeshEnd(tetmesh);
}

int
generatetetmesh(vis_Connect* connectsrf, vis_Connect* connecttet)
{
    Vint i;
    msh_TetMesh* tetmesh;
    Vint numnod, numtri;
    Vdouble x[3];
    Vint nix, ix[3];
    Vint ierr;

    /* create tetmesh object */
    tetmesh = msh_TetMeshBegin();
    vis_ConnectNumber(connectsrf, SYS_NODE, &numnod);
    vis_ConnectNumber(connectsrf, SYS_ELEM, &numtri);
    msh_TetMeshDef(tetmesh, numnod, numtri, 2);
    /* define nodes */
    for (i = 1; i <= numnod; i++) {
        vis_ConnectCoordsdv(connectsrf, 1, &i, (Vdouble(*)[3])x);
        msh_TetMeshSetNode(tetmesh, i, x);
    }
    /* define tris */
    for (i = 1; i <= numtri; i++) {
        vis_ConnectElemNode(connectsrf, i, &nix, ix);
        msh_TetMeshSetTri(tetmesh, i, ix);
    }
    /* try for no interior points */
    msh_TetMeshSetParami(tetmesh, VIS_MESH_INTERREFINE, VIS_OFF);
    /* generate */
    msh_TetMeshGenerate(tetmesh, connecttet);
    ierr = msh_TetMeshError(tetmesh);

    msh_TetMeshEnd(tetmesh);
    return ierr;
}

void
refinesurface(vis_Connect* connectsrf, vis_Connect* connecttet)
{
    Vint i, j, k;
    Vint numtrinod;
    Vint numtetnod;
    Vint nix, ix[4];
    Vint nixa, ixa[1000];
    Vint nint, next, kext[3];
    Vint nixext, ixext;
    Vint nixed, ixed[3];
    Vdouble xa[2][3], xc[3];
    Vint ntrinod;
    Vdouble s, smax;
    Vint kmax = 0;

    vis_ConnectNumber(connectsrf, SYS_NODE, &numtrinod);
    vis_ConnectNumber(connecttet, SYS_NODE, &numtetnod);
    vis_ConnectKernel(connecttet, 0);

    ntrinod = numtrinod;
    /* loop through interior nodes, get connected tets */
    for (i = numtrinod + 1; i <= numtetnod; i++) {
        vis_ConnectNodeElem(connecttet, i, &nixa, ixa);
        /* loop through adjacent tets, get exterior nodes */
        for (j = 0; j < nixa; j++) {
            vis_ConnectElemNode(connecttet, ixa[j], &nix, ix);
            nint = 0;
            next = 0;
            for (k = 0; k < nix; k++) {
                if (ix[k] <= numtrinod) {
                    kext[next] = ix[k];
                    next += 1;
                }
                else {
                    nint += 1;
                }
            }
            /* if more than one interior point, skip */
            if (nint != 1)
                continue;
            vis_ConnectNodeAdj(connectsrf, 3, kext, &nixext, &ixext);
            /* if not exactly one surface triangle, skip */
            if (nixext != 1)
                continue;
            /* split longest edge */
            smax = 0.;
            for (k = 1; k <= 3; k++) {
                vis_ConnectSizeElemdv(connectsrf, SYS_EDGE, ixext, k, &s);
                if (s >= smax) {
                    smax = s;
                    kmax = k;
                }
            }
            /* generate point at center of edge */
            vis_ConnectElemCon(connectsrf, SYS_EDGE, ixext, kmax, &nixed, ixed);
            vis_ConnectCoordsdv(connectsrf, nixed, ixed, xa);
            xc[0] = (xa[0][0] + xa[1][0]) / 2.;
            xc[1] = (xa[0][1] + xa[1][1]) / 2.;
            xc[2] = (xa[0][2] + xa[1][2]) / 2.;
            ntrinod += 1;
            vis_ConnectSetCoordsdv(connectsrf, ntrinod, xc);
            vis_ConnectSplitElem(connectsrf, SYS_EDGE, ixext, kmax, ntrinod);
            printf("split elem= %d, edge= %d, node= %d\n", ixext, kmax, ntrinod);
            break;
        }
    }
}
