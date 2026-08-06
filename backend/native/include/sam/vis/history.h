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
 
#ifndef HISTORY_DEF
#define HISTORY_DEF
#include "sam/base/base.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/gridfun.h"
#include "sam/vis/group.h"
#define HISTORY_ELEMNODE 0
#define HISTORY_NODE 1
#define HISTORY_ELEM 4
#define HISTORY_LISTWIDTH 1
#define HISTORY_LISTTRANSPOSE 2
#define HISTORY_GLOBAL 0
#define HISTORY_LOCAL 1
#define HISTORY_LOWPASS 0
#define HISTORY_TEXT_SUMMARY -5
#define HISTORY_TEXT_LISTING -6
struct vis_History { Vint ierr;Vint ipre;Vint numstp;
Vint maxstp;Vint nument;Vint enttype;Vint subtype;Vint
datatype;Vint engstr;Vint complexmode;Vint complexflag;
vis_GridFun* gf;vis_IdTran* idtrancsys;vsy_HashTable*
hashcsys;vsy_HashTable* csh;vsy_HashTable* edh;vis_State*
statedc;vis_State* statera;vis_RProp* rprop;Vint listwidth;
Vint listtrans;Vint curstp;Vint curent;vis_IdTran* idtranind;
vsy_IntHash* inthashind;Vint maxsizeind;Vint* sizeind;
Vint* sectind;Vint* lposind;vsy_CVect* cvl;Vint maxly;
Vint* ly;Vint maxdataloc;Vint maxdatasize;Vint maxdatasec;
vsy_List* listind;vsy_List* listist;vsy_IntHash* inthashstp;
vsy_IntVec* intvecstp;vsy_FltVec* tstps;vsy_DblVec*
tstpd;Vint zeroistep;Vchar* indepname;vsy_IntVec* rank;
Vint nrows;Vint derive;Vint nrowsderive;Vint section;
Vint system;Vfloat extent[2];
#ifdef __cplusplus
public: VKI_EXTERN vis_History(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_History(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Pre(Vint);VKI_EXTERN void GetPre(Vint*);
VKI_EXTERN void SetObject(Vint,Vobject*);VKI_EXTERN
void GetObject(Vint,Vobject**);VKI_EXTERN void SetHashTable(Vint,
vsy_HashTable*);VKI_EXTERN void SetParami(Vint,Vint);
VKI_EXTERN void Def(Vint,Vint,Vint,Vint,Vint);VKI_EXTERN
void Inq(Vint*,Vint*,Vint*,Vint*,Vint*)const;VKI_EXTERN
void SetComplexMode(Vint);VKI_EXTERN void GetComplexMode(Vint*);
VKI_EXTERN void GetComplex(Vint*);VKI_EXTERN void SetEngineeringStrain(Vint);
VKI_EXTERN void GetEngineeringStrain(Vint*);VKI_EXTERN
void Clear();VKI_EXTERN void SetDataSect(Vint,Vint);
VKI_EXTERN void DataSect(Vint,Vint[],Vint[]);VKI_EXTERN
void SetDataLayPos(Vint,Vint);VKI_EXTERN void DataLayPos(Vint,
Vint*);VKI_EXTERN void SetDataLayers(Vint,Vint[],Vint[]);
VKI_EXTERN void DataLayers(Vint,Vint[],Vint[]);VKI_EXTERN
void SetData(Vint,Vint,Vfloat[]);VKI_EXTERN void SetDatadv(Vint,
Vint,Vdouble[]);VKI_EXTERN void SetDataStat(Vint,Vint[]);
VKI_EXTERN void SetIndep(Vint,Vfloat);VKI_EXTERN void
SetIndepdv(Vint,Vdouble);VKI_EXTERN void Indep(Vint,
Vfloat*);VKI_EXTERN void Indepdv(Vint,Vdouble*);VKI_EXTERN
void SetIndepName(Vchar*);VKI_EXTERN void GetIndepName(Vchar[]);
VKI_EXTERN void Data(Vint,Vint,Vint[],Vfloat[]);VKI_EXTERN
void Datadv(Vint,Vint,Vint[],Vdouble[]);VKI_EXTERN void
DataNum(Vint,Vint*,Vint*,Vint*);VKI_EXTERN void DataMax(Vint*,
Vint*,Vint*);VKI_EXTERN void DataStat(Vint,Vint[]);
VKI_EXTERN void DataSteps(Vint,Vint[],Vfloat[]);VKI_EXTERN
void DataStepsdv(Vint,Vint[],Vdouble[]);VKI_EXTERN void
SetDerive(Vint);VKI_EXTERN void GetDerive(Vint*)const;
VKI_EXTERN void NumDerive(Vint*)const;VKI_EXTERN void
SetSection(Vint);VKI_EXTERN void GetSection(Vint*)const;
VKI_EXTERN void SetSystem(Vint);VKI_EXTERN void GetSystem(Vint*)
const;VKI_EXTERN void NumIndices(Vint*)const;VKI_EXTERN
void GetIndex(Vint,Vint*);VKI_EXTERN void Indices(Vint*,
Vint[])const;VKI_EXTERN void NumSteps(Vint*)const;VKI_EXTERN
void GetStep(Vint,Vint*);VKI_EXTERN void Steps(Vint*,
Vint[])const;VKI_EXTERN void IndepSteps(Vfloat[])const;
VKI_EXTERN void IndepStepsdv(Vdouble[])const;VKI_EXTERN
void Extent(Vfloat[]);VKI_EXTERN void Filter(Vint);
VKI_EXTERN void GetRank(Vint,Vint*);VKI_EXTERN void
CutoffRank(Vint,Vint,Vint,Vint*);VKI_EXTERN void Sample();
VKI_EXTERN void List(Vint,vis_Group*,Vchar*);VKI_EXTERN
void Copy(vis_History*);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_History* vis_HistoryBegin(void);VKI_EXTERN
void vis_History_Construct(vis_History* p);VKI_EXTERN
void vis_HistoryEnd(vis_History* p);VKI_EXTERN void
vis_History_Destruct(vis_History* p);VKI_EXTERN Vint
vis_HistoryError(vis_History* p);VKI_EXTERN void vis_HistoryPre(vis_History*
p,Vint ipre);VKI_EXTERN void vis_HistoryGetPre(vis_History*
p,Vint* ipre);VKI_EXTERN void vis_HistorySetObject(vis_History*
p,Vint objecttype,Vobject* object);VKI_EXTERN void vis_HistoryGetObject(vis_History*
p,Vint objecttype,Vobject** object);VKI_EXTERN void
vis_HistorySetHashTable(vis_History* p,Vint type,vsy_HashTable*
hashtable);VKI_EXTERN void vis_HistorySetParami(vis_History*
p,Vint type,Vint iparam);VKI_EXTERN void vis_HistoryDef(vis_History*
p,Vint numstp,Vint nument,Vint enttype,Vint subtype,
Vint datatype);VKI_EXTERN void vis_HistoryInq(const
vis_History* p,Vint* numstp,Vint* nument,Vint* enttype,
Vint* subtype,Vint* datatype);VKI_EXTERN void vis_HistorySetComplexMode(vis_History*
p,Vint complexmode);VKI_EXTERN void vis_HistoryGetComplexMode(vis_History*
p,Vint* complexmode);VKI_EXTERN void vis_HistoryGetComplex(vis_History*
p,Vint* complexflag);VKI_EXTERN void vis_HistorySetEngineeringStrain(vis_History*
p,Vint flag);VKI_EXTERN void vis_HistoryGetEngineeringStrain(vis_History*
p,Vint* flag);VKI_EXTERN void vis_HistoryClear(vis_History*
p);VKI_EXTERN void vis_HistorySetDataSect(vis_History*
p,Vint id,Vint nsecs);VKI_EXTERN void vis_HistoryDataSect(vis_History*
p,Vint nids,Vint ids[],Vint nsec[]);VKI_EXTERN void
vis_HistorySetDataLayPos(vis_History* p,Vint id,Vint
laypos);VKI_EXTERN void vis_HistoryDataLayPos(vis_History*
p,Vint id,Vint* laypos);VKI_EXTERN void vis_HistorySetDataLayers(vis_History*
p,Vint id,Vint pos[],Vint lay[]);VKI_EXTERN void vis_HistoryDataLayers(vis_History*
p,Vint id,Vint pos[],Vint lay[]);VKI_EXTERN void vis_HistorySetData(vis_History*
p,Vint istep,Vint id,Vfloat s[]);VKI_EXTERN void vis_HistorySetDatadv(vis_History*
p,Vint istep,Vint id,Vdouble s[]);VKI_EXTERN void vis_HistorySetDataStat(vis_History*
p,Vint id,Vint stat[]);VKI_EXTERN void vis_HistorySetIndep(vis_History*
p,Vint istep,Vfloat t);VKI_EXTERN void vis_HistorySetIndepdv(vis_History*
p,Vint istep,Vdouble t);VKI_EXTERN void vis_HistoryIndep(vis_History*
p,Vint istep,Vfloat* t);VKI_EXTERN void vis_HistoryIndepdv(vis_History*
p,Vint istep,Vdouble* t);VKI_EXTERN void vis_HistorySetIndepName(vis_History*
p,Vchar* name);VKI_EXTERN void vis_HistoryGetIndepName(vis_History*
p,Vchar name[]);VKI_EXTERN void vis_HistoryData(vis_History*
p,Vint istep,Vint nids,Vint ids[],Vfloat s[]);VKI_EXTERN
void vis_HistoryDatadv(vis_History* p,Vint istep,Vint
nids,Vint ids[],Vdouble s[]);VKI_EXTERN void vis_HistoryDataNum(vis_History*
p,Vint id,Vint* ndat,Vint* nloc,Vint* nsec);VKI_EXTERN
void vis_HistoryDataMax(vis_History* p,Vint* mdat,Vint*
mloc,Vint* msec);VKI_EXTERN void vis_HistoryDataStat(vis_History*
p,Vint id,Vint stat[]);VKI_EXTERN void vis_HistoryDataSteps(vis_History*
p,Vint nids,Vint ids[],Vfloat s[]);VKI_EXTERN void vis_HistoryDataStepsdv(vis_History*
p,Vint nids,Vint ids[],Vdouble s[]);VKI_EXTERN void
vis_HistorySetDerive(vis_History* p,Vint derive);VKI_EXTERN
void vis_HistoryGetDerive(const vis_History* p,Vint*
derive);VKI_EXTERN void vis_HistoryNumDerive(const vis_History*
p,Vint* numder);VKI_EXTERN void vis_HistorySetSection(vis_History*
p,Vint section);VKI_EXTERN void vis_HistoryGetSection(const
vis_History* p,Vint* section);VKI_EXTERN void vis_HistorySetSystem(vis_History*
p,Vint system);VKI_EXTERN void vis_HistoryGetSystem(const
vis_History* p,Vint* system);VKI_EXTERN void vis_HistoryNumIndices(const
vis_History* p,Vint* nument);VKI_EXTERN void vis_HistoryGetIndex(vis_History*
p,Vint in,Vint* index);VKI_EXTERN void vis_HistoryIndices(const
vis_History* p,Vint* nument,Vint ids[]);VKI_EXTERN void
vis_HistoryNumSteps(const vis_History* p,Vint* numstp);
VKI_EXTERN void vis_HistoryGetStep(vis_History* p,Vint
is,Vint* istep);VKI_EXTERN void vis_HistorySteps(const
vis_History* p,Vint* numstp,Vint isteps[]);VKI_EXTERN
void vis_HistoryIndepSteps(const vis_History* p,Vfloat
t[]);VKI_EXTERN void vis_HistoryIndepStepsdv(const vis_History*
p,Vdouble t[]);VKI_EXTERN void vis_HistoryExtent(vis_History*
p,Vfloat extent[]);VKI_EXTERN void vis_HistoryFilter(vis_History*
p,Vint filter);VKI_EXTERN void vis_HistoryGetRank(vis_History*
p,Vint istep,Vint* rank);VKI_EXTERN void vis_HistoryCutoffRank(vis_History*
p,Vint istep1,Vint istep2,Vint num,Vint* cutoffrank);
VKI_EXTERN void vis_HistorySample(vis_History* p);VKI_EXTERN
void vis_HistoryList(vis_History* p,Vint type,vis_Group*
group,Vchar* path);VKI_EXTERN void vis_HistoryCopy(vis_History*
p,vis_History* fromp);VKI_EXTERN void vis_HistoryPrint(vis_History*
p);
#ifdef __cplusplus
}
#endif
#endif

