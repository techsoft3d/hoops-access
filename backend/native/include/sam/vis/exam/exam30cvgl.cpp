#include <stdlib.h>
#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* define macro for maximums */
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

void
popup_callback(vgl_Popup* popup, vsy_PropSet* prop);
void
display_callback(vgl_IActor* iactor, vsy_Dictionary* dict);
void
draw_Legend(vgl_DrawFun* df, vis_Legend* legend);
void
draw_title(vgl_DrawFun* df, Vchar* title);

/* Red,Green,Blue components of entity Colormap */
static Vfloat rgb[8][3] = {{.5, .5, .5}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.},
                           {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}, {1., 1., 1.}};

static Vfloat rgbiso[3][3] = {{0., 0., 0.}, {1., 1., 1.}, {.5, .5, .5}};

static Vint butaction[6] = {IACTOR_TRACKBALL, IACTOR_TRANSLATE, IACTOR_SCALE, IACTOR_ROTATERATE, IACTOR_SQUIGGLE, IACTOR_WINDOW};

/*----------------------------------------------------------------------
                      Demo visualizer
                      Use VglTools graphics library
----------------------------------------------------------------------*/
int
main()
{
#ifdef VKI_WIND_X11
    Display* display;
    int screen;
#endif

    vis_Connect* connect;
    vis_GridFun* gf;
    vis_Group *groupnode, *groupedge, *groupface;
    vis_IdTran *idtrannode, *idtranelem;
    vis_State *state, *stated;

    vis_VisContext *vc, *vcvalue, *vctriad, *vclegend;
    vis_Levels* levels;
    vis_ColorMap *cmap, *cmapiso;
    vis_TransMap* tmap;
    vis_Edge* edge;
    vis_Face* face;
    vis_Mark* mark;
    vis_Value* value;
    vis_Contour* contour;
    vis_Threshold* threshold;
    vis_Triad* triad;
    vis_Legend* legend;

    vgl_DrawFun* dfdev;
    vgl_OpenGLDev* ogldev;
    vgl_Xfm* xfm;
    vgl_RasFont* rasfont;
    vgl_DrawFun *df, *dfedge, *dftitle, *dftriad, *dflegend;
    vgl_DList *dl, *dledge, *dltitle, *dltriad, *dllegend;
    vgl_IActor* iactor;
    vgl_Popup* popup;

    vsy_Dictionary* dict;
    vsy_PropSet* prop;

    int i, k;
    Vint nlevels;
    Vfloat sminmax[2];
    Vint numnp, numel;
    Vfloat c[3], x[3];
    Vfloat tm3[3][3];
    Vint flag;
    Vfloat extent[2][3], xmax;
    Vfloat fac;

    Vint xsize, ysize;

    Vint ix, iy, but[3];
    Vint ibut = 0, iact = 0;
    Vint shft, cntl;
    Vint exitflag;

    vsy_LicenseValidate(HOOPS_LICENSE);

#ifdef VKI_WIND_X11
    if (vgl_OpenGLDevTestX(&flag), flag == 0) {
        printf("OpenGL not enabled, exiting\n");
        exit(0);
    }
    display = XOpenDisplay(0);
    screen = DefaultScreen(display);
    vgl_OpenGLDevConnectX(display, screen);
#endif
#ifdef VKI_WIND_WIN32
    if (vgl_OpenGLDevTestWIN(&flag), flag == 0) {
        printf("OpenGL not enabled, exiting\n");
        exit(0);
    }
    vgl_OpenGLDevConnectWIN();
#endif

    /* create OpenGL device */
    ogldev = vgl_OpenGLDevBegin();

    /* create drawing function object for OpenGL */
    dfdev = vgl_DrawFunBegin();
    vgl_OpenGLDevDrawFun(ogldev, dfdev);

    /* initialize graphics window and lights */
    xsize = 640;
    ysize = 480;
    vgl_DrawFunPositionWindow(dfdev, 200, 200, xsize, ysize);
    vgl_DrawFunOpenWindow(dfdev, "Example 30cvgl");
    vgl_DrawFunProjOrtho(dfdev, -4.5, 4.5, -3., 3., -300., 300.);
    vgl_DrawFunSetMode(dfdev, VGL_ZBUFFERMODE, VGL_ON);
    vgl_DrawFunSetMode(dfdev, VGL_LIGHTMODE, VGL_ON);
    c[0] = .4f;
    c[1] = .4f;
    c[2] = .4f;
    x[0] = 0.;
    x[1] = 0.;
    x[2] = 0.;
    vgl_DrawFunLight(dfdev, 0, VGL_LIGHT_AMBIENT, c, x);
    c[0] = .6f;
    c[1] = .6f;
    c[2] = .6f;
    x[0] = 1.;
    x[1] = 1.;
    x[2] = 1.;
    vgl_DrawFunLight(dfdev, 1, VGL_LIGHT_DISTANT, c, x);
    x[0] = -1.;
    x[1] = -1.;
    x[2] = -1.;
    vgl_DrawFunLight(dfdev, 2, VGL_LIGHT_DISTANT, c, x);

    /* create transformation object */
    xfm = vgl_XfmBegin();

    /* create raster font object for smallest built-in font */
    rasfont = vgl_RasFontBegin();
    vgl_RasFontLoad(rasfont, RASFONT_NORMAL7X11);
    vgl_DrawFunRasFontDefine(dfdev, 1, rasfont);
    vgl_RasFontEnd(rasfont);

    /* create object display lists and drawing functions */
    /* display list for generated visualization */
    dl = vgl_DListBegin();
    df = vgl_DrawFunBegin();
    vgl_DListDrawFun(dl, df);
    vgl_DListSetObject(dl, VGL_DRAWFUN, dfdev);

    /* display list for edges */
    dledge = vgl_DListBegin();
    dfedge = vgl_DrawFunBegin();
    vgl_DListDrawFun(dledge, dfedge);
    vgl_DListSetObject(dledge, VGL_DRAWFUN, dfdev);

    /* display list for title */
    dltitle = vgl_DListBegin();
    dftitle = vgl_DrawFunBegin();
    vgl_DListDrawFun(dltitle, dftitle);
    vgl_DListSetObject(dltitle, VGL_DRAWFUN, dfdev);

    /* display list for triad */
    dltriad = vgl_DListBegin();
    dftriad = vgl_DrawFunBegin();
    vgl_DListDrawFun(dltriad, dftriad);
    vgl_DListSetObject(dltriad, VGL_DRAWFUN, dfdev);

    /* display list for legend */
    dllegend = vgl_DListBegin();
    dflegend = vgl_DrawFunBegin();
    vgl_DListDrawFun(dllegend, dflegend);
    vgl_DListSetObject(dllegend, VGL_DRAWFUN, dfdev);

    /* create a dictionary for all the display lists */
    dict = vsy_DictionaryBegin();
    vsy_DictionaryInsert(dict, "model", (Vobject*)dl);
    vsy_DictionaryInsert(dict, "edge", (Vobject*)dledge);
    vsy_DictionaryInsert(dict, "title", (Vobject*)dltitle);
    vsy_DictionaryInsert(dict, "triad", (Vobject*)dltriad);
    vsy_DictionaryInsert(dict, "legend", (Vobject*)dllegend);

    /* instance IActor for object manipulation */
    iactor = vgl_IActorBegin();
    vgl_IActorSetObject(iactor, VGL_DRAWFUN, dfdev);

    /* set display callback function */
    vgl_IActorSetFunction(iactor, IACTOR_FUN_DISPLAY, (void (*)(vgl_IActor*, Vobject*))display_callback, dict);

    vgl_IActorSetParamf(iactor, IACTOR_FITSHRINK, .5);

    /* create demo cylindrical brick 1000 element model */
    connect = vis_ConnectBegin();
    vis_ConnectDemo(connect, CONNECT_DEMO_CYLINDER, 1., VIS_SHAPEHEX, 11, 11, 11);
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    vis_ConnectExtent(connect, NULL, extent);
    xmax = 0.;
    for (k = 0; k < 3; k++) {
        xmax = MAX(xmax, extent[1][k] - extent[0][k]);
    }

    /* set user node ids */
    idtrannode = vis_IdTranBegin();
    vis_IdTranDef(idtrannode, numnp);
    for (i = 1; i <= numnp; i++) {
        vis_IdTranSetId(idtrannode, i, i);
    }

    /* set user element ids */
    idtranelem = vis_IdTranBegin();
    vis_IdTranDef(idtranelem, numel);
    for (i = 1; i <= numel; i++) {
        vis_IdTranSetId(idtranelem, i, i);
    }

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

    /* instance state for deformation */
    stated = vis_StateBegin();
    vis_StateDef(stated, numnp, SYS_NODE, SYS_NONE, SYS_VECTOR);
    vis_StateSetObject(stated, VIS_GRIDFUN, gf);

    /* scale deformations to 15 percent of model */
    fac = (.15F * xmax) / sminmax[1];
    vis_StateSetDerive(state, VIS_VECTOR);
    vis_StateDeform(stated, fac, state, NULL);
    vis_StateSetDerive(state, VIS_VECTOR_MAG);

    /* build free face group */
    groupface = vis_GroupBegin();
    vis_GroupDef(groupface, numel, SYS_ELEM, SYS_FACE);
    vis_ConnectFaceGroup(connect, CONNECT_FREE, NULL, groupface);

    /* build free face feature edge group */
    groupedge = vis_GroupBegin();
    vis_GroupDef(groupedge, numel, SYS_ELEM, SYS_EDGE);
    vis_ConnectEdgeGroup(connect, CONNECT_FEATURE, groupface, groupedge);

    /* build free node group */
    groupnode = vis_GroupBegin();
    vis_GroupDef(groupnode, numnp, SYS_NODE, SYS_NONE);
    vis_ConnectNodeGroup(connect, CONNECT_FREE, NULL, groupnode);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vcvalue = vis_VisContextBegin();

    /* set value visualization context values */
    vis_VisContextSetMapColor(vcvalue, VIS_OFF);
    vis_VisContextSetColor(vcvalue, 6);
    vis_VisContextSetLineWidth(vcvalue, 2);
    vis_VisContextSetMinorColor(vcvalue, 1);
    vis_VisContextSetABCColor(vcvalue, 0, 0, 0);
    vis_VisContextSetComponent(vcvalue, VIS_COMPONENT_PRINCIPAL);
    vis_VisContextSetFlags(vcvalue, VIS_VALUEBRACKET | VIS_VALUEBACK);

    /* levels, set evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 12;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, sminmax[0], sminmax[1]);
    vis_LevelsGenerate(levels, LEVELS_PADTOP);

    /* color map for isovalues */
    cmapiso = vis_ColorMapBegin();
    vis_ColorMapRamp(cmapiso, nlevels, 1, COLORMAP_HUE);
    vis_ColorMapSetRGB(cmapiso, 3, nlevels + 1, rgbiso);

    /* color map for entities */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetRGB(cmap, 8, 0, rgb);

    /* trans map */
    tmap = vis_TransMapBegin();

    /* create mark object and set objects */
    mark = vis_MarkBegin();
    vis_MarkSetObject(mark, VGL_DRAWFUN, df);
    vis_MarkSetObject(mark, VIS_VISCONTEXT, vc);
    vis_MarkSetObject(mark, VIS_LEVELS, levels);
    vis_MarkSetObject(mark, VIS_COLORMAP, cmapiso);
    vis_MarkSetObject(mark, VIS_GRIDFUN, gf);

    /* create value object and set objects */
    value = vis_ValueBegin();
    vis_ValueSetObject(value, VGL_DRAWFUN, df);
    vis_ValueSetObject(value, VIS_VISCONTEXT, vcvalue);
    vis_ValueSetObject(value, VIS_LEVELS, levels);
    vis_ValueSetObject(value, VIS_COLORMAP, cmap);
    vis_ValueSetObject(value, VIS_TRANSMAP, tmap);
    vis_ValueSetObject(value, VIS_GRIDFUN, gf);

    /* create contour object and set objects */
    contour = vis_ContourBegin();
    vis_ContourSetObject(contour, VGL_DRAWFUN, df);
    vis_ContourSetObject(contour, VIS_VISCONTEXT, vc);
    vis_ContourSetObject(contour, VIS_LEVELS, levels);
    vis_ContourSetObject(contour, VIS_COLORMAP, cmapiso);
    vis_ContourSetObject(contour, VIS_GRIDFUN, gf);

    /* create threshold object and set objects */
    threshold = vis_ThresholdBegin();
    vis_ThresholdSetObject(threshold, VGL_DRAWFUN, df);
    vis_ThresholdSetObject(threshold, VIS_VISCONTEXT, vc);
    vis_ThresholdSetObject(threshold, VIS_LEVELS, levels);
    vis_ThresholdSetObject(threshold, VIS_COLORMAP, cmapiso);
    vis_ThresholdSetObject(threshold, VIS_GRIDFUN, gf);

    /* create edge object and set objects */
    edge = vis_EdgeBegin();
    vis_EdgeSetObject(edge, VIS_VISCONTEXT, vc);
    vis_EdgeSetObject(edge, VIS_COLORMAP, cmap);
    vis_EdgeSetObject(edge, VIS_GRIDFUN, gf);

    /* create face object and set objects */
    face = vis_FaceBegin();
    vis_FaceSetObject(face, VGL_DRAWFUN, df);
    vis_FaceSetObject(face, VIS_VISCONTEXT, vc);
    vis_FaceSetObject(face, VIS_COLORMAP, cmap);
    vis_FaceSetObject(face, VIS_GRIDFUN, gf);

    /* triad visualization context */
    vctriad = vis_VisContextBegin();
    vis_VisContextSetLineWidth(vctriad, 2);
    vis_VisContextSetMinorColor(vctriad, 0);
    vis_VisContextSetSize(vctriad, 1.);
    vis_VisContextSetMinorSize(vctriad, .5);
    vis_VisContextSetColor(vctriad, 7);
    vis_VisContextSetXYZColor(vctriad, 1, 2, 3);
    vis_VisContextSetABCColor(vctriad, 7, 7, 7);
    vis_VisContextSetTrans(vctriad, 1);
    vis_VisContextSetVectorType(vctriad, VIS_VECTORUMBRELLA);

    /* create Triad object and set objects */
    triad = vis_TriadBegin();
    vis_TriadSetObject(triad, VGL_DRAWFUN, dftriad);
    vis_TriadSetObject(triad, VIS_VISCONTEXT, vctriad);
    vis_TriadSetObject(triad, VIS_COLORMAP, cmap);

    /* legend visualization context */
    vclegend = vis_VisContextBegin();
    vis_VisContextSetLineWidth(vclegend, 2);
    vis_VisContextSetMinorLineWidth(vclegend, 2);
    vis_VisContextSetMinorColor(vclegend, nlevels + 2);
    vis_VisContextSetColor(vclegend, nlevels + 3);
    vis_VisContextSetTrans(vclegend, 1);
    vis_VisContextSetMapTrans(vclegend, VIS_OFF);
    vis_VisContextSetSize(vclegend, .3f);
    vis_VisContextSetMinorSize(vclegend, .8f);
    vis_VisContextSetFlags(vclegend, VIS_ISOVALACCENT);

    /* create Legend object and set objects */
    legend = vis_LegendBegin();
    vis_LegendSetObject(legend, VGL_DRAWFUN, dflegend);
    vis_LegendSetObject(legend, VIS_VISCONTEXT, vclegend);
    vis_LegendSetObject(legend, VIS_COLORMAP, cmapiso);
    vis_LegendSetObject(legend, VIS_LEVELS, levels);
    vis_LegendSetParami(legend, LEGEND_PADTOP, VIS_ON);

    /* set properties for generation */
    prop = vsy_PropSetBegin();
    vsy_PropSetInsertp(prop, "connect", (Vobject*)connect);
    vsy_PropSetInsertp(prop, "groupnode", (Vobject*)groupnode);
    vsy_PropSetInsertp(prop, "groupedge", (Vobject*)groupedge);
    vsy_PropSetInsertp(prop, "groupface", (Vobject*)groupface);
    vsy_PropSetInsertp(prop, "idtrannode", (Vobject*)idtrannode);
    vsy_PropSetInsertp(prop, "state", (Vobject*)state);
    vsy_PropSetInsertp(prop, "stated", (Vobject*)stated);

    vsy_PropSetInsertp(prop, "vc", (Vobject*)vc);
    vsy_PropSetInsertp(prop, "edge", (Vobject*)edge);
    vsy_PropSetInsertp(prop, "face", (Vobject*)face);
    vsy_PropSetInsertp(prop, "mark", (Vobject*)mark);
    vsy_PropSetInsertp(prop, "value", (Vobject*)value);
    vsy_PropSetInsertp(prop, "contour", (Vobject*)contour);
    vsy_PropSetInsertp(prop, "threshold", (Vobject*)threshold);

    vsy_PropSetInsertp(prop, "dl", (Vobject*)dl);
    vsy_PropSetInsertp(prop, "dltitle", (Vobject*)dltitle);
    vsy_PropSetInsertp(prop, "dllegend", (Vobject*)dllegend);
    vsy_PropSetInsertp(prop, "df", (Vobject*)df);
    vsy_PropSetInsertp(prop, "dftitle", (Vobject*)dftitle);
    vsy_PropSetInsertp(prop, "iactor", (Vobject*)iactor);
    vsy_PropSetInserti(prop, "displayold", 0);
    vsy_PropSetInserti(prop, "Exit", 0);

    /* instance Popup for display generation */
    popup = vgl_PopupBegin();
    vgl_PopupSetObject(popup, VGL_DRAWFUN, dfdev);
    vgl_PopupTitle(popup, (Vchar*)"Display Types");
    vgl_PopupAddItem(popup, 0, (Vchar*)"Element Edge", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 1, (Vchar*)"Element Face", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 2, (Vchar*)"Element Face Contour", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 3, (Vchar*)"Element Isosurface", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 4, (Vchar*)"Node Vector", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 5, (Vchar*)"Node Value", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 6, (Vchar*)"Node Label", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddLine(popup);
    vgl_PopupAddToggle(popup, 7, (Vchar*)"Deform", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddLine(popup);
    vgl_PopupAddItem(popup, 10, (Vchar*)"Fit", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 11, (Vchar*)"Exit", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);

    /* draw edges */
    vgl_DListErase(dledge);
    vis_VisContextSetColor(vc, 7);
    vis_EdgeSetObject(edge, VGL_DRAWFUN, dfedge);
    vis_EdgeTrav(edge, groupedge);

    /* set general drawing function */
    vis_EdgeSetObject(edge, VGL_DRAWFUN, df);

    /* draw triad */
    vgl_DListErase(dltriad);
    x[0] = 0.;
    x[1] = 0.;
    x[2] = 0.;
    tm3[0][0] = 1.;
    tm3[0][1] = 0.;
    tm3[0][2] = 0.;
    tm3[1][0] = 0.;
    tm3[1][1] = 1.;
    tm3[1][2] = 0.;
    tm3[2][0] = 0.;
    tm3[2][1] = 0.;
    tm3[2][2] = 1.;
    vis_TriadDraw(triad, SYS_CARTESIAN, x, tm3);

    /* draw legend */
    vgl_DListErase(dllegend);
    draw_Legend(dflegend, legend);

    /* initially fit model edge to screen */
    vgl_IActorFit(iactor, NULL);

    /* implement a simple mouse polling loop */
    while (1) {
        ibut = -1;
        /* detect button press */
        while (ibut == -1) {
            vgl_DrawFunPollMouse(dfdev, &ix, &iy, &but[0], &but[1], &but[2]);
            vgl_DrawFunPollModifiers(dfdev, &cntl, &shft);
            for (i = 0; i < 3; i++) {
                if (but[i]) {
                    ibut = i;
                    iact = ibut + 3 * shft;
                    vgl_IActorDrag(iactor, butaction[iact], VGL_DRAG_INIT, ix, iy);
                    break;
                }
            }
            /* popup menu */
            if (cntl) {
                vgl_DrawFunPollMouse(dfdev, &ix, &iy, &but[0], &but[1], &but[2]);
                vgl_PopupDrag(popup, VGL_DRAG_INIT, ix, iy);
                while (1) {
                    vgl_DrawFunPollModifiers(dfdev, &cntl, &shft);
                    vgl_DrawFunPollMouse(dfdev, &ix, &iy, &but[0], &but[1], &but[2]);
                    if (cntl) {
                        vgl_PopupDrag(popup, VGL_DRAG_MOVE, ix, iy);
                    }
                    else {
                        vgl_PopupDrag(popup, VGL_DRAG_TERM, ix, iy);
                        break;
                    }
                }
                vsy_PropSetLookupInteger(prop, "Exit", &exitflag);
                if (exitflag) {
                    goto done;
                }
            }

            /* spin while waiting */
            if (ibut == -1) {
                vgl_IActorSpin(iactor, NULL);
            }
        }

        /* wait for button release */
        while (ibut != -1) {
            vgl_DrawFunPollMouse(dfdev, &ix, &iy, &but[0], &but[1], &but[2]);
            if (but[ibut]) {
                vgl_IActorDrag(iactor, butaction[iact], VGL_DRAG_MOVE, ix, iy);
            }
            else {
                vgl_IActorDrag(iactor, butaction[iact], VGL_DRAG_TERM, ix, iy);
                ibut = -1;
            }
        }
    }
    /* jump point for exiting polling loop */
done:;

    /* close window */
    vgl_DrawFunCloseWindow(dfdev);

    /* free all objects */
    vis_ConnectEnd(connect);
    vis_StateEnd(state);
    vis_StateEnd(stated);
    vis_GroupEnd(groupface);
    vis_GroupEnd(groupedge);
    vis_GroupEnd(groupnode);
    vis_IdTranEnd(idtrannode);
    vis_IdTranEnd(idtranelem);
    vis_GridFunEnd(gf);

    vgl_OpenGLDevEnd(ogldev);
    vgl_DrawFunEnd(dfdev);
    vgl_DrawFunEnd(df);
    vgl_DrawFunEnd(dfedge);
    vgl_DrawFunEnd(dftitle);
    vgl_DrawFunEnd(dftriad);
    vgl_DrawFunEnd(dflegend);

    vgl_DListEnd(dl);
    vgl_DListEnd(dledge);
    vgl_DListEnd(dltitle);
    vgl_DListEnd(dltriad);
    vgl_DListEnd(dllegend);
    vgl_XfmEnd(xfm);

    vgl_IActorEnd(iactor);

    vis_VisContextEnd(vc);
    vis_VisContextEnd(vcvalue);
    vis_VisContextEnd(vctriad);
    vis_VisContextEnd(vclegend);
    vis_LevelsEnd(levels);
    vis_ColorMapEnd(cmapiso);
    vis_ColorMapEnd(cmap);
    vis_TransMapEnd(tmap);
    vis_MarkEnd(mark);
    vis_ValueEnd(value);
    vis_ContourEnd(contour);
    vis_ThresholdEnd(threshold);
    vis_EdgeEnd(edge);
    vis_FaceEnd(face);
    vis_TriadEnd(triad);
    vis_LegendEnd(legend);
    vsy_DictionaryEnd(dict);
    vsy_PropSetEnd(prop);
    vgl_PopupEnd(popup);

    /* disconnect from window system */
    vgl_OpenGLDevDisconnect();
#ifdef VKI_WIND_X11
    XCloseDisplay(display);
#endif
    return 0;
}

/*----------------------------------------------------------------------
                      Popup function
----------------------------------------------------------------------*/
void
popup_callback(vgl_Popup* popup, vsy_PropSet* prop)
{
    vis_Connect* connect;
    vis_Group *groupnode, *groupedge, *groupface;
    vis_IdTran* idtrannode;
    vis_State *state, *stated;

    vis_VisContext* vc;
    vis_Edge* edge;
    vis_Face* face;
    vis_Mark* mark;
    vis_Value* value;
    vis_Contour* contour;
    vis_Threshold* threshold;

    vgl_DList *dl, *dltitle, *dllegend;
    vgl_IActor* iactor;
    vgl_DrawFun *df, *dftitle;

    Vint ind, val;
    Vint displaytype, displayold;

    /* retrieve objects */
    vsy_PropSetLookupObject(prop, "connect", (Vobject**)&connect);
    vsy_PropSetLookupObject(prop, "groupnode", (Vobject**)&groupnode);
    vsy_PropSetLookupObject(prop, "groupedge", (Vobject**)&groupedge);
    vsy_PropSetLookupObject(prop, "groupface", (Vobject**)&groupface);
    vsy_PropSetLookupObject(prop, "idtrannode", (Vobject**)&idtrannode);
    vsy_PropSetLookupObject(prop, "state", (Vobject**)&state);
    vsy_PropSetLookupObject(prop, "stated", (Vobject**)&stated);

    vsy_PropSetLookupObject(prop, "vc", (Vobject**)&vc);
    vsy_PropSetLookupObject(prop, "edge", (Vobject**)&edge);
    vsy_PropSetLookupObject(prop, "face", (Vobject**)&face);
    vsy_PropSetLookupObject(prop, "mark", (Vobject**)&mark);
    vsy_PropSetLookupObject(prop, "value", (Vobject**)&value);
    vsy_PropSetLookupObject(prop, "contour", (Vobject**)&contour);
    vsy_PropSetLookupObject(prop, "threshold", (Vobject**)&threshold);

    vsy_PropSetLookupObject(prop, "dl", (Vobject**)&dl);
    vsy_PropSetLookupObject(prop, "dltitle", (Vobject**)&dltitle);
    vsy_PropSetLookupObject(prop, "dllegend", (Vobject**)&dllegend);
    vsy_PropSetLookupObject(prop, "df", (Vobject**)&df);
    vsy_PropSetLookupObject(prop, "dftitle", (Vobject**)&dftitle);
    vsy_PropSetLookupObject(prop, "iactor", (Vobject**)&iactor);
    vsy_PropSetLookupInteger(prop, "displayold", &displayold);

    vgl_PopupGetIndex(popup, &ind);

    /* test for fit or exit */
    if (ind == 10) {
        vgl_IActorFit(iactor, NULL);
        return;
    }
    else if (ind == 11) {
        vsy_PropSetInserti(prop, "Exit", 1);
        return;
    }
    /* erase title and model display lists */
    vgl_DListErase(dltitle);
    vgl_DListErase(dl);

    /* test for deform */
    if (ind == 7) {
        vgl_PopupGetToggle(popup, ind, &val);
        if (val) {
            vis_ConnectSetObject(connect, VIS_STATE, stated);
            vis_VisContextSetColor(vc, 0);
            vis_EdgeTrav(edge, groupedge);
        }
        else {
            vis_ConnectSetObject(connect, VIS_STATE, NULL);
        }
        displaytype = displayold;
    }
    else {
        vsy_PropSetInserti(prop, "displayold", ind);
        displaytype = ind;
    }
    vis_VisContextSetColor(vc, 7);

    /* generate new display */
    if (displaytype == 0) {
        draw_title(dftitle, (Vchar*)"Element Edge");
        vgl_DListSetVisibility(dllegend, VGL_OFF);
    }
    else if (displaytype == 1) {
        draw_title(dftitle, (Vchar*)"Element Face");
        vgl_DListSetVisibility(dllegend, VGL_OFF);
        vis_VisContextSetColor(vc, 0);
        vis_FaceTrav(face, groupface, NULL);
    }
    else if (displaytype == 2) {
        draw_title(dftitle, (Vchar*)"Element Face Contour");
        vgl_DListSetVisibility(dllegend, VGL_ON);
        vis_StateSetDerive(state, VIS_VECTOR_MAG);
        vis_VisContextSetIsoValType(vc, VIS_ISOVALFRINGE);
        vis_ContourTrav(contour, state, groupface, NULL);
    }
    else if (displaytype == 3) {
        draw_title(dftitle, (Vchar*)"Element Isosurface");
        vgl_DListSetVisibility(dllegend, VGL_ON);
        vis_StateSetDerive(state, VIS_VECTOR_MAG);
        vis_VisContextSetIsoValType(vc, VIS_ISOVALSURFACE);
        vis_ThresholdTrav(threshold, state, NULL, NULL);
    }
    else if (displaytype == 4) {
        draw_title(dftitle, (Vchar*)"Node Vector");
        vgl_DListSetVisibility(dllegend, VGL_ON);
        vis_StateSetDerive(state, VIS_VECTOR);
        vis_VisContextSetVectorType(vc, VIS_VECTORUMBRELLA);
        vis_VisContextSetComponent(vc, VIS_COMPONENT_PRINCIPAL);
        vis_VisContextSetSize(vc, .25);
        vis_VisContextSetFlags(vc, VIS_VECTORTAIL | VIS_VECTORTAILREGISTER);
        vis_MarkTrav(mark, state, NULL);
    }
    else if (displaytype == 5) {
        draw_title(dftitle, (Vchar*)"Node Value");
        vgl_DListSetVisibility(dllegend, VGL_OFF);
        vis_StateSetDerive(state, VIS_VECTOR);
        vis_ValueTrav(value, state, groupnode);
    }
    else if (displaytype == 6) {
        draw_title(dftitle, (Vchar*)"Node Label");
        vgl_DListSetVisibility(dllegend, VGL_OFF);
        vis_ValueIntTrav(value, idtrannode, groupnode);
    }
}

/*----------------------------------------------------------------------
                      Display function
----------------------------------------------------------------------*/
void
display_callback(vgl_IActor* iactor, vsy_Dictionary* dict)
{
    vgl_Xfm* xfm;

    vgl_DrawFun* df;
    vgl_DList *dl, *dledge, *dltitle, *dltriad, *dllegend;
    Vfloat tm[4][4];
    Vint iparams[2], xsize, ysize, rflag;

    /* retrieve drawfun */
    vgl_IActorGetObject(iactor, VGL_DRAWFUN, (Vobject**)&df);

    /* retrieve display lists */
    vsy_DictionaryLookup(dict, "model", (Vobject**)&dl);
    vsy_DictionaryLookup(dict, "edge", (Vobject**)&dledge);
    vsy_DictionaryLookup(dict, "title", (Vobject**)&dltitle);
    vsy_DictionaryLookup(dict, "triad", (Vobject**)&dltriad);
    vsy_DictionaryLookup(dict, "legend", (Vobject**)&dllegend);

    /* get render mode */
    vgl_DrawFunGetInteger(df, VGL_RENDERMODE, iparams);
    rflag = iparams[0];

    /* get window size */
    vgl_DrawFunGetInteger(df, VGL_WINDOWSIZE, iparams);
    xsize = iparams[0];
    ysize = iparams[1];

    /* clear */
    vgl_DrawFunClear(df);

    /* draw objects */
    vgl_DListCall(dledge);
    vgl_DListCall(dl);

    /* do not draw annotation if in render mode (Fit) */
    if (rflag) {
        return;
    }
    /* instance transformation object */
    xfm = vgl_XfmBegin();

    /* save current projection and viewport */
    vgl_DrawFunProjPush(df);
    vgl_DrawFunAttPush(df, VGL_VIEWPORTATT);

    /* draw title */
    vgl_DrawFunViewport(df, 0, xsize, ysize - 50, ysize);
    vgl_DrawFunProjOrtho(df, -1., 1., -1., 1., -1., 1.);
    vgl_DrawFunXfmPush(df);
    vgl_XfmIdentity(xfm);
    vgl_XfmGetMatrix(xfm, tm);
    vgl_DrawFunXfmLoad(df, tm);
    vgl_DListCall(dltitle);
    vgl_DrawFunXfmPop(df);

    /* draw legend */
    vgl_DrawFunViewport(df, xsize - 140, xsize, ysize - 300, ysize);
    vgl_DrawFunProjOrtho(df, 0., 1., 0., 1., -1., 1.);
    vgl_DrawFunXfmPush(df);
    vgl_XfmIdentity(xfm);
    vgl_XfmGetMatrix(xfm, tm);
    vgl_DrawFunXfmLoad(df, tm);
    vgl_DListCall(dllegend);
    vgl_DrawFunXfmPop(df);

    /* draw triad */
    vgl_DrawFunViewport(df, 0, 100, 0, 100);
    vgl_DrawFunProjOrtho(df, -1.5, 1.5, -1.5, 1.5, -1.5, 1000.0);
    vgl_DrawFunXfmPush(df);
    /* purge translations and scaling */
    vgl_DrawFunGetFloat(df, VGL_MODELVIEWMATRIX, (Vfloat*)tm);
    vgl_XfmSetMatrix(xfm, tm);
    vgl_XfmPurge(xfm, XFM_SCALE);
    vgl_XfmPurge(xfm, XFM_TRANSLATE);
    vgl_XfmGetMatrix(xfm, tm);
    vgl_DrawFunXfmLoad(df, tm);
    vgl_DListCall(dltriad);
    vgl_DrawFunXfmPop(df);

    /* restore projection and viewport */
    vgl_DrawFunAttPop(df);
    vgl_DrawFunProjPop(df);

    /* swap */
    vgl_DrawFunSwap(df);

    vgl_XfmEnd(xfm);
}

/*----------------------------------------------------------------------
                      draw legend
----------------------------------------------------------------------*/
void
draw_Legend(vgl_DrawFun* df, vis_Legend* legend)
{
    Vfloat c[3];
    Vfloat x[3];
    Vint dc[3];
    /* draw a string and the legend */
    vgl_DrawFunSetMode(df, VGL_ZBUFFERMODE, VGL_OFF);
    vgl_DrawFunSetMode(df, VGL_LIGHTMODE, VGL_OFF);
    c[0] = 1.;
    c[1] = 1.;
    c[2] = 1.;
    vgl_DrawFunColor(df, c);
    x[0] = 0.;
    x[1] = 0.;
    x[2] = 0.;
    dc[0] = 0;
    dc[1] = 270;
    dc[2] = 0;
    vgl_DrawFunTextDC(df, x, dc, (Vchar*)"Contour Levels");

    vgl_DrawFunRasFontSelect(df, 1);
    x[0] = .1f;
    x[1] = .05f;
    x[2] = 0.;
    vis_LegendDraw(legend, x);
    vgl_DrawFunRasFontSelect(df, 0);
    vgl_DrawFunSetMode(df, VGL_LIGHTMODE, VGL_ON);
    vgl_DrawFunSetMode(df, VGL_ZBUFFERMODE, VGL_ON);
}

/*----------------------------------------------------------------------
                      draw title
----------------------------------------------------------------------*/
void
draw_title(vgl_DrawFun* df, Vchar* title)
{
    Vfloat c[3];
    Vfloat x[3];
    Vint dc[3];
    /* draw a two line title in raster font */
    vgl_DrawFunSetMode(df, VGL_ZBUFFERMODE, VGL_OFF);
    c[0] = 1.;
    c[1] = 1.;
    c[2] = 1.;
    vgl_DrawFunColor(df, c);
    x[0] = -1.;
    x[1] = 0.;
    x[2] = 0.;
    dc[0] = 10;
    dc[1] = 5;
    dc[2] = 0;
    vgl_DrawFunTextDC(df, x, dc, (Vchar*)"VisTools Demo Viewer");
    dc[0] = 10;
    dc[1] = -10;
    dc[2] = 0;
    vgl_DrawFunTextDC(df, x, dc, title);
    vgl_DrawFunSetMode(df, VGL_ZBUFFERMODE, VGL_ON);
}
