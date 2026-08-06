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
 
#ifndef LMAN_DEF
#define LMAN_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/dataset.h"
#include "sam/vis/model.h"
#include "sam/vis/state.h"
#include "sam/vis/history.h"
#include "sam/vis/rprop.h"
#include "sam/vdm/options.h"
struct vdm_LMan { Vint ierr;vdm_DataFun* df;Vint verbose;
Vint check;Vint nonzero;Vint lmpre,smpre;Vint indexstart,
indexstop;Vint focusconn;Vint nodataval;Vint retcon;
Vint lrpre,srpre;Vint lmload;Vint lmrest;Vint lmelemgeom;
Vint lmset;Vint storeLoadedModel;Vint smcase;Vint srcase;
Vint nient;vsy_Dictionary* idict;Vint nhtime;vsy_Dictionary*
htdict;Vint nhstep;vsy_Dictionary* hsdict;vsy_List*
resultDatasetNames;vis_Model* model;vis_GridFun* gridfun;
vdm_Library* loadedLibrary;
#ifdef __cplusplus
public: VKI_EXTERN vdm_LMan(void);VKI_EXTERN void* operator
new(size_t);VKI_EXTERN ~vdm_LMan(void);VKI_EXTERN void
operator delete(void*);VKI_EXTERN void OpenFile(const
Vchar*,vdm_Options*);VKI_EXTERN void Append(const Vchar*
file);VKI_EXTERN Vint GetNumStates();VKI_EXTERN void
CloseFile();VKI_EXTERN Vint Error();VKI_EXTERN void
SetObject(Vint,Vobject*);VKI_EXTERN void GetObject(Vint,
Vobject**);VKI_EXTERN void SetParami(Vint,Vint);VKI_EXTERN
void Export(const Vchar*,const Vchar*);VKI_EXTERN void
Import(const Vchar*);VKI_EXTERN void TOC(const Vchar*);
VKI_EXTERN void List(const Vchar*);VKI_EXTERN void LoadModel(vis_Model*);
VKI_EXTERN void MakeLibDataset(Vchar*,Vint*);VKI_EXTERN
void SaveModel(vis_Model*);VKI_EXTERN void LoadState(vis_State*,
vis_RProp*);VKI_EXTERN void LoadStateFromName(const
Vchar*,vis_State*);VKI_EXTERN void GetStateNames(vsy_List**);
VKI_EXTERN void LoadIdTranState(vis_IdTran*,vis_State*,
vis_RProp*);VKI_EXTERN void LoadIdTranStateFromName(vis_IdTran*,
const Vchar*,vis_State*);VKI_EXTERN void SaveState(vis_State*,
vis_RProp*);VKI_EXTERN void CreateFile(const Vchar*,
vdm_Options*);VKI_EXTERN void SaveFile(const Vchar*,
vdm_Options*);VKI_EXTERN void LoadHistory(vis_History*,
vis_RProp*);VKI_EXTERN void LoadHistoryFromName(Vchar*,
vis_History*);VKI_EXTERN void SaveHistory(vis_History*,
vis_RProp*);VKI_EXTERN void LoadRedMat(vis_RedMat*,
vis_RProp*);VKI_EXTERN void SaveRedMat(vis_RedMat*,
vis_RProp*);VKI_EXTERN void SearchState(const Vchar*,
Vint,Vint[],Vint*);VKI_EXTERN void SearchLibraryMesh(Vint,
Vint[],Vint*);VKI_EXTERN void SetLibraryMesh(Vint,Vint);
VKI_EXTERN void GetMetadata(Vint,vis_ResultMetadata*);
VKI_EXTERN void GetMetadataFromName(const Vchar*,vis_ResultMetadata*);
VKI_EXTERN void GetConnect(vis_Connect**);VKI_EXTERN
void Inquire(Vchar*,Vint*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_LMan* vdm_LManBegin(void);VKI_EXTERN
void vdm_LManOpenFile(vdm_LMan* p,const Vchar* file,
vdm_Options* options);VKI_EXTERN void vdm_LManCreateFile(vdm_LMan*
p,const Vchar* file,vdm_Options* options);VKI_EXTERN
void vdm_LManAppend(vdm_LMan* p,const Vchar* file);
VKI_EXTERN Vint vdm_LManGetNumStates(vdm_LMan* p);VKI_EXTERN
void vdm_LManSearchState(vdm_LMan* p,const Vchar* name,
Vint max,Vint idsts[],Vint* num);VKI_EXTERN void vdm_LMan_Construct(vdm_LMan*
p);VKI_EXTERN void vdm_LManEnd(vdm_LMan* p);VKI_EXTERN
void vdm_LManCloseFile(vdm_LMan* p);VKI_EXTERN void
vdm_LMan_Destruct(vdm_LMan* p);VKI_EXTERN Vint vdm_LManError(vdm_LMan*
p);VKI_EXTERN void vdm_LManSetObject(vdm_LMan* p,Vint
objecttype,Vobject* object);VKI_EXTERN void vdm_LManGetObject(vdm_LMan*
p,Vint objecttype,Vobject** object);VKI_EXTERN void
vdm_LManSetParami(vdm_LMan* p,Vint type,Vint iparam);
VKI_EXTERN void vdm_LManExport(vdm_LMan* p,const Vchar*
name,const Vchar* path);VKI_EXTERN void vdm_LManImport(vdm_LMan*
p,const Vchar* path);VKI_EXTERN void vdm_LManTOC(vdm_LMan*
p,const Vchar* name);VKI_EXTERN void vdm_LManList(vdm_LMan*
p,const Vchar* name);VKI_EXTERN void vdm_LManLoadModel(vdm_LMan*
p,vis_Model* model);VKI_EXTERN void vdm_LManMakeLibDataset(vdm_LMan*
p,Vchar* dsname,Vint* idst);VKI_EXTERN void vdm_LManSaveModel(vdm_LMan*
p,vis_Model* model);VKI_EXTERN void vdm_LManLoadState(vdm_LMan*
p,vis_State* state,vis_RProp* rprop);VKI_EXTERN void
vdm_LManLoadStateFromName(vdm_LMan* p,const Vchar datasetname[],
vis_State* state);VKI_EXTERN void vdm_LManGetStateNames(vdm_LMan*
p,vsy_List** stateNames);VKI_EXTERN void vdm_LManLoadIdTranState(vdm_LMan*
p,vis_IdTran* idtran,vis_State* state,vis_RProp* rprop);
VKI_EXTERN void vdm_LManLoadIdTranStateFromName(vdm_LMan*
p,vis_IdTran* idtran,const Vchar datasetname[],vis_State*
state);VKI_EXTERN void vdm_LManSaveState(vdm_LMan* p,
vis_State* state,vis_RProp* rprop);VKI_EXTERN void vdm_LManLoadHistory(vdm_LMan*
p,vis_History* history,vis_RProp* rprop);VKI_EXTERN
void vdm_LManLoadHistoryFromName(vdm_LMan* p,Vchar datasetname[],
vis_History* history);VKI_EXTERN void vdm_LManSaveHistory(vdm_LMan*
p,vis_History* history,vis_RProp* rprop);VKI_EXTERN
void vdm_LManLoadRedMat(vdm_LMan* p,vis_RedMat* redmat,
vis_RProp* rprop);VKI_EXTERN void vdm_LManSaveRedMat(vdm_LMan*
p,vis_RedMat* redmat,vis_RProp* rprop);VKI_EXTERN void
vdm_LManGetMetadata(vdm_LMan* p,Vint stateId,vis_ResultMetadata*
metadata);VKI_EXTERN void vdm_LManGetMetadataFromName(vdm_LMan*
p,const Vchar* stateName,vis_ResultMetadata* metadata);
VKI_EXTERN void vdm_LManSaveFile(vdm_LMan* p,const Vchar*
filename,vdm_Options* options);VKI_EXTERN void vdm_LManGetConnect(vdm_LMan*
p,vis_Connect** connect);VKI_EXTERN void vdm_LManSearchLibraryMesh(vdm_LMan*
p,Vint max,Vint idsts[],Vint* num);VKI_EXTERN void vdm_LManSetLibraryMesh(vdm_LMan*
p,Vint operation,Vint index);VKI_EXTERN void vdm_LManInquire(vdm_LMan*
p,Vchar* path,Vint* type);
#ifdef __cplusplus
}
#endif
#endif

