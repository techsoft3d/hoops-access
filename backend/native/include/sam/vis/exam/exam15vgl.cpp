#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Draw a Simple Billboard
----------------------------------------------------------------------*/
int
main()
{
#ifdef VKI_WIND_X11
    Display* display;
    int screen;
#else
    HFONT hfont;
#endif

    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_Billboard* billboard;
    vgl_OpenGLDev* ogldev;
    vgl_RasFont* rasfont;
#ifdef VKI_WIDECHAR
    static Vtchar euro[] = {L'U', L'n', L'i', L'c', L'o', L'd', L'e', L' ', L'E', L'u', L'r', L'o', L'=', L' ', 0x20ac, L'\0'};
#else
    static Vtchar euro[] = "Unicode Euro= euro";
#endif

    Vfloat x[3];

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

    vgl_DrawFunPositionWindow(df, 200, 200, 400, 400);
    vgl_DrawFunOpenWindow(df, "Example 15vgl");
    vgl_DrawFunProjOrtho(df, -2., 2., -2., 2., -2., 2.);
    vgl_DrawFunSetMode(df, VGL_ZBUFFERMODE, VGL_ON);

    rasfont = vgl_RasFontBegin();
#ifdef VKI_WIND_X11
    vgl_RasFontLoadXFont(rasfont, display, (Vchar*)"-adobe-courier-bold-o-normal--14-100-100-100-m-90-iso10646-1");
#else
    hfont = CreateFont(15, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FIXED_PITCH | FF_DONTCARE, TEXT("Arial"));
    vgl_RasFontLoadWINFont(rasfont, hfont);
#endif
    vgl_DrawFunRasFontDefine(df, 1, rasfont);

    /* color map, standard set of 29 colors */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapRamp(cmap, 29, 0, COLORMAP_SET);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetMapColor(vc, VIS_OFF);
    vis_VisContextSetColor(vc, COLORMAP_SET_GRAY40);
    vis_VisContextSetABCColor(vc, COLORMAP_SET_RED, COLORMAP_SET_REDDARK, COLORMAP_SET_REDLITE);

    /* create billboard object */
    billboard = vis_BillboardBegin();
    vis_BillboardSetObject(billboard, VGL_DRAWFUN, df);
    vis_BillboardSetObject(billboard, VIS_COLORMAP, cmap);
    vis_BillboardSetObject(billboard, VIS_VISCONTEXT, vc);

    /* enter contents of billboard */
    vis_BillboardSetItemParami(billboard, BILLBOARD_COLOR, COLORMAP_SET_BLUE);
    /* title automatically generate a new line */
    vis_BillboardTitleItem(billboard, (Vchar*)"Analysis Results");
    vis_BillboardSetItemParami(billboard, BILLBOARD_COLOR, COLORMAP_SET_WHITE);
    vis_BillboardSetItemParami(billboard, BILLBOARD_SHADOW_COLOR, COLORMAP_SET_GRAY20);
    vis_BillboardSetItemParami(billboard, BILLBOARD_RULE_BEVEL, VIS_ON);
    /* rule automatically generate a new line */
    vis_BillboardRuleItem(billboard);

    vis_BillboardSetItemParami(billboard, BILLBOARD_COLOR, COLORMAP_SET_CYAN);
    vis_BillboardTextItem(billboard, (Vchar*)"stress_xx = 10230.\n");
    vis_BillboardTextItem(billboard, (Vchar*)"stress_yy = 15328.\n");
    vis_BillboardTextItem(billboard, (Vchar*)"stress_zz =   556.\n");

    vis_BillboardSetItemParami(billboard, BILLBOARD_COLOR, COLORMAP_SET_BLACK);
    vis_BillboardSetItemParami(billboard, BILLBOARD_RULE_BEVEL, VIS_OFF);
    vis_BillboardSetItemParami(billboard, BILLBOARD_LINE_STYLE, VIS_DASHDASH);
    vis_BillboardRuleItem(billboard);

    vis_BillboardSetItemParami(billboard, BILLBOARD_COLOR, COLORMAP_SET_YELLOW);
    vis_BillboardTextItem(billboard, (Vchar*)"strain_xx = .00121\n");
    vis_BillboardTextItem(billboard, (Vchar*)"strain_yy = .00153\n");
    /* do not want newline after last item */
    vis_BillboardTextItem(billboard, (Vchar*)"strain_zz = .00012");

    /* define anchor point */
    x[0] = -0.5;
    x[1] = -0.5;
    x[2] = 0.0;
    /* draw billboard */
    vgl_DrawFunClear(df);
    vis_BillboardDraw(billboard, x);
    vgl_DrawFunSwap(df);
    vgl_DrawFunDelay(df, 5.);

    /* draw billboard with wide character string */
    vis_BillboardErase(billboard);
    vis_BillboardSetItemParami(billboard, BILLBOARD_COLOR, COLORMAP_SET_BLUE);
    vis_BillboardTitleItem(billboard, (Vchar*)"Product Cost");
    vis_BillboardRuleItem(billboard);
    vis_BillboardTextItemtv(billboard, euro);

    vgl_DrawFunRasFontSelect(df, 1);
    vgl_DrawFunClear(df);
    vis_BillboardDraw(billboard, x);
    vgl_DrawFunSwap(df);
    vgl_DrawFunDelay(df, 5.);

    /* close window */
    vgl_DrawFunCloseWindow(df);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vgl_RasFontEnd(rasfont);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vgl_OpenGLDevEnd(ogldev);
    vis_BillboardEnd(billboard);

    /* disconnect */
    vgl_OpenGLDevDisconnect();
#ifdef VKI_WIND_X11
    XCloseDisplay(display);
#endif
    return 0;
}
