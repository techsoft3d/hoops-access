#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class IdTranslator {
  public:
    PIMPL_MOVE_ONLY(IdTranslator)

    /// Count type
    enum class CountType {
        MAX_INDEX = IDTRAN_MAXINDEX,       ///< Maximum index set
        INDICES_COUNT = IDTRAN_NUMINDICES, ///< Number of non-zero identifiers
        UNIQUE_COUNT = IDTRAN_NUMUNIQUE    ///< Number of unique identifiers
    };

    /// Definition operation types
    enum class DefinitionOperationType {
        THROUGH = IDTRAN_THRU, ///< Through operation
        BY = IDTRAN_BY,        ///< By operation
    };

    ErrorCode getErrorCode();
    Status    define(int entityCount);
    Status    inquire(int *entityCount);
    Status    setId(int index, int id);
    Status    getId(int index, int *id);
    Status    getIds(int indexCount, int indices[], int ids[]);
    Status    setElementEntity(int index, int entityNumber);
    Status    getElementEntity(int index, int *entityNumber);
    Status    getElementEntities(int indexCount, int indices[], int entityNumbers[]);
    Status    addId(int id);
    Status    addThroughByIds(int count, int list[]);
    Status    setEquivalentId(int index, int id);
    Status    sweepEquivalentIds();
    Status    renumberEquivalentIds(int *count);
    Status    setUserId(int id);
    Status    getUserId(int *id);
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    setFiniteElementType(ElementType type);
    Status    getFiniteElementType(ElementType *type);
    Status    setFiniteElementSpecificType(SpecificType type);
    Status    getFiniteElementSpecificType(SpecificType *type);
    Status    setEntityType(EntityType entityType, EntityType entitySubtype);
    Status    getEntityType(EntityType *entityType, EntityType *entitySubtype);
    Status    clear();
    Status    append(IdTranslator *toAppend);
    Status    count(CountType type, int *count);
    Status    createFromGroup(Group *group);
    Status    unique(IdTranslator *source);
    Status    getEntityIndex(int id, int *index);
    Status    getEntityIndices(int count, int ids[], int indices[]);
    Status    indexCount(int id, int *num);
    Status    getAllIndices(int id, int *count, int index[]);
    Status    match(IdTranslator *toCheck, int *flag);
    Status    copy(IdTranslator *source);
    Status    print();

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
