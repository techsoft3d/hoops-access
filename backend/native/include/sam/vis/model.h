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
 
#ifndef MODEL_DEF
#define MODEL_DEF
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#define MODEL_CHECKJACOBIAN 1
#define MODEL_NUMCHECKSTRING -1
#define MODEL_CHECKSTRING 0
#define MODEL_CHECKSTRING0 0
#define MODEL_CHECKSTRING1 1
#define MODEL_CHECKSTRING2 2
#define MODEL_CHECKSTRING3 3
#define MODEL_CHECKSTRING4 4
typedef struct vis_ModelImpl vis_ModelImpl;struct vis_Model
{ Vint ierr;vis_ModelImpl* impl;
#ifdef __cplusplus
public: VKI_EXTERN vis_Model(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vis_Model(void);VKI_EXTERN
void operator delete(void*);VKI_EXTERN void EndWithDeleteOption(Vint);
VKI_EXTERN Vint Error();VKI_EXTERN void SetObject(Vint,
Vobject*);VKI_EXTERN void GetObject(Vint,Vobject**);
VKI_EXTERN void SetHashTable(Vint,vsy_HashTable*);VKI_EXTERN
void GetHashTable(Vint,vsy_HashTable**);VKI_EXTERN void
SetList(Vint,vsy_List*);VKI_EXTERN void GetList(Vint,
vsy_List**);VKI_EXTERN void SetParami(Vint,Vint);VKI_EXTERN
void SetSource(Vint);VKI_EXTERN void GetSource(Vint*);
VKI_EXTERN void Write(Vint,const Vchar*);VKI_EXTERN
void Delete();VKI_EXTERN void GetInteger(Vint,Vint[]);
VKI_EXTERN void GetString(Vint,Vchar[]);VKI_EXTERN void
Check(Vint*);VKI_EXTERN void CheckSProp(vis_SProp*,
Vint*);VKI_EXTERN void Print();VKI_EXTERN void PrintSummary();
VKI_EXTERN void ElemThickness(Vint,Vdouble[]);VKI_EXTERN
void ElemOffset(Vint,Vdouble[]);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vis_Model* vis_ModelBegin(void);VKI_EXTERN
void vis_Model_Construct(vis_Model* p);VKI_EXTERN void
vis_ModelEnd(vis_Model* p);VKI_EXTERN void vis_ModelEndWithDeleteOption(vis_Model*
p,Vint deleteOptionFlag);VKI_EXTERN void vis_Model_Destruct(vis_Model*
p);VKI_EXTERN Vint vis_ModelError(vis_Model* p);VKI_EXTERN
void vis_ModelSetObject(vis_Model* p,Vint objecttype,
Vobject* object);VKI_EXTERN void vis_ModelGetObject(vis_Model*
p,Vint objecttype,Vobject** object);VKI_EXTERN void
vis_ModelSetHashTable(vis_Model* p,Vint type,vsy_HashTable*
hashtable);VKI_EXTERN void vis_ModelGetHashTable(vis_Model*
p,Vint type,vsy_HashTable** hashtable);VKI_EXTERN void
vis_ModelSetList(vis_Model* p,Vint type,vsy_List* list);
VKI_EXTERN void vis_ModelGetList(vis_Model* p,Vint type,
vsy_List** vlist);VKI_EXTERN void vis_ModelSetParami(vis_Model*
p,Vint type,Vint iparam);VKI_EXTERN void vis_ModelSetSource(vis_Model*
p,Vint libtype);VKI_EXTERN void vis_ModelGetSource(vis_Model*
p,Vint* libtype);VKI_EXTERN void vis_ModelWrite(vis_Model*
p,Vint type,const Vchar* path);VKI_EXTERN void vis_ModelDelete(vis_Model*
p);VKI_EXTERN void vis_ModelGetInteger(vis_Model* p,
Vint type,Vint iparam[]);VKI_EXTERN void vis_ModelGetString(vis_Model*
p,Vint type,Vchar cparam[]);VKI_EXTERN void vis_ModelCheck(vis_Model*
p,Vint* status);VKI_EXTERN void vis_ModelCheckSProp(vis_Model*
p,vis_SProp* sprop,Vint* status);VKI_EXTERN void vis_ModelPrintSummary(vis_Model*
p);VKI_EXTERN void vis_ModelPrint(vis_Model* p);VKI_EXTERN
void vis_ModelElemThickness(vis_Model* p,Vint index,
Vdouble thickness[]);VKI_EXTERN void vis_ModelElemOffset(vis_Model*
p,Vint index,Vdouble offset[]);
#ifdef __cplusplus
}
#endif
#endif

