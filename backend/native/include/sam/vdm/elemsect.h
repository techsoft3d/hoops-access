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
/* Section helper object */
#ifndef ELEMSECT_DEF
#define ELEMSECT_DEF

#include <stdio.h>

#include "sam/base/base.h"
#include "sam/vdm/vdmdefs.h"

struct vdm_ElemSect {
    Vint ierr;
    Vint numel;
    Vint* sect;
    Vint* layp;
    Vlong* ptr;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_ElemSect(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_ElemSect(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void Def(Vint);
    VKI_EXTERN void
    Inq(Vint*);
    VKI_EXTERN void
    SetPtr(Vint*, Vint*);
    VKI_EXTERN void
    NumSection(Vint, Vint*);
    VKI_EXTERN void
    LayPos(Vint, Vint, Vint*, Vint*);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_ElemSect*
vdm_ElemSectBegin(void);
VKI_EXTERN void
vdm_ElemSect_Construct(vdm_ElemSect* p);
VKI_EXTERN void
vdm_ElemSectEnd(vdm_ElemSect* p);
VKI_EXTERN void
vdm_ElemSect_Destruct(vdm_ElemSect* p);
VKI_EXTERN Vint
vdm_ElemSectError(vdm_ElemSect* p);
VKI_EXTERN void
vdm_ElemSectDef(vdm_ElemSect* p, Vint numel);
VKI_EXTERN void
vdm_ElemSectInq(vdm_ElemSect* p, Vint* numel);
VKI_EXTERN void
vdm_ElemSectSetPtr(vdm_ElemSect* p, Vint* sect, Vint* layp);
VKI_EXTERN void
vdm_ElemSectNumSection(vdm_ElemSect* p, Vint in, Vint* numsec);
VKI_EXTERN void
vdm_ElemSectLayPos(vdm_ElemSect* p, Vint in, Vint isec, Vint* ipos, Vint* ilay);

#ifdef __cplusplus
}
#endif

#endif
