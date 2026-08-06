#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vfloat rgb[16][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Generate handlebox
----------------------------------------------------------------------*/
int
main()
{
#ifdef VKI_WIND_X11
    Display* display;
    int screen;
#endif
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vgl_DrawFun* df;
    vgl_OpenGLDev* ogldev;
    vgl_Xfm* xfm;

    vis_HandleBox* handlebox;
    Vfloat extent[2][3];
    Vint parami[4];
    Vfloat paramf[16];
    Vfloat tm[4][4];
    Vint but1, but2, but3 = 0, px, py;
    Vint hit;

#ifdef VKI_WIND_X11
    display = XOpenDisplay(0);
    screen = DefaultScreen(display);
    vgl_OpenGLDevConnectX(display, screen);
#endif
#ifdef VKI_WIND_WIN32
    vgl_OpenGLDevConnectWIN();
#endif

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    ogldev = vgl_OpenGLDevBegin();

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    vgl_OpenGLDevDrawFun(ogldev, df);

    vgl_DrawFunPositionWindow(df, 200, 200, 400, 400);
    vgl_DrawFunOpenWindow(df, "Example 16bvgl");
    vgl_DrawFunProjOrtho(df, -10., 10., -10., 10., -10., 10.);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetColor(vc, 1);
    vis_VisContextSetMinorColor(vc, 2);
    vis_VisContextSetSize(vc, 1.0);
    vis_VisContextSetABCColor(vc, 3, 4, 5);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 16, 0, rgb);

    /* handlebox */
    handlebox = vis_HandleBoxBegin();
    vis_HandleBoxSetObject(handlebox, VGL_DRAWFUN, df);
    vis_HandleBoxSetObject(handlebox, VIS_COLORMAP, cmap);
    vis_HandleBoxSetObject(handlebox, VIS_VISCONTEXT, vc);

    extent[0][0] = 0.;
    extent[0][1] = 0.;
    extent[0][2] = 0.;
    extent[1][0] = 4.;
    extent[1][1] = 4.;
    extent[1][2] = 4.;
    vis_HandleBoxSetExtent(handlebox, extent);

    /* create transformation object */
    xfm = vgl_XfmBegin();

    vgl_DrawFunXfmPush(df);
    vgl_XfmRotate(xfm, 12.f * .017453f, XFM_XAXIS);
    vgl_XfmGetMatrix(xfm, tm);
    vgl_DrawFunXfmLoad(df, tm);

    vgl_DrawFunGetFloat(df, VGL_PROJECTIONMATRIX, paramf);
    vis_VisContextSetProjMatrix(vc, (Vfloat(*)[4])paramf);
    vgl_DrawFunGetFloat(df, VGL_MODELVIEWMATRIX, paramf);
    vis_VisContextSetXfmMatrix(vc, (Vfloat(*)[4])paramf);
    vgl_DrawFunGetInteger(df, VGL_VIEWPORT, parami);
    vis_VisContextSetViewport(vc, parami[0], parami[1], parami[2], parami[3]);

    vgl_DrawFunClear(df);
    vis_HandleBoxDraw(handlebox);
    vgl_DrawFunSwap(df);
    for (;;) {
        vgl_DrawFunPollMouse(df, &px, &py, &but1, &but2, &but3);
        vis_HandleBoxTestHit(handlebox, px, py, &hit);
        if (hit == 0) {
            vis_HandleBoxInitHit(handlebox);
        }
        vgl_DrawFunClear(df);
        vis_HandleBoxDraw(handlebox);
        vgl_DrawFunSwap(df);
        if (but3)
            break;
    }
    for (;;) {
        vgl_DrawFunPollMouse(df, &px, &py, &but1, &but2, &but3);
        vgl_DrawFunClear(df);
        vis_HandleBoxDrag(handlebox, VIS_ACTION_TRANSLATE, VIS_DRAG_MOVE, px, py);
        vgl_DrawFunSwap(df);
        if (but3)
            break;
    }
    /* close window */
    vgl_DrawFunCloseWindow(df);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_HandleBoxEnd(handlebox);
    vgl_OpenGLDevEnd(ogldev);
    return 0;
}
