#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"

static Vfloat xhex[8][3] = {{0., 0., 0.}, {1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.},
                            {0., 0., 1.}, {1., 0., 1.}, {1., 1., 1.}, {0., 1., 1.}};
static Vfloat shex[8] = {0., 1., 1., 0., 1., 2., 2., 1.};
static Vfloat rgb[4][3] = {{.2, .2, .2}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}};

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

    /* create draw function object */
    df = new vgl_DrawFun;

    /* set built in print functions */
    df->API(DRAWFUN_APIPRINT);

    /* vis context and set attributes */
    vc = new vis_VisContext;
    vc->SetIsoValType(VIS_ISOVALSURFACE);

    /* levels, set three evenly spaced levels */
    levels = new vis_Levels;
    nlevels = 3;
    levels->Def(LEVELS_LINEAR, nlevels);
    levels->SetMinMax(0., 2.);
    levels->Generate(LEVELS_PADENDS);

    /* color map */
    cmap = new vis_ColorMap;
    cmap->SetType(COLORMAP_TRUECOLOR);
    cmap->SetRGB(nlevels + 1, 0, rgb);

    /* transparency map */
    tmap = new vis_TransMap;

    /* create threshold object and set objects */
    threshold = new vis_Threshold;
    threshold->SetObject(VGL_DRAWFUN, df);
    threshold->SetObject(VIS_VISCONTEXT, vc);
    threshold->SetObject(VIS_LEVELS, levels);
    threshold->SetObject(VIS_COLORMAP, cmap);
    threshold->SetObject(VIS_TRANSMAP, tmap);

    /* draw threshold surfaces */
    threshold->Curv(shex, xhex, VIS_NODATA, NULL);

    /* free all objects */
    delete df;
    delete vc;
    delete levels;
    delete cmap;
    delete tmap;
    delete threshold;
    return 0;
}
