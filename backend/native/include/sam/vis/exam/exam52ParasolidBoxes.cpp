#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sam/base/base.h"
#include "sam/base/vututil.h"
#include "sam/vis/vis.h"
#include "sam/msh/msh.h"
#include <map>
#include <vector>
#include <limits>

#define MOVE3(x, y)  \
    (y)[0] = (x)[0]; \
    (y)[1] = (x)[1]; \
    (y)[2] = (x)[2]
#define TOBOOL3(x, y)        \
    (y)[0] = (x)[0] ? 1 : 0; \
    (y)[1] = (x)[1] ? 1 : 0; \
    (y)[2] = (x)[2] ? 1 : 0;
#define DIFF3(x, y, z)        \
    (z)[0] = (x)[0] - (y)[0]; \
    (z)[1] = (x)[1] - (y)[1]; \
    (z)[2] = (x)[2] - (y)[2]

template<class T, class U>
T
map_lookup(const std::map<U, T>& m, const U& key, const T& default_value)
{
    typename std::map<U, T>::const_iterator it = m.find(key);
    if (it == m.end()) {
        return default_value;
    }
    return it->second;
}

struct Conic {
    Vint id;
    Vint sense;
};

struct MeshSize {
    Vint nodes = 0;
    Vint elements = 0;
};

/*
 * The three files below are part of the
 * Parasolid installation
 */
#include "parasolid_kernel.h"
#include "frustrum_ifails.h"
#include "frustrum_tokens.h"

/*
 * The frustrum functions below are required by
 * the Parasolid engine. We use the example frustrum
 * functions provided with the Parasolid distribution
 */
#include "frustrum.c"
/*
 * The static variables below
 * are required by the Parasolid engine
 */
static PK_SESSION_frustrum_t frustrum;
static PK_ERROR_frustrum_t errorFrustrum;
static PK_SESSION_start_o_t options;

/*
 * The error handler and memory allocation functions
 * are required by the Parasolid engine
 */
extern PK_ERROR_code_t
parasolid_ErrorHandler(PK_ERROR_sf_t* error)
{
    printf("PK error: %s returned %s\n", error->function, error->code_token);
    return error->code;
}

extern void
parasolid_ReturnMemory(int* nbytes, char** memory, int* ifail)
{
    vut_freeMem(*memory);
    *ifail = FR_no_errors;
}

extern void
parasolid_GetMemory(int* nbytes, char** memory, int* ifail)
{
    *ifail = FR_no_errors;
    *memory = (Vchar*)vut_mallocMem(*nbytes);
    if (*memory == NULL) {
        *ifail = FR_memory_full;
    }
}

static void
parasolid_Init()
{
    /* initialize frustrum with default values */
    errorFrustrum.handler_fn = parasolid_ErrorHandler;
    PK_SESSION_frustrum_o_m(frustrum);

    frustrum.fstart = FSTART;
    frustrum.fstop = FSTOP;
    frustrum.ffoprd = FFOPRD;
    frustrum.ffopwr = FFOPWR;
    frustrum.ffwrit = FFWRIT;
    frustrum.ffread = FFREAD;
    frustrum.ffclos = FFCLOS;
    frustrum.fabort = FABORT;
    frustrum.fmallo = parasolid_GetMemory;
    frustrum.fmfree = parasolid_ReturnMemory;

    /* register frustrum */
    PK_SESSION_register_frustrum(&frustrum);

    /* start the modeller */
    PK_SESSION_start_o_m(options);
    PK_SESSION_start(&options);
}

static void
parasolid_Term()
{
    PK_SESSION_stop();
}

char*
strremove(char* str, const char* sub)
{
    char *p, *q, *r;
    if (*sub && (q = r = strstr(str, sub)) != NULL) {
        size_t len = strlen(sub);
        while ((r = strstr(p = r + len, sub)) != NULL) {
            memmove(q, p, r - p);
            q += r - p;
        }
        memmove(q, p, strlen(p) + 1);
    }
    return str;
}

static void
imprintFace(const PK_FACE_t targetFace, const PK_FACE_t toolFace)
{
    PK_ERROR_code_t error_code;
    PK_EDGE_t* edges = NULL;
    PK_CURVE_t* curve_array;
    PK_INTERVAL_t* interval_array = NULL;
    PK_INTERVAL_t* bounds = NULL;
    PK_VECTOR_t* vectors = NULL;
    double* ts_1 = NULL;
    double* ts_2 = NULL;

    PK_intersect_vector_t* types = NULL;

    PK_SURF_t surface;
    PK_FACE_ask_surf(targetFace, &surface);

    PK_CLASS_t entity_class;
    error_code = PK_ENTITY_ask_class(surface, &entity_class);
    if (PK_CLASS_plane == entity_class) {
        // Get normal dir
        PK_PLANE_sf_t plane_sf;
        error_code = PK_PLANE_ask(surface, &plane_sf);

        PK_BODY_t body;
        PK_FACE_ask_body(targetFace, &body);

        int n_edges;
        error_code = PK_FACE_ask_edges(toolFace, &n_edges, &edges);

        curve_array = new PK_CURVE_t[n_edges];
        interval_array = new PK_INTERVAL_t[n_edges];
        bounds = new PK_INTERVAL_t[n_edges];

        for (int j = 0; j < n_edges; j++) {
            error_code = PK_EDGE_ask_curve(edges[j], &curve_array[j]);
            error_code = PK_ENTITY_ask_class(curve_array[j], &entity_class);
            error_code = PK_CURVE_ask_interval(curve_array[j], &interval_array[j]);
        }

        PK_CURVE_intersect_curve_o_t intersectOpts;
        PK_CURVE_intersect_curve_o_m(intersectOpts);
        for (int j = 0; j < n_edges; j++) {
            int jj = j + 1;
            if (n_edges == jj)
                jj = 0;
            int n_vectors = 0;
            error_code = PK_CURVE_intersect_curve(curve_array[j], interval_array[j], curve_array[jj], interval_array[jj],
                                                  &intersectOpts, &n_vectors, &vectors, &ts_1, &ts_2, &types);
            bounds[j].value[1] = ts_1[0];
            bounds[jj].value[0] = ts_2[0];
        }

        for (int j = 0; j < n_edges; j++) {
            double st = bounds[j].value[0];
            double en = bounds[j].value[1];

            if (st > en) {
                bounds[j].value[0] = en;
                bounds[j].value[1] = st;
            }
        }

        PK_CURVE_project_o_t project_opts;
        PK_CURVE_project_r_t project_results;
        PK_ENTITY_track_r_t project_tracking;

        PK_CURVE_project_o_m(project_opts);
        project_opts.function = PK_proj_function_imprint_c;
        project_opts.have_direction = PK_LOGICAL_true;
        project_opts.direction = {-plane_sf.basis_set.axis.coord[0], -plane_sf.basis_set.axis.coord[1],
                                  -plane_sf.basis_set.axis.coord[2]};
        error_code = PK_CURVE_project(n_edges, curve_array, bounds, 1, &body, &project_opts, &project_results, &project_tracking);
    }
}

void
setConic_PK_PLANE(msh_SurfMesh* surfmesh, Vint conicid, Vint sense, PK_SURF_t& surf)
{
    Vdouble xo[3], axis[3], ref[3];
    PK_PLANE_sf_t plane_sf;
#ifdef MESH_DEBUG
    printf("PK_CLASS_plane\n");
#endif
    PK_PLANE_ask(surf, &plane_sf);
    MOVE3(plane_sf.basis_set.location.coord, xo);
    MOVE3(plane_sf.basis_set.axis.coord, axis);
    MOVE3(plane_sf.basis_set.ref_direction.coord, ref);
    msh_SurfMeshSetConic(surfmesh, conicid, SURFMESH_CONIC_PLANE, sense, xo, axis, ref, 0., 0.);
}

void
setConic_PK_CYL(msh_SurfMesh* surfmesh, Vint conicid, Vint sense, PK_SURF_t& surf)
{
    Vdouble xo[3], axis[3], ref[3], cr;
    PK_CYL_sf_t cyl_sf;
#ifdef MESH_DEBUG
    printf("PK_CLASS_cyl\n");
#endif
    PK_CYL_ask(surf, &cyl_sf);
    MOVE3(cyl_sf.basis_set.location.coord, xo);
    MOVE3(cyl_sf.basis_set.axis.coord, axis);
    MOVE3(cyl_sf.basis_set.ref_direction.coord, ref);
    cr = cyl_sf.radius;
    msh_SurfMeshSetConic(surfmesh, conicid, SURFMESH_CONIC_CYLINDER, sense, xo, axis, ref, cr, 0.);
}

void
setConic_PK_CONE(msh_SurfMesh* surfmesh, Vint conicid, Vint sense, PK_SURF_t& surf)
{
    Vdouble xo[3], axis[3], ref[3], cr;
    PK_CONE_sf_t cone_sf;
#ifdef MESH_DEBUG
    printf("PK_CLASS_cone\n");
#endif
    PK_CONE_ask(surf, &cone_sf);
    MOVE3(cone_sf.basis_set.location.coord, xo);
    MOVE3(cone_sf.basis_set.axis.coord, axis);
    MOVE3(cone_sf.basis_set.ref_direction.coord, ref);
    cr = cone_sf.semi_angle;
    msh_SurfMeshSetConic(surfmesh, conicid, SURFMESH_CONIC_CONE, sense, xo, axis, ref, cr, 0.);
}

void
setConic_PK_SPHERE(msh_SurfMesh* surfmesh, Vint conicid, Vint sense, PK_SURF_t& surf)
{
    Vdouble xo[3], axis[3], ref[3], cr;
    PK_SPHERE_sf_t sphere_sf;
#ifdef MESH_DEBUG
    printf("PK_CLASS_sphere\n");
#endif
    PK_SPHERE_ask(surf, &sphere_sf);
    MOVE3(sphere_sf.basis_set.location.coord, xo);
    MOVE3(sphere_sf.basis_set.axis.coord, axis);
    MOVE3(sphere_sf.basis_set.ref_direction.coord, ref);
    cr = sphere_sf.radius;
    msh_SurfMeshSetConic(surfmesh, conicid, SURFMESH_CONIC_SPHERE, sense, xo, axis, ref, cr, 0.);
}

void
setConic_PK_TORUS(msh_SurfMesh* surfmesh, Vint conicid, Vint sense, PK_SURF_t& surf)
{
    Vdouble xo[3], axis[3], ref[3], cr, cc;
    PK_TORUS_sf_t torus_sf;
#ifdef MESH_DEBUG
    printf("PK_CLASS_torus\n");
#endif
    PK_TORUS_ask(surf, &torus_sf);
    MOVE3(torus_sf.basis_set.location.coord, xo);
    MOVE3(torus_sf.basis_set.axis.coord, axis);
    MOVE3(torus_sf.basis_set.ref_direction.coord, ref);
    cr = torus_sf.minor_radius;
    cc = torus_sf.major_radius;
    msh_SurfMeshSetConic(surfmesh, conicid, SURFMESH_CONIC_TORUS, sense, xo, axis, ref, cr, cc);
#ifdef MESH_DEBUG
    printf("xo= %e %e %e\n", xo[0], xo[1], xo[2]);
    printf("axis= %e %e %e\n", axis[0], axis[1], axis[2]);
    printf("ref= %e %e %e\n", ref[0], ref[1], ref[2]);
    printf("minor_radius= %e\n", torus_sf.minor_radius);
    printf("major_radius= %e\n", torus_sf.major_radius);
#endif
}

void
setConic_PK(msh_SurfMesh* surfmesh, Vint conicid, Vint sense, PK_SURF_t& surf)
{
    PK_CLASS_t sclass;
#ifdef MESH_DEBUG
    printf("conicid= %d\n", conicid);
#endif
    PK_ENTITY_ask_class(surf, &sclass);
    if (sclass == PK_CLASS_plane) {
        setConic_PK_PLANE(surfmesh, conicid, sense, surf);
    }
    else if (sclass == PK_CLASS_cyl) {
        setConic_PK_CYL(surfmesh, conicid, sense, surf);
    }
    else if (sclass == PK_CLASS_cone) {
        setConic_PK_CONE(surfmesh, conicid, sense, surf);
    }
    else if (sclass == PK_CLASS_sphere) {
        setConic_PK_SPHERE(surfmesh, conicid, sense, surf);
    }
    else if (sclass == PK_CLASS_torus) {
        setConic_PK_TORUS(surfmesh, conicid, sense, surf);
    }
}

void
setConics(msh_SurfMesh* surfmesh, std::map<int, Conic>& surfconic_map)
{
    PK_SURF_t surf;
    Vint sense;
    Vint conicid;
    for (auto& iconic: surfconic_map) {
        conicid = iconic.second.id;
        sense = iconic.second.sense;
        if (sense == 0)
            sense = -1;
        setConic_PK(surfmesh, conicid, sense, surf);
    }
}

struct TessellationTable {
    PK_TOPOL_fctab_facet_fin_s* facet_fin;
    PK_TOPOL_fctab_fin_fin_s* fin_fin;
    PK_TOPOL_fctab_fin_data_s* fin_data;
    PK_TOPOL_fctab_data_point_s* data_point_idx;
    PK_TOPOL_fctab_data_normal_s* data_normal_idx;
    PK_TOPOL_fctab_point_vec_s* point_vec;
    PK_TOPOL_fctab_normal_vec_s* normal_vec;
    PK_TOPOL_fctab_facet_face_s* facet_face;
    PK_TOPOL_fctab_fin_edge_s* fin_edge;
    PK_TOPOL_fctab_point_topol_s* point_topol;
};

TessellationTable
makeParasolidTessellation(const PK_TOPOL_t* part, const PK_TOPOL_facet_2_o_t* facet_options)
{
    PK_TOPOL_facet_2_r_t tables;
    PK_ERROR_t err = PK_TOPOL_facet_2(1, part, NULL, facet_options, &tables);
    if (err != 0) {
        fprintf(stderr, "PK_TOPOL_facet_2 error= %d\n", err);
        exit(1);
    }
    TessellationTable tessellation;
    for (Vint j = 0; j < tables.number_of_tables; j++) {
        if (tables.tables[j].fctab == PK_TOPOL_fctab_facet_fin_c) {
            tessellation.facet_fin = tables.tables[j].table.facet_fin;
        }
        else if (tables.tables[j].fctab == PK_TOPOL_fctab_fin_fin_c) {
            tessellation.fin_fin = tables.tables[j].table.fin_fin;
        }
        else if (tables.tables[j].fctab == PK_TOPOL_fctab_fin_data_c) {
            tessellation.fin_data = tables.tables[j].table.fin_data;
        }
        else if (tables.tables[j].fctab == PK_TOPOL_fctab_data_point_c) {
            tessellation.data_point_idx = tables.tables[j].table.data_point_idx;
        }
        else if (tables.tables[j].fctab == PK_TOPOL_fctab_data_normal_c) {
            tessellation.data_normal_idx = tables.tables[j].table.data_normal_idx;
        }
        else if (tables.tables[j].fctab == PK_TOPOL_fctab_point_vec_c) {
            tessellation.point_vec = tables.tables[j].table.point_vec;
        }
        else if (tables.tables[j].fctab == PK_TOPOL_fctab_normal_vec_c) {
            tessellation.normal_vec = tables.tables[j].table.normal_vec;
        }
        else if (tables.tables[j].fctab == PK_TOPOL_fctab_facet_face_c) {
            tessellation.facet_face = tables.tables[j].table.facet_face;
        }
        else if (tables.tables[j].fctab == PK_TOPOL_fctab_fin_edge_c) {
            tessellation.fin_edge = tables.tables[j].table.fin_edge;
        }
        else if (tables.tables[j].fctab == PK_TOPOL_fctab_point_topol_c) {
            tessellation.point_topol = tables.tables[j].table.point_topol;
        }
    }
    return tessellation;
}

int
checkIsVoid(int n_faces, PK_LOGICAL_t* orients)
{
    for (int ifa = 0; ifa < n_faces; ifa++)
        if (!orients[ifa])
            return 0;
    return 1;
}
void
makeFaceRegionMaps(std::map<int, int>& faceregion_l_map, std::map<int, int>& faceregion_r_map, int n_faces, PK_FACE_t* faces,
                   PK_LOGICAL_t* orients, PK_REGION_t region)
{
    for (int ifa = 0; ifa < n_faces; ifa++) {
        if (!orients[ifa]) {
            faceregion_l_map[faces[ifa]] = region;
        }
        else {
            faceregion_r_map[faces[ifa]] = region;
        }
    }
}

void
makeSurfConicMap(std::map<int, Conic>& surfconic_map, int n_faces, PK_FACE_t* faces, int* numconic)
{
    PK_SURF_t surf;
    PK_LOGICAL_t orientf;
    Vint conicid = 0;
    PK_CLASS_t sclass;
    for (int ifa = 0; ifa < n_faces; ifa++) {
        PK_FACE_ask_oriented_surf(faces[ifa], &surf, &orientf);
        PK_ENTITY_ask_class(surf, &sclass);
        Vint isconic = 0;
        if (sclass == PK_CLASS_plane) {
            isconic = sclass;
        }
        else if (sclass == PK_CLASS_cyl) {
            isconic = sclass;
        }
        else if (sclass == PK_CLASS_cone) {
            isconic = sclass;
        }
        else if (sclass == PK_CLASS_sphere) {
            isconic = sclass;
        }
        else if (sclass == PK_CLASS_torus) {
            isconic = sclass;
        }
        if (isconic) {
            conicid = map_lookup(surfconic_map, surf, {0, 0}).id;
            if (conicid == 0) {
                *numconic += 1;
#ifdef MESH_DEBUG
                printf("conicid= %d, orientf= %d\n", *numconic, orientf);
#endif
                surfconic_map[surf] = {*numconic, orientf};
            }
        }
    }
}

void
makePartMaps(PK_PART_t& part, std::map<int, Conic>& surfconic_map, std::map<int, int>& faceregion_l_map,
             std::map<int, int>& faceregion_r_map, std::map<int, int>& vertexpart_map, Vint* numconic)
{
    PK_REGION_t* regions;
    PK_SHELL_t* shells;
    PK_FACE_t* faces;
    PK_VERTEX_t* vertices;
    PK_LOGICAL_t* orients;
    PK_LOGICAL_t is_solid;

    int n_regions, n_shells, n_faces, n_vertices;
    PK_BODY_ask_regions(part, &n_regions, &regions);
    for (int ir = 0; ir < n_regions; ir++) {
        /* skip non-solid regions */
        PK_REGION_is_solid(regions[ir], &is_solid);
        if (is_solid == false)
            continue;
        PK_REGION_ask_shells(regions[ir], &n_shells, &shells);
        Vint isvoid = 1;
        for (int is = 0; is < n_shells; is++) {
            PK_SHELL_ask_oriented_faces(shells[is], &n_faces, &faces, &orients);
            isvoid = isvoid && checkIsVoid(n_faces, orients);
            makeFaceRegionMaps(faceregion_l_map, faceregion_r_map, n_faces, faces, orients, regions[ir]);
            makeSurfConicMap(surfconic_map, n_faces, faces, numconic);
            if (n_faces) {
                PK_MEMORY_free(faces);
                PK_MEMORY_free(orients);
            }
        }
        if (n_shells)
            PK_MEMORY_free(shells);
    }
    if (n_regions)
        PK_MEMORY_free(regions);

    PK_BODY_ask_vertices(part, &n_vertices, &vertices);
    printf("  Number of vertices = %d\n", n_vertices);
    for (int j = 0; j < n_vertices; j++) {
        vertexpart_map[vertices[j]] = part;
    }
    if (n_vertices)
        PK_MEMORY_free(vertices);
}

void
alignTangentWithEdgeDirection(PK_VECTOR_t& tg, Vdouble* etang, Vdouble* tang)
{
    /* make sure tangent is aligned with edge direction */
    MOVE3(tg.coord, tang);
    if (tang[0] * etang[0] + tang[1] * etang[1] + tang[2] * etang[2] < 0.) {
        tang[0] = -tang[0];
        tang[1] = -tang[1];
        tang[2] = -tang[2];
    }
}

Vint
parametrisePointAndTangent(PK_CURVE_t& curve, PK_VECTOR_t& pt, PK_VECTOR_t* tg, PK_GEOM_range_vector_o_t* options,
                           PK_range_result_t* range_result, PK_range_1_r_t* range)
{
    /* compute parameter "t" on curve */
    double t;
    PK_ERROR_t err = PK_CURVE_parameterise_vector(curve, pt, &t);

    /*
     * An error indicates that the point, although
     * supposedly on the edge, was placed away from the
     * during the Tessellation. We then try to find
     * a point on the edge that is as close as possible
     * to the Tessellation point
     */
    if (err != 0) {
        err = PK_GEOM_range_vector(curve, pt, options, range_result, range);
        if (err) {
            printf("Unable to project point to curve, err= %d\n", err);
            return 1;
        }
        t = range->end.parameters[0];
    }
    PK_CURVE_eval_with_tangent(curve, t, 0, &pt, tg);
    return 0;
}

void
insertPoint(msh_SurfMesh* surfmesh, Vint index, Vint geopoint, Vdouble* vertex, std::map<int, int>& pointvertex_map,
            std::map<int, int>& vertexpart_map)
{
    /* Check whether node is on edge/vertex, or interior to a surface. */
    Vint geovert = map_lookup(pointvertex_map, geopoint, 0);
    Vint geobody = map_lookup(vertexpart_map, geovert, 0);
    if (geobody) {
        msh_SurfMeshSetPoint(surfmesh, index, vertex, 1);
        msh_SurfMeshSetPointAssoc(surfmesh, VIS_GEOVERT, index, geovert);
    }
    else {
        msh_SurfMeshSetPoint(surfmesh, index, vertex, 0);
    }
}

void
insertTriangle(msh_SurfMesh* surfmesh, Vint element, Vint* ix, Vint* eflags, Vdouble normals[3][3], Vint geoface,
               std::map<int, Conic>& surfconic_map, std::map<int, int>& faceregion_l_map, std::map<int, int>& faceregion_r_map,
               int invert_sense)
{
    msh_SurfMeshSetTri(surfmesh, element, ix, eflags);
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOFACE, element, SYS_FACE, 0, geoface);
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, element, SYS_ELEM, 0, geoface);
    Vint geobodyrb = map_lookup(faceregion_r_map, geoface, 0);
    Vint geobodylb = map_lookup(faceregion_l_map, geoface, 0);
    if (geobodylb || geobodyrb) {
        if (invert_sense)
            std::swap(geobodyrb, geobodylb);
    }
    else if (invert_sense) {
        geobodylb = 1;
    }

    msh_SurfMeshSetTriBack(surfmesh, element, geobodyrb, geobodylb);
    if (geobodyrb) {
        msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, element, SYS_ELEM, 0, geobodyrb);
        // msh_SurfMeshSetTriAssoc (surfmesh,VIS_PROPID,element,SYS_ELEM,0,geobodyrb);
    }
    if (geobodylb) {
        msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, element, SYS_ELEM, -1, geobodylb);
        // msh_SurfMeshSetTriAssoc (surfmesh,VIS_PROPID,element,SYS_ELEM,-1,geobodylb);
    }
    msh_SurfMeshSetTriNorm(surfmesh, element, normals);

    PK_SURF_t surf;
    PK_FACE_ask_surf(geoface, &surf);
    Vint conicid = map_lookup(surfconic_map, surf, {0, 0}).id;
    if (conicid) {
        msh_SurfMeshSetTriConic(surfmesh, element, conicid);
    }
}

Vint
freeEdges(vis_Connect* connect)
{
    vis_ConnectKernel(connect, 0);
    Vint numnp, numel;
    vis_ConnectInq(connect, &numnp, &numel);

    // build free edge group
    vis_Group* groupedgefree = vis_GroupBegin();
    vis_GroupDef(groupedgefree, numel, SYS_ELEM, SYS_EDGE);
    vis_ConnectEdgeGroup(connect, CONNECT_FREE, NULL, groupedgefree);
    Vint childCount = 0;
    Vint parentCount = 0;
    vis_GroupCount(groupedgefree, &parentCount, &childCount);
    vis_GroupEnd(groupedgefree);
    return size_t(childCount);
}

void
mergeCoincidentNodes(vis_Connect* connect, Vdouble tolerance)
{
    vis_ConnectKernel(connect, 0);
    Vint numnp, numel;
    vis_ConnectInq(connect, &numnp, &numel);

    // build free edge group
    vis_Group* groupedgefree = vis_GroupBegin();
    vis_GroupDef(groupedgefree, numel, SYS_ELEM, SYS_EDGE);
    vis_ConnectEdgeGroup(connect, CONNECT_FREE, NULL, groupedgefree);

    // build free edge node group
    vis_Group* groupnode = vis_GroupBegin();
    vis_GroupDef(groupnode, numnp, SYS_NODE, SYS_NONE);
    vis_ConnectNodeGroup(connect, CONNECT_UNIQUE, groupedgefree, groupnode);
    vis_ConnectSetParamf(connect, CONNECT_TOLERANCE, tolerance);
    vis_ConnectMerge(connect, groupnode);
    vis_GroupEnd(groupnode);
    vis_GroupEnd(groupedgefree);
}

Vint
setEdgeTangent(msh_SurfMesh* surfmesh, Vint element, Vint edge, Vint* geoedges, Vdouble vertex[3][3],
               PK_GEOM_range_vector_o_t* options, PK_range_result_t* range_result, PK_range_1_r_t* range)
{
    PK_CURVE_t curve;
    PK_VECTOR_t pt, tg;
    double tang[2][3], etang[3];
    /* assign edge association */
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOEDGE, element, SYS_EDGE, edge, geoedges[edge - 1]);

    DIFF3(vertex[edge % 3], vertex[edge - 1], etang);
    PK_EDGE_ask_curve(geoedges[edge - 1], &curve);

    /* first point on edge */
    MOVE3(vertex[edge - 1], pt.coord);
    if (parametrisePointAndTangent(curve, pt, &tg, options, range_result, range))
        return 1;
    /* make sure tangent is aligned with edge direction */
    alignTangentWithEdgeDirection(tg, etang, tang[0]);

    /* likewise, second point on edge */
    MOVE3(vertex[edge % 3], pt.coord);
    if (parametrisePointAndTangent(curve, pt, &tg, options, range_result, range))
        return 1;
    alignTangentWithEdgeDirection(tg, etang, tang[1]);

    /* set tangents */
    msh_SurfMeshSetTriTang(surfmesh, element, edge, tang);
    return 0;
}

void
updateExtents(Vdouble* minext, Vdouble* maxext, Vdouble* vertex)
{
    if (vertex[0] < minext[0])
        minext[0] = vertex[0];
    if (vertex[1] < minext[1])
        minext[1] = vertex[1];
    if (vertex[2] < minext[2])
        minext[2] = vertex[2];
    if (vertex[0] > maxext[0])
        maxext[0] = vertex[0];
    if (vertex[1] > maxext[1])
        maxext[1] = vertex[1];
    if (vertex[2] > maxext[2])
        maxext[2] = vertex[2];
}

MeshSize
dumpTessellationIntoSurfmesh(msh_SurfMesh* surfmesh, TessellationTable tessellation, int invert_sense,
                             std::map<int, int>& vertexpart_map, std::map<int, Conic>& surfconic_map,
                             std::map<int, int>& faceregion_l_map, std::map<int, int>& faceregion_r_map,
                             PK_GEOM_range_vector_o_t* options, PK_range_result_t* range_result, PK_range_1_r_t* range)
{
    std::map<int, int> finedge_map;
    for (Vint ii = 0; ii < tessellation.fin_edge->length; ii++) {
        finedge_map[tessellation.fin_edge->data[ii].fin] = tessellation.fin_edge->data[ii].edge;
    }
    /* map point->vertex information */
    std::map<int, int> pointvertex_map;
    for (Vint ii = 0; ii < tessellation.point_topol->length; ii++) {
        pointvertex_map[tessellation.point_topol->data[ii].point + 1] = tessellation.point_topol->data[ii].topol;
    }

    /* loop over all fins */
    Vint length = tessellation.facet_fin->length;
    Vint j = 0;
    MeshSize surfmeshsize;
    Vint ix[3];
    Vint geoedge[3];
    Vdouble normals[3][3];
    Vdouble vertex[3][3];
    Vint eflags[3];
    std::map<int, int> pointnode_map;

    for (Vint ii = 0; ii < length; ii++) {
        Vint finID = tessellation.facet_fin->data[ii].fin;
        Vint finIndex = tessellation.fin_data->data[finID];
        Vint point = tessellation.data_point_idx->point[finIndex];
        MOVE3(tessellation.point_vec->vec[point].coord, vertex[j]);
        Vint index = map_lookup(pointnode_map, point + 1, 0);
        /* check for new node */
        if (index == 0) {
            index = ++surfmeshsize.nodes;
            pointnode_map[point + 1] = index;
            insertPoint(surfmesh, index, point + 1, vertex[j], pointvertex_map, vertexpart_map);
        }
        ix[j] = index;
        /* every 3 fins => completed triangle */
        Vint facetID = tessellation.facet_fin->data[ii].facet;
        Vint geoface = tessellation.facet_face->face[facetID];
        Vint normalIndex = tessellation.data_normal_idx->normal[finIndex];
        MOVE3(tessellation.normal_vec->vec[normalIndex].coord, normals[j]);
        geoedge[(j + 2) % 3] = map_lookup(finedge_map, finID, 0);
        ++j;
        if (j == 3) {
            ++surfmeshsize.elements;
            TOBOOL3(geoedge, eflags);
            /* insert triangle, its associations, and normals */
            insertTriangle(surfmesh, surfmeshsize.elements, ix, eflags, normals, geoface, surfconic_map, faceregion_l_map,
                           faceregion_r_map, invert_sense);
            /* compute edge tangents for geometry edges */
            for (Vint m = 1; m <= 3; m++) {
                if (geoedge[m - 1]) {
                    setEdgeTangent(surfmesh, surfmeshsize.elements, m, geoedge, vertex, options, range_result, range);
                }
            }
            j = 0;
        }
    }
    return surfmeshsize;
}

PK_TOPOL_facet_2_o_t
makefacet_options()
{
    PK_TOPOL_facet_2_o_t facet_options;
    /* set default Parasolid Tessellation options */
    PK_TOPOL_facet_2_o_m(facet_options);
    /* initialize Tessellation choice options */
    facet_options.choice.facet_fin = true;
    facet_options.choice.fin_data = true;
    facet_options.choice.data_point_idx = true;
    facet_options.choice.data_normal_idx = true;
    facet_options.choice.point_vec = true;
    facet_options.choice.normal_vec = true;
    facet_options.choice.facet_face = true;
    facet_options.choice.fin_edge = true;
    facet_options.choice.point_topol = true;
    facet_options.choice.facet_fin = PK_LOGICAL_true;
    facet_options.choice.fin_fin = PK_LOGICAL_true;
    facet_options.choice.fin_data = PK_LOGICAL_true;
    facet_options.choice.data_point_idx = PK_LOGICAL_true;
    facet_options.choice.data_normal_idx = PK_LOGICAL_true;
    facet_options.choice.point_vec = PK_LOGICAL_true;
    facet_options.choice.normal_vec = PK_LOGICAL_true;
    facet_options.choice.facet_face = PK_LOGICAL_true;
    facet_options.choice.fin_edge = PK_LOGICAL_true;
    facet_options.choice.point_topol = PK_LOGICAL_true;
    /* initialize Tessellation control options */
    facet_options.control.shape = PK_facet_shape_any_c;
    facet_options.control.match = PK_facet_match_topol_c;
    /*
     * The option below is used to minimize the number
     * of edge Tessellation point that are not on the edge
     */
    facet_options.control.quality = PK_facet_quality_improved_c;
    return facet_options;
}

Vint
canSurfMeshPart(PK_PART_t part)
{
    PK_CLASS_t eclass;
    PK_BODY_type_t bodyType;
    /* get part class (body, sheet, etc.) */
    PK_ENTITY_ask_class(part, &eclass);
    /* check for body */
    if (eclass != PK_CLASS_body)
        return 0;
    /* check for solid, sheet, or non-manifold body */
    PK_BODY_ask_type(part, &bodyType);
    if (bodyType != PK_BODY_type_sheet_c && bodyType != PK_BODY_type_solid_c && bodyType != PK_BODY_type_general_c)
        return 0;

    return 1;
}

void
setSurfMeshParameters(msh_SurfMesh* surfmesh, PK_PART_t part, Vdouble edgelen)
{
    PK_BODY_type_t bodyType;
    PK_BODY_ask_type(part, &bodyType);
    if (bodyType == PK_BODY_type_general_c) {
        printf("Warning: Body %d is of general type\n", part);
        msh_SurfMeshSetParami(surfmesh, SURFMESH_NONMANIFOLD, SYS_ON);
    }
    else {
        printf("Body %d is a %s\n", part, bodyType == PK_BODY_type_sheet_c ? "sheet" : "solid");
        msh_SurfMeshSetParami(surfmesh, SURFMESH_NONMANIFOLD, SYS_OFF);
    }
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, edgelen);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_SPANANGLE, 45.);
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 3);
}

void
setTetMeshParameters(msh_TetMesh* tetmesh, PK_PART_t /*part*/, Vdouble edgelen)
{
    msh_TetMeshSetParamd(tetmesh, VIS_MESH_EDGELENGTH, edgelen);
    msh_TetMeshSetParamd(tetmesh, VIS_MESH_GROWTHRATE, 2.);
}

vis_Connect*
makeSurfMesh(msh_SurfMesh* surfmesh, PK_PART_t part, Vint saveDebugObject)
{
    /* Save SurfMesh file */
    if (saveDebugObject) {
        Vchar filnam[256];
        sprintf(filnam, "PK_CSAM_bridge_part_%d.srf", part);
        msh_SurfMeshWrite(surfmesh, SYS_ASCII, filnam);
    }

    /* Generate mesh and store it in a connect object */
    vis_Connect* connectsrf = vis_ConnectBegin();
    vis_ConnectPre(connectsrf, SYS_DOUBLE);
    msh_SurfMeshGenerate(surfmesh, connectsrf);
    Vint ierr = msh_SurfMeshError(surfmesh);
    if (ierr) {
        Vchar filnam[25];
        printf("Error generating surface mesh, part= %d\n", part);
        sprintf(filnam, "model-%d.srf", part);
        msh_SurfMeshWrite(surfmesh, SYS_ASCII, filnam);
        vis_ConnectEnd(connectsrf);
        return nullptr;
    }
    Vint numnp = 0;
    Vint numel = 0;
    printf("SurfMesh part= %d complete\n", part);
    vis_ConnectNumber(connectsrf, SYS_NODE, &numnp);
    vis_ConnectNumber(connectsrf, SYS_ELEM, &numel);
    printf("Surface number of nodes= %d\n", numnp);
    printf("Surface number of elems= %d\n", numel);
    return connectsrf;
}

vis_Connect*
makeTetMesh(msh_TetMesh* tetmesh, PK_PART_t part, Vint saveDebugObject)
{
    /* Save TetMesh file */
    if (saveDebugObject) {
        Vchar filnam[256];
        sprintf(filnam, "PK_CSAM_bridge_part_%d.tet", part);
        msh_TetMeshWrite(tetmesh, SYS_ASCII, filnam);
    }

    /* Generate mesh and store it in a connect object */
    vis_Connect* connecttet = vis_ConnectBegin();
    vis_ConnectPre(connecttet, SYS_DOUBLE);
    msh_TetMeshGenerate(tetmesh, connecttet);
    Vint ierr = msh_TetMeshError(tetmesh);
    if (ierr) {
        Vchar filnam[25];
        printf("Error generating tet mesh, part= %d\n", part);
        sprintf(filnam, "part_%d.btet", part);
        msh_TetMeshWrite(tetmesh, SYS_BINARY, filnam);
        vis_ConnectEnd(connecttet);
        return nullptr;
    }
    MeshSize connectsize;
    printf("TetMesh part= %d complete\n", part);
    vis_ConnectNumber(connecttet, SYS_NODE, &connectsize.nodes);
    vis_ConnectNumber(connecttet, SYS_ELEM, &connectsize.elements);
    printf("Volume number of nodes= %d\n", connectsize.nodes);
    printf("Volume number of elems= %d\n", connectsize.elements);
    return connecttet;
}

static Vint writesurfmesh = 1;
static Vint writetetmesh = 0;
static Vint tetmeshoption = 1;

/*----------------------------------------------------------------------
          Illustrate Parasolid interface to SurfMesh
----------------------------------------------------------------------*/

vis_Connect*
meshParasolidParts(PK_PART_t* parts, int* face_orientations, Vint nparts, PK_TOPOL_facet_2_o_t* facet_options,
                   PK_GEOM_range_vector_o_t* project_options, PK_range_result_t* range_result, PK_range_1_r_t* range)
{
    Vint numconic;
    Vdouble edgelen = 0.05;
    vis_Connect* connect = vis_ConnectBegin(); // This object will transfer ownership to parent scope
    msh_SurfMesh* surfmesh = msh_SurfMeshBegin();
    msh_TetMesh* tetmesh = msh_TetMeshBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    std::map<int, int> vertexpart_map;
    /* loop over parts */
    for (int i = 0; i < nparts; i++) {
        printf("Processing part %d\n", i);
        if (!canSurfMeshPart(parts[i]))
            continue;
        /* initialize IntHash for body to the left of face */
        std::map<int, int> faceregion_l_map;
        std::map<int, int> faceregion_r_map;
        std::map<int, Conic> surfconic_map;
        /* create region->face map */
        numconic = 0;
        makePartMaps(parts[i], surfconic_map, faceregion_l_map, faceregion_r_map, vertexpart_map, &numconic);
        /* tesselate part */
        TessellationTable tessellation = makeParasolidTessellation(&parts[i], facet_options);
        /* initialize SurfMesh */
        msh_SurfMeshDef(surfmesh, tessellation.point_vec->length, tessellation.facet_fin->length / 3);
        /* set conic sections */
        setConics(surfmesh, surfconic_map);
        /* map fin->edge information */
        dumpTessellationIntoSurfmesh(surfmesh, tessellation, face_orientations[i], vertexpart_map, surfconic_map,
                                     faceregion_l_map, faceregion_r_map, project_options, range_result, range);
        /* set SurfMesh parameters */
        setSurfMeshParameters(surfmesh, parts[i], edgelen);
        /* generate surface mesh and write result */
        vis_Connect* connectsrf = makeSurfMesh(surfmesh, parts[i], writesurfmesh);
        if (connectsrf == nullptr)
            continue;

        vis_ConnectAppend(connect, connectsrf);
        vis_ConnectEnd(connectsrf);
    }

    if (tetmeshoption) {
        /* make volumetric mesh if requested */
        printf("Generating volumetric mesh\n");
        /* test for no free edges */
        Vint nfree = freeEdges(connect);
        if (nfree) {
            /* Try to merge coincident nodes to remove free edges */
            printf("  Number of free edges = %d\n", nfree);
            printf("    Attempting merge\n");
            mergeCoincidentNodes(connect, edgelen * 1e-6);
            nfree = freeEdges(connect);
            printf("    Merge Done\n");
        }

        if (nfree) {
            printf("  Can not make TetMesh: number of remaining free edges= %d\n", nfree);
        }
        else {
            printf("  Meshing...\n");
            setTetMeshParameters(tetmesh, 0, edgelen);
            msh_TetMeshConnect(tetmesh, connect);
            vis_Connect* connecttet = makeTetMesh(tetmesh, 0, writetetmesh);
            if (connecttet != nullptr) {
                vis_ConnectAppend(connect, connecttet);
                vis_ConnectEnd(connecttet);
            }
        }
    }
    msh_SurfMeshEnd(surfmesh);
    msh_TetMeshEnd(tetmesh);
    return connect;
}

void
makeOpenBoxAndFacet(double box_size_target[3], double box_pos_target[3], int face_index_target, double box_size_tool[3],
                    double box_pos_tool[3], int face_index_tool, PK_BODY_t& obox, PK_BODY_t& oface, int imprinted_face_index)
{
    PK_AXIS2_sf_t basis_set_1;
    PK_AXIS2_sf_t basis_set_2;
    basis_set_1.axis.coord[0] = 0.0;
    basis_set_1.axis.coord[1] = 0.0;
    basis_set_1.axis.coord[2] = 1.0;
    basis_set_1.ref_direction.coord[0] = 1.0;
    basis_set_1.ref_direction.coord[1] = 0.0;
    basis_set_1.ref_direction.coord[2] = 0.0;
    MOVE3(box_pos_target, basis_set_1.location.coord);
    MOVE3(box_pos_tool, basis_set_2.location.coord);
    MOVE3(basis_set_1.axis.coord, basis_set_2.axis.coord);
    MOVE3(basis_set_1.ref_direction.coord, basis_set_2.ref_direction.coord);

    PK_FACE_t* faces;
    int n_faces;
    PK_FACE_t targetFace;
    PK_FACE_t toolFace;
    PK_BODY_t toolBody;

    /* Making Box 1 */
    PK_BODY_create_solid_block(box_size_target[0], box_size_target[1], box_size_target[2], &basis_set_1, &obox);
    PK_BODY_ask_faces(obox, &n_faces, &faces);
    targetFace = faces[face_index_target];

    /* Making Box 2 */
    PK_BODY_create_solid_block(box_size_tool[0], box_size_tool[1], box_size_tool[2], &basis_set_2, &toolBody);
    PK_BODY_ask_faces(toolBody, &n_faces, &faces);
    toolFace = faces[face_index_tool];

    /* Imprint face */
    imprintFace(targetFace, toolFace);

    /* Copy face */
    PK_BODY_ask_faces(obox, &n_faces, &faces);
    targetFace = faces[imprinted_face_index];
    PK_FACE_make_sheet_body(1, &targetFace, &oface);

    PK_BODY_boolean_o_t bool_opts;
    PK_TOPOL_track_r_t tracking;
    PK_BODY_set_type_o_t type_opts;
    PK_boolean_match_o_t match_opts;
    PK_boolean_r_t results;
    PK_BODY_boolean_o_m(bool_opts);
    PK_boolean_match_o_m(match_opts);
    match_opts.match_style = PK_boolean_match_style_auto_c;
    bool_opts.matched_region = &match_opts;
    bool_opts.merge_in_solid = PK_LOGICAL_false;
    bool_opts.merge_in_face = PK_LOGICAL_false;

    bool_opts.function = PK_boolean_subtract_c;
    // bool_opts.function = PK_boolean_unite_c;
    bool_opts.tool_material_side = PK_boolean_material_inside_c;
    PK_BODY_set_type(obox, PK_BODY_type_sheet_c, &type_opts);
    PK_BODY_boolean_2(obox, 1, &toolBody, &bool_opts, &tracking, &results);
    PK_TOPOL_track_r_f(&tracking);
    PK_boolean_r_f(&results);
}

int
main(int argc, char* argv[])
{
    /* Parasolid interface definitions */
    PK_FACE_t* faces;
    PK_ERROR_t err = PK_ERROR_no_errors;
    PK_PART_receive_o_t receive_opts;
    PK_TOPOL_facet_2_o_t facet_options = makefacet_options();
    PK_GEOM_range_vector_o_t options;
    PK_range_result_t range_result;
    PK_range_1_r_t range;

    PK_AXIS2_sf_t basis_set;
    PK_BODY_t body[8];
    PK_FACE_t targetFace;

    /* Custom Parasolid Definitions */
    PK_SESSION_set_general_topology(PK_LOGICAL_true);
    basis_set.location.coord[0] = 0.0;
    basis_set.location.coord[1] = 0.0;
    basis_set.location.coord[2] = 0.0;
    basis_set.axis.coord[0] = 0.0;
    basis_set.axis.coord[1] = 0.0;
    basis_set.axis.coord[2] = 1.0;
    basis_set.ref_direction.coord[0] = 1.0;
    basis_set.ref_direction.coord[1] = 0.0;
    basis_set.ref_direction.coord[2] = 0.0;

    /* set default Parasolid point projection options */
    PK_GEOM_range_vector_o_m(options);

    /* Initialize Parasolid engine */
    parasolid_Init();
    Vdouble box_size_1[3] = {1.0, 0.5, 1.5};
    Vdouble box_pos_1[3] = {0.0, 0.0, 0.0};

    Vdouble box_size_2[3] = {1.0, 1.0, 0.5};
    Vdouble box_pos_2[3] = {1.0, 0.0, 0.0};

    /* Create first openbox body[0] and its lid body[1] */
    makeOpenBoxAndFacet(box_size_1, box_pos_1, 5, box_size_2, box_pos_2, 2, body[0], body[1], 6);
    /* Create second openbox body[2] and its lid body[3], this lid is not used */
    makeOpenBoxAndFacet(box_size_2, box_pos_2, 2, box_size_1, box_pos_1, 5, body[2], body[3], 0);

    /* Invert sense of the faces, note that the body[1] is common for both connects */
    /* However, facets in body[1] should face backwards when building the second connect */
    int invert_sense_1[2] = {0, 0};
    int invert_sense_2[2] = {1, 0};

    /* Configuring the parts to mesh */
    Vint nparts = 2;
    /* Using body[0] && body[1] */
    vis_Connect* connect = meshParasolidParts(&body[0], invert_sense_1, nparts, &facet_options, &options, &range_result, &range);
    /* Using body[1] && body[2] */
    vis_Connect* connect_2 =
    meshParasolidParts(&body[1], invert_sense_2, nparts, &facet_options, &options, &range_result, &range);
    /* Merge the two tet connects */
    vis_ConnectAppend(connect, connect_2);
    vis_ConnectEnd(connect_2);
    mergeCoincidentNodes(connect, 1e-6);
    /* Initialize DevTools objects */

    /* report total number of generate nodes and elements */
    MeshSize connectsize;
    vis_ConnectNumber(connect, SYS_NODE, &connectsize.nodes);
    vis_ConnectNumber(connect, SYS_ELEM, &connectsize.elements);
    printf("total number of nodes= %d\n", connectsize.nodes);
    printf("total number of elems= %d\n", connectsize.elements);
    /* optional write of final mesh */
    if (connectsize.nodes && connectsize.elements) {
        vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "PK_CSAM_bridge.bdf");
    }

    vis_ConnectEnd(connect);
    /* stop Parasolid engine */
    parasolid_Term();
}
