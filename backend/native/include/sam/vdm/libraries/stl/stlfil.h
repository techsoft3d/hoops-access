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
 
#ifndef STLFIL_DEF
#define STLFIL_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vis/gridfun.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
typedef void(VSTLFilMonitorFunc)(vdm_STLFil*,Vobject*);
struct vdm_STLFil { Vint ierr;Vint type;Vchar filename[SYS_MAXPATHCHAR];
VConventionType conv;Vint doubpre;Vint nodata;Vint retcon;
Vint status;Vint numnp;Vint numel;Vint nfree;Vint ndim;
Vint nantyp;Vint neltyp;Vint normflag;Vint phase;Vchar
source[VDM_SOURCE_SIZE];Vchar title[81];vdm_Library*
library;vis_GProp* gprop;vis_Connect* connect;vis_GridFun*
gridfun;Vint numelemsets;vsy_HashTable* elemsets;VSTLFilMonitorFunc*
funmon;Vobject* funobjmon;Vint abortflag;
#ifdef __cplusplus
public: VKI_EXTERN vdm_STLFil(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_STLFil(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN void
GetString(Vint,Vchar*);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VSTLFilMonitorFunc*,Vobject*);VKI_EXTERN
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
VKI_EXTERN vdm_STLFil* vdm_STLFilBegin(void);VKI_EXTERN
void vdm_STLFil_Construct(vdm_STLFil* p);VKI_EXTERN
void vdm_STLFilEnd(vdm_STLFil* p);VKI_EXTERN void vdm_STLFil_Destruct(vdm_STLFil*
p);VKI_EXTERN Vint vdm_STLFilError(vdm_STLFil* p);VKI_EXTERN
void vdm_STLFilGetInteger(vdm_STLFil* p,Vint type,Vint*
ivalue);VKI_EXTERN void vdm_STLFilGetString(vdm_STLFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_STLFilSetMode(vdm_STLFil*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_STLFilSetConvention(vdm_STLFil*
p,VConventionType convention);VKI_EXTERN void vdm_STLFilSetStatus(vdm_STLFil*
p,Vint status);VKI_EXTERN void vdm_STLFilSetIds(vdm_STLFil*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_STLFilGetConnect(vdm_STLFil* p,
vis_Connect** connect);VKI_EXTERN void vdm_STLFilSetConnect(vdm_STLFil*
p,vis_Connect* connect);VKI_EXTERN void vdm_STLFilSetFunction(vdm_STLFil*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_STLFilSetMonitorFunction(vdm_STLFil* p,VSTLFilMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_STLFilAbort(vdm_STLFil*
p);VKI_EXTERN void vdm_STLFilNumDomains(vdm_STLFil*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_STLFilOpen(vdm_STLFil* p,Vint mode,Vchar* filename,
Vint type);VKI_EXTERN void vdm_STLFilClose(vdm_STLFil*
p);VKI_EXTERN void vdm_STLFilAppend(vdm_STLFil* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_STLFilGetNumEntities(vdm_STLFil*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_STLFilGetLibrary(vdm_STLFil*
p,vdm_Library** library);VKI_EXTERN void vdm_STLFilNumDatasets(vdm_STLFil*
p,Vint* numdatasets);VKI_EXTERN void vdm_STLFilNumAttributes(vdm_STLFil*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_STLFilGetAttVal(vdm_STLFil*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_STLFilInqDataset(vdm_STLFil*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_STLFilInqAttribute(vdm_STLFil*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_STLFilReadDataset(vdm_STLFil*
p,Vint idst,void* buff);VKI_EXTERN void vdm_STLFilLibDataset(vdm_STLFil*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_STLFilWriteModel(vdm_STLFil*
p,vis_Model* model);VKI_EXTERN void vdm_STLFilSetString(vdm_STLFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_STLFilGetUnrecognizedData(vdm_STLFil*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_STLFilDataFun(vdm_STLFil* p,vdm_DataFun* datafun);
#ifdef __cplusplus
}
#endif
#endif

