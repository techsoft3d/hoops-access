#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

void
gatherx(Vfloat x[][3], Vint npts, Vint con[], Vfloat xe[][3]);
void
gathers(Vfloat s[], Vint npts, Vint con[], Vfloat se[]);

/* Finite Element Model */
#define MAX_ELEM 2
#define MAX_NODE 5

static Vfloat x[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {0., 1., 0.}, {1., 1., 0.}};

static Vfloat s[MAX_NODE] = {1., 2., 3.5, 4., 3.};

static Vint numconn[MAX_ELEM] = {4, 3};

static Vint conn[MAX_ELEM][4] = {{1, 2, 5, 4}, {2, 3, 5, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEQUAD, VIS_SHAPETRI};

/* Isovalue Types */
static Vint isovaltype[6] = {VIS_ISOVALPOINT,   VIS_ISOVALLINE, VIS_ISOVALFRINGE,
                             VIS_ISOVALTEXTURE, VIS_ISOVALTONE, VIS_ISOVALGOURAUD};

static Vchar* isovalname[6] = {(Vchar*)"VIS_ISOVALPOINT",   (Vchar*)"VIS_ISOVALLINE", (Vchar*)"VIS_ISOVALFRINGE",
                               (Vchar*)"VIS_ISOVALTEXTURE", (Vchar*)"VIS_ISOVALTONE", (Vchar*)"VIS_ISOVALGOURAUD"};

static Vfloat xname[3] = {0., 2., 0.};

static Vfloat cname[3] = {1., 1., 1.};

static Vfloat xref[3] = {0., 2.25, 0.};

/*----------------------------------------------------------------------
                      Generate Isovalue Displays on Element Faces
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
    vis_Contour* contour;
    vgl_OpenGLDev* ogldev;
    vgl_Texture* texture;

    int i, j, k;
    Vint nlevels;
    Vfloat xe[4][3], se[4];
    Vfloat ctexture[256][3];
    Vchar text[33];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* connect to window system */
#ifdef VKI_WIND_X11
    display = XOpenDisplay(0);
    screen = DefaultScreen(display);
    vgl_OpenGLDevConnectX(display, screen);
#endif
#ifdef VKI_WIND_WIN32
    vgl_OpenGLDevConnectWIN();
#endif

    /* create OpenGL device */
    ogldev = vgl_OpenGLDevBegin();

    /* create drawing function object for OpenGL */
    df = vgl_DrawFunBegin();
    vgl_OpenGLDevDrawFun(ogldev, df);

    vgl_DrawFunPositionWindow(df, 200, 200, 400, 400);
    vgl_DrawFunOpenWindow(df, "Example 10vgl");
    vgl_DrawFunProjOrtho(df, -1., 3., -1., 3., -2., 2.);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();

    /* levels, set three evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 12;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, 1., 4.);
    vis_LevelsGenerate(levels, LEVELS_PADTOP);

    /* color map and set drawing functions */
    cmap = vis_ColorMapBegin();
    vis_ColorMapRamp(cmap, nlevels, 1, COLORMAP_HUE);
    vis_ColorMapLevelsGetColors(cmap, levels, COLORMAP_FRINGE, 256, ctexture);

    /* create contour object and set objects */
    contour = vis_ContourBegin();
    vis_ContourSetObject(contour, VGL_DRAWFUN, df);
    vis_ContourSetObject(contour, VIS_VISCONTEXT, vc);
    vis_ContourSetObject(contour, VIS_LEVELS, levels);
    vis_ContourSetObject(contour, VIS_COLORMAP, cmap);

    /* create texture object */
    texture = vgl_TextureBegin();
    vgl_TextureDef(texture, 3, 256, 1);
    vgl_TextureSetColors(texture, (Vfloat*)ctexture);
    vgl_DrawFunTextureDefine(df, 1, texture);

    /* loop through refinement levels */
    for (k = 0; k < 3; k++) {
        vis_VisContextSetRefinement(vc, k);
        sprintf(text, "Refinement = %d\n", k);
        /* draw contour types */
        for (i = 0; i < 6; i++) {
            vgl_DrawFunClear(df);
            vgl_DrawFunColor(df, cname);
            vgl_DrawFunText(df, xref, text);
            vgl_DrawFunText(df, xname, isovalname[i]);
            vis_VisContextSetIsoValType(vc, isovaltype[i]);
            if (isovaltype[i] == VIS_ISOVALTEXTURE) {
                vgl_DrawFunTextureSelect(df, 1);
            }
            for (j = 0; j < MAX_ELEM; j++) {
                vis_ContourSetTopology(contour, shap[j], 2, 0);
                gatherx(x, numconn[j], conn[j], xe);
                gathers(s, numconn[j], conn[j], se);
                vis_ContourCurv(contour, se, xe, VIS_NODATA, NULL);
            }
            if (isovaltype[i] == VIS_ISOVALTEXTURE) {
                vgl_DrawFunTextureSelect(df, 0);
            }
            vgl_DrawFunSwap(df);
            vgl_DrawFunDelay(df, 2.);
        }
    }
    vgl_DrawFunDelay(df, 5.);

    /* close window */
    vgl_DrawFunCloseWindow(df);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_LevelsEnd(levels);
    vis_ColorMapEnd(cmap);
    vis_ContourEnd(contour);
    vgl_OpenGLDevEnd(ogldev);
    vgl_TextureEnd(texture);

    /* disconnect from window system */
    vgl_OpenGLDevDisconnect();
#ifdef VKI_WIND_X11
    XCloseDisplay(display);
#endif
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
