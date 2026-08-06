#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
monitor_loadmodel(vdm_DataFun* datafun)
{
    Vint phase;
    vis_Model* model;
    vis_Connect* connect;
    vdm_LMan* lman;
    Vchar source[VDM_SOURCE_SIZE];
    Vint numnp, numel;

    vdm_DataFunGetInteger(datafun, VDM_PHASE, &phase);
    vdm_DataFunGetString(datafun, VDM_SOURCE, source);
    printf("phase= %d\n", phase);
    printf("source= %s\n", source);
    /* load model when open model is complete */
    if (phase == VDM_PHASE_OPENMODEL) {
        printf("Opening model\n");
    }
    else if (phase == VDM_PHASE_OPENMODELCOMPLETE) {
        printf("Open model complete, load model\n");
        model = vis_ModelBegin();
        lman = vdm_LManBegin();
        vdm_LManSetObject(lman, VDM_DATAFUN, datafun);
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
    else if (phase == VDM_PHASE_OPENRESULT) {
        printf("Opening results\n");
    }
}

static void
nasfil_monitor(vdm_NASFil* nasfil, vdm_DataFun* datafun)
{
    monitor_loadmodel(datafun);
}

static void
naslib_monitor(vdm_NASLib* naslib, vdm_DataFun* datafun)
{
    monitor_loadmodel(datafun);
}

static void
sdrclib_monitor(vdm_SDRCLib* sdrclib, vdm_DataFun* datafun)
{
    monitor_loadmodel(datafun);
}

static void
fluentlib_monitor(vdm_FLUENTLib* fluentlib, vdm_DataFun* datafun)
{
    monitor_loadmodel(datafun);
}

/*----------------------------------------------------------------------
                      Using a Monitor Function
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[256];
    vdm_NASFil* nasfil = NULL;
    vdm_NASLib* naslib = NULL;
    vdm_SDRCLib* sdrclib = NULL;
    vdm_FLUENTLib* fluentlib = NULL;
    vdm_DataFun* datafun = NULL;
    Vint filetype;

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
        vdm_NASFilSetFunction(nasfil, SYS_FUNCTION_MONITOR, (Vfunc*)nasfil_monitor, datafun);
        vdm_NASFilDataFun(nasfil, datafun);
        printf("Nastran Bulk Data File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".op2") != NULL) {
        filetype = VDM_NASTRAN_OUTPUT2;
        naslib = vdm_NASLibBegin();
        vdm_NASLibSetFunction(naslib, SYS_FUNCTION_MONITOR, (Vfunc*)naslib_monitor, datafun);
        vdm_NASLibDataFun(naslib, datafun);
        printf("Nastran Output2 File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".unv") != NULL) {
        filetype = VDM_SDRC_UNIVERSAL;
        sdrclib = vdm_SDRCLibBegin();
        vdm_SDRCLibSetFunction(sdrclib, SYS_FUNCTION_MONITOR, (Vfunc*)sdrclib_monitor, datafun);
        vdm_SDRCLibDataFun(sdrclib, datafun);
        printf("SDRC Universal File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".cas") != NULL || strstr(inputfile, ".msh") != NULL) {
        filetype = VDM_FLUENT_MESH;
        fluentlib = vdm_FLUENTLibBegin();
        vdm_FLUENTLibSetFunction(fluentlib, SYS_FUNCTION_MONITOR, (Vfunc*)fluentlib_monitor, datafun);
        vdm_FLUENTLibDataFun(fluentlib, datafun);
        printf("Fluent Mesh File: %s\n", inputfile);
    }
    else {
        fprintf(stderr, "Error: Bad input file %s\n", inputfile);
        exit(1);
    }
    /* open library device */
    vdm_DataFunOpen(datafun, 0, inputfile, filetype);

    /* close library device and delete interface */
    vdm_DataFunClose(datafun);
    vdm_DataFunEnd(datafun);
    if (filetype == VDM_NASTRAN_BULKDATA) {
        vdm_NASFilEnd(nasfil);
    }
    else if (filetype == VDM_NASTRAN_OUTPUT2) {
        vdm_NASLibEnd(naslib);
    }
    else if (filetype == VDM_SDRC_UNIVERSAL) {
        vdm_SDRCLibEnd(sdrclib);
    }
    else if (filetype == VDM_FLUENT_MESH) {
        vdm_FLUENTLibEnd(fluentlib);
    }
    return 0;
}
