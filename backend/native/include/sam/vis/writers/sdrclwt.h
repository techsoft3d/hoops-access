/* SDRCLwt object */
#ifndef SDRCLWT_DEF
#define SDRCLWT_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"

typedef struct vis_SDRCLwt {
    Vint ierr;
    FILE* fd;
    vis_GridFun* gf;
    Vint numnp;
    Vint numel;
    Vint soltyp; /* solution type */
    Vint nantyp; /* analysis type */
    Vint twotyp; /* 2D type */
    Vint nonlin; /* nonlinear flag */
    Vint aliasnode;
    Vint aliaselem;
    vis_Connect* connect;
    vis_Units* units;
    vsy_HashTable* csh;
    vsy_HashTable* mph;
    vsy_HashTable* eph;
    Vint adl; /* dataset 2414, Analysis dataset label */
} vis_SDRCLwt;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_SDRCLwt*
vis_SDRCLwtBegin(void);
VKI_EXTERN void
vis_SDRCLwt_Construct(vis_SDRCLwt* p);
VKI_EXTERN void
vis_SDRCLwtEnd(vis_SDRCLwt* p);
VKI_EXTERN void
vis_SDRCLwt_Destruct(vis_SDRCLwt* p);
VKI_EXTERN Vint
vis_SDRCLwtError(vis_SDRCLwt* p);
VKI_EXTERN void
vis_SDRCLwtWriteModel(vis_SDRCLwt* p, vis_Model* model, const Vchar* path);
VKI_EXTERN void
vis_SDRCLwtWriteState(vis_SDRCLwt* p, vis_State* state, vis_RProp* rprop, const Vchar* path);
VKI_EXTERN void
vis_SDRCLwtgetDataType(Vint restype, Vint nqua, Vint iqua[], Vint* rt, Vint* nvaldc);
VKI_EXTERN void
vis_SDRCLwtgetRsltType(Vint rt, Vint* restype, Vint* nvaldc, Vint* strtyp);
VKI_EXTERN void
vis_SDRCLwtgetRsltQual(Vint rt, Vint* nqua, Vint iqua[], Vchar cqua[]);

#ifdef __cplusplus
}
#endif

#endif
