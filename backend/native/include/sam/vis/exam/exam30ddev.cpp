#include <stdlib.h>
#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

void
popup_callback(vgl_Popup* popup, vsy_PropSet* prop);
void
display_callback(vgl_IActor* iactor, vsy_Dictionary* dict);
void
draw_1DElem(vis_Group* group, vis_Connect* connect, vis_State* stated, vis_VisContext* vc1d, vis_RigidElem* rigidelem,
            vis_GapElem* gapelem, vis_DiscElem* discelem, vis_MassElem* masselem);
void
draw_ElemEdge(vis_Group* group, vis_Connect* connect, vis_State* stated, vis_Edge* edge);
void
draw_ElemFace(vis_Group* group, vis_Connect* connect, vis_State* stated, vis_Face* face);
void
draw_NodePoint(vis_Group* group, vis_Connect* connect, vis_State* stated, vgl_DrawFun* df);
void
draw_ElemLabel(vis_Group* group, vis_Connect* connect, vis_State* stated, vgl_DrawFun* df);
void
draw_NodeLabel(vis_Group* group, vis_Connect* connect, vis_State* stated, vgl_DrawFun* df);
void
draw_title(vgl_DrawFun* df, Vchar* title);

/* Red,Green,Blue components of entity Colormap */
static Vfloat rgb[9][3] = {{.5, .5, .5}, {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}, {0., 1., 1.},
                           {1., 0., 1.}, {1., 1., 0.}, {1., 1., 1.}, {.5, .5, 1.}};

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
    vis_Group *groupnode, *groupedge, *groupface, *groupelem;
    vis_Group *groupfaceshell, *groupfacesolid, *groupedgebeam;

    vis_VisContext *vc, *vc1d, *vctriad;
    vis_ColorMap* cmap;
    vis_TransMap* tmap;
    vis_Edge* edge;
    vis_Face* face;
    vis_RigidElem* rigidelem;
    vis_GapElem* gapelem;
    vis_DiscElem* discelem;
    vis_MassElem* masselem;
    vis_Triad* triad;

    vgl_DrawFun* dfdev;
    vgl_OpenGLDev* ogldev;
    vgl_Xfm* xfm;
    vgl_RasFont* rasfont;
    vgl_DrawFun *df, *dfedge, *dftitle, *dftriad;
    vgl_DList *dl, *dledge, *dltitle, *dltriad;
    vgl_IActor* iactor;
    vgl_Popup* popup;

    vsy_Dictionary* dict;
    vsy_PropSet* prop;

    /* VdmTools objects */
    vdm_DataFun* datafun = NULL;
    vdm_NASFil* nasfil = NULL;
    vdm_NASLib* naslib = NULL;
    vdm_ANSFil* ansfil = NULL;
    vdm_ANSLib* anslib = NULL;
    vdm_ABAFil* abafil = NULL;
    vdm_ABALib* abalib = NULL;
    vdm_PatLib* patlib = NULL;
    vdm_RASLib* raslib = NULL;
    vdm_SDRCLib* sdrclib = NULL;
    vdm_D3DFil* d3dfil = NULL;
    vdm_D3DLib* d3dlib = NULL;
    vdm_HMAFil* hmafil = NULL;
    vdm_STLFil* stlfil = NULL;
    vdm_PLOT3DLib* plot3dlib = NULL;
    vdm_FLUENTLib* fluentlib = NULL;
    vdm_EnSightLib* ensightlib = NULL;
    vdm_TecplotLib* tecplotlib = NULL;
    vdm_MarcLib* marclib = NULL;
    vdm_CGNSVLib* cgnsvlib = NULL;
    vdm_STARCCMLib* starccmlib = NULL;
    vdm_NatLib* natlib = NULL;
    vdm_LMan* lman = NULL;
    Vint filetype = 0;

    Vint k;
    Vint numnp, numel;
    Vfloat c[3], x[3];
    Vfloat tm3[3][3];
    Vint flag;

    Vint xsize, ysize;
    Vfloat ratio;

    Vint exitflag;
    Vint iper;
    Vfloat bbox[2][3], xmax;

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
    else if (strstr(argv[1], ".ans") != NULL || strstr(argv[1], ".cdb") != NULL) {
        filetype = VDM_ANSYS_INPUT;
        ansfil = vdm_ANSFilBegin();
        vdm_ANSFilDataFun(ansfil, datafun);
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
    else if (strstr(argv[1], ".out") != NULL) {
        filetype = VDM_PAT_NEUTRAL;
        patlib = vdm_PatLibBegin();
        vdm_PatLibDataFun(patlib, datafun);
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
    else if (strstr(argv[1], ".k") != NULL || strstr(argv[1], ".key") != NULL || strstr(argv[1], ".dyn") != NULL ||
             strstr(argv[1], ".DYN") != NULL) {
        filetype = VDM_LSTC_INPUT;
        d3dfil = vdm_D3DFilBegin();
        vdm_D3DFilDataFun(d3dfil, datafun);
    }
    else if (strstr(argv[1], "d3plot") != NULL || strstr(argv[1], "D3PLOT") != NULL) {
        filetype = VDM_LSTC_STATE;
        d3dlib = vdm_D3DLibBegin();
        vdm_D3DLibDataFun(d3dlib, datafun);
    }
    else if (strstr(argv[1], ".hma") != NULL) {
        filetype = VDM_HYPERMESH_ASCII;
        hmafil = vdm_HMAFilBegin();
        vdm_HMAFilDataFun(hmafil, datafun);
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
    else if (strstr(argv[1], ".x") != NULL || strstr(argv[1], ".xyz") != NULL) {
        filetype = VDM_PLOT3D_GRID;
        plot3dlib = vdm_PLOT3DLibBegin();
        vdm_PLOT3DLibDataFun(plot3dlib, datafun);
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
    else if (strstr(argv[1], ".cas") != NULL || strstr(argv[1], ".msh") != NULL) {
        filetype = VDM_FLUENT_MESH;
        fluentlib = vdm_FLUENTLibBegin();
        vdm_FLUENTLibDataFun(fluentlib, datafun);
    }
    else if (strstr(argv[1], ".t16") != NULL || strstr(argv[1], ".t19") != NULL) {
        filetype = VDM_MARC_POST;
        marclib = vdm_MarcLibBegin();
        vdm_MarcLibDataFun(marclib, datafun);
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
    else if (strstr(argv[1], ".vdm") != NULL) {
        filetype = VDM_NATIVE;
        natlib = vdm_NatLibBegin();
        vdm_NatLibDataFun(natlib, datafun);
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
    /* close library device and delete interface */
    vdm_DataFunClose(datafun);
    vdm_DataFunEnd(datafun);
    if (filetype == VDM_NASTRAN_BULKDATA) {
        vdm_NASFilEnd(nasfil);
    }
    else if (filetype == VDM_NASTRAN_OUTPUT2) {
        vdm_NASLibEnd(naslib);
    }
    else if (filetype == VDM_ANSYS_INPUT) {
        vdm_ANSFilEnd(ansfil);
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
    else if (filetype == VDM_PAT_NEUTRAL) {
        vdm_PatLibEnd(patlib);
    }
    else if (filetype == VDM_MECHANICA_STUDY) {
        vdm_RASLibEnd(raslib);
    }
    else if (filetype == VDM_LSTC_INPUT) {
        vdm_D3DFilEnd(d3dfil);
    }
    else if (filetype == VDM_LSTC_STATE) {
        vdm_D3DLibEnd(d3dlib);
    }
    else if (filetype == VDM_HYPERMESH_ASCII) {
        vdm_HMAFilEnd(hmafil);
    }
    else if (filetype == VDM_SDRC_UNIVERSAL) {
        vdm_SDRCLibEnd(sdrclib);
    }
    else if (filetype == VDM_STL || filetype == VDM_STLBIN) {
        vdm_STLFilEnd(stlfil);
    }
    else if (filetype == VDM_PLOT3D_GRID) {
        vdm_PLOT3DLibEnd(plot3dlib);
    }
    else if (filetype == VDM_ENSIGHT) {
        vdm_EnSightLibEnd(ensightlib);
    }
    else if (filetype == VDM_TECPLOT) {
        vdm_TecplotLibEnd(tecplotlib);
    }
    else if (filetype == VDM_FLUENT_MESH) {
        vdm_FLUENTLibEnd(fluentlib);
    }
    else if (filetype == VDM_MARC_POST) {
        vdm_MarcLibEnd(marclib);
    }
    else if (filetype == VDM_CGNS) {
        vdm_CGNSVLibEnd(cgnsvlib);
    }
    else if (filetype == VDM_STARCCM) {
        vdm_STARCCMLibEnd(starccmlib);
    }
    else if (filetype == VDM_NATIVE) {
        vdm_NatLibEnd(natlib);
    }
    vdm_LManEnd(lman);

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
    /* print instructions */
    printf("Example Element Viewer\n");
    printf("  Press CTRL to display Popup menu\n");
    printf("  Press Left Mouse Button to Rotate\n");
    printf("  Press Middle Mouse Button to Translate\n");
    printf("  Press Right Mouse Button to Scale\n");
    printf("  Press SHIFT/Left Mouse Button for Squiggle Window\n");
    printf("  Press SHIFT/Middle Mouse Button for Rectangular Window\n");
    printf("  Press SHIFT/Right Mouse Button for Align\n");
    printf("\n");
    printf("  Solid  Elements drawn in Green\n");
    printf("  Shell  Elements drawn in Blue\n");
    printf("  Beam   Elements drawn in Cyan\n");
    printf("  Rigid  Elements drawn in Red\n");
    printf("  Spring Elements drawn in BlueGray\n");
    printf("  Mass   Elements drawn in Magenta\n");
    printf("  Gap    Elements drawn in Yellow\n");

    /* create OpenGL device */
    ogldev = vgl_OpenGLDevBegin();

    /* create drawing function object for OpenGL */
    dfdev = vgl_DrawFunBegin();
    vgl_OpenGLDevDrawFun(ogldev, dfdev);

    /* initialize graphics window and lights */
    xsize = 640;
    ysize = 480;
    vgl_DrawFunPositionWindow(dfdev, 200, 200, xsize, ysize);
    vgl_DrawFunOpenWindow(dfdev, "Example 30ddev");
    /* Perspective or Orthographic */
    ratio = (Vfloat)xsize / (Vfloat)ysize;
    if (iper) {
        vgl_DrawFunProjFrustum(dfdev, -ratio, ratio, -1., 1., 4., 100.);
    }
    else {
        vgl_DrawFunProjOrtho(dfdev, -ratio, ratio, -1., 1., -1., 1.);
    }
    vgl_DrawFunSetMode(dfdev, VGL_ZBUFFERMODE, VGL_ON);
    vgl_DrawFunSetMode(dfdev, VGL_LIGHTMODE, VGL_ON);
    vgl_DrawFunSetMode(dfdev, VGL_RASFONTDRAWMODE, VGL_ON);
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

    /* create raster font object for smallest built-in font */
    rasfont = vgl_RasFontBegin();
    vgl_RasFontLoad(rasfont, RASFONT_NORMAL7X11);
    vgl_DrawFunRasFontDefine(dfdev, 1, rasfont);
    vgl_RasFontEnd(rasfont);

    /* create transformation object */
    xfm = vgl_XfmBegin();

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
    draw_title(dftitle, argv[1]);

    /* display list for triad */
    dltriad = vgl_DListBegin();
    dftriad = vgl_DrawFunBegin();
    vgl_DListDrawFun(dltriad, dftriad);
    vgl_DListSetObject(dltriad, VGL_DRAWFUN, dfdev);

    /* create a dictionary for all the display lists */
    dict = vsy_DictionaryBegin();
    vsy_DictionaryInsert(dict, "model", (Vobject*)dl);
    vsy_DictionaryInsert(dict, "edge", (Vobject*)dledge);
    vsy_DictionaryInsert(dict, "title", (Vobject*)dltitle);
    vsy_DictionaryInsert(dict, "triad", (Vobject*)dltriad);

    /* instance IActor for object manipulation */
    iactor = vgl_IActorBegin();
    vgl_IActorSetObject(iactor, VGL_DRAWFUN, dfdev);

    /* set display callback function */
    vgl_IActorSetFunction(iactor, IACTOR_FUN_DISPLAY, (void (*)(vgl_IActor*, Vobject*))display_callback, dict);

    vgl_IActorSetParamf(iactor, IACTOR_FITSHRINK, .1f);
    vgl_IActorSetParami(iactor, IACTOR_FITTYPE, IACTOR_FITTYPE_EXTENT);

    /* get Connect object */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);

    /* determine model extent */
    vis_ConnectExtent(connect, NULL, bbox);
    xmax = 0.;
    for (k = 0; k < 3; k++) {
        if (bbox[1][k] - bbox[0][k] > xmax) {
            xmax = bbox[1][k] - bbox[0][k];
        }
    }
    vgl_IActorSetParamfv(iactor, IACTOR_BOUNDBOX, (Vfloat*)bbox);

    /* generate connect kernel */
    vis_ConnectKernel(connect, 0);
    printf("number of nodes    = %d\n", numnp);
    printf("number of elements = %d\n", numel);

    /* create a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* build free face group */
    groupface = vis_GroupBegin();
    vis_GroupDef(groupface, numel, SYS_ELEM, SYS_FACE);
    vis_ConnectFaceGroup(connect, CONNECT_FREE, NULL, groupface);
    /* add 2D elements */
    vis_ConnectFaceGroup(connect, CONNECT_ELEM, NULL, groupface);

    groupelem = vis_GroupBegin();
    vis_GroupDef(groupelem, numel, SYS_ELEM, SYS_NONE);
    vis_ConnectSetGroupParami(connect, CONNECT_ASSOCTYPE, VIS_FEATYPE);

    /* build solid face group */
    vis_GroupClear(groupelem);
    vis_ConnectSetGroupParami(connect, CONNECT_ASSOCID, SYS_ELEM_SOLID);
    vis_ConnectElemGroup(connect, CONNECT_ASSOC, NULL, groupelem);
    groupfacesolid = vis_GroupBegin();
    vis_GroupDef(groupfacesolid, numel, SYS_ELEM, SYS_FACE);
    vis_ConnectFaceGroup(connect, CONNECT_FREE, groupelem, groupfacesolid);

    /* build shell, membrane, interface face group */
    vis_GroupClear(groupelem);
    vis_ConnectSetGroupParami(connect, CONNECT_ASSOCID, SYS_ELEM_SHELL);
    vis_ConnectElemGroup(connect, CONNECT_ASSOC, NULL, groupelem);
    vis_ConnectSetGroupParami(connect, CONNECT_ASSOCID, SYS_ELEM_MEMBRANE);
    vis_ConnectElemGroup(connect, CONNECT_ASSOC, NULL, groupelem);
    vis_ConnectSetGroupParami(connect, CONNECT_ASSOCID, SYS_ELEM_INTER);
    vis_ConnectElemGroup(connect, CONNECT_ASSOC, NULL, groupelem);
    groupfaceshell = vis_GroupBegin();
    vis_GroupDef(groupfaceshell, numel, SYS_ELEM, SYS_FACE);
    vis_ConnectFaceGroup(connect, CONNECT_ELEM, groupelem, groupfaceshell);

    /* build beam edge group */
    vis_GroupClear(groupelem);
    vis_ConnectSetGroupParami(connect, CONNECT_ASSOCID, SYS_ELEM_BEAM);
    vis_ConnectElemGroup(connect, CONNECT_ASSOC, NULL, groupelem);
    groupedgebeam = vis_GroupBegin();
    vis_GroupDef(groupedgebeam, numel, SYS_ELEM, SYS_EDGE);
    vis_ConnectEdgeGroup(connect, CONNECT_ELEM, groupelem, groupedgebeam);

    /* build feature edge group */
    groupedge = vis_GroupBegin();
    vis_GroupDef(groupedge, numel, SYS_ELEM, SYS_EDGE);
    vis_ConnectEdgeGroup(connect, CONNECT_FEATURE, groupface, groupedge);

    /* build free node group */
    groupnode = vis_GroupBegin();
    vis_GroupDef(groupnode, numnp, SYS_NODE, SYS_NONE);
    vis_ConnectNodeGroup(connect, CONNECT_UNIQUE, groupedge, groupnode);

    /* general element vis context and set attributes */
    vc = vis_VisContextBegin();

    /* 1D element vis context */
    vc1d = vis_VisContextBegin();
    vis_VisContextSetSize(vc1d, .008F * xmax);
    vis_VisContextSetRefinement(vc1d, 1);
    vis_VisContextSetElemRep(vc1d, VIS_ELEMREP_SOLID);
    vis_VisContextSetShade(vc1d, VIS_VERTEXSHADE);
    vis_VisContextSetMinorColor(vc1d, 7);
    vis_VisContextSetABCColor(vc1d, 7, 7, 5);

    /* color map for entities */
    cmap = vis_ColorMapBegin();
    vis_ColorMapSetRGB(cmap, 9, 0, rgb);

    /* trans map */
    tmap = vis_TransMapBegin();

    /* create edge object and set objects */
    edge = vis_EdgeBegin();
    vis_EdgeSetObject(edge, VGL_DRAWFUN, dfedge);
    vis_EdgeSetObject(edge, VIS_VISCONTEXT, vc);
    vis_EdgeSetObject(edge, VIS_COLORMAP, cmap);
    vis_EdgeSetObject(edge, VIS_GRIDFUN, gf);

    /* create face object and set objects */
    face = vis_FaceBegin();
    vis_FaceSetObject(face, VGL_DRAWFUN, df);
    vis_FaceSetObject(face, VIS_VISCONTEXT, vc);
    vis_FaceSetObject(face, VIS_COLORMAP, cmap);

    /* 1D element objects */
    /* create rigidelem object and set objects */
    rigidelem = vis_RigidElemBegin();
    vis_RigidElemSetObject(rigidelem, VGL_DRAWFUN, df);
    vis_RigidElemSetObject(rigidelem, VIS_VISCONTEXT, vc1d);
    vis_RigidElemSetObject(rigidelem, VIS_COLORMAP, cmap);

    /* create gapelem object and set objects */
    gapelem = vis_GapElemBegin();
    vis_GapElemSetObject(gapelem, VGL_DRAWFUN, df);
    vis_GapElemSetObject(gapelem, VIS_VISCONTEXT, vc1d);
    vis_GapElemSetObject(gapelem, VIS_COLORMAP, cmap);

    /* create discelem object and set objects */
    discelem = vis_DiscElemBegin();
    vis_DiscElemSetObject(discelem, VGL_DRAWFUN, df);
    vis_DiscElemSetObject(discelem, VIS_VISCONTEXT, vc1d);
    vis_DiscElemSetObject(discelem, VIS_COLORMAP, cmap);

    /* create masselem object and set objects */
    masselem = vis_MassElemBegin();
    vis_MassElemSetObject(masselem, VGL_DRAWFUN, df);
    vis_MassElemSetObject(masselem, VIS_VISCONTEXT, vc1d);
    vis_MassElemSetObject(masselem, VIS_COLORMAP, cmap);

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

    /* set properties for generation */
    prop = vsy_PropSetBegin();
    vsy_PropSetInsertp(prop, "connect", (Vobject*)connect);
    vsy_PropSetInsertp(prop, "groupnode", (Vobject*)groupnode);
    vsy_PropSetInsertp(prop, "groupedge", (Vobject*)groupedge);
    vsy_PropSetInsertp(prop, "groupface", (Vobject*)groupface);
    vsy_PropSetInsertp(prop, "groupfacesolid", (Vobject*)groupfacesolid);
    vsy_PropSetInsertp(prop, "groupfaceshell", (Vobject*)groupfaceshell);
    vsy_PropSetInsertp(prop, "groupedgebeam", (Vobject*)groupedgebeam);

    vsy_PropSetInsertp(prop, "vc", (Vobject*)vc);
    vsy_PropSetInsertp(prop, "vc1d", (Vobject*)vc1d);
    vsy_PropSetInsertp(prop, "edge", (Vobject*)edge);
    vsy_PropSetInsertp(prop, "face", (Vobject*)face);
    vsy_PropSetInsertp(prop, "rigidelem", (Vobject*)rigidelem);
    vsy_PropSetInsertp(prop, "gapelem", (Vobject*)gapelem);
    vsy_PropSetInsertp(prop, "discelem", (Vobject*)discelem);
    vsy_PropSetInsertp(prop, "masselem", (Vobject*)masselem);

    vsy_PropSetInsertp(prop, "dl", (Vobject*)dl);
    vsy_PropSetInsertp(prop, "dledge", (Vobject*)dledge);
    vsy_PropSetInsertp(prop, "dltitle", (Vobject*)dltitle);
    vsy_PropSetInsertp(prop, "df", (Vobject*)df);
    vsy_PropSetInsertp(prop, "dftitle", (Vobject*)dftitle);
    vsy_PropSetInsertp(prop, "iactor", (Vobject*)iactor);
    vsy_PropSetInserti(prop, "Exit", 0);
    vsy_PropSetInserti(prop, "soliddraw", 1);
    vsy_PropSetInserti(prop, "shelldraw", 1);
    vsy_PropSetInserti(prop, "beamdraw", 1);
    vsy_PropSetInserti(prop, "oneddraw", 1);
    vsy_PropSetInserti(prop, "elemlabel", 0);
    vsy_PropSetInserti(prop, "nodelabel", 0);
    vsy_PropSetInserti(prop, "faceedges", 0);
    vsy_PropSetInserti(prop, "facenodes", 0);
    vsy_PropSetInserti(prop, "refine", 0);
    vsy_PropSetInserti(prop, "perspective", iper);
    vsy_PropSetInserti(prop, "smooth", 0);

    /* instance Popup for display generation */
    popup = vgl_PopupBegin();

    vgl_PopupSetObject(popup, VGL_DRAWFUN, dfdev);
    vgl_PopupTitle(popup, (Vchar*)"Display Types");
    vgl_PopupAddToggle(popup, 0, (Vchar*)"Solid Elements", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupSetToggle(popup, 0, 1);
    vgl_PopupAddToggle(popup, 1, (Vchar*)"Shell Elements", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupSetToggle(popup, 1, 1);
    vgl_PopupAddToggle(popup, 2, (Vchar*)"Beam Elements", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupSetToggle(popup, 2, 1);
    vgl_PopupAddToggle(popup, 3, (Vchar*)"1D Elements", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupSetToggle(popup, 3, 1);
    vgl_PopupAddToggle(popup, 5, (Vchar*)"Elem Label", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupSetToggle(popup, 5, 0);
    vgl_PopupAddToggle(popup, 6, (Vchar*)"Node Label", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupSetToggle(popup, 6, 0);

    vgl_PopupAddLine(popup);
    vgl_PopupAddToggle(popup, 10, (Vchar*)"Face Edges", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupSetToggle(popup, 10, 0);
    vgl_PopupAddToggle(popup, 11, (Vchar*)"Face Nodes", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupSetToggle(popup, 11, 0);
    vgl_PopupAddToggle(popup, 12, (Vchar*)"Refine", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupSetToggle(popup, 12, 0);

    vgl_PopupAddLine(popup);
    vgl_PopupAddToggle(popup, 23, (Vchar*)"Perspective", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupSetToggle(popup, 23, iper);
    vgl_PopupAddToggle(popup, 24, (Vchar*)"Smooth", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupSetToggle(popup, 24, 0);
    vgl_PopupAddItem(popup, 25, (Vchar*)"Write Image", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 26, (Vchar*)"Write VRML", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 20, (Vchar*)"Fit", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 21, (Vchar*)"Fit TrackBall", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);
    vgl_PopupAddItem(popup, 22, (Vchar*)"Exit", (void (*)(vgl_Popup*, Vobject*))popup_callback, prop);

    /* draw feature edges */
    vgl_DListErase(dledge);
    vis_VisContextSetColor(vc, 7);
    vis_VisContextSetLineWidth(vc, 1);
    draw_ElemEdge(groupedge, connect, NULL, edge);

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
    vgl_IActorButtonAction(iactor, IACTOR_MIDDLEMOUSE, IACTOR_PAN);
    vgl_IActorButtonAction(iactor, IACTOR_RIGHTMOUSE, IACTOR_ZOOMCENTER);

    vgl_IActorButtonAction(iactor, IACTOR_CTRL, IACTOR_POPUP);

    vgl_IActorModifierAction(iactor, IACTOR_LEFTMOUSE, IACTOR_SHIFT, IACTOR_SQUIGGLE);
    vgl_IActorModifierAction(iactor, IACTOR_MIDDLEMOUSE, IACTOR_SHIFT, IACTOR_WINDOW);
    vgl_IActorModifierAction(iactor, IACTOR_RIGHTMOUSE, IACTOR_SHIFT, IACTOR_TRANSFORMSNAP);
    vgl_IActorSetParami(iactor, IACTOR_USEPROJ, SYS_ON);
    vgl_IActorSetParami(iactor, IACTOR_SMOOTHMOVE, SYS_OFF);

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

    /* free all objects */
    vis_ModelDelete(model);
    vis_ModelEnd(model);
    vis_GroupEnd(groupfacesolid);
    vis_GroupEnd(groupfaceshell);
    vis_GroupEnd(groupedgebeam);
    vis_GroupEnd(groupelem);
    vis_GroupEnd(groupface);
    vis_GroupEnd(groupedge);
    vis_GroupEnd(groupnode);
    vis_GridFunEnd(gf);

    vgl_OpenGLDevEnd(ogldev);
    vgl_DrawFunEnd(dfdev);
    vgl_DrawFunEnd(df);
    vgl_DrawFunEnd(dfedge);
    vgl_DrawFunEnd(dftitle);
    vgl_DrawFunEnd(dftriad);

    vgl_DListEnd(dl);
    vgl_DListEnd(dledge);
    vgl_DListEnd(dltitle);
    vgl_DListEnd(dltriad);
    vgl_XfmEnd(xfm);

    vgl_IActorEnd(iactor);

    vis_VisContextEnd(vc);
    vis_VisContextEnd(vctriad);
    vis_VisContextEnd(vc1d);
    vis_ColorMapEnd(cmap);
    vis_TransMapEnd(tmap);
    vis_EdgeEnd(edge);
    vis_FaceEnd(face);
    vis_RigidElemEnd(rigidelem);
    vis_GapElemEnd(gapelem);
    vis_DiscElemEnd(discelem);
    vis_MassElemEnd(masselem);
    vis_TriadEnd(triad);
    vsy_DictionaryEnd(dict);
    vsy_PropSetEnd(prop);
    vgl_PopupEnd(popup);
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
    vis_Group *groupfacesolid, *groupfaceshell, *groupedgebeam;
    vis_Group *groupfaceedge, *groupfacenode;

    vis_VisContext *vc, *vc1d;
    vis_Edge* edge;
    vis_Face* face;
    vis_RigidElem* rigidelem;
    vis_GapElem* gapelem;
    vis_DiscElem* discelem;
    vis_MassElem* masselem;

    vgl_DList *dl, *dledge, *dltitle;
    vgl_IActor* iactor;
    vgl_DrawFun *df, *dftitle, *dfdev;
    vgl_FBuffer* fbuffer;
    vgl_DFile* dfile;
    vgl_DrawFun* dfdfile;

    Vint ind, val;
    Vint faceedges, facenodes;
    Vint soliddraw, shelldraw, beamdraw, oneddraw;
    Vint nodelabel, elemlabel;
    Vint numel, numnp;
    Vint iref;
    Vint iper;
    Vint ismo;
    Vint iparams[2];
    Vfloat ratio;

    /* retrieve objects */
    vsy_PropSetLookupObject(prop, "connect", (Vobject**)&connect);
    vsy_PropSetLookupObject(prop, "groupnode", (Vobject**)&groupnode);
    vsy_PropSetLookupObject(prop, "groupedge", (Vobject**)&groupedge);
    vsy_PropSetLookupObject(prop, "groupface", (Vobject**)&groupface);
    vsy_PropSetLookupObject(prop, "groupfacesolid", (Vobject**)&groupfacesolid);
    vsy_PropSetLookupObject(prop, "groupfaceshell", (Vobject**)&groupfaceshell);
    vsy_PropSetLookupObject(prop, "groupedgebeam", (Vobject**)&groupedgebeam);

    vsy_PropSetLookupObject(prop, "vc", (Vobject**)&vc);
    vsy_PropSetLookupObject(prop, "vc1d", (Vobject**)&vc1d);
    vsy_PropSetLookupObject(prop, "edge", (Vobject**)&edge);
    vsy_PropSetLookupObject(prop, "face", (Vobject**)&face);
    vsy_PropSetLookupObject(prop, "rigidelem", (Vobject**)&rigidelem);
    vsy_PropSetLookupObject(prop, "gapelem", (Vobject**)&gapelem);
    vsy_PropSetLookupObject(prop, "discelem", (Vobject**)&discelem);
    vsy_PropSetLookupObject(prop, "masselem", (Vobject**)&masselem);

    vsy_PropSetLookupObject(prop, "dl", (Vobject**)&dl);
    vsy_PropSetLookupObject(prop, "dledge", (Vobject**)&dledge);
    vsy_PropSetLookupObject(prop, "dltitle", (Vobject**)&dltitle);
    vsy_PropSetLookupObject(prop, "df", (Vobject**)&df);
    vsy_PropSetLookupObject(prop, "dftitle", (Vobject**)&dftitle);
    vsy_PropSetLookupObject(prop, "iactor", (Vobject**)&iactor);
    vsy_PropSetLookupInteger(prop, "soliddraw", &soliddraw);
    vsy_PropSetLookupInteger(prop, "shelldraw", &shelldraw);
    vsy_PropSetLookupInteger(prop, "beamdraw", &beamdraw);
    vsy_PropSetLookupInteger(prop, "oneddraw", &oneddraw);
    vsy_PropSetLookupInteger(prop, "nodelabel", &nodelabel);
    vsy_PropSetLookupInteger(prop, "elemlabel", &elemlabel);
    vsy_PropSetLookupInteger(prop, "faceedges", &faceedges);
    vsy_PropSetLookupInteger(prop, "facenodes", &facenodes);
    vsy_PropSetLookupInteger(prop, "refine", &iref);
    vsy_PropSetLookupInteger(prop, "perspective", &iper);
    vsy_PropSetLookupInteger(prop, "smooth", &ismo);

    vgl_PopupGetIndex(popup, &ind);

    /* test for projection */
    if (ind == 23) {
        vgl_PopupGetToggle(popup, ind, &val);
        iper = val;
        vsy_PropSetInserti(prop, "perspective", iper);
        vgl_IActorGetObject(iactor, VGL_DRAWFUN, (Vobject**)&dfdev);
        vgl_DrawFunGetInteger(dfdev, VGL_WINDOWSIZE, iparams);
        ratio = (Vfloat)iparams[0] / (Vfloat)iparams[1];
        if (iper) {
            vgl_DrawFunProjFrustum(dfdev, -ratio, ratio, -1., 1., 4., 100.);
        }
        else {
            vgl_DrawFunProjOrtho(dfdev, -ratio, ratio, -1., 1., -1., 1.);
        }
        vgl_IActorFit(iactor, NULL);
        return;
        /* test for smooth move */
    }
    else if (ind == 24) {
        vgl_PopupGetToggle(popup, ind, &val);
        ismo = val;
        vsy_PropSetInserti(prop, "smooth", ismo);
        vgl_IActorSetParami(iactor, IACTOR_SMOOTHMOVE, ismo);
        return;
        /* test for image write */
    }
    else if (ind == 25) {
        vgl_IActorGetObject(iactor, VGL_DRAWFUN, (Vobject**)&dfdev);
        vgl_DrawFunGetInteger(dfdev, VGL_WINDOWSIZE, iparams);
        fbuffer = vgl_FBufferBegin();
        vgl_FBufferDef(fbuffer, iparams[0], iparams[1]);
        vgl_DrawFunFBufferRead(dfdev, 0, 0, 0, 0, fbuffer);
        vgl_FBufferWriteGIF(fbuffer, (Vchar*)"exam30ddev.gif");
        vgl_FBufferEnd(fbuffer);
        /* test for VRML write */
    }
    else if (ind == 26) {
        /* instance DFile and associated drawing function */
        dfile = vgl_DFileBegin();
        dfdfile = vgl_DrawFunBegin();
        vgl_DFileDrawFun(dfile, dfdfile);
        /* set drawing function to DFile into display lists */
        vgl_DListSetObject(dledge, VGL_DRAWFUN, dfdfile);
        vgl_DListSetObject(dl, VGL_DRAWFUN, dfdfile);
        /* set VRML format and file name */
        vgl_DFileSetFileType(dfile, DFILE_VRML);
        vgl_DFileSetFileName(dfile, (Vchar*)"exam30ddev.wrl");
        /* open file, draw and close */
        vgl_DFileOpen(dfile);
        vgl_DListCall(dledge);
        vgl_DListCall(dl);
        vgl_DFileClose(dfile);
        /* restore device drawing functions to display lists */
        vgl_IActorGetObject(iactor, VGL_DRAWFUN, (Vobject**)&dfdev);
        vgl_DListSetObject(dledge, VGL_DRAWFUN, dfdev);
        vgl_DListSetObject(dl, VGL_DRAWFUN, dfdev);
        /* delete DFile and associated drawing function */
        vgl_DFileEnd(dfile);
        vgl_DrawFunEnd(dfdfile);
        /* test for fit or exit */
    }
    else if (ind == 20) {
        vgl_IActorFit(iactor, NULL);
        return;
    }
    else if (ind == 21) {
        vgl_IActorFitTrackBall(iactor, NULL);
        return;
    }
    else if (ind == 22) {
        vsy_PropSetInserti(prop, "Exit", 1);
        vgl_IActorAbort(iactor, NULL);
        return;
    }

    if (ind == 0) {
        vgl_PopupGetToggle(popup, ind, &val);
        soliddraw = val;
        vsy_PropSetInserti(prop, "soliddraw", soliddraw);
    }
    else if (ind == 1) {
        vgl_PopupGetToggle(popup, ind, &val);
        shelldraw = val;
        vsy_PropSetInserti(prop, "shelldraw", shelldraw);
    }
    else if (ind == 2) {
        vgl_PopupGetToggle(popup, ind, &val);
        beamdraw = val;
        vsy_PropSetInserti(prop, "beamdraw", beamdraw);
    }
    else if (ind == 3) {
        vgl_PopupGetToggle(popup, ind, &val);
        oneddraw = val;
        vsy_PropSetInserti(prop, "oneddraw", oneddraw);
    }
    else if (ind == 5) {
        vgl_PopupGetToggle(popup, ind, &val);
        elemlabel = val;
        vsy_PropSetInserti(prop, "elemlabel", elemlabel);
    }
    else if (ind == 6) {
        vgl_PopupGetToggle(popup, ind, &val);
        nodelabel = val;
        vsy_PropSetInserti(prop, "nodelabel", nodelabel);
    }
    else if (ind == 10) {
        vgl_PopupGetToggle(popup, ind, &val);
        faceedges = val;
        vsy_PropSetInserti(prop, "faceedges", faceedges);
    }
    else if (ind == 11) {
        vgl_PopupGetToggle(popup, ind, &val);
        facenodes = val;
        vsy_PropSetInserti(prop, "facenodes", facenodes);
    }
    else if (ind == 12) {
        vgl_PopupGetToggle(popup, ind, &val);
        iref = val;
        vsy_PropSetInserti(prop, "refine", iref);
    }
    /* erase model display list */
    vgl_DListErase(dl);

    /* set refinement */
    vis_VisContextSetRefinement(vc, iref);
    /* draw edges first */
    if (faceedges) {
        vis_ConnectNumber(connect, SYS_ELEM, &numel);
        groupfaceedge = vis_GroupBegin();
        vis_GroupDef(groupfaceedge, numel, SYS_ELEM, SYS_EDGE);
        vis_ConnectEdgeGroup(connect, CONNECT_UNIQUE, groupface, groupfaceedge);
        vis_VisContextSetColor(vc, 7);
        draw_ElemEdge(groupfaceedge, connect, NULL, edge);
        vis_GroupEnd(groupfaceedge);
    }
    if (facenodes) {
        vis_ConnectNumber(connect, SYS_NODE, &numnp);
        groupfacenode = vis_GroupBegin();
        vis_GroupDef(groupfacenode, numnp, SYS_NODE, SYS_NONE);
        vis_ConnectNodeGroup(connect, CONNECT_UNIQUE, groupface, groupfacenode);
        vis_VisContextSetColor(vc, 7);
        draw_NodePoint(groupfacenode, connect, NULL, df);
        vis_GroupEnd(groupfacenode);
    }
    if (soliddraw) {
        vis_VisContextSetColor(vc, 2);
        draw_ElemFace(groupfacesolid, connect, NULL, face);
    }
    if (shelldraw) {
        vis_VisContextSetColor(vc, 3);
        draw_ElemFace(groupfaceshell, connect, NULL, face);
    }
    if (beamdraw) {
        vis_VisContextSetColor(vc, 4);
        draw_ElemEdge(groupedgebeam, connect, NULL, edge);
    }
    if (oneddraw) {
        draw_1DElem(NULL, connect, NULL, vc1d, rigidelem, gapelem, discelem, masselem);
    }
    if (elemlabel) {
        draw_ElemLabel(NULL, connect, NULL, df);
    }
    if (nodelabel) {
        draw_NodeLabel(NULL, connect, NULL, df);
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
    vgl_DList *dl, *dledge, *dltitle, *dltriad;
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
    vgl_DrawFunViewport(df, 0, xsize, ysize - 50, ysize);
    vgl_DrawFunProjOrtho(df, -1., 1., -1., 1., -1., 1.);
    vgl_DrawFunXfmPush(df);
    vgl_XfmIdentity(xfm);
    vgl_XfmGetMatrix(xfm, tm);
    vgl_DrawFunXfmLoad(df, tm);
    vgl_DListCall(dltitle);
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
                      Draw Rigid, Mass Elements
----------------------------------------------------------------------*/
void
draw_1DElem(vis_Group* group, vis_Connect* connect, vis_State* stated, vis_VisContext* vc1d, vis_RigidElem* rigidelem,
            vis_GapElem* gapelem, vis_DiscElem* discelem, vis_MassElem* masselem)
{
    Vint numel;
    Vint n;
    Vint nix, maxelno;
    Vint* ix;
    Vfloat(*x)[3];
    Vfloat xa[3], xb[3];
    Vint featype, feaspec;
    Vint shape, maxi, maxj, maxk;
    Vint endatopo, endbtopo, endacon, endbcon, acon, bcon;

    /* get number of elements */
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    /* get maximum number of element nodes */
    vis_ConnectMaxElemNode(connect, &maxelno);
    ix = (Vint*)malloc(maxelno * sizeof(Vint));
    x = (Vfloat(*)[3])malloc(3 * maxelno * sizeof(Vfloat));

    /* loop through elements */
    for (n = 1; n <= numel; n++) {
        if (vis_GroupElem(group, n) == 0)
            continue;
        vis_ConnectElemAssoc(connect, VIS_FEATYPE, 1, &n, &featype);
        /* draw only "discrete" elements */
        if (featype != SYS_ELEM_RIGID && featype != SYS_ELEM_GAP && featype != SYS_ELEM_SPRINGDASHPOT && featype != SYS_ELEM_MASS)
            continue;
        vis_ConnectElemAssoc(connect, VIS_FEASPEC, 1, &n, &feaspec);
        vis_ConnectElemAssoc(connect, VIS_ENDATOPO, 1, &n, &endatopo);
        vis_ConnectElemAssoc(connect, VIS_ENDBTOPO, 1, &n, &endbtopo);
        vis_ConnectElemAssoc(connect, VIS_ENDACON, 1, &n, &endacon);
        if (endacon > 0) {
            acon = SYS_ELEMEND_POSITION;
            vis_ConnectCoords(connect, 1, &endacon, (Vfloat(*)[3])xa);
        }
        else {
            acon = 0;
        }
        vis_ConnectElemAssoc(connect, VIS_ENDBCON, 1, &n, &endbcon);
        if (endbcon > 0) {
            bcon = SYS_ELEMEND_POSITION;
            vis_ConnectCoords(connect, 1, &endbcon, (Vfloat(*)[3])xb);
        }
        else {
            bcon = 0;
        }
        vis_ConnectTopology(connect, n, &shape, &maxi, &maxj, &maxk);
        vis_ConnectElemNode(connect, n, &nix, ix);

        if (stated != NULL) {
            vis_StateData(stated, nix, ix, (Vfloat*)x);
        }
        else {
            vis_ConnectCoords(connect, nix, ix, x);
        }
        /* draw rigid elem in red */
        if (featype == SYS_ELEM_RIGID) {
            vis_VisContextSetColor(vc1d, 1);
            vis_RigidElemSetSpec(rigidelem, feaspec);
            vis_RigidElemSetTopology(rigidelem, shape, maxi);
            vis_RigidElemCurv(rigidelem, x);
            /* draw gap elem in yellow */
        }
        else if (featype == SYS_ELEM_GAP) {
            vis_VisContextSetColor(vc1d, 6);
            vis_GapElemSetSpec(gapelem, feaspec);
            vis_GapElemSetTopology(gapelem, shape, maxi);
            vis_GapElemCurv(gapelem, x);
            /* draw spring/dashpot elem in red */
        }
        else if (featype == SYS_ELEM_SPRINGDASHPOT) {
            vis_VisContextSetColor(vc1d, 8);
            vis_DiscElemSetSpec(discelem, feaspec);
            vis_DiscElemSetTopology(discelem, shape, maxi);
            vis_DiscElemSetEndTopo(discelem, endatopo, endbtopo);
            vis_DiscElemSetEndCon(discelem, acon, xa, bcon, xb);
            vis_DiscElemCurv(discelem, x);
            /* draw mass elem in magenta */
        }
        else if (featype == SYS_ELEM_MASS) {
            vis_VisContextSetColor(vc1d, 5);
            vis_MassElemSetSpec(masselem, feaspec);
            vis_MassElemSetTopology(masselem, shape, maxi);
            vis_MassElemCurv(masselem, x);
        }
    }
    free(ix);
    free(x);
}

/*----------------------------------------------------------------------
                      Draw Element Edges
----------------------------------------------------------------------*/
void
draw_ElemEdge(vis_Group* group, vis_Connect* connect, vis_State* stated, vis_Edge* edge)
{
    Vint numel;
    Vint n, j;
    Vint nedges;
    Vint shape, maxi, maxj;
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
                      Draw Element Face
----------------------------------------------------------------------*/
void
draw_ElemFace(vis_Group* group, vis_Connect* connect, vis_State* stated, vis_Face* face)
{
    Vint numel;
    Vint n, j;
    Vint nfaces;
    Vint shape, maxi, maxj;
    Vint nix;
    Vint ix[VIS_MAXELEMNODE];
    Vfloat x[VIS_MAXELEMNODE][3];

    /* get number of elements */
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    /* draw element faces */
    /* loop through elements */
    for (n = 1; n <= numel; n++) {
        if (vis_GroupElem(group, n) == 0)
            continue;
        vis_ConnectElemNum(connect, SYS_FACE, n, &nfaces);
        /* loop through element faces */
        for (j = 1; j <= nfaces; j++) {
            if (vis_GroupElemEnt(group, n, j) == 0)
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
                      Draw Node Points
----------------------------------------------------------------------*/
void
draw_NodePoint(vis_Group* group, vis_Connect* connect, vis_State* stated, vgl_DrawFun* df)
{
    Vint numnp;
    Vint n;
    Vfloat c[3];
    Vfloat x[3];
    /* get number of nodes */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    /* loop through nodes */
    c[0] = 0., c[1] = 1., c[2] = 1.;
    vgl_DrawFunColor(df, c);
    vgl_DrawFunPointSize(df, 4);
    for (n = 1; n <= numnp; n++) {
        if (vis_GroupNode(group, n) == 0)
            continue;
        if (stated != NULL) {
            vis_StateData(stated, 1, &n, x);
        }
        else {
            vis_ConnectCoords(connect, 1, &n, (Vfloat(*)[3])x);
        }
        vgl_DrawFunPolyPoint(df, 1, (Vfloat(*)[3])x);
    }
}

/*----------------------------------------------------------------------
                      Draw Elem Labels
----------------------------------------------------------------------*/
void
draw_ElemLabel(vis_Group* group, vis_Connect* connect, vis_State* stated, vgl_DrawFun* df)
{
    Vint numel;
    Vint i, n;
    Vint id;
    Vchar stg[16];
    Vfloat c[3];
    Vint nix, maxelno;
    Vint* ix;
    Vfloat(*x)[3];
    Vfloat xc[3];
    /* labels at elements */
    /* get number of elem */
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    /* get maximum number of element nodes */
    vis_ConnectMaxElemNode(connect, &maxelno);
    ix = (Vint*)malloc(maxelno * sizeof(Vint));
    x = (Vfloat(*)[3])malloc(3 * maxelno * sizeof(Vfloat));
    /* set color to magenta */
    c[0] = 1., c[1] = 0., c[2] = 1.;
    vgl_DrawFunColor(df, c);

    /* loop through elements */
    for (n = 1; n <= numel; n++) {
        if (vis_GroupElem(group, n) == 0)
            continue;
        vis_ConnectElemNode(connect, n, &nix, ix);
        if (stated != NULL) {
            vis_StateData(stated, nix, ix, (Vfloat*)x);
        }
        else {
            vis_ConnectCoords(connect, nix, ix, x);
        }
        vis_ConnectElemAssoc(connect, VIS_USERID, 1, &n, &id);
        /* average node locations to get element centroid */
        xc[0] = 0.;
        xc[1] = 0.;
        xc[2] = 0.;
        for (i = 0; i < nix; i++) {
            xc[0] += x[i][0];
            xc[1] += x[i][1];
            xc[2] += x[i][2];
        }
        xc[0] /= nix;
        xc[1] /= nix;
        xc[2] /= nix;
        sprintf(stg, "%d", id);
        vgl_DrawFunText(df, xc, stg);
    }
    free(ix);
    free(x);
}

/*----------------------------------------------------------------------
                      Draw Node Labels
----------------------------------------------------------------------*/
void
draw_NodeLabel(vis_Group* group, vis_Connect* connect, vis_State* stated, vgl_DrawFun* df)
{
    Vint numnp;
    Vint n;
    Vint id;
    Vchar stg[16];
    Vfloat c[3];
    Vfloat x[3];
    Vint dc[3];
    /* labels at nodes */
    /* get number of nodes */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    /* set color to yellow */
    c[0] = 1., c[1] = 1., c[2] = 0.;
    vgl_DrawFunColor(df, c);
    /* offset labels a few pixels away from node */
    dc[0] = 3, dc[1] = 2, dc[2] = 0;

    /* loop through nodes */
    for (n = 1; n <= numnp; n++) {
        if (vis_GroupNode(group, n) == 0)
            continue;
        if (stated != NULL) {
            vis_StateData(stated, 1, &n, x);
        }
        else {
            vis_ConnectCoords(connect, 1, &n, (Vfloat(*)[3])x);
        }
        vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &n, &id);
        sprintf(stg, "%d", id);
        vgl_DrawFunTextDC(df, x, dc, stg);
    }
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
    vgl_DrawFunTextDC(df, x, dc, (Vchar*)"VisTools Element Viewer");
    dc[0] = 10;
    dc[1] = -10;
    dc[2] = 0;
    vgl_DrawFunTextDC(df, x, dc, title);
}
