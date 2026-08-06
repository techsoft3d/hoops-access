/* EnSight Library object */
#ifndef ENSIGHTLIB_DEF
#define ENSIGHTLIB_DEF

#include <stdio.h>

#include "sam/base/basedefs.h"
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#include "sam/vdm/libraries/cgns/cgnsdat.h"
#include "sam/vdm/permute.h"

/* defines for function prototypes */
typedef void(VEnSightLibMonitorFunc)(vdm_EnSightLib*, Vobject*);

struct vdm_EnSightLib {
    Vint ierr;
    Vint type;
    VConventionType conv;
    Vint doubpre;
    Vint nodata;
    Vint retcon;
    Vint status;
    Vint idtyp, idoff[3], idbas[3];
    Vint tnumnp;
    Vint numnp;
    Vint numel;
    Vint nparticles;
    Vint nfree;
    Vint ndim;
    Vint nantyp;
    Vint soltyp;
    Vint twotyp;
    Vint nonlin;
    Vint numcells;
    Vint numfaces;
    Vint ersvec;
    Vint emtcid;
    Vint emtvec;
    Vint zeropartid;
    Vint swap;
    Vint format;
    Vint fileid;
    Vint change_coords_only;
    Vint mchange_coords_only;
    Vint ischild;
    Vint erbversion;
    Vint onecomp;

    Vchar version[13];
    Vchar date[32];
    Vchar time[32];
    Vchar title[81];
    Vchar subtitle[81];
    Vint numdataset;
    vdm_Library* library;
    vsy_Dictionary* resdicti;

    vis_Connect* connect;
    vis_GProp* gprop;
    vis_IdTran* idtrannode;
    vis_IdTran* idtranelem;
    vis_IdTran* idtranface;

    Vint numdatasetplex;
    vdm_Plex* plex;

    VEnSightLibMonitorFunc* funmon;
    Vobject* funobjmon;
    Vint abortflag;

    FILE* fp;
    vsy_HashTable* timeseth;
    vsy_IntHash* partnodebegin;
    vsy_IntHash* partnodenum;
    vsy_HashTable* partelemtypebegin; /* Hash of dictionaries to store 1st ele of each type per part */
    vsy_HashTable* partelemtypenum;   /* Hash of dictionaries to store number of eles of each type per part */
    vsy_VHashTable* topoh;
    Vchar path[SYS_MAXPATHCHAR];
    Vint savegeom;
    Vint goldflag;
    Vint starcd;
    vsy_IntDict* starcddict;
    vsy_IntDict* famdict;
    vsy_Dictionary* timedict;
    vsy_Concat* concat;
    vsy_IntDict* famname;
    vsy_HashTable* parth;
    Vint hascomplex;
    vsy_IntDict* abbrdict;
    vsy_IntHash* nodeid;
    vdm_EnSightLib* parlib;
    vdm_EnSightLib* curlib;
    Vint numlib;
    vdm_Dataset** libs;
    vsy_HashTable* modelht;
    Vint* libdsts;
    vsy_Dictionary* tempdict;
    vsy_Dictionary* resdict;
    vsy_Dictionary* esresdict;
    vsy_Dictionary* posdict;
    vsy_IntDict* nstepsid;
    /* get integer values */
    Vint phase;
    /* get string values */
    Vchar source[SYS_MAXPATHCHAR];
    vsy_HashTable* rigidht;
    vsy_Dictionary* rigidnamedic;
    vsy_Dictionary* rigiddic;
    Vint rigidmode;
    Vint haszerotime;
    vsy_IntHash* timeid1ih;
    vsy_IntHash* id1timeih;
    vsy_Dictionary* transformdic;
    Vint enonscalar;
    Vint nnonscalar;
    vsy_IntHash* nparticlesih;
    vsy_List* timesetlist;

    Vchar geomfilemodel[SYS_MAXPATHCHAR];
    Vchar geomfilemeasured[SYS_MAXPATHCHAR];
    Vchar erbfile[SYS_MAXPATHCHAR];
    Vint geom_ts;
    Vint geom_fs;
    Vint measured_ts;
    Vint measured_fs;
    vsy_HashTable* varht;
    vsy_HashTable* timeht;
    vsy_HashTable* fileht;
    Vint* geomid1;

    FILE* wordfile;
    Vchar wordbuf[20][30];
    Vint curword;
    Vint nwords;
    Vint ichar;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_EnSightLib(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_EnSightLib(void);
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
    SetMonitorFunction(VEnSightLibMonitorFunc*, Vobject*);
    VKI_EXTERN void
    Abort();
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
    VKI_EXTERN void LibDataset(Vint, Vint);
    VKI_EXTERN void
    DataFun(vdm_DataFun*);
    VKI_EXTERN void
    WriteModel(vis_Model*);
    VKI_EXTERN void
    WriteState(vis_RProp*, vis_State*);
    VKI_EXTERN void
    GetInteger(Vint, Vint*);
    VKI_EXTERN void
    GetString(Vint, Vchar*);
    VKI_EXTERN void
    NumDomains(Vchar*, Vint, Vint*);
    VKI_EXTERN void
    SetString(Vint, Vchar*);
    VKI_EXTERN void
    GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_EnSightLib*
vdm_EnSightLibBegin(void);
VKI_EXTERN void
vdm_EnSightLib_Construct(vdm_EnSightLib* p);
VKI_EXTERN void
vdm_EnSightLibEnd(vdm_EnSightLib* p);
VKI_EXTERN void
vdm_EnSightLib_Destruct(vdm_EnSightLib* p);
VKI_EXTERN Vint
vdm_EnSightLibError(vdm_EnSightLib* p);
VKI_EXTERN void
vdm_EnSightLibSetMode(vdm_EnSightLib* p, Vint mode, Vint flag);
VKI_EXTERN void
vdm_EnSightLibSetConvention(vdm_EnSightLib* p, VConventionType convention);
VKI_EXTERN void
vdm_EnSightLibSetStatus(vdm_EnSightLib* p, Vint status);
VKI_EXTERN void
vdm_EnSightLibSetIds(vdm_EnSightLib* p, Vint idtype, Vint id1off, Vint id2off, Vint id3off);
VKI_EXTERN void
vdm_EnSightLibGetConnect(vdm_EnSightLib* p, vis_Connect** connect);
VKI_EXTERN void
vdm_EnSightLibSetConnect(vdm_EnSightLib* p, vis_Connect* connect);
VKI_EXTERN void
vdm_EnSightLibSetFunction(vdm_EnSightLib* p, Vint funtype, Vfunc* function, Vobject* object);
VKI_EXTERN void
vdm_EnSightLibSetMonitorFunction(vdm_EnSightLib* p, VEnSightLibMonitorFunc* function, Vobject* object);
VKI_EXTERN void
vdm_EnSightLibAbort(vdm_EnSightLib* p);
VKI_EXTERN void
vdm_EnSightLibOpen(vdm_EnSightLib* p, Vint mode, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_EnSightLibClose(vdm_EnSightLib* p);
VKI_EXTERN void
vdm_EnSightLibAppend(vdm_EnSightLib* p, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_EnSightLibGetNumEntities(vdm_EnSightLib* p, Vint enttype, Vint* nument);
VKI_EXTERN void
vdm_EnSightLibGetLibrary(vdm_EnSightLib* p, vdm_Library** library);
VKI_EXTERN void
vdm_EnSightLibNumDatasets(vdm_EnSightLib* p, Vint* numdatasets);
VKI_EXTERN void
vdm_EnSightLibNumAttributes(vdm_EnSightLib* p, Vint idst, Vint* numattributes);
VKI_EXTERN void
vdm_EnSightLibGetAttVal(vdm_EnSightLib* p, Vint idst, Vint iatt, void* value);
VKI_EXTERN void
vdm_EnSightLibInqDataset(vdm_EnSightLib* p, Vint idst, Vchar name[], Vlong* lrec, Vint* nrow, Vint* ncol, Vint* type);
VKI_EXTERN void
vdm_EnSightLibInqAttribute(vdm_EnSightLib* p, Vint idst, Vint iatt, Vchar name[], Vint* length, Vint* type);
VKI_EXTERN void
vdm_EnSightLibReadDataset(vdm_EnSightLib* p, Vint idst, void* buf);
VKI_EXTERN void
vdm_EnSightLibLibDataset(vdm_EnSightLib* p, Vint oper, Vint idst);
VKI_EXTERN void
vdm_EnSightLibSetString(vdm_EnSightLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_EnSightLibGetUnrecognizedData(vdm_EnSightLib* p, vdm_UnrecognizedData** unrecognizedData);
VKI_EXTERN void
vdm_EnSightLibDataFun(vdm_EnSightLib* p, vdm_DataFun* datafun);
VKI_EXTERN void
vdm_EnSightLibWriteModel(vdm_EnSightLib* p, vis_Model* model);
VKI_EXTERN void
vdm_EnSightLibWriteState(vdm_EnSightLib* p, vis_RProp* urprop, vis_State* state);
VKI_EXTERN void
vdm_EnSightLibGetInteger(vdm_EnSightLib* p, Vint type, Vint* ivalue);
VKI_EXTERN void
vdm_EnSightLibGetString(vdm_EnSightLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_EnSightLibNumDomains(vdm_EnSightLib* p, Vchar* filename, Vint type, Vint* numdomains);

#ifdef __cplusplus
}
#endif

#endif
