#include <math.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Computational Features of Edge, Face, Cell
----------------------------------------------------------------------*/
int
main()
{
    Vint i, j, k, n;
    vis_Edge* edge;
    vis_Face* face;
    vis_Cell* cell;
    Vint nix;
    Vfloat r[4], rs[16][2], rst[64][3];
    Vfloat radin, dr, ang, da, z, dz, mag, rad;
    Vfloat x[64][3];
    Vfloat v[64][3], g[3][3];
    Vfloat rc[3], vc[3], xc[3];
    /* generate cononical tet structure of nodes */
    /* radin 10., radout = 20., height 2., ang= 45 degrees */
    /* use for edge, face, cell geometry */
    n = 0;
    radin = 10.;
    dr = (20. - 10.) / 2.;
    ang = 3.14149f / 4.f;
    da = ang / 2;
    z = 2.;
    dz = z / 2;
    for (i = 0; i < 3; i++) {
        rad = radin + i * dr;
        for (j = 0; j < 3 - i; j++) {
            for (k = 0; k < 3 - j; k++) {
                x[n][0] = rad * (Vfloat)cos(k * da);
                x[n][1] = rad * (Vfloat)sin(k * da);
                x[n][2] = j * dz;
                n += 1;
            }
        }
    }
    printf("Tet coordinates at nodes\n");
    for (i = 0; i < n; i++) {
        printf("i= %d, x= %f %f %f\n", i, x[i][0], x[i][1], x[i][2]);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create edge object */
    /* reuse first 3 nodes of tet geometry */
    edge = vis_EdgeBegin();
    /* compute natural coordinates at nodes */
    /* parabolic edge */
    vis_EdgeSetTopology(edge, VIS_SHAPELINE, 3);
    vis_EdgeRST(edge, rc, &nix, r);
    printf("Natural coordinates at center\n");
    printf("center rc= %f\n", rc[0]);
    printf("Natural coordinates at nodes\n");
    for (i = 0; i < nix; i++) {
        printf("i= %d, r= %f\n", i, r[i]);
    }
    /* edge tangents, normalized */
    vis_EdgeComputeTang(edge, x, v);
    printf("Edge normalized tangent vectors at nodes\n");
    for (i = 0; i < nix; i++) {
        printf("i= %d, v= %f %f %f\n", i, v[i][0], v[i][1], v[i][2]);
    }
    /* edge gradient tangents */
    printf("Edge tangent vectors at nodes\n");
    for (i = 0; i < nix; i++) {
        vis_EdgeTangRST(edge, x, r[i], g[0]);
        printf("i= %d, g[0]= %f %f %f\n", i, g[0][0], g[0][1], g[0][2]);
    }
    /* interpolate coordinates to center */
    vis_EdgeInterpolate(edge, rc[0], 3, (Vfloat*)x, xc);
    printf("Edge center coordinate\n");
    printf("center xc= %f %f %f\n", xc[0], xc[1], xc[2]);

    vis_EdgeEnd(edge);

    /* create face object */
    /* reuse first 6 nodes of tet geometry */
    face = vis_FaceBegin();
    /* compute natural coordinates at nodes */
    /* parabolic, Lagrange triangle */
    vis_FaceSetTopology(face, VIS_SHAPETRI, 3, 3);
    vis_FaceRST(face, rc, &nix, rs);
    printf("Natural coordinates at center\n");
    printf("center rc= %f %f\n", rc[0], rc[1]);
    printf("Natural coordinates at nodes\n");
    for (i = 0; i < nix; i++) {
        printf("i= %d, rs= %f %f\n", i, rs[i][0], rs[i][1]);
    }
    /* face normals */
    vis_FaceComputeNorm(face, x, v);
    printf("Face normal vectors at nodes\n");
    for (i = 0; i < nix; i++) {
        printf("i= %d, v= %f %f %f\n", i, v[i][0], v[i][1], v[i][2]);
    }
    /* face tangents */
    printf("Face gradient tangent vectors at nodes\n");
    for (i = 0; i < nix; i++) {
        vis_FaceTangRST(face, x, rs[i], g);
        printf("i= %d, g[0]= %f %f %f, g[1]= %f %f %f\n", i, g[0][0], g[0][1], g[0][2], g[1][0], g[1][1], g[1][2]);
    }
    /* interpolate normal to center */
    vis_FaceInterpolate(face, rc, 3, (Vfloat*)v, vc);
    printf("Face center normal vector\n");
    /* normalize */
    mag = (Vfloat)sqrt(vc[0] * vc[0] + vc[1] * vc[1] + vc[2] * vc[2]);
    vc[0] = vc[0] / mag;
    vc[1] = vc[1] / mag;
    vc[2] = vc[2] / mag;
    printf("center v= %f %f %f\n", vc[0], vc[1], vc[2]);

    vis_FaceEnd(face);

    /* create cell object */
    cell = vis_CellBegin();
    /* compute natural coordinates at nodes */
    /* parabolic, Lagrange tet */
    vis_CellSetTopology(cell, VIS_SHAPETET, 3, 3, 3);
    vis_CellRST(cell, rc, &nix, rst);
    printf("Natural coordinates at center\n");
    printf("center rc= %f %f\n", rc[0], rc[1]);
    printf("Natural coordinates at nodes\n");
    for (i = 0; i < nix; i++) {
        printf("i= %d, rst= %f %f %f\n", i, rst[i][0], rst[i][1], rst[i][2]);
    }
    /* cell tangents */
    printf("Cell gradient tangent vectors at nodes\n");
    for (i = 0; i < nix; i++) {
        vis_CellTangRST(cell, x, rst[i], g);
        printf("i= %d, g[0]= %f %f %f, g[1]= %f %f %f, g[2]= %f %f %f\n", i, g[0][0], g[0][1], g[0][2], g[1][0], g[1][1], g[1][2],
               g[2][0], g[2][1], g[2][2]);
    }
    /* interpolate coordinates to center */
    vis_CellInterpolate(cell, rc, 3, (Vfloat*)x, xc);
    printf("Cell center coordinate\n");
    printf("center xc= %f %f %f\n", xc[0], xc[1], xc[2]);

    vis_CellEnd(cell);

    return 0;
}
