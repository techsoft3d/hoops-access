#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::access {

class UnrecognizedData {
  public:
    PIMPL_MOVE_ONLY(UnrecognizedData)

    cae::core::ErrorCode getErrorCode();
    cae::core::Status    getLineCount(int *count);
    cae::core::Status    getLineNumbers(cae::core::IntVectorPtr &lineNumbers);
    cae::core::Status    getLines(cae::core::HashTablePtr<char> &lines);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::access
