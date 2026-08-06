#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class RigidBody {
  public:
    /// Node constraint type
    enum class NodeType {
        TIE = RBODY_TIE, ///< Tied node (all DOFs constrained)
        PIN = RBODY_PIN  ///< Pinned node (only translational DOFs constrained)
    };

    /// Property definition flag
    enum class PropertyFlag {
        UNDEFINED = RBODY_UNDEFINED, ///< Property not defined
        VALUE = RBODY_VALUE,         ///< Property defined as value
        CURVE = RBODY_CURVE          ///< Property defined as curve
    };

    /// \brief Rigid body property integer type identifiers
    enum class IntegerProperty {
        PROPERTY_ID = RBODY_PID ///< Property ID for mass properties
    };

    /// \brief Rigid body property double type identifiers
    enum class DoubleProperty {
        ROTATION_AXIS = RBODY_ROTATION_AXIS ///< Rotation axis definition
    };

    PIMPL_MOVE_ONLY(RigidBody)

    ErrorCode getErrorCode();
    Status    define(EntityType entityType);
    Status    inquire(EntityType *entityType);
    Status    setMeshInterface(MeshInterface *functions);
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    setElementEntity(int elementIndex, int entityNumber);
    Status    isElementEntityDefined(int index, int *elementFlag, int *elementEntityBitFlag);
    Status    setNode(int index, NodeType type);
    Status    getNode(int index, NodeType *type);
    Status    hasRigidBodyEntitySpecified(int *flag);
    Status    setReferenceNode(int index);
    Status    getReferenceNode(int *index);
    Status    setPropertyIntegerValue(IntegerProperty type, int value);
    Status    setPropertyDoubleValue(DoubleProperty type, double *value);
    Status    getPropertyFlag(IntegerProperty type, PropertyFlag *flag);
    Status    getPropertyFlag(DoubleProperty type, PropertyFlag *flag);
    Status    getPropertyInformation(IntegerProperty type, int *componentCount);
    Status    getPropertyInformation(DoubleProperty type, int *componentCount);
    Status    getPropertyName(IntegerProperty type, char name[]);
    Status    getPropertyName(DoubleProperty type, char name[]);
    Status    getPropertyDoubleValue(DoubleProperty type, double value[]);
    Status    getPropertyIntegerValue(IntegerProperty type, int value[]);
    Status    getListOfFaces(IdTranslator *idtranslator);
    Status    getListOfEdges(IdTranslator *idtranslator);
    Status    getListOfNodes(NodeType type, IdTranslator *idtranslator);
    Status    print();
    Status    setAnalyticSurfaceId(int id);
    Status    getAnalyticSurfaceId(int *id);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
