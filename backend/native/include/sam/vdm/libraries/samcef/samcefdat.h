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
 
#ifndef SAMCEFDAT_DEF
#define SAMCEFDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
typedef struct vdm_SAMCEFDat { Vint restype;Vint nqua;
Vint iqua[SYS_NQUA_MAX];Vchar cqua[80];Vchar src[256];
Vchar label[256];Vint icat;Vint nsys;Vint nrows;Vint
cplx;Vint num;Vint* ires;Vint* iref;Vint* icode;Vint*
hasply;Vint* beamsec;Vint iter;Vint enttype;Vint subtype;
Vint isvectensor;vsy_CVect* sectcvect;Vchar liname[80];
Vint numentries;Vint nument;Vint mastercvect;Vchar*
secname;Vchar* dslays;Vchar* dsrotang;Vint elmult;Vint
elnomult;Vint linkcid;struct vdm_SAMCEFDat* parent;
}vdm_SAMCEFDat;typedef struct { Vint icode;const Vchar*
desc;Vint isvectensor;Vint type;Vint isec;Vint row;
Vint nrows;Vint nqua;Vint iqua[SYS_NQUA_MAX];const Vchar*
cqua;Vint* map;Vint nolayer;}vdm_SAMCEF_res;typedef
struct { const Vchar* lcp;Vint analtype;Vint soltype;
}vdm_SAMCEF_anal;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_SAMCEFDat* vdm_SAMCEFDatBegin(void);
VKI_EXTERN void vdm_SAMCEFDatEnd(vdm_SAMCEFDat* p);
VKI_EXTERN void vdm_SAMCEFDatDef(vdm_SAMCEFDat* p,Vint
restype,Vint nqua,Vint iqua[],Vchar cqua[],Vint icat,
Vint nsys,Vint nrows,Vint cplx,Vint enttype,Vint subtype,
Vint isvectensor);VKI_EXTERN void vdm_SAMCEFDatInq(vdm_SAMCEFDat*
p,Vint* restype,Vint* nqua,Vint iqua[],Vchar cqua[],
Vint* icat,Vint* nsys,Vint* nrows,Vint* cplx,Vint* enttype,
Vint* subtype,Vint* isvectensor);VKI_EXTERN void vdm_SAMCEFDatAdd(vdm_SAMCEFDat*
p,Vint ires,Vint iref,Vint icode,Vint hasply,Vint beamsec);
VKI_EXTERN void vdm_SAMCEFDatInitIter(vdm_SAMCEFDat*
p);VKI_EXTERN void vdm_SAMCEFDatNextIter(vdm_SAMCEFDat*
p,Vint* ires,Vint* iref,Vint* icode,Vint* hasply,Vint*
beamsec);VKI_EXTERN void vdm_SAMCEFDatSetSrc(vdm_SAMCEFDat*
p,Vchar* src);VKI_EXTERN void vdm_SAMCEFDatGetSrc(vdm_SAMCEFDat*
p,Vchar src[]);VKI_EXTERN void vdm_SAMCEFDatSetSect(vdm_SAMCEFDat*
p,vsy_CVect* sectcvect);VKI_EXTERN void vdm_SAMCEFDatGetSect(vdm_SAMCEFDat*
p,vsy_CVect** sectcvect);VKI_EXTERN void vdm_SAMCEFDatSetLabel(vdm_SAMCEFDat*
p,Vchar* label);VKI_EXTERN void vdm_SAMCEFDatGetLabel(vdm_SAMCEFDat*
p,Vchar label[]);VKI_EXTERN void vdm_SAMCEFDatSetLinkIndex(vdm_SAMCEFDat*
p,Vchar liname[],Vint numentries,Vint nument);VKI_EXTERN
void vdm_SAMCEFDatGetLinkIndex(vdm_SAMCEFDat* p,Vchar
liname[],Vint* numentries,Vint* nument);VKI_EXTERN void
vdm_SAMCEFDatSetMasterCVect(vdm_SAMCEFDat* p,Vint flag);
VKI_EXTERN void vdm_SAMCEFDatGetMasterCVect(vdm_SAMCEFDat*
p,Vint* flag);VKI_EXTERN void vdm_SAMCEFDatSetSectInfo(vdm_SAMCEFDat*
p,Vchar secname[],Vchar dslays[],Vchar dsrotang[],Vint
elmult,Vint elnomult,Vint linkcid);VKI_EXTERN void vdm_SAMCEFDatGetSectInfo(vdm_SAMCEFDat*
p,Vchar secname[],Vchar dslays[],Vchar dsrotang[],Vint*
elmult,Vint* elnomult,Vint* linkcid);VKI_EXTERN void
vdm_SAMCEFDatSetParent(vdm_SAMCEFDat* p,vdm_SAMCEFDat*
q);
#ifdef __cplusplus
}
#endif
#endif

