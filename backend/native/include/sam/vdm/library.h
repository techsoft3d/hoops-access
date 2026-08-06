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
 
#ifndef LIBRARY_DEF
#define LIBRARY_DEF
#include "sam/base/basedefs.h"
#include "sam/base/list.h"
#include "sam/base/regexp.h"
#include "sam/vdm/dataset.h"
#define LIB_NATIVE 1
#define LIB_GENERIC 5
#define LIB_PDA 6
#define LIB_D3DLSTC 7
#define LIB_ABAODB 8
#define LIB_ABAFILBIN 9
#define LIB_NASOUTPUT2 10
#define LIB_ABAINPUT 13
#define LIB_SDRC 14
#define LIB_PAMDAISY 15
#define LIB_ANSYSRESULT 16
#define LIB_MECHANICASTUDY 17
#define LIB_NASBULKDATA 18
#define LIB_PATNEUTRAL 20
#define LIB_FLUENT 21
#define LIB_ANSYSINPUT 22
#define LIB_MOLDFLOW 23
#define LIB_MAXLIBTYPE 28
struct vdm_Library { Vint ierr;Vchar path[SYS_MAXPATHCHAR];
Vint type;Vint numdataset;vsy_List* list;vsy_IntDict*
dict;vsy_RegExp* regexp;
#ifdef __cplusplus
public: VKI_EXTERN vdm_Library(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vdm_Library(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Def(const Vchar*,Vint);VKI_EXTERN
void Inq(Vchar[],Vint*);VKI_EXTERN void Print();VKI_EXTERN
void TOC(const Vchar*,Vint);VKI_EXTERN void InsertDataset(Vint,
vdm_Dataset*);VKI_EXTERN void AddDataset(vdm_Dataset*);
VKI_EXTERN void GetNumDatasets(Vint*);VKI_EXTERN void
GetDataset(Vint,vdm_Dataset**);VKI_EXTERN void SearchDataset(const
Vchar*,Vint,Vint[],Vint*);VKI_EXTERN void ProcessLinkIndex();
VKI_EXTERN void MaxIds(Vint*,Vint*,Vint*);VKI_EXTERN
void DatasetEndObj(Vfunc1*);VKI_EXTERN void DatasetEndLib(Vfunc1*);
VKI_EXTERN void DatasetGetObj(Vint,Vobject**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_Library* vdm_LibraryBegin(void);VKI_EXTERN
void vdm_Library_Construct(vdm_Library* p);VKI_EXTERN
void vdm_LibraryEnd(vdm_Library* p);VKI_EXTERN void
vdm_Library_Destruct(vdm_Library* p);VKI_EXTERN Vint
vdm_LibraryError(vdm_Library* p);VKI_EXTERN void vdm_LibraryDef(vdm_Library*
p,const Vchar* path,Vint type);VKI_EXTERN void vdm_LibraryInq(vdm_Library*
p,Vchar path[],Vint* type);VKI_EXTERN void vdm_LibraryPrint(vdm_Library*
p);VKI_EXTERN void vdm_LibraryTOC(vdm_Library* p,const
Vchar* name,Vint flag);VKI_EXTERN void vdm_LibraryInsertDataset(vdm_Library*
p,Vint idx,vdm_Dataset* dataset);VKI_EXTERN void vdm_LibraryAddDataset(vdm_Library*
p,vdm_Dataset* dataset);VKI_EXTERN void vdm_LibraryGetNumDatasets(vdm_Library*
p,Vint* numdataset);VKI_EXTERN void vdm_LibraryGetDataset(vdm_Library*
p,Vint idst,vdm_Dataset** dataset);VKI_EXTERN void vdm_LibrarySearchDataset(vdm_Library*
p,const Vchar* name,Vint max,Vint idsts[],Vint* num);
VKI_EXTERN void vdm_LibraryProcessLinkIndex(vdm_Library*
p);VKI_EXTERN void vdm_LibraryMaxIds(vdm_Library* p,
Vint* id1,Vint* id2,Vint* id3);VKI_EXTERN void vdm_LibraryDatasetEndObj(vdm_Library*
p,Vfunc1* function);VKI_EXTERN void vdm_LibraryDatasetEndLib(vdm_Library*
p,Vfunc1* function);VKI_EXTERN void vdm_LibraryDatasetGetObj(vdm_Library*
p,Vint idst,Vobject** obj);
#ifdef __cplusplus
}
#endif
#endif

