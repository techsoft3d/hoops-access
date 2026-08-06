#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

static Vfloat xpt[3][3] = {{-1., 0., 0.}, {0., 0., 0.}, {1., 0., 0.}};
static Vfloat sca = {-.6f};
static Vfloat vec[3] = {.3f, -.6f, 1.};
static Vfloat ten[6] = {.3f, -.6f, 1., .6f, .2f, -.4f};
static Vfloat xtex[3] = {-1., 1.5f, 0.};
static Vfloat ctex[3] = {1., 1., 1.};

static Vfloat rgb[7][3] = {{.5f, .5f, .5f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/*----------------------------------------------------------------------
                      Display a Scalar, Vector and Tensor in 3 Ways
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext *vcsca, *vcvec, *vcten;
    vis_Levels* levels;
    vis_ColorMap* cmap;
    vis_Mark* mark;
    GLWin* glwin;

    int i, j, k;
    Vint nlevels;
    Vfloat van[6], xan[6][2][3];
    Vchar stg[16];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -2., 2., -2., 2., -2., 2.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* scalar viscontext and set attributes */
    vcsca = vis_VisContextBegin();
    vis_VisContextSetColor(vcsca, 4);
    vis_VisContextSetRefinement(vcsca, 2);

    /* vector viscontext and set attributes */
    vcvec = vis_VisContextBegin();
    vis_VisContextSetFlags(vcvec, VIS_VECTORTAIL | VIS_VECTORTAILREGISTER);
    vis_VisContextSetMapSize(vcvec, VIS_ON);
    vis_VisContextSetXYZColor(vcvec, 4, 5, 6);

    /* tensor viscontext and set attributes */
    vcten = vis_VisContextBegin();
    vis_VisContextSetFlags(vcten, VIS_TENSORBOX | VIS_TENSORDIRECT | VIS_TENSORSHEAR);
    vis_VisContextSetMapSize(vcten, VIS_ON);
    vis_VisContextSetXYZColor(vcten, 4, 5, 6);
    vis_VisContextSetRefinement(vcten, 1);

    /* levels, set three evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 6;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, -1., 1.);
    vis_LevelsGenerate(levels, LEVELS_PADNONE);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, 7, 0, rgb);

    /* create mark object and set objects */
    mark = vis_MarkBegin();
    vis_MarkSetObject(mark, VGL_DRAWFUN, df);
    vis_MarkSetObject(mark, VIS_VISCONTEXT_SCALAR, vcsca);
    vis_MarkSetObject(mark, VIS_VISCONTEXT_VECTOR, vcvec);
    vis_MarkSetObject(mark, VIS_VISCONTEXT_TENSOR, vcten);
    vis_MarkSetObject(mark, VIS_LEVELS, levels);
    vis_MarkSetObject(mark, VIS_COLORMAP, cmap);

    /* draw scalars */
    for (i = 0; i < 8; i++) {
        GLWinClear(glwin);
        GLWinColor(glwin, ctex);
        GLWinText(glwin, xtex, (Vchar*)"Scalar");
        GLWinXfmPush(glwin);
        GLWinRotate(glwin, i * 8.F, 'x');
        GLWinRotate(glwin, i * 4.F, 'y');

        /* 3D spherical type scalar, mapped to color */
        vis_VisContextSetMarkerType(vcsca, VIS_SPHERE);
        vis_VisContextSetMapColor(vcsca, VIS_ON);
        vis_MarkScalar(mark, 1, &sca, (Vfloat(*)[3])xpt[0]);

        /* 2D line type scalar, not mapped to color */
        vis_VisContextSetMarkerType(vcsca, VIS_HOURGLASS);
        vis_VisContextSetMapColor(vcsca, VIS_OFF);
        vis_MarkScalar(mark, 1, &sca, (Vfloat(*)[3])xpt[1]);

        /* 2D point type scalar, mapped to color */
        vis_VisContextSetMarkerType(vcsca, VIS_POINT4);
        vis_VisContextSetMapColor(vcsca, VIS_ON);
        vis_MarkScalar(mark, 1, &sca, (Vfloat(*)[3])xpt[2]);

        GLWinXfmPop(glwin);
        GLWinSwap(glwin);
        sleep(1);
    }
    sleep(2);

    /* draw vectors */
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++) {
            GLWinClear(glwin);
            GLWinColor(glwin, ctex);
            if (j) {
                vis_VisContextSetComponent(vcvec, VIS_COMPONENT_PRINCIPAL);
                GLWinText(glwin, xtex, (Vchar*)"Vector Resultants");
            }
            else {
                vis_VisContextSetComponent(vcvec, VIS_COMPONENT_BASIC);
                GLWinText(glwin, xtex, (Vchar*)"Vector Components");
            }
            GLWinXfmPush(glwin);
            GLWinRotate(glwin, i * 8.F, 'x');
            GLWinRotate(glwin, i * 4.F, 'y');

            /* 3D cylindrical type vector, mapped to color */
            vis_VisContextSetVectorType(vcvec, VIS_VECTORCYLINDER);
            vis_VisContextSetMapColor(vcvec, VIS_ON);
            vis_MarkVector(mark, 1, (Vfloat(*)[3])vec, (Vfloat(*)[3])xpt[0]);

            /* 2D line type vector, not mapped to color */
            vis_VisContextSetVectorType(vcvec, VIS_VECTORLINE);
            vis_VisContextSetMapColor(vcvec, VIS_OFF);
            vis_MarkVector(mark, 1, (Vfloat(*)[3])vec, (Vfloat(*)[3])xpt[1]);

            /* 3D polygon head, 2D line tail vector, mapped to color */
            vis_VisContextSetVectorType(vcvec, VIS_VECTORUMBRELLA);
            vis_VisContextSetMapSize(vcvec, VIS_OFF);
            vis_VisContextSetSize(vcvec, .6f);
            vis_VisContextSetMapColor(vcvec, VIS_ON);
            vis_MarkVector(mark, 1, (Vfloat(*)[3])vec, (Vfloat(*)[3])xpt[2]);
            vis_VisContextSetMapSize(vcvec, VIS_ON);
            vis_VisContextSetSize(vcvec, 1.);

            GLWinXfmPop(glwin);
            GLWinSwap(glwin);
            sleep(1);
        }
        sleep(1);
    }
    sleep(2);

    /* draw tensors */
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 8; i++) {
            GLWinClear(glwin);
            GLWinColor(glwin, ctex);
            if (j == 2) {
                vis_VisContextSetComponent(vcten, VIS_COMPONENT_MAXSHEAR);
                GLWinText(glwin, xtex, (Vchar*)"Tensor Max Shear");
            }
            else if (j == 1) {
                vis_VisContextSetComponent(vcten, VIS_COMPONENT_PRINCIPAL);
                GLWinText(glwin, xtex, (Vchar*)"Tensor Principals");
            }
            else {
                vis_VisContextSetComponent(vcten, VIS_COMPONENT_BASIC);
                GLWinText(glwin, xtex, (Vchar*)"Tensor Components");
            }
            GLWinXfmPush(glwin);
            GLWinRotate(glwin, i * 8.F, 'x');
            GLWinRotate(glwin, i * 4.F, 'y');

            /* 3D ellipsoidal tensor, mapped to color */
            vis_VisContextSetVectorType(vcvec, VIS_VECTORCYLINDER);
            vis_VisContextSetTensorType(vcten, VIS_TENSORELLIPSOID);
            vis_VisContextSetMapColor(vcten, VIS_ON);
            vis_MarkTensor(mark, 1, (Vfloat(*)[6])ten, (Vfloat(*)[3])xpt[0]);

            /* 3D cube tensor, not mapped to color */
            vis_VisContextSetVectorType(vcvec, VIS_VECTORLINE);
            vis_VisContextSetTensorType(vcten, VIS_TENSORCUBE);
            vis_VisContextSetMapColor(vcten, VIS_OFF);
            vis_VisContextSetSize(vcten, .6f);
            vis_VisContextSetXYZColor(vcten, 0, 0, 0);
            vis_MarkTensor(mark, 1, (Vfloat(*)[6])ten, (Vfloat(*)[3])xpt[1]);
            vis_VisContextSetMapSize(vcten, VIS_ON);
            vis_VisContextSetSize(vcten, 1.);
            vis_VisContextSetXYZColor(vcten, 4, 5, 6);

            /* 2D crows feet tensor, mapped to color */
            vis_VisContextSetVectorType(vcvec, VIS_VECTORUMBRELLA);
            vis_VisContextSetTensorType(vcten, VIS_TENSORCROWSFEET);
            vis_VisContextSetMapColor(vcten, VIS_ON);
            vis_VisContextSetMapSize(vcvec, VIS_OFF);
            vis_VisContextSetSize(vcvec, .6f);
            vis_MarkTensor(mark, 1, (Vfloat(*)[6])ten, (Vfloat(*)[3])xpt[2]);
            vis_MarkTensorCompute(mark, ten, xpt[2], van, xan);
            vis_VisContextSetMapSize(vcvec, VIS_ON);
            vis_VisContextSetSize(vcvec, 1.);
            /* annotate */
            GLWinColor(glwin, ctex);
            for (k = 0; k < 6; k++) {
                if (van[k] != 0.) {
                    sprintf(stg, "%g", van[k]);
                    GLWinText(glwin, xan[k][0], stg);
                }
            }

            GLWinXfmPop(glwin);
            GLWinSwap(glwin);
            sleep(1);
        }
        sleep(1);
    }
    sleep(2);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vcsca);
    vis_VisContextEnd(vcvec);
    vis_VisContextEnd(vcten);
    vis_LevelsEnd(levels);
    vis_ColorMapEnd(cmap);
    vis_MarkEnd(mark);
    GLWinEnd(glwin);
    return 0;
}
