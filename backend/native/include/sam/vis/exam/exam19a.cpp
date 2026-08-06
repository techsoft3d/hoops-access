#include <stdio.h>
#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/vis/exam/glwin.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vfloat rgb[7][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/* a simple hollow cube */
static Vdouble coords[16][3] = {{-10., -10., -10.}, {10., -10., -10.}, {-10., 10., -10.}, {10., 10., -10.},
                                {-10., -10., 10.},  {10., -10., 10.},  {-10., 10., 10.},  {10., 10., 10.},
                                {-11., -11., -11.}, {11., -11., -11.}, {-11., 11., -11.}, {11., 11., -11.},
                                {-11., -11., 11.},  {11., -11., 11.},  {-11., 11., 11.},  {11., 11., 11.}};

static Vint tris[24][3] = {{3, 5, 1},    {7, 5, 3},    {2, 6, 4},    {4, 6, 8},    {5, 2, 1},    {6, 2, 5},
                           {3, 4, 7},    {7, 4, 8},    {2, 4, 1},    {3, 1, 4},    {7, 8, 5},    {8, 6, 5},
                           {9, 13, 11},  {11, 13, 15}, {12, 14, 10}, {16, 14, 12}, {9, 10, 13},  {13, 10, 14},
                           {15, 12, 11}, {16, 12, 15}, {9, 12, 10},  {12, 9, 11},  {13, 16, 15}, {13, 14, 16}};

void
loadsurface(vis_Connect* connectsrf);
void
readsurface(vis_Connect* connectsrf, Vchar* path);
void
outlinesurface(vis_Connect* connectsrf, Vdouble xn[3], Vdouble vn[3], vis_Tess* tess);

/*----------------------------------------------------------------------
         Cross product between two vectors
----------------------------------------------------------------------*/
static void
cross(Vdouble a[3], Vdouble b[3], Vdouble c[3])
{
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
}

/*----------------------------------------------------------------------
         Difference between two vectors
----------------------------------------------------------------------*/
static void
diff(Vdouble a[3], Vdouble b[3], Vdouble c[3])
{
    c[0] = a[0] - b[0];
    c[1] = a[1] - b[1];
    c[2] = a[2] - b[2];
}

/*----------------------------------------------------------------------
                      Triangulate a Planar Slice of a Bounded Tesselation
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    vis_Connect* connectsrf;
    vis_Tess* tess;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    GLWin* glwin;
    vgl_DrawFun* df;

    Vdouble bbox[2][3], d[3], blen, xn[3], vn[3];
    Vfloat xmin, xmax, ymin, ymax;
    Vfloat dx, dy, xc, yc, sca;
    Vint numunrec, numdrawtri;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object of surface */
    connectsrf = vis_ConnectBegin();
    /* load surface from static arrays */
    if (argc < 2) {
        loadsurface(connectsrf);
        /* read surface from STL file */
    }
    else {
        readsurface(connectsrf, argv[1]);
    }
    /* compute extent */
    vis_ConnectExtentdv(connectsrf, NULL, bbox);
    diff(bbox[1], bbox[0], d);
    blen = sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);

    /* cutting plane normal to z axis */
    xn[0] = 0.;
    xn[1] = 0.;
    xn[2] = .5 * (bbox[0][2] + bbox[1][2]);

    vn[0] = 0.;
    vn[1] = 0.;
    vn[2] = 1.;

    xmin = (Vfloat)bbox[0][0];
    xmax = (Vfloat)bbox[1][0];
    ymin = (Vfloat)bbox[0][1];
    ymax = (Vfloat)bbox[1][1];
    /* determine orthographic limits to fit view */
    /* assuming a square viewport */
    dx = xmax - xmin;
    xc = .5F * (xmax + xmin);
    dy = ymax - ymin;
    yc = .5F * (ymax + ymin);
    if (dx > dy) {
        sca = dx / dy;
        ymin = yc - .5F * sca * dy;
        ymax = yc + .5F * sca * dy;
    }
    else {
        sca = dy / dx;
        xmin = xc - .5F * sca * dx;
        xmax = xc + .5F * sca * dx;
    }
    /* add a bit of margin */
    xmin = xmin - .05F * (xmax - xmin);
    xmax = xmax + .05F * (xmax - xmin);
    ymin = ymin - .05F * (ymax - ymin);
    ymax = ymax + .05F * (ymax - ymin);
    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);
    GLWinOrtho(glwin, xmin, xmax, ymin, ymax, -10000., 10000);

    tess = vis_TessBegin();
    vis_TessDef(tess, 0, 0);
    /* create outline mesh on surface triangles */
    /* create tess object */
    outlinesurface(connectsrf, xn, vn, tess);

    /* visualization context */
    vc = vis_VisContextBegin();
    vis_VisContextSetColor(vc, 4);
    vis_VisContextSetMinorColor(vc, 5);
    vis_VisContextSetShade(vc, VIS_VERTEXSHADE);
    vis_VisContextSetPrimType(vc, VIS_PRIM_STRIP);
    vis_VisContextSetEdge(vc, VIS_ON);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 7, 0, rgb);

    /* normal to cutting plane */
    vis_TessSetNormaldv(tess, vn);
    /* set objects for drawing */
    vis_TessSetObject(tess, VIS_VISCONTEXT, vc);
    vis_TessSetObject(tess, VIS_COLORMAP, cmap);
    vis_TessSetObject(tess, VGL_DRAWFUN, df);
    vis_TessSetParamd(tess, TESS_INTERTOL, .00001 * blen);

    /* draw */
    GLWinClear(glwin);
    vis_TessDraw(tess);
    vis_TessGetInteger(tess, TESS_NUMUNREC, &numunrec);
    vis_TessGetInteger(tess, TESS_NUMDRAWTRI, &numdrawtri);
    if (numunrec || numdrawtri == 0) {
        printf("numunrec=   %d\n", numunrec);
        printf("numdrawtri= %d\n", numdrawtri);
    }
    GLWinSwap(glwin);
    sleep(10);
    /* end Tess */
    vis_ConnectEnd(connectsrf);
    vis_TessEnd(tess);
    vis_ColorMapEnd(cmap);
    vis_VisContextEnd(vc);
    GLWinEnd(glwin);
    vgl_DrawFunEnd(df);
    return 0;
}

void
loadsurface(vis_Connect* connectsrf)
{
    Vint i;

    printf("load surface from static arrays\n");
    vis_ConnectDef(connectsrf, 0, 0);
    /* set nodes */
    for (i = 0; i < 16; i++) {
        vis_ConnectSetCoordsdv(connectsrf, i + 1, coords[i]);
    }
    /* set triangles */
    for (i = 0; i < 24; i++) {
        vis_ConnectSetTopology(connectsrf, i + 1, VIS_SHAPETRI, 2, 0, 0);
        vis_ConnectSetElemNode(connectsrf, i + 1, tris[i]);
    }
}

void
readsurface(vis_Connect* connectsrf, Vchar* path)
{
    vis_Connect* connect;

    connect = vis_ConnectBegin();
    if (strstr(path, ".stl") != NULL) {
        printf("read surface from stl file: %s\n", path);
        vis_ConnectRead(connect, SYS_FILE_STL, path);
    }
    else if (strstr(path, ".STL") != NULL) {
        printf("read surface from binary stl file: %s\n", path);
        vis_ConnectRead(connect, SYS_FILE_STLBIN, path);
    }
    /* copy it */
    vis_ConnectCopy(connectsrf, connect);
    vis_ConnectEnd(connect);
}

void
outlinesurface(vis_Connect* connectsrf, Vdouble xn[3], Vdouble vn[3], vis_Tess* tess)
{
    Vint k, m;
    Vdouble x[3][3];
    Vint ntris;
    Vint nplus, nminus;
    Vint np, lp[2], lix[2], npnts, nlins;
    Vint nix, ix[3];
    Vdouble d[3], dt[3], dx[3];
    Vint s[3];
    Vdouble xl[2][3], xd[3], xc[3], dot, f;
    Vdouble vt[3][3];

    vis_ConnectNumber(connectsrf, SYS_ELEM, &ntris);
    npnts = 0;
    nlins = 0;
    /* determine intersection line of plane and triangle */
    for (m = 1; m <= ntris; m++) {
        vis_ConnectElemNode(connectsrf, m, &nix, ix);
        vis_ConnectCoordsdv(connectsrf, nix, ix, x);
        nplus = nminus = 0;
        for (k = 0; k < 3; k++) {
            diff(x[k], xn, d);
            dt[k] = vn[0] * d[0] + vn[1] * d[1] + vn[2] * d[2];
            if (dt[k] >= 0.) {
                s[k] = 1;
                nplus += 1;
            }
            else if (dt[k] < 0.) {
                s[k] = -1;
                nminus += 1;
            }
        }
        if (nplus == 0 || nminus == 0)
            continue;
        /* compute exact intersection points */
        np = 0;
        for (k = 0; k < 3; k++) {
            if (s[k] == 0)
                continue;
            if (s[(k + 1) % 3] * s[k] == 1)
                continue;
            diff(x[(k + 1) % 3], x[k], dx);
            f = dt[k] / (dt[k] - dt[(k + 1) % 3]);
            xl[np][0] = x[k][0] + f * dx[0];
            xl[np][1] = x[k][1] + f * dx[1];
            xl[np][2] = x[k][2] + f * dx[2];
            lp[np] = ++npnts;
            vis_TessSetPointdv(tess, lp[np], xl[np]);
            np += 1;
        }
        vis_ConnectElemNormdv(connectsrf, m, 1, vt);
        diff(xl[1], xl[0], xd);
        cross(xd, vn, xc);
        dot = xc[0] * vt[0][0] + xc[1] * vt[0][1] + xc[2] * vt[0][2];
        if (dot >= 0.) {
            lix[0] = lp[0];
            lix[1] = lp[1];
        }
        else {
            lix[1] = lp[0];
            lix[0] = lp[1];
        }
        nlins += 1;
        vis_TessSetLine(tess, nlins, lix);
    }
}
