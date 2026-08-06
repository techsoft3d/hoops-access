/* PERMASLib Library object */
#ifndef PERMASLIB_DEF
#define PERMASLIB_DEF

#include <stdio.h>

#include "sam/base/basedefs.h"
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#include "sam/vdm/permute.h"

/* defines for function prototypes */
typedef void(VPERMASLibMonitorFunc)(vdm_PERMASLib*, Vobject*);

typedef struct vdm_PERMASLibio vdm_PERMASLibio;

struct vdm_PERMASLib {
    Vint ierr;
    Vint type;
    VConventionType conv;
    Vint doubpre;
    Vint nodata;
    Vint retcon;
    Vint numnp;
    Vint numel;
    Vint numdataset;
    Vint status;
    Vint axisym;
    Vint analtype;
    Vint delio;
    Vint soltyp;
    Vint nonlin;
    Vint nantyp;
    Vint onecomp;
    Vchar path[SYS_MAXPATHCHAR];
    Vchar title[81];
    Vchar version[10];
    vdm_Library* library;
    vis_Connect* connect;
    vis_GProp* gprop;
    vis_GridFun* gridfun;
    vsy_Dictionary* soltypdic;
    vdm_PERMASLibio* io;
    vsy_HashTable* sitht;
    Vint numsit;
    vsy_Dictionary* eltypedict;
    vsy_HashTable* elemsets;
    Vint numelemsets;
    vsy_HashTable* nodesets;
    Vint numnodesets;
    vsy_Dictionary* elemsetdict;
    vsy_Dictionary* nodesetdict;
    vsy_HashTable* edh;
    vsy_Dictionary* ntrsysdic;
    vsy_IntDict* ntrsysid;
    Vint numntrsys;
    Vint numrotb;

    VPERMASLibMonitorFunc* funmon;
    Vobject* funobjmon;
    Vint abortflag;

    vis_IdTran* idtrannode;
    vis_IdTran* idtranelem;
    vdm_Permute* permute;
    vsy_HashTable* csh;
    vsy_IntHash* cih;
    Vint maxcsys;

    vsy_Dictionary* resdict;
    vsy_IntDict* elementid;

    Vint nlsect;
    vsy_Dictionary* hldict;
    vis_IdTran* idtranl;

    Vint numdatasetplex;
    vdm_Plex* plex;
    Vint idtyp;
    Vint idoff[3];
    Vint idbas[3];
    vis_Connect* connectset;

    vsy_Dictionary* datasetdic;

    vsy_IntVHash* timefreqbuckivh;
    Vint numids;

    vsy_IntDict* elsysid;
    vdm_PERMASLib* openlib;
    vsy_List* cshr;

    vdm_Dataset* ciddataset;
    vdm_Dataset* ciddataseti;
    vsy_HashTable* linkcidht;
    Vint numlinkcid;

    Vint nrotb;
    vsy_HashTable* rotbht;

    Vint nntrsys;
    vsy_HashTable* ntrsysht;

    Vint nelprop;
    Vint nummat;
    vsy_HashTable* elpropht;
    vsy_IntDict* geodatid;
    vsy_IntDict* matid;

    Vint numprop;
    vsy_HashTable* eph;

    vsy_Dictionary* propdict;
    /* get integer values */
    Vint phase;
    /* get string values */
    Vchar source[VDM_SOURCE_SIZE];
    vsy_IntDict* eldict;

    vis_IdTran* idtranncols;
    vis_IdTran* idtranecols;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_PERMASLib(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_PERMASLib(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void SetMode(Vint, Vint);
    VKI_EXTERN void SetConvention(VConventionType);
    VKI_EXTERN void SetStatus(Vint);
    VKI_EXTERN void
    SetOpenLib(Vobject*);
    VKI_EXTERN void
    SetConnect(vis_Connect*);
    VKI_EXTERN void
    GetConnect(vis_Connect**);
    VKI_EXTERN void SetIds(Vint, Vint, Vint, Vint);
    VKI_EXTERN void
    SetFunction(Vint, Vfunc*, Vobject*);
    VKI_EXTERN void
    SetMonitorFunction(VPERMASLibMonitorFunc*, Vobject*);
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
    VKI_EXTERN void
    ReadDatasetCols(Vint, Vint, Vint[], void*, Vlong[]);
    VKI_EXTERN void LibDataset(Vint, Vint);
    VKI_EXTERN void
    DataFun(vdm_DataFun*);
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
VKI_EXTERN vdm_PERMASLib*
vdm_PERMASLibBegin(void);
VKI_EXTERN void
vdm_PERMASLib_Construct(vdm_PERMASLib* p);
VKI_EXTERN void
vdm_PERMASLibEnd(vdm_PERMASLib* p);
VKI_EXTERN void
vdm_PERMASLib_Destruct(vdm_PERMASLib* p);
VKI_EXTERN Vint
vdm_PERMASLibError(vdm_PERMASLib* p);
VKI_EXTERN void
vdm_PERMASLibSetMode(vdm_PERMASLib* p, Vint mode, Vint flag);
VKI_EXTERN void
vdm_PERMASLibSetConvention(vdm_PERMASLib* p, VConventionType convention);
VKI_EXTERN void
vdm_PERMASLibSetStatus(vdm_PERMASLib* p, Vint status);
VKI_EXTERN void
vdm_PERMASLibSetOpenLib(vdm_PERMASLib* p, Vobject* openlib);
VKI_EXTERN void
vdm_PERMASLibSetConnect(vdm_PERMASLib* p, vis_Connect* connect);
VKI_EXTERN void
vdm_PERMASLibGetConnect(vdm_PERMASLib* p, vis_Connect** connect);
VKI_EXTERN void
vdm_PERMASLibSetIds(vdm_PERMASLib* p, Vint idtype, Vint id1off, Vint id2off, Vint id3off);
VKI_EXTERN void
vdm_PERMASLibSetFunction(vdm_PERMASLib* p, Vint funtype, Vfunc* function, Vobject* object);
VKI_EXTERN void
vdm_PERMASLibSetMonitorFunction(vdm_PERMASLib* p, VPERMASLibMonitorFunc* function, Vobject* object);
VKI_EXTERN void
vdm_PERMASLibAbort(vdm_PERMASLib* p);
VKI_EXTERN void
vdm_PERMASLibOpen(vdm_PERMASLib* p, Vint mode, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_PERMASLibClose(vdm_PERMASLib* p);
VKI_EXTERN void
vdm_PERMASLibAppend(vdm_PERMASLib* p, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_PERMASLibGetNumEntities(vdm_PERMASLib* p, Vint enttype, Vint* nument);
VKI_EXTERN void
vdm_PERMASLibGetLibrary(vdm_PERMASLib* p, vdm_Library** library);
VKI_EXTERN void
vdm_PERMASLibNumDatasets(vdm_PERMASLib* p, Vint* numdatasets);
VKI_EXTERN void
vdm_PERMASLibNumAttributes(vdm_PERMASLib* p, Vint idst, Vint* numattributes);
VKI_EXTERN void
vdm_PERMASLibGetAttVal(vdm_PERMASLib* p, Vint idst, Vint iatt, void* value);
VKI_EXTERN void
vdm_PERMASLibInqDataset(vdm_PERMASLib* p, Vint idst, Vchar name[], Vlong* lrec, Vint* nrow, Vint* ncol, Vint* type);
VKI_EXTERN void
vdm_PERMASLibInqAttribute(vdm_PERMASLib* p, Vint idst, Vint iatt, Vchar name[], Vint* length, Vint* type);
VKI_EXTERN void
vdm_PERMASLibReadDataset(vdm_PERMASLib* p, Vint idst, void* buf);
VKI_EXTERN void
vdm_PERMASLibReadDatasetCols(vdm_PERMASLib* p, Vint idst, Vint ncols, Vint cols[], void* buf, Vlong lptr[]);
VKI_EXTERN void
vdm_PERMASLibLibDataset(vdm_PERMASLib* p, Vint oper, Vint idst);
VKI_EXTERN void
vdm_PERMASLibSetString(vdm_PERMASLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_PERMASLibGetUnrecognizedData(vdm_PERMASLib* p, vdm_UnrecognizedData** unrecognizedData);
VKI_EXTERN void
vdm_PERMASLibDataFun(vdm_PERMASLib* p, vdm_DataFun* datafun);
VKI_EXTERN void
vdm_PERMASLibGetInteger(vdm_PERMASLib* p, Vint type, Vint* ivalue);
VKI_EXTERN void
vdm_PERMASLibGetString(vdm_PERMASLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_PERMASLibNumDomains(vdm_PERMASLib* p, Vchar* filename, Vint type, Vint* numdomains);

#ifdef __cplusplus
}
#endif

#endif
