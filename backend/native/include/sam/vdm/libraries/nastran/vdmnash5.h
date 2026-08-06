/* vdm H5 utility functions header file */
#ifndef VDMNASH5_DEF
#define VDMNASH5_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/libraries/nastran/naslib.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void
vdm_nash5Open(vdm_NASLib* p);
extern void
vdm_nash5Close(vdm_NASLib* p);
extern void
vdm_nash5ReadDataset(vdm_NASLib* p, Vint idst, Vint ibuf[]);

#ifdef __cplusplus
}
#endif

#endif
