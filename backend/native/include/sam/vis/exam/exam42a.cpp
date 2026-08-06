#include <math.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* a simple 5 sided unit cube */
static Vdouble xc[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                           {0., 0., 1.}, {1., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}};

/* extrusion directions for each node */
/* these will be scaled to desired
   boundary layer thickness */
static Vdouble vn[8][3] = {{1., 1., 1.}, {-1., 1., 1.}, {1., -1., 1.}, {-1., -1., 1.},
                           {1., 1., 0.}, {-1., 1., 0.}, {1., -1., 0.}, {-1., -1., 0.}};

static Vint tris[10][3] = {{1, 5, 3}, {3, 5, 7}, {4, 6, 2}, {8, 6, 4}, {1, 2, 5},
                           {5, 2, 6}, {7, 4, 3}, {8, 4, 7}, {1, 4, 2}, {4, 1, 3}};

/*----------------------------------------------------------------------
         Generate an Extruded Mesh along Normals
----------------------------------------------------------------------*/
int
main()
{
    Vint i, j;
    msh_ExtMesh* extmesh;
    vis_Connect* connect;
    Vdouble mag, layersize;
    Vdouble normal[8][3];
    Vint numnp, numel;
    Vdouble x[3];
    Vint nix, ix[6], aid;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* perform extrusion meshing */
    /* set normal length to layer size of 0.25 */
    layersize = .25;
    for (i = 0; i < 8; ++i) {
        mag = sqrt(vn[i][0] * vn[i][0] + vn[i][1] * vn[i][1] + vn[i][2] * vn[i][2]);
        mag = layersize / mag;
        normal[i][0] = mag * vn[i][0];
        normal[i][1] = mag * vn[i][1];
        normal[i][2] = mag * vn[i][2];
    }
    /* create ExtMesh object */
    extmesh = msh_ExtMeshBegin();
    /* 8 input nodes, 10 input triangles */
    msh_ExtMeshDef(extmesh, 8, 10);

    /* enter starting surface and normals */
    for (i = 1; i <= 8; ++i) {
        msh_ExtMeshSetNode(extmesh, i, xc[i - 1]);
        msh_ExtMeshSetNodeNormal(extmesh, i, normal[i - 1]);
    }
    for (i = 1; i <= 10; ++i) {
        msh_ExtMeshSetElem(extmesh, i, SYS_SHAPETRI, 2, 0, tris[i - 1]);
    }
    /* set mesh parameters */
    msh_ExtMeshSetParami(extmesh, EXTMESH_NORMAL, SYS_ON);
    msh_ExtMeshSetParamd(extmesh, VIS_MESH_GROWTHRATE, 2.);
    msh_ExtMeshSetParami(extmesh, EXTMESH_LOCALRECEDE, SYS_ON);
    msh_ExtMeshSetNormalPath(extmesh, 4, 1., SYS_OFF);
    /* the normals are pointing in the opposite direction
       to the connectivity sense of the surface triangles */
    msh_ExtMeshSetParami(extmesh, EXTMESH_REVERSE, SYS_ON);
    /* mark faces on original layer with value of 1
       and faces on final layer with value of 2 */
    msh_ExtMeshSetParami(extmesh, EXTMESH_FACEMARK, VIS_GEOFACE);

    /* create Connect object and generate */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);
    msh_ExtMeshGenerate(extmesh, connect);

    /* print generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("numnp= %d, numel= %d\n", numnp, numel);
    /* print node information */
    printf("Node information\n");
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, (Vdouble(*)[3])x);
        printf("id= %d  x= %e, y= %e, z= %e\n", i, x[0], x[1], x[2]);
    }
    /* print element information */
    printf("Element information\n");
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemNode(connect, i, &nix, ix);
        printf("id= %d  ix= %d %d %d %d %d %d\n", i, ix[0], ix[1], ix[2], ix[3], ix[4], ix[5]);
        for (j = 1; j <= 5; j++) {
            vis_ConnectElemEntAssoc(connect, VIS_GEOFACE, SYS_FACE, i, j, &aid);
            if (aid == 1) {
                printf("element face= %d on original face\n", j);
            }
            else if (aid == 2) {
                printf("element face= %d on final face\n", j);
            }
        }
    }
    /* write generated mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam42a.bdf");

    vis_ConnectEnd(connect);
    msh_ExtMeshEnd(extmesh);
    return 0;
}
