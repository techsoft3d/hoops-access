/***********************************************************************
 *                                                                      *
 *               Copyright (C) 2011, Visual Kinematics, Inc.            *
 *                                                                      *
 *  These coded inttructions, statements and computer programs contain  *
 *  unpublished proprietary information of Visual Kinematics, Inc.,     *
 *  and are protected by Federal copyright law.  They may not be        *
 *  disclosed to third parties or copied or duplicated in any form,     *
 *  in whole or in part, without the prior written consent of           *
 *  Visual Kinematics, Inc.                                             *
 *                                                                      *
 ***********************************************************************/
/*
   file       :  exam52pk.cxx
   description:  Parasolid PK file library object
   author     :  Arthur Muller
   date       :  May 5, 2011
   discussion :
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sam/base/base.h"
#include "sam/base/vututil.h"
#include "sam/vis/vis.h"
#include "sam/msh/msh.h"
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

static Vint writesurfmesh = 1;

/*----------------------------------------------------------------------
          Illustrate Parasolid x_t/x_b interface to SurfMesh
----------------------------------------------------------------------*/
int
main(int argc, char* argv[])
{
    /* DevTools interface definitions */
    msh_SurfMesh* surfmesh;
    msh_TetMesh* tetmesh;
    vsy_IntHash* nodeih;
    vsy_IntHash* vertexih;
    vis_Connect *connectsrf, *connect, *connecttet;
    vsy_IntHash *bodylih, *bodyrih, *conicih;
    vsy_IntHash* finedgeih;
    vsy_IntHash* pointvertexih;
    vsy_IntVec* faceorientiv;
    Vint nparts, geobody, geobodyrb, geobodylb;
    Vint ii, j, m, finID, finIndex, point, normalIndex, facetID, geoface;
    Vint geoedge[3], geovert[3];
    Vint length, ix[3], index;
    Vint conicid, numconic, isconic;
    Vdouble *xl, *xn, vertex[3][3], normals[3][3];
    Vdouble xo[3], axis[3], ref[3], cr, cc;
    Vint numel, numnp, eflags[3], sense;
    Vchar buffer[256];
    Vdouble minext[3], maxext[3], diaglen, edgelen;
    int n_vertices, n_regions, n_shells, isvoid, n_faces;
    double t, tang[2][3], etang[3];
    Vint ierr, tetmeshoption, nfree;
    Vchar filnam[256];

    /* Parasolid interface definitions */
    PK_PART_t* parts;
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
    PK_VERTEX_t* vertices;
    PK_REGION_t* regions;
    PK_SHELL_t* shells;
    PK_FACE_t* faces;
    PK_LOGICAL_t *orients, orientf;
    PK_ERROR_t err = PK_ERROR_no_errors;
    PK_PART_receive_o_t receive_opts;
    PK_CLASS_t eclass, sclass;
    PK_BODY_type_t bodyType;
    PK_TOPOL_facet_2_r_t tables;
    PK_TOPOL_facet_2_o_t facetOptions;
    PK_GEOM_range_vector_o_t options;
    PK_range_result_t range_result;
    PK_range_1_r_t range;
    PK_LOGICAL_t is_solid;
    PK_SURF_t surf;
    PK_CURVE_t curve;
    PK_VECTOR_t pt, tg;
    char filename[80];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s parasolid_x_t_file\n", argv[0]);
        return 0;
    }

    nparts = 0;
    parts = NULL;
    numnp = numel = 0;

    /* open Parasolid file */
    PK_PART_receive_o_m(receive_opts);
    if (strstr(argv[1], ".x_t") || strstr(argv[1], ".xmt_txt")) {
        receive_opts.transmit_format = PK_transmit_format_text_c;
    }
    else if (strstr(argv[1], ".x_b") || strstr(argv[1], ".xmt_bin")) {
        receive_opts.transmit_format = PK_transmit_format_binary_c;
    }
    else {
        fprintf(stderr, "Unknown file extension\n");
        return 1;
    }
    /* initialize Parasolid engine */
    parasolid_Init();
    /* load Parasolid parts */
    strcpy(&filename[0], argv[1]);
#ifndef _WIN32
    // In unix, frustrum.c implements FFOPRD which always expects a part with name
    // NAME.xmt_txt in disk (AKA PS_LONG_NAME) but it must be passed without the extension.
    // As such, it is necessary to remove the ".xmt_txt" from the filename
    strremove(&filename[0], ".xmt_txt");
    printf("loading file %s.xmt_txt\n", filename);
#else
    strremove(&filename[0], ".x_t");
    printf("loading file %s.x_t\n", filename);
#endif
    err = PK_PART_receive(filename, &receive_opts, &nparts, &parts);
    if (err != PK_ERROR_no_errors) {
        fprintf(stderr, "PK_PART_receive error= %d\n", err);
        return 1;
    }
    /* set default Parasolid tesselation options */
    PK_TOPOL_facet_2_o_m(facetOptions);
    /* set default Parasolid point projection options */
    PK_GEOM_range_vector_o_m(options);

    /* initialize DevTools objects */
    surfmesh = msh_SurfMeshBegin();
    tetmesh = msh_TetMeshBegin();
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vertexih = vsy_IntHashBegin();

    /* initialize tesselation choice options */
    facetOptions.choice.facet_fin = true;
    facetOptions.choice.fin_data = true;
    facetOptions.choice.data_point_idx = true;
    facetOptions.choice.data_normal_idx = true;
    facetOptions.choice.point_vec = true;
    facetOptions.choice.normal_vec = true;
    facetOptions.choice.facet_face = true;
    facetOptions.choice.fin_edge = true;
    facetOptions.choice.point_topol = true;
    facetOptions.choice.facet_fin = PK_LOGICAL_true;
    facetOptions.choice.fin_fin = PK_LOGICAL_true;
    facetOptions.choice.fin_data = PK_LOGICAL_true;
    facetOptions.choice.data_point_idx = PK_LOGICAL_true;
    facetOptions.choice.data_normal_idx = PK_LOGICAL_true;
    facetOptions.choice.point_vec = PK_LOGICAL_true;
    facetOptions.choice.normal_vec = PK_LOGICAL_true;
    facetOptions.choice.facet_face = PK_LOGICAL_true;
    facetOptions.choice.fin_edge = PK_LOGICAL_true;
    facetOptions.choice.point_topol = PK_LOGICAL_true;

    /* initialize tesselation control options */
    facetOptions.control.shape = PK_facet_shape_convex_c;
    facetOptions.control.match = PK_facet_match_topol_c;
    /*
     * The option below is used to minimize the number
     * of edge tesselation point that are not on the edge
     */
    facetOptions.control.quality = PK_facet_quality_improved_c;

    /* loop over all parts */
    for (int i = 0; i < nparts; i++) {
        PK_ENTITY_ask_class(parts[i], &eclass);
        if (eclass == PK_CLASS_body) {
            /* initialize IntHash for body to the left of face */
            bodylih = vsy_IntHashBegin();
            bodyrih = vsy_IntHashBegin();
            conicih = vsy_IntHashBegin();
            faceorientiv = vsy_IntVecBegin();
            numconic = 0;

            /* check for solid, sheet, or non-manifold body */
            PK_BODY_ask_type(parts[i], &bodyType);
            if (bodyType == PK_BODY_type_sheet_c || bodyType == PK_BODY_type_solid_c || bodyType == PK_BODY_type_general_c) {
                if (bodyType == PK_BODY_type_general_c) {
                    msh_SurfMeshSetParami(surfmesh, SURFMESH_NONMANIFOLD, SYS_ON);
                }
                else {
                    msh_SurfMeshSetParami(surfmesh, SURFMESH_NONMANIFOLD, SYS_OFF);
                }

                /* create region->face map */
                PK_BODY_ask_regions(parts[i], &n_regions, &regions);
                for (int ir = 0; ir < n_regions; ir++) {
                    /* skip non-solid regions */
                    PK_REGION_is_solid(regions[ir], &is_solid);
                    if (is_solid == false) {
                        continue;
                    }

                    PK_REGION_ask_shells(regions[ir], &n_shells, &shells);
                    /*
                     * The "isvoid" flag checks whether any face orientation
                     * points outwardly to the body. If all faces point
                     * inwardly SurfMeshGenerate will still succeed.  However,
                     * this problem needs to be accounted for when passing
                     * the surface mesh to TetMesh.
                     */
                    isvoid = 1;
                    for (int is = 0; is < n_shells; is++) {
                        PK_SHELL_ask_oriented_faces(shells[is], &n_faces, &faces, &orients);
                        for (int ifa = 0; ifa < n_faces; ifa++) {
                            if (!orients[ifa]) {
                                vsy_IntHashInsert(bodylih, faces[ifa], regions[ir]);
                                isvoid = 0;
                            }
                            else {
                                vsy_IntHashInsert(bodyrih, faces[ifa], regions[ir]);
                            }
                            PK_FACE_ask_oriented_surf(faces[ifa], &surf, &orientf);
                            PK_ENTITY_ask_class(surf, &sclass);
                            isconic = 0;
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
                                vsy_IntHashLookup(conicih, surf, &conicid);
                                if (conicid == 0) {
                                    numconic += 1;
#ifdef MESH_DEBUG
                                    printf("conicid= %d, orientf= %d\n", numconic, orientf);
#endif
                                    vsy_IntHashInsert(conicih, surf, numconic);
                                    vsy_IntVecSet(faceorientiv, numconic, orientf);
                                }
                            }
                        }
                        if (n_faces) {
                            PK_MEMORY_free(faces);
                            PK_MEMORY_free(orients);
                        }
                    }
                    if (n_shells) {
                        PK_MEMORY_free(shells);
                    }
                }
                if (n_regions) {
                    PK_MEMORY_free(regions);
                }

                /* assign part number to vertices */
                numnp = numel = 0;
                PK_BODY_ask_vertices(parts[i], &n_vertices, &vertices);
                for (j = 0; j < n_vertices; j++) {
                    vsy_IntHashInsert(vertexih, vertices[j], parts[i]);
                }
                if (n_vertices) {
                    PK_MEMORY_free(vertices);
                }
                /* tesselate part */
                err = PK_TOPOL_facet_2(1, &parts[i], NULL, &facetOptions, &tables);
                if (err != 0) {
                    fprintf(stderr, "PK_TOPOL_facet_2 error= %d\n", err);
                    return 1;
                }

                /* gather tables */
                for (j = 0; j < tables.number_of_tables; j++) {
                    if (tables.tables[j].fctab == PK_TOPOL_fctab_facet_fin_c) {
                        facet_fin = tables.tables[j].table.facet_fin;
                    }
                    else if (tables.tables[j].fctab == PK_TOPOL_fctab_fin_fin_c) {
                        fin_fin = tables.tables[j].table.fin_fin;
                    }
                    else if (tables.tables[j].fctab == PK_TOPOL_fctab_fin_data_c) {
                        fin_data = tables.tables[j].table.fin_data;
                    }
                    else if (tables.tables[j].fctab == PK_TOPOL_fctab_data_point_c) {
                        data_point_idx = tables.tables[j].table.data_point_idx;
                    }
                    else if (tables.tables[j].fctab == PK_TOPOL_fctab_data_normal_c) {
                        data_normal_idx = tables.tables[j].table.data_normal_idx;
                    }
                    else if (tables.tables[j].fctab == PK_TOPOL_fctab_point_vec_c) {
                        point_vec = tables.tables[j].table.point_vec;
                    }
                    else if (tables.tables[j].fctab == PK_TOPOL_fctab_normal_vec_c) {
                        normal_vec = tables.tables[j].table.normal_vec;
                    }
                    else if (tables.tables[j].fctab == PK_TOPOL_fctab_facet_face_c) {
                        facet_face = tables.tables[j].table.facet_face;
                    }
                    else if (tables.tables[j].fctab == PK_TOPOL_fctab_fin_edge_c) {
                        fin_edge = tables.tables[j].table.fin_edge;
                    }
                    else if (tables.tables[j].fctab == PK_TOPOL_fctab_point_topol_c) {
                        point_topol = tables.tables[j].table.point_topol;
                    }
                }
                /* initialize SurfMesh */
                msh_SurfMeshDef(surfmesh, point_vec->length, facet_fin->length / 3);

                /* set conic sections */
                vsy_IntHashInitIter(conicih);
                while (vsy_IntHashNextIter(conicih, &surf, &conicid), conicid) {
                    vsy_IntVecGet(faceorientiv, conicid, &sense);
                    if (sense == 0)
                        sense = -1;
#ifdef MESH_DEBUG
                    printf("conicid= %d\n", conicid);
#endif
                    PK_ENTITY_ask_class(surf, &sclass);
                    if (sclass == PK_CLASS_plane) {
                        PK_PLANE_sf_t plane_sf;
#ifdef MESH_DEBUG
                        printf("PK_CLASS_plane\n");
#endif
                        PK_PLANE_ask(surf, &plane_sf);
                        xo[0] = plane_sf.basis_set.location.coord[0];
                        xo[1] = plane_sf.basis_set.location.coord[1];
                        xo[2] = plane_sf.basis_set.location.coord[2];
                        axis[0] = plane_sf.basis_set.axis.coord[0];
                        axis[1] = plane_sf.basis_set.axis.coord[1];
                        axis[2] = plane_sf.basis_set.axis.coord[2];
                        ref[0] = plane_sf.basis_set.ref_direction.coord[0];
                        ref[1] = plane_sf.basis_set.ref_direction.coord[1];
                        ref[2] = plane_sf.basis_set.ref_direction.coord[2];
                        msh_SurfMeshSetConic(surfmesh, conicid, SURFMESH_CONIC_PLANE, sense, xo, axis, ref, 0., 0.);
                    }
                    else if (sclass == PK_CLASS_cyl) {
                        PK_CYL_sf_t cyl_sf;
#ifdef MESH_DEBUG
                        printf("PK_CLASS_cyl\n");
#endif
                        PK_CYL_ask(surf, &cyl_sf);
                        xo[0] = cyl_sf.basis_set.location.coord[0];
                        xo[1] = cyl_sf.basis_set.location.coord[1];
                        xo[2] = cyl_sf.basis_set.location.coord[2];
                        axis[0] = cyl_sf.basis_set.axis.coord[0];
                        axis[1] = cyl_sf.basis_set.axis.coord[1];
                        axis[2] = cyl_sf.basis_set.axis.coord[2];
                        ref[0] = cyl_sf.basis_set.ref_direction.coord[0];
                        ref[1] = cyl_sf.basis_set.ref_direction.coord[1];
                        ref[2] = cyl_sf.basis_set.ref_direction.coord[2];
                        cr = cyl_sf.radius;
                        msh_SurfMeshSetConic(surfmesh, conicid, SURFMESH_CONIC_CYLINDER, sense, xo, axis, ref, cr, 0.);
                    }
                    else if (sclass == PK_CLASS_cone) {
                        PK_CONE_sf_t cone_sf;
#ifdef MESH_DEBUG
                        printf("PK_CLASS_cone\n");
#endif
                        PK_CONE_ask(surf, &cone_sf);
                        xo[0] = cone_sf.basis_set.location.coord[0];
                        xo[1] = cone_sf.basis_set.location.coord[1];
                        xo[2] = cone_sf.basis_set.location.coord[2];
                        axis[0] = cone_sf.basis_set.axis.coord[0];
                        axis[1] = cone_sf.basis_set.axis.coord[1];
                        axis[2] = cone_sf.basis_set.axis.coord[2];
                        ref[0] = cone_sf.basis_set.ref_direction.coord[0];
                        ref[1] = cone_sf.basis_set.ref_direction.coord[1];
                        ref[2] = cone_sf.basis_set.ref_direction.coord[2];
                        cr = cone_sf.semi_angle;
                        msh_SurfMeshSetConic(surfmesh, conicid, SURFMESH_CONIC_CONE, sense, xo, axis, ref, cr, 0.);
                    }
                    else if (sclass == PK_CLASS_sphere) {
                        PK_SPHERE_sf_t sphere_sf;
#ifdef MESH_DEBUG
                        printf("PK_CLASS_sphere\n");
#endif
                        PK_SPHERE_ask(surf, &sphere_sf);
                        xo[0] = sphere_sf.basis_set.location.coord[0];
                        xo[1] = sphere_sf.basis_set.location.coord[1];
                        xo[2] = sphere_sf.basis_set.location.coord[2];
                        axis[0] = sphere_sf.basis_set.axis.coord[0];
                        axis[1] = sphere_sf.basis_set.axis.coord[1];
                        axis[2] = sphere_sf.basis_set.axis.coord[2];
                        ref[0] = sphere_sf.basis_set.ref_direction.coord[0];
                        ref[1] = sphere_sf.basis_set.ref_direction.coord[1];
                        ref[2] = sphere_sf.basis_set.ref_direction.coord[2];
                        cr = sphere_sf.radius;
                        msh_SurfMeshSetConic(surfmesh, conicid, SURFMESH_CONIC_SPHERE, sense, xo, axis, ref, cr, 0.);
                    }
                    else if (sclass == PK_CLASS_torus) {
                        PK_TORUS_sf_t torus_sf;
#ifdef MESH_DEBUG
                        printf("PK_CLASS_torus\n");
#endif
                        PK_TORUS_ask(surf, &torus_sf);
                        xo[0] = torus_sf.basis_set.location.coord[0];
                        xo[1] = torus_sf.basis_set.location.coord[1];
                        xo[2] = torus_sf.basis_set.location.coord[2];
                        axis[0] = torus_sf.basis_set.axis.coord[0];
                        axis[1] = torus_sf.basis_set.axis.coord[1];
                        axis[2] = torus_sf.basis_set.axis.coord[2];
                        ref[0] = torus_sf.basis_set.ref_direction.coord[0];
                        ref[1] = torus_sf.basis_set.ref_direction.coord[1];
                        ref[2] = torus_sf.basis_set.ref_direction.coord[2];
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
                }
                /* map fin->edge information */
                numnp = numel = 0;
                finedgeih = vsy_IntHashBegin();
                for (ii = 0; ii < fin_edge->length; ii++) {
                    vsy_IntHashInsert(finedgeih, fin_edge->data[ii].fin, fin_edge->data[ii].edge);
                }
                /* map point->vertex information */
                pointvertexih = vsy_IntHashBegin();
                for (ii = 0; ii < point_topol->length; ii++) {
                    vsy_IntHashInsert(pointvertexih, point_topol->data[ii].point + 1, point_topol->data[ii].topol);
                }
                nodeih = vsy_IntHashBegin();

                /* loop over all fins */
                length = facet_fin->length;
                j = 0;
                for (ii = 0; ii < length; ii++) {
                    finID = facet_fin->data[ii].fin;
                    finIndex = fin_data->data[finID];
                    point = data_point_idx->point[finIndex];
                    xl = point_vec->vec[point].coord;
                    vertex[j][0] = xl[0];
                    vertex[j][1] = xl[1];
                    vertex[j][2] = xl[2];
                    normalIndex = data_normal_idx->normal[finIndex];
                    xn = normal_vec->vec[normalIndex].coord;
                    facetID = facet_fin->data[ii].facet;
                    geoface = facet_face->face[facetID];
                    PK_FACE_ask_surf(geoface, &surf);
                    vsy_IntHashLookup(conicih, surf, &conicid);
                    vsy_IntHashLookup(finedgeih, finID, &geoedge[(j + 2) % 3]);
                    vsy_IntHashLookup(nodeih, point + 1, &index);

                    /* check for new node */
                    if (index == 0) {
                        index = ++numnp;

                        /* update extent */
                        if (index == 1) {
                            minext[0] = maxext[0] = vertex[j][0];
                            minext[1] = maxext[1] = vertex[j][1];
                            minext[2] = maxext[2] = vertex[j][2];
                        }
                        else {
                            if (vertex[j][0] < minext[0])
                                minext[0] = vertex[j][0];
                            if (vertex[j][1] < minext[1])
                                minext[1] = vertex[j][1];
                            if (vertex[j][2] < minext[2])
                                minext[2] = vertex[j][2];
                            if (vertex[j][0] > maxext[0])
                                maxext[0] = vertex[j][0];
                            if (vertex[j][1] > maxext[1])
                                maxext[1] = vertex[j][1];
                            if (vertex[j][2] > maxext[2])
                                maxext[2] = vertex[j][2];
                        }
                        vsy_IntHashInsert(nodeih, point + 1, index);

                        /*
                         * Check whether node is on edge/vertex, or interior
                         * to a surface.
                         */
                        vsy_IntHashLookup(pointvertexih, point + 1, &geovert[j]);
                        vsy_IntHashLookup(vertexih, geovert[j], &geobody);
                        if (geobody) {
                            msh_SurfMeshSetPoint(surfmesh, index, vertex[j], 1);
                            msh_SurfMeshSetPointAssoc(surfmesh, VIS_GEOVERT, index, geovert[j]);
                        }
                        else {
                            msh_SurfMeshSetPoint(surfmesh, index, vertex[j], 0);
                        }
                    }
                    normals[j][0] = xn[0];
                    normals[j][1] = xn[1];
                    normals[j][2] = xn[2];
                    ix[j] = index;
                    ++j;
                    /* every 3 fins => completed triangle */
                    if (j == 3) {
                        ++numel;

                        /* gather edge information */
                        for (m = 1; m <= 3; m++) {
                            eflags[m - 1] = 0;
                            if (geoedge[m - 1]) {
                                eflags[m - 1] = 1;
                            }
                        }
                        /* insert triangle, its associations, and normals */
                        msh_SurfMeshSetTri(surfmesh, numel, ix, eflags);
                        msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOFACE, numel, SYS_FACE, 0, geoface);
                        vsy_IntHashLookup(bodylih, geoface, &geobodyrb);
                        vsy_IntHashLookup(bodyrih, geoface, &geobodylb);
                        msh_SurfMeshSetTriBack(surfmesh, numel, geobodyrb, geobodylb);
                        if (geobodyrb) {
                            msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, numel, SYS_ELEM, 0, geobodyrb);
                            msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, numel, SYS_ELEM, 0, geobodyrb);
                        }
                        if (geobodylb) {
                            msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, numel, SYS_ELEM, -1, geobodylb);
                            msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, numel, SYS_ELEM, -1, geobodylb);
                        }
                        msh_SurfMeshSetTriNorm(surfmesh, numel, normals);
                        if (conicid) {
                            msh_SurfMeshSetTriConic(surfmesh, numel, conicid);
                        }
                        /* compute edge tangents for geometry edges */
                        for (m = 1; m <= 3; m++) {
                            if (geoedge[m - 1]) {
                                /* assign edge association */
                                msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOEDGE, numel, SYS_EDGE, m, geoedge[m - 1]);

                                /* compute parameter "t" on curve */
                                etang[0] = vertex[m % 3][0] - vertex[m - 1][0];
                                etang[1] = vertex[m % 3][1] - vertex[m - 1][1];
                                etang[2] = vertex[m % 3][2] - vertex[m - 1][2];
                                PK_EDGE_ask_curve(geoedge[m - 1], &curve);

                                /* first point on edge */
                                pt.coord[0] = vertex[m - 1][0];
                                pt.coord[1] = vertex[m - 1][1];
                                pt.coord[2] = vertex[m - 1][2];
                                err = PK_CURVE_parameterise_vector(curve, pt, &t);

                                /*
                                 * An error indicates that the point, although
                                 * supposedly on the edge, was placed away from the
                                 * during the tesselation. We then try to find
                                 * a point on the edge that is as close as possible
                                 * to the tesselation point
                                 */
                                if (err != 0) {
                                    err = PK_GEOM_range_vector(curve, pt, &options, &range_result, &range);
                                    if (err) {
                                        printf("Unable to project point to curve, err= %d\n", err);
                                        continue;
                                    }
                                    t = range.end.parameters[0];
                                }
                                PK_CURVE_eval_with_tangent(curve, t, 0, &pt, &tg);

                                /* make sure tangent is aligned with edge direction */
                                tang[0][0] = tg.coord[0];
                                tang[0][1] = tg.coord[1];
                                tang[0][2] = tg.coord[2];
                                if (tang[0][0] * etang[0] + tang[0][1] * etang[1] + tang[0][2] * etang[2] < 0.) {
                                    tang[0][0] = -tang[0][0];
                                    tang[0][1] = -tang[0][1];
                                    tang[0][2] = -tang[0][2];
                                }

                                /* likewise, second point on edge */
                                pt.coord[0] = vertex[m % 3][0];
                                pt.coord[1] = vertex[m % 3][1];
                                pt.coord[2] = vertex[m % 3][2];
                                err = PK_CURVE_parameterise_vector(curve, pt, &t);
                                if (err != 0) {
                                    err = PK_GEOM_range_vector(curve, pt, &options, &range_result, &range);
                                    if (err) {
                                        printf("Unable to project point to curve, err= %d\n", err);
                                        continue;
                                    }
                                    t = range.end.parameters[0];
                                }

                                PK_CURVE_eval_with_tangent(curve, t, 0, &pt, &tg);
                                tang[1][0] = tg.coord[0];
                                tang[1][1] = tg.coord[1];
                                tang[1][2] = tg.coord[2];
                                if (tang[1][0] * etang[0] + tang[1][1] * etang[1] + tang[1][2] * etang[2] < 0.) {
                                    tang[1][0] = -tang[1][0];
                                    tang[1][1] = -tang[1][1];
                                    tang[1][2] = -tang[1][2];
                                }

                                /* set tangents */
                                msh_SurfMeshSetTriTang(surfmesh, numel, m, tang);
                            }
                        }
                        j = 0;
                    }
                }
                vsy_IntHashEnd(nodeih);
                vsy_IntHashEnd(finedgeih);
                vsy_IntHashEnd(conicih);
                vsy_IntHashEnd(pointvertexih);
                vsy_IntVecEnd(faceorientiv);

                /* compute extent diagonal lenth for edge length */
                diaglen =
                sqrt((maxext[0] - minext[0]) * (maxext[0] - minext[0]) + (maxext[1] - minext[1]) * (maxext[1] - minext[1]) +
                     (maxext[2] - minext[2]) * (maxext[2] - minext[2]));
                edgelen = diaglen / 20.;
                msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, edgelen);
                msh_SurfMeshSetParamd(surfmesh, VIS_MESH_SPANANGLE, 45.);

                /* generate parabolic triangles */
                msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 3);

                /* save SurfMesh file */
                if (writesurfmesh) {
                    sprintf(buffer, "exam52pk_%d.srf", parts[i]);
                    msh_SurfMeshWrite(surfmesh, SYS_ASCII, buffer);
                }

                /* generate surface mesh and write result */
                connectsrf = vis_ConnectBegin();
                vis_ConnectPre(connectsrf, SYS_DOUBLE);
                msh_SurfMeshGenerate(surfmesh, connectsrf);
                ierr = msh_SurfMeshError(surfmesh);
                if (ierr) {
                    printf("Error generating surface mesh, part= %d\n", parts[i]);
                    sprintf(filnam, "model-%d.srf", parts[i]);
                    msh_SurfMeshWrite(surfmesh, SYS_ASCII, filnam);
                    vis_ConnectEnd(connectsrf);
                    continue;
                }
                printf("SurfMesh part= %d complete\n", parts[i]);
                vis_ConnectNumber(connectsrf, SYS_NODE, &numnp);
                vis_ConnectNumber(connectsrf, SYS_ELEM, &numel);
                printf("Surface number of nodes= %d\n", numnp);
                printf("Surface number of elems= %d\n", numel);

                tetmeshoption = 1;
                /* test for no free edges */
                msh_SurfMeshGetInteger(surfmesh, SURFMESH_NUMFREEEDGE, &nfree);
                if (nfree) {
                    tetmeshoption = 0;
                }
                if (tetmeshoption) {
                    connecttet = vis_ConnectBegin();
                    vis_ConnectPre(connecttet, SYS_DOUBLE);
                    msh_TetMeshConnect(tetmesh, connectsrf);
                    msh_TetMeshSetParamd(tetmesh, VIS_MESH_EDGELENGTH, edgelen);
                    msh_TetMeshSetParamd(tetmesh, VIS_MESH_GROWTHRATE, 2.);
                    /* optional write of TetMesh contents for QA
          msh_TetMeshWrite (tetmesh,SYS_BINARY,"model1.btet");
                    */
                    msh_TetMeshGenerate(tetmesh, connecttet);
                    ierr = msh_TetMeshError(tetmesh);
                    if (ierr) {
                        printf("Error generating tet mesh, part= %d\n", parts[i]);
                        sprintf(filnam, "part_%d.btet", parts[i]);
                        msh_TetMeshWrite(tetmesh, SYS_BINARY, filnam);
                        vis_ConnectEnd(connecttet);
                        vsy_IntHashEnd(bodylih);
                        vsy_IntHashEnd(bodyrih);
                        continue;
                    }
                    printf("TetMesh part= %d complete\n", parts[i]);
                    vis_ConnectAppend(connect, connecttet);
                    vis_ConnectEnd(connecttet);
                }
                else {
                    vis_ConnectAppend(connect, connectsrf);
                }
                vis_ConnectEnd(connectsrf);
            }
            vsy_IntHashEnd(bodylih);
            vsy_IntHashEnd(bodyrih);
        }
    }
    /* report total number of generate nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("total number of nodes= %d\n", numnp);
    printf("total number of elems= %d\n", numel);
    /* optional write of final mesh */
    if (numnp && numel) {
        vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "model.bdf");
    }
    msh_SurfMeshEnd(surfmesh);
    msh_TetMeshEnd(tetmesh);
    vsy_IntHashEnd(vertexih);
    vis_ConnectEnd(connect);
    PK_MEMORY_free(parts);

    /* stop Parasolid engine */
    parasolid_Term();
}
