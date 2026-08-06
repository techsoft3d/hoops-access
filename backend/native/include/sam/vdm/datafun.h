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
 
#ifndef DATAFUN_DEF
#define DATAFUN_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/options.h"
typedef void(VDataFunSetMode)(Vobject*,Vint,Vint);typedef
void(VDataFunSetConvention)(Vobject*,VConventionType);
typedef void(VDataFunOpen)(Vobject*,Vint,const Vchar*,
Vint);typedef void(VDataFunClose)(Vobject*);typedef
void(VDataFunDefDataset)(Vobject*,const Vchar*,Vlong,
Vint,Vint,Vint,Vint*);typedef void(VDataFunGetNumEntities)(Vobject*,
Vint,Vint*);typedef void(VDataFunGetLibrary)(Vobject*,
vdm_Library**);typedef void(VDataFunWriteDataset)(Vobject*,
Vint,void*);typedef void(VDataFunReadDataset)(Vobject*,
Vint,void*);typedef void(VDataFunUpdate)(Vobject*);
typedef void(VDataFunSetStatus)(Vobject*,Vint);typedef
void(VDataFunIncDataset)(Vobject*,Vchar*);typedef void(VDataFunAppend)(Vobject*,
const Vchar*,Vint);typedef Vint(VDataFunError)(Vobject*);
typedef void(VDataFunWriteModel)(Vobject*,vis_Model*);
typedef void(VDataFunWriteState)(Vobject*,vis_RProp*,
vis_State*);typedef void(VDataFunSetIds)(Vobject*,Vint,
Vint,Vint,Vint);typedef void(VDataFunSetConnect)(Vobject*,
vis_Connect*);typedef void(VDataFunGetConnect)(Vobject*,
vis_Connect**);typedef void(VDataFunLibDataset)(Vobject*,
Vint,Vint);typedef void(VDataFunDefAttribute)(Vobject*,
Vint,const Vchar*,Vint,Vint,Vint*);typedef void(VDataFunSetAttVal)(Vobject*,
Vint,Vint,void*);typedef void(VDataFunGetAttVal)(Vobject*,
Vint,Vint,void*);typedef void(VDataFunNumDatasets)(Vobject*,
Vint*);typedef void(VDataFunNumAttributes)(Vobject*,
Vint,Vint*);typedef void(VDataFunInqDataset)(Vobject*,
Vint,const Vchar*,Vlong*,Vint*,Vint*,Vint*);typedef
void(VDataFunInqAttribute)(Vobject*,Vint,Vint,const
Vchar*,Vint*,Vint*);typedef void(VDataFunGetInteger)(Vobject*,
Vint,Vint*);typedef void(VDataFunGetString)(Vobject*,
Vint,Vchar*);typedef void(VDataFunNumDomains)(Vobject*,
Vchar*,Vint,Vint*);typedef void(VDataFunPushContainer)(Vobject*,
Vchar*);typedef void(VDataFunPopContainer)(Vobject*);
typedef void(VDataFunReadDatasetCols)(Vobject*,Vint,
Vint,Vint*,void*,Vlong*);typedef void(VDataFunSetThreadsCount)(Vobject*,
Vint);typedef void(VDataFunSetString)(Vobject*,Vint,
Vchar*);typedef void(VDataFunGetUnrecognizedData)(Vobject*,
vdm_UnrecognizedData**);typedef void(VDataFunApplySettings)(Vobject*,
vdm_Settings*);
#define DATAFUN_SETMODE 1
#define DATAFUN_SETCONVENTION 2
#define DATAFUN_OPEN 3
#define DATAFUN_CLOSE 4
#define DATAFUN_DEFDATASET 5
#define DATAFUN_GETNUMENTITIES 6
#define DATAFUN_GETLIBRARY 7
#define DATAFUN_WRITEDATASET 8
#define DATAFUN_READDATASET 9
#define DATAFUN_UPDATE 10
#define DATAFUN_SETSTATUS 11
#define DATAFUN_INCDATASET 12
#define DATAFUN_APPEND 13
#define DATAFUN_ERROR 14
#define DATAFUN_WRITEMODEL 15
#define DATAFUN_WRITESTATE 16
#define DATAFUN_SETIDS 17
#define DATAFUN_SETCONNECT 18
#define DATAFUN_GETCONNECT 19
#define DATAFUN_LIBDATASET 20
#define DATAFUN_DEFATTRIBUTE 21
#define DATAFUN_SETATTVAL 22
#define DATAFUN_GETATTVAL 23
#define DATAFUN_NUMDATASETS 24
#define DATAFUN_NUMATTRIBUTES 25
#define DATAFUN_INQDATASET 26
#define DATAFUN_INQATTRIBUTE 27
#define DATAFUN_GETINTEGER 28
#define DATAFUN_GETSTRING 29
#define DATAFUN_NUMDOMAINS 30
#define DATAFUN_PUSHCONTAINER 31
#define DATAFUN_POPCONTAINER 32
#define DATAFUN_READDATASETCOLS 33
#define DATAFUN_SETTHREADSCOUNT 34
#define DATAFUN_SETSTRING 35
#define DATAFUN_GETUNRECOGNIZEDDATA 36
#define DATAFUN_APPLYLIBSETTINGS 37
 
#define DATAFUN_MAX 38
struct vdm_DataFun { Vint ierr;Vobject* obj;void (*fun[1])(void);
void (*setmode)(Vobject*,Vint,Vint);void (*setconvention)(Vobject*,
VConventionType);void (*open)(Vobject*,Vint,const Vchar*,
Vint);void (*close)(Vobject*);void (*defdataset)(Vobject*,
const Vchar*,Vlong,Vint,Vint,Vint,Vint*);void (*getnumentities)(Vobject*,
Vint,Vint*);void (*getlibrary)(Vobject*,vdm_Library**);
void (*writedataset)(Vobject*,Vint,void*);void (*readdataset)(Vobject*,
Vint,void*);void (*update)(Vobject*);void (*setstatus)(Vobject*,
Vint);void (*incdataset)(Vobject*,Vchar*);void (*append)(Vobject*,
const Vchar*,Vint);Vint (*error)(Vobject*);void (*writemodel)(Vobject*,
vis_Model*);void (*writestate)(Vobject*,vis_RProp*,
vis_State*);void (*setids)(Vobject*,Vint,Vint,Vint,
Vint);void (*setconnect)(Vobject*,vis_Connect*);void
(*getconnect)(Vobject*,vis_Connect**);void (*libdataset)(Vobject*,
Vint,Vint);void (*defattribute)(Vobject*,Vint,const
Vchar*,Vint,Vint,Vint*);void (*setattval)(Vobject*,
Vint,Vint,void*);void (*getattval)(Vobject*,Vint,Vint,
void*);void (*numdatasets)(Vobject*,Vint*);void (*numattributes)(Vobject*,
Vint,Vint*);void (*inqdataset)(Vobject*,Vint,const Vchar*,
Vlong*,Vint*,Vint*,Vint*);void (*inqattribute)(Vobject*,
Vint,Vint,const Vchar*,Vint*,Vint*);void (*getinteger)(Vobject*,
Vint,Vint*);void (*getstring)(Vobject*,Vint,Vchar*);
void (*numdomains)(Vobject*,Vchar*,Vint,Vint*);void
(*pushcontainer)(Vobject*,Vchar*);void (*popcontainer)(Vobject*);
void (*readdatasetcols)(Vobject*,Vint,Vint,Vint*,void*,
Vlong*);void (*setthreadscount)(Vobject*,Vint);void
(*setstring)(Vobject*,Vint,Vchar*);void (*getunrecognizeddata)(Vobject*,
vdm_UnrecognizedData**);void (*applysettings)(Vobject*,
vdm_Settings*);
#ifdef __cplusplus
public: VKI_EXTERN vdm_DataFun(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_DataFun(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Init();VKI_EXTERN void Set(Vint,
Vfunc*);VKI_EXTERN void SetErrorFunction(VfuncInt*);
VKI_EXTERN void Get(Vint,Vfunc**);VKI_EXTERN void SetObj(Vobject*);
VKI_EXTERN void GetObj(Vobject**);VKI_EXTERN void Copy(vdm_DataFun*);
VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void OpenFile(const
Vchar*,vdm_Options*);VKI_EXTERN void Open(Vint,const
Vchar*,Vint);VKI_EXTERN void CloseFile();VKI_EXTERN
void Close();VKI_EXTERN void GetNumEntities(Vint,Vint*);
VKI_EXTERN void GetLibrary(vdm_Library**);VKI_EXTERN
void DefDataset(const Vchar*,Vlong,Vint,Vint,Vint,Vint*);
VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN void
WriteDataset(Vint,void*);VKI_EXTERN void Update();VKI_EXTERN
void Append(Vchar*,Vint);VKI_EXTERN void AppendFile(Vchar*
path);VKI_EXTERN void WriteModel(vis_Model*);VKI_EXTERN
void WriteState(vis_RProp*,vis_State*);VKI_EXTERN void
SetIds(Vint,Vint,Vint,Vint);VKI_EXTERN void SetConnect(vis_Connect*);
VKI_EXTERN void GetConnect(vis_Connect**);VKI_EXTERN
void LibDataset(Vint,Vint);VKI_EXTERN void DefAttribute(Vint,
const Vchar*,Vint,Vint,Vint*);VKI_EXTERN void SetAttVal(Vint,
Vint,void*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);
VKI_EXTERN void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void InqDataset(Vint,const Vchar*,
Vlong*,Vint*,Vint*,Vint*);VKI_EXTERN void InqAttribute(Vint,
Vint,const Vchar*,Vint*,Vint*);VKI_EXTERN void GetInteger(Vint,
Vint*);VKI_EXTERN void GetString(Vint,Vchar*);VKI_EXTERN
void NumDomains(Vchar*,Vint,Vint*);VKI_EXTERN void PushContainer(Vchar*);
VKI_EXTERN void PopContainer();VKI_EXTERN void ReadDatasetCols(Vint,
Vint,Vint[],void*,Vlong*);VKI_EXTERN void SetSetModeFun(VDataFunSetMode*);
VKI_EXTERN void SetSetConventionFun(VDataFunSetConvention*);
VKI_EXTERN void SetOpenFun(VDataFunOpen*);VKI_EXTERN
void SetCloseFun(VDataFunClose*);VKI_EXTERN void SetDefDatasetFun(VDataFunDefDataset*);
VKI_EXTERN void SetGetNumEntitiesFun(VDataFunGetNumEntities*);
VKI_EXTERN void SetGetLibraryFun(VDataFunGetLibrary*);
VKI_EXTERN void SetWriteDatasetFun(VDataFunWriteDataset*);
VKI_EXTERN void SetReadDatasetFun(VDataFunReadDataset*);
VKI_EXTERN void SetUpdateFun(VDataFunUpdate*);VKI_EXTERN
void SetSetStatusFun(VDataFunSetStatus*);VKI_EXTERN
void SetIncDatasetFun(VDataFunIncDataset*);VKI_EXTERN
void SetAppendFun(VDataFunAppend*);VKI_EXTERN void SetErrorFun(VDataFunError*);
VKI_EXTERN void SetWriteModelFun(VDataFunWriteModel*);
VKI_EXTERN void SetWriteStateFun(VDataFunWriteState*);
VKI_EXTERN void SetSetIdsFun(VDataFunSetIds*);VKI_EXTERN
void SetSetConnectFun(VDataFunSetConnect*);VKI_EXTERN
void SetGetConnectFun(VDataFunGetConnect*);VKI_EXTERN
void SetLibDatasetFun(VDataFunLibDataset*);VKI_EXTERN
void SetDefAttribute(VDataFunDefAttribute*);VKI_EXTERN
void SetGetIntegerFun(VDataFunGetInteger*);VKI_EXTERN
void SetGetStringFun(VDataFunGetString*);VKI_EXTERN
void SetNumDomainsFun(VDataFunNumDomains*);VKI_EXTERN
void SetPushContainerFun(VDataFunPushContainer*);VKI_EXTERN
void SetPopContainerFun(VDataFunPopContainer*);VKI_EXTERN
void SetReadDatasetColrFun(VDataFunReadDatasetCols*);
VKI_EXTERN void SetSetThreadsCount(VDataFunSetThreadsCount*);
VKI_EXTERN void SetString(Vint,Vchar*);VKI_EXTERN void
SetSetStringFun(VDataFunSetString*);VKI_EXTERN void
SetGetUnrecognizedDataFun(VDataFunGetUnrecognizedData*);
VKI_EXTERN void ApplySettingsFun(VDataFunApplySettings*);
VKI_EXTERN void GetNumDatasets(Vint* numdataset);VKI_EXTERN
void GetDataset(Vint idst,vdm_Dataset** dataset);VKI_EXTERN
void SearchDataset(const Vchar* name,Vint max,Vint idsts[],
Vint* num);VKI_EXTERN void AppendFile(const Vchar* path);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_DataFun* vdm_DataFunBegin(void);VKI_EXTERN
void vdm_DataFun_Construct(vdm_DataFun* p);VKI_EXTERN
void vdm_DataFunEnd(vdm_DataFun* p);VKI_EXTERN void
vdm_DataFun_Destruct(vdm_DataFun* p);VKI_EXTERN Vint
vdm_DataFunError(vdm_DataFun* p);VKI_EXTERN void vdm_DataFunInit(vdm_DataFun*
p);VKI_EXTERN void vdm_DataFunSet(vdm_DataFun* p,Vint
type,Vfunc* function);VKI_EXTERN void vdm_DataFunSetErrorFunction(vdm_DataFun*
p,VfuncInt* function);VKI_EXTERN void vdm_DataFunGet(vdm_DataFun*
p,Vint type,Vfunc** function);VKI_EXTERN void vdm_DataFunSetObj(vdm_DataFun*
p,Vobject* obj);VKI_EXTERN void vdm_DataFunGetObj(vdm_DataFun*
p,Vobject** obj);VKI_EXTERN void vdm_DataFunCopy(vdm_DataFun*
p,vdm_DataFun* fromp);VKI_EXTERN void vdm_DataFunSetMode(vdm_DataFun*
p,Vint mode,Vint param);VKI_EXTERN void vdm_DataFunSetConvention(vdm_DataFun*
p,VConventionType convention);VKI_EXTERN void vdm_DataFunSetStatus(vdm_DataFun*
p,Vint status);VKI_EXTERN void vdm_DataFunOpenFile(vdm_DataFun*
p,const Vchar* file,vdm_Options* options);VKI_EXTERN
void vdm_DataFunOpen(vdm_DataFun* p,Vint mode,const
Vchar* path,Vint type);VKI_EXTERN void vdm_DataFunClose(vdm_DataFun*
p);VKI_EXTERN void vdm_DataFunCloseFile(vdm_DataFun*
p);VKI_EXTERN void vdm_DataFunGetNumEntities(vdm_DataFun*
p,Vint entitytype,Vint* numentities);VKI_EXTERN void
vdm_DataFunGetLibrary(vdm_DataFun* p,vdm_Library** library);
VKI_EXTERN void vdm_DataFunDefDataset(vdm_DataFun* p,
const Vchar* name,Vlong lrec,Vint nrow,Vint ncol,Vint
type,Vint* idst);VKI_EXTERN void vdm_DataFunReadDataset(vdm_DataFun*
p,Vint idst,void* buff);VKI_EXTERN void vdm_DataFunWriteDataset(vdm_DataFun*
p,Vint idst,void* buff);VKI_EXTERN void vdm_DataFunUpdate(vdm_DataFun*
p);VKI_EXTERN void vdm_DataFunAppend(vdm_DataFun* p,
Vchar* path,Vint type);VKI_EXTERN void vdm_DataFunAppendFile(vdm_DataFun*
p,const Vchar* path);VKI_EXTERN void vdm_DataFunWriteModel(vdm_DataFun*
p,vis_Model* model);VKI_EXTERN void vdm_DataFunWriteState(vdm_DataFun*
p,vis_RProp* rprop,vis_State* state);VKI_EXTERN void
vdm_DataFunSetIds(vdm_DataFun* p,Vint idtype,Vint id1,
Vint id2,Vint id3);VKI_EXTERN void vdm_DataFunSetConnect(vdm_DataFun*
p,vis_Connect* connect);VKI_EXTERN void vdm_DataFunGetConnect(vdm_DataFun*
p,vis_Connect** connect);VKI_EXTERN void vdm_DataFunLibDataset(vdm_DataFun*
p,Vint iop,Vint idst);VKI_EXTERN void vdm_DataFunDefAttribute(vdm_DataFun*
p,Vint idst,const Vchar* name,Vint length,Vint type,
Vint* iatt);VKI_EXTERN void vdm_DataFunSetAttVal(vdm_DataFun*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_DataFunGetAttVal(vdm_DataFun*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_DataFunNumDatasets(vdm_DataFun*
p,Vint* numdats);VKI_EXTERN void vdm_DataFunNumAttributes(vdm_DataFun*
p,Vint idst,Vint* numatts);VKI_EXTERN void vdm_DataFunInqDataset(vdm_DataFun*
p,Vint idst,const Vchar* name,Vlong* lrec,Vint* nrow,
Vint* ncol,Vint* type);VKI_EXTERN void vdm_DataFunInqAttribute(vdm_DataFun*
p,Vint idst,Vint iatt,const Vchar* name,Vint* length,
Vint* type);VKI_EXTERN void vdm_DataFunGetInteger(vdm_DataFun*
p,Vint type,Vint* iparam);VKI_EXTERN void vdm_DataFunGetString(vdm_DataFun*
p,Vint type,Vchar* cparam);VKI_EXTERN void vdm_DataFunNumDomains(vdm_DataFun*
p,Vchar* path,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_DataFunPushContainer(vdm_DataFun* p,Vchar*
path);VKI_EXTERN void vdm_DataFunPopContainer(vdm_DataFun*
p);VKI_EXTERN void vdm_DataFunReadDatasetCols(vdm_DataFun*
p,Vint idst,Vint ncols,Vint cols[],void* buff,Vlong*
lptr);VKI_EXTERN void vdm_DataFunSetString(vdm_DataFun*
p,Vint type,Vchar* cparam);VKI_EXTERN void vdm_DataFunSetSetModeFun(vdm_DataFun*
p,VDataFunSetMode* func);VKI_EXTERN void vdm_DataFunSetSetConventionFun(vdm_DataFun*
p,VDataFunSetConvention* func);VKI_EXTERN void vdm_DataFunSetOpenFun(vdm_DataFun*
p,VDataFunOpen* func);VKI_EXTERN void vdm_DataFunSetCloseFun(vdm_DataFun*
p,VDataFunClose* func);VKI_EXTERN void vdm_DataFunSetDefDatasetFun(vdm_DataFun*
p,VDataFunDefDataset* func);VKI_EXTERN void vdm_DataFunSetGetNumEntitiesFun(vdm_DataFun*
p,VDataFunGetNumEntities* func);VKI_EXTERN void vdm_DataFunSetGetLibraryFun(vdm_DataFun*
p,VDataFunGetLibrary* func);VKI_EXTERN void vdm_DataFunSetWriteDatasetFun(vdm_DataFun*
p,VDataFunWriteDataset* func);VKI_EXTERN void vdm_DataFunSetReadDatasetFun(vdm_DataFun*
p,VDataFunReadDataset* func);VKI_EXTERN void vdm_DataFunSetUpdateFun(vdm_DataFun*
p,VDataFunUpdate* func);VKI_EXTERN void vdm_DataFunSetSetStatusFun(vdm_DataFun*
p,VDataFunSetStatus* func);VKI_EXTERN void vdm_DataFunSetIncDatasetFun(vdm_DataFun*
p,VDataFunIncDataset* func);VKI_EXTERN void vdm_DataFunSetAppendFun(vdm_DataFun*
p,VDataFunAppend* func);VKI_EXTERN void vdm_DataFunSetErrorFun(vdm_DataFun*
p,VDataFunError* func);VKI_EXTERN void vdm_DataFunSetWriteModelFun(vdm_DataFun*
p,VDataFunWriteModel* func);VKI_EXTERN void vdm_DataFunSetWriteStateFun(vdm_DataFun*
p,VDataFunWriteState* func);VKI_EXTERN void vdm_DataFunSetSetIdsFun(vdm_DataFun*
p,VDataFunSetIds* func);VKI_EXTERN void vdm_DataFunSetSetConnectFun(vdm_DataFun*
p,VDataFunSetConnect* func);VKI_EXTERN void vdm_DataFunSetGetConnectFun(vdm_DataFun*
p,VDataFunGetConnect* func);VKI_EXTERN void vdm_DataFunSetLibDatasetFun(vdm_DataFun*
p,VDataFunLibDataset* func);VKI_EXTERN void vdm_DataFunSetDefAttribute(vdm_DataFun*
p,VDataFunDefAttribute* func);VKI_EXTERN void vdm_DataFunSetGetIntegerFun(vdm_DataFun*
p,VDataFunGetInteger* func);VKI_EXTERN void vdm_DataFunSetGetStringFun(vdm_DataFun*
p,VDataFunGetString* func);VKI_EXTERN void vdm_DataFunSetNumDomainsFun(vdm_DataFun*
p,VDataFunNumDomains* func);VKI_EXTERN void vdm_DataFunSetPushContainerFun(vdm_DataFun*
p,VDataFunPushContainer* func);VKI_EXTERN void vdm_DataFunSetPopContainerFun(vdm_DataFun*
p,VDataFunPopContainer* func);VKI_EXTERN void vdm_DataFunSetReadDatasetColrFun(vdm_DataFun*
p,VDataFunReadDatasetCols* func);VKI_EXTERN void vdm_DataFunSetSetThreadsCount(vdm_DataFun*
p,VDataFunSetThreadsCount* func);VKI_EXTERN void vdm_DataFunSetSetStringFun(vdm_DataFun*
p,VDataFunSetString* func);VKI_EXTERN void vdm_DataFunSetGetUnrecognizedDataFun(vdm_DataFun*
p,VDataFunGetUnrecognizedData* func);VKI_EXTERN void
vdm_DataFunApplySettingsFun(vdm_DataFun* p,VDataFunApplySettings*
func);VKI_EXTERN void vdm_DataFunGetNumDatasets(vdm_DataFun*
p,Vint* numdataset);VKI_EXTERN void vdm_DataFunGetDataset(vdm_DataFun*
p,Vint idst,vdm_Dataset** dataset);VKI_EXTERN void vdm_DataFunSearchDataset(vdm_DataFun*
p,const Vchar* name,Vint max,Vint idsts[],Vint* num);
#ifdef __cplusplus
}
#endif
#define vdm_DataFunObj(x)(x)->obj
#if !defined(VKI_FUN_NODEFINE)|| defined(VKI_FUN_DEFINE)
#define vdm_DataFunSetMode(x,a,b)(x)->setmode((x)->obj,\
(a),(b))
#define vdm_DataFunSetConvention(x,a)(x)->setconvention((x)->obj,\
(a))
#define vdm_DataFunSetStatus(x,a)(x)->setstatus((x)->obj,\
(a))
#define vdm_DataFunOpen(x,a,b,c)(x)->open((x)->obj,\
(a),(b),(c))
#define vdm_DataFunClose(x)(x)->close((x)->obj)
#define vdm_DataFunDefDataset(x,a,b,c,d,e,f)(x)->defdataset((x)->obj,\
(a),(b),(c),(d),(e),(f))
#define vdm_DataFunGetNumEntities(x,a,b)(x)->getnumentities((x)->obj,\
(a),(b))
#define vdm_DataFunGetLibrary(x,a)(x)->getlibrary((x)->obj,\
(vdm_Library**)(a))
#define vdm_DataFunWriteDataset(x,a,b)(x)->writedataset((x)->obj,\
(a),(b))
#define vdm_DataFunReadDataset(x,a,b)(x)->readdataset((x)->obj,\
(a),(b))
#define vdm_DataFunUpdate(x)(x)->update((x)->obj)
#define vdm_DataFunIncDataset(x,a)(x)->incdataset((x)->obj,\
(a))
#define vdm_DataFunAppend(x,a,b)(x)->append((x)->obj,\
(a),(b))
#define vdm_DataFunWriteModel(x,a)(x)->writemodel((x)->obj,\
(a))
#define vdm_DataFunWriteState(x,a,b)(x)->writestate((x)->obj,\
(a),(b))
#define vdm_DataFunSetIds(x,a,b,c,d)(x)->setids((x)->obj,\
(a),(b),(c),(d))
#define vdm_DataFunSetConnect(x,a)(x)->setconnect((x)->obj,\
(a))
#define vdm_DataFunGetConnect(x,a)(x)->getconnect((x)->obj,\
(a))
#define vdm_DataFunLibDataset(x,a,b)(x)->libdataset((x)->obj,\
(a),(b))
#define vdm_DataFunDefAttribute(x,a,b,c,d,e)(x)->defattribute((x)->obj,\
(a),(b),(c),(d),(e))
#define vdm_DataFunSetAttVal(x,a,b,c)(x)->setattval((x)->obj,\
(a),(b),(c))
#define vdm_DataFunGetAttVal(x,a,b,c)(x)->getattval((x)->obj,\
(a),(b),(c))
#define vdm_DataFunNumDatasets(x,a)(x)->numdatasets((x)->obj,\
(a))
#define vdm_DataFunNumAttributes(x,a,b)(x)->numattributes((x)->obj,\
(a),(b))
#define vdm_DataFunInqDataset(x,a,b,c,d,e,f)(x)->inqdataset((x)->obj,\
(a),(b),(c),(d),(e),(f))
#define vdm_DataFunInqAttribute(x,a,b,c,d,e)(x)->inqattribute((x)->obj,\
(a),(b),(c),(d),(e))
#define vdm_DataFunGetInteger(x,a,b)(x)->getinteger((x)->obj,\
(a),(b))
#define vdm_DataFunGetString(x,a,b)(x)->getstring((x)->obj,\
(a),(b))
#define vdm_DataFunNumDomains(x,a,b,c)(x)->numdomains((x)->obj,\
(a),(b),(c))
#define vdm_DataFunPushContainer(x,a)(x)->pushcontainer((x)->obj,\
(a))
#define vdm_DataFunPopContainer(x)(x)->popcontainer((x)->obj)
#define vdm_DataFunReadDatasetCols(x,a,b,c,d,e)(x)->readdatasetcols((x)->obj,\
(a),(b),(c),(d),(e))
#define vdm_DataFunSetThreadsCount(x,a)(x)->setthreadscount((x)->obj,\
(a))
#define vdm_DataFunSetString(x,a,b)(x)->setstring((x)->obj,\
(a),(b))
#define vdm_DataFunGetUnrecognizedData(x,a)(x)->getunrecognizeddata((x)->obj,\
(a))
#define vdm_DataFunApplySettings(x,a)(x)->applysettings((x)->obj,\
(a))
#endif
#endif

