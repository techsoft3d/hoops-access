#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat rgb[9][3] = {{.5, .5, .5}, {1., 0., 0.}, {0., 1., 0.},    {0., 0., 1.}, {0., 1., 1.},
                           {1., 0., 1.}, {1., 1., 0.}, {.2f, .2f, .2f}, {1., 1., 1.}};

static Vfloat xtex[3] = {-.8f, .8f, 0.};
static Vfloat ctex[3] = {1., 1., 1.};

/*----------------------------------------------------------------------
                      Compute and Draw 3-Layer Shell Wall
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_Levels* levels;
    vis_ShellWall* shellwall;
    GLWin* glwin;

    Vint i;
    Vfloat x[3], tm[3][3];
    Vint nlayers = 3;
    Vfloat zp[4] = {0., .2f, .6f, .8f};
    Vint ix[2];
    Vfloat phi[3] = {-45., 0., -45.};
    Vfloat mprop[6];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -1., 1., -1., 1., -1., 1.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    vc = vis_VisContextBegin();
    vis_VisContextSetABCColor(vc, 0, 0, 0);
    vis_VisContextSetXYZColor(vc, 4, 5, 6);
    vis_VisContextSetLineWidth(vc, 2);
    vis_VisContextSetMinorLineWidth(vc, 2);
    vis_VisContextSetSize(vc, .4f);
    vis_VisContextSetMapColor(vc, VIS_ON);

    /* levels for shell wall */
    levels = vis_LevelsBegin();
    vis_LevelsDef(levels, LEVELS_LINEAR, 7);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 9, 0, rgb);

    /* create shellwall object and set objects */
    shellwall = vis_ShellWallBegin();
    vis_ShellWallSetObject(shellwall, VGL_DRAWFUN, df);
    vis_ShellWallSetObject(shellwall, VIS_VISCONTEXT, vc);
    vis_ShellWallSetObject(shellwall, VIS_COLORMAP, cmap);
    vis_ShellWallSetObject(shellwall, VIS_LEVELS, levels);
    vis_ShellWallSetParami(shellwall, SHELLWALL_AXESBASIC, SYS_ON);

    /* define 3 layer laminate */
    vis_ShellWallDef(shellwall, SHELLWALL_GEOMETRY);
    for (i = 1; i <= nlayers + 1; i++) {
        vis_ShellWallSetPoint(shellwall, i, zp[i - 1]);
    }
    for (i = 1; i <= nlayers; i++) {
        ix[0] = i;
        ix[1] = i + 1;
        vis_ShellWallSetLayer(shellwall, i, ix, phi[i - 1], 1);
    }
    /* define lamina material id 1 */
    mprop[0] = 1000000.;
    mprop[1] = 2000000.;
    mprop[2] = .1f;
    mprop[3] = 500000.;
    mprop[4] = 500000.;
    mprop[5] = 500000.;
    vis_ShellWallSetElasProp(shellwall, 1, VIS_MAT_LAMINA, mprop);

    /* compute wall properties */
    vis_ShellWallProps(shellwall);

    /* set position */
    x[0] = 0.;
    x[1] = 0.;
    x[2] = 0.;
    /* set orientation - x' out, y' right, z' up */
    tm[0][0] = 0.;
    tm[0][1] = 0.;
    tm[0][2] = 1.;
    tm[1][0] = 1.;
    tm[1][1] = 0.;
    tm[1][2] = 0.;
    tm[2][0] = 0.;
    tm[2][1] = 1.;
    tm[2][2] = 0.;

    /* draw */
    GLWinClear(glwin);
    GLWinColor(glwin, ctex);
    GLWinText(glwin, xtex, (Vchar*)"3 Layer Shell Wall");
    GLWinRotate(glwin, 20., 'x');
    GLWinRotate(glwin, 60., 'y');
    vis_ShellWallDraw(shellwall, x, tm);
    GLWinSwap(glwin);
    sleep(5);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_LevelsEnd(levels);
    vis_ShellWallEnd(shellwall);
    GLWinEnd(glwin);
    return 0;
}
