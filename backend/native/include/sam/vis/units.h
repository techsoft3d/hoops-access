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
 
#ifndef UNITS_DEF
#define UNITS_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
struct vis_Units { Vint ierr;Vint deflength;Vint deftime;
Vint defmass;Vint deftemp;Vint defangle;Vint defcharge;
Vint setlength;Vint settime;Vint setmass;Vint settemp;
Vint setangle;Vint setcharge;Vdouble faclength;Vdouble
facmass;Vdouble factime;Vdouble factemp;Vdouble offtemp;
Vdouble facangle;Vdouble faccharge;
#ifdef __cplusplus
public: VKI_EXTERN vis_Units(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_Units(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void SetBase(Vint,Vint);VKI_EXTERN void GetBase(Vint,
Vint*);VKI_EXTERN void SetConv(Vint,Vint);VKI_EXTERN
void GetConv(Vint,Vint*);VKI_EXTERN void GetDesc(Vint,
Vint,Vchar[]);VKI_EXTERN void SetFactor(Vint,Vdouble);
VKI_EXTERN void GetFactor(Vint,Vdouble*);VKI_EXTERN
void GetBaseSIFactor(Vint,Vdouble*);VKI_EXTERN void
GetSIFactor(Vint,Vint,Vdouble*);VKI_EXTERN void ComputeFactors();
VKI_EXTERN void Copy(vis_Units*);VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_Units* vis_UnitsBegin(void);VKI_EXTERN
void vis_Units_Construct(vis_Units* p);VKI_EXTERN void
vis_UnitsEnd(vis_Units* p);VKI_EXTERN void vis_Units_Destruct(vis_Units*
p);VKI_EXTERN Vint vis_UnitsError(vis_Units* p);VKI_EXTERN
void vis_UnitsSetBase(vis_Units* p,Vint type,Vint value);
VKI_EXTERN void vis_UnitsGetBase(vis_Units* p,Vint type,
Vint* value);VKI_EXTERN void vis_UnitsSetConv(vis_Units*
p,Vint type,Vint value);VKI_EXTERN void vis_UnitsGetConv(vis_Units*
p,Vint type,Vint* value);VKI_EXTERN void vis_UnitsGetDesc(vis_Units*
p,Vint type,Vint value,Vchar stg[]);VKI_EXTERN void
vis_UnitsSetFactor(vis_Units* p,Vint type,Vdouble value);
VKI_EXTERN void vis_UnitsGetFactor(vis_Units* p,Vint
type,Vdouble* value);VKI_EXTERN void vis_UnitsGetBaseSIFactor(vis_Units*
p,Vint type,Vdouble* value);VKI_EXTERN void vis_UnitsGetSIFactor(vis_Units*
p,Vint type,Vint unit,Vdouble* value);VKI_EXTERN void
vis_UnitsComputeFactors(vis_Units* p);VKI_EXTERN void
vis_UnitsCopy(vis_Units* p,vis_Units* fromp);VKI_EXTERN
void vis_UnitsPrint(vis_Units* p);
#ifdef __cplusplus
}
#endif
#endif

