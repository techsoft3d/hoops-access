#ifndef PLUGINLIB_DEF
#define PLUGINLIB_DEF

#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/vdmadapter.h"

/* defines for function prototypes */
typedef void(VPluginLibMonitorFunc)(vdm_PluginLib*, Vobject*);

struct vdm_PluginLib {
    vdm_Adapter* pluginAdapter; /* holds the address to a c++ class objec t*/
    vdm_Library* library;       /* Library where all datasets are stored */
    Vint ierr;
    VConventionType conventions;
    Vint errorLevel;

    /* Named funmon for consistency. In the other libraries, there is an equivalent funmon, but each has their on type */
    VPluginLibMonitorFunc* funmon;
    Vobject* funobjmon;
    Vint phase;
    Vchar source[VDM_SOURCE_SIZE];

    Vint abortflag; /* Checked when calling the monitor function */

    vdm_Settings* settings; /*pointer to global library and pluging settings*/

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_PluginLib(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_PluginLib(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN void
    Def(Vchar*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void
    Close();
    VKI_EXTERN void
    Open(Vint, Vchar*, Vint);
    VKI_EXTERN void
    DataFun(vdm_DataFun*);
    VKI_EXTERN void
    GetConnect(vis_Connect**);
    VKI_EXTERN void
    GetNumEntities(Vint, Vint*);
    VKI_EXTERN void
    GetLibrary(vdm_Library**);
    VKI_EXTERN void SetStatus(Vint);
    VKI_EXTERN void
    GetAttVal(Vint, Vint, void*);
    VKI_EXTERN void
    NumDatasets(Vint*);
    VKI_EXTERN void
    NumAttributes(Vint, Vint*);
    VKI_EXTERN void
    InqDataset(Vint, Vchar*, Vlong*, Vint*, Vint*, Vint*);
    VKI_EXTERN void
    InqAttribute(Vint, Vint, Vchar*, Vint*, Vint*);
    VKI_EXTERN void
    ReadDataset(Vint, void*);
    VKI_EXTERN void SetMode(Vint, Vint);
    VKI_EXTERN void SetConvention(VConventionType);
    VKI_EXTERN void
    DefDataset(const Vchar*, Vlong, Vint, Vint, Vint, Vint*);
    VKI_EXTERN void
    WriteDataset(Vint, void*);
    VKI_EXTERN void
    Append(Vchar*, Vint);
    VKI_EXTERN void SetIds(Vint, Vint, Vint, Vint);
    VKI_EXTERN void
    SetConnect(vis_Connect*);
    VKI_EXTERN void LibDataset(Vint, Vint);
    VKI_EXTERN void
    DefAttribute(Vint, const Vchar*, Vint, Vint, Vint*);
    VKI_EXTERN void
    SetAttVal(Vint, Vint, void*);
    VKI_EXTERN void
    GetInteger(Vint, Vint*);
    VKI_EXTERN void
    GetString(Vint, Vchar*);
    VKI_EXTERN void
    NumDomains(Vchar*, Vint, Vint*);
    VKI_EXTERN void
    ReadDatasetCols(Vint, Vint, Vint*, void*, Vlong*);
    VKI_EXTERN void SetErrorLevel(Vint);
    VKI_EXTERN void
    ApplySettings(vdm_Settings* globalSettings);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_PluginLib*
vdm_PluginLibBegin(void);
VKI_EXTERN void
vdm_PluginLib_Construct(vdm_PluginLib* p);
VKI_EXTERN void
vdm_PluginLibDef(vdm_PluginLib* p, Vchar* pathToPluginLibrary);
VKI_EXTERN void
vdm_PluginLibEnd(vdm_PluginLib* p);
VKI_EXTERN void
vdm_PluginLib_Destruct(vdm_PluginLib* p);
VKI_EXTERN Vint
vdm_PluginLibError(vdm_PluginLib* p);
VKI_EXTERN void
vdm_PluginLibClose(vdm_PluginLib* p);
VKI_EXTERN void
vdm_PluginLibApplySettings(vdm_PluginLib* p, vdm_Settings* globalSettings);
VKI_EXTERN void
vdm_PluginLibOpen(vdm_PluginLib* p, Vint mode, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_PluginLibDataFun(vdm_PluginLib* p, vdm_DataFun* datafun);
VKI_EXTERN void
vdm_PluginLibGetConnect(vdm_PluginLib* p, vis_Connect** connect);
VKI_EXTERN void
vdm_PluginLibGetNumEntities(vdm_PluginLib* p, Vint entitytype, Vint* numentity);
VKI_EXTERN void
vdm_PluginLibGetLibrary(vdm_PluginLib* p, vdm_Library** library);
VKI_EXTERN void
vdm_PluginLibSetStatus(vdm_PluginLib* p, Vint status);
VKI_EXTERN void
vdm_PluginLibGetAttVal(vdm_PluginLib* p, Vint datasetIndex, Vint iatt, void* value);
VKI_EXTERN void
vdm_PluginLibNumDatasets(vdm_PluginLib* p, Vint* numdatasets);
VKI_EXTERN void
vdm_PluginLibNumAttributes(vdm_PluginLib* p, Vint datasetIndex, Vint* numattributes);
VKI_EXTERN void
vdm_PluginLibInqDataset(vdm_PluginLib* p, Vint datasetIndex, Vchar name[], Vlong* lrec, Vint* nrow, Vint* ncol, Vint* type);
VKI_EXTERN void
vdm_PluginLibInqAttribute(vdm_PluginLib* p, Vint idst, Vint iatt, Vchar name[], Vint* length, Vint* type);
VKI_EXTERN void
vdm_PluginLibReadDataset(vdm_PluginLib* p, Vint datasetIndex, void* data);
VKI_EXTERN void
vdm_PluginLibSetMode(vdm_PluginLib* p, Vint mode, Vint flag);
VKI_EXTERN void
vdm_PluginLibSetConvention(vdm_PluginLib* p, VConventionType convention);
VKI_EXTERN void
vdm_PluginLibDefDataset(vdm_PluginLib* p, const Vchar* name, Vlong lrec, Vint nrow, Vint ncol, Vint type, Vint* idst);
VKI_EXTERN void
vdm_PluginLibWriteDataset(vdm_PluginLib* p, Vint idst, void* buff);
VKI_EXTERN void
vdm_PluginLibAppend(vdm_PluginLib* p, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_PluginLibSetIds(vdm_PluginLib* p, Vint idtype, Vint id1, Vint id2, Vint id3);
VKI_EXTERN void
vdm_PluginLibSetConnect(vdm_PluginLib* p, vis_Connect* connect);
VKI_EXTERN void
vdm_PluginLibLibDataset(vdm_PluginLib* p, Vint oper, Vint idst);
VKI_EXTERN void
vdm_PluginLibDefAttribute(vdm_PluginLib* p, Vint idst, const Vchar* name, Vint length, Vint type, Vint* iatt);
VKI_EXTERN void
vdm_PluginLibSetAttVal(vdm_PluginLib* p, Vint idst, Vint iatt, void* value);
VKI_EXTERN void
vdm_PluginLibGetInteger(vdm_PluginLib* p, Vint type, Vint* ivalue);
VKI_EXTERN void
vdm_PluginLibGetString(vdm_PluginLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_PluginLibNumDomains(vdm_PluginLib* p, Vchar* filename, Vint type, Vint* numdomains);
VKI_EXTERN void
vdm_PluginLibReadDatasetCols(vdm_PluginLib* p, Vint idst, Vint ncols, Vint cols[], void* buf, Vlong* lptr);
VKI_EXTERN void
vdm_PluginLibSetErrorLevel(vdm_PluginLib* p, Vint errorLevel);

#ifdef __cplusplus
}
#endif

#endif
