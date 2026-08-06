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
 
#ifndef GEOMFUN_DEF
#define GEOMFUN_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#define GEOMFUN_OPEN 1
#define GEOMFUN_CLOSE 2
#define GEOMFUN_MODELLER 4
#define GEOMFUN_NUMBODY 5
#define GEOMFUN_BODY 6
#define GEOMFUN_FACE 7
#define GEOMFUN_EDGE 8
#define GEOMFUN_NODE 9
#define GEOMFUN_FACELOOP 10
#define GEOMFUN_EXTENT 11
#define GEOMFUN_EDGEPOINT 12
#define GEOMFUN_EDGENEAREST 13
#define GEOMFUN_FACEPOINT 14
#define GEOMFUN_FACENEAREST 15
#define GEOMFUN_FACENORMAL 16
#define GEOMFUN_ERROR 17
#define GEOMFUN_MAX 18
struct vis_GeomFun { Vint ierr;Vobject* obj;void (*fun[1])(void);
void (*open)(Vobject*,Vchar*,Vchar*,Vint);void (*close)(Vobject*);
void (*dummy3)(void);void (*modeller)(Vobject*,Vchar*);
void (*numbody)(Vobject*,Vint*);void (*body)(Vobject*,
Vint,Vint*,Vint*,Vint*);void (*face)(Vobject*,Vint,
Vint,Vdouble[2][2],Vint*);void (*edge)(Vobject*,Vint,
Vint,Vdouble[2],Vint[2]);void (*node)(Vobject*,Vint,
Vint,Vdouble[3]);void (*faceloop)(Vobject*,Vint,Vint,
Vint*,Vint[],Vint[]);void (*extent)(Vobject*,Vint,Vdouble[2][3]);
void (*edgepoint)(Vobject*,Vint,Vint,Vdouble,Vdouble[3],
Vint,Vdouble[3],Vdouble[3]);void (*edgenearest)(Vobject*,
Vint,Vint,Vdouble,Vdouble[3],Vdouble*,Vdouble[3]);void
(*faceepoint)(Vobject*,Vint,Vint,Vdouble[2],Vdouble[3],
Vint,Vdouble[2][3],Vdouble[3][3]);void (*facenearest)(Vobject*,
Vint,Vint,Vdouble[2],Vdouble[3],Vdouble[2],Vdouble[3]);
void (*facenormal)(Vobject*,Vint,Vint,Vdouble[2],Vdouble[3],
Vdouble[3]);Vint (*error)(Vobject*);
#ifdef __cplusplus
public: VKI_EXTERN vis_GeomFun(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_GeomFun(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Init();VKI_EXTERN void Set(Vint,
Vfunc*);VKI_EXTERN void Get(Vint,Vfunc**);VKI_EXTERN
void SetObj(Vobject*);VKI_EXTERN void GetObj(Vobject**);
VKI_EXTERN void Copy(vis_GeomFun*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_GeomFun* vis_GeomFunBegin(void);VKI_EXTERN
void vis_GeomFun_Construct(vis_GeomFun* p);VKI_EXTERN
void vis_GeomFunEnd(vis_GeomFun* p);VKI_EXTERN void
vis_GeomFun_Destruct(vis_GeomFun* p);VKI_EXTERN Vint
vis_GeomFunError(vis_GeomFun* p);VKI_EXTERN void vis_GeomFunInit(vis_GeomFun*
p);VKI_EXTERN void vis_GeomFunSet(vis_GeomFun* p,Vint
type,Vfunc* function);VKI_EXTERN void vis_GeomFunGet(vis_GeomFun*
p,Vint type,Vfunc** function);VKI_EXTERN void vis_GeomFunSetObj(vis_GeomFun*
p,Vobject* obj);VKI_EXTERN void vis_GeomFunGetObj(vis_GeomFun*
p,Vobject** obj);VKI_EXTERN void vis_GeomFunCopy(vis_GeomFun*
p,vis_GeomFun* fromp);
#ifdef __cplusplus
}
#endif
#endif

