#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

template <typename T>
class HashTable {
  public:
    PIMPL_MOVE_ONLY(HashTable)

    ErrorCode getErrorCode();
    Status    define(int capacity);
    Status    count(int *itemCount);
    Status    inquire(int *capacity);
    Status    insert(int key, T *item);
    Status    lookup(int key, Pointer<T> &item);
    Status    maxKey(int *maxKey);
    Status    remove(int key);
    Status    clear();
    Status    allKeys(int keys[]);
    Status    initializeIterator();
    Status    initializeOrderedIterator();
    Status    nextItem(int *key, Pointer<T> &item);
    Status    forEach(UnaryFunction *func);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
