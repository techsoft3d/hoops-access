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
 
#ifndef SDRCLIB_DEF
#define SDRCLIB_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/units.h"
#include "sam/vis/gprop.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
typedef void(VSDRCLibMonitorFunc)(vdm_SDRCLib*,Vobject*);
typedef struct _SDRCio { FILE* fd;Vint binflag;Vint
budflag;Vint byteswap;Vint sizelong;}vdm_SDRCio;struct
vdm_SDRCLib { vdm_Library* library;Vint ierr;Vint type;
VConventionType conv;Vint doubpre;Vint sparser;Vint
onecomp;Vint nodata;Vint retcon;Vint status;Vint idtyp,
idoff[3],idbas[3];Vint numadd;Vint binflag;Vint budflag;
Vint byteswap;Vint numnp;Vint numel;Vint numcs;Vint
nfree;Vint ndim;Vint nantyp;Vint soltyp;Vint nonlin;
Vint twotyp;Vint nodesys;Vint shellflag;Vint thickflag;
Vint maxpid;Vint maxeid;vdm_SDRCio sdrcio,*io;Vchar
filename[SYS_MAXPATHCHAR];Vchar title[81];Vchar subtitle[81];
Vchar program[81];Vchar time[11];Vchar date[11];Vchar
version[6];Vint iver,irel;Vint colormapflag;Vfloat colormap[16][3];
Vint numdataset;vdm_SDRCLib* openlib;Vint phase;Vchar
source[VDM_SOURCE_SIZE];Vchar* screv;vsy_HashTable*
csh;vsy_HashTable* eph;vsy_HashTable* bsh;vsy_HashTable*
mph;vsy_HashTable* rch;vsy_HashTable* lch;vis_Connect*
connectset;vis_Connect* connect;vis_GProp* gprop;vis_Units*
units;vis_GridFun* gridfun;vis_IdTran* idtrannode;vis_IdTran*
idtranelem;vis_IdTran* idtranncols;vis_IdTran* idtranecols;
vdm_Permute* permute;Vint numelemsets;vsy_HashTable*
elemsets;Vint numnodesets;vsy_HashTable* nodesets;vsy_IntDict*
tsdict;Vint tmgescflag;Vint tmgescstep;Vint actranflag;
Vint actrantype;Vint pegasusflag;Vint advdurflag;vis_IdTran*
idtransymm;Vint nsymm;vsy_IntVec* ivsymmlab;vsy_IntVec*
ivsymmcid;vsy_IntVec* ivsymmnsc;Vint nhnode;vsy_Dictionary*
hndict;Vint nhelem;vsy_Dictionary* hedict;vis_IdTran*
idtranh;Vint nlsect;vsy_Dictionary* hldict;vis_IdTran*
idtranl;Vfloat *val,*pval;Vint nllays;vsy_Dictionary*
hvdict;vsy_CVect* cvl;Vint numdatasetplex;vdm_Plex*
plex;VSDRCLibMonitorFunc* funmon;Vobject* funobjmon;
Vint abortflag;
#ifdef __cplusplus
public: VKI_EXTERN vdm_SDRCLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_SDRCLib(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN
void GetString(Vint,Vchar*);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN void SetStatus(Vint);
VKI_EXTERN void SetIds(Vint,Vint,Vint,Vint);VKI_EXTERN
void SetOpenLib(Vobject*);VKI_EXTERN void SetConnect(vis_Connect*);
VKI_EXTERN void GetConnect(vis_Connect**);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VSDRCLibMonitorFunc*,Vobject*);VKI_EXTERN
void Abort();VKI_EXTERN void NumDomains(Vchar*,Vint,
Vint*);VKI_EXTERN void Open(Vint,Vchar*,Vint);VKI_EXTERN
void Close();VKI_EXTERN void Append(Vchar*,Vint);VKI_EXTERN
void GetNumEntities(Vint,Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);
VKI_EXTERN void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void ReadDatasetCols(Vint,Vint,Vint[],void*,Vlong*);
VKI_EXTERN void LibDataset(Vint,Vint);VKI_EXTERN void
DataFun(vdm_DataFun*);VKI_EXTERN void WriteModel(vis_Model*);
VKI_EXTERN void WriteState(vis_RProp*,vis_State*);VKI_EXTERN
void SetString(Vint,Vchar*);VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_SDRCLib* vdm_SDRCLibBegin(void);VKI_EXTERN
void vdm_SDRCLib_Construct(vdm_SDRCLib* p);VKI_EXTERN
void vdm_SDRCLibEnd(vdm_SDRCLib* p);VKI_EXTERN void
vdm_SDRCLib_Destruct(vdm_SDRCLib* p);VKI_EXTERN Vint
vdm_SDRCLibError(vdm_SDRCLib* p);VKI_EXTERN void vdm_SDRCLibGetInteger(vdm_SDRCLib*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_SDRCLibGetString(vdm_SDRCLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_SDRCLibSetConvention(vdm_SDRCLib*
p,VConventionType convention);VKI_EXTERN void vdm_SDRCLibSetMode(vdm_SDRCLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_SDRCLibSetStatus(vdm_SDRCLib*
p,Vint status);VKI_EXTERN void vdm_SDRCLibSetIds(vdm_SDRCLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_SDRCLibSetOpenLib(vdm_SDRCLib* p,
Vobject* openlib);VKI_EXTERN void vdm_SDRCLibSetConnect(vdm_SDRCLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_SDRCLibGetConnect(vdm_SDRCLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_SDRCLibSetFunction(vdm_SDRCLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_SDRCLibSetMonitorFunction(vdm_SDRCLib* p,VSDRCLibMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_SDRCLibAbort(vdm_SDRCLib*
p);VKI_EXTERN void vdm_SDRCLibNumDomains(vdm_SDRCLib*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_SDRCLibOpen(vdm_SDRCLib* p,Vint mode,Vchar*
filename,Vint type);VKI_EXTERN void vdm_SDRCLibClose(vdm_SDRCLib*
p);VKI_EXTERN void vdm_SDRCLibAppend(vdm_SDRCLib* p,
Vchar* filename,Vint type);VKI_EXTERN void vdm_SDRCLibGetNumEntities(vdm_SDRCLib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_SDRCLibGetLibrary(vdm_SDRCLib*
p,vdm_Library** library);VKI_EXTERN void vdm_SDRCLibNumDatasets(vdm_SDRCLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_SDRCLibNumAttributes(vdm_SDRCLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_SDRCLibGetAttVal(vdm_SDRCLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_SDRCLibInqDataset(vdm_SDRCLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_SDRCLibInqAttribute(vdm_SDRCLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_SDRCLibReadDataset(vdm_SDRCLib*
p,Vint idst,void* buf);VKI_EXTERN void vdm_SDRCLibReadDatasetCols(vdm_SDRCLib*
p,Vint idst,Vint ncols,Vint cols[],void* buf,Vlong*
lptr);VKI_EXTERN void vdm_SDRCLibLibDataset(vdm_SDRCLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_SDRCLibSetString(vdm_SDRCLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_SDRCLibGetUnrecognizedData(vdm_SDRCLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_SDRCLibDataFun(vdm_SDRCLib* p,vdm_DataFun*
datafun);VKI_EXTERN void vdm_SDRCLibWriteModel(vdm_SDRCLib*
p,vis_Model* model);VKI_EXTERN void vdm_SDRCLibWriteState(vdm_SDRCLib*
p,vis_RProp* rprop,vis_State* state);
#ifdef __cplusplus
}
#endif
#endif

