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
/* Element Check object */

#ifndef MODELCHK_DEF
#define MODELCHK_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/model.h"

/* action definitions */
#define VIS_MODELCHK_ACTION_CHECK   1
#define VIS_MODELCHK_ACTION_PROCESS 2

/* HashTable names */
#define VIS_MODELCHK_CIRC_DEPENDENCY 1

struct vis_ModelChk {
    Vint ierr;
    vsy_HashTable* circularDependencyPerSProp;
    vis_Model* model;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vis_ModelChk(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vis_ModelChk(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void
    Def(vis_Model*);
    VKI_EXTERN Vint MPC(Vint, Vint);
    VKI_EXTERN void
    GetHashTable(Vint, vsy_HashTable**);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_ModelChk*
vis_ModelChkBegin(void);
VKI_EXTERN void
vis_ModelChk_Construct(vis_ModelChk* p);
VKI_EXTERN void
vis_ModelChkEnd(vis_ModelChk* p);
VKI_EXTERN void
vis_ModelChk_Destruct(vis_ModelChk* p);
VKI_EXTERN Vint
vis_ModelChkError(vis_ModelChk* p);
VKI_EXTERN void
vis_ModelChkDef(vis_ModelChk* p, vis_Model* model);
VKI_EXTERN Vint
vis_ModelChkMPC(vis_ModelChk* p, Vint MPCtype, Vint action);
VKI_EXTERN void
vis_ModelChkGetHashTable(vis_ModelChk* p, Vint type, vsy_HashTable** hashtable);

#ifdef __cplusplus
}
#endif

#endif
