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
 
#ifndef TECPLOTLIB_DEF
#define TECPLOTLIB_DEF
#include <stdio.h>
#include "sam/base/basedefs.h"
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#include "sam/vdm/libraries/tecplot/tecplotdat.h"
#include "sam/vdm/libraries/native/natlib.h"
#include "sam/vdm/lman.h"
#define TECPLOTLIB_MERGESHAPE 1
typedef void(VTecplotLibMonitorFunc)(vdm_TecplotLib*,
Vobject*);typedef struct vdm_TecplotLibio vdm_TecplotLibio;
struct vdm_TecplotLib { Vint ierr;Vint type;Vchar path[SYS_MAXPATHCHAR];
VConventionType conv;Vint doubpre;Vint doubres;Vint
nodata;Vint retcon;Vint status;Vint idtyp,idoff[3],
idbas[3];Vint numnp;Vint numel;Vint nfree;Vint ndim;
Vint nantyp;Vint soltyp;Vint twotyp;Vint mergeshape;
Vint convertpoly;Vchar xyznam[3][256];vdm_LMan* lman;
vdm_DataFun* dfnat;vdm_Library* lbnat;vdm_NatLib* natlib;
Vchar natfile[SYS_MAXPATHCHAR];vis_Model* model;vsy_HashTable
*znhash,*znnode;Vint nummodelz;Vint numstates;vsy_Dictionary*
zsdict;vsy_List* zslist;vsy_IntDict* zddict;Vint numvar,
*varloc,*varfmt;Vint* varzsd;Vchar version[5];Vint iver;
Vchar title[2049];Vint numdataset;vdm_Library* library;
vdm_TecplotLibio* io;vsy_IntDict* intdictvar;Vint numzone;
vsy_HashTable* hashzone;Vlong* lncvar;Vint* shrvar;
Vint* pasvar;Vint nonshar;Vint* sharzone;Vint* stepzone;
Vint numstep;vis_Connect* connectset;vis_GProp* gprop;
vis_Connect* connect;vsy_IntHash* interht;Vint numdatasetplex;
vdm_Plex* plex;VTecplotLibMonitorFunc* funmon;Vobject*
funobjmon;Vint abortflag;vsy_HashTable* intvhashht;
vsy_HashTable* ivhht;Vint izone;vsy_HashTable* idtranht;
Vint* basenode;Vint numparts;vsy_IntDict* partdict;
vsy_IntHash* partih;Vint phase;Vchar source[VDM_SOURCE_SIZE];
Vfloat* time;Vint altpart;
#ifdef __cplusplus
public: VKI_EXTERN vdm_TecplotLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_TecplotLib(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN
void SetConvention(VConventionType);VKI_EXTERN void
SetStatus(Vint);VKI_EXTERN void SetIds(Vint,Vint,Vint,
Vint);VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void GetConnect(vis_Connect**);VKI_EXTERN void SetFunction(Vint,
Vfunc*,Vobject*);VKI_EXTERN void SetMonitorFunction(VTecplotLibMonitorFunc*,
Vobject*);VKI_EXTERN void Abort();VKI_EXTERN void SetCoordsNames(Vchar*,
Vchar*,Vchar*);VKI_EXTERN void Open(Vint,Vchar*,Vint);
VKI_EXTERN void Close();VKI_EXTERN void Append(Vchar*,
Vint);VKI_EXTERN void GetNumEntities(Vint,Vint*);VKI_EXTERN
void GetLibrary(vdm_Library**);VKI_EXTERN void NumDatasets(Vint*);
VKI_EXTERN void NumAttributes(Vint,Vint*);VKI_EXTERN
void GetAttVal(Vint,Vint,void*);VKI_EXTERN void InqDataset(Vint,
Vchar[],Vlong*,Vint*,Vint*,Vint*);VKI_EXTERN void InqAttribute(Vint,
Vint,Vchar[],Vint*,Vint*);VKI_EXTERN void ReadDataset(Vint,
void*);VKI_EXTERN void LibDataset(Vint,Vint);VKI_EXTERN
void DataFun(vdm_DataFun*);VKI_EXTERN void WriteModel(vis_Model*);
VKI_EXTERN void WriteState(vis_RProp*,vis_State*);VKI_EXTERN
void SetParami(Vint,Vint);VKI_EXTERN void GetInteger(Vint,
Vint*);VKI_EXTERN void GetString(Vint,Vchar*);VKI_EXTERN
void NumDomains(Vchar*,Vint,Vint*);VKI_EXTERN void SetString(Vint,
Vchar*);VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_TecplotLib* vdm_TecplotLibBegin(void);
VKI_EXTERN void vdm_TecplotLib_Construct(vdm_TecplotLib*
p);VKI_EXTERN void vdm_TecplotLibEnd(vdm_TecplotLib*
p);VKI_EXTERN void vdm_TecplotLib_Destruct(vdm_TecplotLib*
p);VKI_EXTERN Vint vdm_TecplotLibError(vdm_TecplotLib*
p);VKI_EXTERN void vdm_TecplotLibSetMode(vdm_TecplotLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_TecplotLibSetConvention(vdm_TecplotLib*
p,VConventionType convention);VKI_EXTERN void vdm_TecplotLibSetStatus(vdm_TecplotLib*
p,Vint status);VKI_EXTERN void vdm_TecplotLibSetIds(vdm_TecplotLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_TecplotLibSetConnect(vdm_TecplotLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_TecplotLibGetConnect(vdm_TecplotLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_TecplotLibSetFunction(vdm_TecplotLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_TecplotLibSetMonitorFunction(vdm_TecplotLib*
p,VTecplotLibMonitorFunc* function,Vobject* object);
VKI_EXTERN void vdm_TecplotLibAbort(vdm_TecplotLib*
p);VKI_EXTERN void vdm_TecplotLibSetCoordsNames(vdm_TecplotLib*
p,Vchar* xname,Vchar* yname,Vchar* zname);VKI_EXTERN
void vdm_TecplotLibOpen(vdm_TecplotLib* p,Vint mode,
Vchar* filename,Vint type);VKI_EXTERN void vdm_TecplotLibClose(vdm_TecplotLib*
p);VKI_EXTERN void vdm_TecplotLibAppend(vdm_TecplotLib*
p,Vchar* filename,Vint type);VKI_EXTERN void vdm_TecplotLibGetNumEntities(vdm_TecplotLib*
p,Vint enttype,Vint* nument);VKI_EXTERN void vdm_TecplotLibGetLibrary(vdm_TecplotLib*
p,vdm_Library** library);VKI_EXTERN void vdm_TecplotLibNumDatasets(vdm_TecplotLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_TecplotLibNumAttributes(vdm_TecplotLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_TecplotLibGetAttVal(vdm_TecplotLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_TecplotLibInqDataset(vdm_TecplotLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_TecplotLibInqAttribute(vdm_TecplotLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_TecplotLibReadDataset(vdm_TecplotLib*
p,Vint idst,void* buf);VKI_EXTERN void vdm_TecplotLibLibDataset(vdm_TecplotLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_TecplotLibSetString(vdm_TecplotLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_TecplotLibGetUnrecognizedData(vdm_TecplotLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_TecplotLibDataFun(vdm_TecplotLib* p,vdm_DataFun*
datafun);VKI_EXTERN void vdm_TecplotLibWriteModel(vdm_TecplotLib*
p,vis_Model* model);VKI_EXTERN void vdm_TecplotLibWriteState(vdm_TecplotLib*
p,vis_RProp* rprop,vis_State* state);VKI_EXTERN void
vdm_TecplotLibSetParami(vdm_TecplotLib* p,Vint type,
Vint iparam);VKI_EXTERN void vdm_TecplotLibGetInteger(vdm_TecplotLib*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_TecplotLibGetString(vdm_TecplotLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_TecplotLibNumDomains(vdm_TecplotLib*
p,Vchar* filename,Vint type,Vint* numdomains);
#ifdef __cplusplus
}
#endif
#endif

