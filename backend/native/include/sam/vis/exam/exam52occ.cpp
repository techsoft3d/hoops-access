#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/vis/visshar.h"
#include "sam/base/system.h"
#include "sam/vis/exam/exam52occ.hxx"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
#include <new>
#include <stdio.h>

static Vdouble rstol[3][2] = {
//{1.e-1,1.e-1}, {0.9,1.e-1}, {1.e-1,0.9} };
{ONETHIRD, ONETHIRD},
{ONETHIRD, ONETHIRD},
{ONETHIRD, ONETHIRD}};
static Vdouble rschord[3][2] = {{0.5, 0.5}, {0., 0.5}, {0.5, 0.}};
static Vdouble rsorig[3][2] = {{0., 0.}, {1., 0.}, {0., 1.}};

/*----------------------------------------------------------------------
                      Illustrate OpenCASCADE Interface SurfMesh
----------------------------------------------------------------------*/
static void
exam52occ_nodeid(vsy_ADTree* adtree, vis_Connect* connect, Vdouble coord[3], Vint isvert, Vint* nvert, Vint* id)
{
    Vint key, numnp, minkey;
    Vdouble dist, mindist = 0, x[3];
    /* see if point already exists */
    vsy_ADTreeRefPointInit(adtree, coord);
    minkey = 0;
    while (vsy_ADTreeRefPointNext(adtree, &key), key) {
        vis_ConnectCoordsdv(connect, 1, &key, &x);
        x[0] -= coord[0];
        x[1] -= coord[1];
        x[2] -= coord[2];
        dist = x[0] * x[0] + x[1] * x[1] + x[2] * x[2];
        if (minkey == 0) {
            mindist = dist;
            minkey = key;
        }
        else {
            if (dist < mindist) {
                mindist = dist;
                minkey = key;
            }
        }
    }
    if (minkey > 0) {
        *id = minkey;
        return;
    }
    /* add point */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    ++numnp;
    vis_ConnectSetCoordsdv(connect, numnp, coord);
    if (isvert) {
        vis_ConnectSetNodeAssoc(connect, VIS_GEOVERT, numnp, ++(*nvert));
    }
    vsy_ADTreeInsertPoint(adtree, numnp, coord);
    *id = numnp;
}

static void
exam52_surfnormal(Handle(Geom_Surface) geomsurf, Standard_Real u, Standard_Real v, Vdouble enorm[3], Vint* flag)
{
    Vint iter;

    *flag = 0;
    for (iter = 0; iter < 5; ++iter) {
        try {
            GeomLProp_SLProps aProp(geomsurf, u, v, 1, Precision::Angular());
            gp_Dir normal = aProp.Normal();
            normal.Coord(enorm[0], enorm[1], enorm[2]);
            *flag = 1;
            return;
        }
        catch (Standard_Failure) {
            u += 1.e-6;
            v += 1.e-6;
        }
    }
}

static void
exam52_edgetang(Handle(Geom_Curve) geomcurve, Standard_Real uv, Vdouble tang[3], Vint* flag)
{
    Vint iter;

    *flag = 0;
    for (iter = 0; iter < 5; ++iter) {
        try {
            GeomLProp_CLProps aProp(geomcurve, uv, 1, Precision::Angular());
            gp_Dir tangent;
            aProp.Tangent(tangent);
            tangent.Coord(tang[0], tang[1], tang[2]);
            *flag = 1;
            return;
        }
        catch (Standard_Failure) {
            uv += 1.e-6;
        }
    }
}

static void
exam52occ_configADTree(TopoDS_Shape& myShape, vsy_ADTree* adtree, Vdouble* diaglength)
{
    Vdouble dx, dy, dz, tol;
    Standard_Real xmin[3], xmax[3];

    /* Get bounding box for shape */
    Bnd_Box B;
    BRepBndLib::Add(myShape, B);
    B.Get(xmin[0], xmin[1], xmin[2], xmax[0], xmax[1], xmax[2]);

    /* Create ADTree with this bounding box */
    dx = xmax[0] - xmin[0];
    dy = xmax[1] - xmin[1];
    dz = xmax[2] - xmin[2];

    /* Set diagonal length of extent box */
    *diaglength = sqrt(dx * dx + dy * dy + dz * dz);

    xmin[0] -= 0.05 * dx;
    xmax[0] += 0.05 * dx;
    xmin[1] -= 0.05 * dy;
    xmax[1] += 0.05 * dy;
    xmin[2] -= 0.05 * dz;
    xmax[2] += 0.05 * dz;
    vsy_ADTreeDef(adtree, ADTREE_POINT, xmin, xmax);
    tol = 1.1 * sqrt(dx * dx + dy * dy + dz * dz) * 1.e-8;
    vsy_ADTreeSetParamd(adtree, ADTREE_TOLERANCE, tol);
}

static void
exam52occ_addVertex(TopoDS_Shape& myShape, vsy_ADTree* adtree, vis_Connect* connect, Vint* nvert)
{
    Standard_Real x, y, z;
    TopExp_Explorer ex;
    Vdouble coord[3];
    Vint id;

    /* insert all vertices; check for repeated */
    for (ex.Init(myShape, TopAbs_VERTEX); ex.More(); ex.Next()) {
        TopoDS_Vertex vertex = TopoDS::Vertex(ex.Current());
        gp_Pnt p = BRep_Tool::Pnt(vertex);
        p.Coord(x, y, z);
        coord[0] = x;
        coord[1] = y;
        coord[2] = z;

        /* get node id */
        exam52occ_nodeid(adtree, connect, coord, 1, nvert, &id);
    }
}

static void
exam52occ_sort3(Vint ix[3])
{
    Vint imin, imax, kx[3], i;

    imin = (ix[0] < ix[1]) ? ((ix[0] < ix[2] ? ix[0] : ix[2])) : ((ix[1] < ix[2] ? ix[1] : ix[2]));
    imax = (ix[0] < ix[1]) ? ((ix[1] < ix[2] ? ix[2] : ix[1])) : ((ix[0] < ix[2] ? ix[2] : ix[0]));
    kx[0] = kx[1] = kx[2] = 0;
    for (i = 0; i < 3; ++i) {
        if (imin == ix[i]) {
            kx[i] = 1;
        }
        if (imax == ix[i]) {
            kx[i] = 1;
        }
    }
    for (i = 0; i < 3; ++i) {
        if (kx[i] == 0) {
            ix[1] = ix[i];
            break;
        }
    }
    ix[0] = imin;
    ix[2] = imax;
}

int
main(int argc, char* argv[])
{
    TopoDS_Shape myShape;
    vis_Connect* connect;
    Vint n, k, rev;
    Vint numnp, numel, nix, index, ntri, npts;
    Vdouble coord[3];
    Vchar brepname[SYS_MAXPATHCHAR];
    Vchar srfname[SYS_MAXPATHCHAR];
    Vchar baseName[SYS_MAXPATHCHAR];
    Vint nvert = 0;
    Standard_Real x, y, z;
    vsy_ADTree* adtree;
    BRep_Builder b;
    Vint shape, maxi, maxj, maxk, key = 0;
    Vdouble xyz[3], enorm[3][3];
    vsy_IntVHash* ivhenum;
    vsy_IntHash *ihnode, *ihedge;
    vsy_VHashTable* vhtang;
    Vint numedge, numface, in0, in1;
    Vdouble edgelength = 0.;
    Vdouble diaglength, chordheight;
    Vint iquad = 0, itet = 0;
    Vint ierr;
    msh_SurfMesh* surfmesh;
    msh_TetMesh* tetmesh;
    vis_Connect* connecttet;
    vsy_IntVHash* ivhall;

    /* gather all parameters */
    strcpy(baseName, "exam52occ");
    strcpy(srfname, baseName);
    strcat(srfname, ".srf");
    for (int iarg = 1; iarg < argc; ++iarg) {
        if (strcmp(argv[iarg], "-quad") == 0) {
            iquad = 1;
        }
        else if (strcmp(argv[iarg], "-srfname") == 0) {
            ++iarg;
            strcpy(srfname, argv[iarg]);
        }
        else if (strcmp(argv[iarg], "-tet") == 0) {
            itet = 1;
        }
        else if (strcmp(argv[iarg], "-el") == 0) {
            ++iarg;
            (void)sscanf(argv[iarg], "%le", &edgelength);
        }
    }

    if (argc <= 1) {
        printf("A BREP file must be set as first argument\n");
        return 1;
    }

    strcpy(brepname, argv[argc - 1]);

    /* read brep file */
    printf("reading file= %s\n", brepname);
    BRepTools::Read(myShape, brepname, b);
    if (myShape.IsNull()) {
        printf("Unable to read brep file= %s\n", brepname);
        return 1;
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create Connect object to store geometry tesselation information */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    numnp = numel = nvert = 0;

    /* create shape with missing additional edges */
    TopoDS_Compound toadd;
    ihedge = vsy_IntHashBegin();
    ivhenum = vsy_IntVHashBegin();
    vhtang = vsy_VHashTableBegin();
    vsy_IntVHashDef(ivhenum, 2, 100);
    vsy_VHashTableDef(vhtang, 2, 100);

    /* create ADTree to generate unique points */
    adtree = vsy_ADTreeBegin();
    exam52occ_configADTree(myShape, adtree, &diaglength);
    /* set meshing edgelength, tesselation chordheight */
    if (edgelength == 0.) {
        edgelength = .05 * diaglength;
    }
    chordheight = .001 * diaglength;

    /* Tesselate geometry */
    BRepTools::Clean(myShape);
    BRepMesh_IncrementalMesh incrementalMesh(myShape, chordheight);

    /* insert all vertices; check for repeated */
    exam52occ_addVertex(myShape, adtree, connect, &nvert);

    /* extract face tesselation */
    TopTools_IndexedMapOfShape faceMap;
    TopExp::MapShapes(myShape, TopAbs_FACE, faceMap);
    ivhall = vsy_IntVHashBegin();
    vsy_IntVHashDef(ivhall, 3, faceMap.Extent());

    numedge = 0;
    numface = 0;
    for (int j = 1; j <= faceMap.Extent(); ++j) {
        const TopoDS_Face& face = TopoDS::Face(faceMap(j));
        numface += 1;

        /* Extract geometric surface from face */
        TopLoc_Location surflocation;
        Handle(Geom_Surface) geomsurf = BRep_Tool::Surface(face, surflocation);

        /* Map nodes on this face */
        vsy_IntVHash* ivhfreeedges;
        ivhfreeedges = vsy_IntVHashBegin();
        vsy_IntVHashDef(ivhfreeedges, 2, 100);

        TopLoc_Location location;
        Handle_Poly_Triangulation triangulation = BRep_Tool::Triangulation(face, location);
        if (triangulation.IsNull())
            continue;

        const Poly_ArrayOfNodes& internalNodes = triangulation->InternalNodes();
        const Poly_Array1OfTriangle& triangles = triangulation->Triangles();

        /* store all nodes first */
        Vint minnode = internalNodes.Lower();
        Vint maxnode = internalNodes.Upper();
        Vint sizenode = maxnode - minnode + 1;
        Vint* nodemap = (Vint*)malloc(sizenode * sizeof(Vint));
        for (int i = minnode; i <= maxnode; i++) {
            const gp_Pnt& p1 = internalNodes[i];
            p1.Coord(x, y, z);
            location.Transformation().Transforms(x, y, z);
            coord[0] = x;
            coord[1] = y;
            coord[2] = z;
            exam52occ_nodeid(adtree, connect, coord, 0, &nvert, &index);
            nodemap[i - minnode] = index;
        }

        /* Iterate over the triangles and their nodes */
        Vint firstflagged = 0;
        for (int i = triangles.Lower(); i <= triangles.Upper(); ++i) {
            const Poly_Triangle& triangle = triangles(i);

            Vint ixn[3];
            triangle.Get(ixn[0], ixn[1], ixn[2]);
            /* first loop through nodes */
            Vint ix[3];
            for (k = 0; k < 3; k++) {
                ix[k] = nodemap[(ixn[k] - 1) - minnode];
            }
            ++numel;
            /* check for degenerate triangle */
            if (ix[0] == ix[1] || ix[0] == ix[2] || ix[1] == ix[2]) {
                vis_ConnectSetTopology(connect, numel, SYS_SHAPEPOINT, 1, 0, 0);
                vis_ConnectSetElemNode(connect, numel, ix);
                continue;
            }
            vis_ConnectSetTopology(connect, numel, SYS_SHAPETRI, 0, 0, 0);
            vis_ConnectSetElemNode(connect, numel, ix);
            vis_ConnectSetElemAssoc(connect, VIS_GEOFACE, numel, j);
            if (face.Orientation() == TopAbs_REVERSED) {
                vis_ConnectSetElemAssoc(connect, VIS_MISCID, numel, 1);
            }

            /* second loop through nodes for normals */
            Vint flag, normflag = 0;
            Standard_Real uvo[3][2], uvtol[3][2];
            for (k = 0; k < 3; k++) {
                const gp_Pnt2d& uv = triangulation->UVNode(triangle(k + 1));
                uv.Coord(uvo[k][0], uvo[k][1]);
            }
            /* check for geovert */
            Vint vertid[3];
            vis_ConnectNodeAssoc(connect, VIS_GEOVERT, 3, ix, vertid);
#ifdef OLDWAY
            Vdouble h[3];
            for (k = 0; k < 3; k++) {
                if (vertid[k]) {
                    vis_shape2DGendv(1, SYS_SHAPETRI, 0, 0, rstol[k], h, NULL);
                    uvtol[k][0] = h[0] * uvo[0][0] + h[1] * uvo[1][0] + h[2] * uvo[2][0];
                    uvtol[k][1] = h[0] * uvo[0][1] + h[1] * uvo[1][1] + h[2] * uvo[2][1];
                }
                else {
                    MOVE2(uvo[k], uvtol[k]);
                }
            }
#endif

            Vdouble enormal[3], xtri[3][3], v1[3], v2[3];
            vis_ConnectCoordsdv(connect, 3, ix, xtri);
            DIFF3(xtri[1], xtri[0], v1);
            DIFF3(xtri[2], xtri[0], v2);
            CROSS3(v1, v2, enormal);
            UNIT3(enormal);
            for (k = 0; k < 3; k++) {
                if (vertid[k]) {
                    Vdouble uvv[2], h[3];
                    for (int l = 0; l < 10; ++l) {
                        uvv[0] = rsorig[k][0] + (rschord[k][0] - rsorig[k][0]) * 0.1 * l;
                        uvv[1] = rsorig[k][0] + (rschord[k][0] - rsorig[k][0]) * 0.1 * l;
                        vis_shape2DGendv(1, SYS_SHAPETRI, 0, 0, uvv, h, NULL);
                        uvtol[k][0] = h[0] * uvo[0][0] + h[1] * uvo[1][0] + h[2] * uvo[2][0];
                        uvtol[k][1] = h[0] * uvo[0][1] + h[1] * uvo[1][1] + h[2] * uvo[2][1];
                        exam52_surfnormal(geomsurf, uvtol[k][0], uvtol[k][1], enorm[k], &flag);
                        if (flag == 1) {
                            ++normflag;
                            gp_Vec vec = gp_Vec(enorm[k][0], enorm[k][1], enorm[k][2]);
                            gp_Vec nvec = surflocation.Transformation().GetRotation().Multiply(vec);
                            nvec.Coord(enorm[k][0], enorm[k][1], enorm[k][2]);
                        }
                        if (DOT3(enorm[k], enormal) > 0.8)
                            break;
                    }
                }
                else {
                    exam52_surfnormal(geomsurf, uvo[k][0], uvo[k][1], enorm[k], &flag);
                    if (flag == 1) {
                        ++normflag;
                        gp_Vec vec = gp_Vec(enorm[k][0], enorm[k][1], enorm[k][2]);
                        gp_Vec nvec = surflocation.Transformation().GetRotation().Multiply(vec);
                        nvec.Coord(enorm[k][0], enorm[k][1], enorm[k][2]);
                    }
                }
            }
            vis_ConnectSetElemNormdv(connect, numel, 1, enorm);

            /* mark edges */
            Vint jx[2], key2;
            for (k = 0; k < 3; k++) {
                jx[0] = ix[k] > ix[(k + 1) % 3] ? ix[(k + 1) % 3] : ix[k];
                jx[1] = ix[k] > ix[(k + 1) % 3] ? ix[k] : ix[(k + 1) % 3];
                vsy_IntVHashLookup(ivhfreeedges, jx, &key2);
                ++key2;
                vsy_IntVHashInsert(ivhfreeedges, jx, key2);
            }

            /* sort nodes min to max and store unique connectivity */
            if (firstflagged == 0) {
                exam52occ_sort3(ix);
                vsy_IntVHashInsert(ivhall, ix, numel);
                firstflagged = 1;
            }
        }

        Vint en = 1;
        TopExp_Explorer ExpW;
        for (ExpW.Init(face, TopAbs_EDGE); ExpW.More(); ExpW.Next()) {
            ++en;

            TopoDS_Shape shapw = ExpW.Current();
            TopoDS_Edge edge = TopoDS::Edge(shapw);

            TopLoc_Location edgelocation;
            Standard_Real cfirst, clast;
            Handle(Geom_Curve) geomcurve = BRep_Tool::Curve(edge, edgelocation, cfirst, clast);
            if (geomcurve.IsNull())
                continue;

            TopLoc_Location tlocation;
            Handle(Poly_PolygonOnTriangulation) edgeMesh;
            edgeMesh = BRep_Tool::PolygonOnTriangulation(edge, triangulation, tlocation);

            if (edgeMesh.IsNull())
                continue;

            Handle(TColStd_HArray1OfReal) unodes = edgeMesh->Parameters();
            const TColStd_Array1OfInteger& enodes = edgeMesh->Nodes();
            Vint* indices = (Vint*)malloc(edgeMesh->NbNodes() * sizeof(Vint));
            Vdouble* tang = (Vdouble*)malloc(3 * edgeMesh->NbNodes() * sizeof(Vdouble));
            Vint flag;
            for (k = 1; k <= edgeMesh->NbNodes(); ++k) {
                indices[k - 1] = nodemap[enodes(k) - 1];

                /* get tangent */
                const Standard_Real u = unodes->Value(k);
                exam52_edgetang(geomcurve, u, tang + 3 * (k - 1), &flag);
                if (flag == 1) {
                    gp_Vec vec = gp_Vec(tang[3 * (k - 1)], tang[3 * (k - 1) + 1], tang[3 * (k - 1) + 2]);
                    gp_Vec nvec = edgelocation.Transformation().GetRotation().Multiply(vec);
                    nvec.Coord(tang[3 * (k - 1)], tang[3 * (k - 1) + 1], tang[3 * (k - 1) + 2]);
                }
                else {
                    tang[3 * (k - 1)] = 2.;
                }
            }
            for (k = 1; k <= edgeMesh->NbNodes() - 1; ++k) {
                Vdouble* atang;
                Vint jx[2];

                Vint ix[3];
                ix[0] = indices[k - 1];
                ix[1] = indices[k];

                /* update free edges */
                jx[0] = ix[0] > ix[1] ? ix[1] : ix[0];
                jx[1] = ix[0] > ix[1] ? ix[0] : ix[1];
                vsy_IntVHashInsert(ivhfreeedges, jx, -1);

                if (k == 1) {
                    vsy_IntVHashLookup(ivhenum, ix, &key);
                    if (key == 0 || key == -1) {
                        key = ++numedge;
                    }
                }

                vsy_IntVHashLookup(ivhenum, ix, &n);
                if (n <= 0) {
                    /* check reversed edge */
                    vsy_IntVHashLookup(ivhenum, jx, &n);
                    if (n <= 0) {
                        if (tang[3 * (k - 1)] != 2. && tang[3 * k] != 2.) {
                            vsy_IntVHashInsert(ivhenum, ix, key);
                            atang = (Vdouble*)malloc(6 * sizeof(Vdouble));
                            vut_CopyD(tang + 3 * (k - 1), atang, 6);
                            vsy_VHashTableInsert(vhtang, ix, atang);
                        }
                    }
                }
            }
            free(indices);
            free(tang);
        }
        free(nodemap);

        /* add remaining free edges */
        vsy_IntVHashInitIter(ivhfreeedges);
        Vint ix[3];
        while (vsy_IntVHashNextIter(ivhfreeedges, ix, &key), key) {
            if (key == 1) {
                vsy_IntVHashLookup(ivhenum, ix, &k);
                if (k == 0) {
                    Vint nx[2];

                    nx[0] = ix[1];
                    nx[1] = ix[0];
                    vsy_IntVHashLookup(ivhenum, nx, &k);
                    if (k == 0) {
                        vsy_IntVHashInsert(ivhenum, ix, -1);
                    }
                }
            }
        }
        vsy_IntVHashEnd(ivhfreeedges);
    }

    /* determine double-backed surfaces */
    Vint* ibody = (Vint*)malloc(2 * numel * sizeof(Vint));
    vut_ZeroI(ibody, 2 * numel);
    Vint nbody = 0;
    TopExp_Explorer ExpS;
    for (ExpS.Init(myShape, TopAbs_SOLID); ExpS.More(); ExpS.Next()) {
        TopoDS_Shape shapw = ExpS.Current();
        TopoDS_Solid solid = TopoDS::Solid(shapw);
        ++nbody;

        TopExp_Explorer ExpF;
        for (ExpF.Init(solid, TopAbs_FACE); ExpF.More(); ExpF.Next()) {
            TopoDS_Shape shapz = ExpF.Current();
            TopoDS_Face face = TopoDS::Face(shapz);

            TopLoc_Location location;
            Handle_Poly_Triangulation triangulation = BRep_Tool::Triangulation(face, location);
            if (triangulation.IsNull())
                continue;

            const Poly_Array1OfTriangle& triangles = triangulation->Triangles();

            /* Iterate over the triangles and their nodes */
            Vint firstflagged = 0;
            for (int i = triangles.Lower(); i <= triangles.Upper(); ++i) {
                const Poly_Triangle& triangle = triangles(i);

                if (firstflagged == 0) {
                    /* extract first element index */
                    Vint ix[3];
                    for (k = 0; k < 3; k++) {
                        const gp_Pnt& p1 = triangulation->Node(triangle(k + 1));
                        p1.Coord(x, y, z);
                        location.Transformation().Transforms(x, y, z);
                        coord[0] = x;
                        coord[1] = y;
                        coord[2] = z;
                        exam52occ_nodeid(adtree, connect, coord, 0, &nvert, &ix[k]);
                    }
                    if (ix[0] == ix[1] || ix[0] == ix[2] || ix[1] == ix[2]) {
                        continue;
                    }
                    firstflagged = 1;
                    exam52occ_sort3(ix);
                    vsy_IntVHashLookup(ivhall, ix, &key);
                }
                else {
                    /* increment element index */
                    ++key;
                }
                vis_ConnectElemAssoc(connect, VIS_MISCID, 1, &key, &rev);
                if (face.Orientation() == TopAbs_REVERSED) {
                    if (rev) {
                        ibody[2 * (key - 1)] = nbody;
                    }
                    else {
                        ibody[2 * (key - 1) + 1] = nbody;
                    }
                }
                else {
                    if (rev) {
                        ibody[2 * (key - 1) + 1] = nbody;
                    }
                    else {
                        ibody[2 * (key - 1)] = nbody;
                    }
                }
            }
        }
    }
    vsy_IntVHashEnd(ivhall);

    /* create SurfMesh */
    surfmesh = msh_SurfMeshBegin();
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    ntri = npts = 0;
    ihnode = vsy_IntHashBegin();
    for (n = 1; n <= numel; ++n) {
        vis_ConnectTopology(connect, n, &shape, &maxi, &maxj, &maxk);
        if (shape != SYS_SHAPETRI)
            continue;
        ++ntri;
        Vint ix[3];
        vis_ConnectElemNode(connect, n, &nix, ix);
        for (Vint j = 0; j < 3; ++j) {
            vsy_IntHashLookup(ihnode, ix[j], &key);
            if (key == 0) {
                ++npts;
                vsy_IntHashInsert(ihnode, ix[j], npts);
            }
        }
    }

    if (npts == 0 || ntri == 0)
        goto labelcleanup;

    msh_SurfMeshDef(surfmesh, npts, ntri);
    /* load points */
    for (n = 1; n <= numnp; ++n) {
        Vint j = 0;
        vsy_IntHashLookup(ihnode, n, &j);
        if (j == 0)
            continue;

        vis_ConnectCoordsdv(connect, 1, &n, &xyz);
        vis_ConnectNodeAssoc(connect, VIS_GEOVERT, 1, &n, &nvert);
        if (nvert) {
            msh_SurfMeshSetPoint(surfmesh, j, xyz, 1);
            msh_SurfMeshSetPointAssoc(surfmesh, VIS_GEOVERT, j, nvert);
        }
        else {
            msh_SurfMeshSetPoint(surfmesh, j, xyz, 0);
        }
    }
    /* load triangles */
    ntri = 0;
    static Vint irev[3] = {2, 1, 0};
    for (n = 1; n <= numel; ++n) {
        Vint tefl[3] = {0, 0, 0};
        Vint teflag = 0;
        Vint tesens[3] = {0, 0, 0};
        Vint jx[3], aid, enormflag;
        Vdouble* etang[3] = {NULL, NULL, NULL};

        vis_ConnectTopology(connect, n, &shape, &maxi, &maxj, &maxk);
        if (shape != SYS_SHAPETRI)
            continue;
        ++ntri;
        Vint ix[3];
        vis_ConnectElemNode(connect, n, &nix, ix);
        vis_ConnectElemAssoc(connect, VIS_GEOFACE, 1, &n, &aid);
        vis_ConnectElemAssoc(connect, VIS_MISCID, 1, &n, &rev);
        /* loop over triangle edges */
        for (k = 0; k < 3; k++) {
            if (rev == 0) {
                in0 = k;
                in1 = (k + 1) % 3;
            }
            else {
                in1 = irev[k];
                in0 = (irev[k] + 1) % 3;
            }
            jx[0] = ix[in0];
            jx[1] = ix[in1];
            vsy_IntVHashLookup(ivhenum, jx, &teflag);
            if (teflag == 0) {
                jx[0] = ix[in1];
                jx[1] = ix[in0];
                vsy_IntVHashLookup(ivhenum, jx, &teflag);
                if (teflag) {
                    tesens[k] = 1;
                    tefl[k] = 1;
                }
            }
            else {
                tefl[k] = 1;
            }
            if (tefl[k]) {
                if (teflag > 0) {
                    msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOEDGE, ntri, SYS_EDGE, k + 1, teflag);
                }
                vsy_VHashTableLookup(vhtang, jx, (Vobject**)&etang[k]);
            }
        }
        if (rev == 0) {
            vsy_IntHashLookup(ihnode, ix[0], &jx[0]);
            vsy_IntHashLookup(ihnode, ix[1], &jx[1]);
            vsy_IntHashLookup(ihnode, ix[2], &jx[2]);
        }
        else {
            vsy_IntHashLookup(ihnode, ix[0], &jx[0]);
            vsy_IntHashLookup(ihnode, ix[1], &jx[2]);
            vsy_IntHashLookup(ihnode, ix[2], &jx[1]);
        }
        msh_SurfMeshSetTri(surfmesh, ntri, jx, tefl);
        if (ibody[2 * (n - 1)] > 0 && ibody[2 * (n - 1) + 1] > 0) {
            msh_SurfMeshSetTriBack(surfmesh, ntri, 1, 1);
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, ntri, SYS_ELEM, 0, ibody[2 * (n - 1)]);
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, ntri, SYS_ELEM, -1, ibody[2 * (n - 1) + 1]);
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, ntri, SYS_ELEM, 0, ibody[2 * (n - 1)]);
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, ntri, SYS_ELEM, -1, ibody[2 * (n - 1) + 1]);
        }
        else if (ibody[2 * (n - 1)] > 0) {
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, ntri, SYS_ELEM, 0, ibody[2 * (n - 1)]);
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, ntri, SYS_ELEM, 0, ibody[2 * (n - 1)]);
        }
        /* set triangle node normals */
        vis_ConnectIsElemNorm(connect, n, 1, &enormflag);
        if (enormflag) {
            vis_ConnectElemNormdv(connect, n, 1, enorm);
            if (rev) {
                Vdouble tmp[3];
                tmp[0] = enorm[1][0];
                tmp[1] = enorm[1][1];
                tmp[2] = enorm[1][2];
                enorm[1][0] = enorm[2][0];
                enorm[1][1] = enorm[2][1];
                enorm[1][2] = enorm[2][2];
                enorm[2][0] = tmp[0];
                enorm[2][1] = tmp[1];
                enorm[2][2] = tmp[2];
                for (k = 0; k < 3; k++) {
                    enorm[0][k] = -enorm[0][k];
                    enorm[1][k] = -enorm[1][k];
                    enorm[2][k] = -enorm[2][k];
                }
            }
            msh_SurfMeshSetTriNorm(surfmesh, ntri, enorm);
        }
        msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOFACE, ntri, SYS_FACE, 0, aid);
        /* set triangle edge tangents */
        for (k = 0; k < 3; k++) {
            if (tefl[k] == 0 || etang[k] == NULL)
                continue;
            if (tesens[k] == 0) {
                msh_SurfMeshSetTriTang(surfmesh, ntri, k + 1, (Vdouble(*)[3])etang[k]);
            }
            else {
                Vdouble copy[6];
                for (int i = 0; i < 3; ++i) {
                    copy[i] = -etang[k][i + 3];
                    copy[i + 3] = -etang[k][i];
                }
                msh_SurfMeshSetTriTang(surfmesh, ntri, k + 1, (Vdouble(*)[3])copy);
            }
        }
    }
    /* end objects */
labelcleanup:
    free(ibody);
    vsy_VHashTableForEach(vhtang, (Vfunc1*)free);
    vsy_VHashTableEnd(vhtang);
    vsy_IntHashEnd(ihnode);
    vsy_IntHashEnd(ihedge);
    vsy_IntVHashEnd(ivhenum);

    vis_ConnectEnd(connect);
    vsy_ADTreeEnd(adtree);
    printf("Geometry read complete\n");
    printf(" Number of geometry edges=  %d\n", numedge);
    printf(" Number of geometry faces=  %d\n", numface);
    printf(" Number of geometry bodies= %d\n", nbody);
    printf(" Number of tesselation points= %d\n", npts);
    printf(" Number of tesselation tris=   %d\n", ntri);
    if (npts == 0 || ntri == 0) {
        msh_SurfMeshEnd(surfmesh);
        return 1;
    }

    /* Set SurfMesh parameters */
    if (iquad) {
        msh_SurfMeshSetParami(surfmesh, VIS_MESH_SHAPE, VIS_SHAPEQUAD);
    }
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, edgelength);
    printf("edgelength= %e\n", edgelength);
    msh_SurfMeshSetParami(surfmesh, SURFMESH_NONMANIFOLD, 1);
    /* msh_SurfMeshSetParami(surfmesh, SURFMESH_GLOBALINTERSECT, 10);*/
    /* msh_SurfMeshSetParami(surfmesh, SURFMESH_GEOMCHORDEDGE_INTERSECT, 1);*/

    /* Write of SurfMesh input contents */
    msh_SurfMeshWrite(surfmesh, SYS_ASCII, srfname);

    /* Write input as bdf */
    Vchar bdfInputName[SYS_MAXPATHCHAR];
    strcpy(bdfInputName, baseName);
    strcat(bdfInputName, "_SurfmeshInput.bdf");
    vis_ConnectWrite(surfmesh->ce, SYS_NASTRAN_BULKDATA, bdfInputName);

    vis_Connect* connectsrf = vis_ConnectBegin();
    msh_SurfMeshGenerate(surfmesh, connectsrf);
    ierr = msh_SurfMeshError(surfmesh);

    if (ierr) {
        printf("Error generating surface mesh\n");
    }
    else {
        Vint numnpsrf, numelsrf;
        printf("SurfMesh complete\n");

        vis_ConnectNumber(connectsrf, SYS_NODE, &numnpsrf);
        vis_ConnectNumber(connectsrf, SYS_ELEM, &numelsrf);
        printf(" Surface number of nodes= %d\n", numnpsrf);
        printf(" Surface number of elems= %d\n", numelsrf);

        /* Write of SurfMesh mesh */
        Vchar bdfOutputName[SYS_MAXPATHCHAR];
        strcpy(bdfOutputName, baseName);
        strcat(bdfOutputName, "_SurfmeshOutput.bdf");
        vis_ConnectWrite(connectsrf, SYS_NASTRAN_BULKDATA, bdfOutputName);

        /* perform tet mesh */
        if (nbody)
            itet = 1;
        if (itet) {
            connecttet = vis_ConnectBegin();
            tetmesh = msh_TetMeshBegin();
            msh_TetMeshConnect(tetmesh, connectsrf);
            msh_TetMeshSetParamd(tetmesh, VIS_MESH_EDGELENGTH, edgelength);
            /* Write of TetMesh input content */
            Vchar tetName[SYS_MAXPATHCHAR];
            strcpy(tetName, baseName);
            strcat(tetName, "tet");
            msh_TetMeshWrite(tetmesh, SYS_ASCII, tetName);

            msh_TetMeshGenerate(tetmesh, connecttet);
            if (ierr) {
                printf("Error generating tet mesh\n");
            }
            else {
                Vint numnptet, numeltet;
                printf("TetMesh complete\n");
                vis_ConnectNumber(connecttet, SYS_NODE, &numnptet);
                vis_ConnectNumber(connecttet, SYS_ELEM, &numeltet);
                printf(" Tet mesh number of nodes= %d\n", numnptet);
                printf(" Tet mesh number of elems= %d\n", numeltet);

                /* Write of TetMesh mesh */
                Vchar bdfOutputFinalName[SYS_MAXPATHCHAR];
                strcpy(bdfOutputFinalName, baseName);
                strcat(bdfOutputFinalName, "_TetmeshOutput.bdf");
                vis_ConnectWrite(connecttet, SYS_NASTRAN_BULKDATA, bdfOutputFinalName);
            }
            vis_ConnectEnd(connecttet);
            msh_TetMeshEnd(tetmesh);
        }
    }
    msh_SurfMeshEnd(surfmesh);
    vis_ConnectEnd(connectsrf);

    return 0;
}
