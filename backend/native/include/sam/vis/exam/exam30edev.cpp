#include <stdlib.h>
#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* define macro for maximums */
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

void
popup_callback(vgl_Popup* popup, vsy_PropSet* prop);
void
display_callback(vgl_IActor* iactor, vsy_Dictionary* dict);
void
draw_ElemEdge(vis_Edge* edge, vis_Connect* connect, vis_Group* group);
void
draw_NodePoint(vgl_DrawFun* df, vis_Connect* connect, vis_Group* group);
void
draw_Legend(vgl_DrawFun* df, vis_Legend* legend);
void
draw_title(vgl_DrawFun* df, Vchar* title1, Vchar* title2);
void
load_states(vdm_LMan* lman, Vint ids, vis_State* staten, vis_State* stateen, Vint* enflag, vis_State* statee, Vint* eflag,
            vis_State* stateenv, Vint* envflag);
void
transform_disp(vsy_HashTable* hashcsys, vis_IdTran* idtrannsys, vis_State* staten);
void
transform_strs(vsy_HashTable* hashcsys, vsy_HashTable* hasheldt, vis_IdTran* idtranesys, vis_Group* group, vis_State* stateen);
void
load_deform(vis_State* staten, vis_State* stated, Vfloat xmax, Vfloat fac, Vint deformtype);
void
load_scalarn(vis_State* staten, vis_State* stateen, vis_State* statee, Vint resulttype, vis_State* state);

/* Red,Green,Blue components of entity Colormap */
static Vfloat rgb[8][3] = {{.5, .5, .5}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.},
                           {0., 1., 1.}, {1., 0., 1.}, {1., 1., 0.}, {1., 1., 1.}};

static Vfloat rgbiso[3][3] = {{0., 0., 0.}, {1., 1., 1.}, {.5, .5, .5}};

static Vchar* resulttitle[4] = {NULL, (Vchar*)"Displacement Magnitude", (Vchar*)"Von Mises Stress",
                                (Vchar*)"Strain Energy Density"};

/*----------------------------------------------------------------------
                      Demo visualizer
                      Use VglTools graphics library
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
#ifdef VKI_WIND_X11
    Display* display;
    int screen;
#endif

    vis_Model* model;
    vis_Connect* connect;
    vis_GridFun* gf;
    vis_Group *groupnode, *groupedge, *groupface, *grouptran;
    vis_State *state, *stated;
    vis_State *staten, *statee, *stateen, *stateenv;
    vis_IdTran *idtrannsys, *idtranesys;
    vsy_HashTable *hashcsys, *hasheldt;

    vis_VisContext *vc, *vcvalue, *vctriad, *vclegend, *vcetriad;
    vis_Levels* levels;
    vis_ColorMap *cmap, *cmapiso;
    vis_TransMap* tmap;
    vis_Edge* edge;
    vis_Face* face;
    vis_Mark* mark;
    vis_Value* value;
    vis_Contour* contour;
    vis_Threshold* threshold;
    vis_Triad *triad, *etriad;
    vis_Legend* legend;
    vis_CoordSys* coordsys;

    vgl_DrawFun* dfdev;
    vgl_OpenGLDev* ogldev;
    vgl_Xfm* xfm;
    vgl_RasFont* rasfont;
    vgl_DrawFun *df, *dfedge, *dftitle, *dftriad, *dflegend;
    vgl_DList *dl, *dledge, *dltitle, *dltriad, *dllegend;
    vgl_IActor* iactor;
    vgl_Popup *popup, *popupcases, *popupdef;

    vsy_Dictionary* dict;
    vsy_PropSet* prop;

    /* VdmTools objects */
    vdm_DataFun* datafun = NULL;
    vdm_Library* library = NULL;
    vdm_Dataset* dataset = NULL;
    vdm_NASFil* nasfil = NULL;
    vdm_NASLib* naslib = NULL;
    vdm_ANSLib* anslib = NULL;
    vdm_ABAFil* abafil = NULL;
    vdm_ABALib* abalib = NULL;
    vdm_RASLib* raslib = NULL;
    vdm_SDRCLib* sdrclib = NULL;
    vdm_EnSightLib* ensightlib = NULL;
    vdm_TecplotLib* tecplotlib = NULL;
    vdm_MarcLib* marclib = NULL;
    vdm_STLFil* stlfil = NULL;
    vdm_PatLib* patlib = NULL;
    vdm_D3DLib* d3dlib = NULL;
    vdm_NatLib* natlib = NULL;
    vdm_CGNSVLib* cgnsvlib = NULL;
    vdm_STARCCMLib* starccmlib = NULL;
    vdm_LMan* lman = NULL;
    Vint filetype = 0;
    Vint numdatasets, *idsts, ndsts;
    Vchar dsname[DATASET_MAXNAME];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vint enflag, eflag, envflag;
    Vint cid;

    int i, k;
    Vint nlevels;
    Vfloat sminmax[2];
    Vint numnp, numel;
    Vfloat c[3], x[3];
    Vfloat tm3[3][3];
    Vint flag;
    Vfloat extent[2][3], xmax;

    Vint xsize, ysize;

    Vint exitflag;
    Vint iper;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-p] inputfile\n", argv[0]);
        exit(0);
    }
    /* process flag for perspective */
    iper = 0;
    if (strcmp(argv[1], "-p") == 0) {
        iper = 1;
        argc -= 1;
        argv = &argv[1];
    }
    /* process possible input file */
    if (argc < 2) {
        fprintf(stderr, " inputfile is blank, exiting\n");
        exit(0);
    }
    /* instance DataFun object */
    datafun = vdm_DataFunBegin();

    /* determine file type from file extension */
    if (strstr(argv[1], ".bdf") != NULL || strstr(argv[1], ".dat") != NULL) {
        filetype = VDM_NASTRAN_BULKDATA;
        nasfil = vdm_NASFilBegin();
        vdm_NASFilDataFun(nasfil, datafun);
    }
    else if (strstr(argv[1], ".op2") != NULL) {
        filetype = VDM_NASTRAN_OUTPUT2;
        naslib = vdm_NASLibBegin();
        vdm_NASLibDataFun(naslib, datafun);
    }
    else if (strstr(argv[1], ".rst") != NULL || strstr(argv[1], ".rth") != NULL) {
        filetype = VDM_ANSYS_RESULT;
        anslib = vdm_ANSLibBegin();
        vdm_ANSLibDataFun(anslib, datafun);
    }
    else if (strstr(argv[1], ".inp") != NULL) {
        filetype = VDM_ABAQUS_INPUT;
        abafil = vdm_ABAFilBegin();
        vdm_ABAFilDataFun(abafil, datafun);
    }
    else if (strstr(argv[1], ".fil") != NULL) {
        filetype = VDM_ABAQUS_FIL;
        abalib = vdm_ABALibBegin();
        vdm_ABALibDataFun(abalib, datafun);
    }
    else if (strstr(argv[1], ".odb") != NULL) {
        filetype = VDM_ABAQUS_ODB;
        abalib = vdm_ABALibBegin();
        vdm_ABALibDataFun(abalib, datafun);
    }
    else if (strstr(argv[1], ".neu") != NULL) {
        filetype = VDM_MECHANICA_STUDY;
        raslib = vdm_RASLibBegin();
        vdm_RASLibDataFun(raslib, datafun);
    }
    else if (strstr(argv[1], ".unv") != NULL || strstr(argv[1], ".bun") != NULL) {
        filetype = VDM_SDRC_UNIVERSAL;
        sdrclib = vdm_SDRCLibBegin();
        vdm_SDRCLibDataFun(sdrclib, datafun);
    }
    else if (strstr(argv[1], ".case") != NULL || strstr(argv[1], ".encas") != NULL) {
        filetype = VDM_ENSIGHT;
        ensightlib = vdm_EnSightLibBegin();
        vdm_EnSightLibDataFun(ensightlib, datafun);
    }
    else if (strstr(argv[1], ".plt") != NULL) {
        filetype = VDM_TECPLOT;
        tecplotlib = vdm_TecplotLibBegin();
        vdm_TecplotLibDataFun(tecplotlib, datafun);
    }
    else if (strstr(argv[1], ".t16") != NULL || strstr(argv[1], ".t19") != NULL) {
        filetype = VDM_MARC_POST;
        marclib = vdm_MarcLibBegin();
        vdm_MarcLibDataFun(marclib, datafun);
    }
    else if (strstr(argv[1], ".stl") != NULL) {
        filetype = VDM_STL;
        stlfil = vdm_STLFilBegin();
        vdm_STLFilDataFun(stlfil, datafun);
    }
    else if (strstr(argv[1], ".STL") != NULL) {
        filetype = VDM_STLBIN;
        stlfil = vdm_STLFilBegin();
        vdm_STLFilDataFun(stlfil, datafun);
    }
    else if (strstr(argv[1], ".out") != NULL) {
        filetype = VDM_PATRAN_NEUTRAL;
        patlib = vdm_PatLibBegin();
        vdm_PatLibDataFun(patlib, datafun);
    }
    else if (strstr(argv[1], "d3plot") != NULL || strstr(argv[1], "D3PLOT") != NULL) {
        filetype = VDM_LSTC_STATE;
        d3dlib = vdm_D3DLibBegin();
        vdm_D3DLibDataFun(d3dlib, datafun);
    }
    else if (strstr(argv[1], ".vdm") != NULL) {
        filetype = VDM_NATIVE;
        natlib = vdm_NatLibBegin();
        vdm_NatLibDataFun(natlib, datafun);
    }
    else if (strstr(argv[1], ".cgns") != NULL) {
        filetype = VDM_CGNS;
        cgnsvlib = vdm_CGNSVLibBegin();
        vdm_CGNSVLibDataFun(cgnsvlib, datafun);
    }
    else if (strstr(argv[1], ".ccm") != NULL || strstr(argv[1], ".CCM") != NULL) {
        filetype = VDM_STARCCM;
        starccmlib = vdm_STARCCMLibBegin();
        vdm_STARCCMLibDataFun(starccmlib, datafun);
    }
    else {
        fprintf(stderr, "Error: Bad input file %s\n", argv[1]);
        exit(0);
    }

    /* open library device */
    vdm_DataFunOpen(datafun, 0, argv[1], filetype);
    if (vdm_DataFunError(datafun)) {
        fprintf(stderr, "Error: Unable to open input data file\n");
        exit(0);
    }
    /* load model */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);
    model = vis_ModelBegin();
    vdm_LManLoadModel(lman, model);
    if (vdm_LManError(lman)) {
        fprintf(stderr, "Error: Unable to load model information\n");
        exit(0);
    }
    vdm_DataFunGetLibrary(datafun, &library);
    vdm_LibraryTOC(library, "*", SYS_ON);

#ifdef VKI_WIND_X11
    if (vgl_OpenGLDevTestX(&flag), flag == 0) {
        fprintf(stderr, "OpenGL not enabled, exiting\n");
        exit(0);
    }
    display = XOpenDisplay(0);
    screen = DefaultScreen(display);
    vgl_OpenGLDevConnectX(display, screen);
#endif
#ifdef VKI_WIND_WIN32
    if (vgl_OpenGLDevTestWIN(&flag), flag == 0) {
        fprintf(stderr, "OpenGL not enabled, exiting\n");
        exit(0);
    }
    vgl_OpenGLDevConnectWIN();
#endif

    /* print instructions */
    printf("Example Visualizer\n");
    printf("  Press CTRL to display Popup menu\n");
    printf("  Press Left Mouse Button to Rotate\n");
    printf("  Press Middle Mouse Button to Translate\n");
    printf("  Press Right Mouse Button to Scale\n");
    printf("  Press SHIFT/Left Mouse Button to Squiggle Window\n");
    printf("  Press SHIFT/Middle Mouse Button to Rectangular Window\n");
    printf("  Press SHIFT/Right Mouse Button to Align\n");

    /* create OpenGL device */
    ogldev = vgl_OpenGLDevBegin();

    /* create drawing function object for OpenGL */
    dfdev = vgl_DrawFunBegin();
    vgl_OpenGLDevDrawFun(ogldev, dfdev);

    /* initialize graphics window and lights */
    xsize = 640;
    ysize = 480;
    vgl_DrawFunPositionWindow(dfdev, 200, 200, xsize, ysize);
    vgl_DrawFunOpenWindow(dfdev, "Example 30edev");
    if (iper) {
        vgl_DrawFunProjFrustum(dfdev, -6.4f, 6.4f, -4.8f, 4.8f, 8.f, 100.f);
    }
    else {
        vgl_DrawFunProjOrtho(dfdev, -6.4f, 6.4f, -4.8f, 4.8f, 5.f, 100.f);
    }
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

    /* create a dictionary for all the display lists
       and immediate mode objects */
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

    vgl_IActorSetParamf(iactor, IACTOR_FITSHRINK, .1f);

    /* get Connect object */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    vis_ConnectExtent(connect, NULL, extent);
    xmax = 0.;
    for (k = 0; k < 3; k++) {
        if (extent[1][k] - extent[0][k] > xmax) {
            xmax = extent[1][k] - extent[0][k];
        }
    }
    printf("number of nodes    = %d\n", numnp);
    printf("number of elements = %d\n", numel);

    /* generate connect kernel */
    vis_ConnectKernel(connect, 0);

    /* create a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* instance result states */
    staten = vis_StateBegin();
    vis_StateDef(staten, numnp, SYS_NODE, SYS_NONE, VIS_VECTOR);
    vis_StateSetObject(staten, VIS_GRIDFUN, gf);

    statee = vis_StateBegin();
    vis_StateDef(statee, numel, SYS_ELEM, SYS_NONE, VIS_SCALAR);
    vis_StateSetObject(statee, VIS_GRIDFUN, gf);

    stateen = vis_StateBegin();
    vis_StateDef(stateen, numel, SYS_ELEM, SYS_NODE, VIS_TENSOR);
    vis_StateSetObject(stateen, VIS_GRIDFUN, gf);

    stateenv = vis_StateBegin();
    vis_StateDef(stateenv, numel, SYS_ELEM, SYS_NODE, VIS_VECTOR);
    vis_StateSetObject(stateenv, VIS_GRIDFUN, gf);

    /* instance state for deformation */
    stated = vis_StateBegin();
    vis_StateDef(stated, numnp, SYS_NODE, SYS_NONE, VIS_VECTOR);
    vis_StateSetObject(stated, VIS_GRIDFUN, gf);

    /* get HashTable of CoordSys objects */
    vis_ModelGetHashTable(model, VIS_COORDSYS, &hashcsys);
    vis_ModelGetHashTable(model, VIS_ELEMDAT, &hasheldt);

    /* idtran objects for coordinate system identifiers */
    /* nodes */
    idtrannsys = vis_IdTranBegin();
    vis_IdTranDef(idtrannsys, numnp);
    for (i = 1; i <= numnp; i++) {
        vis_ConnectNodeAssoc(connect, VIS_CSYSID, 1, &i, &cid);
        vis_IdTranSetId(idtrannsys, i, cid);
    }
    /* elements */
    idtranesys = vis_IdTranBegin();
    vis_IdTranDef(idtranesys, numel);
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemAssoc(connect, VIS_CSYSID, 1, &i, &cid);
        vis_IdTranSetId(idtranesys, i, cid);
    }

    /* build elem group of 3D and 2D elements to transform */
    grouptran = vis_GroupBegin();
    vis_GroupDef(grouptran, numel, SYS_ELEM, SYS_NONE);
    vis_ConnectSetGroupParami(connect, CONNECT_DIMENSION, 3);
    vis_ConnectElemGroup(connect, CONNECT_DIMENSION, NULL, grouptran);
    vis_ConnectSetGroupParami(connect, CONNECT_DIMENSION, 2);
    vis_ConnectElemGroup(connect, CONNECT_DIMENSION, NULL, grouptran);
    vis_ConnectSetGroupParami(connect, CONNECT_DIMENSION, 1);
    vis_ConnectElemGroup(connect, CONNECT_DIMENSION, NULL, grouptran);

    /* find total number of datasets */
    vdm_LibraryGetNumDatasets(library, &numdatasets);
    idsts = (Vint*)malloc(numdatasets * sizeof(Vint));

    /* find number of displacement datasets */
    vdm_LibrarySearchDataset(library, "D.N:*", numdatasets, idsts, &ndsts);
    printf("number of displacement datasets = %d\n", ndsts);

    /* load the first state if any exist */
    if (ndsts > 0) {
        load_states(lman, idsts[0], staten, stateen, &enflag, statee, &eflag, stateenv, &envflag);
        transform_disp(hashcsys, idtrannsys, staten);
        if (enflag) {
            transform_strs(hashcsys, hasheldt, idtranesys, grouptran, stateen);
        }
        /* otherwise manufacture "demo" displacements */
    }
    else {
        vis_StateDemo(staten, STATE_DEMO_PLATE, .25, NULL);
        printf("Demo displacements generated\n");
        enflag = 0;
        eflag = 0;
    }
    load_deform(staten, stated, xmax, .15f, 0);

    /* instance state object to hold displayed node scalar */
    state = vis_StateBegin();
    vis_StateDef(state, numnp, SYS_NODE, SYS_NONE, VIS_SCALAR);

    load_scalarn(staten, stateen, statee, 1, state);
    vis_StateExtent(state, NULL, sminmax);

    /* build free face group */
    groupface = vis_GroupBegin();
    vis_GroupDef(groupface, numel, SYS_ELEM, SYS_FACE);
    vis_ConnectFaceGroup(connect, CONNECT_FREE, NULL, groupface);
    /* add 2D elements */
    vis_ConnectFaceGroup(connect, CONNECT_ELEM, NULL, groupface);

    /* build free face feature edge group */
    groupedge = vis_GroupBegin();
    vis_GroupDef(groupedge, numel, SYS_ELEM, SYS_EDGE);
    vis_ConnectEdgeGroup(connect, CONNECT_FEATURE, groupface, groupedge);

    /* build free node group */
    groupnode = vis_GroupBegin();
    vis_GroupDef(groupnode, numnp, SYS_NODE, SYS_NONE);
    vis_ConnectNodeGroup(connect, CONNECT_FEATURE, groupedge, groupnode);

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vcvalue = vis_VisContextBegin();

    /* set value visualization context values */
    vis_VisContextSetMapColor(vcvalue, VIS_OFF);
    vis_VisContextSetColor(vcvalue, 6);
    vis_VisContextSetLineWidth(vcvalue, 2);
    vis_VisContextSetMinorColor(vcvalue, 1);
    vis_VisContextSetABCColor(vcvalue, 0, 0, 0);
    vis_VisContextSetComponent(vcvalue, VIS_COMPONENT_BASIC);
    vis_VisContextSetFlags(vcvalue, VIS_VALUEBRACKET | VIS_VALUEBACK);

    /* levels, set evenly spaced levels */
    levels = vis_LevelsBegin();
    nlevels = 12;
    vis_LevelsDef(levels, LEVELS_LINEAR, nlevels);
    vis_LevelsSetMinMax(levels, sminmax[0], sminmax[1]);
    vis_LevelsGenerate(levels, LEVELS_PADNONE);

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

    /* element orientation triad visualization context */
    vcetriad = vis_VisContextBegin();
    vis_VisContextSetLineWidth(vcetriad, 1);
    vis_VisContextSetMinorColor(vcetriad, 0);
    vis_VisContextSetSize(vcetriad, .05F * xmax);
    vis_VisContextSetMinorSize(vcetriad, .02F * xmax);
    vis_VisContextSetColor(vcetriad, 7);
    vis_VisContextSetXYZColor(vcetriad, 1, 2, 3);
    vis_VisContextSetABCColor(vcetriad, 0, 0, 0);
    vis_VisContextSetTrans(vcetriad, 1);
    vis_VisContextSetVectorType(vcetriad, VIS_VECTORLINE);

    /* create Triad object and set objects */
    triad = vis_TriadBegin();
    vis_TriadSetObject(triad, VGL_DRAWFUN, dftriad);
    vis_TriadSetObject(triad, VIS_VISCONTEXT, vctriad);
    vis_TriadSetObject(triad, VIS_COLORMAP, cmap);

    /* create element orientatin Triad object and set objects */
    etriad = vis_TriadBegin();
    vis_TriadSetObject(etriad, VGL_DRAWFUN, df);
    vis_TriadSetObject(etriad, VIS_VISCONTEXT, vcetriad);
    vis_TriadSetObject(etriad, VIS_COLORMAP, cmap);
    vis_TriadSetParami(etriad, TRIAD_LABELS, 0);

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
    vis_LegendSetObject(legend, VIS_VISCONTEXT, vclegend);
    vis_LegendSetObject(legend, VIS_COLORMAP, cmapiso);
    vis_LegendSetObject(legend, VIS_LEVELS, levels);
    vis_LegendSetParami(legend, LEGEND_PADTOP, VIS_OFF);

    /* create CoordSys object for material orientation */
    coordsys = vis_CoordSysBegin();
    vis_CoordSysDef(coordsys, SYS_CARTESIAN);

    /* set properties for generation */
    prop = vsy_PropSetBegin();
    vsy_PropSetInsertp(prop, "connect", (Vobject*)connect);
    vsy_PropSetInsertp(prop, "groupnode", (Vobject*)groupnode);
    vsy_PropSetInsertp(prop, "groupedge", (Vobject*)groupedge);
    vsy_PropSetInsertp(prop, "groupface", (Vobject*)groupface);
    vsy_PropSetInsertp(prop, "grouptran", (Vobject*)grouptran);
    vsy_PropSetInsertp(prop, "state", (Vobject*)state);
    vsy_PropSetInsertp(prop, "stated", (Vobject*)stated);
    vsy_PropSetInsertp(prop, "staten", (Vobject*)staten);
    vsy_PropSetInsertp(prop, "stateen", (Vobject*)stateen);
    vsy_PropSetInsertp(prop, "stateenv", (Vobject*)stateenv);
    vsy_PropSetInsertp(prop, "statee", (Vobject*)statee);
    vsy_PropSetInsertp(prop, "idtrannsys", (Vobject*)idtrannsys);
    vsy_PropSetInsertp(prop, "idtranesys", (Vobject*)idtranesys);
    vsy_PropSetInsertp(prop, "hashcsys", (Vobject*)hashcsys);
    vsy_PropSetInsertp(prop, "hasheldt", (Vobject*)hasheldt);
    vsy_PropSetInsertp(prop, "lman", (Vobject*)lman);
    vsy_PropSetInsertp(prop, "idsts", (Vobject*)idsts);
    vsy_PropSetInsertp(prop, "etriad", (Vobject*)etriad);
    vsy_PropSetInsertp(prop, "coordsys", (Vobject*)coordsys);

    vsy_PropSetInsertp(prop, "vc", (Vobject*)vc);
    vsy_PropSetInsertp(prop, "levels", (Vobject*)levels);
    vsy_PropSetInsertp(prop, "edge", (Vobject*)edge);
    vsy_PropSetInsertp(prop, "face", (Vobject*)face);
    vsy_PropSetInsertp(prop, "mark", (Vobject*)mark);
    vsy_PropSetInsertp(prop, "value", (Vobject*)value);
    vsy_PropSetInsertp(prop, "contour", (Vobject*)contour);
    vsy_PropSetInsertp(prop, "threshold", (Vobject*)threshold);
    vsy_PropSetInsertp(prop, "legend", (Vobject*)legend);

    vsy_PropSetInsertp(prop, "dl", (Vobject*)dl);
    vsy_PropSetInsertp(prop, "dltitle", (Vobject*)dltitle);
    vsy_PropSetInsertp(prop, "dllegend", (Vobject*)dllegend);
    vsy_PropSetInsertp(prop, "df", (Vobject*)df);
    vsy_PropSetInsertp(prop, "dftitle", (Vobject*)dftitle);
    vsy_PropSetInsertp(prop, "dflegend", (Vobject*)dflegend);
    vsy_PropSetInsertp(prop, "iactor", (Vobject*)iactor);
    vsy_PropSetInsertf(prop, "xmax", xmax);
    /* initial display is "Element Face Contour" */
    vsy_PropSetInserti(prop, "displayold", 2);
    vsy_PropSetInserti(prop, "deformold", 0);
    /* initial Element Orientation is off */
    vsy_PropSetInserti(prop, "elemorientold", 0);
    /* initial result is "Displacement" */
    vsy_PropSetInserti(prop, "resultold", 1);
    vsy_PropSetInserti(prop, "faceedges", 0);
    vsy_PropSetInserti(prop, "facenodes", 0);
    vsy_PropSetInserti(prop, "Exit", 0);

    /* instance Popup for display generation */
    popup = vgl_PopupBegin();
    vgl_PopupSetObject(popup, VGL_DRAWFUN, dfdev);
    popupcases = vgl_PopupBegin();
    vgl_PopupSetObject(popupcases, VGL_DRAWFUN, dfdev);
    popupdef = vgl_PopupBegin();
    vgl_PopupSetObject(popupdef, VGL_DRAWFUN, dfdev);

    vgl_PopupTitle(popup, (Vchar*)"Display Types");
    vgl_PopupAddItem(popup, 0, (Vchar*)"Element Edge", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 1, (Vchar*)"Element Face", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 2, (Vchar*)"Element Face Contour", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 3, (Vchar*)"Element Isosurface", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 4, (Vchar*)"Element Isofringe", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 5, (Vchar*)"Node Vector", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 6, (Vchar*)"Node Value", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddLine(popup);
    vgl_PopupAddPopup(popup, 20, (Vchar*)"Cases", popupcases);
    vgl_PopupAddRadio(popup, 21, 1, (Vchar*)"Displacement", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddRadio(popup, 21, 2, (Vchar*)"Stress", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddRadio(popup, 21, 3, (Vchar*)"Strain Energy Density", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupSetRadio(popup, 21, 1);
    vgl_PopupAddLine(popup);
    vgl_PopupAddPopup(popup, 10, (Vchar*)"Deform", popupdef);
    vgl_PopupAddToggle(popup, 11, (Vchar*)"Face Edges", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddToggle(popup, 12, (Vchar*)"Face Nodes", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddToggle(popup, 13, (Vchar*)"Element Orientation", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddLine(popup);
    vgl_PopupAddItem(popup, 30, (Vchar*)"Fit", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 31, (Vchar*)"Exit", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);

    /* cases Popup */
    for (i = 0; i < ndsts; i++) {
        vdm_LibraryGetDataset(library, idsts[i], &dataset);
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);
        vgl_PopupAddRadio(popupcases, 100, i + 1, dsname, (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    }

    /* deform Popup */
    vgl_PopupAddRadio(popupdef, 200, 1, (Vchar*)"None", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddRadio(popupdef, 200, 2, (Vchar*)"Scaled", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddRadio(popupdef, 200, 3, (Vchar*)"True", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupSetRadio(popup, 200, 1);

    vgl_PopupSetRadio(popup, 100, 1);

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

    vgl_IActorSetFunction(iactor, IACTOR_FUN_IDLE, (void (*)(vgl_IActor*, Vobject*))vgl_IActorSpin, NULL);
    vgl_IActorSetObject(iactor, VGL_POPUP, popup);
    vgl_IActorSetFunction(iactor, IACTOR_FUN_UNBOUND, (void (*)(vgl_IActor*, Vobject*))vgl_IActorAbort, NULL);

    /* set button bindings for object manipulation */
    vgl_IActorButtonAction(iactor, IACTOR_LEFTMOUSE, IACTOR_TRACKBALL);
    vgl_IActorButtonAction(iactor, IACTOR_MIDDLEMOUSE, IACTOR_TRANSLATE);
    if (iper == 0) {
        vgl_IActorButtonAction(iactor, IACTOR_RIGHTMOUSE, IACTOR_SCALECENTER);
    }
    else {
        vgl_IActorButtonAction(iactor, IACTOR_RIGHTMOUSE, IACTOR_DOLLYCENTER);
    }
    vgl_IActorButtonAction(iactor, IACTOR_CTRL, IACTOR_POPUP);

    vgl_IActorModifierAction(iactor, IACTOR_LEFTMOUSE, IACTOR_SHIFT, IACTOR_SQUIGGLE);
    vgl_IActorModifierAction(iactor, IACTOR_MIDDLEMOUSE, IACTOR_SHIFT, IACTOR_WINDOW);
    vgl_IActorModifierAction(iactor, IACTOR_RIGHTMOUSE, IACTOR_SHIFT, IACTOR_TRANSFORMSNAP);

    /* initialize display */
    popup_callback(popup, prop);

    /* initially fit model edge to screen */
    vgl_IActorFit(iactor, NULL);

    /* implement a simple mouse polling loop */
    while (1) {
        vgl_IActorMainPoll(iactor);
        vsy_PropSetLookupInteger(prop, "Exit", &exitflag);
        if (exitflag)
            break;
    }

    /* close window */
    vgl_DrawFunCloseWindow(dfdev);

    /* close library device and delete interface */
    vdm_DataFunClose(datafun);
    vdm_DataFunEnd(datafun);
    if (filetype == VDM_NASTRAN_BULKDATA) {
        vdm_NASFilEnd(nasfil);
    }
    else if (filetype == VDM_NASTRAN_OUTPUT2) {
        vdm_NASLibEnd(naslib);
    }
    else if (filetype == VDM_ANSYS_RESULT) {
        vdm_ANSLibEnd(anslib);
    }
    else if (filetype == VDM_ABAQUS_INPUT) {
        vdm_ABAFilEnd(abafil);
    }
    else if (filetype == VDM_ABAQUS_FIL || filetype == VDM_ABAQUS_ODB) {
        vdm_ABALibEnd(abalib);
    }
    else if (filetype == VDM_MECHANICA_STUDY) {
        vdm_RASLibEnd(raslib);
    }
    else if (filetype == VDM_SDRC_UNIVERSAL) {
        vdm_SDRCLibEnd(sdrclib);
    }
    else if (filetype == VDM_ENSIGHT) {
        vdm_EnSightLibEnd(ensightlib);
    }
    else if (filetype == VDM_TECPLOT) {
        vdm_TecplotLibEnd(tecplotlib);
    }
    else if (filetype == VDM_MARC_POST) {
        vdm_MarcLibEnd(marclib);
    }
    else if (filetype == VDM_STL || filetype == VDM_STLBIN) {
        vdm_STLFilEnd(stlfil);
    }
    else if (filetype == VDM_PATRAN_NEUTRAL) {
        vdm_PatLibEnd(patlib);
    }
    else if (filetype == VDM_LSTC_STATE) {
        vdm_D3DLibEnd(d3dlib);
    }
    else if (filetype == VDM_NATIVE) {
        vdm_NatLibEnd(natlib);
    }
    else if (filetype == VDM_CGNS) {
        vdm_CGNSVLibEnd(cgnsvlib);
    }
    else if (filetype == VDM_STARCCM) {
        vdm_STARCCMLibEnd(starccmlib);
    }
    vdm_LManEnd(lman);

    /* free explicitly allocated memory */
    free(idsts);
    /* free all objects */
    vis_ModelDelete(model);
    vis_ModelEnd(model);
    vis_StateEnd(state);
    vis_StateEnd(stated);
    vis_StateEnd(staten);
    vis_StateEnd(statee);
    vis_StateEnd(stateen);
    vis_StateEnd(stateenv);
    vis_IdTranEnd(idtrannsys);
    vis_IdTranEnd(idtranesys);
    vis_GroupEnd(groupface);
    vis_GroupEnd(groupedge);
    vis_GroupEnd(groupnode);
    vis_GroupEnd(grouptran);
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
    vis_VisContextEnd(vcetriad);
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
    vis_TriadEnd(etriad);
    vis_LegendEnd(legend);
    vis_CoordSysEnd(coordsys);
    vsy_DictionaryEnd(dict);
    vsy_PropSetEnd(prop);
    vgl_PopupEnd(popup);
    vgl_PopupEnd(popupcases);
    vgl_PopupEnd(popupdef);

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
    vis_Group *groupnode, *groupedge, *groupface, *grouptran;
    vis_Group *groupfaceedge, *groupfacenode;
    vis_State *state, *stated;
    vis_State *staten, *statee, *stateen, *stateenv;
    vis_IdTran *idtrannsys, *idtranesys;
    vis_CoordSys* coordsys;
    vsy_HashTable *hashcsys, *hasheldt;

    vis_VisContext* vc;
    vis_Levels* levels;
    vis_Edge* edge;
    vis_Face* face;
    vis_Mark* mark;
    vis_Value* value;
    vis_Contour* contour;
    vis_Threshold* threshold;
    vis_Legend* legend;

    vgl_DList *dl, *dltitle, *dllegend;
    vgl_IActor* iactor;
    vgl_DrawFun *df, *dftitle, *dflegend;

    vdm_LMan* lman;

    Vint ind, val;
    Vint faceedges, facenodes;
    Vint displaytype, displayold;
    Vint deformtype, deformold;
    Vint resulttype, resultold;
    Vint elemorienttype, elemorientold;
    Vint enflag, eflag, envflag;
    Vint* idsts;
    Vfloat xmax;
    Vfloat sminmax[2], smin, smax;
    Vint numel, numnp;

    vis_Triad* etriad;
    Vfloat orientvec[VIS_MAXELEMNODE][3], xcoord[VIS_MAXELEMNODE][3], tm[3][3];
    Vint nix, ix[VIS_MAXELEMNODE], n, i;

    /* retrieve objects */
    vsy_PropSetLookupObject(prop, "connect", (Vobject**)&connect);
    vsy_PropSetLookupObject(prop, "groupnode", (Vobject**)&groupnode);
    vsy_PropSetLookupObject(prop, "groupedge", (Vobject**)&groupedge);
    vsy_PropSetLookupObject(prop, "groupface", (Vobject**)&groupface);
    vsy_PropSetLookupObject(prop, "grouptran", (Vobject**)&grouptran);
    vsy_PropSetLookupObject(prop, "state", (Vobject**)&state);
    vsy_PropSetLookupObject(prop, "stated", (Vobject**)&stated);
    vsy_PropSetLookupObject(prop, "staten", (Vobject**)&staten);
    vsy_PropSetLookupObject(prop, "stateen", (Vobject**)&stateen);
    vsy_PropSetLookupObject(prop, "stateenv", (Vobject**)&stateenv);
    vsy_PropSetLookupObject(prop, "statee", (Vobject**)&statee);
    vsy_PropSetLookupObject(prop, "idtrannsys", (Vobject**)&idtrannsys);
    vsy_PropSetLookupObject(prop, "idtranesys", (Vobject**)&idtranesys);
    vsy_PropSetLookupObject(prop, "hashcsys", (Vobject**)&hashcsys);
    vsy_PropSetLookupObject(prop, "hasheldt", (Vobject**)&hasheldt);
    vsy_PropSetLookupObject(prop, "lman", (Vobject**)&lman);
    vsy_PropSetLookupObject(prop, "idsts", (Vobject**)&idsts);
    vsy_PropSetLookupObject(prop, "etriad", (Vobject**)&etriad);
    vsy_PropSetLookupObject(prop, "coordsys", (Vobject**)&coordsys);

    vsy_PropSetLookupObject(prop, "vc", (Vobject**)&vc);
    vsy_PropSetLookupObject(prop, "levels", (Vobject**)&levels);
    vsy_PropSetLookupObject(prop, "edge", (Vobject**)&edge);
    vsy_PropSetLookupObject(prop, "face", (Vobject**)&face);
    vsy_PropSetLookupObject(prop, "mark", (Vobject**)&mark);
    vsy_PropSetLookupObject(prop, "value", (Vobject**)&value);
    vsy_PropSetLookupObject(prop, "contour", (Vobject**)&contour);
    vsy_PropSetLookupObject(prop, "threshold", (Vobject**)&threshold);
    vsy_PropSetLookupObject(prop, "legend", (Vobject**)&legend);

    vsy_PropSetLookupObject(prop, "dl", (Vobject**)&dl);
    vsy_PropSetLookupObject(prop, "dltitle", (Vobject**)&dltitle);
    vsy_PropSetLookupObject(prop, "dllegend", (Vobject**)&dllegend);
    vsy_PropSetLookupObject(prop, "df", (Vobject**)&df);
    vsy_PropSetLookupObject(prop, "dftitle", (Vobject**)&dftitle);
    vsy_PropSetLookupObject(prop, "dflegend", (Vobject**)&dflegend);
    vsy_PropSetLookupObject(prop, "iactor", (Vobject**)&iactor);
    vsy_PropSetLookupFloat(prop, "xmax", &xmax);
    vsy_PropSetLookupInteger(prop, "displayold", &displayold);
    vsy_PropSetLookupInteger(prop, "deformold", &deformold);
    vsy_PropSetLookupInteger(prop, "elemorientold", &elemorientold);
    vsy_PropSetLookupInteger(prop, "resultold", &resultold);
    vsy_PropSetLookupInteger(prop, "faceedges", &faceedges);
    vsy_PropSetLookupInteger(prop, "facenodes", &facenodes);

    vgl_PopupGetIndex(popup, &ind);

    /* test for fit or exit */
    if (ind == 30) {
        vgl_IActorFit(iactor, NULL);
        return;
    }
    else if (ind == 31) {
        vsy_PropSetInserti(prop, "Exit", 1);
        vgl_IActorAbort(iactor, NULL);
        return;
    }
    /* erase title, legend and model display lists */
    vgl_DListErase(dltitle);
    vgl_DListErase(dllegend);
    vgl_DListErase(dl);

    displaytype = displayold;
    deformtype = deformold;
    elemorienttype = elemorientold;
    resulttype = resultold;

    /* test for display type */
    if (ind >= 0 && ind <= 6) {
        vsy_PropSetInserti(prop, "displayold", ind);
        displaytype = ind;
    }

    /* test for cases popup */
    /* load selected states */
    if (ind == 100) {
        vgl_PopupGetRadio(popup, ind, &val);
        load_states(lman, idsts[val - 1], staten, stateen, &enflag, statee, &eflag, stateenv, &envflag);
        transform_disp(hashcsys, idtrannsys, staten);
        if (enflag) {
            transform_strs(hashcsys, hasheldt, idtranesys, grouptran, stateen);
        }
        load_deform(staten, stated, xmax, .15f, deformtype);

        load_scalarn(staten, stateen, statee, resulttype, state);
        vis_StateExtent(state, NULL, sminmax);
        vis_LevelsSetMinMax(levels, sminmax[0], sminmax[1]);
        vis_LevelsGenerate(levels, LEVELS_PADNONE);
    }

    /* test for result */
    if (ind == 21) {
        vgl_PopupGetRadio(popup, ind, &val);
        load_scalarn(staten, stateen, statee, val, state);
        vis_StateExtent(state, NULL, sminmax);
        vis_LevelsSetMinMax(levels, sminmax[0], sminmax[1]);
        vis_LevelsGenerate(levels, LEVELS_PADNONE);
        vsy_PropSetInserti(prop, "resultold", val);
        resulttype = val;
    }

    /* test for deform */
    if (ind == 200) {
        vgl_PopupGetRadio(popup, ind, &val);
        vsy_PropSetInserti(prop, "deformold", val - 1);
        deformtype = val - 1;
        load_deform(staten, stated, xmax, .15f, deformtype);
    }

    /* test for element orientation */
    if (ind == 13) {
        vgl_PopupGetToggle(popup, ind, &val);
        vsy_PropSetInserti(prop, "elemorientold", val);
        elemorienttype = val;
    }

    /* auxiliary edges or nodes */
    if (ind == 11) {
        vgl_PopupGetToggle(popup, ind, &val);
        faceedges = val;
        vsy_PropSetInserti(prop, "faceedges", faceedges);
    }
    else if (ind == 12) {
        vgl_PopupGetToggle(popup, ind, &val);
        facenodes = val;
        vsy_PropSetInserti(prop, "facenodes", facenodes);
    }

    /* set deformed coordinates */
    if (deformtype) {
        vis_ConnectSetObject(connect, VIS_STATE, stated);
    }

    /* draw element orientation triad */
    if (elemorienttype) {
        vis_ConnectNumber(connect, SYS_ELEM, &numel);
        for (n = 1; n <= numel; n++) {
            vis_StateData(stateenv, 1, &n, (Vfloat*)orientvec);
            vis_ConnectElemNode(connect, n, &nix, ix);
            vis_ConnectCoords(connect, nix, ix, xcoord);
            for (i = 0; i < nix; i++) {
                vis_CoordSysSetOriginRotAng(coordsys, xcoord[i], orientvec[i]);
                vis_CoordSysDirCos(coordsys, xcoord[i], tm);
                vis_TriadDraw(etriad, SYS_CARTESIAN, xcoord[i], tm);
            }
        }
    }

    /* draw auxiliary edges */
    vis_VisContextSetMapColor(vc, VIS_OFF);
    vis_VisContextSetColor(vc, 7);
    if (faceedges) {
        vis_ConnectNumber(connect, SYS_ELEM, &numel);
        groupfaceedge = vis_GroupBegin();
        vis_GroupDef(groupfaceedge, numel, SYS_ELEM, SYS_EDGE);
        vis_ConnectEdgeGroup(connect, CONNECT_UNIQUE, groupface, groupfaceedge);
        vis_EdgeTrav(edge, groupfaceedge);
        vis_GroupEnd(groupfaceedge);
    }
    else {
        vis_EdgeTrav(edge, groupedge);
    }

    /* draw auxiliary nodes */
    if (facenodes) {
        vis_ConnectNumber(connect, SYS_NODE, &numnp);
        groupfacenode = vis_GroupBegin();
        vis_GroupDef(groupfacenode, numnp, SYS_NODE, SYS_NONE);
        vis_ConnectNodeGroup(connect, CONNECT_UNIQUE, groupface, groupfacenode);
        draw_NodePoint(df, connect, groupfacenode);
        vis_GroupEnd(groupfacenode);
    }

    /* generate new display */
    if (displaytype == 0) {
        draw_title(dftitle, (Vchar*)"Element Edge", NULL);
        vis_VisContextSetColor(vc, 7);
        vis_VisContextSetMapColor(vc, VIS_OFF);
        draw_ElemEdge(edge, connect, NULL);
    }
    else if (displaytype == 1) {
        draw_title(dftitle, (Vchar*)"Element Face", NULL);
        vis_VisContextSetColor(vc, 0);
        vis_VisContextSetMapColor(vc, VIS_OFF);
        vis_FaceTrav(face, groupface, NULL);
    }
    else if (displaytype == 2) {
        draw_title(dftitle, (Vchar*)"Element Face Contour", resulttitle[resulttype]);
        draw_Legend(dflegend, legend);
        vis_VisContextSetMapColor(vc, VIS_ON);
        vis_VisContextSetIsoValType(vc, VIS_ISOVALFRINGE);
        vis_VisContextSetFlags(vc, VIS_ISOVALACCENT);
        vis_VisContextSetColor(vc, 13);
        vis_ContourTrav(contour, state, groupface, NULL);
    }
    else if (displaytype == 3) {
        draw_title(dftitle, (Vchar*)"Element Isosurface", resulttitle[resulttype]);
        draw_Legend(dflegend, legend);
        vis_VisContextSetIsoValType(vc, VIS_ISOVALSURFACE);
        vis_VisContextSetMapColor(vc, VIS_ON);
        vis_ThresholdTrav(threshold, state, NULL, NULL);
    }
    else if (displaytype == 4) {
        draw_title(dftitle, (Vchar*)"Element Isofringe", resulttitle[resulttype]);
        draw_Legend(dflegend, legend);
        vis_VisContextSetIsoValType(vc, VIS_ISOVALFRINGE);
        vis_VisContextSetMapColor(vc, VIS_ON);
        vis_VisContextSetSize(vc, .01F * xmax);
        vis_ThresholdTrav(threshold, state, NULL, NULL);
    }
    else if (displaytype == 5) {
        draw_title(dftitle, (Vchar*)"Node Vector", (Vchar*)"Displacement");
        vis_LevelsGetMinMax(levels, &smin, &smax);
        vis_StateSetDerive(staten, VIS_VECTOR_MAG);
        vis_StateExtent(staten, NULL, sminmax);
        vis_LevelsSetMinMax(levels, sminmax[0], sminmax[1]);
        vis_LevelsGenerate(levels, LEVELS_PADNONE);
        draw_Legend(dflegend, legend);
        vis_StateSetDerive(staten, VIS_VECTOR);
        vis_VisContextSetVectorType(vc, VIS_VECTORUMBRELLA);
        vis_VisContextSetComponent(vc, VIS_COMPONENT_PRINCIPAL);
        vis_VisContextSetSize(vc, .15F * xmax);
        vis_VisContextSetFlags(vc, VIS_VECTORTAIL | VIS_VECTORTAILREGISTER);
        vis_VisContextSetMapColor(vc, VIS_ON);
        vis_VisContextSetMapSize(vc, VIS_ON);
        vis_MarkTrav(mark, staten, NULL);
        vis_LevelsSetMinMax(levels, smin, smax);
        vis_LevelsGenerate(levels, LEVELS_PADNONE);
    }
    else if (displaytype == 6) {
        draw_title(dftitle, (Vchar*)"Node Value", (Vchar*)"Displacement");
        vis_ValueTrav(value, staten, groupnode);
    }
    /* unset deformed coordinates */
    if (deformtype) {
        vis_ConnectSetObject(connect, VIS_STATE, NULL);
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
    Vfloat cbot[3] = {.4f, .4f, .4f};
    Vfloat ctop[3] = {0., 0., .12f};

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
    if (!rflag) {
        vgl_IActorDrawBackground(iactor, cbot, ctop);
        vgl_IActorDrawTrackBall(iactor);
        vgl_IActorDrawRotCenter(iactor, 50);
    }
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
    vgl_DrawFunViewport(df, 0, xsize, ysize - 60, ysize);
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
                      draw element edges
----------------------------------------------------------------------*/
void
draw_ElemEdge(vis_Edge* edge, vis_Connect* connect, vis_Group* group)
{
    Vint numel;
    Vint n, j;
    Vint nedges;
    Vint nix;
    Vint ix[VIS_MAXEDGENODE];
    Vfloat x[VIS_MAXEDGENODE][3];

    /* get number of elements */
    vis_ConnectNumber(connect, SYS_ELEM, &numel);

    /* draw element edges */
    /* loop through elements */
    for (n = 1; n <= numel; n++) {
        if (vis_GroupElem(group, n) == 0)
            continue;
        vis_ConnectElemNum(connect, SYS_EDGE, n, &nedges);

        /* loop through element edges */
        for (j = 1; j <= nedges; j++) {
            if (vis_GroupElemEnt(group, n, j) == 0)
                continue;
            vis_ConnectElemCon(connect, SYS_EDGE, n, j, &nix, ix);
            vis_ConnectCoords(connect, nix, ix, x);
            vis_EdgeSetTopology(edge, SYS_SHAPELINE, nix);
            vis_EdgeCurv(edge, x);
        }
    }
}

/*----------------------------------------------------------------------
                      draw node points
----------------------------------------------------------------------*/
void
draw_NodePoint(vgl_DrawFun* df, vis_Connect* connect, vis_Group* group)
{
    Vint numnp;
    Vint n;
    Vint flags;
    Vfloat c[3];
    Vfloat x[3];

    /* get number of nodes */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);

    /* set color and point size */
    c[0] = 0., c[1] = 1., c[2] = 1.;
    vgl_DrawFunColor(df, c);
    vgl_DrawFunPointSize(df, 4);

    /* loop through nodes */
    for (n = 1; n <= numnp; n++) {
        if (group != NULL) {
            vis_GroupGetIndex(group, n, &flags);
            if (flags == 0)
                continue;
        }
        vis_ConnectCoords(connect, 1, &n, (Vfloat(*)[3])x);
        vgl_DrawFunPolyPoint(df, 1, (Vfloat(*)[3])x);
    }
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
    dc[0] = 10;
    dc[1] = 270;
    dc[2] = 0;
    vgl_DrawFunTextDC(df, x, dc, (Vchar*)"Contour Levels");

    vgl_DrawFunRasFontSelect(df, 1);
    x[0] = .1f;
    x[1] = .05f;
    x[2] = 0.;
    vis_LegendSetObject(legend, VGL_DRAWFUN, df);
    vis_LegendDraw(legend, x);
    vgl_DrawFunRasFontSelect(df, 0);
    vgl_DrawFunSetMode(df, VGL_LIGHTMODE, VGL_ON);
    vgl_DrawFunSetMode(df, VGL_ZBUFFERMODE, VGL_ON);
}

/*----------------------------------------------------------------------
                      draw title
----------------------------------------------------------------------*/
void
draw_title(vgl_DrawFun* df, Vchar* title1, Vchar* title2)
{
    Vfloat c[3];
    Vfloat x[3];
    Vint dc[3];
    /* draw a three line title in raster font */
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
    if (title1) {
        dc[0] = 10;
        dc[1] = -10;
        dc[2] = 0;
        vgl_DrawFunTextDC(df, x, dc, title1);
        vgl_DrawFunSetMode(df, VGL_ZBUFFERMODE, VGL_ON);
    }
    if (title2) {
        dc[0] = 10;
        dc[1] = -25;
        dc[2] = 0;
        vgl_DrawFunTextDC(df, x, dc, title2);
        vgl_DrawFunSetMode(df, VGL_ZBUFFERMODE, VGL_ON);
    }
}

/*----------------------------------------------------------------------
                      load states associated with a displacement dataset
----------------------------------------------------------------------*/
void
load_states(vdm_LMan* lman, Vint ids, vis_State* staten, vis_State* stateen, Vint* enflag, vis_State* statee, Vint* eflag,
            vis_State* stateenv, Vint* envflag)
{
    vis_RProp* rprop;
    vdm_DataFun* datafun;
    vdm_Library* library;
    vdm_Dataset* dataset;
    Vchar dsname[DATASET_MAXNAME], dname[DATASET_MAXNAME];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vint id1, id2, id3;
    Vint enids, eids;

    /* instance result property object */
    rprop = vis_RPropBegin();

    vdm_LManGetObject(lman, VDM_DATAFUN, (Vobject**)&datafun);
    vdm_DataFunGetLibrary(datafun, &library);

    /* get displacement dataset */
    vdm_LibraryGetDataset(library, ids, &dataset);
    vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);
    vis_RPropDef(rprop, SYS_NODE, SYS_NONE);
    vis_RPropSetDatasetName(rprop, dsname);
    vdm_LManLoadState(lman, staten, rprop);

    vdm_DatasetDecode(dataset, dname, &id1, &id2, &id3);

    /* test for stress */
    /* section stress */
    if (id2 != 0) {
        sprintf(dsname, "%s%-d:%-d", "S.SEC.TOP.EL:", id1, id2);
    }
    else {
        sprintf(dsname, "%s%-d", "S.SEC.TOP.EL:", id1);
    }
    vdm_LibrarySearchDataset(library, dsname, 1, &enids, enflag);
    /* if none then general stress */
    if (*enflag == 0) {
        if (id2 != 0) {
            sprintf(dsname, "%s%-d:%-d", "S.EL:", id1, id2);
        }
        else {
            sprintf(dsname, "%s%-d", "S.EL:", id1);
        }
        vdm_LibrarySearchDataset(library, dsname, 1, &enids, enflag);
    }
    if (*enflag) {
        vdm_LibraryGetDataset(library, enids, &dataset);
        vis_RPropDef(rprop, SYS_ELEM, SYS_NODE);
        vis_RPropSetDatasetName(rprop, dsname);
        vdm_LManLoadState(lman, stateen, rprop);
    }
    else {
        vis_StateClear(stateen);
    }

    /* test for strain energy density */
    if (id2 != 0) {
        sprintf(dsname, "%s%-d:%-d", "SE_DENSITY.E:", id1, id2);
    }
    else {
        sprintf(dsname, "%s%-d", "SE_DENSITY.E:", id1);
    }
    vdm_LibrarySearchDataset(library, dsname, 1, &eids, eflag);
    if (*eflag) {
        vdm_LibraryGetDataset(library, eids, &dataset);
        vis_RPropDef(rprop, SYS_ELEM, SYS_NONE);
        vis_RPropSetDatasetName(rprop, dsname);
        vdm_LManLoadState(lman, statee, rprop);
    }
    else {
        vis_StateClear(statee);
    }

    /* test for element orientation */
    if (id2 != 0) {
        sprintf(dsname, "%s%-d:%-d", "ROT_ANG.EL:", id1, id2);
    }
    else {
        sprintf(dsname, "%s%-d", "ROT_ANG.EL:", id1);
    }
    vdm_LibrarySearchDataset(library, dsname, 1, &eids, envflag);
    if (*envflag) {
        vdm_LibraryGetDataset(library, eids, &dataset);
        vis_RPropDef(rprop, SYS_ELEM, SYS_NODE);
        vis_RPropSetDatasetName(rprop, dsname);
        vdm_LManLoadState(lman, stateenv, rprop);
    }
    else {
        vis_StateClear(stateenv);
    }

    /* delete result property object */
    vis_RPropEnd(rprop);
}

/*----------------------------------------------------------------------
                      transform displacement to global
----------------------------------------------------------------------*/
void
transform_disp(vsy_HashTable* hashcsys, vis_IdTran* idtrannsys, vis_State* staten)
{
    vis_StateSetHashTable(staten, VIS_COORDSYS, hashcsys);
    vis_StateSetObject(staten, VIS_IDTRAN, idtrannsys);
    vis_StateTransform(staten, STATE_GLOBAL, NULL);
}

/*----------------------------------------------------------------------
                      transform stress to global
----------------------------------------------------------------------*/
void
transform_strs(vsy_HashTable* hashcsys, vsy_HashTable* hasheldt, vis_IdTran* idtranesys, vis_Group* group, vis_State* stateen)
{
    vis_StateSetHashTable(stateen, VIS_COORDSYS, hashcsys);
    vis_StateSetHashTable(stateen, VIS_ELEMDAT, hasheldt);
    vis_StateSetObject(stateen, VIS_IDTRAN, idtranesys);
    vis_StateSetSystem(stateen, STATE_LOCAL);
    vis_StateTransform(stateen, STATE_GLOBAL, group);
}

/*----------------------------------------------------------------------
                      create deformed coordinate state from displacements
----------------------------------------------------------------------*/
void
load_deform(vis_State* staten, vis_State* stated, Vfloat xmax, Vfloat fac, Vint deformtype)
{
    Vfloat sminmax[2];
    Vfloat f;
    /* scale deformations to fac fraction of model */
    if (deformtype == 2) {
        f = 1.;
    }
    else {
        vis_StateSetDerive(staten, VIS_VECTOR_MAG);
        vis_StateExtent(staten, NULL, sminmax);
        if (sminmax[1] == 0.) {
            f = 1.;
        }
        else {
            f = (fac * xmax) / sminmax[1];
        }
    }
    vis_StateSetDerive(staten, VIS_VECTOR);
    vis_StateDeform(stated, f, staten, NULL);
}

/*----------------------------------------------------------------------
                      create nodal scalar for display
----------------------------------------------------------------------*/
void
load_scalarn(vis_State* staten, vis_State* stateen, vis_State* statee, Vint resulttype, vis_State* state)
{
    /* displacement magnitude */
    if (resulttype == 1) {
        vis_StateSetDerive(staten, VIS_VECTOR_MAG);
        vis_StateOperateUnary(state, STATE_EQUAL, 1., STATE_IDENTITY, staten, NULL);
        vis_StateSetDerive(staten, VIS_VECTOR);

        /* effective stress */
    }
    else if (resulttype == 2) {
        vis_StateSetDerive(stateen, VIS_TENSOR_VONMISES);
        vis_StateMap(state, stateen, NULL);
        vis_StateSetDerive(stateen, VIS_TENSOR);

        /* strain energy density */
    }
    else if (resulttype == 3) {
        vis_StateMap(state, statee, NULL);
    }
}
