/* vdm odb utility functions header file */
#ifndef VDMODB_DEF
#define VDMODB_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/attribute.h"
#include "sam/vdm/dataset.h"
#include "sam/vdm/library.h"
#include "sam/vdm/permute.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef VKI_LIBAPI_ABAODB
extern void
vdm_odbInit(void);
extern void
vdm_odbTerm(void);
extern void
vdm_odbUpgrade(vdm_ABALib* p, Vchar* filename, Vchar* upgrade);
extern void
vdm_odbOpen(vdm_ABALib* p, Vchar* filename, Vint status);
extern void
vdm_odbClose(vdm_ABALib* p);
extern void
vdm_odbRead(vdm_ABALib* p, Vint idst, Vint ncols, Vint cols[], Vint buff[], Vfloat fb[], Vlong lptr[]);
extern void
vdm_odbWriteModel(vdm_ABALib* p, vis_Model* model);
extern void
vdm_odbSaveState(vdm_ABALib* p, vis_RProp* rprop, vis_State* state);
#endif

#ifdef __cplusplus
}
#endif

#endif
