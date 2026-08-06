#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class Group {
  public:
    PIMPL_MOVE_ONLY(Group)

    /// Group operation type for combining or modifying groups
    enum class Operation {
        SET = GROUP_SET,       ///< Set/replace group contents
        INSERT = GROUP_INSERT, ///< Insert/add to group
        REMOVE = GROUP_DELETE, ///< Remove from group
        MASK = GROUP_MASK      ///< Apply mask operation
    };

    ErrorCode getErrorCode();
    Status    define(int entityCount, EntityType entityType, EntityType entitySubtype);
    Status    inquire(int *entityCount, EntityType *entityType, EntityType *entitySubtype);
    Status    setIndex(int entityIndex, int flag);
    Status    setIndices(int count, int entityIndices[], int flag);
    Status    getIndex(int entityIndex, int *flag);
    Status    setEntityFlag(int entityIndex, int entityNumber, int flag);
    Status    getEntityFlag(int entityIndex, int entityNumber, int *flag);
    Status    entityFlagSetCount(int entityIndex, int *entityNumberCount, int *entityNumberMaxCount);
    int       isNodeActive(int nodeIndex);
    int       isElementActive(int elementIndex);
    int       isElementEntityActive(int elementEntityIndex, int elementEntityNumber);
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    setType(int type);
    Status    getType(int *type);
    Status    setSpecificType(int type);
    Status    getSpecificType(int *type);
    Status    initializeIndexIteration();
    Status    nextIndex(int *index, int *flag);
    Status    clear();
    Status    all();
    Status    applyOperation(Operation operation, Group *source);
    Status    complement();
    Status    count(int *parentCount, int *childCount);
    Status    createFromIdTranslator(IdTranslator *idtranslator);
    Status    copy(Group *source);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
