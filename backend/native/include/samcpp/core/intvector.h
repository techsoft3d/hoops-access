#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class IntVector {
  public:
    PIMPL_MOVE_ONLY(IntVector)

    /// Integer parameters for IntVector
    enum class IntegerParameter {
        INCLUDE_ZERO = VSY_INCLUDEZERO, ///< Validity of zero index
    };

    ErrorCode getErrorCode();
    Status    define(int length);
    Status    inquire(int *maxIndex);
    Status    setIntegerParameter(IntegerParameter parameter, int value);
    Status    count(int *itemCount);
    Status    set(int index, int item);
    Status    expand(int index);
    Status    append(int item);
    Status    get(int index, int *item);
    Status    increment(int index, int item);
    Status    clear();
    Status    initializeIterator();
    Status    nextItem(int *index, int *item);
    Status    match(IntVector *intvec, int *flag);
    Status    copy(IntVector *from);
    Status    print();
    Status    unique(int item);
    Status    getStartingIndex(int *index);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
