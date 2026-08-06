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
 
#ifndef OBJFWT_DEF
#define OBJFWT_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
typedef struct vis_OBJFwt { Vint ierr;FILE* fd;vis_GridFun*
gf;Vint numnp;Vint numel;vis_Connect* connect;}vis_OBJFwt;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_OBJFwt* vis_OBJFwtBegin(void);VKI_EXTERN
void vis_OBJFwt_Construct(vis_OBJFwt* p);VKI_EXTERN
void vis_OBJFwtEnd(vis_OBJFwt* p);VKI_EXTERN void vis_OBJFwt_Destruct(vis_OBJFwt*
p);VKI_EXTERN Vint vis_OBJFwtError(vis_OBJFwt* p);VKI_EXTERN
void vis_OBJFwtWriteModel(vis_OBJFwt* p,vis_Model* model,
const Vchar* path);
#ifdef __cplusplus
}
#endif
#endif

