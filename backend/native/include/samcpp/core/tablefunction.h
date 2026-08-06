#pragma once

#include "sam/vis/tcurvedefs.h"
#include "samcpp/core/base_types.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class TableFunction {
  public:
    /// Table function type
    enum class Type {
        PWLINEAR = TCURVE_PWLINEAR,    ///< Piecewise linear function
        EQUATION = TCURVE_EQUATION,    ///< Equation-based function
        EXPRESSION = TCURVE_EXPRESSION ///< Expression-based function
    };

    /// Table parameter types for scaling and shifting
    enum class TableParameter {
        SCALE = TCURVE_SCALE,     ///< Scale factor
        SHIFT = TCURVE_SHIFT,     ///< Shift value
        DIVISOR = TCURVE_DIVISOR, ///< Divisor value
        OFFSET = TCURVE_OFFSET    ///< Offset value
    };

    /// Double precision parameter types
    enum class DoubleParameter {
        TOLERANCE = TCURVE_TOLERANCE ///< Tolerance value
    };

    /// Integer parameter types
    enum class IntegerParameter {
        EXTRAPOLATE = TCURVE_EXTRAPOLATE, ///< Extrapolation flag
    };

    PIMPL_MOVE_ONLY(TableFunction)

    ErrorCode getErrorCode();
    Status    setId(int id);
    Status    getId(int *id);
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    define(Type type, int dimension);
    Status    inquire(Type *type, int *dimension);
    Status    setFactor(TableParameter type, float factor);
    Status    setFactor(TableParameter type, double factor);
    Status    getFactor(TableParameter type, float *factor);
    Status    getFactor(TableParameter type, double *factor);
    Status    setDoubleParameter(DoubleParameter type, double value);
    Status    setIntegerParameter(IntegerParameter type, int value);
    Status    getIntegerParameter(IntegerParameter type, int *value);
    Status    setPiecewiseLinear(int pointCount, float x[], float y[]);
    Status    setPiecewiseLinear(int pointCount, double x[], double y[]);
    Status    getPointCount(int *count);
    Status    getIndependentValues(int pointCount, int pointIndexes[], float values[]);
    Status    getIndependentValues(int pointCount, int pointIndexes[], double values[]);
    Status    getDependentValues(int pointCount, int pointIndexes[], float values[]);
    Status    getDependentValues(int pointCount, int pointIndexes[], double values[]);
    Status    setDependentValues(int pointCount, int pointIndexes[], float values[]);
    Status    setDependentValues(int pointCount, int pointIndexes[], double values[]);
    Status    evaluate(int pointCount, float independentValues[], float dependentValues[]);
    Status    evaluate(int pointCount, double independentValues[], double dependentValues[]);
    Status    merge(int count, TableFunction **functionArray);
    Status    checkMatchingIndependentValues(int pointCount, float independentValues[], int *flag);
    Status    print();
    int       isEqualTo(TableFunction *function);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
