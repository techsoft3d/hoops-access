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
 
#ifndef STLFWT_DEF
#define STLFWT_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
typedef struct vis_STLFwt { Vint ierr;FILE* fd;vis_GridFun*
gf;Vint numnp;Vint numel;Vint type;vis_Connect* connect;
}vis_STLFwt;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_STLFwt* vis_STLFwtBegin(void);VKI_EXTERN
void vis_STLFwt_Construct(vis_STLFwt* p);VKI_EXTERN
void vis_STLFwtEnd(vis_STLFwt* p);VKI_EXTERN void vis_STLFwt_Destruct(vis_STLFwt*
p);VKI_EXTERN Vint vis_STLFwtError(vis_STLFwt* p);VKI_EXTERN
void vis_STLFwtSetFileType(vis_STLFwt* p,Vint type);
VKI_EXTERN void vis_STLFwtWriteModel(vis_STLFwt* p,
vis_Model* model,const Vchar* path);
#ifdef __cplusplus
}
#endif
#endif

