/* RASFwt object */
#ifndef RASFWT_DEF
#define RASFWT_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"

typedef struct vis_RASFwt {
    Vint ierr;
    FILE* fd;
    vis_GridFun* gf;
    Vint numnp;
    Vint numel;
    Vint numelt;        /* number of elements which can be exported */
    Vint numet;         /* number of elements types */
    Vint* etype;        /* vector of element types for each element */
    vsy_IntDict* dtype; /* dictionary of element types */
    Vint numcs;
    Vint nummph;
    Vint numeph;
    Vint soltyp; /* solution type */
    Vint nantyp; /* analysis type */
    vis_Connect* connect;
    vsy_HashTable* csh;
    vsy_HashTable* lch;
} vis_RASFwt;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_RASFwt*
vis_RASFwtBegin(void);
VKI_EXTERN void
vis_RASFwt_Construct(vis_RASFwt* p);
VKI_EXTERN void
vis_RASFwtEnd(vis_RASFwt* p);
VKI_EXTERN void
vis_RASFwt_Destruct(vis_RASFwt* p);
VKI_EXTERN Vint
vis_RASFwtError(vis_RASFwt* p);
VKI_EXTERN void
vis_RASFwtWriteModel(vis_RASFwt* p, vis_Model* model, Vchar* path);

#ifdef __cplusplus
}
#endif

#endif
