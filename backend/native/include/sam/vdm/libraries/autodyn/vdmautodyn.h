/* autodyn utility functions header file */
#ifndef VDMAUTODYN_DEF
#define VDMAUTODYN_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/attribute.h"
#include "sam/vdm/dataset.h"
#include "sam/vdm/library.h"
#include "sam/vdm/libraries/autodyn/autodyndat.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef VKI_LIBAPI_AUTODYN
extern void
vdm_AUTODYNLib_open(vdm_AUTODYNLib* p, Vchar* filename);
extern void
vdm_AUTODYNLib_read(vdm_AUTODYNLib* p, Vint enttype, Vint subtype, Vint nrows, vdm_Dataset* dataset, Vfloat buf[]);
#endif

#ifdef __cplusplus
}
#endif

#endif
