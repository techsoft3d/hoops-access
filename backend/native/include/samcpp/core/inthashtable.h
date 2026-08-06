#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

#define INTHASH_UNDEFINED 1

ACCESSOR_DECL

namespace cae::core {

class IntHashTable {
  public:
    PIMPL_MOVE_ONLY(IntHashTable)

    /// Integer parameter types
    enum class IntegerParameter {
        UNDEFINED = INTHASH_UNDEFINED ///< Undefined value
    };

    ErrorCode getErrorCode();
    Status    define(int capacity);
    Status    inquire(int *capacity);
    Status    setIntegerParameter(IntegerParameter parameter, int value);
    Status    count(int *itemCount);
    Status    maxKey(int *key);
    Status    allKeys(int keys[]);
    Status    emptyKey(int *key);
    Status    insert(int key, int item);
    Status    insertIfAbsent(int key, int item, int *oldItem);
    Status    lookup(int key, int *item);
    Status    clear();
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    initializeIterator();
    Status    initializeOrderedIterator();
    Status    nextItem(int *key, int *item);
    Status    print();

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
