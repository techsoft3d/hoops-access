#include <stdlib.h>
#ifdef VKI_WIND_X11
#include <unistd.h>
#endif

#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"

static void
gather(Vfloat x[][3], Vint con[4], Vfloat xe[][3]);

static Vfloat xquad[9][3] = {0., 0., 0., 1., 0., 0., 2., 0., 0., 0., 1., 0., 1., 1.,
                             0., 2., 1., 0., 0., 2., 0., 1., 2., 0., 2., 2., 0.};
static Vfloat vquad[9][3] = {1., 0., 0., 1., 0.,  0., 1., 1.,  0., 0., 0.,  0., 0., 0.,
                             0., 0., 1., 0., -1., 0., 0., -1., 0., 0., -1., 1., 0.};
static Vint con[4][4] = {1, 2, 5, 4, 2, 3, 6, 5, 4, 5, 8, 7, 5, 6, 9, 8};
static Vint adj[4][4] = {0, 2, 3, 0, 0, 0, 4, 1, 1, 4, 0, 0, 2, 0, 0, 3};
static Vfloat rgb[16][3] = {.2, .2, .2, 1., 0., 0., 0., 1., 0., 0., 0., 1., 0., 1., 1., 1., 0., 1., 1., 1., 0.};

/*----------------------------------------------------------------------
                      Generate tangent curve on quadrilateral elements
                      Use VglTools graphics library with a parent window
----------------------------------------------------------------------*/
int
main()
{
#ifdef VKI_WIND_X11
    Display* display;
    int screen;
    Window window;
    XEvent event;
#endif
#ifdef VKI_WIND_WIN32
    HINSTANCE hInstance;
    WNDCLASS wc;
    HWND window;
    RECT rect;
    char AppName[33];
#endif

    vgl_DrawFun* df;
    vis_VisContext *vcface, *vcmark, *vctrace;
    vis_ColorMap* cmap;
    vis_TransMap* tmap;
    vis_Face* face;
    vis_Mark* mark;
    vis_Trace* trace;
    vgl_OpenGLDev* ogldev;
    vgl_Xfm* xfm;

    int i, j;
    Vfloat xe[4][3], ve[4][3], xc[3];
    Vint nn;
    Vfloat r[2], t;
    Vint status, edgenumber;
    Vfloat rout[2], tout;
    Vfloat v[3], w[3], vout[3], wout[3];
    Vfloat tm[4][4];
    Vint flag;

    /* connect to window system */
    /* create parent window */
#ifdef VKI_WIND_X11
    if (vgl_OpenGLDevTestX(&flag), flag == 0) {
        printf("OpenGL not enabled, exiting\n");
        exit(0);
    }
    display = XOpenDisplay(0);
    screen = DefaultScreen(display);
    vgl_OpenGLDevConnectX(display, screen);
    window = XCreateSimpleWindow(display, RootWindow(display, screen), 200, 200, 400, 400, 1, WhitePixel(display, screen),
                                 BlackPixel(display, screen));
    XSetStandardProperties(display, window, "Example 5vglpar", "X11", None, 0, 0, 0);
    XMapWindow(display, window);
    XSelectInput(display, window, ExposureMask);
    do {
        XNextEvent(display, &event);
    } while (event.type != Expose);
#endif
#ifdef VKI_WIND_WIN32
    if (vgl_OpenGLDevTestWIN(&flag), flag == 0) {
        printf("OpenGL not enabled, exiting\n");
        exit(0);
    }
    vgl_OpenGLDevConnectWIN();
    strcpy(AppName, "Example5");
    hInstance = GetModuleHandle(NULL);

    wc.style = 0;
    wc.lpfnWndProc = (WNDPROC)DefWindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(hInstance, AppName);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszMenuName = AppName;
    wc.lpszClassName = AppName;

    if (!RegisterClass(&wc))
        return 0;
    window = CreateWindow(AppName, "exam5vglpar", WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 200, 200, 400, 400,
                          NULL, (HMENU)NULL, hInstance, NULL);
    ShowWindow(window, SW_SHOWDEFAULT);
    UpdateWindow(window);
#endif

    /* create OpenGL device */
    ogldev = new vgl_OpenGLDev;

    /* create drawing function object for OpenGL */
    df = new vgl_DrawFun;
    ogldev->DrawFun(df);

    df->ParentWindow((Vword)window);
    df->OpenWindow("");
    df->ProjOrtho(-3., 3., -3., 3., -3., 3.);

    /* create transformation object */
    xfm = new vgl_Xfm;

    /* vis context and set attributes */
    vcface = new vis_VisContext;
    vcface->SetEdge(VIS_ON);
    vcface->SetFill(VIS_OFF);
    vcface->SetColor(4);

    vcmark = new vis_VisContext;
    vcmark->SetFlags(VIS_VECTORTAIL | VIS_VECTORTAILREGISTER);
    vcmark->SetVectorType(VIS_VECTORCYLINDER);
    vcmark->SetSize(.5);
    vcmark->SetMapColor(VIS_OFF);
    vcmark->SetColor(1);

    vctrace = new vis_VisContext;
    vctrace->SetLineWidth(2);
    vctrace->SetColor(6);

    /* color map and set drawing functions */
    cmap = new vis_ColorMap;
    cmap->SetType(COLORMAP_TRUECOLOR);
    cmap->SetRGB(7, 0, rgb);

    /* transparency map and set drawing functions */
    tmap = new vis_TransMap;

    /* create face object and set objects */
    face = new vis_Face;
    face->SetObject(VGL_DRAWFUN, df);
    face->SetObject(VIS_VISCONTEXT, vcface);
    face->SetObject(VIS_COLORMAP, cmap);
    face->SetObject(VIS_TRANSMAP, tmap);

    /* create mark object and set objects */
    mark = new vis_Mark;
    mark->SetObject(VGL_DRAWFUN, df);
    mark->SetObject(VIS_VISCONTEXT_VECTOR, vcmark);
    mark->SetObject(VIS_COLORMAP, cmap);

    /* create trace object and set objects */
    trace = new vis_Trace;
    trace->SetObject(VGL_DRAWFUN, df);
    trace->SetObject(VIS_VISCONTEXT, vctrace);
    trace->SetObject(VIS_COLORMAP, cmap);

    for (i = 0; i < 30; i++) {
        df->Clear();
        df->XfmPush();
        xfm->Rotate(i * 12. * .017453, XFM_XAXIS);
        xfm->GetMatrix(tm);
        df->XfmLoad(tm);

        /* draw face outlines */
        vcface->Touch();
        for (j = 0; j < 4; j++) {
            gather(xquad, con[j], xe);
            face->Curv(xe, 0, NULL);
        }
        /* draw vectors */
        vcmark->Touch();
        mark->Vector(9, vquad, xquad);
        /* draw tangent curve */
        vctrace->Touch();
        t = 0.;
        nn = 0;
        xc[0] = 0.;
        xc[1] = .5;
        xc[2] = 0.;
        while (1) {
            gather(xquad, con[nn], xe);
            gather(vquad, con[nn], ve);
            trace->ConvertCoord(xe, xc, r);
            trace->SetEnter(0, r, v, w, t);
            trace->Curv(VIS_VECTOR, (Vfloat*)ve, xe);
            trace->GetExit(0, &status, &edgenumber, rout, vout, wout, &tout);
            if (adj[nn][edgenumber - 1]) {
                t = tout;
                nn = adj[nn][edgenumber - 1] - 1;
                trace->ComputeCoord(xe, rout, xc);
            }
            else {
                break;
            }
        }

        df->XfmPop();
        df->Swap();
        df->Delay(1.);
    }
    df->Delay(5.);

    /* close window */
    df->CloseWindow();

    /* free all objects */
    delete df;
    delete vcface;
    delete vcmark;
    delete vctrace;
    delete cmap;
    delete tmap;
    delete face;
    delete mark;
    delete trace;
    delete ogldev;
    delete xfm;

    /* disconnect from window system */
    vgl_OpenGLDevDisconnect();

    /* close parent window */
#ifdef VKI_WIND_X11
    XDestroyWindow(display, window);
    XCloseDisplay(display);
#endif
#ifdef VKI_WIND_WIN32
    DestroyWindow(window);
    UnregisterClass(AppName, GetModuleHandle(NULL));
#endif
    return 0;
}

/*----------------------------------------------------------------------
                      Utility function to gather element vectors
----------------------------------------------------------------------*/
static void
gather(Vfloat x[][3], Vint con[4], Vfloat xe[][3])
{
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            xe[i][j] = x[con[i] - 1][j];
        }
    }
}
