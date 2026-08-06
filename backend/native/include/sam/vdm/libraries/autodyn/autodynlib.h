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
 
#ifndef AUTODYNLIB_DEF
#define AUTODYNLIB_DEF
#include <stdio.h>
#include "sam/base/basedefs.h"
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#include "sam/vdm/libraries/autodyn/autodyndat.h"
#include "sam/vdm/permute.h"
#define AUTODYNLIB_LIBVERSION 1
typedef void(VAUTODYNLibMonitorFunc)(vdm_AUTODYNLib*,
Vobject*);struct vdm_AUTODYNLib { Vint ierr;Vint type;
VConventionType conv;Vint doubpre;Vint nodata;Vint retcon;
Vint idtyp,idoff[3],idbas[3];Vint numnp;Vint numel;
Vint numelmem;Vint numnpmem;Vint mem;Vint status;Vint
numdataset;vdm_Library* library;vis_Connect* connect;
vis_GProp* gprop;vis_IdTran* uid;vis_IdTran* idtrannode;
VAUTODYNLibMonitorFunc* funmon;Vobject* funobjmon;Vint
abortflag;Vint numsteps;Vint numuelem;Vint numunode;
Vint numsnode;Vint numuparts;Vint numsparts;Vint* ncycles;
Vfloat* times;Vint* pnIsub;Vint* pnJsub;Vint* pnKsub;
Vint* numvartypes;Vint* numvars;Vint** varID;Vint**
uvarID;Vint** vartype;Vchar*** varname;vsy_HashTable*
resht;vsy_Dictionary* resdict;Vint nshell;Vint nbeam;
vsy_Dictionary* hldict;vis_IdTran* idtranl;Vint nlsect;
Vint libversion;Vint phase;Vchar source[VDM_SOURCE_SIZE];
#ifdef __cplusplus
public: VKI_EXTERN vdm_AUTODYNLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_AUTODYNLib(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN
void SetConvention(VConventionType);VKI_EXTERN void
SetStatus(Vint);VKI_EXTERN void SetConnect(vis_Connect*);
VKI_EXTERN void GetConnect(vis_Connect**);VKI_EXTERN
void SetIds(Vint,Vint,Vint,Vint);VKI_EXTERN void SetFunction(Vint,
Vfunc*,Vobject*);VKI_EXTERN void SetMonitorFunction(VAUTODYNLibMonitorFunc*,
Vobject*);VKI_EXTERN void Abort();VKI_EXTERN void Open(Vint,
Vchar*,Vint);VKI_EXTERN void Close();VKI_EXTERN void
Append(Vchar*,Vint);VKI_EXTERN void GetNumEntities(Vint,
Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);VKI_EXTERN
void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void LibDataset(Vint,Vint);VKI_EXTERN void SetVersion(Vint);
VKI_EXTERN void DataFun(vdm_DataFun*);VKI_EXTERN void
GetInteger(Vint,Vint*);VKI_EXTERN void GetString(Vint,
Vchar*);VKI_EXTERN void NumDomains(Vchar*,Vint,Vint*);
VKI_EXTERN void SetString(Vint,Vchar*);VKI_EXTERN void
GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_AUTODYNLib* vdm_AUTODYNLibBegin(void);
VKI_EXTERN void vdm_AUTODYNLib_Construct(vdm_AUTODYNLib*
p);VKI_EXTERN void vdm_AUTODYNLibEnd(vdm_AUTODYNLib*
p);VKI_EXTERN void vdm_AUTODYNLib_Destruct(vdm_AUTODYNLib*
p);VKI_EXTERN Vint vdm_AUTODYNLibError(vdm_AUTODYNLib*
p);VKI_EXTERN void vdm_AUTODYNLibSetMode(vdm_AUTODYNLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_AUTODYNLibSetConvention(vdm_AUTODYNLib*
p,VConventionType convention);VKI_EXTERN void vdm_AUTODYNLibSetStatus(vdm_AUTODYNLib*
p,Vint status);VKI_EXTERN void vdm_AUTODYNLibSetConnect(vdm_AUTODYNLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_AUTODYNLibGetConnect(vdm_AUTODYNLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_AUTODYNLibSetIds(vdm_AUTODYNLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_AUTODYNLibSetFunction(vdm_AUTODYNLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_AUTODYNLibSetMonitorFunction(vdm_AUTODYNLib*
p,VAUTODYNLibMonitorFunc* function,Vobject* object);
VKI_EXTERN void vdm_AUTODYNLibAbort(vdm_AUTODYNLib*
p);VKI_EXTERN void vdm_AUTODYNLibOpen(vdm_AUTODYNLib*
p,Vint mode,Vchar* filename,Vint type);VKI_EXTERN void
vdm_AUTODYNLibClose(vdm_AUTODYNLib* p);VKI_EXTERN void
vdm_AUTODYNLibAppend(vdm_AUTODYNLib* p,Vchar* filename,
Vint type);VKI_EXTERN void vdm_AUTODYNLibGetNumEntities(vdm_AUTODYNLib*
p,Vint enttype,Vint* nument);VKI_EXTERN void vdm_AUTODYNLibGetLibrary(vdm_AUTODYNLib*
p,vdm_Library** library);VKI_EXTERN void vdm_AUTODYNLibNumDatasets(vdm_AUTODYNLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_AUTODYNLibNumAttributes(vdm_AUTODYNLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_AUTODYNLibGetAttVal(vdm_AUTODYNLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_AUTODYNLibInqDataset(vdm_AUTODYNLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_AUTODYNLibInqAttribute(vdm_AUTODYNLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_AUTODYNLibReadDataset(vdm_AUTODYNLib*
p,Vint idst,void* buf);VKI_EXTERN void vdm_AUTODYNLibLibDataset(vdm_AUTODYNLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_AUTODYNLibSetVersion(vdm_AUTODYNLib*
p,Vint iversion);VKI_EXTERN void vdm_AUTODYNLibSetString(vdm_AUTODYNLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_AUTODYNLibGetUnrecognizedData(vdm_AUTODYNLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_AUTODYNLibDataFun(vdm_AUTODYNLib* p,vdm_DataFun*
datafun);VKI_EXTERN void vdm_AUTODYNLibGetInteger(vdm_AUTODYNLib*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_AUTODYNLibGetString(vdm_AUTODYNLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_AUTODYNLibNumDomains(vdm_AUTODYNLib*
p,Vchar* filename,Vint type,Vint* numdomains);
#ifdef __cplusplus
}
#endif
#endif

