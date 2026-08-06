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
 
#ifndef ANSFIL_DEF
#define ANSFIL_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/units.h"
#include "sam/vis/idtran.h"
#include "sam/vis/gridfun.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#include "sam/vdm/unrecognizeddata.h"
#define ANSFIL_NUMRESTYPES 12
#define ANSFIL_CONTROLCARDS 1
#define ANSFIL_NUMUNREC -1
#define ANSFIL_LINENUM -2
#define ANSFIL_UNRECTYPE -3
#define ANSFIL_UNRECCARD -4
#define ANSFIL_UNRECKEYWORD -5
#define ANSFIL_UNRECFORMAT -6
#define ANSFIL_UNRECDATALINE -7
#define ANSFIL_UNRECPARAM -8
#define ANSFIL_UNRECREFER -9
 
#define ANSFIL_MAXSIZE 257
#define ANSFIL_MAXELEMENTNODE 81
typedef void(VANSFilMonitorFunc)(vdm_ANSFil*,Vobject*);
typedef struct vdm_ANSFilio vdm_ANSFilio;struct vdm_ANSFil
{ Vint ierr;Vint type;Vchar filename[SYS_MAXPATHCHAR];
VConventionType conv;Vint nodata;Vint retcon;Vint status;
Vint idtyp,idoff[3],idbas[3];Vint numnp;Vint numel;
Vint nfree;Vint ndim;Vint numcs;Vint numcp;Vint nantyp;
Vint soltyp;Vint twotyp;Vint nonlin;Vint largestrain;
Vdouble timestep;Vdouble timeStepMin;Vdouble timeStepMax;
Vdouble nonlinearDisplacementTolerance;Vdouble nonlinearReactionForceTolerance;
Vdouble nonlinearEnergyTolerance;Vint iterMax;Vint doubpre;
Vint altpart;Vint nonzeroz;Vint controlcards;Vint negtshap;
Vint targetOrContactElementsToProcess;Vint neigen;Vdouble
leigen,reigen;Vint phase;Vchar source[VDM_SOURCE_SIZE];
vis_CoordSys* acsys;vis_CoordSys* esys;vdm_Library*
library;vdm_ANSFilio* io;Vchar title[SYS_MAXNAMECHAR];
Vchar subtitle[SYS_MAXNAMECHAR];Vchar label[SYS_MAXNAMECHAR];
Vchar destinationfile[SYS_MAXNAMECHAR];Vint systemflag;
vsy_CSystem* system;Vchar keyword[ANSFIL_MAXSIZE];vsy_CSystem*
csystem;Vint numelemsets;vsy_HashTable* elemsets;Vint
numnodesets;vsy_HashTable* nodesets;vsy_Dictionary*
nsetdict;vsy_Dictionary* esetdict;vsy_Dictionary* intdict;
vsy_Dictionary* surfdict;vsy_Dictionary* afactdict;
vsy_HashTable* csh;vsy_Dictionary* csd;vsy_HashTable*
cpht;vsy_HashTable* cpPropsetHt;Vint numpid;vsy_HashTable*
eph;vsy_HashTable* mph;vis_MProp* curmprop;vis_EProp*
cureprop;vsy_HashTable* edh;Vint stepflag;Vint numsid;
vsy_List* spl;Vint numprnt,numfile;Vint curprnt[ANSFIL_NUMRESTYPES];
Vint curfile[ANSFIL_NUMRESTYPES];Vint curtprnt[ANSFIL_NUMRESTYPES];
Vint curtfile[ANSFIL_NUMRESTYPES];Vint resultImportedAsLoad;
Vchar importResultFile[SYS_MAXNAME];Vint importResultStep;
Vint numrid;vsy_HashTable* rch;vis_RCase* rcase;vis_LCase*
lcase;Vint numlid;Vint newrcase;Vint newlcase;vsy_HashTable*
lch;Vint curnce;Vint curnts;Vint nummpcid;vsy_HashTable*
mch;Vint numtid;vsy_HashTable* tch;Vint numicid;vsy_HashTable*
ich;Vint shlthk;Vint ersvec;Vint emtcid;Vint emtvec;
Vint trefid;Vint orientationNodesFound;vis_Connect*
connect;vis_GridFun* gridfun;vis_Units* units;vis_GProp*
gprop;vis_IdTran* idtrannode;vis_IdTran* idtranelem;
Vint numdatasetplex;vdm_Plex* plex;VANSFilMonitorFunc*
funmon;Vobject* funobjmon;Vint abortflag;vsy_IntVec*
mpcids;vsy_IntVec* mpcdof;vsy_DblVec* mpcval;vdm_UnrecognizedData*
unrecognizedData;vis_IdTran* idtrantype;vsy_HashTable*
hashkeyword;vsy_HashTable* hashparam;vsy_HashTable*
hashparamval;vis_Group* activenodes;vis_Group* activeelems;
vsy_HashTable* realhash;vsy_HashTable* sechash;vsy_HashTable*
opthash;vsy_IntDict* pidnames;vsy_IntHash* piddefined;
Vint curreal;Vint cursec;Vint cursecoffsetflag;Vchar
cursecoffsetloca[256];Vint mat;vsy_IntHash* matIds;
Vint real;Vint secnum;Vint tshap;Vint itype;Vint bodyid;
Vchar bodyname[256];vsy_Dictionary* matprop;Vint mptempnum;
Vint mptempcur;vsy_List* mptemplist;vsy_IntDict* mptempdict;
vsy_DblVec* activemptemp;Vint activemptempzero;Vdouble
refTempMaterial;vsy_Dictionary* matpropFromTb;Vdouble
activeTbTemperature;Vchar activeTbCommand[256];vsy_IntHash*
cphash;Vint structural;Vint thermal;Vint electrical;
Vint magnetic;Vint fluid;Vint activedofs[32];Vchar errordata[ANSFIL_MAXSIZE];
Vint numsdim;vsy_Dictionary* sdim;vsy_HashTable* ash;
#ifdef __cplusplus
public: VKI_EXTERN vdm_ANSFil(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_ANSFil(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void GetString(Vint,Vchar*);VKI_EXTERN void
SetParami(Vint,Vint);VKI_EXTERN void SetMode(Vint,Vint);
VKI_EXTERN void SetConvention(VConventionType);VKI_EXTERN
void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,Vint,
Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VANSFilMonitorFunc*,Vobject*);VKI_EXTERN
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
Vchar**);VKI_EXTERN void WriteModel(vis_Model*);VKI_EXTERN
void LibDataset(Vint,Vint);VKI_EXTERN void DataFun(vdm_DataFun*);
VKI_EXTERN void PrintUnrecognizedData();VKI_EXTERN void
SetString(Vint,Vchar*);VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_ANSFil* vdm_ANSFilBegin(void);VKI_EXTERN
void vdm_ANSFil_Construct(vdm_ANSFil* p);VKI_EXTERN
void vdm_ANSFilEnd(vdm_ANSFil* p);VKI_EXTERN void vdm_ANSFil_Destruct(vdm_ANSFil*
p);VKI_EXTERN Vint vdm_ANSFilError(vdm_ANSFil* p);VKI_EXTERN
void vdm_ANSFilGetString(vdm_ANSFil* p,Vint type,Vchar*
cvalue);VKI_EXTERN void vdm_ANSFilSetParami(vdm_ANSFil*
p,Vint ptype,Vint iparam);VKI_EXTERN void vdm_ANSFilSetMode(vdm_ANSFil*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_ANSFilSetConvention(vdm_ANSFil*
p,VConventionType convention);VKI_EXTERN void vdm_ANSFilSetStatus(vdm_ANSFil*
p,Vint status);VKI_EXTERN void vdm_ANSFilSetIds(vdm_ANSFil*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_ANSFilGetConnect(vdm_ANSFil* p,
vis_Connect** connect);VKI_EXTERN void vdm_ANSFilSetConnect(vdm_ANSFil*
p,vis_Connect* connect);VKI_EXTERN void vdm_ANSFilSetFunction(vdm_ANSFil*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_ANSFilSetMonitorFunction(vdm_ANSFil* p,VANSFilMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_ANSFilAbort(vdm_ANSFil*
p);VKI_EXTERN void vdm_ANSFilNumDomains(vdm_ANSFil*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_ANSFilOpen(vdm_ANSFil* p,Vint mode,Vchar* filename,
Vint type);VKI_EXTERN void vdm_ANSFilClose(vdm_ANSFil*
p);VKI_EXTERN void vdm_ANSFilAppend(vdm_ANSFil* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_ANSFilGetNumEntities(vdm_ANSFil*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_ANSFilGetLibrary(vdm_ANSFil*
p,vdm_Library** library);VKI_EXTERN void vdm_ANSFilNumDatasets(vdm_ANSFil*
p,Vint* numdatasets);VKI_EXTERN void vdm_ANSFilNumAttributes(vdm_ANSFil*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_ANSFilGetAttVal(vdm_ANSFil*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_ANSFilInqDataset(vdm_ANSFil*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_ANSFilInqAttribute(vdm_ANSFil*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_ANSFilReadDataset(vdm_ANSFil*
p,Vint idst,void* buf);VKI_EXTERN void vdm_ANSFilGetInteger(vdm_ANSFil*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_ANSFilGetStringPtr(vdm_ANSFil*
p,Vint type,Vchar** string);VKI_EXTERN void vdm_ANSFilEPropName(vis_EProp*
eprop,Vchar key[],Vint id,Vchar name[]);VKI_EXTERN void
vdm_ANSFilWriteModel(vdm_ANSFil* p,vis_Model* model);
VKI_EXTERN void vdm_ANSFilLibDataset(vdm_ANSFil* p,
Vint oper,Vint idst);VKI_EXTERN void vdm_ANSFilSetString(vdm_ANSFil*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_ANSFilGetUnrecognizedData(vdm_ANSFil*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_ANSFilDataFun(vdm_ANSFil* p,vdm_DataFun* datafun);
VKI_EXTERN void vdm_ANSFilPrintUnrecognizedData(vdm_ANSFil*
p);VKI_EXTERN void vdm_ANSFilaliasElement(Vint rouelm,
Vint* keyptr,Vint shape,Vint* reconn,Vint nix,Vint ix[]);
#ifdef __cplusplus
}
#endif
#endif

