#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static void
gather(Vfloat x[][3], Vint conArg[8], Vfloat xe[][3]);

/* coordinates in cylindrical system */
static Vfloat xcyl[21][3] = {
{2.00000000e+000f, 0.00000000e+000f, 1.00000000e+000f}, {3.00000000e+000f, 0.00000000e+000f, 1.00000000e+000f},
{4.00000000e+000f, 0.00000000e+000f, 1.00000000e+000f}, {5.00000000e+000f, 0.00000000e+000f, 1.00000000e+000f},
{6.00000000e+000f, 0.00000000e+000f, 1.00000000e+000f}, {2.00000000e+000f, 1.95084646e-001f, 9.80786383e-001f},
{4.00000000e+000f, 1.95084646e-001f, 9.80786383e-001f}, {6.00000000e+000f, 1.95084646e-001f, 9.80786383e-001f},
{2.00000000e+000f, 3.82672727e-001f, 9.23883975e-001f}, {3.00000000e+000f, 3.82672727e-001f, 9.23883975e-001f},
{4.00000000e+000f, 3.82672727e-001f, 9.23883975e-001f}, {5.00000000e+000f, 3.82672727e-001f, 9.23883975e-001f},
{6.00000000e+000f, 3.82672727e-001f, 9.23883975e-001f}, {2.00000000e+000f, 5.55555761e-001f, 8.31479251e-001f},
{4.00000000e+000f, 5.55555761e-001f, 8.31479251e-001f}, {6.00000000e+000f, 5.55555761e-001f, 8.31479251e-001f},
{2.00000000e+000f, 7.07090378e-001f, 7.07123160e-001f}, {3.00000000e+000f, 7.07090378e-001f, 7.07123160e-001f},
{4.00000000e+000f, 7.07090378e-001f, 7.07123160e-001f}, {5.00000000e+000f, 7.07090378e-001f, 7.07123160e-001f},
{6.00000000e+000f, 7.07090378e-001f, 7.07123160e-001f}};

/* 4 quadratic 8-node surface elements */
/* element connectivity */
static Vint con[4][8] = {
{1, 3, 11, 9, 2, 7, 10, 6}, {3, 5, 13, 11, 4, 8, 12, 7}, {9, 11, 19, 17, 10, 15, 18, 14}, {11, 13, 21, 19, 12, 16, 20, 15}};

/* use this array to determine element adjacency */
static Vint adj[4][4] = {{0, 2, 3, 0}, {0, 0, 4, 1}, {1, 4, 0, 0}, {2, 0, 0, 3}};

static Vfloat rgb[16][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Generate tangent curve constrained to cylindrical surface
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext *vcface, *vcmark, *vctrace;
    vis_ColorMap* cmap;
    vis_Face* face;
    vis_Mark* mark;
    vis_Trace* trace;
    vis_Levels* levels;
    GLWin* glwin;

    int j;
    Vfloat xe[8][3], ve[8][3], xc[3];
    Vint nn;
    Vfloat t;
    Vint status, edgenumber;
    Vfloat tout;
    Vfloat v[3], w[3], vout[3], wout[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, 0., 8., -2., 2., -6., 6.);

    /* create drawing function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* vis context and set attributes */
    /* face edges in red */
    vcface = vis_VisContextBegin();
    vis_VisContextSetEdge(vcface, VIS_ON);
    vis_VisContextSetFill(vcface, VIS_OFF);
    vis_VisContextSetColor(vcface, 3);
    vis_VisContextSetRefinement(vcface, 0);

    /* vectors in blue */
    vcmark = vis_VisContextBegin();
    vis_VisContextSetFlags(vcmark, VIS_VECTORTAIL | VIS_VECTORTAILREGISTER);
    vis_VisContextSetVectorType(vcmark, VIS_VECTORCYLINDER);
    vis_VisContextSetSize(vcmark, 1.);
    vis_VisContextSetMapColor(vcmark, VIS_OFF);
    vis_VisContextSetColor(vcmark, 3);
    vis_VisContextSetMapSize(vcmark, VIS_ON);

    /* trace in yellow */
    vctrace = vis_VisContextBegin();
    vis_VisContextSetLineWidth(vctrace, 2);
    vis_VisContextSetColor(vctrace, 6);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 7, 0, rgb);

    /* levels */
    levels = vis_LevelsBegin();
    vis_LevelsSetMinMax(levels, 0., 6.);

    /* create face object and set objects */
    face = vis_FaceBegin();
    vis_FaceSetObject(face, VGL_DRAWFUN, df);
    vis_FaceSetObject(face, VIS_VISCONTEXT, vcface);
    vis_FaceSetObject(face, VIS_COLORMAP, cmap);
    vis_FaceSetTopology(face, SYS_SHAPEQUAD, 3, 0);

    /* create mark object and set objects */
    mark = vis_MarkBegin();
    vis_MarkSetObject(mark, VGL_DRAWFUN, df);
    vis_MarkSetObject(mark, VIS_VISCONTEXT_VECTOR, vcmark);
    vis_MarkSetObject(mark, VIS_COLORMAP, cmap);
    vis_MarkSetObject(mark, VIS_LEVELS, levels);

    /* create trace object and set objects */
    trace = vis_TraceBegin();
    vis_TraceSetObject(trace, VGL_DRAWFUN, df);
    vis_TraceSetObject(trace, VIS_VISCONTEXT, vctrace);
    vis_TraceSetObject(trace, VIS_COLORMAP, cmap);
    vis_TraceSetTopology(trace, SYS_SHAPEQUAD, 3, 0);

    GLWinClear(glwin);

    /* draw face outlines */
    vis_VisContextTouch(vcface);
    for (j = 0; j < 4; j++) {
        gather(xcyl, con[j], xe);
        vis_FaceCurv(face, xe, 0, NULL);
    }
    /* draw vectors */
    vis_VisContextTouch(vcmark);
    vis_MarkVector(mark, 21, xcyl, xcyl);
    /* draw tangent curve */
    vis_VisContextTouch(vctrace);
    t = 0.;
    nn = 0;
    v[0] = 0.;
    v[1] = 0.;
    v[2] = 0.;
    w[0] = 0.;
    w[1] = 0.;
    w[2] = 0.;
    gather(xcyl, con[nn], xe);
    xc[0] = 0.5F * (xe[0][0] + xe[3][0]);
    xc[1] = 0.5F * (xe[0][1] + xe[3][1]);
    xc[2] = 0.5F * (xe[0][2] + xe[3][2]);
    for (;;) {
        gather(xcyl, con[nn], xe);
        gather(xcyl, con[nn], ve);
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
    GLWinSwap(glwin);
    sleep(10);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vcface);
    vis_VisContextEnd(vcmark);
    vis_VisContextEnd(vctrace);
    vis_ColorMapEnd(cmap);
    vis_FaceEnd(face);
    vis_MarkEnd(mark);
    vis_TraceEnd(trace);
    vis_LevelsEnd(levels);
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
