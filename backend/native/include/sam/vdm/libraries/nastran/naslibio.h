/* Nastran OUTPUT2 Library io object */
#ifndef NASLIBIO_DEF
#define NASLIBIO_DEF

#include "sam/base/base.h"
#include "sam/vdm/vdmoper.h"

/* integer definitions */
#define NASLIBIO_ILP64    1
#define NASLIBIO_BYTESWAP 2
#define NASLIBIO_VENDOR   3
/* parameter settings */
#define NASLIBIO_NOIDARRAY 1

typedef struct vdm_NASLibio {
    Vint ierr;
    Vchar filename[SYS_MAXPATHCHAR];
    FILE* fd;
    Vint nwds;
    Vint* ib;
    Vlong* lb;
    Vint* iz;
    Vlong* lz;
    Vlong fiolen; /* FORTRAN record size in chars */
    Vint isDataInBuffer;
    Vint icbp;
    Vint irl;
    Vint isDataInBufferSave, icbpsav, irlsav;
    Vint vsap;
    Vint byteswap;
    Vint ilp64;
    Vint vendor;
    Vint nlrtyp;  /* next logical record type: =0 for tables, =1/2/3 for Matrices */
    Vint nlrlwds; /* Matrix table: next logical record lenght in words */
    Vint noidarray;
    Vint fword;
} vdm_NASLibio;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_NASLibio*
vdm_NASLibioBegin(void);
VKI_EXTERN void
vdm_NASLibioEnd(vdm_NASLibio* p);
VKI_EXTERN Vint
vdm_NASLibioError(vdm_NASLibio* p);
VKI_EXTERN void
vdm_NASLibioOpen(vdm_NASLibio* p, Vchar filename[], Vint* status);
VKI_EXTERN void
vdm_NASLibioOpenFile(vdm_NASLibio* p);
VKI_EXTERN void
vdm_NASLibioCloseFile(vdm_NASLibio* p);
VKI_EXTERN void
vdm_NASLibioInit(vdm_NASLibio* p, Vint date[3], Vchar* title, Vchar* label, Vfloat* release, Vchar* version, Vint* ierr);
VKI_EXTERN void
vdm_NASLibioClose(vdm_NASLibio* p);
VKI_EXTERN void
vdm_NASLibioSetParami(vdm_NASLibio* p, Vint type, Vint iparam);
VKI_EXTERN void
vdm_NASLibioGetInteger(vdm_NASLibio* p, Vint type, Vint* value);
VKI_EXTERN void
vdm_NASLibioHead(vdm_NASLibio* p, Vchar* dbname, Vint trailer[7], Vint header[4], Vint* lrtype, Vint* ierr);
VKI_EXTERN void
vdm_NASLibioGetPos(vdm_NASLibio* p, Vlong* nc);
VKI_EXTERN Vint
vdm_NASLibioSetPos(vdm_NASLibio* p, Vlong nc);
VKI_EXTERN void
vdm_NASLibioSave(vdm_NASLibio* p);
VKI_EXTERN void
vdm_NASLibioRest(vdm_NASLibio* p);
VKI_EXTERN void
vdm_NASLibioPeek(vdm_NASLibio* p, Vint id[], Vint nw, Vint* nwr, Vint* irtn);
VKI_EXTERN void
vdm_NASLibioGetFWord(vdm_NASLibio* p, Vint* fword);
VKI_EXTERN void
vdm_NASLibioDatai(vdm_NASLibio* p, Vint iw, Vint nw, Vint* ival);
VKI_EXTERN void
vdm_NASLibioDatal(vdm_NASLibio* p, Vint iw, Vlong* lval);
VKI_EXTERN void
vdm_NASLibioDataf(vdm_NASLibio* p, Vint iw, Vint nw, Vfloat* fval);
VKI_EXTERN void
vdm_NASLibioFillf(vdm_NASLibio* p, Vint iw, Vint nw, Vfloat* fval);
VKI_EXTERN void
vdm_NASLibioDatad(vdm_NASLibio* p, Vint iw, Vint nw, Vdouble* dval);
VKI_EXTERN void
vdm_NASLibioRead(vdm_NASLibio* p, Vint id[], Vint nw1, Vint iflag, Vint* nwr, Vint* irtn, Vint* ierr);

#ifdef __cplusplus
}
#endif

#endif
