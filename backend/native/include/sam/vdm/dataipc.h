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
 
#ifndef DATAIPC_DEF
#define DATAIPC_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vis/gridfun.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#define DATAIPC_CLIENT 1
#define DATAIPC_SERVER 2
#define DATAIPC_NET 1
#define DATAIPC_LOCAL 2
#define DATAIPC_USER 3
#define DATAIPC_FUN_MONITOR 1
#define DATAIPC_FUN_WRITE 2
#define DATAIPC_FUN_READ 3
#define DATAIPC_FUN_USER 4
#define DATAIPC_BEFORE 0
#define DATAIPC_AFTER 1
#define DATAIPC_DATAFUN -1
#define DATAIPC_STATE -2
#define DATAIPC_FILETYPE -3
#define DATAIPC_FILENAME -4
typedef void(VDataIPCMonitorFunc)(vdm_DataIPC*,Vobject*);
typedef void(VDataIPCWriteFunc)(Vobject*,Vint,Vchar*);
typedef void(VDataIPCReadFunc)(Vobject*,Vint,Vchar*);
typedef void(VDataIPCUserFunc)(vdm_DataIPC*,vdm_DataFun*,
Vint,Vchar[],Vint,Vint[],Vint,Vfloat[],Vint,Vdouble[]);
struct vdm_DataIPC { Vint ierr;Vint type;Vint iport;
Vint nodata;Vint retcon;Vint swap;Vchar hostname[2048];
Vchar filename[2048];Vchar dbname[2048];vdm_DataFun*
df;vdm_Library* library;VDataIPCMonitorFunc* funmon;
Vobject* funobjmon;Vobject* readobj;Vobject* writeobj;
Vint abortflag;Vint action;Vint state;Vint filetype;
Vchar localname[2048];VDataIPCWriteFunc* write;VDataIPCReadFunc*
read;VDataIPCUserFunc* user;
#ifdef __cplusplus
public: VKI_EXTERN vdm_DataIPC(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_DataIPC(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*);
VKI_EXTERN void SetSwap(Vint);VKI_EXTERN void SetObject(Vint,
Vobject*);VKI_EXTERN void GetObject(Vint,Vobject**);
VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void GetNumEntities(Vint,Vint*);VKI_EXTERN
void GetLibrary(vdm_Library**);VKI_EXTERN void GetInteger(Vint,
Vint*);VKI_EXTERN void GetString(Vint,Vchar*);VKI_EXTERN
void NumDomains(Vchar*,Vint,Vint*);VKI_EXTERN void PushContainer(Vchar[]);
VKI_EXTERN void PopContainer();VKI_EXTERN void StartServer();
VKI_EXTERN void StopServer();VKI_EXTERN void Open(Vint,
Vchar*,Vint);VKI_EXTERN void ReadDataset(Vint,void*);
VKI_EXTERN void ReadDatasetCols(Vint,Vint,Vint[],void*,
Vlong[]);VKI_EXTERN void Close();VKI_EXTERN void Append(Vchar*,
Vint);VKI_EXTERN void DataFun(vdm_DataFun*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VDataIPCMonitorFunc*,Vobject*);VKI_EXTERN
void SetReadFunction(VDataIPCReadFunc*,Vobject*);VKI_EXTERN
void SetWriteFunction(VDataIPCWriteFunc*,Vobject*);
VKI_EXTERN void Abort();VKI_EXTERN void LibDataset(Vint,
Vint);VKI_EXTERN void Update();VKI_EXTERN void DefDataset(const
Vchar*,Vlong,Vint,Vint,Vint,Vint*);VKI_EXTERN void InqDataset(Vint,
Vchar[],Vlong*,Vint*,Vint*,Vint*);VKI_EXTERN void NumDatasets(Vint*);
VKI_EXTERN void WriteDataset(Vint,void*);VKI_EXTERN
void DefAttribute(Vint,const Vchar*,Vint,Vint,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void SetAttVal(Vint,Vint,void*);VKI_EXTERN
void GetAttVal(Vint,Vint,void*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void User(Vint,Vchar[],Vint,Vint[],
Vint,Vfloat[],Vint,Vdouble[]);VKI_EXTERN void SetString(Vint,
Vchar*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_DataIPC* vdm_DataIPCBegin(void);VKI_EXTERN
void vdm_DataIPC_Construct(vdm_DataIPC* p);VKI_EXTERN
void vdm_DataIPCEnd(vdm_DataIPC* p);VKI_EXTERN void
vdm_DataIPC_Destruct(vdm_DataIPC* p);VKI_EXTERN Vint
vdm_DataIPCError(vdm_DataIPC* p);VKI_EXTERN void vdm_DataIPCDef(vdm_DataIPC*
p,Vint type);VKI_EXTERN void vdm_DataIPCInq(vdm_DataIPC*
p,Vint* type);VKI_EXTERN void vdm_DataIPCSetSwap(vdm_DataIPC*
p,Vint swap);VKI_EXTERN void vdm_DataIPCSetObject(vdm_DataIPC*
p,Vint type,Vobject* obj);VKI_EXTERN void vdm_DataIPCGetObject(vdm_DataIPC*
p,Vint type,Vobject** obj);VKI_EXTERN void vdm_DataIPCSetMode(vdm_DataIPC*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_DataIPCSetConvention(vdm_DataIPC*
p,VConventionType convention);VKI_EXTERN void vdm_DataIPCSetStatus(vdm_DataIPC*
p,Vint status);VKI_EXTERN void vdm_DataIPCSetIds(vdm_DataIPC*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_DataIPCGetConnect(vdm_DataIPC* p,
vis_Connect** connect);VKI_EXTERN void vdm_DataIPCGetNumEntities(vdm_DataIPC*
p,Vint entitytype,Vint* numentities);VKI_EXTERN void
vdm_DataIPCGetLibrary(vdm_DataIPC* p,vdm_Library** library);
VKI_EXTERN void vdm_DataIPCGetInteger(vdm_DataIPC* p,
Vint type,Vint* iparam);VKI_EXTERN void vdm_DataIPCGetString(vdm_DataIPC*
p,Vint type,Vchar* cparam);VKI_EXTERN void vdm_DataIPCNumDomains(vdm_DataIPC*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_DataIPCPushContainer(vdm_DataIPC* p,Vchar name[]);
VKI_EXTERN void vdm_DataIPCPopContainer(vdm_DataIPC*
p);VKI_EXTERN void vdm_DataIPCStartServer(vdm_DataIPC*
p);VKI_EXTERN void vdm_DataIPCStopServer(vdm_DataIPC*
p);VKI_EXTERN void vdm_DataIPCOpen(vdm_DataIPC* p,Vint
mode,Vchar* filename,Vint type);VKI_EXTERN void vdm_DataIPCReadDataset(vdm_DataIPC*
p,Vint idst,void* buff);VKI_EXTERN void vdm_DataIPCReadDatasetCols(vdm_DataIPC*
p,Vint idst,Vint ncols,Vint cols[],void* buff,Vlong
lptr[]);VKI_EXTERN void vdm_DataIPCClose(vdm_DataIPC*
p);VKI_EXTERN void vdm_DataIPCAppend(vdm_DataIPC* p,
Vchar* filename,Vint type);VKI_EXTERN void vdm_DataIPCSetString(vdm_DataIPC*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_DataIPCDataFun(vdm_DataIPC*
p,vdm_DataFun* datafun);VKI_EXTERN void vdm_DataIPCSetFunction(vdm_DataIPC*
p,Vint functype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_DataIPCSetMonitorFunction(vdm_DataIPC* p,VDataIPCMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_DataIPCSetReadFunction(vdm_DataIPC*
p,VDataIPCReadFunc* function,Vobject* object);VKI_EXTERN
void vdm_DataIPCSetWriteFunction(vdm_DataIPC* p,VDataIPCWriteFunc*
function,Vobject* object);VKI_EXTERN void vdm_DataIPCAbort(vdm_DataIPC*
p);VKI_EXTERN void vdm_DataIPCLibDataset(vdm_DataIPC*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_DataIPCUpdate(vdm_DataIPC*
p);VKI_EXTERN void vdm_DataIPCDefDataset(vdm_DataIPC*
p,const Vchar* name,Vlong lrec,Vint nrow,Vint ncol,
Vint type,Vint* idst);VKI_EXTERN void vdm_DataIPCInqDataset(vdm_DataIPC*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_DataIPCNumDatasets(vdm_DataIPC*
p,Vint* numdatasets);VKI_EXTERN void vdm_DataIPCWriteDataset(vdm_DataIPC*
p,Vint idst,void* buff);VKI_EXTERN void vdm_DataIPCDefAttribute(vdm_DataIPC*
p,Vint idst,const Vchar* name,Vint length,Vint type,
Vint* iatt);VKI_EXTERN void vdm_DataIPCInqAttribute(vdm_DataIPC*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_DataIPCSetAttVal(vdm_DataIPC*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_DataIPCGetAttVal(vdm_DataIPC*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_DataIPCNumAttributes(vdm_DataIPC*
p,Vint idst,Vint* natt);VKI_EXTERN void vdm_DataIPCUser(vdm_DataIPC*
p,Vint nchars,Vchar chars[],Vint nints,Vint ints[],
Vint nfloats,Vfloat floats[],Vint ndoubles,Vdouble doubles[]);
#ifdef __cplusplus
}
#endif
#endif

