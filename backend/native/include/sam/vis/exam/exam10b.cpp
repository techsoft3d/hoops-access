#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

void
gather(Vfloat x[][3], Vint npts, Vint con[], Vfloat xe[][3], Vfloat se[]);

/* Finite Element Model */
#define MAX_ELEM 2
#define MAX_NODE 10

/* node coordinates */
static Vfloat x[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                                {0., 0., 1.}, {1., 0., 1.}, {2., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}};

/* element connectivity */
static Vint numconn[MAX_ELEM] = {8, 6};
static Vint conn[MAX_ELEM][8] = {{1, 2, 5, 4, 6, 7, 10, 9}, {2, 3, 5, 7, 8, 10, 0, 0}};
static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEWED};

/* face data */
static Vint numface[MAX_ELEM] = {6, 5};
static Vint numconnface[MAX_ELEM][6] = {{4, 4, 4, 4, 4, 4}, {3, 3, 4, 4, 4, 0}};
/* face connectivity relative to parent element */
static Vint indxface[MAX_ELEM][6][4] = {{{1, 4, 3, 2}, {5, 6, 7, 8}, {1, 2, 6, 5}, {4, 8, 7, 3}, {1, 5, 8, 4}, {2, 3, 7, 6}},

                                        {{1, 3, 2, 0}, {4, 5, 6, 0}, {1, 2, 5, 4}, {1, 4, 6, 3}, {2, 3, 6, 5}, {0, 0, 0, 0}}};

/* colors */
static Vfloat rgb[2][3] = {{1., 1., 1.}, {1., 0., 0.}};

/*----------------------------------------------------------------------
                      Draw Mesh Section Using Contour and Threshold
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_Levels* levels;
    vis_ColorMap* cmap;
    vis_Contour* contour;
    vis_Threshold* threshold;
    GLWin* glwin;

    int i, j, k, n;
    Vint nlevels;
    Vint nfc, ifx[4];
    Vfloat xe[8][3], se[8];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -1., 3., -1., 3., -2., 2.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetMapColor(vc, VIS_MAPCOLOR_NONE);

    /* levels, set twelve evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 1;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetValue(levels, 1, .5);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetRGB(cmap, 2, 1, rgb);

    /* create contour object and set objects */
    contour = vis_ContourBegin();
    vis_ContourSetObject(contour, VGL_DRAWFUN, df);
    vis_ContourSetObject(contour, VIS_VISCONTEXT, vc);
    vis_ContourSetObject(contour, VIS_LEVELS, levels);
    vis_ContourSetObject(contour, VIS_COLORMAP, cmap);

    /* create threshold object and set objects */
    threshold = vis_ThresholdBegin();
    vis_ThresholdSetObject(threshold, VGL_DRAWFUN, df);
    vis_ThresholdSetObject(threshold, VIS_VISCONTEXT, vc);
    vis_ThresholdSetObject(threshold, VIS_LEVELS, levels);
    vis_ThresholdSetObject(threshold, VIS_COLORMAP, cmap);

    /* draw mesh section */
    for (k = 0; k < 10; k++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, k * 12.F, 'y');
        for (j = 0; j < MAX_ELEM; j++) {
            /* use threshold to draw cut through element in white */
            vis_VisContextSetIsoValType(vc, VIS_ISOVALSURFACE);
            vis_VisContextSetColor(vc, 1);
            vis_ThresholdSetTopology(threshold, shap[j], 2, 0, 0);
            gather(x, numconn[j], conn[j], xe, se);
            vis_ThresholdCurv(threshold, se, xe, VIS_NODATA, NULL);
            /* use contour to draw cut through element faces in red */
            vis_VisContextSetIsoValType(vc, VIS_ISOVALLINE);
            vis_VisContextSetColor(vc, 2);
            vis_VisContextSetLineWidth(vc, 2);
            /* loop through faces and get face nodes */
            for (i = 0; i < numface[j]; i++) {
                nfc = numconnface[j][i];
                for (n = 0; n < nfc; n++) {
                    ifx[n] = conn[j][indxface[j][i][n] - 1];
                }
                if (nfc == 3) {
                    vis_ContourSetTopology(contour, SYS_SHAPETRI, 2, 0);
                }
                else {
                    vis_ContourSetTopology(contour, SYS_SHAPEQUAD, 2, 0);
                }
                gather(x, nfc, ifx, xe, se);
                vis_ContourCurv(contour, se, xe, VIS_NODATA, NULL);
            }
        }
        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(5);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_LevelsEnd(levels);
    vis_ColorMapEnd(cmap);
    vis_ContourEnd(contour);
    vis_ThresholdEnd(threshold);
    GLWinEnd(glwin);
    return 0;
}

/*----------------------------------------------------------------------
                      Utility function to gather element data
----------------------------------------------------------------------*/
void
gather(Vfloat xArg[][3], Vint npts, Vint con[], Vfloat xe[][3], Vfloat se[])
{
    int i, j;

    for (i = 0; i < npts; i++) {
        for (j = 0; j < 3; j++) {
            xe[i][j] = xArg[con[i] - 1][j];
        }
        /* return z coordinate as scalar */
        se[i] = xArg[con[i] - 1][2];
    }
}
