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
 
#ifndef D3DFIL_DEF
#define D3DFIL_DEF
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
#define D3DFIL_NUMRESTYPES 32
#define D3DFIL_PARTHEADER_LENGTH 133
#define D3DFIL_NUMUNREC -1
#define D3DFIL_LINENUM -2
#define D3DFIL_UNRECKEYWORD -3
#define D3DFIL_UNRECDATALINE -4
#define D3DFIL_UNRECFILE -5
typedef void(VD3DFilMonitorFunc)(vdm_D3DFil*,Vobject*);
typedef struct vdm_D3DFilio vdm_D3DFilio;struct vdm_D3DFil
{ Vint ierr;Vint type;Vchar filename[SYS_MAXPATHCHAR];
VConventionType conv;Vint nodata;Vint retcon;Vint status;
Vint numnp;Vint numel;Vint nfree;Vint ndim;Vint numcs;
Vint numcp;Vint nantyp;Vint soltyp;Vint twotyp;Vint
nonlin;Vint doubpre;Vint phase;Vchar source[VDM_SOURCE_SIZE];
vdm_Library* library;vdm_D3DFilio* io;Vchar heading[SYS_MAXNAMECHAR];
Vchar title[SYS_MAXNAMECHAR];Vchar subtitle[SYS_MAXNAMECHAR];
Vchar label[SYS_MAXNAMECHAR];Vint systemflag;vsy_CSystem*
system;Vchar keyword[SYS_MAXNAMECHAR];vsy_CSystem* csystem;
vsy_CSystem* wsystem;vsy_IntHash* ndef;Vint numelemsets;
vsy_HashTable* elemsets;vsy_VHashTable* elemSetsWithTypes;
Vint numnodesets;vsy_HashTable* nodesets;Vint numpartsets;
vsy_Dictionary* intdict;vsy_Dictionary* surfdict;vsy_Dictionary*
afactdict;vsy_HashTable* csh;Vint maxpid;Vint numpid;
vsy_HashTable* sech;vsy_HashTable* eph;vsy_Dictionary*
epd;Vint nummid;vsy_HashTable* mph;vis_MProp* curmprop;
vis_EProp* cureprop;vsy_HashTable* edh;Vint stepflag;
Vint numsid;vsy_List* spl;Vint steprid;Vint steplid;
Vint numprnt,numfile;Vint curprnt[D3DFIL_NUMRESTYPES];
Vint curfile[D3DFIL_NUMRESTYPES];Vint curtprnt[D3DFIL_NUMRESTYPES];
Vint curtfile[D3DFIL_NUMRESTYPES];Vint numrid;vsy_HashTable*
rch;Vint numlid;vsy_HashTable* lch;Vint nummpc;Vint
nummpid;vsy_HashTable* mch;Vint numtid;vsy_HashTable*
tch;Vint numicid;vsy_HashTable* ich;Vint shellthk;Vint
shellOffset;Vint ersvec;Vint emtcid;Vint emtvec;Vint
trefid;Vint orientnodeflag;Vint pinflags;Vint include;
Vint checknewinclude;vis_Connect* connect;vis_GridFun*
gridfun;vis_IdTran* idtrannode;vis_IdTran* idtranelem;
vdm_Permute* permute;Vint numdatasetplex;vdm_Plex* plex;
vis_GProp* gprop;vsy_IntVec* mpcids;vsy_IntVec* mpcdof;
vsy_DblVec* mpcval;vsy_IntVec* mpcdistnod;vsy_DblVec*
mpcdistwgt;Vint idnoff;Vint ideoff;Vint idpoff;Vint
idmoff;Vint idsoff;Vint idfoff;Vint iddoff;Vint idroff;
Vint tranid;Vdouble fctmas,fcttim,fctlen,fcttem;vsy_HashTable*
transh;vsy_Calc* calc;Vint numunrec;vis_IdTran* idtranline;
vis_IdTran* idtrantype;vsy_HashTable* hashkeyword;vsy_HashTable*
hashcard;vsy_HashTable* hashfile;VD3DFilMonitorFunc*
funmon;Vobject* funobjmon;Vint abortflag;
#ifdef __cplusplus
public: VKI_EXTERN vdm_D3DFil(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_D3DFil(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VD3DFilMonitorFunc*,Vobject*);VKI_EXTERN
void Abort();VKI_EXTERN void NumDomains(Vchar*,Vint,
Vint*);VKI_EXTERN void Open(Vint,Vchar*,Vint);VKI_EXTERN
void Close();VKI_EXTERN void Append(Vchar*,Vint);VKI_EXTERN
void GetNumEntities(Vint,Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);
VKI_EXTERN void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void GetInteger(Vint,Vint*);VKI_EXTERN void GetString(Vint,
Vchar*);VKI_EXTERN void GetStringPtr(Vint,Vchar**);
VKI_EXTERN void GetUnrecognizedDataSize(Vint*);VKI_EXTERN
void WriteModel(vis_Model*);VKI_EXTERN void LibDataset(Vint,
Vint);VKI_EXTERN void DataFun(vdm_DataFun*);VKI_EXTERN
void PrintUnrecognizedData();VKI_EXTERN void SetString(Vint,
Vchar*);VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_D3DFil* vdm_D3DFilBegin(void);VKI_EXTERN
void vdm_D3DFil_Construct(vdm_D3DFil* p);VKI_EXTERN
void vdm_D3DFilEnd(vdm_D3DFil* p);VKI_EXTERN void vdm_D3DFil_Destruct(vdm_D3DFil*
p);VKI_EXTERN Vint vdm_D3DFilError(vdm_D3DFil* p);VKI_EXTERN
void vdm_D3DFilSetMode(vdm_D3DFil* p,Vint mode,Vint
flag);VKI_EXTERN void vdm_D3DFilSetConvention(vdm_D3DFil*
p,VConventionType convention);VKI_EXTERN void vdm_D3DFilSetStatus(vdm_D3DFil*
p,Vint status);VKI_EXTERN void vdm_D3DFilSetIds(vdm_D3DFil*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_D3DFilGetConnect(vdm_D3DFil* p,
vis_Connect** connect);VKI_EXTERN void vdm_D3DFilSetConnect(vdm_D3DFil*
p,vis_Connect* connect);VKI_EXTERN void vdm_D3DFilSetFunction(vdm_D3DFil*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_D3DFilSetMonitorFunction(vdm_D3DFil* p,VD3DFilMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_D3DFilAbort(vdm_D3DFil*
p);VKI_EXTERN void vdm_D3DFilNumDomains(vdm_D3DFil*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_D3DFilOpen(vdm_D3DFil* p,Vint mode,Vchar* filename,
Vint type);VKI_EXTERN void vdm_D3DFilClose(vdm_D3DFil*
p);VKI_EXTERN void vdm_D3DFilAppend(vdm_D3DFil* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_D3DFilGetNumEntities(vdm_D3DFil*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_D3DFilGetLibrary(vdm_D3DFil*
p,vdm_Library** library);VKI_EXTERN void vdm_D3DFilNumDatasets(vdm_D3DFil*
p,Vint* numdatasets);VKI_EXTERN void vdm_D3DFilNumAttributes(vdm_D3DFil*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_D3DFilGetAttVal(vdm_D3DFil*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_D3DFilInqDataset(vdm_D3DFil*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_D3DFilInqAttribute(vdm_D3DFil*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_D3DFilReadDataset(vdm_D3DFil*
p,Vint idst,void* buf);VKI_EXTERN void vdm_D3DFilGetInteger(vdm_D3DFil*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_D3DFilGetString(vdm_D3DFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_D3DFilGetStringPtr(vdm_D3DFil*
p,Vint type,Vchar** string);VKI_EXTERN void vdm_D3DFilWriteModel(vdm_D3DFil*
p,vis_Model* model);VKI_EXTERN void vdm_D3DFilLibDataset(vdm_D3DFil*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_D3DFilSetString(vdm_D3DFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_D3DFilGetUnrecognizedData(vdm_D3DFil*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_D3DFilDataFun(vdm_D3DFil* p,vdm_DataFun* datafun);
VKI_EXTERN void vdm_D3DFilGetUnrecognizedDataSize(vdm_D3DFil*
p,Vint* numunrec);VKI_EXTERN void vdm_D3DFilPrintUnrecognizedData(vdm_D3DFil*
p);
#ifdef __cplusplus
}
#endif
#endif

