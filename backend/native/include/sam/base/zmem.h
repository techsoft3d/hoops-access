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
 
#ifndef ZMEM_DEF
#define ZMEM_DEF
#include "sam/base/basedefs.h"
#define ZMEM_BUFFER 1
#define ZMEM_FINISH 2
struct vsy_ZMem { Vint ierr;Vint init;Vint level;Vint
repeat;Vlong loc;void* z_stream;
#ifdef __cplusplus
public: VKI_EXTERN vsy_ZMem(void);VKI_EXTERN void* operator
new(size_t);VKI_EXTERN ~vsy_ZMem(void);VKI_EXTERN void
operator delete(void*);VKI_EXTERN Vint Error();VKI_EXTERN
void Compress(Vint,Vlong,Vchar[],Vlong,Vchar[],Vlong*,
Vint*);VKI_EXTERN void Uncompress(Vint,Vlong,Vchar[],
Vlong,Vchar[],Vlong*,Vint*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_ZMem* vsy_ZMemBegin(void);VKI_EXTERN
void vsy_ZMem_Construct(vsy_ZMem* p);VKI_EXTERN void
vsy_ZMemEnd(vsy_ZMem* p);VKI_EXTERN void vsy_ZMem_Destruct(vsy_ZMem*
p);VKI_EXTERN Vint vsy_ZMemError(vsy_ZMem* p);VKI_EXTERN
void vsy_ZMemCompress(vsy_ZMem* p,Vint mode,Vlong nin,
Vchar in[],Vlong nout,Vchar out[],Vlong* length,Vint*
repeat);VKI_EXTERN void vsy_ZMemUncompress(vsy_ZMem*
p,Vint mode,Vlong nin,Vchar in[],Vlong nout,Vchar out[],
Vlong* length,Vint* repeat);
#ifdef __cplusplus
}
#endif
#endif

