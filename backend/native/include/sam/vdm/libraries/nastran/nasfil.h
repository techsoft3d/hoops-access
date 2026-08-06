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
 
#ifndef NASFIL_DEF
#define NASFIL_DEF
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vis/gridfun.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#include "sam/vdm/unrecognizeddata.h"
#define NAS_NUMRESTYPES 17
#define NASFIL_NUMUNREC -1
#define NASFIL_LINENUM -2
#define NASFIL_UNRECTYPE -3
#define NASFIL_UNRECCARD -4
#define NASFIL_UNRECCOMMAND -5
#define NASFIL_UNRECFIELD -6
#define NASFIL_UNRECFIELDVAL -7
#define NASFIL_RELATIVEPATH 1
#define NASFIL_RIGIDPBUSHVALUE 1e11
#define NASFIL_NO_COORDINATE_SYSTEM 0
#define NASFIL_BASIC_COORDINATE_SYSTEM 1
#define NASFIL_GLOBAL_COORDINATE_SYSTEM 2
#define NASFIL_OFFSET_COORDINATE_SYSTEM 3
typedef void(VNASFilMonitorFunc)(vdm_NASFil*,Vobject*);
typedef struct vdm_NASFilio vdm_NASFilio;struct vdm_NASFil
{ Vint ierr;Vint type;Vchar filename[SYS_MAXPATHCHAR];
Vchar pathroot[SYS_MAXPATHCHAR];Vchar inclstg[SYS_MAXPATHCHAR];
Vchar compstg[256];VConventionType conv;Vint doubpre;
Vint pshellt;Vint nocomment;Vint nodata;Vint retcon;
Vint includeerror;Vint status;Vint idtyp,idoff[3],idbas[3];
Vint numnp;Vint numel;Vint nfree;Vint ndim;Vint nantyp;
Vint soltyp;Vint nonlin;Vint twotyp;Vint vendor;Vint
emtdata;Vint spttype;Vint ncrod;Vint ncshl;Vint ncsca;
Vint nconm2cid;Vint numugspe,numcgap,curcgap;Vint eidcgap,
pidcgap;Vint shpcgap,mxicgap,mxjcgap,mxkcgap,nixcgap,
ixcgap[9];Vint hmpid;Vchar hmname[256];Vint writeallres;
 Vint phase;Vchar source[VDM_SOURCE_SIZE];Vint relativepath;
Vint sol;Vchar curtitle[81];Vchar cursubtitle[81];Vchar
curlabel[81];Vint curspc;Vint curmpc;Vint curload;Vint
curtemp;Vint curtref;Vint numprnt,numfile,numpunch;
Vint curprnt[NAS_NUMRESTYPES];Vint curfile[NAS_NUMRESTYPES];
Vint curtprnt[NAS_NUMRESTYPES];Vint curtfile[NAS_NUMRESTYPES];
Vint curpunch[NAS_NUMRESTYPES];Vint curtpunch[NAS_NUMRESTYPES];
Vint subcase;Vint numcase;Vint nsoln;vsy_List* spl;
vsy_List* sload;Vint grdsetflag;Vint grdsetcp,grdsetcd,
grdsetps;Vint barorflag;Vint barorpid,barorg0;Vdouble
barorx1,barorx2,barorx3;Vint beamorflag;Vint beamorpid,
beamorg0;Vdouble beamorx1,beamorx2,beamorx3;vdm_Library*
library;vdm_NASFilio* io;vis_Connect* connect;vis_GridFun*
gridfun;vis_IdTran* idtrannode;vis_IdTran* idtranelem;
Vint numinter;vis_IdTran* idtraninter;vis_GProp* gprop;
vis_Units* units;Vint numsets;vsy_HashTable* sets;Vint
numelemsets;vsy_HashTable* elemsets;Vint numnodesets;
vsy_HashTable* nodesets;Vint nentsets;vsy_HashTable*
enth;Vint numdefelemsets;vsy_HashTable* defelemsets;
Vint numdefnodesets;vsy_HashTable* defnodesets;vsy_HashTable*
csh;Vint numcp;vsy_HashTable* cph;vsy_HashTable* cpht;
vdm_Permute* permute;vsy_HashTable* rch;vsy_HashTable*
rchd;vis_RCase* rcps;vsy_HashTable* mch;vsy_HashTable*
ihash;Vint lhashlcase;vsy_HashTable* lch;vsy_HashTable*
mph;vsy_HashTable* mthash;vsy_HashTable* eph;vsy_HashTable*
tch;vsy_HashTable* econvhash;vsy_Dictionary* epd;vsy_Dictionary*
ecd;vsy_Concat* shelltk;Vint shelloffsetflag;vsy_Concat*
beamof;vsy_Concat* localvc;vsy_Concat* matervc;vsy_Concat*
bdyconv;Vint orientnodeflag;Vint pinflags;Vint ncweld;
Vint nchbdye;Vint weldtopoflag;Vint weldconnflag;Vint
nspcadd;Vint nmpcadd;Vint nloadadd;Vint ncycadd;Vint
cyclicSystemId;Vint numcycset;vsy_IntVec *cycid,*cycnsec,
*cyccsid,*cycstgid,*cycgrpid; Vint numbcbody;vsy_HashTable*
bcbody;Vint numbsid;vsy_HashTable* bsid;vsy_List* cardrec;
Vint numdatasetplex;vdm_Plex* plex;VNASFilMonitorFunc*
funmon;Vobject* funobjmon;Vint abortflag;vsy_IntVec*
mpcids;vsy_IntVec* mpcdof;vsy_DblVec* mpcval;vsy_IntVec*
itmp1;vsy_IntVec* itmp2;vsy_DblVec* dtmp1;vsy_DblVec*
dtmp2;vdm_UnrecognizedData* unrecognizedData;vis_IdTran*
idtrantype;vsy_HashTable* hashcommand;vsy_HashTable*
hashfield;vsy_HashTable* hashfieldval;vsy_DblDict* labeledDoubles;
vsy_IntDict* labeledIntegers;vsy_IntHash* nlparmHT;
vsy_HashTable* BCTABL1IDToBCONECTIDs;vsy_IntHash* BCONECTIDToIDPRIM;
vsy_IntHash* BCONECTIDToIDSCND;vsy_IntHash* BCONECTIDToBCONPRG;
vsy_IntHash* BCONECTIDToBCONPRP;vsy_HashTable* BCONPRGProperties;
vsy_HashTable* BCONPRPProperties;vsy_IntHash* BCBODY1IDToBCPROPID;
vsy_HashTable* BCPARAProperties;
#ifdef __cplusplus
public: VKI_EXTERN vdm_NASFil(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_NASFil(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void GetString(Vint,Vchar*);VKI_EXTERN void
SetMode(Vint,Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VNASFilMonitorFunc*,Vobject*);VKI_EXTERN
void Abort();VKI_EXTERN void NumDomains(Vchar*,Vint,
Vint*);VKI_EXTERN void Open(Vint,Vchar*,Vint);VKI_EXTERN
void Close();VKI_EXTERN void Append(Vchar*,Vint);VKI_EXTERN
void GetNumEntities(Vint,Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);
VKI_EXTERN void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void GetInteger(Vint,Vint*);VKI_EXTERN void GetStringPtr(Vint,
Vchar**);VKI_EXTERN void SetParami(Vint,Vint);VKI_EXTERN
void PrintUnrecognizedData();VKI_EXTERN void WriteModel(vis_Model*);
VKI_EXTERN void WriteState(vis_RProp*,vis_State*);VKI_EXTERN
void LibDataset(Vint,Vint);VKI_EXTERN void DataFun(vdm_DataFun*);
VKI_EXTERN void SetString(Vint,Vchar*);VKI_EXTERN void
GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_NASFil* vdm_NASFilBegin(void);VKI_EXTERN
void vdm_NASFil_Construct(vdm_NASFil* p);VKI_EXTERN
void vdm_NASFilEnd(vdm_NASFil* p);VKI_EXTERN void vdm_NASFil_Destruct(vdm_NASFil*
p);VKI_EXTERN Vint vdm_NASFilError(vdm_NASFil* p);VKI_EXTERN
void vdm_NASFilGetString(vdm_NASFil* p,Vint type,Vchar*
cvalue);VKI_EXTERN void vdm_NASFilSetParami(vdm_NASFil*
p,Vint type,Vint iparam);VKI_EXTERN void vdm_NASFilSetMode(vdm_NASFil*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_NASFilSetConvention(vdm_NASFil*
p,VConventionType convention);VKI_EXTERN void vdm_NASFilSetStatus(vdm_NASFil*
p,Vint status);VKI_EXTERN void vdm_NASFilSetIds(vdm_NASFil*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_NASFilGetConnect(vdm_NASFil* p,
vis_Connect** connect);VKI_EXTERN void vdm_NASFilSetConnect(vdm_NASFil*
p,vis_Connect* connect);VKI_EXTERN void vdm_NASFilSetFunction(vdm_NASFil*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_NASFilSetMonitorFunction(vdm_NASFil* p,VNASFilMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_NASFilAbort(vdm_NASFil*
p);VKI_EXTERN void vdm_NASFilNumDomains(vdm_NASFil*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_NASFilentityPLOAD(Vint ga,Vint gb,Vint enttype,
Vint shape,Vint maxi,Vint maxj,Vint maxk,Vint ix[],
Vint* no);VKI_EXTERN void vdm_NASFilOpen(vdm_NASFil*
p,Vint mode,Vchar* filename,Vint type);VKI_EXTERN void
vdm_NASFilClose(vdm_NASFil* p);VKI_EXTERN void vdm_NASFilAppend(vdm_NASFil*
p,Vchar* filename,Vint type);VKI_EXTERN void vdm_NASFilGetNumEntities(vdm_NASFil*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_NASFilGetLibrary(vdm_NASFil*
p,vdm_Library** library);VKI_EXTERN void vdm_NASFilNumDatasets(vdm_NASFil*
p,Vint* numdatasets);VKI_EXTERN void vdm_NASFilNumAttributes(vdm_NASFil*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_NASFilGetAttVal(vdm_NASFil*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_NASFilInqDataset(vdm_NASFil*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_NASFilInqAttribute(vdm_NASFil*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_NASFilReadDataset(vdm_NASFil*
p,Vint idst,void* buf);VKI_EXTERN void vdm_NASFilGetInteger(vdm_NASFil*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_NASFilGetStringPtr(vdm_NASFil*
p,Vint type,Vchar** string);VKI_EXTERN void vdm_NASFilPrintUnrecognizedData(vdm_NASFil*
p);VKI_EXTERN void vdm_NASFilprocessSET(vsy_HashTable*
sets,vis_IdTran* idtrannode,vis_IdTran* idtranelem,
Vint* numnodesets,vsy_HashTable* nodesets,Vint* numelemsets,
vsy_HashTable* elemsets);VKI_EXTERN void vdm_NASFilprocSYMMID(vis_GProp*
gprop,vis_Connect* connect,vsy_HashTable* defelemsets);
VKI_EXTERN void vdm_NASFilprocBSURF(vsy_HashTable* enth,
vis_Connect* connect);VKI_EXTERN void vdm_NASFilprocCPair(vsy_List*
spl,vsy_HashTable* cpht,vsy_HashTable* cpph,vsy_Dictionary*
ecd,vis_Connect* connect,vsy_HashTable* enth,vsy_HashTable*
defelemsets,vsy_HashTable* defnodesets,vis_GridFun*
gridfun);VKI_EXTERN void vdm_NASFilsGRID(vis_Connect*
connect,Vint index,Vint featype,Vint id,Vint cp,Vdouble
x[3],Vint cd,Vint ps,Vint seid);VKI_EXTERN void vdm_NASFilChkPoint(Vint
type,Vint* shape,Vint* maxi,Vint ix[]);VKI_EXTERN void
vdm_NASFilsIX(vis_Connect* connect,Vint index,Vint type,
Vint id,Vint mid,Vint pid,Vint shape,Vint maxi,Vint
maxj,Vint maxk,Vint ix[]);VKI_EXTERN void vdm_NASFilsCORDT(vsy_HashTable*
csh,Vint cid,Vint type,Vdouble x[3],Vdouble tm[3][3]);
VKI_EXTERN void vdm_NASFilsCORD1(vsy_HashTable* csh,
Vint cid,Vint type,Vint iop,Vint g1,Vint g2,Vint g3);
VKI_EXTERN void vdm_NASFilsCORD2(vsy_HashTable* csh,
Vint cid,Vint type,Vint iop,Vdouble x1[3],Vdouble x2[3],
Vdouble x3[3],Vint rcid);VKI_EXTERN void vdm_NASFilsCHBDYE(vis_Connect*
connect,Vint iop,Vint eid2,Vint side,Vint* shapeCHBDYE,
Vint* maxi,Vint* maxj,Vint* maxk,Vint ixe[]);VKI_EXTERN
void vdm_NASFilsCHBDYG(Vint iop,Vint stype,Vint npe,
Vint nodes[],Vint* shape,Vint* maxi,Vint* maxj,Vint*
maxk,Vint ixe[]);VKI_EXTERN void vdm_NASFilsCHBDYP(Vint
iop,Vint stype,Vint npe,Vint nodes[],Vint gmid,Vint*
shape,Vint* maxi,Vint* maxj,Vint ixe[]);VKI_EXTERN void
vdm_NASFilsCWELD(vis_Connect* connect,Vint ein,Vint
shapea,Vint maxia,Vint shapeb,Vint maxib,Vint ga,Vint
gb);VKI_EXTERN void vdm_NASFilpSUPER(vsy_Dictionary*
epd,vsy_Dictionary* ecd,vis_Connect* connect,Vint seid);
VKI_EXTERN void vdm_NASFilpCONROD(vsy_Dictionary* epd,
vsy_Dictionary* ecd,vis_Connect* connect,Vint mid,Vdouble
a,Vdouble j,Vdouble c,Vdouble nsm);VKI_EXTERN void vdm_NASFilpCONM1(vsy_Dictionary*
epd,vsy_Dictionary* ecd,vis_Connect* connect,Vdouble
mij[21]);VKI_EXTERN void vdm_NASFilpCONM2(vsy_Dictionary*
epd,vsy_Dictionary* ecd,vis_Connect* connect,Vdouble
m,Vdouble xoff[3],Vdouble mij[21]);VKI_EXTERN void vdm_NASFilpCMASSx(vsy_Dictionary*
epd,vsy_Dictionary* ecd,vis_Connect* connect,Vint imass,
Vint pid,Vdouble ms,Vint c1,Vint c2);VKI_EXTERN void
vdm_NASFilpCELASx(vsy_Dictionary* epd,vsy_Dictionary*
ecd,vis_Connect* connect,Vint ielas,Vint pid,Vdouble
k,Vdouble ge,Vdouble s,Vint c1,Vint c2);VKI_EXTERN void
vdm_NASFilpCDAMPx(vsy_Dictionary* epd,vsy_Dictionary*
ecd,vis_Connect* connect,Vint idamp,Vint pid,Vdouble
mb,Vint c1,Vint c2);VKI_EXTERN void vdm_NASFilpRBEx(vsy_Dictionary*
epd,vsy_Dictionary* ecd,vis_Connect* connect,Vint itype,
Vint num,Vint cni[],Vint cmi[],Vdouble w[],Vdouble alpha);
VKI_EXTERN void vdm_NASFilpPSOLID(vsy_Dictionary* epd,
Vchar* name,Vint pid,Vint mid,Vint mcidflag,Vint mcid,
Vdouble t,Vdouble nsm);VKI_EXTERN void vdm_NASFilpPSHELL(vsy_Dictionary*
epd,Vint pid,Vint mid,Vint mid2,Vint mid3,Vint mid4,
Vdouble t,Vdouble nsm,Vdouble i12t3,Vdouble tst,Vint
z1flag,Vint z2flag,Vdouble z1,Vdouble z2,Vdouble zoff);
VKI_EXTERN void vdm_NASFilpPCOMP(vsy_Dictionary* epd,
Vint etype,Vint pid,Vint igid,Vdouble tot,Vdouble ecc,
Vdouble nsm,Vdouble ge,Vint nlay,Vint gid[],Vint mid[],
Vdouble thk[],Vdouble phi[],Vint mcid,Vint psdir);VKI_EXTERN
void vdm_NASFilpPSHEAR(vsy_Dictionary* epd,Vint pid,
Vint mid,Vdouble t,Vdouble nsm,Vdouble f1,Vdouble f2);
VKI_EXTERN void vdm_NASFilpPBEAM(vsy_Dictionary* epd,
Vint pid,Vint mid,Vdouble a[],Vdouble i1[],Vdouble i2[],
Vdouble i12[],Vdouble j[],Vdouble k1[],Vdouble k2[],
Vdouble cw[],Vdouble ofy[],Vdouble ofz[],Vdouble dsy[],
Vdouble dsz[],Vdouble nsm[],Vdouble cyz[2][2],Vdouble
dyz[2][2],Vdouble eyz[2][2],Vdouble fyz[2][2]);VKI_EXTERN
void vdm_NASFilpPBAR(vsy_Dictionary* epd,Vint pid,Vint
mid,Vdouble a,Vdouble i1,Vdouble i2,Vdouble i12,Vdouble
j,Vdouble k1,Vdouble k2,Vdouble nsm,Vdouble cyz[2][2],
Vdouble dyz[2][2],Vdouble eyz[2][2],Vdouble fyz[2][2]);
VKI_EXTERN void vdm_NASFilpPBEND(vsy_Dictionary* epd,
Vint pid,Vint mid,Vdouble a,Vdouble i1,Vdouble i2,Vdouble
j,Vdouble rb,Vdouble thetab,Vdouble cyz[2][2],Vdouble
dyz[2][2],Vdouble eyz[2][2],Vdouble fyz[2][2],Vdouble
k1,Vdouble k2,Vdouble nsm,Vdouble rc,Vdouble zc,Vdouble
rm,Vdouble deltan,Vint fsi,Vdouble t,Vdouble pint);
VKI_EXTERN void vdm_NASFilpPTUBE(vsy_Dictionary* epd,
Vint pid,Vint mid,Vdouble od,Vdouble t,Vdouble od2,
Vdouble nsm);VKI_EXTERN void vdm_NASFilpPSection(vsy_Dictionary*
epd,Vint ptype,Vint pid,Vint mid,Vint btype,Vdouble
dime[2][20],Vdouble nsm[],Vdouble rotang,Vint reflecty,
Vint reflectz);VKI_EXTERN void vdm_NASFilpPROD(vsy_Dictionary*
epd,Vint pid,Vint mid,Vdouble a,Vdouble j,Vdouble c,
Vdouble nsm);VKI_EXTERN void vdm_NASFilpPDAMP(vsy_Dictionary*
epd,Vint pid,Vdouble ds);VKI_EXTERN void vdm_NASFilpPELAS(vsy_Dictionary*
epd,Vint pid,Vdouble ks,Vdouble ge,Vdouble s);VKI_EXTERN
void vdm_NASFilpPMASS(vsy_Dictionary* epd,Vint pid,
Vdouble ms);VKI_EXTERN void vdm_NASFilpPBUSH(vsy_Dictionary*
epd,Vint pid,Vdouble ktra[],Vdouble krot[],Vdouble btra[],
Vdouble brot[],Vdouble dtra[],Vdouble drot[],Vdouble
sa,Vdouble st,Vdouble ea,Vdouble et);VKI_EXTERN void
vdm_NASFilpPBUSH1D(vsy_Dictionary* epd,Vint pid,Vdouble
stiffK,Vdouble viscousDampingC,Vdouble totalMassM,Vdouble
stressRecoverySA,Vdouble strainRecoverySE,Vdouble cv[2],
Vdouble expv[2],Vint tableOptions[4]);VKI_EXTERN void
vdm_NASFilpPWELD(vsy_Dictionary* epd,Vint pid,Vint mid,
Vdouble d);VKI_EXTERN void vdm_NASFilpPFAST(vsy_Dictionary*
epd,Vint pid,Vdouble d,Vdouble kt[3],Vdouble kr[3],
Vdouble ms,Vdouble ge);VKI_EXTERN void vdm_NASFilpPGAP(vsy_Dictionary*
epd,Vint pid,Vdouble u0,Vdouble f0,Vdouble ka,Vdouble
kb,Vdouble kt,Vdouble mu1,Vdouble mu2,Vdouble tmax,
Vdouble mar);VKI_EXTERN void vdm_NASFilpPVISC(vsy_Dictionary*
epd,Vint pid,Vdouble btra,Vdouble brot);VKI_EXTERN void
vdm_NASFilpPHBDY(vsy_Dictionary* epd,Vint pid,Vdouble
af);VKI_EXTERN void vdm_NASFilprocEProp(vsy_Dictionary*
epd,vsy_HashTable* eph,vis_Connect* connect);VKI_EXTERN
void vdm_NASFilmMAT1(vsy_HashTable* mph,Vint mid,Vdouble
elas[],Vdouble dens,Vdouble thermexp,Vdouble reftemp,
Vdouble ge,Vdouble st,Vdouble sc,Vdouble ss);VKI_EXTERN
void vdm_NASFilmMAT2or9(vsy_HashTable* mph,Vint mid,
Vdouble dmat[],Vdouble dens,Vdouble avec[],Vdouble reftemp,
Vdouble ge,Vdouble st,Vdouble sc,Vdouble ss);VKI_EXTERN
void vdm_NASFilmMAT3or8(vsy_HashTable* mph,Vint mid,
Vdouble ym[],Vdouble pr[],Vdouble sm[],Vdouble avec[],
Vdouble dens,Vdouble reftemp,Vdouble xt,Vdouble xc,
Vdouble yt,Vdouble yc,Vdouble s,Vdouble ge);VKI_EXTERN
void vdm_NASFilmMAT4(vsy_HashTable* mph,Vint mid,Vdouble
thermcond,Vdouble specheat,Vdouble dens,Vdouble filmcoef);
VKI_EXTERN void vdm_NASFilmMAT5(vsy_HashTable* mph,
Vint mid,Vdouble kmat[],Vdouble specheat,Vdouble dens);
VKI_EXTERN void vdm_NASFilmMAT10(vsy_HashTable* mph,
Vint mid,Vdouble bulk,Vdouble dens,Vdouble sound);VKI_EXTERN
void vdm_NASFilcShelltk(vsy_Concat** shelltk,Vint ein,
Vint tflag,Vdouble tk[4],Vdouble zf);VKI_EXTERN void
vdm_NASFilcBeamof(vsy_Concat** beamof,Vint ein,Vdouble
wa[3],Vdouble wb[3],Vdouble orientationVector[3],const
Vchar* offsetVectorSpecification);VKI_EXTERN void vdm_NASFilcBushof(vsy_Concat**
beamof,Vint ein,Vint ocid,Vdouble s,Vdouble sc[3]);
VKI_EXTERN void vdm_NASFilcMatervc(vsy_Concat** matervc,
vis_Connect* connect,Vint ein,Vint mcid,Vdouble theta,
Vint matcidflag);VKI_EXTERN void vdm_NASFilcLocalvc(vsy_Concat**
localvc,vis_Connect* connect,Vint ein,Vint g0,Vdouble
v[3],Vint cid,Vint geomCbend,const Vchar* offsetVectorSpecification);
VKI_EXTERN void vdm_NASFilreadShelltk(vsy_Concat* shelltk,
vis_Connect* connect,vsy_HashTable* eph,Vint pshellt,
Vint dstype,Vdouble dbuf[]);VKI_EXTERN void vdm_NASFilreadBeamof(vsy_Concat*
beamof,vis_Connect* connect,Vdouble dbuf[]);VKI_EXTERN
void vdm_NASFilreadVc(vsy_Concat* vc,Vfloat fbuf[]);
VKI_EXTERN void vdm_NASFilprocBeamof(vsy_Concat* beamof,
vis_Connect* connect,vsy_HashTable* csh);VKI_EXTERN
void vdm_NASFilprocMaterVc(vsy_Concat* matervc,vis_Connect*
connect,vsy_HashTable* csh,Vdouble* materang);VKI_EXTERN
void vdm_NASFilprocLocalVc(vsy_Concat* localvc,vis_Connect*
connect,vsy_HashTable* csh,vsy_Dictionary* epd);VKI_EXTERN
void vdm_NASFilprocCROD(vsy_HashTable* eph,vis_Connect*
connect,Vint numel);VKI_EXTERN void vdm_NASFilWriteModel(vdm_NASFil*
p,vis_Model* model);VKI_EXTERN void vdm_NASFilWriteState(vdm_NASFil*
p,vis_RProp* rprop,vis_State* state);VKI_EXTERN void
vdm_NASFilLibDataset(vdm_NASFil* p,Vint oper,Vint idst);
VKI_EXTERN void vdm_NASFilSetString(vdm_NASFil* p,Vint
type,Vchar* cvalue);VKI_EXTERN void vdm_NASFilGetUnrecognizedData(vdm_NASFil*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_NASFilDataFun(vdm_NASFil* p,vdm_DataFun* datafun);
VKI_EXTERN void vdm_NASFilPLSection(Vdouble d[],Vchar
type[],Vint in,Vint* btype,Vdouble dime[20],Vdouble*
nsm,Vdouble* rotang,Vint* reflecty,Vint* reflectz,Vint*
insm,Vdouble srec[4][2]);VKI_EXTERN void vdm_NASFilcUNITSYS(Vchar*
cval,vis_Units* units);VKI_EXTERN void vdm_NASFilcUNITTIME(Vchar*
cval,vis_Units* units);VKI_EXTERN void vdm_NASFilsetRCase(vis_IdTran*
idtrannode,Vint nantyp,Vint g,Vint c,Vint restraintType,
Vdouble value,vis_RCase* rcase);
#ifdef __cplusplus
}
#endif
#endif

