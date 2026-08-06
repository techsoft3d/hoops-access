#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/pointer.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

template <typename T>
class List {
  public:
    PIMPL_MOVE_ONLY(List)

    ErrorCode getErrorCode();
    Status    define(int capacity);
    Status    inquire(int *capacity);
    Status    count(int *itemCount);
    Status    maxIndex(int *index);
    Status    allIndices(int indices[]);
    Status    insert(int index, T *item);
    Status    add(T *item, int *index);
    Status    append(T *item);
    Status    get(int index, Pointer<T> &item);
    Status    remove(int index);
    Status    clear();
    Status    compact();
    Status    initializeIterator();
    Status    nextItem(int *index, Pointer<T> &item);
    Status    forEach(UnaryFunction *function);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
