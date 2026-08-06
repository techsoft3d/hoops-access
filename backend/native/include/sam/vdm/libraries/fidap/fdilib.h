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
 
#ifndef FDILIB_DEF
#define FDILIB_DEF
#include <stdio.h>
#include "sam/base/basedefs.h"
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
typedef struct vdm_FDIio { FILE* fd;Vlong ipnt;}vdm_FDIio;
typedef struct vdm_FDIflux { Vint iv1;Vint iv2;Vint
ix[9];Vdouble flux[9];}vdm_FDIflux;struct vdm_FDILib
{ vdm_Library* library;Vint ierr;Vint type;VConventionType
conv;Vint doubpre;Vint nodata;Vint retcon;Vint status;
Vint idtyp,idoff[3],idbas[3];Vint numnp;Vint numel;
Vint nfree;Vint ndim;Vint soltyp;Vint ngrps;Vint ndfcd;
Vint ndfvl;vdm_FDIio fdiio;vdm_FDIio* fdiioptr;Vchar
version[32];Vchar date[32];Vchar time[32];Vchar title[81];
Vint ndof[10];Vint numdataset;vis_Connect* connect;
vis_GridFun* gridfun;vis_IdTran* idtrannode;vis_IdTran*
idtranelem;Vint numelemsets;vsy_HashTable* elemsets;
vdm_Permute* permute;vsy_HashTable* rch;vsy_HashTable*
ich;vsy_HashTable* lch;vsy_Concat* flux;
#ifdef __cplusplus
public: VKI_EXTERN vdm_FDILib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_FDILib(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void NumDomains(Vchar*,Vint,Vint*);VKI_EXTERN void Open(Vint,
Vchar*,Vint);VKI_EXTERN void Close();VKI_EXTERN void
Append(Vchar*,Vint);VKI_EXTERN void GetNumEntities(Vint,
Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);VKI_EXTERN
void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void LibDataset(Vint,Vint);VKI_EXTERN void DataFun(vdm_DataFun*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_FDILib* vdm_FDILibBegin(void);VKI_EXTERN
void vdm_FDILib_Construct(vdm_FDILib* p);VKI_EXTERN
void vdm_FDILibEnd(vdm_FDILib* p);VKI_EXTERN void vdm_FDILib_Destruct(vdm_FDILib*
p);VKI_EXTERN Vint vdm_FDILibError(vdm_FDILib* p);VKI_EXTERN
void vdm_FDILibSetMode(vdm_FDILib* p,Vint mode,Vint
flag);VKI_EXTERN void vdm_FDILibSetConvention(vdm_FDILib*
p,VConventionType convention);VKI_EXTERN void vdm_FDILibSetStatus(vdm_FDILib*
p,Vint status);VKI_EXTERN void vdm_FDILibSetIds(vdm_FDILib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_FDILibGetConnect(vdm_FDILib* p,
vis_Connect** connect);VKI_EXTERN void vdm_FDILibSetConnect(vdm_FDILib*
p,vis_Connect* connect);VKI_EXTERN void vdm_FDILibNumDomains(vdm_FDILib*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_FDILibOpen(vdm_FDILib* p,Vint mode,Vchar* filename,
Vint type);VKI_EXTERN void vdm_FDILibClose(vdm_FDILib*
p);VKI_EXTERN void vdm_FDILibAppend(vdm_FDILib* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_FDILibGetNumEntities(vdm_FDILib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_FDILibGetLibrary(vdm_FDILib*
p,vdm_Library** library);VKI_EXTERN void vdm_FDILibNumDatasets(vdm_FDILib*
p,Vint* numdatasets);VKI_EXTERN void vdm_FDILibNumAttributes(vdm_FDILib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_FDILibGetAttVal(vdm_FDILib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_FDILibInqDataset(vdm_FDILib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_FDILibInqAttribute(vdm_FDILib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_FDILibReadDataset(vdm_FDILib*
p,Vint idst,void* buff);VKI_EXTERN void vdm_FDILibLibDataset(vdm_FDILib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_FDILibDataFun(vdm_FDILib*
p,vdm_DataFun* datafun);
#ifdef __cplusplus
}
#endif
#endif

