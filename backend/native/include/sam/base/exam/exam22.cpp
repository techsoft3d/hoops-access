#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
#ifdef VKI_ARCH_WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define BUFSIZE 256

static const Vchar* commands[2][5] = {{"client1", "int", "float", "double", "bye"}, {"client2", "int", "float", "double", "bye"}};

static Vint icval[2] = {27, -2};
static Vfloat fcval[2] = {-0.001f, 3.e-5f};
static Vdouble dcval[2] = {0.33, -2.56};

typedef struct {
    vsy_VSocket* vsocket;
    Vint cid;
    Vchar firstbuf[BUFSIZE];
} exam22struct;

/* terminate thread */
static void
exam22term(exam22struct* inst)
{
    free(inst);
}

static void
server(Vobject* obj)
{
    exam22struct* inst = (exam22struct*)obj;
    Vint size, iterm;
    Vint ival, n;
    Vfloat fval;
    Vdouble dval;
    Vchar buffer[BUFSIZE];

    iterm = 0;
    /* Infinite loop to receive commands from client */
    for (n = 0;; ++n) {
        /* Read first command from struct; otherwise, from socket */
        if (n == 0) {
            strcpy(buffer, inst->firstbuf);
        }
        else {
            vsy_VSocketReadString(inst->vsocket, inst->cid, BUFSIZE, buffer, &size);
            if (vsy_VSocketError(inst->vsocket))
                return;
        }

        /* echo command */
        printf("SERVER: client %d- %s", inst->cid, buffer);

        /* Termination: set flag to quit later */
        if (strstr(buffer, "bye")) {
            iterm = 1;

            /* int: read integer from socket and print */
        }
        else if (strstr(buffer, "int")) {
            vsy_VSocketRead(inst->vsocket, inst->cid, sizeof(Vint), (Vchar*)&ival);
            if (vsy_VSocketError(inst->vsocket))
                return;

            printf(" %d", ival);

            /* float: read float from socket and print */
        }
        else if (strstr(buffer, "float")) {
            vsy_VSocketRead(inst->vsocket, inst->cid, sizeof(Vfloat), (Vchar*)&fval);
            if (vsy_VSocketError(inst->vsocket))
                return;

            printf(" %e", fval);

            /* double: read double from socket and print */
        }
        else if (strstr(buffer, "double")) {
            vsy_VSocketRead(inst->vsocket, inst->cid, sizeof(Vdouble), (Vchar*)&dval);
            if (vsy_VSocketError(inst->vsocket))
                return;

            printf(" %e", dval);
        }
        printf("\n");

        /* acknowledge receipt to client */
        vsy_VSocketWriteString(inst->vsocket, inst->cid, (Vchar*)"ok");
        if (vsy_VSocketError(inst->vsocket))
            return;

        /* bye: quit */
        if (iterm == 1) {
            vsy_VSocketClose(inst->vsocket, inst->cid);
            break;
        }
    }
}

static void
main_server()
{
    vsy_VSocket* vsocket;
    vsy_List* list;
    Vchar hostname[BUFSIZE], buffer[BUFSIZE];
    Vint flag, cid, i, size;
    exam22struct* inst;

    /* Get info about this host */
    vut_MachInfoHostName(&flag, hostname);
    if (flag == 0) {
        printf("SERVER: Unable to retrieve host name\n");
        return;
    }
    /* Instance and set up VSocket */
    vsocket = vsy_VSocketBegin();
    vsy_VSocketSetParami(vsocket, VSOCKET_WAITTIME, 10);
    vsy_VSocketSetParami(vsocket, VSOCKET_MAXCONNECTIONS, 1);
    vsy_VSocketDef(vsocket, VSOCKET_SERVER, VSOCKET_NET);
    vsy_VSocketSetNet(vsocket, 10000, hostname);
    vsy_VSocketOpen(vsocket);
    if (vsy_VSocketError(vsocket)) {
        printf("SERVER: Unable to Open\n");
        return;
    }
    /* Instance list to store client instances */
    list = vsy_ListBegin();

    for (i = 0; i < 5; ++i) {
        vsy_VSocketAccept(vsocket, &cid);
        if (cid == 0)
            break;

        vsy_VSocketReadString(vsocket, cid, BUFSIZE, buffer, &size);

        /* check for stop server command */
        if (strstr(buffer, "stop")) {
            vsy_VSocketClose(vsocket, cid);
            break;
        }

        /* establish new connection in thread */
        inst = (exam22struct*)malloc(sizeof(exam22struct));
        vsy_ListInsert(list, cid, (Vobject*)inst);
        inst->vsocket = vsocket;
        inst->cid = cid;
        strcpy(inst->firstbuf, buffer);
        server((Vobject*)inst);
    }

    /* Close connection and cleanup */
    vsy_VSocketSetParami(vsocket, VSOCKET_WAITTIME, 1);
    vsy_ListForEach(list, (Vfunc1*)exam22term);
    vsy_VSocketClose(vsocket, 0);
    vsy_ListEnd(list);
    vsy_VSocketEnd(vsocket);
    return;
}

static void
client(vsy_VSocket* vsocket, Vint id)
{
    Vint iterm = 0, size = 0, n = 0;
    Vchar buffer[BUFSIZE] = {0};

    /* start command loop */
    for (n = 0; n < 5; n++) {
        /* send command to server */
        vsy_VSocketWriteString(vsocket, 0, (Vchar*)commands[id - 1][n]);
        if (vsy_VSocketError(vsocket))
            return;

        /* set termination flag */
        if (strcmp(commands[id - 1][n], "bye") == 0) {
            iterm = 1;

            /* read and send int as binary */
        }
        else if (strcmp(commands[id - 1][n], "int") == 0) {
            vsy_VSocketWrite(vsocket, 0, sizeof(Vint), (Vchar*)&icval[id - 1]);
            if (vsy_VSocketError(vsocket))
                return;

            /* read and send float as binary */
        }
        else if (strcmp(commands[id - 1][n], "float") == 0) {
            vsy_VSocketWrite(vsocket, 0, sizeof(Vfloat), (Vchar*)&fcval[id - 1]);
            if (vsy_VSocketError(vsocket))
                return;

            /* read and send double as binary */
        }
        else if (strcmp(commands[id - 1][n], "double") == 0) {
            vsy_VSocketWrite(vsocket, 0, sizeof(Vdouble), (Vchar*)&dcval[id - 1]);
            if (vsy_VSocketError(vsocket))
                return;
        }
        /* read receipt acknowledgement from server */
        vsy_VSocketReadString(vsocket, 0, BUFSIZE, buffer, &size);
        if (vsy_VSocketError(vsocket))
            return;
        if (strcmp(buffer, "ok") == 0) {
            printf("CLIENT %d: ...information received by server from client\n", id);
        }

        /* terminate thread if "bye" */
        if (iterm == 1)
            break;
    }
}

static void
main_client(Vint id)
{
    vsy_VSocket* vsocket;
    Vchar hostname[BUFSIZE];
    Vint flag;

    /* Get info about this host */
    vut_MachInfoHostName(&flag, hostname);
    if (flag == 0) {
        printf("CLIENT %d: Unable to retrieve host name in client\n", id);
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
    /* Exchange information with server */
    client(vsocket, id);
    /* Close connection and cleanup */
    vsy_VSocketClose(vsocket, 0);
    vsy_VSocketEnd(vsocket);
    return;
}

static void
main_stop()
{
    vsy_VSocket* vsocket;
    Vchar hostname[BUFSIZE];
    Vint flag;

    /* Get info about this host */
    vut_MachInfoHostName(&flag, hostname);
    if (flag == 0) {
        printf("STOP: Unable to retrieve host name\n");
        return;
    }
    /* Instance and set up VSocket */
    vsocket = vsy_VSocketBegin();
    vsy_VSocketDef(vsocket, VSOCKET_CLIENT, VSOCKET_NET);
    vsy_VSocketSetNet(vsocket, 10000, hostname);
    vsy_VSocketOpen(vsocket);

    /* Send command to server to stop itself */
    printf("STOP: sending stop command to server\n");
    vsy_VSocketWriteString(vsocket, 0, (Vchar*)"stop");

    /* Close connection and cleanup */
    vsy_VSocketClose(vsocket, 0);
    vsy_VSocketEnd(vsocket);
    return;
}

/*----------------------------------------------------------------------
                      Test and Demonstrate VSocket Object

                      Byte-swapping may need to be added for
                      heterogeneous machines with different
                      byte representation
----------------------------------------------------------------------*/
int
main(int argc, char* argv[])
{
    Vchar sys[BUFSIZE];
    Vint n;

    vsy_LicenseValidate(HOOPS_LICENSE);

#ifdef VKI_ARCH_WIN32
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
#endif
    /* Check input */
    if (argc == 1) {
        for (n = 1; n <= 3; n++) {
#ifdef VKI_ARCH_WIN32
            sprintf(sys, "%s %d", argv[0], n);
            ZeroMemory(&si, sizeof(si));
            si.cb = sizeof(si);
            ZeroMemory(&pi, sizeof(pi));
            if (!CreateProcess(NULL, sys, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
                printf("SERVER: Unable to start child process %d\n", n);
                exit(0);
            }
#else
            sprintf(sys, "%s %d &", argv[0], n);
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
        main_server();
    }
    else if (argc == 2) {
        sscanf(argv[1], "%d", &n);
        if (n == 1 || n == 2) {
            main_client(n);
        }
        else {
            /* Wait 10 seconds before stopping server */
            printf("SERVER: Waiting 10 seconds to launch stop server...\n");
#ifdef VKI_ARCH_WIN32
            Sleep(10000);
#else
            sleep(10);
#endif
            main_stop();
        }
    }
    return 0;
}
