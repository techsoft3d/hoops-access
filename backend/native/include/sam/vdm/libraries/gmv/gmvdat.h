/* GMV results */

#ifndef GMVDAT_DEF
#define GMVDAT_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"

#define GMV_INTERIOR -1
#define GMV_TRACER   -2
#define GMV_SURF     -3
#define GMV_BOTH     -4

typedef struct {
    Vint nentries;
    Vint types;
    Vint* type;
    Vint* nrcmp;
    Vint* ncmp;
    Vint* icmp;
    Vint* ocmp;
    Vint* enttype;
    Vlong* pos;
    Vint icur;
} vdm_GMVDat;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_GMVDat*
vdm_GMVDatBegin(void);
VKI_EXTERN void
vdm_GMVDatEnd(vdm_GMVDat* p);
VKI_EXTERN void
vdm_GMVDatAdd(vdm_GMVDat* p, Vint type, Vint nrcmp, Vint ncmp, Vint icmp[], Vint ocmp[], Vint enttype, Vlong pos);
VKI_EXTERN void
vdm_GMVDatInitIter(vdm_GMVDat* p);
VKI_EXTERN void
vdm_GMVDatNextIter(vdm_GMVDat* p, Vint* type, Vint* nrcmp, Vint* ncmp, Vint icmp[], Vint ocmp[], Vint* enttype, Vlong* pos);
VKI_EXTERN void
vdm_GMVDatGetTypes(vdm_GMVDat* p, Vint* types);

#ifdef __cplusplus
}
#endif

#endif
