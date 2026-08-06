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
 
#ifndef MARCLIB_DEF
#define MARCLIB_DEF
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vis/model.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
typedef void(VMarcLibMonitorFunc)(vdm_MarcLib*,Vobject*);
typedef struct vdm_MarcLibio vdm_MarcLibio;struct vdm_MarcLib
{ vdm_Library* library;Vint ierr;Vint type;Vchar path[SYS_MAXPATHCHAR];
VConventionType conv;Vint doubpre;Vint nodata;Vint retcon;
Vint status;Vint idtyp,idoff[3],idbas[3];Vint numnp;
Vint numel;Vint ndim;Vint nantyp;Vint soltyp;Vint nonlin;
Vint twotyp;Vint* npost;Vint* maxel;Vint* nstres;Vint*
nbctra;Vint* nsprng;Vint* post;Vlong* start;Vint nodesys;
Vint nprocd;Vint iproc;Vint ninc;Vint conveip;Vint onecomp;
vsy_IntHash* id1incih;vsy_Dictionary* dieres;vsy_DblVec*
histtime;vdm_MarcLibio* marcio;vdm_MarcLibio** marcios;
Vint iversion;Vchar version[16];Vchar date[17];Vchar
time[9];Vchar heading[81];Vint numdataset;vis_Connect*
connect;vis_GProp* gprop;vis_IdTran* idtrannode;vis_IdTran*
idtranelem;vdm_Permute* permute;Vint numelemsets;vsy_HashTable*
elemsets;Vint numnodesets;vsy_HashTable* nodesets;vsy_Dictionary*
esetdict;vsy_Dictionary* nsetdict;vsy_HashTable* csh;
vsy_HashTable* ash;vsy_HashTable* cpht;vsy_HashTable*
rbh;Vint numrbody;Vint numasurf;VMarcLibMonitorFunc*
funmon;Vobject* funobjmon;Vint abortflag;vsy_HashTable*
elemresht;vsy_HashTable* elemtype;vsy_HashTable* nodetype;
vsy_HashTable* noderesht;vis_IdTran* idtranl;vsy_Dictionary*
hldict;Vint nlsect;Vint sisize;Vint snsize;Vdouble*
si;Vdouble* sn;vsy_HashTable* eltypht;vis_IdTran* activeelem;
Vint maxpost;Vint maxnoderes;Vint hasrotang;Vint ndie;
vsy_IntHash* nodemap;vis_IdTran** idtrandom;Vint* numnps;
Vint* numels;vis_GridFun* gf;Vint mesh;Vint numlib;
vdm_Dataset** libs;Vint* libdsts;vdm_MarcLib* parlib;
vdm_MarcLib* curlib;Vint incnum;Vint stpnum;Vint jantyp;
Vint elmvar;Vint knod;Vint ihresp;Vint ieig;Vint iglv;
Vint setid;Vchar subtitle[80];vsy_Dictionary* resdict;
vsy_Dictionary* resdicti;vsy_HashTable* savedelemresht;
vsy_HashTable* nresht;Vint nelemres;Vint phase;Vchar
source[VDM_SOURCE_SIZE];Vint linearextrap;Vint ndieres;
#ifdef __cplusplus
public: VKI_EXTERN vdm_MarcLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_MarcLib(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN
void SetConvention(VConventionType);VKI_EXTERN void
SetStatus(Vint);VKI_EXTERN void SetIds(Vint,Vint,Vint,
Vint);VKI_EXTERN void GetConnect(vis_Connect**);VKI_EXTERN
void SetConnect(vis_Connect*);VKI_EXTERN void SetFunction(Vint,
Vfunc*,Vobject*);VKI_EXTERN void SetMonitorFunction(VMarcLibMonitorFunc*,
Vobject*);VKI_EXTERN void Abort();VKI_EXTERN void Open(Vint,
Vchar*,Vint);VKI_EXTERN void Close();VKI_EXTERN void
Append(Vchar*,Vint);VKI_EXTERN void GetNumEntities(Vint,
Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);VKI_EXTERN
void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void LibDataset(Vint,Vint);VKI_EXTERN void DataFun(vdm_DataFun*);
VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN void
GetString(Vint,Vchar*);VKI_EXTERN void NumDomains(Vchar*,
Vint,Vint*);VKI_EXTERN void SetString(Vint,Vchar*);
VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_MarcLib* vdm_MarcLibBegin(void);VKI_EXTERN
void vdm_MarcLib_Construct(vdm_MarcLib* p);VKI_EXTERN
void vdm_MarcLibEnd(vdm_MarcLib* p);VKI_EXTERN void
vdm_MarcLib_Destruct(vdm_MarcLib* p);VKI_EXTERN Vint
vdm_MarcLibError(vdm_MarcLib* p);VKI_EXTERN void vdm_MarcLibSetMode(vdm_MarcLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_MarcLibSetConvention(vdm_MarcLib*
p,VConventionType convention);VKI_EXTERN void vdm_MarcLibSetStatus(vdm_MarcLib*
p,Vint status);VKI_EXTERN void vdm_MarcLibSetIds(vdm_MarcLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_MarcLibGetConnect(vdm_MarcLib* p,
vis_Connect** connect);VKI_EXTERN void vdm_MarcLibSetConnect(vdm_MarcLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_MarcLibSetFunction(vdm_MarcLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_MarcLibSetMonitorFunction(vdm_MarcLib* p,VMarcLibMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_MarcLibAbort(vdm_MarcLib*
p);VKI_EXTERN void vdm_MarcLibOpen(vdm_MarcLib* p,Vint
mode,Vchar* filename,Vint type);VKI_EXTERN void vdm_MarcLibClose(vdm_MarcLib*
p);VKI_EXTERN void vdm_MarcLibAppend(vdm_MarcLib* p,
Vchar* filename,Vint type);VKI_EXTERN void vdm_MarcLibGetNumEntities(vdm_MarcLib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_MarcLibGetLibrary(vdm_MarcLib*
p,vdm_Library** library);VKI_EXTERN void vdm_MarcLibNumDatasets(vdm_MarcLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_MarcLibNumAttributes(vdm_MarcLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_MarcLibGetAttVal(vdm_MarcLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_MarcLibInqDataset(vdm_MarcLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_MarcLibInqAttribute(vdm_MarcLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_MarcLibReadDataset(vdm_MarcLib*
p,Vint idst,void* buf);VKI_EXTERN void vdm_MarcLibLibDataset(vdm_MarcLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_MarcLibSetString(vdm_MarcLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_MarcLibGetUnrecognizedData(vdm_MarcLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_MarcLibDataFun(vdm_MarcLib* p,vdm_DataFun*
datafun);VKI_EXTERN void vdm_MarcLibGetInteger(vdm_MarcLib*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_MarcLibGetString(vdm_MarcLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_MarcLibNumDomains(vdm_MarcLib*
p,Vchar* filename,Vint type,Vint* numdomains);
#ifdef __cplusplus
}
#endif
#endif

