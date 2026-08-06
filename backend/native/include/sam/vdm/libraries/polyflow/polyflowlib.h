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
 
#ifndef POLYFLOWLIB_DEF
#define POLYFLOWLIB_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vis/gridfun.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
typedef void(VPOLYFLOWLibMonitorFunc)(vdm_POLYFLOWLib*,
Vobject*);struct vdm_POLYFLOWLib { Vint ierr;Vint type;
VConventionType conv;Vint doubpre;Vint nodata;Vint retcon;
Vint status;Vint numnp;Vint numel;Vint ndim;Vint nsub;
Vint numpos;Vint numdataset;Vint numdatasetplex;Vint
idtyp,idoff[3],idbas[3];fpos_t* pos;VPOLYFLOWLibMonitorFunc*
funmon;Vobject* funobjmon;Vint abortflag;vsy_IntDict*
id2dic;vsy_Dictionary* polyres;vsy_Dictionary* dsets;
vdm_Library* library;vis_Connect* connect;vis_GProp*
gprop;vis_Connect* cf;Vint nentgroups;vsy_HashTable*
enth;vdm_Plex* plex;Vint phase;Vchar source[VDM_SOURCE_SIZE];
#ifdef __cplusplus
public: VKI_EXTERN vdm_POLYFLOWLib(void);VKI_EXTERN
void* operator new(size_t);VKI_EXTERN ~vdm_POLYFLOWLib(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN
void SetConvention(VConventionType);VKI_EXTERN void
SetStatus(Vint);VKI_EXTERN void SetIds(Vint,Vint,Vint,
Vint);VKI_EXTERN void GetConnect(vis_Connect**);VKI_EXTERN
void SetConnect(vis_Connect*);VKI_EXTERN void SetFunction(Vint,
Vfunc*,Vobject*);VKI_EXTERN void SetMonitorFunction(VPOLYFLOWLibMonitorFunc*,
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
Vint,Vint*);VKI_EXTERN void SetString(Vint,Vchar*);
VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_POLYFLOWLib* vdm_POLYFLOWLibBegin(void);
VKI_EXTERN void vdm_POLYFLOWLib_Construct(vdm_POLYFLOWLib*
p);VKI_EXTERN void vdm_POLYFLOWLibEnd(vdm_POLYFLOWLib*
p);VKI_EXTERN void vdm_POLYFLOWLib_Destruct(vdm_POLYFLOWLib*
p);VKI_EXTERN Vint vdm_POLYFLOWLibError(vdm_POLYFLOWLib*
p);VKI_EXTERN void vdm_POLYFLOWLibSetMode(vdm_POLYFLOWLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_POLYFLOWLibSetConvention(vdm_POLYFLOWLib*
p,VConventionType convention);VKI_EXTERN void vdm_POLYFLOWLibSetStatus(vdm_POLYFLOWLib*
p,Vint status);VKI_EXTERN void vdm_POLYFLOWLibSetIds(vdm_POLYFLOWLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_POLYFLOWLibGetConnect(vdm_POLYFLOWLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_POLYFLOWLibSetConnect(vdm_POLYFLOWLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_POLYFLOWLibSetFunction(vdm_POLYFLOWLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_POLYFLOWLibSetMonitorFunction(vdm_POLYFLOWLib*
p,VPOLYFLOWLibMonitorFunc* function,Vobject* object);
VKI_EXTERN void vdm_POLYFLOWLibAbort(vdm_POLYFLOWLib*
p);VKI_EXTERN void vdm_POLYFLOWLibOpen(vdm_POLYFLOWLib*
p,Vint mode,Vchar* filename,Vint type);VKI_EXTERN void
vdm_POLYFLOWLibClose(vdm_POLYFLOWLib* p);VKI_EXTERN
void vdm_POLYFLOWLibAppend(vdm_POLYFLOWLib* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_POLYFLOWLibGetNumEntities(vdm_POLYFLOWLib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_POLYFLOWLibGetLibrary(vdm_POLYFLOWLib*
p,vdm_Library** library);VKI_EXTERN void vdm_POLYFLOWLibNumDatasets(vdm_POLYFLOWLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_POLYFLOWLibNumAttributes(vdm_POLYFLOWLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_POLYFLOWLibGetAttVal(vdm_POLYFLOWLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_POLYFLOWLibInqDataset(vdm_POLYFLOWLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_POLYFLOWLibInqAttribute(vdm_POLYFLOWLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_POLYFLOWLibReadDataset(vdm_POLYFLOWLib*
p,Vint idst,void* buff);VKI_EXTERN void vdm_POLYFLOWLibLibDataset(vdm_POLYFLOWLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_POLYFLOWLibSetString(vdm_POLYFLOWLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_POLYFLOWLibGetUnrecognizedData(vdm_POLYFLOWLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_POLYFLOWLibDataFun(vdm_POLYFLOWLib* p,vdm_DataFun*
datafun);VKI_EXTERN void vdm_POLYFLOWLibGetInteger(vdm_POLYFLOWLib*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_POLYFLOWLibGetString(vdm_POLYFLOWLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_POLYFLOWLibNumDomains(vdm_POLYFLOWLib*
p,Vchar* filename,Vint type,Vint* numdomains);
#ifdef __cplusplus
}
#endif
#endif

