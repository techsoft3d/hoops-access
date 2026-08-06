#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vfloat rgb[12][3] = {{0., 0., 1.},     {0., 0.2f, 0.8f}, {0., 0.4f, 0.6f}, {0., 0.6f, 0.4f},
                            {0., 0.8f, 0.2f}, {0., 1.f, 0.},    {0.2f, 0.8f, 0.}, {0.4f, 0.6f, 0.},
                            {0.6f, 0.4f, 0.}, {0.8f, 0.2f, 0.}, {1., 0., 0.},     {1., 1., 1.}};
static Vint nlevels = 10;
static Vint ndiv = 10;
static Vfloat white[3] = {1., 1., 1.};

static void
draw_scene(vgl_DrawFun* df, vgl_DList* dlist, vis_IsoLabel* isolabel, vis_VisContext* vc, vgl_RasFont* rasfont, Vint sizetype,
           Vfloat size, Vint textplane, Vint mapcolor, Vchar title[])
{
    Vint parami[4];
    Vfloat paramf[16], xtitle[3];

    /* draw title with default screen oriented font */
    vgl_DrawFunRasFontSelect(df, 0);
    xtitle[0] = -2.9f;
    xtitle[1] = 2.7f;
    xtitle[2] = 0.;
    vgl_DrawFunColor(df, white);
    vgl_DrawFunText(df, xtitle, title);

    /* draw contour lines */
    vgl_DListCall(dlist);

    /* pass screen parameters to VisContext */
    vgl_DrawFunGetFloat(df, VGL_PROJECTIONMATRIX, paramf);
    vis_VisContextSetProjMatrix(vc, (Vfloat(*)[4])paramf);
    vgl_DrawFunGetFloat(df, VGL_MODELVIEWMATRIX, paramf);
    vis_VisContextSetXfmMatrix(vc, (Vfloat(*)[4])paramf);
    vgl_DrawFunGetInteger(df, VGL_VIEWPORT, parami);
    vis_VisContextSetViewport(vc, parami[0], parami[1], parami[2], parami[3]);

    /* set IsoLabel paramters */
    /* turn on user labels when doing world sizing */
    vis_VisContextSetSizeType(vc, sizetype);
    if (sizetype == VIS_SIZEDEVICE) {
        vis_VisContextSetDeviceSize(vc, (Vint)size);
    }
    else {
        vis_VisContextSetSize(vc, size);
        vis_IsoLabelSetParami(isolabel, ISOLABEL_LABELUSELEVELS, SYS_ON);
    }
    /* set color mapping mode */
    vis_VisContextSetMapColor(vc, mapcolor);

    /* set RasFont text plane mode */
    vgl_RasFontSetParami(rasfont, RASFONT_TEXTPLANE, textplane);
    /* OpenGLDev must reconfigure changed RasFont */
    vgl_DrawFunRasFontDefine(df, 1, rasfont);
    vgl_DrawFunRasFontSelect(df, 1);
    vis_IsoLabelSetParami(isolabel, ISOLABEL_TEXTPLANE, textplane);

    /* draw labels */
    vis_IsoLabelDraw(isolabel);
}

static void
generate_contour(vis_Contour* contour)
{
    Vint i, j, n;
    Vfloat x[4][3], s[4];

    /* set all Z coordinates to zero */
    x[0][2] = x[1][2] = x[2][2] = x[3][2] = 0.;
    /* use ContourCurv to draw lines */
    vis_ContourSetTopology(contour, SYS_SHAPEQUAD, 0, 0);
    for (i = 0; i < ndiv; ++i) {
        /* set x coordinates */
        x[0][0] = -1.8F + i * 3.6F / ndiv;
        x[1][0] = -1.8F + (i + 1) * 3.6F / ndiv;
        x[2][0] = x[1][0];
        x[3][0] = x[0][0];
        for (j = 0; j < ndiv; ++j) {
            /* set y coordinates */
            x[0][1] = -1.8F + j * 3.6F / ndiv;
            x[1][1] = x[0][1];
            x[2][1] = -1.8F + (j + 1) * 3.6F / ndiv;
            x[3][1] = x[2][1];

            /* compute distance from center as field to display */
            for (n = 0; n < 4; ++n) {
                s[n] = (Vfloat)sqrt(x[n][0] * x[n][0] + x[n][1] * x[n][1]);
            }
            vis_ContourCurv(contour, s, x, VIS_NODATA, NULL);
        }
    }
}

/*----------------------------------------------------------------------
                      Draw Contour Line Labels Using IsoLabel
----------------------------------------------------------------------*/
int
main()
{
#ifdef VKI_WIND_X11
    Display* display;
    int screen;
#endif
    Vint i;
    Vfloat sizepix;
    Vchar label[16];
    vgl_DrawFun *dfGL, *dfDL;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_IsoLabel* isolabel;
    vis_Contour* contour;
    vis_Levels* levels;
    vgl_OpenGLDev* ogldev;
    vgl_RasFont* rasfont;
    vgl_DList* dlist;

    vsy_LicenseValidate(HOOPS_LICENSE);

#ifdef VKI_WIND_X11
    /* open X display */
    display = XOpenDisplay(0);
    screen = DefaultScreen(display);
    vgl_OpenGLDevConnectX(display, screen);
#endif
#ifdef VKI_WIND_WIN32
    vgl_OpenGLDevConnectWIN();
#endif
    /* create GL device */
    ogldev = vgl_OpenGLDevBegin();

    /* create draw function object for GL */
    dfGL = vgl_DrawFunBegin();
    vgl_OpenGLDevDrawFun(ogldev, dfGL);

    vgl_DrawFunPositionWindow(dfGL, 200, 200, 800, 800);
    vgl_DrawFunOpenWindow(dfGL, "Example 10cvgl");
    vgl_DrawFunProjOrtho(dfGL, -3., 3., -3., 3., -1., 1.);
    /*
     * IsoLabel always uses VGL_BOTTOM, but it must
     * know what the VGL_TEXTANCHORMODE has been set to
     * so it can compensate for it
     */
    vgl_DrawFunSetMode(dfGL, VGL_TEXTANCHORMODE, VGL_BOTTOMLEFT);

    /* create draw function object for DList */
    dlist = vgl_DListBegin();
    dfDL = vgl_DrawFunBegin();
    vgl_DListDrawFun(dlist, dfDL);
    vgl_DListSetObject(dlist, VGL_DRAWFUN, (Vobject*)dfGL);

    /* create objects */
    vc = vis_VisContextBegin();
    cmap = vis_ColorMapBegin();
    levels = vis_LevelsBegin();
    isolabel = vis_IsoLabelBegin();
    contour = vis_ContourBegin();
    rasfont = vgl_RasFontBegin();

    /* configure ColorMap */
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 12, 0, rgb);

    /* configure Levels */
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, 0., 3.);
    vis_LevelsGenerate(levels, LEVELS_PADENDS);
    /* user defined labels at levels */
    for (i = 1; i <= nlevels; i++) {
        sprintf(label, "level %d", i);
        vis_LevelsSetLabel(levels, i, label);
    }
    /* configure Contour */
    vis_ContourSetObject(contour, VGL_DRAWFUN, dfDL);
    vis_ContourSetObject(contour, VIS_ISOLABEL, isolabel);
    vis_ContourSetObject(contour, VIS_VISCONTEXT, vc);
    vis_ContourSetObject(contour, VIS_COLORMAP, cmap);
    vis_ContourSetObject(contour, VIS_LEVELS, levels);
    /* tell Contour to generate data for IsoLabel */
    vis_ContourSetParami(contour, CONTOUR_ISOVALDATA, SYS_ON);

    /* configure IsoLabel */
    vis_IsoLabelSetObject(isolabel, VIS_VISCONTEXT, vc);
    vis_IsoLabelSetObject(isolabel, VIS_COLORMAP, cmap);
    vis_IsoLabelSetObject(isolabel, VIS_LEVELS, levels);
    vis_IsoLabelSetObject(isolabel, VGL_DRAWFUN, dfGL);

    vis_IsoLabelSetParami(isolabel, ISOLABEL_TEXTPLANE, SYS_ON);

    /* add labels to every other level */
    vis_IsoLabelSetParami(isolabel, ISOLABEL_LINEFREQUENCY, 2);

    /* use numeric values, not pre-defined string labels */
    vis_IsoLabelSetParami(isolabel, ISOLABEL_LABELUSELEVELS, SYS_OFF);

    /* tolerance to merge lines from Contour */
    vis_VisContextSetDistTol(vc, 0.01f);

    /* segment curvature tolerance to skip labeling */
    vis_IsoLabelSetParamf(isolabel, ISOLABEL_CURVFRAC, 0.05f);

    /* flag to not allow overlap of labels */
    vis_IsoLabelSetParami(isolabel, ISOLABEL_OVERLAP, SYS_OFF);

    /* configure RasFont */
    vgl_RasFontLoad(rasfont, RASFONT_QUALITY9X13);
    vgl_RasFontSetParami(rasfont, RASFONT_DEVICESIZE, SYS_ON);
    vgl_DrawFunRasFontDefine(dfGL, 1, rasfont);
    vgl_DrawFunRasFontSelect(dfGL, 1);

    /* configure VisContext */
    /* white constant color */
    vis_VisContextSetColor(vc, 11);
    /* draw dot where label is positioned */
    vis_VisContextSetSpot(vc, SYS_ON);
    vis_VisContextSetPointSize(vc, 4);

    /* set TEXTANCHORMODE as used by DrawFun */
    vis_VisContextSetPosition(vc, VGL_BOTTOMLEFT);

    /* specify floating point format for label */
    vis_VisContextSetFormat(vc, VIS_FMFORMAT);

    /* space labels based on device (pixels) distance */
    vis_VisContextSetSizeType(vc, VIS_SIZEDEVICE);

    /* space labels at approximately 200 pixels on lines */
    vis_VisContextSetDeviceSize(vc, 200);

    /* offset label 3 pixels away from lines */
    vis_VisContextSetDeviceOffset(vc, 0, 3);

    /* always orient labels so they read left to right */
    vis_VisContextSetFlags(vc, VIS_BACKPLANEFLIP);

    /* specify raster font character sizes */
    vis_VisContextSetTextBox(vc, 9, 13);

    /* for Contour object, generate lines */
    vis_VisContextSetIsoValType(vc, VIS_ISOVALLINE);
    vis_VisContextSetMapColor(vc, VIS_MAPCOLOR_SMOOTH);

    /* generate contour */
    vis_IsoLabelReset(isolabel);
    generate_contour(contour);

    /* draw */
    /* vary the device size */
    for (i = 1; i <= 5; i++) {
        vgl_DrawFunClear(dfGL);
        sizepix = i * 20.F;
        draw_scene(dfGL, dlist, isolabel, vc, rasfont, VIS_SIZEDEVICE, sizepix, SYS_ON, VIS_MAPCOLOR_SMOOTH,
                   (Vchar*)"SIZE=DEVICE, TEXTPLANE=SYS_ON, MAPCOLOR=SMOOTH");
        vgl_DrawFunSwap(dfGL);
        vgl_DrawFunDelay(dfGL, 2.);
    }
    /* do not output oriented labels */
    vgl_DrawFunClear(dfGL);
    draw_scene(dfGL, dlist, isolabel, vc, rasfont, VIS_SIZEDEVICE, 200., SYS_OFF, VIS_MAPCOLOR_SMOOTH,
               (Vchar*)"SIZE=DEVICE, TEXTPLANE=SYS_OFF, MAPCOLOR=SMOOTH");
    vgl_DrawFunSwap(dfGL);
    vgl_DrawFunDelay(dfGL, 5.);
    /* constant color, white, labels */
    vgl_DrawFunClear(dfGL);
    draw_scene(dfGL, dlist, isolabel, vc, rasfont, VIS_SIZEDEVICE, 200., SYS_OFF, VIS_MAPCOLOR_NONE,
               (Vchar*)"SIZE=DEVICE, TEXTPLANE=SYS_OFF, MAPCOLOR=NONE");
    vgl_DrawFunSwap(dfGL);
    vgl_DrawFunDelay(dfGL, 5.);
    /* world coordinate spacing of oriented labels */
    vgl_DrawFunClear(dfGL);
    draw_scene(dfGL, dlist, isolabel, vc, rasfont, VIS_SIZEWORLD, 0.5, SYS_ON, VIS_MAPCOLOR_SMOOTH,
               (Vchar*)"SIZE=WORLD, TEXTPLANE=SYS_ON, MAPCOLOR=SMOOTH");
    vgl_DrawFunSwap(dfGL);
    vgl_DrawFunDelay(dfGL, 5.);

    /* close window */
    vgl_DrawFunCloseWindow(dfGL);
    /* disconnect */
    vgl_OpenGLDevDisconnect();
#ifdef VKI_WIND_X11
    XCloseDisplay(display);
#endif
    /* free all objects */
    vgl_RasFontEnd(rasfont);
    vis_ContourEnd(contour);
    vis_IsoLabelEnd(isolabel);
    vis_LevelsEnd(levels);
    vis_ColorMapEnd(cmap);
    vis_VisContextEnd(vc);
    vgl_DrawFunEnd(dfGL);
    vgl_DrawFunEnd(dfDL);
    vgl_DListEnd(dlist);
    vgl_OpenGLDevEnd(ogldev);
    return 0;
}
