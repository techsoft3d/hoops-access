#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class ResultMetadata {
  public:
    PIMPL_MOVE_ONLY(ResultMetadata)

    ErrorCode getErrorCode();
    Status    setSize(long long length, int rowsCount, int columnsCount);
    Status    setType(DataLayout type, EntityType entityType, EntityType subEntityType);
    Status    setName(const char *name);
    Status    inquire(char name[], long long *lrec, int *nrow, int *ncol, DataLayout *type);
    Status    addAttributeInteger(const char *name, int value);
    Status    addAttributeFloat(const char *name, float value);
    Status    addAttributeDouble(const char *name, double value);
    Status    addAttributeString(const char *name, const char *value);
    Status    getAttributeValueInteger(const char *name, int *value);
    Status    getAttributeValueFloat(const char *name, float *value);
    Status    getAttributeValueDouble(const char *name, double *value);
    Status    getAttributeValueString(const char *name, char *value);
    Status    setResultType(ResultType resultType);
    Status    getDimensions(char dimensions[]);
    Status    getEntityType(EntityType *entityType, EntityType *subEntityType);
    Status    printAttributes();
    Status    getAttributesNames(ListPtr<char> &attributesNames);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
