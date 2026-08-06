#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat xhex[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.},
                            {0., 0., 1.}, {1., 0., 1.}, {1., 1., 1.}, {0., 1., 1.}};
static Vfloat shex[8] = {0., 1., 1., 0., 1., 2., 2., 1.};
static Vfloat rhex[8] = {0., 0., 1., 1., 0., 0., 1., 1.};
static Vfloat rgb[7][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Generate isosurfaces in a hexahedron
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun *dfGL, *dfC;
    vis_VisContext *vc, *vcC;
    vis_Levels *levels, *levelsC;
    vis_ColorMap* cmap;
    vis_Threshold* threshold;
    vis_Contour* contour;
    vis_DataInt* dataint;
    GLWin* glwin;

    int i;
    Vint nlevels, nlevelsC;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -2., 2., -2., 2., -2., 2.);

    /* create drawing function object for GL */
    dfGL = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, dfGL);

    /* Threshold data interpolation */
    dataint = vis_DataIntBegin();
    vis_DataIntSetDataPtr(dataint, 0, 1, rhex);

    /* Threshold vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetIsoValType(vc, VIS_ISOVALSURFACE);
    vis_VisContextSetDraw(vc, VIS_OFF);
    vis_VisContextSetShade(vc, VIS_NOSHADE);

    /* Threshold levels, set three evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 3;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, 0., 2.);
    vis_LevelsGenerate(levels, LEVELS_PADENDS);

    /* Contour vis context and set attributes */
    vcC = vis_VisContextBegin();
    vis_VisContextSetIsoValType(vcC, VIS_ISOVALFRINGE);

    /* Contour levels, set six evenly spaced levels */
    levelsC = vis_LevelsBegin();
    nlevelsC = 6;
    vis_LevelsDef(levelsC, LEVELS_LINEAR, nlevelsC);
    vis_LevelsSetMinMax(levelsC, 0., 1.);
    vis_LevelsGenerate(levelsC, LEVELS_PADTOP);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, nlevelsC + 1, 0, rgb);

    /* create contour object and set objects */
    contour = vis_ContourBegin();
    vis_ContourSetObject(contour, VGL_DRAWFUN, dfGL);
    vis_ContourSetObject(contour, VIS_VISCONTEXT, vcC);
    vis_ContourSetObject(contour, VIS_LEVELS, levelsC);
    vis_ContourSetObject(contour, VIS_COLORMAP, cmap);

    /* create contouring drawing function object */
    dfC = vgl_DrawFunBegin();
    vgl_DrawFunSetObj(dfC, contour);
    vgl_DrawFunAPI(dfC, DRAWFUN_APIRETURN);
    /* use function provided by Contour module */
    vgl_DrawFunSet(dfC, DRAWFUN_POLYGONDATA, (Vfunc*)vis_ContourPolygonData);

    /* create threshold object and set objects */
    threshold = vis_ThresholdBegin();
    vis_ThresholdSetObject(threshold, VGL_DRAWFUN, dfC);
    vis_ThresholdSetObject(threshold, VIS_VISCONTEXT, vc);
    vis_ThresholdSetObject(threshold, VIS_LEVELS, levels);
    vis_ThresholdSetObject(threshold, VIS_DATAINT, dataint);

    /* draw threshold surfaces */
    for (i = 0; i < 30; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 12.F, 'x');
        vis_ThresholdCurv(threshold, shex, xhex, VIS_NODATA, NULL);
        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(5);

    /* free all objects */
    vgl_DrawFunEnd(dfGL);
    vgl_DrawFunEnd(dfC);
    vis_VisContextEnd(vc);
    vis_VisContextEnd(vcC);
    vis_LevelsEnd(levels);
    vis_LevelsEnd(levelsC);
    vis_ColorMapEnd(cmap);
    vis_ThresholdEnd(threshold);
    vis_ContourEnd(contour);
    vis_DataIntEnd(dataint);
    GLWinEnd(glwin);
    return 0;
}
