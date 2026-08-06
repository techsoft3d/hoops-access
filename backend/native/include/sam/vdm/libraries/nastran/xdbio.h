/* Nastran XDB Library io object */
#ifndef XDBIO_DEF
#define XDBIO_DEF

#include "sam/base/base.h"
#include "sam/vdm/vdmoper.h"

typedef struct vdm_XDBio {
    Vint ierr;
    FILE* fd;
    Vint nwds;
    Vint* ibuf;
    Vlong* lbuf;
    Vint* idata;
    Vlong* ldata;
    Vint datasize;
    Vint byteswap;
    Vint ilp64;
    Vint iheader[24];
    Vlong lheader[24];
    Vint curblock;
    Vint iobj[24];
    Vlong lobj[24];
    Vint ndicentries;
    Vint idicentry;
    Vint iloc;
    Vint dbptr;
    Vint nextblock;
    Vint jloc;
    Vint ientry;
    Vint nentries;
    Vint iword;
    Vint nwords;
    Vint dicblock;
    Vint secondary;
    Vint nkeys;
    Vint fact;
    Vint negkey;
    Vint numread;
} vdm_XDBio;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_XDBio*
vdm_XDBioBegin(void);
VKI_EXTERN void
vdm_XDBioEnd(vdm_XDBio* p);
VKI_EXTERN Vint
vdm_XDBioError(vdm_XDBio* p);
VKI_EXTERN void
vdm_XDBioOpen(vdm_XDBio* p, Vchar filename[], Vchar version[], Vint* ierr);
VKI_EXTERN void
vdm_XDBioClose(vdm_XDBio* p);
VKI_EXTERN Vint
vdm_XDBioInitDict(vdm_XDBio* p);
VKI_EXTERN void
vdm_XDBioNextDict(vdm_XDBio* p, Vchar name[], Vint* flag);
VKI_EXTERN void
vdm_XDBioGetDictPartID(vdm_XDBio* p, Vint* partid);
VKI_EXTERN void
vdm_XDBioGetDictSetID(vdm_XDBio* p, Vint* setid);
VKI_EXTERN void
vdm_XDBioGetDictSubcaseID(vdm_XDBio* p, Vint* subcaseid);
VKI_EXTERN void
vdm_XDBioGetDictClassType(vdm_XDBio* p, Vint* classtype);
VKI_EXTERN void
vdm_XDBioGetDictSize(vdm_XDBio* p, Vint* size);
VKI_EXTERN Vint
vdm_XDBioInitRecord(vdm_XDBio* p, Vint* nkeys);
VKI_EXTERN void
vdm_XDBioNextRecord(vdm_XDBio* p, Vint* flag);
VKI_EXTERN void
vdm_XDBioSkipRecord(vdm_XDBio* p, Vint num, Vint* flag);
VKI_EXTERN void
vdm_XDBioDatai(vdm_XDBio* p, Vint start, Vint num, Vint value[]);
VKI_EXTERN void
vdm_XDBioDataf(vdm_XDBio* p, Vint start, Vint num, Vfloat value[]);
VKI_EXTERN void
vdm_XDBioDatal(vdm_XDBio* p, Vint start, Vint num, Vlong value[]);
VKI_EXTERN void
vdm_XDBioDatad(vdm_XDBio* p, Vint start, Vint num, Vdouble value[]);
VKI_EXTERN void
vdm_XDBioDatah(vdm_XDBio* p, Vint start, Vint num, Vint value[]);
VKI_EXTERN void
vdm_XDBioGetPos(vdm_XDBio* p, Vint* dbptr, Vint* blockid);
VKI_EXTERN void
vdm_XDBioSetPos(vdm_XDBio* p, Vint dbptr, Vint blockid, Vchar cname[]);
VKI_EXTERN Vint
vdm_XDBioKeys(vdm_XDBio* p, Vint key[3]);
VKI_EXTERN void
vdm_XDBioSetNegKeys(vdm_XDBio* p, Vint flag);
VKI_EXTERN void
vdm_XDBioNumSeq(vdm_XDBio* p, Vint* numseq);

#ifdef __cplusplus
}
#endif

#endif
