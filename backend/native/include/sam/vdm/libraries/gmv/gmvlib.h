/* Los Alamos GMV object */
#ifndef GMVLIB_DEF
#define GMVLIB_DEF

#include <stdio.h>

#include "sam/base/base.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vis/connect.h"

/* defines for function prototypes */
typedef void(VGMVLibMonitorFunc)(vdm_GMVLib*, Vobject*);

/* defines for search types */
#define GMVLIB_SEARCH_OFF     0
#define GMVLIB_SEARCH_FILENUM 1

typedef struct vdm_GMVLibio vdm_GMVLibio;

struct vdm_GMVLib {
    Vint ierr;
    Vint type;
    Vchar filename[SYS_MAXPATHCHAR];
    VConventionType conv;
    Vint nodata;
    Vint retcon;
    Vint status;
    Vint numnp;
    Vint numel;
    Vint nface;
    Vint nsurf;
    Vint doubpre;
    Vchar version[17];
    Vchar date[17];
    vdm_Library* library;
    vsy_HashTable* eph;
    vsy_HashTable* elemsets;
    vsy_HashTable* nodesets;
    Vint numelemsets;
    Vint numnodesets;
    Vchar codename[80];

    Vint beginnodemodel;
    Vint beginelemmodel;
    Vint beginelemsurf;
    Vint* vertex;
    Vint maxvertex;
    Vint* faces;
    Vint maxfaces;

    VGMVLibMonitorFunc* funmon;
    Vobject* funobjmon;
    Vint abortflag;
    vsy_Dictionary* elemtypes;
    vsy_Dictionary* resdict;

    vis_Connect* connect;
    vis_GProp* gprop;
    vdm_GMVLibio* io;
    vdm_Permute* permute;
    Vfloat t;
    Vint timeset;
    Vint cycleset;
    Vint cycleno;
    Vint numnpmodel;
    Vint numelmodel;
    Vint ntracers;
    vsy_Dictionary* restypes;
    vis_Connect* connectface;
    Vlong cellpos;
    Vint polyshape;
    Vint* cellno;

    Vint numdatasets;
    vdm_GMVLib* parlib;
    vdm_GMVLib* curlib;
    vdm_Dataset** libs;
    Vchar** fnames;
    Vint* fids;
    Vint* fsort;
    Vint* libdsts;
    Vint numlib;
    /* get integer values */
    Vint phase;
    /* get string values */
    Vchar source[VDM_SOURCE_SIZE];
    Vdouble* polyx;
    Vint maxpolyx;
    Vint numpoly;
    Vint beginelempoly;
    Vint beginnodepoly;
    Vint search;

    Vint npolynodes;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_GMVLib(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_GMVLib(void);
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
    SetMonitorFunction(VGMVLibMonitorFunc*, Vobject*);
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
    WriteModel(vis_Model*);
    VKI_EXTERN void LibDataset(Vint, Vint);
    VKI_EXTERN void
    DataFun(vdm_DataFun*);
    VKI_EXTERN void
    GetInteger(Vint, Vint*);
    VKI_EXTERN void
    GetString(Vint, Vchar*);
    VKI_EXTERN void
    NumDomains(Vchar*, Vint, Vint*);
    VKI_EXTERN void SetSearch(Vint);
    VKI_EXTERN void
    SetString(Vint, Vchar*);
    VKI_EXTERN void
    GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_GMVLib*
vdm_GMVLibBegin(void);
VKI_EXTERN void
vdm_GMVLib_Construct(vdm_GMVLib* p);
VKI_EXTERN void
vdm_GMVLibEnd(vdm_GMVLib* p);
VKI_EXTERN void
vdm_GMVLib_Destruct(vdm_GMVLib* p);
VKI_EXTERN Vint
vdm_GMVLibError(vdm_GMVLib* p);
VKI_EXTERN void
vdm_GMVLibSetMode(vdm_GMVLib* p, Vint mode, Vint flag);
VKI_EXTERN void
vdm_GMVLibSetConvention(vdm_GMVLib* p, VConventionType convention);
VKI_EXTERN void
vdm_GMVLibSetStatus(vdm_GMVLib* p, Vint status);
VKI_EXTERN void
vdm_GMVLibSetIds(vdm_GMVLib* p, Vint idtype, Vint id1off, Vint id2off, Vint id3off);
VKI_EXTERN void
vdm_GMVLibGetConnect(vdm_GMVLib* p, vis_Connect** connect);
VKI_EXTERN void
vdm_GMVLibSetConnect(vdm_GMVLib* p, vis_Connect* connect);
VKI_EXTERN void
vdm_GMVLibSetFunction(vdm_GMVLib* p, Vint funtype, Vfunc* function, Vobject* object);
VKI_EXTERN void
vdm_GMVLibSetMonitorFunction(vdm_GMVLib* p, VGMVLibMonitorFunc* function, Vobject* object);
VKI_EXTERN void
vdm_GMVLibAbort(vdm_GMVLib* p);
VKI_EXTERN void
vdm_GMVLibOpen(vdm_GMVLib* p, Vint mode, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_GMVLibClose(vdm_GMVLib* p);
VKI_EXTERN void
vdm_GMVLibAppend(vdm_GMVLib* p, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_GMVLibGetNumEntities(vdm_GMVLib* p, Vint entitytype, Vint* numentity);
VKI_EXTERN void
vdm_GMVLibGetLibrary(vdm_GMVLib* p, vdm_Library** library);
VKI_EXTERN void
vdm_GMVLibNumDatasets(vdm_GMVLib* p, Vint* numdatasets);
VKI_EXTERN void
vdm_GMVLibNumAttributes(vdm_GMVLib* p, Vint idst, Vint* numattributes);
VKI_EXTERN void
vdm_GMVLibGetAttVal(vdm_GMVLib* p, Vint idst, Vint iatt, void* value);
VKI_EXTERN void
vdm_GMVLibInqDataset(vdm_GMVLib* p, Vint idst, Vchar name[], Vlong* lrec, Vint* nrow, Vint* ncol, Vint* type);
VKI_EXTERN void
vdm_GMVLibInqAttribute(vdm_GMVLib* p, Vint idst, Vint iatt, Vchar name[], Vint* length, Vint* type);
VKI_EXTERN void
vdm_GMVLibReadDataset(vdm_GMVLib* p, Vint idst, void* buf);
VKI_EXTERN void
vdm_GMVLibWriteModel(vdm_GMVLib* p, vis_Model* model);
VKI_EXTERN void
vdm_GMVLibLibDataset(vdm_GMVLib* p, Vint oper, Vint idst);
VKI_EXTERN void
vdm_GMVLibSetString(vdm_GMVLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_GMVLibGetUnrecognizedData(vdm_GMVLib* p, vdm_UnrecognizedData** unrecognizedData);
VKI_EXTERN void
vdm_GMVLibDataFun(vdm_GMVLib* p, vdm_DataFun* datafun);
VKI_EXTERN void
vdm_GMVLibGetInteger(vdm_GMVLib* p, Vint type, Vint* ivalue);
VKI_EXTERN void
vdm_GMVLibGetString(vdm_GMVLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_GMVLibNumDomains(vdm_GMVLib* p, Vchar* filename, Vint type, Vint* numdomains);
VKI_EXTERN void
vdm_GMVLibSetSearch(vdm_GMVLib* p, Vint search);

#ifdef __cplusplus
}
#endif

#endif
