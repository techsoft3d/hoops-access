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
 
#ifndef PATLIB_DEF
#define PATLIB_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/gridfun.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#define PATLIB_NODAL 1
#define PATLIB_DISPLACEMENT 2
#define PATLIB_ELEMENTAL 3
#define PATLIB_TITLE_MAXNAME 83
typedef void(VPatLibMonitorFunc)(vdm_PatLib*,Vobject*);
typedef struct vdm_PatLibio { FILE* fd;Vlong ipnt;}
vdm_PatLibio;struct vdm_PatLib { Vint ierr;Vint type;
Vchar pathname[SYS_MAXPATHCHAR];Vchar filename[SYS_MAXPATHCHAR];
VConventionType conv;Vint doubpre;Vint nodata;Vint retcon;
Vint status;Vint idtyp,idoff[3],idbas[3];Vint numnp;
Vint numel;Vint nfree;Vint ndim;Vint nantyp;Vint nummat;
Vint numep;Vint numcs;Vint num1,num2;Vint id,iv,kc,
n1,n2,n3,n4,n5;Vint neuform;vdm_Library* library;vdm_PatLibio
patio;vdm_PatLibio* patioptr;Vchar stg[SYS_MAXNAME];
Vchar version[32];Vchar date[32];Vchar time[32];Vchar
title[PATLIB_TITLE_MAXNAME];Vchar subtitle1[PATLIB_TITLE_MAXNAME];
Vchar subtitle2[PATLIB_TITLE_MAXNAME];Vint nnodes;Vint
nwidth;Vfloat rrec[200];Vlong ipntrec;Vint ndof[10];
Vint numdataset;Vint ncol,icol[200];Vint rtype,restype,
sect;Vint ncmp;Vint phase;Vchar source[SYS_MAXNAME];
vis_Connect* connectset;vis_Connect* connect;vis_GridFun*
gridfun;vis_GProp* gprop;vis_IdTran* idtrannode;vis_IdTran*
idtranelem;vdm_Permute* permute;vsy_IntVec *ixv,*igv;
vsy_DblVec* cfv;Vint numelemsets;vsy_HashTable* elemsets;
Vint numnodesets;vsy_HashTable* nodesets;vsy_HashTable*
csh;vsy_HashTable* mph;vsy_HashTable* eph;vsy_HashTable*
lch;vsy_HashTable* ich;vsy_HashTable* rch;vsy_HashTable*
mch;Vint numdatasetplex;vdm_Plex* plex;VPatLibMonitorFunc*
funmon;Vobject* funobjmon;Vint abortflag;
#ifdef __cplusplus
public: VKI_EXTERN vdm_PatLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_PatLib(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN void
GetString(Vint,Vchar*);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void SetConnect(vis_Connect*);
VKI_EXTERN void GetConnect(vis_Connect**);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VPatLibMonitorFunc*,Vobject*);VKI_EXTERN
void Abort();VKI_EXTERN void NumDomains(Vchar*,Vint,
Vint*);VKI_EXTERN void Open(Vint,Vchar*,Vint);VKI_EXTERN
void Close();VKI_EXTERN void Append(Vchar*,Vint);VKI_EXTERN
void GetNumEntities(Vint,Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);
VKI_EXTERN void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void SetResultCols(Vint,Vint[]);VKI_EXTERN void SetResultType(Vint,
Vint,Vint);VKI_EXTERN void WriteModel(vis_Model*);VKI_EXTERN
void WriteState(vis_RProp*,vis_State*);VKI_EXTERN void
LibDataset(Vint,Vint);VKI_EXTERN void DataFun(vdm_DataFun*);
VKI_EXTERN void SetString(Vint,Vchar*);VKI_EXTERN void
GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_PatLib* vdm_PatLibBegin(void);VKI_EXTERN
void vdm_PatLib_Construct(vdm_PatLib* p);VKI_EXTERN
void vdm_PatLibEnd(vdm_PatLib* p);VKI_EXTERN void vdm_PatLib_Destruct(vdm_PatLib*
p);VKI_EXTERN Vint vdm_PatLibError(vdm_PatLib* p);VKI_EXTERN
void vdm_PatLibGetInteger(vdm_PatLib* p,Vint type,Vint*
ivalue);VKI_EXTERN void vdm_PatLibGetString(vdm_PatLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_PatLibSetMode(vdm_PatLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_PatLibSetConvention(vdm_PatLib*
p,VConventionType convention);VKI_EXTERN void vdm_PatLibSetStatus(vdm_PatLib*
p,Vint status);VKI_EXTERN void vdm_PatLibSetIds(vdm_PatLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_PatLibSetConnect(vdm_PatLib* p,
vis_Connect* connect);VKI_EXTERN void vdm_PatLibGetConnect(vdm_PatLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_PatLibSetFunction(vdm_PatLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_PatLibSetMonitorFunction(vdm_PatLib* p,VPatLibMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_PatLibAbort(vdm_PatLib*
p);VKI_EXTERN void vdm_PatLibNumDomains(vdm_PatLib*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_PatLibOpen(vdm_PatLib* p,Vint mode,Vchar* filename,
Vint type);VKI_EXTERN void vdm_PatLibClose(vdm_PatLib*
p);VKI_EXTERN void vdm_PatLibAppend(vdm_PatLib* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_PatLibGetNumEntities(vdm_PatLib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_PatLibGetLibrary(vdm_PatLib*
p,vdm_Library** library);VKI_EXTERN void vdm_PatLibNumDatasets(vdm_PatLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_PatLibNumAttributes(vdm_PatLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_PatLibGetAttVal(vdm_PatLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_PatLibInqDataset(vdm_PatLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_PatLibInqAttribute(vdm_PatLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_PatLibReadDataset(vdm_PatLib*
p,Vint idst,void* buff);VKI_EXTERN void vdm_PatLibSetResultCols(vdm_PatLib*
p,Vint ncols,Vint icols[]);VKI_EXTERN void vdm_PatLibSetResultType(vdm_PatLib*
p,Vint rtype,Vint restype,Vint sect);VKI_EXTERN void
vdm_PatLibWriteModel(vdm_PatLib* p,vis_Model* model);
VKI_EXTERN void vdm_PatLibWriteState(vdm_PatLib* p,
vis_RProp* rprop,vis_State* state);VKI_EXTERN void vdm_PatLibLibDataset(vdm_PatLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_PatLibSetString(vdm_PatLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_PatLibGetUnrecognizedData(vdm_PatLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_PatLibDataFun(vdm_PatLib* p,vdm_DataFun* datafun);
#ifdef __cplusplus
}
#endif
#endif

