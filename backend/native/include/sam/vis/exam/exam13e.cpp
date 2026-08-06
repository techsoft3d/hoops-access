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

static Vfloat xbeam[3][3] = {{-1.5f, .3f, 0.}, {0., 0., 0.}, {1.5f, .3f, 0.}};
static Vfloat sbeam[3] = {5., 3., 8.};

/*----------------------------------------------------------------------
                      Draw TEE Beam Element Bending Moment Diagram
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

    int i, j;
    Vfloat dimes[5];
    Vfloat factors[2];

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
    vis_VisContextSetMinorColor(vc, 8);
    vis_VisContextSetXYZColor(vc, 1, 2, 3);
    vis_VisContextSetABCColor(vc, 8, 7, 6);
    vis_VisContextSetEdge(vc, VIS_ON);
    vis_VisContextSetFill(vc, VIS_ON);
    vis_VisContextSetSize(vc, 1.);
    vis_VisContextSetMinorSize(vc, .2f);
    vis_VisContextSetMapColor(vc, VIS_ON);
    vis_VisContextSetMapSize(vc, VIS_ON);
    vis_VisContextSetRefinement(vc, 2);
    vis_VisContextSetShade(vc, VIS_VERTEXSHADE);
    vis_VisContextSetMarkerType(vc, VIS_BOX);
    vis_VisContextSetIsoValType(vc, VIS_ISOVALFRINGE);

    /* levels for beam section */
    levels = vis_LevelsBegin();
    vis_LevelsDef(levels, LEVELS_LINEAR, 7);
    vis_LevelsSetMinMax(levels, 2., 8.);
    vis_LevelsGenerate(levels, LEVELS_PADNONE);

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
    vis_BeamSectSetParami(beamsect, BEAMSECT_CENTROID, BEAMSECT_CENTROID_SPHERE);
    vis_BeamSectSetParami(beamsect, BEAMSECT_SHEARCENTER, VIS_ON);
    vis_BeamSectSetParami(beamsect, BEAMSECT_AXESBASIC, VIS_ON);
    vis_BeamSectSetParami(beamsect, BEAMSECT_AXESPRINCIPAL, VIS_ON);

    /* define TEE section */
    vis_BeamSectDef(beamsect, BEAMSECT_TEE);
    dimes[0] = 3.;
    dimes[1] = 2.;
    dimes[2] = .1f;
    dimes[3] = .3f;
    dimes[4] = .2f;
    vis_BeamSectSetDimensions(beamsect, dimes);

    /* create beam element object and set objects */
    beamelem = vis_BeamElemBegin();
    vis_BeamElemSetObject(beamelem, VGL_DRAWFUN, df);
    vis_BeamElemSetObject(beamelem, VIS_VISCONTEXT, vc);
    vis_BeamElemSetObject(beamelem, VIS_COLORMAP, cmap);
    vis_BeamElemSetObject(beamelem, VIS_BEAMSECT, beamsect);
    vis_BeamElemSetObject(beamelem, VIS_LEVELS, levels);
    vis_BeamElemSetParami(beamelem, BEAMELEM_SECT, VIS_ON);

    vis_BeamElemSetTopology(beamelem, VIS_SHAPELINE, 3);
    factors[0] = 1.;
    factors[1] = .5;
    vis_BeamElemSetEndFactors(beamelem, factors);

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
        }
        else if (j == 3) {
            vis_VisContextSetElemRep(vc, VIS_ELEMREP_SOLID);
        }
        else if (j == 4) {
            vis_VisContextSetElemRep(vc, VIS_ELEMREP_SOLID);
            vis_VisContextSetMapColor(vc, VIS_OFF);
            vis_BeamSectSetParami(beamsect, BEAMSECT_POLYLINE, VIS_ON);
        }

        for (i = 0; i < 10; i++) {
            GLWinClear(glwin);
            GLWinColor(glwin, ctex);
            GLWinText(glwin, xtex, (Vchar*)"TEE Beam Element");
            GLWinXfmPush(glwin);
            GLWinRotate(glwin, i * 4.F, 'x');
            GLWinRotate(glwin, i * 12.F, 'y');
            /* draw diagram along y' axis */
            vis_BeamElemDiagram(beamelem, sbeam, SYS_YAXIS, xbeam, VIS_NODATA, NULL, VIS_NODATA, NULL);
            /* draw beam */
            vis_BeamElemCurv(beamelem, xbeam, VIS_NODATA, NULL, VIS_NODATA, NULL);
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
