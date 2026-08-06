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
 
#ifndef RASFIL_DEF
#define RASFIL_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
typedef void(VRASFilMonitorFunc)(vdm_RASFil*,Vobject*);
struct vdm_RASFil { Vint ierr;Vint type;Vchar filename[SYS_MAXPATHCHAR];
VConventionType conv;Vint nodata;Vint retcon;Vint status;
Vint numnp;Vint numel;vdm_Library* library;Vint phase;
Vchar source[VDM_SOURCE_SIZE];VRASFilMonitorFunc* funmon;
Vobject* funobjmon;Vint abortflag;
#ifdef __cplusplus
public: VKI_EXTERN vdm_RASFil(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_RASFil(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN void
GetString(Vint,Vchar*);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VRASFilMonitorFunc*,Vobject*);VKI_EXTERN
void Abort();VKI_EXTERN void NumDomains(Vchar*,Vint,
Vint*);VKI_EXTERN void Open(Vint,Vchar*,Vint);VKI_EXTERN
void Close();VKI_EXTERN void Append(Vchar*,Vint);VKI_EXTERN
void GetNumEntities(Vint,Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);
VKI_EXTERN void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void WriteModel(vis_Model*);VKI_EXTERN void LibDataset(Vint,
Vint);VKI_EXTERN void DataFun(vdm_DataFun*);VKI_EXTERN
void SetString(Vint,Vchar*);VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_RASFil* vdm_RASFilBegin(void);VKI_EXTERN
void vdm_RASFil_Construct(vdm_RASFil* p);VKI_EXTERN
void vdm_RASFilEnd(vdm_RASFil* p);VKI_EXTERN void vdm_RASFil_Destruct(vdm_RASFil*
p);VKI_EXTERN Vint vdm_RASFilError(vdm_RASFil* p);VKI_EXTERN
void vdm_RASFilGetInteger(vdm_RASFil* p,Vint type,Vint*
ivalue);VKI_EXTERN void vdm_RASFilGetString(vdm_RASFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_RASFilSetMode(vdm_RASFil*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_RASFilSetConvention(vdm_RASFil*
p,VConventionType convention);VKI_EXTERN void vdm_RASFilSetStatus(vdm_RASFil*
p,Vint status);VKI_EXTERN void vdm_RASFilSetIds(vdm_RASFil*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_RASFilGetConnect(vdm_RASFil* p,
vis_Connect** connect);VKI_EXTERN void vdm_RASFilSetConnect(vdm_RASFil*
p,vis_Connect* connect);VKI_EXTERN void vdm_RASFilSetFunction(vdm_RASFil*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_RASFilSetMonitorFunction(vdm_RASFil* p,VRASFilMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_RASFilAbort(vdm_RASFil*
p);VKI_EXTERN void vdm_RASFilNumDomains(vdm_RASFil*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_RASFilOpen(vdm_RASFil* p,Vint mode,Vchar* filename,
Vint type);VKI_EXTERN void vdm_RASFilClose(vdm_RASFil*
p);VKI_EXTERN void vdm_RASFilAppend(vdm_RASFil* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_RASFilGetNumEntities(vdm_RASFil*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_RASFilGetLibrary(vdm_RASFil*
p,vdm_Library** library);VKI_EXTERN void vdm_RASFilNumDatasets(vdm_RASFil*
p,Vint* numdatasets);VKI_EXTERN void vdm_RASFilNumAttributes(vdm_RASFil*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_RASFilGetAttVal(vdm_RASFil*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_RASFilInqDataset(vdm_RASFil*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_RASFilInqAttribute(vdm_RASFil*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_RASFilReadDataset(vdm_RASFil*
p,Vint idst,void* buf);VKI_EXTERN void vdm_RASFilWriteModel(vdm_RASFil*
p,vis_Model* model);VKI_EXTERN void vdm_RASFilLibDataset(vdm_RASFil*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_RASFilSetString(vdm_RASFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_RASFilGetUnrecognizedData(vdm_RASFil*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_RASFilDataFun(vdm_RASFil* p,vdm_DataFun* datafun);
#ifdef __cplusplus
}
#endif
#endif

