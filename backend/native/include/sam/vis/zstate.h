/*********************************************************************
 *                                                                   *
 *                          DevTools 3.1.0                           *
 *                                                                   *
 *  These coded instructions, statements and computer programs       *
 *  contain unpublished proprietary information of Tech Soft 3D,     *
 *  and are protected by Federal copyright law.  They may not be     *
 *  disclosed to third parties or copied or duplicated in any form,  *
 *  in whole or in part, without the prior written consent of        *
 *  Tech Soft 3D.                                                    *
 *                                                                   *
 *                 Copyright (C) 2026, Tech Soft 3D                  *
 *                                                                   *
 *********************************************************************/
/* ZState object */
#ifndef ZSTATE_DEF
#define ZSTATE_DEF

#include "sam/base/base.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/gridfun.h"
#include "sam/vis/group.h"

/* ZState types */
#define ZSTATE_ELEMNODE 0
#define ZSTATE_NODE     1
#define ZSTATE_ELEM     4

/* parameter types */
#define ZSTATE_TOL        1
#define ZSTATE_NUMLEVELS  2
#define ZSTATE_NUMCOARSE  3
#define ZSTATE_NUMFINE    4
#define ZSTATE_WRITEMESH  5
#define ZSTATE_PRINTLEVEL 6
#define ZSTATE_ZEROTOL    7
#define ZSTATE_NUMZERO    8

/* mode types */
#define ZSTATE_SPATIALCONTINUITY 1

/* buffer size */
#define ZSTATE_BUFSIZE 2048

typedef struct {
    vis_GridFun* gf;
    vis_GridFun* ugf;
    Vint numnp;
    Vint numel;
    Vint enttype;
    Vint* emap;
    Vint* nmap;
    Vint* invnmap;
} vis_ZState_EGF;

struct vis_ZState {
    Vint ierr;
    Vint nument;  /* maximum index */
    Vint enttype; /* object type of ids */
    Vint subtype; /* sub object type of numbers */
    Vint datatype;

    vis_GridFun* gf;
    vis_GridFun* ugf;      /* use gridfun */
    vis_Connect* econnect; /* element connect object */
    vis_ZState_EGF* egf;
    Vfloat tol;
    Vfloat zerotol;

    /* kernel data */
    Vchar* cflag;
    Vint* tempmask;
    Vint numnp;
    Vint numel;
    Vint nc;
    Vint nf;
    Vint pdom;
    Vint groupid;
    Vschar* nixcoarse;
    Vint* ixcoarse;
    Vint nquad;
    Vint nlinear;
    Vint level;
    Vint hassublevel;
    vsy_BitVec* pathos;
    vis_ZState* zstate;
    vis_ZState* parent;
    vis_ZState* top;
    Vint* fnode;
    Vint maxeid;
    vis_Connect* connect;
    Vint kernel;
    Vint writemesh;
    vis_Connect* edgecn;
    vis_Connect* facecn;
    vis_Connect* richcn;
    Vint mapelem;
    Vint ngroups;
    vsy_IntHash* groupidx;
    vsy_IntVec* groupids;
    vis_ZState** kernels;
    Vulong nusbytes; /* number of uncompressed state bytes */
    Vulong nukbytes; /* number of uncompressed state bytes */
    Vint* elemnode;
    Vint continuous;
    Vint quant;
    Vfloat minval;
    Vfloat maxval;
    Vfloat delta;
    Vfloat constv;
    Vint maxdatasize;
    Vint maxdataloc;
    Vint maxdatasec;
    Vint printlevel;
    Vint nftot;
    Vint* active;
    Vint nzero;
    vis_IdTran* idtran;
    vsy_ZMem* zmem;
    Vulong membytes; /* total memory in write buffer */
    Vulong nubytes;  /* number of uncompressed bytes */
    Vulong ncbytes;  /* number of compressed bytes */
    Vulong nrubytes; /* number of uncompressed bytes during read */
    Vulong nrcbytes; /* number of compressed bytes during read */
    Vint buflen;
    Vchar buffer[ZSTATE_BUFSIZE];
    Vchar* cbuff;
    Vint swap;
    Vint bufpos;
    Vint iversion;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vis_ZState(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vis_ZState(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void
    SetObject(Vint, Vobject*);
    VKI_EXTERN void
    GetObject(Vint, Vobject**);
    VKI_EXTERN void SetParamf(Vint, Vfloat);
    VKI_EXTERN void SetParami(Vint, Vint);
    VKI_EXTERN void Def(Vint, Vint, Vint);
    VKI_EXTERN void
    Inq(Vint*, Vint*, Vint*) const;
    VKI_EXTERN void SetTemp(Vint);
    VKI_EXTERN void
    ClearTemp();
    VKI_EXTERN void SetPerm(Vint);
    VKI_EXTERN void
    Kernel(vis_IdTran*);
    VKI_EXTERN void
    LngKernel(Vulong*);
    VKI_EXTERN void
    SaveKernel(void*, Vulong*);
    VKI_EXTERN void
    LoadKernel(void*);
    VKI_EXTERN void
    Interpolate(Vint, Vint, Vint, Vint*, Vint*, Vint[], Vdouble[]);
    VKI_EXTERN void
    State(vis_State*);
    VKI_EXTERN void
    LngState(Vulong*);
    VKI_EXTERN void
    SaveState(vis_State*, void*, Vulong*);
    VKI_EXTERN void
    LoadState(void*, vis_State*);
    VKI_EXTERN void
    GetInteger(Vint, Vint, Vint*);
    VKI_EXTERN void
    GetLevelInteger(Vint, Vint, Vint, Vint*);
    VKI_EXTERN void
    ClearKernel();
    VKI_EXTERN void
    PrintKernel();
    VKI_EXTERN void SetMode(Vint, Vint);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif

VKI_EXTERN vis_ZState*
vis_ZStateBegin(void);
VKI_EXTERN void
vis_ZState_Construct(vis_ZState* p);
VKI_EXTERN void
vis_ZStateEnd(vis_ZState* p);
VKI_EXTERN void
vis_ZState_Destruct(vis_ZState* p);
VKI_EXTERN Vint
vis_ZStateError(vis_ZState* p);
VKI_EXTERN void
vis_ZStateSetObject(vis_ZState* p, Vint objecttype, Vobject* object);
VKI_EXTERN void
vis_ZStateGetObject(vis_ZState* p, Vint objecttype, Vobject** object);
VKI_EXTERN void
vis_ZStateSetParamf(vis_ZState* p, Vint type, Vfloat fparam);
VKI_EXTERN void
vis_ZStateSetParami(vis_ZState* p, Vint type, Vint iparam);
VKI_EXTERN void
vis_ZStateDef(vis_ZState* p, Vint nument, Vint enttype, Vint subtype);
VKI_EXTERN void
vis_ZStateInq(const vis_ZState* p, Vint* nument, Vint* enttype, Vint* subtype);
VKI_EXTERN void
vis_ZStateSetTemp(vis_ZState* p, Vint id);
VKI_EXTERN void
vis_ZStateClearTemp(vis_ZState* p);
VKI_EXTERN void
vis_ZStateSetPerm(vis_ZState* p, Vint nid);
VKI_EXTERN void
vis_ZStateKernel(vis_ZState* p, vis_IdTran* idtran);
VKI_EXTERN void
vis_ZStateLngKernel(vis_ZState* p, Vulong* nbytes);
VKI_EXTERN void
vis_ZStateSaveKernel(vis_ZState* p, void* buff, Vulong* nbytes);
VKI_EXTERN void
vis_ZStateLoadKernel(vis_ZState* p, void* buff);
VKI_EXTERN void
vis_ZStateInterpolate(vis_ZState* p, Vint group, Vint level, Vint nf, Vint* ifine, Vint* nix, Vint ix[], Vdouble w[]);
VKI_EXTERN void
vis_ZStateState(vis_ZState* p, vis_State* state);
VKI_EXTERN void
vis_ZStateLngState(vis_ZState* p, Vulong* nbytes);
VKI_EXTERN void
vis_ZStateSaveState(vis_ZState* p, vis_State* state, void* buff, Vulong* nbytes);
VKI_EXTERN void
vis_ZStateLoadState(vis_ZState* p, void* buff, vis_State* state);
VKI_EXTERN void
vis_ZStateGetInteger(vis_ZState* p, Vint group, Vint type, Vint* ivalue);
VKI_EXTERN void
vis_ZStateGetLevelInteger(vis_ZState* p, Vint group, Vint level, Vint type, Vint* ivalue);
VKI_EXTERN void
vis_ZStateClearKernel(vis_ZState* p);
VKI_EXTERN void
vis_ZStatePrintKernel(vis_ZState* p);
VKI_EXTERN void
vis_ZStateSetMode(vis_ZState* p, Vint type, Vint value);

#ifdef __cplusplus
}
#endif

#endif
