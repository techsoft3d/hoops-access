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
 
#ifndef ABAFIL_DEF
#define ABAFIL_DEF
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
#include "sam/vdm/unrecognizeddata.h"
#define ABAFIL_NUMRESTYPES 32
#define ABAFIL_NUMUNREC -1
#define ABAFIL_LINENUM -2
#define ABAFIL_UNRECTYPE -3
#define ABAFIL_UNRECCARD -4
#define ABAFIL_UNRECKEYWORD -5
#define ABAFIL_UNRECPARAM -6
#define ABAFIL_UNRECPARAMVAL -7
#define ABAFIL_UNRECDATALINE -8
#define ABAFIL_UNRECFILE -9
typedef void(VABAFilMonitorFunc)(vdm_ABAFil*,Vobject*);
typedef struct vdm_ABAFilio vdm_ABAFilio;struct vdm_ABAFil
{ Vint ierr;Vint type;Vchar filename[SYS_MAXPATHCHAR];
VConventionType conv;Vint nodata;Vint retcon;Vint includeerror;
Vint status;Vint idtyp,idoff[3],idbas[3];Vint numnp;
Vint numel;Vint nfree;Vint ndim;Vint numcs;Vint numcp;
Vint nantyp;Vint soltyp;Vint twotyp;Vint nonlin;Vint
largestrain;Vint thermalstrain;Vint savefreq;Vint doubpre;
Vint nointernalsets;Vint parabolic;Vint nonlintherm;
Vint nonlinthermhist;Vint phase;Vchar source[VDM_SOURCE_SIZE];
vdm_Library* library;vdm_ABAFilio* io;Vchar heading[81];
Vchar title[81];Vchar subtitle[81];Vchar label[81];
Vchar sublabel[81];Vint systemflag;vsy_CSystem* system;
Vchar keyword[81];vsy_CSystem* csystem;vsy_CSystem*
wsystem;vsy_IntHash* edef;vsy_IntHash* ndef;Vint numelemsets;
vsy_HashTable* elemsets;Vint numnodesets;vsy_HashTable*
nodesets;Vint nentgroups;vsy_HashTable* enth;vsy_HashTable*
ash;Vint numasurf;Vint numrbody;vsy_Dictionary* nsetdict;
vsy_Dictionary* esetdict;vsy_Dictionary* intdict;vsy_Dictionary*
surfdict;vsy_IntDict* asurfdict;vsy_Dictionary* afactdict;
vsy_Dictionary* distributionFormatDict;vsy_Dictionary*
distributionDict;vsy_HashTable* csh;vsy_HashTable* cph;
vsy_HashTable* cpht;vsy_Dictionary* csd;Vint numpid;
vsy_HashTable* eph;Vint nummid;vsy_HashTable* mph;vsy_Dictionary*
mpd;vis_MProp* curmprop;vis_EProp* cureprop;vis_MProp*
curBeamGenSectionMprop;vsy_HashTable* edh;vsy_HashTable*
rbh;Vint stepflag;Vint numsid;vsy_List* spl;Vint steprid;
Vint steplid;Vint numload,lasload,newload;Vint numprnt,
numfile;Vint curprnt[ABAFIL_NUMRESTYPES];Vint curfile[ABAFIL_NUMRESTYPES];
Vint curtprnt[ABAFIL_NUMRESTYPES];Vint curtfile[ABAFIL_NUMRESTYPES];
Vint numrid;vsy_HashTable* rch;Vint numlid;vsy_HashTable*
lch;vsy_List* lchlist;Vint nummpc;Vint nummpid;vsy_HashTable*
mch;Vint numtid;vsy_HashTable* tch;vsy_Dictionary* tcurvedict;
Vint numicid;vsy_HashTable* ich;vis_State* statethk;
Vint shellthk;Vint orientationNodeFlag;Vint ersvec;
Vint emtcid;Vint emtvec;Vint trefid;Vint pinflags;vis_GProp*
gprop;vis_Connect* connect;vis_GridFun* gridfun;vdm_Permute*
permute;Vint numdatasetplex;vdm_Plex* plex;VABAFilMonitorFunc*
funmon;Vobject* funobjmon;Vint abortflag;vsy_DblVec*
dcr1;vsy_DblVec* dcr2;vsy_IntVec* icr1;vsy_IntVec* icr2;
vsy_IntVec* icr3;vsy_Calc* calc;vdm_UnrecognizedData*
unrecognizedData;vis_IdTran* idtrantype;vsy_HashTable*
hashkeyword;vsy_HashTable* hashparam;vsy_HashTable*
hashparamval;vsy_HashTable* hashfile;vsy_IntDict* cosim;
Vint ncosim;Vdouble time;vsy_Dictionary* coupling;Vchar
curcoupname[81];Vint numuserelem;vsy_IntDict* userelem;
vsy_IntDict* userelty;vsy_HashTable* userfet;vsy_Dictionary*
partdict;vsy_Dictionary* instdict;vdm_ABAFil* parent;
Vchar assemname[256];Vchar instname[256];Vint inassembly;
Vint ininstance;Vint inpart;Vint icreateinst;Vint emptyrcase;
void* inst;Vint hasbase;vsy_HashTable* propnameht;Vint
altpart;Vint assempartid;Vint numparts;vsy_IntDict*
partiddic;
#ifdef __cplusplus
public: VKI_EXTERN vdm_ABAFil(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_ABAFil(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VABAFilMonitorFunc*,Vobject*);VKI_EXTERN
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
Vchar*);VKI_EXTERN void GetStringPtr(Vint,Vchar*[]);
VKI_EXTERN void WriteModel(vis_Model*);VKI_EXTERN void
LibDataset(Vint,Vint);VKI_EXTERN void DataFun(vdm_DataFun*);
VKI_EXTERN void PrintUnrecognizedData();VKI_EXTERN void
SetString(Vint,Vchar*);VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_ABAFil* vdm_ABAFilBegin(void);VKI_EXTERN
void vdm_ABAFil_Construct(vdm_ABAFil* p);VKI_EXTERN
void vdm_ABAFilEnd(vdm_ABAFil* p);VKI_EXTERN void vdm_ABAFil_Destruct(vdm_ABAFil*
p);VKI_EXTERN Vint vdm_ABAFilError(vdm_ABAFil* p);VKI_EXTERN
void vdm_ABAFilSetMode(vdm_ABAFil* p,Vint mode,Vint
flag);VKI_EXTERN void vdm_ABAFilSetConvention(vdm_ABAFil*
p,VConventionType convention);VKI_EXTERN void vdm_ABAFilSetStatus(vdm_ABAFil*
p,Vint status);VKI_EXTERN void vdm_ABAFilSetIds(vdm_ABAFil*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_ABAFilGetConnect(vdm_ABAFil* p,
vis_Connect** connect);VKI_EXTERN void vdm_ABAFilSetConnect(vdm_ABAFil*
p,vis_Connect* connect);VKI_EXTERN void vdm_ABAFilSetFunction(vdm_ABAFil*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_ABAFilSetMonitorFunction(vdm_ABAFil* p,VABAFilMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_ABAFilAbort(vdm_ABAFil*
p);VKI_EXTERN void vdm_ABAFilNumDomains(vdm_ABAFil*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_ABAFilOpen(vdm_ABAFil* p,Vint mode,Vchar* filename,
Vint type);VKI_EXTERN void vdm_ABAFilClose(vdm_ABAFil*
p);VKI_EXTERN void vdm_ABAFilAppend(vdm_ABAFil* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_ABAFilGetNumEntities(vdm_ABAFil*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_ABAFilGetLibrary(vdm_ABAFil*
p,vdm_Library** library);VKI_EXTERN void vdm_ABAFilNumDatasets(vdm_ABAFil*
p,Vint* numdatasets);VKI_EXTERN void vdm_ABAFilNumAttributes(vdm_ABAFil*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_ABAFilGetAttVal(vdm_ABAFil*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_ABAFilInqDataset(vdm_ABAFil*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_ABAFilInqAttribute(vdm_ABAFil*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_ABAFilReadDataset(vdm_ABAFil*
p,Vint idst,void* buf);VKI_EXTERN void vdm_ABAFilGetInteger(vdm_ABAFil*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_ABAFilGetString(vdm_ABAFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_ABAFilGetStringPtr(vdm_ABAFil*
p,Vint type,Vchar** string);VKI_EXTERN void vdm_ABAFilEPropName(vis_EProp*
eprop,Vchar key[],Vchar elset[],Vint id);VKI_EXTERN
void vdm_ABAFilWriteModel(vdm_ABAFil* p,vis_Model* model);
VKI_EXTERN void vdm_ABAFilLibDataset(vdm_ABAFil* p,
Vint oper,Vint idst);VKI_EXTERN void vdm_ABAFilSetString(vdm_ABAFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_ABAFilGetUnrecognizedData(vdm_ABAFil*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_ABAFilDataFun(vdm_ABAFil* p,vdm_DataFun* datafun);
VKI_EXTERN void vdm_ABAFilPrintUnrecognizedData(vdm_ABAFil*
p);
#ifdef __cplusplus
}
#endif
#endif

