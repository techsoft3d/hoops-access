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
 
#ifndef AFLRFIL_DEF
#define AFLRFIL_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vis/gridfun.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
typedef void(VAFLRFilMonitorFunc)(vdm_AFLRFil*,Vobject*);
typedef struct vdm_AFLRFilio vdm_AFLRFilio;struct vdm_AFLRFil
{ Vint ierr;Vint type;Vchar filename[SYS_MAXPATHCHAR];
VConventionType conv;Vint doubpre;Vint nodata;Vint retcon;
Vint status;Vint numnp;Vint numel;Vint ftype;Vint swap;
vdm_AFLRFilio* io;Vint phase;Vchar source[VDM_SOURCE_SIZE];
vdm_Library* library;vis_GProp* gprop;vis_Connect* connect;
VAFLRFilMonitorFunc* funmon;Vobject* funobjmon;Vint
abortflag;
#ifdef __cplusplus
public: VKI_EXTERN vdm_AFLRFil(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_AFLRFil(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN
void GetString(Vint,Vchar*);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VAFLRFilMonitorFunc*,Vobject*);VKI_EXTERN
void Abort();VKI_EXTERN void NumDomains(Vchar*,Vint,
Vint*);VKI_EXTERN void Open(Vint,Vchar*,Vint);VKI_EXTERN
void Close();VKI_EXTERN void Append(Vchar*,Vint);VKI_EXTERN
void GetNumEntities(Vint,Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);
VKI_EXTERN void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void LibDataset(Vint,Vint);VKI_EXTERN void WriteModel(vis_Model*);
VKI_EXTERN void DataFun(vdm_DataFun*);VKI_EXTERN void
SetString(Vint,Vchar*);VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_AFLRFil* vdm_AFLRFilBegin(void);VKI_EXTERN
void vdm_AFLRFil_Construct(vdm_AFLRFil* p);VKI_EXTERN
void vdm_AFLRFilEnd(vdm_AFLRFil* p);VKI_EXTERN void
vdm_AFLRFil_Destruct(vdm_AFLRFil* p);VKI_EXTERN Vint
vdm_AFLRFilError(vdm_AFLRFil* p);VKI_EXTERN void vdm_AFLRFilGetInteger(vdm_AFLRFil*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_AFLRFilGetString(vdm_AFLRFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_AFLRFilSetMode(vdm_AFLRFil*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_AFLRFilSetConvention(vdm_AFLRFil*
p,VConventionType convention);VKI_EXTERN void vdm_AFLRFilSetStatus(vdm_AFLRFil*
p,Vint status);VKI_EXTERN void vdm_AFLRFilSetIds(vdm_AFLRFil*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_AFLRFilGetConnect(vdm_AFLRFil* p,
vis_Connect** connect);VKI_EXTERN void vdm_AFLRFilSetConnect(vdm_AFLRFil*
p,vis_Connect* connect);VKI_EXTERN void vdm_AFLRFilSetFunction(vdm_AFLRFil*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_AFLRFilSetMonitorFunction(vdm_AFLRFil* p,VAFLRFilMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_AFLRFilAbort(vdm_AFLRFil*
p);VKI_EXTERN void vdm_AFLRFilNumDomains(vdm_AFLRFil*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_AFLRFilOpen(vdm_AFLRFil* p,Vint mode,Vchar*
filename,Vint type);VKI_EXTERN void vdm_AFLRFilClose(vdm_AFLRFil*
p);VKI_EXTERN void vdm_AFLRFilAppend(vdm_AFLRFil* p,
Vchar* filename,Vint type);VKI_EXTERN void vdm_AFLRFilGetNumEntities(vdm_AFLRFil*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_AFLRFilGetLibrary(vdm_AFLRFil*
p,vdm_Library** library);VKI_EXTERN void vdm_AFLRFilNumDatasets(vdm_AFLRFil*
p,Vint* numdatasets);VKI_EXTERN void vdm_AFLRFilNumAttributes(vdm_AFLRFil*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_AFLRFilGetAttVal(vdm_AFLRFil*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_AFLRFilInqDataset(vdm_AFLRFil*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_AFLRFilInqAttribute(vdm_AFLRFil*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_AFLRFilReadDataset(vdm_AFLRFil*
p,Vint idst,void* buff);VKI_EXTERN void vdm_AFLRFilLibDataset(vdm_AFLRFil*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_AFLRFilWriteModel(vdm_AFLRFil*
p,vis_Model* model);VKI_EXTERN void vdm_AFLRFilSetString(vdm_AFLRFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_AFLRFilGetUnrecognizedData(vdm_AFLRFil*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_AFLRFilDataFun(vdm_AFLRFil* p,vdm_DataFun*
datafun);
#ifdef __cplusplus
}
#endif
#endif

