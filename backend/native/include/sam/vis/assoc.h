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
 
#ifndef ASSOC_DEF
#define ASSOC_DEF
#include "sam/base/basedefs.h"
typedef struct vis_Assoc { Vint ierr;Vint nument;Vint
maxent;Vint assize;Vint asconst;Vschar* aschar;Vshort*
asshort;Vint* asint;Vint asfsta;Vint asfnum;Vint* asmsta;
Vint asmmax;Vint (*asmval)[2];}vis_Assoc;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_Assoc* vis_AssocBegin(void);VKI_EXTERN
void vis_AssocEnd(vis_Assoc* p);VKI_EXTERN Vint vis_AssocError(vis_Assoc*
p);VKI_EXTERN void vis_AssocDef(vis_Assoc* p,Vint nument);
VKI_EXTERN void vis_AssocInq(vis_Assoc* p,Vint* nument);
VKI_EXTERN void vis_AssocSet(vis_Assoc* p,Vint index,
Vint aid);VKI_EXTERN void vis_AssocSetConst(vis_Assoc*
p,Vint num,Vint aid);VKI_EXTERN void vis_AssocSetArray(vis_Assoc*
p,Vint num,Vint aid[]);VKI_EXTERN Vint vis_AssocOne(const
vis_Assoc* p,Vint id);VKI_EXTERN void vis_AssocArray(const
vis_Assoc* p,Vint num,Vint aids[]);VKI_EXTERN void vis_AssocCompact(vis_Assoc*
p);VKI_EXTERN void vis_AssocAdd(vis_Assoc* p,Vint index,
Vint aid);VKI_EXTERN void vis_AssocUni(vis_Assoc* p,
Vint index,Vint aid);VKI_EXTERN void vis_AssocDel(vis_Assoc*
p,Vint index);VKI_EXTERN void vis_AssocNum(vis_Assoc*
p,Vint index,Vint* num);VKI_EXTERN void vis_AssocAll(vis_Assoc*
p,Vint index,Vint* num,Vint aids[]);VKI_EXTERN void
vis_AssocPrint(vis_Assoc* p);
#ifdef __cplusplus
}
#endif
#endif

