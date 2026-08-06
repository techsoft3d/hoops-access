/* PatLwt object */
#ifndef PATLWT_DEF
#define PATLWT_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"

typedef struct vis_PatLwt {
    Vint ierr;
    FILE* fd;
    vis_GridFun* gf;
    Vint numnp;
    Vint numel;
    Vint aliasnode;
    Vint aliaselem;
    vis_Connect* connect;
    vsy_HashTable* csh;
    vsy_HashTable* mph;
    vsy_HashTable* eph;
} vis_PatLwt;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_PatLwt*
vis_PatLwtBegin(void);
VKI_EXTERN void
vis_PatLwt_Construct(vis_PatLwt* p);
VKI_EXTERN void
vis_PatLwtEnd(vis_PatLwt* p);
VKI_EXTERN void
vis_PatLwt_Destruct(vis_PatLwt* p);
VKI_EXTERN Vint
vis_PatLwtError(vis_PatLwt* p);
VKI_EXTERN void
vis_PatLwtWriteModel(vis_PatLwt* p, vis_Model* model, const Vchar* path);
VKI_EXTERN void
vis_PatLwtWriteState(vis_PatLwt* p, vis_State* state, vis_RProp* rprop, const Vchar* path);

#ifdef __cplusplus
}
#endif

#endif
