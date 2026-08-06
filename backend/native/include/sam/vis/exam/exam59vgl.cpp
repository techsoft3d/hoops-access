#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vfloat rgb[6][3] = {{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}};

/* common parallel object */
typedef struct {
    Vint iproc;
    Vint nel;
    Vint nface;
    Vint numel;
    Vint numproc;
    vis_Threshold* threshold;
    vis_Contour* contour;
    vgl_DList* dl;
    vgl_DrawFun* dfdl;
    vis_Connect* connect;
    vis_IdTran* idtranthreshold;
    vis_IdTran* idtrancontour;
} ParObj;

#define NNODEX 101
#define NNODEY 101
#define NNODEZ 101
#define NELEMX (NNODEX - 1)
#define NELEMY (NNODEY - 1)
#define NELEMZ (NNODEZ - 1)

/* threshold generation function */
static void
gen_threshold(Vobject* obj)
{
    ParObj* par = (ParObj*)obj;
    Vfloat s[8], x[8][3];
    Vint nix, ix[8], i, n, id;
    /* generate display list */
    vis_ThresholdSetTopology(par->threshold, SYS_SHAPEHEX, 0, 0, 0);
    for (n = 1; n <= par->nel; ++n) {
        vis_IdTranGetId(par->idtranthreshold, n, &id);
        vis_ConnectElemNode(par->connect, id, &nix, ix);
        vis_ConnectCoords(par->connect, nix, ix, x);
        for (i = 0; i < nix; ++i) {
            s[i] = (Vfloat)sqrt(x[i][0] * x[i][0] + x[i][1] * x[i][1] + x[i][2] * x[i][2]);
        }
        vis_ThresholdCurv(par->threshold, s, x, VIS_NODATA, NULL);
    }
}

/* threshold generation function */
static void
gen_contour(Vobject* obj)
{
    ParObj* par = (ParObj*)obj;
    Vfloat s[8], x[8][3];
    Vint nix, ix[8], i, n, id, no;
    Vint shape, maxi, maxj;

    /* generate display list */
    for (n = 1; n <= par->nface; ++n) {
        vis_IdTranGetId(par->idtrancontour, n, &id);
        vis_IdTranGetEnt(par->idtrancontour, n, &no);
        vis_ConnectElemTopo(par->connect, SYS_FACE, id, no, &shape, &maxi, &maxj);
        vis_ContourSetTopology(par->contour, shape, maxi, maxj);

        vis_ConnectElemCon(par->connect, SYS_FACE, id, no, &nix, ix);
        vis_ConnectCoords(par->connect, nix, ix, x);
        for (i = 0; i < nix; ++i) {
            s[i] = (Vfloat)sqrt(x[i][0] * x[i][0] + x[i][1] * x[i][1] + x[i][2] * x[i][2]);
        }
        vis_ContourCurv(par->contour, s, x, VIS_NODATA, NULL);
    }
}

/* serial drawing of display lists */
static void
draw_display(vgl_DrawFun* df, Vint numproc, ParObj** objs)
{
    Vint i, n;
    Vfloat tm[4][4];
    vgl_Xfm* xfm;

    xfm = vgl_XfmBegin();
    /* draw display lists */
    for (i = 0; i < 30; i++) {
        vgl_DrawFunClear(df);
        vgl_DrawFunXfmPush(df);
        vgl_XfmRotate(xfm, i * 12.F * .017453F, XFM_XAXIS);
        vgl_XfmGetMatrix(xfm, tm);
        vgl_DrawFunXfmLoad(df, tm);
        for (n = 0; n < numproc; ++n) {
            vgl_DListCall(objs[n]->dl);
        }
        vgl_DrawFunXfmPop(df);
        vgl_DrawFunSwap(df);
        vgl_DrawFunDelay(df, 1.);
    }

    vgl_XfmEnd(xfm);
}

static void
createMesh(vis_Connect* connect, Vint* numel)
{
    Vint i, j, k, ix[8], numnode, numelem, numnodehex;
    Vfloat dx, dy, dz, x[3];

    numnode = 0;
    numelem = 0;
    dx = 1.f / NELEMX;
    dy = 1.f / NELEMY;
    dz = 1.f / NELEMZ;
    /* generate nodes for hex elements */
    for (k = 0; k < NNODEZ; ++k) {
        x[2] = k * dz;
        for (j = 0; j < NNODEY; ++j) {
            x[1] = j * dy;
            for (i = 0; i < NNODEX; ++i) {
                x[0] = i * dx;
                ++numnode;
                vis_ConnectSetCoords(connect, numnode, x);
            }
        }
    }
    numnodehex = numnode;

    /* generate nodes for quad elements */
    x[2] = 0.;
    for (j = 0; j < NNODEY; ++j) {
        x[1] = j * dy;
        for (i = 0; i < NNODEX; ++i) {
            x[0] = i * dx - 1.F;
            ++numnode;
            vis_ConnectSetCoords(connect, numnode, x);
        }
    }
    /* generate hex elements */
    for (k = 0; k < NELEMZ; ++k) {
        for (j = 0; j < NELEMY; ++j) {
            for (i = 0; i < NELEMX; ++i) {
                ix[0] = NNODEX * NNODEY * k + NNODEX * j + i + 1;
                ix[1] = ix[0] + 1;
                ix[2] = ix[1] + NNODEX;
                ix[3] = ix[2] - 1;
                ix[4] = ix[0] + NNODEX * NNODEY;
                ix[5] = ix[1] + NNODEX * NNODEY;
                ix[6] = ix[2] + NNODEX * NNODEY;
                ix[7] = ix[3] + NNODEX * NNODEY;
                ++numelem;
                vis_ConnectSetTopology(connect, numelem, SYS_SHAPEHEX, 0, 0, 0);
                vis_ConnectSetElemNode(connect, numelem, ix);
            }
        }
    }
    /* generate quad elements */
    for (j = 0; j < NELEMY; ++j) {
        for (i = 0; i < NELEMX; ++i) {
            ix[0] = NNODEX * j + i + numnodehex + 1;
            ix[1] = ix[0] + 1;
            ix[2] = ix[1] + NNODEX;
            ix[3] = ix[2] - 1;
            ++numelem;
            vis_ConnectSetTopology(connect, numelem, SYS_SHAPEQUAD, 0, 0, 0);
            vis_ConnectSetElemNode(connect, numelem, ix);
        }
    }
    vis_ConnectKernel(connect, 0);
    *numel = numelem;
}

/*----------------------------------------------------------------------
                      Demonstrate Parallel Contour and Threshold Generation
----------------------------------------------------------------------*/
int
main()
{
    ParObj** objs;
#ifdef VKI_WIND_X11
    Display* display;
    int screen;
#endif

    vsy_PTask* ptask;
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_Levels* levels;
    vis_ColorMap* cmap;
    vgl_OpenGLDev* ogldev;
    vis_Connect* connect;
    vis_Group* group;

    int n, m, no, iproc;
    Vint nlevels;
    Vfloat c[3], x[3];
    Vint flag, numproc, numel;
    Vint nel, numparent, nfaces, nfproc, neproc;
    Vint shape, maxi, maxj, maxk;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* generate mesh */
    connect = vis_ConnectBegin();
    createMesh(connect, &numel);
    printf("mesh generation complete\n");
#ifdef VKI_WIND_X11
    /* open X display */
    display = XOpenDisplay(0);
    screen = DefaultScreen(display);
    vgl_OpenGLDevConnectX(display, screen);
#endif
#ifdef VKI_WIND_WIN32
    vgl_OpenGLDevConnectWIN();
#endif
    /* create GL device */
    ogldev = vgl_OpenGLDevBegin();

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    vgl_OpenGLDevDrawFun(ogldev, df);

    vgl_DrawFunPositionWindow(df, 200, 200, 400, 400);
    vgl_DrawFunOpenWindow(df, "Example 59vgl");
    vgl_DrawFunProjOrtho(df, -2., 2., -2., 2., -2., 2.);
    vgl_DrawFunSetMode(df, VGL_ZBUFFERMODE, VGL_ON);
    vgl_DrawFunSetMode(df, VGL_LIGHTMODE, VGL_ON);
    c[0] = .4f;
    c[1] = .4f;
    c[2] = .4f;
    x[0] = 0.;
    x[1] = 0.;
    x[2] = 0.;
    vgl_DrawFunLight(df, 0, LIGHT_AMBIENT, c, x);
    c[0] = .6f;
    c[1] = .6f;
    c[2] = .6f;
    x[0] = 1.;
    x[1] = 1.;
    x[2] = 1.;
    vgl_DrawFunLight(df, 1, LIGHT_DISTANT, c, x);
    x[0] = -1.;
    x[1] = -1.;
    x[2] = -1.;
    vgl_DrawFunLight(df, 2, LIGHT_DISTANT, c, x);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();

    /* levels, set three evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 5;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, 0., 1);
    vis_LevelsGenerate(levels, LEVELS_PADENDS);

    /* color map */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetType(cmap, COLORMAP_TRUECOLOR);
    vis_ColorMapSetRGB(cmap, nlevels + 1, 0, rgb);

    /* retrieve number of processors */
    vut_MachInfoNumProc(&flag, &numproc);
    if (!flag) {
        numproc = 1;
    }
    /* instance PTask object for parallelization tasks */
    ptask = vsy_PTaskBegin();
    vsy_PTaskDef(ptask, numproc, PTASK_EXEC);

    /* instance parallel objects */
    objs = (ParObj**)vut_MemoryMalloc(numproc * sizeof(ParObj**));
    for (iproc = 0; iproc < numproc; iproc++) {
        objs[iproc] = (ParObj*)vut_MemoryMalloc(sizeof(ParObj));
        objs[iproc]->iproc = iproc;
        objs[iproc]->connect = connect;
        objs[iproc]->numel = numel;
        objs[iproc]->numproc = numproc;
        /* create threshold DList and its DrawFun */
        objs[iproc]->dl = vgl_DListBegin();
        objs[iproc]->dfdl = vgl_DrawFunBegin();
        vgl_DListDrawFun(objs[iproc]->dl, objs[iproc]->dfdl);
        vgl_DListSetObject(objs[iproc]->dl, VGL_DRAWFUN, df);

        /* create threshold object and set objects */
        objs[iproc]->threshold = vis_ThresholdBegin();
        vis_ThresholdSetObject(objs[iproc]->threshold, VGL_DRAWFUN, objs[iproc]->dfdl);
        vis_ThresholdSetObject(objs[iproc]->threshold, VIS_VISCONTEXT, vc);
        vis_ThresholdSetObject(objs[iproc]->threshold, VIS_LEVELS, levels);
        vis_ThresholdSetObject(objs[iproc]->threshold, VIS_COLORMAP, cmap);

        /* create list of threshold elements for this processor */
        objs[iproc]->idtranthreshold = vis_IdTranBegin();

        /* create contour object and set objects */
        objs[iproc]->contour = vis_ContourBegin();
        vis_ContourSetObject(objs[iproc]->contour, VGL_DRAWFUN, objs[iproc]->dfdl);
        vis_ContourSetObject(objs[iproc]->contour, VIS_VISCONTEXT, vc);
        vis_ContourSetObject(objs[iproc]->contour, VIS_LEVELS, levels);
        vis_ContourSetObject(objs[iproc]->contour, VIS_COLORMAP, cmap);

        /* create list of contour faces for this processor */
        objs[iproc]->idtrancontour = vis_IdTranBegin();
        vis_IdTranSetEntType(objs[iproc]->idtrancontour, SYS_ELEM, SYS_FACE);
    }
    /* count list of 3D elements for threshold */
    nel = 0;
    for (n = 1; n <= numel; ++n) {
        vis_ConnectTopology(connect, n, &shape, &maxi, &maxj, &maxk);
        if (shape == SYS_SHAPEHEX) {
            ++nel;
        }
    }
    /* populate list of 3D elements for threshold */
    iproc = 0;
    m = 0;
    neproc = nel / numproc;
    for (n = 1; n <= numel; ++n) {
        vis_ConnectTopology(connect, n, &shape, &maxi, &maxj, &maxk);
        if (shape != SYS_SHAPEHEX)
            continue;

        ++m;
        vis_IdTranSetId(objs[iproc]->idtranthreshold, m, n);

        /* check whether to populate next processor */
        if (m == neproc && iproc != numproc - 1) {
            objs[iproc]->nel = neproc;
            m = 0;
            ++iproc;
        }
    }
    objs[numproc - 1]->nel = m;

    /* generate free faces */
    group = vis_GroupBegin();
    vis_GroupDef(group, numel, SYS_ELEM, SYS_FACE);
    vis_ConnectFaceGroup(connect, CONNECT_FREE, NULL, group);
    /* count list of faces for contour */
    vis_GroupCount(group, &numparent, &nfaces);
    /* populate list of contour faces */
    iproc = 0;
    m = 0;
    nfproc = nfaces / numproc;
    for (n = 1; n <= numel; ++n) {
        for (no = 1; no <= 6; ++no) {
            if (vis_GroupElemEnt(group, n, no) == 0)
                continue;

            ++m;
            vis_IdTranSetId(objs[iproc]->idtrancontour, m, n);
            vis_IdTranSetEnt(objs[iproc]->idtrancontour, m, no);

            /* check whether to populate next processor */
            if (m == nfproc && iproc != numproc - 1) {
                objs[iproc]->nface = nfproc;
                m = 0;
                ++iproc;
            }
        }
    }
    objs[numproc - 1]->nface = m;
    printf("parallel objects complete\n");

    /* erase display list (actually not needed first time) */
    for (n = 0; n < numproc; ++n) {
        vgl_DListErase(objs[n]->dl);
    }
    /* generate threshold display list */
    printf("begin threshold generation\n");
    vis_VisContextSetIsoValType(vc, VIS_ISOVALSURFACE);
    vsy_PTaskExec(ptask, numproc, (Vfunc1*)gen_threshold, (Vobject**)objs);
    printf("thresold generation complete\n");

    /* draw threshold isosurfaces */
    draw_display(df, numproc, objs);

    /* erase display list */
    for (n = 0; n < numproc; ++n) {
        vgl_DListErase(objs[n]->dl);
    }
    /* generate contour display list */
    printf("begin contour generation\n");
    vis_VisContextSetIsoValType(vc, VIS_ISOVALFRINGE);
    vsy_PTaskExec(ptask, numproc, (Vfunc1*)gen_contour, (Vobject**)objs);
    printf("contour generation complete\n");

    /* draw contoured surfaces */
    draw_display(df, numproc, objs);

    /* close window */
    vgl_DrawFunCloseWindow(df);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_LevelsEnd(levels);
    vis_ColorMapEnd(cmap);
    vgl_OpenGLDevEnd(ogldev);
    vsy_PTaskEnd(ptask);
    vis_ConnectEnd(connect);
    vis_GroupEnd(group);
    for (n = 0; n < numproc; ++n) {
        vgl_DListEnd(objs[n]->dl);
        vgl_DrawFunEnd(objs[n]->dfdl);
        vis_ThresholdEnd(objs[n]->threshold);
        vis_ContourEnd(objs[n]->contour);
        vis_IdTranEnd(objs[n]->idtranthreshold);
        vis_IdTranEnd(objs[n]->idtrancontour);
        vut_MemoryFree(objs[n]);
    }
    vut_MemoryFree(objs);

    /* disconnect from window system */
    vgl_OpenGLDevDisconnect();

    /* close X display */
#ifdef VKI_WIND_X11
    XCloseDisplay(display);
#endif
    return 0;
}
