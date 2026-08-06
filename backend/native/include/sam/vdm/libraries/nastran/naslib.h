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
 
#ifndef NASLIB_DEF
#define NASLIB_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/gprop.h"
#include "sam/vis/units.h"
#include "sam/vis/idtran.h"
#include "sam/vis/eprop.h"
#include "sam/vis/mprop.h"
#include "sam/vis/rcase.h"
#include "sam/vis/lcase.h"
#include "sam/vis/sprop.h"
#include "sam/vis/gridfun.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#include "sam/vdm/libraries/native/natlib.h"
#include "sam/vdm/lman.h"
#include "sam/vdm/libraries/nastran/nasdat.h"
typedef void(VNASLibMonitorFunc)(vdm_NASLib*,Vobject*);
typedef struct vdm_NASLibio vdm_NASLibio;typedef struct
vdm_NASop2io vdm_NASop2io;typedef struct vdm_XDBio vdm_XDBio;
struct vdm_NASLib { vdm_Library* library;Vint ierr;
Vchar serr[256];Vint type;Vchar path[SYS_MAXPATHCHAR];
Vint byteswap;Vint ilp64;VConventionType conv;Vint pshellt;
Vint doubpre;Vint sparser;Vint nointer;Vint stinvar;
Vint onecomp;Vint unires;Vint mapCylindricalAltToVector;
Vint onlyScalarShearPanelStress;VConventionType originalGasketStatus;
Vint eloc;Vint nodata;Vint retcon;Vint status;Vint idtyp,
idoff[3],idbas[3];Vint numadd;Vint numnp;Vint numel;
Vint nummode;Vint nfree;Vint ndim;Vint nantyp;Vint soltyp;
Vint nonlin;Vint twotyp;Vint vendor;Vfloat release;
Vint eigennorm;Vint eigennormc;Vint pidmax;Vint nddl2004;
Vint nddl2005;Vint omachpr;Vlong nczero;Vlong ncinit;
Vchar dbinit[9];Vint nsuper;vdm_NASLibio* io;Vint mix,
*ix;Vdouble* tgp;vdm_NASop2io* op2io;vdm_LMan* lman;
vdm_DataFun* dfnat;vdm_NatLib* natlib;vis_GridFun* gfop2;
Vchar natfile[SYS_MAXPATHCHAR];Vchar version[16];Vint
date[3];Vchar title[81];Vchar subtit[29];Vchar label[9];
Vint* irec;Vfloat* frec;Vint numdataset;vsy_HashTable*
csh;vsy_HashTable* eph;vsy_HashTable* mph;vsy_HashTable*
rch;vsy_HashTable* lch;vsy_HashTable* mch;vsy_List*
spl;vsy_HashTable* sph;vsy_HashTable* edh;Vint numcp;
vsy_HashTable* cph;vsy_HashTable* cpph;Vint numcycset;
vis_Connect* connectset;vis_Connect* connect;vis_GProp*
gprop;vis_Units* units;vis_GridFun* gridfun;vis_IdTran*
idtrannode;vis_IdTran* idtranelem;vis_IdTran* idtraneout;
vis_IdTran* idtrandyna;vis_IdTran* idtraninter;vis_IdTran*
idtranncols;vis_IdTran* idtranecols;vdm_Permute* permute;
vsy_Dictionary* epd;vsy_Dictionary* ecd;vis_ElemDat*
offsetvecedt;vsy_Concat* shelltk;vsy_Concat* beamof;
vsy_Concat* localvc;vsy_Concat* matervc;Vint matcidall;
vis_RCase* usetrcase[7];Vint numseloc;vis_IdTran *idseid,
*idseloc;vsy_IntHash* idsein;Vint numseconct;vsy_HashTable*
idse;Vint seid;Vint seidnotdefined;Vint processsprop;
Vint processedModel;Vint processModelextraDataSets;
Vint icatcodugs;Vint appcodsave;Vint sbcnumsave;Vint
rsoeeflag;Vint hoefflag;Vint mat4flag;Vint matnot4flag;
Vint lamaflag;Vint lamasflag,lamafflag;Vfloat rotorspeed;
Vchar rotorunits[5],rotorqual[256];Vint rotorflag;Vint
boltsequenceid;Vchar boltsequencequal[256];Vint designcycleflag;
Vint designcycle;Vint aeroflag;Vint iextdb,geom1,matk,
matm,matv;Vchar geom1x[9];Vint stresscentroid;Vint stresselemnode;
Vint toraxielemnode;Vint acousnumelem;Vint nonacousnumelem;
Vint iacoustic;Vint ncrod;Vint trmbuflag;Vint cyclicSystemId;
Vint curistp,cursbcn;vsy_IntHash* floatTimeLoadToId;
vsy_DblHash* timeLoadToId;Vint icount;vsy_IntDict* icnt;
Vdouble* materang;vsy_FltVec* fltgvs;vsy_IntDict* dictec;
vsy_IntVec* veccycle;Vint nhnode;vsy_Dictionary* hndict;
Vint nhelem;vsy_Dictionary* hedict;Vint nhtime;vsy_Dictionary*
htdict;Vint nhstep;vsy_Dictionary* hsdict;Vint nhncomp;
vsy_Dictionary* hncdict;Vint nhecomp;vsy_Dictionary*
hecdict;Vint nhmode;vsy_Dictionary* hmdict;Vint nhpanl;
vsy_Dictionary* hpdict;Vdouble modalEffectiveMassSummary[SYS_MAX_DEGREES_OF_FREEDOM];
vsy_Dictionary* effectiveMassResults;vis_IdTran* idh;
vsy_DblVec* dvh;vsy_IntVec* ivh;vis_IdTran* idtranoef;
vis_IdTran* idtranoes;vis_IdTran* idtranh;vis_IdTran*
idtranee;vis_IdTran* idtranef;vsy_Dictionary* eidd;
vsy_Dictionary* nidd;Vint nlsect;vsy_Dictionary* hldict;
vis_IdTran* idtranl;Vint nllays;vsy_Dictionary* hvdict;
vsy_IntVec* ivl;vsy_CVect* cvl;vsy_Dictionary* hadict;
vsy_Dictionary* dbdict;Vint nentdof;vsy_Dictionary*
hddict;vis_IdTran* idtrand;Vint nmatsiz;vsy_Dictionary*
hmsdict;vsy_CVect* cvms;vsy_IntVHash* intvhashms;Vint
geom2defined;Vint geom3defined;Vint geom4defined;Vint
csysdefined;Vint nodedefined;Vint eptdefined;Vint mptdefined;
Vint dynamicflag;Vint solidflag;Vint shellflag;Vint
beamflag;Vint gapflag;Vint rodflag;Vint hbdyflag;Vint
parabolicflag;Vint weldtopoflag;Vint orientnodeflag;
Vint plyflag;Vint plycornflag;Vint elemsys;Vint nodesys;
Vint bgpdtflag;Vint emtdata;Vint isol;Vint tic;Vint
nasprt;Vint phase;Vchar source[VDM_SOURCE_SIZE];Vint
numsets;vsy_HashTable* sets;Vint numelemsets;vsy_HashTable*
elemsets;Vint numnodesets;vsy_HashTable* nodesets;Vint
nentsets;vsy_HashTable* enth;Vint numdatasetplex;vdm_Plex*
plex;VNASLibMonitorFunc* funmon;Vobject* funobjmon;
Vint abortflag;Vint numlib;Vint* libdsts;vdm_NASLib*
parlib;vdm_NASLib* curlib;vsy_Dictionary* dictentries;
vsy_HashTable* subcaseinfo;vis_IdTran* intnode;vis_IdTran*
intelem;vsy_HashTable* idelem;vsy_HashTable* pcompext;
vsy_HashTable* rbepool;vsy_Dictionary* eltypedic;vsy_Dictionary*
outdic;vsy_IntVec* rbeids;vsy_IntVec* rbecni;vsy_IntVec*
rbecmi;vsy_DblVec* rbewgt;vsy_FltVec* eigenvalue;vsy_FltVec*
eigenfreq;vsy_FltVec* loadfact;vsy_FltVec* genmass;
vsy_FltVec* genstif;vsy_IntVec* order;vis_IdTran* idtranbase;
vsy_IntHash* ihelem;vsy_IntVec* eqexineiv;Vint pidint;
Vint classtype;Vint analtype;Vint shelloffsetflag;Vint
partid;Vint setid;Vint icat;Vint complexeigenflag;Vchar
cname[9];vsy_Dictionary* resdict;vsy_FltVec* timefv;
Vfloat transtol;vdm_XDBio* xio;vsy_HashTable* gpfpnodeindexht;
vsy_HashTable* gpfpid2ht;vsy_IntHash* fiberih;void*
h5;vsy_Dictionary* resdat;vsy_HashTable* dht;vsy_IntHash*
scsol;vsy_HashTable* titht;vsy_HashTable* subht;vsy_HashTable*
labht;Vint pinflags;Vlong schema;Vint maxglis1,maxglis2;
Vint *ia_glis1,*ia_glis2;Vint maxdbl1,maxdbl2;Vdouble
*a_dbl1,*a_dbl2;vsy_IntHash* vonmisesih;vsy_Dictionary*
vonmisesd;vsy_IntHash* spcih;vsy_IntHash* mpcih;vsy_IntHash*
eslih;vsy_IntHash* totih;vsy_IntHash* mscstepih;
#ifdef __cplusplus
public: VKI_EXTERN vdm_NASLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_NASLib(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN void
GetString(Vint,Vchar*);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void SetConnect(vis_Connect*);
VKI_EXTERN void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN
void SetMonitorFunction(VNASLibMonitorFunc*,Vobject*);
VKI_EXTERN void Abort();VKI_EXTERN void NumDomains(Vchar*,
Vint,Vint*);VKI_EXTERN void OpenFile();VKI_EXTERN void
CloseFile();VKI_EXTERN void Open(Vint,Vchar*,Vint);
VKI_EXTERN void Close();VKI_EXTERN void Append(Vchar*,
Vint);VKI_EXTERN void GetNumEntities(Vint,Vint*);VKI_EXTERN
void GetLibrary(vdm_Library**);VKI_EXTERN void NumDatasets(Vint*);
VKI_EXTERN void NumAttributes(Vint,Vint*);VKI_EXTERN
void GetAttVal(Vint,Vint,void*);VKI_EXTERN void InqDataset(Vint,
Vchar[],Vlong*,Vint*,Vint*,Vint*);VKI_EXTERN void InqAttribute(Vint,
Vint,Vchar[],Vint*,Vint*);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN void
ReadDatasetCols(Vint,Vint,Vint[],void*,Vlong*);VKI_EXTERN
void LibDataset(Vint,Vint);VKI_EXTERN void DataFun(vdm_DataFun*);
VKI_EXTERN void AddDataset(vdm_NASDat*,vdm_Dataset*);
VKI_EXTERN void SectInit();VKI_EXTERN void SectComp(Vint,
Vint*,Vint*,Vchar[],Vint*,Vchar[]);VKI_EXTERN void Sect(vdm_Dataset*,
Vint,Vint,Vchar*,Vint,Vchar*);VKI_EXTERN void PlyRotAngComp(Vchar*,
Vint,Vchar*,Vchar[],Vint*);VKI_EXTERN void PlyRotAngRead(vdm_Dataset*,
Vfloat*);VKI_EXTERN void ElemTransform(Vint,Vint,Vint,
Vint,Vint,Vint,Vint,Vint,Vint,Vfloat[]);VKI_EXTERN void
WriteModel(vis_Model*);VKI_EXTERN void WriteState(vis_RProp*,
vis_State*);VKI_EXTERN void OpenInit(Vint*,Vint*,Vint*,
Vlong*);VKI_EXTERN void SetCoordinateSystems(vsy_HashTable*);
VKI_EXTERN void SetString(Vint,Vchar*);VKI_EXTERN void
GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_NASLib* vdm_NASLibBegin(void);VKI_EXTERN
void vdm_NASLib_Construct(vdm_NASLib* p);VKI_EXTERN
void vdm_NASLibEnd(vdm_NASLib* p);VKI_EXTERN void vdm_NASLib_Destruct(vdm_NASLib*
p);VKI_EXTERN Vint vdm_NASLibError(vdm_NASLib* p);VKI_EXTERN
void vdm_NASLibGetInteger(vdm_NASLib* p,Vint type,Vint*
ivalue);VKI_EXTERN void vdm_NASLibGetString(vdm_NASLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_NASLibSetMode(vdm_NASLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_NASLibSetConvention(vdm_NASLib*
p,VConventionType convention);VKI_EXTERN void vdm_NASLibSetStatus(vdm_NASLib*
p,Vint status);VKI_EXTERN void vdm_NASLibSetIds(vdm_NASLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_NASLibSetConnect(vdm_NASLib* p,
vis_Connect* connect);VKI_EXTERN void vdm_NASLibSetFunction(vdm_NASLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_NASLibSetMonitorFunction(vdm_NASLib* p,VNASLibMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_NASLibAbort(vdm_NASLib*
p);VKI_EXTERN void vdm_NASLibNumDomains(vdm_NASLib*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_NASLibOpenFile(vdm_NASLib* p);VKI_EXTERN void
vdm_NASLibCloseFile(vdm_NASLib* p);VKI_EXTERN void vdm_NASLibOpen(vdm_NASLib*
p,Vint mode,Vchar* filename,Vint type);VKI_EXTERN void
vdm_NASLibClose(vdm_NASLib* p);VKI_EXTERN void vdm_NASLibAppend(vdm_NASLib*
p,Vchar* filename,Vint type);VKI_EXTERN void vdm_NASLibGetNumEntities(vdm_NASLib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_NASLibGetLibrary(vdm_NASLib*
p,vdm_Library** library);VKI_EXTERN void vdm_NASLibNumDatasets(vdm_NASLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_NASLibNumAttributes(vdm_NASLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_NASLibGetAttVal(vdm_NASLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_NASLibInqDataset(vdm_NASLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_NASLibInqAttribute(vdm_NASLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_NASLibGetConnect(vdm_NASLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_NASLibReadDataset(vdm_NASLib*
p,Vint idst,void* buf);VKI_EXTERN void vdm_NASLibReadDatasetCols(vdm_NASLib*
p,Vint idst,Vint ncols,Vint cols[],void* buf,Vlong*
lptr);VKI_EXTERN void vdm_NASLibLibDataset(vdm_NASLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_NASLibSetString(vdm_NASLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_NASLibGetUnrecognizedData(vdm_NASLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_NASLibDataFun(vdm_NASLib* p,vdm_DataFun* datafun);
VKI_EXTERN void vdm_NASLibAddDataset(vdm_NASLib* p,
vdm_NASDat* nasdat,vdm_Dataset* dataset);VKI_EXTERN
void vdm_NASLibAddAttr(vdm_Dataset* dataset,Vchar* tit,
Vchar* stit,Vchar* lab,Vint cplx,Vint clnk,Vint istrn,
Vchar* dbname);VKI_EXTERN void vdm_NASLibSectInit(vdm_NASLib*
p);VKI_EXTERN void vdm_NASLibSectComp(vdm_NASLib* p,
Vint nlent,Vint* lreccent,Vint* lrecelno,Vchar dssect[],
Vint* laysflag,Vchar dslays[]);VKI_EXTERN void vdm_NASLibSect(vdm_NASLib*
p,vdm_Dataset* dataset,Vint ind,Vint nstep,Vchar* dssect,
Vint laysflag,Vchar* dslays);VKI_EXTERN void vdm_NASLibPlyRotAngComp(vdm_NASLib*
p,Vchar* dnsect,Vint laysflag,Vchar* dnlays,Vchar dnrota[],
Vint* flag);VKI_EXTERN void vdm_NASLibPlyRotAngRead(vdm_NASLib*
p,vdm_Dataset* dsrota,Vfloat* fbuf);VKI_EXTERN Vfloat
vdm_NASLibminus(Vint cplx,Vfloat gp);VKI_EXTERN void
vdm_NASLibElemTransform(vdm_NASLib* p,Vint n,Vint ecode,
Vint elrescs,Vint cflag,Vint corde,Vint csopt,Vint ncmp,
Vint istr,Vint cplx,Vfloat fb[]);VKI_EXTERN void vdm_NASLibWriteModel(vdm_NASLib*
p,vis_Model* model);VKI_EXTERN void vdm_NASLibWriteState(vdm_NASLib*
p,vis_RProp* rprop,vis_State* state);VKI_EXTERN void
vdm_NASLibOpenInit(vdm_NASLib* p,Vint* numnp,Vint* numel,
Vint* maxnpe,Vlong* lngec);VKI_EXTERN void vdm_NASLibSetCoordinateSystems(vdm_NASLib*
p,vsy_HashTable* coordinatesystems);
#ifdef __cplusplus
}
#endif
#endif

