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
/* User Property Object */
#ifndef UPROP_DEF
#define UPROP_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"

#define UPROP_UNDEFINED 0
#define UPROP_VALUE     1

#define UPROP_USERDIMENUM  -1000000
#define UPROP_USERDIME     -2000000
#define UPROP_USERNAME     -3000000
#define UPROP_USERDATATYPE -4000000
#define UPROP_USERDATA     -5000000
#define UPROP_USERBASE     -5000000

typedef struct vis_UProp_Entry {
    Vint dimenum;
    Vint* dime;
    Vchar* name;
    Vint datatype;
    union {
        void* vp;    /* object property such as a function, f(x) or f(x,y) */
        Vint* ip;    /* pointer to integer properties */
        Vdouble* fp; /* pointer to float properties */
        Vchar* cp;   /* pointer to character properties */
    } prop;
} vis_UProp_Entry;

typedef struct vis_UProp {
    Vint ierr;
    Vint usernum;
    vis_UProp_Entry* user;
} vis_UProp;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_UProp*
vis_UPropBegin(void);
VKI_EXTERN void
vis_UPropEnd(vis_UProp* p);
VKI_EXTERN Vint
vis_UPropError(vis_UProp* p);
VKI_EXTERN void
vis_UPropSetType(vis_UProp* p, Vint id, Vchar* name, Vint nval, Vint datatype);
VKI_EXTERN void
vis_UPropGetType(vis_UProp* p, Vint id, Vchar* name, Vint* nval, Vint* dtype);
VKI_EXTERN void
vis_UPropSetValuei(vis_UProp* p, Vint id, Vint ivalue);
VKI_EXTERN void
vis_UPropSetValueiv(vis_UProp* p, Vint id, Vint* ivalue);
VKI_EXTERN void
vis_UPropSetValuef(vis_UProp* p, Vint id, Vfloat rvalue);
VKI_EXTERN void
vis_UPropSetValuefv(vis_UProp* p, Vint id, Vfloat* rvalue);
VKI_EXTERN void
vis_UPropSetValued(vis_UProp* p, Vint id, Vdouble val);
VKI_EXTERN void
vis_UPropSetValuedv(vis_UProp* p, Vint id, Vdouble* val);
VKI_EXTERN void
vis_UPropSetValuec(vis_UProp* p, Vint id, Vchar* cvalue);
VKI_EXTERN void
vis_UPropValueInteger(vis_UProp* p, Vint id, Vint iparam[]);
VKI_EXTERN void
vis_UPropValueFloat(vis_UProp* p, Vint id, Vfloat fparam[]);
VKI_EXTERN void
vis_UPropValueDouble(vis_UProp* p, Vint id, Vdouble dparam[]);
VKI_EXTERN void
vis_UPropValueString(vis_UProp* p, Vint id, Vchar cparam[]);
VKI_EXTERN void
vis_UPropNum(vis_UProp* p, Vint* num);
VKI_EXTERN void
vis_UPropSetUserNum(vis_UProp* p, Vint num, Vchar* func);
VKI_EXTERN void
vis_UPropSetUserValue(vis_UProp* p, Vint type, Vint dtype, void* param, Vchar* func);
VKI_EXTERN void
vis_UPropValueTypeNum(vis_UProp* p, Vint* ntypes);
VKI_EXTERN void
vis_UPropValueType(vis_UProp* p, Vint* ntypes, Vint type[]);
VKI_EXTERN void
vis_UPropValueFlag(vis_UProp* p, Vint type, Vint* flag);
VKI_EXTERN void
vis_UPropUnSetValue(vis_UProp* p, Vint type);
VKI_EXTERN void
vis_UPropValueParams(vis_UProp* p, Vint type, Vint* nval, Vint* dtyp);
VKI_EXTERN void
vis_UPropValueName(vis_UProp* p, Vint type, Vchar name[]);
VKI_EXTERN void
vis_UPropGetUserValue(vis_UProp* p, Vint type, Vint dtype, void* param, Vchar* func);
VKI_EXTERN void
vis_UPropStreamNum(vis_UProp* p, Vint strmtype, Vint* num);
VKI_EXTERN void
vis_UPropStreamSave(vis_UProp* p, Vint strmtype, Vint num, void* data);
VKI_EXTERN void
vis_UPropStreamLoad(vis_UProp* p, Vint strmtype, Vint ndat, Vint num, void* data);
VKI_EXTERN void
vis_UPropCopy(vis_UProp* p, vis_UProp* fromp);
VKI_EXTERN void
vis_UPropPrint(vis_UProp* p);
VKI_EXTERN Vint
vis_UPropChk(vis_UProp* p, Vint type, Vchar* func);

#ifdef __cplusplus
}
#endif

#endif
