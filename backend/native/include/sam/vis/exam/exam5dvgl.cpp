#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
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

static Vfloat rgb[16][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/* custom object */
typedef struct exam5d_obj {
    vis_Mark* mark;
    vis_Segment* segment;
    Vint it;     /* animation counter */
    Vint itfreq; /* animation counter frequency */
    Vint itmark; /* animation counter mark */
    Vint maxpts;
    Vfloat* vmag;
} exam5d_obj;

/* custom drawing functions */
static void
exam5d_PolyPointData(exam5d_obj* obj, Vint npts, Vfloat x[][3], Vint nrws, Vfloat d[])
{
    Vint i;
    Vfloat v[3];
    /* extract vector data (v) and time (t) */
    for (i = 0; i < npts; i++) {
        v[0] = d[i * nrws + 0];
        v[1] = d[i * nrws + 1];
        v[2] = d[i * nrws + 2];
        /* draw every itfreq vector */
        if (obj->it % obj->itfreq == obj->itmark % obj->itfreq) {
            vis_MarkVector(obj->mark, 1, &v, &x[i]);
        }
        /* increment counter */
        obj->it += 1;
    }
}

static void
exam5d_PolyLineData(exam5d_obj* obj, Vint type, Vint npts, Vfloat x[][3], Vint nrws, Vfloat d[])
{
    Vint i;
    Vfloat v[3];
    /* extract vector data (v) and time (t) */
    if (npts > obj->maxpts) {
        obj->vmag = (Vfloat*)realloc(obj->vmag, npts * sizeof(Vfloat));
        obj->maxpts = npts;
    }
    for (i = 0; i < npts; i++) {
        v[0] = d[i * nrws + 0];
        v[1] = d[i * nrws + 1];
        v[2] = d[i * nrws + 2];
        obj->vmag[i] = (Vfloat)sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    }
    vis_SegmentPolyLineData(obj->segment, type, npts, x, 1, obj->vmag);
}

/*----------------------------------------------------------------------
                      Generate tangent curve on hex elements
----------------------------------------------------------------------*/
int
main()
{
#ifdef VKI_WIND_X11
    Display* display;
    int screen;
#endif
    vgl_DrawFun *dfdev, *df, *dfM;
    vis_VisContext *vccell, *vc, *vcstream;
    vis_Levels* levels;
    vis_ColorMap* cmap;
    vis_Cell* cell;
    vis_Mark* mark;
    vis_Segment* segment;
    vis_Stream* stream;
    vis_DataInt* dataint;
    vgl_OpenGLDev* ogldev;
    vgl_DList* dlist;
    exam5d_obj obj;

    Vint i, j;
    Vint streamtype, animatenumber;
    Vfloat c[3], x[3];
    Vfloat xe[8][3], ve[8][3], xc[3];
    Vint nn;
    Vfloat t;
    Vint status, facenumber;
    Vfloat v[3], w[3];
    Vint nlevels;

    vsy_LicenseValidate(HOOPS_LICENSE);

#ifdef VKI_WIND_X11
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
    dfdev = vgl_DrawFunBegin();
    vgl_OpenGLDevDrawFun(ogldev, dfdev);
    vgl_DrawFunPositionWindow(dfdev, 200, 200, 400, 400);
    vgl_DrawFunOpenWindow(dfdev, "Example 5dvgl");
    vgl_DrawFunProjOrtho(dfdev, -1., 3., -1., 3., -2., 2.);
    vgl_DrawFunSetMode(dfdev, VGL_ZBUFFERMODE, VGL_ON);
    vgl_DrawFunSetMode(dfdev, VGL_LIGHTMODE, VGL_ON);
    c[0] = .4f;
    c[1] = .4f;
    c[2] = .4f;
    x[0] = 0.;
    x[1] = 0.;
    x[2] = 0.;
    vgl_DrawFunLight(dfdev, 0, VGL_LIGHT_AMBIENT, c, x);
    c[0] = .6f;
    c[1] = .6f;
    c[2] = .6f;
    x[0] = 1.;
    x[1] = 1.;
    x[2] = 1.;
    vgl_DrawFunLight(dfdev, 1, VGL_LIGHT_DISTANT, c, x);
    x[0] = -1.;
    x[1] = -1.;
    x[2] = -1.;
    vgl_DrawFunLight(dfdev, 2, VGL_LIGHT_DISTANT, c, x);

    /* vis context */
    /* draw edges of hex elements */
    vccell = vis_VisContextBegin();
    vis_VisContextSetEdge(vccell, VIS_ON);
    vis_VisContextSetFill(vccell, VIS_OFF);
    vis_VisContextSetMinorColor(vccell, 4);

    /* set stream type and turn off non data primitives */
    vcstream = vis_VisContextBegin();
    vis_VisContextSetDraw(vcstream, VIS_OFF);
    streamtype = VIS_STREAMPOINT;
    streamtype = VIS_STREAMLINE;
    vis_VisContextSetStreamType(vcstream, streamtype);

    /* data rendering on streamline */
    vc = vis_VisContextBegin();

    /* levels */
    levels = vis_LevelsBegin();
    nlevels = 5;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, 0.5, 0.55f);
    vis_LevelsGenerate(levels, LEVELS_PADTOP);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 7, 0, rgb);

    /* create cell object and set objects */
    cell = vis_CellBegin();
    vis_CellSetObject(cell, VGL_DRAWFUN, dfdev);
    vis_CellSetObject(cell, VIS_VISCONTEXT, vccell);
    vis_CellSetObject(cell, VIS_COLORMAP, cmap);

    /* create mark object and set objects */
    mark = vis_MarkBegin();
    vis_MarkSetObject(mark, VGL_DRAWFUN, dfdev);
    vis_MarkSetObject(mark, VIS_VISCONTEXT_VECTOR, vc);
    vis_MarkSetObject(mark, VIS_COLORMAP, cmap);
    vis_MarkSetObject(mark, VIS_LEVELS, levels);

    /* create segment object and set objects */
    segment = vis_SegmentBegin();
    vis_SegmentSetObject(segment, VGL_DRAWFUN, dfdev);
    vis_SegmentSetObject(segment, VIS_VISCONTEXT, vc);
    vis_SegmentSetObject(segment, VIS_COLORMAP, cmap);
    vis_SegmentSetObject(segment, VIS_LEVELS, levels);

    /* streamline vector data interpolation */
    dataint = vis_DataIntBegin();
    vis_DataIntSetDataPtr(dataint, 0, 3, (Vfloat*)ve);

    /* create streamline drawing function object */
    obj.mark = mark;
    obj.segment = segment;
    obj.itfreq = 10;
    obj.maxpts = 10;
    obj.vmag = (Vfloat*)malloc(10 * sizeof(Vfloat));
    dfM = vgl_DrawFunBegin();
    vgl_DrawFunSetObj(dfM, &obj);
    vgl_DrawFunAPI(dfM, DRAWFUN_APIRETURN);
    /* use custom function */
    vgl_DrawFunSet(dfM, DRAWFUN_POLYPOINTDATA, (Vfunc*)exam5d_PolyPointData);
    vgl_DrawFunSet(dfM, DRAWFUN_POLYLINEDATA, (Vfunc*)exam5d_PolyLineData);

    /* create display list to hold streamline */
    dlist = vgl_DListBegin();
    df = vgl_DrawFunBegin();
    vgl_DListDrawFun(dlist, df);
    vgl_DListSetObject(dlist, VGL_DRAWFUN, dfM);

    /* create stream object and set objects */
    stream = vis_StreamBegin();
    vis_StreamSetObject(stream, VGL_DRAWFUN, df);
    vis_StreamSetObject(stream, VIS_VISCONTEXT, vcstream);
    vis_StreamSetObject(stream, VIS_COLORMAP, cmap);
    vis_StreamSetObject(stream, VIS_DATAINT, dataint);

    /* generate streamline */
    /* set initial conditions */
    /* orientation vectors orthogonal to velocity */
    v[0] = 0.;
    v[1] = .2f;
    v[2] = 0.;
    w[0] = 0.;
    w[1] = 0.;
    w[2] = .2f;
    /* time 0. */
    t = 0.;
    /* starting point of stream line */
    xc[0] = 0.;
    xc[1] = .5f;
    xc[2] = .5f;
    /* starting point is in first element */
    nn = 0;
    /* propagate the stream through elements */
    /* in practice add a limit to the number
       of elements visited */
    vis_VisContextTouch(vcstream);
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
    /* draw */
    if (streamtype == VIS_STREAMPOINT) {
        animatenumber = 50;
        vis_VisContextSetFlags(vc, VIS_VECTORTAIL | VIS_VECTORTAILREGISTER);
        vis_VisContextSetVectorType(vc, VIS_VECTORCYLINDER);
        vis_VisContextSetSize(vc, .5);
        vis_VisContextSetColor(vc, 1);
        vis_VisContextSetMapColor(vc, VIS_OFF);
    }
    else {
        animatenumber = 1;
        vis_VisContextSetIsoValType(vc, VIS_ISOVALGOURAUD);
        vis_VisContextSetLineStyle(vc, VIS_CYLINDER);
        vis_VisContextSetSize(vc, .03f);
    }
    for (i = 0; i < animatenumber; i++) {
        obj.it = 0;
        obj.itmark = i;
        vgl_DrawFunClear(dfdev);
        /* draw cell outlines */
        vis_VisContextTouch(vccell);
        for (j = 0; j < 4; j++) {
            gather(xhex, con[j], xe);
            vis_CellCurv(cell, xe);
        }
        /* draw tangent curve */
        vis_VisContextTouch(vc);
        vgl_DListCall(dlist);
        vgl_DrawFunSwap(dfdev);
        vgl_DrawFunDelay(dfdev, 1.);
    }
    vgl_DrawFunDelay(dfdev, 5.);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vgl_DrawFunEnd(dfM);
    vgl_DrawFunEnd(dfdev);
    vis_VisContextEnd(vccell);
    vis_VisContextEnd(vc);
    vis_VisContextEnd(vcstream);
    vis_DataIntEnd(dataint);
    vis_ColorMapEnd(cmap);
    vis_LevelsEnd(levels);
    vis_CellEnd(cell);
    vis_MarkEnd(mark);
    vis_SegmentEnd(segment);
    vis_StreamEnd(stream);
    vgl_OpenGLDevEnd(ogldev);
    vgl_DListEnd(dlist);
    free(obj.vmag);

    /* disconnect from window system */
    vgl_OpenGLDevDisconnect();
    /* close X display */
#ifdef VKI_WIND_X11
    XCloseDisplay(display);
#endif
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
