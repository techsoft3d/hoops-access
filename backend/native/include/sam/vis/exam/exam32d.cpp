#include <stdio.h>
#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

/*----------------------------------------------------------------------
                      Draw Analytic Surfaces using ASurf and Glyph
----------------------------------------------------------------------*/
int
main()
{
    Vint i, j;
    vsy_HashTable* ht;
    vis_ASurf* asurf;
    Vfloat x[3], r, cg[3], xtxt[3], ctxt[3];
    Vfloat a[3], b[3], c[3], length, width;
    Vfloat xp[3], yp[3];
    Vfloat xs[4][3], xy[3][2];
    Vint type, id, segtype;
    Vint ix[3], numpnt, numseg;

    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_Glyph* glyph;
    GLWin* glwin;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create HashTable to hold ASurf objects */
    ht = vsy_HashTableBegin();
    /* create ASurf object for a sphere */
    asurf = vis_ASurfBegin();
    vis_ASurfDef(asurf, ASURF_SPHERE);
    x[0] = 0.;
    x[1] = 1.;
    x[2] = 1.;
    r = 2.;
    vis_ASurfSetSphere(asurf, x, r);
    vsy_HashTableInsert(ht, 10, asurf);
    /* create ASurf object for a plane */
    asurf = vis_ASurfBegin();
    vis_ASurfDef(asurf, ASURF_PLANE);
    a[0] = 0.;
    a[1] = 0.;
    a[2] = 0.;
    b[0] = 1.;
    b[1] = 0.;
    b[2] = 0.;
    c[0] = 0.;
    c[1] = 1.;
    c[2] = 0.;
    length = 3.;
    width = 4.;
    vis_ASurfSetPlane(asurf, a, b, c, length, width);
    vsy_HashTableInsert(ht, 20, asurf);
    /* create ASurf object for a surface of revolution */
    asurf = vis_ASurfBegin();
    vis_ASurfDef(asurf, ASURF_SEGMENT_REV);
    /* set local coordinate system */
    a[0] = 0.;
    a[1] = 0.;
    a[2] = 0.;
    b[0] = 1.;
    b[1] = 0.;
    b[2] = 0.;
    c[0] = 0.;
    c[1] = 1.;
    c[2] = 0.;
    vis_ASurfSetSegmentRev(asurf, a, b, c);
    /* points assumed in local x-z plane for revolve */
    /* set points */
    x[0] = 2.;
    x[1] = 0.;
    x[2] = 0.;
    vis_ASurfSetPoint(asurf, 1, x);
    x[0] = 2.;
    x[1] = 2.;
    x[2] = 0.;
    vis_ASurfSetPoint(asurf, 2, x);
    x[0] = 1.;
    x[1] = 3.;
    x[2] = 0.;
    vis_ASurfSetPoint(asurf, 3, x);
    /* circle center */
    x[0] = 1.;
    x[1] = 2.;
    x[2] = 0.;
    vis_ASurfSetPoint(asurf, 4, x);
    /* set segments */
    ix[0] = 1;
    ix[1] = 2;
    vis_ASurfSetSegment(asurf, 1, ASURF_SEG_LINE, ix);
    ix[0] = 2;
    ix[1] = 4;
    ix[2] = 3;
    vis_ASurfSetSegment(asurf, 2, ASURF_SEG_ARC, ix);
    vsy_HashTableInsert(ht, 30, asurf);

    /* now draw */
    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 800, 800);
    GLWinOrtho(glwin, -4., 4., -4., 4., -4., 4.);

    /* create drawing function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetRefinement(vc, 2);
    vis_VisContextSetShade(vc, VIS_VERTEXSHADE);

    /* create glyph object and set objects */
    glyph = vis_GlyphBegin();
    vis_GlyphSetObject(glyph, VGL_DRAWFUN, df);
    vis_GlyphSetObject(glyph, VIS_VISCONTEXT, vc);

    GLWinXfmPush(glwin);
    GLWinRotate(glwin, 30., 'x');
    GLWinRotate(glwin, 60., 'y');

    /* loop through HashTable */
    vsy_HashTableInitIter(ht);
    while (vsy_HashTableNextIter(ht, &id, (Vobject**)&asurf), asurf) {
        GLWinClear(glwin);
        /* set glyph color to magenta */
        cg[0] = 1.;
        cg[1] = 0.;
        cg[2] = 1.;
        /* set text color to white */
        ctxt[0] = 1.;
        ctxt[1] = 1.;
        ctxt[2] = 1.;
        xtxt[0] = -1.;
        xtxt[1] = 3.5;
        xtxt[2] = 0.;
        vis_ASurfInq(asurf, &type);
        if (type == ASURF_SPHERE) {
            vis_ASurfGetSphere(asurf, x, &r);
            vgl_DrawFunColor(df, ctxt);
            vgl_DrawFunText(df, xtxt, (Vchar*)"Sphere");
            vgl_DrawFunColor(df, cg);
            vis_GlyphSphere(glyph, x, r, VIS_ON);
        }
        else if (type == ASURF_PLANE) {
            vis_ASurfGetPlane(asurf, a, b, c, &length, &width);
            /* orient glyph */
            xp[0] = b[0] - a[0];
            xp[1] = b[1] - a[1];
            xp[2] = b[2] - a[2];
            yp[0] = c[0] - a[0];
            yp[1] = c[1] - a[1];
            yp[2] = c[2] - a[2];
            vis_GlyphSetOrientXY(glyph, xp, yp);
            vgl_DrawFunColor(df, ctxt);
            vgl_DrawFunText(df, xtxt, (Vchar*)"Plane");
            vgl_DrawFunColor(df, cg);
            vis_GlyphRectangle(glyph, a, length, width, 0., VIS_ON);
        }
        else if (type == ASURF_SEGMENT_REV) {
            vis_ASurfNumPoints(asurf, &numpnt);
            vis_ASurfNumSegments(asurf, &numseg);
            vis_ASurfGetSegmentRev(asurf, a, b, c);
            for (i = 1; i <= numpnt; i++) {
                vis_ASurfGetPoint(asurf, i, xs[i - 1]);
            }
            /* orient glyph */
            xp[0] = b[0] - a[0];
            xp[1] = b[1] - a[1];
            xp[2] = b[2] - a[2];
            yp[0] = c[0] - a[0];
            yp[1] = c[1] - a[1];
            yp[2] = c[2] - a[2];
            vis_GlyphSetOrientXY(glyph, xp, yp);
            vgl_DrawFunColor(df, ctxt);
            vgl_DrawFunText(df, xtxt, (Vchar*)"Segment Revolve");
            vgl_DrawFunColor(df, cg);
            for (i = 1; i <= numseg; i++) {
                vis_ASurfGetSegment(asurf, i, &segtype, ix);
                if (segtype == ASURF_SEG_LINE) {
                    for (j = 0; j < 2; j++) {
                        xy[j][0] = xs[ix[j] - 1][0];
                        xy[j][1] = xs[ix[j] - 1][1];
                    }
                    vis_GlyphSegmentRev(glyph, a, 360., GLYPH_SEG_LINE, xy);
                }
                else if (segtype == ASURF_SEG_ARC) {
                    printf(" seg arc,  id= %d, ix= %d %d %d\n", i, ix[0], ix[1], ix[2]);
                    for (j = 0; j < 3; j++) {
                        xy[j][0] = xs[ix[j] - 1][0];
                        xy[j][1] = xs[ix[j] - 1][1];
                    }
                    vis_GlyphSegmentRev(glyph, a, 360., GLYPH_SEG_ARC, xy);
                }
            }
        }
        GLWinSwap(glwin);
        sleep(2);
    }
    /* end objects */
    vsy_HashTableForEach(ht, (void (*)(void*))vis_ASurfEnd);
    vsy_HashTableEnd(ht);

    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_GlyphEnd(glyph);
    GLWinEnd(glwin);

    return 0;
}
