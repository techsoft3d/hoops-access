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
 
#ifndef CGNSDAT_DEF
#define CGNSDAT_DEF
#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/libraries/cgns/cgnsvlib.h"
typedef struct vdm_CGNSDat { Vint cur;Vint nentries;
Vint ncomp;Vint id1;Vint id2;Vint id3;vsy_IntVec* zones;
vsy_IntVec* sols;vsy_IntVec* fields;vsy_IntVec* icmp;
vdm_CGNSVLib** libs;}vdm_CGNSDat;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_CGNSDat* vdm_CGNSDatBegin(void);VKI_EXTERN
void vdm_CGNSDatEnd(vdm_CGNSDat* p);VKI_EXTERN void
vdm_CGNSDatDef(vdm_CGNSDat* p,Vint ncomp,Vint id1,Vint
id2,Vint id3);VKI_EXTERN void vdm_CGNSDatInq(vdm_CGNSDat*
p,Vint* ncomp,Vint* id1,Vint* id2,Vint* id3);VKI_EXTERN
void vdm_CGNSDatAdd(vdm_CGNSDat* p,vdm_CGNSVLib* q,
Vint zone,Vint sol,Vint field,Vint icmp);VKI_EXTERN
void vdm_CGNSDatInitIter(vdm_CGNSDat* p);VKI_EXTERN
void vdm_CGNSDatNextIter(vdm_CGNSDat* p,vdm_CGNSVLib**
q,Vint* zone,Vint* sol,Vint* field,Vint* icmp);
#ifdef __cplusplus
}
#endif
#endif

