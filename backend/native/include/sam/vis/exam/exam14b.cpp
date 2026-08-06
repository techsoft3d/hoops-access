#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat rgb[9][3] = {{.5, .5, .5}, {1., 0., 0.}, {0., 1., 0.},    {0., 0., 1.}, {0., 1., 1.},
                           {1., 0., 1.}, {1., 1., 0.}, {.2f, .2f, .2f}, {1., 1., 1.}};

/*       two 6 node triangular shell elements

           7---8---9
           | \     |
           4---5---6
           |     \ |
           1---2---3
*/
/* midsurface node coordinates */
static Vfloat xmid[9][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                            {2., 1., 0.}, {0., 2., 0.}, {1., 2., 0.}, {2., 2., 0.}};
/* midsurface normals, all in z direction */
static Vfloat vmid[9][3] = {{0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.},
                            {0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}, {0., 0., 1.}};
/* shell element connectivity */
static Vint scon[2][6] = {{1, 3, 7, 2, 5, 4}, {3, 9, 7, 6, 8, 5}};

/*----------------------------------------------------------------------
                      Contour Plot and Cutting Plane 3D Monocoque Shell Elements
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun *df, *dfC;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_Levels* levels;
    vis_Contour* contour;
    vis_VisContext* vct;
    vis_Levels* levelst;
    vis_Threshold* threshold;
    vis_DataInt* dataint;
    GLWin* glwin;
    vis_Connect* connect;
    vis_Group* group;

    Vint i, j, k, m, n;
    Vfloat xbt[2][6][3], sbt[2][6];
    Vfloat xedge[6][3], sedge[6];
    Vfloat sth[2][6];
    Vint numelem, numnode;
    Vint flag, nix, in[3], nn;
    Vfloat thick = .25;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -3., 3., -3., 3., -10., 10.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);
    /* load shell model into Connect object */
    numnode = 9;
    numelem = 2;
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, numnode, numelem);
    /* load nodes */
    for (i = 1; i <= numnode; i++) {
        vis_ConnectSetCoords(connect, i, xmid[i - 1]);
    }
    /* load element connectivity */
    for (i = 1; i <= numelem; i++) {
        vis_ConnectSetTopology(connect, i, VIS_SHAPETRI, 3, 0, 0);
        vis_ConnectSetElemNode(connect, i, scon[i - 1]);
    }
    /* form kernel for adjacency related queries */
    vis_ConnectKernel(connect, 0);
    /* generate element edge group of free edges */
    group = vis_GroupBegin();
    vis_GroupDef(group, numelem, SYS_ELEM, SYS_EDGE);
    vis_ConnectEdgeGroup(connect, CONNECT_FREE, NULL, group);

    vc = vis_VisContextBegin();
    vis_VisContextSetIsoValType(vc, VIS_ISOVALFRINGE);
    vis_VisContextSetMapColor(vc, VIS_ON);
    vis_VisContextSetShade(vc, VIS_VERTEXSHADE);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 9, 0, rgb);

    /* levels object for contouring, 6 levels*/
    levels = vis_LevelsBegin();
    vis_LevelsDef(levels, LEVELS_LINEAR, 6);
    vis_LevelsSetMinMax(levels, 0., 2.5);
    vis_LevelsGenerate(levels, LEVELS_PADTOP);

    /* contour object */
    contour = vis_ContourBegin();
    vis_ContourSetObject(contour, VGL_DRAWFUN, df);
    vis_ContourSetObject(contour, VIS_VISCONTEXT, vc);
    vis_ContourSetObject(contour, VIS_COLORMAP, cmap);
    vis_ContourSetObject(contour, VIS_LEVELS, levels);

    /* rotate 30 times */
    for (k = 0; k < 15; k++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, -k * 4.F, 'x');
        GLWinRotate(glwin, -k * 10.F, 'y');
        /* loop through elements */
        for (i = 1; i <= numelem; i++) {
            /* bottom and top surfaces */
            vis_ContourSetTopology(contour, VIS_SHAPETRI, 3, 0);
            for (j = 0; j < 6; j++) {
                nn = scon[i - 1][j];
                xbt[0][j][0] = xmid[nn - 1][0] - vmid[nn - 1][0] * .5F * thick;
                xbt[0][j][1] = xmid[nn - 1][1] - vmid[nn - 1][1] * .5F * thick;
                xbt[0][j][2] = xmid[nn - 1][2] - vmid[nn - 1][2] * .5F * thick;
                sbt[0][j] = xbt[0][j][0];
                xbt[1][j][0] = xmid[nn - 1][0] + vmid[nn - 1][0] * .5F * thick;
                xbt[1][j][1] = xmid[nn - 1][1] + vmid[nn - 1][1] * .5F * thick;
                xbt[1][j][2] = xmid[nn - 1][2] + vmid[nn - 1][2] * .5F * thick;
                sbt[1][j] = xbt[1][j][0] + .5F;
            }
            /* turn on reflect for bottom */
            vis_VisContextSetReflect(vc, VIS_ON);
            vis_ContourCurv(contour, sbt[0], xbt[0], VIS_NODATA, NULL);
            /* turn off reflect for top */
            vis_VisContextSetReflect(vc, VIS_OFF);
            vis_ContourCurv(contour, sbt[1], xbt[1], VIS_NODATA, NULL);
            /* now loop through 3 edges */
            /* the edge is a quad face
               parabolic in one direction and linear in the other */
            vis_ContourSetTopology(contour, VIS_SHAPEQUAD, 3, 2);
            for (m = 1; m <= 3; m++) {
                /* test to only draw free edges */
                flag = vis_GroupElemEnt(group, i, m);
                if (flag == 0)
                    continue;
                /* get locations of edge data in element arrays */
                vis_ConnectElemCnn(connect, SYS_EDGE, i, m, &nix, in);
                /* set bottom data first and then top data */
                for (n = 0; n < 3; n++) {
                    xedge[n][0] = xbt[0][in[n] - 1][0];
                    xedge[n][1] = xbt[0][in[n] - 1][1];
                    xedge[n][2] = xbt[0][in[n] - 1][2];
                    sedge[n] = sbt[0][in[n] - 1];
                    xedge[3 + n][0] = xbt[1][in[n] - 1][0];
                    xedge[3 + n][1] = xbt[1][in[n] - 1][1];
                    xedge[3 + n][2] = xbt[1][in[n] - 1][2];
                    sedge[3 + n] = sbt[1][in[n] - 1];
                }
                vis_ContourCurv(contour, sedge, xedge, VIS_NODATA, NULL);
            }
        }
        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        GLWinDelay(glwin, 1.);
    }

    /* viscontext for threshold */
    vct = vis_VisContextBegin();
    vis_VisContextSetIsoValType(vct, VIS_ISOVALSURFACE);
    vis_VisContextSetShade(vc, VIS_VERTEXSHADE);

    /* levels object for threshold 1 level*/
    /* the cutting plane is at y = .75 */
    levelst = vis_LevelsBegin();
    vis_LevelsDef(levelst, LEVELS_LINEAR, 1);
    vis_LevelsSetValue(levelst, 1, .75);

    /* data interpolation object for scalar field */
    dataint = vis_DataIntBegin();
    vis_DataIntSetDataPtr(dataint, 0, 1, (Vfloat*)sbt);

    /* create contouring drawing function object */
    dfC = vgl_DrawFunBegin();
    vgl_DrawFunSetObj(dfC, contour);
    vgl_DrawFunAPI(dfC, DRAWFUN_APIRETURN);
    /* use function provided by Contour module */
    vgl_DrawFunSet(dfC, DRAWFUN_POLYGONDATA, (Vfunc*)vis_ContourPolygonData);

    /* threshold object */
    threshold = vis_ThresholdBegin();
    vis_ThresholdSetObject(threshold, VGL_DRAWFUN, dfC);
    vis_ThresholdSetObject(threshold, VIS_VISCONTEXT, vct);
    vis_ThresholdSetObject(threshold, VIS_COLORMAP, cmap);
    vis_ThresholdSetObject(threshold, VIS_LEVELS, levelst);
    vis_ThresholdSetObject(threshold, VIS_DATAINT, dataint);

    /* rotate 30 times */
    for (k = 0; k < 15; k++) {
        GLWinClear(glwin);
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, -k * 4.F, 'x');
        GLWinRotate(glwin, -k * 10.F, 'y');
        /* the 3D shell is respresented as a wedge */
        vis_ThresholdSetTopology(threshold, VIS_SHAPEWED, 3, 0, 2);
        /* loop through elements */
        for (i = 1; i <= numelem; i++) {
            /* bottom and top surfaces */
            /* sth array holds y coordinates */
            for (j = 0; j < 6; j++) {
                nn = scon[i - 1][j];
                xbt[0][j][0] = xmid[nn - 1][0] - vmid[nn - 1][0] * .5F * thick;
                xbt[0][j][1] = xmid[nn - 1][1] - vmid[nn - 1][1] * .5F * thick;
                xbt[0][j][2] = xmid[nn - 1][2] - vmid[nn - 1][2] * .5F * thick;
                sbt[0][j] = xbt[0][j][0];
                sth[0][j] = xbt[0][j][1];
                xbt[1][j][0] = xmid[nn - 1][0] + vmid[nn - 1][0] * .5F * thick;
                xbt[1][j][1] = xmid[nn - 1][1] + vmid[nn - 1][1] * .5F * thick;
                xbt[1][j][2] = xmid[nn - 1][2] + vmid[nn - 1][2] * .5F * thick;
                sbt[1][j] = xbt[1][j][0] + .5F;
                sth[1][j] = xbt[1][j][1];
            }
            vis_ThresholdCurv(threshold, (Vfloat*)sth, (Vfloat(*)[3])xbt, VIS_NODATA, NULL);
        }
        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        GLWinDelay(glwin, 1.);
    }
    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_LevelsEnd(levels);
    vis_ContourEnd(contour);
    vgl_DrawFunEnd(dfC);
    vis_VisContextEnd(vct);
    vis_LevelsEnd(levelst);
    vis_ThresholdEnd(threshold);
    vis_ConnectEnd(connect);
    vis_GroupEnd(group);
    GLWinEnd(glwin);
    return 0;
}
