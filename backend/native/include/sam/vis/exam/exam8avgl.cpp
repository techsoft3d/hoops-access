#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat rgb[16][3] = {{.8f, .8f, .8f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Draw Axes Using Orientable Raster Fonts
----------------------------------------------------------------------*/
int
main()
{
#ifdef VKI_WIND_X11
    Display* display;
    int screen;
#endif
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_Levels* levels;
    vis_ColorMap* cmap;
    vis_Axis* axis;
    vgl_OpenGLDev* ogldev;
    vgl_RasFont* rasfont;
    vgl_Xfm* xfm;

    int i;
    Vfloat x[3], path[3], plane[3];
    Vfloat tm[4][4];

    /* connect to window system */
#ifdef VKI_WIND_X11
    display = XOpenDisplay(0);
    screen = DefaultScreen(display);
    vgl_OpenGLDevConnectX(display, screen);
#endif

    vsy_LicenseValidate(HOOPS_LICENSE);

#ifdef VKI_WIND_WIN32
    vgl_OpenGLDevConnectWIN();
#endif
    /* create OpenGL device */
    ogldev = vgl_OpenGLDevBegin();
    /* create drawing function object for OpenGL */
    df = vgl_DrawFunBegin();
    vgl_OpenGLDevDrawFun(ogldev, df);

    vgl_DrawFunPositionWindow(df, 200, 200, 600, 600);
    vgl_DrawFunOpenWindow(df, "Example 8vgl");
    vgl_DrawFunProjOrtho(df, -2., 2., -2., 2., -2., 2.);

    /* create transformation object */
    xfm = vgl_XfmBegin();

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
    /* disable stroke fonts */
    vis_AxisSetParami(axis, AXIS_STROKEFONT, VGL_OFF);

    rasfont = vgl_RasFontBegin();
    vgl_RasFontLoad(rasfont, RASFONT_QUALITY9X13);
    vgl_RasFontSetParami(rasfont, RASFONT_TEXTPLANE, SYS_ON);
    vgl_RasFontSetParami(rasfont, RASFONT_DEVICESIZE, SYS_ON);
    vgl_RasFontSetPixelSize(rasfont, .008f);
    vgl_DrawFunRasFontDefine(df, 1, rasfont);
    vgl_DrawFunRasFontSelect(df, 1);

    /* illustrate axes */
    for (i = 0; i < 30; i++) {
        vgl_DrawFunClear(df);
        vgl_DrawFunXfmPush(df);

        vgl_XfmRotate(xfm, i * 2.F * .017453F, XFM_XAXIS);
        vgl_XfmGetMatrix(xfm, tm);
        vgl_DrawFunXfmMult(df, tm);
        vgl_XfmRotate(xfm, -i * 2.F * .017453F, XFM_YAXIS);
        vgl_XfmGetMatrix(xfm, tm);
        vgl_DrawFunXfmMult(df, tm);

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
        vis_AxisPath(axis, x, 2., (Vchar*)"Y axis", (Vchar*)"Dependent Variable");
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

        vgl_DrawFunXfmPop(df);
        vgl_DrawFunSwap(df);
        vgl_DrawFunDelay(df, 1.);
    }

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_LevelsEnd(levels);
    vis_AxisEnd(axis);
    vgl_OpenGLDevEnd(ogldev);
    vgl_RasFontEnd(rasfont);
    vgl_XfmEnd(xfm);
    /* disconnect from window system */
    vgl_OpenGLDevDisconnect();
#ifdef VKI_WIND_X11
    XCloseDisplay(display);
#endif
    return 0;
}
