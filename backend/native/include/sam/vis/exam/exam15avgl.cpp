#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vfloat xhex[8][3] = {{-.5, -.5, -.5}, {.5, -.5, -.5}, {.5, .5, -.5}, {-.5, .5, -.5},
                            {-.5, -.5, .5},  {.5, -.5, .5},  {.5, .5, .5},  {-.5, .5, .5}};

/*----------------------------------------------------------------------
                      Draw a Fancy Billboard
----------------------------------------------------------------------*/
int
main()
{
#ifdef VKI_WIND_X11
    Display* display;
    int screen;
#endif

    vgl_DrawFun* df;
    vis_VisContext *vc, *vccell;
    vis_ColorMap* cmap;
    vis_Billboard* billboard;
    vis_Cell* cell;
    vgl_OpenGLDev* ogldev;
    vgl_Xfm* xfm;

    int i;
    Vfloat offset[2];
    Vchar str[80];
    Vfloat width, height;
    Vfloat c[3], x[3], tm[4][4];

#ifdef VKI_WIND_X11
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

    vgl_DrawFunPositionWindow(df, 100, 100, 800, 800);
    vgl_DrawFunOpenWindow(df, "Example 15avgl");
    vgl_DrawFunProjOrtho(df, -1., 2., -1., 2., -1., 2.);
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

    /* color map, standard set of 29 colors */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapRamp(cmap, 29, 0, COLORMAP_SET);

    /* vis context and set attributes */
    vccell = vis_VisContextBegin();
    vis_VisContextSetMapColor(vccell, VIS_OFF);
    vis_VisContextSetColor(vccell, COLORMAP_SET_YELLOW);
    vis_VisContextSetFill(vccell, VIS_OFF);
    vis_VisContextSetEdge(vccell, VIS_ON);
    vis_VisContextSetLineStyle(vccell, VIS_CYLINDER);
    vis_VisContextSetSize(vccell, .025f);

    /* create cell object */
    cell = vis_CellBegin();
    vis_CellSetObject(cell, VGL_DRAWFUN, df);
    vis_CellSetObject(cell, VIS_COLORMAP, cmap);
    vis_CellSetObject(cell, VIS_VISCONTEXT, vccell);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetMapColor(vc, VIS_OFF);
    vis_VisContextSetColor(vc, COLORMAP_SET_GRAY40);
    vis_VisContextSetMinorColor(vc, COLORMAP_SET_WHITE);
    vis_VisContextSetABCColor(vc, COLORMAP_SET_GRAY50, COLORMAP_SET_GRAY30, COLORMAP_SET_GRAY70);
    vis_VisContextSetDeviceOffset(vc, 40, 10);

    /* create billboard object */
    billboard = vis_BillboardBegin();
    vis_BillboardSetObject(billboard, VGL_DRAWFUN, df);
    vis_BillboardSetObject(billboard, VIS_COLORMAP, cmap);
    vis_BillboardSetObject(billboard, VIS_VISCONTEXT, vc);

    /* enter contents of billboard */
    vis_BillboardSetItemParami(billboard, BILLBOARD_COLOR, COLORMAP_SET_BLUE);
    vis_BillboardTitleItem(billboard, (Vchar*)"Custom");
    vis_BillboardTitleItem(billboard, (Vchar*)"Color Legend");
    vis_BillboardSetItemParami(billboard, BILLBOARD_COLOR, COLORMAP_SET_GRAY70);
    vis_BillboardSetItemParami(billboard, BILLBOARD_SHADOW_COLOR, COLORMAP_SET_GRAY30);
    vis_BillboardRuleItem(billboard);
    vis_BillboardNewLine(billboard, 2.0);
    width = 4.0;
    height = 2.5;

    /* add a series of colored boxes for a legend */
    for (i = 0; i < 6; i++) {
        sprintf(str, "value %d", i + 1);
        vis_BillboardSetItemParami(billboard, BILLBOARD_COLOR, COLORMAP_SET_RED + i);
        vis_BillboardRectangleItem(billboard, width, height, 1);

        /* backspace to outline in black */
        vis_BillboardSpace(billboard, -width);
        vis_BillboardSetItemParami(billboard, BILLBOARD_COLOR, COLORMAP_SET_BLACK);
        vis_BillboardRectangleItem(billboard, width, height, 0);

        /* offset to draw text after rectangle */
        offset[0] = 2.0;
        offset[1] = 1.0;
        vis_BillboardSetItemParamfv(billboard, BILLBOARD_OFFSET, offset);
        vis_BillboardSetItemParami(billboard, BILLBOARD_COLOR, COLORMAP_SET_RED + i);
        vis_BillboardTextItem(billboard, str);
        offset[0] = 0.0;
        offset[1] = 0.0;
        vis_BillboardSetItemParamfv(billboard, BILLBOARD_OFFSET, offset);

        if (i != 5) {
            vis_BillboardNewLine(billboard, height);
        }
    }
    /* turn on drawing of offset vector */
    vis_BillboardSetParami(billboard, BILLBOARD_OFFSET_VECTOR, VIS_ON);

    /* draw billboard and wireframe cell */
    for (i = 0; i < 340; i++) {
        vgl_DrawFunClear(df);
        vgl_DrawFunXfmPush(df);
        vgl_XfmRotate(xfm, i * .03F, XFM_YAXIS);
        vgl_XfmGetMatrix(xfm, tm);
        vgl_DrawFunXfmLoad(df, tm);
        vgl_XfmRotate(xfm, i * .01F, XFM_XAXIS);
        vgl_XfmGetMatrix(xfm, tm);
        vgl_DrawFunXfmMult(df, tm);
        vis_VisContextTouch(vccell);
        vis_CellCurv(cell, xhex);
        vis_VisContextTouch(vc);
        vgl_DrawFunSetMode(df, VGL_LIGHTMODE, VGL_OFF);
        vis_BillboardDraw(billboard, xhex[4]);
        vgl_DrawFunSetMode(df, VGL_LIGHTMODE, VGL_ON);
        vgl_DrawFunXfmPop(df);
        vgl_DrawFunSwap(df);
        vgl_DrawFunDelay(df, .05f);
    }

    vgl_DrawFunDelay(df, 5.);

    /* close window */
    vgl_DrawFunCloseWindow(df);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_VisContextEnd(vccell);
    vis_ColorMapEnd(cmap);
    vgl_OpenGLDevEnd(ogldev);
    vgl_XfmEnd(xfm);
    vis_BillboardEnd(billboard);
    vis_CellEnd(cell);

    /* disconnect */
    vgl_OpenGLDevDisconnect();
#ifdef VKI_WIND_X11
    XCloseDisplay(display);
#endif
    return 0;
}
