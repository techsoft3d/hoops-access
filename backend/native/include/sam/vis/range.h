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
 
#ifndef RANGE_DEF
#define RANGE_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/gridfun.h"
#include "sam/vis/idtran.h"
#include "sam/vis/group.h"
#include "sam/vis/state.h"
#include "sam/vis/space.h"
#define RANGE_MAX_STATES 16
typedef struct rangeParams { Vint line;Vint plane;}
rangeParams;typedef struct RangeStateList { Vint state_id;
Vfloat *min_vals,*max_vals;vis_State* state;}RangeStateList;
struct vis_Range { Vint ierr;vis_GridFun* gf;vis_Space*
space_obj;RangeStateList state_ranges[RANGE_MAX_STATES
+ 1];
#ifdef __cplusplus
public: VKI_EXTERN vis_Range(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_Range(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void SetObject(Vint,Vobject*);VKI_EXTERN
void SetState(Vint,vis_State*);VKI_EXTERN void SurfGroup(Vint,
Vfloat,vis_Group*,vis_Group*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_Range* vis_RangeBegin(void);VKI_EXTERN
void vis_Range_Construct(vis_Range* p);VKI_EXTERN void
vis_RangeEnd(vis_Range* p);VKI_EXTERN void vis_Range_Destruct(vis_Range*
p);VKI_EXTERN Vint vis_RangeError(vis_Range* p);VKI_EXTERN
void vis_RangeSetObject(vis_Range* p,Vint objecttype,
Vobject* object);VKI_EXTERN void vis_RangeSetState(vis_Range*
p,Vint index,vis_State* state);VKI_EXTERN void vis_RangeSurfGroup(vis_Range*
p,Vint index,Vfloat value,vis_Group* groupdst,vis_Group*
group);
#ifdef __cplusplus
}
#endif
#endif

