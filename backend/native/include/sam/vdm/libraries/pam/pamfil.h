/* ABAQUS Input Deck Interface object */
#ifndef PAMFIL_DEF
#define PAMFIL_DEF

#include <stdio.h>

#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vis/gridfun.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"

#define PAMFIL_NUMRESTYPES 32

/* get integer */
#define PAMFIL_NUMUNREC      -1
#define PAMFIL_LINENUM       -2
#define PAMFIL_UNRECKEYWORD  -3
#define PAMFIL_UNRECDATALINE -4
#define PAMFIL_UNRECFILE     -5

/* defines for function prototypes */
typedef void(VPAMFilMonitorFunc)(vdm_PAMFil*, Vobject*);

typedef struct vdm_PAMFilio vdm_PAMFilio;

struct vdm_PAMFil {
    Vint ierr;
    Vint type;
    Vchar filename[SYS_MAXPATHCHAR];
    Vchar pathroot[SYS_MAXPATHCHAR];
    Vchar pathinc[SYS_MAXPATHCHAR];
    VConventionType conv;
    Vint nodata;
    Vint retcon;
    Vint status;
    Vint numnp;
    Vint numel;
    Vint nfree;
    Vint ndim;
    Vint numcs;
    Vint numcp;
    Vint nantyp;
    Vint soltyp;
    Vint twotyp;
    Vint nonlin;
    Vint doubpre;
    /* get integer, string */
    Vint phase;
    Vchar source[VDM_SOURCE_SIZE];

    vdm_Library* library;
    vdm_PAMFilio* io;
    Vchar heading[81];
    Vchar title[81];
    Vchar subtitle[81];
    Vchar label[81];
    Vint systemflag; /* current *SYSTEM status */
    vsy_CSystem* system;
    Vchar keyword[81];    /* current keyword */
    vsy_CSystem* csystem; /* parameter SYSTEM csystem */
    vsy_CSystem* wsystem; /* working csystem */
    vsy_IntHash* ndef;    /* hashtable of defined nodes */
    Vint numelemsets;
    vsy_HashTable* elemsets;
    Vint numnodesets;
    vsy_HashTable* nodesets;
    vsy_Dictionary* intdict;   /* dictionary of cpair interactions */
    vsy_Dictionary* surfdict;  /* dictionary of surface groups */
    vsy_Dictionary* afactdict; /* dictionary of area factor nodal states */
    vsy_HashTable* csh;        /* hashtable of CoordSys */
    vsy_HashTable* cph;        /* hashtable of cpair propsets */
    vsy_HashTable* cpht;       /* hashtable of cpairs */
    Vint maxpid;               /* maximum of externally generated pid */
    Vint numpid;               /* number of internally generated pids */
    vsy_HashTable* sech;       /* hashtable of section EProp */
    vsy_HashTable* eph;        /* hashtable of EProp */
    vsy_Dictionary* epd;       /* dictionary internal pids */
    Vint nummid;
    vsy_HashTable* mph; /* hashtable and dictionary of MProp */
    vis_MProp* curmprop;
    vis_EProp* cureprop;
    vsy_HashTable* edh; /* hashtable of ElemDat */
    Vint stepflag;      /* *STEP open flag */
    Vint numsid;
    vsy_List* spl; /* list of SProp */
    Vint steprid;
    Vint steplid;
    Vint numprnt, numfile; /* result print, file requests */
    Vint curprnt[PAMFIL_NUMRESTYPES];
    Vint curfile[PAMFIL_NUMRESTYPES];
    Vint curtprnt[PAMFIL_NUMRESTYPES];
    Vint curtfile[PAMFIL_NUMRESTYPES];

    Vint numrid;
    vsy_HashTable* rch; /* hashtable of RCase */
    Vint numlid;
    vsy_HashTable* lch; /* hashtable of LCase */
    Vint nummpc;
    Vint nummpid;
    vsy_HashTable* mch; /* hashtable of MCase */
    Vint numtid;
    vsy_HashTable* tch; /* hashtable of TCurve */
    Vint numicid;
    vsy_HashTable* ich; /* hashtable of ICase */
    vis_State* statethk;
    Vint shellthk;
    Vint ersvec;
    Vint emtcid;
    Vint emtvec;
    Vint trefid;
    Vint orientnodeflag;
    Vint pinflags;

    vis_GProp* gprop;
    vis_Connect* connect;
    vis_GridFun* gridfun;
    vis_IdTran* idtrannode;
    vis_IdTran* idtranelem;
    vdm_Permute* permute;
    Vint numdatasetplex;
    vdm_Plex* plex;

    vsy_IntVec* mpcids; /* EQUATION */
    vsy_IntVec* mpcdof;
    vsy_DblVec* mpcval;

    vsy_IntVec* mpcdistnod; /* DISTRIBUTING COUPLINGS */
    vsy_DblVec* mpcdistwgt;

    Vint idnoff, ideoff, idpoff, idmoff, idsoff, idfoff, iddoff, idroff, tranid;
    Vdouble fctmas, fcttim, fctlen, fcttem;
    vsy_HashTable* transh; /* transformations */

    vsy_Calc* calc;

    Vint numunrec;
    vis_IdTran* idtranline;
    vis_IdTran* idtrantype;
    vsy_HashTable* hashkeyword;
    vsy_HashTable* hashcard;
    vsy_HashTable* hashfile;

    VPAMFilMonitorFunc* funmon;
    Vobject* funobjmon;
    Vint abortflag;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_PAMFil(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_PAMFil(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void SetMode(Vint, Vint);
    VKI_EXTERN void SetConvention(VConventionType);
    VKI_EXTERN void SetStatus(Vint);
    VKI_EXTERN void SetIds(Vint, Vint, Vint, Vint);
    VKI_EXTERN void
    GetConnect(vis_Connect**);
    VKI_EXTERN void
    SetConnect(vis_Connect*);
    VKI_EXTERN void
    SetFunction(Vint, Vfunc*, Vobject*);
    VKI_EXTERN void
    SetMonitorFunction(VPAMFilMonitorFunc*, Vobject*);
    VKI_EXTERN void
    Abort();
    VKI_EXTERN void
    NumDomains(Vchar*, Vint, Vint*);
    VKI_EXTERN void
    Open(Vint, Vchar*, Vint);
    VKI_EXTERN void
    Close();
    VKI_EXTERN void
    Append(Vchar*, Vint);
    VKI_EXTERN void
    GetNumEntities(Vint, Vint*);
    VKI_EXTERN void
    GetLibrary(vdm_Library**);
    VKI_EXTERN void
    NumDatasets(Vint*);
    VKI_EXTERN void
    NumAttributes(Vint, Vint*);
    VKI_EXTERN void
    GetAttVal(Vint, Vint, void*);
    VKI_EXTERN void
    InqDataset(Vint, Vchar[], Vlong*, Vint*, Vint*, Vint*);
    VKI_EXTERN void
    InqAttribute(Vint, Vint, Vchar[], Vint*, Vint*);
    VKI_EXTERN void
    ReadDataset(Vint, void*);
    VKI_EXTERN void
    GetInteger(Vint, Vint*);
    VKI_EXTERN void
    GetStringPtr(Vint, Vchar**);
    VKI_EXTERN void
    GetString(Vint, Vchar*);
    VKI_EXTERN void
    WriteModel(vis_Model*);
    VKI_EXTERN void LibDataset(Vint, Vint);
    VKI_EXTERN void
    DataFun(vdm_DataFun*);
    VKI_EXTERN void
    PrintUnrecognizedData();
    VKI_EXTERN void
    SetString(Vint, Vchar*);
    VKI_EXTERN void
    GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_PAMFil*
vdm_PAMFilBegin(void);
VKI_EXTERN void
vdm_PAMFil_Construct(vdm_PAMFil* p);
VKI_EXTERN void
vdm_PAMFilEnd(vdm_PAMFil* p);
VKI_EXTERN void
vdm_PAMFil_Destruct(vdm_PAMFil* p);
VKI_EXTERN Vint
vdm_PAMFilError(vdm_PAMFil* p);
VKI_EXTERN void
vdm_PAMFilSetMode(vdm_PAMFil* p, Vint mode, Vint flag);
VKI_EXTERN void
vdm_PAMFilSetConvention(vdm_PAMFil* p, VConventionType convention);
VKI_EXTERN void
vdm_PAMFilSetStatus(vdm_PAMFil* p, Vint status);
VKI_EXTERN void
vdm_PAMFilSetIds(vdm_PAMFil* p, Vint idtype, Vint id1off, Vint id2off, Vint id3off);
VKI_EXTERN void
vdm_PAMFilGetConnect(vdm_PAMFil* p, vis_Connect** connect);
VKI_EXTERN void
vdm_PAMFilSetConnect(vdm_PAMFil* p, vis_Connect* connect);
VKI_EXTERN void
vdm_PAMFilSetFunction(vdm_PAMFil* p, Vint functype, Vfunc* function, Vobject* object);
VKI_EXTERN void
vdm_PAMFilSetMonitorFunction(vdm_PAMFil* p, VPAMFilMonitorFunc* function, Vobject* object);
VKI_EXTERN void
vdm_PAMFilAbort(vdm_PAMFil* p);
VKI_EXTERN void
vdm_PAMFilNumDomains(vdm_PAMFil* p, Vchar* filename, Vint type, Vint* numdomains);
VKI_EXTERN void
vdm_PAMFilOpen(vdm_PAMFil* p, Vint mode, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_PAMFilClose(vdm_PAMFil* p);
VKI_EXTERN void
vdm_PAMFilAppend(vdm_PAMFil* p, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_PAMFilGetNumEntities(vdm_PAMFil* p, Vint entitytype, Vint* numentity);
VKI_EXTERN void
vdm_PAMFilGetLibrary(vdm_PAMFil* p, vdm_Library** library);
VKI_EXTERN void
vdm_PAMFilNumDatasets(vdm_PAMFil* p, Vint* numdatasets);
VKI_EXTERN void
vdm_PAMFilNumAttributes(vdm_PAMFil* p, Vint idst, Vint* numattributes);
VKI_EXTERN void
vdm_PAMFilGetAttVal(vdm_PAMFil* p, Vint idst, Vint iatt, void* value);
VKI_EXTERN void
vdm_PAMFilInqDataset(vdm_PAMFil* p, Vint idst, Vchar name[], Vlong* lrec, Vint* nrow, Vint* ncol, Vint* type);
VKI_EXTERN void
vdm_PAMFilInqAttribute(vdm_PAMFil* p, Vint idst, Vint iatt, Vchar name[], Vint* length, Vint* type);
VKI_EXTERN void
vdm_PAMFilReadDataset(vdm_PAMFil* p, Vint idst, void* buf);
VKI_EXTERN void
vdm_PAMFilGetInteger(vdm_PAMFil* p, Vint type, Vint* ivalue);
VKI_EXTERN void
vdm_PAMFilGetStringPtr(vdm_PAMFil* p, Vint type, Vchar** string);
VKI_EXTERN void
vdm_PAMFilGetString(vdm_PAMFil* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_PAMFilWriteModel(vdm_PAMFil* p, vis_Model* model);
VKI_EXTERN void
vdm_PAMFilLibDataset(vdm_PAMFil* p, Vint oper, Vint idst);
VKI_EXTERN void
vdm_PAMFilSetString(vdm_PAMFil* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_PAMFilGetUnrecognizedData(vdm_PAMFil* p, vdm_UnrecognizedData** unrecognizedData);
VKI_EXTERN void
vdm_PAMFilDataFun(vdm_PAMFil* p, vdm_DataFun* df);
VKI_EXTERN void
vdm_PAMFilPrintUnrecognizedData(vdm_PAMFil* p);

#ifdef __cplusplus
}
#endif

#endif
