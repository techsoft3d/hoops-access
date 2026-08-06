/* Adams .adm Library helper object */
#ifndef ADAMSLIBIO_DEF
#define ADAMSLIBIO_DEF

#include "sam/base/base.h"

#define ADAMSLIBIO_PARAMETER 1000

typedef struct vdm_AdamsLibio {
    FILE* fd;
    FILE* rd;
    Vint line;
    Vint cachedflag;
    Vchar cachedline[82];
    Vint ntokens;
    Vint maxtoken;
    Vint nparams;
    Vint* iparam;
    Vchar** token;
    Vint* flag;
    Vint reslevel;
    Vchar resfile[SYS_MAXPATHCHAR];
    Vchar* attrname;
    Vchar* attrvalue;
    Vchar nodename[256];
    Vint nattr;
    Vint maxattr;
    Vint rescached;
    Vlong pos;
    Vlong ndata;
    Vchar buffer[4096];
    Vint bufsize;
    Vint bufloc;
    Vint last;
    Vint nfloat;
    Vint maxfloats;
    Vfloat* floats;
} vdm_AdamsLibio;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_AdamsLibio*
vdm_AdamsLibioBegin(void);
VKI_EXTERN void
vdm_AdamsLibioEnd(vdm_AdamsLibio* p);
VKI_EXTERN void
vdm_AdamsLibioOpen(vdm_AdamsLibio* p, Vchar filename[], Vchar title[], Vint* hasres, Vchar resfile[], Vint* ierr);
VKI_EXTERN void
vdm_AdamsLibioClose(vdm_AdamsLibio* p);
VKI_EXTERN void
vdm_AdamsLibioAdmKeyword(vdm_AdamsLibio* p, Vchar key[], Vint* id, Vint* nparams, Vint* ierr);
VKI_EXTERN void
vdm_AdamsLibioAdmNumParamArgs(vdm_AdamsLibio* p, Vint iparam, Vchar param[], Vint* nargs);
VKI_EXTERN void
vdm_AdamsLibioAdmParamArgc(vdm_AdamsLibio* p, Vint iparam, Vint iarg, Vchar arg[]);
VKI_EXTERN void
vdm_AdamsLibioAdmParamArgi(vdm_AdamsLibio* p, Vint iparam, Vint iarg, Vint* arg);
VKI_EXTERN void
vdm_AdamsLibioAdmParamArgf(vdm_AdamsLibio* p, Vint iparam, Vint iarg, Vfloat* arg);
VKI_EXTERN void
vdm_AdamsLibioAdmParamArg3f(vdm_AdamsLibio* p, Vint iparam, Vint iarg, Vfloat arg[]);
VKI_EXTERN void
vdm_AdamsLibioAdmParamArga(vdm_AdamsLibio* p, Vint iparam, Vint iarg, Vfloat* arg);
VKI_EXTERN void
vdm_AdamsLibioAdmParamArg3a(vdm_AdamsLibio* p, Vint iparam, Vint iarg, Vfloat arg[]);
VKI_EXTERN void
vdm_AdamsLibioResRead(vdm_AdamsLibio* p, Vchar name[], Vint* nparams, Vint* level, Vint* type, Vlong* pos, Vlong* ndata);
VKI_EXTERN void
vdm_AdamsLibioResAttr(vdm_AdamsLibio* p, Vint n, Vchar** name, Vchar** value);
VKI_EXTERN void
vdm_AdamsLibioSetPos(vdm_AdamsLibio* p, Vlong pos, Vlong ndata);
VKI_EXTERN void
vdm_AdamsLibioDataf(vdm_AdamsLibio* p, Vfloat data[]);
VKI_EXTERN void
vdm_AdamsLibioCachedFloat(vdm_AdamsLibio* p, Vint n, Vfloat* fvalue);

#ifdef __cplusplus
}
#endif

#endif
