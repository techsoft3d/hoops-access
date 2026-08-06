#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include "glwin.h"

void
draw_ElemEdge(vis_Group* group, vis_Connect* connect, vis_State* stated, vis_Edge* edge);
void
draw_ElemFaceGroup(vis_Group* group, vis_Connect* connect, vis_State* stated, vis_Face* face);
void
draw_ElemFaceIdTran(vis_IdTran* idtran, vis_Connect* connect, vis_State* stated, vis_Face* face);
void
draw_ElemFaceContour(vis_Group* group, vis_Connect* connect, vis_State* state, vis_State* stated, vis_Contour* contour);
void
draw_ElemIsosurface(vis_Group* group, vis_Connect* connect, vis_State* state, vis_State* stated, vis_Threshold* threshold);
void
draw_NodeMark(vis_Group* group, vis_Connect* connect, Vint datatype, vis_State* state, vis_State* stated, vis_Mark* mark);

/* Red,Green,Blue components of entity Colormap */
static Vfloat rgb[8][3] = {{.5, .5, .5}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.},
                           {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}, {1., 1., 1.}};

/*----------------------------------------------------------------------
                      Demo visualizer
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_GridFun* gf;
    vis_Group *groupedge, *groupface;
    vis_IdTran* idtranface;
    vis_State* state;

    vis_VisContext* vc;
    vis_Levels* levels;
    vis_ColorMap *cmap, *cmapiso;
    vis_Edge* edge;
    vis_Face* face;
    vis_Mark* mark;
    vis_Contour* contour;
    vis_Threshold* threshold;
    GLWin* glwin;
    vgl_DrawFun* df;

    int i, j;
    Vint nlevels;
    Vfloat sminmax[2];
    Vint numnp, numel;
    Vfloat xtext[3], ctext[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create GL device */
    glwin = GLWinBegin();
    GLWinCreateWindow(glwin, 200, 200, 400, 400);
    GLWinOrtho(glwin, -3., 3., -3., 3., -300., 300.);

    /* create draw function object for GL */
    df = vgl_DrawFunBegin();
    GLWinDrawFun(glwin, df);

    /* create demo cylindrical brick 1000 element model */
    connect = vis_ConnectBegin();
    vis_ConnectDemo(connect, CONNECT_DEMO_CYLINDER, 1., VIS_SHAPEHEX, 11, 11, 11);
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);

    /* generate connect kernel */
    vis_ConnectKernel(connect, 0);

    /* create a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* instance state object to hold demo node vector result */
    state = vis_StateBegin();
    vis_StateDef(state, numnp, SYS_NODE, SYS_NONE, SYS_VECTOR);
    vis_StateSetObject(state, VIS_GRIDFUN, gf);
    vis_StateDemo(state, STATE_DEMO_PLATE, .25, NULL);

    /* compute results minmax */
    vis_StateSetDerive(state, VIS_VECTOR_MAG);
    vis_StateExtent(state, NULL, sminmax);

    /* build free face group */
    groupface = vis_GroupBegin();
    vis_GroupDef(groupface, numel, SYS_ELEM, SYS_FACE);
    vis_ConnectFaceGroup(connect, CONNECT_FREE, NULL, groupface);
    idtranface = vis_IdTranBegin();
    vis_IdTranGroup(idtranface, groupface);

    /* build free face feature edge group */
    groupedge = vis_GroupBegin();
    vis_GroupDef(groupedge, numel, SYS_ELEM, SYS_EDGE);
    vis_ConnectEdgeGroup(connect, CONNECT_FEATURE, groupface, groupedge);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();

    /* levels, set evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 10;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, sminmax[0], sminmax[1]);
    vis_LevelsGenerate(levels, LEVELS_PADTOP);

    /* color map for isovalues */
    cmapiso = vis_ColorMapBegin();
    vis_ColorMapRamp(cmapiso, nlevels, 1, COLORMAP_HUE);

    /* color map for entities */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetRGB(cmap, 8, 0, rgb);

    /* create mark object and set objects */
    mark = vis_MarkBegin();
    vis_MarkSetObject(mark, VGL_DRAWFUN, df);
    vis_MarkSetObject(mark, VIS_VISCONTEXT, vc);
    vis_MarkSetObject(mark, VIS_LEVELS, levels);
    vis_MarkSetObject(mark, VIS_COLORMAP, cmapiso);

    /* create contour object and set objects */
    contour = vis_ContourBegin();
    vis_ContourSetObject(contour, VGL_DRAWFUN, df);
    vis_ContourSetObject(contour, VIS_VISCONTEXT, vc);
    vis_ContourSetObject(contour, VIS_LEVELS, levels);
    vis_ContourSetObject(contour, VIS_COLORMAP, cmapiso);

    /* create threshold object and set objects */
    threshold = vis_ThresholdBegin();
    vis_ThresholdSetObject(threshold, VGL_DRAWFUN, df);
    vis_ThresholdSetObject(threshold, VIS_VISCONTEXT, vc);
    vis_ThresholdSetObject(threshold, VIS_LEVELS, levels);
    vis_ThresholdSetObject(threshold, VIS_COLORMAP, cmapiso);

    /* create edge object and set objects */
    edge = vis_EdgeBegin();
    vis_EdgeSetObject(edge, VGL_DRAWFUN, df);
    vis_EdgeSetObject(edge, VIS_VISCONTEXT, vc);
    vis_EdgeSetObject(edge, VIS_COLORMAP, cmap);

    /* create face object and set objects */
    face = vis_FaceBegin();
    vis_FaceSetObject(face, VGL_DRAWFUN, df);
    vis_FaceSetObject(face, VIS_VISCONTEXT, vc);
    vis_FaceSetObject(face, VIS_COLORMAP, cmap);

    xtext[0] = -2.5;
    xtext[1] = 2.5;
    xtext[2] = 0.;
    ctext[0] = 1.;
    ctext[1] = 1.;
    ctext[2] = 1.;
    /* loop through visualization types */
    for (j = 0; j < 5; j++) {
        for (i = 0; i < 8; i++) {
            GLWinClear(glwin);
            GLWinColor(glwin, ctext);
            if (j == 0) {
                GLWinText(glwin, xtext, (Vchar*)"draw_ElemFaceGroup");
            }
            else if (j == 1) {
                GLWinText(glwin, xtext, (Vchar*)"draw_ElemFaceIdTran");
            }
            else if (j == 2) {
                GLWinText(glwin, xtext, (Vchar*)"draw_ElemFaceContour");
            }
            else if (j == 3) {
                GLWinText(glwin, xtext, (Vchar*)"draw_ElemIsosurface");
            }
            else if (j == 4) {
                GLWinText(glwin, xtext, (Vchar*)"draw_NodeMark");
            }
            GLWinXfmPush(glwin);
            GLWinRotate(glwin, i * 4.F, 'X');
            GLWinRotate(glwin, -i * 4.F, 'Y');
            vis_VisContextSetColor(vc, 7);
            draw_ElemEdge(groupedge, connect, NULL, edge);
            /* draw elem face subset using a Group object */
            if (j == 0) {
                vis_VisContextSetColor(vc, 0);
                draw_ElemFaceGroup(groupface, connect, NULL, face);
                /* draw elem face subset using an IdTran object */
            }
            else if (j == 1) {
                vis_VisContextSetColor(vc, 0);
                draw_ElemFaceIdTran(idtranface, connect, NULL, face);
                /* draw elem face contours */
            }
            else if (j == 2) {
                vis_StateSetDerive(state, VIS_VECTOR_MAG);
                vis_VisContextSetIsoValType(vc, VIS_ISOVALFRINGE);
                draw_ElemFaceContour(groupface, connect, state, NULL, contour);
                /* draw elem isosurfaces */
            }
            else if (j == 3) {
                vis_StateSetDerive(state, VIS_VECTOR_MAG);
                vis_VisContextSetIsoValType(vc, VIS_ISOVALSURFACE);
                draw_ElemIsosurface(NULL, connect, state, NULL, threshold);
                /* draw node vector markers */
            }
            else if (j == 4) {
                vis_StateSetDerive(state, VIS_VECTOR);
                vis_VisContextSetVectorType(vc, VIS_VECTORUMBRELLA);
                vis_VisContextSetComponent(vc, VIS_COMPONENT_PRINCIPAL);
                vis_VisContextSetSize(vc, .25);
                vis_VisContextSetFlags(vc, VIS_VECTORTAIL | VIS_VECTORTAILREGISTER);
                draw_NodeMark(NULL, connect, VIS_VECTOR, state, NULL, mark);
            }
            GLWinXfmPop(glwin);
            GLWinSwap(glwin);
            sleep(1);
        }
    }
    sleep(5);

    /* free all objects */
    vis_ConnectEnd(connect);
    vis_StateEnd(state);
    vis_GroupEnd(groupface);
    vis_GroupEnd(groupedge);
    vis_GridFunEnd(gf);
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_LevelsEnd(levels);
    vis_ColorMapEnd(cmapiso);
    vis_ColorMapEnd(cmap);
    vis_MarkEnd(mark);
    vis_ContourEnd(contour);
    vis_ThresholdEnd(threshold);
    vis_EdgeEnd(edge);
    vis_FaceEnd(face);
    GLWinEnd(glwin);
    return 0;
}

/*----------------------------------------------------------------------
                      Draw Element Edges
----------------------------------------------------------------------*/
void
draw_ElemEdge(vis_Group* group, vis_Connect* connect, vis_State* stated, vis_Edge* edge)
{
    Vint numel;
    Vint n, j;
    Vint flags, flagj;
    Vint nedges;
    Vint shape, maxi, maxj;
    Vint nix;
    Vint ix[8];
    Vfloat x[8][3];

    /* get number of elements */
    vis_ConnectNumber(connect, SYS_ELEM, &numel);

    /* draw element edges */
    /* loop through elements */
    for (n = 1; n <= numel; n++) {
        vis_GroupGetIndex(group, n, &flags);
        if (flags == 0)
            continue;
        vis_ConnectElemNum(connect, SYS_EDGE, n, &nedges);

        /* loop through element edges */
        for (j = 1; j <= nedges; j++) {
            vis_GroupGetEntFlag(group, n, j, &flagj);
            if (flagj == 0)
                continue;
            vis_ConnectElemCon(connect, SYS_EDGE, n, j, &nix, ix);
            vis_ConnectElemTopo(connect, SYS_EDGE, n, j, &shape, &maxi, &maxj);
            if (stated != NULL) {
                vis_StateData(stated, nix, ix, (Vfloat*)x);
            }
            else {
                vis_ConnectCoords(connect, nix, ix, x);
            }
            vis_EdgeSetTopology(edge, SYS_SHAPELINE, nix);
            vis_EdgeCurv(edge, x);
        }
    }
}

/*----------------------------------------------------------------------
                      Draw Element Face using Group
----------------------------------------------------------------------*/
void
draw_ElemFaceGroup(vis_Group* group, vis_Connect* connect, vis_State* stated, vis_Face* face)
{
    Vint numel;
    Vint n, j;
    Vint flags, flagj;
    Vint nfaces;
    Vint shape, maxi, maxj;
    Vint nix;
    Vint ix[VIS_MAXFACENODE];
    Vfloat x[VIS_MAXFACENODE][3];

    /* get number of elements */
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    /* draw element faces */
    /* loop through elements */
    for (n = 1; n <= numel; n++) {
        vis_GroupGetIndex(group, n, &flags);
        if (flags == 0)
            continue;
        vis_ConnectElemNum(connect, SYS_FACE, n, &nfaces);
        /* loop through element faces */
        for (j = 1; j <= nfaces; j++) {
            vis_GroupGetEntFlag(group, n, j, &flagj);
            if (flagj == 0)
                continue;
            vis_ConnectElemCon(connect, SYS_FACE, n, j, &nix, ix);
            vis_ConnectElemTopo(connect, SYS_FACE, n, j, &shape, &maxi, &maxj);
            if (stated != NULL) {
                vis_StateData(stated, nix, ix, (Vfloat*)x);
            }
            else {
                vis_ConnectCoords(connect, nix, ix, x);
            }
            vis_FaceSetTopology(face, shape, maxi, maxj);
            vis_FaceCurv(face, x, VIS_NODATA, NULL);
        }
    }
}

/*----------------------------------------------------------------------
                      Draw Element Face using IdTran
----------------------------------------------------------------------*/
void
draw_ElemFaceIdTran(vis_IdTran* idtran, vis_Connect* connect, vis_State* stated, vis_Face* face)
{
    Vint maxind;
    Vint i, n, j;
    Vint shape, maxi, maxj;
    Vint nix;
    Vint ix[VIS_MAXFACENODE];
    Vfloat x[VIS_MAXFACENODE][3];

    /* get number of indices with faces */
    vis_IdTranCount(idtran, IDTRAN_MAXINDEX, &maxind);
    /* draw element faces */
    /* loop through indices */
    for (i = 1; i <= maxind; i++) {
        vis_IdTranGetId(idtran, i, &n);
        if (n == 0)
            continue;
        /* get element face */
        vis_IdTranGetEnt(idtran, i, &j);
        vis_ConnectElemCon(connect, SYS_FACE, n, j, &nix, ix);
        vis_ConnectElemTopo(connect, SYS_FACE, n, j, &shape, &maxi, &maxj);
        if (stated != NULL) {
            vis_StateData(stated, nix, ix, (Vfloat*)x);
        }
        else {
            vis_ConnectCoords(connect, nix, ix, x);
        }
        vis_FaceSetTopology(face, shape, maxi, maxj);
        vis_FaceCurv(face, x, VIS_NODATA, NULL);
    }
}

/*----------------------------------------------------------------------
                      Draw Element Face Contours
----------------------------------------------------------------------*/
void
draw_ElemFaceContour(vis_Group* group, vis_Connect* connect, vis_State* state, vis_State* stated, vis_Contour* contour)
{
    Vint numel;
    Vint n, j;
    Vint flags, flagj;
    Vint nfaces;
    Vint shape, maxi, maxj;
    Vint nix;
    Vint ix[8];
    Vfloat x[8][3];
    Vfloat s[8];

    /* get number of elements */
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    /* contour on element faces */
    /* loop through elements */
    for (n = 1; n <= numel; n++) {
        vis_GroupGetIndex(group, n, &flags);
        if (flags == 0)
            continue;
        vis_ConnectElemNum(connect, SYS_FACE, n, &nfaces);
        /* loop through element faces */
        for (j = 1; j <= nfaces; j++) {
            vis_GroupGetEntFlag(group, n, j, &flagj);
            if (flagj == 0)
                continue;
            vis_ConnectElemCon(connect, SYS_FACE, n, j, &nix, ix);
            vis_ConnectElemTopo(connect, SYS_FACE, n, j, &shape, &maxi, &maxj);
            if (stated != NULL) {
                vis_StateData(stated, nix, ix, (Vfloat*)x);
            }
            else {
                vis_ConnectCoords(connect, nix, ix, x);
            }
            vis_StateData(state, nix, ix, s);
            vis_ContourSetTopology(contour, shape, maxi, maxj);
            vis_ContourCurv(contour, s, x, VIS_NODATA, NULL);
        }
    }
}

/*----------------------------------------------------------------------
                      Draw Element Isosurfaces
----------------------------------------------------------------------*/
void
draw_ElemIsosurface(vis_Group* group, vis_Connect* connect, vis_State* state, vis_State* stated, vis_Threshold* threshold)
{
    Vint numel;
    Vint n;
    Vint shape, maxi, maxj, maxk;
    Vint nix;
    Vint flags;
    Vint ix[VIS_MAXCELLNODE];
    Vfloat x[VIS_MAXCELLNODE][3];
    Vfloat s[VIS_MAXCELLNODE];

    /* get number of elements */
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    /* loop through all elements */
    for (n = 1; n <= numel; n++) {
        if (group != NULL) {
            vis_GroupGetIndex(group, n, &flags);
            if (flags == 0)
                continue;
        }
        vis_ConnectTopology(connect, n, &shape, &maxi, &maxj, &maxk);
        if (shape == SYS_SHAPETET || shape == SYS_SHAPEPYR || shape == SYS_SHAPEWED || shape == SYS_SHAPEHEX) {
            /* draw isosurfaces */
            vis_ConnectElemNode(connect, n, &nix, ix);
            if (stated != NULL) {
                vis_StateData(stated, nix, ix, (Vfloat*)x);
            }
            else {
                vis_ConnectCoords(connect, nix, ix, x);
            }
            vis_StateData(state, nix, ix, s);
            vis_ThresholdSetTopology(threshold, shape, maxi, maxj, maxk);
            vis_ThresholdCurv(threshold, s, x, VIS_NODATA, NULL);
        }
    }
}

/*----------------------------------------------------------------------
                      Draw Node Markers
----------------------------------------------------------------------*/
void
draw_NodeMark(vis_Group* group, vis_Connect* connect, Vint datatype, vis_State* state, vis_State* stated, vis_Mark* mark)
{
    Vint numnp;
    Vint n;
    Vint flags;
    Vfloat x[3];
    Vfloat s[6];

    /* get number of nodes */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    /* markers at nodes */
    /* loop through nodes */
    for (n = 1; n <= numnp; n++) {
        if (group != NULL) {
            vis_GroupGetIndex(group, n, &flags);
            if (flags == 0)
                continue;
        }
        if (stated != NULL) {
            vis_StateData(stated, 1, &n, x);
        }
        else {
            vis_ConnectCoords(connect, 1, &n, (Vfloat(*)[3])x);
        }
        vis_StateData(state, 1, &n, s);
        if (datatype == VIS_SCALAR) {
            vis_MarkScalar(mark, 1, s, (Vfloat(*)[3])x);
        }
        else if (datatype == VIS_VECTOR) {
            vis_MarkVector(mark, 1, (Vfloat(*)[3])s, (Vfloat(*)[3])x);
        }
        else if (datatype == VIS_TENSOR) {
            vis_MarkTensor(mark, 1, (Vfloat(*)[6])s, (Vfloat(*)[3])x);
        }
    }
}
