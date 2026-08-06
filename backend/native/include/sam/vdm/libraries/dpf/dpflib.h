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
 
#ifndef DPFLIB_DEF
#define DPFLIB_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/state.h"
#include "sam/vis/group.h"
#include "sam/vis/connect.h"
#include "sam/vis/units.h"
#include "sam/vis/gprop.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/library.h"
#include "sam/vdm/plex.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/vdmadapter.h"
typedef void(VDPFLibMonitorFunc)(vdm_DPFLib*,Vobject*);
struct vdm_DPFLib { vdm_Adapter* dpfAdapter;vdm_Library*
library;Vint ierr;Vint nodataMode;Vchar libraryPath[SYS_MAXPATHCHAR];
Vint assumeLicensingAvailable;VConventionType conventions;
Vint doubpre; VDPFLibMonitorFunc* funmon;Vobject* funobjmon;
Vint phase;Vchar source[VDM_SOURCE_SIZE];Vint abortflag;
 Vint numdatasetplex;vdm_Plex* plex;
#ifdef __cplusplus
public: VKI_EXTERN vdm_DPFLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_DPFLib(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN void
GetString(Vint,Vchar*);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VDPFLibMonitorFunc*,Vobject*);VKI_EXTERN
void Abort();VKI_EXTERN void NumDomains(Vchar*,Vint,
Vint*);VKI_EXTERN void SetSearch(Vint);VKI_EXTERN void
SetSearchPath(Vint,Vchar*);VKI_EXTERN void Open(Vint,
Vchar*,Vint);VKI_EXTERN void Close();VKI_EXTERN void
Append(Vchar*,Vint);VKI_EXTERN void GetNumEntities(Vint,
Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);VKI_EXTERN
void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void ReadDatasetCols(Vint,Vint,Vint[],void*,Vlong*);
VKI_EXTERN void LibDataset(Vint,Vint);VKI_EXTERN void
DefDataset(const Vchar*,Vlong,Vint,Vint,Vint,Vint*);
VKI_EXTERN void WriteDataset(Vint,void*);VKI_EXTERN
void DefAttribute(Vint,const Vchar*,Vint,Vint,Vint*);
VKI_EXTERN void SetAttVal(Vint,Vint,void*);VKI_EXTERN
void DataFun(vdm_DataFun*);VKI_EXTERN void SetString(Vint,
Vchar*);VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_DPFLib* vdm_DPFLibBegin(void);VKI_EXTERN
void vdm_DPFLib_Construct(vdm_DPFLib* p);VKI_EXTERN
void vdm_DPFLibEnd(vdm_DPFLib* p);VKI_EXTERN void vdm_DPFLib_Destruct(vdm_DPFLib*
p);VKI_EXTERN void vdm_DPFLibOpen(vdm_DPFLib* p,Vint
mode,Vchar* filename,Vint type);VKI_EXTERN void vdm_DPFLibReadDataset(vdm_DPFLib*
p,Vint datasetIndex,void* data);VKI_EXTERN void vdm_DPFLibClose(vdm_DPFLib*
p);VKI_EXTERN void vdm_DPFLibGetConnect(vdm_DPFLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_DPFLibGetNumEntities(vdm_DPFLib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN Vint vdm_DPFLibError(vdm_DPFLib*
p);VKI_EXTERN void vdm_DPFLibGetLibrary(vdm_DPFLib*
p,vdm_Library** library);VKI_EXTERN void vdm_DPFLibNumDatasets(vdm_DPFLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_DPFLibNumAttributes(vdm_DPFLib*
p,Vint datasetIndex,Vint* numattributes);VKI_EXTERN
void vdm_DPFLibGetAttVal(vdm_DPFLib* p,Vint datasetIndex,
Vint iatt,void* value);VKI_EXTERN void vdm_DPFLibInqAttribute(vdm_DPFLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_DPFLibInqDataset(vdm_DPFLib*
p,Vint datasetIndex,Vchar name[],Vlong* lrec,Vint* nrow,
Vint* ncol,Vint* type);VKI_EXTERN void vdm_DPFLibSetMode(vdm_DPFLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_DPFLibSetString(vdm_DPFLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_DPFLibGetUnrecognizedData(vdm_DPFLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_DPFLibDataFun(vdm_DPFLib* p,vdm_DataFun* datafun);
VKI_EXTERN void vdm_DPFLibAbort(vdm_DPFLib* p);VKI_EXTERN
void vdm_DPFLibNumDomains(vdm_DPFLib* p,Vchar* filename,
Vint type,Vint* numdomains);VKI_EXTERN void vdm_DPFLibAppend(vdm_DPFLib*
p,Vchar* filename,Vint type);VKI_EXTERN void vdm_DPFLibReadDatasetCols(vdm_DPFLib*
p,Vint idst,Vint ncols,Vint cols[],void* buf,Vlong*
lptr);VKI_EXTERN void vdm_DPFLibLibDataset(vdm_DPFLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_DPFLibGetInteger(vdm_DPFLib*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_DPFLibGetString(vdm_DPFLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_DPFLibSetConvention(vdm_DPFLib*
p,VConventionType convention);VKI_EXTERN void vdm_DPFLibSetStatus(vdm_DPFLib*
p,Vint status);VKI_EXTERN void vdm_DPFLibSetIds(vdm_DPFLib*
p,Vint idtype,Vint id1,Vint id2,Vint id3);VKI_EXTERN
void vdm_DPFLibSetFunction(vdm_DPFLib* p,Vint funtype,
Vfunc* function,Vobject* object);VKI_EXTERN void vdm_DPFLibSetMonitorFunction(vdm_DPFLib*
p,VDPFLibMonitorFunc* function,Vobject* object);VKI_EXTERN
void vdm_DPFLibSetConnect(vdm_DPFLib* p,vis_Connect*
connect);VKI_EXTERN void vdm_DPFLibDefDataset(vdm_DPFLib*
p,const Vchar* name,Vlong lrec,Vint nrow,Vint ncol,
Vint type,Vint* idst);VKI_EXTERN void vdm_DPFLibWriteDataset(vdm_DPFLib*
p,Vint idst,void* buff);VKI_EXTERN void vdm_DPFLibDefAttribute(vdm_DPFLib*
p,Vint idst,const Vchar* name,Vint length,Vint type,
Vint* iatt);VKI_EXTERN void vdm_DPFLibSetAttVal(vdm_DPFLib*
p,Vint idst,Vint iatt,void* value);
#ifdef __cplusplus
}
#endif
#endif

