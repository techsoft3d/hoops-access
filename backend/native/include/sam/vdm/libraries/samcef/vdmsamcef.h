/* Samcef utility functions header file */
#ifndef VDMSAMCEF_DEF
#define VDMSAMCEF_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/attribute.h"
#include "sam/vdm/dataset.h"
#include "sam/vdm/library.h"
#include "sam/vdm/libraries/samcef/samcefdat.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef VKI_LIBAPI_SAMCEF
extern void
vdm_SAMCEFLib_open(vdm_SAMCEFLib* p);
extern void
vdm_SAMCEFLib_read(vdm_SAMCEFLib* p, Vint enttype, Vint subtype, Vint nrows, vdm_Dataset* dataset, Vint ncols, Vint cols[],
                   Vfloat buf[], Vlong lptr[]);
extern void
vdm_SAMCEFLib_close(vdm_SAMCEFLib* p);
#endif

#ifdef __cplusplus
}
#endif

#endif
