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
 
#ifndef GRIDFUN_DEF
#define GRIDFUN_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/group.h"
typedef void(VGridFunNumber)(Vobject*,Vint,Vint*);typedef
void(VGridFunTopology)(Vobject*,Vint,Vint*,Vint*,Vint*,
Vint*);typedef void(VGridFunElemNode)(Vobject*,Vint,
Vint*,Vint[]);typedef void(VGridFunMaxElemNode)(Vobject*,
Vint*);typedef void(VGridFunCoords)(Vobject*,Vint,Vint[],
Vfloat[][3]);typedef void(VGridFunNodeAssoc)(Vobject*,
Vint,Vint,Vint[],Vint[]);typedef void(VGridFunElemAssoc)(Vobject*,
Vint,Vint,Vint[],Vint[]);typedef void(VGridFunElemNum)(Vobject*,
Vint,Vint,Vint*);typedef void(VGridFunElemCon)(Vobject*,
Vint,Vint,Vint,Vint*,Vint[]);typedef void(VGridFunElemTopo)(Vobject*,
Vint,Vint,Vint,Vint*,Vint*,Vint*);typedef void(VGridFunElemAdj)(Vobject*,
Vint,Vint,Vint,Vint*,Vint[]);typedef void(VGridFunMaxNodeElem)(Vobject*,
Vint*);typedef void(VGridFunNodeElem)(Vobject*,Vint,
Vint*,Vint[]);typedef void(VGridFunExtent)(Vobject*,
vis_Group*,Vfloat[2][3]);typedef void(VGridFunElemCnn)(Vobject*,
Vint,Vint,Vint,Vint*,Vint[]);typedef void(VGridFunNodeAdj)(Vobject*,
Vint,Vint[],Vint*,Vint[]);typedef void(VGridFunCoordsdv)(Vobject*,
Vint,Vint[],Vdouble[][3]);typedef void(VGridFunLngElemNode)(Vobject*,
Vlong*);typedef Vint(VGridFunError)(Vobject*);typedef
void(VGridFunNumElemNode)(Vobject*,Vint,Vint*);typedef
void(VGridFunNumNodeElem)(Vobject*,Vint,Vint*);typedef
void(VGridFunElemCorn)(Vobject*,Vint,Vint,Vint,Vint*,
Vint[]);typedef void(VGridFunIndElemNode)(Vobject*,
Vint,Vlong*);typedef void(VGridFunDimension)(Vobject*,
Vint*);typedef void(VGridFunExtentdv)(Vobject*,vis_Group*,
Vdouble[2][3]);typedef void(VGridFunElemEntAssoc)(Vobject*,
Vint,Vint,Vint,Vint,Vint*);typedef void(VGridFunNodeNode)(Vobject*,
Vint,Vint*,Vint[]);typedef void(VGridFunNumEIP)(Vobject*,
Vint,Vint*);typedef void(VGridFunLngEIP)(Vobject*,Vlong*);
typedef void(VGridFunIndEIP)(Vobject*,Vint,Vlong*);
typedef void(VGridFunPartName)(Vobject*,Vint,Vchar[]);
typedef void(VGridFunNumPartName)(Vobject*,Vint*);typedef
void(VGridFunIthPartName)(Vobject*,Vint,Vint*,Vchar[]);
struct vis_GridFun { Vint ierr;Vobject* obj;void (*fun[1])(void);
void (*number)(Vobject*,Vint,Vint*);void (*topology)(Vobject*,
Vint,Vint*,Vint*,Vint*,Vint*);void (*elemnode)(Vobject*,
Vint,Vint*,Vint[]);void (*maxelemnode)(Vobject*,Vint*);
void (*coords)(Vobject*,Vint,Vint[],Vfloat[][3]);void
(*nodeassoc)(Vobject*,Vint,Vint,Vint[],Vint[]);void
(*elemassoc)(Vobject*,Vint,Vint,Vint[],Vint[]);void
(*elemnum)(Vobject*,Vint,Vint,Vint*);void (*elemcon)(Vobject*,
Vint,Vint,Vint,Vint*,Vint[]);void (*elemtopo)(Vobject*,
Vint,Vint,Vint,Vint*,Vint*,Vint*);void (*elemadj)(Vobject*,
Vint,Vint,Vint,Vint*,Vint[]);void (*maxnodeelem)(Vobject*,
Vint*);void (*nodeelem)(Vobject*,Vint,Vint*,Vint[]);
void (*extent)(Vobject*,vis_Group*,Vfloat[2][3]);void
(*elemcnn)(Vobject*,Vint,Vint,Vint,Vint*,Vint[]);void
(*nodeadj)(Vobject*,Vint,Vint[],Vint*,Vint[]);void (*coordsdv)(Vobject*,
Vint,Vint[],Vdouble[][3]);void (*lngelemnode)(Vobject*,
Vlong*);Vint (*error)(Vobject*);void (*numelemnode)(Vobject*,
Vint,Vint*);void (*numnodeelem)(Vobject*,Vint,Vint*);
void (*elemcorn)(Vobject*,Vint,Vint,Vint,Vint*,Vint[]);
void (*indelemnode)(Vobject*,Vint,Vlong*);void (*dimension)(Vobject*,
Vint*);void (*extentdv)(Vobject*,vis_Group*,Vdouble[2][3]);
void (*elementassoc)(Vobject*,Vint,Vint,Vint,Vint,Vint*);
void (*nodenode)(Vobject*,Vint,Vint*,Vint[]);void (*numeip)(Vobject*,
Vint,Vint*);void (*lngeip)(Vobject*,Vlong*);void (*indeip)(Vobject*,
Vint,Vlong*);void (*partname)(Vobject*,Vint,Vchar[]);
void (*numpartname)(Vobject*,Vint*);void (*ithpartname)(Vobject*,
Vint,Vint*,Vchar[]);
#ifdef __cplusplus
public: VKI_EXTERN vis_GridFun(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_GridFun(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Init();VKI_EXTERN void Set(Vint,
Vfunc*);VKI_EXTERN void SetErrorFunction(VfuncInt*);
VKI_EXTERN void Get(Vint,Vfunc**);VKI_EXTERN void SetObj(Vobject*);
VKI_EXTERN void GetObj(Vobject**);VKI_EXTERN void Copy(vis_GridFun*);
VKI_EXTERN void MallocElemNode(Vint,Vint,void**);VKI_EXTERN
void FreeElemNode(void*);VKI_EXTERN void MallocNodeElem(Vint,
Vint,void**);VKI_EXTERN void FreeNodeElem(void*);VKI_EXTERN
void Number(Vint,Vint*)const;VKI_EXTERN void Topology(Vint,
Vint*,Vint*,Vint*,Vint*)const;VKI_EXTERN void MaxElemNode(Vint*)
const;VKI_EXTERN void ElemNode(Vint,Vint*,Vint[])const;
VKI_EXTERN void Coords(Vint,Vint[],Vfloat[][3])const;
VKI_EXTERN void Coordsdv(Vint,Vint[],Vdouble[][3])const;
VKI_EXTERN void NodeAssoc(Vint,Vint,Vint[],Vint[]);
VKI_EXTERN void ElemAssoc(Vint,Vint,Vint[],Vint[]);
VKI_EXTERN void MaxNodeElem(Vint*);VKI_EXTERN void NodeElem(Vint,
Vint*,Vint[])const;VKI_EXTERN void ElemAdj(Vint,Vint,
Vint,Vint*,Vint[])const;VKI_EXTERN void ElemNum(Vint,
Vint,Vint*)const;VKI_EXTERN void ElemCon(Vint,Vint,
Vint,Vint*,Vint[])const;VKI_EXTERN void ElemCnn(Vint,
Vint,Vint,Vint*,Vint[])const;VKI_EXTERN void ElemTopo(Vint,
Vint,Vint,Vint*,Vint*,Vint*)const;VKI_EXTERN void Extent(vis_Group*,
Vfloat[2][3]);VKI_EXTERN void LngElemNode(Vlong*)const;
VKI_EXTERN void NumElemNode(Vint,Vint*)const;VKI_EXTERN
void NumNodeElem(Vint,Vint*)const;VKI_EXTERN void NodeAdj(Vint,
Vint[],Vint*,Vint[])const;VKI_EXTERN void ElemCorn(Vint,
Vint,Vint,Vint*,Vint[])const;VKI_EXTERN void IndElemNode(Vint,
Vlong*)const;VKI_EXTERN void Dimension(Vint*)const;
VKI_EXTERN void Extentdv(vis_Group*,Vdouble[2][3]);
VKI_EXTERN void ElemEntAssoc(Vint,Vint,Vint,Vint,Vint*);
VKI_EXTERN void NodeNode(Vint,Vint*,Vint[]);VKI_EXTERN
void NumEIP(Vint,Vint*);VKI_EXTERN void LngEIP(Vlong*);
VKI_EXTERN void IndEIP(Vint,Vlong*);VKI_EXTERN void
PartName(Vint,Vchar[]);VKI_EXTERN void NumPartName(Vint*);
VKI_EXTERN void IthPartName(Vint,Vint*,Vchar[]);VKI_EXTERN
void SetNumberFun(VGridFunNumber*);VKI_EXTERN void SetTopologyFun(VGridFunTopology*);
VKI_EXTERN void SetElemNodeFun(VGridFunElemNode*);VKI_EXTERN
void SetMaxElemNodeFun(VGridFunMaxElemNode*);VKI_EXTERN
void SetCoordsFun(VGridFunCoords*);VKI_EXTERN void SetNodeAssocFun(VGridFunNodeAssoc*);
VKI_EXTERN void SetElemAssocFun(VGridFunElemAssoc*);
VKI_EXTERN void SetSetElemNumFun(VGridFunElemNum*);
VKI_EXTERN void SetElemConFun(VGridFunElemCon*);VKI_EXTERN
void SetElemTopoFun(VGridFunElemTopo*);VKI_EXTERN void
SetElemAdjFun(VGridFunElemAdj*);VKI_EXTERN void SetMaxNodeElemFun(VGridFunMaxNodeElem*);
VKI_EXTERN void SetNodeElemFun(VGridFunNodeElem*);VKI_EXTERN
void SetExtentFun(VGridFunExtent*);VKI_EXTERN void SetElemCnnFun(VGridFunElemCnn*);
VKI_EXTERN void SetNodeAdjFun(VGridFunNodeAdj*);VKI_EXTERN
void SetCoordsdvFun(VGridFunCoordsdv*);VKI_EXTERN void
SetLngElemNodeFun(VGridFunLngElemNode*);VKI_EXTERN void
SetErrorFun(VGridFunError*);VKI_EXTERN void SetNumElemNodeFun(VGridFunNumElemNode*);
VKI_EXTERN void SetNumNodeElemFun(VGridFunNumNodeElem*);
VKI_EXTERN void SetElemCornFun(VGridFunElemCorn*);VKI_EXTERN
void SetIndElemNodeFun(VGridFunIndElemNode*);VKI_EXTERN
void SetDimensionFun(VGridFunDimension*);VKI_EXTERN
void SetExtentdvFun(VGridFunExtentdv*);VKI_EXTERN void
SetElemEntAssocFun(VGridFunElemEntAssoc*);VKI_EXTERN
void NodeNodeFun(VGridFunNodeNode*);VKI_EXTERN void
NumEIPFun(VGridFunNumEIP*);VKI_EXTERN void LngEIPFun(VGridFunLngEIP*);
VKI_EXTERN void IndEIPFun(VGridFunIndEIP*);VKI_EXTERN
void PartNameFun(VGridFunPartName*);VKI_EXTERN void
NumPartNameFun(VGridFunNumPartName*);VKI_EXTERN void
IthPartNameFun(VGridFunIthPartName*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_GridFun* vis_GridFunBegin(void);VKI_EXTERN
void vis_GridFun_Construct(vis_GridFun* p);VKI_EXTERN
void vis_GridFunEnd(vis_GridFun* p);VKI_EXTERN void
vis_GridFun_Destruct(vis_GridFun* p);VKI_EXTERN Vint
vis_GridFunError(vis_GridFun* p);VKI_EXTERN void vis_GridFunInit(vis_GridFun*
p);VKI_EXTERN void vis_GridFunSet(vis_GridFun* p,Vint
type,Vfunc* function);VKI_EXTERN void vis_GridFunSetErrorFunction(vis_GridFun*
p,VfuncInt* function);VKI_EXTERN void vis_GridFunGet(vis_GridFun*
p,Vint type,Vfunc** function);VKI_EXTERN void vis_GridFunSetObj(vis_GridFun*
p,Vobject* obj);VKI_EXTERN void vis_GridFunGetObj(vis_GridFun*
p,Vobject** obj);VKI_EXTERN void vis_GridFunCopy(vis_GridFun*
p,vis_GridFun* fromp);VKI_EXTERN void vis_GridFunMallocElemNode(vis_GridFun*
p,Vint nrows,Vint size,void** ptr);VKI_EXTERN void vis_GridFunFreeElemNode(vis_GridFun*
p,void* ptr);VKI_EXTERN void vis_GridFunMallocNodeElem(vis_GridFun*
p,Vint nrows,Vint size,void** ptr);VKI_EXTERN void vis_GridFunFreeNodeElem(vis_GridFun*
p,void* ptr);VKI_EXTERN void vis_GridFunNumber(const
vis_GridFun* p,Vint type,Vint* numentity);VKI_EXTERN
void vis_GridFunTopology(const vis_GridFun* p,Vint id,
Vint* shape,Vint* maxi,Vint* maxj,Vint* maxk);VKI_EXTERN
void vis_GridFunMaxElemNode(const vis_GridFun* p,Vint*
maxnum);VKI_EXTERN void vis_GridFunElemNode(const vis_GridFun*
p,Vint id,Vint* nix,Vint ix[]);VKI_EXTERN void vis_GridFunCoords(const
vis_GridFun* p,Vint nids,Vint ids[],Vfloat x[][3]);
VKI_EXTERN void vis_GridFunCoordsdv(const vis_GridFun*
p,Vint nids,Vint ids[],Vdouble x[][3]);VKI_EXTERN void
vis_GridFunNodeAssoc(vis_GridFun* p,Vint type,Vint nix,
Vint ix[],Vint aids[]);VKI_EXTERN void vis_GridFunElemAssoc(vis_GridFun*
p,Vint type,Vint nix,Vint ix[],Vint aids[]);VKI_EXTERN
void vis_GridFunMaxNodeElem(vis_GridFun* p,Vint* maxnum);
VKI_EXTERN void vis_GridFunNodeElem(const vis_GridFun*
p,Vint id,Vint* nix,Vint ix[]);VKI_EXTERN void vis_GridFunElemAdj(const
vis_GridFun* p,Vint type,Vint id,Vint no,Vint* nidadj,
Vint idadj[]);VKI_EXTERN void vis_GridFunElemNum(const
vis_GridFun* p,Vint type,Vint id,Vint* num);VKI_EXTERN
void vis_GridFunElemCon(const vis_GridFun* p,Vint type,
Vint id,Vint no,Vint* nix,Vint ix[]);VKI_EXTERN void
vis_GridFunElemCnn(const vis_GridFun* p,Vint type,Vint
id,Vint no,Vint* nix,Vint in[]);VKI_EXTERN void vis_GridFunElemTopo(const
vis_GridFun* p,Vint type,Vint id,Vint no,Vint* shapet,
Vint* maxit,Vint* maxjt);VKI_EXTERN void vis_GridFunExtent(vis_GridFun*
p,vis_Group* group,Vfloat extent[2][3]);VKI_EXTERN void
vis_GridFunLngElemNode(const vis_GridFun* p,Vlong* lng);
VKI_EXTERN void vis_GridFunNumElemNode(const vis_GridFun*
p,Vint id,Vint* num);VKI_EXTERN void vis_GridFunNumNodeElem(const
vis_GridFun* p,Vint id,Vint* num);VKI_EXTERN void vis_GridFunNodeAdj(const
vis_GridFun* p,Vint nix,Vint ix[],Vint* nidadj,Vint
idadj[]);VKI_EXTERN void vis_GridFunElemCorn(const vis_GridFun*
p,Vint type,Vint id,Vint no,Vint* nix,Vint in[]);VKI_EXTERN
void vis_GridFunIndElemNode(const vis_GridFun* p,Vint
id,Vlong* num);VKI_EXTERN void vis_GridFunDimension(const
vis_GridFun* p,Vint* ndim);VKI_EXTERN void vis_GridFunExtentdv(vis_GridFun*
p,vis_Group* group,Vdouble extent[2][3]);VKI_EXTERN
void vis_GridFunElemEntAssoc(vis_GridFun* p,Vint type,
Vint enttype,Vint id,Vint no,Vint* aid);VKI_EXTERN void
vis_GridFunNodeNode(vis_GridFun* p,Vint id,Vint* nix,
Vint ix[]);VKI_EXTERN void vis_GridFunNumEIP(vis_GridFun*
p,Vint id,Vint* numeip);VKI_EXTERN void vis_GridFunLngEIP(vis_GridFun*
p,Vlong* lngeip);VKI_EXTERN void vis_GridFunIndEIP(vis_GridFun*
p,Vint id,Vlong* indeip);VKI_EXTERN void vis_GridFunPartName(vis_GridFun*
p,Vint partid,Vchar name[]);VKI_EXTERN void vis_GridFunNumPartName(vis_GridFun*
p,Vint* numname);VKI_EXTERN void vis_GridFunIthPartName(vis_GridFun*
p,Vint ith,Vint* partid,Vchar name[]);VKI_EXTERN void
vis_GridFunSetNumberFun(vis_GridFun* p,VGridFunNumber*
func);VKI_EXTERN void vis_GridFunSetTopologyFun(vis_GridFun*
p,VGridFunTopology* func);VKI_EXTERN void vis_GridFunSetElemNodeFun(vis_GridFun*
p,VGridFunElemNode* func);VKI_EXTERN void vis_GridFunSetMaxElemNodeFun(vis_GridFun*
p,VGridFunMaxElemNode* func);VKI_EXTERN void vis_GridFunSetCoordsFun(vis_GridFun*
p,VGridFunCoords* func);VKI_EXTERN void vis_GridFunSetNodeAssocFun(vis_GridFun*
p,VGridFunNodeAssoc* func);VKI_EXTERN void vis_GridFunSetElemAssocFun(vis_GridFun*
p,VGridFunElemAssoc* func);VKI_EXTERN void vis_GridFunSetSetElemNumFun(vis_GridFun*
p,VGridFunElemNum* func);VKI_EXTERN void vis_GridFunSetElemConFun(vis_GridFun*
p,VGridFunElemCon* func);VKI_EXTERN void vis_GridFunSetElemTopoFun(vis_GridFun*
p,VGridFunElemTopo* func);VKI_EXTERN void vis_GridFunSetElemAdjFun(vis_GridFun*
p,VGridFunElemAdj* func);VKI_EXTERN void vis_GridFunSetMaxNodeElemFun(vis_GridFun*
p,VGridFunMaxNodeElem* func);VKI_EXTERN void vis_GridFunSetNodeElemFun(vis_GridFun*
p,VGridFunNodeElem* func);VKI_EXTERN void vis_GridFunSetExtentFun(vis_GridFun*
p,VGridFunExtent* func);VKI_EXTERN void vis_GridFunSetElemCnnFun(vis_GridFun*
p,VGridFunElemCnn* func);VKI_EXTERN void vis_GridFunSetNodeAdjFun(vis_GridFun*
p,VGridFunNodeAdj* func);VKI_EXTERN void vis_GridFunSetCoordsdvFun(vis_GridFun*
p,VGridFunCoordsdv* func);VKI_EXTERN void vis_GridFunSetLngElemNodeFun(vis_GridFun*
p,VGridFunLngElemNode* func);VKI_EXTERN void vis_GridFunSetErrorFun(vis_GridFun*
p,VGridFunError* func);VKI_EXTERN void vis_GridFunSetNumElemNodeFun(vis_GridFun*
p,VGridFunNumElemNode* func);VKI_EXTERN void vis_GridFunSetNumNodeElemFun(vis_GridFun*
p,VGridFunNumNodeElem* func);VKI_EXTERN void vis_GridFunSetElemCornFun(vis_GridFun*
p,VGridFunElemCorn* func);VKI_EXTERN void vis_GridFunSetIndElemNodeFun(vis_GridFun*
p,VGridFunIndElemNode* func);VKI_EXTERN void vis_GridFunSetDimensionFun(vis_GridFun*
p,VGridFunDimension* func);VKI_EXTERN void vis_GridFunSetExtentdvFun(vis_GridFun*
p,VGridFunExtentdv* func);VKI_EXTERN void vis_GridFunSetElemEntAssocFun(vis_GridFun*
p,VGridFunElemEntAssoc* func);VKI_EXTERN void vis_GridFunNodeNodeFun(vis_GridFun*
p,VGridFunNodeNode* func);VKI_EXTERN void vis_GridFunNumEIPFun(vis_GridFun*
p,VGridFunNumEIP* func);VKI_EXTERN void vis_GridFunLngEIPFun(vis_GridFun*
p,VGridFunLngEIP* func);VKI_EXTERN void vis_GridFunIndEIPFun(vis_GridFun*
p,VGridFunIndEIP* func);VKI_EXTERN void vis_GridFunPartNameFun(vis_GridFun*
p,VGridFunPartName* func);VKI_EXTERN void vis_GridFunNumPartNameFun(vis_GridFun*
p,VGridFunNumPartName* func);VKI_EXTERN void vis_GridFunIthPartNameFun(vis_GridFun*
p,VGridFunIthPartName* func);
#ifdef __cplusplus
}
#endif
#define vis_GridFunObj(x)(x)->obj
#if !defined(VKI_FUN_NODEFINE)|| defined(VKI_FUN_DEFINE)
#define vis_GridFunNumber(x,a,b)(x)->number((x)->obj,\
(a),(b))
#define vis_GridFunTopology(x,a,b,c,d,e)(x)->topology((x)->obj,\
(a),(b),(c),(d),(e))
#define vis_GridFunElemNode(x,a,b,c)(x)->elemnode((x)->obj,\
(a),(b),(c))
#define vis_GridFunMaxElemNode(x,a)(x)->maxelemnode((x)->obj,\
(a))
#define vis_GridFunCoords(x,a,b,c)(x)->coords((x)->obj,\
(a),(b),(c))
#define vis_GridFunNodeAssoc(x,a,b,c,d)(x)->nodeassoc((x)->obj,\
(a),(b),(c),(d))
#define vis_GridFunElemAssoc(x,a,b,c,d)(x)->elemassoc((x)->obj,\
(a),(b),(c),(d))
#define vis_GridFunElemNum(x,a,b,c)(x)->elemnum((x)->obj,\
(a),(b),(c))
#define vis_GridFunElemCon(x,a,b,c,d,e)(x)->elemcon((x)->obj,\
(a),(b),(c),(d),(e))
#define vis_GridFunElemTopo(x,a,b,c,d,e,f)(x)->elemtopo((x)->obj,\
(a),(b),(c),(d),(e),(f))
#define vis_GridFunElemAdj(x,a,b,c,d,e)(x)->elemadj((x)->obj,\
(a),(b),(c),(d),(e))
#define vis_GridFunMaxNodeElem(x,a)(x)->maxnodeelem((x)->obj,\
(a))
#define vis_GridFunNodeElem(x,a,b,c)(x)->nodeelem((x)->obj,\
(a),(b),(c))
#define vis_GridFunExtent(x,a,b)(x)->extent((x)->obj,\
(a),(b))
#define vis_GridFunElemCnn(x,a,b,c,d,e)(x)->elemcnn((x)->obj,\
(a),(b),(c),(d),(e))
#define vis_GridFunNodeAdj(x,a,b,c,d)(x)->nodeadj((x)->obj,\
(a),(b),(c),(d))
#define vis_GridFunCoordsdv(x,a,b,c)(x)->coordsdv((x)->obj,\
(a),(b),(c))
#define vis_GridFunLngElemNode(x,a)(x)->lngelemnode((x)->obj,\
(a))
#define vis_GridFunNumElemNode(x,a,b)(x)->numelemnode((x)->obj,\
(a),(b))
#define vis_GridFunNumNodeElem(x,a,b)(x)->numnodeelem((x)->obj,\
(a),(b))
#define vis_GridFunElemCorn(x,a,b,c,d,e)(x)->elemcorn((x)->obj,\
(a),(b),(c),(d),(e))
#define vis_GridFunIndElemNode(x,a,b)(x)->indelemnode((x)->obj,\
(a),(b))
#define vis_GridFunDimension(x,a)(x)->dimension((x)->obj,\
(a))
#define vis_GridFunExtentdv(x,a,b)(x)->extentdv((x)->obj,\
(a),(b))
#define vis_GridFunElemEntAssoc(x,a,b,c,d,e)(x)->elementassoc((x)->obj,\
(a),(b),(c),(d),(e))
#define vis_GridFunNodeNode(x,a,b,c)(x)->nodenode((x)->obj,\
(a),(b),(c))
#define vis_GridFunNumEIP(x,a,b)(x)->numeip((x)->obj,\
(a),(b))
#define vis_GridFunLngEIP(x,a)(x)->lngeip((x)->obj,\
(a))
#define vis_GridFunIndEIP(x,a,b)(x)->indeip((x)->obj,\
(a),(b))
#define vis_GridFunPartName(x,a,b)(x)->partname((x)->obj,\
(a),(b))
#define vis_GridFunNumPartName(x,a)(x)->numpartname((x)->obj,\
(a))
#define vis_GridFunIthPartName(x,a,b,c)(x)->ithpartname((x)->obj,\
(a),(b),(c))
#endif
#endif

