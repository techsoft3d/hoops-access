#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat rgb[9][3] = {{.5f, .5f, .5f}, {1., 0., 0.}, {0., 1., 0.},    {0., 0., 1.}, {0., 1., 1.},
                           {1., 0., 1.},    {1., 1., 0.}, {.2f, .2f, .2f}, {1., 1., 1.}};

static Vfloat xtex[3] = {-1.8f, 1.8f, 0.};
static Vfloat ctex[3] = {1., 1., 1.};

/*----------------------------------------------------------------------
                      Compute and Draw TEE Beam Section
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_Levels* levels;
    vis_BeamSect* beamsect;
    GLWin* glwin;

    Vfloat dimes[5];
    Vfloat x[3], tm[3][3];
    Vfloat props[BEAMSECT_MAXPROPS];
    Vfloat dmat[21];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -2., 2., -2., 2., -2., 2.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    vc = vis_VisContextBegin();
    vis_VisContextSetColor(vc, 0);
    vis_VisContextSetXYZColor(vc, 1, 2, 3);
    vis_VisContextSetABCColor(vc, 8, 7, 6);
    vis_VisContextSetEdge(vc, VIS_ON);
    vis_VisContextSetFill(vc, VIS_ON);
    vis_VisContextSetSize(vc, .5);
    vis_VisContextSetMinorSize(vc, .2f);
    vis_VisContextSetMapColor(vc, VIS_ON);

    /* levels for beam section */
    levels = vis_LevelsBegin();
    vis_LevelsDef(levels, LEVELS_LINEAR, 7);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 9, 0, rgb);

    /* create beamsect object and set objects */
    beamsect = vis_BeamSectBegin();
    vis_BeamSectSetObject(beamsect, VGL_DRAWFUN, df);
    vis_BeamSectSetObject(beamsect, VIS_VISCONTEXT, vc);
    vis_BeamSectSetObject(beamsect, VIS_COLORMAP, cmap);
    vis_BeamSectSetObject(beamsect, VIS_LEVELS, levels);

    /* set display parameters */
    vis_BeamSectSetParami(beamsect, BEAMSECT_AXESBASIC, VIS_ON);
    vis_BeamSectSetParami(beamsect, BEAMSECT_AXESPRINCIPAL, VIS_ON);
    vis_BeamSectSetParami(beamsect, BEAMSECT_CENTROID, BEAMSECT_CENTROID_CIRCLE);
    vis_BeamSectSetParami(beamsect, BEAMSECT_SHEARCENTER, VIS_ON);

    /* define TEE section */
    vis_BeamSectDef(beamsect, BEAMSECT_TEE);
    dimes[0] = 3.;
    dimes[1] = 2.;
    dimes[2] = .1f;
    dimes[3] = .3f;
    dimes[4] = .2f;
    vis_BeamSectSetDimensions(beamsect, dimes);

    /* compute and get section properties */
    vis_BeamSectProps(beamsect);
    vis_BeamSectGetProps(beamsect, props, dmat);

    /* print section properties */
    printf("\n");
    printf("A   = %f\n", props[0]);
    printf("Iyy = %f\n", props[1]);
    printf("Izz = %f\n", props[2]);
    printf("Iyz = %f\n", props[3]);
    printf("Ang = %f\n", props[4]);
    printf("J   = %f\n", props[5]);
    printf("Asy = %f\n", props[6]);
    printf("Asz = %f\n", props[7]);
    printf("Ey  = %f\n", props[9]);
    printf("Ez  = %f\n", props[10]);
    printf("Dsy = %f\n", props[11]);
    printf("Dsz = %f\n", props[12]);
    printf("Cw  = %f\n", props[13]);
    printf("Ny  = %f\n", props[14]);
    printf("Nz  = %f\n", props[15]);

    /* draw */
    GLWinClear(glwin);
    GLWinColor(glwin, ctex);
    GLWinText(glwin, xtex, (Vchar*)"TEE Beam Section");
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
    vis_BeamSectDraw(beamsect, x, tm, VIS_OFF);
    GLWinSwap(glwin);
    sleep(5);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_LevelsEnd(levels);
    vis_BeamSectEnd(beamsect);
    GLWinEnd(glwin);
    return 0;
}
