#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "glwin.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

void
gatherx(Vfloat x[][3], Vint npts, Vint con[], Vfloat xe[][3]);
void
gathers(Vfloat s[], Vint npts, Vint con[], Vfloat se[]);

/* Finite Element Model */
#define MAX_ELEM 2
#define MAX_NODE 10

static Vfloat x[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                                {0., 0., 1.}, {1., 0., 1.}, {2., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}};

static Vfloat s[MAX_NODE] = {1., 2., 3.5f, 4., 3., 1.2f, 2.3f, 3.8f, 4.4f, 3.5f};

static Vint numconn[MAX_ELEM] = {8, 6};

static Vint conn[MAX_ELEM][8] = {{1, 2, 5, 4, 6, 7, 10, 9}, {2, 3, 5, 7, 8, 10, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEWED};

/* Isovalue Types */
static Vint isovaltype[2] = {VIS_ISOVALSURFACE, VIS_ISOVALLINE};

static Vchar* isovalname[2] = {(Vchar*)"VIS_ISOVALSURFACE", (Vchar*)"VIS_ISOVALLINE"};

static Vfloat xname[3] = {0., 2., 0.};

static Vfloat cname[3] = {1., 1., 1.};

/*----------------------------------------------------------------------
                      Draw Isosurfaces in Elements
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_Levels* levels;
    vis_ColorMap* cmap;
    vis_Threshold* threshold;
    GLWin* glwin;

    int i, j, k;
    Vint nlevels;
    Vfloat xe[8][3], se[8];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -1., 3., -1., 3., -2., 2.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();

    /* levels, set twelve evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 12;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, 1., 4.);
    vis_LevelsGenerate(levels, LEVELS_PADTOP);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapRamp(cmap, nlevels, 1, COLORMAP_HUE);

    /* create threshold object and set objects */
    threshold = vis_ThresholdBegin();
    vis_ThresholdSetObject(threshold, VGL_DRAWFUN, df);
    vis_ThresholdSetObject(threshold, VIS_VISCONTEXT, vc);
    vis_ThresholdSetObject(threshold, VIS_LEVELS, levels);
    vis_ThresholdSetObject(threshold, VIS_COLORMAP, cmap);

    /* draw threshold types */
    for (i = 0; i < 2; i++) {
        vis_VisContextSetIsoValType(vc, isovaltype[i]);
        for (k = 0; k < 10; k++) {
            GLWinClear(glwin);
            GLWinXfmPush(glwin);
            GLWinRotate(glwin, k * 12.F, 'y');
            GLWinColor(glwin, cname);
            GLWinText(glwin, xname, isovalname[i]);
            for (j = 0; j < MAX_ELEM; j++) {
                vis_ThresholdSetTopology(threshold, shap[j], 2, 0, 0);
                gatherx(x, numconn[j], conn[j], xe);
                gathers(s, numconn[j], conn[j], se);
                vis_ThresholdCurv(threshold, se, xe, VIS_NODATA, NULL);
            }
            GLWinXfmPop(glwin);
            GLWinSwap(glwin);
            sleep(1);
        }
    }
    sleep(5);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_LevelsEnd(levels);
    vis_ColorMapEnd(cmap);
    vis_ThresholdEnd(threshold);
    GLWinEnd(glwin);
    return 0;
}

/*----------------------------------------------------------------------
                      Utility functions to gather element vectors and scalars
----------------------------------------------------------------------*/
void
gatherx(Vfloat xArg[][3], Vint npts, Vint con[], Vfloat xe[][3])
{
    int i, j;

    for (i = 0; i < npts; i++) {
        for (j = 0; j < 3; j++) {
            xe[i][j] = xArg[con[i] - 1][j];
        }
    }
}

void
gathers(Vfloat sArg[], Vint npts, Vint con[], Vfloat se[])
{
    int i;

    for (i = 0; i < npts; i++) {
        se[i] = sArg[con[i] - 1];
    }
}
