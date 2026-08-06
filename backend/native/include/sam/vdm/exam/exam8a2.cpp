#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vint magic = 1234;

/* read and write functions for client */
static void
exam8readc(vsy_VSocket* vsocket, Vint num, Vchar* buf)
{
    vsy_VSocketRead(vsocket, 0, num, buf);
}

static void
exam8writec(vsy_VSocket* vsocket, Vint num, Vchar* buf)
{
    vsy_VSocketWrite(vsocket, 0, num, buf);
}
/* 4-byte swapping function */
static void
exam8swap4(Vchar* num)
{
    Vchar c;

    c = num[0];
    num[0] = num[3];
    num[3] = c;
    c = num[1];
    num[1] = num[2];
    num[2] = c;
}

/*----------------------------------------------------------------------
                       Save a VDM_NATIVE file remotely
----------------------------------------------------------------------*/
int
main(int argc, char* argv[])
{
    vdm_LMan* lman;
    vdm_DataFun* datafun;
    vdm_DataIPC* dataipc;
    vsy_VSocket* vsocket;
    Vchar hostname[256];
    Vint flag, swap, imagic, filetype;
    vdm_NASLib* naslib;
    vdm_NASFil* nasfil;
    vdm_SDRCLib* sdrclib;
    vis_Model* model;
    vdm_Library* library;
    vis_RProp* rprop = NULL;
    vis_State* state = NULL;
    Vint ndst, idst;
    Vchar filename[256];

    vsy_LicenseValidate(HOOPS_LICENSE);

    if (argc == 1) {
        fprintf(stderr, "Usage: %s pathname\n", argv[0]);
        fprintf(stderr, " cantilever.unv is assumed\n");
        strcpy(filename, "cantilever.unv");
    }
    else {
        strcpy(filename, argv[1]);
    }
    printf("This example requires that exam8a1 also be running\n");

    datafun = vdm_DataFunBegin();
    if (strstr(filename, ".op2")) {
        filetype = SYS_NASTRAN_OUTPUT2;
        naslib = vdm_NASLibBegin();
        vdm_NASLibDataFun(naslib, datafun);
    }
    else if (strstr(filename, ".dat")) {
        filetype = SYS_NASTRAN_BULKDATA;
        nasfil = vdm_NASFilBegin();
        vdm_NASFilDataFun(nasfil, datafun);
    }
    else if (strstr(filename, ".unv")) {
        filetype = SYS_SDRC_UNIVERSAL;
        sdrclib = vdm_SDRCLibBegin();
        vdm_SDRCLibDataFun(sdrclib, datafun);
    }
    else {
        fprintf(stderr, "Unsupported file type\n");
        return 1;
    }
    /* Load model */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, (Vobject*)datafun);
    vdm_DataFunOpen(datafun, 0, filename, filetype);
    if (vdm_DataFunError(datafun)) {
        printf("Cannot open file %s\n", filename);
        return 1;
    }
    model = vis_ModelBegin();
    vdm_LManLoadModel(lman, model);
    vdm_DataFunGetLibrary(datafun, &library);
    vdm_LibrarySearchDataset(library, "D.N:1", 1, &ndst, &idst);
    if (ndst) {
        rprop = vis_RPropBegin();
        vis_RPropSetDatasetName(rprop, (Vchar*)"D.N:1");
        state = vis_StateBegin();
        vdm_LManLoadState(lman, state, rprop);
    }

    vdm_DataFunClose(datafun);
    vdm_DataFunEnd(datafun);
    vdm_LManEnd(lman);

    /* Get info about this host */
    vut_MachInfoHostName(&flag, hostname);
    if (flag == 0) {
        printf("Unable to retrieve host name\n");
        return 1;
    }
    /* Instance and set up VSocket */
    vsocket = vsy_VSocketBegin();
    vsy_VSocketSetParami(vsocket, VSOCKET_WAITTIME, 1000);
    vsy_VSocketDef(vsocket, VSOCKET_CLIENT, VSOCKET_NET);
    vsy_VSocketSetNet(vsocket, 10000, hostname);
    vsy_VSocketOpen(vsocket);
    if (vsy_VSocketError(vsocket)) {
        vsy_VSocketEnd(vsocket);
        return 1;
    }
    /* send magic number */
    vsy_VSocketWrite(vsocket, 0, sizeof(Vint), (Vchar*)&magic);

    /* receive magic number */
    swap = 0;
    vsy_VSocketRead(vsocket, 0, sizeof(Vint), (Vchar*)&imagic);
    if (imagic != magic) {
        exam8swap4((Vchar*)&imagic);
        if (imagic != magic) {
            vsy_VSocketClose(vsocket, 0);
            return 1;
        }
        else {
            swap = 1;
        }
    }
    /* create data function object */
    datafun = vdm_DataFunBegin();
    dataipc = vdm_DataIPCBegin();
    vdm_DataIPCSetSwap(dataipc, swap);
    vdm_DataIPCDef(dataipc, DATAIPC_CLIENT);
    vdm_DataIPCDataFun(dataipc, datafun);

    vdm_DataIPCSetFunction(dataipc, DATAIPC_FUN_WRITE, (Vfunc*)exam8writec, (Vobject*)vsocket);
    vdm_DataIPCSetFunction(dataipc, DATAIPC_FUN_READ, (Vfunc*)exam8readc, (Vobject*)vsocket);

    /* open library device */
    vdm_DataFunSetStatus(datafun, VDM_STATUS_NEW);
    vdm_DataFunOpen(datafun, 0, (Vchar*)"exam8a.vdm", VDM_NATIVE);
    if (vdm_DataFunError(datafun))
        goto labelabort;

    /* check for error and try to upgrade */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);
    vdm_LManSetParami(lman, LMAN_VERBOSE, SYS_ON);
    vdm_LManSaveModel(lman, model);
    if (ndst) {
        vdm_LManSaveState(lman, state, rprop);
        vis_RPropEnd(rprop);
        vis_StateEnd(state);
    }
    vdm_LManEnd(lman);
    vdm_DataFunClose(datafun);
    vis_ModelDelete(model);
    vis_ModelEnd(model);

labelabort:
    vdm_DataIPCStopServer(dataipc);
    vsy_VSocketClose(vsocket, 0);

    /* free objects */
    vdm_DataFunEnd(datafun);
    vdm_DataIPCEnd(dataipc);
    vsy_VSocketEnd(vsocket);
    return 0;
}
