#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat rgb[8][3] = {{.5, .5, .5}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.},
                           {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}, {1., 1., 1.}};

static Vfloat xtex[3] = {-1.8f, 1.5f, 0.};
static Vfloat ctex[3] = {1., 1., 1.};

void
draw_elem(vgl_DrawFun* df, vis_GapElem* gapelem, Vfloat x[][3], Vchar* text);
void
rotate_elem(vgl_DrawFun* df, vis_GapElem* gapelem, Vfloat x[][3], Vchar* text);

/*----------------------------------------------------------------------
                      Draw gap elements
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_GapElem* gapelem;
    vis_EProp* eprop;
    vis_CoordSys* coordsys;
    GLWin* glwin;

    Vfloat x[2][3];
    Vfloat xo[3], v1[3], v2[3], vec[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -2., 2., -2., 2., -2., 2.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    vc = vis_VisContextBegin();
    vis_VisContextSetColor(vc, 1);
    vis_VisContextSetMinorColor(vc, 7);
    vis_VisContextSetSize(vc, .5);
    vis_VisContextSetShade(vc, VIS_VERTEXSHADE);
    vis_VisContextSetRefinement(vc, 2);
    vis_VisContextSetABCColor(vc, 3, 7, 7);
    vis_VisContextSetXYZColor(vc, 4, 5, 6);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetRGB(cmap, 8, 0, rgb);

    /* create eprop object to control display */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, SYS_ELEM_GAP);

    /* create coordsys object to define local system */
    coordsys = vis_CoordSysBegin();
    vis_CoordSysDef(coordsys, SYS_CARTESIAN);

    /* create gapelem object and set objects */
    gapelem = vis_GapElemBegin();
    vis_GapElemSetObject(gapelem, VGL_DRAWFUN, df);
    vis_GapElemSetObject(gapelem, VIS_VISCONTEXT, vc);
    vis_GapElemSetObject(gapelem, VIS_COLORMAP, cmap);
    vis_GapElemSetObject(gapelem, VIS_EPROP, eprop);

    vis_VisContextSetElemRep(vc, VIS_ELEMREP_SOLID);

    vis_GapElemSetParami(gapelem, DISCELEM_PROP, VIS_ON);

    x[0][0] = 0.;
    x[0][1] = 0.;
    x[0][2] = 0.;
    x[1][0] = 1.;
    x[1][1] = 0.;
    x[1][2] = 0.;

    /* draw node to node gap */
    vis_GapElemSetTopology(gapelem, SYS_SHAPELINE, 2);
    vis_EPropSetValuef(eprop, EPROP_UZERO, .05f);
    /* non coincident nodes */
    rotate_elem(df, gapelem, x, (Vchar*)"Node to Node Gap Non Coincident");
    vgl_DrawFunDelay(df, 2.);
    /* coincident nodes, need local system for orientation */
    x[1][0] = 0.;
    x[1][1] = 0.;
    x[1][2] = 0.;
    vis_VisContextSetElemAxes(vc, VIS_ON);
    xo[0] = 0.;
    xo[1] = 0.;
    xo[2] = 0.;
    v1[0] = 1.;
    v1[1] = 1.;
    v1[2] = 0.;
    v2[0] = 0.;
    v2[1] = 1.;
    v2[2] = 0.;
    vis_CoordSysSetOriginVectors(coordsys, xo, v1, v2);
    vis_CoordSysRotAng(coordsys, x[0], vec);
    vis_GapElemSetLocalSystem(gapelem, SYS_ELEMSYS_ROTANG, vec, 0.);
    rotate_elem(df, gapelem, x, (Vchar*)"Node to Node Gap Coincident");
    vgl_DrawFunDelay(df, 2.);

    /* draw node to ground gap */
    vis_GapElemSetParami(gapelem, DISCELEM_PROP, VIS_OFF);
    vis_GapElemSetTopology(gapelem, SYS_SHAPEPOINT, 1);
    rotate_elem(df, gapelem, x, (Vchar*)"Node to Ground Gap");
    vgl_DrawFunDelay(df, 2.);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_GapElemEnd(gapelem);
    vis_EPropEnd(eprop);
    vis_CoordSysEnd(coordsys);
    GLWinEnd(glwin);
    return 0;
}

/*----------------------------------------------------------------------
                      draw element
----------------------------------------------------------------------*/
void
draw_elem(vgl_DrawFun* df, vis_GapElem* gapelem, Vfloat x[][3], Vchar* text)
{
    vgl_DrawFunClear(df);
    vgl_DrawFunColor(df, ctex);
    vgl_DrawFunText(df, xtex, text);
    vis_GapElemCurv(gapelem, x);
    vgl_DrawFunSwap(df);
}

void
rotate_elem(vgl_DrawFun* df, vis_GapElem* gapelem, Vfloat x[][3], Vchar* text)
{
    Vint i;
    vgl_Xfm* xfm;
    Vfloat tm[4][4];

    xfm = vgl_XfmBegin();
    for (i = 0; i < 8; i++) {
        vgl_DrawFunClear(df);
        vgl_DrawFunColor(df, ctex);
        vgl_DrawFunText(df, xtex, text);
        vgl_DrawFunXfmPush(df);
        vgl_XfmRotate(xfm, -i * 8.F * 3.14F / 180.F, XFM_YAXIS);
        vgl_XfmGetMatrix(xfm, tm);
        vgl_DrawFunXfmLoad(df, tm);
        vis_GapElemCurv(gapelem, x);
        vgl_DrawFunSwap(df);
        vgl_DrawFunXfmPop(df);
        vgl_DrawFunDelay(df, 1.);
    }
    vgl_XfmEnd(xfm);
}
