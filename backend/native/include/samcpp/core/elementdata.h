#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class ElementData {
  public:
    PIMPL_MOVE_ONLY(ElementData)

    /// Group Operation types
    enum class GroupOperation {
        EDGES_WITH_DATA = ELEMDAT_SETDATA ///< Edges at which data has been set
    };
    /// Integer parameter types
    enum class IntegerParameter {
        LINEARIZE_NORMALS = ELEMDAT_LINNORMAL ///< Linearize normals from corner nodes
    };
    /// Double precision parameter types
    enum class DoubleParameter {
        FEATURE_ANGLE = ELEMDAT_FEATUREANGLE ///< Feature angle in degrees
    };

    ErrorCode getErrorCode();
    Status    setPrecision(Precision precision);
    Status    getPrecision(Precision *precision);
    Status    setMeshInterface(MeshInterface *functions);
    Status    getMeshInterface(MeshInterfacePtr &functions);
    Status    define(int entityCount, EntityType parentType, EntityType childType, DataLayout layout);
    Status    inquire(int *entityCount, EntityType *parentType, EntityType *childType, DataLayout *layout);
    Status    setIntegerParameter(IntegerParameter parameter, int value);
    Status    setDoubleParameter(DoubleParameter parameter, double value);
    Status    setComplexMode(ComplexMode mode);
    Status    getComplexMode(ComplexMode *mode);
    Status    hasComplexData(int *flag);
    Status    setData(int index, int entityNumber, double data[]);
    Status    getData(int index, int entityNumber, double data[]);
    Status    clear();
    Status    getDataStatus(int index, int entityNumber, int *status);
    Status    computeAccurateNodeFaceNormals(Group *group);
    Status    getListOfElementEntities(GroupOperation operation, IdTranslator *list);
    Status    copy(ElementData *from);
    Status    print();

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
