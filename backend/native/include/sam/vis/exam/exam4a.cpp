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
static Vfloat rgb[7][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

typedef struct Tobj {
    vis_Contour* contour;
    Vfloat* dctri;
} Tobj;

/*----------------------------------------------------------------------
                      Drawing function for output from Threshold
----------------------------------------------------------------------*/
static void
TPolygonData(Vobject* obj, Vint type, Vint npts, Vfloat x[][3], Vint nrws, Vfloat* d, Vint vflag, Vfloat v[])
{
    int i;
    Vfloat sctri[3];
    Tobj* tobj;

    tobj = (Tobj*)obj;
    /* fill dctri with scalar */
    /* fill sctri with x coordinate */
    for (i = 0; i < 3; i++) {
        tobj->dctri[i] = d[nrws * i];
        sctri[i] = d[nrws * i + 1];
    }

    if (npts == 3) {
        vis_ContourSetTopology(tobj->contour, VIS_SHAPETRI, 0, 0);
    }
    else {
        vis_ContourSetTopology(tobj->contour, VIS_SHAPEQUAD, 0, 0);
    }
    vis_ContourCurv(tobj->contour, sctri, x, VIS_NODATA, NULL);
}

/*----------------------------------------------------------------------
                      Generate isolines in a hexahedron
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun *dfGL, *dfT, *dfC;
    vis_DataInt *diT, *diC;
    vis_VisContext *vcT, *vcC, *vc;
    vis_Levels *levelsT, *levelsC, *levels;
    vis_ColorMap* cmap;
    vis_Threshold* threshold;
    vis_Segment* segment;
    GLWin* glwin;

    int i;
    Vint nlevels;
    Vfloat dthex[8][2], sthex[8];
    /* object info for Threshold drawing function */
    Tobj tobj;
    vis_Contour* contour;
    Vfloat dctri[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -2., 2., -2., 2., -2., 2.);

    /* create drawing function object for GL */
    dfGL = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, dfGL);

    /* Threshold levels, set one level at .2 */
    levelsT = vis_LevelsBegin();
    vis_LevelsDef(levelsT, LEVELS_LINEAR, 1);
    vis_LevelsSetValue(levelsT, 1, .2f);

    /* Contour levels, set one level at .4 */
    levelsC = vis_LevelsBegin();
    vis_LevelsDef(levelsC, LEVELS_LINEAR, 1);
    vis_LevelsSetValue(levelsC, 1, .4f);

    /* Segment levels, set six evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 6;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, 0., 2.);
    vis_LevelsGenerate(levels, LEVELS_PADTOP);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, nlevels + 1, 0, rgb);

    /* Segment vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetIsoValType(vc, VIS_ISOVALFRINGE);
    vis_VisContextSetLineWidth(vc, 2);

    /* create segment object and set objects */
    segment = vis_SegmentBegin();
    vis_SegmentSetObject(segment, VGL_DRAWFUN, dfGL);
    vis_SegmentSetObject(segment, VIS_VISCONTEXT, vc);
    vis_SegmentSetObject(segment, VIS_LEVELS, levels);
    vis_SegmentSetObject(segment, VIS_COLORMAP, cmap);

    /* Contour vis context and set attributes */
    vcC = vis_VisContextBegin();
    vis_VisContextSetIsoValType(vcC, VIS_ISOVALLINE);
    vis_VisContextSetDraw(vcC, VIS_OFF);
    vis_VisContextSetShade(vcC, VIS_NOSHADE);
    vis_VisContextSetMapColor(vcC, VIS_OFF);

    /* create drawing function object for Contour output*/
    dfC = vgl_DrawFunBegin();
    vgl_DrawFunSetObj(dfC, segment);
    vgl_DrawFunAPI(dfC, DRAWFUN_APIRETURN);
    /* use function provided by Segment module */
    vgl_DrawFunSet(dfC, DRAWFUN_POLYLINEDATA, (Vfunc*)vis_SegmentPolyLineData);

    /* Contour data interpolation */
    diC = vis_DataIntBegin();
    vis_DataIntSetDataPtr(diC, 0, 1, (Vfloat*)dctri);

    /* create contour object and set objects */
    contour = vis_ContourBegin();
    vis_ContourSetObject(contour, VGL_DRAWFUN, dfC);
    vis_ContourSetObject(contour, VIS_VISCONTEXT, vcC);
    vis_ContourSetObject(contour, VIS_LEVELS, levelsC);
    vis_ContourSetObject(contour, VIS_DATAINT, diC);

    /* Threshold vis context and set attributes */
    vcT = vis_VisContextBegin();
    vis_VisContextSetIsoValType(vcT, VIS_ISOVALSURFACE);
    vis_VisContextSetDraw(vcT, VIS_OFF);
    vis_VisContextSetShade(vcT, VIS_NOSHADE);
    vis_VisContextSetMapColor(vcT, VIS_OFF);

    /* fill object info */
    tobj.contour = contour;
    tobj.dctri = dctri;
    /* create drawing function object for Threshold output*/
    dfT = vgl_DrawFunBegin();
    vgl_DrawFunSetObj(dfT, (Vobject*)&tobj);
    vgl_DrawFunAPI(dfT, DRAWFUN_APIRETURN);
    vgl_DrawFunSet(dfT, DRAWFUN_POLYGONDATA, (Vfunc*)TPolygonData);

    /* Threshold data interpolation */
    diT = vis_DataIntBegin();
    vis_DataIntSetDataPtr(diT, 0, 2, (Vfloat*)dthex);

    /* create threshold object and set objects */
    threshold = vis_ThresholdBegin();
    vis_ThresholdSetObject(threshold, VGL_DRAWFUN, dfT);
    vis_ThresholdSetObject(threshold, VIS_VISCONTEXT, vcT);
    vis_ThresholdSetObject(threshold, VIS_LEVELS, levelsT);
    vis_ThresholdSetObject(threshold, VIS_DATAINT, diT);

    /* fill dthex with scalar and x coordinate */
    /* fill sthex with y coordinate */
    for (i = 0; i < 8; i++) {
        dthex[i][0] = shex[i];
        dthex[i][1] = xhex[i][0];
        sthex[i] = xhex[i][1];
    }

    /* draw segments */
    for (i = 0; i < 30; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 12.F, 'x');
        vis_ThresholdCurv(threshold, sthex, xhex, VIS_NODATA, NULL);
        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(5);

    /* free all objects */
    vgl_DrawFunEnd(dfGL);
    vgl_DrawFunEnd(dfT);
    vgl_DrawFunEnd(dfC);
    vis_DataIntEnd(diT);
    vis_DataIntEnd(diC);
    vis_VisContextEnd(vcT);
    vis_VisContextEnd(vcC);
    vis_VisContextEnd(vc);
    vis_LevelsEnd(levelsT);
    vis_LevelsEnd(levelsC);
    vis_LevelsEnd(levels);
    vis_ColorMapEnd(cmap);
    vis_ThresholdEnd(threshold);
    vis_ContourEnd(contour);
    vis_SegmentEnd(segment);
    GLWinEnd(glwin);
    return 0;
}
