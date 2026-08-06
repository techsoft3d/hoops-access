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
 
#ifndef CFXLIB_DEF
#define CFXLIB_DEF
#include <stdio.h>
#include "sam/base/basedefs.h"
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
typedef void(VCFXLibMonitorFunc)(vdm_CFXLib*,Vobject*);
struct vdm_CFXLib { Vint ierr;Vint type;VConventionType
conv;Vint doubpre;Vint nodata;Vint retcon;Vint idtyp,
idoff[3],idbas[3];Vint numnp;Vint numel;Vint numdataset;
Vint status;Vlong lngec;Vint maxnpe;vdm_Library* library;
vis_Connect* connect;vis_GProp* gprop;VCFXLibMonitorFunc*
funmon;Vobject* funobjmon;Vint abortflag;vdm_CFXLib*
parlib;vdm_CFXLib* curlib;Vint numlib;vdm_Dataset**
libs;Vint* libdsts;Vint numdatasetplex;vdm_Plex* plex;
vsy_Dictionary* restype;vsy_IntDict* bndtype;vsy_HashTable*
enth;Vchar ofilename[SYS_MAXPATHCHAR];Vint phase;Vchar
source[VDM_SOURCE_SIZE];void* cfx;Vint init;
#ifdef __cplusplus
public: VKI_EXTERN vdm_CFXLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_CFXLib(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetConnect(vis_Connect*);
VKI_EXTERN void GetConnect(vis_Connect**);VKI_EXTERN
void SetIds(Vint,Vint,Vint,Vint);VKI_EXTERN void SetFunction(Vint,
Vfunc*,Vobject*);VKI_EXTERN void SetMonitorFunction(VCFXLibMonitorFunc*,
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
VKI_EXTERN vdm_CFXLib* vdm_CFXLibBegin(void);VKI_EXTERN
void vdm_CFXLib_Construct(vdm_CFXLib* p);VKI_EXTERN
void vdm_CFXLibEnd(vdm_CFXLib* p);VKI_EXTERN void vdm_CFXLib_Destruct(vdm_CFXLib*
p);VKI_EXTERN Vint vdm_CFXLibError(vdm_CFXLib* p);VKI_EXTERN
void vdm_CFXLibSetMode(vdm_CFXLib* p,Vint mode,Vint
flag);VKI_EXTERN void vdm_CFXLibSetConvention(vdm_CFXLib*
p,VConventionType convention);VKI_EXTERN void vdm_CFXLibSetStatus(vdm_CFXLib*
p,Vint status);VKI_EXTERN void vdm_CFXLibSetConnect(vdm_CFXLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_CFXLibGetConnect(vdm_CFXLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_CFXLibSetIds(vdm_CFXLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_CFXLibSetFunction(vdm_CFXLib* p,
Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_CFXLibSetMonitorFunction(vdm_CFXLib* p,VCFXLibMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_CFXLibAbort(vdm_CFXLib*
p);VKI_EXTERN void vdm_CFXLibOpen(vdm_CFXLib* p,Vint
mode,Vchar* filename,Vint type);VKI_EXTERN void vdm_CFXLibClose(vdm_CFXLib*
p);VKI_EXTERN void vdm_CFXLibAppend(vdm_CFXLib* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_CFXLibGetNumEntities(vdm_CFXLib*
p,Vint enttype,Vint* nument);VKI_EXTERN void vdm_CFXLibGetLibrary(vdm_CFXLib*
p,vdm_Library** library);VKI_EXTERN void vdm_CFXLibNumDatasets(vdm_CFXLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_CFXLibNumAttributes(vdm_CFXLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_CFXLibGetAttVal(vdm_CFXLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_CFXLibInqDataset(vdm_CFXLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_CFXLibInqAttribute(vdm_CFXLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_CFXLibReadDataset(vdm_CFXLib*
p,Vint idst,void* buf);VKI_EXTERN void vdm_CFXLibLibDataset(vdm_CFXLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_CFXLibSetString(vdm_CFXLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_CFXLibGetUnrecognizedData(vdm_CFXLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_CFXLibDataFun(vdm_CFXLib* p,vdm_DataFun* datafun);
VKI_EXTERN void vdm_CFXLibGetInteger(vdm_CFXLib* p,
Vint type,Vint* ivalue);VKI_EXTERN void vdm_CFXLibGetString(vdm_CFXLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_CFXLibNumDomains(vdm_CFXLib*
p,Vchar* filename,Vint type,Vint* numdomains);
#ifdef __cplusplus
}
#endif
#endif

