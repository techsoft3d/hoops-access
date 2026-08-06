/* Adams Interface object */
#ifndef AdamsLIB_DEF
#define AdamsLIB_DEF

#include <stdio.h>

#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"

/* defines for function prototypes */
typedef void(VAdamsLibMonitorFunc)(vdm_AdamsLib*, Vobject*);

typedef struct vdm_AdamsLibio vdm_AdamsLibio;

struct vdm_AdamsLib {
    Vint ierr;
    Vint type;
    Vchar title[82];
    Vchar version[17];
    Vchar date[17];
    Vchar time[9];
    VConventionType conv;
    Vint doubpre;
    Vint nodata;
    Vint retcon;
    Vint status;
    Vint numnp;
    Vint numel;
    Vint numcsys;
    Vint groundpartid;
    vdm_AdamsLibio* io;

    vdm_Library* library;
    vis_Connect* connect;
    vis_GProp* gprop;

    VAdamsLibMonitorFunc* funmon;
    Vobject* funobjmon;
    Vint abortflag;
    /* get integer values */
    Vint phase;
    /* get string values */
    Vchar source[VDM_SOURCE_SIZE];

    vsy_HashTable* csh;
    vsy_HashTable* partht;
    vsy_HashTable* pmht;
    vsy_HashTable* markerht;
    vsy_HashTable* jointht;
    vsy_HashTable* bushht;
    vsy_IntHash* frictionih;
    Vfloat* fdata;

    vsy_Dictionary* resdict;
    vsy_IntDict* resultid;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_AdamsLib(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_AdamsLib(void);
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
    SetMonitorFunction(VAdamsLibMonitorFunc*, Vobject*);
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
VKI_EXTERN vdm_AdamsLib*
vdm_AdamsLibBegin(void);
VKI_EXTERN void
vdm_AdamsLib_Construct(vdm_AdamsLib* p);
VKI_EXTERN void
vdm_AdamsLibEnd(vdm_AdamsLib* p);
VKI_EXTERN void
vdm_AdamsLib_Destruct(vdm_AdamsLib* p);
VKI_EXTERN Vint
vdm_AdamsLibError(vdm_AdamsLib* p);
VKI_EXTERN void
vdm_AdamsLibSetMode(vdm_AdamsLib* p, Vint mode, Vint flag);
VKI_EXTERN void
vdm_AdamsLibSetConvention(vdm_AdamsLib* p, VConventionType convention);
VKI_EXTERN void
vdm_AdamsLibSetStatus(vdm_AdamsLib* p, Vint status);
VKI_EXTERN void
vdm_AdamsLibSetIds(vdm_AdamsLib* p, Vint idtype, Vint id1off, Vint id2off, Vint id3off);
VKI_EXTERN void
vdm_AdamsLibGetConnect(vdm_AdamsLib* p, vis_Connect** connect);
VKI_EXTERN void
vdm_AdamsLibSetConnect(vdm_AdamsLib* p, vis_Connect* connect);
VKI_EXTERN void
vdm_AdamsLibSetFunction(vdm_AdamsLib* p, Vint funtype, Vfunc* function, Vobject* object);
VKI_EXTERN void
vdm_AdamsLibSetMonitorFunction(vdm_AdamsLib* p, VAdamsLibMonitorFunc* function, Vobject* object);
VKI_EXTERN void
vdm_AdamsLibAbort(vdm_AdamsLib* p);
VKI_EXTERN void
vdm_AdamsLibOpen(vdm_AdamsLib* p, Vint mode, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_AdamsLibClose(vdm_AdamsLib* p);
VKI_EXTERN void
vdm_AdamsLibAppend(vdm_AdamsLib* p, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_AdamsLibGetNumEntities(vdm_AdamsLib* p, Vint entitytype, Vint* numentity);
VKI_EXTERN void
vdm_AdamsLibGetLibrary(vdm_AdamsLib* p, vdm_Library** library);
VKI_EXTERN void
vdm_AdamsLibNumDatasets(vdm_AdamsLib* p, Vint* numdatasets);
VKI_EXTERN void
vdm_AdamsLibNumAttributes(vdm_AdamsLib* p, Vint idst, Vint* numattributes);
VKI_EXTERN void
vdm_AdamsLibGetAttVal(vdm_AdamsLib* p, Vint idst, Vint iatt, void* value);
VKI_EXTERN void
vdm_AdamsLibInqDataset(vdm_AdamsLib* p, Vint idst, Vchar name[], Vlong* lrec, Vint* nrow, Vint* ncol, Vint* type);
VKI_EXTERN void
vdm_AdamsLibInqAttribute(vdm_AdamsLib* p, Vint idst, Vint iatt, Vchar name[], Vint* length, Vint* type);
VKI_EXTERN void
vdm_AdamsLibReadDataset(vdm_AdamsLib* p, Vint idst, void* buff);
VKI_EXTERN void
vdm_AdamsLibLibDataset(vdm_AdamsLib* p, Vint oper, Vint idst);
VKI_EXTERN void
vdm_AdamsLibSetString(vdm_AdamsLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_AdamsLibGetUnrecognizedData(vdm_AdamsLib* p, vdm_UnrecognizedData** unrecognizedData);
VKI_EXTERN void
vdm_AdamsLibDataFun(vdm_AdamsLib* p, vdm_DataFun* datafun);
VKI_EXTERN void
vdm_AdamsLibGetInteger(vdm_AdamsLib* p, Vint type, Vint* ivalue);
VKI_EXTERN void
vdm_AdamsLibGetString(vdm_AdamsLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_AdamsLibNumDomains(vdm_AdamsLib* p, Vchar* filename, Vint type, Vint* numdomains);

#ifdef __cplusplus
}
#endif

#endif
