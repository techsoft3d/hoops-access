#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat rgb[9][3] = {{.5, .5, .5}, {1., 0., 0.}, {0., 1., 0.},    {0., 0., 1.}, {0., 1., 1.},
                           {1., 0., 1.}, {1., 1., 0.}, {.2f, .2f, .2f}, {1., 1., 1.}};

static Vfloat xtex[3] = {-1.8f, 1.8f, 0.};
static Vfloat ctex[3] = {1., 1., 1.};

/* beam element node point locations */
static Vfloat xbeam[2][3] = {{-1.0, .3f, 0.}, {1.0f, .3f, 0.}};

/* dimensions of TEE */
static Vfloat dimes[5] = {3., 2., .1f, .3f, .2f};

/* dimensions of geometry */
static Vfloat xp[6][2] = {{0.2f, 0.2f}, {0.4f, 0.2f}, {0.6f, 0.2f}, {0.6f, 0.4f}, {0.4f, 0.4f}, {0.2f, 0.4f}};
static Vint ix[6] = {1, 2, 3, 4, 5, 6};
/* 3 orientations of beam element axis */
static Vfloat mbeam[3][2][3] = {
{{-1.0, .3f, 0.}, {1.0, .3f, 0}}, {{0.3f, 1., 0.}, {0.3f, -1., 0}}, {{1.0, .3f, 1.}, {1.0, .3f, -1.}}};

/*----------------------------------------------------------------------
                      Draw TEE Beam Element with Local Axis Orientations
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_Levels* levels;
    vis_BeamSect* beamsect;
    vis_BeamElem* beamelem;
    GLWin* glwin;

    int i, k;
    Vfloat vec[3];
    Vfloat v1[2][3], v2[2][3];
    Vchar text[65];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -2., 2., -2., 2., -3., 3.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    vc = vis_VisContextBegin();
    vis_VisContextSetColor(vc, 0);
    vis_VisContextSetXYZColor(vc, 1, 2, 3);
    vis_VisContextSetABCColor(vc, 8, 7, 6);
    vis_VisContextSetEdge(vc, VIS_ON);
    vis_VisContextSetFill(vc, VIS_ON);
    vis_VisContextSetSize(vc, .6f);
    vis_VisContextSetMapColor(vc, VIS_ON);
    vis_VisContextSetRefinement(vc, 2);
    vis_VisContextSetShade(vc, VIS_VERTEXSHADE);
    vis_VisContextSetMarkerType(vc, VIS_BOX);
    vis_VisContextSetElemRep(vc, VIS_ELEMREP_SOLID);
    vis_VisContextSetLineWidth(vc, 2);

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

    /* create beam element object and set objects */
    beamelem = vis_BeamElemBegin();
    vis_BeamElemSetObject(beamelem, VGL_DRAWFUN, df);
    vis_BeamElemSetObject(beamelem, VIS_VISCONTEXT, vc);
    vis_BeamElemSetObject(beamelem, VIS_COLORMAP, cmap);
    vis_BeamElemSetObject(beamelem, VIS_BEAMSECT, beamsect);
    vis_BeamElemSetParami(beamelem, BEAMELEM_SECT, VIS_ON);
    vis_BeamElemSetTopology(beamelem, VIS_SHAPELINE, 2);

    vis_BeamSectDef(beamsect, BEAMSECT_TEE);
    vis_BeamSectSetDimensions(beamsect, dimes);

    /* orient beam element local y' axis */
    for (k = 0; k < 3; k++) {
        /* orient along global z axis */
        if (k == 0) {
            vec[0] = 0.;
            vec[1] = 0.;
            vec[2] = 1.;
            vis_BeamElemSetLocalSystem(beamelem, SYS_ELEMSYS_VECTOR, vec, 0.);
            strcpy(text, "Global Z Axis");
            /* orient 30. degrees from global z axis */
        }
        else if (k == 1) {
            vec[0] = 0.;
            vec[1] = 0.;
            vec[2] = 1.;
            vis_BeamElemSetLocalSystem(beamelem, SYS_ELEMSYS_VECTOR, vec, 30.);
            strcpy(text, "30. Degrees from Global Z Axis");
            /* orient along global y axis */
        }
        else if (k == 2) {
            vec[0] = 0.;
            vec[1] = 1.;
            vec[2] = 0.;
            vis_BeamElemSetLocalSystem(beamelem, SYS_ELEMSYS_VECTOR, vec, 0.);
            strcpy(text, "Global Y Axis");
        }
        /* rotate 10 times */
        for (i = 0; i < 10; i++) {
            GLWinClear(glwin);
            GLWinColor(glwin, ctex);
            GLWinText(glwin, xtex, text);
            GLWinXfmPush(glwin);
            GLWinRotate(glwin, i * 4.F, 'x');
            GLWinRotate(glwin, i * 12.F, 'y');
            vis_BeamElemCurv(beamelem, xbeam, VIS_NODATA, NULL, VIS_NODATA, NULL);
            GLWinXfmPop(glwin);
            GLWinSwap(glwin);
            sleep(1);
        }
    }
    /* orient beam element local y' and z' axes */
    for (k = 0; k < 2; k++) {
        /* rotate 15 times */
        for (i = 0; i < 15; i++) {
            GLWinClear(glwin);
            GLWinColor(glwin, ctex);
            GLWinXfmPush(glwin);
            if (k == 0) {
                v1[0][0] = 0.;
                v1[0][1] = 1.;
                v1[0][2] = 0.;
                v1[1][0] = 0.;
                v1[1][1] = 1.;
                v1[1][2] = 1.;
                strcpy(text, "Twisted Beam");
            }
            else if (k == 1) {
                v1[0][0] = 0.;
                v1[0][1] = 1.;
                v1[0][2] = 0.;
                v1[1][0] = 0.;
                v1[1][1] = 1.;
                v1[1][2] = 0.;
                v2[0][0] = -1.;
                v2[0][1] = 0.;
                v2[0][2] = 1.;
                v2[1][0] = +1.;
                v2[1][1] = 0.;
                v2[1][2] = 1.;
                strcpy(text, "Tilted Beam");
            }
            GLWinText(glwin, xtex, text);
            GLWinRotate(glwin, i * 4.F, 'x');
            GLWinRotate(glwin, i * 12.F, 'y');
            /* twisted beam */
            if (k == 0) {
                vis_BeamElemCurv(beamelem, xbeam, VIS_VERTEXDATA, v1, VIS_NODATA, NULL);
                /* tilted beam*/
            }
            else if (k == 1) {
                vis_BeamElemCurv(beamelem, xbeam, VIS_VERTEXDATA, v1, VIS_VERTEXDATA, v2);
            }
            GLWinXfmPop(glwin);
            GLWinSwap(glwin);
            sleep(1);
        }
    }
    /* user defined geometry */
    vis_BeamSectDef(beamsect, BEAMSECT_GEOMETRY);
    for (i = 1; i <= 6; i++) {
        vis_BeamSectSetPoint(beamsect, i, xp[i - 1]);
    }
    vis_BeamSectSetLoop(beamsect, 1, 1, 6, ix);
    /* orient beam element x' axis along global x, y and z */
    for (k = 0; k < 3; k++) {
        /* local x' along global x, local y' along global z */
        if (k == 0) {
            vec[0] = 0.;
            vec[1] = 0.;
            vec[2] = 1.;
            vis_BeamElemSetLocalSystem(beamelem, SYS_ELEMSYS_VECTOR, vec, 0.);
            strcpy(text, "X' along Global X, Y' along Global Z");
            /* local x' along global y, local y' along global x */
        }
        else if (k == 1) {
            vec[0] = 1.;
            vec[1] = 0.;
            vec[2] = 0.;
            vis_BeamElemSetLocalSystem(beamelem, SYS_ELEMSYS_VECTOR, vec, 0.);
            strcpy(text, "X' along Global Y, Y' along Global X");
            /* local x' along global z, local y' along global y */
        }
        else if (k == 2) {
            vec[0] = 0.;
            vec[1] = 1.;
            vec[2] = 0.;
            vis_BeamElemSetLocalSystem(beamelem, SYS_ELEMSYS_VECTOR, vec, 0.);
            strcpy(text, "X' along Global Z, Y' along Global Y");
        }
        /* rotate 10 times */
        for (i = 0; i < 10; i++) {
            GLWinClear(glwin);
            GLWinColor(glwin, ctex);
            GLWinText(glwin, xtex, text);
            GLWinXfmPush(glwin);
            GLWinRotate(glwin, i * 4.F, 'x');
            GLWinRotate(glwin, i * 12.F, 'y');
            vis_BeamElemCurv(beamelem, mbeam[k], VIS_NODATA, NULL, VIS_NODATA, NULL);
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
    vis_BeamSectEnd(beamsect);
    vis_BeamElemEnd(beamelem);
    GLWinEnd(glwin);
    return 0;
}
