#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

/* coordinates and data for 8 node hex */
static Vfloat xhex[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.},
                            {0., 0., 1.}, {1., 0., 1.}, {1., 1., 1.}, {0., 1., 1.}};
static Vfloat shex[8] = {0., 1., 1., 0., 1., 2., 2., 1.};
/* coordinates and data (y coordinate) for 20 node tet */
static Vfloat xtet[20][3] = {{0., 0., 0.}, {.5, 0., 0.}, {1., 0., 0.},  {1.5, 0., 0.}, {0., .5, 0.}, {.5, .5, 0.}, {1., .5, 0.},
                             {0., 1., 0.}, {.5, 1., 0.}, {0., 1.5, 0.}, {0., 0., .5},  {.5, 0., .5}, {1., 0., .5}, {0., .5, .5},
                             {.5, .5, .5}, {0., 1., .5}, {0., 0., 1.},  {.5, 0., 1.},  {0., .5, 1.}, {0., 0., 1.5}};
static Vfloat stet[20] = {0., 0., 0., 0., .5, .5, .5, 1., 1., 1.5, 0., 0., 0., .5, .5, 1., 0., 0., .5, 0.};

static Vfloat rgb[7][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Draw Isosurfaces and Volume Fringes in Hex and Tet
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_Levels* levels;
    vis_ColorMap* cmap;
    vis_TransMap* tmap;
    vis_Threshold* threshold;
    GLWin* glwin;

    int i;
    Vint nlevels;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -2., 2., -2., 2., -2., 2.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetIsoValType(vc, VIS_ISOVALSURFACE);

    /* levels, set six evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 6;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, nlevels + 1, 0, rgb);

    /* create threshold object and set objects */
    threshold = vis_ThresholdBegin();
    vis_ThresholdSetObject(threshold, VGL_DRAWFUN, df);
    vis_ThresholdSetObject(threshold, VIS_VISCONTEXT, vc);
    vis_ThresholdSetObject(threshold, VIS_LEVELS, levels);
    vis_ThresholdSetObject(threshold, VIS_COLORMAP, cmap);

    /* draw threshold surfaces */
    /* 8 node hex */
    vis_LevelsSetMinMax(levels, 0.0, 2.0);
    vis_LevelsGenerate(levels, LEVELS_PADENDS);
    vis_ThresholdSetTopology(threshold, VIS_SHAPEHEX, 2, 0, 0);
    for (i = 0; i < 10; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 12.F, 'x');
        vis_ThresholdCurv(threshold, shex, xhex, VIS_NODATA, NULL);
        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(2);
    /* 20 node tet */
    vis_LevelsSetMinMax(levels, 0.0, 1.5);
    vis_LevelsGenerate(levels, LEVELS_PADENDS);
    vis_ThresholdSetTopology(threshold, VIS_SHAPETET, 4, 4, 4);
    for (i = 0; i < 10; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 12.F, 'x');
        vis_ThresholdCurv(threshold, stet, xtet, VIS_NODATA, NULL);
        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(2);

    /* transparency map */
    tmap = vis_TransMapBegin();
    vis_TransMapSetType(tmap, TRANSMAP_FACTOR);
    vis_TransMapRamp(tmap, nlevels + 2, 0, TRANSMAP_UP);
    vis_TransMapSetDecay(tmap, .1f);

    /* set object in threshold */
    vis_ThresholdSetObject(threshold, VIS_TRANSMAP, tmap);

    /* set viscontext for volume fringing */
    vis_VisContextSetIsoValType(vc, VIS_ISOVALFRINGE);
    vis_VisContextSetMapTrans(vc, VIS_ON);
    vis_VisContextSetSize(vc, .05f);

    /* draw threshold volume fringes */
    /* 8 node hex */
    vis_LevelsSetMinMax(levels, 0.0, 2.0);
    vis_LevelsGenerate(levels, LEVELS_PADENDS);
    vis_ThresholdSetTopology(threshold, VIS_SHAPEHEX, 2, 0, 0);
    for (i = 0; i < 10; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 12.F, 'x');
        vis_ThresholdCurv(threshold, shex, xhex, VIS_NODATA, NULL);
        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(2);
    /* 20 node tet */
    vis_LevelsSetMinMax(levels, 0.0, 1.5);
    vis_LevelsGenerate(levels, LEVELS_PADENDS);
    vis_ThresholdSetTopology(threshold, VIS_SHAPETET, 4, 4, 4);
    for (i = 0; i < 10; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 12.F, 'x');
        vis_ThresholdCurv(threshold, stet, xtet, VIS_NODATA, NULL);
        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(2);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_LevelsEnd(levels);
    vis_ColorMapEnd(cmap);
    vis_TransMapEnd(tmap);
    vis_ThresholdEnd(threshold);
    GLWinEnd(glwin);
    return 0;
}
