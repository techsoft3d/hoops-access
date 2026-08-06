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

static Vfloat xbeam[2][3] = {{0., 0., 0.}, {1.5f, .3f, 0.}};

/*----------------------------------------------------------------------
                      Contour Stress on a TEE Beam Element
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
    vis_Contour* contour;
    GLWin* glwin;

    int i, j, n, nn;
    Vfloat dimes[5];
    Vint npoints, nloops, nlines, ntris, nqualpnts, nqualtris;
    Vfloat xs[2], xb[2][3];
    Vint type, npts, *ix;
    Vint reflectflag;
    Vfloat(*xl)[3], *sl, *s1, *s2;
    Vfloat props[BEAMSECT_MAXPROPS];
    Vfloat dmat[21];
    Vfloat area, iyy, izz;
    Vfloat nx1, my1, mz1;
    Vfloat nx2, my2, mz2;
    Vfloat smin, smax;
    Vfloat st1[3], xt1[3][3];
    Vfloat st2[3], xt2[3][3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -2., 2., -2., 2., -2., 2.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    vc = vis_VisContextBegin();
    vis_VisContextSetShade(vc, VIS_VERTEXSHADE);
    vis_VisContextSetIsoValType(vc, VIS_ISOVALFRINGE);

    /* levels for contouring */
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

    /* create beamsect object */
    beamsect = vis_BeamSectBegin();

    /* define TEE section */
    vis_BeamSectDef(beamsect, BEAMSECT_TEE);
    dimes[0] = 3.;
    dimes[1] = 2.;
    dimes[2] = .1f;
    dimes[3] = .3f;
    dimes[4] = .2f;
    vis_BeamSectSetDimensions(beamsect, dimes);

    /* compute and retrieve section properties */
    vis_BeamSectProps(beamsect);
    vis_BeamSectGetProps(beamsect, props, dmat);
    area = props[0];
    iyy = props[1];
    izz = props[2];

    /* create beam element object and set objects */
    beamelem = vis_BeamElemBegin();
    vis_BeamElemSetObject(beamelem, VIS_BEAMSECT, beamsect);

    /* straight beam segment */
    vis_BeamElemSetTopology(beamelem, VIS_SHAPELINE, 2);

    /* get number of points and loops */
    vis_BeamSectGetNum(beamsect, &npoints, &nloops, &nlines, &ntris, &nqualpnts, &nqualtris);

    /* allocate memory for possibly all point ids */
    ix = (Vint*)malloc(sizeof(Vint) * npoints);

    /* allocate memory for point stress data at each end */
    s1 = (Vfloat*)malloc(sizeof(Vfloat) * npoints);
    s2 = (Vfloat*)malloc(sizeof(Vfloat) * npoints);

    /* assume some end forces and moments */
    nx1 = 100.;
    my1 = 3.;
    mz1 = 20.;
    nx2 = 100.;
    my2 = 6.;
    mz2 = 40.;
    /* compute stresses */
    smin = smax = 0.;
    for (n = 1; n <= npoints; n++) {
        vis_BeamSectGetPoint(beamsect, n, xs);
        /* first end */
        s1[n - 1] = nx1 / area + my1 * xs[0] / iyy + mz1 * xs[1] / izz;
        if (s1[n - 1] < smin)
            smin = s1[n - 1];
        if (s1[n - 1] > smax)
            smax = s1[n - 1];

        /* second end */
        s2[n - 1] = nx2 / area + my2 * xs[0] / iyy + mz2 * xs[1] / izz;
        if (s2[n - 1] < smin)
            smin = s2[n - 1];
        if (s2[n - 1] > smax)
            smax = s2[n - 1];
    }
    /* generate contour levels */
    vis_LevelsSetMinMax(levels, smin, smax);
    vis_LevelsGenerate(levels, LEVELS_PADNONE);

    /* allocate memory for local stress and coordinate arrays */
    sl = (Vfloat*)malloc(sizeof(Vfloat) * 2 * (npoints + 1));
    xl = (Vfloat(*)[3])malloc(3 * sizeof(Vfloat) * 2 * (npoints + 1));

    /* rotate display 30 times */
    /* contour the complete surface of the beam */
    for (i = 0; i < 30; i++) {
        GLWinClear(glwin);
        GLWinColor(glwin, ctex);
        GLWinText(glwin, xtex, (Vchar*)"TEE Beam Complete Loop Surface Contour");
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 4.F, 'x');
        GLWinRotate(glwin, i * 12.F, 'y');
        GLWinRotate(glwin, i * 6.F, 'z');

        /* loop over loops, the first loop is the outer loop */
        for (j = 1; j <= nloops; j++) {
            vis_BeamSectGetLoop(beamsect, j, &type, &npts, ix);
            vis_ContourSetTopology(contour, VIS_SHAPEQUAD, 2, npts + 1);
            reflectflag = (j == 1);
            for (n = 0; n <= npts; n++) {
                nn = n % npts;

                /* compute coordinates */
                vis_BeamElemCoords(beamelem, ix[nn], reflectflag, xbeam, VIS_NODATA, NULL, VIS_NODATA, NULL, &xl[2 * n]);

                /* gather stress */
                if (reflectflag) {
                    sl[2 * n + 1] = s1[ix[nn] - 1];
                    sl[2 * n] = s2[ix[nn] - 1];
                }
                else {
                    sl[2 * n] = s1[ix[nn] - 1];
                    sl[2 * n + 1] = s2[ix[nn] - 1];
                }
            }
            vis_ContourCurv(contour, sl, xl, VIS_NODATA, NULL);
        }

        /* cap ends, loop over tris */
        vis_ContourSetTopology(contour, VIS_SHAPETRI, 2, 0);
        for (j = 1; j <= ntris; j++) {
            vis_BeamSectGetTri(beamsect, j, ix);
            for (n = 0; n < 3; n++) {
                vis_BeamElemCoords(beamelem, ix[n], 0, xbeam, VIS_NODATA, NULL, VIS_NODATA, NULL, xb);
                /* invert first end to point outward */
                xt1[2 - n][0] = xb[0][0];
                xt1[2 - n][1] = xb[0][1];
                xt1[2 - n][2] = xb[0][2];
                st1[2 - n] = s1[ix[n] - 1];
                /* second end is already pointed outward */
                xt2[n][0] = xb[1][0];
                xt2[n][1] = xb[1][1];
                xt2[n][2] = xb[1][2];
                st2[n] = s2[ix[n] - 1];
            }
            vis_ContourCurv(contour, st1, xt1, VIS_NODATA, NULL);
            vis_ContourCurv(contour, st2, xt2, VIS_NODATA, NULL);
        }

        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(5);
    /* rotate display 30 times */
    /* contour the polyline representation of the beam */
    for (i = 0; i < 30; i++) {
        GLWinClear(glwin);
        GLWinColor(glwin, ctex);
        GLWinText(glwin, xtex, (Vchar*)"TEE Beam PolyLine Surface Contour");
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 4.F, 'x');
        GLWinRotate(glwin, i * 12.F, 'y');
        GLWinRotate(glwin, i * 6.F, 'z');

        /* loop over polylines */
        for (j = 1; j <= nlines; j++) {
            vis_BeamSectGetPolyLine(beamsect, j, &type, &npts, ix);
            for (n = 0; n < npts; n++) {
                /* compute coordinates */
                vis_BeamElemCoords(beamelem, ix[n], 0, xbeam, VIS_NODATA, NULL, VIS_NODATA, NULL, &xl[2 * n]);

                /* gather stress */
                sl[2 * n] = s1[ix[n] - 1];
                sl[2 * n + 1] = s2[ix[n] - 1];
            }
            /* close polyline if necessary */
            if (type == VIS_ON) {
                vis_ContourSetTopology(contour, VIS_SHAPEQUAD, 2, npts + 1);
                vis_BeamElemCoords(beamelem, ix[0], 0, xbeam, VIS_NODATA, NULL, VIS_NODATA, NULL, &xl[2 * npts]);
                sl[2 * npts] = s1[ix[0] - 1];
                sl[2 * npts + 1] = s2[ix[0] - 1];
            }
            else {
                vis_ContourSetTopology(contour, VIS_SHAPEQUAD, 2, npts);
            }
            vis_ContourCurv(contour, sl, xl, VIS_NODATA, NULL);
        }

        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(5);
    /* free allocated memory */
    free(ix);
    free(s1);
    free(s2);
    free(sl);
    free(xl);
    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_LevelsEnd(levels);
    vis_BeamSectEnd(beamsect);
    vis_BeamElemEnd(beamelem);
    vis_ContourEnd(contour);
    GLWinEnd(glwin);
    return 0;
}
