#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat rgb[3][3] = {{0., 0., 0.}, {1., 1., 1.}, {.5, .5, .5}};

static Vfloat xtex[3] = {-3.8f, 1.8f, 0.f};
static Vfloat ctex[3] = {1., 1., 1.};

/*----------------------------------------------------------------------
                      Draw legends
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_TransMap* tmap;
    vis_Levels* levels;
    vis_Legend* legend;
    GLWin* glwin;

    Vfloat x[3];
    Vint nlevels;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 800, 400);
    GLWinOrtho(glwin, -4., 4., -2., 2., -2., 2.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    vc = vis_VisContextBegin();
    vis_VisContextSetLineWidth(vc, 2);
    vis_VisContextSetMinorLineStyle(vc, VIS_SOLID);
    vis_VisContextSetMinorLineWidth(vc, 2);
    vis_VisContextSetMinorColor(vc, 14);
    vis_VisContextSetColor(vc, 15);
    vis_VisContextSetTrans(vc, 1);
    vis_VisContextSetFormat(vc, VIS_E2FORMAT);
    vis_VisContextSetFrequency(vc, 0);
    vis_VisContextSetMapTrans(vc, VIS_OFF);
    nlevels = 12;
    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapRamp(cmap, nlevels, 1, COLORMAP_ANSYS);
    vis_ColorMapSetRGB(cmap, 3, 13, rgb);

    /* transparency map */
    tmap = vis_TransMapBegin();
    vis_TransMapSetType(tmap, TRANSMAP_FACTOR);
    vis_TransMapRamp(tmap, nlevels, 1, TRANSMAP_UP);

    /* levels, generate evenly spaced levels */
    levels = vis_LevelsBegin();
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, -2., 2.);
    vis_LevelsSetLabel(levels, nlevels - 2, (Vchar*)" Yield Stress");

    /* create Legend object and set objects */
    legend = vis_LegendBegin();
    vis_LegendSetObject(legend, VGL_DRAWFUN, df);
    vis_LegendSetObject(legend, VIS_VISCONTEXT, vc);
    vis_LegendSetObject(legend, VIS_COLORMAP, cmap);
    vis_LegendSetObject(legend, VIS_TRANSMAP, tmap);
    vis_LegendSetObject(legend, VIS_LEVELS, levels);

    /* draw vertical layout */
    x[0] = -1.;
    x[1] = -1.5;
    x[2] = 0.;
    vis_VisContextSetSize(vc, .5);
    vis_VisContextSetMinorSize(vc, 3.);
    vis_LegendSetParami(legend, LEGEND_LAYOUT, LEGEND_VERTICAL);

    /* Fringe, Accent, Raster Font */
    vis_VisContextSetFlags(vc, VIS_ISOVALACCENT);
    vis_LegendSetParami(legend, LEGEND_STROKEFONT, VIS_OFF);
    vis_LegendSetParami(legend, LEGEND_SPECTRUM, LEGEND_FRINGE);
    vis_LegendSetParami(legend, LEGEND_PADTOP, VIS_ON);
    vis_LegendSetParami(legend, LEGEND_LABELUSELEVELS, VIS_ON);
    vis_LevelsGenerate(levels, LEVELS_PADTOP);

    GLWinClear(glwin);
    GLWinColor(glwin, ctex);
    GLWinText(glwin, xtex, (Vchar*)"Vertical, Fringe, Accent, Raster Font");
    vis_LegendDraw(legend, x);
    GLWinSwap(glwin);
    sleep(5);
    /* Now draw labels on left */
    vis_LegendSetParami(legend, LEGEND_LABELLEFT, VIS_ON);
    GLWinClear(glwin);
    GLWinColor(glwin, ctex);
    GLWinText(glwin, xtex, (Vchar*)"Vertical, Fringe, Accent, Raster Font, Left Labels");
    vis_LegendDraw(legend, x);
    GLWinSwap(glwin);
    sleep(5);

    /* Tone, Accent, Stroke Font */
    vis_LegendSetParami(legend, LEGEND_LABELLEFT, VIS_OFF);
    vis_VisContextSetFlags(vc, VIS_OFF);

    vis_LegendSetParami(legend, LEGEND_STROKEFONT, VIS_ON);
    vis_LegendSetParami(legend, LEGEND_SPECTRUM, LEGEND_TONE);
    vis_LegendSetParami(legend, LEGEND_PADTOP, VIS_OFF);
    vis_LegendSetParami(legend, LEGEND_LABELUSELEVELS, VIS_OFF);
    vis_LevelsGenerate(levels, LEVELS_PADNONE);

    GLWinClear(glwin);
    GLWinColor(glwin, ctex);
    GLWinText(glwin, xtex, (Vchar*)"Vertical, Tone, Accent, Stroke Font");
    vis_LegendDraw(legend, x);
    GLWinSwap(glwin);
    sleep(5);

    /* draw horizontal layout */
    x[0] = -3.5;
    x[1] = 0.;
    x[2] = 0.;
    vis_VisContextSetSize(vc, 7.);
    vis_VisContextSetMinorSize(vc, .25);
    vis_LegendSetParami(legend, LEGEND_LAYOUT, LEGEND_HORIZONTAL);

    /* Line, Border, Stroked Font */
    vis_VisContextSetFlags(vc, VIS_OFF);
    vis_LegendSetParami(legend, LEGEND_BORDER, VIS_ON);
    vis_LegendSetParami(legend, LEGEND_SPECTRUM, LEGEND_LINE);
    vis_LegendSetParami(legend, LEGEND_PADTOP, VIS_ON);
    vis_LegendSetParami(legend, LEGEND_PADBOTTOM, VIS_ON);
    vis_LevelsGenerate(levels, LEVELS_PADENDS);

    GLWinClear(glwin);
    GLWinColor(glwin, ctex);
    GLWinText(glwin, xtex, (Vchar*)"Horizontal, Line, Border, Stroke Font");
    vis_LegendDraw(legend, x);
    GLWinSwap(glwin);
    sleep(5);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_TransMapEnd(tmap);
    vis_LevelsEnd(levels);
    vis_LegendEnd(legend);
    GLWinEnd(glwin);
    return 0;
}
