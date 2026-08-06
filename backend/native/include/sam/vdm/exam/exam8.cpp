#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#define BUFSIZE 256

static Vint magic = 1234;

/* data structure for server */
typedef struct {
    vsy_VSocket* vsocket;
    Vint cid;
} exam8struct;

/* monitor function for server */
static void
exam8monitor(vdm_DataIPC* p, Vobject* obj)
{
    Vint ierr;

    ierr = vdm_DataIPCError(p);
    if (ierr) {
        vdm_DataIPCAbort(p);
    }
}
/* read and write functions for server */
static void
exam8reads(exam8struct* inst, Vint num, Vchar* buf)
{
    vsy_VSocketRead(inst->vsocket, inst->cid, num, buf);
}
static void
exam8writes(exam8struct* inst, Vint num, Vchar* buf)
{
    vsy_VSocketWrite(inst->vsocket, inst->cid, num, buf);
}

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

static void
server(exam8struct* inst)
{
    vdm_NASFil* nasfil = NULL;
    vdm_NASLib* naslib = NULL;
    vdm_SDRCLib* sdrclib = NULL;
    vdm_DataFun* datafun = NULL;
    vdm_DataIPC* dataipc = NULL;
    Vint swap = 0, imagic = 0, size = 0, filetype = 0;
    Vchar filename[BUFSIZE];

    /* retrieve magic number to determine swapping */
    swap = 0;
    vsy_VSocketRead(inst->vsocket, inst->cid, sizeof(Vint), (Vchar*)&imagic);
    if (imagic != magic) {
        exam8swap4((Vchar*)&imagic);
        if (imagic != 1234) {
            swap = -1;
        }
        else {
            swap = 1;
        }
    }
    if (swap == -1) {
        vsy_VSocketWrite(inst->vsocket, inst->cid, sizeof(Vint), (Vchar*)&swap);
        vsy_VSocketClose(inst->vsocket, inst->cid);
        printf("Invalid magic number detected\n");
        return;
    }

    /* send magic number to determine swapping */
    vsy_VSocketWrite(inst->vsocket, inst->cid, sizeof(Vint), (Vchar*)&magic);

    /* retrieve filetype and filename */
    vsy_VSocketRead(inst->vsocket, inst->cid, sizeof(Vint), (Vchar*)&filetype);
    if (swap)
        exam8swap4((Vchar*)&filetype);
    vsy_VSocketReadString(inst->vsocket, inst->cid, BUFSIZE, filename, &size);
    if (filetype != SYS_NASTRAN_OUTPUT2 && filetype != SYS_NASTRAN_BULKDATA && filetype != SYS_SDRC_UNIVERSAL) {
        vsy_VSocketClose(inst->vsocket, inst->cid);
        printf("Unsupported filetype= %d\n", filetype);
        return;
    }
    vsy_VSocketWriteString(inst->vsocket, inst->cid, (Vchar*)"ok");

    /* setup VdmTools data structures */
    datafun = vdm_DataFunBegin();
    dataipc = vdm_DataIPCBegin();
    vdm_DataIPCDef(dataipc, DATAIPC_SERVER);
    vdm_DataIPCSetSwap(dataipc, swap);

    if (filetype == SYS_NASTRAN_OUTPUT2) {
        naslib = vdm_NASLibBegin();
        vdm_NASLibDataFun(naslib, datafun);
    }
    else if (filetype == SYS_NASTRAN_BULKDATA) {
        nasfil = vdm_NASFilBegin();
        vdm_NASFilDataFun(nasfil, datafun);
    }
    else if (filetype == SYS_SDRC_UNIVERSAL) {
        sdrclib = vdm_SDRCLibBegin();
        vdm_SDRCLibDataFun(sdrclib, datafun);
    }
    vdm_DataIPCSetObject(dataipc, VDM_DATAFUN, (Vobject*)datafun);

    vdm_DataIPCSetFunction(dataipc, DATAIPC_FUN_MONITOR, (Vfunc*)exam8monitor, NULL);
    vdm_DataIPCSetFunction(dataipc, DATAIPC_FUN_WRITE, (Vfunc*)exam8writes, (Vobject*)inst);
    vdm_DataIPCSetFunction(dataipc, DATAIPC_FUN_READ, (Vfunc*)exam8reads, (Vobject*)inst);

    /* put server in receive-command mode */
    vdm_DataIPCStartServer(dataipc);

    /* cleanup */
    vdm_DataIPCEnd(dataipc);
    vdm_DataFunEnd(datafun);
    if (filetype == SYS_NASTRAN_OUTPUT2) {
        vdm_NASLibEnd(naslib);
    }
    else if (filetype == SYS_NASTRAN_BULKDATA) {
        vdm_NASFilEnd(nasfil);
    }
    else if (filetype == SYS_SDRC_UNIVERSAL) {
        vdm_SDRCLibEnd(sdrclib);
    }
    vsy_VSocketClose(inst->vsocket, inst->cid);
}

/*----------------------------------------------------------------------
                       Remotely Access Any File Format
----------------------------------------------------------------------*/
static int
main_server()
{
    vsy_VSocket* vsocket;
    Vint cid, flag;
    Vchar hostname[BUFSIZE];
    exam8struct inst;

    /* Get info about this host */
    hostname[0] = '\0';
    vut_MachInfoHostName(&flag, hostname);
    if (flag == 0) {
        printf("Unable to retrieve host name\n");
        return 0;
    }
    /* Instance and set up VSocket */
    vsocket = vsy_VSocketBegin();
    vsy_VSocketSetParami(vsocket, VSOCKET_WAITTIME, 10000);
    vsy_VSocketSetParami(vsocket, VSOCKET_MAXCONNECTIONS, 10);
    vsy_VSocketDef(vsocket, VSOCKET_SERVER, VSOCKET_NET);
    vsy_VSocketSetNet(vsocket, 10000, hostname);
    vsy_VSocketOpen(vsocket);
    vsy_VSocketAccept(vsocket, &cid);

    inst.vsocket = vsocket;
    inst.cid = cid;
    /* call server */
    server(&inst);
    /* shut server down and cleanup */
    vsy_VSocketClose(vsocket, 0);
    vsy_VSocketEnd(vsocket);
    return 0;
}

/*----------------------------------------------------------------------
                       Remotely Access Any File Format
----------------------------------------------------------------------*/
static void
main_client(Vchar filename[])
{
    vdm_LMan* lman;
    vdm_DataFun* datafun;
    vdm_DataIPC* dataipc;
    vsy_VSocket* vsocket;
    Vchar hostname[BUFSIZE], buffer[BUFSIZE];
    Vint flag, swap, imagic, size, filetype;

    if (strstr(filename, ".op2")) {
        filetype = SYS_NASTRAN_OUTPUT2;
    }
    else if (strstr(filename, ".dat")) {
        filetype = SYS_NASTRAN_BULKDATA;
    }
    else if (strstr(filename, ".unv")) {
        filetype = SYS_SDRC_UNIVERSAL;
    }
    else {
        fprintf(stderr, "Unsupported file type\n");
        return;
    }
    /* Get info about this host */
    hostname[0] = '\0';
    vut_MachInfoHostName(&flag, hostname);
    if (flag == 0) {
        printf("Unable to retrieve host name\n");
        return;
    }
    /* Instance and set up VSocket */
    vsocket = vsy_VSocketBegin();
    vsy_VSocketSetParami(vsocket, VSOCKET_WAITTIME, 1000);
    vsy_VSocketDef(vsocket, VSOCKET_CLIENT, VSOCKET_NET);
    vsy_VSocketSetNet(vsocket, 10000, hostname);
    vsy_VSocketOpen(vsocket);
    if (vsy_VSocketError(vsocket)) {
        vsy_VSocketEnd(vsocket);
        return;
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
            return;
        }
        else {
            swap = 1;
        }
    }
    /* send filetype and filename */
    vsy_VSocketWrite(vsocket, 0, sizeof(Vint), (Vchar*)&filetype);
    vsy_VSocketWriteString(vsocket, 0, filename);
    vsy_VSocketReadString(vsocket, 0, BUFSIZE, buffer, &size);
    if (strcmp(buffer, "ok")) {
        vsy_VSocketClose(vsocket, 0);
        printf("Server did not acknowledge filetype and filename\n");
        return;
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
    vdm_DataFunOpen(datafun, 0, filename, filetype);
    if (vdm_DataFunError(datafun))
        goto labelabort;

    /* check for error and try to upgrade */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);
    vdm_LManSetParami(lman, LMAN_VERBOSE, SYS_ON);
    vdm_LManTOC(lman, "*");
    vdm_LManExport(lman, (Vchar*)"*", (Vchar*)"exam8.exp");
    vdm_LManEnd(lman);
    vdm_DataFunClose(datafun);

labelabort:
    vdm_DataIPCStopServer(dataipc);
    vsy_VSocketClose(vsocket, 0);

    /* free objects */
    vdm_DataFunEnd(datafun);
    vdm_DataIPCEnd(dataipc);
    vsy_VSocketEnd(vsocket);
}

static void
start_server(char* arg)
{
    Vchar sys[BUFSIZE];

#ifdef VKI_ARCH_WIN32
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    sprintf(sys, "%s s s s s", arg);
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    if (!CreateProcess(NULL, sys, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        printf("SERVER: Unable to start child process\n");
        exit(0);
    }
#else
    sprintf(sys, "%s s s s s &", arg);
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
#endif
    system(sys);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif
}

int
main(int argc, char* argv[])
{
    vsy_LicenseValidate(HOOPS_LICENSE);

    /* no input: use cantilever.unv */
    if (argc == 1) {
        fprintf(stderr, "Usage: %s pathname\n", argv[0]);
        fprintf(stderr, " cantilever.unv is assumed\n");
        start_server(argv[0]);
        main_client((Vchar*)"cantilever.unv");
        printf("Client terminated\n");
        /* one argument: file to open */
    }
    else if (argc == 2) {
        start_server(argv[0]);
        main_client(argv[1]);
        printf("Client terminated\n");
        /* internal use, process started by start_server */
    }
    else {
        main_server();
        printf("Server terminated\n");
    }
    return 0;
}
