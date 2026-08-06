#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat xhex[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.},
                            {0., 0., 1.}, {1., 0., 1.}, {1., 1., 1.}, {0., 1., 1.}};
static Vfloat sang[8] = {5., 10., 15., 20., -25., -30., 35., 40.};
static Vfloat rgb[10][3] = {{1., 1., 1.},   {1., 0., 0.},   {0., 1., 0.}, {.8f, .6f, .6f}, {1., .2f, .2f},
                            {.2f, 1., .2f}, {.2f, .2f, 1.}, {0., 1., 1.}, {1., 0., 1.},    {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Generate meters at vertices of a hexahedron
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_Levels* levels;
    vis_ColorMap* cmap;
    vis_Mark* mark;
    GLWin* glwin;

    int i;
    Vint nlevels;
    Vfloat tm[4][4];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 600, 600);
    GLWinOrtho(glwin, -2., 2., -2., 2., -2., 2.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* viscontext and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetSize(vc, .4f);
    vis_VisContextSetMarkerType(vc, VIS_METER);
    /* map circle color to needle angle */
    vis_VisContextSetMapColor(vc, VIS_MAPCOLOR_CONSTANT);
    /* color of meter outline, zero reference line, needle */
    vis_VisContextSetABCColor(vc, 1, 2, 0);
    /* enable drawing meter outline */
    vis_VisContextSetEdge(vc, VIS_ON);
    /* set segment angle */
    vis_VisContextSetAngle(vc, 60.);
    /* set segment color */
    vis_VisContextSetMinorColor(vc, 3);
    /* set zero reference line linewidth */
    vis_VisContextSetMinorLineWidth(vc, 2);
    /* set needle linewidth */
    vis_VisContextSetLineWidth(vc, 4);
    vis_VisContextSetTrans(vc, 1);
    vis_VisContextSetRefinement(vc, 2);

    /* levels, set six evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 6;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, 0., 40.);
    vis_LevelsGenerate(levels, LEVELS_PADNONE);
    vis_LevelsSetIndex(levels, 0, 4);
    vis_LevelsSetIndex(levels, 1, 4);
    vis_LevelsSetIndex(levels, 2, 5);
    vis_LevelsSetIndex(levels, 3, 6);
    vis_LevelsSetIndex(levels, 4, 7);
    vis_LevelsSetIndex(levels, 5, 8);
    vis_LevelsSetIndex(levels, 6, 9);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 10, 0, rgb);

    /* create mark object and set objects */
    mark = vis_MarkBegin();
    vis_MarkSetObject(mark, VGL_DRAWFUN, df);
    vis_MarkSetObject(mark, VIS_VISCONTEXT_SCALAR, vc);
    vis_MarkSetObject(mark, VIS_COLORMAP, cmap);
    vis_MarkSetObject(mark, VIS_LEVELS, levels);

    /* draw meters */
    for (i = 0; i < 10; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 12.F, 'x');
        vis_MarkScalar(mark, 8, sang, xhex);
        GLWinSetMode(glwin, VGL_LIGHTMODE, VGL_OFF);
        GLWinSetMode(glwin, VGL_LIGHTMODE, VGL_ON);
        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(5);

    /* draw viewplane projected meters */
    vis_VisContextSetProject(vc, VIS_ON);
    for (i = 0; i < 10; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 12.F, 'x');
        /* get the current modelview matrix */
        GLWinXfmGet(glwin, tm);
        /* set matrix in viscontext */
        vis_VisContextSetXfmMatrix(vc, tm);
        /* draw vectors */
        vis_MarkScalar(mark, 8, sang, xhex);
        GLWinSetMode(glwin, VGL_LIGHTMODE, VGL_OFF);
        GLWinSetMode(glwin, VGL_LIGHTMODE, VGL_ON);
        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(5);
    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_LevelsEnd(levels);
    vis_MarkEnd(mark);
    GLWinEnd(glwin);
    return 0;
}
