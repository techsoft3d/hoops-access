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
 
#ifndef NASDAT_DEF
#define NASDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/base/cvect.h"
#include "sam/base/vhashtable.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vis/idtran.h"
#define VDM_H5_MAXSEC 4
#define VDM_H5_MAXCORN 8
#define VDM_H5_MAXCOMP 8
typedef struct { const Vchar* name;Vint analtype;Vint
hist;Vint type;Vint nqua;Vint iqua[SYS_NQUA_MAX];const
Vchar* cqua;Vint cplx;Vint layerpos;Vint enttype;Vint
subtype;Vint nrows;Vint algorithm;const Vchar* caux;
Vchar** id;Vchar** plyname;Vint numnames;Vchar** names;
Vint ecode;Vint nsect;Vint entry[VDM_H5_MAXSEC][VDM_H5_MAXCORN][VDM_H5_MAXCOMP];
Vint iversion;Vint note;}vdm_NASLib_H5Res;
#define VDM_XDB_MAXSEC 4
#define VDM_XDB_MAXCORN 8
#define VDM_XDB_MAXCOMP 8
typedef struct { const Vchar* name;const Vchar* elemname;
Vint cplx;Vint enttype;Vint subtype;Vint nsect;Vint
layerpos;Vint nrows;Vint ecode;Vint centroidal;Vint
restype;Vint nqua;Vint iqua[SYS_NQUA_MAX];const Vchar*
cqua;Vint note;Vint real[VDM_XDB_MAXSEC][VDM_XDB_MAXCORN][VDM_XDB_MAXCOMP];
Vint imag[VDM_XDB_MAXSEC][VDM_XDB_MAXCORN][VDM_XDB_MAXCOMP];
}vdm_NASLib_XDBres;typedef struct vdm_NASDat { Vlong
nc;Vint type;Vint sect;Vint id;Vint icmp;Vint ncmp;
Vint exid;Vint cplx;Vint iran;Vint irms;Vint indx;Vint
rtyp;Vint cent;Vint iout;Vint nhdr;Vint nstp;Vint nelemtype;
Vint mcet;Vint iply;Vlong* ncet;vsy_VHashTable* dbptr;
Vint cur;vis_IdTran* idtran;vsy_CVect* cvect;Vobject*
obj;Vint fiberflag;Vobject* h5dom;Vobject** h5res;Vint*
h5id;Vint* h5pos;Vint* h5size;Vint h5iter;Vint h5num;
Vchar* h5path;Vobject** ch5res;Vint* ch5id;Vint* ch5pos;
Vint* ch5size;Vint ch5iter;Vint ch5num;Vchar* ch5path;
}vdm_NASDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_NASDat* vdm_NASDatBegin(void);VKI_EXTERN
void vdm_NASDatEnd(vdm_NASDat* p);VKI_EXTERN void vdm_NASDatDef(vdm_NASDat*
p,Vlong nc,Vint type,Vint sect,Vint id,Vint icmp,Vint
ncmp,Vint cplx);VKI_EXTERN void vdm_NASDatInq(vdm_NASDat*
p,Vlong* nc,Vint* type,Vint* sect,Vint* id,Vint* icmp,
Vint* ncmp,Vint* cplx);VKI_EXTERN void vdm_NASDatAdd(vdm_NASDat*
p,Vlong nc);VKI_EXTERN void vdm_NASDatNum(vdm_NASDat*
p,Vint* numpos);VKI_EXTERN void vdm_NASDatPos(vdm_NASDat*
p,Vint ithpos,Vlong* nc);VKI_EXTERN void vdm_NASDatSetNumHdr(vdm_NASDat*
p,Vint nhdr);VKI_EXTERN void vdm_NASDatGetNumHdr(vdm_NASDat*
p,Vint* nhdr);VKI_EXTERN void vdm_NASDatSetNumStp(vdm_NASDat*
p,Vint nstp);VKI_EXTERN void vdm_NASDatGetNumStp(vdm_NASDat*
p,Vint* nstp);VKI_EXTERN void vdm_NASDatSetIRan(vdm_NASDat*
p,Vint iran);VKI_EXTERN void vdm_NASDatGetIRan(vdm_NASDat*
p,Vint* iran);VKI_EXTERN void vdm_NASDatSetEXid(vdm_NASDat*
p,Vint exid);VKI_EXTERN void vdm_NASDatGetEXid(vdm_NASDat*
p,Vint* exid);VKI_EXTERN void vdm_NASDatSetIRMS(vdm_NASDat*
p,Vint irms);VKI_EXTERN void vdm_NASDatGetIRMS(vdm_NASDat*
p,Vint* irms);VKI_EXTERN void vdm_NASDatSetIndx(vdm_NASDat*
p,Vint indx);VKI_EXTERN void vdm_NASDatGetIndx(vdm_NASDat*
p,Vint* indx);VKI_EXTERN void vdm_NASDatSetRtyp(vdm_NASDat*
p,Vint rtyp);VKI_EXTERN void vdm_NASDatGetRtyp(vdm_NASDat*
p,Vint* rtyp);VKI_EXTERN void vdm_NASDatSetCent(vdm_NASDat*
p,Vint cent);VKI_EXTERN void vdm_NASDatGetCent(vdm_NASDat*
p,Vint* cent);VKI_EXTERN void vdm_NASDatSetOutID(vdm_NASDat*
p,Vint iout);VKI_EXTERN void vdm_NASDatGetOutID(vdm_NASDat*
p,Vint* iout);VKI_EXTERN void vdm_NASDatAppend(vdm_NASDat*
p,Vint dbptr,Vint iblk,Vint code,Vobject* obj);VKI_EXTERN
void vdm_NASDatInitIter(vdm_NASDat* p);VKI_EXTERN void
vdm_NASDatNextIter(vdm_NASDat* p,Vint* dbptr,Vint* iblk,
Vint* code,Vobject** obj);VKI_EXTERN void vdm_NASDatSetIdTran(vdm_NASDat*
p,vis_IdTran* idtran);VKI_EXTERN void vdm_NASDatGetIdTran(vdm_NASDat*
p,vis_IdTran** idtran);VKI_EXTERN void vdm_NASDatSetCVect(vdm_NASDat*
p,vsy_CVect* cvect);VKI_EXTERN void vdm_NASDatGetCVect(vdm_NASDat*
p,vsy_CVect** cvect);VKI_EXTERN void vdm_NASDatSetObj(vdm_NASDat*
p,Vobject* obj);VKI_EXTERN void vdm_NASDatSetDomain(vdm_NASDat*
p,Vobject* obj);VKI_EXTERN void vdm_NASDatGetDomain(vdm_NASDat*
p,Vobject** obj);VKI_EXTERN void vdm_NASDatAddH5(vdm_NASDat*
p,Vchar path[],Vobject* h5res,Vint id,Vint position,
Vint length);VKI_EXTERN void vdm_NASDatAddCH5(vdm_NASDat*
p,Vchar path[],Vobject* h5res,Vint id,Vint position,
Vint length);VKI_EXTERN void vdm_NASDatInitH5(vdm_NASDat*
p);VKI_EXTERN void vdm_NASDatNextH5(vdm_NASDat* p,Vchar
path[],Vobject** h5res,Vint* id,Vint* position,Vint*
length);VKI_EXTERN void vdm_NASDatSetFiberFlag(vdm_NASDat*
p,Vint fiberflag);VKI_EXTERN void vdm_NASDatGetFiberFlag(vdm_NASDat*
p,Vint* fiberflag);
#ifdef __cplusplus
}
#endif
#endif

