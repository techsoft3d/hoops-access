/* GMV Library helper object */
#ifndef GMVLIBIO_DEF
#define GMVLIBIO_DEF

#include "sam/base/base.h"
#include "sam/vdm/zfile.h"

/* file format types */
#define GMV_FORMAT_ASCII 1
#define GMV_FORMAT_BIN   2

typedef struct vdm_GMVLibio {
    FILE* fd;
    FILE* pfd;
    Vint ftype;
    Vint pftype;
    Vint nentries;
    Vint nproc;
    Vint swap;
    Vint charsize;
    Vint pcharsize;
    Vchar path[SYS_MAXPATHCHAR];
    Vchar buf[40][80];
    Vchar buffer[4096];
    Vint bufloc;
    Vint bufsize;
    Vlong pos;
} vdm_GMVLibio;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_GMVLibio*
vdm_GMVLibioBegin(void);
VKI_EXTERN void
vdm_GMVLibioEnd(vdm_GMVLibio* p);
VKI_EXTERN void
vdm_GMVLibioOpen(vdm_GMVLibio* p, Vchar* filename, Vint* ierr);
VKI_EXTERN void
vdm_GMVLibioDatac(vdm_GMVLibio* p, Vint n, Vchar str[], Vint* ierr);
VKI_EXTERN void
vdm_GMVLibioDataci(vdm_GMVLibio* p, Vint n, Vchar comp[], Vint* ivalue, Vint* ierr);
VKI_EXTERN void
vdm_GMVLibioDatas(vdm_GMVLibio* p, Vchar str[], Vint* ierr);
VKI_EXTERN void
vdm_GMVLibioDatai(vdm_GMVLibio* p, Vint n, Vint* ivalue, Vint* ierr);
VKI_EXTERN void
vdm_GMVLibioDataf(vdm_GMVLibio* p, Vint n, Vfloat* fvalue, Vint* ierr);
VKI_EXTERN void
vdm_GMVLibioDatad(vdm_GMVLibio* p, Vint n, Vdouble* dvalue, Vint* ierr);
VKI_EXTERN void
vdm_GMVLibioSkipi(vdm_GMVLibio* p, Vint n);
VKI_EXTERN void
vdm_GMVLibioSkipf(vdm_GMVLibio* p, Vint n);
VKI_EXTERN void
vdm_GMVLibioClose(vdm_GMVLibio* p);
VKI_EXTERN void
vdm_GMVLibioKeyword(vdm_GMVLibio* p, Vchar key[], Vchar errfile[], Vint* ierr);
VKI_EXTERN void
vdm_GMVLibioSeek(vdm_GMVLibio* p, Vlong pos);
VKI_EXTERN void
vdm_GMVLibioTell(vdm_GMVLibio* p, Vlong* pos);

#ifdef __cplusplus
}
#endif

#endif
