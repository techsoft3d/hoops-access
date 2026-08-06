#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "glwin.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* useful macro for magnitude of a vector */
#define MAG(x) sqrt(((x)[0] * (x)[0] + (x)[1] * (x)[1] + (x)[2] * (x)[2]))

/* anchor location of text string */
static Vfloat xtxt[3] = {-11., 11., 0.};
/* colors for text, polygon, polyline */
static Vfloat ctxt[3] = {1., 1., 1.};
static Vfloat cpgn[3] = {1., 0., 1.};
static Vfloat cpln[3] = {1., 1., 1.};

/*----------------------------------------------------------------------
                      Clip Graphics Primitives to Isosurfaces Using PrmClp
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vgl_DrawFun* dfpc;
    vis_IsoClip* isoclip;
    vis_PrmClp* prmclp;
    vis_CoordSys* coordsys;
    GLWin* glwin;

    int i, j, k;
    Vfloat xf[4][3];
    Vfloat val0, val1;
    Vfloat sf0[4], sf1[4];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -12., 12., -12., 12., -12., 12.);

    /* create drawing function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* create isosurface clipping object */
    isoclip = vis_IsoClipBegin();
    vis_IsoClipSetMode(isoclip, ISOCLIP_ANY);

    /* create drawing function object for PrmClp */
    dfpc = vgl_DrawFunBegin();
    /* create primitive clipping object */
    prmclp = vis_PrmClpBegin();
    vis_PrmClpDrawFun(prmclp, dfpc);
    /* set isosurface clipping object */
    vis_PrmClpSetObject(prmclp, VIS_ISOCLIP, isoclip);
    /* set output drawing function to GLWin */
    vis_PrmClpSetObject(prmclp, VIS_ISOCLIP, isoclip);
    vis_PrmClpSetObject(prmclp, VGL_DRAWFUN, df);

    /* data based clipping */
    vis_IsoClipSetDataPtr(isoclip, 0, sf0);
    vis_IsoClipSetDataPtr(isoclip, 1, sf1);

    /* alter isosurface clipping values 20 times */
    for (i = 0; i < 20; i++) {
        GLWinClear(glwin);
        val0 = 10.F - .3333F * i;
        vis_IsoClipSetType(isoclip, 0, ISOCLIP_DATA, ISOCLIP_HITHER, val0);
        val1 = 12.F - .3333F * i;
        vis_IsoClipSetType(isoclip, 1, ISOCLIP_DATA, ISOCLIP_HITHER, val1);
        /* draw 10 by 10 grid of faces */
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 10; k++) {
                xf[0][0] = (Vfloat)j;
                xf[0][1] = (Vfloat)k;
                xf[0][2] = 0;
                xf[1][0] = (Vfloat)j + 1;
                xf[1][1] = (Vfloat)k;
                xf[1][2] = 0;
                xf[2][0] = (Vfloat)j + 1;
                xf[2][1] = (Vfloat)k + 1;
                xf[2][2] = 0;
                xf[3][0] = (Vfloat)j;
                xf[3][1] = (Vfloat)k + 1;
                xf[3][2] = 0;
                sf0[0] = xf[0][0];
                sf0[1] = xf[1][0];
                sf0[2] = xf[2][0];
                sf0[3] = xf[3][0];
                sf1[0] = (Vfloat)(MAG(xf[0]));
                sf1[1] = (Vfloat)(MAG(xf[1]));
                sf1[2] = (Vfloat)(MAG(xf[2]));
                sf1[3] = (Vfloat)(MAG(xf[3]));
                GLWinColor(glwin, cpgn);
                vgl_DrawFunPolygon(dfpc, VGL_POLYGON, 4, xf, VGL_NOSHADE, NULL);
                GLWinColor(glwin, cpln);
                vgl_DrawFunPolyLine(dfpc, VGL_LINELOOP, 4, xf);
            }
        }
        GLWinColor(glwin, ctxt);
        GLWinText(glwin, xtxt, (Vchar*)"Data Clipping");
        GLWinSwap(glwin);
        sleep(1);
    }
    /* coordinate based clipping */
    /* create cylindrical system for radial clipping */
    /* default system at origin and aligned to global */
    coordsys = vis_CoordSysBegin();
    vis_CoordSysDef(coordsys, SYS_CYLINDRICAL);
    vis_IsoClipSetCoordSys(isoclip, 1, coordsys);

    /* alter isosurface clipping values 20 times */
    for (i = 0; i < 20; i++) {
        GLWinClear(glwin);
        val0 = 10.F - .3333F * i;
        vis_IsoClipSetType(isoclip, 0, ISOCLIP_X, ISOCLIP_HITHER, val0);
        val1 = 12.F - .3333F * i;
        /* the radial coordinate is "X" */
        vis_IsoClipSetType(isoclip, 1, ISOCLIP_X, ISOCLIP_HITHER, val1);
        /* draw 10 by 10 grid of faces */
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 10; k++) {
                xf[0][0] = (Vfloat)j;
                xf[0][1] = (Vfloat)k;
                xf[0][2] = 0;
                xf[1][0] = (Vfloat)j + 1;
                xf[1][1] = (Vfloat)k;
                xf[1][2] = 0;
                xf[2][0] = (Vfloat)j + 1;
                xf[2][1] = (Vfloat)k + 1;
                xf[2][2] = 0;
                xf[3][0] = (Vfloat)j;
                xf[3][1] = (Vfloat)k + 1;
                xf[3][2] = 0;
                GLWinColor(glwin, cpgn);
                vgl_DrawFunPolygon(dfpc, VGL_POLYGON, 4, xf, VGL_NOSHADE, NULL);
                GLWinColor(glwin, cpln);
                vgl_DrawFunPolyLine(dfpc, VGL_LINELOOP, 4, xf);
            }
        }
        GLWinColor(glwin, ctxt);
        GLWinText(glwin, xtxt, (Vchar*)"Coordinate Clipping");
        GLWinSwap(glwin);
        sleep(1);
    }

    sleep(5);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vgl_DrawFunEnd(dfpc);
    vis_IsoClipEnd(isoclip);
    vis_PrmClpEnd(prmclp);
    vis_CoordSysEnd(coordsys);
    GLWinEnd(glwin);
    return 0;
}
