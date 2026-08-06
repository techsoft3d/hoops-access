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
/* ResultMetadata object */
#ifndef RESULTMETADATA_DEF
#define RESULTMETADATA_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vis/visdefs.h"
#include "sam/base/inthash.h"

struct vis_ResultMetadata {
    void* implementationObject;
    Vint ierr;
    vsy_List* attributesNames;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vis_ResultMetadata(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vis_ResultMetadata(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void SetSize(Vlong, Vint, Vint);
    VKI_EXTERN void SetType(Vint, Vint, Vint);
    VKI_EXTERN void
    SetName(const Vchar*);
    VKI_EXTERN void
    Inq(Vchar[], Vlong*, Vint*, Vint*, Vint*);
    VKI_EXTERN void
    AddAttributeInt(const Vchar*, Vint);
    VKI_EXTERN void
    AddAttributeFloat(const Vchar*, Vfloat);
    VKI_EXTERN void
    AddAttributeDouble(const Vchar*, Vdouble);
    VKI_EXTERN void
    AddAttributeString(const Vchar*, const Vchar*);
    VKI_EXTERN void
    GetAttributeValueInt(const Vchar*, Vint*);
    VKI_EXTERN void
    GetAttributeValueFloat(const Vchar*, Vfloat*);
    VKI_EXTERN void
    GetAttributeValueDouble(const Vchar*, Vdouble*);
    VKI_EXTERN void
    GetAttributeValueString(const Vchar*, Vchar*);
    VKI_EXTERN void SetResultType(Vint);
    VKI_EXTERN void
    GetDimensions(Vchar*);
    VKI_EXTERN void
    EntType(Vint*, Vint*);
    VKI_EXTERN void
    PrintAttributes();
    VKI_EXTERN void
    GetAttributesNames(vsy_List**);

#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_ResultMetadata*
vis_ResultMetadataBegin(void);
VKI_EXTERN void
vis_ResultMetadata_Construct(vis_ResultMetadata* p);
VKI_EXTERN void
vis_ResultMetadataEnd(vis_ResultMetadata* p);
VKI_EXTERN void
vis_ResultMetadata_Destruct(vis_ResultMetadata* p);
VKI_EXTERN void
vis_ResultMetadataSetSize(vis_ResultMetadata* p, Vlong length, Vint rowsCount, Vint columnsCount);
VKI_EXTERN void
vis_ResultMetadataSetType(vis_ResultMetadata* p, Vint datatype, Vint parenttype, Vint childtype);
VKI_EXTERN void
vis_ResultMetadataSetName(vis_ResultMetadata* p, const Vchar* name);
VKI_EXTERN void
vis_ResultMetadataInq(vis_ResultMetadata* p, Vchar name[], Vlong* length, Vint* rowsCount, Vint* columnsCount, Vint* type);
VKI_EXTERN void
vis_ResultMetadataAddAttributeInt(vis_ResultMetadata* p, const Vchar* name, Vint value);
VKI_EXTERN void
vis_ResultMetadataAddAttributeFloat(vis_ResultMetadata* p, const Vchar* name, Vfloat value);
VKI_EXTERN void
vis_ResultMetadataAddAttributeDouble(vis_ResultMetadata* p, const Vchar* name, Vdouble value);
VKI_EXTERN void
vis_ResultMetadataAddAttributeString(vis_ResultMetadata* p, const Vchar* name, const Vchar* value);
VKI_EXTERN void
vis_ResultMetadataGetAttributeValueInt(vis_ResultMetadata* p, const Vchar* name, Vint* value);
VKI_EXTERN void
vis_ResultMetadataGetAttributeValueFloat(vis_ResultMetadata* p, const Vchar* name, Vfloat* value);
VKI_EXTERN void
vis_ResultMetadataGetAttributeValueDouble(vis_ResultMetadata* p, const Vchar* name, Vdouble* value);
VKI_EXTERN void
vis_ResultMetadataGetAttributeValueString(vis_ResultMetadata* p, const Vchar* name, Vchar* value);
VKI_EXTERN void
vis_ResultMetadataSetResultType(vis_ResultMetadata* p, Vint resultType);
VKI_EXTERN void
vis_ResultMetadataGetDimensions(vis_ResultMetadata* p, Vchar dimensions[]);
VKI_EXTERN void
vis_ResultMetadataEntType(vis_ResultMetadata* p, Vint* enttype, Vint* subtype);
VKI_EXTERN Vint
vis_ResultMetadataError(vis_ResultMetadata* p);
VKI_EXTERN void
vis_ResultMetadataPrintAttributes(vis_ResultMetadata* p);
VKI_EXTERN void
vis_ResultMetadataGetAttributesNames(vis_ResultMetadata* p, vsy_List** attributesNames);

#ifdef __cplusplus
}
#endif
#endif
