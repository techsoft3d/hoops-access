/* Adams results */

#ifndef ADAMSDAT_DEF
#define ADAMSDAT_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"

typedef struct {
    Vlong pos;
    Vlong ndata;
    Vint nadd;
    Vint iter;
    Vint derived;
    Vint* id;
    Vint* icmp;
    Vint* enttype;
    Vint* objid;
} vdm_AdamsDat;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_AdamsDat*
vdm_AdamsDatBegin(void);
VKI_EXTERN void
vdm_AdamsDatEnd(vdm_AdamsDat* p);
VKI_EXTERN void
vdm_AdamsDatSetDerived(vdm_AdamsDat* p, Vint derived);
VKI_EXTERN void
vdm_AdamsDatSetPos(vdm_AdamsDat* p, Vlong pos, Vlong ndata);
VKI_EXTERN void
vdm_AdamsDatGetDerived(vdm_AdamsDat* p, Vint* derived);
VKI_EXTERN void
vdm_AdamsDatGetPos(vdm_AdamsDat* p, Vlong* pos, Vlong* ndata);
VKI_EXTERN void
vdm_AdamsDatAdd(vdm_AdamsDat* p, Vint id, Vint icmp, Vint enttype, Vint objid);
VKI_EXTERN void
vdm_AdamsDatInitIter(vdm_AdamsDat* p);
VKI_EXTERN void
vdm_AdamsDatNextIter(vdm_AdamsDat* p, Vint* id, Vint* icmp, Vint* enttype, Vint* objid);

#ifdef __cplusplus
}
#endif

#endif
