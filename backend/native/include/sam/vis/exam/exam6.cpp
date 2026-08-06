#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat rgb[7][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Generate stroked fonts
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_Font* font;
    GLWin* glwin;

    int i;
    Vfloat x[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 100, 100, 800, 400);
    GLWinOrtho(glwin, -2., 6., -2., 2., -2., 2.);

    /* create drawing function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetColor(vc, 4);
    vis_VisContextSetSize(vc, .1f);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 7, 0, rgb);

    /* create font object and set objects */
    font = vis_FontBegin();
    vis_FontSetObject(font, VGL_DRAWFUN, df);
    vis_FontSetObject(font, VIS_VISCONTEXT, vc);
    vis_FontSetObject(font, VIS_COLORMAP, cmap);

    /* draw standard font */
    GLWinClear(glwin);
    x[0] = x[1] = x[2] = 0.;
    vis_FontSetParami(font, FONT_DIRECTION, VIS_RIGHT);
    vis_FontText(font, x, "Hello World");
    vis_FontSetParami(font, FONT_DIRECTION, VIS_BOTTOM);
    vis_FontText(font, x, "Hello World");
    vis_FontSetParami(font, FONT_DIRECTION, VIS_RIGHT);
    x[1] = .5;
    vis_FontText(font, x, "Hello World");
    vis_FontSetParamf(font, FONT_ANGLE, 30.);
    vis_FontText(font, x, "Hello World");
    vis_FontSetParamf(font, FONT_ANGLE, 60.);
    vis_FontText(font, x, "Hello World");
    vis_FontSetParamf(font, FONT_ANGLE, 90.);
    vis_FontText(font, x, "Hello World");
    vis_FontSetParamf(font, FONT_ANGLE, 0.);
    GLWinSwap(glwin);
    sleep(5);
    /* illustrate expansion, spacing, etc. */
    vis_VisContextSetSize(vc, .1f);
    for (i = 0; i < 30; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 12.F, 'x');

        x[0] = -1.8f;
        x[1] = 1.5f;
        vis_FontText(font, x, "1234 ABCD abcd !@#$%^&*()_+");
        x[0] = -1.8f;
        x[1] = 1.0f;
        vis_FontSetParamf(font, FONT_EXPANSION, .5);
        vis_FontText(font, x, "1234 ABCD abcd !@#$%^&*()_+");
        vis_FontSetParamf(font, FONT_EXPANSION, 1.);
        x[0] = -1.8f;
        x[1] = .5f;
        vis_FontSetParamf(font, FONT_SLANT, .2f);
        vis_FontText(font, x, "1234 ABCD abcd !@#$%^&*()_+");
        vis_FontSetParamf(font, FONT_SLANT, 0.);
        x[0] = -1.8f;
        x[1] = 0.;
        vis_FontSetParamf(font, FONT_SPACING, .2f);
        vis_FontText(font, x, "1234 ABCD abcd !@#$%^&*()_+");
        vis_FontSetParamf(font, FONT_SPACING, 0.);
        x[0] = -1.8f;
        x[1] = -.5f;
        vis_FontSetParamf(font, FONT_EXTRUSION, .02f);
        vis_FontText(font, x, "1234 ABCD abcd !@#$%^&*()_+");
        x[0] = -1.8f;
        x[1] = -1.;
        vis_FontSetParamf(font, FONT_EXTRUSION, .05f);
        vis_VisContextSetSize(vc, .2f);
        vis_FontSetParamf(font, FONT_EXPANSION, .5);
        vis_FontText(font, x, "1234 ABCD abcd !@#$%^&*()_+");
        vis_FontSetParamf(font, FONT_EXTRUSION, 0.);
        vis_VisContextSetSize(vc, .1f);
        vis_FontSetParamf(font, FONT_EXPANSION, 1.);

        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(5);
    /* illustrate available fonts */
    GLWinClear(glwin);
    vis_VisContextSetSize(vc, .15f);
    x[0] = -1.8f;
    x[1] = 1.8f;
    vis_FontLoad(font, FONT_GREEK);
    vis_FontText(font, x, "1234 ABCD abcd !@#$ GREEK");
    x[0] = -1.8f;
    x[1] = 1.4f;
    vis_FontLoad(font, FONT_ITALICS);
    vis_FontText(font, x, "1234 ABCD abcd !@#$ ITALICS");
    x[0] = -1.8f;
    x[1] = 1.0;
    vis_FontLoad(font, FONT_ROMAN1);
    vis_FontText(font, x, "1234 ABCD abcd !@#$ ROMAN1");
    x[0] = -1.8f;
    x[1] = .6f;
    vis_FontLoad(font, FONT_ROMAN2);
    vis_FontText(font, x, "1234 ABCD abcd !@#$ ROMAN2");
    x[0] = -1.8f;
    x[1] = .2f;
    vis_FontLoad(font, FONT_BOLDSCRIPT);
    vis_FontText(font, x, "1234 ABCD abcd !@#$ BOLDSCRIPT");
    /*
       x[0] = -1.8; x[1] = -.2;
       vis_FontLoad (font,FONT_FILLROMAN1);
       vis_FontText (font,x,"1234 ABCD abcd !@#$ FILLROMAN1");
       x[0] = -1.8; x[1] = -.6;
       vis_FontLoad (font,FONT_FILLROMAN2);
       vis_FontText (font,x,"1234 ABCD abcd !@#$ FILLROMAN2");
       x[0] = -1.8; x[1] = -1.0;
       vis_FontLoad (font,FONT_GOTHIC);
       vis_FontText (font,x,"1234 ABCD abcd !@#$ GOTHIC");
    */
    x[0] = -1.8f;
    x[1] = -1.4f;
    vis_FontLoad(font, FONT_SCRIPT);
    vis_FontText(font, x, "1234 ABCD abcd !@#$ SCRIPT");
    x[0] = -1.8f;
    x[1] = -1.8f;
    vis_FontLoad(font, FONT_UNCIAL);
    vis_FontText(font, x, "1234 ABCD abcd !@#$ UNCIAL");
    GLWinSwap(glwin);

    sleep(5);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_FontEnd(font);
    GLWinEnd(glwin);
    return 0;
}
