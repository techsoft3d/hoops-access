/* Memory Library object */
#ifndef MEMLIB_DEF
#define MEMLIB_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/dataset.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"

/* get integer */
#define MEMLIB_VERSION    -1
#define MEMLIB_CREATEDATE -2
#define MEMLIB_CREATETIME -3
#define MEMLIB_UPDATEDATE -4
#define MEMLIB_UPDATETIME -5

/* defines for function prototypes */
typedef void(VMemLibMonitorFunc)(vdm_MemLib*, Vobject*);

struct vdm_MemLib {
    Vint ierr;
    Vint type;
    Vint status;
    Vint numnp;
    Vint numel;
    Vint nodata;
    Vint idtyp;
    Vint idoff[3];
    Vint initvers;
    Vint idat[3];
    Vint itim[3];
    Vint ldat[3];
    Vint ltim[3];
    Vint swap;
    Vint curlib;
    Vint numdatasetplex;
    vdm_Library* toplibrary;
    vdm_Library* uselibrary;
    vsy_List* liblist;
    vdm_Plex* plex;
    VMemLibMonitorFunc* funmon;
    Vobject* funobjmon;
    Vint abortflag;
    Vchar source[VDM_SOURCE_SIZE];

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_MemLib(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_MemLib(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void
    GetInteger(Vint, Vint*);
    VKI_EXTERN void
    GetString(Vint, Vchar*);
    VKI_EXTERN void SetMode(Vint, Vint);
    VKI_EXTERN void SetConvention(VConventionType);
    VKI_EXTERN void SetIds(Vint, Vint, Vint, Vint);
    VKI_EXTERN void SetStatus(Vint);
    VKI_EXTERN void
    SetConnect(vis_Connect*);
    VKI_EXTERN void
    GetConnect(vis_Connect**);
    VKI_EXTERN void
    SetFunction(Vint, Vfunc*, Vobject*);
    VKI_EXTERN void
    SetMonitorFunction(VMemLibMonitorFunc*, Vobject*);
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
    DefDataset(const Vchar*, Vlong, Vint, Vint, Vint, Vint*);
    VKI_EXTERN void
    DefAttribute(Vint, const Vchar*, Vint, Vint, Vint*);
    VKI_EXTERN void
    SetAttVal(Vint, Vint, void*);
    VKI_EXTERN void
    ReadDataset(Vint, void*);
    VKI_EXTERN void
    NumDataset(Vint*);
    VKI_EXTERN void
    WriteDataset(Vint, void*);
    VKI_EXTERN void
    Update();
    VKI_EXTERN void LibDataset(Vint, Vint);
    VKI_EXTERN void PushContainer(Vchar[]);
    VKI_EXTERN void
    PopContainer();
    VKI_EXTERN void
    DataFun(vdm_DataFun*);
    VKI_EXTERN void
    StreamNum(Vlong*);
    VKI_EXTERN void
    Stream(void*);
    VKI_EXTERN void
    SetString(Vint, Vchar*);
    VKI_EXTERN void
    GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_MemLib*
vdm_MemLibBegin(void);
VKI_EXTERN void
vdm_MemLib_Construct(vdm_MemLib* p);
VKI_EXTERN void
vdm_MemLibEnd(vdm_MemLib* p);
VKI_EXTERN void
vdm_MemLib_Destruct(vdm_MemLib* p);
VKI_EXTERN Vint
vdm_MemLibError(vdm_MemLib* p);
VKI_EXTERN void
vdm_MemLibGetInteger(vdm_MemLib* p, Vint type, Vint* param);
VKI_EXTERN void
vdm_MemLibGetString(vdm_MemLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_MemLibSetMode(vdm_MemLib* p, Vint mode, Vint flag);
VKI_EXTERN void
vdm_MemLibSetConvention(vdm_MemLib* p, VConventionType convention);
VKI_EXTERN void
vdm_MemLibSetIds(vdm_MemLib* p, Vint idtype, Vint id1off, Vint id2off, Vint id3off);
VKI_EXTERN void
vdm_MemLibSetStatus(vdm_MemLib* p, Vint status);
VKI_EXTERN void
vdm_MemLibSetConnect(vdm_MemLib* p, vis_Connect* connect);
VKI_EXTERN void
vdm_MemLibGetConnect(vdm_MemLib* p, vis_Connect** connect);
VKI_EXTERN void
vdm_MemLibSetFunction(vdm_MemLib* p, Vint funtype, Vfunc* function, Vobject* object);
VKI_EXTERN void
vdm_MemLibSetMonitorFunction(vdm_MemLib* p, VMemLibMonitorFunc* function, Vobject* object);
VKI_EXTERN void
vdm_MemLibAbort(vdm_MemLib* p);
VKI_EXTERN void
vdm_MemLibNumDomains(vdm_MemLib* p, Vchar* filename, Vint type, Vint* numdomains);
VKI_EXTERN void
vdm_MemLibOpen(vdm_MemLib* p, Vint mode, Vchar* path, Vint type);
VKI_EXTERN void
vdm_MemLibClose(vdm_MemLib* p);
VKI_EXTERN void
vdm_MemLibAppend(vdm_MemLib* p, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_MemLibGetNumEntities(vdm_MemLib* p, Vint entitytype, Vint* numentity);
VKI_EXTERN void
vdm_MemLibGetLibrary(vdm_MemLib* p, vdm_Library** library);
VKI_EXTERN void
vdm_MemLibNumDatasets(vdm_MemLib* p, Vint* numdatasets);
VKI_EXTERN void
vdm_MemLibNumAttributes(vdm_MemLib* p, Vint idst, Vint* numattributes);
VKI_EXTERN void
vdm_MemLibGetAttVal(vdm_MemLib* p, Vint idst, Vint iatt, void* value);
VKI_EXTERN void
vdm_MemLibInqDataset(vdm_MemLib* p, Vint idst, Vchar name[], Vlong* lrec, Vint* nrow, Vint* ncol, Vint* type);
VKI_EXTERN void
vdm_MemLibInqAttribute(vdm_MemLib* p, Vint idst, Vint iatt, Vchar name[], Vint* length, Vint* type);
VKI_EXTERN void
vdm_MemLibDefDataset(vdm_MemLib* p, const Vchar* name, Vlong lrec, Vint nrow, Vint ncol, Vint type, Vint* idst);
VKI_EXTERN void
vdm_MemLibDefAttribute(vdm_MemLib* p, Vint idst, const Vchar* name, Vint length, Vint atttype, Vint* iatt);
VKI_EXTERN void
vdm_MemLibSetAttVal(vdm_MemLib* p, Vint idst, Vint iatt, void* value);
VKI_EXTERN void
vdm_MemLibReadDataset(vdm_MemLib* p, Vint idst, void* buff);
VKI_EXTERN void
vdm_MemLibNumDataset(vdm_MemLib* p, Vint* numdataset);
VKI_EXTERN void
vdm_MemLibWriteDataset(vdm_MemLib* p, Vint idst, void* buff);
VKI_EXTERN void
vdm_MemLibUpdate(vdm_MemLib* p);
VKI_EXTERN void
vdm_MemLibLibDataset(vdm_MemLib* p, Vint oper, Vint idst);
VKI_EXTERN void
vdm_MemLibPushContainer(vdm_MemLib* p, Vchar name[]);
VKI_EXTERN void
vdm_MemLibPopContainer(vdm_MemLib* p);
VKI_EXTERN void
vdm_MemLibSetString(vdm_MemLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_MemLibGetUnrecognizedData(vdm_MemLib* p, vdm_UnrecognizedData** unrecognizedData);
VKI_EXTERN void
vdm_MemLibDataFun(vdm_MemLib* p, vdm_DataFun* datafun);
VKI_EXTERN void
vdm_MemLibStreamNum(vdm_MemLib* p, Vlong* nbytes);
VKI_EXTERN void
vdm_MemLibStream(vdm_MemLib* p, void* buff);

#ifdef __cplusplus
}
#endif

#endif
