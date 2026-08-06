#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

/*----------------------------------------------------------------------
                      Draw Displacement Restraints Using Glyph
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_Glyph* glyph;
    GLWin* glwin;

    int i;
    Vfloat c[3], x[3], v[3];
    Vfloat l, r, h, off, hatchoff, hatchh;
    Vint head;
    Vfloat xstg[3] = {-1.5, 1.5, 0.};

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
    vis_VisContextSetRefinement(vc, 0);
    vis_VisContextSetShade(vc, VIS_VERTEXSHADE);

    /* create glyph object and set objects */
    glyph = vis_GlyphBegin();
    vis_GlyphSetObject(glyph, VGL_DRAWFUN, df);
    vis_GlyphSetObject(glyph, VIS_VISCONTEXT, vc);

    /* draw in light blue */
    c[0] = 0.6f;
    c[1] = 0.6f;
    c[2] = 1.0f;
    vgl_DrawFunColor(df, c);

    /* orient z' direction of arrow along x axis */
    v[0] = 1.f;
    v[1] = 0.;
    v[2] = 0.;
    vis_GlyphSetOrientZ(glyph, v);
    /* arrow tip at 0.,0.,0. */
    x[0] = 0.;
    x[1] = 0.;
    x[2] = 0.;
    /* length of restraint arrow */
    l = 1.5;
    /* make radius of arrow head .125 of length */
    r = .125F * l;
    /* make height of arrow head equal to twice the radius */
    h = 2.F * r;
    /* do not offset arrow head from tip */
    off = 0.;
    /* use 1 headed arrow for displacment restraint */
    head = 1;
    /* set hatch mark offset .75 of arrow length back from tip */
    hatchoff = -.75F * l;

    /* translational restraint using planar (x',z') arrow */
    for (i = 0; i < 19; i++) {
        GLWinClear(glwin);
        vgl_DrawFunText(df, xstg, (Vchar*)"Planar head, wireframe tail");
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, -i * 10.F, 'y');
        /* draw 2D arrow with tail, filled, normal style, capped */
        vis_GlyphArrow2D(glyph, x, l, r, h, off, head, VIS_ON, VIS_ON, VIS_OFF, VIS_ON);
        /* add hatch mark in x' direction only */
        vis_GlyphTriaxis(glyph, x, h, 0., 0., hatchoff);

        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }

    /* translational restraint using mixed arrow */
    for (i = 0; i < 19; i++) {
        GLWinClear(glwin);
        vgl_DrawFunText(df, xstg, (Vchar*)"Tetrahedral head, wireframe tail");
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, -i * 10.F, 'y');
        /* draw mixed 2D,3D arrow */
        vis_GlyphArrow2D3D(glyph, x, l, r, h, off, head, VIS_ON, VIS_ON, VIS_OFF, VIS_ON);
        /* add hatch mark in x' and y' directions */
        vis_GlyphTriaxis(glyph, x, h, h, 0., hatchoff);

        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }

    /* use 2 headed arrow for rotation restraint */
    head = 2;
    /* thin hatch mark disk */
    hatchh = .025F * l;
    /* use higher refinement with circular glyphs */
    vis_VisContextSetRefinement(vc, 2);

    /* illustrate rotational restraint using 3D arrow */
    for (i = 0; i < 19; i++) {
        GLWinClear(glwin);
        vgl_DrawFunText(df, xstg, (Vchar*)"Conical head, cylindrical tail");
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, -i * 10.F, 'y');
        /* draw 3D arrow with tail, filled, normal style, capped */
        vis_GlyphArrow3D(glyph, x, l, r, h, off, head, VIS_ON, VIS_ON, VIS_OFF, VIS_ON);
        /* add hatch mark as thin disk */
        vis_GlyphDisk(glyph, x, r, hatchh, hatchoff, VIS_ON);

        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(2);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_GlyphEnd(glyph);
    GLWinEnd(glwin);
    return 0;
}
