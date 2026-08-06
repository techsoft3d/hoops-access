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
draw_elem(vgl_DrawFun* df, vis_DiscElem* discelem, Vfloat x[][3], Vchar* text);
void
rotate_elem(vgl_DrawFun* df, vis_DiscElem* discelem, Vfloat x[][3], Vchar* text);

/*----------------------------------------------------------------------
                      Draw discrete elements
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_DiscElem* discelem;
    vis_EProp* eprop;
    GLWin* glwin;

    int i;
    Vfloat x[7][3];
    Vfloat xend[3];

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

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetRGB(cmap, 8, 0, rgb);

    /* create eprop object to control display */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, SYS_ELEM_SPRINGDASHPOT);

    /* create discelem object and set objects */
    discelem = vis_DiscElemBegin();
    vis_DiscElemSetObject(discelem, VGL_DRAWFUN, df);
    vis_DiscElemSetObject(discelem, VIS_VISCONTEXT, vc);
    vis_DiscElemSetObject(discelem, VIS_COLORMAP, cmap);
    vis_DiscElemSetObject(discelem, VIS_EPROP, eprop);

    vis_VisContextSetElemRep(vc, VIS_ELEMREP_SOLID);

    vis_DiscElemSetParami(discelem, DISCELEM_WINDINGS, 2);
    vis_DiscElemSetParami(discelem, DISCELEM_PROP, VIS_ON);

    x[0][0] = 0.;
    x[0][1] = 0.;
    x[0][2] = 0.;
    x[1][0] = 1.;
    x[1][1] = 1.;
    x[1][2] = 1.;

    /* draw scalar spring */
    vis_VisContextSetFlags(vc, VIS_DOFBACK);
    vis_EPropSetValuei(eprop, EPROP_DOF1, SYS_DOF_TY);
    vis_EPropSetValuei(eprop, EPROP_DOF2, SYS_DOF_RX);
    vis_EPropSetValuef(eprop, EPROP_STIFF, 1.);
    vis_EPropSetValuef(eprop, EPROP_DAMP, 0.);
    vis_DiscElemSetSpec(discelem, SYS_SPRINGDASHPOT_SCALAR);
    vis_DiscElemSetTopology(discelem, SYS_SHAPELINE, 2);
    rotate_elem(df, discelem, x, (Vchar*)"Node to Node Scalar Spring");
    vgl_DrawFunDelay(df, 2.);

    /* draw link spring and dashpot */
    vis_EPropSetValuef(eprop, EPROP_STIFF, 1.);
    vis_EPropSetValuef(eprop, EPROP_DAMP, 1.);
    vis_DiscElemSetSpec(discelem, SYS_SPRINGDASHPOT_LINK);
    vis_DiscElemSetTopology(discelem, SYS_SHAPELINE, 2);
    rotate_elem(df, discelem, x, (Vchar*)"Node to Node Link Spring and Dashpot");
    vgl_DrawFunDelay(df, 2.);

    /* draw node to ground spring and dashpot */
    vis_DiscElemSetTopology(discelem, SYS_SHAPEPOINT, 1);
    draw_elem(df, discelem, x, (Vchar*)"Node to Ground Spring and Dashpot");
    vgl_DrawFunDelay(df, 2.);

    /* draw node to ground dashpot only */
    vis_EPropSetValuef(eprop, EPROP_STIFF, 0.);
    draw_elem(df, discelem, x, (Vchar*)"Node to Ground Link Dashpot");
    vgl_DrawFunDelay(df, 2.);

    /* draw node to ground spring only */
    vis_EPropSetValuef(eprop, EPROP_STIFF, 1.);
    vis_EPropSetValuef(eprop, EPROP_DAMP, 0.);
    draw_elem(df, discelem, x, (Vchar*)"Node to Ground Link Spring");
    vgl_DrawFunDelay(df, 2.);

    /* draw node to ground spring only, line representation */
    vis_VisContextSetElemRep(vc, VIS_ELEMREP_LINE);
    draw_elem(df, discelem, x, (Vchar*)"Node to Ground Link Spring");
    vgl_DrawFunDelay(df, 2.);

    /* draw node to ground spring only, bitmap representation */
    vis_VisContextSetElemRep(vc, VIS_ELEMREP_BITMAP);
    for (i = 1; i < 8; i++) {
        vis_VisContextSetBitmapSize(vc, i);
        draw_elem(df, discelem, x, (Vchar*)"Node to Ground Link Spring");
        vgl_DrawFunDelay(df, 1.);
    }
    vgl_DrawFunDelay(df, 2.);
    vis_VisContextSetBitmapSize(vc, 1);

    /* draw bush with translation and rotation springs */
    vis_VisContextSetElemRep(vc, VIS_ELEMREP_SOLID);
    vis_EPropSetValuef(eprop, EPROP_STIFFTRA, 1.);
    vis_EPropSetValuef(eprop, EPROP_STIFFROT, 1.);
    vis_DiscElemSetSpec(discelem, SYS_SPRINGDASHPOT_BUSH);
    vis_DiscElemSetTopology(discelem, SYS_SHAPELINE, 2);
    rotate_elem(df, discelem, x, (Vchar*)"Node to Node Bush");
    vgl_DrawFunDelay(df, 2.);

    /* draw weld with topological end connections */
    /* end A quad */
    x[0][0] = 0.;
    x[0][1] = 0.;
    x[0][2] = 0.;
    x[1][0] = 1.;
    x[1][1] = 0.;
    x[1][2] = 0.;
    x[2][0] = 1.;
    x[2][1] = 1.;
    x[2][2] = 0.;
    x[3][0] = 0.;
    x[3][1] = 1.;
    x[3][2] = 0.;
    /* end B tri */
    x[4][0] = 0.;
    x[4][1] = 0.;
    x[4][2] = 1.;
    x[5][0] = 1.;
    x[5][1] = 0.;
    x[5][2] = 1.;
    x[6][0] = 1.;
    x[6][1] = 1.;
    x[6][2] = 1.;

    /* set diameter of weld */
    vis_EPropSetValuef(eprop, EPROP_DOUT, .2f);
    vis_DiscElemSetSpec(discelem, SYS_SPRINGDASHPOT_WELD);
    /* set topologies of end points */
    vis_DiscElemSetEndTopo(discelem, SYS_TOPO_QUAD4SER, SYS_TOPO_TRI3);
    /* location of spot weld */
    xend[0] = .4f;
    xend[1] = .2f;
    xend[2] = .5;
    vis_DiscElemSetEndCon(discelem, SYS_ELEMEND_POSITION, xend, SYS_ELEMEND_POSITION, xend);
    vis_DiscElemSetTopology(discelem, SYS_SHAPEPOINT, 7);
    rotate_elem(df, discelem, x, (Vchar*)"Elem to Elem Weld");
    vgl_DrawFunDelay(df, 2.);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_DiscElemEnd(discelem);
    vis_EPropEnd(eprop);
    GLWinEnd(glwin);
    return 0;
}

/*----------------------------------------------------------------------
                      draw element
----------------------------------------------------------------------*/
void
draw_elem(vgl_DrawFun* df, vis_DiscElem* discelem, Vfloat x[][3], Vchar* text)
{
    vgl_DrawFunClear(df);
    vgl_DrawFunColor(df, ctex);
    vgl_DrawFunText(df, xtex, text);
    vis_DiscElemCurv(discelem, x);
    vgl_DrawFunSwap(df);
}

void
rotate_elem(vgl_DrawFun* df, vis_DiscElem* discelem, Vfloat x[][3], Vchar* text)
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
        vis_DiscElemCurv(discelem, x);
        vgl_DrawFunSwap(df);
        vgl_DrawFunXfmPop(df);
        vgl_DrawFunDelay(df, 1.);
    }
    vgl_XfmEnd(xfm);
}
