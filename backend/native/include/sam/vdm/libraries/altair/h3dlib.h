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
 
#ifndef H3DLIB_DEF
#define H3DLIB_DEF
#include <stdio.h>
#include "sam/base/basedefs.h"
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#include "sam/vdm/permute.h"
typedef void(VH3DLibMonitorFunc)(vdm_H3DLib*,Vobject*);
struct vdm_H3DLib { Vint ierr;Vint type;VConventionType
conv;Vint doubpre;Vint nodata;Vint retcon;Vint idtyp,
idoff[3],idbas[3];Vint numnp;Vint numel;Vint numdataset;
Vint status;Vint onecomp;Vchar title[81];Vchar version[10];
Vlong lngec;Vint maxnpe;vdm_Library* library;vis_Connect*
connect;vis_GProp* gprop;vsy_Dictionary* epd;vsy_HashTable*
eph;vsy_HashTable* mph;VH3DLibMonitorFunc* funmon;Vobject*
funobjmon;Vint abortflag;void* h3d;Vchar* func;vsy_HashTable*
elemtype;vsy_Dictionary* restype;vsy_Dictionary* quatype;
vsy_HashTable* csh;vsy_HashTable* frestype;Vint maxnix;
Vint* ix;Vint maxelemsets;Vint maxnodesets;vsy_HashTable*
elemsets;vsy_HashTable* nodesets;vsy_Dictionary* hldict;
vis_IdTran* idtranl;Vint nlsect;vdm_H3DLib* parlib;
vdm_H3DLib* curlib;Vint numlib;vdm_Dataset** libs;Vint*
libdsts;Vint phase;Vchar source[VDM_SOURCE_SIZE];vis_ElemDat*
th;vis_IdTran* idtranncols;vis_IdTran* idtranecols;
#ifdef __cplusplus
public: VKI_EXTERN vdm_H3DLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_H3DLib(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetConnect(vis_Connect*);
VKI_EXTERN void GetConnect(vis_Connect**);VKI_EXTERN
void SetIds(Vint,Vint,Vint,Vint);VKI_EXTERN void SetFunction(Vint,
Vfunc*,Vobject*);VKI_EXTERN void SetMonitorFunction(VH3DLibMonitorFunc*,
Vobject*);VKI_EXTERN void Abort();VKI_EXTERN void Open(Vint,
Vchar*,Vint);VKI_EXTERN void Close();VKI_EXTERN void
Append(Vchar*,Vint);VKI_EXTERN void GetNumEntities(Vint,
Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);VKI_EXTERN
void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void ReadDatasetCols(Vint,Vint,Vint[],void*,Vlong*);
VKI_EXTERN void LibDataset(Vint,Vint);VKI_EXTERN void
DataFun(vdm_DataFun*);VKI_EXTERN void GetInteger(Vint,
Vint*);VKI_EXTERN void GetString(Vint,Vchar*);VKI_EXTERN
void NumDomains(Vchar*,Vint,Vint*);VKI_EXTERN void SetString(Vint,
Vchar*);VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_H3DLib* vdm_H3DLibBegin(void);VKI_EXTERN
void vdm_H3DLib_Construct(vdm_H3DLib* p);VKI_EXTERN
void vdm_H3DLibEnd(vdm_H3DLib* p);VKI_EXTERN void vdm_H3DLib_Destruct(vdm_H3DLib*
p);VKI_EXTERN Vint vdm_H3DLibError(vdm_H3DLib* p);VKI_EXTERN
void vdm_H3DLibSetMode(vdm_H3DLib* p,Vint mode,Vint
flag);VKI_EXTERN void vdm_H3DLibSetConvention(vdm_H3DLib*
p,VConventionType convention);VKI_EXTERN void vdm_H3DLibSetStatus(vdm_H3DLib*
p,Vint status);VKI_EXTERN void vdm_H3DLibSetConnect(vdm_H3DLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_H3DLibGetConnect(vdm_H3DLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_H3DLibSetIds(vdm_H3DLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_H3DLibSetFunction(vdm_H3DLib* p,
Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_H3DLibSetMonitorFunction(vdm_H3DLib* p,VH3DLibMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_H3DLibAbort(vdm_H3DLib*
p);VKI_EXTERN void vdm_H3DLibOpen(vdm_H3DLib* p,Vint
mode,Vchar* filename,Vint type);VKI_EXTERN void vdm_H3DLibClose(vdm_H3DLib*
p);VKI_EXTERN void vdm_H3DLibAppend(vdm_H3DLib* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_H3DLibGetNumEntities(vdm_H3DLib*
p,Vint enttype,Vint* nument);VKI_EXTERN void vdm_H3DLibGetLibrary(vdm_H3DLib*
p,vdm_Library** library);VKI_EXTERN void vdm_H3DLibNumDatasets(vdm_H3DLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_H3DLibNumAttributes(vdm_H3DLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_H3DLibGetAttVal(vdm_H3DLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_H3DLibInqDataset(vdm_H3DLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_H3DLibInqAttribute(vdm_H3DLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_H3DLibReadDataset(vdm_H3DLib*
p,Vint idst,void* buf);VKI_EXTERN void vdm_H3DLibReadDatasetCols(vdm_H3DLib*
p,Vint idst,Vint ncols,Vint cols[],void* buf,Vlong*
lptr);VKI_EXTERN void vdm_H3DLibLibDataset(vdm_H3DLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_H3DLibSetString(vdm_H3DLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_H3DLibGetUnrecognizedData(vdm_H3DLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_H3DLibDataFun(vdm_H3DLib* p,vdm_DataFun* datafun);
VKI_EXTERN void vdm_H3DLibGetInteger(vdm_H3DLib* p,
Vint type,Vint* ivalue);VKI_EXTERN void vdm_H3DLibGetString(vdm_H3DLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_H3DLibNumDomains(vdm_H3DLib*
p,Vchar* filename,Vint type,Vint* numdomains);
#ifdef __cplusplus
}
#endif
#endif

