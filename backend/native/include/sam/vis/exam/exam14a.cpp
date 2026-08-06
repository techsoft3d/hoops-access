#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat rgb[9][3] = {{.5, .5, .5}, {1., 0., 0.}, {0., 1., 0.},    {0., 0., 1.}, {0., 1., 1.},
                           {1., 0., 1.}, {1., 1., 0.}, {.2f, .2f, .2f}, {1., 1., 1.}};

static Vfloat xtex[3] = {-.8f, 2.8f, 0.};
static Vfloat ctex[3] = {1., 1., 1.};
/* cylindrical shell midsurface coordinates */
static Vfloat xshell[6][3] = {{0., 0., 0.}, {2., 0., 0.},          {0., 1., 1.},
                              {1., 0., 0.}, {1.f, .7071f, .2928f}, {0.f, .7071f, .2928f}};
/* shell midsurface normals */
static Vfloat vshell[6][3] = {{0., 0., 1.}, {0., 0., 1.},          {0., -1., 0.},
                              {0., 0., 1.}, {0., -.7071f, .7071f}, {0., -.7071f, .7071f}};

/*----------------------------------------------------------------------
                      Draw 3-Layer Parabolic Triangular Shell Element
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_Levels* levels;
    vis_ShellElem* shellelem;
    vis_ShellWall* shellwall;
    GLWin* glwin;

    Vint i, j;
    Vfloat factors[3];
    Vint nlayers = 3;
    Vfloat zp[4] = {0., .02f, .06f, .08f};
    Vint ix[2];
    Vfloat phi[3] = {-45., 0., -45.};
    Vfloat mprop[6];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 600, 600);
    GLWinOrtho(glwin, -.5, 2.5, -.5, 2.5, -10., 10.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    vc = vis_VisContextBegin();
    /* surfaces gray */
    vis_VisContextSetColor(vc, 0);
    vis_VisContextSetMinorColor(vc, 0);
    vis_VisContextSetABCColor(vc, 0, 0, 0);

    vis_VisContextSetXYZColor(vc, 1, 2, 3);
    vis_VisContextSetFill(vc, VIS_ON);
    vis_VisContextSetEdge(vc, VIS_OFF);
    vis_VisContextSetSize(vc, .4f);
    vis_VisContextSetMapColor(vc, VIS_ON);
    vis_VisContextSetRefinement(vc, 2);
    vis_VisContextSetScale(vc, 2.);
    vis_VisContextSetShade(vc, VIS_VERTEXSHADE);
    vis_VisContextSetElemRep(vc, VIS_ELEMREP_SOLID);

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

    /* create shell object and set objects */
    shellelem = vis_ShellElemBegin();
    vis_ShellElemSetObject(shellelem, VGL_DRAWFUN, df);
    vis_ShellElemSetObject(shellelem, VIS_VISCONTEXT, vc);
    vis_ShellElemSetObject(shellelem, VIS_COLORMAP, cmap);
    vis_ShellElemSetObject(shellelem, VIS_SHELLWALL, shellwall);
    vis_ShellElemSetParami(shellelem, SHELLELEM_WALL, VIS_ON);

    vis_ShellElemSetTopology(shellelem, VIS_SHAPETRI, 3, 0);
    factors[0] = 1.;
    factors[1] = 1.5;
    factors[2] = 1.75;
    vis_ShellElemSetCornerFactors(shellelem, factors);

    /* draw */
    for (j = 0; j < 5; j++) {
        if (j == 0) {
            vis_VisContextSetElemLoc(vc, VIS_ELEMLOC_CENTROID);
            vis_VisContextSetElemRep(vc, VIS_ELEMREP_SEMI);
        }
        else if (j == 1) {
            vis_VisContextSetElemLoc(vc, VIS_ELEMLOC_CORNERS);
            vis_VisContextSetElemRep(vc, VIS_ELEMREP_SEMI);
        }
        else if (j == 2) {
            vis_VisContextSetElemLoc(vc, VIS_ELEMLOC_NODES);
            vis_VisContextSetElemRep(vc, VIS_ELEMREP_SEMI);
            /* bottom surface green, top surface red */
        }
        else if (j == 3) {
            vis_VisContextSetColor(vc, 1);
            vis_VisContextSetMinorColor(vc, 2);
            vis_VisContextSetElemRep(vc, VIS_ELEMREP_SOLID);
            vis_ShellElemSetParami(shellelem, SHELLELEM_WALL, VIS_OFF);
        }
        else if (j == 4) {
            vis_VisContextSetColor(vc, 0);
            vis_VisContextSetMinorColor(vc, 0);
            vis_VisContextSetElemRep(vc, VIS_ELEMREP_SOLID);
            vis_ShellElemSetParami(shellelem, SHELLELEM_WALL, VIS_ON);
        }

        for (i = 0; i < 10; i++) {
            GLWinClear(glwin);
            GLWinColor(glwin, ctex);
            GLWinText(glwin, xtex, (Vchar*)"3 Layer Shell Element");
            GLWinXfmPush(glwin);
            GLWinRotate(glwin, i * 4.F, 'x');
            GLWinRotate(glwin, i * 11.F, 'y');
            /* draw shell using exact normals */
            vis_ShellElemCurv(shellelem, xshell, VIS_VERTEXDATA, vshell);
            GLWinXfmPop(glwin);
            GLWinSwap(glwin);
            sleep(1);
        }
    }
    sleep(5);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_LevelsEnd(levels);
    vis_ShellWallEnd(shellwall);
    vis_ShellElemEnd(shellelem);
    GLWinEnd(glwin);
    return 0;
}
