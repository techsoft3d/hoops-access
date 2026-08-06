#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vfloat rgb[16][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Generate polybox
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

    vis_PolyBox* polybox;
    Vint parami[4];
    Vfloat paramf[16];
    Vint but1, but2, but3, px, py;
    Vint action, drag;
    Vint hit;
    Vint cornermode = 0;
    Vint ntri, tri[100][3];
    Vint npts, npenta, penta[100][6];
    Vfloat pts[200][3];

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
    vgl_DrawFunOpenWindow(df, "Example 16bvgl");
    vgl_DrawFunProjOrtho(df, -10., 10., -10., 10., -10., 10.);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetColor(vc, 1);
    vis_VisContextSetMinorColor(vc, 2);
    vis_VisContextSetSize(vc, 1.0);
    vis_VisContextSetABCColor(vc, 3, 4, 5);
    vis_VisContextSetPointSize(vc, 8);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 16, 0, rgb);

    /* polybox */
    polybox = vis_PolyBoxBegin();
    vis_PolyBoxSetObject(polybox, VGL_DRAWFUN, df);
    vis_PolyBoxSetObject(polybox, VIS_COLORMAP, cmap);
    vis_PolyBoxSetObject(polybox, VIS_VISCONTEXT, vc);
    vis_PolyBoxSetParami(polybox, POLYBOX_PIXTOL, 10);

    npts = 3;
    pts[0][0] = 10;
    pts[0][1] = 10;
    pts[1][0] = 100;
    pts[1][1] = 10;
    pts[2][0] = 100;
    pts[2][1] = 100;

    vgl_DrawFunGetFloat(df, VGL_PROJECTIONMATRIX, paramf);
    vis_VisContextSetProjMatrix(vc, (Vfloat(*)[4])paramf);
    vgl_DrawFunGetFloat(df, VGL_MODELVIEWMATRIX, paramf);
    vis_VisContextSetXfmMatrix(vc, (Vfloat(*)[4])paramf);
    vgl_DrawFunGetInteger(df, VGL_VIEWPORT, parami);
    vis_VisContextSetViewport(vc, parami[0], parami[1], parami[2], parami[3]);

    printf("\nCreate PolyBox\n");
    printf("Click Left Mouse to place point\n");
    printf("Click Middle Mouse to complete loop\n");
    /* create polybox */
    for (;;) {
        vgl_DrawFunClear(df);
        vgl_DrawFunPollMouse(df, &px, &py, &but1, &but2, &but3);
        vis_PolyBoxCurrentDrag(polybox, &action, &drag);
        if (action == VIS_ACTION_NONE) {
            if (but1) {
                vis_PolyBoxDrag(polybox, POLYBOX_ACTION_CORNER, VIS_DRAG_INIT, px, py);
                cornermode = 1;
            }
        }
        else {
            if (cornermode == 0) {
                if (but1) {
                    vis_PolyBoxDrag(polybox, POLYBOX_ACTION_CORNER, VIS_DRAG_MOVE, px, py);
                    cornermode = 1;
                }
                else if (but2) {
                    vis_PolyBoxDrag(polybox, POLYBOX_ACTION_CORNER, VIS_DRAG_TERM, px, py);
                    vis_PolyBoxInitHit(polybox);
                    break;
                }
                else {
                    vis_PolyBoxDrag(polybox, POLYBOX_ACTION_LINE, VIS_DRAG_MOVE, px, py);
                }
            }
            else {
                vis_PolyBoxDrag(polybox, POLYBOX_ACTION_LINE, VIS_DRAG_MOVE, px, py);
                if (but1 == 0)
                    cornermode = 0;
            }
        }
        vgl_DrawFunSwap(df);
    }
    /* draw constructed polybox */
    vgl_DrawFunClear(df);
    vis_PolyBoxDraw(polybox);
    vgl_DrawFunSwap(df);
    /* query polybox triangles */
    /* no triangles are produced for intersecting polybox */
    vis_PolyBoxGetTri(polybox, &ntri, tri);
    printf("ntri= %d\n", ntri);
    vis_PolyBoxGetPenta(polybox, &npts, pts, &npenta, penta);
    printf("npts= %d\n", npts);

    printf("\nManipulate PolyBox\n");
    printf("Press Left Mouse to drag point\n");
    printf("Press Middle Mouse to translate entire loop\n");
    printf("Press Left Mouse to exit\n");
    /* manipulate polybox */
    for (;;) {
        vgl_DrawFunClear(df);
        vis_PolyBoxDraw(polybox);
        vgl_DrawFunPollMouse(df, &px, &py, &but1, &but2, &but3);
        if (but3)
            break;
        vis_PolyBoxCurrentDrag(polybox, &action, &drag);
        /* no current action, test for hit */
        if (action == VIS_ACTION_NONE) {
            vis_PolyBoxTestHit(polybox, px, py, &hit);
            if (hit == 0) {
                vis_PolyBoxInitHit(polybox);
            }
            else {
                if (but1) {
                    vis_PolyBoxDrag(polybox, POLYBOX_ACTION_MOVECORNER, VIS_DRAG_INIT, px, py);
                }
            }
            /* translate entire polybox */
            if (but2) {
                vis_PolyBoxDrag(polybox, POLYBOX_ACTION_TRANSLATE, VIS_DRAG_INIT, px, py);
            }
            /* current action */
        }
        else {
            if (but1) {
                vis_PolyBoxDrag(polybox, POLYBOX_ACTION_MOVECORNER, VIS_DRAG_MOVE, px, py);
            }
            else if (but2) {
                vis_PolyBoxDrag(polybox, POLYBOX_ACTION_TRANSLATE, VIS_DRAG_MOVE, px, py);
            }
            else {
                vis_PolyBoxDrag(polybox, 0, VIS_DRAG_TERM, px, py);
                vis_PolyBoxInitHit(polybox);
            }
        }
        vgl_DrawFunSwap(df);
    }
    /* close window */
    vgl_DrawFunCloseWindow(df);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_PolyBoxEnd(polybox);
    vgl_OpenGLDevEnd(ogldev);
    return 0;
}
