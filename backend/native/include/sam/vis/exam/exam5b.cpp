#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat xhex[27][3] = {
{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {0., 1., 0.}, {1., 1., 0.}, {2., 1., 0.}, {0., 2., 0.}, {1., 2., 0.}, {2., 2., 0.},

{0., 0., 1.}, {1., 0., 1.}, {2., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}, {2., 1., 1.}, {0., 2., 1.}, {1., 2., 1.}, {2., 2., 1.},

{0., 0., 2.}, {1., 0., 2.}, {2., 0., 2.}, {0., 1., 2.}, {1., 1., 2.}, {2., 1., 2.}, {0., 2., 2.}, {1., 2., 2.}, {2., 2., 2.}};
static Vfloat vhex[27][3] = {{.5, 1., -1.},  {.5, 1., -1.},  {.5, 1., -1.},  {.5, 1., 0.},  {.5, 1., 0.},  {.5, 1., 0.},
                             {.5, 1., 1.},   {.5, 1., 1.},   {.5, 1., 1.},   {.5, 0., -1.}, {.5, 0., -1.}, {.5, 0., -1.},
                             {.5, 0., 0.},   {.5, 0., 0.},   {.5, 0., 0.},   {.5, 0., 1.},  {.5, 0., 1.},  {.5, 0., 1.},
                             {.5, -1., -1.}, {.5, -1., -1.}, {.5, -1., -1.}, {.5, -1., 0.}, {.5, -1., 0.}, {.5, -1., 0.},
                             {.5, -1., 1.},  {.5, -1., 1.},  {.5, -1., 1.}};

static Vfloat rgb[4][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}};

/*----------------------------------------------------------------------
                      Drawing functions for points
----------------------------------------------------------------------*/
static void
vgl_DrawFunPtPolyPointData(Vobject* df, Vint npts, Vfloat x[][3], Vint nrws, Vfloat* d)
{
    static Vfloat c[3] = {1., 1., 1.};

    /* print info */
    printf("vgl_DrawFunPtPolyPointData npts = %d\n", npts);
    printf("x = %f %f %f\n", x[0][0], x[0][1], x[0][2]);
    printf("nrws = %d\n", nrws);
    printf("v = %f %f %f\n", d[0], d[1], d[2]);
    printf("t = %f\n", d[3]);

    /* draw point for illustration only */
    vgl_DrawFunColor((vgl_DrawFun*)df, c);
    vgl_DrawFunPointSize((vgl_DrawFun*)df, 2);
    vgl_DrawFunPolyPoint((vgl_DrawFun*)df, npts, x);
}

/*----------------------------------------------------------------------
                      Generate data points in a 27 node brick element
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun *df, *dfPt;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_Stream* stream;
    vis_DataInt* dataint;
    GLWin* glwin;

    Vfloat x[3], v[3], w[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -3., 3., -3., 3., -3., 3.);

    /* create draw function object */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* Data interpolation */
    dataint = vis_DataIntBegin();
    vis_DataIntSetDataPtr(dataint, 0, 3, (Vfloat*)vhex);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    /* set stream type to point to output points */
    vis_VisContextSetStreamType(vc, VIS_STREAMPOINT);
    /* do not call normal drawing functions,
       only "Data" drawing functions */
    vis_VisContextSetDraw(vc, VIS_OFF);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 4, 0, rgb);

    /* create point drawing function object */
    dfPt = vgl_DrawFunBegin();
    vgl_DrawFunSetObj(dfPt, df);
    vgl_DrawFunSet(dfPt, DRAWFUN_POLYPOINTDATA, (Vfunc*)vgl_DrawFunPtPolyPointData);

    /* create stream object and set objects */
    stream = vis_StreamBegin();
    vis_StreamSetObject(stream, VGL_DRAWFUN, dfPt);
    vis_StreamSetObject(stream, VIS_VISCONTEXT, vc);
    vis_StreamSetObject(stream, VIS_COLORMAP, cmap);
    /* Stream will now call "Data" drawing functions */
    vis_StreamSetObject(stream, VIS_DATAINT, dataint);

    /* draw stream */
    vis_StreamSetTopology(stream, VIS_SHAPEHEX, 3, 3, 3);
    /* set initial position */
    x[0] = 0.;
    x[1] = 1.;
    x[2] = 1.5;
    /* set initial orientation vector,
       ignored for a StreamType of VIS_STREAMPOINT */
    v[0] = 0.;
    v[1] = 0.;
    v[2] = .5;
    w[0] = 0.;
    w[1] = -.5;
    w[2] = 0.;

    GLWinClear(glwin);
    vis_StreamSetEnter(stream, SYS_ON, x, v, w, 0.);
    vis_StreamCurv(stream, VIS_VECTOR, (Vfloat*)vhex, xhex);
    GLWinSwap(glwin);

    sleep(5);
    /* free all objects */
    vgl_DrawFunEnd(df);
    vgl_DrawFunEnd(dfPt);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_StreamEnd(stream);
    vis_DataIntEnd(dataint);
    GLWinEnd(glwin);
    return 0;
}
