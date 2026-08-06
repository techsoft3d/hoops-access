#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/error.h"

namespace cae::core {
class Status {
  public:
    explicit Status(const Vint error);

    /* Implicit conversion to bool */
    operator bool() const;

    bool hasError() const;

    bool isSuccess() const;

    ErrorCode getErrorCode() const;

    const char *getErrorMessage() const;

    Status(const Status &other);

    Status &operator=(const Status &) = default;

  private:
    ErrorCode m_errorCode;
};

} // namespace cae::core