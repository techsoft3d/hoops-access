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
 
#ifndef RANDOM_DEF
#define RANDOM_DEF
#include "sam/base/basedefs.h"
struct vsy_Random { Vint ierr;Vint seed;
#ifdef __cplusplus
public: VKI_EXTERN vsy_Random(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_Random(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Init(Vint);VKI_EXTERN void Number(Vfloat*);
VKI_EXTERN void Integer(Vint*);VKI_EXTERN Vint Rand(void);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_Random* vsy_RandomBegin(void);VKI_EXTERN
void vsy_Random_Construct(vsy_Random* p);VKI_EXTERN
void vsy_RandomEnd(vsy_Random* p);VKI_EXTERN void vsy_Random_Destruct(vsy_Random*
p);VKI_EXTERN Vint vsy_RandomError(vsy_Random* p);VKI_EXTERN
void vsy_RandomInit(vsy_Random* p,Vint seed);VKI_EXTERN
void vsy_RandomNumber(vsy_Random* p,Vfloat* number);
VKI_EXTERN void vsy_RandomInteger(vsy_Random* p,Vint*
number);VKI_EXTERN Vint vsy_RandomRand(vsy_Random* p);
#ifdef __cplusplus
}
#endif
#endif

