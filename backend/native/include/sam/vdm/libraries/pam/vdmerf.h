/* vdm ERF utility functions header file */
#ifndef VDMERF_DEF
#define VDMERF_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"

#ifdef __cplusplus
extern "C" {
#endif

extern Vint
vdm_PAMLibMonitor(vdm_PAMLib* p);
extern void
vdm_erfOpen(vdm_PAMLib* p, Vchar* filename, Vint type);
extern void
vdm_erfClose(vdm_PAMLib* p);
extern void
vdm_erfRead(vdm_PAMLib* p, Vint idst, Vint ncols, Vint cols[], Vint ibuf[], Vfloat fbuf[], Vlong lptr[]);

#ifdef __cplusplus
}
#endif

#endif
