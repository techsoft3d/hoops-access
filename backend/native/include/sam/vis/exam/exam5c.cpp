#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static void
gather(Vfloat x[][3], Vint conArg[8], Vfloat xe[][3]);

static Vfloat xhex[18][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {0., 1., 0.}, {1., 1., 0.}, {2., 1., 0.},
                             {0., 2., 0.}, {1., 2., 0.}, {2., 2., 0.}, {0., 0., 1.}, {1., 0., 1.}, {2., 0., 1.},
                             {0., 1., 1.}, {1., 1., 1.}, {2., 1., 1.}, {0., 2., 1.}, {1., 2., 1.}, {2., 2., 1.}};

static Vfloat vhex[18][3] = {{1., 0., 0.},  {1., 0., 0.},  {1., 1., 0.},  {0., 0., 0.},  {0., 0., 0.},  {0., 1., 0.},
                             {-1., 0., 0.}, {-1., 0., 0.}, {-1., 1., 0.}, {1., 0., 0.},  {1., 0., 0.},  {1., 1., 0.},
                             {0., 0., 0.},  {0., 0., 0.},  {0., 1., 0.},  {-1., 0., 0.}, {-1., 0., 0.}, {-1., 1., 0.}};
static Vint con[4][8] = {
{1, 2, 5, 4, 10, 11, 14, 13}, {2, 3, 6, 5, 11, 12, 15, 14}, {4, 5, 8, 7, 13, 14, 17, 16}, {5, 6, 9, 8, 14, 15, 18, 17}};
static Vint adj[4][6] = {{0, 0, 0, 3, 0, 2}, {0, 0, 0, 4, 1, 0}, {0, 0, 1, 0, 0, 4}, {0, 0, 2, 0, 3, 0}};

static Vfloat rgb[7][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Generate tangent curve on hex elements
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext *vccell, *vcmark, *vcstream;
    vis_ColorMap* cmap;
    vis_Cell* cell;
    vis_Mark* mark;
    vis_Stream* stream;
    GLWin* glwin;

    int i, j, k;
    Vfloat xe[8][3], ve[8][3], xc[3];
    Vint nn;
    Vfloat t;
    Vint status, facenumber;
    Vfloat v[3], w[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -3., 3., -3., 3., -3., 3.);

    /* create drawing function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* vis context and set attributes */
    vccell = vis_VisContextBegin();
    vis_VisContextSetEdge(vccell, VIS_ON);
    vis_VisContextSetFill(vccell, VIS_OFF);
    vis_VisContextSetMinorColor(vccell, 4);

    vcmark = vis_VisContextBegin();
    vis_VisContextSetFlags(vcmark, VIS_VECTORTAIL | VIS_VECTORTAILREGISTER);
    vis_VisContextSetVectorType(vcmark, VIS_VECTORCYLINDER);
    vis_VisContextSetSize(vcmark, .5);
    vis_VisContextSetMapColor(vcmark, VIS_OFF);
    vis_VisContextSetColor(vcmark, 1);

    vcstream = vis_VisContextBegin();
    vis_VisContextSetLineWidth(vcstream, 2);
    vis_VisContextSetColor(vcstream, 6);
    vis_VisContextSetMinorColor(vcstream, 3);
    vis_VisContextSetSize(vcstream, 1.);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 7, 0, rgb);

    /* create cell object and set objects */
    cell = vis_CellBegin();
    vis_CellSetObject(cell, VGL_DRAWFUN, df);
    vis_CellSetObject(cell, VIS_VISCONTEXT, vccell);
    vis_CellSetObject(cell, VIS_COLORMAP, cmap);

    /* create mark object and set objects */
    mark = vis_MarkBegin();
    vis_MarkSetObject(mark, VGL_DRAWFUN, df);
    vis_MarkSetObject(mark, VIS_VISCONTEXT_VECTOR, vcmark);
    vis_MarkSetObject(mark, VIS_COLORMAP, cmap);

    /* create stream object and set objects */
    stream = vis_StreamBegin();
    vis_StreamSetObject(stream, VGL_DRAWFUN, df);
    vis_StreamSetObject(stream, VIS_VISCONTEXT, vcstream);
    vis_StreamSetObject(stream, VIS_COLORMAP, cmap);

    /* loop through three stream types */
    for (k = 0; k < 3; k++) {
        if (k == 0) {
            vis_VisContextSetStreamType(vcstream, VIS_STREAMRIBBON);
        }
        else if (k == 1) {
            vis_VisContextSetStreamType(vcstream, VIS_STREAMTUBE);
        }
        else if (k == 2) {
            vis_VisContextSetStreamType(vcstream, VIS_STREAMTWIST);
        }
        /* rotate around */
        for (i = 0; i < 10; i++) {
            GLWinClear(glwin);
            GLWinXfmPush(glwin);
            GLWinRotate(glwin, i * 12.F, 'x');
            /* draw cell outlines */
            vis_VisContextTouch(vccell);
            for (j = 0; j < 4; j++) {
                gather(xhex, con[j], xe);
                vis_CellCurv(cell, xe);
            }
            /* draw vectors */
            vis_VisContextTouch(vcmark);
            vis_MarkVector(mark, 18, vhex, xhex);
            /* draw tangent curve */
            vis_VisContextTouch(vcstream);
            /* set initial conditions */
            v[0] = 0.;
            v[1] = .2f;
            v[2] = 0.;
            w[0] = 0.;
            w[1] = 0.;
            w[2] = .2f;
            t = 0.;
            nn = 0;
            xc[0] = 0.;
            xc[1] = .5f;
            xc[2] = .5f;
            /* propagate the stream through elements */
            for (;;) {
                gather(xhex, con[nn], xe);
                gather(vhex, con[nn], ve);
                vis_StreamSetEnter(stream, SYS_ON, xc, v, w, t);
                vis_StreamCurv(stream, VIS_VECTOR, (Vfloat*)ve, xe);
                vis_StreamGetExit(stream, SYS_ON, &status, &facenumber, xc, v, w, &t);
                /* adjacent element, propagate */
                if (adj[nn][facenumber - 1]) {
                    nn = adj[nn][facenumber - 1] - 1;
                    /* free face, quit */
                }
                else {
                    break;
                }
            }

            GLWinXfmPop(glwin);
            GLWinSwap(glwin);
            sleep(1);
        }
    }
    sleep(5);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vccell);
    vis_VisContextEnd(vcmark);
    vis_VisContextEnd(vcstream);
    vis_ColorMapEnd(cmap);
    vis_CellEnd(cell);
    vis_MarkEnd(mark);
    vis_StreamEnd(stream);
    GLWinEnd(glwin);
    return 0;
}

/*----------------------------------------------------------------------
                      Utility function to gather element vectors
----------------------------------------------------------------------*/
static void
gather(Vfloat x[][3], Vint conArg[8], Vfloat xe[][3])
{
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            xe[i][j] = x[conArg[i] - 1][j];
        }
    }
}
