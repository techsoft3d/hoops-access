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
 
#ifndef PROPSET_DEF
#define PROPSET_DEF
#include "sam/base/basedefs.h"
#include "sam/base/dictionary.h"
struct vsy_PropSet { Vint ierr;vsy_Dictionary* dict;
#ifdef __cplusplus
public: VKI_EXTERN vsy_PropSet(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_PropSet(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(Vint);VKI_EXTERN void Inq(Vint*)
const;VKI_EXTERN void Count(Vint*)const;VKI_EXTERN void
Inserti(const Vchar*,Vint);VKI_EXTERN void Insertiv(const
Vchar*,Vint,Vint[]);VKI_EXTERN void Insertf(const Vchar*,
Vfloat);VKI_EXTERN void Insertfv(const Vchar*,Vint,
Vfloat[]);VKI_EXTERN void Insertd(const Vchar*,Vdouble);
VKI_EXTERN void Insertdv(const Vchar*,Vint,Vdouble[]);
VKI_EXTERN void Insertl(const Vchar*,Vlong);VKI_EXTERN
void Insertlv(const Vchar*,Vint,Vlong[]);VKI_EXTERN
void Insertp(const Vchar*,Vobject*);VKI_EXTERN void
Insertpv(const Vchar*,Vint,Vobject*[]);VKI_EXTERN void
Insertc(const Vchar*,Vchar*);VKI_EXTERN void LookupInteger(const
Vchar*,Vint*)const;VKI_EXTERN void LookupFloat(const
Vchar*,Vfloat*)const;VKI_EXTERN void LookupDouble(const
Vchar*,Vdouble*)const;VKI_EXTERN void LookupLong(const
Vchar*,Vlong*)const;VKI_EXTERN void LookupString(const
Vchar*,Vchar[])const;VKI_EXTERN void LookupObject(const
Vchar*,Vobject**)const;VKI_EXTERN void Lookup(const
Vchar*,Vint*,Vint*,Vint*)const;VKI_EXTERN void Remove(const
Vchar*);VKI_EXTERN void Clear();VKI_EXTERN void InitIter();
VKI_EXTERN void NextIter(Vchar**);VKI_EXTERN void Copy(vsy_PropSet*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_PropSet* vsy_PropSetBegin(void);VKI_EXTERN
void vsy_PropSet_Construct(vsy_PropSet* p);VKI_EXTERN
void vsy_PropSetEnd(vsy_PropSet* p);VKI_EXTERN void
vsy_PropSet_Destruct(vsy_PropSet* p);VKI_EXTERN Vint
vsy_PropSetError(vsy_PropSet* p);VKI_EXTERN void vsy_PropSetDef(vsy_PropSet*
p,Vint numobj);VKI_EXTERN void vsy_PropSetInq(const
vsy_PropSet* p,Vint* nument);VKI_EXTERN void vsy_PropSetCount(const
vsy_PropSet* p,Vint* num);VKI_EXTERN void vsy_PropSetInserti(vsy_PropSet*
p,const Vchar* name,Vint v);VKI_EXTERN void vsy_PropSetInsertiv(vsy_PropSet*
p,const Vchar* name,Vint num,Vint v[]);VKI_EXTERN void
vsy_PropSetInsertf(vsy_PropSet* p,const Vchar* name,
Vfloat v);VKI_EXTERN void vsy_PropSetInsertfv(vsy_PropSet*
p,const Vchar* name,Vint num,Vfloat v[]);VKI_EXTERN
void vsy_PropSetInsertd(vsy_PropSet* p,const Vchar*
name,Vdouble v);VKI_EXTERN void vsy_PropSetInsertdv(vsy_PropSet*
p,const Vchar* name,Vint num,Vdouble v[]);VKI_EXTERN
void vsy_PropSetInsertl(vsy_PropSet* p,const Vchar*
name,Vlong v);VKI_EXTERN void vsy_PropSetInsertlv(vsy_PropSet*
p,const Vchar* name,Vint num,Vlong v[]);VKI_EXTERN void
vsy_PropSetInsertp(vsy_PropSet* p,const Vchar* name,
Vobject* v);VKI_EXTERN void vsy_PropSetInsertpv(vsy_PropSet*
p,const Vchar* name,Vint num,Vobject* v[]);VKI_EXTERN
void vsy_PropSetInsertc(vsy_PropSet* p,const Vchar*
name,Vchar* prop);VKI_EXTERN void vsy_PropSetLookupInteger(const
vsy_PropSet* p,const Vchar* name,Vint* v);VKI_EXTERN
void vsy_PropSetLookupFloat(const vsy_PropSet* p,const
Vchar* name,Vfloat* v);VKI_EXTERN void vsy_PropSetLookupDouble(const
vsy_PropSet* p,const Vchar* name,Vdouble* prop);VKI_EXTERN
void vsy_PropSetLookupLong(const vsy_PropSet* p,const
Vchar* name,Vlong* v);VKI_EXTERN void vsy_PropSetLookupString(const
vsy_PropSet* p,const Vchar* name,Vchar v[]);VKI_EXTERN
void vsy_PropSetLookupObject(const vsy_PropSet* p,const
Vchar* name,Vobject** v);VKI_EXTERN void vsy_PropSetLookup(const
vsy_PropSet* p,const Vchar* name,Vint* type,Vint* num,
Vint* size);VKI_EXTERN void vsy_PropSetRemove(vsy_PropSet*
p,const Vchar* name);VKI_EXTERN void vsy_PropSetClear(vsy_PropSet*
p);VKI_EXTERN void vsy_PropSetInitIter(vsy_PropSet*
p);VKI_EXTERN void vsy_PropSetNextIter(vsy_PropSet*
p,Vchar** name);VKI_EXTERN void vsy_PropSetCopy(vsy_PropSet*
p,vsy_PropSet* q);
#ifdef __cplusplus
}
#endif
#endif

