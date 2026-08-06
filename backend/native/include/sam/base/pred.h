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
/* Pred object */

#ifndef PRED_DEF
#define PRED_DEF

#include "sam/base/basedefs.h"

struct vsy_Pred {
    Vint ierr;
    Vint fpupush;
    int cword;
    Vdouble splitter; /* = 2^ceiling(p / 2) + 1 Used to split floats in half. */
    Vdouble epsilon;  /* = 2^(-p).  Used to estimate roundoff errors. */
    /* A set of coefficients used to calculate maximum roundoff errors. */
    Vdouble resulterrbound;
    Vdouble ccwerrboundA, ccwerrboundB, ccwerrboundC;
    Vdouble o3derrboundA, o3derrboundB, o3derrboundC;
    Vdouble iccerrboundA, iccerrboundB, iccerrboundC;
    Vdouble isperrboundA, isperrboundB, isperrboundC;
    Vdouble o3dstaticfilter;
    Vdouble ispstaticfilter;
    Vint use_inexact_arith;
    Vint use_static_filter;
    Vint testzerodet;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vsy_Pred(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vsy_Pred(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void TetGen(Vint, Vint, Vdouble, Vdouble, Vdouble);
    VKI_EXTERN void TestZeroDet(Vint);
    VKI_EXTERN void
    PushFPU();
    VKI_EXTERN void
    PopFPU();
    VKI_EXTERN Vdouble
    Orient2d(Vdouble*, Vdouble*, Vdouble*);
    VKI_EXTERN Vdouble
    Orient2dExact(Vdouble*, Vdouble*, Vdouble*);
    VKI_EXTERN Vdouble
    Orient3d(Vdouble*, Vdouble*, Vdouble*, Vdouble*);
    VKI_EXTERN Vdouble
    Orient3dExact(Vdouble*, Vdouble*, Vdouble*, Vdouble*);
    VKI_EXTERN Vdouble
    Incircle(Vdouble*, Vdouble*, Vdouble*, Vdouble*);
    VKI_EXTERN Vdouble
    Insphere(Vdouble*, Vdouble*, Vdouble*, Vdouble*, Vdouble*);
    VKI_EXTERN void IntersectLineTri(Vdouble[3][3], Vdouble[2][3], Vint*, Vint*, Vint*);
    VKI_EXTERN void IntersectLineLine(Vdouble[2][2], Vdouble[2][2], Vint*, Vint*, Vint*);
    VKI_EXTERN Vdouble
    Orient4d(Vdouble*, Vdouble*, Vdouble*, Vdouble*, Vdouble*, Vdouble, Vdouble, Vdouble, Vdouble, Vdouble);
    VKI_EXTERN Vdouble
    Orient4dExact(Vdouble*, Vdouble*, Vdouble*, Vdouble*, Vdouble* pe, Vdouble, Vdouble, Vdouble, Vdouble, Vdouble);
    VKI_EXTERN void
    Exact(Vint*);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vsy_Pred*
vsy_PredBegin(void);
VKI_EXTERN void
vsy_Pred_Construct(vsy_Pred* p);
VKI_EXTERN void
vsy_PredEnd(vsy_Pred* p);
VKI_EXTERN void
vsy_Pred_Destruct(vsy_Pred* p);
VKI_EXTERN Vint
vsy_PredError(vsy_Pred* p);
VKI_EXTERN void
vsy_PredTetGen(vsy_Pred* p, Vint noexact, Vint nofilter, Vdouble maxx, Vdouble maxy, Vdouble maxz);
VKI_EXTERN void
vsy_PredTestZeroDet(vsy_Pred* p, Vint flag);
VKI_EXTERN void
vsy_PredPushFPU(vsy_Pred* p);
VKI_EXTERN void
vsy_PredPopFPU(vsy_Pred* p);
VKI_EXTERN Vdouble
vsy_PredOrient2d(vsy_Pred* p, Vdouble* a, Vdouble* b, Vdouble* c);
VKI_EXTERN Vdouble
vsy_PredOrient2dExact(vsy_Pred* p, Vdouble* pa, Vdouble* pb, Vdouble* pc);
VKI_EXTERN Vdouble
vsy_PredOrient3d(vsy_Pred* p, Vdouble* b, Vdouble* a, Vdouble* c, Vdouble* d);
VKI_EXTERN Vdouble
vsy_PredOrient3dExact(vsy_Pred* p, Vdouble* pb, Vdouble* pa, Vdouble* pc, Vdouble* pd);
VKI_EXTERN Vdouble
vsy_PredIncircle(vsy_Pred* p, Vdouble* a, Vdouble* b, Vdouble* c, Vdouble* d);
VKI_EXTERN Vdouble
vsy_PredInsphere(vsy_Pred* p, Vdouble* a, Vdouble* b, Vdouble* c, Vdouble* d, Vdouble* e);
VKI_EXTERN void
vsy_PredIntersectLineTri(vsy_Pred* p, Vdouble xt[3][3], Vdouble xl[2][3], Vint* code, Vint* ient, Vint* ierr);
VKI_EXTERN void
vsy_PredIntersectLineLine(vsy_Pred* p, Vdouble xl1[2][2], Vdouble xl2[2][2], Vint* code, Vint* ient, Vint* ierr);
VKI_EXTERN Vdouble
vsy_PredOrient4d(vsy_Pred* p, Vdouble* pa, Vdouble* pb, Vdouble* pc, Vdouble* pd, Vdouble* pe, Vdouble aheight, Vdouble bheight,
                 Vdouble cheight, Vdouble dheight, Vdouble eheight);
VKI_EXTERN Vdouble
vsy_PredOrient4dExact(vsy_Pred* p, Vdouble* pa, Vdouble* pb, Vdouble* pc, Vdouble* pd, Vdouble* pe, Vdouble aheight,
                      Vdouble bheight, Vdouble cheight, Vdouble dheight, Vdouble eheight);
VKI_EXTERN void
vsy_PredExact(vsy_Pred* p, Vint* pass);

#ifdef __cplusplus
}
#endif

#endif
