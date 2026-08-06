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
 
#ifndef PAMLIB_DEF
#define PAMLIB_DEF
#include <stdio.h>
#include "sam/base/basedefs.h"
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#include "sam/vdm/permute.h"
typedef void(VPAMLibMonitorFunc)(vdm_PAMLib*,Vobject*);
typedef struct { const Vchar* id;const Vchar* name;
Vint shape;Vint maxi;Vint maxj;Vint maxk;Vint perm;
}vdm_PAMLib_ERFElems;typedef struct { const Vchar* name;
Vint featype;Vint feaspec;}vdm_PAMLib_ERFSpec;typedef
struct { Vchar* name;Vint type;Vint nqua;Vint iqua[SYS_NQUA_MAX];
Vchar* cqua;}vdm_PAMLib_ERSRes;struct vdm_PAMLib { Vint
ierr;Vint type;VConventionType conv;Vint doubpre;Vint
nodata;Vint retcon;Vint status;Vint idtyp,idoff[3],
idbas[3];Vint numnp;Vint numel;Vint totelem;Vint nfree;
Vint ndim;Vint nantyp;Vint soltyp;Vint twotyp;Vint nonlin;
Vint numcells;Vint numfaces;Vint ersvec;Vint emtcid;
Vint emtvec;Vchar program[17];Vchar version[17];Vchar
date[32];Vchar time[32];Vchar title[81];Vchar subtitle[81];
Vint numdataset;vdm_Library* library;vis_Connect* connect;
vis_GProp* gprop;vis_Connect* connectf;vis_IdTran* idtrannode;
vis_IdTran* idtranelem;vis_IdTran* idtranface;Vint numdatasetplex;
vdm_Plex* plex;VPAMLibMonitorFunc* funmon;Vobject* funobjmon;
Vint abortflag;vsy_HashTable* nodesets;Vint numnodesets;
vsy_HashTable* elemsets;Vint numelemsets;vsy_HashTable*
eph;Vint solid;Vint beam;Vint shell;Vint tool;Vint nstates;
Vfloat* timelist;Vint global_var;Vint number_of_material;
Vint var_per_material;Vint number_of_section;Vint var_per_section;
Vint number_of_contact;Vint var_per_contact;Vint number_of_rigidwall;
Vint var_per_rigidwall;Vint number_of_airbag;Vint var_per_airbag;
Vchar* gvartitles;Vint numgvartit;Vint isdisp;Vint isvel;
Vint isacc;Vint isnod;Vint numnodtit;Vchar* nodtitles;
Vint numsolidvar;Vint numsolidtitle;Vchar* solidtitles;
Vint numshellvar;Vint numshelltitle;Vchar* shelltitles;
Vint numbeamvar;Vint numbeamtitle;Vchar* beamtitles;
Vfloat* globvarval;vsy_Dictionary* resdict;vsy_Dictionary*
globaldict;vsy_HashTable* math;vis_GridFun* gf;vsy_HashTable*
edh;vdm_Permute* permute;vsy_Dictionary* erfelems;vsy_Dictionary*
erfspec;vsy_Dictionary* erfresdict;vsy_Dictionary* hndict;
vsy_Dictionary* hedict;vsy_Dictionary* hsdict;vsy_Dictionary*
htdict;Vint nhnode;Vint nhelem;Vint nhstep;Vint nhtime;
vis_IdTran* idtranh;vsy_IntVec* ivh;vsy_DblVec* dvh;
Vint nlsect;vsy_Dictionary* hldict;vis_IdTran* idtranl;
vsy_CVect* cvl;vsy_Dictionary* hvdict;Vint nllays;void*
erf;Vint phase;Vchar source[VDM_SOURCE_SIZE];vis_IdTran*
idtranncols;vis_IdTran* idtranecols;
#ifdef __cplusplus
public: VKI_EXTERN vdm_PAMLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_PAMLib(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VPAMLibMonitorFunc*,Vobject*);VKI_EXTERN
void Abort();VKI_EXTERN void Open(Vint,Vchar*,Vint);
VKI_EXTERN void Close();VKI_EXTERN void Append(Vchar*,
Vint);VKI_EXTERN void GetNumEntities(Vint,Vint*);VKI_EXTERN
void GetLibrary(vdm_Library**);VKI_EXTERN void NumDatasets(Vint*);
VKI_EXTERN void NumAttributes(Vint,Vint*);VKI_EXTERN
void GetAttVal(Vint,Vint,void*);VKI_EXTERN void InqDataset(Vint,
Vchar[],Vlong*,Vint*,Vint*,Vint*);VKI_EXTERN void InqAttribute(Vint,
Vint,Vchar[],Vint*,Vint*);VKI_EXTERN void ReadDataset(Vint,
void*);VKI_EXTERN void ReadDatasetCols(Vint,Vint,Vint[],
void*,Vlong*);VKI_EXTERN void LibDataset(Vint,Vint);
VKI_EXTERN void DataFun(vdm_DataFun*);VKI_EXTERN void
WriteModel(vis_Model*);VKI_EXTERN void WriteState(vis_RProp*,
vis_State*);VKI_EXTERN void GetInteger(Vint,Vint*);
VKI_EXTERN void GetString(Vint,Vchar*);VKI_EXTERN void
NumDomains(Vchar*,Vint,Vint*);VKI_EXTERN void SetString(Vint,
Vchar*);VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_PAMLib* vdm_PAMLibBegin(void);VKI_EXTERN
void vdm_PAMLib_Construct(vdm_PAMLib* p);VKI_EXTERN
void vdm_PAMLibEnd(vdm_PAMLib* p);VKI_EXTERN void vdm_PAMLib_Destruct(vdm_PAMLib*
p);VKI_EXTERN Vint vdm_PAMLibError(vdm_PAMLib* p);VKI_EXTERN
void vdm_PAMLibSetMode(vdm_PAMLib* p,Vint mode,Vint
flag);VKI_EXTERN void vdm_PAMLibSetConvention(vdm_PAMLib*
p,VConventionType convention);VKI_EXTERN void vdm_PAMLibSetStatus(vdm_PAMLib*
p,Vint status);VKI_EXTERN void vdm_PAMLibSetIds(vdm_PAMLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_PAMLibGetConnect(vdm_PAMLib* p,
vis_Connect** connect);VKI_EXTERN void vdm_PAMLibSetConnect(vdm_PAMLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_PAMLibSetFunction(vdm_PAMLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_PAMLibSetMonitorFunction(vdm_PAMLib* p,VPAMLibMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_PAMLibAbort(vdm_PAMLib*
p);VKI_EXTERN void vdm_PAMLibOpen(vdm_PAMLib* p,Vint
mode,Vchar* filename,Vint type);VKI_EXTERN void vdm_PAMLibClose(vdm_PAMLib*
p);VKI_EXTERN void vdm_PAMLibAppend(vdm_PAMLib* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_PAMLibGetNumEntities(vdm_PAMLib*
p,Vint enttype,Vint* nument);VKI_EXTERN void vdm_PAMLibGetLibrary(vdm_PAMLib*
p,vdm_Library** library);VKI_EXTERN void vdm_PAMLibNumDatasets(vdm_PAMLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_PAMLibNumAttributes(vdm_PAMLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_PAMLibGetAttVal(vdm_PAMLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_PAMLibInqDataset(vdm_PAMLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_PAMLibInqAttribute(vdm_PAMLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_PAMLibReadDataset(vdm_PAMLib*
p,Vint idst,void* buf);VKI_EXTERN void vdm_PAMLibReadDatasetCols(vdm_PAMLib*
p,Vint idst,Vint ncols,Vint cols[],void* buf,Vlong*
lptr);VKI_EXTERN void vdm_PAMLibLibDataset(vdm_PAMLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_PAMLibSetString(vdm_PAMLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_PAMLibGetUnrecognizedData(vdm_PAMLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_PAMLibDataFun(vdm_PAMLib* p,vdm_DataFun* datafun);
VKI_EXTERN void vdm_PAMLibWriteModel(vdm_PAMLib* p,
vis_Model* model);VKI_EXTERN void vdm_PAMLibWriteState(vdm_PAMLib*
p,vis_RProp* urprop,vis_State* state);VKI_EXTERN void
vdm_PAMLibGetInteger(vdm_PAMLib* p,Vint type,Vint* ivalue);
VKI_EXTERN void vdm_PAMLibGetString(vdm_PAMLib* p,Vint
type,Vchar* cvalue);VKI_EXTERN void vdm_PAMLibNumDomains(vdm_PAMLib*
p,Vchar* filename,Vint type,Vint* numdomains);
#ifdef __cplusplus
}
#endif
#endif

