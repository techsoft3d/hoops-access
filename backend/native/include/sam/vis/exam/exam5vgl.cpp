#include <stdlib.h>
#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
gather(Vfloat x[][3], Vint con[4], Vfloat xe[][3]);

static Vfloat xquad[9][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                             {2., 1., 0.}, {0., 2., 0.}, {1., 2., 0.}, {2., 2., 0.}};
static Vfloat vquad[9][3] = {{1., 0., 0.}, {1., 0., 0.},  {1., 1., 0.},  {0., 0., 0.}, {0., 0., 0.},
                             {0., 1., 0.}, {-1., 0., 0.}, {-1., 0., 0.}, {-1., 1., 0.}};
static Vint con[4][4] = {{1, 2, 5, 4}, {2, 3, 6, 5}, {4, 5, 8, 7}, {5, 6, 9, 8}};
static Vint adj[4][4] = {{0, 2, 3, 0}, {0, 0, 4, 1}, {1, 4, 0, 0}, {2, 0, 0, 3}};
static Vfloat rgb[7][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Generate tangent curve on quadrilateral elements
                      Use VglTools graphics library
----------------------------------------------------------------------*/
int
main()
{
#ifdef VKI_WIND_X11
    Display* display;
    int screen;
#endif

    vgl_DrawFun* df;
    vis_VisContext *vcface, *vcmark, *vctrace;
    vis_ColorMap* cmap;
    vis_Face* face;
    vis_Mark* mark;
    vis_Trace* trace;
    vgl_OpenGLDev* ogldev;
    vgl_Xfm* xfm;

    int i, j;
    Vfloat xe[4][3], ve[4][3], xc[3];
    Vint nn;
    Vfloat t;
    Vint status, edgenumber;
    Vfloat tout;
    Vfloat v[3], w[3], vout[3], wout[3];
    Vfloat tm[4][4];
    Vint flag;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* connect to window system */
#ifdef VKI_WIND_X11
    if (vgl_OpenGLDevTestX(&flag), flag == 0) {
        printf("OpenGL not enabled, exiting\n");
        exit(0);
    }
    display = XOpenDisplay(0);
    screen = DefaultScreen(display);
    vgl_OpenGLDevConnectX(display, screen);
#endif
#ifdef VKI_WIND_WIN32
    if (vgl_OpenGLDevTestWIN(&flag), flag == 0) {
        printf("OpenGL not enabled, exiting\n");
        exit(0);
    }
    vgl_OpenGLDevConnectWIN();
#endif

    /* create OpenGL device */
    ogldev = vgl_OpenGLDevBegin();

    /* create drawing function object for OpenGL */
    df = vgl_DrawFunBegin();
    vgl_OpenGLDevDrawFun(ogldev, df);

    vgl_DrawFunPositionWindow(df, 200, 200, 400, 400);
    vgl_DrawFunOpenWindow(df, "Example 5vgl");
    vgl_DrawFunProjOrtho(df, -3., 3., -3., 3., -3., 3.);

    /* create transformation object */
    xfm = vgl_XfmBegin();

    /* vis context and set attributes */
    vcface = vis_VisContextBegin();
    vis_VisContextSetEdge(vcface, VIS_ON);
    vis_VisContextSetFill(vcface, VIS_OFF);
    vis_VisContextSetColor(vcface, 4);

    vcmark = vis_VisContextBegin();
    vis_VisContextSetFlags(vcmark, VIS_VECTORTAIL | VIS_VECTORTAILREGISTER);
    vis_VisContextSetVectorType(vcmark, VIS_VECTORCYLINDER);
    vis_VisContextSetSize(vcmark, .5);
    vis_VisContextSetMapColor(vcmark, VIS_OFF);
    vis_VisContextSetColor(vcmark, 1);

    vctrace = vis_VisContextBegin();
    vis_VisContextSetLineWidth(vctrace, 2);
    vis_VisContextSetColor(vctrace, 6);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 7, 0, rgb);

    /* create face object and set objects */
    face = vis_FaceBegin();
    vis_FaceSetObject(face, VGL_DRAWFUN, df);
    vis_FaceSetObject(face, VIS_VISCONTEXT, vcface);
    vis_FaceSetObject(face, VIS_COLORMAP, cmap);

    /* create mark object and set objects */
    mark = vis_MarkBegin();
    vis_MarkSetObject(mark, VGL_DRAWFUN, df);
    vis_MarkSetObject(mark, VIS_VISCONTEXT_VECTOR, vcmark);
    vis_MarkSetObject(mark, VIS_COLORMAP, cmap);

    /* create trace object and set objects */
    trace = vis_TraceBegin();
    vis_TraceSetObject(trace, VGL_DRAWFUN, df);
    vis_TraceSetObject(trace, VIS_VISCONTEXT, vctrace);
    vis_TraceSetObject(trace, VIS_COLORMAP, cmap);

    for (i = 0; i < 30; i++) {
        vgl_DrawFunClear(df);
        vgl_DrawFunXfmPush(df);
        vgl_XfmRotate(xfm, i * 12.F * .017453F, XFM_XAXIS);
        vgl_XfmGetMatrix(xfm, tm);
        vgl_DrawFunXfmLoad(df, tm);

        /* draw face outlines */
        vis_VisContextTouch(vcface);
        for (j = 0; j < 4; j++) {
            gather(xquad, con[j], xe);
            vis_FaceCurv(face, xe, 0, NULL);
        }
        /* draw vectors */
        vis_VisContextTouch(vcmark);
        vis_MarkVector(mark, 9, vquad, xquad);
        /* draw tangent curve */
        vis_VisContextTouch(vctrace);
        t = 0.;
        nn = 0;
        xc[0] = 0.;
        xc[1] = .5;
        xc[2] = 0.;
        while (1) {
            gather(xquad, con[nn], xe);
            gather(vquad, con[nn], ve);
            vis_TraceSetEnter(trace, SYS_ON, xc, v, w, t);
            vis_TraceCurv(trace, VIS_VECTOR, (Vfloat*)ve, xe);
            vis_TraceGetExit(trace, SYS_ON, &status, &edgenumber, xc, vout, wout, &tout);
            if (adj[nn][edgenumber - 1]) {
                t = tout;
                nn = adj[nn][edgenumber - 1] - 1;
            }
            else {
                break;
            }
        }

        vgl_DrawFunXfmPop(df);
        vgl_DrawFunSwap(df);
        vgl_DrawFunDelay(df, 1.);
    }
    vgl_DrawFunDelay(df, 5.);

    /* close window */
    vgl_DrawFunCloseWindow(df);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vcface);
    vis_VisContextEnd(vcmark);
    vis_VisContextEnd(vctrace);
    vis_ColorMapEnd(cmap);
    vis_FaceEnd(face);
    vis_MarkEnd(mark);
    vis_TraceEnd(trace);
    vgl_OpenGLDevEnd(ogldev);
    vgl_XfmEnd(xfm);

    /* disconnect from window system */
    vgl_OpenGLDevDisconnect();
#ifdef VKI_WIND_X11
    XCloseDisplay(display);
#endif
    return 0;
}

/*----------------------------------------------------------------------
                      Utility function to gather element vectors
----------------------------------------------------------------------*/
static void
gather(Vfloat x[][3], Vint conArg[4], Vfloat xe[][3])
{
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            xe[i][j] = x[conArg[i] - 1][j];
        }
    }
}
