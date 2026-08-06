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
 
#ifndef MARCFIL_DEF
#define MARCFIL_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vis/gridfun.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
typedef void(VMarcFilMonitorFunc)(vdm_MarcFil*,Vobject*);
typedef struct vdm_MarcFilio vdm_MarcFilio;struct vdm_MarcFil
{ Vint ierr;Vint type;Vchar filename[SYS_MAXPATHCHAR];
VConventionType conv;Vint doubpre;Vint nodata;Vint retcon;
Vint status;Vint numnp;Vint numel;Vint extended;Vint
iversion;Vint ndim;Vint twotyp;Vint* ixp;Vint* ix;Vint
maxnix;Vchar title[81];Vchar version[16];vdm_Permute*
permute;vdm_MarcFilio* io;Vint phase;Vchar source[VDM_SOURCE_SIZE];
vdm_Library* library;vis_GProp* gprop;vis_Connect* connect;
vsy_IntHash* nodeih;vsy_IntHash* elemih;VMarcFilMonitorFunc*
funmon;Vobject* funobjmon;Vint abortflag;vsy_HashTable*
elemsets;vsy_HashTable* nodesets;Vint numelemsets;Vint
numnodesets;void* iptrulecopy;
#ifdef __cplusplus
public: VKI_EXTERN vdm_MarcFil(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_MarcFil(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN
void GetString(Vint,Vchar*);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VMarcFilMonitorFunc*,Vobject*);VKI_EXTERN
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
VKI_EXTERN vdm_MarcFil* vdm_MarcFilBegin(void);VKI_EXTERN
void vdm_MarcFil_Construct(vdm_MarcFil* p);VKI_EXTERN
void vdm_MarcFilEnd(vdm_MarcFil* p);VKI_EXTERN void
vdm_MarcFil_Destruct(vdm_MarcFil* p);VKI_EXTERN Vint
vdm_MarcFilError(vdm_MarcFil* p);VKI_EXTERN void vdm_MarcFilGetInteger(vdm_MarcFil*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_MarcFilGetString(vdm_MarcFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_MarcFilSetMode(vdm_MarcFil*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_MarcFilSetConvention(vdm_MarcFil*
p,VConventionType convention);VKI_EXTERN void vdm_MarcFilSetStatus(vdm_MarcFil*
p,Vint status);VKI_EXTERN void vdm_MarcFilSetIds(vdm_MarcFil*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_MarcFilGetConnect(vdm_MarcFil* p,
vis_Connect** connect);VKI_EXTERN void vdm_MarcFilSetConnect(vdm_MarcFil*
p,vis_Connect* connect);VKI_EXTERN void vdm_MarcFilSetFunction(vdm_MarcFil*
p,Vint functype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_MarcFilSetMonitorFunction(vdm_MarcFil* p,VMarcFilMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_MarcFilAbort(vdm_MarcFil*
p);VKI_EXTERN void vdm_MarcFilNumDomains(vdm_MarcFil*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_MarcFilOpen(vdm_MarcFil* p,Vint mode,Vchar*
filename,Vint type);VKI_EXTERN void vdm_MarcFilClose(vdm_MarcFil*
p);VKI_EXTERN void vdm_MarcFilAppend(vdm_MarcFil* p,
Vchar* filename,Vint type);VKI_EXTERN void vdm_MarcFilGetNumEntities(vdm_MarcFil*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_MarcFilGetLibrary(vdm_MarcFil*
p,vdm_Library** library);VKI_EXTERN void vdm_MarcFilNumDatasets(vdm_MarcFil*
p,Vint* numdatasets);VKI_EXTERN void vdm_MarcFilNumAttributes(vdm_MarcFil*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_MarcFilGetAttVal(vdm_MarcFil*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_MarcFilInqDataset(vdm_MarcFil*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_MarcFilInqAttribute(vdm_MarcFil*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_MarcFilReadDataset(vdm_MarcFil*
p,Vint idst,void* buff);VKI_EXTERN void vdm_MarcFilLibDataset(vdm_MarcFil*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_MarcFilWriteModel(vdm_MarcFil*
p,vis_Model* model);VKI_EXTERN void vdm_MarcFilSetString(vdm_MarcFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_MarcFilGetUnrecognizedData(vdm_MarcFil*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_MarcFilDataFun(vdm_MarcFil* p,vdm_DataFun*
df);
#ifdef __cplusplus
}
#endif
#endif

