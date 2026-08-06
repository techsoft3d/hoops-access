#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vfloat xhex[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.},
                            {0., 0., 1.}, {1., 0., 1.}, {1., 1., 1.}, {0., 1., 1.}};
static Vfloat shex[8] = {0., 1., 1., 0., 1., 2., 2., 1.};
static Vfloat rgb[4][3] = {{.2f, .2f, .2f}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}};

/*----------------------------------------------------------------------
                      Generate isosurfaces in a hexahedron
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_Levels* levels;
    vis_ColorMap* cmap;
    vis_TransMap* tmap;
    vis_Threshold* threshold;

    Vint nlevels;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create draw function object */
    df = vgl_DrawFunBegin();

    /* set built in print functions */
    vgl_DrawFunAPI(df, DRAWFUN_APIPRINT);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetIsoValType(vc, VIS_ISOVALSURFACE);

    /* levels, set three evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 3;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, 0., 2.);
    vis_LevelsGenerate(levels, LEVELS_PADENDS);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, nlevels + 1, 0, rgb);

    /* transparency map */
    tmap = vis_TransMapBegin();

    /* create threshold object and set objects */
    threshold = vis_ThresholdBegin();
    vis_ThresholdSetObject(threshold, VGL_DRAWFUN, df);
    vis_ThresholdSetObject(threshold, VIS_VISCONTEXT, vc);
    vis_ThresholdSetObject(threshold, VIS_LEVELS, levels);
    vis_ThresholdSetObject(threshold, VIS_COLORMAP, cmap);
    vis_ThresholdSetObject(threshold, VIS_TRANSMAP, tmap);

    /* draw threshold surfaces */
    vis_ThresholdCurv(threshold, shex, xhex, VIS_NODATA, NULL);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_LevelsEnd(levels);
    vis_ColorMapEnd(cmap);
    vis_TransMapEnd(tmap);
    vis_ThresholdEnd(threshold);
    return 0;
}
