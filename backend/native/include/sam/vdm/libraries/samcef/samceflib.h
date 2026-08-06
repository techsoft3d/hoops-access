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
 
#ifndef SAMCEFLIB_DEF
#define SAMCEFLIB_DEF
#include <stdio.h>
#include "sam/base/basedefs.h"
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vis/units.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#include "sam/vdm/libraries/samcef/samcefdat.h"
#include "sam/vdm/permute.h"
typedef void(VSAMCEFLibMonitorFunc)(vdm_SAMCEFLib*,
Vobject*);struct vdm_SAMCEFLib { Vint ierr;Vint type;
VConventionType conv;Vint doubpre;Vint doubres;Vint
nodata;Vint retcon;Vint status;Vint idtyp,idoff[3],
idbas[3];Vint numnp;Vint numel;Vint numdataset;Vint
soltype;Vint analtype;Vint onecomp;vsy_Dictionary* analdic;
vsy_HashTable* resht;vdm_Library* library;vis_Connect*
connect;vis_GProp* gprop;Vint nlsect;vsy_Dictionary*
hldict;vsy_Dictionary* hvdict;vsy_CVect* cvl;Vint nllays;
vis_IdTran* idtranl;vsy_HashTable* nodesets;vsy_HashTable*
elemsets;Vint numelemsets;Vint numnodesets;void* samresAPI;
vsy_HashTable* globht;vsy_IntDict* id1dic;Vint nid1;
vsy_HashTable* edh;Vint numcsys;vsy_HashTable* csh;
vsy_HashTable* eph;vis_GridFun* gf;Vint* laminateptr;
Vint* laminates;Vdouble* laminateangles;Vdouble* laminaterotang;
vsy_HashTable* laminateht;vsy_HashTable* plyht;vsy_IntHash*
plylamih;Vint nrotang;vsy_HashTable* rotanght;VSAMCEFLibMonitorFunc*
funmon;Vobject* funobjmon;Vint abortflag;Vint phase;
Vchar source[SYS_MAXNAME];Vchar title[SYS_MAXNAME];
Vchar version[SYS_MAXNAME];Vchar date[SYS_MAXNAME];
Vchar tmpname[SYS_MAXPATHCHAR];vsy_IntVHash* topoivh;
vsy_HashTable* topoht;Vint ntopo;vsy_List* spl;vis_Units*
units;vdm_SAMCEFLib* parlib;vdm_SAMCEFLib* curlib;vdm_Dataset**
libs;Vint* libdsts;Vint numlib;Vchar filename[SYS_MAXPATHCHAR];
vsy_Dictionary* lidict;Vint nh;vis_IdTran* idtranncols;
vis_IdTran* idtranecols;
#ifdef __cplusplus
public: VKI_EXTERN vdm_SAMCEFLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_SAMCEFLib(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN
void SetConvention(VConventionType);VKI_EXTERN void
SetStatus(Vint);VKI_EXTERN void SetConnect(vis_Connect*);
VKI_EXTERN void GetConnect(vis_Connect**);VKI_EXTERN
void SetIds(Vint,Vint,Vint,Vint);VKI_EXTERN void SetFunction(Vint,
Vfunc*,Vobject*);VKI_EXTERN void SetMonitorFunction(VSAMCEFLibMonitorFunc*,
Vobject*);VKI_EXTERN void Abort();VKI_EXTERN void Open(Vint,
Vchar*,Vint);VKI_EXTERN void Close();VKI_EXTERN void
Append(Vchar*,Vint);VKI_EXTERN void GetNumEntities(Vint,
Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);VKI_EXTERN
void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void ReadDatasetCols(Vint,Vint,Vint[],void*,Vlong[]);
VKI_EXTERN void LibDataset(Vint,Vint);VKI_EXTERN void
DataFun(vdm_DataFun*);VKI_EXTERN void GetInteger(Vint,
Vint*);VKI_EXTERN void GetString(Vint,Vchar*);VKI_EXTERN
void NumDomains(Vchar*,Vint,Vint*);VKI_EXTERN void SetTempDir(Vchar[]);
VKI_EXTERN void SetString(Vint,Vchar*);VKI_EXTERN void
GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_SAMCEFLib* vdm_SAMCEFLibBegin(void);
VKI_EXTERN void vdm_SAMCEFLib_Construct(vdm_SAMCEFLib*
p);VKI_EXTERN void vdm_SAMCEFLibEnd(vdm_SAMCEFLib* p);
VKI_EXTERN void vdm_SAMCEFLib_Destruct(vdm_SAMCEFLib*
p);VKI_EXTERN Vint vdm_SAMCEFLibError(vdm_SAMCEFLib*
p);VKI_EXTERN void vdm_SAMCEFLibSetMode(vdm_SAMCEFLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_SAMCEFLibSetConvention(vdm_SAMCEFLib*
p,VConventionType convention);VKI_EXTERN void vdm_SAMCEFLibSetStatus(vdm_SAMCEFLib*
p,Vint status);VKI_EXTERN void vdm_SAMCEFLibSetConnect(vdm_SAMCEFLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_SAMCEFLibGetConnect(vdm_SAMCEFLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_SAMCEFLibSetIds(vdm_SAMCEFLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_SAMCEFLibSetFunction(vdm_SAMCEFLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_SAMCEFLibSetMonitorFunction(vdm_SAMCEFLib*
p,VSAMCEFLibMonitorFunc* function,Vobject* object);
VKI_EXTERN void vdm_SAMCEFLibAbort(vdm_SAMCEFLib* p);
VKI_EXTERN void vdm_SAMCEFLibOpen(vdm_SAMCEFLib* p,
Vint mode,Vchar* filename,Vint type);VKI_EXTERN void
vdm_SAMCEFLibClose(vdm_SAMCEFLib* p);VKI_EXTERN void
vdm_SAMCEFLibAppend(vdm_SAMCEFLib* p,Vchar* filename,
Vint type);VKI_EXTERN void vdm_SAMCEFLibGetNumEntities(vdm_SAMCEFLib*
p,Vint enttype,Vint* nument);VKI_EXTERN void vdm_SAMCEFLibGetLibrary(vdm_SAMCEFLib*
p,vdm_Library** library);VKI_EXTERN void vdm_SAMCEFLibNumDatasets(vdm_SAMCEFLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_SAMCEFLibNumAttributes(vdm_SAMCEFLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_SAMCEFLibGetAttVal(vdm_SAMCEFLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_SAMCEFLibInqDataset(vdm_SAMCEFLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_SAMCEFLibInqAttribute(vdm_SAMCEFLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_SAMCEFLibReadDataset(vdm_SAMCEFLib*
p,Vint idst,void* buf);VKI_EXTERN void vdm_SAMCEFLibReadDatasetCols(vdm_SAMCEFLib*
p,Vint idst,Vint ncols,Vint cols[],void* buf,Vlong lptr[]);
VKI_EXTERN void vdm_SAMCEFLibLibDataset(vdm_SAMCEFLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_SAMCEFLibSetString(vdm_SAMCEFLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_SAMCEFLibGetUnrecognizedData(vdm_SAMCEFLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_SAMCEFLibDataFun(vdm_SAMCEFLib* p,vdm_DataFun*
datafun);VKI_EXTERN void vdm_SAMCEFLibGetInteger(vdm_SAMCEFLib*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_SAMCEFLibGetString(vdm_SAMCEFLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_SAMCEFLibNumDomains(vdm_SAMCEFLib*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_SAMCEFLibSetTempDir(vdm_SAMCEFLib* p,Vchar
name[]);
#ifdef __cplusplus
}
#endif
#endif

