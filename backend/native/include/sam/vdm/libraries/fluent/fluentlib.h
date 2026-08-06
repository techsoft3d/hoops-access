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
 
#ifndef FLUENTLIB_DEF
#define FLUENTLIB_DEF
#include <stdio.h>
#include "sam/base/basedefs.h"
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vis/gprop.h"
#include "sam/vis/units.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#include "sam/vdm/libraries/fluent/fluentdat.h"
typedef void(VFLUENTLibMonitorFunc)(vdm_FLUENTLib*,
Vobject*);typedef struct vdm_FLUENTLibio vdm_FLUENTLibio;
typedef struct vis_FLUENTLwt vis_FLUENTLwt; typedef
struct vdm_FLUENTLibz { Vint enttype;Vint first_index;
Vint last_index;Vint type;Vchar* name;void* uprop;Vint
nuprop;Vint first_id;}vdm_FLUENTLibz;struct vdm_FLUENTLib
{ Vint ierr;Vint type;Vchar filename[SYS_MAXPATHCHAR];
Vchar fileroot[SYS_MAXPATHCHAR];VConventionType conv;
Vint nodata;Vint retcon;Vint doubpre;Vint doubres;Vint
wallinter;Vint status;Vint idtyp,idoff[3],idbas[3];
Vint numnp;Vint numel;Vint nfree;Vint ndim;Vint nantyp;
Vint soltyp;Vint twotyp;Vint nonlin;Vint numcells;Vint
numfaces;Vint *ic0f,*ic1f;Vshort* bctypef;Vint* zoneidf;
Vint *parid,*chlid;Vint timestep;Vfloat flowtime;Vchar
version[13];Vchar date[32];Vchar time[32];Vchar title[81];
Vint numdataset;vdm_Library* library;vdm_FLUENTLibio*
io;Vint phase;Vchar source[VDM_SOURCE_SIZE];vis_Connect*
connectset;vis_Connect* connect;vis_GProp* gprop;vis_Units*
units;vis_IdTran* idtranface;Vint* ia_cell;Vchar* ic_inactive;
vis_Connect* connectf;vis_IdTran* idtranf;Vint numfa;
vsy_IntVec* intfn;Vint* ia_fn;vsy_IntHash* zones;vsy_HashTable*
zhtab;Vint numelemsets;vsy_HashTable* elemsets;Vint
numidtrans;vsy_HashTable* enth;Vint sindex;Vint binfmt;
Vchar svstg[256];Vint lasntyp;Vint curntyp;Vint cursubsectid;
Vint curenttype;Vchar lasdname[DATASET_MAXNAME];Vchar
curdname[DATASET_MAXNAME];vdm_Dataset* curentdataset;
vdm_FLUENTDat* curfluentdat;Vint nhelem;vsy_Dictionary*
hedict;Vint numelement;vis_IdTran* idtranh;Vint numdatasetplex;
vdm_Plex* plex;VFLUENTLibMonitorFunc* funmon;Vobject*
funobjmon;Vint abortflag;vsy_IntDict* stepdict;vis_FLUENTLwt*
fluentlwt;Vint nummat;vsy_HashTable* mph;Vint numprp;
vsy_HashTable* eph;vsy_IntDict* matdict;vsy_Dictionary*
zonemat;vsy_IntHash* zonematid;vsy_IntHash* zoneprpid;
vsy_IntVec* domainphase;vdm_FLUENTLib* openlib;
#ifdef __cplusplus
public: VKI_EXTERN vdm_FLUENTLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_FLUENTLib(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN
void GetString(Vint,Vchar*);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void SetOpenLib(Vobject*);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void GetConnect(vis_Connect**);VKI_EXTERN void SetFunction(Vint,
Vfunc*,Vobject*);VKI_EXTERN void SetMonitorFunction(VFLUENTLibMonitorFunc*,
Vobject*);VKI_EXTERN void Abort();VKI_EXTERN void NumDomains(Vchar*,
Vint,Vint*);VKI_EXTERN void OpenFile();VKI_EXTERN void
CloseFile();VKI_EXTERN void Open(Vint,Vchar*,Vint);
VKI_EXTERN void Close();VKI_EXTERN void Append(Vchar*,
Vint);VKI_EXTERN void GetNumEntities(Vint,Vint*);VKI_EXTERN
void GetLibrary(vdm_Library**);VKI_EXTERN void NumDatasets(Vint*);
VKI_EXTERN void NumAttributes(Vint,Vint*);VKI_EXTERN
void GetAttVal(Vint,Vint,void*);VKI_EXTERN void InqDataset(Vint,
Vchar[],Vlong*,Vint*,Vint*,Vint*);VKI_EXTERN void InqAttribute(Vint,
Vint,Vchar[],Vint*,Vint*);VKI_EXTERN void ReadDataset(Vint,
void*);VKI_EXTERN void WriteModel(vis_Model*);VKI_EXTERN
void WriteState(vis_RProp*,vis_State*);VKI_EXTERN void
LibDataset(Vint,Vint);VKI_EXTERN void DataFun(vdm_DataFun*);
VKI_EXTERN void Init(vis_Model*);VKI_EXTERN void Term();
VKI_EXTERN void Dimension(Vint*);VKI_EXTERN void NumEntities(Vint*,
Vint*,Vint*);VKI_EXTERN void NumCellZone(Vint*);VKI_EXTERN
void CellZoneParam(Vint,Vint*,Vint*,Vint*,Vint*);VKI_EXTERN
void CellZoneType(Vint,Vint[]);VKI_EXTERN void CellZoneName(Vint,
Vchar[]);VKI_EXTERN void CellZoneId(Vint,Vint*);VKI_EXTERN
void NumFaceZone(Vint*);VKI_EXTERN void FaceZoneParam(Vint,
Vint*,Vint*,Vint*,Vint*);VKI_EXTERN void FaceZoneType(Vint,
Vint[]);VKI_EXTERN void FaceZoneName(Vint,Vchar[]);
VKI_EXTERN void FaceZoneId(Vint,Vint*);VKI_EXTERN void
FaceZone(Vint,Vint[],Vint[],Vint[]);VKI_EXTERN void
Node(Vdouble[]);VKI_EXTERN void SetString(Vint,Vchar*);
VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_FLUENTLib* vdm_FLUENTLibBegin(void);
VKI_EXTERN void vdm_FLUENTLib_Construct(vdm_FLUENTLib*
p);VKI_EXTERN void vdm_FLUENTLibEnd(vdm_FLUENTLib* p);
VKI_EXTERN void vdm_FLUENTLib_Destruct(vdm_FLUENTLib*
p);VKI_EXTERN Vint vdm_FLUENTLibError(vdm_FLUENTLib*
p);VKI_EXTERN void vdm_FLUENTLibGetInteger(vdm_FLUENTLib*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_FLUENTLibGetString(vdm_FLUENTLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_FLUENTLibSetMode(vdm_FLUENTLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_FLUENTLibSetConvention(vdm_FLUENTLib*
p,VConventionType convention);VKI_EXTERN void vdm_FLUENTLibSetStatus(vdm_FLUENTLib*
p,Vint status);VKI_EXTERN void vdm_FLUENTLibSetIds(vdm_FLUENTLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_FLUENTLibSetOpenLib(vdm_FLUENTLib*
p,Vobject* openlib);VKI_EXTERN void vdm_FLUENTLibSetConnect(vdm_FLUENTLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_FLUENTLibGetConnect(vdm_FLUENTLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_FLUENTLibSetFunction(vdm_FLUENTLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_FLUENTLibSetMonitorFunction(vdm_FLUENTLib*
p,VFLUENTLibMonitorFunc* function,Vobject* object);
VKI_EXTERN void vdm_FLUENTLibAbort(vdm_FLUENTLib* p);
VKI_EXTERN void vdm_FLUENTLibNumDomains(vdm_FLUENTLib*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_FLUENTLibOpenFile(vdm_FLUENTLib* p);VKI_EXTERN
void vdm_FLUENTLibCloseFile(vdm_FLUENTLib* p);VKI_EXTERN
void vdm_FLUENTLibOpen(vdm_FLUENTLib* p,Vint mode,Vchar*
filename,Vint type);VKI_EXTERN void vdm_FLUENTLibClose(vdm_FLUENTLib*
p);VKI_EXTERN void vdm_FLUENTLibAppend(vdm_FLUENTLib*
p,Vchar* filename,Vint type);VKI_EXTERN void vdm_FLUENTLibGetNumEntities(vdm_FLUENTLib*
p,Vint enttype,Vint* nument);VKI_EXTERN void vdm_FLUENTLibGetLibrary(vdm_FLUENTLib*
p,vdm_Library** library);VKI_EXTERN void vdm_FLUENTLibNumDatasets(vdm_FLUENTLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_FLUENTLibNumAttributes(vdm_FLUENTLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_FLUENTLibGetAttVal(vdm_FLUENTLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_FLUENTLibInqDataset(vdm_FLUENTLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_FLUENTLibInqAttribute(vdm_FLUENTLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_FLUENTLibReadDataset(vdm_FLUENTLib*
p,Vint idst,void* buf);VKI_EXTERN void vdm_FLUENTLibWriteModel(vdm_FLUENTLib*
p,vis_Model* model);VKI_EXTERN void vdm_FLUENTLibWriteState(vdm_FLUENTLib*
p,vis_RProp* rprop,vis_State* state);VKI_EXTERN void
vdm_FLUENTLibLibDataset(vdm_FLUENTLib* p,Vint oper,
Vint idst);VKI_EXTERN void vdm_FLUENTLibSetString(vdm_FLUENTLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_FLUENTLibGetUnrecognizedData(vdm_FLUENTLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_FLUENTLibDataFun(vdm_FLUENTLib* p,vdm_DataFun*
datafun);VKI_EXTERN void vdm_FLUENTLibInit(vdm_FLUENTLib*
p,vis_Model* model);VKI_EXTERN void vdm_FLUENTLibTerm(vdm_FLUENTLib*
p);VKI_EXTERN void vdm_FLUENTLibDimension(vdm_FLUENTLib*
p,Vint* nd);VKI_EXTERN void vdm_FLUENTLibNumEntities(vdm_FLUENTLib*
p,Vint* numcell,Vint* numface,Vint* numnode);VKI_EXTERN
void vdm_FLUENTLibNumCellZone(vdm_FLUENTLib* p,Vint*
numcellzone);VKI_EXTERN void vdm_FLUENTLibCellZoneParam(vdm_FLUENTLib*
p,Vint ithcellzone,Vint* ifirst,Vint* ilast,Vint* type,
Vint* etype);VKI_EXTERN void vdm_FLUENTLibCellZoneType(vdm_FLUENTLib*
p,Vint ithcellzone,Vint type[]);VKI_EXTERN void vdm_FLUENTLibCellZoneName(vdm_FLUENTLib*
p,Vint ithcellzone,Vchar name[]);VKI_EXTERN void vdm_FLUENTLibCellZoneId(vdm_FLUENTLib*
p,Vint ithcellzone,Vint* id);VKI_EXTERN void vdm_FLUENTLibNumFaceZone(vdm_FLUENTLib*
p,Vint* numfacezone);VKI_EXTERN void vdm_FLUENTLibFaceZoneParam(vdm_FLUENTLib*
p,Vint ithfacezone,Vint* ifirst,Vint* ilast,Vint* type,
Vint* etype);VKI_EXTERN void vdm_FLUENTLibFaceZoneType(vdm_FLUENTLib*
p,Vint ithfacezone,Vint type[]);VKI_EXTERN void vdm_FLUENTLibFaceZoneName(vdm_FLUENTLib*
p,Vint ithfacezone,Vchar name[]);VKI_EXTERN void vdm_FLUENTLibFaceZoneId(vdm_FLUENTLib*
p,Vint ithfacezone,Vint* id);VKI_EXTERN void vdm_FLUENTLibFaceZone(vdm_FLUENTLib*
p,Vint ithfacezone,Vint ixf[],Vint cl[],Vint cr[]);
VKI_EXTERN void vdm_FLUENTLibNode(vdm_FLUENTLib* p,
Vdouble x[]);
#ifdef __cplusplus
}
#endif
#endif

