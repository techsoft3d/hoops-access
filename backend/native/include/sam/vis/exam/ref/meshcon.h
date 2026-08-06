/* MeshCon object */
#ifndef MESHCON_DEF
#define MESHCON_DEF

#include "sam/base/base.h"
#include "sam/base/pred.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/meshsize.h"

/* GetInteger */
#define MESHCON_GLOBALPROJECT 1

#define MESHCON_CONSISTENT      100
#define MESHCON_PATCHPROJECT    101
#define MESHCON_CHECKCLOSEDFRNT 102
#define MESHCON_EXTEND          103
#define MESHCON_NORMAL          104
#define MESHCON_CTRLSPACE       107
#define MESHCON_PATCHRESTRICT   108
#define MESHCON_VERBOSE         110

#define MESHCON_MAXNOED 12

#define MESHCON_STAT_ALL  0
#define MESHCON_STAT_FREE -1
#define MESHCON_STAT_PRES -2
#define MESHCON_STAT_TEMP -3
#define MESHCON_STAT_PREF -4

#define MESHCON_MINELEMANG    1
#define MESHCON_MAXELEMLEN    2
#define MESHCON_MINELEMLEN    3
#define MESHCON_MAXEDGELEN    4
#define MESHCON_MINEDGELEN    5
#define MESHCON_MINFRNTLEN    6
#define MESHCON_FRNTANG       7
#define MESHCON_CORNANG       8
#define MESHCON_COLLREL       9
#define MESHCON_COLLRELFLAG   10
#define MESHCON_COLLMET       11
#define MESHCON_COLLMETFLAG   12
#define MESHCON_COLLANG       13
#define MESHCON_COLLANGFLAG   14
#define MESHCON_MAXMINELEMANG 15
#define MESHCON_COLLIMPFLAG   16
#define MESHCON_GROWTHRATE    17
#define MESHCON_TINYLEN       18
#define MESHCON_MAXELEMANG    19

#define MESHCON_ELEMHEAPSIZEFACT 20
#define MESHCON_EDGEHEAPSIZEFACT 21
#define MESHCON_EDGEHEAPPRESONLY 22
#define MESHCON_COLLTOPOFLAG     23
#define MESHCON_COLLANGIMPFLAG   24
#define MESHCON_RECOVERCOS       25
#define MESHCON_COLLLENMAX       26
#define MESHCON_COLLLENMIN       27
#define MESHCON_COLLLENFLAG      28
#define MESHCON_COLLNORMANG      29
#define MESHCON_COLLNORMANGFLAG  30
#define MESHCON_FUNSIZINGMIN     31
#define MESHCON_WALKFACETOL      32
#define MESHCON_SWAPNORMANG      33
#define MESHCON_SWAPNORMANGFLAG  34
#define MESHCON_SWAPNORMANGFLAG  34

#define MESHCON_MAXNMT 100
#define MESHCON_MAXNDG 10000

typedef struct vis_MeshCon_Elem vis_MeshCon_Elem;
struct vis_MeshCon_Elem {
    Vint nn;
    Vint no[4];
    Vint ed[4];
    Vdouble size;
    Vdouble (*ne)[3]; /* element vertex normals */
    Vint pres;        /* preserved */
    Vint pind;        /* associated element index */
    Vint flat;        /* flat flag */
    Vint stat;        /* status for various purposes */
    Vint prev;
    Vint next;
};

typedef struct vis_MeshCon_Edge vis_MeshCon_Edge;
struct vis_MeshCon_Edge {
    Vint no[2];
    Vint nelem; /* number of elements attached to the edge */
    Vint melem; /* maximum elements attached to the edge */
    Vint* el;   /* attached elements */
    Vint* fr;   /* front associated with element */
    Vdouble size;
    Vdouble (*ns)[3]; /* edge tangents */
    Vint pres;        /* preserved */
    Vint pind;        /* associated entity */
    Vint pref;        /* refined type */
    Vint stat;        /* swap status */
    Vint cent;        /* optional center node */
    Vint topo;        /* topological flag */
    Vint prev;
    Vint next;
};

typedef struct vis_MeshCon_Frnt vis_MeshCon_Frnt;
struct vis_MeshCon_Frnt {
    Vint elid;
    Vint elk;
    Vint no[2];
    Vint fr[2];
    Vdouble an[2]; /* angles in radians at each end */
    Vint st[2];    /* state 0,1 */
    Vint level;
    Vint prev;
    Vint next;
};

typedef struct vis_MeshCon_Node vis_MeshCon_Node;
struct vis_MeshCon_Node {
    Vint ned;
    Vint noed; /* first node edge block */
    Vint loed; /* last node edge block */
    Vdouble x[3];
    Vdouble size;
    Vdouble dist; /* this is currently not used, repurpose for anisotopy */
    Vint pres;    /* preserved entity type 0,1,2,3 */
    Vint pind;    /* associated entity */
    Vint pref;    /* refined type */
    Vint stat;
    Vint topo; /* topological flag */
    Vint prev;
    Vint next;
};

typedef struct vis_MeshCon_NoEd vis_MeshCon_NoEd;
struct vis_MeshCon_NoEd {
    Vint ed[MESHCON_MAXNOED];
    Vint noed; /* next node edge block for node */
    Vint prev;
    Vint next;
};

typedef struct vis_MeshCon vis_MeshCon;
struct vis_MeshCon {
    Vint ierr;
    Vint numnode; /* number of nodes */
    Vint maxnode;
    Vint numelem; /* number of elements */
    Vint maxelem;
    Vint numedge; /* number of edges */
    Vint maxedge;
    Vint numfrnt; /* number of fronts */
    Vint maxfrnt;
    Vdouble vk[2][3], vl[2][3], vf[2][3];
    Vdouble pk[2][3], pl[2][3], pf[2][3];
    Vint lastformelem;
    Vint lastdiagelem[2];

    Vint numgeomface; /* number of geometry faces */
    Vint* geomfaceelemhint;
    Vint* geomfaceelemnum;
    Vint* geomfacemapmesh;
    Vint* geomfaceinternal;
    Vchar* geomfacecan;
    Vint* geomfacestk;

    Vint mconsistent;
    Vint nconsistent;
    Vint patchproject;
    Vint patchrestrict;
    Vint checkclosedfrnt;
    Vint ctrlspace;
    Vint extendflag;
    Vint verbose;

    Vint currenttype;
    Vint currentid;
    Vdouble debugcen[3], debugrad;
    Vint debugnumnodes, debugnodes[10];
    Vint debuglevel;

    Vint nprojiter;
    Vint projglob; /* global projection used in last call */
    Vint nprojglob;
    Vint nprojedgeiter;
    Vint nprojedgepres;
    Vint nprojedgeglob;
    Vint nsplitelem;
    Vint nsplitedge;
    Vint nswapedge;
    Vint ncollapseedge;
    Vint warnflag;
    Vdouble adttol;
    vsy_ADTree* adt;
    vsy_ADTree* adtn;
    Vdouble growthrate;
    vsy_IntVec *ived, *ivel;
    vsy_IntVec *stk, *lst, *can;
    Vint numelemstat, maxelemstat;
    vsy_IntVec* est;

    Vint iternode;
    Vint iteredge;
    Vint iterelem;

    Vint iternodeedge;
    Vint iternodeelem;
    Vint iterned, iternoed, iternoin;
    vsy_Pred* pred;

    vis_MeshCon_Elem* elem;
    Vint headelem;
    vis_MeshCon_Edge* edge;
    Vint headedge;
    Vint* edgestack;
    Vint numedgestack;
    vis_MeshCon_Frnt* frnt;
    Vint headfrnt;
    vis_MeshCon_Node* node;
    Vint headnode;

    Vint numnoed;
    Vint maxnoed;
    Vint mxnoed;
    vis_MeshCon_NoEd* noed;
    Vint headnoed;

    Vint asfsta;       /* >0 start of free mult assoc slots, =0 none */
    Vint asfnum;       /* number of free slots */
    Vint asmmax;       /* maximum number of slots allocated */
    Vint (*asmval)[2]; /* multiple assoc slots, [0] next slot, [1] assoc */

    Vint mxinoed;
    Vint* inoed;  /* temporary, internal storage for node edges */
    Vint* inoed1; /* temporary, internal storage for node edges */
    Vint mxiedl;
    Vint* iedl;      /* temporary, internal storage for recover edge */
    vsy_IntHash* ih; /* speed up node-elem searches */
    Vint maxpedge;
    Vint* tpedge;         /* temporary internal storage for edge pasting */
    Vdouble (*xpedge)[3]; /* temporary internal storage for edge pasting */

    Vdouble edgeheapsizefact;
    Vint edgeheappresonly;
    Vint edgeheap;
    vsy_Heap* hpedge;
    Vdouble elemheapsizefact;
    Vint elemheap;
    vsy_Heap* hpelem;

    Vint normalflag;
    vsy_Concat* concat; /* storage for all normal data */

    Vint minfrntlen;
    Vdouble frntang;
    Vdouble cornang;
    vsy_PQueue* bfminlen[3];
    Vdouble collrel;
    Vint collrelflag;
    Vdouble collmet;
    Vint collmetflag;
    Vdouble collang;
    Vint collangflag;
    Vint collangimpflag;
    Vint collimpflag;
    Vint colltopoflag;
    Vdouble colllenmin;
    Vdouble colllenmax;
    Vint colllenflag;
    Vdouble collnormang;
    Vint collnormangflag;
    Vdouble swapnormang;
    Vint swapnormangflag;
    Vdouble tinylen;
    Vdouble recovercos;
    Vint funsizingminflag;
    Vdouble walkfacetol;

    vis_MeshCon* gm;
    vis_MeshSize* meshsize;
    vis_MeshSize* dmeshsize;

    vsy_List* coniclist;

    Vint funflag;
    void (*fun)(vis_MeshCon*, Vobject*);
    Vobject* funobject;
    void (*funsiz)(vis_MeshCon*, Vobject*, Vdouble x[], Vdouble* s);
    Vobject* funobjsiz;
    void (*funani)(vis_MeshCon*, Vobject*, Vdouble x[], Vdouble s[3][3]);
    Vobject* funobjani;
    void (*fungeo)(Vobject*, Vobject*, Vint, Vint, Vdouble*, Vdouble*, Vdouble*, Vdouble*);
    Vobject* funobjgeo;
};

#ifdef __cplusplus
extern "C" {
#endif

VKI_EXTERN vis_MeshCon*
vis_MeshConBegin(void);
VKI_EXTERN void
vis_MeshCon_Construct(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConEnd(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshCon_Destruct(vis_MeshCon* p);
VKI_EXTERN Vint
vis_MeshConError(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConDef(vis_MeshCon* p, Vint nnode, Vint nelem);
VKI_EXTERN void
vis_MeshConInq(const vis_MeshCon* p, Vint* nnode, Vint* nelem);
VKI_EXTERN void
vis_MeshConSetPred(vis_MeshCon* p, vsy_Pred* pred);
VKI_EXTERN void
vis_MeshConSetFunction(vis_MeshCon* p, Vfunc* function, Vobject* object);
VKI_EXTERN void
vis_MeshConSetSizing(vis_MeshCon* p, Vfunc* function, Vobject* object);
VKI_EXTERN void
vis_MeshConSetASizing(vis_MeshCon* p, Vfunc* function, Vobject* object);
VKI_EXTERN void
vis_MeshConSetGeoproj(vis_MeshCon* p, Vfunc* function, Vobject* object);
VKI_EXTERN void
vis_MeshConSetFunFlag(vis_MeshCon* p, Vint funflag);
VKI_EXTERN Vint
vis_MeshConFunFlag(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConCallFunction(vis_MeshCon* p, Vint iop, Vchar* stg);
VKI_EXTERN void
vis_MeshConSetGeomMeshCon(vis_MeshCon* p, vis_MeshCon* gmeshcon);
VKI_EXTERN void
vis_MeshConSetConicList(vis_MeshCon* p, vsy_List* coniclist);
VKI_EXTERN void
vis_MeshConGetConicList(vis_MeshCon* p, vsy_List** coniclist);
VKI_EXTERN void
vis_MeshConGetCoordSys(vis_MeshCon* p, Vint ptid, vis_CoordSys** coordsys);
VKI_EXTERN void
vis_MeshConSetGeomMeshSize(vis_MeshCon* p, vis_MeshSize* meshsize);
VKI_EXTERN void
vis_MeshConSetDepthMeshSize(vis_MeshCon* p, vis_MeshSize* meshsize);
VKI_EXTERN void
vis_MeshConSetParami(vis_MeshCon* p, Vint type, Vint iparam);
VKI_EXTERN void
vis_MeshConGetParami(vis_MeshCon* p, Vint type, Vint* iparam);
VKI_EXTERN void
vis_MeshConSetParamd(vis_MeshCon* p, Vint type, Vdouble param);
VKI_EXTERN void
vis_MeshConGetParamd(vis_MeshCon* p, Vint type, Vdouble* param);
VKI_EXTERN void
vis_MeshConWarn(vis_MeshCon* p, Vint* flag);
VKI_EXTERN void
vis_MeshConNumber(const vis_MeshCon* p, Vint type, Vint* numentity);
VKI_EXTERN void
vis_MeshConGetInteger(vis_MeshCon* p, Vint type, Vint iparams[]);
VKI_EXTERN void
vis_MeshConMaxEdge(vis_MeshCon* p, Vint* maxedge);
VKI_EXTERN void
vis_MeshConClrAuxVec(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConSetAuxVec(vis_MeshCon* p, Vint type, Vint k, Vdouble v[3]);
VKI_EXTERN void
vis_MeshConGetAuxVec(vis_MeshCon* p, Vint type, Vint k, Vdouble v[3]);
VKI_EXTERN void
vis_MeshConClrAuxPnt(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConSetAuxPnt(vis_MeshCon* p, Vint type, Vint k, Vdouble v[3]);
VKI_EXTERN void
vis_MeshConGetAuxPnt(vis_MeshCon* p, Vint type, Vint k, Vdouble v[3]);
VKI_EXTERN void
vis_MeshConSetCurrEnt(vis_MeshCon* p, Vint enttype, Vint id);
VKI_EXTERN void
vis_MeshConGetCurrEnt(vis_MeshCon* p, Vint* enttype, Vint* id);
VKI_EXTERN void
vis_MeshConGetCurrEntId(vis_MeshCon* p, Vint enttype, Vint* id);
VKI_EXTERN void
vis_MeshConSetDebugSphere(vis_MeshCon* p, Vdouble cen[3], Vdouble rad);
VKI_EXTERN void
vis_MeshConSetDebugNodes(vis_MeshCon* p, Vint num, Vint nodes[]);
VKI_EXTERN void
vis_MeshConSetDebugLevel(vis_MeshCon* p, Vint level);
VKI_EXTERN void
vis_MeshConDebugEnt(vis_MeshCon* p, Vint enttype, Vint id, Vint* flag);
VKI_EXTERN void
vis_MeshConAddNode(vis_MeshCon* p, Vdouble x[3], Vint* id);
VKI_EXTERN void
vis_MeshConSetNode(vis_MeshCon* p, Vint id, Vdouble x[3]);
VKI_EXTERN void
vis_MeshConDelNode(vis_MeshCon* p, Vint id);
VKI_EXTERN void
vis_MeshConGetNode(vis_MeshCon* p, Vint id, Vdouble x[3]);
VKI_EXTERN void
vis_MeshConGetNode2Dim(vis_MeshCon* p, Vint id, Vdouble x[2]);
VKI_EXTERN void
vis_MeshConGetNodes(vis_MeshCon* p, Vint nid, Vint ids[], Vdouble x[][3]);
VKI_EXTERN void
vis_MeshConGetNodesCtrl(vis_MeshCon* p, Vint nid, Vint ids[], Vdouble x[][3]);
VKI_EXTERN void
vis_MeshConMaxNodeEdge(vis_MeshCon* p, Vint* maxnodeedge);
VKI_EXTERN void
vis_MeshConNumNodeEdge(vis_MeshCon* p, Vint id, Vint* numnodeedge);
VKI_EXTERN void
vis_MeshConNumNodePresEdge(vis_MeshCon* p, Vint id, Vint* numnodepresedge);
VKI_EXTERN void
vis_MeshConNodePresEdge(vis_MeshCon* p, Vint id, Vint* num, Vint noed[]);
VKI_EXTERN void
vis_MeshConFindNodePresEdge(vis_MeshCon* p, Vint id, Vint pres, Vint* edid);
VKI_EXTERN void
vis_MeshConAdjPresEdge(vis_MeshCon* p, Vint id, Vint noid, Vint* noed);
VKI_EXTERN void
vis_MeshConNodeSpecPresEdge(vis_MeshCon* p, Vint noid, Vint pres, Vint* num, Vint id[]);
VKI_EXTERN void
vis_MeshConNumNodePrefEdge(vis_MeshCon* p, Vint id, Vint* numnodeprefedge);
VKI_EXTERN void
vis_MeshConNumNodeNMEdge(vis_MeshCon* p, Vint id, Vint* numnodenmedge);
VKI_EXTERN void
vis_MeshConNumNodeFrntEdge(vis_MeshCon* p, Vint id, Vint* numnodefrntedge);
VKI_EXTERN void
vis_MeshConNumNodeInconEdge(vis_MeshCon* p, Vint id, Vint* numnodeinconedge);
VKI_EXTERN void
vis_MeshConGetNodeEdge(vis_MeshCon* p, Vint id, Vint* num, Vint noed[]);
VKI_EXTERN void
vis_MeshConGetNodeCCWEdge(vis_MeshCon* p, Vint id, Vint* num, Vint noed[]);
VKI_EXTERN void
vis_MeshConGetNodeCCWEdgeBound(vis_MeshCon* p, Vint id, Vint elid, Vint edid1, Vint edid2, Vint* num, Vint noed[]);
VKI_EXTERN void
vis_MeshConGetNodeCCWNextPres(vis_MeshCon* p, Vint id, Vint elid, Vint* pelid, Vint* pelk, Vint* pedid);
VKI_EXTERN void
vis_MeshConGetNodeCCWPresBound(vis_MeshCon* p, Vint id, Vint elid, Vint* num, Vint noel[]);
VKI_EXTERN void
vis_MeshConGetNodeCCWNMBound(vis_MeshCon* p, Vint id, Vint elid, Vint* num, Vint noed[]);
VKI_EXTERN void
vis_MeshConGetNodeCCWPresEdgeBound(vis_MeshCon* p, Vint id, Vint elid, Vint* num, Vint noed[]);
VKI_EXTERN void
vis_MeshConGetNodeNode(vis_MeshCon* p, Vint id, Vint* num, Vint nono[]);
VKI_EXTERN void
vis_MeshConMatchNodeNode(vis_MeshCon* p, Vint id, Vint idm, Vint* imatch);
VKI_EXTERN void
vis_MeshConNodeNodeLength(vis_MeshCon* p, Vint id, Vint idm, Vdouble* fl);
VKI_EXTERN void
vis_MeshConCheckMergeNode(vis_MeshCon* p, Vint id, Vint idm, Vint* flag);
VKI_EXTERN void
vis_MeshConMergeNode(vis_MeshCon* p, Vint id, Vint idm);
VKI_EXTERN void
vis_MeshConPurgePresEdge(vis_MeshCon* p, Vint noid1, Vint noid2);
VKI_EXTERN void
vis_MeshConCheckNodeEdgeFree(vis_MeshCon* p, Vint id, Vint* flag);
VKI_EXTERN void
vis_MeshConGetEdgeQuad(vis_MeshCon* p, Vint id, Vint iq[4], Vint iqe[4]);
VKI_EXTERN void
vis_MeshConGetEdgeQuadNorm(vis_MeshCon* p, Vint id, Vint iq[4], Vint iqe[4], Vdouble vq[4][3]);
VKI_EXTERN void
vis_MeshConGetNodeElem(vis_MeshCon* p, Vint id, Vint* num, Vint noel[]);
VKI_EXTERN void
vis_MeshConOneNodeElem(vis_MeshCon* p, Vint id, Vint* eid);
VKI_EXTERN void
vis_MeshConSetNodeSize(vis_MeshCon* p, Vint id, Vdouble size);
VKI_EXTERN void
vis_MeshConGetNodeSize(vis_MeshCon* p, Vint id, Vdouble* size);
VKI_EXTERN void
vis_MeshConGetNodeSizes(vis_MeshCon* p, Vint nid, Vint ids[], Vdouble s[]);
VKI_EXTERN void
vis_MeshConSetNodeDist(vis_MeshCon* p, Vint id, Vdouble dist);
VKI_EXTERN void
vis_MeshConGetNodeDist(vis_MeshCon* p, Vint id, Vdouble* dist);
VKI_EXTERN void
vis_MeshConSetNodeStat(vis_MeshCon* p, Vint id, Vint stat);
VKI_EXTERN void
vis_MeshConGetNodeStat(vis_MeshCon* p, Vint id, Vint* stat);
VKI_EXTERN void
vis_MeshConCountNodeStat(vis_MeshCon* p, Vint* num);
VKI_EXTERN void
vis_MeshConSetNodeTopo(vis_MeshCon* p, Vint id, Vint topo);
VKI_EXTERN void
vis_MeshConGetNodeTopo(vis_MeshCon* p, Vint id, Vint* topo);
VKI_EXTERN void
vis_MeshConSetNodePres(vis_MeshCon* p, Vint id, Vint pres);
VKI_EXTERN void
vis_MeshConGetNodePres(vis_MeshCon* p, Vint id, Vint* pres);
VKI_EXTERN void
vis_MeshConSetNodePref(vis_MeshCon* p, Vint id, Vint pref);
VKI_EXTERN void
vis_MeshConGetNodePref(vis_MeshCon* p, Vint id, Vint* pref);
VKI_EXTERN void
vis_MeshConNumNodePind(vis_MeshCon* p, Vint id, Vint* num);
VKI_EXTERN void
vis_MeshConAllNodePind(vis_MeshCon* p, Vint id, Vint* num, Vint pind[]);
VKI_EXTERN void
vis_MeshConSetNodePind(vis_MeshCon* p, Vint id, Vint pind);
VKI_EXTERN void
vis_MeshConGetNodePind(vis_MeshCon* p, Vint id, Vint* pind);
VKI_EXTERN void
vis_MeshConNodeSizeElem(vis_MeshCon* p, Vint id, Vdouble x[3], Vdouble* size);
VKI_EXTERN void
vis_MeshConNodeSizeEdge(vis_MeshCon* p, Vint id, Vdouble x[3], Vdouble* size);
VKI_EXTERN void
vis_MeshConGetNodeElemAngle(vis_MeshCon* p, Vint id, Vint elid, Vdouble* angle);
VKI_EXTERN void
vis_MeshConAddElem(vis_MeshCon* p, Vint nn, Vint ix[], Vint* id);
VKI_EXTERN void
vis_MeshConDelElem(vis_MeshCon* p, Vint id);
VKI_EXTERN void
vis_MeshConGetElem(vis_MeshCon* p, Vint id, Vint* nn, Vint no[], Vint ed[]);
VKI_EXTERN void
vis_MeshConGetElemNum(vis_MeshCon* p, Vint id, Vint* nn);
VKI_EXTERN void
vis_MeshConGetElemNode(vis_MeshCon* p, Vint id, Vint* nn, Vint no[]);
VKI_EXTERN void
vis_MeshConGetElemEdge(vis_MeshCon* p, Vint id, Vint* nn, Vint ed[]);
VKI_EXTERN void
vis_MeshConSetElemSize(vis_MeshCon* p, Vint id, Vdouble size);
VKI_EXTERN void
vis_MeshConGetElemSize(vis_MeshCon* p, Vint id, Vdouble* size);
VKI_EXTERN void
vis_MeshConSetElemNorm(vis_MeshCon* p, Vint id, Vdouble ve[3][3]);
VKI_EXTERN void
vis_MeshConIsElemNorm(vis_MeshCon* p, Vint id, Vint* flag);
VKI_EXTERN void
vis_MeshConGetElemNorm(vis_MeshCon* p, Vint id, Vdouble ve[3][3]);
VKI_EXTERN void
vis_MeshConSetEdgeTang(vis_MeshCon* p, Vint id, Vdouble ve[2][3]);
VKI_EXTERN void
vis_MeshConIsEdgeTang(vis_MeshCon* p, Vint id, Vint* flag);
VKI_EXTERN void
vis_MeshConGetEdgeTang(vis_MeshCon* p, Vint id, Vdouble ve[2][3]);
VKI_EXTERN void
vis_MeshConEdgeTang(vis_MeshCon* p, Vint id, Vdouble xp[3], Vdouble ve[3]);
VKI_EXTERN void
vis_MeshConEdgeElemNode(vis_MeshCon* p, Vint edid, Vint elid, Vint edelno[2]);
VKI_EXTERN void
vis_MeshConSetElemNodeNorm(vis_MeshCon* p, Vint id, Vint noid, Vdouble ve[3]);
VKI_EXTERN void
vis_MeshConSetElemPres(vis_MeshCon* p, Vint id, Vint pres);
VKI_EXTERN void
vis_MeshConGetElemPres(vis_MeshCon* p, Vint id, Vint* pres);
VKI_EXTERN void
vis_MeshConGetPresElem(vis_MeshCon* p, Vint pres, Vint* id);
VKI_EXTERN void
vis_MeshConSetElemPind(vis_MeshCon* p, Vint id, Vint pind);
VKI_EXTERN void
vis_MeshConGetElemPind(vis_MeshCon* p, Vint id, Vint* pind);
VKI_EXTERN void
vis_MeshConSetElemFlat(vis_MeshCon* p, Vint id, Vint flat);
VKI_EXTERN void
vis_MeshConGetElemFlat(vis_MeshCon* p, Vint id, Vint* flat);
VKI_EXTERN void
vis_MeshConNumElemStat(vis_MeshCon* p, Vint* numstat);
VKI_EXTERN void
vis_MeshConSetElemStat(vis_MeshCon* p, Vint id, Vint stat);
VKI_EXTERN void
vis_MeshConGetElemStat(vis_MeshCon* p, Vint id, Vint* stat);
VKI_EXTERN void
vis_MeshConStatLastFormElem(vis_MeshCon* p, Vint stat);
VKI_EXTERN void
vis_MeshConStatLastDiagElem(vis_MeshCon* p, Vint stat);
VKI_EXTERN void
vis_MeshConSplitElem(vis_MeshCon* p, Vint id, Vint noid);
VKI_EXTERN void
vis_MeshConCheckDiagElem(vis_MeshCon* p, Vint id, Vint noid, Vint* flag);
VKI_EXTERN void
vis_MeshConDiagElem(vis_MeshCon* p, Vint id, Vint noid);
VKI_EXTERN void
vis_MeshConGetLeftElem(vis_MeshCon* p, Vint noid, Vint edid, Vint* elid, Vint* elk);
VKI_EXTERN void
vis_MeshConInitTree(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConTermTree(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConSetNumGeomFace(vis_MeshCon* p, Vint numgeomface);
VKI_EXTERN void
vis_MeshConGetNumGeomFace(vis_MeshCon* p, Vint* numgeomface);
VKI_EXTERN void
vis_MeshConInitGeomFace(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConTermGeomFace(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConGeomFaceNodeElem(vis_MeshCon* p, Vint geomface, vis_IdTran* idtrann, vis_IdTran* idtrane);
VKI_EXTERN void
vis_MeshConGetGeomFaceElemHint(vis_MeshCon* p, Vint geomface, Vint* id);
VKI_EXTERN void
vis_MeshConGetElemGeomFace(vis_MeshCon* p, Vint id, Vint* geomface);
VKI_EXTERN void
vis_MeshConSetGeomFaceInternal(vis_MeshCon* p, Vint geomface, Vint internal);
VKI_EXTERN void
vis_MeshConGetGeomFaceInternal(vis_MeshCon* p, Vint geomface, Vint* internal);
VKI_EXTERN void
vis_MeshConSetGeomFaceMapMesh(vis_MeshCon* p, Vint geomface, Vint mapmesh);
VKI_EXTERN void
vis_MeshConGetGeomFaceMapMesh(vis_MeshCon* p, Vint geomface, Vint* mapmesh);
VKI_EXTERN void
vis_MeshConGetAdjElem(vis_MeshCon* p, Vint id, Vint no, Vint* elid);
VKI_EXTERN void
vis_MeshConFindNodeEdge(vis_MeshCon* p, Vint noid1, Vint noid2, Vint* edid);
VKI_EXTERN void
vis_MeshConBestNodePresElem(vis_MeshCon* p, Vint noid, Vint pres, Vdouble x[3], Vint* elid);
VKI_EXTERN void
vis_MeshConFindEdgePresElem(vis_MeshCon* p, Vint edid, Vint pres, Vint* elid);
VKI_EXTERN void
vis_MeshConCheckFormElem(vis_MeshCon* p, Vint nn, Vint no[], Vint ed[], Vint* flag);
VKI_EXTERN void
vis_MeshConCheckInvertFormElem(vis_MeshCon* p, Vint nn, Vint no[], Vdouble v[3], Vdouble* metric);
VKI_EXTERN void
vis_MeshConFormElem(vis_MeshCon* p, Vint nn, Vint no[], Vint ed[]);
VKI_EXTERN void
vis_MeshConLastFormElem(vis_MeshCon* p, Vint* id);
VKI_EXTERN void
vis_MeshConSimpElem(vis_MeshCon* p, Vint nn, Vint no[]);
VKI_EXTERN void
vis_MeshConInitElemHeap(vis_MeshCon* p, Vint type);
VKI_EXTERN void
vis_MeshConNextElemHeap(vis_MeshCon* p, Vint* id, Vdouble* val);
VKI_EXTERN void
vis_MeshConNextElemHeapRemove(vis_MeshCon* p, Vint* id, Vdouble* val);
VKI_EXTERN void
vis_MeshConRemoveElemHeap(vis_MeshCon* p, Vint id);
VKI_EXTERN void
vis_MeshConInsertElemHeap(vis_MeshCon* p, Vint id);
VKI_EXTERN void
vis_MeshConAddFrnt(vis_MeshCon* p, Vint elid, Vint no, Vint* id);
VKI_EXTERN void
vis_MeshConDelFrnt(vis_MeshCon* p, Vint id);
VKI_EXTERN void
vis_MeshConGetFrnt(vis_MeshCon* p, Vint id, Vint no[], Vint fr[]);
VKI_EXTERN void
vis_MeshConGetFrntNode(vis_MeshCon* p, Vint id, Vint no[]);
VKI_EXTERN void
vis_MeshConGetFrntElem(vis_MeshCon* p, Vint id, Vint* elid, Vint* no);
VKI_EXTERN void
vis_MeshConGetFrntEdge(vis_MeshCon* p, Vint id, Vint* edid);
VKI_EXTERN void
vis_MeshConSetFrntLevel(vis_MeshCon* p, Vint id, Vint level);
VKI_EXTERN void
vis_MeshConGetFrntLevel(vis_MeshCon* p, Vint id, Vint* level);
VKI_EXTERN void
vis_MeshConGetFrntState(vis_MeshCon* p, Vint id, Vint st[2], Vdouble an[2]);
VKI_EXTERN void
vis_MeshConGetEdge(vis_MeshCon* p, Vint id, Vint no[], Vint el[]);
VKI_EXTERN void
vis_MeshConGetEdgeElem(vis_MeshCon* p, Vint id, Vint el[]);
VKI_EXTERN void
vis_MeshConNumEdgeElem(vis_MeshCon* p, Vint id, Vint* nix);
VKI_EXTERN void
vis_MeshConIthEdgeElem(vis_MeshCon* p, Vint id, Vint no, Vint* elid);
VKI_EXTERN void
vis_MeshConGetEdgeNM(vis_MeshCon* p, Vint id, Vint no[], Vint* nix, Vint el[]);
VKI_EXTERN void
vis_MeshConEdgeIncon(vis_MeshCon* p, Vint id, Vint* flag);
VKI_EXTERN void
vis_MeshConGetEdgeNode(vis_MeshCon* p, Vint id, Vint no[]);
VKI_EXTERN void
vis_MeshConOppEdgeNode(vis_MeshCon* p, Vint id, Vint noid, Vint* opno);
VKI_EXTERN void
vis_MeshConGetEdgeFrnt(vis_MeshCon* p, Vint id, Vint fr[]);
VKI_EXTERN void
vis_MeshConGetEdgeFrntNM(vis_MeshCon* p, Vint id, Vint* nix, Vint fr[]);
VKI_EXTERN void
vis_MeshConNumEdgeFrnt(vis_MeshCon* p, Vint id, Vint* nix);
VKI_EXTERN void
vis_MeshConGetEdgeFrntElem(vis_MeshCon* p, Vint id, Vint elid, Vint* frid);
VKI_EXTERN void
vis_MeshConGetNodeFrnt(vis_MeshCon* p, Vint ix[2], Vint* frid);
VKI_EXTERN void
vis_MeshConSwapEdge(vis_MeshCon* p, Vint id);
VKI_EXTERN void
vis_MeshConCheckSplitEdge(vis_MeshCon* p, Vint id, Vint noid, Vint* flag);
VKI_EXTERN void
vis_MeshConSplitEdge(vis_MeshCon* p, Vint id, Vint noid);
VKI_EXTERN void
vis_MeshConCheckCollapseEdge(vis_MeshCon* p, Vint id, Vint noid, Vint midflag, Vdouble cang, Vdouble vn[3], Vint* flag);
VKI_EXTERN void
vis_MeshConCheckCollapseEdgeTopo(vis_MeshCon* p, Vint id, Vint noid, Vint* flag);
VKI_EXTERN void
vis_MeshConCheckCollapseEdgeFace(vis_MeshCon* p, Vint id, Vint* flag);
VKI_EXTERN void
vis_MeshConCheckCollapseEdgeDAng(vis_MeshCon* p, Vint id, Vint noid, Vint midflag, Vdouble* fl);
VKI_EXTERN void
vis_MeshConCollapseEdge(vis_MeshCon* p, Vint id, Vint noid, Vint midflag);
VKI_EXTERN void
vis_MeshConRecoverEdge2Dim(vis_MeshCon* p, Vint ix[2], Vint* edid);
VKI_EXTERN void
vis_MeshConRecoverEdge(vis_MeshCon* p, Vdouble ve[3], Vint ix[2], Vint* edid);
VKI_EXTERN void
vis_MeshConCreateEdge(vis_MeshCon* p, Vdouble ve[3], Vint ix[2], Vint* edid);
VKI_EXTERN void
vis_MeshConMergeEdge(vis_MeshCon* p, Vint id, Vint idm);
VKI_EXTERN void
vis_MeshConSetEdgeStat(vis_MeshCon* p, Vint id, Vint stat);
VKI_EXTERN void
vis_MeshConPushNodeEdge(vis_MeshCon* p, Vint id);
VKI_EXTERN void
vis_MeshConGetEdgeStat(vis_MeshCon* p, Vint id, Vint* stat);
VKI_EXTERN void
vis_MeshConSetEdgePres(vis_MeshCon* p, Vint id, Vint pres);
VKI_EXTERN void
vis_MeshConGetEdgePres(vis_MeshCon* p, Vint id, Vint* pres);
VKI_EXTERN void
vis_MeshConGetPresEdge(vis_MeshCon* p, Vint pres, Vint* id);
VKI_EXTERN void
vis_MeshConSetEdgeTopo(vis_MeshCon* p, Vint id, Vint topo);
VKI_EXTERN void
vis_MeshConSetEdgeTopoFeat(vis_MeshCon* p, Vint id, Vint feat);
VKI_EXTERN void
vis_MeshConGetEdgeTopoFeat(vis_MeshCon* p, Vint id, Vint* feat);
VKI_EXTERN void
vis_MeshConSetEdgeTopoFlag(vis_MeshCon* p, Vint id, Vint flag);
VKI_EXTERN void
vis_MeshConGetEdgeTopoFlag(vis_MeshCon* p, Vint id, Vint* flag);
VKI_EXTERN void
vis_MeshConSetEdgeTopoLays(vis_MeshCon* p, Vint id, Vint lays);
VKI_EXTERN void
vis_MeshConGetEdgeTopoLays(vis_MeshCon* p, Vint id, Vint* lays);
VKI_EXTERN void
vis_MeshConSetEdgeTopoRate(vis_MeshCon* p, Vint id, Vint rate);
VKI_EXTERN void
vis_MeshConGetEdgeTopoRate(vis_MeshCon* p, Vint id, Vint* rate);
VKI_EXTERN void
vis_MeshConGetEdgeTopo(vis_MeshCon* p, Vint id, Vint* topo);
VKI_EXTERN void
vis_MeshConSetEdgePref(vis_MeshCon* p, Vint id, Vint pref);
VKI_EXTERN void
vis_MeshConGetEdgePref(vis_MeshCon* p, Vint id, Vint* pref);
VKI_EXTERN void
vis_MeshConNumEdgePind(vis_MeshCon* p, Vint id, Vint* num);
VKI_EXTERN void
vis_MeshConAllEdgePind(vis_MeshCon* p, Vint id, Vint* num, Vint pind[]);
VKI_EXTERN void
vis_MeshConSetEdgeCent(vis_MeshCon* p, Vint id, Vint cent);
VKI_EXTERN void
vis_MeshConGetEdgeCent(vis_MeshCon* p, Vint id, Vint* cent);
VKI_EXTERN void
vis_MeshConSetEdgeSize(vis_MeshCon* p, Vint id, Vdouble size);
VKI_EXTERN void
vis_MeshConGetEdgeSize(vis_MeshCon* p, Vint id, Vdouble* size);
VKI_EXTERN void
vis_MeshConNumPushEdge(vis_MeshCon* p, Vint* num);
VKI_EXTERN void
vis_MeshConPushEdge(vis_MeshCon* p, Vint id);
VKI_EXTERN void
vis_MeshConPopEdge(vis_MeshCon* p, Vint* id);
VKI_EXTERN void
vis_MeshConRefEdge(vis_MeshCon* p, Vint ith, Vint* id);
VKI_EXTERN void
vis_MeshConInitEdgeHeap(vis_MeshCon* p, Vint type);
VKI_EXTERN void
vis_MeshConNextEdgeHeap(vis_MeshCon* p, Vint* id, Vdouble* val);
VKI_EXTERN void
vis_MeshConRemoveEdgeHeap(vis_MeshCon* p, Vint id);
VKI_EXTERN void
vis_MeshConPushEdgeHeapNodeElem(vis_MeshCon* p, Vint noid);
VKI_EXTERN void
vis_MeshConRangeMinFrntLen(vis_MeshCon* p, Vdouble fmin, Vdouble fmax);
VKI_EXTERN void
vis_MeshConInitMinFrntLen(vis_MeshCon* p, Vint* num);
VKI_EXTERN void
vis_MeshConNextMinFrntLen(vis_MeshCon* p, Vint* id, Vdouble* val);
VKI_EXTERN void
vis_MeshConRemoveMinFrntLen(vis_MeshCon* p, Vint id);
VKI_EXTERN void
vis_MeshConLookupMinFrntLen(vis_MeshCon* p, Vint id, Vdouble* val);
VKI_EXTERN void
vis_MeshConNumFrnt(vis_MeshCon* p, Vint* num);
VKI_EXTERN void
vis_MeshConInitNode(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConNextNode(vis_MeshCon* p, Vint* id);
VKI_EXTERN void
vis_MeshConInitEdge(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConNextEdge(vis_MeshCon* p, Vint* id);
VKI_EXTERN void
vis_MeshConInitElem(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConNextElem(vis_MeshCon* p, Vint* id);
VKI_EXTERN void
vis_MeshConCheckElemLists(vis_MeshCon* p, Vint* flag);
VKI_EXTERN void
vis_MeshConInitNodeEdge(vis_MeshCon* p, Vint noid);
VKI_EXTERN void
vis_MeshConNextNodeEdge(vis_MeshCon* p, Vint* id);
VKI_EXTERN void
vis_MeshConInitNodeElem(vis_MeshCon* p, Vint noid);
VKI_EXTERN void
vis_MeshConNextNodeElem(vis_MeshCon* p, Vint* id);
VKI_EXTERN void
vis_MeshConWalkEdge(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vint* edid, Vint* noid, Vdouble x[3]);
VKI_EXTERN void
vis_MeshConWalkFace(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vint* elid, Vint* edid, Vint* noid, Vdouble x[3]);
VKI_EXTERN void
vis_MeshCon_Project(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vint* id, Vint* edid, Vdouble r[3], Vdouble x[3]);
VKI_EXTERN void
vis_MeshConProject(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vint* id, Vint* edid, Vdouble x[3]);
VKI_EXTERN void
vis_MeshConProjectNorm(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vdouble x[3], Vdouble v[3]);
VKI_EXTERN void
vis_MeshConProjectElems(vis_MeshCon* p, Vint nel, Vint iel[], Vdouble xp[3], Vint* id, Vdouble x[3]);
VKI_EXTERN void
vis_MeshConProjectGlobal(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vint* id, Vint* edid, Vdouble x[3]);
VKI_EXTERN void
vis_MeshConProjectOneTri(vis_MeshCon* p, Vint id, Vdouble xp[3], Vdouble r[3], Vdouble x[3], Vint* ierr);
VKI_EXTERN void
vis_MeshConElemNorm(vis_MeshCon* p, Vint id, Vdouble xp[3], Vdouble vp[3]);
VKI_EXTERN void
vis_MeshConElemArea(vis_MeshCon* p, Vint tid, Vdouble* area);
VKI_EXTERN void
vis_MeshConElemCurvature(vis_MeshCon* p, Vint tid, Vdouble vk[3], Vdouble rk[2], Vdouble pk[2][3]);
VKI_EXTERN void
vis_MeshConElemExtent(vis_MeshCon* p, Vint id, Vdouble extent[2][3]);
VKI_EXTERN void
vis_MeshConNormal(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vdouble vp[3]);
VKI_EXTERN void
vis_MeshConTangent(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vdouble vp[3]);
VKI_EXTERN void
vis_MeshConElemGath(vis_MeshCon* p, Vint id, Vint* npts, Vdouble xd[][3]);
VKI_EXTERN void
vis_MeshConProjectEdge(vis_MeshCon* p, Vint edid, Vdouble xp[3], Vint* id, Vdouble x[3]);
VKI_EXTERN void
vis_MeshConProjectEdgeLocal(vis_MeshCon* p, Vdouble xl[3], Vint edid, Vdouble xp[3], Vint* id, Vdouble x[3]);
VKI_EXTERN void
vis_MeshConPasteEdgePres(vis_MeshCon* p, Vdouble xa[3], Vint ta, Vdouble xb[3], Vint tb, Vint* npt, Vdouble xt[][3], Vint tt[]);
VKI_EXTERN void
vis_MeshConProjectEdgePres(vis_MeshCon* p, Vdouble xa[3], Vint ta, Vdouble xb[3], Vint tb, Vdouble w, Vdouble xp[3], Vint* tp);
VKI_EXTERN void
vis_MeshConProjectOneEdge(vis_MeshCon* p, Vint edid, Vdouble xp[3], Vdouble* r, Vdouble x[3], Vint* ierr);
VKI_EXTERN void
vis_MeshConGetADTree(vis_MeshCon* p, vsy_ADTree** adtree);
VKI_EXTERN void
vis_MeshConMaxEdgeElem(vis_MeshCon* p, Vint* melem);
VKI_EXTERN void
vis_MeshConDebugEdge(vis_MeshCon* p, Vint iop);
VKI_EXTERN void
vis_MeshConConsistent(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConExtent(vis_MeshCon* p, Vdouble extent[2][3]);
VKI_EXTERN void
vis_MeshConLoadConnect(vis_MeshCon* p, vis_Connect* connect);
VKI_EXTERN void
vis_MeshConSummary(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConPrint(vis_MeshCon* p);
VKI_EXTERN void
vis_MeshConAddEdge(vis_MeshCon* p, Vint elid, Vint ixe[2], Vint* edid);
VKI_EXTERN void
vis_MeshConReverseEdge(vis_MeshCon* p, Vint id);
VKI_EXTERN void
vis_MeshConCheckInvertElem(vis_MeshCon* p, Vint id, Vdouble v[3], Vdouble* metric, Vint* flag);
VKI_EXTERN void
vis_MeshConFlatNormal(vis_MeshCon* p, Vint id, Vdouble v[3]);
VKI_EXTERN void
vis_MeshConFlatTangent(vis_MeshCon* p, Vint id, Vint k, Vdouble v[3]);
VKI_EXTERN void
vis_MeshConElemCurv(vis_MeshCon* p, Vint id, Vint* npts, Vdouble x[][3]);
VKI_EXTERN void
vis_MeshConEdgeCurv(vis_MeshCon* p, Vint id, Vint* npts, Vdouble x[][3]);
VKI_EXTERN void
vis_MeshConBisect(vis_MeshCon* p, Vint noid, Vint edid1, Vint edid2, Vdouble vn[3], Vdouble vt[3], Vdouble vb[3]);
VKI_EXTERN void
vis_MeshConEdgeTangent(vis_MeshCon* p, Vint id, Vdouble v[3]);
VKI_EXTERN void
vis_MeshConEdgeLength(vis_MeshCon* p, Vint id, Vdouble* fl);
VKI_EXTERN void
vis_MeshConEdgeTangLeng(vis_MeshCon* p, Vint id, Vdouble v[3], Vdouble* fl);
VKI_EXTERN void
vis_MeshConEdgeCurvLength(vis_MeshCon* p, Vint id, Vdouble* fl);
VKI_EXTERN void
vis_MeshConElemEdgeNorm(vis_MeshCon* p, Vint id, Vint edid, Vint noid, Vint midflag, Vdouble ve[3]);
VKI_EXTERN void
vis_MeshConFrntDirCos(vis_MeshCon* p, Vint id, Vdouble tm[3][3]);

#ifdef __cplusplus
}
#endif

#endif
