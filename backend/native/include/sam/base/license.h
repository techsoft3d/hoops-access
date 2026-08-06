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
/* Licensing functionalities */

#ifndef LICENSE_BASE_DEF
#define LICENSE_BASE_DEF

#include "sam/base/basedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

VKI_EXTERN void
vsy_LicenseValidate(const Vchar* licenseKey);

VKI_EXTERN void
vsy_LicenseRelease(void);

VKI_EXTERN void
vsy_LicenseIsValid(Vint* isValidFlag);

VKI_EXTERN void
vsy_LicenseHasExpired(Vint* hasExpiredFlag);

VKI_EXTERN void
vsy_LicenseIsPerpetual(Vint* isPerpetualFlag);

VKI_EXTERN void
vsy_LicenseHasAccess(Vint* hasFeature);

VKI_EXTERN void
vsy_LicenseHasMesh(Vint* hasFeature);

VKI_EXTERN void
vsy_LicenseHasSolve(Vint* hasFeature);

VKI_EXTERN void
vsy_LicenseCustomerName(Vchar** customerName, Vint* customerNameSize);

VKI_EXTERN void
vsy_LicenseExpiryDate(Vchar** expiryDate, Vint* expiryDataSize);

#ifdef __cplusplus
}
#endif

#endif
