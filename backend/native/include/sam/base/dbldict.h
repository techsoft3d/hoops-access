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
/* IntDict object */

#ifndef DBLDICT_DEF
#define DBLDICT_DEF

#include "sam/base/basedefs.h"

#define DOUBLE_DICTIONARY_MIN_STORAGE 128

typedef struct _DblDict_Entry {
    Vchar* name;
    Vdouble val;
} vsy_DblDict_Entry;

struct vsy_DblDict {
    Vint ierr;
    Vint iter;
    Vchar** csort;
    Vint* isort;
    Vint numelt;
    Vint highwater;
    Vint vsize;
    vsy_DblDict_Entry* vec;
    Vdouble undefined;
#ifdef __cplusplus
  public:
    VKI_EXTERN
    vsy_DblDict(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vsy_DblDict(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void Def(Vint);
    VKI_EXTERN void
    Inq(Vint*) const;
    VKI_EXTERN void
    Count(Vint*) const;
    VKI_EXTERN void
    Insert(const Vchar*, Vdouble);
    VKI_EXTERN void
    Lookup(const Vchar*, Vdouble*) const;
    VKI_EXTERN void
    Clear();
    VKI_EXTERN void
    InitIter();
    VKI_EXTERN void
    NextIter(Vchar**, Vdouble*);
    VKI_EXTERN void
    InitIterOrder();
    VKI_EXTERN void
    Print();
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vsy_DblDict*
vsy_DblDictBegin(void);
VKI_EXTERN void
vsy_DblDict_Construct(vsy_DblDict* p);
VKI_EXTERN void
vsy_DblDictEnd(vsy_DblDict* p);
VKI_EXTERN void
vsy_DblDict_Destruct(vsy_DblDict* p);
VKI_EXTERN Vint
vsy_DblDictError(vsy_DblDict* p);
VKI_EXTERN void
vsy_DblDictDef(vsy_DblDict* p, Vint numint);
VKI_EXTERN void
vsy_DblDictInq(const vsy_DblDict* p, Vint* nument);
VKI_EXTERN void
vsy_DblDictCount(const vsy_DblDict* p, Vint* num);
VKI_EXTERN void
vsy_DblDictInsert(vsy_DblDict* p, const Vchar* name, Vdouble value);
VKI_EXTERN void
vsy_DblDictLookup(const vsy_DblDict* p, const Vchar* name, Vdouble* value);
VKI_EXTERN void
vsy_DblDictClear(vsy_DblDict* p);
VKI_EXTERN void
vsy_DblDictInitIter(vsy_DblDict* p);
VKI_EXTERN void
vsy_DblDictNextIter(vsy_DblDict* p, Vchar** name, Vdouble* value);
VKI_EXTERN void
vsy_DblDictInitIterOrder(vsy_DblDict* p);
VKI_EXTERN void
vsy_DblDictPrint(vsy_DblDict* p);

#ifdef __cplusplus
}
#endif

#endif
