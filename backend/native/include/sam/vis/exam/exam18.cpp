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
draw_elem(vgl_DrawFun* df, vis_RigidElem* rigidelem, Vfloat x[][3], Vchar* text);
void
rotate_elem(vgl_DrawFun* df, vis_RigidElem* rigidelem, Vfloat x[][3], Vchar* text);

/*----------------------------------------------------------------------
                      Draw rigid elements
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_RigidElem* rigidelem;
    vis_EProp* eprop;
    GLWin* glwin;

    Vfloat x[4][3];
    Vint dofflagind[4], dofflagdep[4];
    Vfloat wgts[4];

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
    vis_EPropDef(eprop, SYS_ELEM_RIGID);

    /* create rigidelem object and set objects */
    rigidelem = vis_RigidElemBegin();
    vis_RigidElemSetObject(rigidelem, VGL_DRAWFUN, df);
    vis_RigidElemSetObject(rigidelem, VIS_VISCONTEXT, vc);
    vis_RigidElemSetObject(rigidelem, VIS_COLORMAP, cmap);
    vis_RigidElemSetObject(rigidelem, VIS_EPROP, eprop);

    vis_VisContextSetElemRep(vc, VIS_ELEMREP_SOLID);
    vis_RigidElemSetParami(rigidelem, RIGIDELEM_PROP, VIS_ON);

    x[0][0] = 0.;
    x[0][1] = 0.;
    x[0][2] = 0.;
    x[1][0] = 1.;
    x[1][1] = 1.;
    x[1][2] = 1.;
    x[2][0] = 1.;
    x[2][1] = .5;
    x[2][2] = 0.;
    x[3][0] = 0.;
    x[3][1] = 1.;
    x[3][2] = 1.;

    /* draw distributing coupling, RBE3 */
    vis_VisContextSetFlags(vc, VIS_DOFBACK);
    vis_EPropSetValuei(eprop, EPROP_DOFFLAG_NUM, 4);
    dofflagdep[0] = 63;
    dofflagdep[1] = 0;
    dofflagdep[2] = 0;
    dofflagdep[3] = 0;
    dofflagind[0] = 0;
    dofflagind[1] = 7;
    dofflagind[2] = 7;
    dofflagind[3] = 7;
    vis_EPropSetValueiv(eprop, EPROP_DOFFLAG_IND, dofflagind);
    vis_EPropSetValueiv(eprop, EPROP_DOFFLAG_DEP, dofflagdep);
    wgts[0] = 1.;
    wgts[1] = 1.;
    wgts[2] = .5;
    wgts[3] = .25;
    vis_RigidElemSetParami(rigidelem, RIGIDELEM_WGTSIZEFLAG, VIS_ON);
    vis_RigidElemSetParamf(rigidelem, RIGIDELEM_WGTSIZE, .1f);
    vis_EPropSetValuefv(eprop, EPROP_DOFFLAG_WGTS, wgts);
    vis_RigidElemSetSpec(rigidelem, SYS_RIGID_DIST);
    /* 4 nodes; 1 dependent, 3 independent */
    vis_RigidElemSetTopology(rigidelem, SYS_SHAPEPOINT, 4);
    /* with properties */
    rotate_elem(df, rigidelem, x, (Vchar*)"Distributing Coupling with Properties");
    vgl_DrawFunDelay(df, 2.);
    /* without properties */
    vis_RigidElemSetParami(rigidelem, RIGIDELEM_PROP, VIS_OFF);
    vis_RigidElemSetParami(rigidelem, RIGIDELEM_WGTSIZEFLAG, VIS_OFF);
    rotate_elem(df, rigidelem, x, (Vchar*)"Distributing Coupling without Properties");
    vgl_DrawFunDelay(df, 2.);

    /* draw kinematic coupling, RBE2 */
    vis_RigidElemSetParami(rigidelem, RIGIDELEM_PROP, VIS_ON);
    vis_EPropSetValuei(eprop, EPROP_DOFFLAG_NUM, 2);
    dofflagdep[0] = 0;
    dofflagdep[1] = 7;
    dofflagind[0] = 63;
    dofflagind[1] = 0;
    vis_EPropSetValueiv(eprop, EPROP_DOFFLAG_IND, dofflagind);
    vis_EPropSetValueiv(eprop, EPROP_DOFFLAG_DEP, dofflagdep);
    vis_RigidElemSetSpec(rigidelem, SYS_RIGID_DIST);
    rotate_elem(df, rigidelem, x, (Vchar*)"Kinematic Coupling");
    vgl_DrawFunDelay(df, 2.);

    /* rigid link, RROD */
    vis_RigidElemSetSpec(rigidelem, SYS_RIGID_LINK);
    vis_EPropSetValuei(eprop, EPROP_DOFFLAG_NUM, 2);
    dofflagdep[0] = 2;
    dofflagdep[1] = 0;
    dofflagind[0] = 5;
    dofflagind[1] = 7;
    vis_EPropSetValueiv(eprop, EPROP_DOFFLAG_IND, dofflagind);
    vis_EPropSetValueiv(eprop, EPROP_DOFFLAG_DEP, dofflagdep);
    vis_RigidElemSetTopology(rigidelem, SYS_SHAPELINE, 2);
    rotate_elem(df, rigidelem, x, (Vchar*)"Rigid Link");
    vgl_DrawFunDelay(df, 2.);

    /* rigid triangular plate, RTRPLT */
    vis_RigidElemSetSpec(rigidelem, SYS_RIGID_KINE);
    vis_RigidElemSetTopology(rigidelem, SYS_SHAPETRI, 2);
    vis_RigidElemSetParami(rigidelem, RIGIDELEM_PROP, VIS_OFF);
    rotate_elem(df, rigidelem, x, (Vchar*)"Rigid Triangular Plate");
    vgl_DrawFunDelay(df, 2.);

    /* multi-point constraint */
    vis_RigidElemSetSpec(rigidelem, SYS_RIGID_MPC);
    vis_EPropSetValuei(eprop, EPROP_DOFFLAG_NUM, 4);
    dofflagdep[0] = 2;
    dofflagdep[1] = 0;
    dofflagdep[2] = 0;
    dofflagdep[3] = 0;
    dofflagind[0] = 0;
    dofflagind[1] = 2;
    dofflagind[2] = 4;
    dofflagind[3] = 2;
    vis_EPropSetValueiv(eprop, EPROP_DOFFLAG_IND, dofflagind);
    vis_EPropSetValueiv(eprop, EPROP_DOFFLAG_DEP, dofflagdep);
    wgts[0] = 1.;
    wgts[1] = .5;
    wgts[2] = 1.51265f;
    wgts[3] = .5;
    vis_EPropSetValuefv(eprop, EPROP_DOFFLAG_WGTS, wgts);
    vis_RigidElemSetParami(rigidelem, RIGIDELEM_PROP, VIS_ON);
    vis_RigidElemSetTopology(rigidelem, SYS_SHAPEPOINT, 4);
    rotate_elem(df, rigidelem, x, (Vchar*)"Multi-Point Constraint");
    vgl_DrawFunDelay(df, 2.);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_RigidElemEnd(rigidelem);
    vis_EPropEnd(eprop);
    GLWinEnd(glwin);
    return 0;
}

/*----------------------------------------------------------------------
                      draw element
----------------------------------------------------------------------*/
void
draw_elem(vgl_DrawFun* df, vis_RigidElem* rigidelem, Vfloat x[][3], Vchar* text)
{
    vgl_DrawFunClear(df);
    vgl_DrawFunColor(df, ctex);
    vgl_DrawFunText(df, xtex, text);
    vis_RigidElemCurv(rigidelem, x);
    vgl_DrawFunSwap(df);
}

void
rotate_elem(vgl_DrawFun* df, vis_RigidElem* rigidelem, Vfloat x[][3], Vchar* text)
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
        vis_RigidElemCurv(rigidelem, x);
        vgl_DrawFunSwap(df);
        vgl_DrawFunXfmPop(df);
        vgl_DrawFunDelay(df, 1.);
    }
    vgl_XfmEnd(xfm);
}
