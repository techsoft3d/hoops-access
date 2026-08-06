/* VTKLib Library object */
#ifndef VTKLIB_DEF
#define VTKLIB_DEF

#include <stdio.h>

#include "sam/base/basedefs.h"
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/libraries/native/natlib.h"
#include "sam/vdm/lman.h"

/* defines for function prototypes */
typedef void(VVTKLibMonitorFunc)(vdm_VTKLib*, Vobject*);

/* defines for search types */
#define VTKLIB_SEARCH_OFF      0
#define VTKLIB_SEARCH_OPENFOAM 1
#define VTKLIB_SEARCH_MULTIDIR 2

typedef struct vdm_VTKLibio vdm_VTKLibio;

struct vdm_VTKLib {
    Vint ierr;
    Vint type;
    VConventionType conv;
    Vint doubpre;
    Vint doubres;
    Vint nodata;
    Vint retcon;
    Vint idtyp, idoff[3], idbas[3];
    Vint numnp;
    Vint numel;
    Vint numdataset;
    Vint status;
    Vint legacy;
    Vint numcell;
    Vint buflen;
    Vint ibuf;
    Vint swap;
    Vint* ix;
    Vint maxnix;
    Vchar word[256];
    Vlong cellpos;
    Vchar title[81];
    Vchar version[10];
    Vchar buffer[257];
    FILE* fd;
    vdm_Library* library;
    vis_Connect* connect;
    vis_GProp* gprop;
    vsy_HashTable* etypeht; /* HashT to convert VTKLegacy elements to Vdm elements */
    vdm_Permute* permute;
    vdm_VTKLibio* io;

    VVTKLibMonitorFunc* funmon;
    Vobject* funobjmon;
    Vint abortflag;

    Vint ftimeflag;
    Vfloat ftime;
    Vchar fdirname[SYS_MAXPATHCHAR]; /* files directory name */
    vsy_List* filelist;              /* list of vdm_VTKLib_file files in the library */
    Vint nfiles;                     /* total number of vdm_VTKLib_file files in the library */
    Vint idcount;                    /* number of result states time steps */
    vsy_IntHash* idih;
    Vint useid; /* reference user mesh Id=Ids[0] in growing order: 1 per time step */
    Vint single;
    Vfloat usetime;
    Vint search;
    vsy_IntDict* dirid;
    Vint numparts;
    Vchar filename[SYS_MAXPATHCHAR];
    vsy_Dictionary* resdict;

    Vint numlib;
    vdm_Dataset** libs; /* list of library datasets: owned by the root lib. 1 lib per time step */
    Vint* libdsts;      /* linked library datasets: 1 lib per time step */
    vdm_VTKLib* parlib; /* parent library */
    vdm_VTKLib* curlib; /* current library */
    /* get integer values */
    Vint phase;
    /* get string values */
    Vchar source[SYS_MAXPATHCHAR];

    vdm_LMan* lman;                    /* associated lman to save states */
    vdm_DataFun* dfNative;             /* Native df to store result datasets: <=> dfnat in NasLib */
    vdm_NatLib* nativeLib;             /* Native lib for catching states */
    Vchar nativeFile[SYS_MAXPATHCHAR]; /* temporary .vdm native file */
    vis_GridFun* gridFunVtu;           /* GriFun needed to write results */
    Vint statesMustBeWritten;          /* at least 1 state write requested */
    Vint modelMustBeWritten;           /* at model write requested */
    vsy_IntDict* elementTypeDict;      /* Dictionnary to convert Vdm elements to VTKVTU element types */

    Vint zLibCompress;  /* Vtu export ZLIB compression ON/OFF */
    Vint writingFormat; /* Vtu export format Ascii/Binary */
    Vint headerType;    /* Vtu export header Item type Uint64/Uint32 */

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_VTKLib(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_VTKLib(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void SetMode(Vint, Vint);
    VKI_EXTERN void SetConvention(VConventionType);
    VKI_EXTERN void SetStatus(Vint);
    VKI_EXTERN void
    SetConnect(vis_Connect*);
    VKI_EXTERN void
    GetConnect(vis_Connect**);
    VKI_EXTERN void SetIds(Vint, Vint, Vint, Vint);
    VKI_EXTERN void
    SetFunction(Vint, Vfunc*, Vobject*);
    VKI_EXTERN void
    SetMonitorFunction(VVTKLibMonitorFunc*, Vobject*);
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
    VKI_EXTERN void SetSearch(Vint);
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
    VKI_EXTERN void
    WriteModel(vis_Model* model);
    VKI_EXTERN void
    WriteState(vis_RProp* rprop, vis_State* state);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_VTKLib*
vdm_VTKLibBegin(void);
VKI_EXTERN void
vdm_VTKLib_Construct(vdm_VTKLib* p);
VKI_EXTERN void
vdm_VTKLibEnd(vdm_VTKLib* p);
VKI_EXTERN void
vdm_VTKLib_Destruct(vdm_VTKLib* p);
VKI_EXTERN Vint
vdm_VTKLibError(vdm_VTKLib* p);
VKI_EXTERN void
vdm_VTKLibSetMode(vdm_VTKLib* p, Vint mode, Vint flag);
VKI_EXTERN void
vdm_VTKLibSetConvention(vdm_VTKLib* p, VConventionType convention);
VKI_EXTERN void
vdm_VTKLibSetStatus(vdm_VTKLib* p, Vint status);
VKI_EXTERN void
vdm_VTKLibSetConnect(vdm_VTKLib* p, vis_Connect* connect);
VKI_EXTERN void
vdm_VTKLibGetConnect(vdm_VTKLib* p, vis_Connect** connect);
VKI_EXTERN void
vdm_VTKLibSetIds(vdm_VTKLib* p, Vint idtype, Vint id1off, Vint id2off, Vint id3off);
VKI_EXTERN void
vdm_VTKLibSetFunction(vdm_VTKLib* p, Vint funtype, Vfunc* function, Vobject* object);
VKI_EXTERN void
vdm_VTKLibSetMonitorFunction(vdm_VTKLib* p, VVTKLibMonitorFunc* function, Vobject* object);
VKI_EXTERN void
vdm_VTKLibAbort(vdm_VTKLib* p);
VKI_EXTERN void
vdm_VTKLibOpen(vdm_VTKLib* p, Vint mode, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_VTKLibClose(vdm_VTKLib* p);
VKI_EXTERN void
vdm_VTKLibAppend(vdm_VTKLib* p, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_VTKLibGetNumEntities(vdm_VTKLib* p, Vint enttype, Vint* nument);
VKI_EXTERN void
vdm_VTKLibGetLibrary(vdm_VTKLib* p, vdm_Library** library);
VKI_EXTERN void
vdm_VTKLibNumDatasets(vdm_VTKLib* p, Vint* numdatasets);
VKI_EXTERN void
vdm_VTKLibNumAttributes(vdm_VTKLib* p, Vint idst, Vint* numattributes);
VKI_EXTERN void
vdm_VTKLibGetAttVal(vdm_VTKLib* p, Vint idst, Vint iatt, void* value);
VKI_EXTERN void
vdm_VTKLibInqDataset(vdm_VTKLib* p, Vint idst, Vchar name[], Vlong* lrec, Vint* nrow, Vint* ncol, Vint* type);
VKI_EXTERN void
vdm_VTKLibInqAttribute(vdm_VTKLib* p, Vint idst, Vint iatt, Vchar name[], Vint* length, Vint* type);
VKI_EXTERN void
vdm_VTKLibReadDataset(vdm_VTKLib* p, Vint idst, void* buf);
VKI_EXTERN void
vdm_VTKLibLibDataset(vdm_VTKLib* p, Vint oper, Vint idst);
VKI_EXTERN void
vdm_VTKLibSetString(vdm_VTKLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_VTKLibGetUnrecognizedData(vdm_VTKLib* p, vdm_UnrecognizedData** unrecognizedData);
VKI_EXTERN void
vdm_VTKLibDataFun(vdm_VTKLib* p, vdm_DataFun* datafun);
VKI_EXTERN void
vdm_VTKLibSetSearch(vdm_VTKLib* p, Vint search);
VKI_EXTERN void
vdm_VTKLibGetInteger(vdm_VTKLib* p, Vint type, Vint* ivalue);
VKI_EXTERN void
vdm_VTKLibGetString(vdm_VTKLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_VTKLibNumDomains(vdm_VTKLib* p, Vchar* filename, Vint type, Vint* numdomains);
VKI_EXTERN void
vdm_VTKLibWriteModel(vdm_VTKLib* p, vis_Model* model);
VKI_EXTERN void
vdm_VTKLibWriteState(vdm_VTKLib* p, vis_RProp* rprop, vis_State* state);

#ifdef __cplusplus
}
#endif

#endif
