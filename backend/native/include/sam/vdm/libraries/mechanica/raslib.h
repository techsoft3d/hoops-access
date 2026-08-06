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
 
#ifndef RASLIB_DEF
#define RASLIB_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vis/gprop.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
typedef void(VRASLibMonitorFunc)(vdm_RASLib*,Vobject*);
typedef struct _RASio { FILE* fd;Vlong ipnt;Vint byteswap;
}vdm_RASio;struct vdm_RASLib { vdm_Library* library;
Vint byteswap;Vint release;FILE* rptfd;FILE* pnufd;
Vint pnuform;FILE* neufd;Vint neuform;FILE* terfd;Vint
stepflag;Vint ierr;Vint nantyp;Vint soltyp;Vint twotyp;
Vint nonlin;Vint type;VConventionType conv;Vint doubpre;
Vint nodata;Vint retcon;Vint status;Vint idtyp,idoff[3],
idbas[3];Vint numnp;Vint numel;Vint nfree;Vint ndim;
Vint mside;Vint contactflag;vdm_RASio rasio;Vchar file[SYS_MAXPATHCHAR];
Vchar studyroot[SYS_MAXPATHCHAR];Vchar study[SYS_MAXPATHCHAR];
Vchar analysisroot[SYS_MAXPATHCHAR];Vchar analysis[SYS_MAXPATHCHAR];
Vchar title[80];Vchar version[16];Vchar time[16];Vchar
date[16];Vint numdataset;Vint phase;Vchar source[VDM_SOURCE_SIZE];
vsy_HashTable* csh;vsy_HashTable* eph;vsy_HashTable*
mph;vsy_HashTable* rch;vis_GProp* gprop;vis_Connect*
connect;vis_IdTran* idtrannode;vis_IdTran* idtranelem;
Vint nlsect;vsy_Dictionary* hldict;vis_IdTran* idtranl;
VRASLibMonitorFunc* funmon;Vobject* funobjmon;Vint abortflag;
#ifdef __cplusplus
public: VKI_EXTERN vdm_RASLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_RASLib(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN void
GetString(Vint,Vchar*);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VRASLibMonitorFunc*,Vobject*);VKI_EXTERN
void Abort();VKI_EXTERN void NumDomains(Vchar*,Vint,
Vint*);VKI_EXTERN void Open(Vint,Vchar*,Vint);VKI_EXTERN
void Close();VKI_EXTERN void Append(Vchar*,Vint);VKI_EXTERN
void GetNumEntities(Vint,Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);
VKI_EXTERN void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void LibDataset(Vint,Vint);VKI_EXTERN void DataFun(vdm_DataFun*);
VKI_EXTERN void SetString(Vint,Vchar*);VKI_EXTERN void
GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_RASLib* vdm_RASLibBegin(void);VKI_EXTERN
void vdm_RASLib_Construct(vdm_RASLib* p);VKI_EXTERN
void vdm_RASLibEnd(vdm_RASLib* p);VKI_EXTERN void vdm_RASLib_Destruct(vdm_RASLib*
p);VKI_EXTERN Vint vdm_RASLibError(vdm_RASLib* p);VKI_EXTERN
void vdm_RASLibGetInteger(vdm_RASLib* p,Vint type,Vint*
ivalue);VKI_EXTERN void vdm_RASLibGetString(vdm_RASLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_RASLibSetMode(vdm_RASLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_RASLibSetConvention(vdm_RASLib*
p,VConventionType convention);VKI_EXTERN void vdm_RASLibSetStatus(vdm_RASLib*
p,Vint status);VKI_EXTERN void vdm_RASLibSetIds(vdm_RASLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_RASLibGetConnect(vdm_RASLib* p,
vis_Connect** connect);VKI_EXTERN void vdm_RASLibSetConnect(vdm_RASLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_RASLibSetFunction(vdm_RASLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_RASLibSetMonitorFunction(vdm_RASLib* p,VRASLibMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_RASLibAbort(vdm_RASLib*
p);VKI_EXTERN void vdm_RASLibNumDomains(vdm_RASLib*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_RASLibOpen(vdm_RASLib* p,Vint mode,Vchar* filename,
Vint type);VKI_EXTERN void vdm_RASLibClose(vdm_RASLib*
p);VKI_EXTERN void vdm_RASLibAppend(vdm_RASLib* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_RASLibGetNumEntities(vdm_RASLib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_RASLibGetLibrary(vdm_RASLib*
p,vdm_Library** library);VKI_EXTERN void vdm_RASLibNumDatasets(vdm_RASLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_RASLibNumAttributes(vdm_RASLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_RASLibGetAttVal(vdm_RASLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_RASLibInqDataset(vdm_RASLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_RASLibInqAttribute(vdm_RASLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_RASLibReadDataset(vdm_RASLib*
p,Vint idst,void* buff);VKI_EXTERN void vdm_RASLibLibDataset(vdm_RASLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_RASLibSetString(vdm_RASLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_RASLibGetUnrecognizedData(vdm_RASLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_RASLibDataFun(vdm_RASLib* p,vdm_DataFun* datafun);
#ifdef __cplusplus
}
#endif
#endif

