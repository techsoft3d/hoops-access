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
 
#ifndef FEMAPLIB_DEF
#define FEMAPLIB_DEF
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
typedef void(VFEMAPLibMonitorFunc)(vdm_FEMAPLib*,Vobject*);
typedef struct vdm_FEMAPLibio vdm_FEMAPLibio;struct
vdm_FEMAPLib { Vint ierr;Vint type;VConventionType conv;
Vint doubpre;Vint nodata;Vint retcon;Vint status;Vint
numnp;Vint numel;Vint nfree;Vint ndim;Vint nlsect;Vdouble
dversion;Vchar version[9];Vchar title[81];Vint numdataset;
Vint hasbeamshell;Vint onecomp;Vint nodecsys;vdm_Library*
library;vis_Connect* connect;vis_GProp* gprop;vis_IdTran*
idtrannode;vis_IdTran* idtranelem;Vint numelemsets;
vsy_HashTable* elemsets;Vint numnodesets;vsy_HashTable*
nodesets;vsy_HashTable* csh;vsy_HashTable* rch;vdm_FEMAPLibio*
io;vsy_HashTable* etypesht;vsy_HashTable* blockht;vsy_HashTable*
analht;vsy_List* outl;vsy_Dictionary* resdict;vsy_Dictionary*
resdicti;vdm_Permute* permute;VFEMAPLibMonitorFunc*
funmon;Vobject* funobjmon;Vint abortflag;vsy_IntHash*
nodegeomassoc[4];vsy_IntVec* rigidiv[4];vsy_HashTable*
ftypeht;vsy_Dictionary* hldict;vis_IdTran* idtranl;
Vint phase;Vchar source[VDM_SOURCE_SIZE];vsy_IntVHash*
namesiv;Vint nwnames;vdm_Plex* plex;Vint numdatasetplex;
Vint idtyp;Vint idoff[3];
#ifdef __cplusplus
public: VKI_EXTERN vdm_FEMAPLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_FEMAPLib(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN
void SetConvention(VConventionType);VKI_EXTERN void
SetStatus(Vint);VKI_EXTERN void SetIds(Vint,Vint,Vint,
Vint);VKI_EXTERN void GetConnect(vis_Connect**);VKI_EXTERN
void SetConnect(vis_Connect*);VKI_EXTERN void SetFunction(Vint,
Vfunc1*,Vobject*);VKI_EXTERN void SetMonitorFunction(VFEMAPLibMonitorFunc*,
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
VKI_EXTERN vdm_FEMAPLib* vdm_FEMAPLibBegin(void);VKI_EXTERN
void vdm_FEMAPLib_Construct(vdm_FEMAPLib* p);VKI_EXTERN
void vdm_FEMAPLibEnd(vdm_FEMAPLib* p);VKI_EXTERN void
vdm_FEMAPLib_Destruct(vdm_FEMAPLib* p);VKI_EXTERN Vint
vdm_FEMAPLibError(vdm_FEMAPLib* p);VKI_EXTERN void vdm_FEMAPLibSetMode(vdm_FEMAPLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_FEMAPLibSetConvention(vdm_FEMAPLib*
p,VConventionType convention);VKI_EXTERN void vdm_FEMAPLibSetStatus(vdm_FEMAPLib*
p,Vint status);VKI_EXTERN void vdm_FEMAPLibSetIds(vdm_FEMAPLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_FEMAPLibGetConnect(vdm_FEMAPLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_FEMAPLibSetConnect(vdm_FEMAPLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_FEMAPLibSetFunction(vdm_FEMAPLib*
p,Vint funtype,Vfunc1* function,Vobject* object);VKI_EXTERN
void vdm_FEMAPLibSetMonitorFunction(vdm_FEMAPLib* p,
VFEMAPLibMonitorFunc* function,Vobject* object);VKI_EXTERN
void vdm_FEMAPLibAbort(vdm_FEMAPLib* p);VKI_EXTERN void
vdm_FEMAPLibOpen(vdm_FEMAPLib* p,Vint mode,Vchar* filename,
Vint type);VKI_EXTERN void vdm_FEMAPLibClose(vdm_FEMAPLib*
p);VKI_EXTERN void vdm_FEMAPLibAppend(vdm_FEMAPLib*
p,Vchar* filename,Vint type);VKI_EXTERN void vdm_FEMAPLibGetNumEntities(vdm_FEMAPLib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_FEMAPLibGetLibrary(vdm_FEMAPLib*
p,vdm_Library** library);VKI_EXTERN void vdm_FEMAPLibNumDatasets(vdm_FEMAPLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_FEMAPLibNumAttributes(vdm_FEMAPLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_FEMAPLibGetAttVal(vdm_FEMAPLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_FEMAPLibInqDataset(vdm_FEMAPLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_FEMAPLibInqAttribute(vdm_FEMAPLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_FEMAPLibReadDataset(vdm_FEMAPLib*
p,Vint idst,void* buff);VKI_EXTERN void vdm_FEMAPLibLibDataset(vdm_FEMAPLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_FEMAPLibSetString(vdm_FEMAPLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_FEMAPLibGetUnrecognizedData(vdm_FEMAPLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_FEMAPLibDataFun(vdm_FEMAPLib* p,vdm_DataFun*
datafun);VKI_EXTERN void vdm_FEMAPLibGetInteger(vdm_FEMAPLib*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_FEMAPLibGetString(vdm_FEMAPLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_FEMAPLibNumDomains(vdm_FEMAPLib*
p,Vchar* filename,Vint type,Vint* numdomains);
#ifdef __cplusplus
}
#endif
#endif

