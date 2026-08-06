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
 
#ifndef ANSLIB_DEF
#define ANSLIB_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/state.h"
#include "sam/vis/group.h"
#include "sam/vis/connect.h"
#include "sam/vis/units.h"
#include "sam/vis/gprop.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#define ANSLIB_SEARCH_OFF 0
#define ANSLIB_SEARCH_CDB 1
typedef void(VANSLibMonitorFunc)(vdm_ANSLib*,Vobject*);
typedef struct vdm_ANSFilio vdm_ANSFilio;typedef struct
vdm_ANSLibio vdm_ANSLibio;struct vdm_ANSLib { vdm_Library*
library;Vfloat release;Vint irelease;Vint ierr;Vint
charswap;Vint hostswap;Vint baseflag;Vint type;VConventionType
conv;Vint partIdType;Vint doubpre;Vint doubres;Vint
onecomp;Vint nodata;Vint retcon;Vint status;Vint idtyp,
idoff[3],idbas[3];Vint numnp;Vint numel;Vint nfree;
Vint ndim;Vint nantyp;Vint soltyp;Vint nonlin;Vint twotyp;
Vlong lngec;Vint maxnpe;vdm_ANSLibio* ansio;Vchar version[5];
Vchar date[17];Vchar time[17];Vchar title[81];Vint ndof[24];
Vint maxds;Vint mrec;Vint* irec;Vdouble* drec;Vint numdataset;
Vint phase;Vchar source[VDM_SOURCE_SIZE];Vint suffix;
Vint antyp;Vint rechdr;Vint recend;Vint recds;Vint rectim;
Vint recls;Vint receid;Vint recnid;Vint recgeo;Vint
reccyc;Vint recety,recrel,recnod,recsys,recelm;Vint
nsets;Vint maxety;Vuint (*solrec)[2];Vint* solnum;Vint
sprs6flag;Vint dynaflag;Vchar* ca_reconn;Vshort* sa_rouelm;
Vint* ia_exttyp;Vint* ia_secnum;Vint numety;Vint numrl;
Vint numcsy;Vint numsec;Vint mapflag;Vint nmatprop;
Vuint ptrrel[2];Vint* erlrec;Vint* erldef;Vint* iferef;
Vint* etyref;Vint* etyrou;Vint (*etykey)[13];Vint* etydof;
Vint* etynpe;Vint* etyfor;Vint* etystr;Vuint (*elmsol)[2];
Vint maxrl;Vint maxcs;Vint nnod;vis_State* nodrot;vis_Group*
nodrfl;Vint anglelinkflag;Vchar anglelinkname[256];
Vint angleplylinkflag;Vchar angleplylinkname[256];vsy_HashTable*
hashcsys;vsy_Dictionary* csd;vis_Connect* connect;vis_GridFun*
gridfun;vis_GProp* gprop;vis_Units* units;vis_IdTran*
idtrannode;vis_IdTran* idtranelem;vis_IdTran* idtrannsd;
vis_IdTran* idtranesd;vsy_HashTable* rch;vsy_HashTable*
edh;vis_ElemDat* elemdatang;vis_ElemDat* elemdatthk;
vsy_HashTable* eph;vsy_HashTable* mph;Vint nlsect;vsy_Dictionary*
hldict;vis_IdTran* idtranl;vis_IdTran* idtrant;vis_IdTran*
idtranncols;vis_IdTran* idtranecols;vis_IdTran* idtranCentroidECR;
Vint searchcdb;Vchar filecdb[SYS_MAXPATHCHAR];vdm_ANSFilio*
cdbio;Vint numelemsets;vsy_HashTable* elemsets;Vint
numnodesets;vsy_HashTable* nodesets;vsy_Dictionary*
nsetdict;vsy_Dictionary* esetdict;vis_Group* activenodes;
vis_Group* activeelems;Vint numdatasetplex;vdm_Plex*
plex;VANSLibMonitorFunc* funmon;Vobject* funobjmon;
Vint abortflag;
#ifdef __cplusplus
public: VKI_EXTERN vdm_ANSLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_ANSLib(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN void
GetString(Vint,Vchar*);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VANSLibMonitorFunc*,Vobject*);VKI_EXTERN
void Abort();VKI_EXTERN void NumDomains(Vchar*,Vint,
Vint*);VKI_EXTERN void SetSearch(Vint);VKI_EXTERN void
SetSearchPath(Vint,Vchar*);VKI_EXTERN void Open(Vint,
Vchar*,Vint);VKI_EXTERN void Close();VKI_EXTERN void
Append(Vchar*,Vint);VKI_EXTERN void GetNumEntities(Vint,
Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);VKI_EXTERN
void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void ReadDatasetCols(Vint,Vint,Vint[],void*,Vlong*);
VKI_EXTERN void LibDataset(Vint,Vint);VKI_EXTERN void
DataFun(vdm_DataFun*);VKI_EXTERN void SetString(Vint,
Vchar*);VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_ANSLib* vdm_ANSLibBegin(void);VKI_EXTERN
void vdm_ANSLib_Construct(vdm_ANSLib* p);VKI_EXTERN
void vdm_ANSLibEnd(vdm_ANSLib* p);VKI_EXTERN void vdm_ANSLib_Destruct(vdm_ANSLib*
p);VKI_EXTERN Vint vdm_ANSLibError(vdm_ANSLib* p);VKI_EXTERN
void vdm_ANSLibGetInteger(vdm_ANSLib* p,Vint type,Vint*
ivalue);VKI_EXTERN void vdm_ANSLibGetString(vdm_ANSLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_ANSLibSetMode(vdm_ANSLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_ANSLibSetConvention(vdm_ANSLib*
p,VConventionType convention);VKI_EXTERN void vdm_ANSLibSetStatus(vdm_ANSLib*
p,Vint status);VKI_EXTERN void vdm_ANSLibSetIds(vdm_ANSLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_ANSLibGetConnect(vdm_ANSLib* p,
vis_Connect** connect);VKI_EXTERN void vdm_ANSLibSetConnect(vdm_ANSLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_ANSLibSetFunction(vdm_ANSLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_ANSLibSetMonitorFunction(vdm_ANSLib* p,VANSLibMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_ANSLibAbort(vdm_ANSLib*
p);VKI_EXTERN void vdm_ANSLibNumDomains(vdm_ANSLib*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_ANSLibSetSearch(vdm_ANSLib* p,Vint search);
VKI_EXTERN void vdm_ANSLibSetSearchPath(vdm_ANSLib*
p,Vint search,Vchar* pathname);VKI_EXTERN void vdm_ANSLibOpen(vdm_ANSLib*
p,Vint mode,Vchar* filename,Vint type);VKI_EXTERN void
vdm_ANSLibClose(vdm_ANSLib* p);VKI_EXTERN void vdm_ANSLibAppend(vdm_ANSLib*
p,Vchar* filename,Vint type);VKI_EXTERN void vdm_ANSLibGetNumEntities(vdm_ANSLib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_ANSLibGetLibrary(vdm_ANSLib*
p,vdm_Library** library);VKI_EXTERN void vdm_ANSLibNumDatasets(vdm_ANSLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_ANSLibNumAttributes(vdm_ANSLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_ANSLibGetAttVal(vdm_ANSLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_ANSLibInqDataset(vdm_ANSLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_ANSLibInqAttribute(vdm_ANSLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_ANSLibReadDataset(vdm_ANSLib*
p,Vint idst,void* buf);VKI_EXTERN void vdm_ANSLibReadDatasetCols(vdm_ANSLib*
p,Vint idst,Vint ncols,Vint cols[],void* buf,Vlong*
lptr);VKI_EXTERN void vdm_ANSLibLibDataset(vdm_ANSLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_ANSLibSetString(vdm_ANSLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_ANSLibGetUnrecognizedData(vdm_ANSLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_ANSLibDataFun(vdm_ANSLib* p,vdm_DataFun* datafun);
#ifdef __cplusplus
}
#endif
#endif

