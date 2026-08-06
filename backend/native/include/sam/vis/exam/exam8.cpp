#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat rgb[7][3] = {{.8f, .8f, .8f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Draw Axes
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_Levels* levels;
    vis_ColorMap* cmap;
    vis_Axis* axis;
    GLWin* glwin;

    int i;
    Vfloat x[3], path[3], plane[3];

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
    vis_VisContextSetColor(vc, 4);
    vis_VisContextSetSize(vc, .025f);
    vis_VisContextSetLineStyle(vc, VIS_CYLINDER);
    vis_VisContextSetXYZColor(vc, 0, 0, 0);
    vis_VisContextSetFill(vc, VIS_OFF);
    vis_VisContextSetMinorColor(vc, 6);
    vis_VisContextSetMinorSize(vc, .08f);
    vis_VisContextSetFormat(vc, VIS_FFORMAT);

    /* Axis levels */
    levels = vis_LevelsBegin();

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 7, 0, rgb);

    /* create axis object and set objects */
    axis = vis_AxisBegin();
    vis_AxisSetObject(axis, VGL_DRAWFUN, df);
    vis_AxisSetObject(axis, VIS_VISCONTEXT, vc);
    vis_AxisSetObject(axis, VIS_COLORMAP, cmap);
    vis_AxisSetObject(axis, VIS_LEVELS, levels);

    /* illustrate axes */
    for (i = 0; i < 30; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 1.F, 'X');
        GLWinRotate(glwin, -i * 1.F, 'Y');

        /* draw x axis */
        x[0] = -1.2f;
        x[1] = -1.2f;
        x[2] = 0.;
        vis_LevelsDef(levels, LEVELS_LINEAR, 6);
        vis_LevelsSetMinMax(levels, 0., 100.);
        vis_LevelsGenerate(levels, LEVELS_PADNONE);
        path[0] = 1.;
        path[1] = 0.;
        path[2] = 0.;
        plane[0] = 0.;
        plane[1] = 1.;
        plane[2] = 0.;
        vis_AxisSetPlane(axis, path, plane);
        vis_AxisSetParami(axis, AXIS_SENSE, VIS_OFF);
        vis_AxisPath(axis, x, 3., (Vchar*)"X axis", (Vchar*)"World Coordinate");
        vis_AxisPlane(axis, x, 3., 2., (Vchar*)"", (Vchar*)"");
        vis_AxisProjection(axis, x, 3., 2., (Vchar*)"", (Vchar*)"");

        /* draw y axis */
        vis_LevelsDef(levels, LEVELS_LINEAR, 4);
        vis_LevelsSetMinMax(levels, 0., 60.);
        vis_LevelsGenerate(levels, LEVELS_PADNONE);
        path[0] = 0.;
        path[1] = 1.;
        path[2] = 0.;
        plane[0] = 1.;
        plane[1] = 0.;
        plane[2] = 0.;
        vis_AxisSetPlane(axis, path, plane);
        vis_AxisSetParami(axis, AXIS_SENSE, VIS_ON);
        /* rotate labels by -90. degrees */
        vis_AxisSetParami(axis, AXIS_ROTATELABEL, AXIS_ROTATELABEL_PLUS90);
        vis_AxisPath(axis, x, 2., (Vchar*)"Y axis", (Vchar*)"");
        vis_AxisSetParami(axis, AXIS_ROTATELABEL, VIS_OFF);

        /* draw z axis */
        vis_LevelsDef(levels, LEVELS_LINEAR, 3);
        vis_LevelsSetMinMax(levels, 0., 1000.);
        vis_LevelsGenerate(levels, LEVELS_PADNONE);
        path[0] = 0.;
        path[1] = 0.;
        path[2] = 1.;
        plane[0] = 0.;
        plane[1] = 1.;
        plane[2] = 0.;
        vis_AxisSetPlane(axis, path, plane);
        vis_AxisSetParami(axis, AXIS_SENSE, VIS_OFF);
        vis_AxisPath(axis, x, 2., (Vchar*)"Z axis", (Vchar*)"");

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
    vis_AxisEnd(axis);
    GLWinEnd(glwin);
    return 0;
}
