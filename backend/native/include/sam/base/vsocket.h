/*********************************************************************
 *                                                                   *
 *                          DevTools 3.1.0                           *
 *                                                                   *
 *  These coded instructions, statements and computer programs       *
 *  contain unpublished proprietary information of Tech Soft 3D,     *
 *  and are protected by Federal copyright law.  They may not be     *
 *  disclosed to third parties or copied or duplicated in any form,  *
 *  in whole or in part, without the prior written consent of        *
 *  Tech Soft 3D.                                                    *
 *                                                                   *
 *                 Copyright (C) 2026, Tech Soft 3D                  *
 *                                                                   *
 *********************************************************************/
 
#ifndef VSOCKET_DEF
#define VSOCKET_DEF
#include "sam/base/basedefs.h"
#ifdef VKI_LIBAPI_SOCKETS
#if defined(VKI_OS_WIN32)
#include <windows.h>
#include <io.h>
#include <winsock.h>
#else
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#endif
#endif
#define VSOCKET_NONE 0
#define VSOCKET_CLIENT 1
#define VSOCKET_SERVER 2
#define VSOCKET_WAITTIME 1
#define VSOCKET_DEBUG 2
#define VSOCKET_SCOPE 3
#define VSOCKET_MAXCONNECTIONS 4
#define VSOCKET_LOCAL 1
#define VSOCKET_NET 2
struct vsy_VSocket { Vchar name[256];Vchar localname[256];
Vint ierr;Vint type;Vushort port;Vint wait;Vint debug;
Vint cardsent;Vint cardreceived;Vint open;Vint scope;
Vint maxcon;
#ifdef VKI_LIBAPI_SOCKETS
#if defined(VKI_OS_WIN32)
SOCKET sd;
#else
int sd;struct sockaddr_un addrl;
#endif
struct hostent* hp;struct sockaddr_in addr;
#endif
Vchar serverhost[256];vsy_List* clist;Vint ncon;
#ifdef __cplusplus
public: VKI_EXTERN vsy_VSocket(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_VSocket(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(Vint,Vint);VKI_EXTERN void
SetNet(Vushort,Vchar[]);VKI_EXTERN void SetLocal(Vchar[]);
VKI_EXTERN void Inq(Vint*,Vint*);VKI_EXTERN void Open();
VKI_EXTERN void Accept(Vint*);VKI_EXTERN void Close(Vint);
VKI_EXTERN void Read(Vint,Vint,Vchar*);VKI_EXTERN void
ReadString(Vint,Vint,Vchar*,Vint*);VKI_EXTERN void Write(Vint,
Vint,Vchar*);VKI_EXTERN void WriteString(Vint,Vchar*);
VKI_EXTERN void SetParami(Vint,Vint);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_VSocket* vsy_VSocketBegin(void);VKI_EXTERN
void vsy_VSocket_Construct(vsy_VSocket* p);VKI_EXTERN
void vsy_VSocketEnd(vsy_VSocket* p);VKI_EXTERN void
vsy_VSocket_Destruct(vsy_VSocket* p);VKI_EXTERN Vint
vsy_VSocketError(vsy_VSocket* p);VKI_EXTERN void vsy_VSocketDef(vsy_VSocket*
p,Vint type,Vint scope);VKI_EXTERN void vsy_VSocketSetNet(vsy_VSocket*
p,Vushort portnumber,Vchar serverhost[]);VKI_EXTERN
void vsy_VSocketSetLocal(vsy_VSocket* p,Vchar localfile[]);
VKI_EXTERN void vsy_VSocketInq(vsy_VSocket* p,Vint*
type,Vint* scope);VKI_EXTERN void vsy_VSocketOpen(vsy_VSocket*
p);VKI_EXTERN void vsy_VSocketAccept(vsy_VSocket* p,
Vint* cid);VKI_EXTERN void vsy_VSocketClose(vsy_VSocket*
p,Vint cid);VKI_EXTERN void vsy_VSocketRead(vsy_VSocket*
p,Vint cid,Vint buflen,Vchar* buffer);VKI_EXTERN void
vsy_VSocketReadString(vsy_VSocket* p,Vint cid,Vint buflen,
Vchar* buffer,Vint* size);VKI_EXTERN void vsy_VSocketWrite(vsy_VSocket*
p,Vint cid,Vint buflen,Vchar* buffer);VKI_EXTERN void
vsy_VSocketWriteString(vsy_VSocket* p,Vint cid,Vchar*
buffer);VKI_EXTERN void vsy_VSocketSetParami(vsy_VSocket*
p,Vint type,Vint iparam);
#ifdef __cplusplus
}
#endif
#endif

