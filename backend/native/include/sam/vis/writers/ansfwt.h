/* ANSFwt object */
#ifndef ANSFWT_DEF
#define ANSFWT_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"

#define ANS_MAXELEMNODE 32
/* parameter values */
#define ANSFWT_CONTROLCARDS 1

#define ANS_ALIAS_LINE300 1
#define ANS_ALIAS_TRI200  2
#define ANS_ALIAS_TRI300  3
#define ANS_ALIAS_TET200  4
#define ANS_ALIAS_TET300  5
#define ANS_ALIAS_PYR200  6
#define ANS_ALIAS_PYR300  7
#define ANS_ALIAS_WED200  8
#define ANS_ALIAS_WED300  9
#define ANS_ALIAS_QUAD320 10
#define ANS_ALIAS_WED302  11
#define ANS_ALIAS_HEX302  12
#define ANS_ALIAS_MAX     12

typedef struct vis_ANSFwt {
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
    Vint aliasnode;
    Vint aliaselem;
    Vint rigidflag;
    Vint cdbFileFlag; /* Indicate that a .cdb file is being written */
    Vint ndim;
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
    vsy_HashTable* cph;   /* vis_CPair storage */
    vis_IdTran* idtranrm; /* rouelm */
    vis_IdTran* idtranet; /* element type */
    vsy_IntHash* htp;     /* mark thicknesses for pid */
    vsy_List* spl;
    vis_IdTran* idtranUnusedNodeElementType; /* Element types for unused nodes ID */
    Vint currentConstraintEquationIndex;     /* Current constraint equation index, linked to CE cards indexing. RBE3 cards also
                                                increase this index. */
    vsy_HashTable* ash;                      /* storage for analytic surfaces (rigid target/master surface of cpair)*/
} vis_ANSFwt;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_ANSFwt*
vis_ANSFwtBegin(void);
VKI_EXTERN void
vis_ANSFwt_Construct(vis_ANSFwt* p);
VKI_EXTERN void
vis_ANSFwtEnd(vis_ANSFwt* p);
VKI_EXTERN void
vis_ANSFwt_Destruct(vis_ANSFwt* p);
VKI_EXTERN Vint
vis_ANSFwtError(vis_ANSFwt* p);
VKI_EXTERN void
vis_ANSFwtReConn(Vint irecon, Vint* nixe, Vint ir[]);
VKI_EXTERN void
vis_ANSFwtReTopo(Vint irecon, Vint* shape, Vint* maxi, Vint* maxj, Vint* maxk);
VKI_EXTERN void
vis_ANSFwtReOrig(Vint irecon, Vint* shape, Vint* nix);
VKI_EXTERN void
vis_ANSFwtReECon(Vint rouelm, Vint reconn, Vint enttype, Vint no, Vint* nixe, Vint ir[]);
VKI_EXTERN void
vis_ANSFwtRouelm(Vchar ename[], Vint* rouelm);
VKI_EXTERN void
vis_ANSFwtMaxRouelm(Vint* maxrouelm);
VKI_EXTERN void
vis_ANSFwtGetName(Vint rouelm, Vchar name[]);
VKI_EXTERN void
vis_ANSFwtGetTopo(Vint rouelm, Vint keyopt[], Vint tshap, Vint* shape, Vint* maxi, Vint* maxj, Vint* maxk, Vint* npe,
                  Vint* nextra);
VKI_EXTERN void
vis_ANSFwtGetFeatype(Vint rouelm, Vint* keyopt, Vint* featype);
VKI_EXTERN void
vis_ANSFwtGetUndoc(Vint rouelm, Vint* undoc);
VKI_EXTERN void
vis_ANSFwtGetAntype(Vint rouelm, Vint* ist, Vint* ith, Vint* iel, Vint* img, Vint* ifl);
VKI_EXTERN void
vis_ANSFwtGetFeaspec(Vint rouelm, Vint* keyopt, Vint* feaspec);
VKI_EXTERN void
vis_ANSFwtGetCsysid(Vint rouelm, Vint* keyopt, Vint* csysid);
VKI_EXTERN void
vis_ANSFwtGetFeatwo(Vint rouelm, Vint* keyopt, Vint* featwo);
VKI_EXTERN void
vis_ANSFwtzeronElem(Vint shape, Vint nix, Vint ix[], Vint* maxi, Vint* numnod);
VKI_EXTERN void
vis_ANSFwtmismidElem(Vint shape, Vint* npe, Vint* maxi, Vint* maxj, Vint ix[]);
VKI_EXTERN void
vis_ANSFwtpermElem(Vint iop, Vint reconn, Vint nixe, Vint ixe[], Vint ix[]);
VKI_EXTERN void
vis_ANSFwtpermElemData(Vint iop, Vint reconn, Vint nixe, Vint nrws, Vfloat de[], Vfloat d[]);
VKI_EXTERN void
vis_ANSFwtsiftElemData(Vint reconn, Vint ncorn, Vint maxj, Vint nixe, Vint nrws, Vfloat de[], Vfloat d[]);
VKI_EXTERN void
vis_ANSFwtpermElemDatadv(Vint iop, Vint reconn, Vint nixe, Vint nrws, Vdouble de[], Vdouble d[]);
VKI_EXTERN void
vis_ANSFwttranElemEnt(Vint noFromLkey, Vint rouelm, Vint reconn, Vint* lkey, Vint* enttype, Vint* no);
VKI_EXTERN void
vis_ANSFwtpermElemEntDatadv(Vint iop, Vint rouelm, Vint reconn, Vint enttype, Vint no, Vint nrws, Vdouble de[], Vdouble d[]);
VKI_EXTERN void
vis_ANSFwtmatchRouelm(Vint nantyp, Vint featype, Vint feaspec, Vint featwod, Vint shape, Vint maxi, vis_EProp* eprop,
                      Vchar etyp[], Vint* rouelm, Vint keyopt[13]);
VKI_EXTERN void
vis_ANSFwtmatchReconn(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint rouelm, Vint* reconn);
VKI_EXTERN void
vis_ANSFwtWriteModel(vis_ANSFwt* p, vis_Model* model, const Vchar* path);
VKI_EXTERN void
vis_ANSFwtSetDimension(vis_ANSFwt* p, Vint dimensionCount);
VKI_EXTERN void
vis_ANSFwtGetTbAnistropicStiffnessNamesCount(Vint* count);
VKI_EXTERN void
vis_ANSFwtGetTbAnistropicStiffnessNameAtIndex(Vint index, Vchar* name);
VKI_EXTERN void
vis_ANSFwtGetTbAnistropicStiffnessNameForStorageAtIndex(Vint index, Vchar* name);
VKI_EXTERN void
vis_ANSFwtGetTbAnistropicConductivityNamesCount(Vint* count);
VKI_EXTERN void
vis_ANSFwtGetTbAnistropicConductivityNameAtIndex(Vint index, Vchar* name);
VKI_EXTERN void
vis_ANSFwtGetTbAnistropicConductivityNameForStorageAtIndex(Vint index, Vchar* name);

#ifdef __cplusplus
}
#endif

#endif
