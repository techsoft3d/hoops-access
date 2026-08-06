/* vdm xdb utility functions header file */
#ifndef VDMXDB_DEF
#define VDMXDB_DEF

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

/* complex types */
#define VDM_XDB_R  SYS_COMPLEX_NONE
#define VDM_XDB_RI SYS_COMPLEX_REALIMAGINARY
#define VDM_XDB_MP SYS_COMPLEX_MAGNITUDEPHASE

extern void
vdm_xdbOpen(vdm_NASLib* p);
extern void
vdm_xdbClose(vdm_NASLib* p);
extern void
vdm_xdbReadDataset(vdm_NASLib* p, Vint idst, Vint ncols, Vint cols[], Vint ibuf[], Vlong lptr[]);

#ifdef __cplusplus
}
#endif

#endif
