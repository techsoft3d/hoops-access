#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class InitialConditionCase {
  public:
    PIMPL_MOVE_ONLY(InitialConditionCase)

    /// Time derivative type for initial condition
    enum class TimeDerivative {
        ZERO = ICASE_DOF,    ///< Degree of freedom value
        FIRST = ICASE_DOFDOT ///< Time derivative value
    };

    constexpr static int TIME_DERIVATIVE_COUNT = 2;

    ErrorCode getErrorCode();
    Status    setSinglePointValue(int nodeIndex, TimeDerivative type, int dofCount, int dofs[], double values[]);
    Status    getSinglePointValueMaxNodeIndex(TimeDerivative type, int *maxNodeIndex);
    Status    getSinglePointValueType(int nodeIndex, int *typeCount, TimeDerivative types[]);
    Status    getSinglePointValue(int nodeIndex, TimeDerivative type, int *dofCount, int dofs[], double values[]);
    Status    getSinglePointValueNodeGroup(Group *inputNodeGroup, Group *outputNodeGroup);
    Status    clear();
    Status    hasInitialConditionSpecified(int *flag);
    Status    setId(int id);
    Status    getId(int *id);
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    print();

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
