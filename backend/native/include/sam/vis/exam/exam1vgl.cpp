#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vfloat xhex[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.},
                            {0., 0., 1.}, {1., 0., 1.}, {1., 1., 1.}, {0., 1., 1.}};
static Vfloat shex[8] = {0., 1., 1., 0., 1., 2., 2., 1.};
static Vfloat rgb[7][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Generate isosurfaces in a hexahedron
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
    vis_Threshold* threshold;
    vgl_OpenGLDev* ogldev;
    vgl_Xfm* xfm;

    int i;
    Vint nlevels;
    Vfloat c[3], x[3], tm[4][4];

#ifdef VKI_WIND_X11
    /* open X display */
    display = XOpenDisplay(0);
    screen = DefaultScreen(display);
    vgl_OpenGLDevConnectX(display, screen);
#endif

    vsy_LicenseValidate(HOOPS_LICENSE);

#ifdef VKI_WIND_WIN32
    vgl_OpenGLDevConnectWIN();
#endif
    /* create GL device */
    ogldev = vgl_OpenGLDevBegin();

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    vgl_OpenGLDevDrawFun(ogldev, df);

    vgl_DrawFunPositionWindow(df, 200, 200, 400, 400);
    vgl_DrawFunOpenWindow(df, "Example 1vgl");
    vgl_DrawFunProjOrtho(df, -2., 2., -2., 2., -2., 2.);
    vgl_DrawFunSetMode(df, VGL_ZBUFFERMODE, VGL_ON);
    vgl_DrawFunSetMode(df, VGL_LIGHTMODE, VGL_ON);
    c[0] = .4f;
    c[1] = .4f;
    c[2] = .4f;
    x[0] = 0.;
    x[1] = 0.;
    x[2] = 0.;
    vgl_DrawFunLight(df, 0, VGL_LIGHT_AMBIENT, c, x);
    c[0] = .6f;
    c[1] = .6f;
    c[2] = .6f;
    x[0] = 1.;
    x[1] = 1.;
    x[2] = 1.;
    vgl_DrawFunLight(df, 1, VGL_LIGHT_DISTANT, c, x);
    x[0] = -1.;
    x[1] = -1.;
    x[2] = -1.;
    vgl_DrawFunLight(df, 2, VGL_LIGHT_DISTANT, c, x);

    /* create transformation object */
    xfm = vgl_XfmBegin();

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetIsoValType(vc, VIS_ISOVALSURFACE);

    /* levels, set three evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 3;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, 0., 2.);
    vis_LevelsGenerate(levels, LEVELS_PADENDS);

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
    for (i = 0; i < 30; i++) {
        vgl_DrawFunClear(df);
        vgl_DrawFunXfmPush(df);
        vgl_XfmRotate(xfm, i * 12.F * .017453F, XFM_XAXIS);
        vgl_XfmGetMatrix(xfm, tm);
        vgl_DrawFunXfmLoad(df, tm);
        vis_ThresholdCurv(threshold, shex, xhex, VIS_NODATA, NULL);
        vgl_DrawFunXfmPop(df);
        vgl_DrawFunSwap(df);
        vgl_DrawFunDelay(df, 1.);
    }
    vgl_DrawFunDelay(df, 5.);

    /* close window */
    vgl_DrawFunCloseWindow(df);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_LevelsEnd(levels);
    vis_ColorMapEnd(cmap);
    vis_ThresholdEnd(threshold);
    vgl_OpenGLDevEnd(ogldev);
    vgl_XfmEnd(xfm);

    /* disconnect from window system */
    vgl_OpenGLDevDisconnect();

    /* close X display */
#ifdef VKI_WIND_X11
    XCloseDisplay(display);
#endif
    return 0;
}
