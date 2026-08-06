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
 
#ifndef COMSOLLIB_DEF
#define COMSOLLIB_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
typedef void(VCOMSOLLibMonitorFunc)(vdm_COMSOLLib*,
Vobject*);typedef struct vdm_COMSOLLibio vdm_COMSOLLibio;
struct vdm_COMSOLLib { Vint ierr;Vint type;Vchar path[SYS_MAXPATHCHAR];
Vchar version[17];Vchar date[17];Vchar time[9];VConventionType
conv;Vint doubpre;Vint nodata;Vint retcon;Vint status;
Vint numnp;Vint numel;Vint ndim;FILE* fd;vdm_Library*
library;vis_Connect* connect;vis_GProp* gprop;vsy_Dictionary*
resdict;VCOMSOLLibMonitorFunc* funmon;Vobject* funobjmon;
Vint abortflag;Vint phase;Vchar source[VDM_SOURCE_SIZE];
vdm_COMSOLLibio* io;vsy_Dictionary* etypedic;
#ifdef __cplusplus
public: VKI_EXTERN vdm_COMSOLLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_COMSOLLib(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN
void SetConvention(VConventionType);VKI_EXTERN void
SetStatus(Vint);VKI_EXTERN void SetIds(Vint,Vint,Vint,
Vint);VKI_EXTERN void GetConnect(vis_Connect**);VKI_EXTERN
void SetConnect(vis_Connect*);VKI_EXTERN void SetFunction(Vint,
Vfunc*,Vobject*);VKI_EXTERN void SetMonitorFunction(VCOMSOLLibMonitorFunc*,
Vobject*);VKI_EXTERN void Abort();VKI_EXTERN void Open(Vint,
Vchar*,Vint);VKI_EXTERN void Close();VKI_EXTERN void
Append(Vchar*,Vint);VKI_EXTERN void GetNumEntities(Vint,
Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);VKI_EXTERN
void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void LibDataset(Vint,Vint);VKI_EXTERN void DataFun(vdm_DataFun*);
VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN void
GetString(Vint,Vchar*);VKI_EXTERN void NumDomains(Vchar*,
Vint,Vint*);VKI_EXTERN void WriteModel(vis_Model*);
VKI_EXTERN void SetString(Vint,Vchar*);VKI_EXTERN void
GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_COMSOLLib* vdm_COMSOLLibBegin(void);
VKI_EXTERN void vdm_COMSOLLib_Construct(vdm_COMSOLLib*
p);VKI_EXTERN void vdm_COMSOLLibEnd(vdm_COMSOLLib* p);
VKI_EXTERN void vdm_COMSOLLib_Destruct(vdm_COMSOLLib*
p);VKI_EXTERN Vint vdm_COMSOLLibError(vdm_COMSOLLib*
p);VKI_EXTERN void vdm_COMSOLLibSetMode(vdm_COMSOLLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_COMSOLLibSetConvention(vdm_COMSOLLib*
p,VConventionType convention);VKI_EXTERN void vdm_COMSOLLibSetStatus(vdm_COMSOLLib*
p,Vint status);VKI_EXTERN void vdm_COMSOLLibSetIds(vdm_COMSOLLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_COMSOLLibGetConnect(vdm_COMSOLLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_COMSOLLibSetConnect(vdm_COMSOLLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_COMSOLLibSetFunction(vdm_COMSOLLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_COMSOLLibSetMonitorFunction(vdm_COMSOLLib*
p,VCOMSOLLibMonitorFunc* function,Vobject* object);
VKI_EXTERN void vdm_COMSOLLibAbort(vdm_COMSOLLib* p);
VKI_EXTERN void vdm_COMSOLLibOpen(vdm_COMSOLLib* p,
Vint mode,Vchar* filename,Vint type);VKI_EXTERN void
vdm_COMSOLLibClose(vdm_COMSOLLib* p);VKI_EXTERN void
vdm_COMSOLLibAppend(vdm_COMSOLLib* p,Vchar* filename,
Vint type);VKI_EXTERN void vdm_COMSOLLibGetNumEntities(vdm_COMSOLLib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_COMSOLLibGetLibrary(vdm_COMSOLLib*
p,vdm_Library** library);VKI_EXTERN void vdm_COMSOLLibNumDatasets(vdm_COMSOLLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_COMSOLLibNumAttributes(vdm_COMSOLLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_COMSOLLibGetAttVal(vdm_COMSOLLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_COMSOLLibInqDataset(vdm_COMSOLLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_COMSOLLibInqAttribute(vdm_COMSOLLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_COMSOLLibReadDataset(vdm_COMSOLLib*
p,Vint idst,void* buff);VKI_EXTERN void vdm_COMSOLLibLibDataset(vdm_COMSOLLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_COMSOLLibSetString(vdm_COMSOLLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_COMSOLLibGetUnrecognizedData(vdm_COMSOLLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_COMSOLLibDataFun(vdm_COMSOLLib* p,vdm_DataFun*
datafun);VKI_EXTERN void vdm_COMSOLLibGetInteger(vdm_COMSOLLib*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_COMSOLLibGetString(vdm_COMSOLLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_COMSOLLibNumDomains(vdm_COMSOLLib*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_COMSOLLibWriteModel(vdm_COMSOLLib* p,vis_Model*
model);
#ifdef __cplusplus
}
#endif
#endif

