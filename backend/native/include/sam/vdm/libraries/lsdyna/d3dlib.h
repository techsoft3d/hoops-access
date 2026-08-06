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
 
#ifndef D3DLIB_DEF
#define D3DLIB_DEF
#include <stdio.h>
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#define D3DLIB_SEARCH_SWFORC 1
#define D3DLIB_SEARCH_SWFORC_OFF 2
#define D3DLIB_SEARCH_NCFORC 3
#define D3DLIB_SEARCH_NCFORC_OFF 4
#define D3D_ELEMENT_SOLID 0
#define D3D_ELEMENT_BEAM 1
#define D3D_ELEMENT_SHELL 2
#define D3D_ELEMENT_THICK_SHELL 3
#define D3D_ELEMENT_HEX8 4
#define D3D_ELEMENT_HEX20 5
#define D3D_ELEMENT_HEX27 6
#define D3D_ELEMENT_TET4 7
#define D3D_ELEMENT_TET10 8
 typedef void(VD3DLibMonitorFunc)(vdm_D3DLib*,Vobject*);
typedef struct _D3Dio { FILE* fd;Vchar namfamily[SYS_MAXPATHCHAR];
Vchar filename[SYS_MAXPATHCHAR];Vchar fileroot[SYS_MAXPATHCHAR];
Vint curfamily;Vlong curoffset;Vlong curlength;Vint
byteswap;Vint dp;Vint dpi;Vint npre;Vint femzip;Vint
type;Vint sizegeo,sizestate,sizedisp,sizeactivity,sizepost;
Vint bsize,*buff;Vlong bpos;Vint ist;int p1[1000],p2[1000],
lp1,lp2;Vint swforc;FILE* fdswforc;Vint ncforc;FILE*
fdncforc;}vdm_D3Dio;struct vdm_D3DLib { vdm_Library*
library;Vint ierr;Vint type;Vint femzip;Vint searchswforc;
Vint swforc;vsy_IntVec* swforcstep;vsy_DblVec* swforctime;
vsy_DblVec* swforcdata;Vint searchncforc;Vint ncforc;
Vchar path[SYS_MAXPATHCHAR];VConventionType conv;Vint
doubpre;Vint nodata;Vint retcon;Vint status;Vint idtyp,
idoff[3],idbas[3];Vint inum;Vint cplx;Vint ieig;Vint
numnp;Vint numel;Vint ndim;Vint nfree;Vint nantyp;Vint
soltyp;Vint nummat;Vint nel8,nelt,nel4,nel2;Vint tet10flag;
Vint nel48;Vint nv3d;Vint nv3dt;Vint nv2d;Vint nv1d;
Vint nt3d;Vint nt3dt;Vint nt2d;Vint nt1d;Vint maxint;
Vint neips;Vint neiph;Vint beamip;Vint lngnne;Vint ioshl[4];
Vint iosol[2];Vint istrn;Vint numrbe;Vint narbs;Vint
nmmat;Vint arbmatflag;Vint* arbmat;Vint* nel4mid;Vint
mattyp;Vint* irbtyp;Vint numfluid;Vint npefg,nvar,npart,
npartgas,subver,desv;Vint ndedb,extcb[10][16];Vint extra;
Vint* iextra;Vint nel20;vsy_DblVec* sttime;Vint conveip;
Vint nds;Vint numds;Vint nst;Vint nsth;Vint nstb;Vint
nsts;Vint nstt;Vint tnods;Vint tsols;Vint tbems;Vint
tshls;Vint ttshs;Vint nstp,iflagd;Vint lngnnd,lngind;
Vint indits,indius,indivs,indias;Vint lngsol;Vint lngbem;
Vint lngshl;Vint lngtsh;Vint lngnst;Vint ntimes;vis_IdTran*
idtranni;Vint nhelem;vsy_Dictionary* hedict;Vint nhnode;
vsy_Dictionary* hndict;Vchar deiname[5][256];vsy_IntVec*
ivstep;vsy_DblVec* dvtime;Vint ifahist;Vlong iadhist;
Vint numeni;vis_IdTran* idtraneni;Vint totenl;vis_IdTran*
idtranenl;Vint nhtime;vsy_Dictionary* htdict;Vint nhstep;
vsy_Dictionary* hsdict;Vint ntimesw;vdm_D3Dio d3dio;
Vchar title[41];Vint controldata[64];Vfloat fversion;
Vchar version[16];Vint nglbv;Vfloat* bglbv;Vint numdataset;
Vint phase;Vchar source[VDM_SOURCE_SIZE];vis_Connect*
connect;vis_GridFun* gridfun;Vint orientnodeflag;vis_GProp*
gprop;Vint ersvec;vsy_HashTable* edh;Vint ialemat;vis_IdTran*
idtranfluidid;Vint nmsph;Vint lngsph,isphfg[11],lngsphdat,
lsphfg[11];Vint numnpt;Vint numelt;Vint mdlopt;Vint
ncfdv1,ncfdv2;Vint nvarids,varids[100];Vint nvolvars[100],
sdid[100];Vint lngstancfdv;vis_IdTran* idtrans;vis_IdTran*
idtransCentroid;vis_IdTran* idtranse;vis_IdTran* idtranl;
VD3DLibMonitorFunc* funmon;Vobject* funobjmon;Vint abortflag;
Vint numlib;Vint* libdsts;vdm_D3DLib* parlib;vdm_D3DLib*
curlib;Vint iad1,iad2;vsy_IntVec* d3dElementTypes;Vint
plasticStrainTensor;Vint thermalStrainTensor;
#ifdef __cplusplus
public: VKI_EXTERN vdm_D3DLib(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_D3DLib(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void GetInteger(Vint,Vint*);VKI_EXTERN void
GetString(Vint,Vchar*);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void SetConvention(VConventionType);
VKI_EXTERN void SetStatus(Vint);VKI_EXTERN void SetIds(Vint,
Vint,Vint,Vint);VKI_EXTERN void GetConnect(vis_Connect**);
VKI_EXTERN void SetConnect(vis_Connect*);VKI_EXTERN
void SetFunction(Vint,Vfunc*,Vobject*);VKI_EXTERN void
SetMonitorFunction(VD3DLibMonitorFunc*,Vobject*);VKI_EXTERN
void Abort();VKI_EXTERN void NumDomains(Vchar*,Vint,
Vint*);VKI_EXTERN void SetSearch(Vint);VKI_EXTERN void
Open(Vint,Vchar*,Vint);VKI_EXTERN void Close();VKI_EXTERN
void Append(Vchar*,Vint);VKI_EXTERN void GetNumEntities(Vint,
Vint*);VKI_EXTERN void GetLibrary(vdm_Library**);VKI_EXTERN
void NumDatasets(Vint*);VKI_EXTERN void NumAttributes(Vint,
Vint*);VKI_EXTERN void GetAttVal(Vint,Vint,void*);VKI_EXTERN
void InqDataset(Vint,Vchar[],Vlong*,Vint*,Vint*,Vint*);
VKI_EXTERN void InqAttribute(Vint,Vint,Vchar[],Vint*,
Vint*);VKI_EXTERN void ReadDataset(Vint,void*);VKI_EXTERN
void LibDataset(Vint,Vint);VKI_EXTERN void DataFun(vdm_DataFun*);
VKI_EXTERN void PrintUnrecognizedData();VKI_EXTERN void
SetString(Vint,Vchar*);VKI_EXTERN void GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_D3DLib* vdm_D3DLibBegin(void);VKI_EXTERN
void vdm_D3DLib_Construct(vdm_D3DLib* p);VKI_EXTERN
void vdm_D3DLibEnd(vdm_D3DLib* p);VKI_EXTERN void vdm_D3DLib_Destruct(vdm_D3DLib*
p);VKI_EXTERN Vint vdm_D3DLibError(vdm_D3DLib* p);VKI_EXTERN
void vdm_D3DLibGetInteger(vdm_D3DLib* p,Vint type,Vint*
ivalue);VKI_EXTERN void vdm_D3DLibGetString(vdm_D3DLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_D3DLibSetMode(vdm_D3DLib*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_D3DLibSetConvention(vdm_D3DLib*
p,VConventionType convention);VKI_EXTERN void vdm_D3DLibSetStatus(vdm_D3DLib*
p,Vint status);VKI_EXTERN void vdm_D3DLibSetIds(vdm_D3DLib*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_D3DLibGetConnect(vdm_D3DLib* p,
vis_Connect** connect);VKI_EXTERN void vdm_D3DLibSetConnect(vdm_D3DLib*
p,vis_Connect* connect);VKI_EXTERN void vdm_D3DLibSetFunction(vdm_D3DLib*
p,Vint funtype,Vfunc* function,Vobject* object);VKI_EXTERN
void vdm_D3DLibSetMonitorFunction(vdm_D3DLib* p,VD3DLibMonitorFunc*
function,Vobject* object);VKI_EXTERN void vdm_D3DLibAbort(vdm_D3DLib*
p);VKI_EXTERN void vdm_D3DLibNumDomains(vdm_D3DLib*
p,Vchar* filename,Vint type,Vint* numdomains);VKI_EXTERN
void vdm_D3DLibSetSearch(vdm_D3DLib* p,Vint search);
VKI_EXTERN void vdm_D3DLibOpen(vdm_D3DLib* p,Vint mode,
Vchar* filename,Vint type);VKI_EXTERN void vdm_D3DLibClose(vdm_D3DLib*
p);VKI_EXTERN void vdm_D3DLibAppend(vdm_D3DLib* p,Vchar*
filename,Vint type);VKI_EXTERN void vdm_D3DLibGetNumEntities(vdm_D3DLib*
p,Vint entitytype,Vint* numentity);VKI_EXTERN void vdm_D3DLibGetLibrary(vdm_D3DLib*
p,vdm_Library** library);VKI_EXTERN void vdm_D3DLibNumDatasets(vdm_D3DLib*
p,Vint* numdatasets);VKI_EXTERN void vdm_D3DLibNumAttributes(vdm_D3DLib*
p,Vint idst,Vint* numattributes);VKI_EXTERN void vdm_D3DLibGetAttVal(vdm_D3DLib*
p,Vint idst,Vint iatt,void* value);VKI_EXTERN void vdm_D3DLibInqDataset(vdm_D3DLib*
p,Vint idst,Vchar name[],Vlong* lrec,Vint* nrow,Vint*
ncol,Vint* type);VKI_EXTERN void vdm_D3DLibInqAttribute(vdm_D3DLib*
p,Vint idst,Vint iatt,Vchar name[],Vint* length,Vint*
type);VKI_EXTERN void vdm_D3DLibReadDataset(vdm_D3DLib*
p,Vint idst,void* buff);VKI_EXTERN void vdm_D3DLibLibDataset(vdm_D3DLib*
p,Vint oper,Vint idst);VKI_EXTERN void vdm_D3DLibSetString(vdm_D3DLib*
p,Vint type,Vchar* cvalue);VKI_EXTERN void vdm_D3DLibGetUnrecognizedData(vdm_D3DLib*
p,vdm_UnrecognizedData** unrecognizedData);VKI_EXTERN
void vdm_D3DLibDataFun(vdm_D3DLib* p,vdm_DataFun* datafun);
VKI_EXTERN void vdm_D3DLibPrintUnrecognizedData(vdm_D3DLib*
p);
#ifdef __cplusplus
}
#endif
#endif

