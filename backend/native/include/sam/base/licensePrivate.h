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
#ifndef VISLICENSE_DEF
#define VISLICENSE_DEF

#include "sam/base/system.h"
#include "sam/base/basedefs.h"

struct licenseInformation {
    /*Has been verified*/
    Vint hasBeenVerified;
    /*partiular client license details*/
    Vchar* customerName;
    Vchar* licenseKey;
    Vchar* expiryDate;
    Vint licenseKeySize;
    Vint customerNameSize;
    Vint expiryDateSize;

    /*validation duration*/
    Vint isValid;
    Vint hasExpired;
    Vint isPerpetual;

    /*features enabled*/
    Vint hasAccess;
    Vint hasMesh;
    Vint hasSolve;
};

#ifdef __cplusplus
extern "C" {
#endif

extern void
initialize_license_components(const Vchar* licenseKey);

extern void
terminate_license_components();

extern Vint
LicenseIsValid();

extern Vint
licenseIsNotValid();

extern Vint
LicenseHasExpired();

extern Vint
LicenseIsPerpetual();

extern Vint
LicenseHasAccess();

extern Vint
LicenseHasMesh();

extern Vint
LicenseHasSolve();

extern void
LicenseCustomerName(Vchar** customerName, Vint* customerNameSize);

extern void
LicenseExpiryDate(Vchar** expiryDate, Vint* expiryDataSize);

extern void
exit_if_not_valid_license();

extern void
exit_if_not_access_license();

extern void
exit_if_not_mesh_license();

extern void
exit_if_not_solve_license();

#ifdef __cplusplus
}
#endif

#endif /* VISLICENSE_DEF*/
