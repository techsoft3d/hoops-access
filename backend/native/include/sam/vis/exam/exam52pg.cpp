#include "pg/pgapi.h"
#include "/home/gordy.ferguson/projects/polygonica/src/examples/include/error.h"
#include "sam/vis/vis.h"
#include "sam/msh/msh.h"

#if PG_OS == PG_OS_UNIX
#include <string.h>
#endif

static PTStatus
report_progress(PTProgressReport prog_rep)
{
    double percent;

    if (PFEntityGetEnumProperty(prog_rep, PV_PROGRESS_PROP_OPERATION_ID) == PV_OPERATION_CREATE_STL_SOLID) {
        percent = PFEntityGetDoubleProperty(prog_rep, PV_PROGRESS_PROP_PERCENT);
        if (percent > 49.9 && percent < 50.1) {
            printf("File read %.1f%% complete\n", percent);
        }
    }
    return PV_STATUS_OK;
}

#define CHECK_FOR_ERROR(_str)          \
    if (status != PV_STATUS_OK)        \
        do {                           \
            printf(_str);              \
            if (stream)                \
                PFStreamClose(stream); \
            return PV_ENTITY_NULL;     \
    } while (1)

/* Expand a filename containing an environment variable */
static PTStatus
expand_filename(char* env_var, char* file_path, char* expanded)
{
    char* env_path = NULL;

    if (env_var == NULL || file_path == NULL || expanded == NULL || env_var[0] == 0 || file_path[0] == 0) {
        printf("Invalid path or environment variable");
        return PV_STATUS_FILE_IO;
    }

    env_path = getenv(env_var);
    if (env_path == NULL) {
        printf("Environment variable \"%s\" not found.\n", env_var);
        return PV_STATUS_FILE_IO;
    }

    strcpy(expanded, env_path);
    strcat(expanded, file_path);

    return PV_STATUS_OK;
}

static PTSolid
load_and_close_solid(PTEnvironment env, char* file_path)
{
    PTSolid solid;
    PTSolidReadOpts stl_options;
    PTStream stream = PV_ENTITY_NULL;
    PTStatus status;
    char filename[1024];

    strcpy(filename, "/home/vki/projects/polygonica/src/samples/solid6.stl");
    status = PFStreamFileOpen(filename, PV_FILE_READ, NULL, &stream);
    CHECK_FOR_ERROR("Failed to open stream\n");

    PMInitSolidReadOpts(&stl_options);
    stl_options.progress_callback = report_progress;
    status = PFSolidRead(env, PV_SOLID_DATA_STL, stream, &stl_options, &solid);
    CHECK_FOR_ERROR("Failed to load solid\n");

    if (!PFEntityGetBooleanProperty(solid, PV_SOLID_PROP_CLOSED)) {
        status = PFSolidClose(solid, NULL);
        CHECK_FOR_ERROR("Failed to close solid\n");
    }

    if (PFEntityGetBooleanProperty(solid, PV_SOLID_PROP_SELF_INTERSECTS)) {
        status = PFSolidFixSelfIntersections(solid, NULL);
        CHECK_FOR_ERROR("Failed to fix self-intersections in solid\n");
    }
    PFStreamClose(stream);

    return solid;
}

#undef CHECK_FOR_ERROR

static int numtri = 0;
static PTStatus
mesh_begin(PTPointer app_data, PTNat32 num_faces, PTNat32 num_loops, PTNat32 num_vertex_indices, PTNat32 num_vertices,
           PTNat32 vertex_array_size, PTPoint** vertices, PTPointer** vertex_app_data)
{
    PTPoint point;
    Vint n;
#define VKI
#ifdef VKI
    msh_SurfMesh* surfmesh;
    surfmesh = (msh_SurfMesh*)app_data;

    msh_SurfMeshDef(surfmesh, num_vertices, num_faces);
    for (n = 0; n < num_vertices; n++) {
        PFMeshGetVertexPosition(point, vertices, vertex_array_size, n);
        msh_SurfMeshSetPoint(surfmesh, n + 1, point, 0);
    }
#endif
    return PV_STATUS_OK;
}

static PTStatus
mesh_add_triangle(PTMeshPolygon* polygon)
{
#ifdef VKI
    msh_SurfMesh* surfmesh;
    Vint ix[3], eflags[3];
    surfmesh = (msh_SurfMesh*)polygon->options->app_data;

    numtri += 1;
    ix[0] = polygon->indices[0] + 1;
    ix[1] = polygon->indices[1] + 1;
    ix[2] = polygon->indices[2] + 1;
    eflags[0] = 0;
    eflags[1] = 0;
    eflags[2] = 0;
    msh_SurfMeshSetTri(surfmesh, numtri, ix, eflags);
    msh_SurfMeshSetTriNorm(surfmesh, numtri, (Vdouble(*)[3])polygon->normals);

    return PV_STATUS_OK;
#endif
}

static PTStatus
mesh_end(PTPointer app_data)
{
    /* Code to deal with mesh start here. */
    return PV_STATUS_OK;
}

static void
querySurfaceTopology(PTEnvironment env, PTEntityList surfaces, PTSurface surface)
{
    PTEntityGroup boundary_edges, faces;
    PTSurfaceLoop boundary;
    PTEdge edge;
    PTFace face;
    PTSurface owningSurface;
    PTEdgeFaceData edge_face_data;
    PTVertex start_vertex, end_vertex;
    //
    //  For each surface can get a list of triangles               ------  PFSurfaceGetFaces(PTSurface surface, PTEntityGroup
    //  *faces) For each triangle can find which surface it belongs to     ------  PFFaceGetSurface for each surface, can get a
    //  list of surface loops          -------  PFSurfaceGetLoops(PTSurface surface, PTEntityList *list)
    //                                                                       PTSurfaceEdge PFSurfaceLoopGetFirst(PTSurfaceLoop
    //                                                                       loop)
    //  for each surface loop can get a lists of surface edges     ------- PFSurfaceEdgeGetNext(PTSurfaceEdge edge)
    //  for each surface edge can get a list of edges              -------- PFSurface EdgeGetEdges(PTSurfaceEdge
    //  edge,PTEntityList* edges) for each edge can get the vertices                          -----   PFEdgeGetVertices(PTEdge
    //  edge, PTVertex* start_vertex, PTVertex* end_vertex) for each edge get a list of faces                           ------
    //  PFEdgeGetFaces
    //

    //
    // Get the Triangles forming the surface
    //
    int checkFaceOwner = 0;
    PFSurfaceGetFaces(surface, &faces);
    if (faces && checkFaceOwner) {
        // can also check owning surface of each faces
        for (face = PFEntityListGetFirst(faces); face; face = PFEntityListGetNext(faces, face)) {
            owningSurface = PFFaceGetSurface(face, surfaces);
        }
    }

    PTEntityList boundaries, edges;
    PFEntityGroupCreate(env, &boundary_edges);

    PFSurfaceGetLoops(surface, &boundaries);

    //
    //  Note on getting loop edges
    //
    //     PFSurfaceLoopGetEdges(boundary, &edges) - gets the triangle edges on the loop of a surface
    //     you can also get them by first getting the PTSurfaceEdge, which represents  a surface edge the triange edges which form
    //     that surface edge
    //

    if (boundaries) {
        for (boundary = PFEntityListGetFirst(boundaries); boundary; boundary = PFEntityListGetNext(boundaries, boundary)) {
            PFSurfaceLoopGetEdges(boundary, &edges);

            /* Add this edge to the group of all boundary edges */
            for (edge = PFEntityListGetFirst(edges); edge; edge = PFEntityListGetNext(edges, edge)) {
                PFEntityGroupAddEntity(boundary_edges, edge);

                //
                //  get edge information
                //
                PFEdgeGetFaces(edge, &edge_face_data);
                int num_faces = edge_face_data.num_faces;
                PTFace* edge_faces = edge_face_data.faces;

                PFEdgeGetVertices(edge, &start_vertex, &end_vertex);
            }
        }
    }
}

static PTNat32
surface_type_to_int(PTSurfaceType type)
{
    switch ((PTSurfaceType)type) {
        case PV_SURFACE_TYPE_UNKNOWN:
            return 0;
        case PV_SURFACE_TYPE_PLANE:
            return 1;
        case PV_SURFACE_TYPE_SPHERE_INSIDE:
            return 2;
        case PV_SURFACE_TYPE_SPHERE_OUTSIDE:
            return 3;
        case PV_SURFACE_TYPE_CYLINDER_INSIDE:
            return 4;
        case PV_SURFACE_TYPE_CYLINDER_OUTSIDE:
            return 5;
        case PV_SURFACE_TYPE_CONE_INSIDE:
            return 6;
        case PV_SURFACE_TYPE_CONE_OUTSIDE:
            return 7;
        case PV_SURFACE_TYPE_TORUS_INSIDE:
            return 8;
        case PV_SURFACE_TYPE_TORUS_OUTSIDE:
            return 9;
        default:
            printf("Invalid surface.\n");
            return -1;
    }
}

static void
print_surface_count(int count, PTNat32 type_count[])
{
    printf("Solid contains %d surfaces:\n", count);
    printf("   %d unknown surfaces.\n", type_count[0]);
    printf("   %d plane surfaces.\n", type_count[1]);
    printf("   %d inside sphere surfaces.\n", type_count[2]);
    printf("   %d outside sphere surfaces.\n", type_count[3]);
    printf("   %d inside cylinder surfaces.\n", type_count[4]);
    printf("   %d outside cylinder surfaces.\n", type_count[5]);
    printf("   %d inside cone surfaces.\n", type_count[6]);
    printf("   %d outside cone surfaces.\n", type_count[7]);
    printf("   %d inside torus surfaces.\n", type_count[8]);
    printf("   %d outside torus surfaces.\n", type_count[9]);
}

#define PROMPT(_str) \
    printf(_str);    \
    getchar()

#define CHECK_FOR_LICENSE_ERROR(_str)     \
    if (status != PV_STATUS_OK)           \
        do {                              \
            handle_license_error(status); \
            printf(_str);                 \
            return -1;                    \
    } while (1)

#define CHECK_FOR_ERROR(_str)              \
    if (status != PV_STATUS_OK) {          \
        do {                               \
            PROMPT(_str);                  \
            if (env)                       \
                PFEnvironmentDestroy(env); \
            PFTerminate();                 \
            return -1;                     \
        } while (1);                       \
    }

int
main(int argc, char* argv[])
{
    Vint i;
    Vint nsurf;
    PTInitialiseOpts initialise_options;
    PTEnvironment env = PV_ENTITY_NULL;
    PTSolid solid;
    PTStatus status;
    PTGetMeshOpts options;
    PTEnvironmentOpts env_options;
    PTCreateSurfaceListOpts surface_opts;
    PTEntityList surface_list, boundaries, edges;
    PTSurface surface;
    PTSurfaceDef surface_def;
    PTNat32 surface_type_count[10];
    PTEntityGroup egroup, planar_surfaces, boundary_edges;
    PTEntityList entity_list;
    PTSurfaceLoop boundary;
    PTEdge edge;
    PTFace face;

#ifdef VKI
    msh_SurfMesh* surfmesh;
#endif

    /* Initialise Polygonica */
    PMInitInitialiseOpts(&initialise_options);
    status = PFInitialise(PV_LICENSE, &initialise_options);
    CHECK_FOR_LICENSE_ERROR("Failed to initialise Polygonica\n");

    PMInitEnvironmentOpts(&env_options);
    status = PFEnvironmentCreate(&env_options, &env);
    CHECK_FOR_ERROR("Failed to create environment\n");
    /* send any diagnostic messages to the function defined in window.h to call PgWindowText() */
    PFEntitySetPointerProperty(env, PV_ENV_PROP_ERROR_REPORT_CB, simple_error_callback);

    printf("Polygonica initialised\n");

    if (!(solid = load_and_close_solid(env, "/src/samples/solid7.stl"))) {
        PFEnvironmentDestroy(env);
        PFTerminate();
        return FALSE;
    }
    printf("Solid created\n");

    PMInitCreateSurfaceListOpts(&surface_opts);
    status = PFSolidCreateSurfaceList(solid, &surface_opts, &surface_list);
    CHECK_FOR_ERROR("Unable to create surface list\n");
    printf("Surface list created\n");
    /* Reset surface type count */
    for (i = 0; i < 10; i++) {
        surface_type_count[i] = 0;
    }
    /* Create an entity group to store all boundary edges */
    PFEntityGroupCreate(env, &boundary_edges);
    printf("Boundary edges created\n");
    /* Count the different types of surface */
    nsurf = 0;
    for (surface = PFEntityListGetFirst(surface_list); surface; surface = PFEntityListGetNext(surface_list, surface)) {
        /* Get definition and boundaries */
        PFSurfaceGetDefinition(surface, &surface_def);
        querySurfaceTopology(env, surface_list, surface);

        PFSurfaceGetLoops(surface, &boundaries);
        if (boundaries) {
            for (boundary = PFEntityListGetFirst(boundaries); boundary; boundary = PFEntityListGetNext(boundaries, boundary)) {
                PFSurfaceLoopGetEdges(boundary, &edges);
                /* Add this edge to the group of all boundary edges */
                for (edge = PFEntityListGetFirst(edges); edge; edge = PFEntityListGetNext(edges, edge)) {
                    PFEntityGroupAddEntity(boundary_edges, edge);
                }
            }
        }
        surface_type_count[surface_type_to_int(surface_def.type)] += 1;
        nsurf += 1;
    }
    printf("Surface types counted, number of surfaces= %d\n", nsurf);

    /* List all the surfaces */
    print_surface_count(nsurf, surface_type_count);

    /* GHF, Peter, we need the following
    1. Associate a surface to each triangle.
    2. Associate an edge to a triangle edge
    3. Flag a vertex which lies on an edge endpoint.
    */
    /* compute normals */
    status = PFSolidSetNormals(solid, 30.);
    CHECK_FOR_ERROR("Failed to solid set normals\n");

#ifdef VKI
    surfmesh = msh_SurfMeshBegin();
#endif

    PMInitGetMeshOpts(&options);
#ifdef VKI
    options.app_data = (void*)surfmesh;
#endif
    options.begin_callback = mesh_begin;
    options.add_polygon_callback = mesh_add_triangle;
    options.end_callback = mesh_end;
    options.output_vertex_normals = TRUE;
    status = PFSolidGetMesh(solid, PV_MESH_TRIANGLES, &options);
    CHECK_FOR_ERROR("Failed to extract mesh\n");

#ifdef VKI
    msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam52pg.srf");
    msh_SurfMeshEnd(surfmesh);
#endif
    printf("Completed solid operations: Destroy environment and terminate.\n");

    /* No need to destroy the individual solids as they're        */
    /* automatically destroyed when the environment is destroyed. */
    PFEnvironmentDestroy(env);
    PFTerminate();

    return 0;
}
