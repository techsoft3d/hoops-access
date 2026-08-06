#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat xhex[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.},
                            {0., 0., 1.}, {1., 0., 1.}, {1., 1., 1.}, {0., 1., 1.}};
static Vfloat rgb[7][3] = {{.2f, .2f, .2f}, {1., .2f, .2f}, {.2f, 1., .2f}, {.2f, .2f, 1.},
                           {0., 1., 1.},    {1., 0., 1.},   {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Generate vectors at vertices of a hexahedron
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
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -2., 2., -2., 2., -2., 2.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* viscontext and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetFlags(vc, VIS_VECTORTAIL | VIS_VECTORTAILREGISTER);
    vis_VisContextSetVectorType(vc, VIS_VECTORCYLINDER);
    vis_VisContextSetSize(vc, .5);

    /* levels, set six evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 6;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, 0., 2.);
    vis_LevelsGenerate(levels, LEVELS_PADENDS);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, nlevels + 1, 0, rgb);

    /* create mark object and set objects */
    mark = vis_MarkBegin();
    vis_MarkSetObject(mark, VGL_DRAWFUN, df);
    vis_MarkSetObject(mark, VIS_VISCONTEXT_VECTOR, vc);
    vis_MarkSetObject(mark, VIS_LEVELS, levels);
    vis_MarkSetObject(mark, VIS_COLORMAP, cmap);

    /* draw vectors */
    for (i = 0; i < 15; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 12.F, 'x');
        vis_MarkVector(mark, 8, xhex, xhex);
        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(5);

    /* draw viewplane projected vectors */
    vis_VisContextSetProject(vc, VIS_ON);
    vis_VisContextSetVectorType(vc, VIS_VECTORLINE);
    vis_VisContextSetFill(vc, VIS_OFF);
    vis_VisContextSetFlags(vc, VIS_VECTORTAIL | VIS_VECTORTAILREGISTER | VIS_VECTORNOCAP);

    for (i = 0; i < 15; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 12.F, 'x');
        /* get the current modelview matrix */
        GLWinXfmGet(glwin, tm);
        /* set matrix in viscontext */
        vis_VisContextSetXfmMatrix(vc, tm);
        /* draw vectors */
        vis_MarkVector(mark, 8, xhex, xhex);
        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(5);
    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_LevelsEnd(levels);
    vis_ColorMapEnd(cmap);
    vis_MarkEnd(mark);
    GLWinEnd(glwin);
    return 0;
}
