/* Native Library object */
#ifndef NATLIB_DEF
#define NATLIB_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/dataset.h"
#include "sam/vdm/disk.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/libraries/native/natdat.h"
#include "sam/vdm/plex.h"
#ifdef VKI_LIBAPI_HDF5
#include "hdf5.h"
#include "H5LTpublic.h"
#include "hdf5_hl.h"
#endif

#define MAXNATDATASET 4096
/* data forms */
#define NATLIB_BASE 0
#define NATLIB_SWAP 1
/* get integer */
#define NATLIB_VERSION    -1
#define NATLIB_CREATEDATE -2
#define NATLIB_CREATETIME -3
#define NATLIB_UPDATEDATE -4
#define NATLIB_UPDATETIME -5

/* defines for function prototypes */
typedef void(VNatLibMonitorFunc)(vdm_NatLib*, Vobject*);

struct vdm_NatLib {
    Vint ierr;
    Vint type;
    VConventionType conv;
    Vint numnp;
    Vint numel;
    Vint dataset32;
    Vint nodata;
    Vint retcon;
    Vint status;
    Vint initvers;
    Vint idat[3];
    Vint itim[3];
    Vint ldat[3];
    Vint ltim[3];
    Vint idtyp, idoff[3], idbas[3];
    Vint updatedataset;
    Vint update;
    Vint iver;
    Vint datasetnamelen;
    Vint attributenamelen;
    Vint attributevallen;
    vdm_Library* toplibrary;
    vdm_Library* library;
    vdm_Dataset** datasets;
    Vint maxlibs;
    Vint npush;
    vdm_Disk* disk;
    Vint numdataset;
    Vint maxdataset;
    Vint version;  /* version */
    Vint dataform; /* data format on database */
    Vint hostform; /* data format on host */

    /* get integer, string */
    Vint phase;
    Vchar source[VDM_SOURCE_SIZE];

    Vint baselen;     /* char length of base record */
    Vint baseoff;     /* offset of base record */
    Vint basesiz;     /* size of base record */
    Vint datalen;     /* char length of offset or size record */
    Vint dataoffoff;  /* offset of offset record */
    Vint dataoffsiz;  /* size of offset record */
    Vint* datasetoff; /* offsets, if zero no disk allocated */
    Vint datasizoff;
    Vint datasizsiz;
    Vint* datasetsiz; /* sizes */

    Vlong baselenl;     /* char length of base record */
    Vlong baseoffl;     /* offset of base record */
    Vlong basesizl;     /* size of base record */
    Vlong datalenl;     /* char length of offset or size record */
    Vlong dataoffoffl;  /* offset of offset record */
    Vlong dataoffsizl;  /* size of offset record */
    Vlong* datasetoffl; /* offsets, if zero no disk allocated */
    Vlong datasizoffl;
    Vlong datasizsizl;
    Vlong* datasetsizl; /* sizes */

    vis_Connect* connect;
    vis_Model* model;
    vdm_DataFun* df;
    vdm_LMan* lman;
    vis_Connect* connectset;
    Vint numdatasettot;
    Vint numdatasetplex;
    vdm_Plex* plex;

    VNatLibMonitorFunc* funmon;
    Vobject* funobjmon;
    Vint abortflag;
    Vint zlibcompress;
    Vint* raggedptr;
    Vint raggedsize;
#ifdef VKI_LIBAPI_HDF5
    hid_t file;
    hid_t gcpl;
    vsy_IntDict* hidid;
    Vchar path[SYS_MAXPATHCHAR];
    vdm_Dataset* hdfdataset;
#endif

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_NatLib(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_NatLib(void);
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
    SetMonitorFunction(VNatLibMonitorFunc*, Vobject*);
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
    ReadDatasetCols(Vint, Vint, Vint[], void*, Vlong*);
    VKI_EXTERN void
    NumDataset(Vint*);
    VKI_EXTERN void
    WriteDataset(Vint, void*);
    VKI_EXTERN void
    Update();
    VKI_EXTERN void LibDataset(Vint, Vint);
    VKI_EXTERN void PushContainer(Vchar[]);
    VKI_EXTERN void
    DataFun(vdm_DataFun*);
    VKI_EXTERN void SetRaggedPtr(Vint, Vint[]);
    VKI_EXTERN void
    SetString(Vint, Vchar*);
    VKI_EXTERN void
    GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_NatLib*
vdm_NatLibBegin(void);
VKI_EXTERN void
vdm_NatLib_Construct(vdm_NatLib* p);
VKI_EXTERN void
vdm_NatLibEnd(vdm_NatLib* p);
VKI_EXTERN void
vdm_NatLib_Destruct(vdm_NatLib* p);
VKI_EXTERN Vint
vdm_NatLibError(vdm_NatLib* p);
VKI_EXTERN void
vdm_NatLibGetInteger(vdm_NatLib* p, Vint type, Vint* param);
VKI_EXTERN void
vdm_NatLibGetString(vdm_NatLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_NatLibSetMode(vdm_NatLib* p, Vint mode, Vint flag);
VKI_EXTERN void
vdm_NatLibSetConvention(vdm_NatLib* p, VConventionType convention);
VKI_EXTERN void
vdm_NatLibSetIds(vdm_NatLib* p, Vint idtype, Vint id1off, Vint id2off, Vint id3off);
VKI_EXTERN void
vdm_NatLibSetStatus(vdm_NatLib* p, Vint status);
VKI_EXTERN void
vdm_NatLibSetConnect(vdm_NatLib* p, vis_Connect* connect);
VKI_EXTERN void
vdm_NatLibGetConnect(vdm_NatLib* p, vis_Connect** connect);
VKI_EXTERN void
vdm_NatLibSetFunction(vdm_NatLib* p, Vint funtype, Vfunc* function, Vobject* object);
VKI_EXTERN void
vdm_NatLibSetMonitorFunction(vdm_NatLib* p, VNatLibMonitorFunc* function, Vobject* object);
VKI_EXTERN void
vdm_NatLibAbort(vdm_NatLib* p);
VKI_EXTERN void
vdm_NatLibNumDomains(vdm_NatLib* p, Vchar* filename, Vint type, Vint* numdomains);
VKI_EXTERN void
vdm_NatLibOpen(vdm_NatLib* p, Vint mode, Vchar* path, Vint type);
VKI_EXTERN void
vdm_NatLibClose(vdm_NatLib* p);
VKI_EXTERN void
vdm_NatLibAppend(vdm_NatLib* p, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_NatLibGetNumEntities(vdm_NatLib* p, Vint entitytype, Vint* numentity);
VKI_EXTERN void
vdm_NatLibGetLibrary(vdm_NatLib* p, vdm_Library** library);
VKI_EXTERN void
vdm_NatLibNumDatasets(vdm_NatLib* p, Vint* numdatasets);
VKI_EXTERN void
vdm_NatLibNumAttributes(vdm_NatLib* p, Vint idst, Vint* numattributes);
VKI_EXTERN void
vdm_NatLibGetAttVal(vdm_NatLib* p, Vint idst, Vint iatt, void* value);
VKI_EXTERN void
vdm_NatLibInqDataset(vdm_NatLib* p, Vint idst, Vchar name[], Vlong* lrec, Vint* nrow, Vint* ncol, Vint* type);
VKI_EXTERN void
vdm_NatLibInqAttribute(vdm_NatLib* p, Vint idst, Vint iatt, Vchar name[], Vint* length, Vint* type);
VKI_EXTERN void
vdm_NatLibDefDataset(vdm_NatLib* p, const Vchar* name, Vlong lrec, Vint nrow, Vint ncol, Vint type, Vint* idst);
VKI_EXTERN void
vdm_NatLibDefAttribute(vdm_NatLib* p, Vint idst, const Vchar* name, Vint length, Vint type, Vint* iatt);
VKI_EXTERN void
vdm_NatLibSetAttVal(vdm_NatLib* p, Vint idst, Vint iatt, void* value);
VKI_EXTERN void
vdm_NatLibReadDataset(vdm_NatLib* p, Vint idst, void* buff);
VKI_EXTERN void
vdm_NatLibReadDatasetCols(vdm_NatLib* p, Vint idst, Vint ncols, Vint cols[], void* buf, Vlong* lptr);
VKI_EXTERN void
vdm_NatLibNumDataset(vdm_NatLib* p, Vint* numdataset);
VKI_EXTERN void
vdm_NatLibWriteDataset(vdm_NatLib* p, Vint idst, void* buff);
VKI_EXTERN void
vdm_NatLibUpdate(vdm_NatLib* p);
VKI_EXTERN void
vdm_NatLibLibDataset(vdm_NatLib* p, Vint oper, Vint idst);
VKI_EXTERN void
vdm_NatLibPushContainer(vdm_NatLib* p, Vchar name[]);
VKI_EXTERN void
vdm_NatLibSetString(vdm_NatLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_NatLibGetUnrecognizedData(vdm_NatLib* p, vdm_UnrecognizedData** unrecognizedData);
VKI_EXTERN void
vdm_NatLibDataFun(vdm_NatLib* p, vdm_DataFun* datafun);
VKI_EXTERN void
vdm_NatLibSetRaggedPtr(vdm_NatLib* p, Vint ncol, Vint size[]);

#ifdef __cplusplus
}
#endif

#endif
