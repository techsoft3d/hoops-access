/* ABAFwt object */
#ifndef ABAFWT_DEF
#define ABAFWT_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"

/* helper structs */
typedef struct vis_ABAFwtload {
    Vint dload; /* set to 1 if DLOAD used in previous step */
    Vint cload;
    Vint temperature; /* >0 if previous step has imposed temp. */
    Vint cflux;
    Vint dflux;
    Vint cfilm;
    Vint film;
    Vint radiate;
} vis_ABAFwtload;

typedef struct vis_ABAFwt {
    Vint ierr;
    FILE* fd;
    vis_GridFun* gf;
    Vint numnp;
    Vint numel;
    Vint eidmax;      /* maximum user element id */
    Vint nidmax;      /* maximum user node id */
    Vint gennumel;    /* highest generated element */
    Vint soltyp;      /* solution type */
    Vint nantyp;      /* analysis type */
    Vint elemvecflag; /* elemvec required */
    Vint aliasnode;
    Vint aliaselem;
    Vint eallflag;
    Vint rigiddistflag, rigidkineflag;
    vis_Connect* connect;
    vsy_HashTable* csh;
    vsy_HashTable* mph;
    vsy_HashTable* eph;
    vsy_HashTable* edh;
    vsy_HashTable* ich;
    vsy_HashTable* lch;
    vsy_HashTable* rch;
    vsy_HashTable* mch;
    vsy_HashTable* tch;
    vsy_HashTable* cph;
    vsy_HashTable* nsets;  /* IdTran of node sets */
    vsy_HashTable* esets;  /* IdTran of element sets */
    vsy_HashTable* eesets; /* IdTran of element entity sets */
    vsy_List* spl;
    vis_ABAFwtload aba;
    vsy_IntHash* htp; /* mark thicknesses for pid */
    vsy_IntHash* htm; /* hashtable for referenced mid's */
    Vchar nall[256];
    vsy_IntDict* pidname;    /* *ELEMENT pid element set names */
    vsy_HashTable* esetname; /* element sets which match PID sets */
} vis_ABAFwt;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_ABAFwt*
vis_ABAFwtBegin(void);
VKI_EXTERN void
vis_ABAFwt_Construct(vis_ABAFwt* p);
VKI_EXTERN void
vis_ABAFwtEnd(vis_ABAFwt* p);
VKI_EXTERN void
vis_ABAFwt_Destruct(vis_ABAFwt* p);
VKI_EXTERN Vint
vis_ABAFwtError(vis_ABAFwt* p);
VKI_EXTERN void
vis_ABAFwtWriteModel(vis_ABAFwt* p, vis_Model* model, const Vchar* path);

#ifdef __cplusplus
}
#endif

#endif
