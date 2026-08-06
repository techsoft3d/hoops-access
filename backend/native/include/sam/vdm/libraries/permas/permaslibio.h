/* PERMAS .post Library helper object */
#ifndef PERMASLIBIO_DEF
#define PERMASLIBIO_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/zfile.h"

typedef struct {
    vsy_BitVec* contbv;
    vdm_ZFile* fd;
    Vchar name[SYS_MAXPATHCHAR];
    Vint line;
    Vint nlines;
    Vlong pos;
} vdm_PERMAS_io;

typedef struct vdm_PERMASLibio {
    Vchar buffer[257];
    Vchar (*pname)[257];
    Vint start;
    Vint maxitems;
    Vint nparams;
    Vint header;
    Vint nheader;
    Vint ninclude;
    Vchar key[256];
    vsy_Dictionary* filedic;
    vdm_PERMAS_io* io;
    vsy_Stack* stack;
} vdm_PERMASLibio;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_PERMASLibio*
vdm_PERMASLibioBegin(void);
VKI_EXTERN void
vdm_PERMASLibioEnd(vdm_PERMASLibio* p);
VKI_EXTERN void
vdm_PERMASLibioOpen(vdm_PERMASLibio* p, Vchar* filename, Vint* ierr);
VKI_EXTERN void
vdm_PERMASLibioInclude(vdm_PERMASLibio* p, Vchar filename[], Vint* ierr);
VKI_EXTERN void
vdm_PERMASLibioClose(vdm_PERMASLibio* p);
VKI_EXTERN void
vdm_PERMASLibioHeader(vdm_PERMASLibio* p, Vchar key[], Vint* nparam);
VKI_EXTERN void
vdm_PERMASLibioParam(vdm_PERMASLibio* p, Vint iparam, Vchar name[]);
VKI_EXTERN void
vdm_PERMASLibioDataLine(vdm_PERMASLibio* p, Vint* nparam);
VKI_EXTERN void
vdm_PERMASLibioRewind(vdm_PERMASLibio* p);
VKI_EXTERN void
vdm_PERMASLibioTell(vdm_PERMASLibio* p, Vchar filename[], Vlong* nc, Vint* line);
VKI_EXTERN void
vdm_PERMASLibioSeek(vdm_PERMASLibio* p, Vint line, Vlong offset, Vint whence);
VKI_EXTERN void
vdm_PERMASLibioPush(vdm_PERMASLibio* p, Vchar filename[]);
VKI_EXTERN void
vdm_PERMASLibioPop(vdm_PERMASLibio* p);

#ifdef __cplusplus
}
#endif

#endif
