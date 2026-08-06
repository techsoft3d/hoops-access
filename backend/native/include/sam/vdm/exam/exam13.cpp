#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/vdm/datafile.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                     Save Model Using MemLib
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[256];
    vdm_DataFun* datafun = NULL;
    vdm_LMan* lman = NULL;
    vdm_MemLib* memlib = NULL;
    vdm_Library* library = NULL;
    vis_RProp* rprop = NULL;
    vis_Model* model = NULL;
    vis_State* state = NULL;
    vis_GridFun* gridfun = NULL;
    vis_Connect* connect = NULL;
    Vint filetype, idst, ndst, hasstate;
    Vlong nbytes;
    Vchar *bytesmodel = NULL, *bytesdisp = NULL;
    Vint ierr;

    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile [result_dataset]\n", argv[0]);
        fprintf(stderr, " inputfile is blank, 'cantilever.unv' is assumed\n");
        strcpy(inputfile, "cantilever.unv");
    }
    else {
        strcpy(inputfile, argv[1]);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create data function object */
    datafun = vdm_DataFunBegin();

    datafiletype(inputfile, &filetype);
    if (filetype == 0) {
        fprintf(stderr, "Error: Bad input file %s\n", inputfile);
        exit(1);
    }
    datafileinit(filetype, datafun);
    /* open library device */
    vdm_DataFunOpen(datafun, 0, inputfile, filetype);
    /* check for error */
    ierr = vdm_DataFunError(datafun);
    if (ierr) {
        fprintf(stderr, "Error: opening file %s\n", inputfile);
        exit(0);
    }
    /* load model */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, (Vobject*)datafun);
    model = vis_ModelBegin();
    vdm_LManLoadModel(lman, model);
    vdm_LManTOC(lman, "*");

    /* load result if it exists */
    hasstate = 0;
    if (argc >= 3) {
        vdm_DataFunGetLibrary(datafun, &library);
        vdm_LibrarySearchDataset(library, argv[2], 1, &idst, &ndst);
        if (ndst) {
            hasstate = 1;
            rprop = vis_RPropBegin();
            vis_RPropDef(rprop, SYS_NODE, SYS_NONE);
            vis_RPropSetDatasetName(rprop, argv[2]);
            state = vis_StateBegin();
            gridfun = vis_GridFunBegin();
            vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
            vis_ConnectGridFun(connect, gridfun);
            vis_StateSetObject(state, VIS_GRIDFUN, (Vobject*)gridfun);
            vdm_LManLoadState(lman, state, rprop);
        }
    }
    /* close and clean-up input file */
    vdm_DataFunClose(datafun);
    datafileterm(filetype, datafun);
    vdm_DataFunEnd(datafun);
    vdm_LManEnd(lman);

    /* save model in first MemLib DataFun */
    datafun = vdm_DataFunBegin();
    memlib = vdm_MemLibBegin();
    vdm_MemLibDataFun(memlib, datafun);
    vdm_DataFunSetStatus(datafun, VDM_STATUS_NEW);
    vdm_DataFunOpen(datafun, 0, NULL, VDM_MEMORY);
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, (Vobject*)datafun);
    vdm_LManSaveModel(lman, model);
    vdm_LManEnd(lman);

    /* determine size and save model data in memory */
    vdm_MemLibStreamNum(memlib, &nbytes);
    printf("nbytes with model= %lld\n", nbytes);
    bytesmodel = (Vchar*)malloc(nbytes);
    vdm_MemLibStream(memlib, bytesmodel);
    vdm_DataFunClose(datafun);
    vdm_DataFunEnd(datafun);
    vdm_MemLibEnd(memlib);

    /* save result in second MemLib DataFun */
    if (hasstate) {
        datafun = vdm_DataFunBegin();
        memlib = vdm_MemLibBegin();
        vdm_MemLibDataFun(memlib, datafun);
        vdm_DataFunSetStatus(datafun, VDM_STATUS_NEW);
        vdm_DataFunOpen(datafun, 0, NULL, VDM_MEMORY);
        lman = vdm_LManBegin();
        vdm_LManSetObject(lman, VDM_DATAFUN, (Vobject*)datafun);
        vdm_LManSaveState(lman, state, rprop);
        vdm_LManEnd(lman);
        vis_RPropEnd(rprop);
        vis_StateEnd(state);
        vis_GridFunEnd(gridfun);
    }
    vis_ModelDelete(model);
    vis_ModelEnd(model);

    /* determine size and save result in memory */
    if (hasstate) {
        vdm_MemLibStreamNum(memlib, &nbytes);
        printf("nbytes with result= %lld\n", nbytes);
        bytesdisp = (Vchar*)malloc(nbytes);
        vdm_MemLibStream(memlib, bytesdisp);
        vdm_DataFunClose(datafun);
        vdm_DataFunEnd(datafun);
        vdm_MemLibEnd(memlib);
    }
    /* re-load model */
    datafun = vdm_DataFunBegin();
    memlib = vdm_MemLibBegin();
    vdm_MemLibDataFun(memlib, datafun);
    vdm_DataFunSetStatus(datafun, VDM_STATUS_OLD);
    vdm_DataFunOpen(datafun, 0, bytesmodel, VDM_MEMORY);

    /* append state onto model */
    if (hasstate) {
        vdm_DataFunAppend(datafun, bytesdisp, SYS_MEMORY);
    }

    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, (Vobject*)datafun);
    vdm_LManTOC(lman, "*");
    vdm_MemLibEnd(memlib);
    vdm_DataFunEnd(datafun);
    vdm_LManEnd(lman);
    free(bytesmodel);
    if (hasstate) {
        free(bytesdisp);
    }

    return 0;
}
