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
 
#ifndef ATTRIBUTE_DEF
#define ATTRIBUTE_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#define ATTRIBUTE_MAXNAME SYS_MAXNAME
  
#define ATTRIBUTE_MAXVALUE SYS_MAXNAME
struct vdm_Attribute { Vint ierr;Vchar* name;Vint length;
Vint type;Vint nbyte;union { Vchar* cvalue;Vint* ivalue;
Vfloat* rvalue;Vdouble* dvalue;}value;
#ifdef __cplusplus
public: VKI_EXTERN vdm_Attribute(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_Attribute(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(const Vchar*,Vint,Vint);
VKI_EXTERN void Inq(Vchar[],Vint*,Vint*);VKI_EXTERN
void Set(const void*);VKI_EXTERN void SetValueiv(const
Vint[]);VKI_EXTERN void SetValuefv(const Vfloat[]);
VKI_EXTERN void SetValuedv(const Vdouble[]);VKI_EXTERN
void SetValuec(const Vchar[]);VKI_EXTERN void Get(void*);
VKI_EXTERN void ValueInteger(Vint[]);VKI_EXTERN void
ValueFloat(Vfloat[]);VKI_EXTERN void ValueDouble(Vdouble[]);
VKI_EXTERN void ValueString(Vchar[]);VKI_EXTERN void
StreamNum(Vint*);VKI_EXTERN void StreamSave(void*);
VKI_EXTERN void StreamLoad(void*);VKI_EXTERN void Copy(vdm_Attribute*);
VKI_EXTERN void Print();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_Attribute* vdm_AttributeBegin(void);
VKI_EXTERN void vdm_Attribute_Construct(vdm_Attribute*
p);VKI_EXTERN void vdm_AttributeEnd(vdm_Attribute* p);
VKI_EXTERN void vdm_Attribute_Destruct(vdm_Attribute*
p);VKI_EXTERN Vint vdm_AttributeError(vdm_Attribute*
p);VKI_EXTERN void vdm_AttributeDef(vdm_Attribute* p,
const Vchar* name,Vint length,Vint type);VKI_EXTERN
void vdm_AttributeInq(vdm_Attribute* p,Vchar name[],
Vint* length,Vint* type);VKI_EXTERN void vdm_AttributeSet(vdm_Attribute*
p,const void* value);VKI_EXTERN void vdm_AttributeSetValueiv(vdm_Attribute*
p,const Vint ivalue[]);VKI_EXTERN void vdm_AttributeSetValuefv(vdm_Attribute*
p,const Vfloat fvalue[]);VKI_EXTERN void vdm_AttributeSetValuedv(vdm_Attribute*
p,const Vdouble dvalue[]);VKI_EXTERN void vdm_AttributeSetValuec(vdm_Attribute*
p,const Vchar cvalue[]);VKI_EXTERN void vdm_AttributeGet(vdm_Attribute*
p,void* value);VKI_EXTERN void vdm_AttributeValueInteger(vdm_Attribute*
p,Vint ivalue[]);VKI_EXTERN void vdm_AttributeValueFloat(vdm_Attribute*
p,Vfloat fvalue[]);VKI_EXTERN void vdm_AttributeValueDouble(vdm_Attribute*
p,Vdouble dvalue[]);VKI_EXTERN void vdm_AttributeValueString(vdm_Attribute*
p,Vchar cvalue[]);VKI_EXTERN void vdm_AttributeStreamNum(vdm_Attribute*
p,Vint* nbytes);VKI_EXTERN void vdm_AttributeStreamSave(vdm_Attribute*
p,void* data);VKI_EXTERN void vdm_AttributeStreamLoad(vdm_Attribute*
p,void* data);VKI_EXTERN void vdm_AttributeCopy(vdm_Attribute*
p,vdm_Attribute* fromp);VKI_EXTERN void vdm_AttributePrint(vdm_Attribute*
p);
#ifdef __cplusplus
}
#endif
#endif

