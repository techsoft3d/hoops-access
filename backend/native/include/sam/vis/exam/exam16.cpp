#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "glwin.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_PTS 50

static Vfloat rgb[7][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

static Vfloat frnt_norm[3] = {0.0, 0.0, 1.0};
static Vfloat back_norm[3] = {0.0, 0.0, -1.0};

void
create_outline(Vint* p_n, Vfloat outline[][2]);
void
draw_solid(vgl_DrawFun* df, Vint n, Vfloat outline[][2], Vfloat zf, Vfloat zb);

/*----------------------------------------------------------------------
                      Generate dimension annotation for a solid
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    GLWin* glwin;

    Vint i, n;
    Vfloat outline[MAX_PTS][2];
    Vfloat view_mat[4][4];
    Vfloat zf, zb;
    vis_Dimension* dimension;
    Vfloat up[3], right[3];
    Vfloat x[3], xl[3], xlabel[3], xcenter[3];

    Vfloat text_size = 0.35f;
    Vfloat arrow_size = 1.5f;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 600, 600);
    GLWinOrtho(glwin, -14., 14., -14., 14., -14., 14.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 16, 0, rgb);
    vis_ColorMapValueDrawFun(cmap, df, 1);

    /* create solid outline */
    create_outline(&n, outline);
    zf = 2.5;
    zb = -2.5;
    /* dimension */
    dimension = vis_DimensionBegin();
    vis_DimensionSetObject(dimension, VGL_DRAWFUN, df);
    vis_DimensionSetObject(dimension, VIS_COLORMAP, cmap);
    vis_DimensionSetObject(dimension, VIS_VISCONTEXT, vc);

    right[0] = 1.0;
    right[1] = 0.0;
    right[2] = 0.0;
    up[0] = 0.0;
    up[1] = 1.0;
    up[2] = 0.0;
    vis_DimensionSetPlane(dimension, right, up);

    vis_VisContextSetColor(vc, 2);
    vis_VisContextSetSize(vc, text_size);
    vis_VisContextSetMinorSize(vc, arrow_size);
    vis_VisContextSetMinorColor(vc, 4);
    vis_VisContextSetFlags(vc, VIS_BACKPLANEFLIP);

    /* draw solid with dimensions */
    for (i = 0; i < 36; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 10.F, 'y');
        GLWinXfmGet(glwin, view_mat);
        vis_VisContextSetXfmMatrix(vc, view_mat);
        vis_ColorMapValueDrawFun(cmap, df, 1);
        draw_solid(df, n, outline, zf, zb);

        vis_VisContextSetVectorType(vc, VIS_VECTORLINE);
        vis_VisContextSetMinorColor(vc, 4);
        vis_VisContextSetLineWidth(vc, 1);

        /* linear vertical dimension */
        x[0] = -5.0;
        x[1] = -5.0;
        x[2] = zf;
        xl[0] = -5.0;
        xl[1] = 0.0;
        xl[2] = zf;
        xlabel[0] = -7.0;
        xlabel[1] = 0.0;
        xlabel[2] = zf;
        vis_DimensionSetParami(dimension, DIMENSION_LABEL_ALIGN, DIMENSION_HORIZONTAL);
        vis_DimensionSetParami(dimension, DIMENSION_LINEAR_ALIGN, DIMENSION_VERTICAL);
        vis_DimensionLinear(dimension, x, xl, xlabel, (Vchar*)"5");

        /* linear horizontal dimension */
        x[0] = 0.0;
        x[1] = 5.0;
        x[2] = zf;
        xl[0] = 5.0;
        xl[1] = 5.0;
        xl[2] = zf;
        xlabel[0] = 4.0;
        xlabel[1] = 7.0;
        xlabel[2] = zf;
        vis_DimensionSetParami(dimension, DIMENSION_LINEAR_ALIGN, DIMENSION_HORIZONTAL);
        vis_DimensionLinear(dimension, x, xl, xlabel, (Vchar*)"5.0");

        /* linear aligned dimension */
        x[0] = -5.0;
        x[1] = 0.0;
        x[2] = zf;
        xl[0] = 0.0;
        xl[1] = 5.0;
        xl[2] = zf;
        xlabel[0] = -5.0;
        xlabel[1] = 5.0;
        xlabel[2] = zf;
        vis_DimensionSetParami(dimension, DIMENSION_LABEL_ALIGN, DIMENSION_ALIGNED);
        vis_DimensionSetParami(dimension, DIMENSION_LINEAR_ALIGN, DIMENSION_ALIGNED);
        vis_DimensionLinear(dimension, x, xl, xlabel, (Vchar*)"7.071");

        /* radius leader dimension */
        x[0] = 1.465f;
        x[1] = -1.465f;
        x[2] = zf;
        xcenter[0] = 5.0;
        xcenter[1] = -5.0;
        xcenter[2] = zf;
        xlabel[0] = 8.0;
        xlabel[1] = -6.0;
        xlabel[2] = zf;
        vis_DimensionRadius(dimension, x, xcenter, xlabel, (Vchar*)"5.0");

        /* angular dimension */
        x[0] = 5.0;
        x[1] = 0.0;
        x[2] = zb;
        xl[0] = 0.0;
        xl[1] = -5.0;
        xl[2] = zb;
        xcenter[0] = 5.0;
        xcenter[1] = -5.0;
        xcenter[2] = zb;
        xlabel[0] = 3.0;
        xlabel[1] = -3.0;
        xlabel[2] = zb;
        vis_DimensionSetParami(dimension, DIMENSION_LABEL_ALIGN, DIMENSION_ORTHOGONAL);
        vis_VisContextSetMinorLineStyle(vc, VIS_DASHDASH);
        vis_DimensionAngular(dimension, x, xl, xcenter, xlabel, (Vchar*)"90 deg");
        vis_VisContextSetMinorLineStyle(vc, VIS_SOLID);

        /* leader dimension */
        vis_VisContextSetVectorType(vc, VIS_VECTORUMBRELLA);
        vis_VisContextSetMinorColor(vc, 6);
        vis_VisContextSetLineWidth(vc, 2);
        x[0] = 5.0;
        x[1] = 2.5;
        x[2] = 0.;
        xlabel[0] = 7.0;
        xlabel[1] = 4.0;
        xlabel[2] = 0.;
        vis_DimensionLeader(dimension, x, xlabel, (Vchar*)"Contact Surface");

        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }

    sleep(2);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_DimensionEnd(dimension);
    GLWinEnd(glwin);
    return 0;
}

void
create_outline(Vint* p_n, Vfloat outline[][2])
{
    Vint n, i, num_div;
    Vfloat r, begin_a, end_a, pi;
    Vfloat t, dt, cx, cy;

    /* Create an outline of a solid */
    n = 0;
    outline[n][0] = -5.0;
    outline[n++][1] = -5.0;
    outline[n][0] = -5.0;
    outline[n++][1] = 0.0;
    outline[n][0] = 0.0;
    outline[n++][1] = 5.0;
    outline[n][0] = 5.0;
    outline[n++][1] = 5.0;
    outline[n][0] = 5.0;
    outline[n++][1] = 0.0;

    r = 5.0;
    num_div = 30;
    pi = 4.0F * (Vfloat)atan(1.0);
    begin_a = pi / 2.0F;
    end_a = pi;
    cx = 5.0;
    cy = -5.0;
    dt = (end_a - begin_a) / (Vfloat)num_div;
    t = begin_a + dt;

    for (i = 0; i < num_div; i++) {
        outline[n][0] = cx + r * (Vfloat)cos(t);
        outline[n++][1] = cy + r * (Vfloat)sin(t);
        t += dt;
    }

    *p_n = n;
}

void
draw_solid(vgl_DrawFun* df, Vint n, Vfloat outline[][2], Vfloat zf, Vfloat zb)
{
    Vint j, k, p, q;
    Vfloat pts[4][3];
    Vfloat nx, ny, nz, norm[3], mag;

    /* Draw a solid extruded from an outline */
    for (j = 0; j < n; j++) {
        k = j + 1;
        if (k >= n) {
            k = 0;
        }

        pts[0][0] = outline[j][0];
        pts[0][1] = outline[j][1];
        pts[0][2] = zf;
        pts[1][0] = outline[k][0];
        pts[1][1] = outline[k][1];
        pts[1][2] = zf;
        pts[2][0] = 0.0;
        pts[2][1] = 0.0;
        pts[2][2] = zf;
        vgl_DrawFunPolygon(df, VGL_POLYGON, 3, pts, VGL_FLATSHADE, frnt_norm);

        pts[0][2] = zb;
        pts[1][2] = zb;
        pts[2][2] = zb;
        vgl_DrawFunPolygon(df, VGL_POLYGON, 3, pts, VGL_FLATSHADE, back_norm);

        pts[0][2] = zf;
        pts[1][2] = zf;
        pts[2][0] = outline[k][0];
        pts[2][1] = outline[k][1];
        pts[2][2] = zb;
        pts[3][0] = outline[j][0];
        pts[3][1] = outline[j][1];
        pts[3][2] = zb;
        nx = ny = nz = 0.0;

        for (p = 0; p < 4; p++) {
            if (p == 3) {
                q = 0;
            }
            else {
                q = p + 1;
            }

            nx += pts[q][1] * pts[p][2] - pts[q][2] * pts[p][1];
            ny += pts[q][2] * pts[p][0] - pts[q][0] * pts[p][2];
            nz += pts[q][0] * pts[p][1] - pts[q][1] * pts[p][0];
        }

        mag = (Vfloat)sqrt(nx * nx + ny * ny + nz * nz);
        norm[0] = nx / mag;
        norm[1] = ny / mag;
        norm[2] = nz / mag;
        vgl_DrawFunPolygon(df, VGL_POLYGON, 4, pts, VGL_FLATSHADE, norm);
    }
}
