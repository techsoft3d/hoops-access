/* PAMLib dataset object */

#ifndef PAMDAT_DEF
#define PAMDAT_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"

typedef struct vdm_PAMDat {
    Vint* ncoo;
    Vint hist;
    Vint ntyp;
    Vint nqua;
    Vint iqua[SYS_NQUA_MAX];
    Vchar cqua[256];
    Vint cplx;
    Vint ncmp;
    Vint enttype;
    Vint subtype;
    Vint id1;
    Vint id2;
    Vint id3;
    Vint maxpath;
    Vint npath;
    Vint maxindex;
    Vint nindex;
    Vint curpath;
    Vint curindex;
    Vchar** path;
    Vchar** indexname;
    Vfloat* indexval;
    Vobject** varname;
    Vint** map;
    Vint* rank;
    Vint* ivar;
    Vint* ndim;
    Vint* offset;
    Vint* izone;
    Vint* node;
    vsy_IntVec* seciv;
    Vint nvar;
    Vint rigidElementType;
    Vint vrotang;
    vdm_Dataset* dataset;
} vdm_PAMDat;

typedef enum { PAM_ERF_RIGID_UNKNOWN, PAM_ERF_RIGID_OTMCO, PAM_ERF_RIGID_MTOCO, PAM_ERF_RIGID_RBODY } pamErf_RBEType;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_PAMDat*
vdm_PAMDatBegin(void);
VKI_EXTERN void
vdm_PAMDatEnd(vdm_PAMDat* p);
VKI_EXTERN void
vdm_PAMDatDef(vdm_PAMDat* p, Vint hist, Vint ntyp, Vint nqua, Vint iqua[], Vchar* cqua, Vint cplx, Vint ncmp, Vint enttype,
              Vint subtype, Vint id1, Vint id2, Vint id3, Vint rigidElementType);
VKI_EXTERN void
vdm_PAMDatInq(vdm_PAMDat* p, Vint* hist, Vint* ntyp, Vint* nqua, Vint iqua[], Vchar* cqua, Vint* cplx, Vint* ncmp, Vint* enttype,
              Vint* subtype, Vint* id1, Vint* id2, Vint* id3, Vint* rigidElementType);
VKI_EXTERN void
vdm_PAMDatAddPath(vdm_PAMDat* p, Vchar* path, Vobject* varname);
VKI_EXTERN void
vdm_PAMDatInitPath(vdm_PAMDat* p);
VKI_EXTERN void
vdm_PAMDatNextPath(vdm_PAMDat* p, Vchar** path, Vobject** varname);
VKI_EXTERN void
vdm_PAMDatAddIndex(vdm_PAMDat* p, Vchar* name, Vfloat value);
VKI_EXTERN void
vdm_PAMDatInitIndex(vdm_PAMDat* p);
VKI_EXTERN void
vdm_PAMDatNextIndex(vdm_PAMDat* p, Vchar** name, Vfloat* value);
VKI_EXTERN void
vdm_PAMDatAddVar(vdm_PAMDat* p, Vint map[], Vint rank, Vint ndim, Vint ncoo, Vint ivar, Vint offset, Vint izone, Vint node);
VKI_EXTERN void
vdm_PAMDatGetVar(vdm_PAMDat* p, Vint ipath, Vint** map, Vint* rank, Vint* ndim, Vint* ncoo, Vint* ivar, Vint* offset, Vint* izone,
                 Vint* node);
VKI_EXTERN void
vdm_PAMDatAddSection(vdm_PAMDat* p, Vint numsec);
VKI_EXTERN void
vdm_PAMDatGetSection(vdm_PAMDat* p, Vint ipath, Vint* numsec);
VKI_EXTERN void
vdm_PAMDatSetVirtualRotAng(vdm_PAMDat* p, Vint flag);
VKI_EXTERN void
vdm_PAMDatGetVirtualRotAng(vdm_PAMDat* p, Vint* flag);
VKI_EXTERN void
vdm_PAMDatSetLink(vdm_PAMDat* p, vdm_Dataset* dataset);
VKI_EXTERN void
vdm_PAMDatGetLink(vdm_PAMDat* p, vdm_Dataset** dataset);

#ifdef __cplusplus
}
#endif

#endif
