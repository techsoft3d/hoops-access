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
 
#ifndef OPENFOAMLIB_DEF
#define OPENFOAMLIB_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vis/connect.h"
#define OPENFOAMLIB_SEARCH_DEFAULT 0
#define OPENFOAMLIB_SEARCH_RECONSTRUCT 1
typedef void(VOpenFOAMLibMonitorFunc)(vdm_OpenFOAMLib*,
Vobject*);struct vdm_OpenFOAMLib { Vint ierr;Vint type;
Vchar filename[SYS_MAXPATHCHAR];Vchar sysfile[SYS_MAXPATHCHAR];
Vchar rootfile[SYS_MAXPATHCHAR];Vchar root[SYS_MAXPATHCHAR];
Vchar skippedpolyMesh[SYS_MAXPATHCHAR];Vint skippolyMesh;
VConventionType conv;Vint doubpre;Vint doubres;Vint
noparinter;Vint wallinter;Vint nodata;Vint nosets;Vint
retcon;Vint status;Vint numnp;Vint numel;Vint numcell;
Vint nentgroups;Vint numdatasets;Vint numelemsets;Vint
numnodesets;Vint numielemsets;Vint swap;Vint firsttime;
vsy_HashTable* elemsets;vsy_HashTable* ielemsets;vsy_HashTable*
nodesets;vsy_HashTable* enth;vsy_Dictionary* enthdic;
vsy_Dictionary* regenthdic;vis_Connect* connect;vis_GProp*
gprop;vdm_Library* library;vsy_HashTable* bound;vsy_IntDict*
resdict;vsy_RegExp* regexp;vsy_HashTable* timenamesht;
vsy_HashTable* boundaryht;vsy_Dictionary* bounddic;
vsy_Dictionary* elemsetdic;vsy_Dictionary* nodesetdic;
VOpenFOAMLibMonitorFunc* funmon;Vobject* funobjmon;
Vint abortflag;Vint iproc;Vint nproc;Vint* timemeshflag;
Vchar meshstep[256];Vint numlib;vdm_Dataset** libs;
Vint* libdsts;vdm_OpenFOAMLib* parlib;vdm_OpenFOAMLib*
curlib;vsy_IntVec* pointiv;vsy_IntVec* faceiv;Vint prec;
Vint ndisfaces;Vint ndispoints;Vint ndiscells;Vint numfaceiv;
vsy_Dictionary* filnames;vsy_IntDict* regionid;Vint
numregion;vsy_Dictionary* polyMeshDic;Vint usetimemesh;
Vfloat meshtime;vsy_Dictionary* pointivdic;vsy_Dictionary*
faceivdic;vsy_Dictionary* cellivdic;Vint numparts;Vchar
func[80];vsy_List* dictlist;Vint phase;Vchar source[SYS_MAXPATHCHAR];
Vchar includeEtcPath[SYS_MAXPATHCHAR];Vint checknumdomains;
Vint usedomain;vsy_IntDict* regionpartid;vsy_VHashTable*
nparticlesht;vsy_IntVHash* nparticlesih;vis_IdTran*
idtranequiv;Vint haspointproc;Vint search;Vint is64;
Vobject** polyorder;vsy_IntDict* regioncount;vsy_VHashTable*
allpmvht;Vint nregions;
#ifdef __cplusplus
public: VKI_EXTERN vdm_OpenFOAMLib(void);VKI_EXTERN
void* operator new(size_t);VKI_EXTERN ~vdm_OpenFOAMLib(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN
void SetConvention(VConventionType);VKI_EXTERN void
SetStatus(Vint);VKI_EXTERN void SetIds(Vint,Vint,Vint,
Vint);VKI_EXTERN void GetConnect(vis_Connect**);VKI_EXTERN
void SetConnect(vis_Connect*);VKI_EXTERN void SetFunction(Vint,
Vfunc*,Vobject*);VKI_EXTERN void SetMonitorFunction(VOpenFOAMLibMonitorFunc*,
Vobject*);VKI_EXTERN void Abort();VKI_EXTERN void Open(Vint,
Vchar*,Vint);VKI_EXTERN void Close();VKI_EXTERN void
Append(Vchar*,Vint);VKI_EXTERN void GetNumEntities(Vint,
Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);VKI_EXTERN
void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void WriteModel(vis_Model*);VKI_EXTERN
void LibDataset(Vint,Vint);VKI_EXTERN void DataFun(vdm_DataFun*);
VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN void
GetInteger(Vint,Vint*);VKI_EXTERN void GetString(Vint,
Vchar*);VKI_EXTERN void NumDomains(Vchar*,Vint,Vint*);
VKI_EXTERN void SetSearch(Vint);VKI_EXTERN void SetString(Vint,
Vchar*);VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_OpenFOAMLib* vdm_OpenFOAMLibBegin(void);
VKI_EXTERN void vdm_OpenFOAMLib_Construct(vdm_OpenFOAMLib*
p);VKI_EXTERN void vdm_OpenFOAMLibEnd(vdm_OpenFOAMLib*
p);VKI_EXTERN void vdm_OpenFOAMLib_Destruct(vdm_OpenFOAMLib*
p);VKI_EXTERN Vint vdm_OpenFOAMLibError(vdm_OpenFOAMLib*
p);VKI_EXTERN void vdm_OpenFOAMLibSetMode(vdm_OpenFOAMLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_OpenFOAMLibSetConvention(vdm_OpenFOAMLib*
p,VConventionType convention);VKI_EXTERN void vdm_OpenFOAMLibSetStatus(vdm_OpenFOAMLib*
p,Vint status);VKI_EXTERN void vdm_OpenFOAMLibSetIds(vdm_OpenFOAMLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_OpenFOAMLibGetConnect(vdm_OpenFOAMLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_OpenFOAMLibSetConnect(vdm_OpenFOAMLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_OpenFOAMLibSetFunction(vdm_OpenFOAMLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_OpenFOAMLibSetMonitorFunction(vdm_OpenFOAMLib*
p,VOpenFOAMLibMonitorFunc* function,Vobject* object);
VKI_EXTERN void vdm_OpenFOAMLibAbort(vdm_OpenFOAMLib*
p);VKI_EXTERN void vdm_OpenFOAMLibOpen(vdm_OpenFOAMLib*
p,Vint mode,Vchar* filename,Vint type);VKI_EXTERN void
vdm_OpenFOAMLibClose(vdm_OpenFOAMLib* p);VKI_EXTERN
void vdm_OpenFOAMLibAppend(vdm_OpenFOAMLib* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_OpenFOAMLibGetNumEntities(vdm_OpenFOAMLib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_OpenFOAMLibGetLibrary(vdm_OpenFOAMLib*
p,vdm_Library** library);VKI_EXTERN void vdm_OpenFOAMLibNumDatasets(vdm_OpenFOAMLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_OpenFOAMLibNumAttributes(vdm_OpenFOAMLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_OpenFOAMLibGetAttVal(vdm_OpenFOAMLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_OpenFOAMLibInqDataset(vdm_OpenFOAMLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_OpenFOAMLibInqAttribute(vdm_OpenFOAMLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_OpenFOAMLibWriteModel(vdm_OpenFOAMLib*
p,vis_Model* model);VKI_EXTERN void vdm_OpenFOAMLibLibDataset(vdm_OpenFOAMLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_OpenFOAMLibDataFun(vdm_OpenFOAMLib*
p,vdm_DataFun* datafun);VKI_EXTERN void vdm_OpenFOAMLibReadDataset(vdm_OpenFOAMLib*
p,Vint idst,void* buff);VKI_EXTERN void vdm_OpenFOAMLibGetInteger(vdm_OpenFOAMLib*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_OpenFOAMLibGetString(vdm_OpenFOAMLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_OpenFOAMLibNumDomains(vdm_OpenFOAMLib*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_OpenFOAMLibSetString(vdm_OpenFOAMLib* p,Vint
type,Vchar* cvalue);VKI_EXTERN void vdm_OpenFOAMLibGetUnrecognizedData(vdm_OpenFOAMLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_OpenFOAMLibSetSearch(vdm_OpenFOAMLib* p,Vint
search);
#ifdef __cplusplus
}
#endif
#endif

