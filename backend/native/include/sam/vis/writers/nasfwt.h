/* NASFwt object */
#ifndef NASFWT_DEF
#define NASFWT_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
/* parameters */
#define NASFWT_RELATIVEPATH 1

typedef struct vis_NASFwt {
    Vint ierr;
    FILE* fd;
    vis_GridFun* gf;
    Vint numnp;
    Vint numel;
    Vchar fnam[SYS_MAXPATHCHAR];
    Vint maxelemid; /* highest generated element userid */
    Vint maxnodeid; /* highest generated node userid */
    Vint genpid;    /* highest generated property */
    Vint genmid;    /* highest generated material */
    Vint gentid;    /* highest generated temperature set */
    Vint soltyp;    /* solution type */
    Vint nantyp;    /* analysis type */
    Vint twotyp;    /* 2D type */
    Vint vendor;    /* export vendor */
    Vint aliasnode;
    Vint aliaselem;
    Vint relativepath;
    vsy_IntHash* pidelm; /* match element type to property type */
    vis_Connect* connect;
    vis_GProp* gprop;
    vsy_HashTable* csh;
    vsy_HashTable* mph;
    vsy_HashTable* eph;
    vsy_HashTable* edh;
    vsy_HashTable* lch;
    vsy_HashTable* nsets;                /* IdTran of node sets */
    vsy_HashTable* esets;                /* IdTran of element sets */
    vsy_HashTable* eesets;               /* IdTran of element entity sets */
    Vchar includedFile[SYS_MAXPATHCHAR]; /* file name to include to chain analysis */
} vis_NASFwt;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_NASFwt*
vis_NASFwtBegin(void);
VKI_EXTERN void
vis_NASFwt_Construct(vis_NASFwt* p);
VKI_EXTERN void
vis_NASFwtEnd(vis_NASFwt* p);
VKI_EXTERN void
vis_NASFwt_Destruct(vis_NASFwt* p);
VKI_EXTERN Vint
vis_NASFwtError(vis_NASFwt* p);
VKI_EXTERN void
vis_NASFwtSetParami(vis_NASFwt* p, Vint type, Vint iparam);
VKI_EXTERN void
vis_NASFwt_GetExportVendor(vis_NASFwt* p, Vint* vendor);
VKI_EXTERN void
vis_NASFwtWriteModel(vis_NASFwt* p, vis_Model* model, const Vchar* path);
VKI_EXTERN void
vis_NASFwtWriteState(vis_NASFwt* p, vis_RProp* rprop, vis_State* state, const Vchar* path);
VKI_EXTERN void
vis_NASFwtgetCnn(Vint shape, Vint maxi, Vint maxj, Vint type, Vint no, Vint* nix, Vint in[], Vint* shapef, Vint* maxif,
                 Vint* maxjf);
VKI_EXTERN void
vis_NASFwtgetEdgeFace(Vint featyp, Vint shape, Vint side, Vint* iface, Vint* etype);

#ifdef __cplusplus
}
#endif

#endif
