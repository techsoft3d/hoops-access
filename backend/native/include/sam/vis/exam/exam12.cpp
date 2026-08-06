#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat rgb[8][3] = {{.8f, .8f, .8f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.},
                           {0., 1., 1.},    {1., 0., 1.}, {1., 1., 0.}, {1., 1., 1.}};

static Vfloat xtex[3] = {-.5, 3.5, 0.};
static Vfloat ctex[3] = {1., 1., 1.};

/*----------------------------------------------------------------------
                      Draw triads
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_Triad* triad;
    GLWin* glwin;

    int i;
    Vfloat x[3], tm[3][3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 700, 500);
    GLWinOrtho(glwin, -1., 6., -1., 4., -4., 4.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    vc = vis_VisContextBegin();
    vis_VisContextSetLineWidth(vc, 2);
    vis_VisContextSetMinorColor(vc, 0);
    vis_VisContextSetSize(vc, 1.);
    vis_VisContextSetMinorSize(vc, .5);
    vis_VisContextSetColor(vc, 7);
    vis_VisContextSetXYZColor(vc, 1, 2, 3);
    vis_VisContextSetABCColor(vc, 7, 7, 7);
    vis_VisContextSetTrans(vc, 1);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 8, 0, rgb);

    /* create triad object and set objects */
    triad = vis_TriadBegin();
    vis_TriadSetObject(triad, VGL_DRAWFUN, df);
    vis_TriadSetObject(triad, VIS_VISCONTEXT, vc);
    vis_TriadSetObject(triad, VIS_COLORMAP, cmap);

    /* set triad orientation to the global system */
    tm[0][0] = 1.;
    tm[0][1] = 0.;
    tm[0][2] = 0.;
    tm[1][0] = 0.;
    tm[1][1] = 1.;
    tm[1][2] = 0.;
    tm[2][0] = 0.;
    tm[2][1] = 0.;
    tm[2][2] = 1.;

    /* use line vectors and no detail */
    vis_VisContextSetVectorType(vc, VIS_VECTORLINE);
    vis_TriadSetParami(triad, TRIAD_DETAIL, VIS_OFF);

    /* draw basic triads */
    for (i = 0; i < 8; i++) {
        GLWinClear(glwin);
        GLWinColor(glwin, ctex);
        GLWinText(glwin, xtex, (Vchar*)"Basic Triads");
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 8.F, 'x');
        GLWinRotate(glwin, i * 4.F, 'y');

        x[0] = 0.;
        x[1] = 0.;
        x[2] = 0.;
        vis_TriadDraw(triad, SYS_CARTESIAN, x, tm);
        x[0] = 2.;
        x[1] = 0.;
        x[2] = 0.;
        vis_TriadDraw(triad, SYS_CYLINDRICAL, x, tm);
        x[0] = 4.;
        x[1] = 0.;
        x[2] = 0.;
        vis_TriadDraw(triad, SYS_CYLINDRICAL_ALT, x, tm);
        x[0] = 0.;
        x[1] = 2.;
        x[2] = 0.;
        vis_TriadDraw(triad, SYS_SPHERICAL, x, tm);
        x[0] = 2.;
        x[1] = 2.;
        x[2] = 0.;
        vis_TriadDraw(triad, SYS_SPHERICAL_ALT, x, tm);
        x[0] = 4.;
        x[1] = 2.;
        x[2] = 0.;
        vis_TriadDraw(triad, SYS_TOROIDAL, x, tm);

        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(2);

    /* use umbrella vectors, detail and shape */
    vis_VisContextSetVectorType(vc, VIS_VECTORUMBRELLA);
    vis_TriadSetParami(triad, TRIAD_DETAIL, VIS_ON);
    vis_TriadSetParami(triad, TRIAD_SHAPE, VIS_ON);

    /* draw detailed triads */
    for (i = 0; i < 8; i++) {
        GLWinClear(glwin);
        GLWinColor(glwin, ctex);
        GLWinText(glwin, xtex, (Vchar*)"Detailed Triads");
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 8.F, 'x');
        GLWinRotate(glwin, i * 4.F, 'y');

        x[0] = 0.;
        x[1] = 0.;
        x[2] = 0.;
        vis_TriadDraw(triad, SYS_CARTESIAN, x, tm);
        x[0] = 2.;
        x[1] = 0.;
        x[2] = 0.;
        vis_TriadDraw(triad, SYS_CYLINDRICAL, x, tm);
        x[0] = 4.;
        x[1] = 0.;
        x[2] = 0.;
        vis_TriadDraw(triad, SYS_CYLINDRICAL_ALT, x, tm);
        x[0] = 0.;
        x[1] = 2.;
        x[2] = 0.;
        vis_TriadDraw(triad, SYS_SPHERICAL, x, tm);
        x[0] = 2.;
        x[1] = 2.;
        x[2] = 0.;
        vis_TriadDraw(triad, SYS_SPHERICAL_ALT, x, tm);
        x[0] = 4.;
        x[1] = 2.;
        x[2] = 0.;
        vis_TriadDraw(triad, SYS_TOROIDAL, x, tm);

        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(4);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_TriadEnd(triad);
    GLWinEnd(glwin);
    return 0;
}
