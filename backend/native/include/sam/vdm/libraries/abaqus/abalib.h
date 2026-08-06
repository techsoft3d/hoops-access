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
 
#ifndef ABALIB_DEF
#define ABALIB_DEF
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#include "sam/vis/model.h"
#define ABALIB_UPGRADEODB 1
#define ABALIB_UPGRADEODBAUTO 2
#define ABA_OUTELEM_WHOLE -2
#define ABA_OUTELEMNODE_WHOLE -3
#define ABA_ROTANGELEM -4
#define ABA_ROTANGELEMNODE -5
#define ABA_ROTANGELEMEIP -6
#define ABA_OUTELEM_FACE -7
#define ABA_OUTELEM_EDGE -8
#define ABA_SML 1.0e-20
#define ABA_SMLTRUN(s)(s)> ABA_SML ? (s): (s)< -ABA_SML\
? (s): 0.
typedef void(VABALibMonitorFunc)(vdm_ABALib*,Vobject*);
#ifdef VKI_LIBAPI_ABAODB
typedef struct vdm_ABAinst { Vint numnpi;Vint numeli;
Vint nnp1,nnp2;Vint nel1,nel2;Vint numinst;vis_IdTran*
idtrannode;vis_IdTran* idtranelem;Vchar name[256];Vint
isdisplay;Vint ref1;Vint ref2;Vint ref3;}vdm_ABAinst;
#endif
typedef struct vdm_ABALibio vdm_ABALibio;struct vdm_ABALib
{ vdm_Library* library;Vint ierr;Vint type;Vchar path[SYS_MAXPATHCHAR];
VConventionType conv;Vint doubpre;Vint doubres;Vint
nodata;Vint unires;Vint uniresuse;Vint retcon;Vint status;
Vint onecomp;Vint nosets;Vint sectnum;Vint noclose;
Vint deferredReadingMode;Vint idtyp,idoff[3],idbas[3];
Vint byteswap;Vint numnp;Vint numel;Vint nfree;Vint
ndim;Vint nantyp;Vint soltyp;Vint nonlin;Vint twotyp;
Vint solidnum;Vint shellnum;Vint beamnum;Vint hasdisplay;
Vint phase;Vchar source[VDM_SOURCE_SIZE];vdm_ABALibio*
abaio;vdm_LMan* lman;vdm_DataFun* dfnat;vdm_NatLib*
natlib;vis_GridFun* gffil;Vchar natfile[SYS_MAXPATHCHAR];
Vdouble savtime;Vdouble savtimestep;Vdouble savamplitude;
Vchar subtitle[256];vsy_IntVec* icix;vsy_IntVec* icixp;
Vchar version[17];Vchar date[17];Vchar time[9];Vchar
heading[81];Vchar label[1024];Vchar label1[1024];Vchar
sublabel[1024];Vchar program[81];Vint istrn;Vint icmp,
kcmp,combine;Vint cplx,clnk;Vint iglv;Vfloat gv[7];
Vint ndof[30];Vint* irec;Vdouble* drec;Vint numdataset;
Vlong nbzero;Vint upgradeflag;Vint upgradeAutoFlag;
Vchar upgradeSuffix[SYS_MAXNAME];Vint newsets;Vint*
elsetid;Vint* elsetidsorted;Vint numsprop;Vchar* unknown;
#ifdef VKI_LIBAPI_ABAODB
void* podb;void* elements;void* ncolnodeset;void* ncolelemset;
Vint* elemsetflag;Vint* nodesetflag;Vint nodeseterror;
Vint elemseterror;vis_IdTran* idtranncols;vis_IdTran*
idtranecols;Vint numinst;vsy_IntVec* nodeInst;vsy_IntVec*
nodeIndex;vsy_IntVec* elemInst;vsy_IntVec* elemIndex;
vsy_Dictionary* dict;vdm_ABAinst** abainst;Vint numelemparts;
vsy_HashTable* elemparts;Vint numnodeparts;vsy_HashTable*
nodeparts;vsy_List* hlist;vsy_Dictionary* hndict;vsy_Dictionary*
hedict;vsy_HashTable* edh;Vint dimension;Vchar fieldName[SYS_MAXPATHCHAR];
Vint nelsets;vis_IdTran* uid;Vint numpid;Vint numtid;
Vint matlid;Vint numcsys;vsy_List* spl;vsy_HashTable*
eph;vsy_Dictionary* epdict;vsy_HashTable* mph;vsy_Dictionary*
mpdict;vsy_HashTable* tch;vis_GridFun* gfed;vsy_HashTable*
csh;Vchar assemname[256];vsy_List* saveds;Vint newstep;
Vint emtcid;Vint emtvec;vsy_Dictionary* hstepdict;Vint
nhiststeps;Vint nh;Vint dimtype;vsy_IntDict* sectid;
vsy_HashTable* sectht;Vint nsectdict;vsy_Dictionary*
ligroupdic;vsy_IntVHash* nintvhash;vsy_IntVHash* eintvhash;
Vint numrbody;vsy_HashTable* rbh;
#endif
vis_Connect* connect;vis_GProp* gprop;vis_IdTran* idtrannode;
vis_IdTran* idtranelem;vis_IdTran* idtransminn;vis_IdTran*
idtransmaxn;vis_IdTran* idtrannodeshell;Vint nlsect;
vsy_Dictionary* hldict;vis_IdTran* idtranl;vsy_Dictionary*
hgdict;vis_Group* groupl;vis_Group* idxegroup;Vint nllays;
vsy_Dictionary* hvdict;vsy_CVect* cvl;vdm_Permute* permute;
Vint numelemsets;vsy_HashTable* elemsets;vsy_HashTable*
elemsetsref;Vint numnodesets;vsy_HashTable* nodesets;
vsy_HashTable* nodesetsref;Vint numelementsets;vsy_HashTable*
elementsets;Vint numdatasetplex;vdm_Plex* plex;VABALibMonitorFunc*
funmon;Vobject* funobjmon;Vint abortflag;Vint incnumber;
Vint curframe;Vint framenumber;Vint stepnumber;vsy_IntDict*
recnodal;vsy_IntDict* recelem;vsy_IntDict* dofnodal;
Vint activedofs[30];Vint csys;Vint elemcent;Vint conveip;
Vint numrotange;Vint numrotangel;Vint numrotangeip;
Vint *ndiv,*ksec,*tptr,*tdat;Vint framezero;Vint nointpt;
vsy_IntDict* instDict;Vfloat (*tm)[3][3];Vint numasurf;
vsy_HashTable* ash;vsy_Dictionary* asurfdict;vsy_Dictionary*
librarydic;Vint inframe;vsy_List* liblist;vsy_Dictionary*
lidict;Vint ncreatedsets;Vchar filename[SYS_MAXPATHCHAR];
Vint altpart;vsy_IntHash* ithpartid;Vint assempartid;
Vint assempartindex;vsy_IntVHash* elemivh;Vint libtype;
Vint nointernalsets;Vint noHistoryOutput;VConventionType
noFieldOutput;Vint resstate;Vchar cachedDatasetWithDeferredIndexName[SYS_MAXNAME];
void* cachedBufferOfDatasetWithDeferredIndex;vis_IdTran*
cachedDeferredIndex;
#ifdef __cplusplus
public: VKI_EXTERN vdm_ABALib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_ABALib(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN void
GetString(Vint,Vchar*);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VABALibMonitorFunc*,Vobject*);VKI_EXTERN
void Abort();VKI_EXTERN Vint Monitor();VKI_EXTERN void
NumDomains(Vchar*,Vint,Vint*);VKI_EXTERN void Open(Vint,
Vchar*,Vint);VKI_EXTERN void Close();VKI_EXTERN void
Append(Vchar*,Vint);VKI_EXTERN void GetNumEntities(Vint,
Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);VKI_EXTERN
void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void ReadDatasetCols(Vint,Vint,Vint[],void*,Vlong*);
VKI_EXTERN void UpgradeOdb(Vchar*,Vchar*);VKI_EXTERN
void LibDataset(Vint,Vint);VKI_EXTERN void DataFun(vdm_DataFun*);
VKI_EXTERN void WriteModel(vis_Model*);VKI_EXTERN void
WriteState(vis_RProp*,vis_State*);VKI_EXTERN void Sect(vdm_Dataset*,
Vint);VKI_EXTERN void Term();VKI_EXTERN void SetString(Vint,
Vchar*);VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_ABALib* vdm_ABALibBegin(void);VKI_EXTERN
void vdm_ABALib_Construct(vdm_ABALib* p);VKI_EXTERN
void vdm_ABALibEnd(vdm_ABALib* p);VKI_EXTERN void vdm_ABALib_Destruct(vdm_ABALib*
p);VKI_EXTERN Vint vdm_ABALibError(vdm_ABALib* p);VKI_EXTERN
void vdm_ABALibGetInteger(vdm_ABALib* p,Vint type,Vint*
param);VKI_EXTERN void vdm_ABALibGetString(vdm_ABALib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_ABALibSetMode(vdm_ABALib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_ABALibSetConvention(vdm_ABALib*
p,VConventionType convention);VKI_EXTERN void vdm_ABALibSetStatus(vdm_ABALib*
p,Vint status);VKI_EXTERN void vdm_ABALibSetIds(vdm_ABALib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_ABALibGetConnect(vdm_ABALib* p,
vis_Connect** connect);VKI_EXTERN void vdm_ABALibSetConnect(vdm_ABALib*
p,vis_Connect* connect);VKI_EXTERN void vdm_ABALibSetFunction(vdm_ABALib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_ABALibSetMonitorFunction(vdm_ABALib* p,VABALibMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_ABALibAbort(vdm_ABALib*
p);VKI_EXTERN Vint vdm_ABALibMonitor(vdm_ABALib* p);
VKI_EXTERN void vdm_ABALibNumDomains(vdm_ABALib* p,
Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_ABALibOpen(vdm_ABALib* p,Vint mode,Vchar* filename,
Vint type);VKI_EXTERN void vdm_ABALibClose(vdm_ABALib*
p);VKI_EXTERN void vdm_ABALibAppend(vdm_ABALib* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_ABALibGetNumEntities(vdm_ABALib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_ABALibGetLibrary(vdm_ABALib*
p,vdm_Library** library);VKI_EXTERN void vdm_ABALibNumDatasets(vdm_ABALib*
p,Vint* numdatasets);VKI_EXTERN void vdm_ABALibNumAttributes(vdm_ABALib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_ABALibGetAttVal(vdm_ABALib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_ABALibInqDataset(vdm_ABALib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_ABALibInqAttribute(vdm_ABALib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_ABALibReadDataset(vdm_ABALib*
p,Vint idst,void* buf);VKI_EXTERN void vdm_ABALibReadDatasetCols(vdm_ABALib*
p,Vint idst,Vint ncols,Vint cols[],void* buf,Vlong*
lptr);VKI_EXTERN void vdm_ABALibUpgradeOdb(vdm_ABALib*
p,Vchar* odbpath,Vchar* newodbpath);VKI_EXTERN void
vdm_ABALibLibDataset(vdm_ABALib* p,Vint oper,Vint idst);
VKI_EXTERN void vdm_ABALibSetString(vdm_ABALib* p,Vint
type,Vchar* cvalue);VKI_EXTERN void vdm_ABALibGetUnrecognizedData(vdm_ABALib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_ABALibDataFun(vdm_ABALib* p,vdm_DataFun* datafun);
VKI_EXTERN void vdm_ABALibWriteModel(vdm_ABALib* p,
vis_Model* model);VKI_EXTERN void vdm_ABALibWriteState(vdm_ABALib*
p,vis_RProp* rprop,vis_State* state);VKI_EXTERN void
vdm_ABALibSect(vdm_ABALib* p,vdm_Dataset* dataset,Vint
enfl);VKI_EXTERN void vdm_ABALibElemType(Vint shape,
Vint maxi,Vint maxj,Vint maxk,Vint analtype,Vint etype,
Vint feaspec,Vint featwod,Vchar ename[9],Vint* iredir);
VKI_EXTERN void vdm_ABALibTerm(vdm_ABALib* p);
#ifdef __cplusplus
}
#endif
#endif

