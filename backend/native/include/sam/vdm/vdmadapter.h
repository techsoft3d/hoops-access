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
#ifndef VDMADAPTER_DEF
#define VDMADAPTER_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/resultInformation.h"

#define VDM_ADAPTER_UNDEFINED 0
#define VDM_ADAPTER_ANSYS_DPF 1
#define VDM_ADAPTER_PLUGIN    2
#define VDM_ADAPTER_MAX       3

typedef struct vdm_Adapter vdm_Adapter;
struct vdm_Adapter {
    Vint type;
    Vint ierr;
    void* adapterPointer;
};

#ifdef __cplusplus
extern "C" {
#endif
/* create/destroy */
extern vdm_Adapter*
vdm_adapter_create(Vint adapterType, int argumentCount, char* arguments[]);
extern void
vdm_adapter_open(vdm_Adapter* vdm_Adapter, vdm_Settings* settings, Vchar* filename);
extern void
vdm_adapter_close(vdm_Adapter* vdm_Adapter);
extern void
vdm_adapter_destroy(vdm_Adapter** vdm_Adapter);

/* getters */
extern void
vdm_adapter_getObject(vdm_Adapter* vdm_Adapter, Vint objectType, Vobject** object);
extern void
vdm_adapter_getConnect(vdm_Adapter* vdm_Adapter, vis_Connect** connect);
extern Vint
vdm_adapter_resultCount(vdm_Adapter* vdm_Adapter);
extern Vint
vdm_adapter_sectionInfoCount(vdm_Adapter* vdm_Adapter);
extern Vint
vdm_adapter_getSectionResultCount(vdm_Adapter* vdm_Adapter, Vint sectionIndex);
extern void
vdm_adapter_getSectionResultDatasetIndexes(vdm_Adapter* vdm_Adapter, Vint sectionIndex, Vint resultIndex, Vint* ids);
extern void
vdm_adapter_getSectionResultDatasetIndexesCount(vdm_Adapter* vdm_Adapter, Vint sectionIndex, Vint resultIndex, Vint* count);
extern Vint
vdm_adapter_getErrorCode(vdm_Adapter* vdm_Adapter);

extern void
vdm_adapter_resultInfo(vdm_Adapter* vdm_Adapter, Vint resultIndex, vis_ResultInformation* resultInformation);
extern Vint
vdm_adapter_isResult(vdm_Adapter* vdm_Adapter, Vchar* resultIdentifier);

/*setters*/
extern void
vdm_adapter_setResultIdentifier(vdm_Adapter* vdm_Adapter, Vint resultIndex, Vint resultDatasetIndex, Vchar* resultIdentifier);
extern void
vdm_adapter_setSectionIdentifier(vdm_Adapter* vdm_Adapter, Vint sectionIndex, Vchar* sectionIdentifier);
extern void
vdm_adapter_setErrorLevel(vdm_Adapter* vdm_Adapter, Vint errorLevel);
extern void
vdm_adapter_setIntegerOption(vdm_Adapter* vdm_Adapter, const Vchar* optionsNameId, const Vchar* key, const Vchar* description,
                             Vint value);

/* query methods */
extern void
vdm_adapter_loadResultInformation(vdm_Adapter* vdm_Adapter);
extern void
vdm_adapter_loadObject(vdm_Adapter* vdm_Adapter, Vint objectType, Vobject** object);
extern void
vdm_adapter_loadConnect(vdm_Adapter* vdm_Adapter, Vint connectId, vis_Connect** connect);
extern void
vdm_adapter_loadResult(vdm_Adapter* vdm_Adapter, Vchar* resultIdentifier, Vdouble* data, Vint* dataSize);
extern void
vdm_adapter_loadDataset(vdm_Adapter* vdm_Adapter, Vint datasetType, Vchar* resultIdentifier, void* data);
extern void
vdm_adapter_getIntegerOption(vdm_Adapter* vdm_Adapter, const Vchar* optionsNameId, const Vchar* key, Vchar* description,
                             Vint* value);

#ifdef __cplusplus
}
#endif

#endif // VDMADAPTER_DEF
