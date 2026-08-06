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
 
#ifndef BANDOPT_DEF
#define BANDOPT_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/gridfun.h"
#include "sam/vis/idtran.h"
struct vis_BandOpt { Vint ierr;vis_GridFun* gf;
#ifdef __cplusplus
public: VKI_EXTERN vis_BandOpt(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_BandOpt(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_BandOpt* vis_BandOptBegin(void);VKI_EXTERN
void vis_BandOpt_Construct(vis_BandOpt* bandopt);VKI_EXTERN
void vis_BandOptEnd(vis_BandOpt* p);VKI_EXTERN void
vis_BandOpt_Destruct(vis_BandOpt* bandopt);VKI_EXTERN
Vint vis_BandOptError(vis_BandOpt* bandopt);VKI_EXTERN
void vis_BandOptSetObject(vis_BandOpt* bandopt,Vint
object_type,Vobject* object);VKI_EXTERN void vis_BandOptOptimize(vis_BandOpt*
bandopt,Vint type,Vint* renumber,vis_IdTran* idtran);
#ifdef __cplusplus
}
#endif
#endif

