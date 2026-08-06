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
 
#ifndef STATE_DEF
#define STATE_DEF
#include "sam/base/base.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/gridfun.h"
#include "sam/vis/group.h"
struct vis_State { Vint ierr;Vint ipre;Vint nument;
Vint enttype;Vint subtype;Vint datatype;Vint nval;Vint
engstr;Vint magphs;Vint isIntegerdata;Vint complexmode;
Vint complexflag;Vint nvalc;Vint scaleddircos;vis_GridFun*
gf;vis_IdTran* idtrancsys;vsy_HashTable* csh;vsy_HashTable*
edh;vis_State* statedc;vis_State* statera;vis_RProp*
rprop;vis_ElemDat* ed;vis_Group* gred;Vfloat *state,
*statei;Vdouble *statd,*statdi;Vfloat *statesave,*stateisave;
Vdouble *statdsave,*statdisave;vis_ElemDat* edsave;
Vint systemsave;Vlong statesize;Vint pntrlflag;Vint*
statepntr;Vlong* statepntrl;Vint sectype;Vint* statesect;
Vint* statelpos;vsy_CVect* cvl;Vint nrows;Vint maxdataloc;
Vint maxdatasize;Vint maxdatasec;Vdouble* tempd;Vchar*
ca_def;Vint derive;Vint nrowsderive;Vint datatypederive;
Vint section;Vint system;Vint systemtype;Vint systemDefaultToRotAng;
Vint mapnonzero;Vint mapdefined;Vint mapelem;Vint mapnode;
Vint midside;Vint sorthighlow;Vint sortabsvalue;Vint
sortelemnodeave;Vint extentnonzero;Vint listwidth;Vint
mapstat;Vint cyclicSystemId;Vint missingLinkCsys;Vfloat
extent[2];Vdouble (*rd)[3];Vdouble (*xd)[3];Vfloat (*x)[3];
Vdouble* orientationVectors;Vdouble* se;Vfloat* sef;
Vdouble* h;Vfloat* hf;Vint* ix;void* mutex;Vint avoidTransformation;
vis_Model* model;
#ifdef __cplusplus
public: VKI_EXTERN vis_State(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_State(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Pre(Vint);VKI_EXTERN void GetPre(Vint*);
VKI_EXTERN void SetObject(Vint,Vobject*);VKI_EXTERN
void GetObject(Vint,Vobject**);VKI_EXTERN void SetHashTable(Vint,
vsy_HashTable*);VKI_EXTERN void GetHashTable(Vint,vsy_HashTable**);
VKI_EXTERN void SetParami(Vint,Vint);VKI_EXTERN void
SetComplexMode(Vint);VKI_EXTERN void GetComplexMode(Vint*);
VKI_EXTERN void GetComplex(Vint*);VKI_EXTERN Vint Err(Vint,
Vint,Vint,Vint,Vint*);VKI_EXTERN void Def(Vint,Vint,
Vint,Vint);VKI_EXTERN void Inq(Vint*,Vint*,Vint*,Vint*)
const;VKI_EXTERN void Number(Vint*)const;VKI_EXTERN
void SetEngineeringStrain(Vint);VKI_EXTERN void GetEngineeringStrain(Vint*)
const;VKI_EXTERN void SetMagnitudePhase(Vint);VKI_EXTERN
void GetMagnitudePhase(Vint*)const;VKI_EXTERN void SetIntegerData(Vint);
VKI_EXTERN void GetIntegerData(Vint*)const;VKI_EXTERN
void SetScaledDirCos(Vint);VKI_EXTERN void GetScaledDirCos(Vint*);
VKI_EXTERN void Clear();VKI_EXTERN void DataStat(Vint,
Vint[],Vint[])const;VKI_EXTERN void DataStatElemEnt(Vint,
Vint,Vint*)const;VKI_EXTERN void DataStatNum(Vint*)
const;VKI_EXTERN void SetDataEnt(Vint,Vint,Vint[]);
VKI_EXTERN void DataEnt(Vint,Vint*,Vint[])const;VKI_EXTERN
void SetDataSect(Vint,Vint);VKI_EXTERN void DataSect(Vint,
Vint[],Vint[])const;VKI_EXTERN void CheckSect(Vint*)
const;VKI_EXTERN void SetDataLayPos(Vint,Vint);VKI_EXTERN
void DataLayPos(Vint,Vint[],Vint[])const;VKI_EXTERN
void SetDataLayers(Vint,Vint[],Vint[]);VKI_EXTERN void
DataLayers(Vint,Vint[],Vint[])const;VKI_EXTERN void
SetDataSectArray(Vint[],Vint[]);VKI_EXTERN void CheckLayers(Vint*);
VKI_EXTERN void ClearData(Vint);VKI_EXTERN void SetDataElemEnt(Vint,
Vint,Vfloat[]);VKI_EXTERN void SetDataElemEntdv(Vint,
Vint,Vdouble[]);VKI_EXTERN void SetData(Vint,Vfloat[]);
VKI_EXTERN void SetDataArray(Vint,Vint[],Vfloat[]);
VKI_EXTERN void SetDatadv(Vint,Vdouble[]);VKI_EXTERN
void SetDerive(Vint);VKI_EXTERN void GetDerive(Vint*)
const;VKI_EXTERN void NumDerive(Vint*)const;VKI_EXTERN
void TypeDerive(Vint*)const;VKI_EXTERN void SetSection(Vint);
VKI_EXTERN void GetSection(Vint*)const;VKI_EXTERN void
SetSystem(Vint);VKI_EXTERN void GetSystem(Vint*)const;
VKI_EXTERN void SetSystemType(Vint);VKI_EXTERN void
GetSystemType(Vint*)const;VKI_EXTERN void Transform(Vint,
vis_Group*);VKI_EXTERN void ConvertStrain(Vint);VKI_EXTERN
void ConvertComplex(Vint);VKI_EXTERN void Demo(Vint,
Vfloat,vis_Group*);VKI_EXTERN void Deform(Vfloat,vis_State*,
vis_Group*);VKI_EXTERN void Data(Vint,Vint[],Vfloat[])
const;VKI_EXTERN void DataElemNode(Vint,Vint,Vint[],
Vfloat[])const;VKI_EXTERN void DataElemNodedv(Vint,
Vint,Vint[],Vdouble[])const;VKI_EXTERN void DataElem(Vint,
Vfloat[])const;VKI_EXTERN void DataElemdv(Vint,Vdouble[])
const;VKI_EXTERN void DataElemEnt(Vint,Vint,Vint,Vfloat[])
const;VKI_EXTERN void DataElemEntdv(Vint,Vint,Vint,
Vdouble[])const;VKI_EXTERN void DataElemRST(Vint,Vfloat[],
Vfloat[]);VKI_EXTERN void DataElemRSTdv(Vint,Vdouble[],
Vdouble[]);VKI_EXTERN void Datadv(Vint,Vint[],Vdouble[])
const;VKI_EXTERN void DataArray(Vint,Vint,Vint[],Vfloat[])
const;VKI_EXTERN void DataArraydv(Vint,Vint,Vint[],
Vdouble[])const;VKI_EXTERN void DataNum(Vint,Vint*,
Vint*,Vint*)const;VKI_EXTERN void DataMax(Vint*,Vint*,
Vint*)const;VKI_EXTERN void DirCos(Vint,Vfloat[][3][3]);
VKI_EXTERN void Extent(vis_Group*,Vfloat[]);VKI_EXTERN
void ExtentLoc(vis_Group*,Vfloat[],Vint[],Vint[]);VKI_EXTERN
void ExtentLocSect(vis_Group*,Vfloat[],Vint[],Vint[],
Vint[]);VKI_EXTERN void Sum(vis_Group*,Vfloat[]);VKI_EXTERN
void Sumdv(vis_Group*,Vdouble[]);VKI_EXTERN void Map(vis_State*,
vis_Group*);VKI_EXTERN void Midside(vis_Group*);VKI_EXTERN
void MapElemNode(vis_State*,vis_Group*,vis_IdTran*);
VKI_EXTERN void OperateUnary(Vint,Vfloat,Vint,vis_State*,
vis_Group*);VKI_EXTERN void OperateUnarydv(Vint,Vdouble,
Vint,vis_State*,vis_Group*);VKI_EXTERN void OperateBinary(Vint,
Vfloat,Vint,vis_State*,vis_State*,vis_Group*);VKI_EXTERN
void OperateBinarydv(Vint,Vdouble,Vint,vis_State*,vis_State*,
vis_Group*);VKI_EXTERN void Derivative(Vint,Vfloat,
Vint,vis_State*,vis_Group*);VKI_EXTERN void ToFloat();
VKI_EXTERN void SetGroupParamfv(Vint,Vfloat[]);VKI_EXTERN
void SortIdTran(vis_Group*,vis_IdTran*);VKI_EXTERN void
ElemGroup(Vint,vis_Group*,vis_Group*);VKI_EXTERN void
NodeGroup(Vint,vis_Group*,vis_Group*);VKI_EXTERN void
Write(vis_RProp*,Vint,const Vchar*);VKI_EXTERN void
List(Vint,vis_Group*,Vchar*);VKI_EXTERN void Read(Vint,
const Vchar*);VKI_EXTERN void SaveFlag(Vint*);VKI_EXTERN
void Save();VKI_EXTERN void Restore();VKI_EXTERN void
Copy(vis_State*);VKI_EXTERN void Print();VKI_EXTERN
void EntitySystemId(Vint,Vint*)const;
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_State* vis_StateBegin(void);VKI_EXTERN
void vis_State_Construct(vis_State* p);VKI_EXTERN void
vis_StateEnd(vis_State* p);VKI_EXTERN void vis_State_Destruct(vis_State*
p);VKI_EXTERN Vint vis_StateError(vis_State* p);VKI_EXTERN
void vis_StatePre(vis_State* p,Vint pre);VKI_EXTERN
void vis_StateGetPre(vis_State* p,Vint* ipre);VKI_EXTERN
void vis_StateSetObject(vis_State* p,Vint objecttype,
Vobject* object);VKI_EXTERN void vis_StateGetObject(vis_State*
p,Vint objecttype,Vobject** object);VKI_EXTERN void
vis_StateSetHashTable(vis_State* p,Vint type,vsy_HashTable*
hashtable);VKI_EXTERN void vis_StateGetHashTable(vis_State*
p,Vint type,vsy_HashTable** hashtable);VKI_EXTERN void
vis_StateSetParami(vis_State* p,Vint ptype,Vint iparam);
VKI_EXTERN void vis_StateSetComplexMode(vis_State* p,
Vint complexmode);VKI_EXTERN void vis_StateGetComplexMode(vis_State*
p,Vint* complexmode);VKI_EXTERN void vis_StateGetComplex(vis_State*
p,Vint* complexmode);VKI_EXTERN Vint vis_StateErr(vis_State*
p,Vint nument,Vint enttype,Vint subtype,Vint datatype,
Vint* ierr);VKI_EXTERN void vis_StateDef(vis_State*
p,Vint nument,Vint parenttype,Vint childtype,Vint datatype);
VKI_EXTERN void vis_StateInq(const vis_State* p,Vint*
nument,Vint* enttype,Vint* subtype,Vint* datatype);
VKI_EXTERN void vis_StateNumber(const vis_State* p,
Vint* count);VKI_EXTERN void vis_StateSetEngineeringStrain(vis_State*
p,Vint flag);VKI_EXTERN void vis_StateGetEngineeringStrain(const
vis_State* p,Vint* flag);VKI_EXTERN void vis_StateSetMagnitudePhase(vis_State*
p,Vint flag);VKI_EXTERN void vis_StateGetMagnitudePhase(const
vis_State* p,Vint* flag);VKI_EXTERN void vis_StateSetIntegerData(vis_State*
p,Vint flag);VKI_EXTERN void vis_StateGetIntegerData(const
vis_State* p,Vint* flag);VKI_EXTERN void vis_StateSetScaledDirCos(vis_State*
p,Vint flag);VKI_EXTERN void vis_StateGetScaledDirCos(vis_State*
p,Vint* flag);VKI_EXTERN void vis_StateClear(vis_State*
p);VKI_EXTERN void vis_StateDataStat(const vis_State*
p,Vint nix,Vint ix[],Vint stat[]);VKI_EXTERN void vis_StateDataStatElemEnt(const
vis_State* p,Vint index,Vint no,Vint* stat);VKI_EXTERN
void vis_StateDataStatNum(const vis_State* p,Vint* numstat);
VKI_EXTERN void vis_StateSetDataEnt(vis_State* p,Vint
index,Vint numno,Vint no[]);VKI_EXTERN void vis_StateDataEnt(const
vis_State* p,Vint id,Vint* numno,Vint no[]);VKI_EXTERN
void vis_StateSetDataSect(vis_State* p,Vint index,Vint
nsec);VKI_EXTERN void vis_StateDataSect(const vis_State*
p,Vint nix,Vint ix[],Vint nsec[]);VKI_EXTERN void vis_StateCheckSect(const
vis_State* p,Vint* flag);VKI_EXTERN void vis_StateSetDataLayPos(vis_State*
p,Vint index,Vint lpos);VKI_EXTERN void vis_StateDataLayPos(const
vis_State* p,Vint nix,Vint ix[],Vint lpos[]);VKI_EXTERN
void vis_StateSetDataLayers(vis_State* p,Vint index,
Vint pos[],Vint lay[]);VKI_EXTERN void vis_StateDataLayers(const
vis_State* p,Vint index,Vint pos[],Vint lay[]);VKI_EXTERN
void vis_StateSetDataSectArray(vis_State* p,Vint psec[],
Vint play[]);VKI_EXTERN void vis_StateCheckLayers(vis_State*
p,Vint* flag);VKI_EXTERN void vis_StateClearData(vis_State*
p,Vint index);VKI_EXTERN void vis_StateSetDataElemEnt(vis_State*
p,Vint index,Vint no,Vfloat s[]);VKI_EXTERN void vis_StateSetDataElemEntdv(vis_State*
p,Vint id,Vint no,Vdouble s[]);VKI_EXTERN void vis_StateSetData(vis_State*
p,Vint index,Vfloat s[]);VKI_EXTERN void vis_StateSetDataArray(vis_State*
p,Vint nind,Vint ind[],Vfloat s[]);VKI_EXTERN void vis_StateSetDatadv(vis_State*
p,Vint id,Vdouble s[]);VKI_EXTERN void vis_StateSetDerive(vis_State*
p,Vint derive);VKI_EXTERN void vis_StateGetDerive(const
vis_State* p,Vint* derive);VKI_EXTERN void vis_StateNumDerive(const
vis_State* p,Vint* ncmp);VKI_EXTERN void vis_StateTypeDerive(const
vis_State* p,Vint* typederive);VKI_EXTERN void vis_StateSetSection(vis_State*
p,Vint section);VKI_EXTERN void vis_StateGetSection(const
vis_State* p,Vint* section);VKI_EXTERN void vis_StateSetSystem(vis_State*
p,Vint system);VKI_EXTERN void vis_StateGetSystem(const
vis_State* p,Vint* system);VKI_EXTERN void vis_StateSetSystemType(vis_State*
p,Vint systemtype);VKI_EXTERN void vis_StateGetSystemType(const
vis_State* p,Vint* systemtype);VKI_EXTERN void vis_StateEntitySystemId(const
vis_State* p,Vint index,Vint* csysid);VKI_EXTERN void
vis_StateTransform(vis_State* p,Vint system,vis_Group*
group);VKI_EXTERN void vis_StateConvertStrain(vis_State*
p,Vint straintype);VKI_EXTERN void vis_StateConvertComplex(vis_State*
p,Vint complextype);VKI_EXTERN void vis_StateDemo(vis_State*
p,Vint oper,Vfloat f,vis_Group* group);VKI_EXTERN void
vis_StateDeform(vis_State* p,Vfloat f,vis_State* stated,
vis_Group* group);VKI_EXTERN void vis_StateData(const
vis_State* p,Vint nix,Vint ix[],Vfloat s[]);VKI_EXTERN
void vis_StateDataElemNode(const vis_State* p,Vint id,
Vint nix,Vint ix[],Vfloat s[]);VKI_EXTERN void vis_StateDataElemNodedv(const
vis_State* p,Vint id,Vint nix,Vint ix[],Vdouble s[]);
VKI_EXTERN void vis_StateDataElem(const vis_State* p,
Vint index,Vfloat s[]);VKI_EXTERN void vis_StateDataElemdv(const
vis_State* p,Vint id,Vdouble s[]);VKI_EXTERN void vis_StateDataElemEnt(const
vis_State* p,Vint type,Vint index,Vint no,Vfloat s[]);
VKI_EXTERN void vis_StateDataElemEntdv(const vis_State*
p,Vint type,Vint id,Vint no,Vdouble s[]);VKI_EXTERN
void vis_StateDataElemRST(vis_State* p,Vint index,Vfloat
r[],Vfloat s[]);VKI_EXTERN void vis_StateDataElemRSTdv(vis_State*
p,Vint id,Vdouble r[],Vdouble s[]);VKI_EXTERN void vis_StateDatadv(const
vis_State* p,Vint nids,Vint ids[],Vdouble s[]);VKI_EXTERN
void vis_StateDataArray(const vis_State* p,Vint mode,
Vint nids,Vint ids[],Vfloat s[]);VKI_EXTERN void vis_StateDataArraydv(const
vis_State* p,Vint mode,Vint nids,Vint ids[],Vdouble
s[]);VKI_EXTERN void vis_StateDataNum(const vis_State*
p,Vint index,Vint* ndat,Vint* nloc,Vint* nsec);VKI_EXTERN
void vis_StateDataMax(const vis_State* p,Vint* maxdat,
Vint* maxloc,Vint* maxsec);VKI_EXTERN void vis_StateDirCos(vis_State*
p,Vint index,Vfloat tm[][3][3]);VKI_EXTERN void vis_StateExtent(vis_State*
p,vis_Group* group,Vfloat extent[]);VKI_EXTERN void
vis_StateExtentLoc(vis_State* p,vis_Group* group,Vfloat
extent[],Vint ix[],Vint no[]);VKI_EXTERN void vis_StateExtentLocSect(vis_State*
p,vis_Group* group,Vfloat extent[],Vint ix[],Vint no[],
Vint sc[]);VKI_EXTERN void vis_StateSum(vis_State* p,
vis_Group* group,Vfloat s[]);VKI_EXTERN void vis_StateSumdv(vis_State*
p,vis_Group* group,Vdouble sum[]);VKI_EXTERN void vis_StateMap(vis_State*
p,vis_State* statesrc,vis_Group* group);VKI_EXTERN void
vis_StateMidside(vis_State* p,vis_Group* group);VKI_EXTERN
void vis_StateMapElemNode(vis_State* p,vis_State* statesrc,
vis_Group* group,vis_IdTran* idtran);VKI_EXTERN void
vis_StateOperateUnary(vis_State* p,Vint oper,Vfloat
f,Vint func,vis_State* statex,vis_Group* group);VKI_EXTERN
void vis_StateOperateUnarydv(vis_State* p,Vint oper,
Vdouble f,Vint funct,vis_State* statex,vis_Group* group);
VKI_EXTERN void vis_StateOperateBinary(vis_State* p,
Vint oper,Vfloat f,Vint func,vis_State* statex,vis_State*
statey,vis_Group* group);VKI_EXTERN void vis_StateOperateBinarydv(vis_State*
p,Vint oper,Vdouble f,Vint funct,vis_State* statex,
vis_State* statey,vis_Group* group);VKI_EXTERN void
vis_StateDerivative(vis_State* p,Vint oper,Vfloat f,
Vint func,vis_State* statex,vis_Group* group);VKI_EXTERN
void vis_StateToFloat(vis_State* p);VKI_EXTERN void
vis_StateSetGroupParamfv(vis_State* p,Vint ptype,Vfloat
vparam[]);VKI_EXTERN void vis_StateSortIdTran(vis_State*
p,vis_Group* group,vis_IdTran* idtran);VKI_EXTERN void
vis_StateElemGroup(vis_State* p,Vint oper,vis_Group*
group,vis_Group* groupdst);VKI_EXTERN void vis_StateNodeGroup(vis_State*
p,Vint oper,vis_Group* group,vis_Group* groupdst);VKI_EXTERN
void vis_StateWrite(vis_State* p,vis_RProp* rprop,Vint
type,const Vchar* path);VKI_EXTERN void vis_StateList(vis_State*
p,Vint type,vis_Group* group,Vchar* path);VKI_EXTERN
void vis_StateRead(vis_State* p,Vint type,const Vchar*
path);VKI_EXTERN void vis_StateSaveFlag(vis_State* p,
Vint* saveflag);VKI_EXTERN void vis_StateSave(vis_State*
p);VKI_EXTERN void vis_StateRestore(vis_State* p);VKI_EXTERN
void vis_StateCopy(vis_State* p,vis_State* fromp);VKI_EXTERN
void vis_StatePrint(vis_State* p);
#ifdef __cplusplus
}
#endif
#endif

