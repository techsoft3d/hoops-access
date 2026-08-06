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
 
#ifndef OBJFIL_DEF
#define OBJFIL_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vis/gridfun.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
typedef void(VOBJFilMonitorFunc)(vdm_OBJFil*,Vobject*);
struct vdm_OBJFil { Vint ierr;Vint type;Vchar filename[SYS_MAXPATHCHAR];
VConventionType conv;Vint doubpre;Vint nodata;Vint retcon;
Vint status;Vint numnp;Vint numel;Vint nfree;Vint ndim;
Vint nantyp;Vint neltyp;Vint normflag;Vint bodyid;Vchar
bodyname[256];Vint phase;Vchar source[VDM_SOURCE_SIZE];
Vchar title[81];vdm_Library* library;vis_GProp* gprop;
vis_Connect* connect;vis_GridFun* gridfun;Vint numelemsets;
vsy_HashTable* elemsets;VOBJFilMonitorFunc* funmon;
Vobject* funobjmon;Vint abortflag;
#ifdef __cplusplus
public: VKI_EXTERN vdm_OBJFil(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_OBJFil(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN void
GetString(Vint,Vchar*);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VOBJFilMonitorFunc*,Vobject*);VKI_EXTERN
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
SetString(Vint,Vchar*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_OBJFil* vdm_OBJFilBegin(void);VKI_EXTERN
void vdm_OBJFil_Construct(vdm_OBJFil* p);VKI_EXTERN
void vdm_OBJFilEnd(vdm_OBJFil* p);VKI_EXTERN void vdm_OBJFil_Destruct(vdm_OBJFil*
p);VKI_EXTERN Vint vdm_OBJFilError(vdm_OBJFil* p);VKI_EXTERN
void vdm_OBJFilGetInteger(vdm_OBJFil* p,Vint type,Vint*
ivalue);VKI_EXTERN void vdm_OBJFilGetString(vdm_OBJFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_OBJFilSetMode(vdm_OBJFil*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_OBJFilSetConvention(vdm_OBJFil*
p,VConventionType convention);VKI_EXTERN void vdm_OBJFilSetStatus(vdm_OBJFil*
p,Vint status);VKI_EXTERN void vdm_OBJFilSetIds(vdm_OBJFil*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_OBJFilGetConnect(vdm_OBJFil* p,
vis_Connect** connect);VKI_EXTERN void vdm_OBJFilSetConnect(vdm_OBJFil*
p,vis_Connect* connect);VKI_EXTERN void vdm_OBJFilSetFunction(vdm_OBJFil*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_OBJFilSetMonitorFunction(vdm_OBJFil* p,VOBJFilMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_OBJFilAbort(vdm_OBJFil*
p);VKI_EXTERN void vdm_OBJFilNumDomains(vdm_OBJFil*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_OBJFilOpen(vdm_OBJFil* p,Vint mode,Vchar* filename,
Vint type);VKI_EXTERN void vdm_OBJFilClose(vdm_OBJFil*
p);VKI_EXTERN void vdm_OBJFilAppend(vdm_OBJFil* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_OBJFilGetNumEntities(vdm_OBJFil*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_OBJFilGetLibrary(vdm_OBJFil*
p,vdm_Library** library);VKI_EXTERN void vdm_OBJFilNumDatasets(vdm_OBJFil*
p,Vint* numdatasets);VKI_EXTERN void vdm_OBJFilNumAttributes(vdm_OBJFil*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_OBJFilGetAttVal(vdm_OBJFil*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_OBJFilInqDataset(vdm_OBJFil*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_OBJFilInqAttribute(vdm_OBJFil*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_OBJFilReadDataset(vdm_OBJFil*
p,Vint idst,void* buff);VKI_EXTERN void vdm_OBJFilLibDataset(vdm_OBJFil*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_OBJFilWriteModel(vdm_OBJFil*
p,vis_Model* model);VKI_EXTERN void vdm_OBJFilSetString(vdm_OBJFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_OBJFilDataFun(vdm_OBJFil*
p,vdm_DataFun* datafun);
#ifdef __cplusplus
}
#endif
#endif

