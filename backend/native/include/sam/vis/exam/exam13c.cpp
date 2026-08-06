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
                      Compute and Plot Strain on a TEE Beam Section
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_Levels* levels;
    vis_BeamSect* beamsect;
    vis_Contour* contour;
    GLWin* glwin;

    Vint i, j;
    Vfloat dimes[5];
    Vfloat x[3], tm[3][3];
    Vfloat elas[2];
    Vint npoints, nloops, nlines, ntris, nqualpnts, nqualtris;
    Vfloat eks[6], strs[6], strn[6];
    Vfloat st[6], xt[6][3];
    Vfloat *stptr, stmin = 0, stmax = 0;
    Vint ix[6], mid;
    Vfloat props[BEAMSECT_MAXPROPS], dmat[21];
    Vdouble err;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 600, 600);
    GLWinOrtho(glwin, -2., 2., -2., 2., -2., 2.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    vc = vis_VisContextBegin();
    vis_VisContextSetColor(vc, 0);
    vis_VisContextSetXYZColor(vc, 1, 2, 3);
    vis_VisContextSetABCColor(vc, 8, 7, 6);
    vis_VisContextSetEdge(vc, VIS_ON);
    vis_VisContextSetFill(vc, VIS_OFF);
    vis_VisContextSetSize(vc, .5);
    vis_VisContextSetMinorSize(vc, .2f);
    vis_VisContextSetMapColor(vc, VIS_ON);
    vis_VisContextSetIsoValType(vc, VIS_ISOVALTONE);

    /* levels for beam section */
    levels = vis_LevelsBegin();
    vis_LevelsDef(levels, LEVELS_LINEAR, 7);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 9, 0, rgb);

    /* create contour object and set objects */
    contour = vis_ContourBegin();
    vis_ContourSetObject(contour, VGL_DRAWFUN, df);
    vis_ContourSetObject(contour, VIS_VISCONTEXT, vc);
    vis_ContourSetObject(contour, VIS_COLORMAP, cmap);
    vis_ContourSetObject(contour, VIS_LEVELS, levels);

    /* create beamsect object and set objects */
    beamsect = vis_BeamSectBegin();
    vis_BeamSectSetObject(beamsect, VGL_DRAWFUN, df);
    vis_BeamSectSetObject(beamsect, VIS_VISCONTEXT, vc);
    vis_BeamSectSetObject(beamsect, VIS_COLORMAP, cmap);
    vis_BeamSectSetObject(beamsect, VIS_LEVELS, levels);

    /* define TEE section */
    vis_BeamSectDef(beamsect, BEAMSECT_TEE);
    dimes[0] = 3.;
    dimes[1] = 2.;
    dimes[2] = .1f;
    dimes[3] = .3f;
    dimes[4] = .2f;
    vis_BeamSectSetDimensions(beamsect, dimes);

    /* set elastic properties */
    elas[0] = 10000000.;
    elas[1] = .3f;
    mid = 1;
    vis_BeamSectSetElasProp(beamsect, mid, SYS_MAT_ISOTROPIC, elas);
    /* option to draw quality grid edges */
    vis_BeamSectSetParami(beamsect, BEAMSECT_QUALITYGRID, SYS_ON);
    /* option to enable adaptive error refinement,
       set to .5 percent */
    vis_BeamSectSetParami(beamsect, BEAMSECT_REFINE, SYS_ON);
    vis_BeamSectSetParamd(beamsect, BEAMSECT_ERRORTOL, .005);

    /* compute section properties */
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
    printf("Asyz= %f\n", props[8]);
    printf("Ey  = %f\n", props[9]);
    printf("Ez  = %f\n", props[10]);
    printf("Dsy = %f\n", props[11]);
    printf("Dsz = %f\n", props[12]);
    printf("Cw  = %f\n", props[13]);
    printf("Ny  = %f\n", props[14]);
    printf("Nz  = %f\n", props[15]);

    /* retrieve error */
    vis_BeamSectGetDouble(beamsect, BEAMSECT_ERROR, &err);
    printf("error= %e\n", err);

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

    /* set centroidal strain, curvature, twist */
    eks[0] = .001f;
    eks[1] = .002f;
    eks[2] = .003f;
    eks[3] = .004f;
    eks[4] = .005f;
    eks[5] = .006f;
    /* determine number of quality points and triangles */
    vis_BeamSectGetNum(beamsect, &npoints, &nloops, &nlines, &ntris, &nqualpnts, &nqualtris);

    /* allocate memory */
    stptr = (Vfloat*)malloc(sizeof(Vfloat) * nqualpnts);

    /* evaluate stress and strain at each quality point */
    for (i = 1; i <= nqualpnts; i++) {
        vis_BeamSectStrsStrn(beamsect, i, eks, strs, strn);
        /* plot ezx strain */
        stptr[i - 1] = strn[5];
        if (i == 1) {
            stmin = stptr[i - 1];
            stmax = stptr[i - 1];
        }
        else {
            if (stptr[i - 1] < stmin)
                stmin = stptr[i - 1];
            if (stptr[i - 1] > stmax)
                stmax = stptr[i - 1];
        }
    }
    /* set minimum and maximum in Levels for contouring */
    vis_LevelsSetMinMax(levels, stmin, stmax);
    vis_LevelsGenerate(levels, LEVELS_PADNONE);

    vis_ContourSetTopology(contour, VIS_SHAPETRI, 3, 0);

    /* loop through triangles */
    for (i = 1; i <= nqualtris; i++) {
        vis_BeamSectGetQualTri(beamsect, i, ix, &mid);
        for (j = 0; j < 6; j++) {
            vis_BeamSectGetPoint(beamsect, ix[j], xt[j]);
            xt[j][2] = 0.;
            st[j] = stptr[ix[j] - 1];
        }
        vis_ContourCurv(contour, st, xt, VIS_NODATA, NULL);
    }
    vis_BeamSectDraw(beamsect, x, tm, VIS_OFF);

    GLWinSwap(glwin);
    sleep(10);
    /* free memory */
    free(stptr);
    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_LevelsEnd(levels);
    vis_BeamSectEnd(beamsect);
    vis_ContourEnd(contour);
    GLWinEnd(glwin);
    return 0;
}
