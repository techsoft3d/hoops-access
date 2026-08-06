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
/* Unrecognized data object */

#ifndef UNRECOGNIZEDDATA_DEF
#define UNRECOGNIZEDDATA_DEF

#include "sam/base/base.h"
#include "sam/base/system.h"
#include "sam/vis/idtran.h"

struct vdm_UnrecognizedData {
    Vint ierr;
    Vint count;
    vsy_IntVec* lineNumbers;
    vsy_HashTable* lines;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_UnrecognizedData(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_UnrecognizedData(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN void AddLine(Vint, Vchar[]);
    VKI_EXTERN void
    Inq(Vint*);
    VKI_EXTERN void
    GetLineNumbers(vsy_IntVec**);
    VKI_EXTERN void
    GetLines(vsy_HashTable**);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_UnrecognizedData*
vdm_UnrecognizedDataBegin(void);
VKI_EXTERN void
vdm_UnrecognizedData_Construct(vdm_UnrecognizedData* p);
VKI_EXTERN void
vdm_UnrecognizedDataAddLine(vdm_UnrecognizedData* p, Vint lineNumber, Vchar line[]);
VKI_EXTERN void
vdm_UnrecognizedDataInq(vdm_UnrecognizedData* p, Vint* count);
VKI_EXTERN void
vdm_UnrecognizedDataGetLineNumbers(vdm_UnrecognizedData* p, vsy_IntVec** lineNumbers);
VKI_EXTERN void
vdm_UnrecognizedDataGetLines(vdm_UnrecognizedData* p, vsy_HashTable** lines);
VKI_EXTERN void
vdm_UnrecognizedDataEnd(vdm_UnrecognizedData* p);
VKI_EXTERN void
vdm_UnrecognizedData_Destruct(vdm_UnrecognizedData* p);

#ifdef __cplusplus
}
#endif

#endif
