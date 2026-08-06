#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat rgb[8][3] = {{.5f, .5f, .5f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.},
                           {0., 1., 1.},    {1., 0., 1.}, {1., 1., 0.}, {1., 1., 1.}};

static Vfloat xtex[3] = {-1.8f, 1.5f, 0.};
static Vfloat ctex[3] = {1., 1., 1.};

void
draw_elem(vgl_DrawFun* df, vis_MassElem* masselem, Vfloat x[][3], Vchar* text);
void
rotate_elem(vgl_DrawFun* df, vis_MassElem* masselem, Vfloat x[][3], Vchar* text);

/*----------------------------------------------------------------------
                      Draw mass elements
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_MassElem* masselem;
    vis_EProp* eprop;
    vis_CoordSys* coordsys;
    GLWin* glwin;

    Vint i;
    Vfloat x[2][3];
    Vfloat xyzoff[3], inertia[6];
    Vfloat xo[3], v1[3], v2[3], vec[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -2., 2., -2., 2., -2., 2.);
    /* create drawing function object for GLWin */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    vc = vis_VisContextBegin();
    vis_VisContextSetColor(vc, 7);
    vis_VisContextSetMinorColor(vc, 1);
    vis_VisContextSetSize(vc, .5);
    vis_VisContextSetShade(vc, VIS_VERTEXSHADE);
    vis_VisContextSetRefinement(vc, 2);

    vis_VisContextSetXYZColor(vc, 4, 5, 6);
    vis_VisContextSetABCColor(vc, 3, 7, 7);
    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetRGB(cmap, 8, 0, rgb);

    /* create eprop object to control display */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, SYS_ELEM_MASS);

    /* create coordsys object to define local system */
    coordsys = vis_CoordSysBegin();
    vis_CoordSysDef(coordsys, SYS_CARTESIAN);

    /* create masselem object and set objects */
    masselem = vis_MassElemBegin();
    vis_MassElemSetObject(masselem, VGL_DRAWFUN, df);
    vis_MassElemSetObject(masselem, VIS_VISCONTEXT, vc);
    vis_MassElemSetObject(masselem, VIS_COLORMAP, cmap);
    vis_MassElemSetObject(masselem, VIS_EPROP, eprop);

    vis_VisContextSetElemRep(vc, VIS_ELEMREP_SOLID);
    vis_MassElemSetParami(masselem, MASSELEM_PROP, VIS_ON);

    x[0][0] = 0.;
    x[0][1] = 0.;
    x[0][2] = 0.;
    x[1][0] = 1.;
    x[1][1] = 1.;
    x[1][2] = 1.;

    /* draw scalar mass */
    vis_VisContextSetFlags(vc, VIS_DOFBACK);
    vis_EPropSetValuef(eprop, EPROP_MASS, 1.);
    vis_EPropSetValuei(eprop, EPROP_DOF1, SYS_DOF_TY);
    vis_EPropSetValuei(eprop, EPROP_DOF2, SYS_DOF_RX);
    vis_MassElemSetSpec(masselem, SYS_MASS_SCALAR);
    vis_MassElemSetTopology(masselem, SYS_SHAPELINE, 2);
    rotate_elem(df, masselem, x, (Vchar*)"Node to Node Scalar Mass");
    vgl_DrawFunDelay(df, 2.);

    /* draw node to ground scalar mass */
    vis_MassElemSetTopology(masselem, SYS_SHAPEPOINT, 1);
    draw_elem(df, masselem, x, (Vchar*)"Node to Ground Scalar Mass");
    vgl_DrawFunDelay(df, 2.);

    /* lumped mass with rotary inertia and offset */
    vis_MassElemSetSpec(masselem, SYS_MASS_LUMP);
    vis_VisContextSetMinorLineStyle(vc, VIS_DASHDASH);
    /* magnitudes of mass, inertia do not affect icon size */
    inertia[0] = 1.;
    inertia[1] = 2.;
    inertia[2] = 3.;
    inertia[3] = 1.;
    inertia[4] = 2.;
    inertia[5] = 3.;
    vis_EPropSetValuefv(eprop, EPROP_INERTIA, inertia);
    /* offset is represented physically */
    xyzoff[0] = .5;
    xyzoff[1] = .3f;
    xyzoff[2] = .1f;
    vis_EPropSetValuefv(eprop, EPROP_OFFSETVEC, xyzoff);
    /* set and draw local system orientation */
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
    vis_MassElemSetLocalSystem(masselem, SYS_ELEMSYS_ROTANG, vec, 0.);
    rotate_elem(df, masselem, x, (Vchar*)"Lumped Mass with Rotary Inertia");
    vgl_DrawFunDelay(df, 2.);

    /* mass matrix */
    vis_MassElemSetSpec(masselem, SYS_MASS_MATRIX);
    /* open box representation */
    rotate_elem(df, masselem, x, (Vchar*)"Mass Matrix");
    vgl_DrawFunDelay(df, 2.);
    /* checker box representation */
    vis_MassElemSetParami(masselem, MASSELEM_CHECKER, VIS_ON);
    rotate_elem(df, masselem, x, (Vchar*)"Mass Matrix");
    vgl_DrawFunDelay(df, 2.);

    /* mass matrix bitmap representation */
    vis_VisContextSetElemRep(vc, VIS_ELEMREP_BITMAP);
    vis_MassElemSetSpec(masselem, SYS_MASS_MATRIX);
    for (i = 1; i < 8; i++) {
        vis_VisContextSetBitmapSize(vc, i);
        draw_elem(df, masselem, x, (Vchar*)"Mass Matrix");
        vgl_DrawFunDelay(df, 1.);
    }
    vgl_DrawFunDelay(df, 2.);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_MassElemEnd(masselem);
    vis_EPropEnd(eprop);
    vis_CoordSysEnd(coordsys);
    GLWinEnd(glwin);

    return 0;
}

/*----------------------------------------------------------------------
                      draw element
----------------------------------------------------------------------*/
void
draw_elem(vgl_DrawFun* df, vis_MassElem* masselem, Vfloat x[][3], Vchar* text)
{
    vgl_DrawFunClear(df);
    vgl_DrawFunColor(df, ctex);
    vgl_DrawFunText(df, xtex, text);
    vis_MassElemCurv(masselem, x);
    vgl_DrawFunSwap(df);
}

void
rotate_elem(vgl_DrawFun* df, vis_MassElem* masselem, Vfloat x[][3], Vchar* text)
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
        vis_MassElemCurv(masselem, x);
        vgl_DrawFunSwap(df);
        vgl_DrawFunXfmPop(df);
        vgl_DrawFunDelay(df, 1.);
    }
    vgl_XfmEnd(xfm);
}
