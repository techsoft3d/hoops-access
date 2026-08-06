/* COMSOL .mph* Library helper object */
#ifndef COMSOLLIBIO_DEF
#define COMSOLLIBIO_DEF

#include "sam/base/base.h"

#define COMSOLLIBIO_BUFSIZE  256
#define COMSOLLIBIO_MAXITEMS 256

typedef struct vdm_COMSOLLibio {
    FILE* fd;
    Vint bin;
    Vint swap;
    Vint size;
    Vint line;
    Vint nitems;
    Vint nread;
    Vint numel;
    Vint numnp;
    Vchar buffer[4096];
    Vchar buf[COMSOLLIBIO_MAXITEMS][COMSOLLIBIO_BUFSIZE];
    Vint bufloc;
    Vint bufsize;
} vdm_COMSOLLibio;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_COMSOLLibio*
vdm_COMSOLLibioBegin(void);
VKI_EXTERN void
vdm_COMSOLLibioEnd(vdm_COMSOLLibio* p);
VKI_EXTERN void
vdm_COMSOLLibioOpen(vdm_COMSOLLibio* p, Vchar* filename, Vint* major, Vint* minor, Vint* binflag, Vint* mversion, Vint* sdim,
                    Vint* ierr);
VKI_EXTERN void
vdm_COMSOLLibioClose(vdm_COMSOLLibio* p);
VKI_EXTERN void
vdm_COMSOLLibioReadi(vdm_COMSOLLibio* p, Vint* ivalue, Vint* ierr);
VKI_EXTERN void
vdm_COMSOLLibioReadd(vdm_COMSOLLibio* p, Vdouble* dvalue, Vint* ierr);
VKI_EXTERN void
vdm_COMSOLLibioReadc(vdm_COMSOLLibio* p, Vint nchars, Vchar cvalue[], Vint* ierr);

#ifdef __cplusplus
}
#endif

#endif
