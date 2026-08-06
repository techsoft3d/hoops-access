#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/msh/msh.h"
#include "capri.h"

/* SurfMesh geometry projection callback function */
void
project_surfmesh2capri(msh_SurfMesh* surfmesh, Vobject* object, Vint enttype, Vint entaid, Vdouble uh[], Vdouble xh[3],
                       Vdouble ug[], Vdouble xg[3])
{
    Vint* ivol = (Vint*)object;
    Vint status;
    Vdouble uv[4];

    uv[0] = uv[1] = uv[2] = uv[3] = 1.e+20;
    if (enttype == SYS_EDGE) {
        status = gi_qNearestOnEdge(*ivol, entaid, xh, uv, xg);
    }
    else if (enttype == SYS_FACE) {
        status = gi_qNearestOnFace(*ivol, entaid, xh, uv, xg);
    }
    if (status) {
        xg[0] = xh[0];
        xg[1] = xh[1];
        xg[2] = xh[2];
    }
}
/* utility function to transform a point */
static void
transform(Vdouble tm[3][4], Vdouble point[], Vdouble out[])
{
    out[0] = tm[0][0] * point[0] + tm[0][1] * point[1] + tm[0][2] * point[2] + tm[0][3];
    out[1] = tm[1][0] * point[0] + tm[1][1] * point[1] + tm[1][2] * point[2] + tm[1][3];
    out[2] = tm[2][0] * point[0] + tm[2][1] * point[1] + tm[2][2] * point[2] + tm[2][3];
}

/* load CAPRI tesselation of a volume into SurfMesh */
static void
loadvolume(Vint ivol, msh_SurfMesh* surfmesh)
{
    vsy_IntDict* intdict;
    vis_IdTran* idtran;
    Vint status, i, j, k;
    Vint no, aid;
    Vchar *name, buf[256];
    Vint nnode, nedge, nface, nbound, n;
    Vint iface;
    Vdouble tm[3][4], *points, *uv, x[3], vn[3][3];
    Vint tlen, *tris, *tric, plen, *ptype, *pindex;
    Vint numnp, numel, ix[3], jx[3], efl[3], base, npts;
    Vint iszero;
    Vint nedgept, n1, n2, nodes[2];
    Vdouble *edgept, *edget, trange[2], tang[2][3], curv;

    status = gi_dGetVolume(ivol, &nnode, &nedge, &nface, &nbound, &name);
    if (status) {
        printf("Error reading volume information for volume= %d\n", ivol);
        return;
    }
    printf("Loaded volume= %s\n", name);

    status = gi_iGetDisplace(ivol, (double*)tm);
    if (status) {
        printf("Error reading Displace for volume= %d\n", ivol);
        return;
    }

    intdict = vsy_IntDictBegin();
    idtran = vis_IdTranBegin();
    /* count total number of tesselation points and triangles */
    numnp = numel = npts = 0;
    for (iface = 1; iface <= nface; ++iface) {
        status = gi_dTesselFace(ivol, iface, &tlen, &tris, &tric, &plen, &points, &ptype, &pindex, &uv);
        if (status) {
            printf("Error reading TesselFace for volume= %d, face= %d\n", ivol, iface);
            return;
        }
        /* loop through points on tesselated face */
        for (i = 0; i < plen; ++i) {
            /* encode edge flag and point */
            sprintf(buf, "%d %d", ptype[i], pindex[i]);
            /* if node in interior */
            if (ptype[i] == -1) {
                numnp += 1;
                vsy_IntDictInsert(intdict, buf, numnp);
                n = numnp;
                /* node not in interior */
            }
            else {
                vsy_IntDictLookup(intdict, buf, &n);
                if (n == 0) {
                    numnp += 1;
                    vsy_IntDictInsert(intdict, buf, numnp);
                    n = numnp;
                }
            }
            npts += 1;
            vis_IdTranSetId(idtran, npts, n);
        }
        numel += tlen;
    }
    vsy_IntDictEnd(intdict);

    msh_SurfMeshDef(surfmesh, numnp, numel);
    npts = base = numel = 0;
    for (iface = 1; iface <= nface; ++iface) {
        status = gi_dTesselFace(ivol, iface, &tlen, &tris, &tric, &plen, &points, &ptype, &pindex, &uv);
        if (status) {
            printf("Error reading TesselFace for volume= %d, face= %d\n", ivol, iface);
            return;
        }
        /* loop through points on tesselated face */
        for (i = 0; i < plen; ++i) {
            npts += 1;
            vis_IdTranGetId(idtran, npts, &n);
            transform(tm, &points[3 * i], x);
            /* if node in interior */
            if (ptype[i] == -1) {
                msh_SurfMeshSetPoint(surfmesh, n, x, 0);
                /* if node not in interior, ie on edge/vertex */
            }
            else {
                /* node on geometry vertex */
                if (ptype[i] == 0) {
                    msh_SurfMeshSetPoint(surfmesh, n, x, 1);
                    msh_SurfMeshSetPointAssoc(surfmesh, VIS_GEOVERT, n, pindex[i]);
                    /* node on geometry edge, not on vertex */
                }
                else {
                    msh_SurfMeshSetPoint(surfmesh, n, x, 0);
                }
            }
        }
        /* loop through triangles on tesselated face */
        for (i = 0; i < tlen; ++i) {
            numel += 1;
            ix[0] = tris[3 * i] + base;
            ix[1] = tris[3 * i + 1] + base;
            ix[2] = tris[3 * i + 2] + base;
            vis_IdTranGetIds(idtran, 3, ix, jx);
            /* flag triangle edges on geometry edges */
            for (j = 0; j < 3; ++j) {
                k = (j + 1) % 3;
                efl[k] = 0;
                if (tric[3 * i + j] < 0) {
                    efl[k] = 1;
                }
            }
            msh_SurfMeshSetTri(surfmesh, numel, jx, efl);
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOFACE, numel, SYS_FACE, 1, iface);
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, numel, SYS_ELEM, 1, ivol);
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, numel, SYS_ELEM, 1, ivol);
            iszero = 0;
            /* loop over triangle nodes */
            for (j = 0; j < 3; ++j) {
                if (tric[3 * i + j] < 0) {
                    /* edge number opposing node */
                    no = (j + 1) % 3 + 1;
                    /* edge association is geometry edge number */
                    aid = -tric[3 * i + j];
                    msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOEDGE, numel, SYS_EDGE, no, aid);
                    /* set triangle edge tangents */
                    status = gi_dTesselEdge(ivol, aid, &nedgept, &edgept, &edget);
                    n1 = tris[3 * i + (j + 1) % 3] - 1;
                    n2 = tris[3 * i + (j + 2) % 3] - 1;
                    ix[0] = ptype[n1];
                    ix[1] = ptype[n2];

                    /* point on edge information not available */
                    gi_dGetEdge(ivol, aid, trange, nodes);
                    if (ix[0] == 0) {
                        if (pindex[n1] == nodes[0]) {
                            ix[0] = 1;
                        }
                        else {
                            ix[0] = nedgept;
                        }
                    }
                    if (ix[1] == 0) {
                        if (pindex[n2] == nodes[0]) {
                            ix[1] = 1;
                        }
                        else {
                            ix[1] = nedgept;
                        }
                    }

                    --ix[0];
                    --ix[1];
                    status = gi_cCurvOfEdge(ivol, aid, edget[ix[0]], tang[0], &curv);
                    status = gi_cCurvOfEdge(ivol, aid, edget[ix[1]], tang[1], &curv);
                    if (edget[ix[1]] - edget[ix[0]] < 0.) {
                        tang[0][0] = -tang[0][0];
                        tang[0][1] = -tang[0][1];
                        tang[0][2] = -tang[0][2];
                        tang[1][0] = -tang[1][0];
                        tang[1][1] = -tang[1][1];
                        tang[1][2] = -tang[1][2];
                    }
                    msh_SurfMeshSetTriTang(surfmesh, numel, no, tang);
                }
                /* evaluate normal at node, check for zeros */
                status = gi_qNormalToFace(ivol, iface, &uv[2 * tris[3 * i + j] - 2], x, vn[j]);
                if (vn[j][0] == 0. && vn[j][1] == 0. && vn[j][2] == 0.) {
                    iszero = 1;
                }
            }
            /* set triangle node normals */
            if (!iszero) {
                msh_SurfMeshSetTriNorm(surfmesh, numel, vn);
            }
        }
        base += plen;
    }
    vis_IdTranEnd(idtran);
}

/*----------------------------------------------------------------------
                      Illustrate CAPRI Interface to SurfMesh and TetMesh
----------------------------------------------------------------------*/
int
main(int argc, char* argv[])
{
    Vint i;
    vis_Connect *connectsrf, *connecttet, *connect;
    msh_SurfMesh* surfmesh;
    msh_TetMesh* tetmesh;
    Vint imodel, status, nvol, ivol, icode;
    Vint ierr;
    Vint numpnts, numtris;
    Vint numnp, numel;
    Vchar buf[256];
    Vdouble extent[2][3], dmax, d, edgelen;

    if (argc < 3) {
        printf("Usage: %s modeller model\n", argv[0]);
        return 1;
    }

    status = gi_uStart();
    if (status) {
        printf("Unable to start CAPRI\n");
        return 1;
    }
    printf("CAPRI started\n");

    gi_putenv("CAPRItess=On");
    imodel = gi_uLoadModel(NULL, argv[1], argv[2]);
    if (imodel == 0) {
        printf("Unable to open %s model %s\n", argv[1], argv[2]);
        return 1;
    }
    printf("CAPRI model loaded\n");

    /* get number of volumes */
    nvol = gi_uNumVolumes();

    /* get maximum extent of all volumes */
    dmax = 0.;
    for (ivol = 1; ivol <= nvol; ++ivol) {
        icode = gi_dBox(ivol, (double*)extent);
        for (i = 0; i < 3; ++i) {
            d = extent[1][i] - extent[0][i];
            if (d > dmax)
                dmax = d;
        }
    }
    edgelen = dmax / 20.;
    /* instance surface mesher and tet mesher */
    surfmesh = msh_SurfMeshBegin();
    tetmesh = msh_TetMeshBegin();
    /* instance Connect object to hold resultant mesh */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    /* mesh each volume separately */
    for (ivol = 1; ivol <= nvol; ++ivol) {
        connectsrf = vis_ConnectBegin();
        vis_ConnectPre(connectsrf, SYS_DOUBLE);
        msh_SurfMeshSetFunction(surfmesh, SURFMESH_FUN_GEOPROJ, (Vfunc*)project_surfmesh2capri, (Vobject*)&ivol);

        /* load the CAPRI geometry tesselation into SurfMesh */
        loadvolume(ivol, surfmesh);
        msh_SurfMeshInq(surfmesh, &numpnts, &numtris);
        if (numpnts == 0 || numtris == 0)
            continue;
        /* compute extent to set reasonable mesh size */
        msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, edgelen);
        msh_SurfMeshSetParamd(surfmesh, VIS_MESH_SPANANGLE, 45.);
        /* generate parabolic triangles */
        msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 3);
        msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam52capri.srf");
        msh_SurfMeshGenerate(surfmesh, connectsrf);
        ierr = msh_SurfMeshError(surfmesh);
        if (ierr) {
            printf("Error generating surface mesh, volume= %d\n", ivol);
            sprintf(buf, "model_%d.srf", ivol);
            msh_SurfMeshWrite(surfmesh, SYS_ASCII, buf);
            vis_ConnectEnd(connectsrf);
            continue;
        }
        printf("SurfMesh volume= %d complete\n", ivol);

        icode = gi_dVolumeType(ivol);
        /* volume is solid, generate tet mesh */
        if (icode == 0) {
            connecttet = vis_ConnectBegin();
            vis_ConnectPre(connecttet, SYS_DOUBLE);
            msh_TetMeshConnect(tetmesh, connectsrf);
            msh_TetMeshSetParamd(tetmesh, VIS_MESH_EDGELENGTH, edgelen);
            msh_TetMeshGenerate(tetmesh, connecttet);
            ierr = msh_TetMeshError(tetmesh);
            if (ierr) {
                printf("Error generating tet mesh, volume= %d\n", ivol);
                sprintf(buf, "model_%d.tet", ivol);
                msh_TetMeshWrite(tetmesh, SYS_ASCII, buf);
                vis_ConnectEnd(connecttet);
                continue;
            }
            printf("TetMesh volume= %d complete\n", ivol);
            vis_ConnectAppend(connect, connecttet);
            vis_ConnectEnd(connecttet);
            /* volume is shell */
        }
        else {
            vis_ConnectAppend(connect, connectsrf);
        }
        vis_ConnectEnd(connectsrf);
    }
    /* report total number of generate nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("total number of nodes= %d\n", numnp);
    printf("total number of elems= %d\n", numel);
    if (numnp && numel) {
        vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam52capri.bdf");
    }
    /* clean up */
    msh_SurfMeshEnd(surfmesh);
    msh_TetMeshEnd(tetmesh);
    vis_ConnectEnd(connect);
    status = gi_uRelModel(imodel);
    status = gi_uStop(0);
    return 0;
}
