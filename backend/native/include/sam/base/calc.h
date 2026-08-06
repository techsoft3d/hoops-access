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
 
#ifndef CALC_DEF
#define CALC_DEF
#include "sam/base/basedefs.h"
#include "sam/base/list.h"
#include "sam/base/stack.h"
#define CALC_INFIX 1
#define CALC_POSTFIX 2
 
#define CALC_LPAREN 1
#define CALC_RPAREN 2
#define CALC_PLUS 3
#define CALC_MINUS 4
#define CALC_ADD 5
#define CALC_SUB 6
#define CALC_DIV 7
#define CALC_MUL 8
#define CALC_POWER 9
#define CALC_INTEGER 10
#define CALC_REAL 11
#define CALC_STRING 12
#define CALC_ABS 13
#define CALC_ACOS 14
#define CALC_ASIN 15
#define CALC_ATAN 16
#define CALC_COS 17
#define CALC_LOG 18
#define CALC_LOG10 19
#define CALC_POW 20
#define CALC_SIN 21
#define CALC_SQRT 22
#define CALC_TAN 23
#define CALC_INT 24
#define CALC_FLOAT 25
#define CALC_STR 26
#define CALC_MAX_TYPE 27
#define CALC_PARSEERROR 1
#define CALC_UNMATCHEDPAREN 1
#define CALC_INSUFFICIENTOPERANDS 2
#define CALC_ILLEGALOPERAND 3
#define CALC_MAX_TOKENS 100
typedef struct vsy_Calc_Token { Vint type;union { Vint
vali;Vdouble vald;Vchar valc[81];}val;}vsy_Calc_Token;
struct vsy_Calc { Vint ierr;Vint typefix;Vint nt;Vint
ns;Vint parserr;vsy_Calc_Token tokens[CALC_MAX_TOKENS];
vsy_List* inp;vsy_Stack* tmp;vsy_List* out;
#ifdef __cplusplus
public: VKI_EXTERN vsy_Calc(void);VKI_EXTERN void* operator
new(size_t);VKI_EXTERN ~vsy_Calc(void);VKI_EXTERN void
operator delete(void*);VKI_EXTERN Vint Error();VKI_EXTERN
void Def(Vint);VKI_EXTERN void Inq(Vint*)const;VKI_EXTERN
void Init();VKI_EXTERN void SetToken(Vint,Vint,Vdouble,
Vchar*);VKI_EXTERN void Term();VKI_EXTERN void GetEvalType(Vint*);
VKI_EXTERN void Eval(Vint,Vint*,Vdouble*,Vchar[]);VKI_EXTERN
void GetInteger(Vint,Vint*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_Calc* vsy_CalcBegin(void);VKI_EXTERN
void vsy_Calc_Construct(vsy_Calc* p);VKI_EXTERN void
vsy_CalcEnd(vsy_Calc* p);VKI_EXTERN void vsy_Calc_Destruct(vsy_Calc*
p);VKI_EXTERN Vint vsy_CalcError(vsy_Calc* p);VKI_EXTERN
void vsy_CalcDef(vsy_Calc* p,Vint type);VKI_EXTERN void
vsy_CalcInq(const vsy_Calc* p,Vint* type);VKI_EXTERN
void vsy_CalcInit(vsy_Calc* p);VKI_EXTERN void vsy_CalcSetToken(vsy_Calc*
p,Vint type,Vint vali,Vdouble vald,Vchar* valc);VKI_EXTERN
void vsy_CalcTerm(vsy_Calc* p);VKI_EXTERN void vsy_CalcGetEvalType(vsy_Calc*
p,Vint* type);VKI_EXTERN void vsy_CalcEval(vsy_Calc*
p,Vint type,Vint* vali,Vdouble* vald,Vchar valc[]);
VKI_EXTERN void vsy_CalcGetInteger(vsy_Calc* p,Vint
type,Vint* iparam);
#ifdef __cplusplus
}
#endif
#endif

