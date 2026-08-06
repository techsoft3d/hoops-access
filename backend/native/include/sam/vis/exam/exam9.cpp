#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"
#define MAG(x) sqrt(((x)[0] * (x)[0] + (x)[1] * (x)[1] + (x)[2] * (x)[2]))

/* anchor location of text string */
static Vfloat xtxt[3] = {-11., 11., 0.};
static Vfloat ctxt[3] = {1., 1., 1.};

/*----------------------------------------------------------------------
                      Clip Finite Element Faces to Isosurfaces
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_ColorMap* cmap;
    vis_Face* face;
    vis_Mark* mark;
    vis_IsoClip* isoclip;
    vis_CoordSys* coordsys;
    GLWin* glwin;

    int i, j, k, n;
    Vfloat c[3];
    Vfloat xf[4][3];
    Vfloat val0, sf0[4], val1, sf1[4];
    Vint mode;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -12., 12., -12., 12., -12., 12.);

    /* create drawing function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetColor(vc, 1);
    vis_VisContextSetMinorColor(vc, 2);
    vis_VisContextSetEdge(vc, VIS_ON);
    vis_VisContextSetFill(vc, VIS_ON);
    vis_VisContextSetMarkerType(vc, VIS_POINT4);
    vis_VisContextSetMapColor(vc, VIS_MAPCOLOR_NONE);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    /* gray */
    c[0] = .5;
    c[1] = .5;
    c[2] = .5;
    vis_ColorMapSetRGB(cmap, 1, 1, (Vfloat(*)[3])c);
    /* white */
    c[0] = 1.0;
    c[1] = 1.0;
    c[2] = 1.0;
    vis_ColorMapSetRGB(cmap, 1, 2, (Vfloat(*)[3])c);
    /* red */
    c[0] = 1.0;
    c[1] = .0;
    c[2] = .0;
    vis_ColorMapSetRGB(cmap, 1, 3, (Vfloat(*)[3])c);

    /* isosurface clipping object */
    isoclip = vis_IsoClipBegin();

    /* create face object and set objects */
    face = vis_FaceBegin();
    vis_FaceSetObject(face, VGL_DRAWFUN, df);
    vis_FaceSetObject(face, VIS_VISCONTEXT, vc);
    vis_FaceSetObject(face, VIS_COLORMAP, cmap);
    vis_FaceSetObject(face, VIS_ISOCLIP, isoclip);

    /* create mark object and set objects */
    mark = vis_MarkBegin();
    vis_MarkSetObject(mark, VGL_DRAWFUN, df);
    vis_MarkSetObject(mark, VIS_VISCONTEXT, vc);
    vis_MarkSetObject(mark, VIS_COLORMAP, cmap);
    vis_MarkSetObject(mark, VIS_ISOCLIP, isoclip);

    /* data based clipping */
    vis_IsoClipSetDataPtr(isoclip, 0, sf0);
    vis_IsoClipSetDataPtr(isoclip, 1, sf1);

    /* first ANY mode and then ALL mode */
    for (n = 0; n < 2; n++) {
        if (n == 0) {
            mode = ISOCLIP_ANY;
        }
        else {
            mode = ISOCLIP_ALL;
        }
        vis_IsoClipSetMode(isoclip, mode);
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
                    vis_VisContextSetColor(vc, 1);
                    vis_FaceCurv(face, xf, VIS_NODATA, NULL);
                    vis_VisContextSetColor(vc, 3);
                    vis_MarkPnt(mark, 4, xf);
                }
            }
            GLWinColor(glwin, ctxt);
            if (mode == ISOCLIP_ANY) {
                GLWinText(glwin, xtxt, (Vchar*)"Data Clipping, ANY mode");
            }
            else {
                GLWinText(glwin, xtxt, (Vchar*)"Data Clipping, ALL mode");
            }
            GLWinSwap(glwin);
            sleep(1);
        }
    }
    /* do the same thing with coordinate based clipping */
    /* create cylindrical system for radial clipping */
    /* default system at origin and aligned to global */
    coordsys = vis_CoordSysBegin();
    vis_CoordSysDef(coordsys, SYS_CYLINDRICAL);
    vis_IsoClipSetCoordSys(isoclip, 1, coordsys);

    for (n = 0; n < 2; n++) {
        if (n == 0) {
            mode = ISOCLIP_ANY;
        }
        else {
            mode = ISOCLIP_ALL;
        }
        vis_IsoClipSetMode(isoclip, mode);
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
                    vis_VisContextSetColor(vc, 1);
                    vis_FaceCurv(face, xf, VIS_NODATA, NULL);
                    vis_VisContextSetColor(vc, 3);
                    vis_MarkPnt(mark, 4, xf);
                }
            }
            GLWinColor(glwin, ctxt);
            if (mode == ISOCLIP_ANY) {
                GLWinText(glwin, xtxt, (Vchar*)"Coordinate Clipping, ANY mode");
            }
            else {
                GLWinText(glwin, xtxt, (Vchar*)"Coordinate Clipping, ALL mode");
            }
            GLWinSwap(glwin);
            sleep(1);
        }
    }

    sleep(5);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_ColorMapEnd(cmap);
    vis_FaceEnd(face);
    vis_MarkEnd(mark);
    vis_IsoClipEnd(isoclip);
    vis_CoordSysEnd(coordsys);
    GLWinEnd(glwin);
    return 0;
}
