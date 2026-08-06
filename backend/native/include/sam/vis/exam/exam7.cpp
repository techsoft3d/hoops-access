#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
#include "glwin.h"

static Vfloat rgb[7][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Generate periodic table of glyphs
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_Glyph* glyph;
    GLWin* glwin;

    int i;
    Vfloat x[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -2., 2., -2., 2., -2., 2.);

    /* create drawing function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetColor(vc, 4);
    vis_VisContextSetRefinement(vc, 0);
    vis_VisContextSetShade(vc, VIS_VERTEXSHADE);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 7, 0, rgb);

    /* create glyph object and set objects */
    glyph = vis_GlyphBegin();
    vis_GlyphSetObject(glyph, VGL_DRAWFUN, df);
    vis_GlyphSetObject(glyph, VIS_VISCONTEXT, vc);
    vis_GlyphSetObject(glyph, VIS_COLORMAP, cmap);

    /* illustrate glyphs */
    for (i = 0; i < 30; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 12.F, 'x');

        vis_VisContextSetColor(vc, 4);
        x[0] = -1.5f;
        x[1] = 1.5f;
        x[2] = 0.f;
        vis_GlyphArrow2D(glyph, x, .4f, .1f, .1f, 0.f, 1, VIS_ON, VIS_ON, 1, 1);
        x[0] = -1.0f;
        x[1] = 1.5f;
        vis_GlyphArrow3D(glyph, x, .4f, .1f, .1f, 0.f, 1, VIS_ON, 1, 0, 1);
        x[0] = -.5f;
        x[1] = 1.5f;
        vis_GlyphBox(glyph, x, .2f, .3f, .4f, VIS_ON);
        x[0] = .0f;
        x[1] = 1.5f;
        vis_GlyphCircle(glyph, x, .1f, 0.f, VIS_OFF);
        x[0] = .5f;
        x[1] = 1.5f;
        vis_GlyphCylinder(glyph, x, .1f, .4f, 0.f, 1);
        x[0] = 1.0f;
        x[1] = 1.5f;
        vis_GlyphEllipsoid(glyph, x, .2f, .4f, .6f);
        x[0] = 1.5f;
        x[1] = 1.5f;
        vis_GlyphRectangle(glyph, x, .2f, .4f, 0.f, VIS_OFF);

        vis_VisContextSetColor(vc, 5);
        x[0] = -1.5f;
        x[1] = 0.5f;
        vis_GlyphSphere(glyph, x, .2f, 1);
        x[0] = -1.0f;
        x[1] = 0.5f;
        vis_GlyphCone(glyph, x, .2f, .4f, 0.f, 1);
        x[0] = -.5f;
        x[1] = 0.5f;
        vis_GlyphTetrahedron(glyph, x, .2f, 1);
        x[0] = .0f;
        x[1] = 0.5f;
        vis_GlyphPyramid(glyph, x, .2f, .4f, .6f);
        x[0] = .5f;
        x[1] = 0.5f;
        vis_GlyphOctahedron(glyph, x, .2f, .4f, .6f, 1);
        x[0] = 1.0f;
        x[1] = 0.5f;
        vis_GlyphTriaxis(glyph, x, .2f, .4f, .6f, 0.f);
        x[0] = 1.5f;
        x[1] = 0.5f;
        vis_GlyphTriangle(glyph, x, .2f, 1);

        vis_VisContextSetColor(vc, 6);
        x[0] = -1.5f;
        x[1] = -.5f;
        vis_GlyphDiamond(glyph, x, .2f, .15f, 0);
        x[0] = -1.0f;
        x[1] = -.5f;
        vis_GlyphHourglass(glyph, x, .2f);
        x[0] = -.5f;
        x[1] = -.5f;
        vis_GlyphGround(glyph, x, .2f, 0.f, 0.f);
        x[0] = 0.f;
        x[1] = -.5f;
        vis_GlyphLine(glyph, x, .4f, 0.f);

        vis_VisContextSetColor(vc, 1);
        vis_VisContextSetRefinement(vc, 1);
        x[0] = -1.5f;
        x[1] = -1.5f;
        vis_GlyphConicalFrustum(glyph, x, .1f, .2f, .4f, 0.f, 1);
        x[0] = 0.f;
        x[1] = -1.5f;
        vis_GlyphArrow2D3D(glyph, x, 1.f, .15f, .3f, 0.f, 1, VIS_ON, 1, 0, 1);
        x[0] = .5f;
        x[1] = -1.5f;
        vis_GlyphArrow2D3D(glyph, x, 1.f, .1f, .3f, 0.f, 2, VIS_ON, 1, 1, 1);

        vis_VisContextSetColor(vc, 4);
        x[0] = 1.0f;
        x[1] = -1.5f;
        x[2] = 0.f;
        vis_GlyphCircleN(glyph, x, 3);
        x[0] = 1.2f;
        x[1] = -1.5f;
        x[2] = 0.f;
        vis_GlyphCircleN(glyph, x, 5);
        x[0] = 1.4f;
        x[1] = -1.5f;
        x[2] = 0.f;
        vis_GlyphCircleN(glyph, x, 7);
        x[0] = 1.6f;
        x[1] = -1.5f;
        x[2] = 0.f;
        vis_GlyphCircleN(glyph, x, 9);

        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(5);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_GlyphEnd(glyph);
    GLWinEnd(glwin);
    return 0;
}
