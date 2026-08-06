#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class InteractionPair {
  public:
    PIMPL_MOVE_ONLY(InteractionPair)

    /// Interaction pair type
    enum class Type {
        CONTACT = CPAIR_CONTACT,    ///< Contact surface interaction
        COSIMULATION = CPAIR_COSIM, ///< Co-simulation surface
        CYCLIC = CPAIR_CYCLIC,      ///< Cyclic surface
        TIE = CPAIR_TIE_DEF         ///< Tie constraint
    };
    /// Surface designation in interaction pair
    enum class SurfaceType {
        MASTER = CPAIR_MASTER, ///< Master surface
        SLAVE = CPAIR_SLAVE    ///< Slave surface
    };

    /// Integer property type for interaction pair attributes
    enum class IntegerProperty {
        PROPERTY_ID = CPAIR_PID,                                   ///< Property ID or Field Interface Id in case of a co-simulation pair
        SMALL_SLIDING = CPAIR_SMALLSLIDING,                        ///< Small sliding flag
        SYMMETRIC = CPAIR_SYMMETRIC,                               ///< Symmetric contact
        SURFACE_TO_SURFACE = CPAIR_SURFTOSURF,                     ///< Surface to surface contact
        SLAVE_TO_MASTER_PROJECTION = CPAIR_PROJECT,                ///< Slave to master projection
        CYCLIC_SECTOR_COUNT = CPAIR_NUMSECTOR,                     ///< Cyclic sector count
        CYCLIC_COORD_SYSTEM_ID = CPAIR_CID,                        ///< Cyclic coordinate system ID
        MASTER_SET = CPAIR_MASTER_SET,                             ///< Master set ID
        SLAVE_SET = CPAIR_SLAVE_SET,                               ///< Slave set ID
        CONTACT_BEHAVIOR = CPAIR_CONTACT_BEHAVIOR,                 ///< Contact behavior type
        SEPARATION_THRESHOLD_TYPE = CPAIR_SEPARATIONTHRESHOLDTYPE, ///< Separation threshold type
        ID = CPAIR_ID,                                             ///< Interaction pair ID
        CYCLIC_MATCHING = CPAIR_CYCLIC_MATCHING,                   ///< Cyclic matching flag
        MATERIAL_ID = CPAIR_MATLID                                 ///< Material ID
    };

    /// Double property type for interaction pair attributes
    enum class DoubleProperty {
        ADJUST_ZONE_DISTANCE = CPAIR_ADJUST,              ///< Adjust zone distance
        SMOOTH_FACTOR = CPAIR_SMOOTH,                     ///< Smoothing factor
        CRITICAL_PENETRATION_DISTANCE = CPAIR_HCRIT,      ///< Critical penetration distance
        EXTENSION_ZONE_FACTOR = CPAIR_EXTENSIONZONE,      ///< Extension zone factor
        POSITION_TOLERANCE = CPAIR_POSITIONTOL,           ///< Position tolerance
        CYCLIC_TOLERANCE = CPAIR_CYCLICTOLERANCE,         ///< Cyclic tolerance
        MIN_POSITION_TOLERANCE = CPAIR_MINPOSITIONTOL,    ///< Minimum position tolerance
        SEPARATION_THRESHOLD = CPAIR_SEPARATIONTHRESHOLD, ///< Separation threshold value
        BIAS_POSITION_TOLERANCE = CPAIR_BIAS_POSITIONTOL  ///< Bias position tolerance
    };

    /// Property definition status flag
    enum class PropertyFlag {
        UNDEFINED = CPAIR_UNDEFINED, ///< Property not defined
        VALUE = CPAIR_VALUE,         ///< Property defined as value
        CURVE = CPAIR_CURVE          ///< Property defined as curve
    };

    /// Contact behavior type
    enum class ContactBehavior {
        STANDARD = CPAIR_CONTACT_BEHAVIOR_STANDARD,           ///< Standard contact behavior
        ROUGH = CPAIR_CONTACT_BEHAVIOR_ROUGH,                 ///< Rough contact behavior
        NO_SEPARATION = CPAIR_CONTACT_BEHAVIOR_NO_SEPARATION, ///< No separation with sliding permitted
        BONDED = CPAIR_CONTACT_BEHAVIOR_BONDED                ///< Bonded contact
    };

    /// Separation threshold criterion type
    enum class SeparationThresholdType {
        FORCE = CPAIR_SEPARATION_FORCE,                         ///< Force-based separation
        STRESS = CPAIR_SEPARATION_STRESS,                       ///< Stress-based separation
        STRESS_EXTRAPOLATED = CPAIR_SEPARATION_STRESS_EXTRAPOL, ///< Extrapolated stress-based separation
        STRESS_NODAL = CPAIR_SEPARATION_STRESS_NODAL,           ///< Nodal stress-based separation
        STRESS_RELATIVE = CPAIR_SEPARATION_STRESS_RELATIVE      ///< Relative stress-based separation
    };

    ErrorCode getErrorCode();
    Status    define(EntityType masterEntityType, EntityType slaveEntityType);
    Status    inquire(EntityType *masterEntityType, EntityType *slaveEntityType);
    Status    setType(Type type);
    Status    getType(Type *type);
    Status    setMeshInterface(MeshInterface *functions);
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    setSlaveNode(int index, double area);
    Status    setSlaveElement(int index, int entityNumber);
    Status    setMasterElement(int index, int entityNumber);
    Status    initializeSlaveElementEntityIterator();
    Status    nextSlaveElementEntityItem(int *index);
    Status    initializeSlaveNodeIterator();
    Status    nextSlaveNodeItem(int *index);
    Status    getSlaveCount(int *indexCount, int *entityCount);
    Status    isSlaveEntityDefined(int index, int *flag);
    Status    getSlaveElementEntity(int index, int *entityNumberCount, int entityNumbers[]);
    Status    getSlaveNode(int index, double *area);
    Status    initializeMasterEntityIterator();
    Status    nextMasterEntityItem(int *index);
    Status    getMasterElementCount(int *indexCount, int *entityCount);
    Status    isMasterEntityDefined(int index, int *flag);
    Status    getMasterElementEntity(int index, int *entityNumberCount, int entityNumbers[]);
    Status    hasInteractionPairSpecified(int *flag);
    Status    setPropertyDoubleValue(DoubleProperty type, double value);
    Status    getPropertyFlag(IntegerProperty type, PropertyFlag *flag);
    Status    getPropertyFlag(DoubleProperty type, PropertyFlag *flag);
    Status    getPropertyInformation(IntegerProperty type, int *componentCount);
    Status    getPropertyInformation(DoubleProperty type, int *componentCount);
    Status    getPropertyName(IntegerProperty type, char name[]);
    Status    getPropertyName(DoubleProperty type, char name[]);
    Status    getPropertyDoubleValue(DoubleProperty type, double values[]);
    Status    getListOfSlaveNodes(IdTranslator *idTranslator);
    Status    getListOfFaces(SurfaceType type, IdTranslator *idTranslator);
    Status    getListOfEdges(SurfaceType type, IdTranslator *idTranslator);
    Status    getMasterEntitySlaveNode(int slaveNodeIndex, int *elementIndex, int *entityNumber);
    Status    print();
    Status    setMasterAnalyticSurface(int id);
    Status    getMasterAnalyticSurface(int *id);

    template <auto IntegerPropertyType, typename PropertyValue>
    Status setPropertyIntegerValue(PropertyValue value);

    template <auto IntegerPropertyType, typename PropertyValue>
    Status getPropertyIntegerValue(PropertyValue values[]);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
