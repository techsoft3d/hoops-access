#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
#include "glwin.h"

static Vfloat xhex[27][3] = {{0., 0., 0.},    {1.f, 0., 0.},  {2.f, 0., 0.},   {0., 1.f, 0.},   {1.f, 1.f, 0.},
                             {2.f, 1.f, 0.},  {0., 2.f, 0.},  {1., 2.f, 0.},   {2.f, 2.f, 0.},

                             {0., 0., 1.f},   {1.f, 0., 1.f}, {2.f, 0., 1.f},  {0., 1.f, 1.f},  {1.f, 1.f, 1.f},
                             {2.f, 1.f, 1.f}, {0., 2.f, 1.f}, {1.f, 2.f, 1.f}, {2.f, 2.f, 1.f},

                             {0., 0., 2.f},   {1.f, 0., 2.f}, {2.f, 0., 2.f},  {0., 1.f, 2.f},  {1.f, 1.f, 2.f},
                             {2.f, 1.f, 2.f}, {0., 2.f, 2.f}, {1.f, 2.f, 2.f}, {2.f, 2.f, 2.f}};
static Vfloat vhex[27][3] = {
{.5f, 1.f, -1.f}, {.5f, 1.f, -1.f}, {.5f, 1.f, -1.f}, {.5f, 1.f, 0.f},  {.5f, 1.f, 0.f},   {.5f, 1.f, 0.f},   {.5f, 1.f, 1.f},
{.5f, 1.f, 1.f},  {.5f, 1.f, 1.f},  {.5f, 0.f, -1.f}, {.5f, 0.f, -1.f}, {.5f, 0.f, -1.f},  {.5f, 0.f, 0.f},   {.5f, 0.f, 0.f},
{.5f, 0.f, 0.f},  {.5f, 0.f, 1.f},  {.5f, 0.f, 1.f},  {.5f, 0.f, 1.f},  {.5f, -1.f, -1.f}, {.5f, -1.f, -1.f}, {.5f, -1.f, -1.f},
{.5f, -1.f, 0.f}, {.5f, -1.f, 0.f}, {.5f, -1.f, 0.f}, {.5f, -1., 1.f},  {.5f, -1.f, 1.f},  {.5f, -1.f, 1.f}};

static Vfloat rgb[4][3] = {{.2f, .2f, .2f}, {1.f, 0.f, 0.f}, {0.f, 1.f, 0.f}, {0.f, 0.f, 1.f}};

/*----------------------------------------------------------------------
                      Generate streamribbon in a 27 node brick element
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_Stream* stream;
    GLWin* glwin;

    int i;
    Vfloat x[3], v[3], w[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -3., 3., -3., 3., -3., 3.);

    /* create draw function object */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetStreamType(vc, VIS_STREAMRIBBON);
    vis_VisContextSetLineWidth(vc, 3);
    vis_VisContextSetSize(vc, .1f);
    vis_VisContextSetColor(vc, 1);
    vis_VisContextSetMinorColor(vc, 2);
    vis_VisContextSetShade(vc, VIS_VERTEXSHADE);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 4, 0, rgb);

    /* create stream object and set objects */
    stream = vis_StreamBegin();
    vis_StreamSetObject(stream, VGL_DRAWFUN, df);
    vis_StreamSetObject(stream, VIS_VISCONTEXT, vc);
    vis_StreamSetObject(stream, VIS_COLORMAP, cmap);

    /* draw stream */
    vis_StreamSetTopology(stream, VIS_SHAPEHEX, 3, 3, 3);
    /* set initial position */
    x[0] = 0.;
    x[1] = 1.;
    x[2] = 1.;
    /* set initial orientation vector */
    v[0] = 0.;
    v[1] = 0.;
    v[2] = .5;
    w[0] = 0.;
    w[1] = -.5;
    w[2] = 0.;
    for (i = 0; i < 30; i++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 12.F, 'y');
        vis_StreamSetEnter(stream, SYS_ON, x, v, w, 0.);
        vis_StreamCurv(stream, VIS_VECTOR, (Vfloat*)vhex, xhex);
        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(5);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_StreamEnd(stream);
    GLWinEnd(glwin);
    return 0;
}
