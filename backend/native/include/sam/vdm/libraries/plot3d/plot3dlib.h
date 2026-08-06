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
 
#ifndef PLOT3DLIB_DEF
#define PLOT3DLIB_DEF
#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/gprop.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/permute.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#define PLOT3DLIB_AUTO 0
#define PLOT3DLIB_SINGLE 1
#define PLOT3DLIB_MULTIPLE 2
#define PLOT3DLIB_1D 1
#define PLOT3DLIB_2D 2
#define PLOT3DLIB_3DWHOLE 3
#define PLOT3DLIB_3DPLANES 4
#define PLOT3DLIB_UNSTRUCTURED 5
#define PLOT3DLIB_Q 1
#define PLOT3DLIB_FUNCTION 2
typedef void(VPLOT3DLibMonitorFunc)(vdm_PLOT3DLib*,
Vobject*);typedef struct vdm_PLOT3DLibio { FILE* fd;
Vint byteswap;Vint format;Vint fltflg;Vint ieor;Vchar
srec[256],*stok;Vint numrep;Vfloat repfval;Vint repival;
Vint irec,nrec;Vlong ipos;Vint ieorsave;Vchar srecsave[256],
*stoksave;Vint numrepsave;Vfloat repfvalsave;Vint repivalsave;
Vint irecsave,nrecsave;}vdm_PLOT3DLibio;struct vdm_PLOT3DLib
{ vdm_Library* library;Vint ierr;Vint type;Vchar filename[SYS_MAXPATHCHAR];
VConventionType conv;Vint doubpre;Vint nodata;Vint retcon;
Vint status;Vint idtyp,idoff[3],idbas[3];Vint numnp;
Vint numel;Vint ndim;vdm_PLOT3DLibio io;vdm_PLOT3DLibio*
ioptr;Vint numdataset;Vint stype,restype,sect;Vint ncmp;
Vint phase;Vchar source[VDM_SOURCE_SIZE];Vint gtype;
Vint istruc;Vint iblank;Vint ngrid;Vint fltflg;Vint*
idim;Vint* jdim;Vint* kdim;Vint* nvar;Vint maxnpg;Vint
maxnva;Vint rtype;Vfloat head[4];Vlong ipos;vis_Connect*
connectset;vis_Connect* connect;vis_GProp* gprop;Vint
numdatasetplex;vdm_Plex* plex;VPLOT3DLibMonitorFunc*
funmon;Vobject* funobjmon;Vint abortflag;vsy_HashTable*
enth;
#ifdef __cplusplus
public: VKI_EXTERN vdm_PLOT3DLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_PLOT3DLib(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN
void GetString(Vint,Vchar*);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void SetConnect(vis_Connect*);
VKI_EXTERN void GetConnect(vis_Connect**);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VPLOT3DLibMonitorFunc*,Vobject*);
VKI_EXTERN void Abort();VKI_EXTERN void NumDomains(Vchar*,
Vint,Vint*);VKI_EXTERN void Open(Vint,Vchar*,Vint);
VKI_EXTERN void Close();VKI_EXTERN void Append(Vchar*,
Vint);VKI_EXTERN void GetNumEntities(Vint,Vint*);VKI_EXTERN
void GetLibrary(vdm_Library**);VKI_EXTERN void NumDatasets(Vint*);
VKI_EXTERN void NumAttributes(Vint,Vint*);VKI_EXTERN
void GetAttVal(Vint,Vint,void*);VKI_EXTERN void InqDataset(Vint,
Vchar[],Vlong*,Vint*,Vint*,Vint*);VKI_EXTERN void InqAttribute(Vint,
Vint,Vchar[],Vint*,Vint*);VKI_EXTERN void ReadDataset(Vint,
void*);VKI_EXTERN void SetGridType(Vint,Vint,Vint);
VKI_EXTERN void SetResultType(Vint,Vint);VKI_EXTERN
void LibDataset(Vint,Vint);VKI_EXTERN void DataFun(vdm_DataFun*);
VKI_EXTERN void SetString(Vint,Vchar*);VKI_EXTERN void
GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_PLOT3DLib* vdm_PLOT3DLibBegin(void);
VKI_EXTERN void vdm_PLOT3DLib_Construct(vdm_PLOT3DLib*
p);VKI_EXTERN void vdm_PLOT3DLibEnd(vdm_PLOT3DLib* p);
VKI_EXTERN void vdm_PLOT3DLib_Destruct(vdm_PLOT3DLib*
p);VKI_EXTERN Vint vdm_PLOT3DLibError(vdm_PLOT3DLib*
p);VKI_EXTERN void vdm_PLOT3DLibGetInteger(vdm_PLOT3DLib*
p,Vint type,Vint* ivalue);VKI_EXTERN void vdm_PLOT3DLibGetString(vdm_PLOT3DLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_PLOT3DLibSetMode(vdm_PLOT3DLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_PLOT3DLibSetConvention(vdm_PLOT3DLib*
p,VConventionType convention);VKI_EXTERN void vdm_PLOT3DLibSetStatus(vdm_PLOT3DLib*
p,Vint status);VKI_EXTERN void vdm_PLOT3DLibSetIds(vdm_PLOT3DLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_PLOT3DLibSetConnect(vdm_PLOT3DLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_PLOT3DLibGetConnect(vdm_PLOT3DLib*
p,vis_Connect** connect);VKI_EXTERN void vdm_PLOT3DLibSetFunction(vdm_PLOT3DLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_PLOT3DLibSetMonitorFunction(vdm_PLOT3DLib*
p,VPLOT3DLibMonitorFunc* function,Vobject* object);
VKI_EXTERN void vdm_PLOT3DLibAbort(vdm_PLOT3DLib* p);
VKI_EXTERN void vdm_PLOT3DLibNumDomains(vdm_PLOT3DLib*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_PLOT3DLibOpen(vdm_PLOT3DLib* p,Vint mode,Vchar*
filename,Vint type);VKI_EXTERN void vdm_PLOT3DLibClose(vdm_PLOT3DLib*
p);VKI_EXTERN void vdm_PLOT3DLibAppend(vdm_PLOT3DLib*
p,Vchar* filename,Vint type);VKI_EXTERN void vdm_PLOT3DLibGetNumEntities(vdm_PLOT3DLib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_PLOT3DLibGetLibrary(vdm_PLOT3DLib*
p,vdm_Library** library);VKI_EXTERN void vdm_PLOT3DLibNumDatasets(vdm_PLOT3DLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_PLOT3DLibNumAttributes(vdm_PLOT3DLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_PLOT3DLibGetAttVal(vdm_PLOT3DLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_PLOT3DLibInqDataset(vdm_PLOT3DLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_PLOT3DLibInqAttribute(vdm_PLOT3DLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_PLOT3DLibReadDataset(vdm_PLOT3DLib*
p,Vint idst,void* buff);VKI_EXTERN void vdm_PLOT3DLibSetGridType(vdm_PLOT3DLib*
p,Vint gtype,Vint dime,Vint iblank);VKI_EXTERN void
vdm_PLOT3DLibSetResultType(vdm_PLOT3DLib* p,Vint rtype,
Vint restype);VKI_EXTERN void vdm_PLOT3DLibLibDataset(vdm_PLOT3DLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_PLOT3DLibSetString(vdm_PLOT3DLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_PLOT3DLibGetUnrecognizedData(vdm_PLOT3DLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_PLOT3DLibDataFun(vdm_PLOT3DLib* p,vdm_DataFun*
datafun);
#ifdef __cplusplus
}
#endif
#endif

