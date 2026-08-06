#include <stdio.h>
#include <math.h>
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

/* surface triangle node normals */
static Vdouble norms[12][3][3] = {{{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}}, {{-1., 0., 0.}, {-1., 0., 0.}, {-1., 0., 0.}},
                                  {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},    {{1., 0., 0.}, {1., 0., 0.}, {1., 0., 0.}},
                                  {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}}, {{0., -1., 0.}, {0., -1., 0.}, {0., -1., 0.}},
                                  {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},    {{0., 1., 0.}, {0., 1., 0.}, {0., 1., 0.}},
                                  {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}}, {{0., 0., -1.}, {0., 0., -1.}, {0., 0., -1.}},
                                  {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}},    {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}}};

/*----------------------------------------------------------------------
         Cross product between two vectors
----------------------------------------------------------------------*/
static void
cross(Vdouble a[3], Vdouble b[3], Vdouble c[3])
{
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
}

/*----------------------------------------------------------------------
         Difference between two vectors
----------------------------------------------------------------------*/
static void
diff(Vdouble a[3], Vdouble b[3], Vdouble c[3])
{
    c[0] = a[0] - b[0];
    c[1] = a[1] - b[1];
    c[2] = a[2] - b[2];
}

/*----------------------------------------------------------------------
         Generate Extruded Boundary Layer with Interior TetMesh
----------------------------------------------------------------------*/
int
main()
{
    vis_IdTran* idtran;
    msh_SurfMesh* surfmesh;
    msh_TetMesh* tetmesh;
    msh_ExtMesh* extmesh;
    vis_Connect *connectsurf, *connectext, *connecttet, *connectall;
    vis_Group *ngroup, *fgroup;
    Vdouble(*normal)[3], x[3][3], u[3], v[3], w[3], mag;
    Vint i, j, nix, ix[10], numnpsurf, numelsurf, numnpext, numelext;
    Vint jx[3], numnp, numel, no, aid, num;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* perform surface meshing */
    /* create SurfMesh object */
    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, 8, 12);

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
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, 0.2);
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 2);

    /* create Connect object */
    connectsurf = vis_ConnectBegin();
    vis_ConnectPre(connectsurf, SYS_DOUBLE);
    vis_ConnectDef(connectsurf, 0, 0);
    /* generate */
    msh_SurfMeshGenerate(surfmesh, connectsurf);
    if (msh_SurfMeshError(surfmesh)) {
        printf("surf mesh generation error\n");
        exit(1);
    }
    else {
        printf("surf mesh generation complete\n");
    }

    /* write generated surf mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connectsurf, SYS_NASTRAN_BULKDATA, "exam42b_srf.bdf");

    /* perform extrusion meshing */
    /* compute averaged nodal normals */
    vis_ConnectNumber(connectsurf, SYS_ELEM, &numelsurf);
    vis_ConnectNumber(connectsurf, SYS_NODE, &numnpsurf);
    normal = (Vdouble(*)[3])malloc(3 * numnpsurf * sizeof(Vdouble));
    for (i = 0; i < numnpsurf; ++i) {
        normal[i][0] = normal[i][1] = normal[i][2] = 0.;
    }
    for (i = 0; i < numelsurf; ++i) {
        vis_ConnectElemNode(connectsurf, i + 1, &nix, ix);
        vis_ConnectCoordsdv(connectsurf, nix, ix, x);
        diff(x[1], x[0], u);
        diff(x[2], x[0], v);
        cross(u, v, w);
        mag = sqrt(w[0] * w[0] + w[1] * w[1] + w[2] * w[2]);
        w[0] /= mag;
        w[1] /= mag;
        w[2] /= mag;
        for (j = 0; j < 3; ++j) {
            normal[ix[j] - 1][0] += w[0];
            normal[ix[j] - 1][1] += w[1];
            normal[ix[j] - 1][2] += w[2];
        }
    }
    /* set normal length to layer size of 0.25 */
    for (i = 0; i < numnpsurf; ++i) {
        mag = sqrt(normal[i][0] * normal[i][0] + normal[i][1] * normal[i][1] + normal[i][2] * normal[i][2]);
        mag = 0.25 / mag;
        normal[i][0] *= -mag;
        normal[i][1] *= -mag;
        normal[i][2] *= -mag;
    }

    /* create ExtMesh object */
    extmesh = msh_ExtMeshBegin();
    msh_ExtMeshDef(extmesh, numnpsurf, numelsurf);

    /* enter generated surface mesh */
    for (i = 1; i <= numnpsurf; ++i) {
        vis_ConnectCoordsdv(connectsurf, 1, &i, &u);
        msh_ExtMeshSetNode(extmesh, i, u);
        msh_ExtMeshSetNodeNormal(extmesh, i, normal[i - 1]);
    }
    for (i = 1; i <= numelsurf; ++i) {
        vis_ConnectElemNode(connectsurf, i, &nix, ix);
        msh_ExtMeshSetElem(extmesh, i, SYS_SHAPETRI, 2, 0, ix);
    }
    /* set mesh parameters */
    msh_ExtMeshSetParami(extmesh, EXTMESH_NORMAL, SYS_ON);
    msh_ExtMeshSetParamd(extmesh, VIS_MESH_GROWTHRATE, 2.);
    msh_ExtMeshSetParami(extmesh, EXTMESH_LOCALRECEDE, SYS_ON);
    msh_ExtMeshSetParami(extmesh, EXTMESH_REVERSE, SYS_ON);
    msh_ExtMeshSetNormalPath(extmesh, 4, 1., SYS_OFF);
    /* mark faces on original layer with value of 1
       and faces on final layer with value of 2 */
    msh_ExtMeshSetParami(extmesh, EXTMESH_FACEMARK, VIS_GEOFACE);

    /* create Connect object and generate */
    connectext = vis_ConnectBegin();
    vis_ConnectPre(connectext, SYS_DOUBLE);
    vis_ConnectDef(connectext, 0, 0);
    msh_ExtMeshGenerate(extmesh, connectext);
    if (msh_ExtMeshError(extmesh)) {
        printf("extrusion mesh generation error\n");
        exit(1);
    }
    else {
        printf("extrusion mesh generation complete\n");
    }
    /* write generated ext mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connectext, SYS_NASTRAN_BULKDATA, "exam42b_ext.bdf");

    /* perform tet meshing of the remaining interior */
    /* create TetMesh object */
    tetmesh = msh_TetMeshBegin();
    msh_TetMeshDef(tetmesh, numnpsurf, numelsurf, 2);
    msh_TetMeshSetParami(tetmesh, VIS_MESH_INWARD, SYS_ON);

    /* fill TetMesh object with generated points on surface */
    vis_ConnectNumber(connectext, SYS_ELEM, &numelext);
    vis_ConnectNumber(connectext, SYS_NODE, &numnpext);
    numnp = 0;
    idtran = vis_IdTranBegin();
    /* find nodes on surface */
    /* first generate face group */
    fgroup = vis_GroupBegin();
    vis_GroupDef(fgroup, numelext, SYS_ELEM, SYS_FACE);
    vis_ConnectSetGroupParami(connectext, CONNECT_ASSOCTYPE, VIS_GEOFACE);
    vis_ConnectSetGroupParami(connectext, CONNECT_ASSOCID, 2);
    vis_ConnectKernel(connectext, 0);
    vis_ConnectFaceGroup(connectext, CONNECT_ASSOC, NULL, fgroup);
    /* second generate unique node group from face group */
    ngroup = vis_GroupBegin();
    vis_GroupDef(ngroup, numnpext, SYS_NODE, SYS_NONE);
    vis_ConnectNodeGroup(connectext, CONNECT_UNIQUE, fgroup, ngroup);
    /* set nodes */
    for (i = 1; i <= numnpext; i++) {
        if (!vis_GroupNode(ngroup, i))
            continue;
        numnp++;
        vis_IdTranSetId(idtran, numnp, i);
        vis_ConnectCoordsdv(connectext, 1, &i, &u);
        msh_TetMeshSetNode(tetmesh, numnp, u);
    }
    vis_GroupEnd(ngroup);
    vis_GroupEnd(fgroup);

    /* fill TetMesh object with generated faces on surface */
    numel = 0;
    for (i = 1; i <= numelext; i++) {
        vis_ConnectElemNum(connectext, SYS_FACE, i, &num);
        for (no = 1; no <= num; no++) {
            vis_ConnectElemEntAssoc(connectext, VIS_GEOFACE, SYS_FACE, i, no, &aid);
            if (aid != 2)
                continue;
            vis_ConnectElemCon(connectext, SYS_FACE, i, no, &nix, ix);
            vis_ConnectCoordsdv(connectext, nix, ix, x);
            vis_IdTranIndices(idtran, nix, ix, jx);
            numel++;
            msh_TetMeshSetTri(tetmesh, numel, jx);
        }
    }
    /* create Connect object to hold generated tet mesh */
    connecttet = vis_ConnectBegin();
    vis_ConnectPre(connecttet, SYS_DOUBLE);
    vis_ConnectDef(connecttet, 0, 0);

    /* generate mesh */
    msh_TetMeshGenerate(tetmesh, connecttet);
    if (msh_TetMeshError(tetmesh)) {
        printf("tet mesh generation error\n");
        exit(1);
    }
    else {
        printf("tet mesh generation complete\n");
    }
    /* write generated tet mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connecttet, SYS_NASTRAN_BULKDATA, "exam42b_tet.bdf");

    /* merge extruded and tet meshes */
    connectall = vis_ConnectBegin();
    vis_ConnectPre(connectall, SYS_DOUBLE);
    vis_ConnectAppend(connectall, connectext);
    vis_ConnectAppend(connectall, connecttet);
    vis_ConnectSetParamf(connectall, CONNECT_TOLERANCE, 0.0);
    vis_ConnectMerge(connectall, NULL);
    vis_ConnectWrite(connectall, SYS_NASTRAN_BULKDATA, "exam42b_all.bdf");

    /* end objects */
    free(normal);
    vis_IdTranEnd(idtran);
    vis_ConnectEnd(connectall);
    /*vis_ConnectClearKernel is called inside vis_ConnectEnd*/
    vis_ConnectEnd(connectext);
    vis_ConnectEnd(connectsurf);
    vis_ConnectEnd(connecttet);
    msh_ExtMeshEnd(extmesh);
    msh_SurfMeshEnd(surfmesh);
    msh_TetMeshEnd(tetmesh);
    return 0;
}
