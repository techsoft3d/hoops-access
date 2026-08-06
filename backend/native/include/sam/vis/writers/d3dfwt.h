/* D3DFwt object */
#ifndef D3DFWT_DEF
#define D3DFWT_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"

typedef struct vis_D3DFwt {
    Vint ierr;
    FILE* fd;
    vis_GridFun* gf;
    Vint numnp;
    Vint numel;
    Vint soltyp;   /* solution type */
    Vint nantyp;   /* analysis type */
    Vint twotyp;   /* 2D type */
    Vint gennumel; /* highest generated element index */
    Vint gennelid; /* highest generated element id */
    Vint gennumnp; /* highest generated node index */
    Vint gennodid; /* highest generated node id */
    Vint gentcid;  /* highest generated tcurve */
    Vint contcid;  /* generated tcurve for constant unity */
    Vint aliasnode;
    Vint aliaselem;
    vis_Connect* connect;
    vsy_HashTable* csh;
    vsy_HashTable* mph;
    vsy_HashTable* eph;
    vsy_HashTable* edh;
    vsy_HashTable* lch;
    vsy_HashTable* rch;
    vsy_HashTable* mch;
    vsy_HashTable* tch;
    vsy_HashTable* ich;   /* initial conditions */
    vsy_HashTable* nsets; /* IdTran of node sets */
    vsy_HashTable* esets; /* IdTran of element sets */
    vsy_List* spl;
} vis_D3DFwt;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_D3DFwt*
vis_D3DFwtBegin(void);
VKI_EXTERN void
vis_D3DFwt_Construct(vis_D3DFwt* p);
VKI_EXTERN void
vis_D3DFwtEnd(vis_D3DFwt* p);
VKI_EXTERN void
vis_D3DFwt_Destruct(vis_D3DFwt* p);
VKI_EXTERN Vint
vis_D3DFwtError(vis_D3DFwt* p);
VKI_EXTERN void
vis_D3DFwtaliasElement(Vint ielemty, Vint* shape, Vint ix[]);
VKI_EXTERN void
vis_D3DFwtpermElemData(Vint shape, Vint nix, Vint nrws, Vfloat de[], Vfloat d[]);
VKI_EXTERN void
vis_D3DFwtWriteModel(vis_D3DFwt* p, vis_Model* model, const Vchar* path);

#ifdef __cplusplus
}
#endif

#endif
