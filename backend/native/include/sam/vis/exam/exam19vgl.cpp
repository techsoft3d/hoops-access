#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "legacy/vgl/vgl.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vfloat rgb[7][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

#define NPOINTS 13
#define NLINES  12

static Vfloat pts[NPOINTS][3] = {{-0.4f, -0.5f, 0.}, {0.4f, -0.5f, 0.}, {0.4f, 0.0, 0.},   {-0.4f, 0.0, 0.}, {-0.8f, 0.0, 0.},
                                 {0.8f, 0.0, 0.},    {0.8f, 0.8f, 0.},  {-0.8f, 0.8f, 0.}, {0.0, 0.5f, 0.},  {-0.2f, 0.2f, 0.},
                                 {-0.2f, 0.4f, 0.},  {0.2f, 0.4f, 0.},  {0.2f, 0.2f, 0.}};

static Vint lines[NLINES][3] = {
/* bottom polygon */
{1, 2, 0},
{2, 3, 0},
{3, 4, 0},
{4, 1, 0},
/* top polygon */
{5, 6, 0},
{6, 7, 0},
{7, 9, 8}, /* this is an arc */
{8, 5, 0},
/* hole in top polygon */
{10, 11, 0},
{11, 12, 0},
{12, 13, 0},
{13, 10, 0}};

/* text drawing */
static Vfloat xtxt[3] = {-0.8f, 0.9f, 0.};
static Vfloat white[3] = {1., 1., 1.};

/* device pixel sizes */
static Vint isize[3] = {5, 10, 50};

/*----------------------------------------------------------------------
                      Draw a 2D Polygon
----------------------------------------------------------------------*/
int
main()
{
#ifdef VKI_WIND_X11
    Display* display;
    int screen;
#endif
    vis_Tess* tess;
    vis_VisContext* vc;
    vis_ColorMap* cm;
    vgl_DrawFun* df;
    vgl_OpenGLDev* ogldev;
    Vint n;
    Vint devicesize;
    Vint parami[4];
    Vchar buffer[80];
    Vfloat paramf[16];

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

    /* create drawing functions */
    df = vgl_DrawFunBegin();
    vgl_OpenGLDevDrawFun(ogldev, df);
    vgl_DrawFunPositionWindow(df, 100, 400, 400, 400);
    vgl_DrawFunOpenWindow(df, "Example 19 vgl");
    vgl_DrawFunProjOrtho(df, -1., 1., -1., 1., -1., 1.);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetColor(vc, 3);
    vis_VisContextSetMinorColor(vc, 5);
    vis_VisContextSetLineWidth(vc, 2);
    vis_VisContextSetLineStyle(vc, VGL_LINESTYLE_DASH);
    vis_VisContextSetFill(vc, 1);
    vis_VisContextSetEdge(vc, 1);
    vis_VisContextSetPrimType(vc, VIS_PRIM_STRIP);

    /* color map */
    cm = vis_ColorMapBegin();
    vis_ColorMapSetType(cm, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cm, 7, 0, rgb);

    /* tess object setup */
    tess = vis_TessBegin();
    vis_TessSetObject(tess, VIS_VISCONTEXT, vc);
    vis_TessSetObject(tess, VIS_COLORMAP, cm);
    vis_TessSetObject(tess, VGL_DRAWFUN, df);
    vis_TessSetParami(tess, TESS_EDGE, TESS_EDGE_OUTLINE);

    vis_TessDef(tess, NPOINTS, NLINES);
    for (n = 1; n <= NPOINTS; n++) {
        vis_TessSetPoint(tess, n, pts[n - 1]);
    }
    for (n = 1; n <= NLINES; n++) {
        if (lines[n - 1][2] == 0) {
            vis_TessSetLine(tess, n, lines[n - 1]);
        }
        else {
            vis_TessSetArc(tess, n, lines[n - 1]);
        }
    }
    /* illustrate world sizing and 3 device sizes */
    for (n = 1; n <= 4; n++) {
        vgl_DrawFunClear(df);
        vgl_DrawFunColor(df, white);
        /* world sizing */
        if (n == 1) {
            vgl_DrawFunText(df, xtxt, (Vchar*)"World size= 0.1");
            vis_VisContextSetSizeType(vc, VIS_SIZEWORLD);
            vis_VisContextSetSize(vc, 0.1f);
            /* 3 device sizes, 5, 10 and 50 pixels */
            /* note that Size scales DeviceSize */
        }
        else {
            devicesize = isize[n - 2];
            sprintf(buffer, "Device size= %d", devicesize);
            vgl_DrawFunText(df, xtxt, buffer);
            vis_VisContextSetSizeType(vc, VIS_SIZEDEVICE);
            vis_VisContextSetSize(vc, 1.);
            vis_VisContextSetDeviceSize(vc, devicesize);
            vgl_DrawFunGetFloat(df, VGL_PROJECTIONMATRIX, paramf);
            vis_VisContextSetProjMatrix(vc, (Vfloat(*)[4])paramf);
            vgl_DrawFunGetFloat(df, VGL_MODELVIEWMATRIX, paramf);
            vis_VisContextSetXfmMatrix(vc, (Vfloat(*)[4])paramf);
            vgl_DrawFunGetInteger(df, VGL_VIEWPORT, parami);
            vis_VisContextSetViewport(vc, parami[0], parami[1], parami[2], parami[3]);
        }
        vis_TessDraw(tess);
        vgl_DrawFunSwap(df);
        vgl_DrawFunDelay(df, 5.);
    }

    /* close windows */
    vgl_DrawFunCloseWindow(df);

    /* free objects */
    vis_TessEnd(tess);
    vis_ColorMapEnd(cm);
    vis_VisContextEnd(vc);
    vgl_DrawFunEnd(df);
    vgl_OpenGLDevEnd(ogldev);

    /* close X display */
#ifdef VKI_WIND_X11
    XCloseDisplay(display);
#endif
    return 0;
}
