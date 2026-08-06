#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class MultipointConstraintCase {
  public:
    PIMPL_MOVE_ONLY(MultipointConstraintCase)

    /// Multipoint constraint types
    enum class ConstraintType {
        MPC = MCASE_MPC,    ///< General multipoint constraint
        TIE = MCASE_TIE,    ///< Tie constraint between nodes
        PIN = MCASE_PIN,    ///< Pin constraint
        LINK = MCASE_LINK,  ///< Link constraint
        BEAM = MCASE_BEAM,  ///< Beam constraint
        ELBOW = MCASE_ELBOW ///< Elbow constraint
    };

    ErrorCode getErrorCode();
    Status    setMPC(int mpcIndex, int termCount, int nodeIndexes[], DofType dofs[], double coefficients[], double inhomogeneity);
    Status    setInhomogeneity(int mpcIndex, double inhomogeneity);
    Status    setBuiltInConstraint(int mpcIndex, ConstraintType type, int nodeIndexes[]);
    Status    getTermCount(int mpcIndex, int *termCount);
    Status    getMPC(int mpcIndex, int *termCount, int nodeIndexes[], DofType dofs[], double coefficients[], double *inhomogeneity);
    Status    getBuiltInConstraint(int mpcIndex, ConstraintType *type, int *termCount, int nodeIndexes[]);
    Status    deleteConstraint(int mpcIndex);
    Status    getType(int mpcIndex, ConstraintType *type);
    Status    getMax(int *maxConstraintIndex, int *maxTermCount, int *maxInhomogeneityCount);
    Status    initializeIterator();
    Status    nextItem(int *index);
    Status    clear();
    Status    hasConstraintSpecified(int *flag);
    Status    add(MultipointConstraintCase *add);
    Status    setId(int id);
    Status    getId(int *id);
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    print();
    Status    getBuiltInConstraintTermCount(ConstraintType type, int *termCount);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
