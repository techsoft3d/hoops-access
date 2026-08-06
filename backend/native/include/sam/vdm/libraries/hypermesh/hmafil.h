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
 
#ifndef HMAFIL_DEF
#define HMAFIL_DEF
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
#define HMAFIL_NUMUNREC -1
#define HMAFIL_LINENUM -2
#define HMAFIL_UNRECCARD -3
#define HMAFIL_UNRECKEYWORD -4
#define HMAFIL_UNRECTYPE -5
typedef void(VHMAFilMonitorFunc)(vdm_HMAFil*,Vobject*);
typedef struct vdm_HMAFilio vdm_HMAFilio;struct vdm_HMAFil
{ Vint ierr;Vint type;VConventionType conv;Vint nodata;
Vint retcon;Vint status;Vint numnp;Vint numel;Vint nfree;
Vint ndim;Vint numcs;Vint numcp;Vint nantyp;Vint soltyp;
Vint twotyp;Vint nonlin;Vint doubpre;Vint systemcollectorid;
Vint phase;Vchar source[VDM_SOURCE_SIZE];vdm_Library*
library;vdm_HMAFilio* io;Vchar title[81];Vchar keyword[81];
vsy_HashTable* csh;vis_GProp* gprop;vis_Connect* connect;
vis_GridFun* gridfun;vis_IdTran* idtrannode;vis_IdTran*
idtranelem;vdm_Permute* permute;Vint numdatasetplex;
vdm_Plex* plex;Vint numunrec;vis_IdTran* idtranline;
vis_IdTran* idtrantype;vsy_HashTable* hashkeyword;vsy_HashTable*
hashcard;Vint curpartid;Vint curmid;Vint nindep;Vint
ndep;Vint elemindex;VHMAFilMonitorFunc* funmon;Vobject*
funobjmon;Vint abortflag;
#ifdef __cplusplus
public: VKI_EXTERN vdm_HMAFil(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_HMAFil(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void GetString(Vint,Vchar*);VKI_EXTERN void
SetMode(Vint,Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VHMAFilMonitorFunc*,Vobject*);VKI_EXTERN
void Abort();VKI_EXTERN void NumDomains(Vchar*,Vint,
Vint*);VKI_EXTERN void Open(Vint,Vchar*,Vint);VKI_EXTERN
void Close();VKI_EXTERN void Append(Vchar*,Vint);VKI_EXTERN
void GetNumEntities(Vint,Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);
VKI_EXTERN void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void GetInteger(Vint,Vint*);VKI_EXTERN void GetStringPtr(Vint,
Vchar**);VKI_EXTERN void LibDataset(Vint,Vint);VKI_EXTERN
void DataFun(vdm_DataFun*);VKI_EXTERN void PrintUnrecognizedData();
VKI_EXTERN void SetString(Vint,Vchar*);VKI_EXTERN void
GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_HMAFil* vdm_HMAFilBegin(void);VKI_EXTERN
void vdm_HMAFil_Construct(vdm_HMAFil* p);VKI_EXTERN
void vdm_HMAFilEnd(vdm_HMAFil* p);VKI_EXTERN void vdm_HMAFil_Destruct(vdm_HMAFil*
p);VKI_EXTERN Vint vdm_HMAFilError(vdm_HMAFil* p);VKI_EXTERN
void vdm_HMAFilGetString(vdm_HMAFil* p,Vint type,Vchar*
cvalue);VKI_EXTERN void vdm_HMAFilSetMode(vdm_HMAFil*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_HMAFilSetConvention(vdm_HMAFil*
p,VConventionType convention);VKI_EXTERN void vdm_HMAFilSetStatus(vdm_HMAFil*
p,Vint status);VKI_EXTERN void vdm_HMAFilSetIds(vdm_HMAFil*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_HMAFilGetConnect(vdm_HMAFil* p,
vis_Connect** connect);VKI_EXTERN void vdm_HMAFilSetConnect(vdm_HMAFil*
p,vis_Connect* connect);VKI_EXTERN void vdm_HMAFilSetFunction(vdm_HMAFil*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_HMAFilSetMonitorFunction(vdm_HMAFil* p,VHMAFilMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_HMAFilAbort(vdm_HMAFil*
p);VKI_EXTERN void vdm_HMAFilNumDomains(vdm_HMAFil*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_HMAFilOpen(vdm_HMAFil* p,Vint mode,Vchar* filename,
Vint type);VKI_EXTERN void vdm_HMAFilClose(vdm_HMAFil*
p);VKI_EXTERN void vdm_HMAFilAppend(vdm_HMAFil* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_HMAFilGetNumEntities(vdm_HMAFil*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_HMAFilGetLibrary(vdm_HMAFil*
p,vdm_Library** library);VKI_EXTERN void vdm_HMAFilNumDatasets(vdm_HMAFil*
p,Vint* numdatasets);VKI_EXTERN void vdm_HMAFilNumAttributes(vdm_HMAFil*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_HMAFilGetAttVal(vdm_HMAFil*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_HMAFilInqDataset(vdm_HMAFil*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_HMAFilInqAttribute(vdm_HMAFil*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_HMAFilReadDataset(vdm_HMAFil*
p,Vint idst,void* buf);VKI_EXTERN void vdm_HMAFilGetInteger(vdm_HMAFil*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_HMAFilGetStringPtr(vdm_HMAFil*
p,Vint type,Vchar** string);VKI_EXTERN void vdm_HMAFilLibDataset(vdm_HMAFil*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_HMAFilSetString(vdm_HMAFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_HMAFilGetUnrecognizedData(vdm_HMAFil*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_HMAFilDataFun(vdm_HMAFil* p,vdm_DataFun* datafun);
VKI_EXTERN void vdm_HMAFilPrintUnrecognizedData(vdm_HMAFil*
p);
#ifdef __cplusplus
}
#endif
#endif

