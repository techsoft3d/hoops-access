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
 
#ifndef ADTREE_DEF
#define ADTREE_DEF
#include "sam/base/basedefs.h"
#include "sam/base/linklist.h"
#include "sam/base/inthash.h"
#define ADTREE_POINT 1
#define ADTREE_EXTENT 2
#define ADTREE_TOLERANCE 1
#define ADTREE_NUMHITS 1
#define ADTREE_NUMVISITS 2
#define ADTREE_MAXLEVEL 3
typedef struct vsy_ADTree_Entry vsy_ADTree_Entry;struct
vsy_ADTree_Entry { Vint index;Vint left;Vint right;
Vdouble x[6];};typedef struct vsy_ADTree_Point vsy_ADTree_Point;
struct vsy_ADTree_Point { Vint index;Vint left;Vint
right;Vdouble x[3];};typedef struct vsy_ADTree_Extent
vsy_ADTree_Extent;struct vsy_ADTree_Extent { Vint index;
Vint left;Vint right;Vdouble x[6];};typedef struct {
Vint nhits;Vint maxhits;Vint nvisits;Vint iter;Vint*
hits;}vsy_ADTree_Iter;struct vsy_ADTree { Vint ierr;
Vint root;Vdouble tol;Vint iter;Vint type;Vint ndim;
Vint numinsert;Vint maxlevel;Vdouble xmin[3];Vdouble
xmax[3];Vint nllblk;Vchar** ll;Vint llshift;Vint llblk;
Vint maxnode;Vint numnode;size_t size;vsy_ADTree_Iter
iters[SYS_THREADS_MAX + 1];
#ifdef __cplusplus
public: VKI_EXTERN vsy_ADTree(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_ADTree(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN Vint Error();
VKI_EXTERN void Def(Vint,Vdouble[3],Vdouble[3]);VKI_EXTERN
void Inq(Vint*,Vint*,Vdouble[3],Vdouble[3])const;VKI_EXTERN
void SetParamd(Vint,Vdouble);VKI_EXTERN void Check();
VKI_EXTERN void InsertPoint(Vint,Vdouble[]);VKI_EXTERN
void InsertExtent(Vint,Vdouble[],Vdouble[]);VKI_EXTERN
void InsertLine(Vint,Vdouble[],Vdouble[]);VKI_EXTERN
void InsertElem(Vint,Vint,Vdouble[][3]);VKI_EXTERN void
RefPointInit(Vdouble[3]);VKI_EXTERN void RefPointNext(Vint*);
VKI_EXTERN void RefExtentInit(Vdouble[3],Vdouble[3]);
VKI_EXTERN void RefExtentNext(Vint*);VKI_EXTERN void
Remove(Vint);VKI_EXTERN void GetInteger(Vint,Vint[]);
VKI_EXTERN void Print();VKI_EXTERN void RefPointInitIter(Vint,
Vdouble[3]);VKI_EXTERN void RefPointNextIter(Vint,Vint*);
VKI_EXTERN void RefExtentInitIter(Vint,Vdouble[3],Vdouble[3]);
VKI_EXTERN void RefExtentNextIter(Vint,Vint*);VKI_EXTERN
void GetIntegerIter(Vint,Vint,Vint[]);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_ADTree* vsy_ADTreeBegin(void);VKI_EXTERN
void vsy_ADTree_Construct(vsy_ADTree* p);VKI_EXTERN
void vsy_ADTreeEnd(vsy_ADTree* p);VKI_EXTERN void vsy_ADTree_Destruct(vsy_ADTree*
p);VKI_EXTERN Vint vsy_ADTreeError(vsy_ADTree* p);VKI_EXTERN
void vsy_ADTreeDef(vsy_ADTree* p,Vint type,Vdouble xmin[3],
Vdouble xmax[3]);VKI_EXTERN void vsy_ADTreeInq(const
vsy_ADTree* p,Vint* type,Vint* len,Vdouble xmin[3],
Vdouble xmax[3]);VKI_EXTERN void vsy_ADTreeSetParamd(vsy_ADTree*
p,Vint ptype,Vdouble dparam);VKI_EXTERN void vsy_ADTreeCheck(vsy_ADTree*
p);VKI_EXTERN void vsy_ADTreeInsertPoint(vsy_ADTree*
p,Vint key,Vdouble x[]);VKI_EXTERN void vsy_ADTreeInsertExtent(vsy_ADTree*
p,Vint key,Vdouble xmin[],Vdouble xmax[]);VKI_EXTERN
void vsy_ADTreeInsertLine(vsy_ADTree* p,Vint index,
Vdouble x1[],Vdouble x2[]);VKI_EXTERN void vsy_ADTreeInsertElem(vsy_ADTree*
p,Vint index,Vint nn,Vdouble x[][3]);VKI_EXTERN void
vsy_ADTreeRefPointInit(vsy_ADTree* p,Vdouble x[3]);
VKI_EXTERN void vsy_ADTreeRefPointNext(vsy_ADTree* p,
Vint* key);VKI_EXTERN void vsy_ADTreeRefExtentInit(vsy_ADTree*
p,Vdouble xmin[3],Vdouble xmax[3]);VKI_EXTERN void vsy_ADTreeRefExtentNext(vsy_ADTree*
p,Vint* key);VKI_EXTERN void vsy_ADTreeRemove(vsy_ADTree*
p,Vint key);VKI_EXTERN void vsy_ADTreeGetInteger(vsy_ADTree*
p,Vint type,Vint iparam[]);VKI_EXTERN void vsy_ADTreePrint(vsy_ADTree*
p);VKI_EXTERN void vsy_ADTreeRefPointInitIter(vsy_ADTree*
p,Vint iter,Vdouble x[3]);VKI_EXTERN void vsy_ADTreeRefPointNextIter(vsy_ADTree*
p,Vint iter,Vint* index);VKI_EXTERN void vsy_ADTreeRefExtentInitIter(vsy_ADTree*
p,Vint iter,Vdouble xmin[3],Vdouble xmax[3]);VKI_EXTERN
void vsy_ADTreeRefExtentNextIter(vsy_ADTree* p,Vint
iter,Vint* index);VKI_EXTERN void vsy_ADTreeGetIntegerIter(vsy_ADTree*
p,Vint iter,Vint type,Vint iparams[]);
#ifdef __cplusplus
}
#endif
#endif

