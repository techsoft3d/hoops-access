#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

typedef struct {
    vdm_DataFun* datafun;
    Vchar inputfile[SYS_MAXPATHCHAR];
    Vint filetype;
    Vint isopened;
    vsy_PTask* ptask;
} UserData;

static void
monitor_checkphase(UserData* userdata)
{
    vdm_Library* library;
    Vint phase;

    vdm_DataFunGetInteger(userdata->datafun, VDM_PHASE, &phase);
    if (phase == VDM_PHASE_OPENMODEL) {
        printf("Opening model\n");
    }
    else if (phase == VDM_PHASE_OPENMODELCOMPLETE) {
        /* display partial TOC with model information only */
        /* unlock when open model is complete */
        vdm_DataFunGetLibrary(userdata->datafun, &library);
        printf("TOC when model is complete:\n");
        vdm_LibraryTOC(library, "*", 0);
        userdata->isopened = 1;
        vsy_PTaskUnlock(userdata->ptask);
    }
    else if (phase == VDM_PHASE_OPENRESULT) {
        printf("Processing results...\n");
    }
}

static void
nasfil_monitor(vdm_NASFil* nasfil, UserData* userdata)
{
    monitor_checkphase(userdata);
}

static void
naslib_monitor(vdm_NASLib* naslib, UserData* userdata)
{
    monitor_checkphase(userdata);
}

static void
anslib_monitor(vdm_ANSLib* anslib, UserData* userdata)
{
    monitor_checkphase(userdata);
}

static void
d3dlib_monitor(vdm_D3DLib* d3dlib, UserData* userdata)
{
    monitor_checkphase(userdata);
}

static void
sdrclib_monitor(vdm_SDRCLib* sdrclib, UserData* userdata)
{
    monitor_checkphase(userdata);
}

static void
fluentlib_monitor(vdm_FLUENTLib* fluentlib, UserData* userdata)
{
    monitor_checkphase(userdata);
}

static void
thread_function(Vobject* obj)
{
    UserData* userdata = (UserData*)obj;
    vis_Model* model;
    vis_Connect* connect;
    vdm_LMan* lman;
    Vint numnp, numel;
    Vint ierr;

    /* first thread to get to this point will open the file */
    vsy_PTaskLock(userdata->ptask);
    if (userdata->isopened == 0) {
        vdm_DataFunOpen(userdata->datafun, 0, userdata->inputfile, userdata->filetype);
        ierr = vdm_DataFunError(userdata->datafun);
        if (ierr) {
            userdata->isopened = -1;
            vsy_PTaskUnlock(userdata->ptask);
        }
    }
    else if (userdata->isopened == 1) {
        printf("Open model complete, load model\n");
        model = vis_ModelBegin();
        lman = vdm_LManBegin();
        vdm_LManSetObject(lman, VDM_DATAFUN, userdata->datafun);
        vdm_LManLoadModel(lman, model);
        /* print number of nodes and elements */
        vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
        vis_ConnectNumber(connect, SYS_NODE, &numnp);
        vis_ConnectNumber(connect, SYS_ELEM, &numel);
        printf("Number of nodes= %d\n", numnp);
        printf("Number of elems= %d\n", numel);
        vis_ModelDelete(model);
        vis_ModelEnd(model);
        vdm_LManEnd(lman);
    }
}

/*----------------------------------------------------------------------
                      Using a Monitor Function and Threading
                      to obtain Model information before DataFunOpen ends
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[256];
    vdm_ANSLib* anslib = NULL;
    vdm_D3DLib* d3dlib = NULL;
    vdm_NASFil* nasfil = NULL;
    vdm_NASLib* naslib = NULL;
    vdm_SDRCLib* sdrclib = NULL;
    vdm_FLUENTLib* fluentlib = NULL;
    vdm_DataFun* datafun = NULL;
    vdm_Library* library = NULL;
    vsy_PTask* ptask = NULL;
    UserData userdata;
    Vint filetype;
    Vobject* objs[2];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        fprintf(stderr, " inputfile is blank, 'bumper.unv' is assumed\n");
        strcpy(inputfile, "bumper.unv");
    }
    else {
        strcpy(inputfile, argv[1]);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create data function object */
    datafun = vdm_DataFunBegin();

    /* determine file type from file extension */
    if (strstr(inputfile, ".bdf") != NULL || strstr(inputfile, ".dat") != NULL) {
        filetype = VDM_NASTRAN_BULKDATA;
        nasfil = vdm_NASFilBegin();
        vdm_NASFilSetFunction(nasfil, SYS_FUNCTION_MONITOR, (Vfunc*)nasfil_monitor, &userdata);
        vdm_NASFilDataFun(nasfil, datafun);
        printf("Nastran Bulk Data File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".op2") != NULL) {
        filetype = VDM_NASTRAN_OUTPUT2;
        naslib = vdm_NASLibBegin();
        vdm_NASLibSetFunction(naslib, SYS_FUNCTION_MONITOR, (Vfunc*)naslib_monitor, &userdata);
        vdm_NASLibDataFun(naslib, datafun);
        printf("Nastran Output2 File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".rst") != NULL) {
        filetype = VDM_ANSYS_RESULT;
        anslib = vdm_ANSLibBegin();
        vdm_ANSLibSetFunction(anslib, SYS_FUNCTION_MONITOR, (Vfunc*)anslib_monitor, &userdata);
        vdm_ANSLibDataFun(anslib, datafun);
        printf("ANSYS .rst File: %s\n", inputfile);
    }
    else if (strstr(inputfile, "d3plot") != NULL) {
        filetype = VDM_LSTC_STATE;
        d3dlib = vdm_D3DLibBegin();
        vdm_D3DLibSetFunction(d3dlib, SYS_FUNCTION_MONITOR, (Vfunc*)d3dlib_monitor, &userdata);
        vdm_D3DLibDataFun(d3dlib, datafun);
        printf("DYNA3D d3plot File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".unv") != NULL) {
        filetype = VDM_SDRC_UNIVERSAL;
        sdrclib = vdm_SDRCLibBegin();
        vdm_SDRCLibSetFunction(sdrclib, SYS_FUNCTION_MONITOR, (Vfunc*)sdrclib_monitor, &userdata);
        vdm_SDRCLibDataFun(sdrclib, datafun);
        printf("SDRC Universal File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".cas") != NULL || strstr(inputfile, ".msh") != NULL) {
        filetype = VDM_FLUENT_MESH;
        fluentlib = vdm_FLUENTLibBegin();
        vdm_FLUENTLibSetFunction(fluentlib, SYS_FUNCTION_MONITOR, (Vfunc*)fluentlib_monitor, &userdata);
        vdm_FLUENTLibDataFun(fluentlib, datafun);
        printf("Fluent Mesh File: %s\n", inputfile);
    }
    else {
        fprintf(stderr, "Error: Bad input file %s\n", inputfile);
        exit(1);
    }

    /* start 2 threads */
    ptask = vsy_PTaskBegin();

    /* populate user data */
    userdata.datafun = datafun;
    userdata.ptask = ptask;
    userdata.filetype = filetype;
    userdata.isopened = 0;
    strcpy(userdata.inputfile, inputfile);
    objs[0] = &userdata;
    objs[1] = &userdata;
    vsy_PTaskDef(ptask, 2, PTASK_EXEC);

    /* execute threads */
    vsy_PTaskExec(ptask, 2, thread_function, objs);
    vdm_DataFunGetLibrary(datafun, &library);
    printf("TOC when DataFunOpen is complete:\n");
    vdm_LibraryTOC(library, "*", 0);

    vsy_PTaskEnd(ptask);

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
    else if (filetype == VDM_LSTC_STATE) {
        vdm_D3DLibEnd(d3dlib);
    }
    else if (filetype == VDM_SDRC_UNIVERSAL) {
        vdm_SDRCLibEnd(sdrclib);
    }
    else if (filetype == VDM_FLUENT_MESH) {
        vdm_FLUENTLibEnd(fluentlib);
    }
    return 0;
}
