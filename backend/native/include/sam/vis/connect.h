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
 
#ifndef CONNECT_DEF
#define CONNECT_DEF
#include "sam/base/base.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/assoc.h"
#include "sam/vis/gridfun.h"
#include "sam/vis/state.h"
#include "sam/vis/elemdat.h"
#include "sam/vis/idtran.h"
#include "sam/vis/group.h"
typedef Vint(VConnectMonitorFunc)(vis_Connect*,Vobject*);
struct vis_Connect { Vint ierr;Vint ipre;Vint type;
Vint numelem;Vint numface;Vint numedge;Vint numnode;
Vint maxelno;Vint maxnoel;Vint maxelfa;Vint maxeled;
Vint maxnode;Vint maxelem;Vint defnode;Vint defelem;
Vint ndim;vis_GridFun* gf;vis_State* state;vis_ElemDat*
ednorm;vis_ElemDat* edtang;vis_GridFun* gfed;Vint numname;
vsy_HashTable* namehash;vsy_IntVec* nameidvec;Vint numijk;
vsy_HashTable* ijkhash;vsy_IntVec* ijkidvec;vis_Assoc*
nodelist[VIS_MAXASSOC];vis_Assoc* elemlist[VIS_MAXASSOC];
vis_CHash* edgelist[VIS_MAXASSOC];vis_CHash* facelist[VIS_MAXASSOC];
Vint numnkern;Vint* nodeelem;Vlong* nodeelempntr;Vint*
nodeelemsize;Vshort* polyface;Vlong* polyfacepntr;Vint
redefinetopo;Vschar* elemshap;Vint* elemmaxi;Vint* elemmaxj;
Vshort* elemmaxk;Vint* bmaxelemnodelength;Vint* belemnodelength;
Vlong maxelemnodelength;Vlong elemnodelength;Vint**
elemnode;Vint* elemnodepntr;Vint nelemblk;Vint* elnosize;
vsy_CVect* cven;vsy_CVect* cvne;Vfloat** coords;Vdouble**
coordd;Vint ncoordblk;Vint* eipsize;Vlong eiplength,
*eipind;Vint nicall;vis_IdTran* idtrannode;Vint eicall;
vis_IdTran* idtranelem;vsy_BitVec* bvnf;vsy_HeapInd*
hinf;vsy_BitVec* bvmf;vsy_HeapInd* himf;Vint maxaelno;
Vint* elnoix;Vint* elnoix1;Vint maxjx,*jx;Vfloat (*x)[3];
Vfloat featureangle;Vfloat featuretoler;Vint featuresense;
Vint featurenonman;Vfloat tolerance;Vfloat size;Vint
assoctype;Vint associd;Vint assocfree;Vint shape;Vint
dimension;Vfloat extent[2][3];Vfloat ctm[4][4];Vint
intervalnum;Vint intervalval;Vint iuse;Vfloat curvaturechange;
Vint curvatureflat;Vfloat sampledistance;Vint seednode;
Vint seedelem;Vint seededgeno;Vint seedfaceno;vis_Group*
seedgroup;Vint exactadj;Vlong* bindelemnode;Vint availnode;
Vint availelem;vis_Assoc *nfeat,*efeat;Vint numassoc;
Vint maxassoc;Vint iassoc[VIS_MAXASSOC];Vint numeassoc;
Vint maxeassoc;Vint ieassoc[VIS_MAXASSOC];vsy_IntVec*
iassocv;Vint coordshift;Vint coordblk;Vdouble normal[3];
Vint layassoc;Vint ignoreelem;Vint zerouserid;Vint nproc;
#ifdef __cplusplus
public: VKI_EXTERN vis_Connect(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_Connect(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Pre(Vint);VKI_EXTERN void GetPre(Vint*);
VKI_EXTERN void Def(Vint,Vint);VKI_EXTERN void Inq(Vint*,
Vint*)const;VKI_EXTERN void Mode(Vint);VKI_EXTERN void
SetObject(Vint,Vobject*);VKI_EXTERN void GetObject(Vint,
Vobject**);VKI_EXTERN void SetParamf(Vint,Vfloat);VKI_EXTERN
void SetParamfv(Vint,Vfloat[]);VKI_EXTERN void SetParami(Vint,
Vint);VKI_EXTERN void Number(Vint,Vint*)const;VKI_EXTERN
void SetDimension(Vint);VKI_EXTERN void GetInteger(Vint,
Vint[]);VKI_EXTERN void SetTopology(Vint,Vint,Vint,
Vint,Vint);VKI_EXTERN void Topology(Vint,Vint*,Vint*,
Vint*,Vint*)const;VKI_EXTERN void TopologyShapeArray(Vint[])
const;VKI_EXTERN void TopologyMIJKArray(Vint[])const;
VKI_EXTERN void DelElem(Vint);VKI_EXTERN void IsElem(Vint,
Vint*);VKI_EXTERN void GenElem(Vint*);VKI_EXTERN void
SetNumEIP(Vint,Vint);VKI_EXTERN void NumEIP(Vint,Vint*);
VKI_EXTERN void LngEIP(Vlong*);VKI_EXTERN void IndEIP(Vint,
Vlong*);VKI_EXTERN void SetElemNode(Vint,Vint[]);VKI_EXTERN
void MaxElemNode(Vint*)const;VKI_EXTERN void NumElemNode(Vint,
Vint*)const;VKI_EXTERN void NumElemNodeArray(Vint[])
const;VKI_EXTERN void ProcessPoly();VKI_EXTERN void
LngElemNode(Vlong*);VKI_EXTERN void IndElemNode(Vint,
Vlong*);VKI_EXTERN void IndElemNodei(Vint,Vint*);VKI_EXTERN
void ElemNode(Vint,Vint*,Vint[])const;VKI_EXTERN void
ElemNodeArray(Vint[])const;VKI_EXTERN void ElemNodePtr(Vint,
Vint*,Vint**)const;VKI_EXTERN void SetCoords(Vint,Vfloat[3]);
VKI_EXTERN void SetCoordsArray(Vint,Vfloat[][3]);VKI_EXTERN
void SetCoordsArraydv(Vint,Vdouble[][3]);VKI_EXTERN
void SetCoordsdv(Vint,Vdouble[3]);VKI_EXTERN void Coords(Vint,
Vint[],Vfloat[][3])const;VKI_EXTERN void CoordsArray(Vfloat[][3])
const;VKI_EXTERN void Coordsdv(Vint,Vint[],Vdouble[][3])
const;VKI_EXTERN void CoordsArraydv(Vdouble[][3])const;
VKI_EXTERN void NodeIndex(Vint,Vint*);VKI_EXTERN void
NodeIndices(Vint,Vint[],Vint[]);VKI_EXTERN void ElemIndex(Vint,
Vint*);VKI_EXTERN void ElemIndices(Vint,Vint[],Vint[]);
VKI_EXTERN void SetPartName(Vint,const Vchar*);VKI_EXTERN
void PartName(Vint,Vchar[])const;VKI_EXTERN void NumPartName(Vint*);
VKI_EXTERN void IthPartName(Vint,Vint*,Vchar[]);VKI_EXTERN
void SetPartIJK(Vint,Vint[3]);VKI_EXTERN void PartIJK(Vint,
Vint[])const;VKI_EXTERN void NumPartIJK(Vint*);VKI_EXTERN
void IthPartIJK(Vint,Vint*,Vint[]);VKI_EXTERN void DelNode(Vint);
VKI_EXTERN void IsNode(Vint,Vint*);VKI_EXTERN void GenNode(Vint*);
VKI_EXTERN void SetNodeAssoc(Vint,Vint,Vint);VKI_EXTERN
void SetNodeAssocArray(Vint,Vint,Vint[]);VKI_EXTERN
void NodeAssoc(Vint,Vint,Vint[],Vint[]);VKI_EXTERN void
NodeAssocArray(Vint,Vint[]);VKI_EXTERN void AddNodeAssoc(Vint,
Vint,Vint);VKI_EXTERN void UniNodeAssoc(Vint,Vint,Vint);
VKI_EXTERN void DelNodeAssoc(Vint,Vint);VKI_EXTERN void
NumNodeAssoc(Vint,Vint,Vint*);VKI_EXTERN void AllNodeAssoc(Vint,
Vint,Vint*,Vint[]);VKI_EXTERN void AnyNodeAssoc(Vint,
Vint*);VKI_EXTERN void SetElemAssoc(Vint,Vint,Vint);
VKI_EXTERN void SetElemAssocArray(Vint,Vint,Vint[]);
VKI_EXTERN void ElemAssoc(Vint,Vint,Vint[],Vint[]);
VKI_EXTERN void ElemAssocArray(Vint,Vint[]);VKI_EXTERN
void AddElemAssoc(Vint,Vint,Vint);VKI_EXTERN void UniElemAssoc(Vint,
Vint,Vint);VKI_EXTERN void DelElemAssoc(Vint,Vint);
VKI_EXTERN void NumElemAssoc(Vint,Vint,Vint*);VKI_EXTERN
void AllElemAssoc(Vint,Vint,Vint*,Vint[]);VKI_EXTERN
void AnyElemAssoc(Vint,Vint*);VKI_EXTERN void MultipleElemAssocArray(Vint,
Vint,Vint*);VKI_EXTERN void AnyMultipleElemAssoc(Vint,
Vint*);VKI_EXTERN void MaxMultipleElemAssoc(Vint,Vint*);
VKI_EXTERN void SetElemEntAssoc(Vint,Vint,Vint,Vint,
Vint);VKI_EXTERN void AddElemEntAssoc(Vint,Vint,Vint,
Vint,Vint);VKI_EXTERN void NumElemEntAssoc(Vint,Vint,
Vint,Vint,Vint*);VKI_EXTERN void DelElemEntAssoc(Vint,
Vint,Vint,Vint);VKI_EXTERN void UniElemEntAssoc(Vint,
Vint,Vint,Vint,Vint);VKI_EXTERN void ElemEntAssoc(Vint,
Vint,Vint,Vint,Vint*);VKI_EXTERN void AllElemEntAssoc(Vint,
Vint,Vint,Vint,Vint*,Vint[]);VKI_EXTERN void AnyElemEntAssoc(Vint,
Vint,Vint*);VKI_EXTERN void Dimension(Vint*);VKI_EXTERN
void MallocElemNode(Vint,Vint,void**);VKI_EXTERN void
FreeElemNode(void*);VKI_EXTERN void MallocNodeElem(Vint,
Vint,void**);VKI_EXTERN void FreeNodeElem(void*);VKI_EXTERN
void Demo(Vint,Vfloat,Vint,Vint,Vint,Vint);VKI_EXTERN
void Read(Vint,const Vchar*);VKI_EXTERN void Process(Vint*,
Vint*);VKI_EXTERN void Kernel(Vint);VKI_EXTERN void
ClearKernel();VKI_EXTERN void Write(Vint,const Vchar*);
VKI_EXTERN void Dual(vis_Connect*,vis_Group*);VKI_EXTERN
void MaxNodeElem(Vint*);VKI_EXTERN void NumNodeElem(Vint,
Vint*);VKI_EXTERN void NodeElem(Vint,Vint*,Vint[])const;
VKI_EXTERN void NodeNode(Vint,Vint*,Vint[])const;VKI_EXTERN
void NodeEdgeCornNode(Vint,Vint*,Vint[])const;VKI_EXTERN
void ElemAdj(Vint,Vint,Vint,Vint*,Vint[])const;VKI_EXTERN
void ElemAdjExact(Vint,Vint,Vint,Vint*,Vint[],Vint[])
const;VKI_EXTERN void _rewriteElementsAsPolys(Vint[],
Vint[]);VKI_EXTERN void ElemAdjEnt(Vint,Vint,Vint,Vint*,
Vint[],Vint[])const;VKI_EXTERN void ElemAdjEntWithCornerNodesOption(Vint,
Vint,Vint,Vint*,Vint[],Vint[],Vint)const;VKI_EXTERN
void NodeAdj(Vint,Vint[],Vint*,Vint[])const;VKI_EXTERN
void ElemNum(Vint,Vint,Vint*)const;VKI_EXTERN void ElemMax(Vint,
Vint*)const;VKI_EXTERN void ElemCon(Vint,Vint,Vint,
Vint*,Vint[])const;VKI_EXTERN void ElemCnn(Vint,Vint,
Vint,Vint*,Vint[])const;VKI_EXTERN void ElemCorn(Vint,
Vint,Vint,Vint*,Vint[])const;VKI_EXTERN void ElemTopo(Vint,
Vint,Vint,Vint*,Vint*,Vint*)const;VKI_EXTERN void SetElemNorm(Vint,
Vint,Vfloat[][3]);VKI_EXTERN void SetElemNormdv(Vint,
Vint,Vdouble[][3]);VKI_EXTERN void LngElemNorm(Vint*,
Vint*)const;VKI_EXTERN void IsElemNorm(Vint,Vint,Vint*)
const;VKI_EXTERN void ElemNorm(Vint,Vint,Vfloat[][3])
const;VKI_EXTERN void ElemNormdv(Vint,Vint,Vdouble[][3])
const;VKI_EXTERN void SetElemTang(Vint,Vint,Vfloat[][3]);
VKI_EXTERN void SetElemTangdv(Vint,Vint,Vdouble[][3]);
VKI_EXTERN void LngElemTang(Vint*,Vint*)const;VKI_EXTERN
void IsElemTang(Vint,Vint,Vint*)const;VKI_EXTERN void
ElemTang(Vint,Vint,Vfloat[][3])const;VKI_EXTERN void
ElemTangdv(Vint,Vint,Vdouble[][3])const;VKI_EXTERN void
Extent(vis_Group*,Vfloat[2][3]);VKI_EXTERN void Extentdv(vis_Group*,
Vdouble[2][3]);VKI_EXTERN void ExtentLoc(vis_Group*,
Vfloat[2][3],Vint[2][3]);VKI_EXTERN void CoordSysExtentLoc(vis_Group*,
vis_CoordSys*,Vfloat[2][3],Vint[2][3]);VKI_EXTERN void
SetGroupParamf(Vint,Vfloat);VKI_EXTERN void SetGroupParamfv(Vint,
Vfloat[]);VKI_EXTERN void SetGroupParami(Vint,Vint);
VKI_EXTERN void SetGroupObject(Vint,Vobject*);VKI_EXTERN
void MergeIdTran(vis_IdTran*);VKI_EXTERN void Merge(vis_Group*);
VKI_EXTERN void MergeWithNodeMapping(vis_Group*,vis_IdTran*);
VKI_EXTERN void ElemGroup(Vint,vis_Group*,vis_Group*);
VKI_EXTERN void FaceGroup(Vint,vis_Group*,vis_Group*);
VKI_EXTERN void EdgeGroup(Vint,vis_Group*,vis_Group*);
VKI_EXTERN void NodeGroup(Vint,vis_Group*,vis_Group*);
VKI_EXTERN void ElemIdTran(Vint,vis_Group*,vis_IdTran*);
VKI_EXTERN void NodeIdTran(Vint,vis_Group*,vis_IdTran*);
VKI_EXTERN void SplitElem(Vint,Vint,Vint,Vint);VKI_EXTERN
void SizeElemdv(Vint,Vint,Vint,Vdouble*);VKI_EXTERN
void Copy(vis_Connect*);VKI_EXTERN void Append(vis_Connect*);
VKI_EXTERN void Subset(vis_Group*,vis_Connect*,vis_IdTran*);
VKI_EXTERN void SubsetWithElementMapping(vis_Group*,
vis_Connect*,vis_IdTran*,vis_IdTran*);VKI_EXTERN void
Print();VKI_EXTERN void PrintSummary();VKI_EXTERN void
Tess(vis_Connect*);VKI_EXTERN void GridFun(vis_GridFun*);
VKI_EXTERN Vint CheckElemIndex(Vint,const Vchar*);VKI_EXTERN
void PlaneIntersect(Vdouble[4],vis_Group*,vis_Group*);
VKI_EXTERN void SetNumThreads(Vint);VKI_EXTERN void
AppendSolidOnly(vis_Connect*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_Connect* vis_ConnectBegin(void);VKI_EXTERN
void vis_Connect_Construct(vis_Connect* p);VKI_EXTERN
void vis_ConnectEnd(vis_Connect* p);VKI_EXTERN void
vis_Connect_Destruct(vis_Connect* p);VKI_EXTERN Vint
vis_ConnectError(vis_Connect* p);VKI_EXTERN void vis_ConnectPre(vis_Connect*
p,Vint pre);VKI_EXTERN void vis_ConnectGetPre(vis_Connect*
p,Vint* ipre);VKI_EXTERN void vis_ConnectDef(vis_Connect*
p,Vint nnode,Vint nelem);VKI_EXTERN void vis_ConnectInq(const
vis_Connect* p,Vint* nnode,Vint* nelem);VKI_EXTERN void
vis_ConnectMode(vis_Connect* p,Vint mode);VKI_EXTERN
void vis_ConnectSetObject(vis_Connect* p,Vint objecttype,
Vobject* object);VKI_EXTERN void vis_ConnectGetObject(vis_Connect*
p,Vint objecttype,Vobject** object);VKI_EXTERN void
vis_ConnectSetParamf(vis_Connect* p,Vint ptype,Vfloat
param);VKI_EXTERN void vis_ConnectSetParamfv(vis_Connect*
p,Vint type,Vfloat param[]);VKI_EXTERN void vis_ConnectSetParami(vis_Connect*
p,Vint ptype,Vint iparam);VKI_EXTERN void vis_ConnectNumber(const
vis_Connect* p,Vint type,Vint* numentity);VKI_EXTERN
void vis_ConnectSetDimension(vis_Connect* p,Vint ndim);
VKI_EXTERN void vis_ConnectGetInteger(vis_Connect* p,
Vint type,Vint iparams[]);VKI_EXTERN void vis_ConnectSetTopology(vis_Connect*
p,Vint index,Vint shape,Vint maxi,Vint maxj,Vint maxk);
VKI_EXTERN void vis_ConnectTopology(const vis_Connect*
p,Vint index,Vint* shape,Vint* maxi,Vint* maxj,Vint*
maxk);VKI_EXTERN void vis_ConnectTopologyShapeArray(const
vis_Connect* p,Vint shape[]);VKI_EXTERN void vis_ConnectTopologyMIJKArray(const
vis_Connect* p,Vint mijk[]);VKI_EXTERN void vis_ConnectDelElem(vis_Connect*
p,Vint index);VKI_EXTERN void vis_ConnectIsElem(vis_Connect*
p,Vint index,Vint* flag);VKI_EXTERN void vis_ConnectGenElem(vis_Connect*
p,Vint* index);VKI_EXTERN void vis_ConnectSetNumEIP(vis_Connect*
p,Vint index,Vint numeip);VKI_EXTERN void vis_ConnectNumEIP(vis_Connect*
p,Vint index,Vint* numeip);VKI_EXTERN void vis_ConnectLngEIP(vis_Connect*
p,Vlong* lng);VKI_EXTERN void vis_ConnectIndEIP(vis_Connect*
p,Vint id,Vlong* ind);VKI_EXTERN void vis_ConnectSetElemNode(vis_Connect*
p,Vint index,Vint ix[]);VKI_EXTERN void vis_ConnectMaxElemNode(const
vis_Connect* p,Vint* maxnum);VKI_EXTERN void vis_ConnectNumElemNode(const
vis_Connect* p,Vint index,Vint* nix);VKI_EXTERN void
vis_ConnectNumElemNodeArray(const vis_Connect* p,Vint
num[]);VKI_EXTERN void vis_ConnectProcessPoly(vis_Connect*
p);VKI_EXTERN void vis_ConnectLngElemNode(vis_Connect*
p,Vlong* lng);VKI_EXTERN void vis_ConnectIndElemNode(vis_Connect*
p,Vint id,Vlong* ind);VKI_EXTERN void vis_ConnectIndElemNodei(vis_Connect*
p,Vint id,Vint* ind);VKI_EXTERN void vis_ConnectElemNode(const
vis_Connect* p,Vint index,Vint* nix,Vint ix[]);VKI_EXTERN
void vis_ConnectElemNodeArray(const vis_Connect* p,
Vint ix[]);VKI_EXTERN void vis_ConnectElemNodePtr(const
vis_Connect* p,Vint id,Vint* nix,Vint** ix);VKI_EXTERN
void vis_ConnectSetCoords(vis_Connect* p,Vint index,
Vfloat x[3]);VKI_EXTERN void vis_ConnectSetCoordsArray(vis_Connect*
p,Vint numnp,Vfloat x[][3]);VKI_EXTERN void vis_ConnectSetCoordsArraydv(vis_Connect*
p,Vint numnp,Vdouble x[][3]);VKI_EXTERN void vis_ConnectSetCoordsdv(vis_Connect*
p,Vint id,Vdouble x[3]);VKI_EXTERN void vis_ConnectCoords(const
vis_Connect* p,Vint nix,Vint ix[],Vfloat x[][3]);VKI_EXTERN
void vis_ConnectCoordsArray(const vis_Connect* p,Vfloat
x[][3]);VKI_EXTERN void vis_ConnectCoordsdv(const vis_Connect*
p,Vint nids,Vint ids[],Vdouble x[][3]);VKI_EXTERN void
vis_ConnectCoordsArraydv(const vis_Connect* p,Vdouble
x[][3]);VKI_EXTERN void vis_ConnectNodeIndex(vis_Connect*
p,Vint id,Vint* index);VKI_EXTERN void vis_ConnectNodeIndices(vis_Connect*
p,Vint nids,Vint ids[],Vint index[]);VKI_EXTERN void
vis_ConnectElemIndex(vis_Connect* p,Vint id,Vint* index);
VKI_EXTERN void vis_ConnectElemIndices(vis_Connect*
p,Vint nids,Vint ids[],Vint index[]);VKI_EXTERN void
vis_ConnectSetPartName(vis_Connect* p,Vint partid,const
Vchar* name);VKI_EXTERN void vis_ConnectPartName(const
vis_Connect* p,Vint partid,Vchar name[]);VKI_EXTERN
void vis_ConnectNumPartName(vis_Connect* p,Vint* numpartname);
VKI_EXTERN void vis_ConnectIthPartName(vis_Connect*
p,Vint ith,Vint* partid,Vchar name[]);VKI_EXTERN void
vis_ConnectSetPartIJK(vis_Connect* p,Vint partid,Vint
ijk[3]);VKI_EXTERN void vis_ConnectPartIJK(const vis_Connect*
p,Vint partid,Vint ijk[]);VKI_EXTERN void vis_ConnectNumPartIJK(vis_Connect*
p,Vint* numpartijk);VKI_EXTERN void vis_ConnectIthPartIJK(vis_Connect*
p,Vint ith,Vint* partid,Vint ijk[]);VKI_EXTERN void
vis_ConnectDelNode(vis_Connect* p,Vint index);VKI_EXTERN
void vis_ConnectIsNode(vis_Connect* p,Vint index,Vint*
flag);VKI_EXTERN void vis_ConnectGenNode(vis_Connect*
p,Vint* index);VKI_EXTERN void vis_ConnectSetNodeAssoc(vis_Connect*
p,Vint type,Vint index,Vint aid);VKI_EXTERN void vis_ConnectSetNodeAssocArray(vis_Connect*
p,Vint type,Vint num,Vint aid[]);VKI_EXTERN void vis_ConnectNodeAssoc(vis_Connect*
p,Vint type,Vint nix,Vint ix[],Vint aids[]);VKI_EXTERN
void vis_ConnectNodeAssocArray(vis_Connect* p,Vint type,
Vint aids[]);VKI_EXTERN void vis_ConnectAddNodeAssoc(vis_Connect*
p,Vint type,Vint index,Vint aid);VKI_EXTERN void vis_ConnectUniNodeAssoc(vis_Connect*
p,Vint type,Vint index,Vint aid);VKI_EXTERN void vis_ConnectDelNodeAssoc(vis_Connect*
p,Vint type,Vint index);VKI_EXTERN void vis_ConnectNumNodeAssoc(vis_Connect*
p,Vint type,Vint index,Vint* num);VKI_EXTERN void vis_ConnectAllNodeAssoc(vis_Connect*
p,Vint type,Vint index,Vint* num,Vint aids[]);VKI_EXTERN
void vis_ConnectAnyNodeAssoc(vis_Connect* p,Vint type,
Vint* flag);VKI_EXTERN void vis_ConnectSetElemAssoc(vis_Connect*
p,Vint type,Vint index,Vint aid);VKI_EXTERN void vis_ConnectSetElemAssocArray(vis_Connect*
p,Vint type,Vint num,Vint aid[]);VKI_EXTERN void vis_ConnectElemAssoc(vis_Connect*
p,Vint type,Vint nix,Vint ix[],Vint aids[]);VKI_EXTERN
void vis_ConnectElemAssocArray(vis_Connect* p,Vint type,
Vint aids[]);VKI_EXTERN void vis_ConnectMultipleElemAssocArray(vis_Connect*
p,Vint type,Vint id1,Vint aids[]);VKI_EXTERN void vis_ConnectAddElemAssoc(vis_Connect*
p,Vint type,Vint index,Vint aid);VKI_EXTERN void vis_ConnectUniElemAssoc(vis_Connect*
p,Vint type,Vint index,Vint aid);VKI_EXTERN void vis_ConnectDelElemAssoc(vis_Connect*
p,Vint type,Vint index);VKI_EXTERN void vis_ConnectNumElemAssoc(vis_Connect*
p,Vint type,Vint index,Vint* num);VKI_EXTERN void vis_ConnectAllElemAssoc(vis_Connect*
p,Vint type,Vint index,Vint* num,Vint aids[]);VKI_EXTERN
void vis_ConnectAnyElemAssoc(vis_Connect* p,Vint type,
Vint* flag);VKI_EXTERN void vis_ConnectAnyMultipleElemAssoc(vis_Connect*
p,Vint type,Vint* flag);VKI_EXTERN void vis_ConnectMaxMultipleElemAssoc(vis_Connect*
p,Vint type,Vint* maxNumMultAssoc);VKI_EXTERN void vis_ConnectSetElemEntAssoc(vis_Connect*
p,Vint type,Vint enttype,Vint index,Vint no,Vint aid);
VKI_EXTERN void vis_ConnectAddElemEntAssoc(vis_Connect*
p,Vint type,Vint enttype,Vint index,Vint no,Vint aid);
VKI_EXTERN void vis_ConnectNumElemEntAssoc(vis_Connect*
p,Vint type,Vint enttype,Vint index,Vint no,Vint* num);
VKI_EXTERN void vis_ConnectDelElemEntAssoc(vis_Connect*
p,Vint type,Vint enttype,Vint index,Vint no);VKI_EXTERN
void vis_ConnectUniElemEntAssoc(vis_Connect* p,Vint
type,Vint enttype,Vint index,Vint no,Vint aid);VKI_EXTERN
void vis_ConnectElemEntAssoc(vis_Connect* p,Vint type,
Vint enttype,Vint index,Vint no,Vint* aid);VKI_EXTERN
void vis_ConnectAllElemEntAssoc(vis_Connect* p,Vint
type,Vint enttype,Vint index,Vint no,Vint* num,Vint
aids[]);VKI_EXTERN void vis_ConnectAnyElemEntAssoc(vis_Connect*
p,Vint type,Vint enttype,Vint* flag);VKI_EXTERN void
vis_ConnectDimension(vis_Connect* p,Vint* ndim);VKI_EXTERN
void vis_ConnectMallocElemNode(vis_Connect* p,Vint nrows,
Vint size,void** ptr);VKI_EXTERN void vis_ConnectFreeElemNode(vis_Connect*
p,void* ptr);VKI_EXTERN void vis_ConnectMallocNodeElem(vis_Connect*
p,Vint nrows,Vint size,void** ptr);VKI_EXTERN void vis_ConnectFreeNodeElem(vis_Connect*
p,void* ptr);VKI_EXTERN void vis_ConnectDemo(vis_Connect*
p,Vint oper,Vfloat f,Vint shape,Vint numi,Vint numj,
Vint numk);VKI_EXTERN void vis_ConnectRead(vis_Connect*
p,Vint type,const Vchar* path);VKI_EXTERN void vis_ConnectProcess(vis_Connect*
p,Vint* eindex,Vint* nid);VKI_EXTERN void vis_ConnectKernel(vis_Connect*
p,Vint flag);VKI_EXTERN void vis_ConnectClearKernel(vis_Connect*
p);VKI_EXTERN void vis_ConnectWrite(vis_Connect* p,
Vint type,const Vchar* path);VKI_EXTERN void vis_ConnectDual(vis_Connect*
p,vis_Connect* connectsrc,vis_Group* groupsrc);VKI_EXTERN
void vis_ConnectMaxNodeElem(vis_Connect* p,Vint* maxnum);
VKI_EXTERN void vis_ConnectNumNodeElem(vis_Connect*
p,Vint index,Vint* nix);VKI_EXTERN void vis_ConnectNodeElem(const
vis_Connect* p,Vint index,Vint* nix,Vint ix[]);VKI_EXTERN
void vis_ConnectNodeNode(const vis_Connect* p,Vint id,
Vint* nix,Vint ix[]);VKI_EXTERN void vis_ConnectNodeEdgeCornNode(const
vis_Connect* p,Vint id,Vint* nix,Vint ix[]);VKI_EXTERN
void vis_ConnectElemAdj(const vis_Connect* p,Vint type,
Vint id,Vint no,Vint* nidadj,Vint idadj[]);VKI_EXTERN
void vis_ConnectElemAdjExact(const vis_Connect* p,Vint
type,Vint id,Vint no,Vint* nidadj,Vint idadj[],Vint
localFaceId[]);VKI_EXTERN void vis_ConnectElemAdjEntWithCornerNodesOption(const
vis_Connect* p,Vint type,Vint index,Vint no,Vint* nix,
Vint ixadj[],Vint noadj[],Vint cornerNodesOnlyFlag);
VKI_EXTERN void vis_ConnectElemAdjEnt(const vis_Connect*
p,Vint type,Vint index,Vint no,Vint* nix,Vint ixadj[],
Vint noadj[]);VKI_EXTERN void vis_ConnectNodeAdj(const
vis_Connect* p,Vint nindices,Vint indices[],Vint* nix,
Vint ix[]);VKI_EXTERN void vis_ConnectElemNum(const
vis_Connect* p,Vint type,Vint index,Vint* num);VKI_EXTERN
void vis_ConnectElemMax(const vis_Connect* p,Vint type,
Vint* num);VKI_EXTERN void vis_ConnectElemCon(const
vis_Connect* p,Vint type,Vint index,Vint no,Vint* nix,
Vint ix[]);VKI_EXTERN void vis_ConnectElemCnn(const
vis_Connect* p,Vint type,Vint index,Vint no,Vint* nix,
Vint in[]);VKI_EXTERN void vis_ConnectElemCorn(const
vis_Connect* p,Vint type,Vint index,Vint no,Vint* nix,
Vint in[]);VKI_EXTERN void vis_ConnectElemTopo(const
vis_Connect* p,Vint type,Vint index,Vint no,Vint* shape,
Vint* maxi,Vint* maxj);VKI_EXTERN void vis_ConnectSetElemNorm(vis_Connect*
p,Vint index,Vint no,Vfloat v[][3]);VKI_EXTERN void
vis_ConnectSetElemNormdv(vis_Connect* p,Vint id,Vint
no,Vdouble v[][3]);VKI_EXTERN void vis_ConnectLngElemNorm(const
vis_Connect* p,Vint* lng,Vint* nent);VKI_EXTERN void
vis_ConnectIsElemNorm(const vis_Connect* p,Vint index,
Vint no,Vint* flag);VKI_EXTERN void vis_ConnectElemNorm(const
vis_Connect* p,Vint index,Vint no,Vfloat v[][3]);VKI_EXTERN
void vis_ConnectElemNormdv(const vis_Connect* p,Vint
id,Vint no,Vdouble v[][3]);VKI_EXTERN void vis_ConnectSetElemTang(vis_Connect*
p,Vint index,Vint no,Vfloat v[][3]);VKI_EXTERN void
vis_ConnectSetElemTangdv(vis_Connect* p,Vint id,Vint
no,Vdouble v[][3]);VKI_EXTERN void vis_ConnectLngElemTang(const
vis_Connect* p,Vint* lng,Vint* nent);VKI_EXTERN void
vis_ConnectIsElemTang(const vis_Connect* p,Vint index,
Vint no,Vint* flag);VKI_EXTERN void vis_ConnectElemTang(const
vis_Connect* p,Vint index,Vint no,Vfloat v[][3]);VKI_EXTERN
void vis_ConnectElemTangdv(const vis_Connect* p,Vint
id,Vint no,Vdouble v[][3]);VKI_EXTERN void vis_ConnectExtent(vis_Connect*
p,vis_Group* group,Vfloat extent[2][3]);VKI_EXTERN void
vis_ConnectExtentdv(vis_Connect* p,vis_Group* group,
Vdouble extent[2][3]);VKI_EXTERN void vis_ConnectExtentLoc(vis_Connect*
p,vis_Group* group,Vfloat extent[2][3],Vint ix[2][3]);
VKI_EXTERN void vis_ConnectCoordSysExtentLoc(vis_Connect*
p,vis_Group* group,vis_CoordSys* coordsys,Vfloat extent[2][3],
Vint ix[2][3]);VKI_EXTERN void vis_ConnectSetGroupParamf(vis_Connect*
p,Vint ptype,Vfloat vparam);VKI_EXTERN void vis_ConnectSetGroupParamfv(vis_Connect*
p,Vint ptype,Vfloat param[]);VKI_EXTERN void vis_ConnectSetGroupParami(vis_Connect*
p,Vint ptype,Vint param);VKI_EXTERN void vis_ConnectSetGroupObject(vis_Connect*
p,Vint type,Vobject* object);VKI_EXTERN void vis_ConnectMergeIdTran(vis_Connect*
p,vis_IdTran* idtran);VKI_EXTERN void vis_ConnectMergeWithNodeMapping(vis_Connect*
p,vis_Group* group,vis_IdTran* previousToNewNodeIndices);
VKI_EXTERN void vis_ConnectMerge(vis_Connect* p,vis_Group*
group);VKI_EXTERN void vis_ConnectElemGroup(vis_Connect*
p,Vint oper,vis_Group* group,vis_Group* groupdst);VKI_EXTERN
void vis_ConnectFaceGroup(vis_Connect* p,Vint oper,
vis_Group* group,vis_Group* groupdst);VKI_EXTERN void
vis_ConnectEdgeGroup(vis_Connect* p,Vint oper,vis_Group*
group,vis_Group* groupdst);VKI_EXTERN void vis_ConnectNodeGroup(vis_Connect*
p,Vint oper,vis_Group* group,vis_Group* groupdst);VKI_EXTERN
void vis_ConnectElemIdTran(vis_Connect* p,Vint oper,
vis_Group* group,vis_IdTran* idtran);VKI_EXTERN void
vis_ConnectNodeIdTran(vis_Connect* p,Vint oper,vis_Group*
group,vis_IdTran* idtran);VKI_EXTERN void vis_ConnectSplitElem(vis_Connect*
p,Vint type,Vint index,Vint no,Vint nind);VKI_EXTERN
void vis_ConnectSizeElemdv(vis_Connect* p,Vint type,
Vint index,Vint no,Vdouble* s);VKI_EXTERN void vis_ConnectCopy(vis_Connect*
p,vis_Connect* fromp);VKI_EXTERN void vis_ConnectAppend(vis_Connect*
p,vis_Connect* fromconnect);VKI_EXTERN void vis_ConnectSubset(vis_Connect*
p,vis_Group* group,vis_Connect* subconnect,vis_IdTran*
idtrannode);VKI_EXTERN void vis_ConnectSubsetWithElementMapping(vis_Connect*
p,vis_Group* group,vis_Connect* subconnect,vis_IdTran*
idtranNode,vis_IdTran* idtranElement);VKI_EXTERN void
vis_ConnectPrintSummary(vis_Connect* p);VKI_EXTERN void
vis_ConnectPrint(vis_Connect* p);VKI_EXTERN void vis_ConnectTess(vis_Connect*
p,vis_Connect* input);VKI_EXTERN void vis_ConnectGridFun(vis_Connect*
p,vis_GridFun* gridfun);VKI_EXTERN Vint vis_ConnectCheckElemIndex(vis_Connect*
p,Vint id,const Vchar* func);VKI_EXTERN void vis_ConnectPlaneIntersect(vis_Connect*
p,Vdouble plane_eq[4],vis_Group* group,vis_Group* groupdst);
VKI_EXTERN void vis_ConnectSetNumThreads(vis_Connect*
p,Vint num);
#ifdef __cplusplus
}
#endif
#endif

