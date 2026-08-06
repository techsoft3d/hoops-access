#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/status.h"

namespace cae::core {

namespace license {

Status validate(const char *licenseKey);
Status release();
Status isValid(int *isValidFlag);
Status hasExpired(int *hasExpiredFlag);
Status isPerpetual(int *isPerpetualFlag);
Status hasAccessFeature(int *hasFeature);
Status hasMeshFeature(int *hasFeature);
Status hasSolveFeature(int *hasFeature);
Status getCustomerName(char **customerName, int *customerNameSize);
Status getExpiryDate(char **expiryDate, int *expiryDataSize);

} // namespace license

} // namespace cae::core
