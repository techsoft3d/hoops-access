#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vfloat xquad[8][3] = {{-1., -1., 0.},  {1., -1., 0.},  {1., 1., 0.}, {-1., 1., 0.},
                             {0., -1.1f, 0.}, {1., 0., 0.1f}, {0., 1., 0.}, {-1., 0., 0.2f}};

static Vfloat xline[3][3] = {{-1., -1., 0.}, {0., -1.1f, 0.}, {1., -1., 0.}};

static Vfloat xtitle[3] = {-1.5f, 1.5f, 0.};

/* Red,Green,Blue components of entity Colormap */
static Vfloat gray[3] = {.6f, .6f, .6f};
static Vfloat white[3] = {1., 1., 1.};
static Vfloat lightblue[3] = {.5, .5, 1.};

/* scalar element node face pressures */
static Vfloat pres[8] = {1., 2., 7., 4., 1.5f, 3.5f, 5.5f, 2.5f};
/* scalar element node line moments */
static Vfloat moment[3] = {1., 3., 2.5};

/*----------------------------------------------------------------------
                      Draw Distributed Loads
----------------------------------------------------------------------*/
int
main()
{
#ifdef VKI_WIND_X11
    Display* display;
    int screen;
#endif
    vis_Face* face;
    vis_Edge* edge;
    vis_Contour* contour;
    vis_Mark* mark;
    vis_VisContext *vc, *vccontour, *vcmark;
    vis_Levels* levels;
    vis_ColorMap *cmapiso, *cmap;
    vis_TransMap* tmap;
    vgl_DrawFun* df;
    vgl_OpenGLDev* ogldev;
    vgl_Xfm* xfm;

    Vint i, j, k, n;
    Vfloat tm[4][4], cl[3], xl[3];
    Vfloat vec[8][3], norm[8][3], xo[8][3], sc, tang[3][3];
    Vfloat enl[8][3], vcl[8][3];
    Vfloat rx[3][3], ry[3][3], d[3], ang, xv[3], xe[6][3], ve[6][3];
    Vfloat trans;
    Vint flag;
    Vint nlevels;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* connect to window system */
#ifdef VKI_WIND_X11
    if (vgl_OpenGLDevTestX(&flag), flag == 0) {
        printf("OpenGL not enabled, exiting\n");
        return 1;
    }
    display = XOpenDisplay(0);
    screen = DefaultScreen(display);
    vgl_OpenGLDevConnectX(display, screen);
#endif
#ifdef VKI_WIND_WIN32
    if (vgl_OpenGLDevTestWIN(&flag), flag == 0) {
        printf("OpenGL not enabled, exiting\n");
        return 1;
    }
    vgl_OpenGLDevConnectWIN();
#endif

    /* create OpenGL device */
    ogldev = vgl_OpenGLDevBegin();
    df = vgl_DrawFunBegin();
    vgl_OpenGLDevDrawFun(ogldev, df);
    vgl_DrawFunPositionWindow(df, 200, 200, 600, 600);
    vgl_DrawFunOpenWindow(df, "Example 11avgl");
    vgl_DrawFunProjOrtho(df, -2.0, 2.0, -2.0, 2.0, -10., 10.);
    vgl_DrawFunSetMode(df, VGL_ZBUFFERMODE, VGL_ON);
    vgl_DrawFunSetMode(df, VGL_LIGHTMODE, VGL_ON);
    cl[0] = .7f;
    cl[1] = .7f;
    cl[2] = .7f;
    xl[0] = 0.;
    xl[1] = 0.;
    xl[2] = 0.;
    vgl_DrawFunLight(df, 0, VGL_LIGHT_AMBIENT, cl, xl);
    cl[0] = .5f;
    cl[1] = .5f;
    cl[2] = .5f;
    xl[0] = 1.f;
    xl[1] = 1.;
    xl[2] = 1.;
    vgl_DrawFunLight(df, 1, VGL_LIGHT_DISTANT, cl, xl);

    /* create transformation object */
    xfm = vgl_XfmBegin();

    /* edge/face vis context */
    vc = vis_VisContextBegin();
    vis_VisContextSetRefinement(vc, 2);
    vis_VisContextSetShade(vc, VIS_VERTEXSHADE);

    /* edge/face color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 1, 1, &gray);
    vis_ColorMapSetRGB(cmap, 1, 2, &white);
    vis_ColorMapSetRGB(cmap, 1, 3, &lightblue);

    /* transparency map */
    trans = .5;
    tmap = vis_TransMapBegin();
    vis_TransMapSetType(tmap, TRANSMAP_FACTOR);
    vis_TransMapSetTrans(tmap, 1, 1, &trans);

    /* create face object and set objects */
    face = vis_FaceBegin();
    vis_FaceSetObject(face, VGL_DRAWFUN, df);
    vis_FaceSetObject(face, VIS_VISCONTEXT, vc);
    vis_FaceSetObject(face, VIS_COLORMAP, cmap);
    vis_FaceSetObject(face, VIS_TRANSMAP, tmap);

    /* create edge object and set objects */
    edge = vis_EdgeBegin();
    vis_EdgeSetObject(edge, VGL_DRAWFUN, df);
    vis_EdgeSetObject(edge, VIS_VISCONTEXT, vc);
    vis_EdgeSetObject(edge, VIS_COLORMAP, cmap);

    /* define levels */
    nlevels = 12;
    levels = vis_LevelsBegin();
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);

    /* generate load color maps */
    cmapiso = vis_ColorMapBegin();
    vis_ColorMapSetType(cmapiso, COLORMAP_TRUECOLOR);
    vis_ColorMapRamp(cmapiso, nlevels, 1, COLORMAP_HUE);

    /* mark vis context */
    vcmark = vis_VisContextBegin();
    vis_VisContextSetMapSize(vcmark, SYS_ON);
    vis_VisContextSetSize(vcmark, 1.);
    vis_VisContextSetMapColor(vcmark, VIS_MAPCOLOR_SMOOTH);

    /* distributed load vectors */
    mark = vis_MarkBegin();
    vis_MarkSetObject(mark, VGL_DRAWFUN, df);
    vis_MarkSetObject(mark, VIS_VISCONTEXT, vcmark);
    vis_MarkSetObject(mark, VIS_LEVELS, levels);
    vis_MarkSetObject(mark, VIS_COLORMAP, cmapiso);

    /* setup contour object */
    vccontour = vis_VisContextBegin();
    vis_VisContextSetIsoValType(vccontour, VIS_ISOVALFRINGE);
    vis_VisContextSetRefinement(vccontour, 2);
    vis_VisContextSetShade(vccontour, VIS_VERTEXSHADE);
    vis_VisContextSetTrans(vccontour, 1);

    contour = vis_ContourBegin();
    vis_ContourSetObject(contour, VGL_DRAWFUN, df);
    vis_ContourSetObject(contour, VIS_VISCONTEXT, vccontour);
    vis_ContourSetObject(contour, VIS_LEVELS, levels);
    vis_ContourSetObject(contour, VIS_COLORMAP, cmapiso);
    vis_ContourSetObject(contour, VIS_TRANSMAP, tmap);

    /* draw pressure */
    vis_LevelsSetMinMax(levels, 0., 7.);
    vis_LevelsGenerate(levels, LEVELS_PADTOP);
    for (i = 1; i <= 20; i++) {
        vgl_DrawFunClear(df);
        vgl_DrawFunColor(df, white);
        vgl_DrawFunText(df, xtitle, (Vchar*)"Distributed pressure surface");

        vgl_DrawFunXfmPush(df);
        vgl_XfmRotate(xfm, -(i - 1) * 8.F * 3.14F / 180.F, XFM_YAXIS);
        vgl_XfmGetMatrix(xfm, tm);
        vgl_DrawFunXfmLoad(df, tm);

        /* draw element face - gray, opaque */
        vis_VisContextSetColor(vc, 1);
        vis_VisContextSetTrans(vc, 0);
        vis_FaceSetTopology(face, SYS_SHAPEQUAD, 3, 0);
        vis_FaceCurv(face, xquad, VIS_NODATA, NULL);

        /* compute pressure sized normal to surface */
        vis_FaceComputeNorm(face, xquad, norm);
        for (n = 0; n < 8; n++) {
            vec[n][0] = -pres[n] * norm[n][0];
            vec[n][1] = -pres[n] * norm[n][1];
            vec[n][2] = -pres[n] * norm[n][2];
        }
        /* draw vectors at face nodes */
        vis_VisContextSetRefinement(vcmark, 1);
        vis_VisContextSetVectorType(vcmark, VIS_VECTORUMBRELLA);
        vis_VisContextSetFlags(vcmark, VIS_VECTORTAIL);
        vis_MarkVector(mark, 8, vec, xquad);

        /* draw pressure colored offset face */
        /* compute locations of vector tails for pressure face */
        for (n = 0; n < 8; n++) {
            vis_MarkVectorCompute(mark, vec[n], xquad[n], &sc, &xo[n]);
        }
        vis_VisContextTouch(vccontour);
        vis_ContourSetTopology(contour, SYS_SHAPEQUAD, 3, 0);
        vis_ContourCurv(contour, pres, xo, VIS_VERTEXDATA, norm);

        vgl_DrawFunSwap(df);
        vgl_DrawFunDelay(df, 1.);

        /* show equivalent nodal loads on eighth frame */
        if (i == 8) {
            vgl_DrawFunClear(df);
            vgl_DrawFunColor(df, white);
            vgl_DrawFunText(df, xtitle, (Vchar*)"Equivalent nodal loads");

            vis_VisContextTouch(vc);
            vis_FaceCurv(face, xquad, VIS_NODATA, NULL);
            vis_FaceComputeDist(face, xquad, 3, (Vfloat*)vec, (Vfloat*)enl);
            vis_MarkVector(mark, 8, enl, xquad);

            vgl_DrawFunSwap(df);
            vgl_DrawFunDelay(df, 2.);
        }

        /* show and recover original tractions on eighth frame */
        if (i == 8) {
            vgl_DrawFunClear(df);
            vgl_DrawFunColor(df, white);
            vgl_DrawFunText(df, xtitle, (Vchar*)"Recover original tractions");

            vis_VisContextTouch(vc);
            vis_FaceCurv(face, xquad, VIS_NODATA, NULL);
            vis_FaceConvertDist(face, xquad, 3, (Vfloat*)enl, (Vfloat*)vcl);
            vis_MarkVector(mark, 8, vcl, xquad);

            vgl_DrawFunSwap(df);
            vgl_DrawFunDelay(df, 2.);
        }

        vgl_DrawFunXfmPop(df);
    }

    /* draw edge moment */
    vis_LevelsSetMinMax(levels, 0., 3.);
    vis_LevelsGenerate(levels, LEVELS_PADTOP);
    for (i = 0; i < 20; i++) {
        vgl_DrawFunClear(df);
        vgl_DrawFunColor(df, white);
        vgl_DrawFunText(df, xtitle, (Vchar*)"Distributed edge moment");

        vgl_DrawFunXfmPush(df);
        vgl_XfmRotate(xfm, -i * 8.F * 3.14F / 180.F, XFM_YAXIS);
        vgl_XfmGetMatrix(xfm, tm);
        vgl_DrawFunXfmLoad(df, tm);

        /* draw face */
        vis_VisContextSetColor(vc, 1);
        vis_VisContextSetTrans(vc, 0);
        vis_FaceSetTopology(face, SYS_SHAPEQUAD, 3, 0);
        vis_FaceCurv(face, xquad, VIS_NODATA, NULL);

        /* draw edge */
        vis_VisContextSetColor(vc, 2);
        vis_VisContextSetLineWidth(vc, 2);
        vis_EdgeSetTopology(edge, SYS_SHAPELINE, 3);
        vis_EdgeCurv(edge, xline);
        /* compute tangent to edge and scale vector by moment */
        vis_EdgeComputeTang(edge, xline, tang);
        for (n = 0; n < 3; n++) {
            vec[n][0] = tang[n][0] * moment[n];
            vec[n][1] = tang[n][1] * moment[n];
            vec[n][2] = tang[n][2] * moment[n];
        }
        /* draw round moment vectors along edge */
        vis_VisContextSetRefinement(vcmark, 2);
        vis_VisContextSetVectorType(vcmark, VIS_VECTORCYLINDER);
        vis_VisContextSetFlags(vcmark, VIS_VECTORTAIL | VIS_VECTORROUND);
        vis_MarkVector(mark, 3, vec, xline);

        /* connect moment arrows with transparent surface */
        /* compute local x', y' directions perpendicular to edge
           and marker radius */
        for (n = 0; n < 3; n++) {
            vis_MarkVectorCompute(mark, vec[n], xline[n], &sc, &xo[n]);
            rx[n][0] = xo[n][0] - xline[n][0];
            rx[n][1] = xo[n][1] - xline[n][1];
            rx[n][2] = xo[n][2] - xline[n][2];

            ry[n][0] = tang[n][1] * rx[n][2] - tang[n][2] * rx[n][1];
            ry[n][1] = tang[n][2] * rx[n][0] - tang[n][0] * rx[n][2];
            ry[n][2] = tang[n][0] * rx[n][1] - tang[n][1] * rx[n][0];

            d[n] = (Vfloat)sqrt(rx[n][0] * rx[n][0] + rx[n][1] * rx[n][1] + rx[n][2] * rx[n][2]);
        }
        /* draw surface - lightblue, transparent */
        vis_VisContextSetColor(vc, 3);
        vis_VisContextSetTrans(vc, 1);
        for (j = 0; j < 12; j++) {
            for (k = 0; k < 2; k++) {
                ang = 2.F * (j + k) / 12.F * 3.14159F;
                xv[0] = (Vfloat)cos(ang);
                xv[1] = (Vfloat)sin(ang);
                xv[2] = 0.;
                /* compute coordinates and normals of a 3 by 2 strip */
                for (n = 0; n < 3; n++) {
                    xe[n + 3 * k][0] = xline[n][0] + xv[0] * rx[n][0] + xv[1] * ry[n][0];
                    xe[n + 3 * k][1] = xline[n][1] + xv[0] * rx[n][1] + xv[1] * ry[n][1];
                    xe[n + 3 * k][2] = xline[n][2] + xv[0] * rx[n][2] + xv[1] * ry[n][2];
                    ve[n + 3 * k][0] = (xe[n + 3 * k][0] - xline[n][0]) / d[n];
                    ve[n + 3 * k][1] = (xe[n + 3 * k][1] - xline[n][1]) / d[n];
                    ve[n + 3 * k][2] = (xe[n + 3 * k][2] - xline[n][2]) / d[n];
                }
            }
            /* draw strip with face object */
            vis_FaceSetTopology(face, SYS_SHAPEQUAD, 3, 2);
            vis_FaceCurv(face, xe, VIS_VERTEXDATA, ve);
        }

        vgl_DrawFunXfmPop(df);
        vgl_DrawFunSwap(df);
        vgl_DrawFunDelay(df, 1.);
    }
    vgl_DrawFunDelay(df, 5.);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vgl_OpenGLDevEnd(ogldev);
    vgl_XfmEnd(xfm);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_TransMapEnd(tmap);
    vis_FaceEnd(face);
    vis_EdgeEnd(edge);
    vis_LevelsEnd(levels);
    vis_ColorMapEnd(cmapiso);
    vis_MarkEnd(mark);
    vis_VisContextEnd(vcmark);
    vis_VisContextEnd(vccontour);
    vis_ContourEnd(contour);

    /* disconnect from window system */
    vgl_OpenGLDevDisconnect();
#ifdef VKI_WIND_X11
    XCloseDisplay(display);
#endif
    return 0;
}
