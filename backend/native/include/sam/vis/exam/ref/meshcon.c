/***********************************************************************
 *                                                                      *
 *               Copyright (C) 1994, Visual Kinematics, Inc.            *
 *                                                                      *
 *  These coded instructions, statements and computer programs contain  *
 *  unpublished proprietary information of Visual Kinematics, Inc.,     *
 *  and are protected by Federal copyright law.  They may not be        *
 *  disclosed to third parties or copied or duplicated in any form,     *
 *  in whole or in part, without the prior written consent of           *
 *  Visual Kinematics, Inc.                                             *
 *                                                                      *
 ***********************************************************************/
/*
   file       :  meshcon.c
   description:  Connection (unstructured grid) object
   author     :  Gordon H. Ferguson
   date       :  May 19, 1999
   discussion :
                 Need to change hardwired mulpind[10000].
                 AddPind, AppPind possible replication of pind values
*/

#include "sam/base/system.h"
#include "sam/base/base.h"
#include "sam/base/vututil.h"
#include "sam/base/vmlutil.h"
#include "sam/vis/visutil.h"
#include "sam/vis/visshar.h"
#include "sam/vis/meshcon.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vis/coordsys.h"

static void
vis_MeshCon_IncEdge(vis_MeshCon* p, Vint edid, Vint elid);
static void
vis_MeshCon_DecEdge(vis_MeshCon* p, Vint edid, Vint elid, Vint flag);
static void
vis_MeshCon_AddNoEd(vis_MeshCon* p, Vint* noed);
static void
vis_MeshCon_IncNode(vis_MeshCon* p, Vint id, Vint edid);
static void
vis_MeshCon_DecNode(vis_MeshCon* p, Vint id, Vint edid);
static void
vis_MeshCon_ADTInsert(vis_MeshCon* p, Vint id);
static void
vis_MeshCon_MinAngle(vis_MeshCon* p, Vint id);
static void
vis_MeshCon_MaxAngle(vis_MeshCon* p, Vint id);
static void
vis_MeshCon_MaxMinAngle(vis_MeshCon* p, Vint id);
static void
vis_MeshCon_MaxElemLen(vis_MeshCon* p, Vint id);
static void
vis_MeshCon_MinElemLen(vis_MeshCon* p, Vint id);
static void
vis_MeshCon_MaxEdgeLen(vis_MeshCon* p, Vint id);
static void
vis_MeshCon_MinEdgeLen(vis_MeshCon* p, Vint id);
static void
vis_MeshCon_MinFrntLen(vis_MeshCon* p, Vint id);
static void
vis_MeshCon_AddPind(vis_MeshCon* p, Vint* pind, Vint ival);
static void
vis_MeshCon_AppPind(vis_MeshCon* p, Vint* pind, Vint link);
static void
vis_MeshCon_NumPind(vis_MeshCon* p, Vint pind, Vint* num);
static void
vis_MeshCon_AllPind(vis_MeshCon* p, Vint pind, Vint* num, Vint ival[]);
static void
vis_MeshCon_FormElem1(vis_MeshCon* p, Vint nn, Vint no[], Vint ed[], Vint id, Vint* ned, Vint eld[], Vint* nnd, Vint nod[],
                      Vint* frfl);
static void
vis_MeshCon_ElemGath(vis_MeshCon* p, Vint nn, Vint elno[4], Vint eled[4], Vint* npts, Vdouble xd[][3]);
static void
vis_MeshCon_LocElemGlobal(vis_MeshCon* p, Vint tid, Vdouble atol, Vdouble xp[3], Vint* tgid, Vint* teid, Vdouble rg[3],
                          Vdouble xg[3]);
static void
vis_MeshCon_LocElemLocal(vis_MeshCon* p, Vint tid, Vdouble atol, Vdouble xp[3], Vint* tgid, Vint* teid, Vdouble rg[3],
                         Vdouble xg[3]);
static void
vis_MeshCon_ElemProject(Vint npts, Vdouble xd[6][3], Vdouble xp[3], Vdouble r[3], Vdouble xpd[3], Vint* nptsp, Vint* ierr);
static void
vis_MeshCon_ElemEdgeProject(Vint npts, Vdouble xd[6][3], Vdouble xp[3], Vint* ke, Vdouble r[3], Vdouble xpd[3]);
static void
vis_MeshCon_DistEdge(vis_MeshCon* p, Vdouble xp[3], Vdouble xpd[3], Vint npts, Vdouble xd[2][3], Vdouble* dist, Vint* ierr);
static void
vis_MeshCon_DistFace(vis_MeshCon* p, Vdouble xp[3], Vdouble xpd[3], Vdouble xd[3][3], Vdouble* dist, Vint* ierr);
static void
vis_MeshCon_LocEdgeGlobal(vis_MeshCon* p, Vdouble xp[3], Vint* tgid, Vdouble xg[3]);
static void
vis_MeshCon_LocEdgePres(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vint* tgid, Vdouble xg[3]);
static void
vis_MeshCon_Free(vis_MeshCon* p);

/*----------------------------------------------------------------------
                      begin
----------------------------------------------------------------------*/
extern vis_MeshCon*
vis_MeshConBegin(void)
{
    vis_MeshCon* p = (vis_MeshCon*)vut_mallocMem(sizeof(vis_MeshCon));
    vis_MeshCon_Construct(p);
    return (p);
}

extern void
vis_MeshCon_Construct(vis_MeshCon* p)
{
    if (p == NULL) {
        vut_ErrorCall("MeshCon", SYS_ERROR_MEMORY, CREATION_FAILURE);
        return;
    }
    p->ierr = SYS_ERROR_NONE;
    p->elem = NULL;
    p->edge = NULL;
    p->edgestack = NULL;
    p->numedgestack = 0;
    p->frnt = NULL;
    p->node = NULL;
    p->noed = NULL;
    p->inoed = NULL;
    p->inoed1 = NULL;
    p->iedl = NULL;
    p->tpedge = NULL;
    p->xpedge = NULL;
    p->ih = NULL;
    p->iternode = 0;
    p->iteredge = 0;
    p->iterelem = 0;
    p->pred = NULL;
    vis_MeshConClrAuxVec(p);
    vis_MeshConClrAuxPnt(p);

    p->numgeomface = 0;
    p->geomfaceelemhint = NULL;
    p->geomfaceelemnum = NULL;
    p->geomfacemapmesh = NULL;
    p->geomfaceinternal = NULL;
    p->geomfacecan = NULL;
    p->geomfacestk = NULL;

    p->asfsta = 0;
    p->asfnum = 0;
    p->asmmax = 0;
    p->asmval = NULL;

    p->currenttype = 0;
    p->currentid = 0;
    ZERO3(p->debugcen);
    p->debugrad = 0.;
    p->debugnumnodes = 0;
    p->debuglevel = 1;

    p->mconsistent = 0;
    p->nconsistent = 0;
    p->patchproject = SYS_ON;
    p->patchrestrict = 0;
    p->checkclosedfrnt = SYS_OFF;
    p->ctrlspace = SYS_OFF;
    p->verbose = 0;
    p->extendflag = 0;
    p->funflag = 0;

    p->nprojiter = 0;
    p->projglob = 0;
    p->nprojglob = 0;
    p->nprojedgeiter = 0;
    p->nprojedgepres = 0;
    p->nprojedgeglob = 0;
    p->nsplitelem = 0;
    p->nsplitedge = 0;
    p->nswapedge = 0;
    p->ncollapseedge = 0;
    p->warnflag = 0;
    p->adt = NULL;
    p->growthrate = 0.;
    p->tinylen = 0.;

    p->edgeheapsizefact = 0.;
    p->edgeheappresonly = 0;
    p->edgeheap = 0;
    p->hpedge = vsy_HeapBegin();
    p->elemheapsizefact = 0.;
    p->elemheap = 0;
    p->hpelem = vsy_HeapBegin();

    p->minfrntlen = 0;
    p->frntang = .75 * PI;
    p->cornang = .25 * PI;
    p->bfminlen[0] = vsy_PQueueBegin();
    p->bfminlen[1] = vsy_PQueueBegin();
    p->bfminlen[2] = vsy_PQueueBegin();

    /* edge collapse parameters */
    p->collrel = .0001;
    p->collrelflag = SYS_ON;
    p->collmet = 0.;
    p->collmetflag = SYS_OFF;
    p->collang = 0.;
    p->collangflag = SYS_OFF;
    p->collnormang = 0.;
    p->collnormangflag = SYS_OFF;
    p->swapnormang = 0.;
    p->swapnormangflag = SYS_OFF;
    p->collangimpflag = SYS_OFF;
    p->collimpflag = SYS_OFF;
    p->colltopoflag = SYS_ON;
    p->colllenmin = 0.;
    p->colllenmax = 0.;
    p->colllenflag = SYS_OFF;
    p->funsizingminflag = SYS_OFF;
    p->recovercos = 0.;
    p->walkfacetol = .01;

    p->normalflag = SYS_OFF;
    p->concat = vsy_ConcatBegin();
    p->ived = vsy_IntVecBegin();
    vsy_IntVecSetParami(p->ived, VSY_INCLUDEZERO, SYS_ON);
    p->ivel = vsy_IntVecBegin();
    vsy_IntVecSetParami(p->ivel, VSY_INCLUDEZERO, SYS_ON);
    p->stk = vsy_IntVecBegin();
    p->can = vsy_IntVecBegin();
    p->lst = vsy_IntVecBegin();
    p->numelemstat = 0;
    p->maxelemstat = 0;
    p->est = vsy_IntVecBegin();
    vsy_IntVecSetParami(p->est, VSY_INCLUDEZERO, SYS_ON);

    /* callback */
    p->funflag = 0;
    p->fun = NULL;
    p->funsiz = NULL;
    p->funani = NULL;
    p->fungeo = NULL;
    /* attribute geometry MeshCon */
    p->gm = NULL;
    /* attribute coordsys list */
    p->coniclist = NULL;
    /* meshsize object */
    p->meshsize = NULL;
    p->dmeshsize = NULL;
}

/*----------------------------------------------------------------------
                      end
----------------------------------------------------------------------*/
extern void
vis_MeshConEnd(vis_MeshCon* p)
{
    vis_MeshCon_Destruct(p);
    vut_freeMem(p);
}

extern void
vis_MeshCon_Destruct(vis_MeshCon* p)
{
    vis_MeshCon_Free(p);
    vsy_HeapEnd(p->hpedge);
    vsy_HeapEnd(p->hpelem);
    vsy_PQueueEnd(p->bfminlen[0]);
    vsy_PQueueEnd(p->bfminlen[1]);
    vsy_PQueueEnd(p->bfminlen[2]);
    vsy_ConcatEnd(p->concat);
    vsy_IntVecEnd(p->ived);
    vsy_IntVecEnd(p->ivel);
    vsy_IntVecEnd(p->stk);
    vsy_IntVecEnd(p->lst);
    vsy_IntVecEnd(p->can);
    vsy_IntVecEnd(p->est);
}

/*----------------------------------------------------------------------
                      get error
----------------------------------------------------------------------*/
extern Vint
vis_MeshConError(vis_MeshCon* p)
{
    Vint ierr;

    ierr = p->ierr;
    p->ierr = SYS_ERROR_NONE;
    return (ierr);
}

/*----------------------------------------------------------------------
                      define
----------------------------------------------------------------------*/
extern void
vis_MeshConDef(vis_MeshCon* p, Vint nnode, Vint nelem)
{
    static Vchar func[] = "vis_MeshConDef";
    Vint i;

    if (nnode < 0 || nelem < 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR2(func, p->ierr, "numnode= %d, numelem= %d", nnode, nelem);
        return;
    }
    /* free if allocated */
    vis_MeshCon_Free(p);

    p->numnode = 0;
    p->maxnode = MAX2(200, nnode + 1);
    p->numelem = 0;
    p->maxelem = MAX2(400, nelem + 1);

    p->numedge = 0;
    p->maxedge = 2 * p->maxelem;
    p->numfrnt = 0;
    p->maxfrnt = p->maxelem / 4;
    vsy_IntVecDef(p->ivel, p->maxelem);
    vsy_IntVecDef(p->ived, p->maxedge);
    vsy_IntVecDef(p->stk, 1000);
    vsy_IntVecDef(p->can, p->maxelem);
    vsy_IntVecDef(p->lst, 1000);
    vsy_IntVecDef(p->est, 1000);

    p->numnoed = 0;
    p->maxnoed = 2 * p->maxnode;

    /* nodes */
    p->node = (vis_MeshCon_Node*)vut_mallocMem((p->maxnode + 1) * sizeof(vis_MeshCon_Node));
    if (p->node == NULL) {
        p->ierr = VIS_ERROR_MEMORY;
        HANDLEERR0(func, p->ierr, "Malloc node");
        return;
    }
    for (i = 0; i <= p->maxnode; i++) {
        p->node[i].ned = 0;
        p->node[i].noed = 0;
        p->node[i].next = i + 1;
        p->node[i].pres = 0;
        p->node[i].pind = 0;
        p->node[i].pref = 0;
        p->node[i].stat = 0;
        p->node[i].topo = 0;
    }
    p->node[p->maxnode].next = 0;
    p->headnode = 0;

    /* internal node edge vector */
    p->mxinoed = 1000;
    p->inoed = (Vint*)vut_mallocMem((p->mxinoed + 1) * sizeof(Vint));
    p->inoed1 = (Vint*)vut_mallocMem((p->mxinoed + 1) * sizeof(Vint));
    if (p->inoed == NULL || p->inoed1 == NULL) {
        p->ierr = VIS_ERROR_MEMORY;
        HANDLEERR0(func, p->ierr, "Malloc inoed");
        return;
    }
    /* internal recover edge list */
    p->mxiedl = 1000;
    p->iedl = (Vint*)vut_mallocMem((p->mxiedl + 1) * sizeof(Vint));
    if (p->iedl == NULL) {
        p->ierr = VIS_ERROR_MEMORY;
        HANDLEERR0(func, p->ierr, "Malloc iedl");
        return;
    }
    /* hash table */
    p->ih = vsy_IntHashBegin();
    vsy_IntHashDef(p->ih, 100);
    /* node edge list */
    p->noed = (vis_MeshCon_NoEd*)vut_mallocMem((p->maxnoed + 1) * sizeof(vis_MeshCon_NoEd));
    if (p->noed == NULL) {
        p->ierr = VIS_ERROR_MEMORY;
        HANDLEERR0(func, p->ierr, "Malloc node edge list");
        return;
    }
    for (i = 0; i <= p->maxnoed; i++) {
        p->noed[i].next = i + 1;
    }
    p->noed[p->maxnoed].next = 0;
    p->headnoed = 0;
    p->mxnoed = 0;

    /* elements */
    p->elem = (vis_MeshCon_Elem*)vut_mallocMem((p->maxelem + 1) * sizeof(vis_MeshCon_Elem));
    if (p->elem == NULL) {
        p->ierr = VIS_ERROR_MEMORY;
        HANDLEERR0(func, p->ierr, "Malloc elem");
        return;
    }
    for (i = 0; i <= p->maxelem; i++) {
        p->elem[i].prev = 0;
        p->elem[i].next = i + 1;
        p->elem[i].pres = 0;
        p->elem[i].pind = 0;
        p->elem[i].flat = 0;
        p->elem[i].stat = 0;
        p->elem[i].size = 0.;
        p->elem[i].ne = NULL;
    }
    p->elem[p->maxelem].next = 0;
    p->headelem = 0;

    /* edges */
    p->edge = (vis_MeshCon_Edge*)vut_mallocMem((p->maxedge + 1) * sizeof(vis_MeshCon_Edge));
    if (p->edge == NULL) {
        p->ierr = VIS_ERROR_MEMORY;
        HANDLEERR0(func, p->ierr, "Malloc edge");
        return;
    }
    p->edgestack = (Vint*)vut_mallocMem((p->maxedge + 1) * sizeof(Vint));
    if (p->edgestack == NULL) {
        p->ierr = VIS_ERROR_MEMORY;
        HANDLEERR0(func, p->ierr, "Malloc edgestack");
        return;
    }
    for (i = 0; i <= p->maxedge; i++) {
        p->edge[i].next = i + 1;
        p->edge[i].nelem = 0;
        p->edge[i].melem = 2;
        p->edge[i].el = (Vint*)vut_mallocMem(2 * sizeof(Vint));
        p->edge[i].el[0] = 0;
        p->edge[i].el[1] = 0;
        p->edge[i].fr = (Vint*)vut_mallocMem(2 * sizeof(Vint));
        p->edge[i].fr[0] = 0;
        p->edge[i].fr[1] = 0;
        p->edge[i].size = 0.;
        p->edge[i].ns = NULL;
        p->edge[i].pres = 0;
        p->edge[i].pind = 0;
        p->edge[i].pref = 0;
        p->edge[i].stat = 0;
        p->edge[i].cent = 0;
        p->edge[i].topo = 0;
    }
    p->edge[p->maxedge].next = 0;
    p->headedge = 0;

    /* fronts */
    p->frnt = (vis_MeshCon_Frnt*)vut_mallocMem((p->maxfrnt + 1) * sizeof(vis_MeshCon_Frnt));
    if (p->frnt == NULL) {
        p->ierr = VIS_ERROR_MEMORY;
        HANDLEERR0(func, p->ierr, "Malloc frnt");
        return;
    }
    for (i = 0; i <= p->maxfrnt; i++) {
        p->frnt[i].next = i + 1;
    }
    p->frnt[p->maxfrnt].next = 0;
    p->headfrnt = 0;

    /* multiple assoc slots */
    p->asmmax = 256;
    p->asmval = (Vint(*)[2])vut_mallocMem(2 * (p->asmmax + 1) * sizeof(Vint));
    if (p->asmval == NULL) {
        p->ierr = VIS_ERROR_MEMORY;
        HANDLEERR0(func, p->ierr, "Malloc asmval");
        return;
    }
    /* initialize free list */
    p->asfnum = p->asmmax;
    p->asfsta = 1;
    p->asmval[0][0] = 0;
    p->asmval[0][1] = 0;
    for (i = 1; i < p->asmmax; i++) {
        p->asmval[i][0] = i + 1;
        p->asmval[i][1] = 0;
    }
    p->asmval[p->asmmax][0] = 0;
    p->asmval[p->asmmax][1] = 0;
}

/*----------------------------------------------------------------------
                      inquire
----------------------------------------------------------------------*/
extern void
vis_MeshConInq(const vis_MeshCon* p, Vint* nnode, Vint* nelem)
{
    *nnode = p->maxnode;
    *nelem = p->maxelem;
}

extern void
vis_MeshConSetPred(vis_MeshCon* p, vsy_Pred* pred)
{
    p->pred = pred;
}

/*----------------------------------------------------------------------
                      set function
----------------------------------------------------------------------*/
extern void
vis_MeshConSetFunction(vis_MeshCon* p, Vfunc* function, Vobject* object)
{
    p->fun = (void (*)(vis_MeshCon*, Vobject*))function;
    p->funobject = object;
}

extern void
vis_MeshConSetSizing(vis_MeshCon* p, Vfunc* function, Vobject* object)
{
    p->funsiz = (void (*)(vis_MeshCon*, Vobject*, Vdouble*, Vdouble*))function;
    p->funobjsiz = object;
}

extern void
vis_MeshConSetASizing(vis_MeshCon* p, Vfunc* function, Vobject* object)
{
    p->funani = (void (*)(vis_MeshCon*, Vobject*, Vdouble*, Vdouble[3][3]))function;
    p->funobjani = object;
}

extern void
vis_MeshConSetGeoproj(vis_MeshCon* p, Vfunc* function, Vobject* object)
{
    p->fungeo = (void (*)(Vobject*, Vobject*, Vint, Vint, Vdouble*, Vdouble*, Vdouble*, Vdouble*))function;
    p->funobjgeo = object;
}

/*----------------------------------------------------------------------
                      call function
----------------------------------------------------------------------*/
extern void
vis_MeshConSetFunFlag(vis_MeshCon* p, Vint funflag)
{
    p->funflag = funflag;
}

extern Vint
vis_MeshConFunFlag(vis_MeshCon* p)
{
    return (p->funflag);
}

extern void
vis_MeshConCallFunction(vis_MeshCon* p, Vint iop, Vchar* stg)
{
    if (stg) {
        printf("%s\n", stg);
    }
    if (iop || p->funflag) {
        if (p->fun) {
            p->fun(p, p->funobject);
        }
    }
}

/*----------------------------------------------------------------------
                      set geometry meshcon
----------------------------------------------------------------------*/
extern void
vis_MeshConSetGeomMeshCon(vis_MeshCon* p, vis_MeshCon* gmeshcon)
{
    p->gm = gmeshcon;
}

/*----------------------------------------------------------------------
                      set geometry meshcon
----------------------------------------------------------------------*/
extern void
vis_MeshConSetConicList(vis_MeshCon* p, vsy_List* coniclist)
{
    p->coniclist = coniclist;
}

extern void
vis_MeshConGetConicList(vis_MeshCon* p, vsy_List** coniclist)
{
    *coniclist = p->coniclist;
}

extern void
vis_MeshConGetCoordSys(vis_MeshCon* p, Vint ptid, vis_CoordSys** coordsys)
{
    if (p->coniclist) {
        vsy_ListRef(p->coniclist, ptid, (Vobject**)coordsys);
    }
    else {
        *coordsys = NULL;
    }
}

/*----------------------------------------------------------------------
                      set geometry meshcon
----------------------------------------------------------------------*/
extern void
vis_MeshConSetGeomMeshSize(vis_MeshCon* p, vis_MeshSize* meshsize)
{
    p->meshsize = meshsize;
}

extern void
vis_MeshConSetDepthMeshSize(vis_MeshCon* p, vis_MeshSize* meshsize)
{
    p->dmeshsize = meshsize;
}

/*----------------------------------------------------------------------
                      set parameters
----------------------------------------------------------------------*/
extern void
vis_MeshConSetParami(vis_MeshCon* p, Vint type, Vint iparam)
{
    static Vchar func[] = "vis_MeshConSetParami";

    if (type == MESHCON_MINFRNTLEN) {
        p->minfrntlen = iparam;
    }
    else if (type == MESHCON_CONSISTENT) {
        p->mconsistent = iparam;
    }
    else if (type == MESHCON_PATCHPROJECT) {
        p->patchproject = iparam;
    }
    else if (type == MESHCON_PATCHRESTRICT) {
        p->patchrestrict = iparam;
    }
    else if (type == MESHCON_CHECKCLOSEDFRNT) {
        p->checkclosedfrnt = iparam;
    }
    else if (type == MESHCON_EXTEND) {
        p->extendflag = iparam;
    }
    else if (type == MESHCON_NORMAL) {
        p->normalflag = iparam;
    }
    else if (type == MESHCON_COLLIMPFLAG) {
        p->collimpflag = iparam;
    }
    else if (type == MESHCON_COLLRELFLAG) {
        p->collrelflag = iparam;
    }
    else if (type == MESHCON_COLLMETFLAG) {
        p->collmetflag = iparam;
    }
    else if (type == MESHCON_COLLANGFLAG) {
        p->collangflag = iparam;
    }
    else if (type == MESHCON_COLLNORMANGFLAG) {
        p->collnormangflag = iparam;
    }
    else if (type == MESHCON_SWAPNORMANGFLAG) {
        p->swapnormangflag = iparam;
    }
    else if (type == MESHCON_COLLANGIMPFLAG) {
        p->collangimpflag = iparam;
    }
    else if (type == MESHCON_COLLTOPOFLAG) {
        p->colltopoflag = iparam;
    }
    else if (type == MESHCON_COLLLENFLAG) {
        p->colllenflag = iparam;
    }
    else if (type == MESHCON_EDGEHEAPPRESONLY) {
        p->edgeheappresonly = iparam;
    }
    else if (type == MESHCON_CTRLSPACE) {
        p->ctrlspace = iparam;
    }
    else if (type == MESHCON_VERBOSE) {
        p->verbose = iparam;
    }
    else if (type == MESHCON_FUNSIZINGMIN) {
        p->funsizingminflag = iparam;
    }
    else {
        p->ierr = SYS_ERROR_ENUM;
        HANDLEERR1(func, p->ierr, "type= %d", type);
        return;
    }
}

extern void
vis_MeshConGetParami(vis_MeshCon* p, Vint type, Vint* iparam)
{
    static Vchar func[] = "vis_MeshConGetParami";

    if (type == MESHCON_PATCHRESTRICT) {
        *iparam = p->patchrestrict;
    }
    else {
        p->ierr = SYS_ERROR_ENUM;
        HANDLEERR1(func, p->ierr, "type= %d", type);
        return;
    }
}

extern void
vis_MeshConSetParamd(vis_MeshCon* p, Vint type, Vdouble param)
{
    static Vchar func[] = "vis_MeshConSetParamd";

    if (type == MESHCON_FRNTANG) {
        p->frntang = param;
    }
    else if (type == MESHCON_CORNANG) {
        p->cornang = param;
    }
    else if (type == MESHCON_COLLREL) {
        p->collrel = param;
    }
    else if (type == MESHCON_COLLMET) {
        p->collmet = param;
    }
    else if (type == MESHCON_COLLANG) {
        p->collang = param;
    }
    else if (type == MESHCON_COLLNORMANG) {
        p->collnormang = param;
    }
    else if (type == MESHCON_SWAPNORMANG) {
        p->swapnormang = param;
    }
    else if (type == MESHCON_COLLLENMAX) {
        p->colllenmax = param;
    }
    else if (type == MESHCON_COLLLENMIN) {
        p->colllenmin = param;
    }
    else if (type == MESHCON_GROWTHRATE) {
        p->growthrate = param;
    }
    else if (type == MESHCON_TINYLEN) {
        p->tinylen = param;
    }
    else if (type == MESHCON_RECOVERCOS) {
        p->recovercos = param;
    }
    else if (type == MESHCON_EDGEHEAPSIZEFACT) {
        p->edgeheapsizefact = param;
    }
    else if (type == MESHCON_ELEMHEAPSIZEFACT) {
        p->elemheapsizefact = param;
    }
    else if (type == MESHCON_WALKFACETOL) {
        p->walkfacetol = param;
        if (p->walkfacetol == 0.) {
            p->walkfacetol = .01;
        }
    }
    else {
        p->ierr = SYS_ERROR_ENUM;
        HANDLEERR1(func, p->ierr, "type= %d", type);
        return;
    }
}

extern void
vis_MeshConGetParamd(vis_MeshCon* p, Vint type, Vdouble* param)
{
    static Vchar func[] = "vis_MeshConGetParamd";

    if (type == MESHCON_TINYLEN) {
        *param = p->tinylen;
    }
    else {
        p->ierr = SYS_ERROR_ENUM;
        HANDLEERR1(func, p->ierr, "type= %d", type);
        return;
    }
}

/*----------------------------------------------------------------------
                      warnflag
----------------------------------------------------------------------*/
extern void
vis_MeshConWarn(vis_MeshCon* p, Vint* flag)
{
    *flag = p->warnflag;
}

/*----------------------------------------------------------------------
                      number of entities
----------------------------------------------------------------------*/
extern void
vis_MeshConNumber(const vis_MeshCon* p, Vint type, Vint* numentity)
{
    if (type == SYS_NODE) {
        *numentity = p->numnode;
    }
    else if (type == SYS_ELEM) {
        *numentity = p->numelem;
    }
    else if (type == SYS_EDGE) {
        *numentity = p->numedge;
    }
}

/*----------------------------------------------------------------------
                      Get Integer
----------------------------------------------------------------------*/
extern void
vis_MeshConGetInteger(vis_MeshCon* p, Vint type, Vint iparams[])
{
    static Vchar func[] = "vis_MeshConGetInteger";

    if (type == MESHCON_GLOBALPROJECT) {
        iparams[0] = p->projglob;
    }
    else {
        p->ierr = VIS_ERROR_ENUM;
        HANDLEERR1(func, p->ierr, "type= %d", type);
    }
}

extern void
vis_MeshConMaxEdge(vis_MeshCon* p, Vint* maxedge)
{
    *maxedge = p->maxedge;
}

/*----------------------------------------------------------------------
                      aux values
----------------------------------------------------------------------*/
extern void
vis_MeshConClrAuxVec(vis_MeshCon* p)
{
    ZERO3(p->vk[0]);
    ZERO3(p->vk[1]);
    ZERO3(p->vl[0]);
    ZERO3(p->vl[1]);
    ZERO3(p->vf[0]);
    ZERO3(p->vf[1]);
}

extern void
vis_MeshConSetAuxVec(vis_MeshCon* p, Vint type, Vint k, Vdouble v[3])
{
    /* ideal vector, vk */
    if (type == 0) {
        MOVE3(v, p->vk[k]);
        /* ideal side vector, vl */
    }
    else if (type == 1) {
        MOVE3(v, p->vl[k]);
        /* projected ideal vector, vf */
    }
    else if (type == 2) {
        MOVE3(v, p->vf[k]);
    }
}

extern void
vis_MeshConGetAuxVec(vis_MeshCon* p, Vint type, Vint k, Vdouble v[3])
{
    /* ideal vector, vk */
    if (type == 0) {
        MOVE3(p->vk[k], v);
        /* ideal side vector, vl */
    }
    else if (type == 1) {
        MOVE3(p->vl[k], v);
        /* projected ideal vector, vf */
    }
    else if (type == 2) {
        MOVE3(p->vf[k], v);
    }
}

extern void
vis_MeshConClrAuxPnt(vis_MeshCon* p)
{
    ZERO3(p->pk[0]);
    ZERO3(p->pk[1]);
    ZERO3(p->pl[0]);
    ZERO3(p->pl[1]);
    ZERO3(p->pf[0]);
    ZERO3(p->pf[1]);
}

extern void
vis_MeshConSetAuxPnt(vis_MeshCon* p, Vint type, Vint k, Vdouble v[3])
{
    /* ideal vector, vk */
    if (type == 0) {
        MOVE3(v, p->pk[k]);
        /* ideal side vector, vl */
    }
    else if (type == 1) {
        MOVE3(v, p->pl[k]);
        /* projected ideal vector, vf */
    }
    else if (type == 2) {
        MOVE3(v, p->pf[k]);
    }
}

extern void
vis_MeshConGetAuxPnt(vis_MeshCon* p, Vint type, Vint k, Vdouble v[3])
{
    /* ideal vector, vk */
    if (type == 0) {
        MOVE3(p->pk[k], v);
        /* ideal side vector, vl */
    }
    else if (type == 1) {
        MOVE3(p->pl[k], v);
        /* projected ideal vector, vf */
    }
    else if (type == 2) {
        MOVE3(p->pf[k], v);
    }
}

/*----------------------------------------------------------------------
                      set,get current node, edge, element for debugging
----------------------------------------------------------------------*/
extern void
vis_MeshConSetCurrEnt(vis_MeshCon* p, Vint enttype, Vint id)
{
    p->currenttype = enttype;
    p->currentid = id;
}

extern void
vis_MeshConGetCurrEnt(vis_MeshCon* p, Vint* enttype, Vint* id)
{
    *enttype = p->currenttype;
    *id = p->currentid;
}

extern void
vis_MeshConGetCurrEntId(vis_MeshCon* p, Vint enttype, Vint* id)
{
    if (enttype == p->currenttype) {
        *id = p->currentid;
    }
    else {
        *id = 0;
    }
}

/*----------------------------------------------------------------------
                      set debug sphere
----------------------------------------------------------------------*/
extern void
vis_MeshConSetDebugSphere(vis_MeshCon* p, Vdouble cen[3], Vdouble rad)
{
    MOVE3(cen, p->debugcen);
    p->debugrad = rad;
}

extern void
vis_MeshConSetDebugNodes(vis_MeshCon* p, Vint num, Vint nodes[])
{
    Vint i;

    p->debugnumnodes = num;
    for (i = 0; i < num; i++) {
        p->debugnodes[i] = nodes[i];
    }
}

extern void
vis_MeshConSetDebugLevel(vis_MeshCon* p, Vint level)
{
    p->debuglevel = level;
}

extern void
vis_MeshConDebugEnt(vis_MeshCon* p, Vint enttype, Vint id, Vint* flag)
{
    Vint i, j;
    Vint nix, ix[4];
    Vdouble x[3], d[3], fl;

    if (enttype == SYS_NODE) {
        nix = 1;
        ix[0] = id;
    }
    else if (enttype == SYS_EDGE) {
        nix = 2;
        vis_MeshConGetEdgeNode(p, id, ix);
    }
    else if (enttype == SYS_ELEM) {
        vis_MeshConGetElemNode(p, id, &nix, ix);
    }
    *flag = 0;
    /* test nodes */
    for (i = 0; i < p->debugnumnodes; i++) {
        /* all nodes */
        if (p->debugnodes[i] == -1) {
            *flag = p->debuglevel;
            return;
        }
        for (j = 0; j < nix; j++) {
            if (p->debugnodes[i] == -2) {
                if (p->node[ix[j]].pres == SYS_NODE) {
                    *flag = p->debuglevel;
                    return;
                }
            }
            else if (p->debugnodes[i] == -3) {
                if (p->node[ix[j]].pres == SYS_EDGE) {
                    *flag = p->debuglevel;
                    return;
                }
            }
            else if (p->debugnodes[i] == -4) {
                if (p->node[ix[j]].pres == SYS_FACE) {
                    *flag = p->debuglevel;
                    return;
                }
            }
            if (ix[j] == p->debugnodes[i]) {
                *flag = p->debuglevel;
                return;
            }
        }
    }
    /* test sphere */
    if (p->debugrad != 0.) {
        for (j = 0; j < nix; j++) {
            vis_MeshConGetNode(p, ix[i], x);
            DIFF3(x, p->debugcen, d);
            fl = MAG3(d);
            if (fl <= p->debugrad) {
                *flag = p->debuglevel;
                return;
            }
        }
    }
}

/*----------------------------------------------------------------------
                      add, set node
----------------------------------------------------------------------*/
extern void
vis_MeshConAddNode(vis_MeshCon* p, Vdouble x[3], Vint* id)
{
    static Vchar func[] = "vis_MeshConAddNode";
    Vint i, n;
    vis_MeshCon_Node* pnode;
    Vint pmaxnode;
    /* check to expand storage */
    if (p->numnode + 1 == p->maxnode) {
        pmaxnode = MIN2(20000 + p->maxnode, 2 * p->maxnode);
        pnode = (vis_MeshCon_Node*)vut_reallocMem(p->node, (pmaxnode + 1) * sizeof(vis_MeshCon_Node));
        if (pnode == NULL) {
            p->ierr = VIS_ERROR_MEMORY;
            HANDLEERR0(func, p->ierr, "Realloc node");
            return;
        }
        p->node = pnode;
        for (i = p->maxnode; i <= pmaxnode; i++) {
            p->node[i].ned = 0;
            p->node[i].noed = 0;
            p->node[i].next = i + 1;
            p->node[i].pres = 0;
            p->node[i].pind = 0;
            p->node[i].pref = 0;
            p->node[i].stat = 0;
            p->node[i].topo = 0;
        }
        p->maxnode = pmaxnode;
        p->node[p->maxnode].next = 0;
    }
    /* get next free node */
    n = p->node[0].next;
    if (n == p->headnode) {
        p->ierr = VIS_ERROR_OPERATION;
        HANDLEERR1(func, p->ierr, "headnode equals n= %d", n);
        return;
    }
    p->node[0].next = p->node[n].next;

    /* link in node */
    p->node[n].next = p->headnode;
    p->node[n].prev = 0;
    p->node[p->headnode].prev = n;
    p->headnode = n;
    /* set coordinates */
    MOVE3(x, p->node[n].x);
    /* zero size and distance */
    p->node[n].size = 0.;
    p->node[n].dist = 0.;
    /* zero status */
    p->node[n].stat = 0;
    /* zero topoflag */
    p->node[n].topo = 0;

    /* no attached elements */
    p->node[n].ned = 0;
    vis_MeshCon_AddNoEd(p, &p->node[n].noed);
    p->node[n].loed = p->node[n].noed;
    *id = n;
    p->numnode += 1;
}

extern void
vis_MeshConSetNode(vis_MeshCon* p, Vint id, Vdouble x[3])
{
    Vint i, k, num, nel;
    Vint frid;
    /* set node coordinates */
    MOVE3(x, p->node[id].x);
    /* tree */
    if (p->adt) {
        vis_MeshConGetNodeElem(p, id, &num, p->inoed);
        for (i = 0; i < num; i++) {
            vsy_ADTreeRemove(p->adt, p->inoed[i]);
            vis_MeshCon_ADTInsert(p, p->inoed[i]);
        }
    }
    /* compute heap property of connected elements */
    if (p->elemheap) {
        vis_MeshConGetNodeElem(p, id, &num, p->inoed);
        for (i = 0; i < num; i++) {
            if (p->elemheap == MESHCON_MINELEMANG) {
                vis_MeshCon_MinAngle(p, p->inoed[i]);
            }
            else if (p->elemheap == MESHCON_MAXELEMANG) {
                vis_MeshCon_MaxAngle(p, p->inoed[i]);
            }
            else if (p->elemheap == MESHCON_MAXELEMANG) {
                vis_MeshCon_MaxAngle(p, p->inoed[i]);
            }
            else if (p->elemheap == MESHCON_MAXELEMLEN) {
                vis_MeshCon_MaxElemLen(p, p->inoed[i]);
            }
            else if (p->elemheap == MESHCON_MINELEMLEN) {
                vis_MeshCon_MinElemLen(p, p->inoed[i]);
            }
            else if (p->elemheap == MESHCON_MAXMINELEMANG) {
                vis_MeshCon_MaxMinAngle(p, p->inoed[i]);
            }
        }
    }
    /* compute edge length of connected edges */
    if (p->edgeheap) {
        vis_MeshConGetNodeEdge(p, id, &num, p->inoed);
        for (i = 0; i < num; i++) {
            if (p->edgeheap == MESHCON_MINEDGELEN) {
                vis_MeshCon_MinEdgeLen(p, p->inoed[i]);
            }
            else if (p->edgeheap == MESHCON_MAXEDGELEN) {
                vis_MeshCon_MaxEdgeLen(p, p->inoed[i]);
            }
        }
    }
    /* update fronts */
    if (p->minfrntlen) {
        vis_MeshConGetNodeEdge(p, id, &num, p->inoed);
        for (i = 0; i < num; i++) {
            nel = p->edge[p->inoed[i]].nelem;
            for (k = 0; k < nel; k++) {
                frid = p->edge[p->inoed[i]].fr[k];
                if (frid) {
                    vis_MeshCon_MinFrntLen(p, frid);
                }
            }
        }
    }
}

extern void
vis_MeshConDelNode(vis_MeshCon* p, Vint id)
{
    Vint i;
    Vint n, nx, pr;
    Vint inoed;

    /* check to make sure node is not referenced by an edge */
    inoed = p->node[id].noed;
    for (i = 0; i < p->node[id].ned; i++) {
        vis_MeshCon_DecNode(p, id, p->noed[inoed].ed[0]);
    }
    /* place node in free list */
    n = p->node[0].next;
    p->node[0].next = id;
    nx = p->node[id].next;
    pr = p->node[id].prev;
    p->node[id].next = n;
    p->node[id].ned = 0;
    p->node[id].noed = 0;
    p->node[id].pres = 0;
    p->node[id].pind = 0;
    p->node[id].pref = 0;
    p->node[id].stat = 0;
    p->node[id].topo = 0;

    /* delete node from active list */
    if (nx) {
        p->node[nx].prev = pr;
    }
    if (pr == 0) {
        p->headnode = nx;
    }
    else {
        p->node[pr].next = nx;
    }

    p->numnode -= 1;
}

extern void
vis_MeshConGetNode(vis_MeshCon* p, Vint id, Vdouble x[3])
{
    static Vchar func[] = "vis_MeshConGetNode";

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    MOVE3(p->node[id].x, x);
}

extern void
vis_MeshConGetNode2Dim(vis_MeshCon* p, Vint id, Vdouble x[2])
{
    static Vchar func[] = "vis_MeshConGetNode2Dim";

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    MOVE2(p->node[id].x, x);
}

extern void
vis_MeshConGetNodes(vis_MeshCon* p, Vint nid, Vint ids[], Vdouble x[][3])
{
    Vint i;

    for (i = 0; i < nid; i++) {
        MOVE3(p->node[ids[i]].x, x[i]);
    }
}

extern void
vis_MeshConGetNodesCtrl(vis_MeshCon* p, Vint nid, Vint ids[], Vdouble x[][3])
{
    Vint i;
    Vdouble ss;
    Vdouble s[3][3];

    for (i = 0; i < nid; i++) {
        MOVE3(p->node[ids[i]].x, x[i]);
    }
    if (p->funani) {
        p->funani(p, p->funobjani, x[0], s);
        vis_transCtrl(s, nid, x);
    }
    else {
        vis_MeshConGetNodeSize(p, ids[0], &ss);
        ss = 1. / ss;
        for (i = 0; i < nid; i++) {
            SCALE3(x[i], ss);
        }
    }
}

extern void
vis_MeshConMaxNodeEdge(vis_MeshCon* p, Vint* maxnodeedge)
{
    *maxnodeedge = p->mxnoed;
}

extern void
vis_MeshConNumNodeEdge(vis_MeshCon* p, Vint id, Vint* numnodeedge)
{
    *numnodeedge = p->node[id].ned;
}

/*----------------------------------------------------------------------
                      number of preserved edges connected to a node
----------------------------------------------------------------------*/
extern void
vis_MeshConNumNodePresEdge(vis_MeshCon* p, Vint id, Vint* numnodepresedge)
{
    Vint i;
    Vint in, inoed;
    Vint edid;

    *numnodepresedge = 0;
    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        if (p->edge[edid].pres) {
            *numnodepresedge += 1;
        }
    }
}

extern void
vis_MeshConNodePresEdge(vis_MeshCon* p, Vint id, Vint* num, Vint noed[])
{
    Vint i;
    Vint in, inoed;
    Vint edid;

    *num = 0;
    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        if (p->edge[edid].pres) {
            noed[*num] = edid;
            *num += 1;
        }
    }
}

extern void
vis_MeshConFindNodePresEdge(vis_MeshCon* p, Vint id, Vint pres, Vint* edid)
{
    Vint i;
    Vint in, inoed;
    Vint eid, epres, ptid;

    *edid = 0;
    if (p->gm == NULL) {
        return;
    }

    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        eid = p->noed[inoed].ed[in];
        epres = p->edge[eid].pres;
        if (epres == 0)
            continue;
        vis_MeshConGetEdgePres(p->gm, epres, &ptid);
        if (pres == ptid) {
            *edid = eid;
            return;
        }
    }
}

extern void
vis_MeshConAdjPresEdge(vis_MeshCon* p, Vint id, Vint noid, Vint* noed)
{
    Vint i;
    Vint in, inoed;
    Vint edid;
    /* noid should be on a preserved edge */
    /* 0 is returned if no adjacent edge */
    *noed = 0;
    inoed = p->node[noid].noed;
    in = 0;
    for (i = 0; i < p->node[noid].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        if (edid == id)
            continue;
        if (p->edge[edid].pres) {
            *noed = edid;
            if (p->verbose > 2) {
                if (p->edge[id].no[0] == noid) {
                    if (p->edge[edid].no[1] != noid) {
                        printf("AdjPresEdge error, id= %d, noid= %d\n", id, noid);
                    }
                }
                else {
                    if (p->edge[edid].no[0] != noid) {
                        printf("AdjPresEdge error, id= %d, noid= %d\n", id, noid);
                    }
                }
            }
            break;
        }
    }
}

extern void
vis_MeshConNodeSpecPresEdge(vis_MeshCon* p, Vint noid, Vint pres, Vint* num, Vint id[])
{
    Vint i;
    Vint in, inoed;
    Vint edid;
    /* noid should be on a preserved node */
    *num = 0;
    inoed = p->node[noid].noed;
    in = 0;
    for (i = 0; i < p->node[noid].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        if (p->edge[edid].pres == pres) {
            id[*num] = edid;
            *num += 1;
        }
    }
}

/*----------------------------------------------------------------------
                      number of recovered edges connected to a node
----------------------------------------------------------------------*/
extern void
vis_MeshConNumNodePrefEdge(vis_MeshCon* p, Vint id, Vint* numnodeprefedge)
{
    Vint i;
    Vint in, inoed;
    Vint edid;

    *numnodeprefedge = 0;
    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        if (p->edge[edid].pref) {
            *numnodeprefedge += 1;
        }
    }
}

/*----------------------------------------------------------------------
                      number of non-manifold edges connected to a node
----------------------------------------------------------------------*/
extern void
vis_MeshConNumNodeNMEdge(vis_MeshCon* p, Vint id, Vint* numnodenmedge)
{
    Vint i;
    Vint in, inoed;
    Vint edid;

    *numnodenmedge = 0;
    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        if (p->edge[edid].nelem != 2) {
            *numnodenmedge += 1;
        }
    }
}

extern void
vis_MeshConNumNodeFrntEdge(vis_MeshCon* p, Vint id, Vint* numnodefrntedge)
{
    Vint i, j;
    Vint in, inoed;
    Vint edid;

    *numnodefrntedge = 0;
    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        for (j = 0; j < p->edge[edid].nelem; j++) {
            if (p->edge[edid].fr[j]) {
                *numnodefrntedge += 1;
            }
        }
    }
}

/*----------------------------------------------------------------------
                      number of inconsistent edges connected to a node
----------------------------------------------------------------------*/
extern void
vis_MeshConNumNodeInconEdge(vis_MeshCon* p, Vint id, Vint* numnodeinconedge)
{
    Vint i, j, k;
    Vint in, inoed;
    Vint edid, em[2], nm[2];

    *numnodeinconedge = 0;
    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        if (p->edge[edid].nelem == 2) {
            for (j = 0; j < 2; j++) {
                em[j] = p->edge[edid].el[j];
                for (k = 0; k < 3; k++) {
                    if (p->elem[em[j]].ed[k] == edid) {
                        nm[j] = k;
                        break;
                    }
                }
            }
            if (p->elem[em[0]].no[(nm[0] + 1) % 3] == p->elem[em[1]].no[(nm[1] + 1) % 3]) {
                *numnodeinconedge += 1;
            }
        }
    }
}

/*----------------------------------------------------------------------
                      edges connected to a node queries
----------------------------------------------------------------------*/
extern void
vis_MeshConGetNodeEdge(vis_MeshCon* p, Vint id, Vint* num, Vint noed[])
{
    Vint i;
    Vint in, inoed;

    *num = 0;
    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        noed[*num] = p->noed[inoed].ed[in];
        *num += 1;
    }
}

/*----------------------------------------------------------------------
                      CCW edges starting from given edge
----------------------------------------------------------------------*/
static void
vis_MeshCon_NodeCCWEdge(vis_MeshCon* p, Vint id, Vint edid, Vint* id1, Vint* edid1, Vint* num, Vint noed[])
{
    static Vchar func[] = "vis_MeshCon_NodeCCWEdge";
    Vint i, k;
    Vint nn, edids, elid, elk, pres, ptid;

    if (p->edge[edid].nelem > 2) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "Non-manifold edge, edid= %d", edid);
        return;
    }
    noed[0] = edid;
    *num = 1;
    *edid1 = 0;
    /* now find ccw elem and elk */
    elk = -1;
    for (i = 0; i < p->edge[edid].nelem; i++) {
        elid = p->edge[edid].el[i];
        if (p->patchrestrict) {
            pres = p->elem[elid].pres;
            if (p->gm) {
                vis_MeshConGetElemPres(p->gm, pres, &ptid);
            }
            else {
                ptid = pres;
            }
            if (p->patchrestrict != ptid)
                continue;
        }
        nn = p->elem[elid].nn;
        for (k = 0; k < nn; k++) {
            if (p->elem[elid].no[k] == id) {
                break;
            }
        }
        if (p->elem[elid].ed[k] == edid) {
            elk = k;
            break;
        }
    }
    /* no ccw element, so return */
    if (elk == -1) {
        *num = 0;
        return;
    }
    /* get next edge */
    for (;;) {
        nn = p->elem[elid].nn;
        edids = p->elem[elid].ed[(elk + nn - 1) % nn];
        if (p->edge[edids].nelem > 2) {
            p->ierr = SYS_ERROR_VALUE;
            HANDLEERR1(func, p->ierr, "Non-manifold edge, edid= %d", edids);
            return;
        }
        if (edids == edid)
            break;
        if (elid == p->edge[edids].el[0]) {
            elid = p->edge[edids].el[1];
        }
        else {
            elid = p->edge[edids].el[0];
        }
        if (elid) {
            nn = p->elem[elid].nn;
            for (k = 0; k < nn; k++) {
                if (p->elem[elid].no[k] == id) {
                    elk = k;
                    break;
                }
            }
        }
        noed[*num] = edids;
        *num += 1;
        if (elid == 0) {
            if (p->edge[edids].no[0] == id) {
                *id1 = p->edge[edids].no[1];
            }
            else {
                *id1 = p->edge[edids].no[0];
            }
            *edid1 = edids;
            break;
        }
    }
}

static void
vis_MeshCon_NodeCCWSelEdge(vis_MeshCon* p, Vint id, Vint edid, Vint* num, Vint noed[], Vint* edids)
{
    Vint i, k;
    Vint nn, in, inoed;
    Vint elid, edid1, iccw, itra;
    Vdouble t[3], t1[3], sc, cmax;

    *edids = 0;
    /* tangent to edge */
    vis_MeshConEdgeTangent(p, edid, t);
    if (id == p->edge[edid].no[1]) {
        SCALE3(t, -1.);
    }
    /* search for next available free edge */
    cmax = -2.;
    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid1 = p->noed[inoed].ed[in];
        /* not a free edge */
        if (p->edge[edid1].el[1])
            continue;
        /* must be free edge on ccw side */
        iccw = 0;
        elid = p->edge[edid1].el[0];
        nn = p->elem[elid].nn;
        for (k = 0; k < nn; k++) {
            if (p->elem[elid].no[k] == id && p->elem[elid].ed[k] == edid1) {
                iccw = 1;
                break;
            }
        }
        if (iccw == 0)
            continue;
        /* see if edge is previously traversed */
        itra = 0;
        for (k = 0; k < *num; k++) {
            if (edid1 == noed[k]) {
                itra = 1;
                break;
            }
        }
        if (itra)
            continue;
        /* find tangent */
        vis_MeshConEdgeTangent(p, edid1, t1);
        if (id == p->edge[edid1].no[1]) {
            SCALE3(t1, -1.);
        }
        sc = DOT3(t, t1);
        /* set edge if dot product is greater */
        if (sc > cmax) {
            cmax = sc;
            *edids = edid1;
        }
    }
}

extern void
vis_MeshConGetNodeCCWEdge(vis_MeshCon* p, Vint id, Vint* num, Vint noed[])
{
    static Vchar func[] = "vis_MeshConGetNodeCCWEdge";
    Vint i, k;
    Vint in, inoed, numi;
    Vint nn, edids, edid, elid, pres, ptid, nelem, imatch;
    Vint id1, edid1, edidr;

    *num = 0;
    edids = 0;
    /* search for starting edge */
    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        nelem = p->edge[edid].nelem;
        if (p->patchrestrict) {
            imatch = 0;
            for (k = 0; k < nelem; k++) {
                elid = p->edge[edid].el[k];
                pres = p->elem[elid].pres;
                if (p->gm) {
                    vis_MeshConGetElemPres(p->gm, pres, &ptid);
                }
                else {
                    ptid = pres;
                }
                if (p->patchrestrict == ptid) {
                    imatch = 1;
                    break;
                }
            }
            if (imatch == 0)
                continue;
        }
        else if (nelem > 2) {
            p->ierr = SYS_ERROR_VALUE;
            HANDLEERR1(func, p->ierr, "Non-manifold edge, id= %d", edid);
            return;
        }
        /* set first edge */
        if (edids == 0) {
            edids = edid;
        }
        /* override with possible free edge on ccw side */
        if (p->edge[edid].el[1] == 0) {
            elid = p->edge[edid].el[0];
            nn = p->elem[elid].nn;
            for (k = 0; k < nn; k++) {
                if (p->elem[elid].no[k] == id) {
                    break;
                }
            }
            if (p->elem[elid].ed[k] == edid) {
                edids = edid;
                break;
            }
        }
    }

labelnextelem:;
    /* traverse elements */
    vis_MeshCon_NodeCCWEdge(p, id, edids, &id1, &edid1, &numi, &noed[*num]);
    if (numi == 0) {
        edidr = edids;
        vis_MeshCon_NodeCCWSelEdge(p, id, edidr, num, noed, &edids);
        if (edids == 0)
            return;
        goto labelnextelem;
    }
    *num += numi;
    /* do we have all the edges */
    /* if edid1 == 0 we have the case of a point connecting
       more than one topological disk of triangles */
    if (edid1 && *num != p->node[id].ned) {
        edidr = edid1;
        vis_MeshCon_NodeCCWSelEdge(p, id, edidr, num, noed, &edids);
        if (edids == 0)
            return;
        goto labelnextelem;
    }
}

extern void
vis_MeshConGetNodeCCWEdgeBound(vis_MeshCon* p, Vint id, Vint elid, Vint edid1, Vint edid2, Vint* num, Vint noed[])
{
    static Vchar func[] = "vis_MeshConGetNodeCCWEdgeBound";
    Vint i, j;
    Vint nn;
    Vint istrt, jstrt, istop, jstop;

    /* get edges bound by edid1 and edid2 */
    vis_MeshConGetNodeCCWNMBound(p, id, elid, &nn, p->inoed);
    istrt = 0;
    istop = 0;
    for (j = 0; j < 2 * nn; j++) {
        i = j % nn;
        if (istrt == 0) {
            if (p->inoed[i] == edid1) {
                istrt = 1;
                jstrt = j;
            }
            else {
                continue;
            }
        }
        else {
            if (p->inoed[i] == edid2) {
                istop = 1;
                jstop = j;
                break;
            }
        }
    }
    *num = 0;
    if (istrt == 0 || istop == 0) {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR2(func, p->ierr, "Unbounded id= %d, elid= %d", id, elid);
        return;
    }
    /* load bound edge subset */
    for (j = jstrt; j <= jstop; j++) {
        i = j % nn;
        noed[*num] = p->inoed[i];
        *num += 1;
    }
}

extern void
vis_MeshConGetNodeCCWNextPres(vis_MeshCon* p, Vint id, Vint elid, Vint* pelid, Vint* pelk, Vint* pedid)
{
    Vint i;
    Vint edadj, nn;
    Vint elchk, elkchk;

    *pelid = 0;
    *pelk = 0;
    *pedid = 0;
    /* search CCW */
    elchk = elid;
    for (;;) {
        nn = p->elem[elchk].nn;
        for (i = 0; i < nn; i++) {
            if (p->elem[elchk].no[i] == id) {
                elkchk = (i + nn - 1) % nn;
                break;
            }
        }
        edadj = p->elem[elchk].ed[elkchk];
        if (p->edge[edadj].pres) {
            *pelid = elchk;
            *pelk = elkchk + 1;
            *pedid = edadj;
            break;
        }
        if (p->edge[edadj].pref) {
            *pelid = elchk;
            *pelk = elkchk + 1;
            *pedid = edadj;
            break;
        }
        if (p->edge[edadj].el[0] == elchk) {
            elchk = p->edge[edadj].el[1];
        }
        else {
            elchk = p->edge[edadj].el[0];
        }
        if (elchk == elid) {
            break;
        }
    }
}

extern void
vis_MeshConGetNodeCCWPresBound(vis_MeshCon* p, Vint id, Vint elid, Vint* num, Vint noel[])
{
    static Vchar func[] = "vis_MeshConGetNodeCCWPresBound";
    Vint i;
    Vint edadj, nn;
    Vint elchk, elkchk;
    Vint nchk;
    /* get ccw elements bound by preserved edges
       connected to a given node adjacent to a given element */
    *num = 0;
    /* search right for starting edge */
    nchk = 0;
    elchk = elid;
    for (;;) {
        if (elchk == 0) {
            p->ierr = SYS_ERROR_OPERATION;
            HANDLEERR1(func, p->ierr, "Zero element encountered, elid= %d", elid);
            return;
        }
        if (nchk > MESHCON_MAXNDG) {
            p->ierr = SYS_ERROR_OPERATION;
            HANDLEERR1(func, p->ierr, "Excessive CCW traversal, elid= %d", elid);
            return;
        }
        nchk += 1;
        nn = p->elem[elchk].nn;
        for (i = 0; i < nn; i++) {
            if (p->elem[elchk].no[i] == id) {
                elkchk = i;
                break;
            }
        }
        edadj = p->elem[elchk].ed[elkchk];
        if (p->edge[edadj].pres) {
            break;
        }
        if (p->edge[edadj].pref) {
            break;
        }
        if (p->edge[edadj].el[0] == elchk) {
            elchk = p->edge[edadj].el[1];
        }
        else {
            elchk = p->edge[edadj].el[0];
        }
        if (elchk == elid) {
            break;
        }
    }
    noel[*num] = elchk;
    *num += 1;
    /* traverse ccw from starting element */
    for (;;) {
        nn = p->elem[elchk].nn;
        for (i = 0; i < nn; i++) {
            if (p->elem[elchk].no[i] == id) {
                elkchk = (i + nn - 1) % nn;
                break;
            }
        }
        edadj = p->elem[elchk].ed[elkchk];
        if (p->edge[edadj].pres) {
            break;
        }
        if (p->edge[edadj].pref) {
            break;
        }
        if (p->edge[edadj].el[0] == elchk) {
            elchk = p->edge[edadj].el[1];
        }
        else {
            elchk = p->edge[edadj].el[0];
        }
        if (elchk == noel[0]) {
            break;
        }
        noel[*num] = elchk;
        *num += 1;
    }
}

extern void
vis_MeshConGetNodeCCWNMBound(vis_MeshCon* p, Vint id, Vint elid, Vint* num, Vint noed[])
{
    Vint i;
    Vint edids, edadj, nel, nn;
    Vint elchk, elkchk, elpre, incon;
    /* get ccw edges bound by free, inconsistent
       or non-manifold edges
       connected to a given node adjacent to a given element */
    *num = 0;
    /* search right for starting edge */
    elchk = elid;
    for (;;) {
        nn = p->elem[elchk].nn;
        for (i = 0; i < nn; i++) {
            if (p->elem[elchk].no[i] == id) {
                elkchk = i;
                break;
            }
        }
        edadj = p->elem[elchk].ed[elkchk];
        nel = p->edge[edadj].nelem;
        if (nel != 2) {
            edids = edadj;
            break;
        }
        vis_MeshConEdgeIncon(p, edadj, &incon);
        if (incon) {
            edids = edadj;
            break;
        }
        elpre = elchk;
        if (p->edge[edadj].el[0] == elchk) {
            elchk = p->edge[edadj].el[1];
        }
        else {
            elchk = p->edge[edadj].el[0];
        }
        if (elchk == elid) {
            edids = edadj;
            elchk = elpre;
            break;
        }
    }
    noed[*num] = edids;
    *num += 1;
    /* traverse ccw from starting edge */
    for (;;) {
        nn = p->elem[elchk].nn;
        for (i = 0; i < nn; i++) {
            if (p->elem[elchk].no[i] == id) {
                elkchk = (i + nn - 1) % nn;
                break;
            }
        }
        edadj = p->elem[elchk].ed[elkchk];
        if (edadj == edids)
            break;
        nel = p->edge[edadj].nelem;
        noed[*num] = edadj;
        *num += 1;
        if (nel != 2) {
            break;
        }
        vis_MeshConEdgeIncon(p, edadj, &incon);
        if (incon) {
            break;
        }
        if (p->edge[edadj].el[0] == elchk) {
            elchk = p->edge[edadj].el[1];
        }
        else {
            elchk = p->edge[edadj].el[0];
        }
    }
}

extern void
vis_MeshConGetNodeCCWPresEdgeBound(vis_MeshCon* p, Vint id, Vint elid, Vint* num, Vint noed[])
{
    Vint i;
    Vint edids, edadj, nn;
    Vint elchk, elkchk, elpre;
    /* get two preserved ccw edges which bound area
       connected to a given node adjacent to a given element */
    *num = 0;
    /* search right for starting edge */
    elchk = elid;
    for (;;) {
        nn = p->elem[elchk].nn;
        for (i = 0; i < nn; i++) {
            if (p->elem[elchk].no[i] == id) {
                elkchk = i;
                break;
            }
        }
        edadj = p->elem[elchk].ed[elkchk];
        if (p->edge[edadj].pres) {
            edids = edadj;
            break;
        }
        elpre = elchk;
        if (p->edge[edadj].el[0] == elchk) {
            elchk = p->edge[edadj].el[1];
        }
        else {
            elchk = p->edge[edadj].el[0];
        }
        if (elchk == elid) {
            return;
        }
    }
    noed[*num] = edids;
    *num += 1;
    /* traverse ccw from starting edge */
    for (;;) {
        nn = p->elem[elchk].nn;
        for (i = 0; i < nn; i++) {
            if (p->elem[elchk].no[i] == id) {
                elkchk = (i + nn - 1) % nn;
                break;
            }
        }
        edadj = p->elem[elchk].ed[elkchk];
        if (edadj == edids)
            break;
        if (p->edge[edadj].pres) {
            noed[*num] = edadj;
            *num += 1;
            break;
        }
        if (p->edge[edadj].el[0] == elchk) {
            elchk = p->edge[edadj].el[1];
        }
        else {
            elchk = p->edge[edadj].el[0];
        }
    }
}

/*----------------------------------------------------------------------
                      nodes connected to a node through edges
----------------------------------------------------------------------*/
extern void
vis_MeshConGetNodeNode(vis_MeshCon* p, Vint id, Vint* num, Vint nono[])
{
    Vint i;
    Vint edid;
    Vint in, inoed;

    *num = 0;
    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        if (p->edge[edid].no[0] == id) {
            nono[*num] = p->edge[edid].no[1];
        }
        else {
            nono[*num] = p->edge[edid].no[0];
        }
        *num += 1;
    }
}

extern void
vis_MeshConMatchNodeNode(vis_MeshCon* p, Vint id, Vint idm, Vint* imatch)
{
    Vint i, n;
    Vint edid, nono;
    Vint in, inoed;
    Vint nelem, elid, pres, ptid, imat;
    /* check for two nodes connected by an edge */
    *imatch = 0;
    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        if (p->patchrestrict) {
            imat = 0;
            nelem = p->edge[edid].nelem;
            for (n = 0; n < nelem; n++) {
                elid = p->edge[edid].el[n];
                pres = p->elem[elid].pres;
                if (p->gm) {
                    vis_MeshConGetElemPres(p->gm, pres, &ptid);
                }
                else {
                    ptid = pres;
                }
                if (p->patchrestrict == ptid) {
                    imat = 1;
                    break;
                }
            }
            if (imat == 0)
                continue;
        }
        if (p->edge[edid].no[0] == id) {
            nono = p->edge[edid].no[1];
        }
        else {
            nono = p->edge[edid].no[0];
        }
        if (nono == idm) {
            *imatch = edid;
            return;
        }
    }
}

extern void
vis_MeshConNodeNodeLength(vis_MeshCon* p, Vint id, Vint idm, Vdouble* fl)
{
    Vdouble x[3], xm[3], d[3];

    vis_MeshConGetNode(p, id, x);
    vis_MeshConGetNode(p, idm, xm);
    DIFF3(x, xm, d);
    *fl = MAG3(d);
}

/*----------------------------------------------------------------------
                      merge node
----------------------------------------------------------------------*/
extern void
vis_MeshConCheckMergeNode(vis_MeshCon* p, Vint id, Vint idm, Vint* flag)
{
    Vint i, k, m;
    Vint nel;
    Vint nn, elno[4];
    Vdouble xn[3], vn[3], v[3], xt[3][3], d1[3], d2[3], fl;
    /* merge connected node id to node idm */
    *flag = 1;
    vis_MeshConGetNode(p, idm, xn);
    vis_MeshConGetNodeElem(p, id, &nel, p->inoed1);
    for (i = 0; i < nel; i++) {
        m = p->inoed1[i];
        vis_MeshConGetElemNode(p, m, &nn, elno);
        vis_MeshConFlatNormal(p, m, vn);
        if (nn != 3)
            continue;
        vis_MeshConGetNodes(p, nn, elno, xt);
        for (k = 0; k < 3; k++) {
            if (id == elno[k]) {
                DIFF3(xt[(k + 1) % 3], xn, d1);
                DIFF3(xt[(k + 2) % 3], xn, d2);
                CROSS3(d1, d2, v);
                fl = DOT3(vn, v);
                if (fl <= 0.) {
                    *flag = 0;
                    return;
                }
            }
        }
    }
}

extern void
vis_MeshConMergeNode(vis_MeshCon* p, Vint id, Vint idm)
{
    Vint j, k, m, n;
    Vint kf, kfn, nn, k1;
    Vint in, inoed;
    Vint edid, frid, nel;
    Vint num;
    Vint ide, icoll, eid, elno[3], eled[3];
    /* merge connected node id to node idm */
    /* check for common edge endpoint */
    vis_MeshConGetNodeNode(p, idm, &num, p->inoed);
    /* look through edges connected to id, splice in element */
    icoll = 0;
    elno[0] = id;
    elno[1] = idm;
    inoed = p->node[id].noed;
    in = 0;
    for (j = 0; j < p->node[id].ned; j++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        for (k = 0; k < 2; k++) {
            if (p->edge[edid].no[k] != id)
                continue;
            ide = p->edge[edid].no[1 - k];
            for (n = 0; n < num; n++) {
                if (ide != p->inoed[n])
                    continue;
                elno[2] = ide;
                vis_MeshConAddElem(p, 3, elno, &eid);
                icoll = 1;
                break;
            }
        }
    }
    /* if element patched in merge with edge collapse */
    if (icoll) {
        vis_MeshConGetElem(p, eid, &nn, elno, eled);
        for (k = 0; k < 3; k++) {
            edid = eled[k];
            if ((p->edge[edid].no[0] == id && p->edge[edid].no[1] == idm) ||
                (p->edge[edid].no[1] == id && p->edge[edid].no[0] == idm)) {
                break;
            }
        }
        vis_MeshConSetEdgePres(p, edid, 1);
        vis_MeshConCollapseEdge(p, edid, idm, 0);
        return;
    }
    /* loop through edges and elements attached to id */
    inoed = p->node[id].noed;
    in = 0;
    for (j = 0; j < p->node[id].ned; j++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        nel = p->edge[edid].nelem;
        for (k = 0; k < 2; k++) {
            if (p->edge[edid].no[k] == id) {
                p->edge[edid].no[k] = idm;
                for (kf = 0; kf < nel; kf++) {
                    frid = p->edge[edid].fr[kf];
                    if (frid) {
                        for (kfn = 0; kfn < 2; kfn++) {
                            if (p->frnt[frid].no[kfn] == id) {
                                p->frnt[frid].no[kfn] = idm;
                            }
                        }
                    }
                }
            }
        }
        for (k = 0; k < nel; k++) {
            m = p->edge[edid].el[k];
            if (m) {
                nn = p->elem[m].nn;
                for (k1 = 0; k1 < nn; k1++) {
                    if (p->elem[m].no[k1] == id) {
                        p->elem[m].no[k1] = idm;
                    }
                }
            }
        }
        vis_MeshCon_IncNode(p, idm, edid);
    }
    /* update extended node pres */
    if (p->extendflag == 1 || p->extendflag == 2) {
        if (p->node[id].pres == SYS_NODE || p->node[id].pres == SYS_NONE) {
            if (p->node[idm].pres == SYS_NODE || p->node[idm].pres == SYS_NONE) {
                vis_MeshCon_AppPind(p, &p->node[idm].pind, p->node[id].pind);
            }
            else {
                p->node[idm].pres = p->node[id].pres;
                p->node[idm].pind = p->node[id].pind;
            }
        }
    }
    /* delete id */
    vis_MeshConDelNode(p, id);
}

/*----------------------------------------------------------------------
                      purge unpreserved nodes between two nodes
----------------------------------------------------------------------*/
extern void
vis_MeshConPurgePresEdge(vis_MeshCon* p, Vint noid1, Vint noid2)
{
    Vint i;
    Vint edno[2], ns, nx, ids, idx;
    Vint pres;
    Vdouble x1[3], x2[3], d[3], x[3], d1[3], fl, flmn;
    Vint num, idmn;
    /* find initial edge */
    vis_MeshConGetNode(p, noid1, x1);
    vis_MeshConGetNode(p, noid2, x2);
    DIFF3(x2, x1, d);
    UNIT3(d);
    vis_MeshConNodePresEdge(p, noid1, &num, p->inoed);
    flmn = -2.;
    for (i = 0; i < num; i++) {
        vis_MeshConGetEdgeNode(p, p->inoed[i], edno);
        if (noid1 == edno[0]) {
            vis_MeshConGetNode(p, edno[1], x);
        }
        else {
            vis_MeshConGetNode(p, edno[0], x);
        }
        DIFF3(x, x1, d1);
        UNIT3(d1);
        fl = DOT3(d, d1);
        if (fl > flmn) {
            flmn = fl;
            idmn = p->inoed[i];
        }
    }
    if (flmn < 0.)
        return;

    ns = noid1;
    ids = idmn;
    for (;;) {
        vis_MeshConGetEdgeNode(p, ids, edno);
        if (ns == edno[0]) {
            nx = edno[1];
        }
        else {
            nx = edno[0];
        }
        if (nx == noid2)
            break;
        vis_MeshConGetNodePres(p, nx, &pres);
        if (pres == SYS_NODE)
            break;
        vis_MeshConAdjPresEdge(p, ids, nx, &idx);
        vis_MeshConCollapseEdge(p, ids, ns, 0);
        ids = idx;
    }
}

/*----------------------------------------------------------------------
                      check for node on free edge
----------------------------------------------------------------------*/
extern void
vis_MeshConCheckNodeEdgeFree(vis_MeshCon* p, Vint id, Vint* flag)
{
    Vint i;
    Vint in, inoed;
    Vint edid;

    *flag = 0;
    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        if (p->edge[edid].el[1] == 0) {
            *flag = 1;
            return;
        }
    }
}

/*----------------------------------------------------------------------
                      get quad edge
----------------------------------------------------------------------*/
extern void
vis_MeshConGetEdgeQuad(vis_MeshCon* p, Vint id, Vint iq[4], Vint iqe[4])
{
    static Vchar func[] = "vis_MeshConGetEdgeQuad";
    Vint k;
    Vint edel[2];
    Vint nn, elno[4], eled[4], ea;
    /* get quad nodes about edge */
    /* edge connects iq[0] and iq[2] */
    if (p->edge[id].nelem != 2) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "Non-manifold edge, id= %d", id);
        return;
    }
    edel[0] = p->edge[id].el[0];
    edel[1] = p->edge[id].el[1];
    vis_MeshConGetElem(p, edel[0], &nn, elno, eled);
    if (nn == 4)
        return;
    for (k = 0; k < 3; k++) {
        ea = eled[k];
        if (ea == id) {
            iq[0] = elno[(k + 1) % 3];
            iq[1] = elno[(k + 2) % 3];
            iq[2] = elno[(k + 3) % 3];
            iqe[0] = eled[(k + 1) % 3];
            iqe[1] = eled[(k + 2) % 3];
            break;
        }
    }
    vis_MeshConGetElem(p, edel[1], &nn, elno, eled);
    if (nn == 4)
        return;
    for (k = 0; k < 3; k++) {
        ea = eled[k];
        if (ea == id) {
            iq[3] = elno[(k + 2) % 3];
            iqe[2] = eled[(k + 1) % 3];
            iqe[3] = eled[(k + 2) % 3];
            break;
        }
    }
}

extern void
vis_MeshConGetEdgeQuadNorm(vis_MeshCon* p, Vint id, Vint iq[4], Vint iqe[4], Vdouble vq[4][3])
{
    static Vchar func[] = "vis_MeshConGetEdgeQuadNorm";
    Vint k;
    Vint edel[2];
    Vint nn, elno[4], eled[4], ea;
    Vdouble ve[3][3];
    /* get quad nodes about edge */
    /* edge connects iq[0] and iq[2] */
    if (p->edge[id].nelem != 2) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "Non-manifold edge, id= %d", id);
        return;
    }
    edel[0] = p->edge[id].el[0];
    edel[1] = p->edge[id].el[1];
    vis_MeshConGetElem(p, edel[0], &nn, elno, eled);
    if (nn == 4)
        return;
    vis_MeshConGetElemNorm(p, edel[0], ve);
    for (k = 0; k < 3; k++) {
        ea = eled[k];
        if (ea == id) {
            iq[0] = elno[(k + 1) % 3];
            iq[1] = elno[(k + 2) % 3];
            iq[2] = elno[(k + 3) % 3];
            MOVE3(ve[(k + 1) % 3], vq[0]);
            MOVE3(ve[(k + 2) % 3], vq[1]);
            MOVE3(ve[(k + 3) % 3], vq[2]);
            iqe[0] = eled[(k + 1) % 3];
            iqe[1] = eled[(k + 2) % 3];
            break;
        }
    }
    vis_MeshConGetElem(p, edel[1], &nn, elno, eled);
    if (nn == 4)
        return;
    vis_MeshConGetElemNorm(p, edel[1], ve);
    for (k = 0; k < 3; k++) {
        ea = eled[k];
        if (ea == id) {
            iq[3] = elno[(k + 2) % 3];
            MOVE3(ve[(k + 2) % 3], vq[3]);
            iqe[2] = eled[(k + 1) % 3];
            iqe[3] = eled[(k + 2) % 3];
            break;
        }
    }
}

/*----------------------------------------------------------------------
                      get node elem
----------------------------------------------------------------------*/
extern void
vis_MeshConGetNodeElem(vis_MeshCon* p, Vint id, Vint* num, Vint noel[])
{
    Vint i, j, k;
    Vint edid, elid;
    Vint in, inoed;
    Vint ihfl, flag;
    /* use a hash table for large numbers of edges */
    if (p->node[id].ned < 10) {
        ihfl = 0;
    }
    else {
        ihfl = 1;
        vsy_IntHashClear(p->ih);
    }
    *num = 0;
    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        for (k = 0; k < p->edge[edid].nelem; k++) {
            elid = p->edge[edid].el[k];
            if (elid) {
                if (ihfl == 0) {
                    for (j = 0; j < *num; j++) {
                        if (noel[j] == elid)
                            goto labelskip;
                    }
                    noel[*num] = elid;
                    *num += 1;
                }
                else {
                    vsy_IntHashLookup(p->ih, elid, &flag);
                    if (flag == 0) {
                        vsy_IntHashInsert(p->ih, elid, 1);
                        noel[*num] = elid;
                        *num += 1;
                    }
                }
            labelskip:;
            }
        }
    }
}

extern void
vis_MeshConOneNodeElem(vis_MeshCon* p, Vint id, Vint* eid)
{
    Vint i, k;
    Vint edid, elid;
    Vint in, inoed;

    *eid = 0;
    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        for (k = 0; k < p->edge[edid].nelem; k++) {
            elid = p->edge[edid].el[k];
            if (elid) {
                *eid = elid;
                break;
            }
        }
    }
}

extern void
vis_MeshConSetNodeSize(vis_MeshCon* p, Vint id, Vdouble size)
{
    static Vchar func[] = "vis_MeshConSetNodeSize";

    if (size < 0.) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR2(func, p->ierr, "Negative node size id= %d, size= %e", id, size);
        return;
    }
    p->node[id].size = size;
}

extern void
vis_MeshConGetNodeSize(vis_MeshCon* p, Vint id, Vdouble* size)
{
    Vdouble dsize, fsize;
    /* function sizing */
    if (p->funsiz) {
        p->funsiz(p, p->funobjsiz, p->node[id].x, &fsize);
        if (p->funsizingminflag == 0) {
            *size = fsize;
            return;
        }
    }
    /* size map */
    *size = p->node[id].size;
    if (p->meshsize) {
        vis_MeshSizeSize(p->meshsize, p->node[id].x, &dsize);
        if (dsize != 0.) {
            *size = MIN2(*size, dsize);
        }
    }
    if (p->dmeshsize) {
        vis_MeshSizeSize(p->dmeshsize, p->node[id].x, &dsize);
        if (dsize != 0.) {
            *size = MIN2(*size, dsize);
        }
    }
    if (p->funsiz) {
        if (fsize) {
            *size = MIN2(*size, fsize);
        }
    }
}

extern void
vis_MeshConGetNodeSizes(vis_MeshCon* p, Vint nid, Vint ids[], Vdouble s[])
{
    Vint i;

    for (i = 0; i < nid; i++) {
        vis_MeshConGetNodeSize(p, ids[i], &s[i]);
    }
}

extern void
vis_MeshConSetNodeDist(vis_MeshCon* p, Vint id, Vdouble dist)
{
    p->node[id].dist = dist;
}

extern void
vis_MeshConGetNodeDist(vis_MeshCon* p, Vint id, Vdouble* dist)
{
    *dist = p->node[id].dist;
}

extern void
vis_MeshConSetNodeStat(vis_MeshCon* p, Vint id, Vint stat)
{
    p->node[id].stat = stat;
}

extern void
vis_MeshConGetNodeStat(vis_MeshCon* p, Vint id, Vint* stat)
{
    *stat = p->node[id].stat;
}

extern void
vis_MeshConCountNodeStat(vis_MeshCon* p, Vint* num)
{
    Vint i;

    *num = 0;
    vis_MeshConInitNode(p);
    while (vis_MeshConNextNode(p, &i), i) {
        if (p->node[i].stat)
            *num += 1;
    }
}

extern void
vis_MeshConSetNodeTopo(vis_MeshCon* p, Vint id, Vint topo)
{
    p->node[id].topo = topo;
}

extern void
vis_MeshConGetNodeTopo(vis_MeshCon* p, Vint id, Vint* topo)
{
    *topo = p->node[id].topo;
}

extern void
vis_MeshConSetNodePres(vis_MeshCon* p, Vint id, Vint pres)
{
    p->node[id].pres = pres;
}

extern void
vis_MeshConGetNodePres(vis_MeshCon* p, Vint id, Vint* pres)
{
    *pres = p->node[id].pres;
}

extern void
vis_MeshConSetNodePref(vis_MeshCon* p, Vint id, Vint pref)
{
    p->node[id].pref = pref;
}

extern void
vis_MeshConGetNodePref(vis_MeshCon* p, Vint id, Vint* pref)
{
    *pref = p->node[id].pref;
}

extern void
vis_MeshConNumNodePind(vis_MeshCon* p, Vint id, Vint* num)
{
    if (p->extendflag == 0) {
        *num = 1;
    }
    else if (p->extendflag == 1 || p->extendflag == 2) {
        vis_MeshCon_NumPind(p, p->node[id].pind, num);
    }
}

extern void
vis_MeshConAllNodePind(vis_MeshCon* p, Vint id, Vint* num, Vint pind[])
{
    if (p->extendflag == 0) {
        *num = 1;
        pind[0] = p->node[id].pind;
    }
    else if (p->extendflag == 1 || p->extendflag == 2) {
        vis_MeshCon_AllPind(p, p->node[id].pind, num, pind);
    }
}

extern void
vis_MeshConSetNodePind(vis_MeshCon* p, Vint id, Vint pind)
{
    if (p->extendflag == 0) {
        p->node[id].pind = pind;
    }
    else if (p->extendflag == 1 || p->extendflag == 2) {
        if (p->node[id].pind == 0) {
            vis_MeshCon_AddPind(p, &p->node[id].pind, pind);
        }
        else {
            p->asmval[p->node[id].pind][1] = pind;
        }
    }
}

extern void
vis_MeshConGetNodePind(vis_MeshCon* p, Vint id, Vint* pind)
{
    if (p->extendflag == 0) {
        *pind = p->node[id].pind;
    }
    else if (p->extendflag == 1 || p->extendflag == 2) {
        *pind = p->asmval[p->node[id].pind][1];
    }
}

/*----------------------------------------------------------------------
                      node size
----------------------------------------------------------------------*/
extern void
vis_MeshConNodeSizeElem(vis_MeshCon* p, Vint id, Vdouble x[3], Vdouble* size)
{
    Vint i;
    Vint nn, elno[4];
    Vdouble slope, sn, xe[4][3], fl, s, sdl;

    vis_MeshConGetElemNode(p, id, &nn, elno);
    vis_MeshConGetNodes(p, nn, elno, xe);
    vis_MeshConGetElemSize(p, id, size);
    slope = 2. * (p->growthrate - 1.) / (p->growthrate + 1.);
    for (i = 0; i < nn; i++) {
        vis_MeshConGetNodeSize(p, elno[i], &sn);
        fl = LEN3(x, xe[i]);
        sdl = fl * slope;
        s = sn + sdl;
        *size = MIN2(s, *size);
        s = sn - sdl;
        *size = MAX2(s, *size);
    }
}

extern void
vis_MeshConNodeSizeEdge(vis_MeshCon* p, Vint id, Vdouble x[3], Vdouble* size)
{
    Vint i;
    Vint edno[2];
    Vdouble slope, sn, xe[2][3], fl, s, sdl;

    vis_MeshConGetEdgeNode(p, id, edno);
    vis_MeshConGetNodes(p, 2, edno, xe);
    slope = 2. * (p->growthrate - 1.) / (p->growthrate + 1.);
    vis_MeshConGetEdgeSize(p, id, size);
    for (i = 0; i < 2; i++) {
        vis_MeshConGetNodeSize(p, edno[i], &sn);
        fl = LEN3(x, xe[i]);
        sdl = fl * slope;
        s = sn + sdl;
        *size = MIN2(s, *size);
        s = sn - sdl;
        *size = MAX2(s, *size);
    }
}

/*----------------------------------------------------------------------
                      get node element angle
----------------------------------------------------------------------*/
extern void
vis_MeshConGetNodeElemAngle(vis_MeshCon* p, Vint id, Vint elid, Vdouble* angle)
{
    static Vchar func[] = "vis_MeshConGetNodeElemAngle";
    Vint k;
    Vint nn, elno[4], imat;
    Vdouble xe[4][3];
    Vdouble v[3], da[3], db[3], vc[3];
    Vdouble an, fc, sc;

    vis_MeshConGetElemNode(p, elid, &nn, elno);
    vis_MeshConGetNodes(p, nn, elno, xe);
    imat = 0;
    for (k = 0; k < nn; k++) {
        if (id == elno[k]) {
            imat = 1;
            break;
        }
    }
    if (imat == 0) {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR2(func, p->ierr, "Unfound id= %d, elid= %d", id, elid);
        return;
    }
    DIFF3(xe[(k + 1) % nn], xe[k], da);
    UNIT3(da);
    DIFF3(xe[(k + nn - 1) % nn], xe[k], db);
    UNIT3(db);
    CROSS3(da, db, vc);

    sc = DOT3(da, db);
    vis_MeshConFlatNormal(p, elid, v);
    fc = DOT3(v, vc);

    sc = CLAMP(sc, -1., 1.);
    sc = SEPSTRUN(sc);
    an = acos(sc);
    if (fc < 0.) {
        an = 2. * PI - an;
    }
    an = fmod(an + 2. * PI, 2. * PI);
    *angle = an;
}

/*----------------------------------------------------------------------
                      elem
----------------------------------------------------------------------*/
extern void
vis_MeshConAddElem(vis_MeshCon* p, Vint nn, Vint ix[], Vint* id)
{
    static Vchar func[] = "vis_MeshConAddElem";
    Vint i, n;
    Vint ixe[2];
    Vint edid;
    vis_MeshCon_Elem* pelem;
    Vint pmaxelem;

    /* check to expand storage */
    if (p->numelem + 1 == p->maxelem) {
        pmaxelem = MIN2(20000 + p->maxelem, 2 * p->maxelem);
        pelem = (vis_MeshCon_Elem*)vut_reallocMem(p->elem, (pmaxelem + 1) * sizeof(vis_MeshCon_Elem));
        if (pelem == NULL) {
            p->ierr = VIS_ERROR_MEMORY;
            HANDLEERR0(func, p->ierr, "Realloc elem");
            return;
        }
        p->elem = pelem;
        for (i = p->maxelem; i <= pmaxelem; i++) {
            p->elem[i].prev = 0;
            p->elem[i].next = i + 1;
            p->elem[i].pres = 0;
            p->elem[i].pind = 0;
            p->elem[i].flat = 0;
            p->elem[i].stat = 0;
            p->elem[i].size = 0.;
            p->elem[i].ne = NULL;
        }
        p->maxelem = pmaxelem;
        p->elem[p->maxelem].next = 0;
    }
    /* get next free element */
    n = p->elem[0].next;
    p->elem[0].next = p->elem[n].next;

    /* link in elem */
    p->elem[n].next = p->headelem;
    p->elem[n].prev = 0;
    p->elem[p->headelem].prev = n;
    p->headelem = n;
    /* set number of nodes, edges */
    p->elem[n].nn = nn;
    /* set connected nodes */
    for (i = 0; i < nn; i++) {
        p->elem[n].no[i] = ix[i];
    }
    /* update edges looping through node pairs */
    for (i = 0; i < nn; i++) {
        ixe[0] = ix[i];
        ixe[1] = ix[(i + 1) % nn];
        vis_MeshConFindNodeEdge(p, ixe[0], ixe[1], &edid);
        if (edid == 0) {
            vis_MeshConAddEdge(p, n, ixe, &edid);
            if (p->ierr)
                return;
        }
        else {
            vis_MeshCon_IncEdge(p, edid, n);
        }
        p->elem[n].ed[i] = edid;
    }
    /* add to tree */
    if (p->adt) {
        vis_MeshCon_ADTInsert(p, n);
    }
    /* compute element heap property */
    if (p->elemheap == MESHCON_MINELEMANG) {
        vis_MeshCon_MinAngle(p, n);
    }
    else if (p->elemheap == MESHCON_MAXELEMANG) {
        vis_MeshCon_MaxAngle(p, n);
    }
    else if (p->elemheap == MESHCON_MAXELEMLEN) {
        vis_MeshCon_MaxElemLen(p, n);
    }
    else if (p->elemheap == MESHCON_MINELEMLEN) {
        vis_MeshCon_MinElemLen(p, n);
    }
    else if (p->elemheap == MESHCON_MAXMINELEMANG) {
        vis_MeshCon_MaxMinAngle(p, n);
    }
    *id = n;
    p->numelem += 1;
    if (p->verbose) {
        Vdouble area;
        vis_MeshConElemArea(p, n, &area);
        if (area <= 0.) {
            HANDLEERR2(func, p->ierr, "Zero area element id= %d, area= %e", n, area);
        }
    }
}

extern void
vis_MeshConDelElem(vis_MeshCon* p, Vint id)
{
    static Vchar func[] = "vis_MeshConDelElem";
    Vint i, m, n;
    Vint nx, pr;
    Vint nn;

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    /* delete element */
    nn = p->elem[id].nn;
    /* decrement references to edges */
    for (i = 0; i < nn; i++) {
        m = p->elem[id].ed[i];
        if (m) {
            vis_MeshCon_DecEdge(p, m, id, 1);
        }
    }
    /* place element in free list */
    n = p->elem[0].next;
    p->elem[0].next = id;
    nx = p->elem[id].next;
    pr = p->elem[id].prev;
    p->elem[id].nn = 0;
    p->elem[id].next = n;
    p->elem[id].pres = 0;
    p->elem[id].pind = 0;
    p->elem[id].flat = 0;
    p->elem[id].size = 0.;
    p->elem[id].ne = NULL;
    /* stat */
    if (p->elem[id].stat) {
        p->elem[id].stat = 0;
        p->numelemstat -= 1;
    }
    /* delete element from active list */
    p->elem[nx].prev = pr;
    if (pr == 0) {
        p->headelem = nx;
    }
    else {
        p->elem[pr].next = nx;
    }
    /* search tree */
    if (p->adt) {
        vsy_ADTreeRemove(p->adt, id);
    }
    /* remove from element heap */
    if (p->elemheap) {
        vis_MeshConRemoveElemHeap(p, id);
    }

    p->numelem -= 1;
}

extern void
vis_MeshConGetElem(vis_MeshCon* p, Vint id, Vint* nn, Vint no[], Vint ed[])
{
    static Vchar func[] = "vis_MeshConGetElem";
    Vint k;

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    *nn = p->elem[id].nn;
    for (k = 0; k < *nn; k++) {
        no[k] = p->elem[id].no[k];
        ed[k] = p->elem[id].ed[k];
    }
}

extern void
vis_MeshConGetElemNum(vis_MeshCon* p, Vint id, Vint* nn)
{
    *nn = p->elem[id].nn;
}

extern void
vis_MeshConGetElemNode(vis_MeshCon* p, Vint id, Vint* nn, Vint no[])
{
    static Vchar func[] = "vis_MeshConGetElemNode";
    Vint k;

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    *nn = p->elem[id].nn;
    for (k = 0; k < *nn; k++) {
        no[k] = p->elem[id].no[k];
    }
}

extern void
vis_MeshConGetElemEdge(vis_MeshCon* p, Vint id, Vint* nn, Vint ed[])
{
    static Vchar func[] = "vis_MeshConGetElemEdge";
    Vint k;

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    *nn = p->elem[id].nn;
    for (k = 0; k < *nn; k++) {
        ed[k] = p->elem[id].ed[k];
    }
}

extern void
vis_MeshConSetElemSize(vis_MeshCon* p, Vint id, Vdouble size)
{
    p->elem[id].size = size;
}

extern void
vis_MeshConGetElemSize(vis_MeshCon* p, Vint id, Vdouble* size)
{
    Vint nid;
    Vdouble xel[3][3], xm[3];
    Vdouble dsize, fsize;

    /* compute midpoint */
    if (p->funsiz || p->meshsize || p->dmeshsize) {
        nid = p->elem[id].no[0];
        MOVE3(p->node[nid].x, xel[0]);
        nid = p->elem[id].no[1];
        MOVE3(p->node[nid].x, xel[1]);
        nid = p->elem[id].no[2];
        MOVE3(p->node[nid].x, xel[2]);
        CENT3(xel, xm);
    }
    if (p->funsiz) {
        p->funsiz(p, p->funobjsiz, xm, &fsize);
        if (p->funsizingminflag == 0) {
            *size = fsize;
            return;
        }
    }
    *size = p->elem[id].size;
    if (p->meshsize) {
        vis_MeshSizeSize(p->meshsize, xm, &dsize);
        if (dsize != 0.) {
            *size = MIN2(*size, dsize);
        }
    }
    if (p->dmeshsize) {
        vis_MeshSizeSize(p->dmeshsize, xm, &dsize);
        if (dsize != 0.) {
            *size = MIN2(*size, dsize);
        }
    }
    if (p->funsiz) {
        if (fsize) {
            *size = MIN2(*size, fsize);
        }
    }
}

extern void
vis_MeshConSetElemNorm(vis_MeshCon* p, Vint id, Vdouble ve[3][3])
{
    if (p->elem[id].ne == NULL) {
        vsy_ConcatAdd(p->concat, 3 * 3 * sizeof(Vdouble), (Vchar*)ve);
        vsy_ConcatRef(p->concat, (void**)&p->elem[id].ne);
    }
    MOVE3(ve[0], p->elem[id].ne[0]);
    MOVE3(ve[1], p->elem[id].ne[1]);
    MOVE3(ve[2], p->elem[id].ne[2]);
}

extern void
vis_MeshConIsElemNorm(vis_MeshCon* p, Vint id, Vint* flag)
{
    if (p->elem[id].ne) {
        *flag = 1;
    }
    else {
        *flag = 0;
    }
}

extern void
vis_MeshConGetElemNorm(vis_MeshCon* p, Vint id, Vdouble ve[3][3])
{
    Vint i;
    Vint nn, elno[4];
    Vint pres, tid, nopr, it, teid;
    Vdouble xd[4][3], xg[3];

    if (p->gm) {
        vis_MeshConGetElemNode(p, id, &nn, elno);
        vis_MeshConGetNodes(p, nn, elno, xd);
        vis_MeshConGetElemPres(p, id, &pres);
        for (i = 0; i < nn; i++) {
            vis_MeshConGetNodePres(p, elno[i], &nopr);
            if (nopr == SYS_FACE) {
                vis_MeshConGetNodePind(p, elno[i], &it);
            }
            else {
                it = pres;
            }
            vis_MeshConProject(p->gm, it, xd[i], &tid, &teid, xg);
            vis_MeshConElemNorm(p->gm, tid, xg, ve[i]);
        }
    }
    else if (p->elem[id].ne != NULL) {
        MOVE3(p->elem[id].ne[0], ve[0]);
        MOVE3(p->elem[id].ne[1], ve[1]);
        MOVE3(p->elem[id].ne[2], ve[2]);
    }
}

extern void
vis_MeshConSetEdgeTang(vis_MeshCon* p, Vint id, Vdouble ve[2][3])
{
    if (p->edge[id].ns == NULL) {
        vsy_ConcatAdd(p->concat, 2 * 3 * sizeof(Vdouble), (Vchar*)ve);
        vsy_ConcatRef(p->concat, (void**)&p->edge[id].ns);
    }
    MOVE3(ve[0], p->edge[id].ns[0]);
    MOVE3(ve[1], p->edge[id].ns[1]);
}

extern void
vis_MeshConIsEdgeTang(vis_MeshCon* p, Vint id, Vint* flag)
{
    if (p->edge[id].ns) {
        *flag = 1;
    }
    else {
        *flag = 0;
    }
}

extern void
vis_MeshConGetEdgeTang(vis_MeshCon* p, Vint id, Vdouble ve[2][3])
{
    Vint i;
    Vint pres, edno[2], it;
    Vdouble xed[2][3], xp[3];

    if (p->gm) {
        vis_MeshConGetEdgePres(p, id, &pres);
        vis_MeshConGetEdgeNode(p, id, edno);
        vis_MeshConGetNodes(p, 2, edno, xed);
        if (pres) {
            for (i = 0; i < 2; i++) {
                vis_MeshConProjectEdge(p->gm, pres, xed[i], &it, xp);
                vis_MeshConEdgeTang(p->gm, it, xp, ve[i]);
            }
        }
        else {
            vis_MeshConEdgeTangent(p, id, ve[0]);
            MOVE3(ve[0], ve[1]);
        }
    }
    else if (p->edge[id].ns) {
        MOVE3(p->edge[id].ns[0], ve[0]);
        MOVE3(p->edge[id].ns[1], ve[1]);
    }
    else {
        vis_MeshConEdgeTangent(p, id, ve[0]);
        MOVE3(ve[0], ve[1]);
    }
}

extern void
vis_MeshConEdgeTang(vis_MeshCon* p, Vint id, Vdouble xp[3], Vdouble ve[3])
{
    Vint edno[2], cent, npts;
    Vdouble xd[3][3], r, xpd[3], h[3];
    Vint ierr;

    if (p->edge[id].pres == 0 || p->edge[id].ns == NULL) {
        vis_MeshConEdgeTangent(p, id, ve);
        return;
    }
    vis_MeshConGetEdgeNode(p, id, edno);
    vis_MeshConGetNode(p, edno[0], xd[0]);
    vis_MeshConGetEdgeCent(p, id, &cent);
    if (cent) {
        npts = 3;
        vis_MeshConGetNode(p, cent, xd[1]);
        vis_MeshConGetNode(p, edno[1], xd[2]);
    }
    else {
        npts = 2;
        vis_MeshConGetNode(p, edno[1], xd[1]);
    }
    if (npts == 2) {
        vis_invertNCLindv(xd, xp, &r, xpd, &ierr);
    }
    else {
        vis_invertNCLinPardv(xd, xp, &r, xpd, &ierr);
        if (ierr) {
            vis_invertNCLindv(xd, xp, &r, xpd, &ierr);
        }
    }
    vis_shapeLinLagdv(1, npts, r, h, NULL);
    vml_multMatrix3d(npts, p->edge[id].ns, h, ve);
}

extern void
vis_MeshConEdgeElemNode(vis_MeshCon* p, Vint edid, Vint elid, Vint edelno[2])
{
    Vint k;
    Vint nn;

    nn = p->elem[elid].nn;
    for (k = 0; k < nn; k++) {
        if (p->elem[elid].ed[k] == edid) {
            break;
        }
    }
    edelno[0] = p->elem[elid].no[k];
    edelno[1] = p->elem[elid].no[(k + 1) % nn];
}

extern void
vis_MeshConSetElemNodeNorm(vis_MeshCon* p, Vint id, Vint noid, Vdouble ve[3])
{
    Vint k;
    /* update single element node normal */
    for (k = 0; k < 3; k++) {
        if (noid == p->elem[id].no[k]) {
            MOVE3(ve, p->elem[id].ne[k]);
            break;
        }
    }
}

extern void
vis_MeshConSetElemPres(vis_MeshCon* p, Vint id, Vint pres)
{
    p->elem[id].pres = pres;
    vsy_IntVecSet(p->ivel, pres, id);
}

extern void
vis_MeshConGetElemPres(vis_MeshCon* p, Vint id, Vint* pres)
{
    *pres = p->elem[id].pres;
}

extern void
vis_MeshConGetPresElem(vis_MeshCon* p, Vint pres, Vint* id)
{
    vsy_IntVecGet(p->ivel, pres, id);
}

extern void
vis_MeshConSetElemPind(vis_MeshCon* p, Vint id, Vint pind)
{
    p->elem[id].pind = pind;
}

extern void
vis_MeshConGetElemPind(vis_MeshCon* p, Vint id, Vint* pind)
{
    *pind = p->elem[id].pind;
}

extern void
vis_MeshConSetElemFlat(vis_MeshCon* p, Vint id, Vint flat)
{
    p->elem[id].flat = flat;
}

extern void
vis_MeshConGetElemFlat(vis_MeshCon* p, Vint id, Vint* flat)
{
    *flat = p->elem[id].flat;
}

extern void
vis_MeshConNumElemStat(vis_MeshCon* p, Vint* numstat)
{
    *numstat = p->numelemstat;
}

extern void
vis_MeshConSetElemStat(vis_MeshCon* p, Vint id, Vint stat)
{
    static Vchar func[] = "vis_MeshConSetElemStat";
    Vint i;
    Vint in;

    if (id == 0) {
        if (stat) {
            p->ierr = VIS_ERROR_OPERATION;
            HANDLEERR2(func, p->ierr, "id= %d, stat= %d", id, stat);
            return;
        }
        p->elem[0].stat = 0;
        for (i = 0; i < p->maxelemstat; i++) {
            vsy_IntVecGet(p->est, i, &in);
            p->elem[in].stat = 0;
        }
        p->numelemstat = 0;
        p->maxelemstat = 0;
    }
    else {
        if (p->elem[id].stat == stat) {
            return;
        }
        if (stat) {
            p->numelemstat += 1;
        }
        else {
            p->numelemstat -= 1;
        }
        vsy_IntVecSet(p->est, p->maxelemstat++, id);
        p->elem[id].stat = stat;
    }
}

extern void
vis_MeshConGetElemStat(vis_MeshCon* p, Vint id, Vint* stat)
{
    *stat = p->elem[id].stat;
}

extern void
vis_MeshConStatLastFormElem(vis_MeshCon* p, Vint stat)
{
    vis_MeshConSetElemStat(p, p->lastformelem, stat);
}

extern void
vis_MeshConStatLastDiagElem(vis_MeshCon* p, Vint stat)
{
    vis_MeshConSetElemStat(p, p->lastdiagelem[0], stat);
    vis_MeshConSetElemStat(p, p->lastdiagelem[1], stat);
}

extern void
vis_MeshConSplitElem(vis_MeshCon* p, Vint id, Vint noid)
{
    Vint i, k, m;
    Vint in[3], ed[3], fr[3], frid, nel, centflag;
    Vint ix[3];
    Vdouble xp[3], xt[3][3], vn[3], ve[3][3], ven[3][3], xc[3];
    Vdouble r[3], h[3];
    Vint normflag, ierr;
    Vint pres, pind, flat, nocn;
    Vdouble size;

    p->nsplitelem += 1;
    centflag = 0;
    for (k = 0; k < 3; k++) {
        in[k] = p->elem[id].no[k];
        ed[k] = p->elem[id].ed[k];
        if (p->edge[ed[k]].cent)
            centflag = 1;
        fr[k] = 0;
        nel = p->edge[ed[k]].nelem;
        for (i = 0; i < nel; i++) {
            frid = p->edge[ed[k]].fr[i];
            if (frid) {
                if (p->frnt[frid].elid == id) {
                    fr[k] = frid;
                }
            }
        }
    }
    /* compute normal at new node if necessary */
    normflag = 0;
    if (p->normalflag && p->elem[id].ne != NULL) {
        for (k = 0; k < 3; k++) {
            vis_MeshConGetNode(p, in[k], xt[k]);
            MOVE3(p->elem[id].ne[k], ve[k]);
        }
        vis_invertNCTridv(xt, p->node[noid].x, r, xp, &ierr);
        if (ierr) {
            vis_centNCdv(VIS_SHAPETRI, r);
        }
        vis_shapeTridv(1, r, h, NULL);
        vml_multMatrix3d(3, ve, h, vn);
        UNIT3(vn);
        normflag = 1;
    }
    pres = p->elem[id].pres;
    pind = p->elem[id].pind;
    flat = p->elem[id].flat;
    size = p->elem[id].size;

    /* add new elements */
    for (k = 0; k < 3; k++) {
        ix[0] = in[k];
        ix[1] = in[(k + 1) % 3];
        ix[2] = noid;
        vis_MeshConAddElem(p, 3, ix, &m);
        if (p->ierr)
            return;
        vis_MeshConSetElemPres(p, m, pres);
        p->elem[m].pind = pind;
        p->elem[m].flat = flat;
        p->elem[m].size = size;
        if (normflag) {
            MOVE3(ve[k], ven[0]);
            MOVE3(ve[(k + 1) % 3], ven[1]);
            MOVE3(vn, ven[2]);
            vsy_ConcatAdd(p->concat, 3 * 3 * sizeof(Vdouble), (Vchar*)ven);
            vsy_ConcatRef(p->concat, (void**)&p->elem[m].ne);
        }
        if (centflag) {
            MID3(p->node[noid].x, p->node[ix[0]].x, xp);
            vis_MeshConProjectOneTri(p, id, xp, r, xc, &ierr);
            vis_MeshConAddNode(p, xc, &nocn);
            p->edge[p->elem[m].ed[2]].cent = nocn;
        }
        if (fr[k]) {
            nel = p->edge[ed[k]].nelem;
            for (i = 0; i < nel; i++) {
                if (p->edge[ed[k]].el[i] == m) {
                    p->edge[ed[k]].fr[i] = fr[k];
                }
            }
            p->frnt[fr[k]].elid = m;
            p->frnt[fr[k]].elk = 0;
        }
    }
    /* delete parent element */
    vis_MeshConDelElem(p, id);
}

extern void
vis_MeshConCheckDiagElem(vis_MeshCon* p, Vint id, Vint noid, Vint* flag)
{
    Vint k;
    Vint kn, kk;
    Vint in[4];
    Vdouble x[4][3];
    Vdouble d1[3], d2[3], d3[3], c1[3], c2[3], fl;
    Vint imatch;

    *flag = 1;
    /* must be quad */
    if (p->elem[id].nn != 4) {
        *flag = 0;
        return;
    }
    for (k = 0; k < 4; k++) {
        in[k] = p->elem[id].no[k];
        MOVE3(p->node[in[k]].x, x[k]);
        if (noid == in[k])
            kn = k;
    }
    /* new edge cannot be edge of pasted triangle */
    vis_MeshConFindNodeEdge(p, noid, in[(kn + 2) % 4], &imatch);
    if (imatch) {
        *flag = 0;
        return;
    }
    kk = (kn + 1) % 4;
    DIFF3(x[kk], x[kn], d1);
    kk = (kn + 2) % 4;
    DIFF3(x[kk], x[kn], d2);
    kk = (kn + 3) % 4;
    DIFF3(x[kk], x[kn], d3);
    CROSS3(d1, d2, c1);
    CROSS3(d2, d3, c2);
    fl = DOT3(c1, c2);
    if (fl <= 0.) {
        *flag = 0;
    }
}

extern void
vis_MeshConDiagElem(vis_MeshCon* p, Vint id, Vint noid)
{
    static Vchar func[] = "vis_MeshConDiagElem";
    Vint k, kn, m;
    Vint in[4], ix[3];
    Vint pres, pind, flat;
    Vdouble size;
    Vint edpr[4], edpd[4], edpf[4];
    Vint flag;

    if (p->verbose) {
        vis_MeshConCheckDiagElem(p, id, noid, &flag);
        if (flag == 0) {
            HANDLEERR1(func, p->ierr, "improper quad diag, id= %d", id);
        }
    }
    /* convert a quad to two triangles */
    if (p->elem[id].nn != 4) {
        p->ierr = VIS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    for (k = 0; k < 4; k++) {
        in[k] = p->elem[id].no[k];
        if (noid == in[k])
            kn = k;
    }
    pres = p->elem[id].pres;
    pind = p->elem[id].pind;
    flat = p->elem[id].flat;
    size = p->elem[id].size;
    for (k = 0; k < 4; k++) {
        edpr[k] = p->edge[p->elem[id].ed[k]].pres;
        edpf[k] = p->edge[p->elem[id].ed[k]].pref;
        edpd[k] = p->edge[p->elem[id].ed[k]].pind;
    }

    vis_MeshConDelElem(p, id);

    ix[0] = noid;
    ix[1] = in[(kn + 1) % 4];
    ix[2] = in[(kn + 2) % 4];
    vis_MeshConAddElem(p, 3, ix, &m);
    p->lastdiagelem[0] = m;
    vis_MeshConSetElemPres(p, m, pres);
    p->elem[m].pind = pind;
    p->elem[m].flat = flat;
    p->elem[m].size = size;
    vis_MeshConSetEdgePres(p, p->elem[m].ed[0], edpr[kn]);
    vis_MeshConSetEdgePres(p, p->elem[m].ed[1], edpr[(kn + 1) % 4]);
    p->edge[p->elem[m].ed[0]].pref = edpf[kn];
    p->edge[p->elem[m].ed[1]].pref = edpf[(kn + 1) % 4];
    p->edge[p->elem[m].ed[0]].pind = edpd[kn];
    p->edge[p->elem[m].ed[1]].pind = edpd[(kn + 1) % 4];

    ix[0] = noid;
    ix[1] = in[(kn + 2) % 4];
    ix[2] = in[(kn + 3) % 4];
    vis_MeshConAddElem(p, 3, ix, &m);
    p->lastdiagelem[1] = m;
    vis_MeshConSetElemPres(p, m, pres);
    p->elem[m].pind = pind;
    p->elem[m].flat = flat;
    p->elem[m].size = size;
    vis_MeshConSetEdgePres(p, p->elem[m].ed[1], edpr[(kn + 2) % 4]);
    vis_MeshConSetEdgePres(p, p->elem[m].ed[2], edpr[(kn + 3) % 4]);
    p->edge[p->elem[m].ed[1]].pref = edpf[(kn + 2) % 4];
    p->edge[p->elem[m].ed[2]].pref = edpf[(kn + 3) % 4];
    p->edge[p->elem[m].ed[1]].pind = edpd[(kn + 2) % 4];
    p->edge[p->elem[m].ed[2]].pind = edpd[(kn + 3) % 4];
}

extern void
vis_MeshConGetLeftElem(vis_MeshCon* p, Vint noid, Vint edid, Vint* elid, Vint* elk)
{
    static Vchar func[] = "vis_MeshConGetLeftElem";
    Vint i, k;
    Vint el, nn, pres, ptid;

    if (p->patchrestrict == 0) {
        if (p->edge[edid].nelem > 2) {
            p->ierr = SYS_ERROR_VALUE;
            HANDLEERR1(func, p->ierr, "Non-manifold edge, id= %d", edid);
            return;
        }
    }
    *elid = 0;
    *elk = 0;
    for (i = 0; i < p->edge[edid].nelem; i++) {
        el = p->edge[edid].el[i];
        if (p->patchrestrict) {
            pres = p->elem[el].pres;
            if (p->gm) {
                vis_MeshConGetElemPres(p->gm, pres, &ptid);
            }
            else {
                ptid = pres;
            }
            if (p->patchrestrict != ptid)
                continue;
        }
        nn = p->elem[el].nn;
        for (k = 0; k < nn; k++) {
            if (noid == p->elem[el].no[k] && edid == p->elem[el].ed[k]) {
                *elid = el;
                *elk = k + 1;
                return;
            }
        }
    }
}

/*----------------------------------------------------------------------
                      initialize search tree
----------------------------------------------------------------------*/
extern void
vis_MeshConInitTree(vis_MeshCon* p)
{
    Vint m;
    Vdouble extent[2][3], d[3], fl, fac;

    p->adt = vsy_ADTreeBegin();
    vis_MeshConExtent(p, extent);
    DIFF3(extent[1], extent[0], d);
    fl = MAG3(d);
    fac = .1 * fl;
    SUB3(extent[0], fac, d, extent[0]);
    ADD3(extent[1], fac, d, extent[1]);
    vsy_ADTreeDef(p->adt, ADTREE_EXTENT, p->maxelem, extent[0], extent[1]);
    vis_MeshConInitElem(p);
    while (vis_MeshConNextElem(p, &m), m) {
        vis_MeshCon_ADTInsert(p, m);
    }
    /* initial search tolerance of .00001 of extent */
    p->adttol = MAG3(d);
    p->adttol *= .00001;
    vsy_ADTreeSetParamd(p->adt, ADTREE_TOLERANCE, p->adttol);
}

extern void
vis_MeshConTermTree(vis_MeshCon* p)
{
    if (p->adt) {
        vsy_ADTreeEnd(p->adt);
    }
    p->adt = NULL;
}

/*----------------------------------------------------------------------
                      set number of geometry faces
----------------------------------------------------------------------*/
extern void
vis_MeshConSetNumGeomFace(vis_MeshCon* p, Vint numgeomface)
{
    p->numgeomface = numgeomface;
    if (p->geomfaceinternal) {
        vut_freeMem(p->geomfaceinternal);
    }
    p->geomfaceinternal = (Vint*)vut_mallocMem((p->numgeomface + 1) * sizeof(Vint));
    vut_ZeroI(p->geomfaceinternal, p->numgeomface + 1);
}

extern void
vis_MeshConGetNumGeomFace(vis_MeshCon* p, Vint* numgeomface)
{
    *numgeomface = p->numgeomface;
}

/*----------------------------------------------------------------------
                      initialize geometry faces
----------------------------------------------------------------------*/
extern void
vis_MeshConInitGeomFace(vis_MeshCon* p)
{
    Vint id, pres, pid;
    Vint maxnum;

    p->geomfaceelemhint = (Vint*)vut_mallocMem((p->numgeomface + 1) * sizeof(Vint));
    vut_ZeroI(p->geomfaceelemhint, p->numgeomface + 1);
    p->geomfaceelemnum = (Vint*)vut_mallocMem((p->numgeomface + 1) * sizeof(Vint));
    vut_ZeroI(p->geomfaceelemnum, p->numgeomface + 1);
    /* loop through all elements */
    maxnum = 0;
    for (id = p->headelem; id != 0; id = p->elem[id].next) {
        if (p->gm) {
            vis_MeshConGetElemPres(p, id, &pres);
            if (pres) {
                vis_MeshConGetElemPres(p->gm, pres, &pid);
            }
            else {
                pid = 0;
            }
        }
        else {
            vis_MeshConGetElemPres(p, id, &pid);
        }
        p->geomfaceelemhint[pid] = id;
        p->geomfaceelemnum[pid] += 1;
        maxnum = MAX2(maxnum, p->geomfaceelemnum[pid]);
    }
    p->geomfacemapmesh = (Vint*)vut_mallocMem((p->numgeomface + 1) * sizeof(Vint));
    vut_ZeroI(p->geomfacemapmesh, p->numgeomface + 1);
    p->geomfacestk = (Vint*)vut_mallocMem((maxnum + 1) * sizeof(Vint));
    maxnum = MAX2(p->maxnode, p->maxelem);
    p->geomfacecan = (Vchar*)vut_mallocMem((maxnum + 1) * sizeof(Vchar));
    vut_ZeroC(p->geomfacecan, maxnum + 1);
}

extern void
vis_MeshConTermGeomFace(vis_MeshCon* p)
{
    if (p->geomfaceelemhint) {
        vut_freeMem(p->geomfaceelemhint);
        p->geomfaceelemhint = NULL;
    }
    if (p->geomfaceelemnum) {
        vut_freeMem(p->geomfaceelemnum);
        p->geomfaceelemnum = NULL;
    }
    if (p->geomfacemapmesh) {
        vut_freeMem(p->geomfacemapmesh);
        p->geomfacemapmesh = NULL;
    }
    if (p->geomfacecan) {
        vut_freeMem(p->geomfacecan);
        p->geomfacecan = NULL;
    }
    if (p->geomfacestk) {
        vut_freeMem(p->geomfacestk);
        p->geomfacestk = NULL;
    }
}

/*----------------------------------------------------------------------
                      geometry face elements
----------------------------------------------------------------------*/
extern void
vis_MeshConGeomFaceNodeElem(vis_MeshCon* p, Vint geomface, vis_IdTran* idtrann, vis_IdTran* idtrane)
{
    Vint i, k;
    Vint id, edid, elid, noid, elpr;
    Vint numstk;
    Vint numnp, numel;
    /* elems */
    /* seed the stack */
    vis_IdTranDef(idtrane, p->geomfaceelemnum[geomface]);
    id = p->geomfaceelemhint[geomface];
    numel = 0;
    numstk = 0;
    if (id) {
        p->geomfacecan[id] = 1;
        p->geomfacestk[numstk++] = id;
    }
    /* processs stack */
    while (numstk) {
        id = p->geomfacestk[--numstk];
        vis_IdTranSetId(idtrane, ++numel, id);
        /* loop through edges */
        for (k = 0; k < 3; k++) {
            edid = p->elem[id].ed[k];
            if (p->edge[edid].nelem == 1)
                continue;
            for (i = 0; i < p->edge[edid].nelem; i++) {
                if (p->edge[edid].el[i] == id)
                    continue;
                elid = p->edge[edid].el[i];
                if (p->gm) {
                    elpr = p->elem[elid].pres;
                    if (p->gm->elem[elpr].pres != geomface)
                        continue;
                }
                else {
                    if (p->elem[elid].pres != geomface)
                        continue;
                }
                if (p->geomfacecan[elid])
                    continue;
                p->geomfacestk[numstk++] = elid;
                p->geomfacecan[elid] = 1;
            }
        }
    }
    /* zero cancellation */
    for (i = 1; i <= numel; i++) {
        vis_IdTranGetId(idtrane, i, &id);
        p->geomfacecan[id] = 0;
    }
    /* nodes */
    if (idtrann) {
        numnp = 0;
        vis_IdTranDef(idtrann, 0);
        for (i = 1; i <= numel; i++) {
            vis_IdTranGetId(idtrane, i, &id);
            for (k = 0; k < 3; k++) {
                noid = p->elem[id].no[k];
                if (p->geomfacecan[noid])
                    continue;
                p->geomfacecan[noid] = 1;
                vis_IdTranSetId(idtrann, ++numnp, noid);
            }
        }
        /* zero cancellation */
        for (i = 1; i <= numnp; i++) {
            vis_IdTranGetId(idtrann, i, &id);
            p->geomfacecan[id] = 0;
        }
    }
}

/*----------------------------------------------------------------------
                      get geometry face hint
----------------------------------------------------------------------*/
extern void
vis_MeshConGetGeomFaceElemHint(vis_MeshCon* p, Vint geomface, Vint* id)
{
    static Vchar func[] = "vis_MeshConGetGeomFaceElemHint";

    if (geomface < 1 || geomface > p->numgeomface) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "geomface= %d", geomface);
        return;
    }
    *id = p->geomfaceelemhint[geomface];
}

/*----------------------------------------------------------------------
                      get geometry face index
----------------------------------------------------------------------*/
extern void
vis_MeshConGetElemGeomFace(vis_MeshCon* p, Vint id, Vint* geomface)
{
    Vint pres;
    /* mesh elem pointing to geometry elem */
    if (p->gm) {
        vis_MeshConGetElemPres(p, id, &pres);
        vis_MeshConGetElemPres(p->gm, pres, geomface);
        /* geometry elem */
    }
    else {
        vis_MeshConGetElemPres(p, id, geomface);
    }
}

/*----------------------------------------------------------------------
                      set, get geometry face internal flag
----------------------------------------------------------------------*/
extern void
vis_MeshConSetGeomFaceInternal(vis_MeshCon* p, Vint geomface, Vint internal)
{
    p->geomfaceinternal[geomface] = internal;
}

extern void
vis_MeshConGetGeomFaceInternal(vis_MeshCon* p, Vint geomface, Vint* internal)
{
    *internal = p->geomfaceinternal[geomface];
}

/*----------------------------------------------------------------------
                      set, get geometry face map mesh
----------------------------------------------------------------------*/
extern void
vis_MeshConSetGeomFaceMapMesh(vis_MeshCon* p, Vint geomface, Vint mapmesh)
{
    p->geomfacemapmesh[geomface] = mapmesh;
}

extern void
vis_MeshConGetGeomFaceMapMesh(vis_MeshCon* p, Vint geomface, Vint* mapmesh)
{
    *mapmesh = p->geomfacemapmesh[geomface];
}

/*----------------------------------------------------------------------
                      get adjacent element
----------------------------------------------------------------------*/
extern void
vis_MeshConGetAdjElem(vis_MeshCon* p, Vint id, Vint no, Vint* elid)
{
    static Vchar func[] = "vis_MeshConGetAdjElem";
    Vint edid;

    edid = p->elem[id].ed[no - 1];
    if (p->edge[edid].nelem > 2) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR2(func, p->ierr, "Non-manifold edge, id= %d, no= %d", id, no);
        return;
    }
    if (p->edge[edid].el[0] == id) {
        *elid = p->edge[edid].el[1];
    }
    else {
        *elid = p->edge[edid].el[0];
    }
}

/*----------------------------------------------------------------------
                      find edge given nodes
----------------------------------------------------------------------*/
extern void
vis_MeshConFindNodeEdge(vis_MeshCon* p, Vint noid1, Vint noid2, Vint* edid)
{
    Vint i;
    Vint in, inoed, id;
    /* find edge, do not patch restrict */
    *edid = 0;
    inoed = p->node[noid1].noed;
    in = 0;
    for (i = 0; i < p->node[noid1].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        id = p->noed[inoed].ed[in];
        if ((noid1 == p->edge[id].no[0] && noid2 == p->edge[id].no[1]) ||
            (noid1 == p->edge[id].no[1] && noid2 == p->edge[id].no[0])) {
            *edid = id;
            return;
        }
    }
}

/*----------------------------------------------------------------------
                      find best
----------------------------------------------------------------------*/
extern void
vis_MeshConBestNodePresElem(vis_MeshCon* p, Vint noid, Vint pres, Vdouble x[3], Vint* elid)
{
    Vint i;
    Vint nelix, epres, ptid, eid, elidmin;
    Vdouble fl, flmin, xp[3], xel[3][3];

    *elid = 0;
    if (p->gm == NULL) {
        return;
    }
    elidmin = 0;
    vis_MeshConGetNodeElem(p, noid, &nelix, p->inoed);
    for (i = 0; i < nelix; i++) {
        eid = p->inoed[i];
        epres = p->elem[eid].pres;
        vis_MeshConGetElemPres(p->gm, epres, &ptid);
        if (pres != ptid)
            continue;
        vis_MeshConGetNodes(p, 3, p->elem[eid].no, xel);
        CENT3(xel, xp);
        fl = LEN3(x, xp);
        if (elidmin == 0) {
            elidmin = eid;
            flmin = fl;
        }
        else if (fl < flmin) {
            elidmin = eid;
            flmin = fl;
        }
    }
    *elid = elidmin;
}

extern void
vis_MeshConFindEdgePresElem(vis_MeshCon* p, Vint edid, Vint pres, Vint* elid)
{
    Vint i;
    Vint num, epres, ptid, eid;

    *elid = 0;
    if (p->gm == NULL) {
        return;
    }
    vis_MeshConNumEdgeElem(p, edid, &num);
    for (i = 1; i <= num; i++) {
        vis_MeshConIthEdgeElem(p, edid, i, &eid);
        epres = p->elem[eid].pres;
        vis_MeshConGetElemPres(p->gm, epres, &ptid);
        if (pres == ptid) {
            *elid = eid;
            return;
        }
    }
}

/*----------------------------------------------------------------------
                      form element
----------------------------------------------------------------------*/
extern void
vis_MeshConCheckFormElem(vis_MeshCon* p, Vint nn, Vint no[], Vint ed[], Vint* flag)
{
    Vint id, ik;
    Vint nep, ned, eld[MESHCON_MAXNDG], nnd, nod[MESHCON_MAXNDG];
    Vint frfl;

    *flag = 1;
    vis_MeshConGetLeftElem(p, no[0], ed[0], &id, &ik);
    if (p->elem[id].nn == 4) {
        *flag = 0;
        return;
    }

    eld[0] = id;
    nep = 0;
    ned = 1;
    nnd = 0;
    for (;;) {
        vis_MeshCon_FormElem1(p, nn, no, ed, eld[nep], &ned, eld, &nnd, nod, &frfl);
        if (frfl) {
            *flag = 0;
            return;
        }
        nep += 1;
        if (nep == ned)
            break;
    }
}

extern void
vis_MeshConCheckInvertFormElem(vis_MeshCon* p, Vint nn, Vint no[], Vdouble v[3], Vdouble* metric)
{
    Vdouble xe[4][3];

    vis_MeshConGetNodes(p, nn, no, xe);
    if (nn == 3) {
        vis_computeMetricTriangle(v, xe, metric);
    }
    else {
        vis_computeMetricQuad(v, xe, metric);
    }
}

extern void
vis_MeshConFormElem(vis_MeshCon* p, Vint nn, Vint no[], Vint ed[])
{
    static Vchar func[] = "vis_MeshConFormElem";
    Vint i, j;
    Vint newid;
    Vint pres, pind, flat, ptid;
    Vdouble size;
    Vint nel, nep, ned, eld[MESHCON_MAXNDG], nnd, nod[MESHCON_MAXNDG];
    Vint edid, edpr[4], edpd[4], edpf[4];
    Vdouble edsz[4];
    Vint id, ik;
    Vint frfl;
    Vint idt, ikt;
    Vint edfr[4][MESHCON_MAXNMT], edfrup[4];
    Vint nelem0, elid;

    /* find a manifold edge and get left element */
    id = 0;
    for (i = 0; i < nn; i++) {
        if (p->edge[ed[i]].nelem <= 2) {
            vis_MeshConGetLeftElem(p, no[i], ed[i], &id, &ik);
            break;
        }
    }
    /* no nonmanifold edge, search for common elem pres */
    if (id == 0) {
        if (p->patchrestrict == 0 || p->gm == NULL) {
            p->ierr = VIS_ERROR_OPERATION;
            HANDLEERR0(func, p->ierr, "Quad element no patch restriction");
            return;
        }
        nelem0 = p->edge[ed[0]].nelem;
        for (j = 0; j < nelem0; j++) {
            elid = p->edge[ed[0]].el[j];
            pres = p->elem[elid].pres;
            vis_MeshConGetElemPres(p->gm, pres, &ptid);
            if (p->patchrestrict == ptid) {
                id = elid;
                break;
            }
        }
    }
    if (p->elem[id].nn == 4) {
        p->ierr = VIS_ERROR_OPERATION;
        HANDLEERR0(func, p->ierr, "Quad element internal to element");
        return;
    }
    pres = p->elem[id].pres;
    pind = p->elem[id].pind;
    flat = p->elem[id].flat;
    size = p->elem[id].size;
    for (i = 0; i < nn; i++) {
        nel = p->edge[ed[i]].nelem;
        edpr[i] = p->edge[ed[i]].pres;
        edpf[i] = p->edge[ed[i]].pref;
        edpd[i] = p->edge[ed[i]].pind;
        edsz[i] = p->edge[ed[i]].size;
        edfrup[i] = -1;
        for (j = 0; j < nel; j++) {
            edfr[i][j] = p->edge[ed[i]].fr[j];
            if (edfr[i][j]) {
                vis_MeshConGetLeftElem(p, no[i], ed[i], &idt, &ikt);
                if (p->frnt[edfr[i][j]].elid == idt) {
                    edfrup[i] = j;
                }
            }
        }
    }

    eld[0] = id;
    nep = 0;
    ned = 1;
    nnd = 0;
    for (;;) {
        vis_MeshCon_FormElem1(p, nn, no, ed, eld[nep], &ned, eld, &nnd, nod, &frfl);
        if (frfl) {
            p->ierr = VIS_ERROR_OPERATION;
            if (frfl == 1) {
                HANDLEERR0(func, p->ierr, "Front internal to element");
            }
            else if (frfl == 2) {
                HANDLEERR0(func, p->ierr, "Preserved node internal to element");
            }
            else {
                HANDLEERR0(func, p->ierr, "Excessive node degree");
            }
            return;
        }
        nep += 1;
        if (nep == ned)
            break;
    }
    /* delete elements, skip first */
    for (i = 1; i < ned; i++) {
        vis_MeshConDelElem(p, eld[i]);
    }
    /* now delete first */
    vis_MeshConDelElem(p, eld[0]);
    vis_MeshConAddElem(p, nn, no, &newid);

    vis_MeshConSetElemPres(p, newid, pres);
    p->lastformelem = newid;
    p->elem[newid].pind = pind;
    p->elem[newid].flat = flat;
    p->elem[newid].size = size;
    for (i = 0; i < nn; i++) {
        edid = p->elem[newid].ed[i];
        nel = p->edge[edid].nelem;
        vis_MeshConSetEdgePres(p, edid, edpr[i]);
        p->edge[edid].pref = edpf[i];
        p->edge[edid].pind = edpd[i];
        p->edge[edid].size = edsz[i];
        if (edfrup[i] != -1) {
            p->frnt[edfr[i][edfrup[i]]].elid = newid;
            p->frnt[edfr[i][edfrup[i]]].elk = i;
            for (j = 0; j < nel; j++) {
                if (p->edge[edid].el[j] == newid) {
                    p->edge[edid].fr[j] = edfr[i][edfrup[i]];
                    break;
                }
            }
        }
    }
    /* delete nodes */
    for (i = 0; i < nnd; i++) {
        vis_MeshConDelNode(p, nod[i]);
    }
}

extern void
vis_MeshConLastFormElem(vis_MeshCon* p, Vint* id)
{
    *id = p->lastformelem;
}

static void
vis_MeshCon_FormElem1(vis_MeshCon* p, Vint nn, Vint no[], Vint ed[], Vint id, Vint* ned, Vint eld[], Vint* nnd, Vint nod[],
                      Vint* frfl)
{
    Vint i, j, k;
    Vint noid, edid, elop;
    Vint imatch, dmatch;

    *frfl = 0;
    for (k = 0; k < 3; k++) {
        edid = p->elem[id].ed[k];
        noid = p->elem[id].no[k];
        imatch = 0;
        for (i = 0; i < nn; i++) {
            if (edid == ed[i]) {
                imatch = 1;
                break;
            }
        }
        if (imatch)
            continue;
        /* front internal to element */
        for (j = 0; j < p->edge[edid].nelem; j++) {
            if (p->edge[edid].fr[j]) {
                *frfl = 1;
                return;
            }
        }

        if (p->edge[edid].el[0] == id) {
            elop = p->edge[edid].el[1];
        }
        else {
            elop = p->edge[edid].el[0];
        }
        dmatch = 0;
        for (i = 0; i < *ned; i++) {
            if (elop == eld[i]) {
                dmatch = 1;
                break;
            }
        }
        if (dmatch == 0) {
            eld[*ned] = elop;
            *ned += 1;
        }
        imatch = 0;
        for (i = 0; i < nn; i++) {
            if (noid == no[i]) {
                imatch = 1;
                break;
            }
        }
        if (imatch)
            continue;
        /* preserved or locked node internal to element */
        if (p->node[noid].pres == SYS_NODE || p->node[noid].pref) {
            *frfl = 2;
            return;
        }
        dmatch = 0;
        for (i = 0; i < *nnd; i++) {
            if (noid == nod[i]) {
                dmatch = 1;
                break;
            }
        }
        if (dmatch == 0) {
            nod[*nnd] = noid;
            *nnd += 1;
            /* excessive node degree */
            if (*nnd >= MESHCON_MAXNDG) {
                *frfl = 3;
                return;
            }
        }
    }
}

/*----------------------------------------------------------------------
                      form simple element
----------------------------------------------------------------------*/
extern void
vis_MeshConSimpElem(vis_MeshCon* p, Vint nn, Vint no[])
{
    Vint i;
    Vint ed[4];
    /* find edges connecting nodes */
    for (i = 0; i < nn; i++) {
        vis_MeshConFindNodeEdge(p, no[i], no[(i + 1) % nn], &ed[i]);
    }
    vis_MeshConFormElem(p, nn, no, ed);
}

/*----------------------------------------------------------------------
                      element geometry
----------------------------------------------------------------------*/
extern void
vis_MeshConInitElemHeap(vis_MeshCon* p, Vint type)
{
    Vint iter, id;

    p->elemheap = type;
    if (p->elemheap == MESHCON_MINELEMANG) {
        vsy_HeapDef(p->hpelem, p->maxelem, 0);
    }
    else if (p->elemheap == MESHCON_MAXELEMANG) {
        vsy_HeapDef(p->hpelem, p->maxelem, 1);
    }
    else if (p->elemheap == MESHCON_MAXELEMLEN) {
        vsy_HeapDef(p->hpelem, p->maxelem, 1);
    }
    else if (p->elemheap == MESHCON_MINELEMLEN) {
        vsy_HeapDef(p->hpelem, p->maxelem, 0);
    }
    else if (p->elemheap == MESHCON_MAXMINELEMANG) {
        vsy_HeapDef(p->hpelem, p->maxelem, 1);
    }
    iter = 0;
    for (;;) {
        if (iter == 0) {
            id = p->headelem;
            iter = id;
        }
        else {
            id = p->elem[iter].next;
            if (id != 0) {
                iter = id;
            }
        }
        if (id == 0)
            break;
        /* compute min angle */
        if (p->elemheap == MESHCON_MINELEMANG) {
            vis_MeshCon_MinAngle(p, id);
        }
        else if (p->elemheap == MESHCON_MAXELEMANG) {
            vis_MeshCon_MaxAngle(p, id);
        }
        else if (p->elemheap == MESHCON_MAXELEMLEN) {
            vis_MeshCon_MaxElemLen(p, id);
        }
        else if (p->elemheap == MESHCON_MINELEMLEN) {
            vis_MeshCon_MinElemLen(p, id);
        }
        else if (p->elemheap == MESHCON_MAXMINELEMANG) {
            vis_MeshCon_MaxMinAngle(p, id);
        }
    }
}

extern void
vis_MeshConNextElemHeap(vis_MeshCon* p, Vint* id, Vdouble* val)
{
    vsy_HeapRef(p->hpelem, id, val);
    if (*id == 0)
        p->elemheap = 0;
}

extern void
vis_MeshConNextElemHeapRemove(vis_MeshCon* p, Vint* id, Vdouble* val)
{
    vsy_HeapRefRemove(p->hpelem, id, val);
    if (*id == 0)
        p->elemheap = 0;
}

extern void
vis_MeshConRemoveElemHeap(vis_MeshCon* p, Vint id)
{
    vsy_HeapRemove(p->hpelem, id);
}

extern void
vis_MeshConInsertElemHeap(vis_MeshCon* p, Vint id)
{
    if (p->elemheap == MESHCON_MINELEMANG) {
        vis_MeshCon_MinAngle(p, id);
    }
    else if (p->elemheap == MESHCON_MAXELEMANG) {
        vis_MeshCon_MaxAngle(p, id);
    }
    else if (p->elemheap == MESHCON_MAXELEMLEN) {
        vis_MeshCon_MaxElemLen(p, id);
    }
    else if (p->elemheap == MESHCON_MINELEMLEN) {
        vis_MeshCon_MinElemLen(p, id);
    }
    else if (p->elemheap == MESHCON_MAXMINELEMANG) {
        vis_MeshCon_MaxMinAngle(p, id);
    }
}

/*----------------------------------------------------------------------
                      utility adjacent fronts to a front
----------------------------------------------------------------------*/
static void
vis_MeshCon_AdjFrnt(vis_MeshCon* p, Vint ix[2], Vint elid, Vint fr[2])
{
    Vint i, j, k;
    Vint elk, elchk, elkchk, edchk;
    Vint edid, frbkflag, nel, nn;
    Vint pres, ptid;
    /* find edge of base front */
    for (i = 0; i < 3; i++) {
        if (p->elem[elid].no[i] == ix[0]) {
            elk = i;
            break;
        }
    }
    edid = p->elem[elid].ed[elk];
#ifdef VISMESH_DEBUG
    printf("vis_MeshCon_AdjFrnt, elid= %d, elk= %d, edid= %d, ix= %d %d\n", elid, elk, edid, ix[0], ix[1]);
#endif
    /* for each end point */
    for (k = 0; k < 2; k++) {
        fr[k] = 0;
        elchk = elid;
        elkchk = elk;
        for (;;) {
            nn = p->elem[elchk].nn;
            if (nn == 4)
                break;
            for (i = 0; i < 3; i++) {
                if (p->elem[elchk].no[i] == ix[k]) {
                    if (k == 0) {
                        elkchk = (i + 2) % 3;
                    }
                    else {
                        elkchk = i % 3;
                    }
                    break;
                }
            }
            edchk = p->elem[elchk].ed[elkchk];
            frbkflag = 0;
            nel = p->edge[edchk].nelem;
            for (j = 0; j < nel; j++) {
                if (p->edge[edchk].el[j] == elchk) {
                    fr[k] = p->edge[edchk].fr[j];
                }
                if (p->edge[edchk].fr[j]) {
                    frbkflag = 1;
                }
            }
            if (fr[k])
                break;
            if (nel != 2)
                break;
            if (frbkflag)
                break;
            if (edchk == edid)
                break;

            if (p->edge[edchk].el[0] == elchk) {
                elchk = p->edge[edchk].el[1];
            }
            else {
                elchk = p->edge[edchk].el[0];
            }
            if (p->patchrestrict) {
                pres = p->elem[elchk].pres;
                vis_MeshConGetElemPres(p->gm, pres, &ptid);
                if (p->patchrestrict != ptid)
                    break;
            }
        }
    }
}

/*----------------------------------------------------------------------
                      fronts
----------------------------------------------------------------------*/
extern void
vis_MeshConAddFrnt(vis_MeshCon* p, Vint elid, Vint no, Vint* id)
{
    static Vchar func[] = "vis_MeshConAddFrnt";
    Vint i, n;
    vis_MeshCon_Frnt* pfrnt;
    Vint pmaxfrnt;
    Vint nn, frid, edid, fradjid;

    if (elid <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "elid= %d", elid);
        return;
    }
    /* check to expand storage */
    if (p->numfrnt + 1 == p->maxfrnt) {
        pmaxfrnt = MIN2(2000 + p->maxfrnt, 2 * p->maxfrnt);
        pfrnt = (vis_MeshCon_Frnt*)vut_reallocMem(p->frnt, (pmaxfrnt + 1) * sizeof(vis_MeshCon_Frnt));
        if (pfrnt == NULL) {
            p->ierr = VIS_ERROR_MEMORY;
            HANDLEERR0(func, p->ierr, "Realloc frnt");
            return;
        }
        p->frnt = pfrnt;
        for (i = p->maxfrnt; i <= pmaxfrnt; i++) {
            p->frnt[i].next = i + 1;
            p->frnt[i].level = 0;
        }
        p->maxfrnt = pmaxfrnt;
        p->frnt[p->maxfrnt].next = 0;
    }
    /* get next free front */
    n = p->frnt[0].next;
    p->frnt[0].next = p->frnt[n].next;

    /* link in front */
    p->frnt[n].next = p->headfrnt;
    p->frnt[n].prev = 0;
    p->frnt[p->headfrnt].prev = n;
    p->headfrnt = n;
    /* set elid, elk */
    p->frnt[n].elid = elid;
    p->frnt[n].elk = no - 1;
    /* set nodes */
    nn = p->elem[elid].nn;
    p->frnt[n].no[0] = p->elem[elid].no[no - 1];
    p->frnt[n].no[1] = p->elem[elid].no[no % nn];

    /* find adjacent fronts, if any */
    vis_MeshCon_AdjFrnt(p, p->frnt[n].no, elid, p->frnt[n].fr);

    /* set adjacent fronts */
    /* unhook and zero previous adjacencies */
    if (p->frnt[n].fr[0]) {
        frid = p->frnt[n].fr[0];
        fradjid = p->frnt[frid].fr[1];
        if (fradjid) {
            p->frnt[fradjid].fr[0] = 0;
        }
        p->frnt[frid].fr[1] = n;
    }
    if (p->frnt[n].fr[1]) {
        frid = p->frnt[n].fr[1];
        fradjid = p->frnt[frid].fr[0];
        if (fradjid) {
            p->frnt[fradjid].fr[1] = 0;
        }
        p->frnt[frid].fr[0] = n;
    }
    /* set front in edge */
    edid = p->elem[elid].ed[no - 1];
    for (i = 0; i < p->edge[edid].nelem; i++) {
        if (p->edge[edid].el[i] == elid) {
            p->edge[edid].fr[i] = n;
        }
    }
    /* compute state */
    p->frnt[n].st[0] = -1;
    p->frnt[n].st[1] = -1;
    vis_MeshCon_MinFrntLen(p, n);

    *id = n;
    p->numfrnt += 1;
}

extern void
vis_MeshConDelFrnt(vis_MeshCon* p, Vint id)
{
    Vint i, k, n;
    Vint nx, pr;
    Vint frid, edid, elid;
    Vint is;
    /* unhook from adjacent fronts */
    if (p->frnt[id].fr[0]) {
        frid = p->frnt[id].fr[0];
        p->frnt[frid].fr[1] = 0;
    }
    if (p->frnt[id].fr[1]) {
        frid = p->frnt[id].fr[1];
        p->frnt[frid].fr[0] = 0;
    }
    /* unset front in edge */
    elid = p->frnt[id].elid;
    k = p->frnt[id].elk;
    edid = p->elem[elid].ed[k];
    for (i = 0; i < p->edge[edid].nelem; i++) {
        if (p->edge[edid].fr[i] == id) {
            p->edge[edid].fr[i] = 0;
        }
    }
    /* remember state */
    is = MIN2(2, p->frnt[id].st[0] + p->frnt[id].st[1]);
    /* place front in free list */
    n = p->frnt[0].next;
    p->frnt[0].next = id;
    nx = p->frnt[id].next;
    pr = p->frnt[id].prev;
    p->frnt[id].next = n;
    p->frnt[id].elid = 0;

    /* delete front from active list */
    p->frnt[nx].prev = pr;
    if (pr == 0) {
        p->headfrnt = nx;
    }
    else {
        p->frnt[pr].next = nx;
    }
    /* remove from state */
    vsy_PQueueRemove(p->bfminlen[is], id);

    p->numfrnt -= 1;
}

extern void
vis_MeshConGetFrnt(vis_MeshCon* p, Vint id, Vint no[], Vint fr[])
{
    static Vchar func[] = "vis_MeshConGetFrnt";

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    MOVE2(p->frnt[id].no, no);
    MOVE2(p->frnt[id].fr, fr);
}

extern void
vis_MeshConGetFrntNode(vis_MeshCon* p, Vint id, Vint no[])
{
    static Vchar func[] = "vis_MeshConGetFrntNode";

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    MOVE2(p->frnt[id].no, no);
}

extern void
vis_MeshConGetFrntElem(vis_MeshCon* p, Vint id, Vint* elid, Vint* no)
{
    *elid = p->frnt[id].elid;
    *no = p->frnt[id].elk + 1;
}

extern void
vis_MeshConGetFrntEdge(vis_MeshCon* p, Vint id, Vint* edid)
{
    Vint elid, elk;

    elid = p->frnt[id].elid;
    elk = p->frnt[id].elk;
    *edid = p->elem[elid].ed[elk];
}

extern void
vis_MeshConSetFrntLevel(vis_MeshCon* p, Vint id, Vint level)
{
    static Vchar func[] = "vis_MeshConSetFrntLevel";
    Vint elid, elk, edid;

    if (p->verbose) {
        if (level == -1) {
            elid = p->frnt[id].elid;
            elk = p->frnt[id].elk;
            edid = p->elem[elid].ed[elk];
            if (p->edge[edid].pres == 0) {
                HANDLEERR2(func, p->ierr, "Improper level= %d, id= %d", level, id);
            }
        }
    }
    p->frnt[id].level = level;
}

extern void
vis_MeshConGetFrntLevel(vis_MeshCon* p, Vint id, Vint* level)
{
    *level = p->frnt[id].level;
}

extern void
vis_MeshConGetFrntState(vis_MeshCon* p, Vint id, Vint st[2], Vdouble an[2])
{
    MOVE2(p->frnt[id].st, st);
    MOVE2(p->frnt[id].an, an);
}

/*----------------------------------------------------------------------
                      edges
----------------------------------------------------------------------*/
extern void
vis_MeshConGetEdge(vis_MeshCon* p, Vint id, Vint no[], Vint el[])
{
    static Vchar func[] = "vis_MeshConGetEdge";
    Vint k, tid, nel, ptid, pres;

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    if (p->edge[id].nelem > 2) {
        if (p->patchrestrict) {
            nel = 0;
            for (k = 0; k < p->edge[id].nelem; k++) {
                tid = p->edge[id].el[k];
                pres = p->elem[tid].pres;
                if (p->gm) {
                    vis_MeshConGetElemPres(p->gm, pres, &ptid);
                }
                else {
                    ptid = pres;
                }
                if (p->patchrestrict != ptid)
                    continue;
                el[nel] = p->edge[id].el[k];
            }
        }
        else {
            p->ierr = SYS_ERROR_VALUE;
            HANDLEERR1(func, p->ierr, "Non-manifold edge, id= %d", id);
            return;
        }
    }
    MOVE2(p->edge[id].no, no);
    el[0] = p->edge[id].el[0];
    if (p->edge[id].nelem == 2) {
        el[1] = p->edge[id].el[1];
    }
    else {
        el[1] = 0;
    }
}

extern void
vis_MeshConGetEdgeElem(vis_MeshCon* p, Vint id, Vint el[])
{
    static Vchar func[] = "vis_MeshConGetEdgeElem";
    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }

    el[0] = p->edge[id].el[0];
    if (p->edge[id].nelem >= 2) {
        el[1] = p->edge[id].el[1];
    }
    else {
        el[1] = 0;
    }
}

extern void
vis_MeshConNumEdgeElem(vis_MeshCon* p, Vint id, Vint* nix)
{
    *nix = p->edge[id].nelem;
}

extern void
vis_MeshConIthEdgeElem(vis_MeshCon* p, Vint id, Vint no, Vint* elid)
{
    *elid = p->edge[id].el[no - 1];
}

extern void
vis_MeshConGetEdgeNM(vis_MeshCon* p, Vint id, Vint no[], Vint* nix, Vint el[])
{
    static Vchar func[] = "vis_MeshConGetEdgeNM";
    Vint i;

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    MOVE2(p->edge[id].no, no);
    *nix = p->edge[id].nelem;
    for (i = 0; i < *nix; i++) {
        el[i] = p->edge[id].el[i];
    }
}

extern void
vis_MeshConEdgeIncon(vis_MeshCon* p, Vint id, Vint* flag)
{
    Vint j, k;
    Vint nn[2], em[2], nm[2], nid;

    *flag = 0;
    if (p->edge[id].nelem > 2) {
        *flag = 1;
    }
    else if (p->edge[id].nelem == 2) {
        nid = p->edge[id].no[0];
        for (j = 0; j < 2; j++) {
            em[j] = p->edge[id].el[j];
            nn[j] = p->elem[em[j]].nn;
            for (k = 0; k < nn[j]; k++) {
                if (p->elem[em[j]].no[k] == nid) {
                    nm[j] = k;
                    break;
                }
            }
        }
        if (p->elem[em[0]].no[(nm[0] + 1) % nn[0]] == p->elem[em[1]].no[(nm[1] + 1) % nn[1]] ||
            p->elem[em[0]].no[(nm[0] + nn[0] - 1) % nn[0]] == p->elem[em[1]].no[(nm[1] + nn[1] - 1) % nn[1]]) {
            *flag = 1;
        }
    }
}

extern void
vis_MeshConGetEdgeNode(vis_MeshCon* p, Vint id, Vint no[])
{
    static Vchar func[] = "vis_MeshConGetEdgeNode";

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    MOVE2(p->edge[id].no, no);
}

extern void
vis_MeshConOppEdgeNode(vis_MeshCon* p, Vint id, Vint noid, Vint* opno)
{
    if (noid == p->edge[id].no[0]) {
        *opno = p->edge[id].no[1];
    }
    else {
        *opno = p->edge[id].no[0];
    }
}

extern void
vis_MeshConGetEdgeFrnt(vis_MeshCon* p, Vint id, Vint fr[])
{
    static Vchar func[] = "vis_MeshConGetEdgeFrnt";

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    if (p->edge[id].nelem > 2) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "Non-manifold edge, id= %d", id);
        return;
    }
    MOVE2(p->edge[id].fr, fr);
}

extern void
vis_MeshConGetEdgeFrntNM(vis_MeshCon* p, Vint id, Vint* nix, Vint fr[])
{
    static Vchar func[] = "vis_MeshConGetEdgeFrntNM";
    Vint i;

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    *nix = p->edge[id].nelem;
    for (i = 0; i < *nix; i++) {
        fr[i] = p->edge[id].fr[i];
    }
}

extern void
vis_MeshConNumEdgeFrnt(vis_MeshCon* p, Vint id, Vint* nix)
{
    static Vchar func[] = "vis_MeshConNumEdgeFrnt";
    Vint i;

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    *nix = 0;
    for (i = 0; i < p->edge[id].nelem; i++) {
        if (p->edge[id].fr[i])
            *nix += 1;
    }
}

extern void
vis_MeshConGetEdgeFrntElem(vis_MeshCon* p, Vint id, Vint elid, Vint* frid)
{
    static Vchar func[] = "vis_MeshConGetEdgeFrntNM";
    Vint i;
    Vint nix;

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    nix = p->edge[id].nelem;
    *frid = 0;
    for (i = 0; i < nix; i++) {
        if (p->edge[id].el[i] == elid) {
            *frid = p->edge[id].fr[i];
            break;
        }
    }
}

extern void
vis_MeshConGetNodeFrnt(vis_MeshCon* p, Vint ix[2], Vint* frid)
{
    Vint i, j;
    Vint num;
    Vint edid, id;

    *frid = 0;
    vis_MeshConGetNodeCCWEdge(p, ix[0], &num, p->inoed);
    /* loop through edges connected to first node */
    for (i = 0; i < num; i++) {
        edid = p->inoed[i];
        if ((ix[0] == p->edge[edid].no[0] && ix[1] == p->edge[edid].no[1]) ||
            (ix[1] == p->edge[edid].no[0] && ix[0] == p->edge[edid].no[1])) {
            /* loop through fronts */
            for (j = 0; j < p->edge[edid].nelem; j++) {
                id = p->edge[edid].fr[j];
                if (ix[0] == p->frnt[id].no[0] && ix[1] == p->frnt[id].no[1]) {
                    *frid = id;
                    break;
                }
            }
        }
    }
}

extern void
vis_MeshConSwapEdge(vis_MeshCon* p, Vint id)
{
    static Vchar func[] = "vis_MeshConSwapEdge";
    Vint k;
    Vint ea;
    Vint k1, k2;
    Vint m1, m2;
    Vint in1[3], in2[3];
    Vint ie1[3], ie2[3];
    Vint frid, iswapnorm;
    Vdouble v1[3][3], v2[3][3];
    Vdouble x[3][3], vn1[3], vn2[3], fl1, fl2;

    /* check for two connected elements */
    if (p->edge[id].nelem != 2) {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR1(func, p->ierr, "edge not adjacent to two triangles, id= %d", id);
        return;
    }
    /* check for edge connected to front */
    if (p->edge[id].fr[0] || p->edge[id].fr[1]) {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR1(func, p->ierr, "edge with front, id= %d", id);
        return;
    }
    m1 = p->edge[id].el[0];
    m2 = p->edge[id].el[1];
    /* triangles only */
    if (p->elem[m1].nn != 3 || p->elem[m2].nn != 3) {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR1(func, p->ierr, "edge adjacent to quad, id= %d", id);
        return;
    }
    p->nswapedge += 1;
    /* first element */
    for (k1 = 0; k1 < 3; k1++) {
        ea = p->elem[m1].ed[k1];
        if (ea == id) {
            in1[0] = p->elem[m1].no[(k1 + 1) % 3];
            in1[1] = p->elem[m1].no[(k1 + 2) % 3];
            ie1[0] = p->elem[m1].ed[(k1 + 1) % 3];
            ie1[1] = id;
            if (p->elem[m1].ne) {
                MOVE3(p->elem[m1].ne[(k1 + 1) % 3], v1[0]);
                MOVE3(p->elem[m1].ne[(k1 + 2) % 3], v1[1]);
            }
            break;
        }
    }
    /* second element */
    for (k2 = 0; k2 < 3; k2++) {
        ea = p->elem[m2].ed[k2];
        if (ea == id) {
            in2[0] = p->elem[m2].no[(k2 + 1) % 3];
            in2[1] = p->elem[m2].no[(k2 + 2) % 3];
            ie2[0] = p->elem[m2].ed[(k2 + 1) % 3];
            ie2[1] = id;
            if (p->elem[m2].ne) {
                MOVE3(p->elem[m2].ne[(k2 + 1) % 3], v2[0]);
                MOVE3(p->elem[m2].ne[(k2 + 2) % 3], v2[1]);
            }
            break;
        }
    }
    ie1[2] = p->elem[m2].ed[(k2 + 2) % 3];
    ie2[2] = p->elem[m1].ed[(k1 + 2) % 3];
    in1[2] = in2[1];
    in2[2] = in1[1];
    if (p->elem[m1].ne && p->elem[m2].ne) {
        MOVE3(p->elem[m2].ne[(k2 + 2) % 3], v1[2]);
        MOVE3(p->elem[m1].ne[(k1 + 2) % 3], v2[2]);
    }
    /* install new nodes and edges in elements */
    if (p->normalflag) {
        vis_MeshConGetNodes(p, 3, in1, x);
        vis_computeNormdv(3, x, vn1);
        vis_MeshConGetNodes(p, 3, in2, x);
        vis_computeNormdv(3, x, vn2);
        iswapnorm = 1;
        if (p->swapnormangflag) {
            fl1 = DOT3(v1[0], v2[1]);
            fl2 = DOT3(v1[1], v2[0]);
            if (fl1 < p->swapnormang || fl2 < p->swapnormang) {
                iswapnorm = 0;
            }
        }
    }
    for (k = 0; k < 3; k++) {
        p->elem[m1].no[k] = in1[k];
        p->elem[m1].ed[k] = ie1[k];
        p->elem[m2].no[k] = in2[k];
        p->elem[m2].ed[k] = ie2[k];
        if (p->elem[m1].ne && p->elem[m2].ne) {
            if (iswapnorm == 0) {
                MOVE3(vn1, p->elem[m1].ne[k]);
                MOVE3(vn2, p->elem[m2].ne[k]);
            }
            else {
                MOVE3(v1[k], p->elem[m1].ne[k]);
                MOVE3(v2[k], p->elem[m2].ne[k]);
            }
        }
    }
    /* set edge elements and fronts of traded edges */
    ea = ie1[2];
    for (k = 0; k < p->edge[ea].nelem; k++) {
        if (p->edge[ea].el[k] == m2) {
            p->edge[ea].el[k] = m1;
        }
        frid = p->edge[ea].fr[k];
        if (frid) {
            if (p->frnt[frid].elid == m2) {
                p->frnt[frid].elid = m1;
                p->frnt[frid].elk = 2;
            }
        }
    }
    ea = ie2[2];
    for (k = 0; k < p->edge[ea].nelem; k++) {
        if (p->edge[ea].el[k] == m1) {
            p->edge[ea].el[k] = m2;
        }
        frid = p->edge[ea].fr[k];
        if (frid) {
            if (p->frnt[frid].elid == m1) {
                p->frnt[frid].elid = m2;
                p->frnt[frid].elk = 2;
            }
        }
    }
    /* see if there are fronts to be redone on remaining */
    for (k = 0; k < p->edge[ie1[0]].nelem; k++) {
        frid = p->edge[ie1[0]].fr[k];
        if (frid) {
            if (p->frnt[frid].elid == m1) {
                p->frnt[frid].elk = 0;
            }
        }
    }
    for (k = 0; k < p->edge[ie2[0]].nelem; k++) {
        frid = p->edge[ie2[0]].fr[k];
        if (frid) {
            if (p->frnt[frid].elid == m2) {
                p->frnt[frid].elk = 0;
            }
        }
    }
    /* reset the edge nodes and node edges of swapped edge */
    vis_MeshCon_DecNode(p, p->edge[id].no[0], id);
    p->edge[id].no[0] = in2[1];
    vis_MeshCon_IncNode(p, p->edge[id].no[0], id);

    vis_MeshCon_DecNode(p, p->edge[id].no[1], id);
    p->edge[id].no[1] = in2[2];
    vis_MeshCon_IncNode(p, p->edge[id].no[1], id);
    /* search tree */
    if (p->adt) {
        vsy_ADTreeRemove(p->adt, m1);
        vis_MeshCon_ADTInsert(p, m1);
        vsy_ADTreeRemove(p->adt, m2);
        vis_MeshCon_ADTInsert(p, m2);
    }
    /* compute min angle */
    if (p->elemheap == MESHCON_MINELEMANG) {
        vis_MeshCon_MinAngle(p, m1);
        vis_MeshCon_MinAngle(p, m2);
    }
    else if (p->elemheap == MESHCON_MAXELEMANG) {
        vis_MeshCon_MaxAngle(p, m1);
        vis_MeshCon_MaxAngle(p, m2);
    }
    else if (p->elemheap == MESHCON_MAXELEMLEN) {
        vis_MeshCon_MaxElemLen(p, m1);
        vis_MeshCon_MaxElemLen(p, m2);
    }
    else if (p->elemheap == MESHCON_MINELEMLEN) {
        vis_MeshCon_MinElemLen(p, m1);
        vis_MeshCon_MinElemLen(p, m2);
    }
    else if (p->elemheap == MESHCON_MAXMINELEMANG) {
        vis_MeshCon_MaxMinAngle(p, m1);
        vis_MeshCon_MaxMinAngle(p, m2);
    }
    if (p->verbose) {
        Vdouble area;
        vis_MeshConElemArea(p, m1, &area);
        if (area <= 0.) {
            HANDLEERR2(func, p->ierr, "Zero area element id= %d, area= %e", m1, area);
        }
        vis_MeshConElemArea(p, m2, &area);
        if (area <= 0.) {
            HANDLEERR2(func, p->ierr, "Zero area element id= %d, area= %e", m2, area);
        }
    }
    /* compute edge length */
    if (p->edgeheap == MESHCON_MINEDGELEN) {
        vis_MeshCon_MinEdgeLen(p, id);
    }
    else if (p->edgeheap == MESHCON_MAXEDGELEN) {
        vis_MeshCon_MaxEdgeLen(p, id);
    }
    if (p->edge[id].nelem != 2 && p->edge[id].pres == 0) {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR1(func, p->ierr, "Non manifold edge, not preserved, id= %d", id);
        return;
    }
}

extern void
vis_MeshConCheckSplitEdge(vis_MeshCon* p, Vint id, Vint noid, Vint* flag)
{
    Vint i, k, m;
    Vint nelem;
    Vint nn, elno[4], eled[4];
    Vdouble vn[3], xn[3], v[3], xt[3][3], d1[3], d2[3], fl;
    /* check for triangle inversion or collapse */
    *flag = 1;
    vis_MeshConGetNode(p, noid, xn);
    nelem = p->edge[id].nelem;
    for (k = 0; k < nelem; k++) {
        m = p->edge[id].el[k];
        vis_MeshConGetElem(p, m, &nn, elno, eled);
        vis_MeshConFlatNormal(p, m, vn);
        if (nn != 3)
            continue;
        vis_MeshConGetNodes(p, nn, elno, xt);
        for (i = 0; i < 3; i++) {
            if (id == eled[i]) {
                DIFF3(xt[(i + 2) % 3], xn, d1);
                DIFF3(xt[i], xn, d2);
                CROSS3(d1, d2, v);
                fl = DOT3(vn, v);
                if (fl <= 0.) {
                    *flag = 0;
                    return;
                }
                DIFF3(xt[(i + 1) % 3], xn, d1);
                DIFF3(xt[(i + 2) % 3], xn, d2);
                CROSS3(d1, d2, v);
                fl = DOT3(vn, v);
                if (fl <= 0.) {
                    *flag = 0;
                    return;
                }
            }
        }
    }
}

extern void
vis_MeshConSplitEdge(vis_MeshCon* p, Vint id, Vint noid)
{
    static Vchar func[] = "vis_MeshConSplitEdge";
    Vint i, j, k, m;
    Vint m1, ea, k1;
    Vint edid;
    Vint im[MESHCON_MAXNMT], nm[2][MESHCON_MAXNMT], ie[MESHCON_MAXNMT];
    Vint in[MESHCON_MAXNMT][3], ix[3];
    Vint nn0, nn1, nce, ncn, ice1, ice2, ic[MESHCON_MAXNMT], icn;
    Vint epres, epind, epref, etopo;
    Vdouble esize;
    Vdouble xp[3], xa[MESHCON_MAXNMT][3], xe[2][3];
    Vint ifl, ieff[2][MESHCON_MAXNMT], frid;
    Vdouble xt[3][3], ve[MESHCON_MAXNMT][3][3], vn[MESHCON_MAXNMT][3], ven[3][3];
    Vdouble r[3], h[3];
    Vdouble xed[2][3], red, xsn[3], ved[2][3], vsn[3], vs[2][3];
    Vint snrmflag;
    Vint normflag[MESHCON_MAXNMT], ierr, nelem;
    Vint irev[MESHCON_MAXNMT], ir, ed[2], edp[2];

    /* check for edge connected to front */
    for (k = 0; k < p->edge[id].nelem; k++) {
        if (p->edge[id].fr[k]) {
            p->ierr = SYS_ERROR_OPERATION;
            HANDLEERR1(func, p->ierr, "edge with front, id= %d", id);
            return;
        }
    }
    p->nsplitedge += 1;
    /* get edge data */
    nn0 = p->edge[id].no[0];
    nn1 = p->edge[id].no[1];
    nce = p->edge[id].cent;
    epres = p->edge[id].pres;
    epind = p->edge[id].pind;
    epref = p->edge[id].pref;
    esize = p->edge[id].size;
    etopo = p->edge[id].topo;
    /* capture connectivity registered to edge */
    ifl = 0;
    nelem = p->edge[id].nelem;
    for (k = 0; k < nelem; k++) {
        m = p->edge[id].el[k];
        im[k] = m;
        ic[k] = 0;
        for (k1 = 0; k1 < 3; k1++) {
            ea = p->elem[m].ed[k1];
            if (ea == id) {
                if (k == 0) {
                    irev[k] = 0;
                }
                else {
                    if (p->elem[m].no[(k1 + 1) % 3] == in[0][1]) {
                        irev[k] = 0;
                    }
                    else {
                        irev[k] = 1;
                    }
                }
                in[k][0] = p->elem[m].no[k1];
                in[k][1] = p->elem[m].no[(k1 + 1) % 3];
                in[k][2] = p->elem[m].no[(k1 + 2) % 3];
                ie[k] = k1;
                ice1 = p->elem[m].ed[(k1 + 1) % 3];
                ice2 = p->elem[m].ed[(k1 + 2) % 3];
                /* center processing */
                ic[k] = (nce || p->edge[ice1].cent || p->edge[ice2].cent);
                /* front processing */
                ir = irev[k];
                ieff[1 - ir][k] = 0;
                for (i = 0; i < p->edge[ice1].nelem; i++) {
                    if (im[k] == p->edge[ice1].el[i] && p->edge[ice1].fr[i]) {
                        ieff[1 - ir][k] = p->edge[ice1].fr[i];
                        ifl = 1;
                        break;
                    }
                }
                ieff[ir][k] = 0;
                for (i = 0; i < p->edge[ice2].nelem; i++) {
                    if (im[k] == p->edge[ice2].el[i] && p->edge[ice2].fr[i]) {
                        ieff[ir][k] = p->edge[ice2].fr[i];
                        ifl = 1;
                        break;
                    }
                }
                break;
            }
        }
        if (ic[k]) {
            MID3(p->node[noid].x, p->node[in[k][2]].x, xp);
            vis_MeshConProjectOneTri(p, im[k], xp, r, xa[k], &ierr);
        }
    }
    /* get normals */
    vut_ZeroI(normflag, MESHCON_MAXNMT);
    if (p->normalflag) {
        for (k = 0; k < nelem; k++) {
            m = im[k];
            if (p->elem[m].ne != NULL) {
                for (k1 = 0; k1 < 3; k1++) {
                    vis_MeshConGetNode(p, p->elem[m].no[k1], xt[k1]);
                    MOVE3(p->elem[m].ne[k1], ve[k][k1]);
                }
                vis_invertNCTridv(xt, p->node[noid].x, r, xp, &ierr);
                if (ierr) {
                    vis_centNCdv(VIS_SHAPETRI, r);
                }
                vis_shapeTridv(1, r, h, NULL);
                vml_multMatrix3d(3, ve[k], h, vn[k]);
                UNIT3(vn[k]);
                normflag[k] = 1;
            }
        }
    }
    /* compute new edge centers of split edge */
    if (nce) {
        MID3(p->node[in[0][0]].x, p->node[noid].x, xp);
        vis_MeshConProjectOneEdge(p, id, xp, &red, xe[0], &ierr);
        MOVE3(xe[0], p->node[nce].x);
        MID3(p->node[in[0][1]].x, p->node[noid].x, xp);
        vis_MeshConProjectOneEdge(p, id, xp, &red, xe[1], &ierr);
        vis_MeshConAddNode(p, xe[1], &ncn);
    }
    /* compute new edge tangents */
    snrmflag = 0;
    if (p->normalflag) {
        if (p->edge[id].ns) {
            vis_MeshConGetNodes(p, 2, p->edge[id].no, xed);
            vis_invertNCLindv(xed, p->node[noid].x, &red, xsn, &ierr);
            vis_shapeLindv(1, red, h, NULL);
            vis_MeshConGetEdgeTang(p, id, ved);
            vml_multMatrix3d(2, ved, h, vsn);
            UNIT3(vsn);
            snrmflag = 1;
        }
    }
    /* add new elements */
    ix[0] = noid;
    for (k = 0; k < nelem; k++) {
        if (irev[k]) {
            ix[1] = in[k][1];
            ix[2] = in[k][2];
        }
        else {
            ix[1] = in[k][2];
            ix[2] = in[k][0];
        }
        vis_MeshConAddElem(p, 3, ix, &m1);
        if (p->ierr)
            return;
        nm[0][k] = m1;
        vis_MeshConSetElemPres(p, m1, p->elem[im[k]].pres);
        p->elem[m1].pind = p->elem[im[k]].pind;
        p->elem[m1].flat = p->elem[im[k]].flat;
        p->elem[m1].size = p->elem[im[k]].size;
        if (normflag[k]) {
            MOVE3(vn[k], ven[0]);
            if (irev[k]) {
                MOVE3(ve[k][(ie[k] + 1) % 3], ven[1]);
                MOVE3(ve[k][(ie[k] + 2) % 3], ven[2]);
            }
            else {
                MOVE3(ve[k][(ie[k] + 2) % 3], ven[1]);
                MOVE3(ve[k][ie[k] % 3], ven[2]);
            }
            vsy_ConcatAdd(p->concat, 3 * 3 * sizeof(Vdouble), (Vchar*)ven);
            vsy_ConcatRef(p->concat, (void**)&p->elem[m1].ne);
        }

        if (irev[k]) {
            ix[1] = in[k][2];
            ix[2] = in[k][0];
        }
        else {
            ix[1] = in[k][1];
            ix[2] = in[k][2];
        }
        vis_MeshConAddElem(p, 3, ix, &m1);
        if (p->ierr)
            return;
        nm[1][k] = m1;
        vis_MeshConSetElemPres(p, m1, p->elem[im[k]].pres);
        p->elem[m1].pind = p->elem[im[k]].pind;
        p->elem[m1].flat = p->elem[im[k]].flat;
        p->elem[m1].size = p->elem[im[k]].size;
        if (normflag[k]) {
            MOVE3(vn[k], ven[0]);
            if (irev[k]) {
                MOVE3(ve[k][(ie[k] + 2) % 3], ven[1]);
                MOVE3(ve[k][ie[k] % 3], ven[2]);
            }
            else {
                MOVE3(ve[k][(ie[k] + 1) % 3], ven[1]);
                MOVE3(ve[k][(ie[k] + 2) % 3], ven[2]);
            }
            vsy_ConcatAdd(p->concat, 3 * 3 * sizeof(Vdouble), (Vchar*)ven);
            vsy_ConcatRef(p->concat, (void**)&p->elem[m1].ne);
        }
        /* add center of element split edge */
        if (ic[k]) {
            vis_MeshConAddNode(p, xa[k], &icn);
            edid = p->elem[nm[0][k]].ed[2];
            p->edge[edid].cent = icn;
        }
        /* delete parent element */
        vis_MeshConDelElem(p, im[k]);
    }
    /* split preserved edge */
    if (epres) {
        ed[0] = p->elem[nm[0][0]].ed[2];
        ed[1] = p->elem[nm[1][0]].ed[0];
        for (j = 0; j < 2; j++) {
            edid = ed[j];
            /* align connectivity with original edge */
            if ((p->edge[edid].no[0] == noid && p->edge[edid].no[1] == nn0) ||
                (p->edge[edid].no[0] == nn1 && p->edge[edid].no[1] == noid)) {
                vis_MeshConReverseEdge(p, edid);
            }
            /* order them along original edge */
            if (p->edge[edid].no[0] == nn0) {
                edp[0] = edid;
            }
            else {
                edp[1] = edid;
            }
            if (p->edge[edid].pres) {
                if (p->extendflag == 1 || p->extendflag == 2) {
                    vis_MeshCon_AddPind(p, &p->edge[edid].pind, epres);
                    vis_MeshCon_AppPind(p, &p->edge[edid].pind, epind);
                }
            }
            else {
                vis_MeshConSetEdgePres(p, edid, epres);
                p->edge[edid].pind = epind;
            }
            p->edge[edid].pref = epref;
            p->edge[edid].topo = etopo;
            p->edge[edid].size = esize;
        }
    }
    /* set center of split edge */
    if (nce) {
        edid = p->elem[nm[0][0]].ed[2];
        p->edge[edid].cent = nce;
        edid = p->elem[nm[1][0]].ed[0];
        p->edge[edid].cent = ncn;
    }
    /* set side normals on edges */
    if (snrmflag) {
        for (j = 0; j < 2; j++) {
            edid = edp[j];
            if (j == 0) {
                MOVE3(ved[0], vs[0]);
                MOVE3(vsn, vs[1]);
            }
            else {
                MOVE3(vsn, vs[0]);
                MOVE3(ved[1], vs[1]);
            }
            vis_MeshConSetEdgeTang(p, edid, vs);
        }
    }
    /* see if there are fronts to be redone */
    if (ifl) {
        if (nelem > 2) {
            p->ierr = SYS_ERROR_OPERATION;
            HANDLEERR1(func, p->ierr, "edge with front, id= %d", id);
            return;
        }
        for (k = 0; k < nelem; k++) {
            for (j = 0; j < 2; j++) {
                m = nm[j][k];
                edid = p->elem[m].ed[1];
                for (i = 0; i < p->edge[edid].nelem; i++) {
                    if (p->edge[edid].el[i] == m) {
                        frid = ieff[j][k];
                        if (frid) {
                            p->edge[edid].fr[i] = frid;
                            p->frnt[frid].elid = m;
                            p->frnt[frid].elk = 1;
                        }
                    }
                }
            }
        }
    }
}

/*----------------------------------------------------------------------
                      check collapse edge
----------------------------------------------------------------------*/
extern void
vis_MeshConCheckCollapseEdge(vis_MeshCon* p, Vint id, Vint noid, Vint midflag, Vdouble cang, Vdouble vn[3], Vint* flag)
{
    Vint i, j, k, m, n;
    Vint nelix;
    Vint nnoix1;
    Vint nnoix2;
    Vint stat;
    Vint nn, ix[4], edix[4], eid;
    Vdouble x[4][3], d1[3], d2[3], va[3], vb[3], xp[3], fl;
    Vdouble xn[2][3], xa[2][3], xx[3], d[3], vc[3];
    Vdouble xcp[3][3], r[3], xi[3], xs[3], e[3], t;
    Vint ierr;
    Vdouble fla, flb, rl, metric;
    Vdouble vq[2][3];
    Vdouble eln[4], ang[4], angmax;
    Vint k1, kmax;
    Vint node[2], edid, edid1;
    Vint nave, nadj, iadj;
    Vint edno[2], edel[MESHCON_MAXNMT];
    Vint edel1[MESHCON_MAXNMT];
    Vint elno[4], eled[4];
    Vint nn1, elno1[4], eled1[4];
    Vint elaid[2], noaid[2];
    Vint napx[MESHCON_MAXNMT], nelem, nelem2, found, nfre;
    Vdouble metorigmin, metcollmin, angorigmax, angcollmax, lenmax;
    Vint collflag, icomp, nodepres, pres;

    *flag = 1;
    if (midflag == 0) {
        nave = 1;
    }
    else {
        nave = 2;
    }
    MOVE2(p->edge[id].no, edno);
    nelem = p->edge[id].nelem;
    for (i = 0; i < nelem; i++) {
        edel[i] = p->edge[id].el[i];
    }
    /*  noid is the node we are keeping;
        node[0] is the one we may move unless midflag is set */
    if (noid == edno[0]) {
        node[0] = edno[1];
    }
    else {
        node[0] = edno[0];
    }
    node[1] = noid;

    vis_MeshConGetNode(p, node[0], xn[0]);
    vis_MeshConGetNode(p, node[1], xn[1]);
    if (midflag == 0) {
        MOVE3(xn[1], xp);
    }
    else if (midflag == 1) {
        MID3(xn[0], xn[1], xp);
    }
    if (p->collimpflag) {
        metorigmin = 1.;
        metcollmin = 1.;
    }
    if (p->collangflag) {
        angorigmax = 0.;
        angcollmax = 0.;
    }
    /* determine collapse length check */
    collflag = 0;
    if (p->colllenflag && p->colllenmax != 0.) {
        lenmax = 0.;
        collflag = 1;
        vis_MeshConGetNodePres(p, noid, &nodepres);
    }
    /* loop through nodes to check */
    for (j = 0; j < nave; j++) {
        /* loop through elements attached to edge node j */
        vis_MeshConGetNodeElem(p, node[j], &nelix, p->inoed);
        for (i = 0; i < nelix; i++) {
            eid = p->inoed[i];
            /* skip elements that contain the edge itself */
            found = 0;
            for (k = 0; k < nelem; k++) {
                if (eid == edel[k]) {
                    found = 1;
                    break;
                }
            }
            vis_MeshConGetElem(p, eid, &nn, ix, edix);
            for (k = 0; k < nn; k++) {
                vis_MeshConGetNode(p, ix[k], x[k]);
                if (ix[k] == node[j]) {
                    k1 = k;
                }
            }
            if (p->collimpflag) {
                vis_computeMetricTriangle(vn, x, &metric);
                metorigmin = MIN2(metorigmin, metric);
            }
            if (p->collangflag) {
                if (nn == 3) {
                    vis_computeAngle(VIS_SHAPETRI, vn, x, eln, ang, &kmax, &angmax);
                }
                else {
                    vis_computeAngle(VIS_SHAPEQUAD, vn, x, eln, ang, &kmax, &angmax);
                }
                angorigmax = MAX2(angorigmax, angmax);
            }
            if (found)
                continue;
            if (collflag) {
                vis_MeshConGetNodePres(p, ix[(k1 + 1) % nn], &pres);
                icomp = 1;
                if (nodepres == SYS_FACE || pres == SYS_FACE) {
                    if (p->colllenmin) {
                        DIFF3(x[(k1 + 1) % nn], x[k1], d1);
                        flb = MAG3(d1);
                        if (flb < p->colllenmin)
                            icomp = 0;
                    }
                }
                if (icomp) {
                    DIFF3(x[(k1 + 1) % nn], xp, d1);
                    fla = MAG3(d1);
                    lenmax = MAX2(fla, lenmax);
                }
                vis_MeshConGetNodePres(p, ix[(k1 + nn - 1) % nn], &pres);
                icomp = 1;
                if (nodepres == SYS_FACE || pres == SYS_FACE) {
                    if (p->colllenmin) {
                        DIFF3(x[(k1 + nn - 1) % nn], x[k1], d1);
                        flb = MAG3(d1);
                        if (flb < p->colllenmin)
                            icomp = 0;
                    }
                }
                if (icomp) {
                    DIFF3(x[(k1 + nn - 1) % nn], xp, d1);
                    fla = MAG3(d1);
                    lenmax = MAX2(fla, lenmax);
                }
            }
            /* compute reference normal */
            if (nn == 3) {
                DIFF3(x[1], x[0], d1);
                DIFF3(x[2], x[0], d2);
            }
            else {
                DIFF3(x[2], x[0], d1);
                DIFF3(x[3], x[1], d2);
            }
            CROSS3(d1, d2, va);
            fla = MAG3(va);
            if (fla != 0.) {
                rl = 1. / fla;
                SCALE3(va, rl);
            }
            /* substitute node and compute new normal */
            MOVE3(xp, x[k1]);
            if (nn == 3) {
                DIFF3(x[1], x[0], d1);
                DIFF3(x[2], x[0], d2);
                CROSS3(d1, d2, vb);
                flb = MAG3(vb);
                if (flb != 0.) {
                    rl = 1. / flb;
                    SCALE3(vb, rl);
                }
            }
            else {
                for (m = 0; m < 2; m++) {
                    DIFF3(x[m + 1], x[m], d1);
                    DIFF3(x[m + 2], x[m], d2);
                    CROSS3(d1, d2, vq[0]);
                    DIFF3(x[m + 2], x[m], d1);
                    DIFF3(x[(m + 3) % 4], x[m], d2);
                    CROSS3(d1, d2, vq[1]);
                    fl = DOT3(vq[0], vq[1]);
                    if (fl <= 0.) {
                        flb = 0.;
                        ZERO3(vb);
                        break;
                    }
                    else {
                        SUM3(vq[0], vq[1], vb);
                        flb = MAG3(vb);
                        UNIT3(vb);
                    }
                }
            }
            /* compute metrics */
            if (p->collmetflag) {
                if (nn == 3) {
                    vis_computeMetricTriangle(vn, x, &metric);
                }
                else {
                    vis_computeMetricQuad(vn, x, &metric);
                }
                if (metric < p->collmet) {
                    *flag = 0;
                    return;
                }
            }
            if (p->collimpflag) {
                vis_computeMetricTriangle(vn, x, &metric);
                metcollmin = MIN2(metcollmin, metric);
            }
            /* compute max angle */
            if (p->collangflag) {
                if (nn == 3) {
                    vis_computeAngle(VIS_SHAPETRI, vn, x, eln, ang, &kmax, &angmax);
                }
                else {
                    vis_computeAngle(VIS_SHAPEQUAD, vn, x, eln, ang, &kmax, &angmax);
                }
                angcollmax = MAX2(angcollmax, angmax);
                if (p->collangimpflag == 0) {
                    if (angmax > p->collang) {
                        *flag = 0;
                        return;
                    }
                }
            }
            /* test normals */
            fl = DOT3(va, vb);
            if (fl < cang) {
                *flag = 0;
#ifdef VISMESH_DEBUGC
                printf("CheckCollapseEdge test normals, fl= %e, cang= %e\n", fl, cang);
#endif
                return;
            }
            /* check against surface normal */
            if (vn != NULL) {
                fl = DOT3(vn, vb);
                if (fl <= 0.) {
                    *flag = 0;
#ifdef VISMESH_DEBUGC
                    printf("CheckCollapseEdge check surface normals, fl= %e\n", fl);
#endif
                    return;
                }
            }
            /* test relative size */
            if (p->collrelflag) {
                if (flb < p->collrel * fla) {
                    *flag = 0;
#ifdef VISMESH_DEBUGC
                    printf("CheckCollapseEdge test relative size, fla= %e, flb= %e\n", fla, flb);
#endif
                    return;
                }
            }
        }
        if (p->collimpflag) {
            if (metcollmin < metorigmin) {
                *flag = 0;
                return;
            }
        }
        if (p->collangimpflag) {
            if (p->collangflag) {
                if (angcollmax > angorigmax && angcollmax > p->collang) {
                    *flag = 0;
                    return;
                }
            }
        }
    }
    if (collflag) {
        if (lenmax > p->colllenmax) {
            *flag = 0;
            return;
        }
    }
    /* check self intersection and degenerate topology */
    nadj = nelem;
    for (i = 0; i < nadj; i++) {
        vis_MeshConGetElem(p, edel[i], &nn, elno, eled);
        nfre = 0;
        for (k = 0; k < 3; k++) {
            if (id != eled[k]) {
                if (p->edge[eled[k]].nelem == 1) {
                    nfre += 1;
                }
            }
        }
        /* stranded triangle */
        if (nfre == 2) {
            *flag = 0;
#ifdef VISMESH_DEBUGC
            printf("CheckCollapseEdge stranded triangle, edel= %d\n", edel[i]);
#endif
            return;
        }
        for (k = 0; k < 3; k++) {
            if (id == eled[k]) {
                napx[i] = elno[(k + 2) % 3];
                vis_MeshConGetNode(p, napx[i], xx);
            }
            else {
                if (elno[k] == node[0] || elno[(k + 1) % 3] == node[0]) {
                    n = 0;
                }
                else {
                    n = 1;
                }
                nelem2 = p->edge[eled[k]].nelem;
                vut_CopyI(p->edge[eled[k]].el, edel1, nelem2);

                if (edel[i] == edel1[0]) {
                    if (nelem2 > 1) {
                        elaid[n] = edel1[1];
                    }
                    else {
                        elaid[n] = 0;
                        break;
                    }
                }
                else {
                    elaid[n] = edel1[0];
                }
                vis_MeshConGetElem(p, elaid[n], &nn1, elno1, eled1);
                /* adjacent quad, skip */
                if (nn1 == 4) {
                    elaid[n] = 0;
                    break;
                }
                for (j = 0; j < 3; j++) {
                    if (eled[k] == eled1[j]) {
                        noaid[n] = elno1[(j + 2) % 3];
                        vis_MeshConGetNode(p, noaid[n], xa[n]);
                        break;
                    }
                }
            }
        }
        /* free edge, no adjacent element */
        if (elaid[n] == 0)
            continue;
        /* degenerate */
        if (noaid[0] == noaid[1]) {
            *flag = 0;
#ifdef VISMESH_DEBUGC
            printf("CheckCollapseEdge degenerate, noaid= %d\n", noaid[0]);
#endif
            return;
        }
        DIFF3(xa[1], xa[0], d);
        for (n = 0; n < nave; n++) {
            if (elaid[n] == 0)
                continue;
            vis_MeshConGetElem(p, elaid[n], &nn, elno, eled);
            for (k = 0; k < nn; k++) {
                vis_MeshConGetNode(p, elno[k], x[k]);
                if (elno[k] == node[n]) {
                    k1 = k;
                }
            }
            /* compute reference normal */
            DIFF3(x[1], x[0], d1);
            DIFF3(x[2], x[0], d2);
            CROSS3(d1, d2, va);
            fla = DOT3(va, d);
            /* substitute node and compute new normal */
            MOVE3(xp, x[k1]);
            DIFF3(x[1], x[0], d1);
            DIFF3(x[2], x[0], d2);
            CROSS3(d1, d2, vb);
            flb = DOT3(vb, d);
            /* changed sign, check */
            if (fla * flb >= 0.)
                continue;
            /* form normal to collapse plane */
            MOVE3(xa[n], xcp[0]);
            MOVE3(xn[n], xcp[1]);
            MOVE3(xp, xcp[2]);

            DIFF3(xcp[1], xcp[0], d1);
            DIFF3(xcp[2], xcp[0], d2);
            CROSS3(d1, d2, vc);
            UNIT3(vc);
            DIFF3(xa[1 - n], xx, e);
            fla = DOT3(e, vc);
            if (fla != 0.) {
                t = (DOT3(xcp[0], vc) - DOT3(xx, vc)) / fla;
                if (t <= 0. || t >= 1.)
                    continue;
                ADD3(xx, t, e, xs);
                vis_invertNCTridv(xcp, xs, r, xi, &ierr);
                if (ierr == 1)
                    continue;
                r[2] = 1. - r[0] - r[1];
                if (r[0] < 0. || r[1] < 0. || r[2] < 0.)
                    continue;
                *flag = 0;
#ifdef VISMESH_DEBUGC
                printf("CheckCollapseEdge degenerate, fla= %e\n", fla);
#endif
                return;
            }
        }
    }
    /* check topology */
    if (p->colltopoflag) {
        vis_MeshConGetNodeNode(p, node[0], &nnoix1, p->inoed);
        /* check connected nodes of second node */
        vis_MeshConGetNodeNode(p, node[1], &nnoix2, p->inoed1);
        for (i = 0; i < nnoix2; i++) {
            vis_MeshConSetNodeStat(p, p->inoed1[i], 0);
        }
        for (i = 0; i < nnoix1; i++) {
            vis_MeshConSetNodeStat(p, p->inoed[i], 1);
        }
        iadj = 0;
        for (i = 0; i < nnoix2; i++) {
            vis_MeshConGetNodeStat(p, p->inoed1[i], &stat);
            if (stat) {
                vis_MeshConFindNodeEdge(p, node[0], p->inoed1[i], &edid);
                vis_MeshConFindNodeEdge(p, node[1], p->inoed1[i], &edid1);
                /* check for both free edge */
                if (p->edge[edid].nelem == 1 && p->edge[edid1].nelem == 1) {
                    *flag = 0;
                    break;
                }
                /* check for both non-manifold edge */
                if (p->edge[edid].nelem > 2 && p->edge[edid1].nelem > 2) {
                    *flag = 0;
                    break;
                }
                found = 0;
                for (j = 0; j < nelem; j++) {
                    for (k = 0; k < p->edge[edid].nelem; k++) {
                        if (edel[j] == p->edge[edid].el[k]) {
                            found = 1;
                            break;
                        }
                    }
                    if (found)
                        break;
                }
                if (found == 0) {
                    *flag = 0;
                    break;
                }
                if (iadj == nadj) {
                    *flag = 0;
#ifdef VISMESH_DEBUGC
                    printf("CheckCollapseEdge topological, iadj= %d\n", iadj);
#endif
                    break;
                }
                else {
                    iadj += 1;
                }
            }
        }
        /* reset status of first set of nodes */
        for (i = 0; i < nnoix1; i++) {
            vis_MeshConSetNodeStat(p, p->inoed[i], 0);
        }
    }
}

extern void
vis_MeshConCheckCollapseEdgeTopo(vis_MeshCon* p, Vint id, Vint noid, Vint* flag)
{
    Vint i;
    Vint nnoix1;
    Vint nnoix2;
    Vint stat;
    Vint node[2];
    Vint nadj, iadj;
    Vint edno[2];

    *flag = 1;
    vis_MeshConGetEdgeNode(p, id, edno);
    vis_MeshConNumEdgeElem(p, id, &nadj);
    if (noid == edno[0]) {
        node[0] = edno[1];
    }
    else {
        node[0] = edno[0];
    }
    node[1] = noid;
    /* this check is essential */
    vis_MeshConGetNodeNode(p, node[0], &nnoix1, p->inoed);
    for (i = 0; i < nnoix1; i++) {
        vis_MeshConSetNodeStat(p, p->inoed[i], 1);
    }
    /* check connected nodes of second node */
    iadj = 0;
    vis_MeshConGetNodeNode(p, node[1], &nnoix2, p->inoed1);
    for (i = 0; i < nnoix2; i++) {
        vis_MeshConGetNodeStat(p, p->inoed1[i], &stat);
        if (stat) {
            if (iadj == nadj) {
                *flag = 0;
#ifdef VISMESH_DEBUGC
                printf("CheckCollapseEdge topological, iadj= %d\n", iadj);
#endif
                break;
            }
            else {
                iadj += 1;
            }
        }
    }
    /* reset status of first set of nodes */
    for (i = 0; i < nnoix1; i++) {
        vis_MeshConSetNodeStat(p, p->inoed[i], 0);
    }
}

extern void
vis_MeshConCheckCollapseEdgeFace(vis_MeshCon* p, Vint id, Vint* flag)
{
    Vint i, k;
    Vint elid, edid, edid1, edid2;
    *flag = 1;
    /* edge not preserved */
    if (p->edge[id].pres == 0)
        return;
    /* test for an attached tri surrounded by preserved edges */
    for (i = 0; i < p->edge[id].nelem; i++) {
        elid = p->edge[id].el[i];
        for (k = 0; k < 3; k++) {
            edid = p->elem[elid].ed[k];
            if (id == edid) {
                edid1 = p->elem[elid].ed[(k + 1) % 3];
                edid2 = p->elem[elid].ed[(k + 2) % 3];
                if (p->edge[edid1].pres && p->edge[edid2].pres) {
                    *flag = 0;
                    return;
                }
            }
        }
    }
}

/*----------------------------------------------------------------------
                      compute crease at new node location
----------------------------------------------------------------------*/
extern void
vis_MeshConCheckCollapseEdgeDAng(vis_MeshCon* p, Vint id, Vint noid, Vint midflag, Vdouble* fl)
{
    static Vchar func[] = "vis_MeshConCheckCollapseEdgeDAng";
    Vint i, j, k;
    Vint noidp, nave, node[2];
    Vint ifirst, elid, nn1, elno1[3], edel1[3];
    Vint edel[2], edno[2], nelix, k1;
    Vdouble xp[3], d1[3], d2[3], vn[3], vr[3], fld, x[3][3];

    if (p->edge[id].pres) {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR1(func, p->ierr, "check preserved edge, id= %d", id);
        return;
    }
    if (p->edge[id].no[0] == noid) {
        noidp = p->edge[id].no[1];
    }
    else if (p->edge[id].no[1] == noid) {
        noidp = p->edge[id].no[0];
    }
    else {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR2(func, p->ierr, "id= %d, noid= %d", id, noid);
        return;
    }
    if (midflag) {
        nave = 2;
        MID3(p->node[noid].x, p->node[noidp].x, xp);
        /* use noid location */
    }
    else {
        nave = 1;
        MOVE3(p->node[noid].x, xp);
    }
    vis_MeshConGetEdge(p, id, edno, edel);
    if (noid == edno[0]) {
        node[0] = edno[1];
    }
    else {
        node[0] = edno[0];
    }
    node[1] = noid;
    ifirst = 0;
    for (j = 0; j < nave; j++) {
        vis_MeshConGetNodeElem(p, node[j], &nelix, p->inoed);
        for (i = 0; i < nelix; i++) {
            elid = p->inoed[i];
            if (elid == edel[0] || elid == edel[1])
                continue;
            vis_MeshConGetElem(p, elid, &nn1, elno1, edel1);
            for (k = 0; k < nn1; k++) {
                vis_MeshConGetNode(p, elno1[k], x[k]);
                if (elno1[k] == node[j]) {
                    k1 = k;
                }
            }
            MOVE3(xp, x[k1]);
            DIFF3(x[1], x[0], d1);
            DIFF3(x[2], x[0], d2);
            CROSS3(d1, d2, vn);
            UNIT3(vn);
            if (ifirst == 0) {
                *fl = 1.;
                MOVE3(vn, vr);
                ifirst = 1;
            }
            else {
                fld = DOT3(vn, vr);
                *fl = MIN2(fld, *fl);
            }
        }
    }
}

/*----------------------------------------------------------------------
                      collapse edge
----------------------------------------------------------------------*/
extern void
vis_MeshConCollapseEdge(vis_MeshCon* p, Vint id, Vint noid, Vint midflag)
{
    static Vchar func[] = "vis_MeshConCollapseEdge";
    Vint i, j, k, m, mp;
    Vint nn, edid, k1, eid, edidp;
    Vint im[MESHCON_MAXNMT], ie[MESHCON_MAXNMT], list[MESHCON_MAXNMT];
    Vint noidp, noidq;
    Vint edab[MESHCON_MAXNMT], edabp[MESHCON_MAXNMT];
    Vint in, inoed;
    Vdouble xp[3], ved[2][3], fl;
    Vint kf, kfn, frid, nelem, found, l, el, nel, inormtran;

    /* check for edge connected to front */
    nelem = p->edge[id].nelem;
    for (k = 0; k < nelem; k++) {
        if (p->edge[id].fr[k]) {
            p->ierr = SYS_ERROR_OPERATION;
            HANDLEERR1(func, p->ierr, "edge with front, id= %d", id);
            return;
        }
    }
#ifdef VISMESH_DEBUGC
    if (id == 0) {
        p->funflag = 1;
        printf("id= %d  noid= %d\n", id, noid);
    }
#endif
    /* identify node to be collapsed */
    /*  noid is the node we are keeping;
        noidp is the one we may move unless midflag is set */
    if (p->edge[id].no[0] == noid) {
        noidp = p->edge[id].no[1];
    }
    else if (p->edge[id].no[1] == noid) {
        noidp = p->edge[id].no[0];
    }
    else {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR2(func, p->ierr, "id= %d, noid= %d", id, noid);
        return;
    }
    p->ncollapseedge += 1;
    /* use noid location */
    if (midflag == 0) {
        MOVE3(p->node[noid].x, xp);
        /* compute average node location */
    }
    else if (midflag == 1) {
        MID3(p->node[noid].x, p->node[noidp].x, xp);
    }
    /* identify collapsed edge on adjacent elements */
    for (k = 0; k < nelem; k++) {
        m = p->edge[id].el[k];
        nn = p->elem[m].nn;
        for (k1 = 0; k1 < nn; k1++) {
            if (p->elem[m].ed[k1] == id) {
                ie[k] = k1;
            }
            if (p->elem[m].ne == NULL)
                continue;
            /* do not propagate normals across a preserved node */
            if (p->node[noidp].pres == SYS_NODE)
                continue;
            if (p->normalflag) {
                if (p->elem[m].no[k1] == noid) {
                    vis_MeshConGetNodeCCWPresBound(p, noidp, m, &nel, p->inoed1);
                    for (i = 0; i < nel; i++) {
                        eid = p->inoed1[i];
                        if (eid == m)
                            continue;
                        for (j = 0; j < p->elem[eid].nn; j++) {
                            if (p->elem[eid].no[j] == noidp) {
                                /* check for tri normal difference */
                                inormtran = 1;
                                if (p->collnormangflag) {
                                    fl = DOT3(p->elem[m].ne[k1], p->elem[eid].ne[j]);
                                    if (fl < p->collnormang) {
                                        inormtran = 0;
                                    }
                                }
                                if (inormtran) {
                                    MOVE3(p->elem[m].ne[k1], p->elem[eid].ne[j]);
                                }
                            }
                        }
                    }
                }
            }
        }
        /* save other node on first triangle */
        if (k == 0 && nn == 3) {
            for (k1 = 0; k1 < nn; k1++) {
                if (p->elem[m].no[k1] != noid && p->elem[m].no[k1] != noidp) {
                    noidq = p->elem[m].no[k1];
                    break;
                }
            }
        }
    }
    /* identify surrounding edges and elements */
    for (k = 0; k < nelem; k++) {
        m = p->edge[id].el[k];
        im[k] = m;
        nn = p->elem[m].nn;
        k1 = ie[k];
        if (p->elem[m].no[k1] == noid) {
            edab[k] = p->elem[m].ed[(k1 + 2) % nn];
            edabp[k] = p->elem[m].ed[(k1 + 1) % nn];
        }
        else {
            edab[k] = p->elem[m].ed[(k1 + 1) % nn];
            edabp[k] = p->elem[m].ed[(k1 + 2) % nn];
        }
    }
    /* loop through edges and elements attached to noidp */
    inoed = p->node[noidp].noed;
    in = 0;
    for (j = 0; j < p->node[noidp].ned; j++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        if (edid == id)
            continue;
        /* replace noidp with noid in edge nodes and front nodes */
        for (k = 0; k < 2; k++) {
            if (p->edge[edid].no[k] == noidp) {
                p->edge[edid].no[k] = noid;
                for (kf = 0; kf < p->edge[edid].nelem; kf++) {
                    frid = p->edge[edid].fr[kf];
                    if (frid) {
                        for (kfn = 0; kfn < 2; kfn++) {
                            if (p->frnt[frid].no[kfn] == noidp) {
                                p->frnt[frid].no[kfn] = noid;
                            }
                        }
                    }
                }
            }
        }
        /* replace noidp with noid in element connectivity */
        for (k = 0; k < p->edge[edid].nelem; k++) {
            m = p->edge[edid].el[k];
            nn = p->elem[m].nn;
            for (k1 = 0; k1 < nn; k1++) {
                if (p->elem[m].no[k1] == noidp) {
                    p->elem[m].no[k1] = noid;
                }
            }
        }
        found = 0;
        for (k = 0; k < nelem; ++k) {
            if (edid == edabp[k]) {
                found = 1;
            }
        }
        if (!found) {
            vis_MeshCon_IncNode(p, noid, edid);
        }
    }
    /* update extended node pres */
    if (p->extendflag == 1 || p->extendflag == 2) {
        if (p->node[noidp].pres == SYS_NODE || p->node[noidp].pres == SYS_NONE) {
            if (p->node[noid].pres == SYS_NODE || p->node[noid].pres == SYS_NONE) {
                vis_MeshCon_AppPind(p, &p->node[noid].pind, p->node[noidp].pind);
            }
            else {
                p->node[noid].pres = p->node[noidp].pres;
                p->node[noid].pind = p->node[noidp].pind;
            }
        }
    }
    /* delete noidp */
    vis_MeshConDelNode(p, noidp);

    /* loop through surrounding elements to replace edges */
    for (k = 0; k < nelem; k++) {
        edid = edab[k];
        edidp = edabp[k];
        for (l = 0; l < p->edge[edidp].nelem; l++) {
            m = p->edge[edidp].el[l];
            if (m == im[k])
                continue;
            frid = p->edge[edidp].fr[l];
            /* do not allow nonmanifold edge to merge */
            if (frid) {
                if (p->edge[edabp[k]].nelem > 2) {
                    p->ierr = SYS_ERROR_OPERATION;
                    HANDLEERR1(func, p->ierr, "non-manifold edge merge, id= %d", edabp[k]);
                    return;
                }
            }
            nn = p->elem[m].nn;
            for (k1 = 0; k1 < nn; k1++) {
                if (edidp == p->elem[m].ed[k1]) {
                    p->elem[m].ed[k1] = edid;
                    vis_MeshCon_IncEdge(p, edid, m);
                    if (frid) {
                        p->edge[edid].fr[p->edge[edid].nelem - 1] = frid;
                        p->frnt[frid].elid = m;
                        p->frnt[frid].elk = k1;
                    }
                    break;
                }
            }
        }
        /* front facing edid */
        /* only if no fronts on edidp */
        frid = 0;
        mp = 0;
        for (l = 0; l < p->edge[edid].nelem; l++) {
            m = p->edge[edid].el[l];
            if (m == im[k]) {
                frid = p->edge[edid].fr[l];
            }
            else {
                mp = m;
            }
        }
        if (frid && mp) {
            for (l = 0; l < p->edge[edid].nelem; l++) {
                m = p->edge[edid].el[l];
                if (m == mp) {
                    p->edge[edid].fr[l] = frid;
                    p->frnt[frid].elid = mp;
                    p->frnt[frid].elk = k1;
                    break;
                }
            }
        }
    }
    /* remove edges and delete elements */
    for (k = 0; k < nelem; k++) {
        if (p->edge[edabp[k]].pres) {
            if (p->edge[edab[k]].pres) {
                if (p->extendflag == 1 || p->extendflag == 2) {
                    vis_MeshCon_AddPind(p, &p->edge[edab[k]].pind, p->edge[edabp[k]].pres);
                    vis_MeshCon_AppPind(p, &p->edge[edab[k]].pind, p->edge[edabp[k]].pind);
                }
            }
            else {
                vis_MeshConSetEdgePres(p, edab[k], p->edge[edabp[k]].pres);
                p->edge[edab[k]].pind = p->edge[edabp[k]].pind;
                p->edge[edab[k]].size = p->edge[edabp[k]].size;
                /* align retained edge connectivity with merged edge */
                if (p->edge[edabp[k]].no[0] == p->edge[edab[k]].no[1]) {
                    vis_MeshConReverseEdge(p, edab[k]);
                }
                if (p->normalflag) {
                    if (p->edge[edabp[k]].ns) {
                        MOVE3(p->edge[edabp[k]].ns[0], ved[0]);
                        MOVE3(p->edge[edabp[k]].ns[1], ved[1]);
                        vis_MeshConSetEdgeTang(p, edab[k], ved);
                    }
                }
            }
        }
        if (p->edge[edab[k]].pref == 0) {
            p->edge[edab[k]].pref = p->edge[edabp[k]].pref;
        }
        j = 0;
        for (l = 0; l < p->edge[edabp[k]].nelem; ++l) {
            el = p->edge[edabp[k]].el[l];
            if (el == im[k])
                continue;
            list[j++] = el;
        }
        for (l = 0; l < j; ++l) {
            vis_MeshCon_DecEdge(p, edabp[k], list[l], 1);
        }
        vis_MeshConDelElem(p, im[k]);
    }
    /* set node location */
    /* any metrics are updated by this call */
    vis_MeshConSetNode(p, noid, xp);
    /* check to see if two opposing triangles removed */
    if (p->node[noid].ned == 0) {
        vis_MeshConDelNode(p, noid);
        vis_MeshConDelNode(p, noidq);
    }
    /* check consistency */
    if (p->mconsistent) {
        p->nconsistent += 1;
        if (p->nconsistent % p->mconsistent == 0) {
            vis_MeshConConsistent(p);
        }
    }
}

/*----------------------------------------------------------------------
                      recover edge in xy plane
----------------------------------------------------------------------*/
extern void
vis_MeshConRecoverEdge2Dim(vis_MeshCon* p, Vint ix[2], Vint* edid)
{
    static Vchar func[] = "vis_MeshConRecoverEdge2Dim";
    Vint i, k;
    Vint nixe;
    Vint nedl, medl, icur;
    Vint edi, edno[2], edel[2];
    Vint elidf, elkf;
    Vint edidi, elidi, elidp, noidi, numedfr, pres;
    Vint nn, elno[4], eled[4];
    Vint iq[4], iqe[4];
    Vdouble xq[4][3];
    Vdouble xe[2][3], xd[2][3], xi[3];
    Vdouble area, area1, area2;
    /* make a quick check */
    vis_MeshConMatchNodeNode(p, ix[0], ix[1], edid);
    if (*edid)
        return;
    vis_MeshConGetNodes(p, 2, ix, xe);

    /* find initial edge in edge list */
    vis_MeshConGetNodeCCWEdge(p, ix[0], &nixe, p->inoed);
    edi = -1;
    for (i = 0; i < nixe; i++) {
        vis_MeshConGetEdgeNode(p, p->inoed[i], edno);
        vis_MeshConGetNodes(p, 2, edno, xd);
        if (edno[0] == ix[0]) {
            area = vsy_PredOrient2d(p->pred, xe[0], xd[1], xe[1]);
        }
        else {
            area = vsy_PredOrient2d(p->pred, xe[0], xd[0], xe[1]);
        }
        if (area > 0.) {
            edi = i;
        }
        else {
            if (edi != -1)
                break;
        }
    }
    if (edi == -1) {
        edi = 0;
    }
    vis_MeshConGetLeftElem(p, ix[0], p->inoed[edi], &elidf, &elkf);
    /* hole encountered */
    if (elidf == 0) {
        return;
    }
    vis_MeshConGetElem(p, elidf, &nn, elno, eled);
    /* quad element encountered */
    if (nn == 4) {
        return;
    }
    edidi = eled[(elkf) % nn];
    elidi = elidf;
    p->iedl[0] = edidi;
    nedl = 1;
    for (;;) {
        vis_MeshConGetEdge(p, edidi, edno, edel);
        vis_MeshConNumEdgeFrnt(p, edidi, &numedfr);
        /* edge on front */
        if (numedfr) {
            return;
        }
        vis_MeshConGetEdgePres(p, edidi, &pres);
        /* edge preserved */
        if (pres) {
            return;
        }
        if (edel[0] == elidi) {
            elidp = edel[1];
        }
        else {
            elidp = edel[0];
        }
        /* hole */
        if (elidp == 0) {
            return;
        }
        vis_MeshConGetElem(p, elidp, &nn, elno, eled);
        /* quad */
        if (nn == 4) {
            return;
        }
        if (ix[1] == elno[0] || ix[1] == elno[1] || ix[1] == elno[2]) {
            break;
        }
        elidi = elidp;
        for (k = 0; k < 3; k++) {
            if (edidi == eled[k]) {
                noidi = elno[(k + 2) % 3];
                break;
            }
        }
        vis_MeshConGetNode(p, noidi, xi);
        area = vsy_PredOrient2d(p->pred, xe[0], xi, xe[1]);
        /* point on edge */
        if (area == 0.) {
            return;
        }

        if (area > 0.) {
            edidi = eled[(k + 2) % nn];
        }
        else {
            edidi = eled[(k + 1) % nn];
        }
        p->iedl[nedl] = edidi;
        nedl += 1;
        if (nedl == p->numedge) {
            *edid = 0;
            return;
        }
        if (nedl == p->mxiedl) {
            p->mxiedl += 1000;
            p->iedl = (Vint*)vut_reallocMem(p->iedl, (p->mxiedl + 1) * sizeof(Vint));
            if (p->iedl == NULL) {
                p->ierr = VIS_ERROR_MEMORY;
                HANDLEERR0(func, p->ierr, "Realloc iedl");
                return;
            }
        }
    }
    /* now swap until top edge is recovered */
    /* do simple case of one edge */
    if (nedl == 1) {
        vis_MeshConSwapEdge(p, p->iedl[0]);
        *edid = p->iedl[0];
        return;
    }
    /* do hard case */
    medl = nedl;
    icur = 0;
    for (;;) {
        if (icur == p->mxiedl) {
            p->mxiedl += 1000;
            p->iedl = (Vint*)vut_reallocMem(p->iedl, (p->mxiedl + 1) * sizeof(Vint));
            if (p->iedl == NULL) {
                p->ierr = VIS_ERROR_MEMORY;
                HANDLEERR0(func, p->ierr, "Realloc iedl");
                return;
            }
        }
        if (icur == nedl)
            break;
        vis_MeshConGetEdgeQuad(p, p->iedl[icur], iq, iqe);
        vis_MeshConGetNodes(p, 4, iq, xq);
        area1 = vsy_PredOrient2d(p->pred, xq[0], xq[1], xq[3]);
        area2 = vsy_PredOrient2d(p->pred, xq[1], xq[2], xq[3]);
        if (area1 > 0. && area2 > 0.) {
            vis_MeshConSwapEdge(p, p->iedl[icur]);
            /* connected to end points */
            if (iq[1] == ix[0] || iq[1] == ix[1] || iq[3] == ix[0] || iq[3] == ix[1]) {
                *edid = p->iedl[icur];
                icur += 1;
                continue;
                /* does not intersect Vs */
            }
            else {
                area1 = vsy_PredOrient2d(p->pred, xe[0], xq[1], xe[1]);
                area2 = vsy_PredOrient2d(p->pred, xe[0], xq[3], xe[1]);
                if (area1 * area2 > 0.) {
                    icur += 1;
                    continue;
                }
            }
        }
        if (icur + 1 == nedl || nedl > 100 * medl) {
            *edid = 0;
            return;
        }
        p->iedl[nedl] = p->iedl[icur];
        nedl += 1;
        icur += 1;
        if (nedl == p->mxiedl) {
            p->mxiedl += 1000;
            p->iedl = (Vint*)vut_reallocMem(p->iedl, (p->mxiedl + 1) * sizeof(Vint));
            if (p->iedl == NULL) {
                p->ierr = VIS_ERROR_MEMORY;
                HANDLEERR0(func, p->ierr, "Realloc iedl");
                return;
            }
        }
    }
}

/*----------------------------------------------------------------------
                      swap quad
----------------------------------------------------------------------*/
static void
vis_MeshCon_SwapQuad(vis_MeshCon* p, Vdouble x[4][3], Vint* flag)
{
    Vdouble d1[3], d2[3], d3[3], d4[3];
    Vdouble va[3], vb[3], s;
    /* flag =  1 swap*/
    /* convexity check */
    DIFF3(x[1], x[0], d1);
    UNIT3(d1);
    DIFF3(x[3], x[0], d2);
    UNIT3(d2);
    CROSS3(d1, d2, va);
    DIFF3(x[3], x[2], d3);
    UNIT3(d3);
    DIFF3(x[1], x[2], d4);
    UNIT3(d4);
    CROSS3(d3, d4, vb);

    s = DOT3(va, vb);
    if (s > p->recovercos) {
        *flag = 1;
    }
    else {
        *flag = 0;
    }
}

/*----------------------------------------------------------------------
                      recover edge
----------------------------------------------------------------------*/
extern void
vis_MeshConRecoverEdge(vis_MeshCon* p, Vdouble ve[3], Vint ix[2], Vint* edid)
{
    static Vchar func[] = "vis_MeshConRecoverEdge";
    Vint i, k;
    Vint nixe;
    Vint nedl, medl, icur;
    Vint edno[2], edel[2];
    Vdouble xe[2][3], vs[3], vn[3], vl[3];
    Vdouble xd[2][3], vd[3];
    Vint edi;
    Vint elidf, elkf;
    Vint edidi, elidi, elidp, noidi, elidt, elid;
    Vint nn, elno[4], eled[4];
    Vdouble xi[3], vi[3], dt, dtmax;
    Vint iq[4], iqe[4];
    Vdouble xq[4][3], xql[4][3];
    Vdouble xt[3], dt1, dt2;
    Vint flag, imatch;
    Vint pres, ptid;
    Vint numedfr;
    Vdouble tm[3][3];
    /* ve normal to surface */
    /* make a quick check */
    vis_MeshConMatchNodeNode(p, ix[0], ix[1], edid);
    if (*edid)
        return;
    /* form vs from ix[1] to ix[0] */
    vis_MeshConGetNode(p, ix[0], xe[0]);
    vis_MeshConGetNode(p, ix[1], xe[1]);
    /* form vn for simple dot product test for edge vectors */
    DIFF3(xe[0], xe[1], vs);
    UNIT3(vs);
    CROSS3(vs, ve, vn);
    UNIT3(vn);
    /* find element most closely aligned to input normal */
    elidt = 0;
    dtmax = -2.;
    vis_MeshConGetNodeElem(p, ix[1], &nixe, p->inoed);
    for (i = 0; i < nixe; i++) {
        elid = p->inoed[i];
        if (p->patchrestrict) {
            pres = p->elem[elid].pres;
            if (p->gm) {
                vis_MeshConGetElemPres(p->gm, pres, &ptid);
            }
            else {
                ptid = pres;
            }
            if (p->patchrestrict != ptid)
                continue;
        }
        vis_MeshConFlatNormal(p, elid, vl);
        dt = DOT3(ve, vl);
        if (dt > dtmax) {
            elidt = elid;
            dtmax = dt;
        }
    }
    /* find initial edge in edge list */
    vis_MeshConGetNodeCCWNMBound(p, ix[1], elidt, &nixe, p->inoed);
    edi = -1;
    for (i = 0; i < nixe; i++) {
        vis_MeshConGetEdgeNode(p, p->inoed[i], edno);
        vis_MeshConGetNode(p, edno[0], xd[0]);
        vis_MeshConGetNode(p, edno[1], xd[1]);
        if (ix[1] == edno[0]) {
            DIFF3(xd[1], xd[0], vd);
        }
        else {
            DIFF3(xd[0], xd[1], vd);
        }
        dt = DOT3(vd, vn);
        if (dt >= 0.) {
            edi = i;
        }
        else {
            if (edi != -1)
                break;
        }
    }
    if (edi == -1) {
#ifdef VISMESH_DEBUGR
        printf(" RecoverEdge failure, ix= %d %d\n", ix[0], ix[1]);
        printf("   Boundary initially encountered, edge= %d\n", p->inoed[edi]);
        if (p->funflag) {
            if (p->fun) {
                p->fun(p, p->funobject);
            }
        }
#endif
        return;
    }
    vis_MeshConGetLeftElem(p, ix[1], p->inoed[edi], &elidf, &elkf);
    if (elidf == 0) {
#ifdef VISMESH_DEBUGR
        printf(" RecoverEdge failure, ix= %d %d\n", ix[0], ix[1]);
        printf("   Hole initially encountered, edge= %d\n", p->inoed[edi]);
        if (p->funflag) {
            if (p->fun) {
                p->fun(p, p->funobject);
            }
        }
#endif
        return;
    }
    vis_MeshConGetElem(p, elidf, &nn, elno, eled);
    if (nn == 4) {
#ifdef VISMESH_DEBUGR
        printf(" RecoverEdge failure, ix= %d %d\n", ix[0], ix[1]);
        printf("   Quad element initially encountered, elidf= %d, nn= %d\n", elidf, nn);
        if (p->funflag) {
            if (p->fun) {
                p->fun(p, p->funobject);
            }
        }
#endif
        return;
    }
    edidi = eled[(elkf) % nn];
    elidi = elidf;
    p->iedl[0] = edidi;
    nedl = 1;
    for (;;) {
        vis_MeshConGetEdge(p, edidi, edno, edel);
        vis_MeshConNumEdgeFrnt(p, edidi, &numedfr);
        if (numedfr) {
#ifdef VISMESH_DEBUGR
            printf(" RecoverEdge failure, ix= %d %d\n", ix[0], ix[1]);
            printf("   edge on front, edidi= %d, nodes= %d %d\n", edidi, edno[0], edno[1]);
            if (p->funflag) {
                if (p->fun) {
                    p->fun(p, p->funobject);
                }
            }
#endif
            return;
        }
        vis_MeshConGetEdgePres(p, edidi, &pres);
        if (pres) {
#ifdef VISMESH_DEBUGR
            printf(" RecoverEdge failure, ix= %d %d\n", ix[0], ix[1]);
            printf("   edge preserved, edidi= %d, nodes= %d %d\n", edidi, edno[0], edno[1]);
            if (p->funflag) {
                if (p->fun) {
                    p->fun(p, p->funobject);
                }
            }
#endif
            return;
        }
        if (edel[0] == elidi) {
            elidp = edel[1];
        }
        else {
            elidp = edel[0];
        }
        if (elidp == 0) {
#ifdef VISMESH_DEBUGR
            printf(" RecoverEdge failure, ix= %d %d\n", ix[0], ix[1]);
            printf("   Hole encountered\n");
            if (p->funflag) {
                if (p->fun) {
                    p->fun(p, p->funobject);
                }
            }
#endif
            return;
        }
        vis_MeshConGetElem(p, elidp, &nn, elno, eled);
        if (nn == 4) {
#ifdef VISMESH_DEBUGR
            printf(" RecoverEdge failure, ix= %d %d\n", ix[0], ix[1]);
            printf("   Quad element encountered, elidp= %d, nn= %d\n", elidp, nn);
            if (p->funflag) {
                if (p->fun) {
                    p->fun(p, p->funobject);
                }
            }
#endif
            return;
        }
        if (ix[0] == elno[0] || ix[0] == elno[1] || ix[0] == elno[2]) {
            break;
        }
        elidi = elidp;
        for (k = 0; k < 3; k++) {
            if (edidi == eled[k]) {
                noidi = elno[(k + 2) % 3];
                break;
            }
        }
        vis_MeshConGetNode(p, noidi, xi);
        DIFF3(xi, xe[1], vi);
        UNIT3(vi);
        dt = DOT3(vi, vn);
        /* check closeness to parallel */
        if (fabs(dt) <= p->recovercos) {
            return;
        }
        if (dt == 0.) {
            dt1 = DOT3(vi, vs);
            if (dt1 >= 0.) {
#ifdef VISMESH_DEBUGR
                printf(" RecoverEdge failure, noidi= %d, ix[1]= %d\n", noidi, ix[1]);
                printf("   parallel edge encountered, edge= %d\n", edidi);
                if (p->funflag) {
                    if (p->fun) {
                        p->fun(p, p->funobject);
                    }
                }
#endif
                return;
            }
        }
        if (dt >= 0.) {
            edidi = eled[(k + 2) % nn];
        }
        else {
            edidi = eled[(k + 1) % nn];
        }
        p->iedl[nedl] = edidi;
        nedl += 1;
        if (nedl == p->numedge) {
            *edid = 0;
            return;
        }
        if (nedl == p->mxiedl) {
            p->mxiedl += 1000;
            p->iedl = (Vint*)vut_reallocMem(p->iedl, (p->mxiedl + 1) * sizeof(Vint));
            if (p->iedl == NULL) {
                p->ierr = VIS_ERROR_MEMORY;
                HANDLEERR0(func, p->ierr, "Realloc iedl");
                return;
            }
        }
    }
    /* now swap until top edge is recovered */
    /* form local triad */
    MOVE3(vn, tm[0]);
    MOVE3(vs, tm[1]);
    CROSS3(tm[0], tm[1], tm[2]);
    /* do hard case */
    medl = nedl;
    icur = 0;
    for (;;) {
        if (icur == p->mxiedl) {
            p->mxiedl += 1000;
            p->iedl = (Vint*)vut_reallocMem(p->iedl, (p->mxiedl + 1) * sizeof(Vint));
            if (p->iedl == NULL) {
                p->ierr = VIS_ERROR_MEMORY;
                HANDLEERR0(func, p->ierr, "Realloc iedl");
                return;
            }
        }
        if (icur == nedl)
            break;
        vis_MeshConGetEdgeQuad(p, p->iedl[icur], iq, iqe);
        for (i = 0; i < 4; i++) {
            vis_MeshConGetNode(p, iq[i], xq[i]);
            ADD3(xq[i], -1., xe[1], xt);
            MATTVEC3(tm, xt, xql[i]);
            xql[i][2] = 0.;
        }
        vis_MeshCon_SwapQuad(p, xql, &flag);
        /* do not patch restrict */
        if (flag == 1) {
            vis_MeshConFindNodeEdge(p, iq[1], iq[3], &imatch);
            if (imatch)
                flag = 0;
        }
        if (flag == 1) {
            vis_MeshConSwapEdge(p, p->iedl[icur]);
            /* connected to end points */
            if (iq[1] == ix[0] || iq[1] == ix[1] || iq[3] == ix[0] || iq[3] == ix[1]) {
                *edid = p->iedl[icur];
                icur += 1;
                continue;
                /* does not intersect Vs */
            }
            else {
                DIFF3(xq[1], xe[1], xt);
                dt1 = DOT3(xt, vn);
                DIFF3(xq[3], xe[1], xt);
                dt2 = DOT3(xt, vn);
                if (dt1 * dt2 > 0.) {
                    icur += 1;
                    continue;
                }
            }
        }
        if (icur + 1 == nedl || nedl > 100 * medl) {
            *edid = 0;
            return;
        }
        p->iedl[nedl] = p->iedl[icur];
        nedl += 1;
        icur += 1;
        if (nedl == p->mxiedl) {
            p->mxiedl += 1000;
            p->iedl = (Vint*)vut_reallocMem(p->iedl, (p->mxiedl + 1) * sizeof(Vint));
            if (p->iedl == NULL) {
                p->ierr = VIS_ERROR_MEMORY;
                HANDLEERR0(func, p->ierr, "Realloc iedl");
                return;
            }
        }
    }
}

extern void
vis_MeshConCreateEdge(vis_MeshCon* p, Vdouble ve[3], Vint ix[2], Vint* edid)
{
    Vint i;
    Vdouble x0[3], x1[3], d[3], x[3], fl, flmn;
    Vint num, edno[2], edel[2], elid, idc, idmn, pres, ptid;
    Vint noid, nodepres;

    vis_MeshConGetNode(p, ix[0], x0);
    vis_MeshConGetNode(p, ix[1], x1);
    DIFF3(x1, x0, d);
    UNIT3(d);
    for (;;) {
        vis_MeshConRecoverEdge(p, ve, ix, edid);
        if (*edid)
            return;
        /* collapse an edge and try again */
        vis_MeshConGetNodeEdge(p, ix[0], &num, p->inoed);
        idmn = 0;
        for (i = 0; i < num; i++) {
            idc = p->inoed[i];
            if (p->edge[idc].pres)
                continue;
            vis_MeshConGetEdge(p, idc, edno, edel);
            if (p->patchrestrict) {
                elid = edel[0];
                pres = p->elem[elid].pres;
                if (p->gm) {
                    vis_MeshConGetElemPres(p->gm, pres, &ptid);
                }
                else {
                    ptid = pres;
                }
                if (p->patchrestrict != ptid)
                    continue;
            }
            if (ix[0] == edno[0]) {
                noid = edno[1];
            }
            else {
                noid = edno[0];
            }
            vis_MeshConGetNodePres(p, noid, &nodepres);
            if (nodepres != SYS_FACE)
                continue;
            vis_MeshConGetNode(p, noid, x);
            fl = LEN3(x, x0);
            if (idmn == 0 || fl < flmn) {
                flmn = fl;
                idmn = idc;
            }
        }
        if (idmn) {
            vis_MeshConCollapseEdge(p, idmn, ix[0], 0);
        }
    }
}

/*----------------------------------------------------------------------
                      merge edge
----------------------------------------------------------------------*/
extern void
vis_MeshConMergeEdge(vis_MeshCon* p, Vint id, Vint idm)
{
    Vint i, k;
    Vint nelem;
    Vint elid, nn;
    Vint el[MESHCON_MAXNMT];
    /* merge edge id to idm */
    /* process each element on edge id */
    nelem = p->edge[id].nelem;
    for (i = 0; i < nelem; i++) {
        elid = p->edge[id].el[i];
        el[i] = elid;
        nn = p->elem[elid].nn;
        /* find edge id on element */
        for (k = 0; k < nn; k++) {
            if (p->elem[elid].ed[k] == id) {
                p->elem[elid].ed[k] = idm;
                break;
            }
        }
    }
    for (i = 0; i < nelem; i++) {
        vis_MeshCon_DecEdge(p, id, el[i], 1);
        vis_MeshCon_IncEdge(p, idm, el[i]);
    }
}

/*----------------------------------------------------------------------
                      set edge stat
----------------------------------------------------------------------*/
extern void
vis_MeshConSetEdgeStat(vis_MeshCon* p, Vint id, Vint stat)
{
    Vint iter, edid;

    if (id > 0) {
        p->edge[id].stat = stat;
    }
    else {
        iter = 0;
        for (;;) {
            if (iter == 0) {
                edid = p->headedge;
                iter = edid;
            }
            else {
                edid = p->edge[iter].next;
                if (edid != 0) {
                    iter = edid;
                }
            }
            if (edid == 0)
                break;
            /* GHF */
            p->edge[edid].stat = 0;
            if (id == MESHCON_STAT_ALL) {
                p->edge[edid].stat = stat;
            }
            else if (id == MESHCON_STAT_FREE) {
                if (p->edge[edid].el[1] == 0) {
                    p->edge[edid].stat = stat;
                }
            }
            else if (id == MESHCON_STAT_PRES) {
                if (p->edge[edid].pres) {
                    p->edge[edid].stat = stat;
                }
            }
            else if (id == MESHCON_STAT_PREF) {
                if (p->edge[edid].pref) {
                    p->edge[edid].stat = stat;
                }
            }
            else if (id == MESHCON_STAT_TEMP) {
                if (p->edge[edid].pres < 0) {
                    p->edge[edid].stat = stat;
                }
            }
            else {
                p->edge[edid].stat = stat;
            }
        }
    }
}

extern void
vis_MeshConPushNodeEdge(vis_MeshCon* p, Vint id)
{
    Vint i, m, k;
    Vint edid, elid, edid1;
    Vint in, inoed;
    Vint nn;

    inoed = p->node[id].noed;
    in = 0;
    for (i = 0; i < p->node[id].ned; i++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        edid = p->noed[inoed].ed[in];
        for (m = 0; m < p->edge[edid].nelem; m++) {
            elid = p->edge[edid].el[m];
            if (elid) {
                nn = p->elem[elid].nn;
                for (k = 0; k < nn; k++) {
                    edid1 = p->elem[elid].ed[k];
                    vis_MeshConPushEdge(p, edid1);
                }
            }
        }
    }
}

extern void
vis_MeshConGetEdgeStat(vis_MeshCon* p, Vint id, Vint* stat)
{
    static Vchar func[] = "vis_MeshConGetEdgeStat";

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    *stat = p->edge[id].stat;
}

extern void
vis_MeshConSetEdgePres(vis_MeshCon* p, Vint id, Vint pres)
{
    p->edge[id].pres = pres;
    if (pres >= 0) {
        vsy_IntVecSet(p->ived, pres, id);
    }
}

extern void
vis_MeshConGetEdgePres(vis_MeshCon* p, Vint id, Vint* pres)
{
    static Vchar func[] = "vis_MeshConGetEdgePres";

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    *pres = p->edge[id].pres;
}

extern void
vis_MeshConGetPresEdge(vis_MeshCon* p, Vint pres, Vint* id)
{
    static Vchar func[] = "vis_MeshConGetPresEdge";
    if (pres >= 0) {
        vsy_IntVecGet(p->ived, pres, id);
    }
    else {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "pres= %d", pres);
        return;
    }
}

/*----------------------------------------------------------------------
                      set edge topology
----------------------------------------------------------------------*/
extern void
vis_MeshConSetEdgeTopo(vis_MeshCon* p, Vint id, Vint topo)
{
    /* 8 bits each - rate, nlay, flag, feat */
    p->edge[id].topo = topo;
}

extern void
vis_MeshConSetEdgeTopoFeat(vis_MeshCon* p, Vint id, Vint feat)
{
    p->edge[id].topo &= 0xffffff00;
    p->edge[id].topo |= feat;
}

extern void
vis_MeshConGetEdgeTopoFeat(vis_MeshCon* p, Vint id, Vint* feat)
{
    *feat = p->edge[id].topo & 0xff;
}

extern void
vis_MeshConSetEdgeTopoFlag(vis_MeshCon* p, Vint id, Vint flag)
{
    p->edge[id].topo &= 0xffff00ff;
    p->edge[id].topo |= (flag << 8);
}

extern void
vis_MeshConGetEdgeTopoFlag(vis_MeshCon* p, Vint id, Vint* flag)
{
    *flag = (p->edge[id].topo >> 8) & 0xff;
}

extern void
vis_MeshConSetEdgeTopoLays(vis_MeshCon* p, Vint id, Vint lays)
{
    p->edge[id].topo &= 0xff00ffff;
    p->edge[id].topo |= (lays << 16);
}

extern void
vis_MeshConGetEdgeTopoLays(vis_MeshCon* p, Vint id, Vint* lays)
{
    *lays = (p->edge[id].topo >> 16) & 0xff;
}

extern void
vis_MeshConSetEdgeTopoRate(vis_MeshCon* p, Vint id, Vint rate)
{
    p->edge[id].topo &= 0x00ffffff;
    p->edge[id].topo |= (rate << 24);
}

extern void
vis_MeshConGetEdgeTopoRate(vis_MeshCon* p, Vint id, Vint* rate)
{
    *rate = (p->edge[id].topo >> 24) & 0xff;
}

extern void
vis_MeshConGetEdgeTopo(vis_MeshCon* p, Vint id, Vint* topo)
{
    *topo = p->edge[id].topo;
}

extern void
vis_MeshConSetEdgePref(vis_MeshCon* p, Vint id, Vint pref)
{
    static Vchar func[] = "vis_MeshConSetEdgePref";

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    p->edge[id].pref = pref;
}

extern void
vis_MeshConGetEdgePref(vis_MeshCon* p, Vint id, Vint* pref)
{
    static Vchar func[] = "vis_MeshConGetEdgePref";

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    *pref = p->edge[id].pref;
}

extern void
vis_MeshConNumEdgePind(vis_MeshCon* p, Vint id, Vint* num)
{
    if (p->extendflag == 0) {
        *num = 1;
    }
    else if (p->extendflag == 1 || p->extendflag == 2) {
        vis_MeshCon_NumPind(p, p->edge[id].pind, num);
    }
}

extern void
vis_MeshConAllEdgePind(vis_MeshCon* p, Vint id, Vint* num, Vint pind[])
{
    if (p->extendflag == 0) {
        *num = 1;
        pind[0] = p->edge[id].pind;
    }
    else if (p->extendflag == 1 || p->extendflag == 2) {
        vis_MeshCon_AllPind(p, p->edge[id].pind, num, pind);
    }
}

extern void
vis_MeshConSetEdgeCent(vis_MeshCon* p, Vint id, Vint cent)
{
    static Vchar func[] = "vis_MeshConSetEdgeCent";

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    p->edge[id].cent = cent;
}

extern void
vis_MeshConGetEdgeCent(vis_MeshCon* p, Vint id, Vint* cent)
{
    static Vchar func[] = "vis_MeshConGetEdgeCent";

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    *cent = p->edge[id].cent;
}

extern void
vis_MeshConSetEdgeSize(vis_MeshCon* p, Vint id, Vdouble size)
{
    p->edge[id].size = size;
}

extern void
vis_MeshConGetEdgeSize(vis_MeshCon* p, Vint id, Vdouble* size)
{
    Vint n0, n1;
    Vdouble xm[3];
    Vdouble dsize, fsize;

    /* compute midpoint */
    if (p->funsiz || p->meshsize || p->dmeshsize) {
        n0 = p->edge[id].no[0];
        n1 = p->edge[id].no[1];
        MID3(p->node[n0].x, p->node[n1].x, xm);
    }
    if (p->funsiz) {
        p->funsiz(p, p->funobjsiz, xm, &fsize);
        if (p->funsizingminflag == 0) {
            *size = fsize;
            return;
        }
    }
    *size = p->edge[id].size;
    if (p->meshsize) {
        vis_MeshSizeSize(p->meshsize, xm, &dsize);
        if (dsize != 0.) {
            *size = MIN2(*size, dsize);
        }
    }
    if (p->dmeshsize) {
        vis_MeshSizeSize(p->dmeshsize, xm, &dsize);
        if (dsize != 0.) {
            *size = MIN2(*size, dsize);
        }
    }
    if (p->funsiz) {
        if (fsize) {
            *size = MIN2(*size, fsize);
        }
    }
}

extern void
vis_MeshConNumPushEdge(vis_MeshCon* p, Vint* num)
{
    *num = p->numedgestack;
}

extern void
vis_MeshConPushEdge(vis_MeshCon* p, Vint id)
{
    Vint iter, edid;

    if (id > 0) {
        if (p->edge[id].stat == 0) {
            p->edgestack[p->numedgestack] = id;
            p->numedgestack += 1;
            p->edge[id].stat = 1;
        }
    }
    else {
        iter = 0;
        for (;;) {
            if (iter == 0) {
                edid = p->headedge;
                iter = edid;
            }
            else {
                edid = p->edge[iter].next;
                if (edid != 0) {
                    iter = edid;
                }
            }
            if (edid == 0)
                break;
            if (p->edge[edid].stat == 1) {
                p->edgestack[p->numedgestack] = edid;
                p->numedgestack += 1;
                p->edge[edid].stat = 1;
            }
        }
    }
}

extern void
vis_MeshConPopEdge(vis_MeshCon* p, Vint* id)
{
    Vint tid;

    *id = 0;
    for (; p->numedgestack;) {
        p->numedgestack -= 1;
        tid = p->edgestack[p->numedgestack];
        if (p->edge[tid].stat) {
            p->edge[tid].stat = 0;
            *id = tid;
            break;
        }
    }
    /* GHF
          p->numedgestack -= 1;
          *id = p->edgestack[p->numedgestack];
          if(p->edge[*id].stat == 0) {
             vis_MeshConPopEdge (p, id);
          } else {
             p->edge[*id].stat = 0;
          }
    */
}

extern void
vis_MeshConRefEdge(vis_MeshCon* p, Vint ith, Vint* id)
{
    if (ith <= p->numedgestack) {
        *id = p->edgestack[ith - 1];
    }
    else {
        *id = 0;
    }
}

extern void
vis_MeshConInitEdgeHeap(vis_MeshCon* p, Vint type)
{
    Vint iter, id;

    p->edgeheap = type;
    if (p->edgeheap == MESHCON_MINEDGELEN) {
        vsy_HeapDef(p->hpedge, p->maxedge, 0);
    }
    else if (p->edgeheap == MESHCON_MAXEDGELEN) {
        vsy_HeapDef(p->hpedge, p->maxedge, 1);
    }
    iter = 0;
    for (;;) {
        if (iter == 0) {
            id = p->headedge;
            iter = id;
        }
        else {
            id = p->edge[iter].next;
            if (id != 0) {
                iter = id;
            }
        }
        if (id == 0)
            break;
        if (p->edgeheap == MESHCON_MINEDGELEN) {
            vis_MeshCon_MinEdgeLen(p, id);
        }
        else if (p->edgeheap == MESHCON_MAXEDGELEN) {
            vis_MeshCon_MaxEdgeLen(p, id);
        }
    }
}

extern void
vis_MeshConNextEdgeHeap(vis_MeshCon* p, Vint* id, Vdouble* val)
{
    vsy_HeapRef(p->hpedge, id, val);
    if (*id == 0)
        p->edgeheap = 0;
}

extern void
vis_MeshConRemoveEdgeHeap(vis_MeshCon* p, Vint id)
{
    vsy_HeapRemove(p->hpedge, id);
}

extern void
vis_MeshConPushEdgeHeapNodeElem(vis_MeshCon* p, Vint noid)
{
    Vint i, j;
    Vint num;
    Vint nn, elno[4], eled[4];

    vis_MeshConGetNodeElem(p, noid, &num, p->inoed);
    for (i = 0; i < num; i++) {
        vis_MeshConGetElem(p, p->inoed[i], &nn, elno, eled);
        for (j = 0; j < nn; j++) {
            if (p->edgeheap == MESHCON_MINEDGELEN) {
                vis_MeshCon_MinEdgeLen(p, eled[j]);
            }
            else if (p->edgeheap == MESHCON_MAXEDGELEN) {
                vis_MeshCon_MaxEdgeLen(p, eled[j]);
            }
        }
    }
}

/*----------------------------------------------------------------------
                      fronts
----------------------------------------------------------------------*/
extern void
vis_MeshConRangeMinFrntLen(vis_MeshCon* p, Vdouble fmin, Vdouble fmax)
{
    vsy_PQueueDef(p->bfminlen[0], p->maxfrnt, 0);
    vsy_PQueueDef(p->bfminlen[1], p->maxfrnt, 0);
    vsy_PQueueDef(p->bfminlen[2], p->maxfrnt, 0);
    vsy_PQueueRange(p->bfminlen[0], fmin, fmax);
    vsy_PQueueRange(p->bfminlen[1], fmin, fmax);
    vsy_PQueueRange(p->bfminlen[2], fmin, fmax);
}

extern void
vis_MeshConInitMinFrntLen(vis_MeshCon* p, Vint* num)
{
    Vint iter, id;
    /* initialize min front length and count fronts */
    *num = 0;
    iter = 0;
    for (;;) {
        if (iter == 0) {
            id = p->headfrnt;
            iter = id;
        }
        else {
            id = p->frnt[iter].next;
            if (id != 0) {
                iter = id;
            }
        }
        if (id == 0)
            break;
        *num += 1;
        vis_MeshCon_MinFrntLen(p, id);
    }
}

extern void
vis_MeshConNextMinFrntLen(vis_MeshCon* p, Vint* id, Vdouble* val)
{
    if (p->numfrnt == 0) {
        *id = 0;
        return;
    }
    vsy_PQueueMinMax(p->bfminlen[2], 0, id, val);
    if (*id == 0) {
        vsy_PQueueMinMax(p->bfminlen[1], 0, id, val);
    }
    if (*id == 0) {
        vsy_PQueueMinMax(p->bfminlen[0], 0, id, val);
    }
}

extern void
vis_MeshConRemoveMinFrntLen(vis_MeshCon* p, Vint id)
{
    static Vchar func[] = "vis_MeshConRemoveMinFrntLen";
    Vint is;

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    is = MIN2(2, p->frnt[id].st[0] + p->frnt[id].st[1]);
    vsy_PQueueRemove(p->bfminlen[is], id);
}

extern void
vis_MeshConLookupMinFrntLen(vis_MeshCon* p, Vint id, Vdouble* val)
{
    static Vchar func[] = "vis_MeshConLookupMinFrntLen";
    Vint is;

    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    is = MIN2(2, p->frnt[id].st[0] + p->frnt[id].st[1]);
    vsy_PQueueLookup(p->bfminlen[is], id, val);
}

extern void
vis_MeshConNumFrnt(vis_MeshCon* p, Vint* num)
{
    *num = p->numfrnt;
}

/*----------------------------------------------------------------------
                      iteration
----------------------------------------------------------------------*/
extern void
vis_MeshConInitNode(vis_MeshCon* p)
{
    p->iternode = 0;
}

extern void
vis_MeshConNextNode(vis_MeshCon* p, Vint* id)
{
    if (p->iternode == 0) {
        *id = p->headnode;
        p->iternode = *id;
    }
    else {
        *id = p->node[p->iternode].next;
        if (*id != 0) {
            p->iternode = *id;
        }
    }
}

extern void
vis_MeshConInitEdge(vis_MeshCon* p)
{
    p->iteredge = 0;
}

extern void
vis_MeshConNextEdge(vis_MeshCon* p, Vint* id)
{
    if (p->iteredge == 0) {
        *id = p->headedge;
        p->iteredge = *id;
    }
    else {
        *id = p->edge[p->iteredge].next;
        if (*id != 0) {
            p->iteredge = *id;
        }
    }
}

extern void
vis_MeshConInitElem(vis_MeshCon* p)
{
    p->iterelem = 0;
}

extern void
vis_MeshConNextElem(vis_MeshCon* p, Vint* id)
{
    if (p->iterelem == 0) {
        *id = p->headelem;
        p->iterelem = *id;
    }
    else {
        *id = p->elem[p->iterelem].next;
        if (*id != 0) {
            p->iterelem = *id;
        }
    }
}

/*----------------------------------------------------------------------
                      check for circularity in element used and free lists
----------------------------------------------------------------------*/
extern void
vis_MeshConCheckElemLists(vis_MeshCon* p, Vint* flag)
{
    static Vchar func[] = "vis_MeshConCheckNextElem";
    Vint id, iter, niter;

    *flag = 1;
    /* check used list */
    iter = 0;
    niter = 0;
    for (;;) {
        if (iter == 0) {
            id = p->headelem;
            iter = id;
        }
        else {
            id = p->elem[iter].next;
            if (id != 0) {
                iter = id;
            }
        }
        if (id == 0)
            break;
        niter += 1;
        if (niter > p->maxelem) {
            p->ierr = SYS_ERROR_OPERATION;
            HANDLEERR0(func, p->ierr, "Used list");
            *flag = 0;
            return;
        }
    }
    /* check free list */
    iter = 0;
    niter = 0;
    for (;;) {
        if (iter == 0) {
            id = p->elem[0].next;
            iter = id;
        }
        else {
            id = p->elem[iter].next;
            if (id != 0) {
                iter = id;
            }
        }
        if (id == 0)
            break;
        niter += 1;
        if (niter > p->maxelem) {
            p->ierr = SYS_ERROR_OPERATION;
            HANDLEERR0(func, p->ierr, "Free list");
            *flag = 0;
            return;
        }
    }
}

extern void
vis_MeshConInitNodeEdge(vis_MeshCon* p, Vint noid)
{
    p->iternodeedge = 0;
    p->iterned = p->node[noid].ned;
    p->iternoed = p->node[noid].noed;
    p->iternoin = 0;
}

extern void
vis_MeshConNextNodeEdge(vis_MeshCon* p, Vint* id)
{
    if (p->iternodeedge >= p->iterned) {
        *id = 0;
        return;
    }
    if (p->iternoin == MESHCON_MAXNOED) {
        p->iternoed = p->noed[p->iternoed].noed;
        p->iternoin = 0;
    }
    *id = p->noed[p->iternoed].ed[p->iternoin];
    p->iternodeedge++;
    p->iternoin++;
}

extern void
vis_MeshConInitNodeElem(vis_MeshCon* p, Vint noid)
{
    p->iternodeelem = 0;
    vis_MeshConGetNodeElem(p, noid, &p->iterned, p->inoed1);
}

extern void
vis_MeshConNextNodeElem(vis_MeshCon* p, Vint* id)
{
    if (p->iternodeelem >= p->iterned) {
        *id = 0;
        return;
    }
    *id = p->inoed1[p->iternodeelem];
    p->iternodeelem++;
}

/*----------------------------------------------------------------------
                      element exit edge
----------------------------------------------------------------------*/
static void
vis_MeshCon_ElemExit(vis_MeshCon* p, Vint npts, Vdouble r[3], Vint* ki, Vint* ke, Vint* kn)
{
    Vint k;
    Vdouble r1;

    *ki = 0;
    *ke = 0;
    *kn = 0;
    r1 = -p->walkfacetol * p->walkfacetol;
    /* quad */
    if (npts == 4) {
        for (k = 0; k < 4; k++) {
            if (k == 0) {
                if (r[1] < -1. + r1) {
                    *ki = k + 1;
                }
                if (fabs(r[1] + 1.) < p->walkfacetol) {
                    *ke = k + 1;
                    if (fabs(r[0] + 1.) < p->walkfacetol) {
                        *kn = k + 1;
                    }
                }
            }
            else if (k == 1) {
                if (r[0] > 1. - r1) {
                    *ki = k + 1;
                }
                if (fabs(r[0] - 1.) < p->walkfacetol) {
                    *ke = k + 1;
                    if (fabs(r[1] + 1.) < p->walkfacetol) {
                        *kn = k + 1;
                    }
                }
            }
            else if (k == 2) {
                if (r[1] > 1. - r1) {
                    *ki = k + 1;
                }
                if (fabs(r[1] - 1.) < p->walkfacetol) {
                    *ke = k + 1;
                    if (fabs(r[0] - 1.) < p->walkfacetol) {
                        *kn = k + 1;
                    }
                }
            }
            else if (k == 3) {
                if (r[0] < -1. + r1) {
                    *ki = k + 1;
                }
                if (fabs(r[0] + 1.) < p->walkfacetol) {
                    *ke = k + 1;
                    if (fabs(r[1] + 1.) < p->walkfacetol) {
                        *kn = k + 1;
                    }
                }
            }
        }
        /* tri */
    }
    else {
        r[2] = 1. - r[0] - r[1];
        for (k = 0; k < 3; k++) {
            if (r[k] < r1) {
                *ki = (k + 2) % 3 + 1;
                r1 = r[k];
            }
            if (fabs(r[k]) < p->walkfacetol) {
                *ke = (k + 2) % 3 + 1;
                if (fabs(r[(k + 1) % 3]) < p->walkfacetol) {
                    *kn = k % 3 + 1;
                }
            }
        }
    }
}

static void
vis_MeshCon_ElemExitDir(vis_MeshCon* p, Vdouble xp[3], Vdouble xpd[3], Vint it, Vint* k1)
{
    Vint k;
    Vint nn, eled[3], edel[2], elid, elno[3];
    Vdouble xe[3][3], xm[3], fl, flmin, d[3], de[3];

    /* normal from current intersection to xp */
    DIFF3(xp, xpd, d);
    UNIT3(d);
    /* find closest normal of edge-adjacent triangles */
    flmin = -2.;
    *k1 = 0;
    vis_MeshConGetElemEdge(p, it, &nn, eled);
    for (k = 0; k < 3; k++) {
        if (p->edge[eled[k]].pres)
            continue;
        vis_MeshConGetEdgeElem(p, eled[k], edel);
        if (it == edel[0]) {
            elid = edel[1];
        }
        else {
            elid = edel[0];
        }
        vis_MeshConGetElemNode(p, it, &nn, elno);
        vis_MeshConGetNodes(p, 3, elno, xe);
        CENT3(xe, xm);
        DIFF3(xm, xpd, de);
        UNIT3(de);
        fl = DOT3(d, de);
        if (*k1 == 0 || fl > flmin) {
            *k1 = k + 1;
            flmin = fl;
        }
    }
}

/*----------------------------------------------------------------------
                      walk preserved edge
----------------------------------------------------------------------*/
extern void
vis_MeshConWalkEdge(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vint* edid, Vint* noid, Vdouble x[3])
{
    Vint k1, it, in, nit;
    Vint edno[2];
    Vdouble xed[2][3], r, r1, dist;
    Vint ierr;

    *noid = 0;
    *edid = 0;
    it = tid;
    nit = 0;
    do {
        vis_MeshConGetEdgeNode(p, it, edno);
        vis_MeshConGetNodes(p, 2, edno, xed);
        vis_invertNCLindv(xed, xp, &r, x, &ierr);
        k1 = 0;
        r1 = p->walkfacetol;
        if (r < -1. - r1) {
            k1 = 1;
        }
        else if (r > 1. + r1) {
            k1 = 2;
        }
        /* inside edge */
        if (k1 == 0) {
            vis_MeshCon_DistEdge(p, xp, x, 2, xed, &dist, &ierr);
            if (ierr) {
                if (r > 0.) {
                    k1 = 2;
                }
                else {
                    k1 = 1;
                }
            }
            else {
                *edid = it;
                if (fabs(r - 1.) < r1) {
                    *noid = edno[1];
                }
                else if (fabs(r + 1.) < r1) {
                    *noid = edno[0];
                }
                return;
            }
        }
        in = edno[k1 - 1];
        if (p->node[in].pres == SYS_NODE) {
            if (p->node[in].pref == 0) {
                return;
            }
        }
        vis_MeshConAdjPresEdge(p, it, in, &it);
        nit += 1;
    } while (nit < 1000);
}

/*----------------------------------------------------------------------
                      walk faces
----------------------------------------------------------------------*/
extern void
vis_MeshConWalkFace(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vint* elid, Vint* edid, Vint* noid, Vdouble x[3])
{
    static Vchar func[] = "vis_MeshConWalkFace";
    Vint k1, ke, kn;
    Vint npts;
    Vdouble xd[6][3], xpd[3];
    Vdouble r[3], dist;
    Vint nit, it;
    Vint itlast1, itlast2;
    Vint nn, elno[4], eled[4];
    Vint edno[2], edel[2];
    Vint edida;
    Vint ierr;
    Vint pres;
    Vint frnt[2];
    Vint nptsp;

    /* if *elid != 0 then walk hit feature on elid */
    /* if *elid == 0 && *edid != 0 then walk hit pres edge edid */
    /* if all return 0 then walk failed */
    if (tid <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "tid= %d", tid);
    }
    itlast1 = 0;
    itlast2 = 0;
    *elid = 0;
    *edid = 0;
    *noid = 0;
    it = tid;
    nit = 0;

    do {
        vis_MeshConGetElem(p, it, &nn, elno, eled);
        if (nn == 4) {
            return;
        }
        vis_MeshCon_ElemGath(p, nn, elno, eled, &npts, xd);
        /* walk triangle network */
        vis_MeshCon_ElemProject(npts, xd, xp, r, xpd, &nptsp, &ierr);
        if (ierr) {
            return;
        }
        /* find exit edge */
        vis_MeshCon_ElemExit(p, npts, r, &k1, &ke, &kn);
        /* inside triangle, perhaps on edge or node */
        if (k1 == 0) {
            vis_MeshCon_DistFace(p, xp, xpd, xd, &dist, &ierr);
            if (ierr) {
                vis_MeshCon_ElemExitDir(p, xp, xpd, it, &k1);
            }
            else {
                MOVE3(xpd, x);
                *elid = it;
                if (ke) {
                    *edid = eled[ke - 1];
                }
                if (kn) {
                    *noid = elno[kn - 1];
                }
                return;
            }
        }
        /* find adjacent triangle */
        edida = eled[k1 - 1];
        /* check preserved edge or fronts */
        vis_MeshConGetEdgePres(p, edida, &pres);
        if (pres) {
            *edid = edida;
            return;
        }
        vis_MeshConGetEdgeFrnt(p, edida, frnt);
        if (frnt[0] || frnt[1]) {
            return;
        }

        vis_MeshConGetEdge(p, edida, edno, edel);
        if (it == edel[0]) {
            it = edel[1];
        }
        else {
            it = edel[0];
        }
        /* adjacent triangle revisited */
        if (it == itlast2) {
            MOVE3(xpd, x);
            *elid = it;
            *edid = edida;
            return;
        }
        itlast2 = itlast1;
        itlast1 = it;
        nit += 1;
    } while (nit < 1000);
}

/*----------------------------------------------------------------------
                      project to face
----------------------------------------------------------------------*/
extern void
vis_MeshCon_Project(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vint* id, Vint* edid, Vdouble r[3], Vdouble x[3])
{
    Vint k1, ke, kn;
    Vint npts;
    Vdouble xd[6][3], xpd[3];
    Vint nit, it, ie;
    Vint itlast1, itlast2, itlasts;
    Vint nn, elno[4], eled[4];
    Vint nedel;
    Vint edno[2], edel[2];
    Vint ierr;
    Vdouble dist, distmin, bas, wid;
    Vint pres, ptid, pit;
    Vdouble d1[3], d2[3], va[3], vb[3], dt;
    Vint nptsp;

    itlast1 = 0;
    itlast2 = 0;
    itlasts = 0;
    *id = 0;
    *edid = 0;
    it = tid;
    nit = 0;
    p->projglob = 0;
    /* global search */
    if (tid == 0) {
        vis_MeshCon_LocElemGlobal(p, tid, 0., xp, id, edid, r, x);
        return;
    }

    if (p->gm) {
        vis_MeshConGetElemPres(p, tid, &pres);
        if (pres) {
            vis_MeshConGetElemPres(p->gm, pres, &ptid);
        }
        else {
            ptid = 0;
        }
    }
    else {
        vis_MeshConGetElemPres(p, tid, &ptid);
    }
#ifdef VISMESH_DEBUG
    printf("vis_MeshConProject, tid= %d, ptid= %d\n", tid, ptid);
#endif
    do {
        p->nprojiter += 1;
        vis_MeshConGetElem(p, it, &nn, elno, eled);
        vis_MeshCon_ElemGath(p, nn, elno, eled, &npts, xd);
        /* check crease */
#ifdef VKI_PROJECT_PROJECTX
        if (itlast2) {
            DIFF3(xd[0], xd[1], d1);
            DIFF3(xd[0], xd[2], d2);
            CROSS3(d1, d2, vb);
            UNIT3(vb);
            dt = DOT3(va, vb);
            if (dt < .5) {
                MOVE3(xpd, x);
                *id = itlast2;
                return;
            }
        }
#endif
        /* walk triangle network */
        vis_MeshCon_ElemProject(npts, xd, xp, r, xpd, &nptsp, &ierr);
        /* zero area triangle */
        if (ierr) {
            vis_MeshCon_LocElemGlobal(p, tid, 0., xp, id, edid, r, x);
            return;
        }
        /* find exit edge */
        vis_MeshCon_ElemExit(p, npts, r, &k1, &ke, &kn);
        /* inside triangle */
        if (k1 == 0) {
            DIFF3(xpd, xp, d1);
            dist = MAG3(d1);
            vis_baseHeight(xd, &bas, &wid);
            /* this setting is pretty loose */
            if (dist > 100. * wid) {
                vis_MeshCon_LocElemGlobal(p, tid, dist, xp, id, edid, r, x);
            }
            else {
                if (nit == 0) {
                    MOVE3(xpd, x);
                    *id = it;
                }
                else {
                    DIFF3(xd[0], xd[1], d1);
                    DIFF3(xd[0], xd[2], d2);
                    CROSS3(d1, d2, vb);
                    UNIT3(vb);
                    dt = DOT3(va, vb);
                    /* test normal of final triangle with initial */
                    if (dist < .2 * wid || (dt > .1 && dist <= 1.0001 * distmin)) {
                        MOVE3(xpd, x);
                        *id = it;
                    }
                    else {
                        vis_MeshCon_LocElemGlobal(p, tid, distmin, xp, id, edid, r, x);
                    }
                }
            }
            return;
        }
        /* find closest point on triangle edge */
        vis_MeshCon_ElemEdgeProject(nptsp, xd, xp, &ke, r, xpd);
        DIFF3(xpd, xp, d1);
        dist = MAG3(d1);
        /* compute normal initial triangle, minimum distance */
        if (nit == 0) {
            DIFF3(xd[0], xd[1], d1);
            DIFF3(xd[0], xd[2], d2);
            CROSS3(d1, d2, va);
            UNIT3(va);
            distmin = dist;
        }
        else {
            if (dist < distmin) {
                distmin = dist;
            }
        }
        /* find adjacent triangle */
        ie = eled[k1 - 1];
        vis_MeshConNumEdgeElem(p, ie, &nedel);
        if (nedel != 2) {
            it = 0;
        }
        else {
            vis_MeshConGetEdge(p, ie, edno, edel);
            if (it == edel[0]) {
                it = edel[1];
            }
            else {
                it = edel[0];
            }
        }
        /* no adjacent triangle or non-manifold edge */
        if (it == 0) {
            vis_MeshCon_LocElemGlobal(p, tid, distmin, xp, id, edid, r, x);
            return;
        }
        if (p->gm) {
            vis_MeshConGetElemPres(p, it, &pres);
            if (pres) {
                vis_MeshConGetElemPres(p->gm, pres, &pit);
            }
            else {
                pit = 0;
            }
        }
        else {
            vis_MeshConGetElemPres(p, it, &pit);
        }
        /* adjacent triangle not in same patch */
        if (p->patchproject) {
            if (pit != ptid) {
                vis_MeshCon_LocElemGlobal(p, tid, distmin, xp, id, edid, r, x);
                return;
            }
        }
        if (it == itlast2) {
            /* not close to edge of parent domain */
            if (ke == 0) {
                vis_MeshCon_LocElemGlobal(p, tid, distmin, xp, id, edid, r, x);
                return;
            }
            DIFF3(xd[0], xd[1], d1);
            DIFF3(xd[0], xd[2], d2);
            CROSS3(d1, d2, vb);
            UNIT3(vb);
            dt = DOT3(va, vb);
            DIFF3(xpd, xp, d1);
            dist = MAG3(d1);
            if (dt > .1 && dist <= 1.0001 * distmin) {
                MOVE3(xpd, x);
                *id = it;
            }
            else {
                vis_MeshCon_LocElemGlobal(p, tid, distmin, xp, id, edid, r, x);
            }
            return;
        }
        itlast2 = itlast1;
        itlast1 = it;
        nit += 1;
    } while (nit < 1000);
    vis_MeshCon_LocElemGlobal(p, tid, distmin, xp, id, edid, r, x);
}

extern void
vis_MeshConProject(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vint* id, Vint* edid, Vdouble x[3])
{
    Vdouble r[3];

    vis_MeshCon_Project(p, tid, xp, id, edid, r, x);
}

extern void
vis_MeshConProjectNorm(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vdouble x[3], Vdouble v[3])
{
    Vint id, edid;
    Vint ctype, elempres;
    Vdouble r[3], h[3];
    vis_CoordSys* coordsys;

    vis_MeshConGetElemFlat(p, tid, &ctype);
    coordsys = NULL;
    if (ctype == SYS_CARTESIAN || ctype == SYS_CYLINDRICAL || ctype == SYS_SPHERICAL || ctype == SYS_TOROIDAL) {
        vis_MeshConGetElemPres(p, tid, &elempres);
        vis_MeshConGetCoordSys(p, elempres, &coordsys);
    }
    if (coordsys) {
        vis_CoordSysProjSurfacedv(coordsys, xp, x);
        vis_CoordSysNormSurfacedv(coordsys, x, v);
    }
    else {
        vis_MeshCon_Project(p, tid, xp, &id, &edid, r, x);
        vis_shapeTridv(1, r, h, NULL);
        vml_multMatrix3d(3, p->elem[id].ne, h, v);
        UNIT3(v);
    }
}

extern void
vis_MeshConProjectElems(vis_MeshCon* p, Vint nel, Vint iel[], Vdouble xp[3], Vint* id, Vdouble x[3])
{
    Vint i;
    Vint k1, ke, kn;
    Vint npts, nptsp, ierr;
    Vdouble xd[6][3], xpd[3], d[3], fl, flmin;
    Vdouble r[3];
    Vint nn, elno[4], eled[4];
    Vint teid;

    *id = 0;
    for (i = 0; i < nel; i++) {
        vis_MeshConGetElem(p, iel[i], &nn, elno, eled);
        vis_MeshCon_ElemGath(p, nn, elno, eled, &npts, xd);
        vis_MeshCon_ElemProject(npts, xd, xp, r, xpd, &nptsp, &ierr);
        if (ierr)
            continue;
        vis_MeshCon_ElemExit(p, npts, r, &k1, &ke, &kn);
        if (k1 == 0) {
            DIFF3(xp, xpd, d);
            fl = MAG3(d);
            if (*id == 0 || fl < flmin) {
                *id = iel[i];
                MOVE3(xpd, x);
                flmin = fl;
            }
        }
    }
    if (*id == 0) {
        vis_MeshConProject(p, iel[0], xp, id, &teid, x);
    }
}

extern void
vis_MeshConProjectGlobal(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vint* id, Vint* edid, Vdouble x[3])
{
    Vdouble r[3];

    vis_MeshCon_LocElemGlobal(p, tid, 0., xp, id, edid, r, x);
}

/*----------------------------------------------------------------------
                      project to one given triangle
----------------------------------------------------------------------*/
extern void
vis_MeshConProjectOneTri(vis_MeshCon* p, Vint id, Vdouble xp[3], Vdouble r[3], Vdouble x[3], Vint* ierr)
{
    Vint npts, nptsp;
    Vdouble xd[6][3];

    vis_MeshConElemGath(p, id, &npts, xd);
    vis_MeshCon_ElemProject(npts, xd, xp, r, x, &nptsp, ierr);
}

extern void
vis_MeshConElemNorm(vis_MeshCon* p, Vint id, Vdouble xp[3], Vdouble vp[3])
{
    static Vchar func[] = "vis_MeshConElemNorm";
    Vint npts, nptsp;
    Vdouble r[3], xd[6][3], xpd[3], h[6];
    Vint ierr;
    Vint pres;
    vis_CoordSys* coordsys;
    /* compute normal at point of triangle */
    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    if (p->elem[id].ne == NULL) {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR1(func, p->ierr, "element= %d, normals not present", id);
        return;
    }
    pres = p->elem[id].pres;
    vis_MeshConGetCoordSys(p, pres, &coordsys);
    if (coordsys) {
        vis_CoordSysNormSurfacedv(coordsys, xp, vp);
        return;
    }
    vis_MeshConElemGath(p, id, &npts, xd);
    vis_MeshCon_ElemProject(npts, xd, xp, r, xpd, &nptsp, &ierr);
    vis_shapeTridv(1, r, h, NULL);
    vml_multMatrix3d(3, p->elem[id].ne, h, vp);
    UNIT3(vp);
}

extern void
vis_MeshConElemArea(vis_MeshCon* p, Vint tid, Vdouble* area)
{
    Vint nn, elno[4], eled[4];
    Vdouble x[4][3];

    vis_MeshConGetElem(p, tid, &nn, elno, eled);
    vis_MeshConGetNodes(p, nn, elno, x);
    vis_computeAreadv(nn, x, area);
}

extern void
vis_MeshConElemCurvature(vis_MeshCon* p, Vint tid, Vdouble vk[3], Vdouble rk[2], Vdouble pk[2][3])
{
    Vint nn, elno[4];
    Vdouble r[2], x[3][3], v[3][3];

    vis_centNCdv(VIS_SHAPETRI, r);
    vis_MeshConGetElemNode(p, tid, &nn, elno);
    vis_MeshConGetNodes(p, nn, elno, x);
    vis_MeshConGetElemNorm(p, tid, v);
    vis_curvatureTridv(x, v, r, vk, rk, pk);
}

extern void
vis_MeshConElemExtent(vis_MeshCon* p, Vint id, Vdouble extent[2][3])
{
    Vint i, k;
    Vint nn, elno[4];
    Vdouble x[4][3];

    vis_MeshConGetElemNode(p, id, &nn, elno);
    vis_MeshConGetNodes(p, nn, elno, x);
    MOVE3(x[0], extent[0]);
    MOVE3(x[0], extent[1]);
    for (i = 1; i < nn; i++) {
        for (k = 0; k < 3; k++) {
            if (x[i][k] < extent[0][k])
                extent[0][k] = x[i][k];
            if (x[i][k] > extent[1][k])
                extent[1][k] = x[i][k];
        }
    }
}

extern void
vis_MeshConNormal(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vdouble vp[3])
{
    Vint npts;
    Vdouble r[2], xd[6][3], xpd[3], d1[3], d2[3];
    Vint ierr;

    vis_MeshConElemGath(p, tid, &npts, xd);
    if (npts == 3) {
        DIFF3(xd[1], xd[0], d1);
        DIFF3(xd[2], xd[0], d2);
        CROSS3(d1, d2, vp);
        UNIT3(vp);
    }
    else {
        vis_invertNCTriPardv(xd, xp, r, xpd, &ierr);
        if (ierr) {
            DIFF3(xd[1], xd[0], d1);
            DIFF3(xd[2], xd[0], d2);
            CROSS3(d1, d2, vp);
            UNIT3(vp);
        }
        else {
            vis_normal2DGendv(VIS_SHAPETRI, 3, 0, xd, r, vp);
        }
    }
}

extern void
vis_MeshConTangent(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vdouble vp[3])
{
    Vint npts;
    Vint edno[2];
    Vint cent;
    Vdouble r, xd[3][3], xpd[3];
    Vint ierr;

    vis_MeshConGetEdgeNode(p, tid, edno);
    vis_MeshConGetNode(p, edno[0], xd[0]);
    vis_MeshConGetEdgeCent(p, tid, &cent);
    if (cent) {
        npts = 3;
        vis_MeshConGetNode(p, cent, xd[1]);
        vis_MeshConGetNode(p, edno[1], xd[2]);
    }
    else {
        npts = 2;
        vis_MeshConGetNode(p, edno[1], xd[1]);
    }

    if (npts == 2) {
        DIFF3(xd[1], xd[0], vp);
        UNIT3(vp);
    }
    else {
        vis_invertNCLinPardv(xd, xp, &r, xpd, &ierr);
        vis_tangent1DGendv(3, xd, r, vp);
    }
}

/*----------------------------------------------------------------------
                      gather either 3 or 6 node triangle
----------------------------------------------------------------------*/
extern void
vis_MeshConElemGath(vis_MeshCon* p, Vint id, Vint* npts, Vdouble xd[][3])
{
    Vint nn, elno[4], eled[4];

    vis_MeshConGetElem(p, id, &nn, elno, eled);
    vis_MeshCon_ElemGath(p, nn, elno, eled, npts, xd);
}

/*----------------------------------------------------------------------
                      project to edge
----------------------------------------------------------------------*/
extern void
vis_MeshConProjectEdge(vis_MeshCon* p, Vint edid, Vdouble xp[3], Vint* id, Vdouble x[3])
{
    static Vchar func[] = "vis_MeshConProjectEdge";
    Vint k1;
    Vint npts;
    Vdouble xd[3][3], xpd[3];
    Vdouble r, r1, ri;
    Vdouble h[3];
    Vint nit, it;
    Vint itlast1, itlast2;
    Vdouble rlast1, rlast2;
    Vint edno[2];
    Vint cent;
    Vint noid;
    Vint ierr;
    Vdouble dist;
    Vint tid;

    if (p->gm) {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR0(func, p->ierr, "Projection not on geometry");
        return;
    }
    /* global search */
    if (edid == 0) {
        vis_MeshCon_LocEdgeGlobal(p, xp, id, x);
        return;
    }
    itlast1 = 0;
    rlast1 = 0.;
    itlast2 = 0;
    rlast2 = 0.;
    *id = 0;

    tid = edid;
    it = tid;
    nit = 0;
    do {
#ifdef VISMESH_DEBUG
        printf(" %d", it);
#endif
        p->nprojedgeiter += 1;
        vis_MeshConGetEdgeNode(p, it, edno);
        vis_MeshConGetNode(p, edno[0], xd[0]);
        vis_MeshConGetEdgeCent(p, it, &cent);
        if (cent) {
            npts = 3;
            vis_MeshConGetNode(p, cent, xd[1]);
            vis_MeshConGetNode(p, edno[1], xd[2]);
        }
        else {
            npts = 2;
            vis_MeshConGetNode(p, edno[1], xd[1]);
        }
        /* walk edge network */
        if (npts == 2) {
            vis_invertNCLindv(xd, xp, &r, xpd, &ierr);
        }
        else {
            vis_invertNCLinPardv(xd, xp, &r, xpd, &ierr);
            if (ierr) {
                vis_invertNCLindv(xd, xp, &r, xpd, &ierr);
            }
        }
        if (ierr) {
            vis_MeshCon_LocEdgePres(p, tid, xp, id, x);
            return;
        }
        k1 = 0;
        r1 = .0001;
        if (r < -1. - r1) {
            k1 = 1;
        }
        else if (r > 1. + r1) {
            k1 = 2;
        }
        /* inside edge */
        if (k1 == 0) {
            vis_MeshCon_DistEdge(p, xp, xpd, npts, xd, &dist, &ierr);
            if (ierr == 2 || (ierr == 1 && nit > 0)) {
                vis_MeshCon_LocEdgePres(p, tid, xp, id, x);
            }
            else {
                MOVE3(xpd, x);
                *id = it;
            }
            return;
        }
        /* find adjacent edge */
        noid = edno[k1 - 1];
        if (p->node[noid].pres == SYS_NODE) {
            it = 0;
        }
        else {
            vis_MeshConAdjPresEdge(p, it, noid, &it);
        }

        if (it == 0) {
            vis_MeshCon_LocEdgePres(p, tid, xp, id, x);
            return;
        }
        if (it == itlast2) {
            ri = CLAMP(r, -1., 1.);
            vis_shapeLinLagdv(1, npts, ri, h, NULL);
            vml_multMatrix3d(npts, xd, h, xpd);
            vis_MeshCon_DistEdge(p, xp, xpd, npts, xd, &dist, &ierr);
            if (ierr == 0) {
                if ((r > 2. || rlast2 > 2.) || (r > 1.2 && rlast2 > 1.2))
                    ierr = 1;
            }
            if (ierr) {
                vis_MeshCon_LocEdgePres(p, tid, xp, id, x);
            }
            else {
                MOVE3(xpd, x);
                *id = it;
            }
            return;
        }
        itlast2 = itlast1;
        rlast2 = rlast1;
        itlast1 = it;
        rlast1 = fabs(r);
        nit += 1;
    } while (nit < 1000);
    vis_MeshCon_LocEdgePres(p, tid, xp, id, x);
}

extern void
vis_MeshConProjectEdgeLocal(vis_MeshCon* p, Vdouble xl[3], Vint edid, Vdouble xp[3], Vint* id, Vdouble x[3])
{
    static Vchar func[] = "vis_MeshConProjectEdgeLocal";
    Vint k1;
    Vint npts;
    Vdouble xs[3], xd[3][3], xpd[3], d[3];
    Vdouble r, r1;
    Vint nit, it;
    Vint itlast, itnext;
    Vint edno[2];
    Vint cent;
    Vint noid;
    Vint ierr;
    Vdouble dist, distmin;
    Vint tid;

    if (p->gm) {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR0(func, p->ierr, "Projection not on geometry");
        return;
    }
    if (edid == 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR0(func, p->ierr, "No edge specified");
        return;
    }
    itlast = 0;
    *id = 0;

    tid = edid;
    vis_MeshConProjectEdge(p, edid, xl, &it, xs);
    nit = 0;
    do {
#ifdef VISMESH_DEBUG
        printf(" %d", it);
#endif
        p->nprojedgeiter += 1;
        vis_MeshConGetEdgeNode(p, it, edno);
        vis_MeshConGetNode(p, edno[0], xd[0]);
        vis_MeshConGetEdgeCent(p, it, &cent);
        if (cent) {
            npts = 3;
            vis_MeshConGetNode(p, cent, xd[1]);
            vis_MeshConGetNode(p, edno[1], xd[2]);
        }
        else {
            npts = 2;
            vis_MeshConGetNode(p, edno[1], xd[1]);
        }
        /* walk edge network */
        if (npts == 2) {
            vis_invertNCLindv(xd, xp, &r, xpd, &ierr);
        }
        else {
            vis_invertNCLinPardv(xd, xp, &r, xpd, &ierr);
            if (ierr) {
                vis_invertNCLindv(xd, xp, &r, xpd, &ierr);
            }
        }
        if (ierr) {
            vis_MeshCon_LocEdgePres(p, tid, xp, id, x);
            return;
        }
        k1 = 0;
        r1 = .0001;
        if (r < -1. - r1) {
            k1 = 1;
        }
        else if (r > 1. + r1) {
            k1 = 2;
        }
        /* inside edge */
        if (k1 == 0) {
            MOVE3(xpd, x);
            *id = it;
            return;
        }
        /* find adjacent edge */
        noid = edno[k1 - 1];
        vis_MeshConGetNode(p, noid, xpd);
        DIFF3(xpd, xp, d);
        dist = MAG3(d);
        if (nit == 0) {
            MOVE3(xpd, x);
            *id = it;
            distmin = dist;
        }
        if (p->node[noid].pres == SYS_NODE) {
            return;
        }
        else {
            vis_MeshConAdjPresEdge(p, it, noid, &itnext);
        }
        if (itnext == 0 || itnext == itlast) {
            MOVE3(xpd, x);
            *id = it;
            return;
        }
        itlast = it;
        it = itnext;
        nit += 1;
    } while (nit < 1000);
}

/*----------------------------------------------------------------------
                      paste preserved edge to geometry
----------------------------------------------------------------------*/
extern void
vis_MeshConPasteEdgePres(vis_MeshCon* p, Vdouble xa[3], Vint ta, Vdouble xb[3], Vint tb, Vint* npt, Vdouble xt[][3], Vint tt[])
{
    Vint i;
    Vint npts;
    Vdouble xd[3][3], dr;
    Vdouble xr[3];
    Vdouble ra, rb, rc, r;
    Vdouble h[3];
    Vint tc, nit, it, np;
    Vint edno[2];
    Vint cent;
    Vint noid;
    Vint ierr;
    Vint ptid, pit;
    Vint num;
#ifdef VISMESH_DEBUG
    printf("vis_MeshConPasteEdgePres\n");
#endif
    *npt = 0;
    /* must be on geometry */
    if (p->gm) {
        return;
    }
    /* not on same preserved geometry edge */
    vis_MeshConGetEdgePres(p, ta, &ptid);
    vis_MeshConGetEdgePres(p, tb, &pit);
    if (ptid != pit) {
        return;
    }
    /* allocate temporary buffers */
    if (p->tpedge == NULL) {
        p->maxpedge = 1000;
        p->tpedge = (Vint*)vut_mallocMem(p->maxpedge * sizeof(Vint));
        p->xpedge = (Vdouble(*)[3])vut_mallocMem(3 * p->maxpedge * sizeof(Vdouble));
    }
    /* get endpoint info */
    np = 0;
    vis_MeshConProjectOneEdge(p, ta, xa, &ra, p->xpedge[np], &ierr);
    p->tpedge[np] = ta;
    vis_MeshConProjectOneEdge(p, tb, xb, &rb, xr, &ierr);
    np += 1;
    tc = ta;
    rc = ra;

    for (nit = 0;; nit++) {
        vis_MeshConGetEdgeNode(p, tc, edno);
        vis_MeshConGetNode(p, edno[0], xd[0]);
        vis_MeshConGetEdgeCent(p, tc, &cent);
        if (cent) {
            npts = 3;
            vis_MeshConGetNode(p, cent, xd[1]);
            vis_MeshConGetNode(p, edno[1], xd[2]);
        }
        else {
            npts = 2;
            vis_MeshConGetNode(p, edno[1], xd[1]);
        }
        if (tc == tb) {
            if (npts == 3) {
                dr = (rb - rc) / 8.;
                for (i = 1; i < 8; i++) {
                    r = rc + i * dr;
                    vis_shapeLinLagdv(1, 3, r, h, NULL);
                    vml_multMatrix3d(3, xd, h, p->xpedge[np]);
                    p->tpedge[np] = tc;
                    np += 1;
                }
            }
            MOVE3(xb, p->xpedge[np]);
            p->tpedge[np] = tb;
            np += 1;
            break;
        }
        /* walk edge network */
        if (npts == 2) {
            MOVE3(xd[1], p->xpedge[np]);
            p->tpedge[np] = tc;
            np += 1;
            noid = edno[1];
        }
        else {
            dr = (1. - rc) / 8.;
            for (i = 1; i <= 8; i++) {
                r = rc + i * dr;
                vis_shapeLinLagdv(1, 3, r, h, NULL);
                vml_multMatrix3d(3, xd, h, p->xpedge[np]);
                p->tpedge[np] = tc;
                np += 1;
            }
            noid = edno[1];
        }
        /* find adjacent edge */
        vis_MeshConGetNodeEdge(p, noid, &num, p->inoed);
        it = 0;
        for (i = 0; i < num; i++) {
            vis_MeshConGetEdgePres(p, p->inoed[i], &pit);
            if (pit != ptid) {
                continue;
            }
            if (p->inoed[i] != tc) {
                it = p->inoed[i];
                break;
            }
        }
        if (it == 0) {
            return;
        }
        tc = it;
        vis_MeshConGetEdgeNode(p, tc, edno);
        rc = -1.;
        if (nit > 1000) {
            return;
        }
        if (np >= p->maxpedge - 1) {
            p->maxpedge += 1000;
            p->tpedge = (Vint*)vut_reallocMem(p->tpedge, p->maxpedge * sizeof(Vint));
            p->xpedge = (Vdouble(*)[3])vut_reallocMem(p->xpedge, 3 * p->maxpedge * sizeof(Vdouble));
        }
    }
    *npt = np;
    for (i = 0; i < np; i++) {
        MOVE3(p->xpedge[i], xt[i]);
        tt[i] = p->tpedge[i];
    }
}

/*----------------------------------------------------------------------
                      project to preserved edge, this is new and untried
----------------------------------------------------------------------*/
extern void
vis_MeshConProjectEdgePres(vis_MeshCon* p, Vdouble xa[3], Vint ta, Vdouble xb[3], Vint tb, Vdouble w, Vdouble xp[3], Vint* tp)
{
    static Vchar func[] = "vis_MeshConProjectEdgePres";
    Vint i;
    Vint in;
    Vint npts;
    Vdouble xd[3][3], d[3], fl, fi, dr, tlen, flen, dlen;
    Vdouble xt[110][3], xi[3], xr[3];
    Vint tt[110];
    Vdouble ra, rb, rc, r, ri, rd;
    Vdouble h[3];
    Vint tc, nit, it, np;
    Vint edno[2];
    Vint cent;
    Vint noid;
    Vint ierr;
    Vint ptid, pit;
    Vint num;

#ifdef VISMESH_DEBUG
    printf("vis_MeshConProjectEdgePres\n it=");
#endif
    if (p->gm) {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR0(func, p->ierr, "Projection not on geometry");
        return;
    }
    /* get initial patch id */
    vis_MeshConGetEdgePres(p, ta, &ptid);
    /* get endpoint info */
    np = 0;
    tc = ta;
    vis_MeshConProjectOneEdge(p, ta, xa, &ra, xt[np], &ierr);
    rc = ra;
    tt[np] = ta;
    vis_MeshConProjectOneEdge(p, tb, xb, &rb, xr, &ierr);
    /* see which direction to go */
    DIFF3(xb, xa, d);
    fl = MAG3(d);
    fi = .000001 * fl;
    ADD3(xa, fi, d, xi);
    vis_MeshConProjectOneEdge(p, ta, xi, &ri, xr, &ierr);
    rd = ri - ra;

    for (nit = 0;; nit++) {
        vis_MeshConGetEdgeNode(p, tc, edno);
        vis_MeshConGetNode(p, edno[0], xd[0]);
        vis_MeshConGetEdgeCent(p, tc, &cent);
        if (cent) {
            npts = 3;
            vis_MeshConGetNode(p, cent, xd[1]);
            vis_MeshConGetNode(p, edno[1], xd[2]);
        }
        else {
            npts = 2;
            vis_MeshConGetNode(p, edno[1], xd[1]);
        }
        if (tc == tb) {
            if (npts == 3) {
                dr = (rb - rc) / 8.;
                for (i = 1; i < 8; i++) {
                    r = rc + i * dr;
                    vis_shapeLinLagdv(1, 3, r, h, NULL);
                    np += 1;
                    vml_multMatrix3d(3, xd, h, xt[np]);
                    tt[np] = tc;
                }
            }
            np += 1;
            MOVE3(xb, xt[np]);
            tt[np] = tb;
            break;
        }
        /* walk edge network */
        if (rd > 0.) {
            in = 1;
        }
        else {
            in = 0;
        }
        if (npts == 2) {
            np += 1;
            MOVE3(xd[in], xt[np]);
            tt[np] = tc;
            noid = edno[in];
        }
        else {
            if (in == 0) {
                dr = (-1. - rc) / 8.;
            }
            else {
                dr = (1. - rc) / 8.;
            }
            for (i = 1; i <= 8; i++) {
                r = rc + i * dr;
                vis_shapeLinLagdv(1, 3, r, h, NULL);
                np += 1;
                vml_multMatrix3d(3, xd, h, xt[np]);
                tt[np] = tc;
            }
            if (in == 0) {
                noid = edno[0];
            }
            else {
                noid = edno[1];
            }
        }
        /* find adjacent edge */
        vis_MeshConGetNodeEdge(p, noid, &num, p->inoed);
        it = 0;
        for (i = 0; i < num; i++) {
            vis_MeshConGetEdgePres(p, p->inoed[i], &pit);
            if (pit != ptid) {
                continue;
            }
            if (p->inoed[i] != tc) {
                it = p->inoed[i];
                break;
            }
        }
        if (it == 0) {
            p->ierr = SYS_ERROR_OPERATION;
            HANDLEERR0(func, p->ierr, "No adjacent edge");
            return;
        }
        tc = it;
        vis_MeshConGetEdgeNode(p, tc, edno);
        if (noid == edno[0]) {
            rc = -1.;
            rd = 1.;
        }
        else {
            rc = 1.;
            rd = -1.;
        }
        if (nit > 1000) {
            p->ierr = SYS_ERROR_OPERATION;
            HANDLEERR0(func, p->ierr, "Maximum iterations");
            return;
        }
        if (np > 100) {
            p->ierr = SYS_ERROR_OPERATION;
            HANDLEERR0(func, p->ierr, "Maximum intermediate points");
            return;
        }
    }
    /* walk points for total length */
    tlen = 0;
    for (i = 0; i < np - 1; i++) {
        fl = LEN3(xt[i + 1], xt[i]);
        tlen += fl;
    }
    flen = w * tlen;
    /* now find segment */
    tlen = 0;
    for (i = 0; i < np - 1; i++) {
        fl = LEN3(xt[i + 1], xt[i]);
        if (tlen + fl > flen) {
            dlen = flen - tlen;
            DIFF3(xt[i + 1], xt[i], d);
            UNIT3(d);
            ADD3(xt[i], dlen, d, xr);
            vis_MeshConProjectEdge(p, tt[i], xr, tp, xp);
            return;
        }
        tlen += fl;
    }
}

/*----------------------------------------------------------------------
                      project to one given edge
----------------------------------------------------------------------*/
extern void
vis_MeshConProjectOneEdge(vis_MeshCon* p, Vint edid, Vdouble xp[3], Vdouble* r, Vdouble x[3], Vint* ierr)
{
    Vint edno[2], cent;
    Vint npts;
    Vdouble xd[3][3];

    /* gather edge node coordinates */
    vis_MeshConGetEdgeNode(p, edid, edno);
    vis_MeshConGetNode(p, edno[0], xd[0]);
    vis_MeshConGetEdgeCent(p, edid, &cent);
    if (cent) {
        npts = 3;
        vis_MeshConGetNode(p, cent, xd[1]);
        vis_MeshConGetNode(p, edno[1], xd[2]);
    }
    else {
        npts = 2;
        vis_MeshConGetNode(p, edno[1], xd[1]);
    }
    if (npts == 2) {
        vis_invertNCLindv(xd, xp, r, x, ierr);
    }
    else {
        vis_invertNCLinPardv(xd, xp, r, x, ierr);
        if (*ierr) {
            vis_invertNCLindv(xd, xp, r, x, ierr);
        }
    }
}

/*----------------------------------------------------------------------
                      get adtree
----------------------------------------------------------------------*/
extern void
vis_MeshConGetADTree(vis_MeshCon* p, vsy_ADTree** adtree)
{
    *adtree = p->adt;
}

/*----------------------------------------------------------------------
                      max edge element
----------------------------------------------------------------------*/
extern void
vis_MeshConMaxEdgeElem(vis_MeshCon* p, Vint* melem)
{
    Vint iter, id;

    *melem = 0;
    iter = 0;
    for (;;) {
        if (iter == 0) {
            id = p->headedge;
            iter = id;
        }
        else {
            id = p->edge[iter].next;
            if (id != 0) {
                iter = id;
            }
        }
        if (id == 0)
            break;
        *melem = MAX2(*melem, p->edge[iter].nelem);
    }
}

/*----------------------------------------------------------------------
                      debug edge interactions
----------------------------------------------------------------------*/
extern void
vis_MeshConDebugEdge(vis_MeshCon* p, Vint iop)
{
    Vint iter, id;
    Vint i, j;
    Vint nelem, m0, m1, nm, n0, n1;

    if (iop == 0)
        return;
    iter = 0;
    for (;;) {
        if (iter == 0) {
            id = p->headedge;
            iter = id;
        }
        else {
            id = p->edge[iter].next;
            if (id != 0) {
                iter = id;
            }
        }
        if (id == 0)
            break;
        /* compute number of matching nodes on adjacent elements */
        if (iop == 1) {
            nelem = p->edge[iter].nelem;
            m0 = p->edge[iter].el[0];
            m1 = p->edge[iter].el[1];
            n0 = p->elem[m0].nn;
            n1 = p->elem[m1].nn;
#ifdef VISMESH_DEBUG
#endif
            if (nelem > 2) {
                printf("edge= %d, nonmanifold, n0= %d, n1= %d\n", iter, n0, n1);
            }
            if (nelem != 2)
                continue;
            nm = 0;
            for (i = 0; i < n0; i++) {
                for (j = 0; j < n1; j++) {
                    if (p->elem[m0].no[i] == p->elem[m1].no[j]) {
                        nm += 1;
                    }
                    if (nm == 3 && ((n0 == 4 && n1 == 3) || (n0 == 3 && n1 == 4))) {
                        printf("edge= %d, m0= %d, m1= %d\n", iter, m0, m1);
                    }
                }
            }
        }
    }
}

/*----------------------------------------------------------------------
                      consistency
----------------------------------------------------------------------*/
extern void
vis_MeshConConsistent(vis_MeshCon* p)
{
    static Vchar func[] = "vis_MeshConConsistent";
    Vint i, j, k;
    Vint ne, elid, edid, noid, frid;
    Vint frida;
    Vint iter, id;
    Vint in, inoed;
    Vint nfre, numerr, maxerr;
    Vint nn;
    Vdouble area;
    /* iterate through edges */
    maxerr = 10;
    numerr = 0;
    iter = 0;
    nfre = 0;
    for (;;) {
        if (iter == 0) {
            id = p->headedge;
            iter = id;
        }
        else {
            id = p->edge[iter].next;
            if (id != 0) {
                iter = id;
            }
        }
        if (id == 0)
            break;
        if (p->edge[id].nelem == 1 && p->edge[id].pref == 0) {
            if (p->edge[id].pres == 0) {
                p->ierr = SYS_ERROR_OPERATION;
                HANDLEERR3(func, p->ierr, "free edge= %d not preserved, nodes= %d %d", id, p->edge[id].no[0], p->edge[id].no[1]);
                numerr += 1;
            }
        }
        else if (p->edge[id].nelem > 2) {
            if (p->edge[id].pres == 0) {
#ifdef VISMESH_DEBUG
                printf("*****Non-manifold Edge not preserved");
                printf(" edge id= %d, node ids= %d %d, nelem= %d\n", id, p->edge[id].no[0], p->edge[id].no[1], p->edge[id].nelem);
#endif
                p->ierr = SYS_ERROR_OPERATION;
                HANDLEERR4(func, p->ierr, "Non-manifold edge= %d not preserved, nelem= %d, nodes= %d %d", id, p->edge[id].nelem,
                           p->edge[id].no[0], p->edge[id].no[1]);
                numerr += 1;
            }
        }
        /* check size */
        if (p->edge[id].size < 0.) {
            p->ierr = SYS_ERROR_OPERATION;
            HANDLEERR3(func, p->ierr, "Negative edge size= %d, nodes= %d %d", id, p->edge[id].no[0], p->edge[id].no[1]);
            numerr += 1;
        }
        /* look at each connected element */
        for (i = 0; i < p->edge[id].nelem; i++) {
            elid = p->edge[id].el[i];
            /* first element slot can never be zero */
            if (elid == 0) {
                nfre += 1;
#ifdef VISMESH_DEBUG
                printf("*****Mesh not consistent");
                printf(" edge id= %d, node ids= %d %d, elem ids= %d %d\n", id, p->edge[id].no[0], p->edge[id].no[1],
                       p->edge[id].el[0], p->edge[id].el[1]);
#endif
                p->ierr = SYS_ERROR_OPERATION;
                HANDLEERR2(func, p->ierr, "Inconsistent edge, nodes= %d %d", p->edge[id].no[0], p->edge[id].no[1]);
                numerr += 1;
            }
            /* check normals */
            if (p->normalflag) {
                if (p->elem[elid].ne == NULL) {
#ifdef VISMESH_DEBUG
                    printf("*****Mesh not consistent");
                    printf(" edge id= %d, node ids= %d %d, elem ids= %d %d\n", id, p->edge[id].no[0], p->edge[id].no[1],
                           p->edge[id].el[0], p->edge[id].el[1]);
#endif
                    p->ierr = SYS_ERROR_OPERATION;
                    HANDLEERR1(func, p->ierr, "No element normals edge, elem= %d", elid);
                    numerr += 1;
                }
            }
            /* edge must appear only once in element */
            nn = p->elem[elid].nn;
            ne = 0;
            for (k = 0; k < nn; k++) {
                edid = p->elem[elid].ed[k];
                if (edid == id) {
                    ne += 1;
                }
            }
            if (ne == 1)
                continue;
#ifdef VISMESH_DEBUG
            printf("*****Mesh not consistent");
            printf(" edge id= %d, node ids= %d %d, elem ids= %d %d\n", id, p->edge[id].no[0], p->edge[id].no[1],
                   p->edge[id].el[0], p->edge[id].el[1]);
#endif
            p->ierr = SYS_ERROR_OPERATION;
            HANDLEERR2(func, p->ierr, "Inconsistent edge, nodes= %d %d", p->edge[id].no[0], p->edge[id].no[1]);
            numerr += 1;
        }
        /* look at each connected node */
        for (k = 0; k < 2; k++) {
            ne = 0;
            noid = p->edge[id].no[k];
            /* check size, dist */
            if (p->node[noid].dist < 0. || p->node[noid].size < 0.) {
                p->ierr = SYS_ERROR_OPERATION;
                HANDLEERR1(func, p->ierr, "Negative node size or dist= %d", noid);
                numerr += 1;
            }
            /* edge must appear only once in node */
            inoed = p->node[noid].noed;
            in = 0;
            for (i = 0; i < p->node[noid].ned; i++, in++) {
                if (in == MESHCON_MAXNOED) {
                    inoed = p->noed[inoed].noed;
                    in = 0;
                }
                edid = p->noed[inoed].ed[in];
                if (edid == id) {
                    ne += 1;
                }
            }
            if (ne == 1)
                continue;
#ifdef VISMESH_DEBUG
            printf("**Mesh not consistent, edge id= %d, node id= %d\n", id, noid);
#endif
            p->ierr = SYS_ERROR_OPERATION;
            HANDLEERR1(func, p->ierr, "Inconsistent node= %d", noid);
            numerr += 1;
        }
        /* look at each connected front */
        for (i = 0; i < p->edge[id].nelem; i++) {
            frid = p->edge[id].fr[i];
            if (frid == 0)
                continue;
            elid = p->frnt[frid].elid;
            if (elid == 0) {
#ifdef VISMESH_DEBUG
                printf("*****Mesh not consistent");
                printf(" edge id= %d, node ids= %d %d, frnt ids= %d %d\n", id, p->edge[id].no[0], p->edge[id].no[1],
                       p->edge[id].fr[0], p->edge[id].fr[1]);
#endif
                p->ierr = SYS_ERROR_OPERATION;
                HANDLEERR2(func, p->ierr, "Inconsistent front edge, nodes= %d %d", p->edge[id].no[0], p->edge[id].no[1]);
                numerr += 1;
            }
            if (elid != p->edge[id].el[i]) {
#ifdef VISMESH_DEBUG
                printf("*****Mesh not consistent");
                printf(" edge id= %d, node= %d %d, elem= %d %d, frnt= %d %d\n", id, p->edge[id].no[0], p->edge[id].no[1],
                       p->edge[id].el[0], p->edge[id].el[1], p->edge[id].fr[0], p->edge[id].fr[1]);
#endif
                p->ierr = SYS_ERROR_OPERATION;
                HANDLEERR2(func, p->ierr, "Inconsistent front edge, nodes= %d %d", p->edge[id].no[0], p->edge[id].no[1]);
                numerr += 1;
            }
            k = p->frnt[frid].elk;
            edid = p->elem[elid].ed[k];
            if (edid != id || p->edge[edid].fr[i] != frid) {
#ifdef VISMESH_DEBUG
                printf("*****Mesh not consistent");
                printf(" edge id= %d, node ids= %d %d, frnt ids= %d %d\n", id, p->edge[id].no[0], p->edge[id].no[1],
                       p->edge[id].fr[0], p->edge[id].fr[1]);
#endif
                p->ierr = SYS_ERROR_OPERATION;
                HANDLEERR2(func, p->ierr, "Inconsistent front edge, nodes= %d %d", p->edge[id].no[0], p->edge[id].no[1]);
                numerr += 1;
            }
            if (p->checkclosedfrnt) {
                if (p->frnt[frid].fr[0] == 0 || p->frnt[frid].fr[1] == 0) {
#ifdef VISMESH_DEBUG
                    printf("*****Mesh fronts not closed");
                    printf(" frnt id= %d, node ids= %d %d, frnt ids= %d %d\n", frid, p->frnt[frid].no[0], p->frnt[frid].no[1],
                           p->frnt[frid].fr[0], p->frnt[frid].fr[1]);
#endif
                    p->ierr = SYS_ERROR_OPERATION;
                    HANDLEERR0(func, p->ierr, "Fronts not closed");
                    numerr += 1;
                }
                /* make sure neighboring front points back to this one */
                for (j = 0; j < 2; j++) {
                    frida = p->frnt[frid].fr[j];
                    if (frid != p->frnt[frida].fr[1 - j]) {
#ifdef VISMESH_DEBUG
                        printf("*****Mesh fronts not closed, inconsistent neighbor");
                        printf(" frnt id= %d, node ids= %d %d, frnt ids= %d %d\n", frid, p->frnt[frid].no[0], p->frnt[frid].no[1],
                               p->frnt[frid].fr[0], p->frnt[frid].fr[1]);
#endif
                        p->ierr = SYS_ERROR_OPERATION;
                        HANDLEERR0(func, p->ierr, "Fronts not closed");
                        numerr += 1;
                    }
                }
            }
        }
        if (numerr > maxerr)
            break;
    }
    /* check for zero area elements */
    iter = 0;
    for (;;) {
        if (iter == 0) {
            id = p->headelem;
            iter = id;
        }
        else {
            id = p->elem[iter].next;
            if (id != 0) {
                iter = id;
            }
        }
        if (id == 0)
            break;
        vis_MeshConElemArea(p, id, &area);
        if (area <= 0.) {
            if (p->verbose) {
                HANDLEERR1(func, p->ierr, "Zero area element= %d", id);
            }
        }
    }
}

/*----------------------------------------------------------------------
                      extent
----------------------------------------------------------------------*/
extern void
vis_MeshConExtent(vis_MeshCon* p, Vdouble extent[2][3])
{
    Vint i;
    Vint init;
    Vdouble x[3];

    init = 0;
    for (i = p->headnode; i != 0; i = p->node[i].next) {
        MOVE3(p->node[i].x, x);
        if (init == 0) {
            MOVE3(x, extent[0]);
            MOVE3(x, extent[1]);
            init = 1;
        }
        extent[0][0] = MIN2(x[0], extent[0][0]);
        extent[1][0] = MAX2(x[0], extent[1][0]);
        extent[0][1] = MIN2(x[1], extent[0][1]);
        extent[1][1] = MAX2(x[1], extent[1][1]);
        extent[0][2] = MIN2(x[2], extent[0][2]);
        extent[1][2] = MAX2(x[2], extent[1][2]);
        if (p->node[i].next == 0)
            break;
    }
}

/*----------------------------------------------------------------------
                      load connect
----------------------------------------------------------------------*/
extern void
vis_MeshConLoadConnect(vis_MeshCon* p, vis_Connect* connect)
{
    vsy_IntHash* inthash;
    Vint i, numel, j, nedge;
    Vint shape, flag;

    inthash = vsy_IntHashBegin();
    vis_ConnectDef(connect, p->numnode, p->numelem);
    /* load nodes */
    for (i = p->headnode; i != 0; i = p->node[i].next) {
        vis_ConnectSetCoordsdv(connect, i, p->node[i].x);
    }
    /* load elements */
    numel = 0;
    for (i = p->headelem; i != 0; i = p->elem[i].next) {
        if (p->elem[i].nn == 3) {
            shape = VIS_SHAPETRI;
            nedge = 3;
        }
        else {
            shape = VIS_SHAPEQUAD;
            nedge = 4;
        }
        ++numel;
        vis_ConnectSetTopology(connect, numel, shape, 0, 0, 0);
        vis_ConnectSetElemNode(connect, numel, p->elem[i].no);
        vis_ConnectSetElemAssoc(connect, VIS_USERID, numel, i);

        for (j = 0; j < nedge; j++) {
            vsy_IntHashLookup(inthash, p->elem[i].ed[j], &flag);
            if (!flag) {
                vsy_IntHashInsert(inthash, p->elem[i].ed[j], 1);
                ++numel;
                vis_ConnectSetTopology(connect, numel, SYS_SHAPELINE, 0, 0, 0);
                vis_ConnectSetElemNode(connect, numel, p->edge[p->elem[i].ed[j]].no);
                vis_ConnectSetElemAssoc(connect, VIS_USERID, numel, p->elem[i].ed[j]);
            }
        }
    }
    vsy_IntHashEnd(inthash);
}

/*----------------------------------------------------------------------
                      Summary
----------------------------------------------------------------------*/
extern void
vis_MeshConSummary(vis_MeshCon* p)
{
    printf("\n MeshCon Summary:\n");
    printf(" numnode = %d\n", p->numnode);
    printf(" numelem = %d\n", p->numelem);
    printf(" numedge = %d\n", p->numedge);
    printf(" SplitElem     = %d\n", p->nsplitelem);
    printf(" SplitEdge     = %d\n", p->nsplitedge);
    printf(" SwapEdge      = %d\n", p->nswapedge);
    printf(" CollapseEdge  = %d\n", p->ncollapseedge);
    printf(" Project iter     = %d\n", p->nprojiter);
    printf(" Project glob     = %d\n", p->nprojglob);
    printf(" ProjectEdge iter = %d\n", p->nprojedgeiter);
    printf(" ProjectEdge pres = %d\n", p->nprojedgepres);
    printf(" ProjectEdge glob = %d\n", p->nprojedgeglob);
}

/*----------------------------------------------------------------------
                      print
----------------------------------------------------------------------*/
extern void
vis_MeshConPrint(vis_MeshCon* p)
{
    Vint i, j;
    Vint in, inoed;

    printf("\n MeshCon Object:\n");
    printf(" numnode = %d\n", p->numnode);
    printf(" numelem = %d\n", p->numelem);
    printf(" numedge = %d\n", p->numedge);

    /* elements */
    printf("elements\n");
    for (i = p->headelem; i != 0; i = p->elem[i].next) {
        if (p->elem[i].nn == 3) {
            printf("id= %d,  no= %d %d %d,  ed= %d %d %d,", i, p->elem[i].no[0], p->elem[i].no[1], p->elem[i].no[2],
                   p->elem[i].ed[0], p->elem[i].ed[1], p->elem[i].ed[2]);
        }
        else {
            printf("id= %d,  no= %d %d %d %d,  ed= %d %d %d %d,", i, p->elem[i].no[0], p->elem[i].no[1], p->elem[i].no[2],
                   p->elem[i].no[3], p->elem[i].ed[0], p->elem[i].ed[1], p->elem[i].ed[2], p->elem[i].ed[3]);
        }
        printf(" pres= %d, pind= %d, flat= %d,  size= %e\n", p->elem[i].pres, p->elem[i].pind, p->elem[i].flat, p->elem[i].size);
        if (p->normalflag && p->elem[i].ne != NULL) {
            printf(" norm[0]= %f %f %f\n", p->elem[i].ne[0][0], p->elem[i].ne[0][1], p->elem[i].ne[0][2]);
            printf(" norm[1]= %f %f %f\n", p->elem[i].ne[1][0], p->elem[i].ne[1][1], p->elem[i].ne[1][2]);
            printf(" norm[2]= %f %f %f\n", p->elem[i].ne[2][0], p->elem[i].ne[2][1], p->elem[i].ne[2][2]);
        }
        if (p->elem[i].next == 0)
            break;
    }

    /* edges */
    printf("edges\n");
    for (i = p->headedge; i != 0; i = p->edge[i].next) {
        printf("id= %d,  no= %d %d, nelem= %d, el=", i, p->edge[i].no[0], p->edge[i].no[1], p->edge[i].nelem);
        for (j = 0; j < p->edge[i].nelem; j++) {
            printf(" %d", p->edge[i].el[j]);
        }
        printf(", stat= %d, pres= %d", p->edge[i].stat, p->edge[i].pres);
        if (p->extendflag == 0) {
            printf(", pind= %d", p->edge[i].pind);
        }
        else if (p->extendflag == 1 || p->extendflag == 2) {
            printf(" pind=");
            j = p->edge[i].pind;
            if (j == 0)
                printf(" 0");
            while (j) {
                printf(" %d", p->asmval[j][1]);
                j = p->asmval[j][0];
            }
        }
        printf(", cent= %d", p->edge[i].cent);
        printf(", pref= %d\n", p->edge[i].pref);
        if (p->edge[i].fr[0] || p->edge[i].fr[1]) {
            printf(" fr= %d %d\n", p->edge[i].fr[0], p->edge[i].fr[1]);
        }
        if (p->edge[i].next == 0)
            break;
    }

    /* fronts */
    printf("fronts\n");
    for (i = p->headfrnt; i != 0; i = p->frnt[i].next) {
        printf("id= %d,  elid,elk= %d,%d, no= %d %d, fr= %d %d", i, p->frnt[i].elid, p->frnt[i].elk, p->frnt[i].no[0],
               p->frnt[i].no[1], p->frnt[i].fr[0], p->frnt[i].fr[1]);
        printf(", level= %d\n", p->frnt[i].level);
        printf(" st= %d %d, an= %f %f\n", p->frnt[i].st[0], p->frnt[i].st[1], p->frnt[i].an[0], p->frnt[i].an[1]);
        if (p->frnt[i].next == 0)
            break;
    }

    /* nodes */
    printf("nodes\n");
    for (i = p->headnode; i != 0; i = p->node[i].next) {
        printf("id= %d,  x= %e %e %e\n", i, p->node[i].x[0], p->node[i].x[1], p->node[i].x[2]);
        printf(" pres= %d\n", p->node[i].pres);
        if (p->extendflag == 0) {
            printf(" pind= %d\n", p->node[i].pind);
        }
        else if (p->extendflag == 1 || p->extendflag == 2) {
            printf(" pind=");
            j = p->node[i].pind;
            if (j == 0)
                printf(" 0");
            while (j) {
                printf(" %d", p->asmval[j][1]);
                j = p->asmval[j][0];
            }
            printf("\n");
        }
        printf(" pref= %d\n", p->node[i].pref);
        printf(" size= %e, dist= %e\n", p->node[i].size, p->node[i].dist);
        printf(" ned= %d, ed=", p->node[i].ned);

        inoed = p->node[i].noed;
        in = 0;
        for (j = 0; j < p->node[i].ned; j++, in++) {
            if (in == MESHCON_MAXNOED) {
                inoed = p->noed[inoed].noed;
                in = 0;
            }
            printf(" %d", p->noed[inoed].ed[in]);
        }
        printf("\n");
        if (p->node[i].next == 0)
            break;
    }
}

/*----------------------------------------------------------------------
                      geometry utilities
----------------------------------------------------------------------*/
static void
vis_MeshCon_ElemGath(vis_MeshCon* p, Vint nn, Vint elno[4], Vint eled[4], Vint* npts, Vdouble xd[][3])
{
    Vint k, k1;
    Vint curvflag, flatflag;
    Vint edce[3];
    /* gather quad */
    if (nn == 4) {
        *npts = 4;
        vis_MeshConGetNodes(p, nn, elno, xd);
        return;
    }
    /* gather linear or parabolic tri */
    curvflag = 0;
    flatflag = 0;
    *npts = 3;
    for (k = 0; k < 3; k++) {
        vis_MeshConGetNode(p, elno[k], xd[k]);
        vis_MeshConGetEdgeCent(p, eled[k], &edce[k]);
        if (edce[k]) {
            vis_MeshConGetNode(p, edce[k], xd[k + 3]);
            curvflag = 1;
            *npts = 6;
        }
        else {
            flatflag = 1;
        }
    }
    if (curvflag && flatflag) {
        for (k = 0; k < 3; k++) {
            if (edce[k] == 0) {
                k1 = (k + 1) % 3;
                MID3(xd[k], xd[k1], xd[k + 3]);
            }
        }
    }
}

static void
vis_MeshCon_LocElemGlobal(vis_MeshCon* p, Vint tid, Vdouble atol, Vdouble xp[3], Vint* tgid, Vint* teid, Vdouble rg[3],
                          Vdouble xg[3])
{
    Vdouble xd[6][3], xpd[3], d[3];
    Vdouble r[3];
    Vint nn, elno[4], eled[4];
    Vdouble dist, distmin;
    Vint npts, k1, ke, kn;
    Vint ierr;
    Vint id, idmin, ieflg;
    Vint pres, ptid, pid;
    Vint nhits;
    Vint nptsp;
    Vdouble tol;

    p->projglob = 1;
    p->nprojglob += 1;
    if (tid) {
        vis_MeshCon_LocElemLocal(p, tid, atol, xp, tgid, teid, rg, xg);
        if (*tgid) {
            return;
        }
    }

#ifdef VISMESH_DEBUG
    printf("vis_MeshCon_LocElemGlobal entering, glob= %d\n", p->nprojglob);
    if (p->funflag) {
        if (p->fun) {
            p->fun(p, p->funobject);
        }
    }
#endif

    if (tid) {
        if (p->gm) {
            vis_MeshConGetElemPres(p, tid, &pres);
            if (pres) {
                vis_MeshConGetElemPres(p->gm, pres, &ptid);
            }
            else {
                ptid = 0;
            }
        }
        else {
            vis_MeshConGetElemPres(p, tid, &ptid);
        }
    }
    /* loop through all elements to find minimum distance */
    *tgid = 0;
    *teid = 0;
    idmin = 0;
    if (p->adt) {
        if (atol == 0.) {
            tol = p->adttol;
        }
        else {
            tol = atol;
        }
    }
labelagain:;
    if (p->adt) {
        vsy_ADTreeSetParamd(p->adt, ADTREE_TOLERANCE, tol);
        for (;;) {
            vsy_ADTreeRefPointInit(p->adt, xp);
            vsy_ADTreeGetInteger(p->adt, ADTREE_NUMHITS, &nhits);
            if (nhits)
                break;
            tol *= 2.;
            vsy_ADTreeSetParamd(p->adt, ADTREE_TOLERANCE, tol);
        }
    }
    else {
        vis_MeshConInitElem(p);
    }
    for (;;) {
        if (p->adt) {
            vsy_ADTreeRefPointNext(p->adt, &id);
        }
        else {
            vis_MeshConNextElem(p, &id);
        }
        if (id == 0)
            break;

        if (p->patchproject) {
            if (tid) {
                if (p->gm) {
                    pres = p->elem[id].pres;
                    if (pres) {
                        pid = p->gm->elem[pres].pres;
                    }
                    else {
                        pid = 0;
                    }
                }
                else {
                    pid = p->elem[id].pres;
                }
                if (pid != ptid)
                    continue;
            }
        }
        vis_MeshConGetElem(p, id, &nn, elno, eled);
        /* check for unconnected element */
        if (eled[0] == 0) {
            continue;
        }
        vis_MeshCon_ElemGath(p, nn, elno, eled, &npts, xd);
        /* project to element */
        vis_MeshCon_ElemProject(npts, xd, xp, r, xpd, &nptsp, &ierr);
        ieflg = 0;
        if (ierr) {
            CENT3(xd, xpd);
        }
        else {
            vis_MeshCon_ElemExit(p, nptsp, r, &k1, &ke, &kn);
            if (k1) {
                vis_MeshCon_ElemEdgeProject(nptsp, xd, xp, &ke, r, xpd);
                ieflg = ke;
            }
        }
        /* compute distance */
        DIFF3(xpd, xp, d);
        dist = DOT3(d, d);
#ifdef VISMESH_DEBUG
        if (dist > 20.) {
            printf("dist= %e\n", dist);
            if (p->funflag) {
                if (p->fun) {
                    p->fun(p, p->funobject);
                }
            }
        }
#endif
        if (idmin == 0 || dist < distmin) {
            distmin = dist;
            idmin = id;
            *tgid = idmin;
            if (ieflg) {
                *teid = eled[ke - 1];
            }
            else {
                *teid = 0;
            }
            MOVE3(xpd, xg);
        }
    }
    if (idmin == 0) {
        if (p->adt) {
            tol *= 2.;
            vsy_ADTreeSetParamd(p->adt, ADTREE_TOLERANCE, tol);
            goto labelagain;
        }
    }
    if (*teid) {
        vis_MeshCon_LocElemLocal(p, *tgid, atol, xp, tgid, teid, rg, xg);
        if (*tgid == 0)
            *tgid = idmin;
    }
#ifdef VISMESH_DEBUG
    printf("      tgid= %d, teid= %d\n", *tgid, *teid);
#endif
}

static void
vis_MeshCon_LocElemLocal(vis_MeshCon* p, Vint tid, Vdouble atol, Vdouble xp[3], Vint* tgid, Vint* teid, Vdouble rg[3],
                         Vdouble xg[3])
{
    Vint k, m;
    Vdouble xd[6][3], xpd[3], d[3], xt[3][3], fl, dtol;
    Vdouble r[3];
    Vint nn, elno[4], eled[4], edno[2], edel[2], elid;
    Vint nn1, elno1[4];
    Vdouble dist, distmin, bas, hgt;
    Vint npts, k1, ke, kn, iout;
    Vint ierr;
    Vint id, idmin, ieflg;
    Vint pres, flag;
    Vint nptsp;
    Vint numstk, numlst;
    /* loop through neighboring elements to find minimum distance */
    *tgid = 0;
    *teid = 0;
    idmin = 0;
    /* determine search radius */
    dtol = atol;
    vis_MeshConGetElemNode(p, tid, &nn, elno);
    vis_MeshConGetNodes(p, 3, elno, xt);
    for (k = 0; k < 3; k++) {
        fl = LEN3(xt[k], xp);
        dtol = MAX2(fl, dtol);
    }
    numstk = 1;
    vsy_IntVecSet(p->stk, numstk, tid);
    numlst = 1;
    vsy_IntVecSet(p->lst, numlst, tid);
    vsy_IntVecSet(p->can, tid, 1);
    while (numstk) {
        vsy_IntVecGet(p->stk, numstk, &id);
        numstk--;
        vis_MeshConGetElem(p, id, &nn, elno, eled);
        vis_MeshCon_ElemGath(p, nn, elno, eled, &npts, xd);
        /* project to element */
        vis_MeshCon_ElemProject(npts, xd, xp, r, xpd, &nptsp, &ierr);
        ieflg = 0;
        if (ierr) {
            CENT3(xd, xpd);
        }
        else {
            vis_MeshCon_ElemExit(p, nptsp, r, &k1, &ke, &kn);
            if (k1) {
                vis_MeshCon_ElemEdgeProject(nptsp, xd, xp, &ke, r, xpd);
                ieflg = ke;
            }
        }
        /* compute distance */
        DIFF3(xpd, xp, d);
        dist = DOT3(d, d);
        if (idmin == 0 || dist < distmin) {
            distmin = dist;
            idmin = id;
            *tgid = idmin;
            if (ieflg) {
                *teid = eled[ke - 1];
            }
            else {
                *teid = 0;
            }
            MOVE3(r, rg);
            MOVE3(xpd, xg);
        }
        /* loop through triangle edges */
        for (k = 0; k < 3; k++) {
            vis_MeshConGetEdgePres(p, eled[k], &pres);
            /* preserved edge */
            if (pres)
                continue;
            vis_MeshConGetEdge(p, eled[k], edno, edel);
            if (edel[0] == id) {
                elid = edel[1];
            }
            else {
                elid = edel[0];
            }
            vsy_IntVecGet(p->can, elid, &flag);
            if (flag)
                continue;
            vis_MeshConGetElemNode(p, elid, &nn1, elno1);
            /* test all vertices */
            vis_MeshConGetNodes(p, 3, elno1, xt);
            iout = 1;
            for (m = 0; m < 3; m++) {
                fl = LEN3(xt[m], xp);
                if (fl < dtol) {
                    iout = 0;
                    break;
                }
            }
            if (iout)
                continue;
            numstk++;
            vsy_IntVecSet(p->stk, numstk, elid);
            numlst++;
            vsy_IntVecSet(p->lst, numlst, elid);
            vsy_IntVecSet(p->can, elid, 1);
        }
    }
    /* clear cancel */
    for (k = 1; k <= numlst; k++) {
        vsy_IntVecGet(p->lst, k, &id);
        vsy_IntVecSet(p->can, id, 0);
    }
    DIFF3(xg, xp, d);
    dist = MAG3(d);
    vis_baseHeight(xd, &bas, &hgt);
    if (dist > 1. * hgt) {
        *tgid = 0;
    }
}

static void
vis_MeshCon_ElemProject(Vint npts, Vdouble xd[6][3], Vdouble xp[3], Vdouble r[3], Vdouble xpd[3], Vint* nptsp, Vint* ierr)
{
    /* project to triangle or quad */
    *nptsp = npts;
    if (npts == 3) {
        vis_invertNCTridv(xd, xp, r, xpd, ierr);
    }
    else if (npts == 4) {
        vis_invertNCQuaddv(xd, xp, r, xpd, ierr);
    }
    else {
        vis_invertNCTriPardv(xd, xp, r, xpd, ierr);
    }
}

static void
vis_MeshCon_ElemEdgeProject(Vint npts, Vdouble xd[6][3], Vdouble xp[3], Vint* ke, Vdouble r[3], Vdouble xpd[3])
{
    Vint k;
    Vdouble dc, dcmin, rc;
    Vint idc;
    Vint k1;
    Vdouble xe[3][3], xpc[3], d[3];
    Vint ierr;

    idc = 0;
    /* quad element */
    if (npts == 4) {
        for (k = 0; k < 4; k++) {
            if (k == 0) {
                if (r[1] > -1.)
                    continue;
            }
            else if (k == 1) {
                if (r[0] < 1.)
                    continue;
            }
            else if (k == 2) {
                if (r[1] < 1.)
                    continue;
            }
            else if (k == 3) {
                if (r[0] > -1.)
                    continue;
            }
            MOVE3(xd[k], xe[0]);
            k1 = k;
            MOVE3(xd[(k + 1) % 3], xe[1]);
            vis_invertNCLindv(xe, xp, &rc, xpc, &ierr);
            if (rc < -1.) {
                MOVE3(xd[k1], xpc);
            }
            else if (rc > 1.) {
                MOVE3(xd[(k1 + 1) % 3], xpc);
            }
            DIFF3(xpc, xp, d);
            dc = DOT3(d, d);
            if (idc == 0) {
                dcmin = dc;
                MOVE3(xpc, xpd);
                *ke = k1 + 1;
                idc = 1;
            }
            else {
                if (dc < dcmin) {
                    dcmin = dc;
                    MOVE3(xpc, xpd);
                    *ke = k1 + 1;
                }
            }
        }
        return;
    }
    /* tri element */
    r[2] = 1. - r[0] - r[1];
    for (k = 0; k < 3; k++) {
        if (r[k] > 0.)
            continue;
        k1 = (k + 2) % 3;
        if (npts == 3) {
            MOVE3(xd[k1], xe[0]);
            MOVE3(xd[(k1 + 1) % 3], xe[1]);
            vis_invertNCLindv(xe, xp, &rc, xpc, &ierr);
        }
        else {
            MOVE3(xd[k1], xe[0]);
            MOVE3(xd[k1 + 3], xe[1]);
            MOVE3(xd[(k1 + 1) % 3], xe[2]);
            vis_invertNCLinPardv(xe, xp, &rc, xpc, &ierr);
        }
        if (rc < -1.) {
            MOVE3(xd[k1], xpc);
        }
        else if (rc > 1.) {
            MOVE3(xd[(k1 + 1) % 3], xpc);
        }
        DIFF3(xpc, xp, d);
        dc = DOT3(d, d);
        if (idc == 0) {
            dcmin = dc;
            MOVE3(xpc, xpd);
            *ke = k1 + 1;
            idc = 1;
        }
        else {
            if (dc < dcmin) {
                dcmin = dc;
                MOVE3(xpc, xpd);
                *ke = k1 + 1;
            }
        }
    }
}

static void
vis_MeshCon_DistEdge(vis_MeshCon* p, Vdouble xp[3], Vdouble xpd[3], Vint npts, Vdouble xd[2][3], Vdouble* dist, Vint* ierr)
{
    Vdouble d[3], d1[3];
    Vdouble cn = .1;
    Vdouble cp = .2;
    Vdouble fa, deltan, dn;
    /* ierr= 1 if distant, ierr= 2 if grossly distant */
    DIFF3(xp, xpd, d);
    DIFF3(xd[0], xd[npts - 1], d1);
    fa = MAG3(d1);
    deltan = cn * fa;
    dn = MAG3(d);
    *ierr = 0;
    /* not close enough */
    if (dn > deltan) {
        if (p->tinylen) {
            if (dn > p->tinylen) {
                *ierr = 1;
            }
        }
        else {
            *ierr = 1;
        }
        if (dn > cp * fa) {
            *ierr = 2;
        }
    }
    *dist = dn;
}

static void
vis_MeshCon_DistFace(vis_MeshCon* p, Vdouble xp[3], Vdouble xpd[3], Vdouble xd[3][3], Vdouble* dist, Vint* ierr)
{
    Vint i;
    Vdouble cn = .1;
    Vdouble cp = .2;
    Vdouble d[3], fl, fa, deltan, dn;
    /* ierr= 1 if distant, ierr= 2 if grossly distant */
    DIFF3(xp, xpd, d);
    for (i = 0; i < 3; i++) {
        fl = LEN3(xd[i], xd[(i + 1) % 3]);
        if (i == 0) {
            fa = fl;
        }
        else if (fl > fa) {
            fa = fl;
        }
    }
    deltan = cn * fa;
    dn = MAG3(d);
    *ierr = 0;
    /* not close enough */
    if (dn > deltan) {
        if (p->tinylen) {
            if (dn > p->tinylen) {
                *ierr = 1;
            }
        }
        else {
            *ierr = 1;
        }
        if (dn > cp * fa) {
            *ierr = 2;
        }
    }
    *dist = dn;
}

static void
vis_MeshCon_LocEdgeGlobal(vis_MeshCon* p, Vdouble xp[3], Vint* tgid, Vdouble xg[3])
{
    Vdouble xpd[3], d[3], r;
    Vint edno[2];
    Vdouble dist, distmin;
    Vint id, idmin;
    Vint pres;
    Vint ierr;

    p->nprojedgeglob += 1;
#ifdef VISMESH_DEBUG
    if (p->nprojedgeglob < 10) {
        printf("vis_MeshCon_LocEdgeGlobal entering, glob= %d\n", p->nprojedgeglob);
    }
    if (p->funflag) {
        if (p->fun) {
            p->fun(p, p->funobject);
        }
    }
#endif
    /* loop through preserved edges to find minimum distance */
    idmin = 0;
    for (id = p->headedge; id != 0; id = p->edge[id].next) {
        vis_MeshConGetEdgePres(p, id, &pres);
        if (pres == 0)
            continue;
        vis_MeshConProjectOneEdge(p, id, xp, &r, xpd, &ierr);
        /* clamp to endpoints */
        if (r < -1. || r > 1.) {
            vis_MeshConGetEdgeNode(p, id, edno);
            if (r < -1.) {
                vis_MeshConGetNode(p, edno[0], xpd);
            }
            else if (r > 1.) {
                vis_MeshConGetNode(p, edno[1], xpd);
            }
        }

        DIFF3(xpd, xp, d);
        dist = DOT3(d, d);
        if (idmin == 0 || dist < distmin) {
            distmin = dist;
            idmin = id;
            *tgid = idmin;
            MOVE3(xpd, xg);
        }
        if (p->edge[id].next == 0)
            break;
    }
}

static void
vis_MeshCon_LocEdgePres(vis_MeshCon* p, Vint tid, Vdouble xp[3], Vint* tgid, Vdouble xg[3])
{
    Vdouble xpd[3], d[3], r;
    Vint edno[2];
    Vdouble dist, distmin;
    Vint id, idmin, irev, ibeg, inxt, noid, noix;
    Vint ierr;

    p->nprojedgepres += 1;
#ifdef VISMESH_DEBUG
    if (p->nprojedgepres < 10) {
        printf("vis_MeshCon_LocEdgePres entering, pres= %d\n", p->nprojedgepres);
    }
#endif
    /* find minimum distance, loop forward and backward */
    ibeg = tid;
    id = ibeg;
    idmin = 0;
    irev = 0;
    vis_MeshConGetEdgeNode(p, id, edno);
    noid = edno[0];
    noix = edno[1];
    for (;;) {
        vis_MeshConProjectOneEdge(p, id, xp, &r, xpd, &ierr);
        /* clamp to endpoints */
        if (r < -1. || r > 1.) {
            if (r < -1.) {
                vis_MeshConGetNode(p, edno[0], xpd);
            }
            else if (r > 1.) {
                vis_MeshConGetNode(p, edno[1], xpd);
            }
        }
        /* record minimum distance */
        DIFF3(xpd, xp, d);
        dist = DOT3(d, d);
        if (idmin == 0 || dist < distmin) {
            distmin = dist;
            idmin = id;
            *tgid = idmin;
            MOVE3(xpd, xg);
        }
        /* check for preserved nodes, reverse or exit */
        if (p->node[noid].pres == SYS_NODE) {
            if (irev == 1)
                return;
            irev = 1;
            id = ibeg;
            noid = noix;
            if (p->node[noid].pres == SYS_NODE)
                return;
        }
        /* adjacent edge, back to beginning? */
        vis_MeshConAdjPresEdge(p, id, noid, &inxt);
        if (inxt == ibeg)
            return;
        id = inxt;
        vis_MeshConGetEdgeNode(p, id, edno);
        if (edno[0] == noid) {
            noid = edno[1];
        }
        else {
            noid = edno[0];
        }
    }
}

/*----------------------------------------------------------------------
                      utility for edges
----------------------------------------------------------------------*/
extern void
vis_MeshConAddEdge(vis_MeshCon* p, Vint elid, Vint ixe[2], Vint* edid)
{
    static Vchar func[] = "vis_MeshConAddEdge";
    Vint i, n;
    vis_MeshCon_Edge* pedge;
    Vint* pedgestack;
    Vint pmaxedge;

    /* check to expand storage */
    if (p->numedge + 1 == p->maxedge) {
        pmaxedge = MIN2(20000 + p->maxedge, 2 * p->maxedge);
        pedge = (vis_MeshCon_Edge*)vut_reallocMem(p->edge, (pmaxedge + 1) * sizeof(vis_MeshCon_Edge));
        if (pedge == NULL) {
            p->ierr = VIS_ERROR_MEMORY;
            HANDLEERR0(func, p->ierr, "Realloc edge");
            return;
        }
        p->edge = pedge;
        pedgestack = (Vint*)vut_reallocMem(p->edgestack, (pmaxedge + 1) * sizeof(Vint));
        if (pedgestack == NULL) {
            p->ierr = VIS_ERROR_MEMORY;
            HANDLEERR0(func, p->ierr, "Realloc edgestack");
            return;
        }
        p->edgestack = pedgestack;
        p->edge[p->maxedge].next = p->maxedge + 1;
        for (i = p->maxedge + 1; i <= pmaxedge; i++) {
            p->edge[i].next = i + 1;
            p->edge[i].nelem = 0;
            p->edge[i].melem = 2;
            p->edge[i].el = (Vint*)vut_mallocMem(2 * sizeof(Vint));
            p->edge[i].el[0] = 0;
            p->edge[i].el[1] = 0;
            p->edge[i].fr = (Vint*)vut_mallocMem(2 * sizeof(Vint));
            p->edge[i].fr[0] = 0;
            p->edge[i].fr[1] = 0;
            p->edge[i].size = 0.;
            p->edge[i].ns = NULL;
            p->edge[i].pres = 0;
            p->edge[i].pind = 0;
            p->edge[i].pref = 0;
            p->edge[i].stat = 0;
            p->edge[i].cent = 0;
            p->edge[i].topo = 0;
        }
        p->maxedge = pmaxedge;
        p->edge[p->maxedge].next = 0;
    }
    /* check for replicated nodes */
    if (ixe[0] == ixe[1]) {
        p->ierr = VIS_ERROR_OPERATION;
        HANDLEERR2(func, p->ierr, "Repeated edge nodes= %d %d", ixe[0], ixe[1]);
        return;
    }
    /* get next free edge */
    n = p->edge[0].next;
    p->edge[0].next = p->edge[n].next;

    /* link in edge */
    p->edge[n].next = p->headedge;
    p->edge[n].prev = 0;
    p->edge[p->headedge].prev = n;
    p->headedge = n;

    /* set element and nodes */
    p->edge[n].el[0] = elid;
    p->edge[n].el[1] = 0;
    if (elid == 0) {
        p->edge[n].nelem = 0;
    }
    else {
        p->edge[n].nelem = 1;
    }
    p->edge[n].no[0] = ixe[0];
    p->edge[n].no[1] = ixe[1];

    /* zero front */
    for (i = 0; i < p->edge[n].melem; i++) {
        p->edge[n].fr[i] = 0;
    }

    /* increment nodes with new edge */
    vis_MeshCon_IncNode(p, ixe[0], n);
    vis_MeshCon_IncNode(p, ixe[1], n);

    /* compute edge lengths */
    if (p->edgeheap == MESHCON_MINEDGELEN) {
        vis_MeshCon_MinEdgeLen(p, n);
    }
    else if (p->edgeheap == MESHCON_MAXEDGELEN) {
        vis_MeshCon_MaxEdgeLen(p, n);
    }
    *edid = n;
    p->numedge += 1;
}

extern void
vis_MeshConReverseEdge(vis_MeshCon* p, Vint id)
{
    static Vchar func[] = "vis_MeshConAddEdge";
    Vint ns;
    Vdouble vs[3];
    /* reverse edge connectivity */
    if (id <= 0) {
        p->ierr = SYS_ERROR_VALUE;
        HANDLEERR1(func, p->ierr, "id= %d", id);
        return;
    }
    ns = p->edge[id].no[1];
    p->edge[id].no[1] = p->edge[id].no[0];
    p->edge[id].no[0] = ns;
    if (p->edge[id].ns) {
        MOVE3(p->edge[id].ns[1], vs);
        MOVE3(p->edge[id].ns[0], p->edge[id].ns[1]);
        MOVE3(vs, p->edge[id].ns[0]);
        SCALE3(p->edge[id].ns[0], -1.);
        SCALE3(p->edge[id].ns[1], -1.);
    }
}

static void
vis_MeshCon_IncEdge(vis_MeshCon* p, Vint edid, Vint elid)
{
    static Vchar func[] = "vis_MeshCon_IncEdge";
    Vint nelem, melem;

    if (elid == 0) {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR1(func, p->ierr, "Zero element for edid= %d", edid);
        return;
    }
    nelem = p->edge[edid].nelem;
    if (nelem == p->edge[edid].melem) {
        p->edge[edid].melem += 1;
        melem = p->edge[edid].melem;
        p->edge[edid].el = (Vint*)vut_reallocMem(p->edge[edid].el, melem * sizeof(Vint));
        p->edge[edid].fr = (Vint*)vut_reallocMem(p->edge[edid].fr, melem * sizeof(Vint));
    }
    if (nelem == MESHCON_MAXNMT) {
        p->ierr = SYS_ERROR_OPERATION;
        HANDLEERR2(func, p->ierr, "MESHCON_MAXNMT exceeded for edid= %d, elid= %d", edid, elid);
        return;
    }
    p->edge[edid].el[nelem] = elid;
    p->edge[edid].fr[nelem] = 0;
    p->edge[edid].nelem += 1;
    if (p->edgeheap) {
        vsy_HeapRemove(p->hpedge, edid);
        if (p->edgeheap == MESHCON_MINEDGELEN) {
            vis_MeshCon_MinEdgeLen(p, edid);
        }
        else if (p->edgeheap == MESHCON_MAXEDGELEN) {
            vis_MeshCon_MaxEdgeLen(p, edid);
        }
    }
}

static void
vis_MeshCon_DecEdge(vis_MeshCon* p, Vint edid, Vint elid, Vint flag)
{
    Vint n, nx, pr, i;

    for (n = 0; n < p->edge[edid].nelem; ++n) {
        if (p->edge[edid].el[n] == elid) {
            for (i = n + 1; i < p->edge[edid].nelem; ++i) {
                p->edge[edid].el[i - 1] = p->edge[edid].el[i];
                p->edge[edid].fr[i - 1] = p->edge[edid].fr[i];
            }
            p->edge[edid].nelem -= 1;
            p->edge[edid].el[p->edge[edid].nelem] = 0;
            p->edge[edid].fr[p->edge[edid].nelem] = 0;
            /* delete edge if no element references */
            if (flag && p->edge[edid].nelem == 0) {
                /* decrement nodes with deleted edge */
                vis_MeshCon_DecNode(p, p->edge[edid].no[0], edid);
                vis_MeshCon_DecNode(p, p->edge[edid].no[1], edid);
                /* place edge in free list */
                n = p->edge[0].next;
                p->edge[0].next = edid;
                nx = p->edge[edid].next;
                pr = p->edge[edid].prev;
                p->edge[edid].next = n;
                p->edge[edid].nelem = 0;
                p->edge[edid].size = 0.;
                p->edge[edid].ns = NULL;
                p->edge[edid].pres = 0;
                p->edge[edid].pind = 0;
                p->edge[edid].pref = 0;
                p->edge[edid].stat = 0;
                p->edge[edid].cent = 0;
                p->edge[edid].topo = 0;
                p->edge[edid].el[0] = 0;
                p->edge[edid].el[1] = 0;
                p->edge[edid].fr[0] = 0;
                p->edge[edid].fr[1] = 0;
                /* delete edge from active list */
                p->edge[nx].prev = pr;
                if (pr == 0) {
                    p->headedge = nx;
                }
                else {
                    p->edge[pr].next = nx;
                }
                /* remove from min and max edge */
                if (p->edgeheap) {
                    vsy_HeapRemove(p->hpedge, edid);
                }
                p->numedge -= 1;
            }
            return;
        }
    }
}

/*----------------------------------------------------------------------
                      utility for nodes
----------------------------------------------------------------------*/
static void
vis_MeshCon_IncNode(vis_MeshCon* p, Vint id, Vint edid)
{
    static Vchar func[] = "vis_MeshCon_IncNode";
    Vint inoed, in, jnoed;
    Vint *pinoed, *pinoed1;
    Vint pmxinoed;

    if (p->node[id].ned && p->node[id].ned % MESHCON_MAXNOED == 0) {
        inoed = p->node[id].loed;
        vis_MeshCon_AddNoEd(p, &jnoed);
        p->noed[inoed].noed = jnoed;
        p->node[id].loed = p->noed[inoed].noed;
        in = 0;
    }
    else {
        in = p->node[id].ned % MESHCON_MAXNOED;
    }
    inoed = p->node[id].loed;
    p->noed[inoed].ed[in] = edid;
    p->node[id].ned += 1;
    if (p->node[id].ned > p->mxnoed) {
        p->mxnoed = p->node[id].ned;
        /* GHF
              if(p->verbose) {
                 if(p->mxnoed >= 1000) {
                    HANDLEERR2(func,p->ierr,"node id= %d, ned= %d",id,p->mxnoed);
                 }
              }
        */
        if (p->mxnoed + 1 == p->mxinoed) {
            pmxinoed = p->mxinoed + 100;
            pinoed = (Vint*)vut_reallocMem(p->inoed, (pmxinoed + 1) * sizeof(Vint));
            pinoed1 = (Vint*)vut_reallocMem(p->inoed1, (pmxinoed + 1) * sizeof(Vint));
            if (pinoed == NULL || pinoed1 == NULL) {
                p->ierr = VIS_ERROR_MEMORY;
                if (pinoed)
                    vut_freeMem(pinoed);
                if (pinoed1)
                    vut_freeMem(pinoed1);
                HANDLEERR0(func, p->ierr, "Realloc inoed");
                return;
            }
            p->inoed = pinoed;
            p->inoed1 = pinoed1;
            p->mxinoed = pmxinoed;
        }
    }
}

static void
vis_MeshCon_DecNode(vis_MeshCon* p, Vint id, Vint edid)
{
    Vint j, k;
    Vint in, inoed, ln, lnoed, lb;
    Vint n, nx, pr;

    /* decrement reference to edge */
    inoed = p->node[id].noed;
    in = 0;
    for (j = 0; j < p->node[id].ned; j++, in++) {
        if (in == MESHCON_MAXNOED) {
            inoed = p->noed[inoed].noed;
            in = 0;
        }
        /* edge found */
        if (p->noed[inoed].ed[in] == edid) {
            if (p->node[id].ned > 1) {
                lnoed = p->node[id].loed;
                ln = (p->node[id].ned - 1) % MESHCON_MAXNOED;
                if (j != p->node[id].ned - 1) {
                    p->noed[inoed].ed[in] = p->noed[lnoed].ed[ln];
                }
                /* unlink node edge block */
                if (ln == 0) {
                    /* place block in free list */
                    n = p->noed[0].next;
                    p->noed[0].next = lnoed;
                    nx = p->noed[lnoed].next;
                    pr = p->noed[lnoed].prev;
                    p->noed[lnoed].next = n;

                    /* delete block from active list */
                    p->noed[nx].prev = pr;
                    if (pr == 0) {
                        p->headnoed = nx;
                    }
                    else {
                        p->noed[pr].next = nx;
                    }
                    /* reset last block index */
                    lb = (p->node[id].ned - 1) / MESHCON_MAXNOED;
                    inoed = p->node[id].noed;
                    for (k = 1; k < lb; k++) {
                        inoed = p->noed[inoed].noed;
                    }
                    p->node[id].loed = inoed;
                }
            }
            p->node[id].ned -= 1;
            break;
        }
    }
}

/*----------------------------------------------------------------------
                      utilities for noed
----------------------------------------------------------------------*/
static void
vis_MeshCon_AddNoEd(vis_MeshCon* p, Vint* noed)
{
    static Vchar func[] = "vis_MeshCon_AddNoEd";
    Vint i, n;
    vis_MeshCon_NoEd* pnoed;
    Vint pmaxnoed;
    /* check to expand storage */
    if (p->numnoed + 1 == p->maxnoed) {
        pmaxnoed = MIN2(20000 + p->maxnoed, 2 * p->maxnoed);
        pnoed = (vis_MeshCon_NoEd*)vut_reallocMem(p->noed, (pmaxnoed + 1) * sizeof(vis_MeshCon_NoEd));
        if (pnoed == NULL) {
            p->ierr = VIS_ERROR_MEMORY;
            HANDLEERR0(func, p->ierr, "Realloc noed");
            return;
        }
        p->noed = pnoed;
        for (i = p->maxnoed; i <= pmaxnoed; i++) {
            p->noed[i].next = i + 1;
        }
        p->maxnoed = pmaxnoed;
        p->noed[p->maxnoed].next = 0;
    }
    /* get next free noed */
    n = p->noed[0].next;
    p->noed[0].next = p->noed[n].next;

    /* link in noed */
    p->noed[n].next = p->headnoed;
    p->noed[n].prev = 0;
    p->noed[p->headnoed].prev = n;
    p->headnoed = n;

    *noed = n;
    p->numnoed += 1;
}

/*----------------------------------------------------------------------
                      distance
----------------------------------------------------------------------*/
static void
vis_MeshCon_Distance(vis_MeshCon* p, Vint noid1, Vint noid2, Vdouble* dist)
{
    Vdouble x[2][3], flen, d[3];
    Vdouble ss, s[3][3], sn[2];

    MOVE3(p->node[noid1].x, x[0]);
    MOVE3(p->node[noid2].x, x[1]);
    if (p->ctrlspace) {
        if (p->funani) {
            p->funani(p, p->funobjani, x[0], s);
            vis_transCtrl(s, 2, x);
            DIFF3(x[0], x[1], d);
            flen = MAG3(d);
        }
        else {
            vis_MeshConGetNodeSize(p, noid1, &sn[0]);
            vis_MeshConGetNodeSize(p, noid2, &sn[1]);
            ss = MIN2(sn[0], sn[1]);
            ss = 1. / ss;
            DIFF3(x[0], x[1], d);
            flen = MAG3(d);
            flen *= ss;
        }
    }
    else {
        DIFF3(x[0], x[1], d);
        flen = MAG3(d);
    }
    *dist = flen;
}

/*----------------------------------------------------------------------
                      insert element in search tree
----------------------------------------------------------------------*/
static void
vis_MeshCon_ADTInsert(vis_MeshCon* p, Vint id)
{
    Vdouble xt[4][3];

    vis_MeshConGetNodes(p, p->elem[id].nn, p->elem[id].no, xt);
    vsy_ADTreeInsertElem(p->adt, id, p->elem[id].nn, xt);
}

/*----------------------------------------------------------------------
                      min angle
----------------------------------------------------------------------*/
static void
vis_MeshCon_MinAngle(vis_MeshCon* p, Vint id)
{
    Vint k;
    Vint noid, kmn;
    Vdouble xt[3][3], ang;

    if (p->elem[id].nn == 4) {
        vsy_HeapInsert(p->hpelem, id, 90.);
        return;
    }

    for (k = 0; k < 3; k++) {
        noid = p->elem[id].no[k];
        MOVE3(p->node[noid].x, xt[k]);
    }
    vis_minAngle(xt, &kmn, &ang);
    ang = RAD2DEG(ang);
    /* insert in bin */
    vsy_HeapInsert(p->hpelem, id, ang);
}

/*----------------------------------------------------------------------
                      max angle
----------------------------------------------------------------------*/
static void
vis_MeshCon_MaxAngle(vis_MeshCon* p, Vint id)
{
    Vint k;
    Vint noid, kmn;
    Vdouble xt[3][3], ang;

    if (p->elem[id].nn == 4) {
        vsy_HeapInsert(p->hpelem, id, 90.);
        return;
    }

    for (k = 0; k < 3; k++) {
        noid = p->elem[id].no[k];
        MOVE3(p->node[noid].x, xt[k]);
    }
    vis_maxAngle(xt, &kmn, &ang);
    ang = RAD2DEG(ang);
    /* insert in bin */
    vsy_HeapInsert(p->hpelem, id, ang);
}

/*----------------------------------------------------------------------
                      max angle
----------------------------------------------------------------------*/
static void
vis_MeshCon_MaxMinAngle(vis_MeshCon* p, Vint id)
{
    static Vchar func[] = "vis_MeshCon_MaxMinAngle";
    Vint k;
    Vint noid, kmn;
    Vdouble xt[3][3], ang, area;

    if (p->verbose) {
        vis_MeshConElemArea(p, id, &area);
        if (area == 0.) {
            HANDLEERR1(func, p->ierr, "Zero area element= %d", id);
        }
    }
    if (p->elem[id].nn == 4) {
        vsy_HeapInsert(p->hpelem, id, 90.);
        return;
    }

    for (k = 0; k < 3; k++) {
        noid = p->elem[id].no[k];
        MOVE3(p->node[noid].x, xt[k]);
    }
    vis_minAngle(xt, &kmn, &ang);
    ang = RAD2DEG(ang);
    /* insert in bin */
    vsy_HeapInsert(p->hpelem, id, ang);
}

/*----------------------------------------------------------------------
                      max and min edge length
----------------------------------------------------------------------*/
static void
vis_MeshCon_MaxElemLen(vis_MeshCon* p, Vint id)
{
    static Vchar func[] = "vis_MeshCon_MaxMinLen";
    Vint k;
    Vdouble fl, flen, area, elemsize, size;
    Vint nn;

    if (p->verbose) {
        vis_MeshConElemArea(p, id, &area);
        if (area == 0.) {
            HANDLEERR1(func, p->ierr, "Zero area element= %d", id);
        }
    }
    nn = p->elem[id].nn;
    /* compute maximum edge length in element */
    vis_MeshCon_Distance(p, p->elem[id].no[0], p->elem[id].no[1], &flen);
    for (k = 1; k < nn; k++) {
        vis_MeshCon_Distance(p, p->elem[id].no[k], p->elem[id].no[(k + 1) % nn], &fl);
        if (fl > flen) {
            flen = fl;
        }
    }
    if (p->elemheapsizefact) {
        vis_MeshConGetNodeSize(p, p->elem[id].no[0], &elemsize);
        for (k = 1; k < nn; k++) {
            vis_MeshConGetNodeSize(p, p->elem[id].no[k], &size);
            elemsize = MIN2(size, elemsize);
        }
        if (flen < elemsize * p->elemheapsizefact)
            return;
    }
    /* insert in bin */
    vsy_HeapInsert(p->hpelem, id, flen);
}

static void
vis_MeshCon_MinElemLen(vis_MeshCon* p, Vint id)
{
    static Vchar func[] = "vis_MeshCon_MinMinLen";
    Vint k;
    Vdouble fl, flen, area;
    Vint nn;

    if (p->verbose) {
        vis_MeshConElemArea(p, id, &area);
        if (area == 0.) {
            HANDLEERR1(func, p->ierr, "Zero area element= %d", id);
        }
    }
    nn = p->elem[id].nn;
    /* compute maximum edge length in element */
    vis_MeshCon_Distance(p, p->elem[id].no[0], p->elem[id].no[1], &flen);
    for (k = 1; k < nn; k++) {
        vis_MeshCon_Distance(p, p->elem[id].no[k], p->elem[id].no[(k + 1) % nn], &fl);
        if (fl < flen) {
            flen = fl;
        }
    }
    /* insert in bin */
    vsy_HeapInsert(p->hpelem, id, flen);
}

/*----------------------------------------------------------------------
                      edge length
----------------------------------------------------------------------*/
static void
vis_MeshCon_MaxEdgeLen(vis_MeshCon* p, Vint id)
{
    Vdouble flen;
    Vdouble size[2], edgesize;

    if (p->edgeheappresonly) {
        if (p->edge[id].pres == 0)
            return;
    }
    vis_MeshCon_Distance(p, p->edge[id].no[0], p->edge[id].no[1], &flen);
    /* insert in bin */
    if (p->edgeheapsizefact) {
        vis_MeshConGetNodeSizes(p, 2, p->edge[id].no, size);
        edgesize = MIN2(size[0], size[1]);
        if (flen < edgesize * p->edgeheapsizefact)
            return;
    }
    vsy_HeapInsert(p->hpedge, id, flen);
}

static void
vis_MeshCon_MinEdgeLen(vis_MeshCon* p, Vint id)
{
    Vdouble flen;
    Vdouble size[2], edgesize;

    if (p->edgeheappresonly) {
        if (p->edge[id].pres == 0)
            return;
    }
    vis_MeshCon_Distance(p, p->edge[id].no[0], p->edge[id].no[1], &flen);
    if (p->edgeheapsizefact) {
        vis_MeshConGetNodeSizes(p, 2, p->edge[id].no, size);
        edgesize = MIN2(size[0], size[1]);
        if (flen > edgesize * p->edgeheapsizefact)
            return;
    }
    /* insert in bin */
    vsy_HeapInsert(p->hpedge, id, flen);
}

/*----------------------------------------------------------------------
                      min frnt length
----------------------------------------------------------------------*/
static void
vis_MeshCon_MinFrntLen(vis_MeshCon* p, Vint id)
{
    Vint k;
    Vint noid, elid, frid;
    Vdouble xt[2][3], d[3], v[3], da[3], va[3], vc[3], sc, fc, an, flen, val;
    Vdouble alen, fl, df[3];
    Vint is, isf, bt[2];

    /* compute length */
    for (k = 0; k < 2; k++) {
        noid = p->frnt[id].no[k];
        MOVE3(p->node[noid].x, xt[k]);
    }
    DIFF3(xt[1], xt[0], d);
    flen = MAG3(d);
    if (flen != 0.) {
        SCALE3(d, 1. / flen);
    }
    /* compute normal of attached element */
    elid = p->frnt[id].elid;
    vis_MeshConFlatNormal(p, elid, v);

    /* compute angles at each end */
    for (k = 0; k < 2; k++) {
        frid = p->frnt[id].fr[k];
        if (frid) {
            elid = p->frnt[frid].elid;
            vis_MeshConFlatNormal(p, elid, va);
            PLUS3(v, va);
            UNIT3(va);
            MOVE3(p->node[p->frnt[frid].no[0]].x, xt[0]);
            MOVE3(p->node[p->frnt[frid].no[1]].x, xt[1]);
            DIFF3(xt[1], xt[0], da);
            alen = MAG3(da);
            /* project d and da to plane perpendicular to va */
            fl = DOT3(d, va);
            SUB3(d, fl, va, df);
            UNIT3(df);
            fl = DOT3(da, va);
            SUB3(da, fl, va, da);
            UNIT3(da);
            /* d and da point away from each other at a front node */
            if (k == 0) {
                SCALE3(da, -1.);
                CROSS3(df, da, vc);
            }
            else {
                SCALE3(df, -1.);
                CROSS3(da, df, vc);
            }
            /* now compute angle 0 <= an <= 2PI */
            sc = DOT3(df, da);
            fc = DOT3(vc, va);

            sc = CLAMP(sc, -1., 1.);
            sc = SEPSTRUN(sc);
            an = acos(sc);
            if (fc < 0.) {
                an = 2. * PI - an;
            }
            an = fmod(an + 2. * PI, 2. * PI);
            /* check for adjacent front being other front */
            if (p->frnt[id].no[1 - k] == p->frnt[frid].no[k]) {
                an = 2. * PI;
            }
            p->frnt[id].an[k] = an;
            /* reclassify adjacent front */
            p->frnt[frid].an[1 - k] = an;
            bt[0] = (p->frnt[frid].an[0] < p->frntang) + (p->frnt[frid].an[0] < p->cornang);
            bt[1] = (p->frnt[frid].an[1] < p->frntang) + (p->frnt[frid].an[1] < p->cornang);
            is = MIN2(2, bt[0] + bt[1]);
            isf = MIN2(2, p->frnt[frid].st[0] + p->frnt[frid].st[1]);
            if (is != isf) {
                vsy_PQueueLookup(p->bfminlen[isf], frid, &val);
                vsy_PQueueRemove(p->bfminlen[isf], frid);
            }
            vsy_PQueueInsert(p->bfminlen[is], frid, alen);
            p->frnt[frid].st[0] = bt[0];
            p->frnt[frid].st[1] = bt[1];
        }
        else {
            p->frnt[id].an[k] = PI;
        }
    }
    /* insert in bin */
    bt[0] = (p->frnt[id].an[0] < p->frntang) + (p->frnt[id].an[0] < p->cornang);
    bt[1] = (p->frnt[id].an[1] < p->frntang) + (p->frnt[id].an[1] < p->cornang);
    is = MIN2(2, bt[0] + bt[1]);
    isf = MIN2(2, p->frnt[id].st[0] + p->frnt[id].st[1]);
    if (is != isf) {
        if (isf != -2) {
            vsy_PQueueRemove(p->bfminlen[isf], id);
        }
    }
    vsy_PQueueInsert(p->bfminlen[is], id, flen);
    p->frnt[id].st[0] = bt[0];
    p->frnt[id].st[1] = bt[1];
}

/*----------------------------------------------------------------------
                      multiple assoc
----------------------------------------------------------------------*/
static void
vis_MeshCon_AddPind(vis_MeshCon* p, Vint* pind, Vint ival)
{
    static Vchar func[] = "vis_MeshCon_AddPind";
    Vint i;
    Vint savsta, oldmax;
    /* expand multiple assoc slots */
    if (p->asfnum == 0) {
        oldmax = p->asmmax;
        p->asmmax = MAX2(p->asmmax + 1024, 2 * p->asmmax);
        p->asmval = (Vint(*)[2])vut_reallocMem(p->asmval, 2 * (p->asmmax + 1) * sizeof(Vint));
        if (p->asmval == NULL) {
            p->ierr = VIS_ERROR_MEMORY;
            HANDLEERR0(func, p->ierr, "Realloc asmval");
            return;
        }
        p->asfnum = p->asmmax - oldmax;
        p->asfsta = oldmax + 1;
        for (i = oldmax + 1; i < p->asmmax; i++) {
            p->asmval[i][0] = i + 1;
            p->asmval[i][1] = 0;
        }
        p->asmval[p->asmmax][0] = 0;
        p->asmval[p->asmmax][1] = 0;
    }
    /* add association */
    if (*pind == 0) {
        *pind = p->asfsta;
        p->asfsta = p->asmval[p->asfsta][0];
        p->asmval[*pind][0] = 0;
    }
    else {
        savsta = *pind;
        *pind = p->asfsta;
        p->asfsta = p->asmval[p->asfsta][0];
        p->asmval[*pind][0] = savsta;
    }
    p->asmval[*pind][1] = ival;
    p->asfnum -= 1;
}

static void
vis_MeshCon_AppPind(vis_MeshCon* p, Vint* pind, Vint link)
{
    Vint next;

    if (*pind == 0) {
        *pind = link;
    }
    else {
        next = link;
        while (next != 0) {
            vis_MeshCon_AddPind(p, pind, p->asmval[next][1]);
            next = p->asmval[next][0];
        }
    }
}

static void
vis_MeshCon_NumPind(vis_MeshCon* p, Vint pind, Vint* num)
{
    Vint next;

    *num = 0;
    next = pind;
    while (next != 0) {
        *num += 1;
        next = p->asmval[next][0];
    }
}

static void
vis_MeshCon_AllPind(vis_MeshCon* p, Vint pind, Vint* num, Vint ival[])
{
    Vint next;

    *num = 0;
    next = pind;
    while (next != 0) {
        ival[*num] = p->asmval[next][1];
        *num += 1;
        next = p->asmval[next][0];
    }
}

/*----------------------------------------------------------------------
                      check inverted element
----------------------------------------------------------------------*/
extern void
vis_MeshConCheckInvertElem(vis_MeshCon* p, Vint id, Vdouble v[3], Vdouble* metric, Vint* flag)
{
    Vint k;
    Vdouble x[4][3];
    Vdouble met;
    Vint nn, noid;

    nn = p->elem[id].nn;
    for (k = 0; k < nn; k++) {
        noid = p->elem[id].no[k];
        MOVE3(p->node[noid].x, x[k]);
    }
    *flag = 0;

    if (nn == 3) {
        vis_computeMetricTriangle(v, x, &met);
    }
    else {
        vis_computeMetricQuad(v, x, &met);
    }
    /* check user defined metric */
    if (p->collmetflag) {
        if (met <= p->collmet) {
            *flag = 1;
        }
        /* check for strict inversion */
    }
    else {
        if (met <= 0.) {
            *flag = 1;
        }
    }
    *metric = met;
}

/*----------------------------------------------------------------------
                      normal of linear tri or quad
----------------------------------------------------------------------*/
extern void
vis_MeshConFlatNormal(vis_MeshCon* p, Vint id, Vdouble v[3])
{
    Vint k;
    Vdouble x[4][3], d1[3], d2[3];
    Vint nn, noid;
    /* compute normal */
    nn = p->elem[id].nn;
    for (k = 0; k < nn; k++) {
        noid = p->elem[id].no[k];
        MOVE3(p->node[noid].x, x[k]);
    }
    if (nn == 3) {
        DIFF3(x[1], x[0], d1);
        DIFF3(x[2], x[0], d2);
    }
    else {
        DIFF3(x[2], x[0], d1);
        DIFF3(x[3], x[1], d2);
    }
    CROSS3(d1, d2, v);
    UNIT3(v);
}

extern void
vis_MeshConFlatTangent(vis_MeshCon* p, Vint id, Vint k, Vdouble v[3])
{
    Vint nn, noid1, noid2;

    nn = p->elem[id].nn;
    noid1 = p->elem[id].no[k];
    noid2 = p->elem[id].no[(k + 1) % nn];
    DIFF3(p->node[noid2].x, p->node[noid1].x, v);
    UNIT3(v);
}

/*----------------------------------------------------------------------
                      elem curved geometry
----------------------------------------------------------------------*/
extern void
vis_MeshConElemCurv(vis_MeshCon* p, Vint id, Vint* npts, Vdouble x[][3])
{
    static Vchar func[] = "vis_MeshConElemCurv";
    Vint k;
    Vint nn, elno[4], eled[4], it, ie;
    Vdouble vt[3][3], ves[2][3], fv, xe[2][3], xm[3];

    vis_MeshConGetElem(p, id, &nn, elno, eled);
    vis_MeshConGetNodes(p, 3, elno, x);
    if (p->gm) {
        *npts = 6;
        for (k = 0; k < 3; k++) {
            MID3(x[k], x[(k + 1) % 3], xm);
            if (p->edge[eled[k]].pres) {
                vis_MeshConProjectEdge(p, eled[k], xm, &it, x[3 + k]);
            }
            else {
                vis_MeshConProject(p, id, xm, &it, &ie, x[3 + k]);
            }
        }
        return;
    }
    if (nn == 4) {
        p->ierr = VIS_ERROR_OPERATION;
        HANDLEERR0(func, p->ierr, "Quad element not allowed");
        return;
    }
    *npts = 3;
    vis_MeshConGetElemNorm(p, id, vt);
    /* compute midsides */
    for (k = 0; k < 3; k++) {
        MOVE3(x[k], xe[0]);
        MOVE3(x[(k + 1) % 3], xe[1]);
        if (p->edge[eled[k]].pres) {
            vis_MeshConGetEdgeTang(p, eled[k], ves);
            vis_div1DNTangdv(xe, ves, 1, 1, (Vdouble(*)[3])x[3 + k], NULL);
        }
        else {
            MOVE3(vt[k], ves[0]);
            MOVE3(vt[(k + 1) % 3], ves[1]);
            vis_div1DNNormdv(xe, ves, 1, 1, (Vdouble(*)[3])x[3 + k], NULL);
        }
        fv = DOT3(ves[0], ves[1]);
        if (fv < .99999) {
            *npts = 6;
        }
    }
}

/*----------------------------------------------------------------------
                      edge curved geometry
----------------------------------------------------------------------*/
extern void
vis_MeshConEdgeCurv(vis_MeshCon* p, Vint id, Vint* npts, Vdouble x[][3])
{
    Vint k;
    Vint nn, elno[4], eled[4], edno[2], edel[2];
    Vdouble vt[3][3], ves[2][3], fv, xe[3][3];

    if (p->edge[id].pres) {
        vis_MeshConGetEdgeNode(p, id, edno);
        vis_MeshConGetEdgeTang(p, id, ves);
        vis_MeshConGetNodes(p, 2, edno, xe);
        fv = DOT3(ves[0], ves[1]);
        MOVE3(xe[0], x[0]);
        if (fv > .99999) {
            *npts = 2;
            MOVE3(xe[1], x[1]);
        }
        else {
            *npts = 3;
            vis_div1DNTangdv(xe, ves, 1, 1, (Vdouble(*)[3])x[1], NULL);
            MOVE3(xe[1], x[2]);
        }
    }
    else {
        vis_MeshConGetEdge(p, id, edno, edel);
        vis_MeshConGetElem(p, edel[0], &nn, elno, eled);
        vis_MeshConGetNodes(p, 3, elno, xe);
        vis_MeshConGetElemNorm(p, edel[0], vt);
        for (k = 0; k < 3; k++) {
            if (id == eled[k]) {
                MOVE3(vt[k], ves[0]);
                MOVE3(vt[(k + 1) % 3], ves[1]);
                MOVE3(x[k], xe[0]);
                MOVE3(x[(k + 1) % 3], xe[1]);
                fv = DOT3(ves[0], ves[1]);
                MOVE3(xe[0], x[0]);
                if (fv > .99999) {
                    *npts = 2;
                    MOVE3(xe[1], x[1]);
                }
                else {
                    *npts = 3;
                    vis_div1DNNormdv(xe, ves, 1, 1, (Vdouble(*)[3])x[1], NULL);
                    MOVE3(xe[1], x[2]);
                }
                break;
            }
        }
    }
    *npts = 2;
    fv = DOT3(ves[0], ves[1]);
    if (fv < .99999) {
        *npts = 3;
    }
}

/*----------------------------------------------------------------------
                      Bisect
----------------------------------------------------------------------*/
extern void
vis_MeshConBisect(vis_MeshCon* p, Vint noid, Vint edid1, Vint edid2, Vdouble vn[3], Vdouble vt[3], Vdouble vb[3])
{
    Vint n1, n2;
    Vdouble x[3], x1[3], x2[3];
    Vdouble v1[3], v2[3], vc[3], fl, sn;

    MOVE3(p->node[noid].x, x);

    if (noid == p->edge[edid1].no[0]) {
        n1 = p->edge[edid1].no[1];
    }
    else {
        n1 = p->edge[edid1].no[0];
    }
    MOVE3(p->node[n1].x, x1);

    if (noid == p->edge[edid2].no[0]) {
        n2 = p->edge[edid2].no[1];
    }
    else {
        n2 = p->edge[edid2].no[0];
    }
    MOVE3(p->node[n2].x, x2);
    DIFF3(x1, x, v1);
    UNIT3(v1);
    DIFF3(x2, x, v2);
    UNIT3(v2);
    /* tangent */
    DIFF3(v1, v2, vt);
    UNIT3(vt);
    /* bisector */
    fl = DOT3(v1, v2);
    if (fl > .9999) {
        MOVE3(v1, vb);
    }
    else if (fl < -.9999) {
        CROSS3(vn, v1, vb);
    }
    else {
        SUM3(v1, v2, vb);
        UNIT3(vb);
        CROSS3(v1, v2, vc);
        sn = DOT3(vn, vc);
        if (sn < 0.) {
            SCALE3(vb, -1.);
        }
    }
}

/*----------------------------------------------------------------------
                      tangent of straight edge
----------------------------------------------------------------------*/
extern void
vis_MeshConEdgeTangent(vis_MeshCon* p, Vint id, Vdouble v[3])
{
    Vint n0, n1;

    n0 = p->edge[id].no[0];
    n1 = p->edge[id].no[1];
    DIFF3(p->node[n1].x, p->node[n0].x, v);
    UNIT3(v);
}

/*----------------------------------------------------------------------
                      Length of straight edge
----------------------------------------------------------------------*/
extern void
vis_MeshConEdgeLength(vis_MeshCon* p, Vint id, Vdouble* fl)
{
    Vint n0, n1;
    Vdouble v[3];

    n0 = p->edge[id].no[0];
    n1 = p->edge[id].no[1];
    DIFF3(p->node[n1].x, p->node[n0].x, v);
    *fl = MAG3(v);
}

extern void
vis_MeshConEdgeTangLeng(vis_MeshCon* p, Vint id, Vdouble v[3], Vdouble* fl)
{
    Vint n0, n1;
    Vdouble rfl;

    n0 = p->edge[id].no[0];
    n1 = p->edge[id].no[1];
    DIFF3(p->node[n1].x, p->node[n0].x, v);
    *fl = MAG3(v);
    if (*fl != 0.) {
        rfl = 1. / (*fl);
        SCALE3(v, rfl);
    }
}

extern void
vis_MeshConEdgeCurvLength(vis_MeshCon* p, Vint id, Vdouble* fl)
{
    Vint npts;
    Vdouble x[3][3];

    vis_MeshConEdgeCurv(p, id, &npts, x);
    vis_length1DGendv(npts, x, fl);
}

/*----------------------------------------------------------------------
                      compute normal on element edge
----------------------------------------------------------------------*/
extern void
vis_MeshConElemEdgeNorm(vis_MeshCon* p, Vint id, Vint edid, Vint noid, Vint midflag, Vdouble ve[3])
{
    Vint k;
    Vint ked;
    /* compute normal on element edge */
    /* find edge */
    for (k = 0; k < 3; k++) {
        if (p->elem[id].ed[k] == edid) {
            ked = k;
            break;
        }
    }
    /* interpolate or set normal */
    if (midflag) {
        MID3(p->elem[id].ne[ked], p->elem[id].ne[(ked + 1) % 3], ve);
        UNIT3(ve);
    }
    else if (noid == p->elem[id].no[ked]) {
        MOVE3(p->elem[id].ne[ked], ve);
    }
    else {
        MOVE3(p->elem[id].ne[(ked + 1) % 3], ve);
    }
}

/*----------------------------------------------------------------------
                      direction cosines of front
----------------------------------------------------------------------*/
extern void
vis_MeshConFrntDirCos(vis_MeshCon* p, Vint id, Vdouble tm[3][3])
{
    Vint k;
    Vint elid, elk, noid;
    Vdouble xt[3][3];
    /* x' along front, y' in plane, z' normal */
    elid = p->frnt[id].elid;
    elk = p->frnt[id].elk;
    for (k = 0; k < 3; k++) {
        noid = p->elem[elid].no[(elk + k) % 3];
        MOVE3(p->node[noid].x, xt[k]);
    }
    DIFF3(xt[1], xt[0], tm[0]);
    UNIT3(tm[0]);
    DIFF3(xt[2], xt[0], tm[1]);
    CROSS3(tm[0], tm[1], tm[2]);
    UNIT3(tm[2]);
    CROSS3(tm[2], tm[0], tm[1]);
}

/*----------------------------------------------------------------------
                      free utility
----------------------------------------------------------------------*/
static void
vis_MeshCon_Free(vis_MeshCon* p)
{
    Vint i;

    if (p->node != NULL)
        vut_freeMem(p->node);
    p->node = NULL;
    if (p->noed != NULL)
        vut_freeMem(p->noed);
    p->noed = NULL;
    if (p->frnt != NULL)
        vut_freeMem(p->frnt);
    p->frnt = NULL;
    if (p->edge != NULL) {
        for (i = 0; i <= p->maxedge; i++) {
            vut_freeMem(p->edge[i].el);
            vut_freeMem(p->edge[i].fr);
        }
        vut_freeMem(p->edge);
    }
    p->edge = NULL;
    if (p->inoed != NULL)
        vut_freeMem(p->inoed);
    p->inoed = NULL;
    if (p->inoed1 != NULL)
        vut_freeMem(p->inoed1);
    p->inoed1 = NULL;
    if (p->iedl != NULL)
        vut_freeMem(p->iedl);
    p->iedl = NULL;
    if (p->ih) {
        vsy_IntHashEnd(p->ih);
        p->ih = NULL;
    }
    if (p->tpedge) {
        vut_freeMem(p->tpedge);
        p->tpedge = NULL;
        vut_freeMem(p->xpedge);
        p->xpedge = NULL;
    }

    if (p->edgestack != NULL)
        vut_freeMem(p->edgestack);
    p->edgestack = NULL;
    if (p->elem != NULL)
        vut_freeMem(p->elem);
    p->elem = NULL;

    if (p->asmval != NULL)
        vut_freeMem(p->asmval);
    p->asmval = NULL;

    vis_MeshConTermGeomFace(p);
    vis_MeshConTermTree(p);
    if (p->geomfaceinternal) {
        vut_freeMem(p->geomfaceinternal);
        p->geomfaceinternal = NULL;
    }
}
