/* PERMAS results */

#ifndef PERMASDAT_DEF
#define PERMASDAT_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/libraries/permas/vdmpermas.h"
#include "sam/vis/idtran.h"

#define PERMASDAT_SECTION 1
#define PERMASDAT_CID     2

typedef struct {
    Vint mode;
    Vint nentries;
    Vint num;
    Vint iter;
    Vlong* nc;
    Vint* line;
    Vint* column;
    Vint* ncols;
    Vint* ientry;
    Vint* numsec;
    Vint* nstresscomp;
    Vchar** eltype;
    Vchar** filename;
    vis_IdTran* secidtran;
    vis_IdTran* cididtran;
    vdm_PERMASLib_restype** restype;
} vdm_PERMASDat;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_PERMASDat*
vdm_PERMASDatBegin(void);
VKI_EXTERN void
vdm_PERMASDatEnd(vdm_PERMASDat* p);
VKI_EXTERN void
vdm_PERMASDatDef(vdm_PERMASDat* p, Vint mode, Vint nentries);
VKI_EXTERN void
vdm_PERMASDatInq(vdm_PERMASDat* p, Vint* mode, Vint* nentries);
VKI_EXTERN void
vdm_PERMASDatAdd(vdm_PERMASDat* p, Vchar filename[], Vlong nc, Vint line, Vchar eltype[], Vint column, Vint ncols, Vint ientry,
                 Vint numsec, Vint nstresscomp, vdm_PERMASLib_restype* restype);
VKI_EXTERN void
vdm_PERMASDatInitIter(vdm_PERMASDat* p);
VKI_EXTERN void
vdm_PERMASDatNextIter(vdm_PERMASDat* p, Vchar filename[], Vlong* nc, Vint* line, Vchar eltype[], Vint* column, Vint* ncols,
                      Vint* ientry, Vint* numsec, Vint* nstresscomp, vdm_PERMASLib_restype** restype);
VKI_EXTERN void
vdm_PERMASDatSetIdTran(vdm_PERMASDat* p, Vint type, vis_IdTran* idtran);
VKI_EXTERN void
vdm_PERMASDatGetIdTran(vdm_PERMASDat* p, Vint type, vis_IdTran** idtran);
VKI_EXTERN void
vdm_PERMASDatCopy(vdm_PERMASDat* p, vdm_PERMASDat* q);

#ifdef __cplusplus
}
#endif

#endif
