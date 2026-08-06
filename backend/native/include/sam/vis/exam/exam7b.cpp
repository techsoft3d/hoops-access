#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat rgb[7][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Draw Segmented Glyphs
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
    Vfloat x[3], xy[3][2];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 800, 800);
    GLWinOrtho(glwin, -4., 4., -4., 4., -4., 4.);

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
        GLWinRotate(glwin, 12., 'y');

        vis_VisContextSetColor(vc, 4);
        x[0] = -1.5;
        x[1] = 1.0;
        x[2] = 0.;
        /* line, parabola, arc */
        xy[0][0] = .4f;
        xy[0][1] = .4f;
        xy[1][0] = .4f;
        xy[1][1] = .8f;
        vis_GlyphSegment(glyph, x, GLYPH_SEG_LINE, xy);
        xy[0][0] = .4f;
        xy[0][1] = .8f;
        xy[1][0] = 0.f;
        xy[1][1] = 1.2f;
        xy[2][0] = -.4f;
        xy[2][1] = .8f;
        vis_GlyphSegment(glyph, x, GLYPH_SEG_PARAB, xy);
        xy[0][0] = -.4f;
        xy[0][1] = .8f;
        xy[1][0] = 0.f;
        xy[1][1] = .8f;
        xy[2][0] = 0.f;
        xy[2][1] = .4f;
        vis_GlyphSegment(glyph, x, GLYPH_SEG_ARC, xy);
        /* rule */
        x[0] = 0.0;
        x[1] = 1.0;
        x[2] = 0.;
        vis_VisContextSetColor(vc, 5);
        xy[0][0] = .4f;
        xy[0][1] = .4f;
        xy[1][0] = .4f;
        xy[1][1] = .8f;
        vis_GlyphSegmentRule(glyph, x, .3f, .3f, GLYPH_SEG_LINE, xy);
        vis_VisContextSetColor(vc, 3);
        xy[0][0] = .4f;
        xy[0][1] = .8f;
        xy[1][0] = 0.;
        xy[1][1] = 1.2f;
        xy[2][0] = -.4f;
        xy[2][1] = .8f;
        vis_GlyphSegmentRule(glyph, x, .5, .5, GLYPH_SEG_PARAB, xy);
        vis_VisContextSetColor(vc, 2);
        xy[0][0] = -.4f;
        xy[0][1] = .8f;
        xy[1][0] = 0.;
        xy[1][1] = .8f;
        xy[2][0] = 0.;
        xy[2][1] = .4f;
        vis_GlyphSegmentRule(glyph, x, .4f, .4f, GLYPH_SEG_ARC, xy);

        /* revolve */
        x[0] = 1.0;
        x[1] = 1.0;
        x[2] = 0.;
        vis_VisContextSetColor(vc, 5);
        xy[0][0] = .5f;
        xy[0][1] = .2f;
        xy[1][0] = .7f;
        xy[1][1] = .4f;
        vis_GlyphSegmentRev(glyph, x, 90., GLYPH_SEG_LINE, xy);
        vis_VisContextSetColor(vc, 3);
        xy[0][0] = .7f;
        xy[0][1] = .4f;
        xy[1][0] = .5f;
        xy[1][1] = .6f;
        xy[2][0] = .3f;
        xy[2][1] = .4f;
        vis_GlyphSegmentRev(glyph, x, 90., GLYPH_SEG_PARAB, xy);

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
