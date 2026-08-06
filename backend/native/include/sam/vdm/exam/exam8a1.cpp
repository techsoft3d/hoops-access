#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vint magic = 1234;

/* data structure for server */
typedef struct {
    vsy_VSocket* vsocket;
    Vint cid;
} exam8struct;

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
    vdm_NatLib* natlib;
    vdm_DataFun* datafun;
    vdm_DataIPC* dataipc;
    Vint swap, imagic;

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

    /* setup VdmTools data structures */
    datafun = vdm_DataFunBegin();
    dataipc = vdm_DataIPCBegin();
    vdm_DataIPCDef(dataipc, DATAIPC_SERVER);
    vdm_DataIPCSetSwap(dataipc, swap);
    natlib = vdm_NatLibBegin();
    vdm_NatLibDataFun(natlib, datafun);
    vdm_DataIPCSetObject(dataipc, VDM_DATAFUN, (Vobject*)datafun);

    vdm_DataIPCSetFunction(dataipc, DATAIPC_FUN_WRITE, (Vfunc*)exam8writes, (Vobject*)inst);
    vdm_DataIPCSetFunction(dataipc, DATAIPC_FUN_READ, (Vfunc*)exam8reads, (Vobject*)inst);

    /* put server in receive-command mode */
    vdm_DataIPCStartServer(dataipc);

    /* cleanup */
    vdm_DataIPCEnd(dataipc);
    vdm_DataFunEnd(datafun);
    vdm_NatLibEnd(natlib);
    vsy_VSocketClose(inst->vsocket, inst->cid);
}

/*----------------------------------------------------------------------
                       Save a VDM_NATIVE file remotely
----------------------------------------------------------------------*/
int
main()
{
    vsy_VSocket* vsocket;
    Vint cid, flag;
    Vchar hostname[256];
    exam8struct inst;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* Get info about this host */
    vut_MachInfoHostName(&flag, hostname);
    if (flag == 0) {
        printf("Unable to retrieve host name\n");
        return 0;
    }
    printf("This example requires that exam8a2 also be running\n");
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
