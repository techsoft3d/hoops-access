#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "glwin.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define MAX_PTS 50

static Vfloat rgb[7][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Generate a workplane
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
    vis_ColorMap* cmap;
    vgl_OpenGLDev* ogldev;

    Vint i;
    vis_WorkPlane* workplane;
    Vint parami[4];
    Vfloat paramf[16];
    Vfloat origin[3], up[3], right[3];
    Vint but1, but2, but3, px, py;
    Vint hit;
    Vfloat xh[3];

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
    df = vgl_DrawFunBegin();
    vgl_OpenGLDevDrawFun(ogldev, df);

    vgl_DrawFunPositionWindow(df, 200, 200, 800, 800);
    vgl_DrawFunOpenWindow(df, "Example 16avgl");
    vgl_DrawFunProjOrtho(df, -14., 14., -14., 14., -14., 14.);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetIsoValType(vc, VIS_ISOVALSURFACE);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 16, 0, rgb);
    vis_ColorMapValueDrawFun(cmap, df, 1);

    /* workplane */
    workplane = vis_WorkPlaneBegin();
    vis_WorkPlaneSetObject(workplane, VGL_DRAWFUN, df);
    vis_WorkPlaneSetObject(workplane, VIS_COLORMAP, cmap);
    vis_WorkPlaneSetObject(workplane, VIS_VISCONTEXT, vc);

    vis_WorkPlaneSetParami(workplane, WORKPLANE_GRID, 1);
    vis_WorkPlaneSetParami(workplane, WORKPLANE_OUTLINE, 1);
    vis_WorkPlaneSetParami(workplane, WORKPLANE_GRID_POINT, 1);
    vis_WorkPlaneSetDimensions(workplane, 1., 1., 5., 5., 5., 5.);

    origin[0] = 0.0;
    origin[1] = 0.0;
    origin[2] = 0.0;
    right[0] = 1.0;
    right[1] = 0.0;
    right[2] = 0.0;
    up[0] = 0.0;
    up[1] = 1.0;
    up[2] = 0.0;
    vis_WorkPlaneSetOriginPlane(workplane, origin, right, up);

    vis_VisContextSetColor(vc, 2);
    vis_VisContextSetMinorColor(vc, 3);
    vis_VisContextSetFill(vc, 0);
    vis_VisContextSetABCColor(vc, 6, 4, 5);
    vis_VisContextSetPointSize(vc, 3);

    /* draw workplane */
    for (i = 0; i < 5; i++) {
        vgl_DrawFunClear(df);
        vgl_DrawFunGetFloat(df, VGL_PROJECTIONMATRIX, paramf);
        vis_VisContextSetProjMatrix(vc, (Vfloat(*)[4])paramf);
        vgl_DrawFunGetFloat(df, VGL_MODELVIEWMATRIX, paramf);
        vis_VisContextSetXfmMatrix(vc, (Vfloat(*)[4])paramf);
        vgl_DrawFunGetInteger(df, VGL_VIEWPORT, parami);
        vis_VisContextSetViewport(vc, parami[0], parami[1], parami[2], parami[3]);

        vis_WorkPlaneDraw(workplane);
        vgl_DrawFunSwap(df);
        vgl_DrawFunDelay(df, 2.);
        /* reset workplane dimensions */
        if (i == 0) {
            vis_WorkPlaneSetDimensions(workplane, 1., 1., 5., 5., 7., 7.);

            /* reset workplane grid spacing */
        }
        else if (i == 1) {
            vis_WorkPlaneSetDimensions(workplane, 2., 2., 5., 5., 7., 7.);

            /* set workplane draw grid using lines */
        }
        else if (i == 2) {
            vis_WorkPlaneSetParami(workplane, WORKPLANE_GRID_POINT, 0);
            vis_WorkPlaneSetParami(workplane, WORKPLANE_GRID_LINE, 1);
            /* turn off axes and origin */
        }
        else if (i == 3) {
            vis_WorkPlaneSetParami(workplane, WORKPLANE_AXES, 0);
            vis_WorkPlaneSetParami(workplane, WORKPLANE_ORIGIN, 0);
        }
    }

    /* detect grid point hits */
    printf("\nQuery WorkPlane\n");
    printf("Default query colocated point\n");
    printf("Press Left Mouse to query snap point\n");
    printf("Press Right Mouse to exit\n");

    vis_WorkPlaneSetParami(workplane, WORKPLANE_GRID_POINT, SYS_ON);
    vis_WorkPlaneSetParami(workplane, WORKPLANE_GRID_LINE, SYS_OFF);
    vis_WorkPlaneSetParami(workplane, WORKPLANE_AXES, SYS_ON);
    vis_WorkPlaneSetParami(workplane, WORKPLANE_ORIGIN, SYS_ON);
    vgl_DrawFunClear(df);
    vis_WorkPlaneDraw(workplane);
    vgl_DrawFunSwap(df);

    for (;;) {
        vgl_DrawFunClear(df);
        vgl_DrawFunPollMouse(df, &px, &py, &but1, &but2, &but3);
        if (but1) {
            vis_WorkPlaneSetParami(workplane, WORKPLANE_GRID_SNAP, SYS_ON);
        }
        else {
            vis_WorkPlaneSetParami(workplane, WORKPLANE_GRID_SNAP, SYS_OFF);
        }
        if (but3)
            break;
        vis_WorkPlaneTestHit(workplane, px, py, &hit, xh);
        vis_WorkPlaneDraw(workplane);
        vis_WorkPlaneInitHit(workplane);
        vgl_DrawFunSwap(df);
    }
    vgl_DrawFunDelay(df, 2.);
    /* close window */
    vgl_DrawFunCloseWindow(df);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_WorkPlaneEnd(workplane);
    vgl_OpenGLDevEnd(ogldev);
    return 0;
}
