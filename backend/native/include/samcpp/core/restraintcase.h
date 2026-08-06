#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class RestraintCase {
  public:
    PIMPL_MOVE_ONLY(RestraintCase)

    /// Single point constraint type
    enum class ConstraintType {
        FREE = RCASE_FREE,       ///< Free (no constraint)
        FIXED = RCASE_FIXED,     ///< Simple fixity
        APPLIED = RCASE_APPLIED, ///< Constraint to applied value
        MASTER = RCASE_MASTER    ///< Equivalence to another master node
    };

    /// Time derivative type for applied constraint value
    enum class TimeDerivative {
        ZERO = RCASE_DOF,        ///< Degree of freedom
        FIRST = RCASE_DOFDOT,    ///< First time derivative
        SECOND = RCASE_DOFDOTDOT ///< Second time derivative
    };

    ErrorCode getErrorCode();
    Status    setComplexMode(ComplexMode mode);
    Status    getComplexMode(ComplexMode *mode);
    Status    hasComplexData(int *flag);
    Status    setSPC(int nodeIndex, DofType dof, ConstraintType type, double value[], int masterNodeIndex);
    Status    setSPCTableIdentifiers(int index, DofType dof, int ids[]);
    Status    setSPCTimeDerivativeType(int nodeIndex, DofType dof, TimeDerivative derivativeType);
    Status    getSPCcount(int *indexCount, int *appliedCount, int *masterCount);
    Status    getSPCMaxNodeIndex(int *maxNodeIndex);
    Status    initializeSPCIterator();
    Status    nextSPCItem(int *index);
    Status    getSPCUsedDofs(int *dofCount, DofType dofs[]);
    Status    getSPCDofsAtNode(int nodeIndex, int *dofCount, DofType dofs[]);
    Status    getSPC(int nodeIndex, DofType dof, ConstraintType *type, double value[], int *masterNodeIndex);
    Status    getSPCTableIdentifiers(int nodeIndex, DofType dof, int ids[]);
    Status    getSPCTimeDerivativeType(int nodeIndex, DofType dof, TimeDerivative *derivativeType);
    Status    getSPCNodeGroup(Group *inputNodeGroup, Group *outputNodeGroup);
    Status    setConstraintOnElementDof(int elementIndex, DofType dof, ConstraintType type, double value[]);
    Status    getElementConstraintMaxIndex(int *maxElementIndex);
    Status    initializeElementConstraintIterator();
    Status    nextElementConstraintItem(int *elementIndex);
    Status    getUsedConstraintDofsFromElements(int *dofCount, DofType dofs[]);
    Status    getConstraintDofsFromElement(int elementIndex, int *dofCount, DofType dofs[]);
    Status    getConstraintInfoFromElementDof(int elementIndex, DofType dof, ConstraintType *type, double *value);
    Status    getConstraintElementGroup(Group *inputElementGroup, Group *outputElementGroup);
    Status    clear();
    Status    hasRestraintSpecified(int *flag);
    Status    add(RestraintCase *add);
    Status    setId(int id);
    Status    getId(int *id);
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    print();
    Status    copy(RestraintCase *from);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
