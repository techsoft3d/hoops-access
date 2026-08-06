/* h3d utility functions header file */
#ifndef VDMH3D_DEF
#define VDMH3D_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/attribute.h"
#include "sam/vdm/dataset.h"
#include "sam/vdm/library.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef VKI_LIBAPI_H3D
extern void
vdm_h3dOpen(vdm_H3DLib* p, Vchar* filename);
extern void
vdm_h3dClose(vdm_H3DLib* p);
extern void
vdm_h3dRead(vdm_H3DLib* p, Vint enttype, Vint subtype, Vint nrows, vdm_Dataset* dataset, Vint ncols, Vint cols[], Vfloat buf[],
            Vlong lptr[]);
extern void
vdm_h3dInit(vdm_H3DLib* p);
extern void
vdm_h3dTerm(vdm_H3DLib* p);
extern void
vdm_h3dPushLib(vdm_H3DLib* p, Vint* ier);
extern void
vdm_h3dPopLib(vdm_H3DLib* p);
#endif

#ifdef __cplusplus
}
#endif

#endif
