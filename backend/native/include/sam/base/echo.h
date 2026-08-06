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
/* Echo object */

#ifndef ECHO_DEF
#define ECHO_DEF

#include <stdio.h>
#include "sam/base/basedefs.h"
#include "sam/base/intdict.h"

/* defines */
#define ECHO_WRITE 1
#define ECHO_READ  2

#define ECHO_MAX_ARGS 5

struct vsy_Echo {
    Vint ierr;
    Vint isopen;
    Vint nobj;
    Vint mode;
    Vint swap;
    Vchar filename[256];
    Vchar method[256];
    FILE* f;
    vsy_IntDict* dict;
    fpos_t initpos;
    Vint init;
    Vint otype;
    Vint oid;
    Vint nargs;
    Vint type[ECHO_MAX_ARGS];
    Vint length[ECHO_MAX_ARGS];
    Vint maxf[ECHO_MAX_ARGS];
    Vint maxd[ECHO_MAX_ARGS];
    Vint maxi[ECHO_MAX_ARGS];
    Vint maxo[ECHO_MAX_ARGS];
    Vfloat* paramf[ECHO_MAX_ARGS];
    Vdouble* paramd[ECHO_MAX_ARGS];
    Vint* parami[ECHO_MAX_ARGS];
    Vint* paramoid[ECHO_MAX_ARGS];
    Vchar paramc[ECHO_MAX_ARGS][256];
    vsy_IntHash* oh;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vsy_Echo(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vsy_Echo(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void
    Open(Vchar*, Vint);
    VKI_EXTERN void
    Close();
    VKI_EXTERN void
    Write0(Vint, Vobject*, Vchar[]);
    VKI_EXTERN void
    Write1(Vint, Vobject*, Vchar[], Vint, Vint, void*);
    VKI_EXTERN void
    Write2(Vint, Vobject*, Vchar[], Vint, Vint, void*, Vint, Vint, void*);
    VKI_EXTERN void
    Write3(Vint, Vobject*, Vchar[], Vint, Vint, void*, Vint, Vint, void*, Vint, Vint, void*);
    VKI_EXTERN void
    Write4(Vint, Vobject*, Vchar[], Vint, Vint, void*, Vint, Vint, void*, Vint, Vint, void*, Vint, Vint, void*);
    VKI_EXTERN void
    Write5(Vint, Vobject*, Vchar[], Vint, Vint, void*, Vint, Vint, void*, Vint, Vint, void*, Vint, Vint, void*, Vint, Vint,
           void*);
    VKI_EXTERN void
    InitIter();
    VKI_EXTERN void
    NextIter(Vint*, Vint*, Vchar[]);
    VKI_EXTERN void
    GetArg(Vint, Vint*, Vint*, void**);
    VKI_EXTERN void
    NumArgs(Vint*);
    VKI_EXTERN void
    GetLength(Vint, Vint*);
    VKI_EXTERN void InsertObject(Vint, Vint);
    VKI_EXTERN void
    LookupObject(Vint, Vint*);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vsy_Echo*
vsy_EchoBegin(void);
VKI_EXTERN void
vsy_Echo_Construct(vsy_Echo* p);
VKI_EXTERN void
vsy_EchoEnd(vsy_Echo* p);
VKI_EXTERN void
vsy_Echo_Destruct(vsy_Echo* p);
VKI_EXTERN Vint
vsy_EchoError(vsy_Echo* p);
VKI_EXTERN void
vsy_EchoOpen(vsy_Echo* p, Vchar* filename, Vint mode);
VKI_EXTERN void
vsy_EchoClose(vsy_Echo* p);
VKI_EXTERN void
vsy_EchoWrite0(vsy_Echo* p, Vint objtype, Vobject* obj, Vchar method[]);
VKI_EXTERN void
vsy_EchoWrite1(vsy_Echo* p, Vint objtype, Vobject* obj, Vchar method[], Vint type, Vint n, void* ptr);
VKI_EXTERN void
vsy_EchoWrite2(vsy_Echo* p, Vint objtype, Vobject* obj, Vchar method[], Vint type1, Vint n1, void* ptr1, Vint type2, Vint n2,
               void* ptr2);
VKI_EXTERN void
vsy_EchoWrite3(vsy_Echo* p, Vint objtype, Vobject* obj, Vchar method[], Vint type1, Vint n1, void* ptr1, Vint type2, Vint n2,
               void* ptr2, Vint type3, Vint n3, void* ptr3);
VKI_EXTERN void
vsy_EchoWrite4(vsy_Echo* p, Vint objtype, Vobject* obj, Vchar method[], Vint type1, Vint n1, void* ptr1, Vint type2, Vint n2,
               void* ptr2, Vint type3, Vint n3, void* ptr3, Vint type4, Vint n4, void* ptr4);
VKI_EXTERN void
vsy_EchoWrite5(vsy_Echo* p, Vint objtype, Vobject* obj, Vchar method[], Vint type1, Vint n1, void* ptr1, Vint type2, Vint n2,
               void* ptr2, Vint type3, Vint n3, void* ptr3, Vint type4, Vint n4, void* ptr4, Vint type5, Vint n5, void* ptr5);
VKI_EXTERN void
vsy_EchoInitIter(vsy_Echo* p);
VKI_EXTERN void
vsy_EchoNextIter(vsy_Echo* p, Vint* otype, Vint* oid, Vchar method[]);
VKI_EXTERN void
vsy_EchoGetArg(vsy_Echo* p, Vint id, Vint* type, Vint* length, void** ptr);
VKI_EXTERN void
vsy_EchoNumArgs(vsy_Echo* p, Vint* nargs);
VKI_EXTERN void
vsy_EchoGetLength(vsy_Echo* p, Vint id, Vint* length);
VKI_EXTERN void
vsy_EchoInsertObject(vsy_Echo* p, Vint id, Vint type);
VKI_EXTERN void
vsy_EchoLookupObject(vsy_Echo* p, Vint id, Vint* type);

#ifdef __cplusplus
}
#endif

#endif
