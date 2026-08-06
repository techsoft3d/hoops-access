#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include <float.h>

#include "spatial_license.h"
#include "license.hxx"
#include "acis.hxx"
#include "api.hxx"
#include "ga_api.hxx"
#include "at_name.hxx"
#include "at_int.hxx"
#include "kernapi.hxx"
#include "ckoutcom.hxx"
#include "transf.hxx"
#include "transfrm.hxx"
#include "geometry.hxx"
#include "curve.hxx"
#include "curdef.hxx"
#include "body.hxx"
#include "vertex.hxx"
#include "point.hxx"
#include "coedge.hxx"
#include "edge.hxx"
#include "loop.hxx"

/* GHF
#define VKI_PROJECT_WIRES
*/
#define VKI_PROJECT_CONICS
#ifdef VKI_PROJECT_CONICS
#include "cone.hxx"
#include "sphere.hxx"
#include "torus.hxx"
#include "plane.hxx"
#include "getowner.hxx"
#endif

#include "cstrapi.hxx"
#include "af_api.hxx"
#include "LinkedMeshManager.hxx"
#include "idx_mesh.hxx"
#include "stlmmg.hxx"
#include "gmeshmg.hxx"
#include "cface.hxx"
#include "at_fcf.hxx"
#include "cell2d.hxx"
#include "cshell.hxx"
#include "intrapi.hxx"
#include "ptlist.hxx"
#include "license.hxx"
#include "spa_unlock_result.hxx"

#ifdef OLDLICENSE
extern void
unlock_spatial_products_6831();
#endif

/* SurfMesh geometry projection callback function */
void
project_surfmesh2acis(msh_SurfMesh* surfmesh, Vobject* object, Vint enttype, Vint entaid, Vdouble uh[], Vdouble xh[3],
                      Vdouble ug[], Vdouble xg[3])
{
    SPAposition pxh(xh[0], xh[1], xh[2]);
    SPAposition pxg;
    double distance;
    param_info ent_info;
    ENTITY* ent;
    outcome res;

    res = api_get_entity_from_id(--entaid, ent);
    check_outcome(res);

    res = api_entity_point_distance(ent, pxh, pxg, distance, ent_info);
    check_outcome(res);
    if (enttype == SYS_EDGE) {
        ug[0] = ent_info.t();
    }
    else if (enttype == SYS_FACE) {
        ug[0] = ent_info.uv().u;
        ug[1] = ent_info.uv().v;
    }
    xg[0] = pxg.x();
    xg[1] = pxg.y();
    xg[2] = pxg.z();
}

/* ACIS initialization function */
static void
init_acis()
{
#ifdef OLDLICENSE
    unlock_spatial_products_6831();
#endif
    check_outcome(api_start_modeller(0));
    check_outcome(api_initialize_faceter());
}

/* ACIS termination function */
static void
term_acis()
{
    api_terminate_faceter();
    api_stop_modeller();
}

static void
associate_to_cshell(CFACE* cface, tag_id_type* id)
{
    if (cface == NULL)
        return;
    if (cface->owner()->identity() == CELL2D_TYPE)
        return;

    CSHELL* cshell = (CSHELL*)cface->owner();
    CELL* cell = (CELL*)cshell->owner();
    api_get_entity_id(reinterpret_cast<ENTITY*>(cell), *id);
    *id += 1;
}

static logical
calculate_edge_tangents(EDGE* edge, SPAposition pos, Vdouble tpar, Vdouble tv[3])
{
    SPAunit_vector tang;
    SPAvector tan_vec;

    if (tpar == DBL_MAX) {
        if (same_point(pos, edge->start_pos(), SPAresabs)) {
            tpar = edge->start_param();
        }
        else if (same_point(pos, edge->end_pos(), SPAresabs)) {
            tpar = edge->end_param();
        }
        if (tpar == DBL_MAX) {
            tv[0] = 0.;
            tv[1] = 0.;
            tv[2] = 0.;
            return (0);
        }
    }
    tan_vec = edge->geometry()->equation().eval_deriv(tpar, TRUE, TRUE);
    tang = normalise(tan_vec);
    tv[0] = tang.x();
    tv[1] = tang.y();
    tv[2] = tang.z();
    return (1);
}

/* ACIS mesh manager */
class VKI_MESH_MANAGER: public GLOBAL_MESH_MANAGER {
  private:
    msh_SurfMesh* surfmesh;
    Vint tix[3];            /* triangle connectivity */
    Vdouble norms[3][3];    /* triangle node normals */
    Vdouble tangs[3][3];    /* triangle node tangents */
    Vint efl[3];            /* triangle edge flags */
    Vint reversed[3];       /* coedge direction */
    tag_id_type edge_id[3]; /* edge entity tags for triangle */
    tag_id_type face_id;    /* face entity tag for triangle */
    Vint conicid;           /* conic id */
    Vint hasconic;          /* current face has conic */
    Vint nodeind;           /* current defined point */
    Vint elemind;           /* current defined triangle */
    Vint ibody;             /* current body */
    Vint rfaceflag;
    Vint lfaceflag;
    tag_id_type rfaceid; /* back cell */
    tag_id_type lfaceid; /* front cell */

  public:
    VKI_MESH_MANAGER(msh_SurfMesh* surfMesh):
        surfmesh(surfMesh), nodeind(0), elemind(0), face_id(0), conicid(0), hasconic(0), rfaceflag(0), lfaceflag(0), rfaceid(0),
        lfaceid(0), ibody(0)
    {
    }

    virtual logical
    need_global_indexed_polygons(void)
    {
        return TRUE;
    }

    virtual logical
    need_precount_of_global_indexed_polygons(void)
    {
        return TRUE;
    }

    virtual logical
    need_coedge_pointers_on_polyedges()
    {
        return TRUE;
    }

    virtual logical
    need_indexed_polynode_with_data()
    {
        return TRUE;
    }

    virtual logical
    need_edge_indices()
    {
        return TRUE;
    }

    virtual void*
    null_node_id(void)
    {
        return (void*)-1;
    }

    virtual void*
    announce_global_node(int inode, VERTEX* ver, const SPAposition& Xi)
    {
        Vdouble x[3];
        tag_id_type id;
        /* set point coordinates */
        x[0] = Xi.x();
        x[1] = Xi.y();
        x[2] = Xi.z();
        nodeind = inode + 1;
        msh_SurfMeshSetPoint(surfmesh, nodeind, x, 1);
        /* recover and set vertex geometry tag */
        api_get_entity_id((ENTITY*)ver, id);
        /* offset by one to ensure a non-zero tag */
        id += 1;
        msh_SurfMeshSetPointAssoc(surfmesh, VIS_GEOVERT, nodeind, id);
        return ((void*)inode);
    }

    virtual void*
    announce_global_node(int inode, EDGE* mod_edge, const SPAposition& Xi, double t)
    {
        Vdouble x[3];
        /* set point coordinates */
        x[0] = Xi.x();
        x[1] = Xi.y();
        x[2] = Xi.z();
        nodeind = inode + 1;
        msh_SurfMeshSetPoint(surfmesh, nodeind, x, 0);
        return ((void*)inode);
    }

    virtual void*
    announce_global_node(int inode, FACE* mod_face, const SPAposition& Xi, const SPApar_pos& uv)
    {
        Vdouble x[3];
        /* set point coordinates */
        x[0] = Xi.x();
        x[1] = Xi.y();
        x[2] = Xi.z();
        nodeind = inode + 1;
        msh_SurfMeshSetPoint(surfmesh, nodeind, x, 0);
        return ((void*)inode);
    }

    virtual void
    announce_polygon_model_face(ENTITY* ent)
    {
        FACE* face = (FACE*)ent;
        Vint sense;
        Vdouble xo[3], ax[3], dt[3], radius, mag, angle;
        /* set geometry face tag for oncoming polygons */
        api_get_entity_id((ENTITY*)ent, face_id);
        /* offset by one to ensure a non-zero tag */
        face_id += 1;
        hasconic = 0;
        logical face_sense = (face->sense() == REVERSED);
        if (face_sense) {
            sense = -1;
        }
        else {
            sense = 1;
        }
        /* conic sections */
#ifdef VKI_PROJECT_CONICS
        {
            /* GHF */
            printf("face_id= %d\n", face_id);
            printf("sense= %d\n", sense);
            SPAtransf T = SPAtransf();
            T = get_owner_transf(face);

            if (is_conical_face(face)) {
                cone const& the_cone = (cone const&)(face->geometry()->equation());
                SPAposition the_cone_apex = the_cone.get_apex();
                ellipse ell = the_cone.base;
                SPAposition center = ell.centre;
                SPAunit_vector nor = ell.normal;
                SPAvector axis = ell.major_axis;
                Vdouble radius_ratio = ell.radius_ratio;
                Vdouble sine_angle = the_cone.sine_angle;
                /* GHF
                 */
                printf("conical face\n");
                printf("center= %e %e %e\n", center.x(), center.y(), center.z());
                printf("nor= %e %e %e\n", nor.x(), nor.y(), nor.z());
                printf("axis= %e %e %e\n", axis.x(), axis.y(), axis.z());
                printf("radius_ratio= %e\n", radius_ratio);
                printf("sine_angle= %e\n", sine_angle);
                if (radius_ratio == 1.) {
                    conicid += 1;
                    hasconic = 1;
                    xo[0] = center.x();
                    xo[1] = center.y();
                    xo[2] = center.z();
                    ax[0] = nor.x();
                    ax[1] = nor.y();
                    ax[2] = nor.z();
                    dt[0] = axis.x();
                    dt[1] = axis.y();
                    dt[2] = axis.z();
                    radius = sqrt(dt[0] * dt[0] + dt[1] * dt[1] + dt[2] * dt[2]);
                    dt[0] = dt[0] / radius;
                    dt[1] = dt[1] / radius;
                    dt[2] = dt[2] / radius;
                    if (sine_angle == 0.) {
                        msh_SurfMeshSetConic(surfmesh, conicid, SURFMESH_CONIC_CYLINDER, sense, xo, ax, dt, radius, 0.);
                    }
                    else {
                        angle = fabs(sine_angle);
                        msh_SurfMeshSetConic(surfmesh, conicid, SURFMESH_CONIC_CONE, sense, xo, ax, dt, angle, 0.);
                    }
                }
            }
            else if (is_toroidal_face(face)) {
                torus const& tor = (torus const&)(face->geometry()->equation());
                SPAposition center = tor.centre;
                SPAunit_vector normal = tor.normal;
                SPAunit_vector ref = tor.uv_oridir;
                double major_radius = tor.major_radius;
                double minor_radius = tor.minor_radius;
                /* GHF
                 */
                printf("toroidal face\n");
                conicid += 1;
                hasconic = 1;
                xo[0] = center.x();
                xo[1] = center.y();
                xo[2] = center.z();
                ax[0] = normal.x();
                ax[1] = normal.y();
                ax[2] = normal.z();
                dt[0] = ref.x();
                dt[1] = ref.y();
                dt[2] = ref.z();
                major_radius = fabs(major_radius);
                minor_radius = fabs(minor_radius);
                msh_SurfMeshSetConic(surfmesh, conicid, SURFMESH_CONIC_TORUS, sense, xo, ax, dt, minor_radius, major_radius);
            }
            else if (is_spherical_face(face)) {
                sphere* sph = (sphere*)(face->geometry()->trans_surface(T, face_sense));
                SPAposition center = sph->centre;
                SPAunit_vector normal = sph->pole_dir;
                SPAunit_vector ref = sph->uv_oridir;
                radius = sph->radius;
                /* GHF
                 */
                printf("spherical face\n");
                printf("center= %e %e %e\n", center.x(), center.y(), center.z());
                printf("normal= %e %e %e\n", normal.x(), normal.y(), normal.z());
                printf("radius= %e\n", radius);
                conicid += 1;
                hasconic = 1;
                xo[0] = center.x();
                xo[1] = center.y();
                xo[2] = center.z();
                ax[0] = normal.x();
                ax[1] = normal.y();
                ax[2] = normal.z();
                dt[0] = ref.x();
                dt[1] = ref.y();
                dt[2] = ref.z();
                radius = fabs(radius);
                msh_SurfMeshSetConic(surfmesh, conicid, SURFMESH_CONIC_SPHERE, sense, xo, ax, dt, radius, 0.);
            }
            else if (is_planar_face(face)) {
                const plane& p = (const plane&)(face->geometry()->equation());
                SPAposition pos = p.root_point;
                SPAunit_vector nor = p.normal;
                SPAvector ref = p.u_deriv;
                conicid += 1;
                hasconic = 1;
                xo[0] = pos.x();
                xo[1] = pos.y();
                xo[2] = pos.z();
                ax[0] = nor.x();
                ax[1] = nor.y();
                ax[2] = nor.z();
                dt[0] = ref.x();
                dt[1] = ref.y();
                dt[2] = ref.z();
                mag = sqrt(dt[0] * dt[0] + dt[1] * dt[1] + dt[2] * dt[2]);
                dt[0] = dt[0] / mag;
                dt[1] = dt[1] / mag;
                dt[2] = dt[2] / mag;
                msh_SurfMeshSetConic(surfmesh, conicid, SURFMESH_CONIC_PLANE, sense, xo, ax, dt, 0., 0.);
                /* GHF
                 */
                printf("planar face\n");
                printf("pos= %e %e %e\n", pos.x(), pos.y(), pos.z());
                printf("nor= %e %e %e\n", nor.x(), nor.y(), nor.z());
            }
        }
#endif
        /* determine material presense relative to face */
        rfaceflag = 1;
        lfaceflag = 0;
        if (face->sides() == DOUBLE_SIDED) {
            lfaceflag = 1;
        }

        ATTRIB_FACECFACE* att = (ATTRIB_FACECFACE*)find_attrib(face, ATTRIB_CT_TYPE, ATTRIB_FACECFACE_TYPE);
        rfaceid = lfaceid = 0;
        /* check for cellular topology information */
        if (att != NULL) {
            associate_to_cshell(att->back_cface(), &rfaceid);
            associate_to_cshell(att->front_cface(), &lfaceid);
        }
    }

    virtual void
    announce_indexed_polynode(ENTITY* ent, int ipoly, int i, void* idptr, const double& edge_tpar, const SPApar_pos& uv,
                              const SPAposition& pos, const SPAunit_vector& uvec)
    {
        EDGE* edge;
        /* entity is a COEDGE pointer */
        /* triangle edge flagged if lie on geometry edge */
        efl[i] = (ent != NULL) ? 1 : 0;
        /* set triangle normals */
        norms[i][0] = uvec.x();
        norms[i][1] = uvec.y();
        norms[i][2] = uvec.z();
        /* set ith triangle point connection */
        tix[i] = (long)idptr + 1;
        if (i == 0) {
            edge_id[0] = edge_id[1] = edge_id[2] = 0;
            reversed[0] = reversed[1] = reversed[2] = 0;
        }
        if (ent == NULL) {
            return;
        }
        /* store the coedge sense */
        reversed[i] = ((COEDGE*)ent)->sense() != FORWARD;
        /* set edge entity tag and tangent */
        edge = ((COEDGE*)(ent))->edge();
        if (edge && edge->geometry()) {
            api_get_entity_id((ENTITY*)edge, edge_id[i]);
            /* offset by one to ensure a non-zero tag */
            edge_id[i] += 1;
            calculate_edge_tangents(edge, pos, edge_tpar, tangs[i]);
        }
    }

    virtual void
    announce_counts(int numel, int numnp, int npolynode)
    {
        if (numnp == 0 || numel == 0)
            return;
        msh_SurfMeshDef(surfmesh, numnp, numel);
        ibody += 1;
        conicid = 0;
    }

    virtual void
    begin_mesh_output(ENTITY* faceted_entity, ENTITY* refine_entity, ENTITY* output_entity)
    {
    }

    virtual void*
    announce_indexed_node(int inode, const SPApar_pos& param, const SPAposition& Xi, const SPAunit_vector& normal)
    {
        Vdouble x[3];

        x[0] = Xi.x();
        x[1] = Xi.y();
        x[2] = Xi.z();
        nodeind = inode + 1;
        msh_SurfMeshSetPoint(surfmesh, nodeind, x, 0);
        return ((void*)inode);
    }

    virtual void
    end_mesh_output(ENTITY* faceted_entity, ENTITY* refine_entity, ENTITY* output_entity)
    {
    }

    virtual void
    start_indexed_polygon(int ipoly, int npolynode, int ishare)
    {
    }

    virtual void
    announce_indexed_polynode(int ipoly, int i, void* pnode)
    {
    }

    virtual void
    end_indexed_polygon(int iPoly)
    {
        int i, j, i1;
        Vdouble tv[2][3], t1;
        Vdouble x0[3], x1[3], dx[3], fl, elen;
        Vint pflag, oknorm, oktang;
        EDGE* edge;
        SPAposition ci, xi;
        double d;
        param_info ent_info;

        elemind = iPoly + 1;
        msh_SurfMeshSetTri(surfmesh, elemind, tix, efl);
        /* check for zero normal */
        /* we round to 32 bit precision to get rid of noise
           in the normal values which is inconsistent between
           successive mesh manager runs on an unchanged model */
        oknorm = 1;
        for (i = 0; i < 3; i++) {
            norms[i][0] = (float)norms[i][0];
            norms[i][1] = (float)norms[i][1];
            norms[i][2] = (float)norms[i][2];
            fl = norms[i][0] * norms[i][0] + norms[i][1] * norms[i][1] + norms[i][2] * norms[i][2];
            if (fl == 0.) {
                oknorm = 0;
                break;
            }
        }
        if (oknorm) {
            msh_SurfMeshSetTriNorm(surfmesh, elemind, norms);
        }
        /* tag for nodes generated on geometry edge */
        /* compute edge tangents along triangle edge */
        for (i = 0; i < 3; i++) {
            if (edge_id[i]) {
                msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOEDGE, elemind, SYS_EDGE, i + 1, edge_id[i]);
                msh_SurfMeshGetPoint(surfmesh, tix[i], x0, &pflag);
                tv[0][0] = tangs[i][0];
                tv[0][1] = tangs[i][1];
                tv[0][2] = tangs[i][2];
                i1 = (i + 1) % 3;
                msh_SurfMeshGetPoint(surfmesh, tix[i1], x1, &pflag);
                api_get_entity_from_id(edge_id[i] - 1, (ENTITY*&)edge);
                xi.set_x(x1[0]);
                xi.set_y(x1[1]);
                xi.set_z(x1[2]);
                api_entity_point_distance((ENTITY*)edge, xi, ci, d, ent_info);
                if (ent_info.entity_type() == ent_is_vertex) {
                    t1 = reversed[i] ? edge->start_param() : edge->end_param();
                    if (edge->sense() == REVERSED) {
                        t1 = -t1;
                    }
                }
                else {
                    t1 = ent_info.t();
                }
                calculate_edge_tangents(edge, xi, t1, tv[1]);
                /* align tangents with element connectivity */
                dx[0] = x1[0] - x0[0];
                dx[1] = x1[1] - x0[1];
                dx[2] = x1[2] - x0[2];
                elen = sqrt(dx[0] * dx[0] + dx[1] * dx[1] + dx[2] * dx[2]);
                if (elen != 0.) {
                    dx[0] /= elen;
                    dx[1] /= elen;
                    dx[2] /= elen;
                }
                oktang = 1;
                for (j = 0; j < 2; j++) {
                    fl = dx[0] * tv[j][0] + dx[1] * tv[j][1] + dx[2] * tv[j][2];
                    if (fl < 0.) {
                        tv[j][0] *= -1.;
                        tv[j][1] *= -1.;
                        tv[j][2] *= -1.;
                    }
                    if (fabs(fl) < .5) {
                        oktang = 0;
                        break;
                    }
                }
                if (oktang) {
                    msh_SurfMeshSetTriTang(surfmesh, elemind, i + 1, tv);
                }
            }
        }
        /* tag for nodes and elements generated on geometry face */
        if (face_id) {
            msh_SurfMeshSetTriBack(surfmesh, elemind, rfaceflag, lfaceflag);
            if (rfaceid) {
                msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, elemind, SYS_ELEM, 0, rfaceid);
                /* add VIS_PROPID for NASTRAN bulk data file export */
                msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, elemind, SYS_ELEM, 0, rfaceid);
            }
            if (lfaceid) {
                msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOBODY, elemind, SYS_ELEM, -1, lfaceid);
                /* add VIS_PROPID for NASTRAN bulk data file export */
                msh_SurfMeshSetTriAssoc(surfmesh, VIS_PROPID, elemind, SYS_ELEM, -1, lfaceid);
            }
            msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOFACE, elemind, SYS_FACE, 0, face_id);
            if (hasconic) {
                msh_SurfMeshSetTriConic(surfmesh, elemind, conicid);
            }
        }
    }
};

static void
process_wires(ENTITY_LIST* wires, msh_CurvMesh* curvmesh)
{
    bool again;
    Vint numnp, numel, ix[2], index;
    Vdouble x[3];
    vsy_IntHash* nodeih;
    tag_id_type id, start_tag, end_tag;

    nodeih = vsy_IntHashBegin();
    numnp = numel = 0;
    if (wires->count()) {
        WIRE* wire = (WIRE*)wires->first();
        while (wire) {
            if (wire->cont() == ALL_INSIDE) {
                ENTITY_LIST edges;
                check_outcome(api_get_edges(wire, edges));
                if (edges.count()) {
                    EDGE* edge = (EDGE*)edges.first();
                    while (edge) {
                        api_get_entity_id((ENTITY*)edge, id);
                        id += 1;
                        VERTEX* start = edge->start();
                        VERTEX* end = edge->end();
                        /* get entity tags and offset by 1 */
                        api_get_entity_id((ENTITY*)start, start_tag);
                        start_tag += 1;
                        api_get_entity_id((ENTITY*)end, end_tag);
                        end_tag += 1;

                        AF_POINT* de0;
                        AF_POINT* deN;
                        AF_POINT* de;
                        if (AF_POINT::find(edge, edge->sense(), de0, deN)) {
                            Vdouble ts[2][3];
                            de = de0;
                            again = true;
                            do {
                                double t = de->get_parameter();
                                SPAposition p = de->get_position();
                                x[0] = p.x();
                                x[1] = p.y();
                                x[2] = p.z();
                                SPAvector tan_vec = edge->geometry()->equation().eval_deriv(t, TRUE, TRUE);
                                SPAunit_vector tang = normalise(tan_vec);
                                if (de == de0) {
                                    ts[0][0] = tang.x();
                                    ts[0][1] = tang.y();
                                    ts[0][2] = tang.z();
                                    vsy_IntHashLookup(nodeih, start_tag, &index);
                                    if (index == 0) {
                                        index = ++numnp;
                                        vsy_IntHashInsert(nodeih, start_tag, index);
                                        msh_CurvMeshSetPoint(curvmesh, index, x, 1);
                                        msh_CurvMeshSetPointAssoc(curvmesh, VIS_GEOVERT, index, start_tag);
                                    }
                                    ix[0] = index;
                                }
                                else if (de == deN) {
                                    vsy_IntHashLookup(nodeih, end_tag, &index);
                                    if (index == 0) {
                                        index = ++numnp;
                                        vsy_IntHashInsert(nodeih, end_tag, index);
                                        msh_CurvMeshSetPoint(curvmesh, index, x, 1);
                                        msh_CurvMeshSetPointAssoc(curvmesh, VIS_GEOVERT, index, end_tag);
                                    }
                                    again = false;
                                    ix[1] = index;
                                    ++numel;
                                    msh_CurvMeshSetLine(curvmesh, numel, ix);
                                    ts[1][0] = tang.x();
                                    ts[1][1] = tang.y();
                                    ts[1][2] = tang.z();
                                    msh_CurvMeshSetLineTang(curvmesh, numel, ts);
                                    msh_CurvMeshSetLineAssoc(curvmesh, VIS_GEOEDGE, numel, id);
                                    /* save information for next point */
                                    ix[0] = ix[1];
                                    ts[0][0] = ts[1][0];
                                    ts[0][1] = ts[1][1];
                                    ts[0][2] = ts[1][2];
                                }
                                else {
                                    index = ++numnp;
                                    msh_CurvMeshSetPoint(curvmesh, index, x, 1);
                                    ix[1] = index;
                                    ++numel;
                                    msh_CurvMeshSetLine(curvmesh, numel, ix);
                                    ts[1][0] = tang.x();
                                    ts[1][1] = tang.y();
                                    ts[1][2] = tang.z();
                                    msh_CurvMeshSetLineTang(curvmesh, numel, ts);
                                    msh_CurvMeshSetLineAssoc(curvmesh, VIS_GEOEDGE, numel, id);
                                    /* save information for next point */
                                    ix[0] = ix[1];
                                    ts[0][0] = ts[1][0];
                                    ts[0][1] = ts[1][1];
                                    ts[0][2] = ts[1][2];
                                }
                                de = de->next(0);
                            } while (again);
                        }
                        edge = (EDGE*)edges.next();
                    }
                }
            }
            wire = (WIRE*)wires->next();
        }
    }
    vsy_IntHashEnd(nodeih);
}

static void
count_wire_ents(ENTITY_LIST* wires, Vint* numnodes, Vint* numsegs)
{
    bool again;
    Vint numnp, numel, index;
    vsy_IntHash* nodeih;
    tag_id_type start_tag, end_tag;

    *numnodes = *numsegs = 0;
    numnp = numel = 0;
    nodeih = vsy_IntHashBegin();
    if (wires->count()) {
        WIRE* wire = (WIRE*)wires->first();
        while (wire) {
            if (wire->cont() == ALL_INSIDE) {
                ENTITY_LIST edges;
                check_outcome(api_get_edges(wire, edges));
                if (edges.count()) {
                    EDGE* edge = (EDGE*)edges.first();
                    while (edge) {
                        VERTEX* start = edge->start();
                        VERTEX* end = edge->end();
                        /* get entity tags and offset by 1 */
                        api_get_entity_id((ENTITY*)start, start_tag);
                        start_tag += 1;
                        api_get_entity_id((ENTITY*)end, end_tag);
                        end_tag += 1;

                        AF_POINT* de0;
                        AF_POINT* deN;
                        AF_POINT* de;
                        if (AF_POINT::find(edge, edge->sense(), de0, deN)) {
                            de = de0;
                            again = true;
                            do {
                                if (de == de0) {
                                    vsy_IntHashLookup(nodeih, start_tag, &index);
                                    if (index == 0) {
                                        index = ++numnp;
                                        vsy_IntHashInsert(nodeih, start_tag, index);
                                    }
                                }
                                else if (de == deN) {
                                    vsy_IntHashLookup(nodeih, end_tag, &index);
                                    if (index == 0) {
                                        index = ++numnp;
                                        vsy_IntHashInsert(nodeih, end_tag, index);
                                    }
                                    again = false;
                                    ++numel;
                                }
                                else {
                                    ++numnp;
                                    ++numel;
                                }
                                de = de->next(0);
                            } while (again);
                        }
                        edge = (EDGE*)edges.next();
                    }
                }
            }
            wire = (WIRE*)wires->next();
        }
    }
    vsy_IntHashEnd(nodeih);
    *numnodes = numnp;
    *numsegs = numel;
}

/*----------------------------------------------------------------------
                      Illustrate ACIS Interface to CurvMesh, SurfMesh and TetMesh
----------------------------------------------------------------------*/
int
main(int argc, char* argv[])
{
    ENTITY_LIST ents;
    ENTITY* ent;
    vis_Connect* connect;
    vis_Connect* connectsrf;
    vis_Connect* connecttet;
    vis_Connect* connectcrv;
    msh_SurfMesh* surfmesh;
    msh_TetMesh* tetmesh;
    msh_CurvMesh* curvmesh;
    outcome res;
    Vint maxi;
    Vint numpnts, numtris;
    Vint i;
    Vint numnp, numel;
    Vint pflag;
    Vint nfree;
    Vdouble diaglen, edgelen;
    Vdouble minext[3], maxext[3];
    Vdouble x[3];
    FILE* fsat;
    REFINEMENT* ref;
    int enttype;
    Vint ibody;
    Vint ierr;
    Vchar filnam[256];
    Vint tetmeshoption;
    Vint numwirepnts, numwiresegs;

    if (argc < 2) {
        printf("Usage: %s acis_sat_file\n", argv[0]);
        return 0;
    }
    /*
     * function to call in order to unlock the spatial products.
     * SPATIAL_LICENSE is defined in spatial_license.h and points to the license key string.
     */
    spa_unlock_result out = spa_unlock_products(SPATIAL_LICENSE);
    if (out.get_state() != SPA_UNLOCK_PASS && out.get_state() != SPA_UNLOCK_PASS_WARN) {
        printf("%s\n", out.get_message_text());
        return 0;
    }
    /* initialize ACIS */
    init_acis();
    /* open ACIS sat file */
    fsat = acis_fopen(argv[1], "r");
    if (fsat == NULL) {
        printf("Unable to open sat file %s\n", argv[1]);
        return -1;
    }
    /* GHF */
    printf("acis_fopen\n");
    /* restore the entities within */
    res = api_restore_entity_list(fsat, TRUE, ents);
    check_outcome(res);
    /* GHF */
    printf("api_restore_entity_list\n");
    /* ACIS sat file */
    acis_fclose(fsat);
    /* GHF */
    printf("acis_fclose\n");
    /* create a refinement object */
    res = api_create_refinement(ref);
    /* GHF */
    printf("A api_create_refinement\n");
    check_outcome(res);
    /* GHF */
    printf("B api_create_refinement\n");
    /* a normal tolerance of 15 degrees */
    API_BEGIN
    ref->set_normal_tol(15);
    API_END

    EXCEPTION_BEGIN
    MESH_MANAGER* old_MM = NULL;
    MESH_MANAGER* MM = NULL;

    EXCEPTION_TRY

    /* instance surface mesher and tet mesher objects */
    surfmesh = msh_SurfMeshBegin();
    tetmesh = msh_TetMeshBegin();
    /* instance Connect object to hold resultant mesh */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);

    check_outcome(api_get_mesh_manager(old_MM));

    /* create and install VKI mesh manager */
    MM = ACIS_NEW VKI_MESH_MANAGER(surfmesh);
    res = api_set_mesh_manager(MM);
    check_outcome(res);
    /* mesh each body separately */
    ibody = 0;
    for (ents.init(); (ent = ents.next());) {
        ibody += 1;
#ifdef VKI_PROJECT_WIRES
        ENTITY_LIST wires;
#endif
        /* use no-op block to rollback body transformation */
        API_NOP_BEGIN
        api_change_body_trans((BODY*)ent, NULL);
        enttype = ent->identity();
        res = api_set_entity_refinement(ent, ref, FALSE);
        check_outcome(res);
        /* facet entity */
        res = api_facet_entity(ent);
        check_outcome(res);

        /* wire entity */
#ifdef VKI_PROJECT_WIRES
        res = api_get_wires(ent, wires);
        check_outcome(res);
        count_wire_ents(&wires, &numwirepnts, &numwiresegs);
        if (numwirepnts && numwiresegs) {
            curvmesh = msh_CurvMeshBegin();
            msh_CurvMeshDef(curvmesh, numwirepnts, numwiresegs);
            process_wires(&wires, curvmesh);
        }
#endif
        API_NOP_END
        check_outcome(result);

        /* find extent of object to set a reasonable element size */
        msh_SurfMeshInq(surfmesh, &numpnts, &numtris);
        if (numpnts == 0 || numtris == 0)
            continue;
        printf(" Tesselation number of points= %d\n", numpnts);
        printf(" Tesselation number of tris=   %d\n", numtris);
        for (i = 1; i <= numpnts; i++) {
            msh_SurfMeshGetPoint(surfmesh, i, x, &pflag);
            if (i == 1) {
                minext[0] = maxext[0] = x[0];
                minext[1] = maxext[1] = x[1];
                minext[2] = maxext[2] = x[2];
            }
            else {
                if (x[0] < minext[0])
                    minext[0] = x[0];
                if (x[1] < minext[1])
                    minext[1] = x[1];
                if (x[2] < minext[2])
                    minext[2] = x[2];
                if (x[0] > maxext[0])
                    maxext[0] = x[0];
                if (x[1] > maxext[1])
                    maxext[1] = x[1];
                if (x[2] > maxext[2])
                    maxext[2] = x[2];
            }
        }
        diaglen = sqrt((maxext[0] - minext[0]) * (maxext[0] - minext[0]) + (maxext[1] - minext[1]) * (maxext[1] - minext[1]) +
                       (maxext[2] - minext[2]) * (maxext[2] - minext[2]));
        /* set element size to 10% of diagonal of extent box */
        edgelen = diaglen / 10.;
        msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, edgelen);
        maxi = 3;

        /* generate CurvMesh */
#ifdef VKI_PROJECT_WIRES
        if (numwirepnts && numwiresegs) {
            msh_CurvMeshSetParami(curvmesh, VIS_MESH_MAXI, maxi);
            msh_CurvMeshSetParamd(curvmesh, VIS_MESH_EDGELENGTH, edgelen);
            connectcrv = vis_ConnectBegin();
            vis_ConnectDef(connectcrv, 0, 0);
            vis_ConnectPre(connectcrv, SYS_DOUBLE);
            /* optional write of CurvMesh contents for QA
  sprintf(filnam,"exam52acis%d.crv",ibody);
  msh_CurvMeshWrite (curvmesh,SYS_ASCII,filnam);
            */
            msh_CurvMeshGenerate(curvmesh, connectcrv);
            msh_CurvMeshEnd(curvmesh);

            /* vertices and elements are now those in the generated mesh */
            vis_ConnectNumber(connectcrv, SYS_NODE, &numwirepnts);
            vis_ConnectNumber(connectcrv, SYS_ELEM, &numwiresegs);
            /* optional write of mesh
  sprintf(filnam,"model-crv%d.unv",ibody);
  vis_ConnectWrite (connectcrv, SYS_SDRC_UNIVERSAL,filnam);
            */
        }
#endif

        msh_SurfMeshSetParamd(surfmesh, VIS_MESH_MINEDGELENGTH, .01 * edgelen);
        msh_SurfMeshSetParamd(surfmesh, VIS_MESH_GROWTHRATE, 2.);
        msh_SurfMeshSetParamd(surfmesh, VIS_MESH_SPANANGLE, 30.);
        /* generate parabolic triangles */
        msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, maxi);
        /* enable non-manifold geometries */
        msh_SurfMeshSetParami(surfmesh, SURFMESH_NONMANIFOLD, SYS_ON);
        /* double backed triangulation for internal surfaces */
        msh_SurfMeshSetParami(surfmesh, SURFMESH_INTSURFBACK, SYS_ON);

        connectsrf = vis_ConnectBegin();
        vis_ConnectDef(connectsrf, 0, 0);
        vis_ConnectPre(connectsrf, SYS_DOUBLE);
        /* set exact geometry projection callback
msh_SurfMeshSetFunction (surfmesh,SURFMESH_FUN_GEOPROJ,
                    (Vfunc*)project_surfmesh2acis,NULL);
        */
        /* optional write of SurfMesh contents for QA
         */
        sprintf(filnam, "exam52acis%d.srf", ibody);
        msh_SurfMeshWrite(surfmesh, SYS_ASCII, filnam);
        msh_SurfMeshGenerate(surfmesh, connectsrf);
        ierr = msh_SurfMeshError(surfmesh);
        if (ierr) {
            printf("Error generating surface mesh, body= %d\n", ibody);
            sprintf(filnam, "model-%d.srf", ibody);
            msh_SurfMeshWrite(surfmesh, SYS_ASCII, filnam);
            continue;
        }
        /* add curve mesh to surface mesh */
#ifdef VKI_PROJECT_WIRES
        if (numwirepnts && numwiresegs) {
            vis_ConnectAppend(connectsrf, connectcrv);
            vis_ConnectMerge(connectsrf, NULL);
            vis_ConnectEnd(connectcrv);
        }
#endif
        printf("SurfMesh body= %d complete\n", ibody);
        vis_ConnectNumber(connectsrf, SYS_NODE, &numnp);
        vis_ConnectNumber(connectsrf, SYS_ELEM, &numel);
        printf(" Surface number of nodes= %d\n", numnp);
        printf(" Surface number of elems= %d\n", numel);
        /* optional write of surface mesh
sprintf(filnam,"model-srf%d.bdf",ibody);
vis_ConnectWrite (connectsrf,SYS_NASTRAN_BULKDATA,filnam);
        */

        tetmeshoption = 0;
        /* test for no free edges */
        msh_SurfMeshGetInteger(surfmesh, SURFMESH_NUMFREEEDGE, &nfree);
        if (nfree) {
            tetmeshoption = 0;
        }
        if (tetmeshoption) {
            connecttet = vis_ConnectBegin();
            vis_ConnectPre(connecttet, SYS_DOUBLE);

            /* add surface mesh information to tetmesh */
            msh_TetMeshConnect(tetmesh, connectsrf);

            msh_TetMeshSetParamd(tetmesh, VIS_MESH_EDGELENGTH, edgelen);
            msh_TetMeshSetParamd(tetmesh, VIS_MESH_GROWTHRATE, 2.);
            /* optional write of TetMesh contents for QA
  sprintf(filnam,"model_%d.btet",ibody);
  msh_TetMeshWrite (tetmesh,SYS_BINARY,filnam);
            */
            msh_TetMeshGenerate(tetmesh, connecttet);
            ierr = msh_TetMeshError(tetmesh);
            if (ierr) {
                printf("Error generating tet mesh, volume= %d\n", ibody);
                sprintf(filnam, "model_%d.btet", ibody);
                msh_TetMeshWrite(tetmesh, SYS_BINARY, filnam);
                vis_ConnectEnd(connecttet);
                continue;
            }
            printf("TetMesh body= %d complete\n", ibody);
            vis_ConnectNumber(connecttet, SYS_NODE, &numnp);
            vis_ConnectNumber(connecttet, SYS_ELEM, &numel);
            printf(" Volume number of nodes= %d\n", numnp);
            printf(" Volume number of elems= %d\n", numel);
            /* optional write of volume mesh
  sprintf(filnam,"model-tet%d.bdf",ibody);
  vis_ConnectWrite (connecttet,SYS_NASTRAN_BULKDATA,filnam);
            */
            vis_ConnectAppend(connect, connecttet);
            vis_ConnectEnd(connecttet);
        }
        else {
            vis_ConnectAppend(connect, connectsrf);
        }
    }
    /* report total number of generate nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("total number of nodes= %d\n", numnp);
    printf("total number of elems= %d\n", numel);
    /* optional write of final mesh */
    if (numnp && numel) {
        vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "model-tet.bdf");
        vis_ConnectWrite(connect, SYS_SDRC_UNIVERSAL, "model-tet.unv");
    }
    /* clean up */
    msh_SurfMeshEnd(surfmesh);
    msh_TetMeshEnd(tetmesh);
    vis_ConnectEnd(connect);

    ref->lose();

    EXCEPTION_CATCH_TRUE
    api_set_mesh_manager(old_MM);
    ACIS_DELETE MM;
    EXCEPTION_END
    /* final cleanup */
    res = api_del_entity_list(ents);
    check_outcome(res);
    term_acis();
    return 0;
}
